// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2015 MediaTek Inc.
 */

#if IS_ENABLED(CONFIG_COMPAT)
	/* 64 bit */
#include <linux/fs.h>
#include <linux/compat.h>
#endif


#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of_platform.h>
#include <linux/pm_opp.h>
#include <linux/regulator/consumer.h>

#include "mtk-interconnect.h"
#include "inc/cam_qos.h"
#include "cam_common.h"

#include <linux/pm_qos.h>
#include <dt-bindings/interconnect/mtk,mmqos.h>

#define MyTag "[ISP]"

#define LOG_VRB(format, args...)   \
	pr_debug(MyTag "[%s] " format, __func__, ##args)

// #define ISP_DEBUG
#ifdef ISP_DEBUG
#define LOG_DBG(format, args...) \
	pr_info(MyTag "[%s] " format, __func__, ##args)
#else
#define LOG_DBG(format, args...)
#endif

#define LOG_INF(format, args...) \
	pr_info(MyTag "[%s] " format, __func__, ##args)

#define LOG_NOTICE(format, args...) \
	pr_notice(MyTag "[%s] " format, __func__, ##args)


#ifndef MTRUE
#define MTRUE	1
#endif
#ifndef MFALSE
#define MFALSE	  0
#endif

struct icc_path *gCAM_BW_REQ[ISP_CAM_TYPE_CAM_AMOUNT][_rt_dma_max_];
struct icc_path *gSV_BW_REQ[ISP_CAM_TYPE_CAMSV_AMOUNT - ISP_CAM_TYPE_CAM_AMOUNT];


struct pm_qos_request isp_qos;

static struct device *mmdvfsDev;
static struct regulator *mmdvfsRegulator;


/* Unit of target_clk: MHz */
static u32 target_clk;

/* dts data: mediatek,platform */
static unsigned int g_cam_qos_platform_id;

/* dts data: lx_cam_xxx = <M4U_PORT_LX_CAM_XXX> */
static struct m4u_port_larbX_cam m4u_port;

#ifdef CAM_QOS_DBGFS
#include <linux/debugfs.h>

struct dentry *cam_qos_dbg_root;
#endif

void mtk_pmqos_remove(enum ISP_CAM_TYPE_ENUM module)
{
	switch (module) {
	case ISP_CAM_TYPE_CAM0:
	case ISP_CAM_TYPE_CAM1:
		break;
	case ISP_CAM_TYPE_CAMSV0:
	case ISP_CAM_TYPE_CAMSV1:
		break;
	default:
		LOG_NOTICE("unsupported module:%d\n", module);
		break;
	}
}

/* if module and portID are valid, return true. */
bool check_module_and_portID(enum ISP_CAM_TYPE_ENUM module, u32 portID)
{
	switch (module) {
	case ISP_CAM_TYPE_CAM0:
	case ISP_CAM_TYPE_CAM1:
		if (portID >= _rt_dma_max_) {
			LOG_NOTICE("CAM(%d) Wrong portID:%d\n", module, portID);
			return false;
		}
		break;
	case ISP_CAM_TYPE_CAMSV0:
	case ISP_CAM_TYPE_CAMSV1:
		if (portID >= _rt_dma_max_) {
			LOG_NOTICE("CAMSV(%d) Wrong portID:%d\n", module, portID);
			return false;
		}
		break;
	default:
		LOG_NOTICE("unsupported module:%d\n", module);
		return false;
	}

	return true;
}

void mtk_pmqos_add(struct device *dev, enum ISP_CAM_TYPE_ENUM module, u32 portID)
{
	if (check_module_and_portID(module, portID) == false)
		return;

	switch (module) {
	case ISP_CAM_TYPE_CAMSV0:
		gSV_BW_REQ[module - ISP_CAM_TYPE_CAMSV0] = mtk_icc_get(dev,
			MASTER_LARB_PORT(m4u_port.l2_cam_imgo_s),
			SLAVE_COMMON(0));
		break;
	case ISP_CAM_TYPE_CAMSV1:
		gSV_BW_REQ[module - ISP_CAM_TYPE_CAMSV0] = mtk_icc_get(dev,
			MASTER_LARB_PORT(m4u_port.l2_cam_imgo_s2),
			SLAVE_COMMON(0));
		break;
	default:
		switch (portID) {
		case _imgo_:
			switch (module) {
			case ISP_CAM_TYPE_CAM0:
			case ISP_CAM_TYPE_CAM1:
				gCAM_BW_REQ[module][portID] = mtk_icc_get(dev,
					MASTER_LARB_PORT(m4u_port.l2_cam_imgo),
					SLAVE_COMMON(0));
				break;
			default:
				LOG_NOTICE("portID(%d): unsupported module:%d\n", portID, module);
				break;
			}
			break;
		case _rrzo_:
			switch (module) {
			case ISP_CAM_TYPE_CAM0:
			case ISP_CAM_TYPE_CAM1:
				gCAM_BW_REQ[module][portID] = mtk_icc_get(dev,
					MASTER_LARB_PORT(m4u_port.l2_cam_rrzo),
					SLAVE_COMMON(0));
				break;
			default:
				LOG_NOTICE("portID(%d): unsupported module:%d\n", portID, module);
				break;
			}
			break;
		case _aao_:
		case _aao_d_:
			switch (module) {
			case ISP_CAM_TYPE_CAM0:
			case ISP_CAM_TYPE_CAM1:
				gCAM_BW_REQ[module][portID] = mtk_icc_get(dev,
					MASTER_LARB_PORT(m4u_port.l2_cam_aao),
					SLAVE_COMMON(0));
				break;
			default:
				LOG_NOTICE("portID(%d): unsupported module:%d\n", portID, module);
				break;
			}
			break;
		case _afo_:
		case _afo_d_:
			switch (module) {
			case ISP_CAM_TYPE_CAM0:
				gCAM_BW_REQ[module][portID] = mtk_icc_get(dev,
					MASTER_LARB_PORT(m4u_port.l2_cam_afo),
					SLAVE_COMMON(0));
				break;
			case ISP_CAM_TYPE_CAM1:
				gCAM_BW_REQ[module][portID] = mtk_icc_get(dev,
					MASTER_LARB_PORT(m4u_port.l2_cam_afo_d),
					SLAVE_COMMON(0));
				break;
			default:
				LOG_NOTICE("portID(%d): unsupported module:%d\n", portID, module);
				break;
			}
			break;
		case _lcso_:
			switch (module) {
			case ISP_CAM_TYPE_CAM0:
			case ISP_CAM_TYPE_CAM1:
				gCAM_BW_REQ[module][portID] = mtk_icc_get(dev,
					MASTER_LARB_PORT(m4u_port.l2_cam_lcso),
					SLAVE_COMMON(0));
				break;
			default:
				LOG_NOTICE("portID(%d): unsupported module:%d\n", portID, module);
				break;
			}
			break;
		case _esfko_:
			switch (module) {
			case ISP_CAM_TYPE_CAM0:
			case ISP_CAM_TYPE_CAM1:
				gCAM_BW_REQ[module][portID] = mtk_icc_get(dev,
					MASTER_LARB_PORT(m4u_port.l2_cam_esfko),
					SLAVE_COMMON(0));
				break;
			default:
				LOG_NOTICE("portID(%d): unsupported module:%d\n", portID, module);
				break;
			}
			break;
		default:
			LOG_NOTICE("module(%d): unsupported port:%d\n", module, portID);
			break;
		}
		break;
	}
}

void mtk_pmqos_set(enum ISP_CAM_TYPE_ENUM module, u32 portID, struct ISP_BW bw)
{
	int ret = 0;
	switch (module) {
	case ISP_CAM_TYPE_CAM0:
	case ISP_CAM_TYPE_CAM1:
		switch (portID) {
		case _imgo_:
		case _rrzo_:
		case _aao_:
		case _afo_:

		case _lcso_:
		case _ufeo_:
		{
			ret = mtk_icc_set_bw(gCAM_BW_REQ[module][portID],
				MBps_to_icc(bw.avg), MBps_to_icc(bw.peak));

			if (ret)
				LOG_NOTICE("mtk_icc_set_bw(%d,%d,%d) failed(%d)\n", portID,
					MBps_to_icc(bw.avg), MBps_to_icc(bw.peak), ret);
		}
			break;
		default:
			LOG_DBG("Cam unsupported port:%d\n", portID);
		break;
	}
	break;
	case ISP_CAM_TYPE_CAMSV0:
	case ISP_CAM_TYPE_CAMSV1:
		switch (portID) {
		case _camsv_imgo_:
		case _camsv2_imgo_:
		{
			//BW_COMP_NONE
			ret = mtk_icc_set_bw(
				gSV_BW_REQ[module - ISP_CAM_TYPE_CAMSV0],
				MBps_to_icc(bw.avg), MBps_to_icc(bw.peak));

			if (ret)
				LOG_NOTICE("mtk_icc_set_bw(%d,%d) failed(%d)\n",
					MBps_to_icc(bw.avg), MBps_to_icc(bw.peak), ret);
		}
			break;
		default:
			LOG_DBG("CamSV unsupported port:%d\n", portID);
			break;
		}
		break;
	default:
		LOG_DBG("No Cam, unsupported module:%d\n", module);
		break;
	}
}

void mtk_pmqos_clr(enum ISP_CAM_TYPE_ENUM module)
{
	unsigned short portID = 0;
	int ret = 0;

	switch (module) {
	case ISP_CAM_TYPE_CAM0:
	case ISP_CAM_TYPE_CAM1:
	{
		for (portID = 0; portID < _rt_dma_max_; portID++) {
			if (gCAM_BW_REQ[module][portID] == NULL)
				continue;

			ret = mtk_icc_set_bw(gCAM_BW_REQ[module][portID], 0, 0);

			if (ret)
				LOG_NOTICE("module(%d): mtk_icc_set_bw(0, 0) failed(%d)\n",
					module, ret);
		}
	}
		break;
	case ISP_CAM_TYPE_CAMSV0:
	case ISP_CAM_TYPE_CAMSV1:
	{
		for (portID = 0; portID < _rt_dma_max_; portID++) {
			if (gSV_BW_REQ[module - ISP_CAM_TYPE_CAMSV0] == NULL)
				continue;

			ret = mtk_icc_set_bw(gSV_BW_REQ[module - ISP_CAM_TYPE_CAMSV0], 0, 0);

			if (ret)
				LOG_NOTICE("SV module(%d): mtk_icc_set_bw(0, 0) failed(%d)\n",
					module, ret);
		}
	}
		break;
	default:
		LOG_NOTICE("unsupported module:%d\n", module);
		break;
	}
}


unsigned int mtk_dfs_get_cur_freq(void)
{
	unsigned long freq = 0;
	int volt = regulator_get_voltage(mmdvfsRegulator);
	struct dev_pm_opp *opp =
		dev_pm_opp_find_freq_ceil_by_volt(mmdvfsDev, volt);

	if (IS_ERR(opp))
		LOG_NOTICE("Error get current freq fail\n");
	else {
		freq = dev_pm_opp_get_freq(opp);
		dev_pm_opp_put(opp);
	}

	return (unsigned int)freq;
}

#define mtk_dfs_clr()	do { \
	int volt = 0, ret = 0; \
	ret = regulator_set_voltage(mmdvfsRegulator, volt, INT_MAX);\
	if (ret) \
		LOG_NOTICE("Error: E_CLK_UPDATE fail\n"); \
} while (0)

#define mtk_dfs_update(clk)	do { \
	struct dev_pm_opp *opp; \
	int volt = 0, ret = 0; \
	opp = dev_pm_opp_find_freq_ceil(mmdvfsDev, &clk); \
	if (IS_ERR(opp)) \
		opp = dev_pm_opp_find_freq_floor(mmdvfsDev, &clk); \
	volt = dev_pm_opp_get_voltage(opp); \
	dev_pm_opp_put(opp); \
	ret = regulator_set_voltage(mmdvfsRegulator, volt, INT_MAX);\
	if (ret) \
		LOG_NOTICE("Error: E_CLK_UPDATE fail\n"); \
} while (0)

#define mtk_dfs_supported(frq, step)	\
	mmdvfs_qos_get_freq_steps(PM_QOS_CAM_FREQ, frq, &step)

#define mtk_dfs_cur() mtk_dfs_get_cur_freq()


int ISP3_SetPMQOS(
	enum E_QOS_OP cmd,
	enum ISP_CAM_TYPE_ENUM module,
	unsigned int *pvalue)
{
	int Ret = 0;

	if (module > ISP_CAM_TYPE_CAM1) {
		LOG_NOTICE("supported only to CAM_B\n");
		return 1;
	}

	switch (cmd) {
	case E_BW_REMOVE:
		mtk_pmqos_remove(module);
		LOG_INF("PM_QOS:module:%d,OFF\n", module);
		break;
	case E_BW_ADD:
	{
		u32 i = 0;

		for (; i < _rt_dma_max_; i++)
			mtk_pmqos_add(mmdvfsDev, module, i);

		LOG_INF("PM_QOS:module:%d,ON\n", module);
	}
		break;
	case E_BW_UPDATE:
	{
		u32 i = 0;

		struct ISP_BW *ptr;

		for (; i < _rt_dma_max_; i++) {
			ptr = (struct ISP_BW *)pvalue;
			mtk_pmqos_set(module, i, ptr[i]);
		}
		LOG_DBG(
			"PM_QoS: module[%d]-bw_update, bw(peak avg)(%d %d) MB/s\n",
			module, ptr[_rrzo_].peak, ptr[_rrzo_].avg);
	}
		break;
	case E_BW_CLR:
		if (pvalue[0] == MFALSE) {
			mtk_pmqos_clr(module);
			LOG_DBG("module:%d bw_clr\n", module);
		}
		break;
	case E_CLK_CLR:
		mtk_dfs_clr();
		LOG_DBG("DFS_clr\n");
		break;
	case E_CLK_UPDATE:
	{
		unsigned long freq = 0;
#ifndef CONFIG_ARM64
		unsigned long long freq64 = 0;
#endif

		freq = (*(u32 *)pvalue) * 1000000; /* MHz to Hz */
		mtk_dfs_update(freq);

#ifndef CONFIG_ARM64
		freq64 = freq;
		do_div(freq64, 1000000); /* Hz to MHz*/
		freq = (unsigned long)freq64;
#else
		do_div(freq, 1000000); /* Hz to MHz*/
#endif
		target_clk = (u32)freq;
		LOG_INF("DFS Set clock :(%d, %d) MHz\n", *pvalue, target_clk);
	}
		break;
	case E_CLK_SUPPORTED:
	{
		unsigned int num_available, i = 0;
		u32 *speeds = NULL;
		struct dev_pm_opp *opp;
		unsigned long freq;
		#define STR_SIZE (128)
		char str[STR_SIZE];
		int c_num = 0;
		int size_remain = STR_SIZE;

		/* number of available opp */
		num_available = dev_pm_opp_get_opp_count(mmdvfsDev);
		if (num_available > 0) {
			speeds = kcalloc(num_available, sizeof(u32),
				GFP_KERNEL);
			freq = 0;
			if (speeds) {
				while (!IS_ERR(opp =
					dev_pm_opp_find_freq_ceil(
						mmdvfsDev, &freq))) {
				/* available freq is stored in speeds[i].
				 * The clock freq should be stored from high to low in pvalue
				 * for user space usage.
				 */
					speeds[num_available - i - 1] = freq;
					freq++;
					i++;
					dev_pm_opp_put(opp);
				}
			} else
				LOG_INF("Error: kcalloc speeds(%d) failed\n", num_available);
		}
		if (speeds) {
#ifndef CONFIG_ARM64
			u64 speed_64 = 0;

			for (i = 0; i < num_available; i++) {
				speed_64 = speeds[i];
				do_div(speed_64, 1000000); /* Hz to MHz */
				speeds[i] = (u32)speed_64;
				pvalue[i] = speeds[i];
			}
#else
			for (i = 0; i < num_available; i++) {
				do_div(speeds[i], 1000000); /* Hz to MHz */
				pvalue[i] = speeds[i];
			}
#endif
			kfree(speeds);
		}

		if (num_available > 0)
			target_clk = pvalue[num_available - 1];

		for (i = 0 ; i < num_available; i++) {
			int tmp = 0;

			tmp = snprintf(str + c_num, size_remain,
				"DFS Clk_%d:%d MHz\n", i, pvalue[i]);

			if (tmp < 0) {
				LOG_INF("snprintf failed\n");
				break;
			}
			c_num += tmp;
			size_remain -= tmp;

			if (size_remain <= 0) {
				LOG_INF("str size is not enough\n");
				break;
			}
		}
		LOG_INF("%s", str);

		return (int)num_available;

	}
		break;
	case E_CLK_CUR:
	{
#ifndef CONFIG_ARM64
		u64 pvalue64 = 0;

		pvalue[0] = mtk_dfs_cur();
		/* Hz to MHz */
		pvalue64 = pvalue[0];
		do_div(pvalue64, 1000000);
		pvalue[0] = pvalue64;
#else
		pvalue[0] = mtk_dfs_cur();
		/* Hz to MHz */
		do_div(pvalue[0], 1000000);
#endif
		pvalue[1] = (unsigned int)target_clk;
		LOG_INF("cur clk:%d MHz,tar clk:%d MHz\n", pvalue[0], pvalue[1]);
	}
		break;
	case E_CLK_ADD:
	case E_CLK_REMOVE:
	case E_QOS_UNKNOWN:
	default:
		LOG_NOTICE("unsupport cmd:%d\n", cmd);
		Ret = -1;
		break;
	}

	return Ret;
}
EXPORT_SYMBOL_GPL(ISP3_SetPMQOS);

int ISP3_SV_SetPMQOS(
	enum E_QOS_OP cmd,
	enum ISP_CAM_TYPE_ENUM module,
	unsigned int *pvalue)
{
	int Ret = 0;

	if ((module < ISP_CAM_TYPE_CAMSV0) ||
	    (module > ISP_CAM_TYPE_CAMSV1)) {
		LOG_NOTICE("supported only to SV0 to SV1\n");
		return 1;
	}

	switch (cmd) {
	case E_BW_REMOVE:
		mtk_pmqos_remove(module);
		LOG_INF("PM_QOS:module:%d,OFF\n", module);
		break;
	case E_BW_ADD:
	{
		mtk_pmqos_add(mmdvfsDev, module, 0);

		LOG_DBG("PM_QOS:module:%d,ON\n", module);
	}
		break;
	case E_BW_UPDATE:
	{
		u32 i = 0;
		struct ISP_BW *ptr;

		ptr = (struct ISP_BW *)pvalue;
		mtk_pmqos_set(module, i, ptr[i]);

		LOG_DBG(
			"PM_QoS: module[%d]-bw_update, bw(peak avg)(%d %d) MB/s\n",
			module, ptr[_camsv_imgo_].peak,
			ptr[_camsv_imgo_].avg);
	}
		break;
	case E_BW_CLR:
		if (pvalue[0] == MFALSE)
			mtk_pmqos_clr(module);
		LOG_DBG("module:%d BW_clr\n", module);
		break;
	case E_CLK_UPDATE:
	{
		unsigned long freq;
#ifndef CONFIG_ARM64
		unsigned long long freq64 = 0;
#endif

		freq = (*(u32 *)pvalue) * 1000000; // MHz to Hz
		LOG_INF("E_CLK_UPDATE %d MHz\n", *pvalue);
		mtk_dfs_update(freq);
#ifndef CONFIG_ARM64
		freq64 = freq;
		do_div(freq64, 1000000); // Hz to MHz
		freq = freq64;
#else
		do_div(freq, 1000000); // Hz to MHz
#endif
		target_clk = (u32)freq;
		LOG_INF("DFS Set clock :%d MHz\n", target_clk);
	}
		break;
	case E_CLK_CUR:
	{
#ifndef CONFIG_ARM64
		u64 pvalue64 = 0;

		pvalue[0] = mtk_dfs_cur();
		/* Hz to MHz */
		pvalue64 = pvalue[0];
		do_div(pvalue64, 1000000);
		pvalue[0] = pvalue64;
#else
		pvalue[0] = mtk_dfs_cur();
		/* Hz to MHz */
		do_div(pvalue[0], 1000000);
#endif
		pvalue[1] = (unsigned int)target_clk;
		LOG_INF("cur clk:%d MHz,tar clk:%d MHz\n", pvalue[0], pvalue[1]);
	}
		break;
	case E_CLK_SUPPORTED:
	{
		unsigned int num_available, i = 0;
		u32 *speeds = NULL;
		struct dev_pm_opp *opp;
		unsigned long freq;

		/* number of available opp */
		num_available = dev_pm_opp_get_opp_count(mmdvfsDev);
		if (num_available > 0) {
			speeds = kcalloc(num_available, sizeof(u32), GFP_KERNEL);

			freq = 0;
			if (speeds) {
				while (!IS_ERR(opp =
					dev_pm_opp_find_freq_ceil(
						mmdvfsDev, &freq))) {
				/* available freq is stored in speeds[i].
				 * The clock freq should be stored from high to low in pvalue
				 * for user space usage.
				 */
					speeds[num_available - i - 1] = freq;
					freq++;
					i++;
					dev_pm_opp_put(opp);
				}
			} else
				LOG_INF("Error: kcalloc speeds(%d) failed\n", num_available);
		}
		if (speeds) {
#ifndef CONFIG_ARM64
			u64 speed64;

			for (i = 0; i < num_available; i++) {
				speed64 = speeds[i];
				do_div(speed64, 1000000); /* Hz to MHz */
				speeds[i] = speed64;
				pvalue[i] = speeds[i];
			}
#else
			for (i = 0; i < num_available; i++) {
				do_div(speeds[i], 1000000); /* Hz to MHz */
				pvalue[i] = speeds[i];
			}
#endif
			kfree(speeds);
		}
		if (num_available > 0)
			target_clk = pvalue[num_available - 1];

		for (i = 0 ; i < num_available; i++)
			LOG_INF("2:DFS Clk_%d:%d MHz\n", i, pvalue[i]);

		return (int)num_available;
	}
		break;
	case E_QOS_UNKNOWN:
	case E_CLK_ADD:
	case E_CLK_CLR:
	case E_CLK_REMOVE:
	default:
		LOG_NOTICE("unsupport cmd:%d\n", cmd);
		Ret = -1;
		break;
	}
	return Ret;
}
EXPORT_SYMBOL_GPL(ISP3_SV_SetPMQOS);

/* Parse m4u port from DTS. */
static void cam_qos_parse_m4u_port(struct platform_device *pdev)
{
	of_property_read_u32(pdev->dev.of_node, "l2_cam_imgo", &(m4u_port.l2_cam_imgo));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_rrzo", &(m4u_port.l2_cam_rrzo));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_aao", &(m4u_port.l2_cam_aao));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_lcso", &(m4u_port.l2_cam_lcso));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_esfko", &(m4u_port.l2_cam_esfko));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_imgo_s", &(m4u_port.l2_cam_imgo_s));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_imgo_s2", &(m4u_port.l2_cam_imgo_s2));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_lsci", &(m4u_port.l2_cam_lsci));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_lsci_d", &(m4u_port.l2_cam_lsci_d));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_afo", &(m4u_port.l2_cam_afo));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_afo_d", &(m4u_port.l2_cam_afo_d));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_bpci", &(m4u_port.l2_cam_bpci));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_bpci_d", &(m4u_port.l2_cam_bpci_d));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_ufdi", &(m4u_port.l2_cam_ufdi));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_imgi", &(m4u_port.l2_cam_imgi));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_img2o", &(m4u_port.l2_cam_img2o));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_img3o", &(m4u_port.l2_cam_img3o));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_vipi", &(m4u_port.l2_cam_vipi));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_vip2i", &(m4u_port.l2_cam_vip2i));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_vip3i", &(m4u_port.l2_cam_vip3i));
	of_property_read_u32(pdev->dev.of_node, "l2_cam_icei", &(m4u_port.l2_cam_icei));
}

