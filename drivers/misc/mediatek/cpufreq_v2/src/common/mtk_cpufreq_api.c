/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
*/
#include "mtk_ppm_api.h"
#include "mtk_cpufreq_internal.h"
#include "mtk_cpufreq_hybrid.h"
#include "mtk_cpufreq_platform.h"

int mt_cpufreq_set_by_wfi_load_cluster(unsigned int cluster_id,
	unsigned int freq)
{

	return 0;
}
EXPORT_SYMBOL(mt_cpufreq_set_by_wfi_load_cluster);

int mt_cpufreq_set_by_schedule_load_cluster(unsigned int cluster_id,
	unsigned int freq)
{

	return 0;
}
EXPORT_SYMBOL(mt_cpufreq_set_by_schedule_load_cluster);

unsigned int mt_cpufreq_find_close_freq(unsigned int cluster_id,
	unsigned int freq)
{
	enum mt_cpu_dvfs_id id;
	struct mt_cpu_dvfs *p;
	int idx;

	if (cluster_id > NR_MT_CPU_DVFS - 1)
		cluster_id = NR_MT_CPU_DVFS - 1;

	id = (enum mt_cpu_dvfs_id) cluster_id;
	p = id_to_cpu_dvfs(id);
	idx = _search_available_freq_idx(p, freq, CPUFREQ_RELATION_L);

	if (idx < 0)
		idx = 0;

	return mt_cpufreq_get_freq_by_idx(id, idx);
}

int mt_cpufreq_set_iccs_frequency_by_cluster(int en,
	unsigned int cluster_id, unsigned int freq)
{

	return 0;
}
EXPORT_SYMBOL(mt_cpufreq_set_iccs_frequency_by_cluster);

int is_in_suspend(void)
{
	struct mt_cpu_dvfs *p = id_to_cpu_dvfs(0);

	return p->dvfs_disable_by_suspend;
}
EXPORT_SYMBOL(is_in_suspend);

int mt_cpufreq_update_volt(enum mt_cpu_dvfs_id id,
	unsigned int *volt_tbl, int nr_volt_tbl)
{
	struct mt_cpu_dvfs *p;

	FUNC_ENTER(FUNC_LV_API);

	if (id > NR_MT_CPU_DVFS - 1)
		id = (enum mt_cpu_dvfs_id) NR_MT_CPU_DVFS - 1;

	p = id_to_cpu_dvfs(id);

	_mt_cpufreq_dvfs_request_wrapper(p, p->idx_opp_tbl,
		MT_CPU_DVFS_EEM_UPDATE,
		(void *)&volt_tbl);

	FUNC_EXIT(FUNC_LV_API);

	return 0;
}
EXPORT_SYMBOL(mt_cpufreq_update_volt);

cpuVoltsampler_func g_pCpuVoltSampler_met;
cpuVoltsampler_func g_pCpuVoltSampler_ocp;
void notify_cpu_volt_sampler(enum mt_cpu_dvfs_id id,
	unsigned int volt, int up, int event)
{
	unsigned int mv = volt / 100;

	if (g_pCpuVoltSampler_met)
		g_pCpuVoltSampler_met(id, mv, up, event);

	if (g_pCpuVoltSampler_ocp)
		g_pCpuVoltSampler_ocp(id, mv, up, event);
}

/* cpu voltage sampler */
void mt_cpufreq_setvolt_registerCB(cpuVoltsampler_func pCB)
{
	g_pCpuVoltSampler_met = pCB;
}
EXPORT_SYMBOL(mt_cpufreq_setvolt_registerCB);

/* ocp cpu voltage sampler */
void mt_cpufreq_setvolt_ocp_registerCB(cpuVoltsampler_func pCB)
{
	g_pCpuVoltSampler_ocp = pCB;
}
EXPORT_SYMBOL(mt_cpufreq_setvolt_ocp_registerCB);

/* for PTP-OD */
static mt_cpufreq_set_ptbl_funcPTP mt_cpufreq_update_private_tbl;

void mt_cpufreq_set_ptbl_registerCB(mt_cpufreq_set_ptbl_funcPTP pCB)
{
	mt_cpufreq_update_private_tbl = pCB;
}
EXPORT_SYMBOL(mt_cpufreq_set_ptbl_registerCB);


