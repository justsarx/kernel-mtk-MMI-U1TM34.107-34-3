// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2019 MediaTek Inc.
 */

/*
 * MAIN AF voice coil motor driver
 *
 *
 */

#include <linux/atomic.h>
#include <linux/cdev.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/i2c.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/uaccess.h>
#ifdef CONFIG_COMPAT
#include <linux/compat.h>
#endif
#ifdef CONFIG_AF_NOISE_ELIMINATION
#include "linux/pm_wakeup.h"
#endif

/* kernel standard */
#include <linux/regulator/consumer.h>
#include <linux/pinctrl/consumer.h>

/* OIS/EIS Timer & Workqueue */
#include <linux/hrtimer.h>
#include <linux/init.h>
#include <linux/ktime.h>
/* ------------------------- */

#include "lens_info.h"
#include "lens_list.h"

#define AF_DRVNAME "MAINAF"

#if defined(CONFIG_MTK_LEGACY)
#define I2C_CONFIG_SETTING 1
#elif defined(CONFIG_OF)
#define I2C_CONFIG_SETTING 2 /* device tree */
#else

#define I2C_CONFIG_SETTING 1
#endif

#if I2C_CONFIG_SETTING == 1
#define LENS_I2C_BUSNUM 0
#define I2C_REGISTER_ID 0x28
#endif

#define PLATFORM_DRIVER_NAME "lens_actuator_main_af"
#define AF_DRIVER_CLASS_NAME "actuatordrv_main_af"

#if I2C_CONFIG_SETTING == 1
static struct i2c_board_info kd_lens_dev __initdata = {
	I2C_BOARD_INFO(AF_DRVNAME, I2C_REGISTER_ID)};
#endif