static int cam_qos_probe(struct platform_device *pdev)
{
	LOG_INF("CAM QOS probe.\n");

	dev_pm_opp_of_add_table(&pdev->dev);
	mmdvfsDev = &pdev->dev;
	mmdvfsRegulator = devm_regulator_get(&pdev->dev, "dvfsrc-vcore");

	/* parse m4u port from dts. */
	cam_qos_parse_m4u_port(pdev);

	return 0;
}

static const struct of_device_id of_match_cam_qos[] = {
	{ .compatible = CAM_QOS_COMP_NAME, },
	{}
};

static struct platform_driver cam_qos_drv = {
	.probe = cam_qos_probe,
	.driver = {
		.name = "cam_qos",
		.of_match_table = of_match_cam_qos,
	},
};

static int __init cam_qos_init(void)
{
	g_cam_qos_platform_id = GET_PLATFORM_ID(CAM_QOS_COMP_NAME);
	if (g_cam_qos_platform_id == 0) {
		LOG_NOTICE("get platform id failed\n");
		return -ENODEV;
	}
	LOG_NOTICE("platform id(0x%x)\n", g_cam_qos_platform_id);

#ifdef CAM_QOS_DBGFS
	cam_qos_dbg_root = debugfs_create_dir("cam_qos", NULL);

	debugfs_create_x32("platform", 0644,
		cam_qos_dbg_root, &g_cam_qos_platform_id);
	debugfs_create_x32("l13_cam_camsv1", 0644,
		cam_qos_dbg_root, &m4u_port.l13_cam_camsv1);
#endif

	return platform_driver_register(&cam_qos_drv);
}

static void __exit cam_qos_exit(void)
{
	platform_driver_unregister(&cam_qos_drv);
}

/*******************************************************************************
 *
 ******************************************************************************/
module_init(cam_qos_init);
module_exit(cam_qos_exit);
MODULE_DESCRIPTION("Camera QOS");
MODULE_AUTHOR("SW7");
MODULE_LICENSE("GPL");