unsigned int mt_cpufreq_get_cur_volt(enum mt_cpu_dvfs_id id)
{
	struct mt_cpu_dvfs *p;
	struct buck_ctrl_t *vproc_p;

	if (id > NR_MT_CPU_DVFS - 1)
		id = (enum mt_cpu_dvfs_id) NR_MT_CPU_DVFS - 1;

	p = id_to_cpu_dvfs(id);
	vproc_p = id_to_buck_ctrl(p->Vproc_buck_id);

	return vproc_p->cur_volt;

}
EXPORT_SYMBOL(mt_cpufreq_get_cur_volt);

unsigned int mt_cpufreq_get_cur_freq(enum mt_cpu_dvfs_id id)
{
	struct mt_cpu_dvfs *p;

	if (id > NR_MT_CPU_DVFS - 1)
		id = (enum mt_cpu_dvfs_id) NR_MT_CPU_DVFS - 1;

	p = id_to_cpu_dvfs(id);

	return cpu_dvfs_get_cur_freq(p);

}
EXPORT_SYMBOL(mt_cpufreq_get_cur_freq);

unsigned int mt_cpufreq_get_freq_by_idx(enum mt_cpu_dvfs_id id, int idx)
{
	struct mt_cpu_dvfs *p;

	FUNC_ENTER(FUNC_LV_API);

	if (id > NR_MT_CPU_DVFS - 1)
		id = (enum mt_cpu_dvfs_id) NR_MT_CPU_DVFS - 1;

	p = id_to_cpu_dvfs(id);

	if (!cpu_dvfs_is_available(p)) {
		FUNC_EXIT(FUNC_LV_API);
		return 0;
	}

	FUNC_EXIT(FUNC_LV_API);

	return cpu_dvfs_get_freq_by_idx(p, idx);
}
EXPORT_SYMBOL(mt_cpufreq_get_freq_by_idx);

unsigned int mt_cpufreq_get_volt_by_idx(enum mt_cpu_dvfs_id id, int idx)
{
	struct mt_cpu_dvfs *p;

	FUNC_ENTER(FUNC_LV_API);

	if (id > NR_MT_CPU_DVFS - 1)
		id = (enum mt_cpu_dvfs_id) NR_MT_CPU_DVFS - 1;

	p = id_to_cpu_dvfs(id);

	if (!cpu_dvfs_is_available(p)) {
		FUNC_EXIT(FUNC_LV_API);
		return 0;
	}

	FUNC_EXIT(FUNC_LV_API);

	return cpu_dvfs_get_volt_by_idx(p, idx);
}
EXPORT_SYMBOL(mt_cpufreq_get_volt_by_idx);

unsigned int mt_cpufreq_get_cur_phy_freq_no_lock(enum mt_cpu_dvfs_id id)
{
	struct mt_cpu_dvfs *p;
	unsigned int freq = 0;

	FUNC_ENTER(FUNC_LV_LOCAL);

	if (id > NR_MT_CPU_DVFS - 1)
		id = (enum mt_cpu_dvfs_id) NR_MT_CPU_DVFS - 1;

	p = id_to_cpu_dvfs(id);

	freq = cpu_dvfs_get_cur_freq(p);

	FUNC_EXIT(FUNC_LV_LOCAL);

	return freq;
}
EXPORT_SYMBOL(mt_cpufreq_get_cur_phy_freq_no_lock);

int mt_cpufreq_get_ppb_state(void)
{
	return dvfs_power_mode;
}

int mt_cpufreq_get_sched_enable(void)
{
	return sched_dvfs_enable;
}
#if !IS_ENABLED(CONFIG_MTK_TINYSYS_MCUPM_SUPPORT)
void *get_mcupm_ipidev(void)
{
	return NULL;
}
EXPORT_SYMBOL(get_mcupm_ipidev);
#endif

#if !IS_ENABLED(CONFIG_MTK_IPI)
typedef int (*mbox_pin_cb_t)(unsigned int ipi_id, void *prdata, void *data, unsigned int len);

int mtk_ipi_register(void *ipidev, int ipi_id,
		mbox_pin_cb_t cb, void *prdata, void *msg)
{
	return 0;
}
EXPORT_SYMBOL(mtk_ipi_register);

int mtk_ipi_send_compl(void *ipidev, int ipi_id,
		int opt, void *data, int len, unsigned long timeout)
{
	return 0;
}
EXPORT_SYMBOL(mtk_ipi_send_compl);

#endif