#define AF_DEBUG
#ifdef AF_DEBUG
#define LOG_INF(format, args...)                                               \
	pr_info(AF_DRVNAME " [%s] " format, __func__, ##args)
#else
#define LOG_INF(format, args...)
#endif

#ifdef CONFIG_AF_NOISE_ELIMINATION
static unsigned long af_len = 1;
static int Open_holder = 0;
static int Close_holder = 0;
static struct wakeup_source vib_wakelock;
#endif

/* OIS/EIS Timer & Workqueue */
static struct workqueue_struct *ois_workqueue;
static struct work_struct ois_work;
static struct hrtimer ois_timer;

static DEFINE_MUTEX(ois_mutex);
static int g_EnableTimer;
static int g_GetOisInfoCnt;
static int g_OisPosIdx;
static struct stAF_OisPosInfo OisPosInfo;
/* ------------------------- */

static struct stAF_DrvList g_stAF_DrvList[MAX_NUM_OF_LENS] = {
#if defined(CONFIG_MOT_DEVONN_CAMERA_PROJECT)
#ifdef CONFIG_AF_NOISE_ELIMINATION
	{1, MOT_DEVONN_AFDRV_DW9800VAF, MOT_DEVONN_DW9800VAF_SetI2Cclient_Main, MOT_DEVONN_DW9800VAF_Ioctl_Main,
        MOT_DEVONN_DW9800VAF_Release_Main, MOT_DEVONN_DW9800VAF_GetFileName_Main, NULL, VIB_ResetPos},
#else
	{1, MOT_DEVONN_AFDRV_DW9800VAF, MOT_DEVONN_DW9800VAF_SetI2Cclient_Main, MOT_DEVONN_DW9800VAF_Ioctl_Main,
	MOT_DEVONN_DW9800VAF_Release_Main, MOT_DEVONN_DW9800VAF_GetFileName_Main, NULL},
#endif
#elif defined(CONFIG_MOT_DEVONF_CAMERA_PROJECT)
	{1, MOT_DEVONF_AFDRV_GT9764, MOT_DEVONF_GT9764_SetI2CClient, MOT_DEVONF_GT9764_Ioctl,
	MOT_DEVONF_GT9764_Release, MOT_DEVONF_GT9764_GetFileName, NULL},
#elif defined(CONFIG_MOT_CANCUNF_CAMERA_PROJECT)
	{1, MOT_CANCUNF_AFDRV_AW86006, MOT_CANCUNF_AW86006_SetI2Cclient, MOT_CANCUNF_AW86006_Ioctl,
	MOT_CANCUNF_AW86006_Release, MOT_CANCUNF_AW86006_GetFileName, NULL},
	{1, MOT_CANCUNF_AFDRV_AW86006VCMYOVA, MOT_CANCUNF_AW86006VCMYOVA_SetI2Cclient, MOT_CANCUNF_AW86006VCMYOVA_Ioctl,
	MOT_CANCUNF_AW86006VCMYOVA_Release, MOT_CANCUNF_AW86006VCMYOVA_GetFileName, NULL},
#elif defined(CONFIG_MOT_CANCUNN_CAMERA_PROJECT)
        {1, MOT_CANCUNN_AFDRV_AW86006, MOT_CANCUNN_AW86006_SetI2Cclient, MOT_CANCUNN_AW86006_Ioctl,
        MOT_CANCUNN_AW86006_Release, MOT_CANCUNN_AW86006_GetFileName, NULL},
#elif defined(CONFIG_MOT_MAUI_CAMERA_PROJECT)
	{1, MOT_MAUI_AFDRV_GT9772AF, MOT_MAUI_GT9772AF_SetI2Cclient, MOT_MAUI_GT9772AF_Ioctl,
	MOT_MAUI_GT9772AF_Release, MOT_MAUI_GT9772AF_GetFileName, NULL},
#else
//Begin: Add lens driver for Vicky
	{1, MOT_VICKY_AFDRV_GT9764, MOT_VICKY_GT9764_SetI2CClient, MOT_VICKY_GT9764_Ioctl,
	MOT_VICKY_GT9764_Release, MOT_VICKY_GT9764_GetFileName, NULL},
//End
#endif
};

static struct stAF_DrvList *g_pstAF_CurDrv;

static spinlock_t g_AF_SpinLock;

static int g_s4AF_Opened;

static struct i2c_client *g_pstAF_I2Cclient;

static dev_t g_AF_devno;
static struct cdev *g_pAF_CharDrv;
static struct class *actuator_class;
static struct device *lens_device;

static struct regulator *vcamaf_ldo;
static struct pinctrl *vcamaf_pio;
static struct pinctrl_state *vcamaf_pio_on;
static struct pinctrl_state *vcamaf_pio_off;

#define CAMAF_PMIC     "camaf_m1_pmic"
#define CAMAF_GPIO_ON  "camaf_m1_gpio_on"
#define CAMAF_GPIO_OFF "camaf_m1_gpio_off"

static void camaf_power_init(void)
{
	int ret;
	struct device_node *node, *kd_node;

	/* check if customer camera node defined */
	node = of_find_compatible_node(
		NULL, NULL, "mediatek,camera_af_lens");

	if (node) {
		kd_node = lens_device->of_node;
		lens_device->of_node = node;

		if (vcamaf_ldo == NULL) {
			vcamaf_ldo = regulator_get(lens_device, CAMAF_PMIC);
			if (IS_ERR(vcamaf_ldo)) {
				ret = PTR_ERR(vcamaf_ldo);
				vcamaf_ldo = NULL;
				LOG_INF("cannot get regulator\n");
			}
		}

		if (vcamaf_pio == NULL) {
			vcamaf_pio = devm_pinctrl_get(lens_device);
			if (IS_ERR(vcamaf_pio)) {
				ret = PTR_ERR(vcamaf_pio);
				vcamaf_pio = NULL;
				pr_info("cannot get pinctrl\n");
			} else {
				vcamaf_pio_on = pinctrl_lookup_state(
					vcamaf_pio, CAMAF_GPIO_ON);

				if (IS_ERR(vcamaf_pio_on)) {
					ret = PTR_ERR(vcamaf_pio_on);
					vcamaf_pio_on = NULL;
					LOG_INF("cannot get vcamaf_pio_on\n");
				}

				vcamaf_pio_off = pinctrl_lookup_state(
					vcamaf_pio, CAMAF_GPIO_OFF);

				if (IS_ERR(vcamaf_pio_off)) {
					ret = PTR_ERR(vcamaf_pio_off);
					vcamaf_pio_off = NULL;
					LOG_INF("cannot get vcamaf_pio_off\n");
				}
			}
		}

		lens_device->of_node = kd_node;
	}
}

static void camaf_power_on(void)
{
	int ret;

	if (vcamaf_ldo) {
		ret = regulator_enable(vcamaf_ldo);
		LOG_INF("regulator enable (%d)\n", ret);
	}

	if (vcamaf_pio && vcamaf_pio_on) {
		ret = pinctrl_select_state(vcamaf_pio, vcamaf_pio_on);
		LOG_INF("pinctrl enable (%d)\n", ret);
	}
}

static void camaf_power_off(void)
{
	int ret;

	if (vcamaf_ldo) {
		ret = regulator_disable(vcamaf_ldo);
		LOG_INF("regulator disable (%d)\n", ret);
	}

	if (vcamaf_pio && vcamaf_pio_off) {
		ret = pinctrl_select_state(vcamaf_pio, vcamaf_pio_off);
		LOG_INF("pinctrl disable (%d)\n", ret);
	}
}

#ifdef CONFIG_MACH_MT6765
static int DrvPwrDn1 = 1;
static int DrvPwrDn2 = 1;
static int DrvPwrDn3 = 1;
#endif

void AF_PowerDown(void)
{
	if (g_pstAF_I2Cclient != NULL) {
		LOG_INF("+\n");
		LOG_INF("-\n");
	}
}
EXPORT_SYMBOL(AF_PowerDown);

static long AF_SetMotorName(__user struct stAF_MotorName *pstMotorName)
{
	long i4RetValue = -1;
	int i;
	struct stAF_MotorName stMotorName;

	if (copy_from_user(&stMotorName, pstMotorName,
			   sizeof(struct stAF_MotorName))) {
		LOG_INF("copy to user failed when getting motor information\n");
		return i4RetValue;
	}

	for (i = 0; i < MAX_NUM_OF_LENS; i++) {
		if (g_stAF_DrvList[i].uEnable != 1)
			break;

		LOG_INF("Search Motor Name : %s\n", g_stAF_DrvList[i].uDrvName);
		stMotorName.uMotorName[STRUCT_MOTOR_NAME - 1] = '\0';
		if (strcmp(stMotorName.uMotorName,
			   g_stAF_DrvList[i].uDrvName) == 0) {
			LOG_INF("Motor Name : %s\n", stMotorName.uMotorName);
			g_pstAF_CurDrv = &g_stAF_DrvList[i];
			i4RetValue = g_pstAF_CurDrv->pAF_SetI2Cclient(
				g_pstAF_I2Cclient, &g_AF_SpinLock,
				&g_s4AF_Opened);
			break;
		}
	}
	return i4RetValue;
}

static inline int64_t getCurNS(void)
{
	int64_t ns;
	struct timespec64 time;

	time.tv_sec = time.tv_nsec = 0;
	/* get_monotonic_boottime(&time); */
	ns = time.tv_sec * 1000000000LL + time.tv_nsec;

	return ns;
}

/* OIS/EIS Timer & Workqueue */
static void ois_pos_polling(struct work_struct *data)
{
	mutex_lock(&ois_mutex);
	if (g_pstAF_CurDrv) {
		if (g_pstAF_CurDrv->pAF_OisGetHallPos) {
			int PosX = 0, PosY = 0;

			g_pstAF_CurDrv->pAF_OisGetHallPos(&PosX, &PosY);
			if (g_OisPosIdx >= 0) {
				OisPosInfo.TimeStamp[g_OisPosIdx] = getCurNS();
				OisPosInfo.i4OISHallPosX[g_OisPosIdx] = PosX;
				OisPosInfo.i4OISHallPosY[g_OisPosIdx] = PosY;
				g_OisPosIdx++;
				g_OisPosIdx &= OIS_DATA_MASK;
			}
		}
	}
	mutex_unlock(&ois_mutex);
}

static enum hrtimer_restart ois_timer_func(struct hrtimer *timer)
{
	g_GetOisInfoCnt--;

	if (ois_workqueue != NULL && g_GetOisInfoCnt > 11)
		queue_work(ois_workqueue, &ois_work);

	if (g_GetOisInfoCnt < 10) {
		g_EnableTimer = 0;
		return HRTIMER_NORESTART;
	}

	hrtimer_forward_now(timer, ktime_set(0, 5000000));
	return HRTIMER_RESTART;
}
/* ------------------------- */

/* ////////////////////////////////////////////////////////////// */
static long AF_Ioctl(struct file *a_pstFile, unsigned int a_u4Command,
		     unsigned long a_u4Param)
{
	long i4RetValue = 0;

	switch (a_u4Command) {
	case AFIOC_S_SETDRVNAME:
		i4RetValue = AF_SetMotorName(
			(__user struct stAF_MotorName *)(a_u4Param));
		break;

	case AFIOC_G_GETDRVNAME:
		{
	/* Set Driver Name */
	int i;
	struct stAF_MotorName stMotorName = {'\0'};
	struct stAF_DrvList *pstAF_CurDrv = NULL;
	__user struct stAF_MotorName *pstMotorName =
			(__user struct stAF_MotorName *)a_u4Param;

	if (copy_from_user(&stMotorName, pstMotorName,
			   sizeof(struct stAF_MotorName))) {
		LOG_INF("copy to user failed when getting motor information\n");
		break;
	}

	for (i = 0; i < MAX_NUM_OF_LENS; i++) {
		if (g_stAF_DrvList[i].uEnable != 1)
			break;

		LOG_INF("Search Motor Name : %s\n", g_stAF_DrvList[i].uDrvName);
		stMotorName.uMotorName[STRUCT_MOTOR_NAME - 1] = '\0';
		if (strcmp(stMotorName.uMotorName,
			   g_stAF_DrvList[i].uDrvName) == 0) {
			LOG_INF("Motor Name : %s\n", stMotorName.uMotorName);
			pstAF_CurDrv = &g_stAF_DrvList[i];
			break;
		}
	}

	/* Get File Name */
	if (pstAF_CurDrv) {
		if (pstAF_CurDrv->pAF_GetFileName) {
			__user struct stAF_MotorName *pstMotorName =
			(__user struct stAF_MotorName *)a_u4Param;
			struct stAF_MotorName MotorFileName;

			pstAF_CurDrv->pAF_GetFileName(
					MotorFileName.uMotorName);
			i4RetValue = 1;
			LOG_INF("GETDRVNAME : get file name(%s)\n",
				MotorFileName.uMotorName);
			if (copy_to_user(
				    pstMotorName, &MotorFileName,
				    sizeof(struct stAF_MotorName)))
				LOG_INF("copy to user failed\n");
		}
	}
		}
		break;

	case AFIOC_S_SETDRVINIT:
		spin_lock(&g_AF_SpinLock);
		g_s4AF_Opened = 1;
		spin_unlock(&g_AF_SpinLock);
		break;

	case AFIOC_S_SETPOWERDOWN:
		AF_PowerDown();
		i4RetValue = 1;
		break;

	case AFIOC_G_OISPOSINFO:
		if (g_pstAF_CurDrv) {
			if (g_pstAF_CurDrv->pAF_OisGetHallPos) {
				__user struct stAF_OisPosInfo *pstOisPosInfo =
					(__user struct stAF_OisPosInfo *)
						a_u4Param;

				mutex_lock(&ois_mutex);

				if (copy_to_user(
					    pstOisPosInfo, &OisPosInfo,
					    sizeof(struct stAF_OisPosInfo)))
					LOG_INF("copy to user failed\n");

				g_OisPosIdx = 0;
				g_GetOisInfoCnt = 100;
				memset(&OisPosInfo, 0, sizeof(OisPosInfo));
				mutex_unlock(&ois_mutex);

				if (g_EnableTimer == 0) {
					/* Start Timer */
					hrtimer_start(&ois_timer,
						      ktime_set(0, 50000000),
						      HRTIMER_MODE_REL);
					g_EnableTimer = 1;
				}
			}
		}
		break;
#ifdef CONFIG_AF_NOISE_ELIMINATION
	case AFIOC_T_SETOPENER:
		spin_lock(&g_AF_SpinLock);
		Open_holder |= a_u4Param;
		i4RetValue = Open_holder;
		if(a_u4Param == VIB_HOLD){
		    spin_unlock(&g_AF_SpinLock);
			LOG_INF("pm_stay_awake vib_wakelock\n");
			__pm_stay_awake(&vib_wakelock);
		}else{
			spin_unlock(&g_AF_SpinLock);
		}
                LOG_INF(" Open_holder = %d\n",Open_holder);
		break;
	case AFIOC_T_SETCLOSEER:
		spin_lock(&g_AF_SpinLock);
		Close_holder = a_u4Param;
		Open_holder &= ~a_u4Param;
		spin_unlock(&g_AF_SpinLock);
		LOG_INF("Close_holder = %d;Open_holder = %d\n",Close_holder,Open_holder);
		break;
	case AFIOC_T_SETVCMPOS:
		af_len = a_u4Param;
		LOG_INF("set af_len = %d\n",af_len);
		break;
#endif
	default:
		if (g_pstAF_CurDrv) {
			if (g_pstAF_CurDrv->pAF_Ioctl)
				i4RetValue = g_pstAF_CurDrv->pAF_Ioctl(
					a_pstFile, a_u4Command, a_u4Param);
		}
		break;
	}

	return i4RetValue;
}

#ifdef CONFIG_COMPAT
static long AF_Ioctl_Compat(struct file *a_pstFile, unsigned int a_u4Command,
			    unsigned long a_u4Param)
{
	long i4RetValue = 0;

	i4RetValue = AF_Ioctl(a_pstFile, a_u4Command,
			      (unsigned long)compat_ptr(a_u4Param));

	return i4RetValue;
}
#endif

/* Main jobs: */
/* 1.check for device-specified errors, device not ready. */
/* 2.Initialize the device if it is opened for the first time. */
/* 3.Update f_op pointer. */
/* 4.Fill data structures into private_data */
/* CAM_RESET */
static int AF_Open(struct inode *a_pstInode, struct file *a_pstFile)
{
	LOG_INF("Start\n");

	spin_lock(&g_AF_SpinLock);
#ifdef CONFIG_AF_NOISE_ELIMINATION
	Close_holder = NO_HOLD;
	if(g_s4AF_Opened  == 1){
		spin_unlock(&g_AF_SpinLock);
		return 0;
	}
#else
	if (g_s4AF_Opened) {
		spin_unlock(&g_AF_SpinLock);
		LOG_INF("The device is opened\n");
		return -EBUSY;
	}
#endif
	g_s4AF_Opened = 1;
	spin_unlock(&g_AF_SpinLock);

	camaf_power_init();
	camaf_power_on();

	/* OIS/EIS Timer & Workqueue */
	/* init work queue */
	INIT_WORK(&ois_work, ois_pos_polling);

	/* init timer */
	hrtimer_init(&ois_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	ois_timer.function = ois_timer_func;

	g_EnableTimer = 0;
	/* ------------------------- */

	LOG_INF("End\n");

	return 0;
}

/* Main jobs: */
/* 1.Deallocate anything that "open" allocated in private_data. */
/* 2.Shut down the device on last close. */
/* 3.Only called once on last time. */
/* Q1 : Try release multiple times. */
static int AF_Release(struct inode *a_pstInode, struct file *a_pstFile)
{
	LOG_INF("Start\n");
#ifdef CONFIG_AF_NOISE_ELIMINATION
	spin_lock(&g_AF_SpinLock);
	if (g_pstAF_CurDrv && g_s4AF_Opened >= 1 && Open_holder == 0) {
		spin_unlock(&g_AF_SpinLock);
#else
	if (g_pstAF_CurDrv) {
#endif
		g_pstAF_CurDrv->pAF_Release(a_pstInode, a_pstFile);
		g_pstAF_CurDrv = NULL;
	}
#ifdef CONFIG_AF_NOISE_ELIMINATION
        else if(g_s4AF_Opened >= 1 && g_pstAF_CurDrv ){
			if(Open_holder == VIB_HOLD && Close_holder == CAM_HOLD){
				spin_unlock(&g_AF_SpinLock);
				g_pstAF_CurDrv->pAF_ResetPos(af_len);
			}else{
				spin_unlock(&g_AF_SpinLock);
			}
			spin_lock(&g_AF_SpinLock);
			if(Close_holder == VIB_HOLD){
				spin_unlock(&g_AF_SpinLock);
				LOG_INF("pm_relax vib_wakelock\n");
				__pm_relax(&vib_wakelock);
			}else{
				spin_unlock(&g_AF_SpinLock);
			}
			return 0;
        }
#endif
	else {
#ifndef CONFIG_AF_NOISE_ELIMINATION
		spin_lock(&g_AF_SpinLock);
#endif
		g_s4AF_Opened = 0;
		spin_unlock(&g_AF_SpinLock);
	}

	camaf_power_off();

	/* OIS/EIS Timer & Workqueue */
	/* Cancel Timer */
	hrtimer_cancel(&ois_timer);

	/* flush work queue */
	flush_work(&ois_work);

	if (ois_workqueue) {
		flush_workqueue(ois_workqueue);
		destroy_workqueue(ois_workqueue);
		ois_workqueue = NULL;
	}
	/* ------------------------- */

#ifdef CONFIG_AF_NOISE_ELIMINATION
	spin_lock(&g_AF_SpinLock);
	if(Close_holder == VIB_HOLD){
		spin_unlock(&g_AF_SpinLock);
		LOG_INF("pm_relax vib_wakelock\n");
		__pm_relax(&vib_wakelock);
	}else{
		spin_unlock(&g_AF_SpinLock);
	}
#endif
	LOG_INF("End\n");

	return 0;
}

static const struct file_operations g_stAF_fops = {
	.owner = THIS_MODULE,
	.open = AF_Open,
	.release = AF_Release,
	.unlocked_ioctl = AF_Ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl = AF_Ioctl_Compat,
#endif
};

static inline int Register_AF_CharDrv(void)
{
	LOG_INF("Start\n");

	/* Allocate char driver no. */
	if (alloc_chrdev_region(&g_AF_devno, 0, 1, AF_DRVNAME)) {
		LOG_INF("Allocate device no failed\n");

		return -EAGAIN;
	}
	/* Allocate driver */
	g_pAF_CharDrv = cdev_alloc();

	if (g_pAF_CharDrv == NULL) {
		unregister_chrdev_region(g_AF_devno, 1);

		LOG_INF("Allocate mem for kobject failed\n");

		return -ENOMEM;
	}
	/* Attatch file operation. */
	cdev_init(g_pAF_CharDrv, &g_stAF_fops);

	g_pAF_CharDrv->owner = THIS_MODULE;

	/* Add to system */
	if (cdev_add(g_pAF_CharDrv, g_AF_devno, 1)) {
		LOG_INF("Attatch file operation failed\n");

		unregister_chrdev_region(g_AF_devno, 1);

		return -EAGAIN;
	}

	actuator_class = class_create(THIS_MODULE, AF_DRIVER_CLASS_NAME);
	if (IS_ERR(actuator_class)) {
		int ret = PTR_ERR(actuator_class);

		LOG_INF("Unable to create class, err = %d\n", ret);
		return ret;
	}

	lens_device = device_create(actuator_class, NULL, g_AF_devno, NULL,
				    AF_DRVNAME);

	if (lens_device == NULL)
		return -EIO;

	LOG_INF("End\n");
	return 0;
}

static inline void Unregister_AF_CharDrv(void)
{
	LOG_INF("Start\n");

	/* Release char driver */
	cdev_del(g_pAF_CharDrv);

	unregister_chrdev_region(g_AF_devno, 1);

	device_destroy(actuator_class, g_AF_devno);

	class_destroy(actuator_class);

	LOG_INF("End\n");
}

/* //////////////////////////////////////////////////////////////////// */

static int AF_i2c_probe(struct i2c_client *client,
			const struct i2c_device_id *id);
static int AF_i2c_remove(struct i2c_client *client);
static const struct i2c_device_id AF_i2c_id[] = {{AF_DRVNAME, 0}, {} };

/* TOOL : kernel-3.10\tools\dct */
/* PATH : vendor\mediatek\proprietary\custom\#project#\kernel\dct\dct */
#if I2C_CONFIG_SETTING == 2
static const struct of_device_id MAINAF_of_match[] = {
	{.compatible = "mediatek,CAMERA_MAIN_AF"}, {},
};
#endif

static struct i2c_driver AF_i2c_driver = {
	.probe = AF_i2c_probe,
	.remove = AF_i2c_remove,
	.driver.name = AF_DRVNAME,
#if I2C_CONFIG_SETTING == 2
	.driver.of_match_table = MAINAF_of_match,
#endif
	.id_table = AF_i2c_id,
};

static int AF_i2c_remove(struct i2c_client *client)
{
	Unregister_AF_CharDrv();
	return 0;
}

/* Kirby: add new-style driver {*/
static int AF_i2c_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	int i4RetValue = 0;

	LOG_INF("Start\n");

	/* Kirby: add new-style driver { */
	g_pstAF_I2Cclient = client;

	/* Register char driver */
	i4RetValue = Register_AF_CharDrv();

	if (i4RetValue) {

		LOG_INF(" register char device failed!\n");

		return i4RetValue;
	}
#if defined(CONFIG_MOT_CANCUNF_CAMERA_PROJECT) || defined(CONFIG_MOT_CANCUNN_CAMERA_PROJECT)
	aw86006_ois_init(g_pstAF_I2Cclient);
#endif
	spin_lock_init(&g_AF_SpinLock);

	LOG_INF("Attached!!\n");

	return 0;
}

static int AF_probe(struct platform_device *pdev)
{
	return i2c_add_driver(&AF_i2c_driver);
}

static int AF_remove(struct platform_device *pdev)
{
	i2c_del_driver(&AF_i2c_driver);
	return 0;
}

static int AF_suspend(struct platform_device *pdev, pm_message_t mesg)
{
	return 0;
}

static int AF_resume(struct platform_device *pdev)
{
	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id gaf_of_device_id[] = {
	{.compatible = "mediatek,camera_af_lens",},
	{}
};
#endif

/* platform structure */
static struct platform_driver g_stAF_Driver = {
	.probe = AF_probe,
	.remove = AF_remove,
	.suspend = AF_suspend,
	.resume = AF_resume,
	.driver = {
		.name = PLATFORM_DRIVER_NAME,
		.owner = THIS_MODULE,
#ifdef CONFIG_OF
		.of_match_table = gaf_of_device_id,
#endif
	} };

static struct platform_device g_stAF_device = {
	.name = PLATFORM_DRIVER_NAME, .id = 0, .dev = {} };

static int __init MAINAF_i2C_init(void)
{
#if I2C_CONFIG_SETTING == 1
	i2c_register_board_info(LENS_I2C_BUSNUM, &kd_lens_dev, 1);
#endif

	if (platform_device_register(&g_stAF_device)) {
		LOG_INF("failed to register AF driver\n");
		return -ENODEV;
	}

	if (platform_driver_register(&g_stAF_Driver)) {
		LOG_INF("Failed to register AF driver\n");
		return -ENODEV;
	}

#ifdef CONFIG_AF_NOISE_ELIMINATION
	memset(&vib_wakelock,0,sizeof(vib_wakelock));
	vib_wakelock.name = "vibrator_noise_elimination";
	wakeup_source_add(&vib_wakelock);
#endif
	return 0;
}

static void __exit MAINAF_i2C_exit(void)
{
	platform_driver_unregister(&g_stAF_Driver);
	platform_device_unregister(&g_stAF_device);
#ifdef CONFIG_AF_NOISE_ELIMINATION
	__pm_relax(&vib_wakelock);
	wakeup_source_remove(&vib_wakelock);
#endif
}
module_init(MAINAF_i2C_init);
module_exit(MAINAF_i2C_exit);

MODULE_DESCRIPTION("MAINAF lens module driver");
MODULE_AUTHOR("KY Chen <ky.chen@Mediatek.com>");
MODULE_LICENSE("GPL");