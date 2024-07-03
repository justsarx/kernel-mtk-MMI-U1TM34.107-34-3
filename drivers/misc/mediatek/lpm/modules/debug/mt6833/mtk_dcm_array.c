// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2019 MediaTek Inc.
 */

/* This file is generated by GenLP_setting.pl v1.5.7 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

const unsigned int AP_DCM_Golden_Setting_tcl_gs_dpidle_data[] = {
/*	Address		Mask		Golden Setting Value */
	0x0C530230, 0x00000001, 0x00000000,/* CPU_STALL_DCM_CTRL */
	0x0C530A30, 0x00000001, 0x00000000,/* CPU_STALL_DCM_CTRL */
	0x0C531230, 0x00000001, 0x00000000,/* CPU_STALL_DCM_CTRL */
	0x0C531A30, 0x00000001, 0x00000000,/* CPU_STALL_DCM_CTRL */
	0x0C532230, 0x00000001, 0x00000000,/* CPU_STALL_DCM_CTRL */
	0x0C532A30, 0x00000001, 0x00000000,/* CPU_STALL_DCM_CTRL */
	0x0C533230, 0x00000003, 0x00000000,/* STALL_DCM_CONF */
	0x0C533A30, 0x00000003, 0x00000000,/* STALL_DCM_CONF */
	0x0C53A2E0, 0x80000000, 0x80000000,/* BUS_PLLDIV_CFG */
	0x0C53A440, 0x0000FFFF, 0x0000FFFF,/* MCSIC_DCM0 */
	0x0C53A500, 0x00020000, 0x00020000,/* MP_ADB_DCM_CFG0 */
	0x0C53A510, 0x00278000, 0x00278000,/* MP_ADB_DCM_CFG4 */
	0x0C53A518, 0x0000003A, 0x0000003A,/* MP_MISC_DCM_CFG0 */
	0x0C53A5C0, 0x00078100, 0x00078100,/* MCUSYS_DCM_CFG0 */
	0x0C53A900, 0x0000000F, 0x0000000F,/* EMI_WFIFO */
	0x0C53C880, 0x0001000F, 0x0001000F,/* MP0_DCM_CFG0 */
	0x0C53C89C, 0x00000011, 0x00000011,/* MP0_DCM_CFG7 */
	0x0D0A007C, 0x00000002, 0x00000000,/* dbg_mode */
	0x10001070, 0xC0D07FFB, 0xC0D00603,/* INFRA_BUS_DCM_CTRL */
	0x10001074, 0xA03FFFFB, 0xA03F83E3,/* PERI_BUS_DCM_CTRL */
	0x100010A0, 0x0000000F, 0x00000000,/* P2P_RX_CLK_ON */
	0x100010A4, 0x00000100, 0x00000100,/* MODULE_SW_CG_2_SET */
	0x100010A8, 0x00000100, 0x00000000,/* MODULE_SW_CG_2_CLR */
	0x10001A30, 0x0007F000, 0x00030000,/* INFRA_AXIMEM_IDLE_BIT_EN_0 */
	0x10002028, 0x0000007E, 0x0000007E,/* INFRA_EMI_DCM_CFG0 */
	0x1000202C, 0xFFFFFFFF, 0x40388000,/* INFRA_EMI_DCM_CFG1 */
	0x10002034, 0xFFFFFFFF, 0x000000FF,/* INFRA_EMI_DCM_CFG3 */
	0x10002038, 0xFFFFFFFF, 0x00000007,/* TOP_CK_ANCHOR_CFG */
	0x1000A000, 0x80000000, 0x80000000,/* SEJ_CON */
	0x1001A208, 0x0000FFFF, 0x0000FFFF,/* DXCC_NEW_HWDCM_CFG */
	0x10022034, 0x10000003, 0x10000003,/* VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_0 */
	0x10022038, 0x040003E0, 0x04000000,/* VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_1 */
	0x1002203C, 0x000003E0, 0x00000000,/* VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_2 */
	0x10022058, 0x00400000, 0x00400000,/* VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_9 */
	0x1002205C, 0x00001000, 0x00001000,/* VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_10 */
	0x102280F0, 0x00000007, 0x00000007,/* GCE_CTL_INT0 */
	0x10309300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1030A300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1030B300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1030C300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x10728F88, 0x00000007, 0x00000007,/* I3C0_CHN_HW_CG_EN */
	0x10729F88, 0x00000007, 0x00000007,/* I2C1_CHN_HW_CG_EN */
	0x10943008, 0x40000FFF, 0x40000FFF,/* SSPM_DCM_CTRL */
	0x11200700, 0x000F0000, 0x00000000,/* RESREG */
	0x112300B4, 0xFFA00000, 0x00000000,/* PATCH_BIT1 */
	0x11C10480, 0x00000007, 0x00000007,/* DCM_ON */
	0x11FA0014, 0x08000000, 0x00000000,/* MP_GLB_DIG_14 */
	0x13FBF010, 0x0003FF7F, 0x0000C03F,/* MFG_DCM_CON_0 */
	0x13FBF024, 0x00000001, 0x00000001,/* MFG_ASYNC_CON_1 */
	0x13FBF0B0, 0x00000700, 0x00000000,/* MFG_GLOBAL_CON */
	0x13FBF0B4, 0x00000010, 0x00000010,/* MFG_QCHANNEL_CON */
	0x14000120, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_1ST_DIS0 */
	0x14000130, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_1ST_DIS1 */
	0x14000140, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_2ND_DIS0 */
	0x14000150, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_2ND_DIS1 */
	0x140001B0, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_1ST_DIS2 */
	0x140001C0, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_2ND_DIS2 */
	0x14002300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x14003014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x14004014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1400E1F0, 0xFFFFFFFF, 0x00000000,/* DISP_POSTMASK_FUNC_DCM0 */
	0x1400E1F4, 0xFFFFFFFF, 0x00000000,/* DISP_POSTMASK_FUNC_DCM1 */
	0x14016050, 0x007FFFFF, 0x00000000,/* MMU_DCM_DIS */
	0x1401B300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1401C300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1401E300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1502E014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1502F300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1582E014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1602E014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1602F018, 0x00000001, 0x00000000,/* VDEC_DCM_CON */
	0x1602F218, 0x00000001, 0x00000000,/* LAT_DCM_CON */
	0x17010014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x17030300, 0x00000001, 0x00000000,/* JPGENC_DCM_CTRL */
	0x1A001014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1A002014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1A00C300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1A00D300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1A00F014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1A010014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1B00E300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1B00F014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1B10F014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1F000150, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS0 */
	0x1F000160, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS1 */
	0x1F000170, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS2 */
	0x1F000180, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS3 */
	0x1F000190, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS4 */
	0x1F0001A0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS0 */
	0x1F0001B0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS1 */
	0x1F0001C0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS2 */
	0x1F0001D0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS3 */
	0x1F0001E0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS4 */
	0x1F002014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
};

const unsigned int *AP_DCM_Golden_Setting_tcl_gs_dpidle =
		AP_DCM_Golden_Setting_tcl_gs_dpidle_data;

unsigned int AP_DCM_Golden_Setting_tcl_gs_dpidle_len = 282;

const unsigned int AP_DCM_Golden_Setting_tcl_gs_suspend_data[] = {
/*	Address		Mask		Golden Setting Value */
	0x0C530230, 0x00000001, 0x00000000,/* CPU_STALL_DCM_CTRL */
	0x0C530A30, 0x00000001, 0x00000000,/* CPU_STALL_DCM_CTRL */
	0x0C531230, 0x00000001, 0x00000000,/* CPU_STALL_DCM_CTRL */
	0x0C531A30, 0x00000001, 0x00000000,/* CPU_STALL_DCM_CTRL */
	0x0C532230, 0x00000001, 0x00000000,/* CPU_STALL_DCM_CTRL */
	0x0C532A30, 0x00000001, 0x00000000,/* CPU_STALL_DCM_CTRL */
	0x0C533230, 0x00000003, 0x00000000,/* STALL_DCM_CONF */
	0x0C533A30, 0x00000003, 0x00000000,/* STALL_DCM_CONF */
	0x0C53A2E0, 0x80000000, 0x80000000,/* BUS_PLLDIV_CFG */
	0x0C53A440, 0x0000FFFF, 0x0000FFFF,/* MCSIC_DCM0 */
	0x0C53A500, 0x00020000, 0x00020000,/* MP_ADB_DCM_CFG0 */
	0x0C53A510, 0x00278000, 0x00278000,/* MP_ADB_DCM_CFG4 */
	0x0C53A518, 0x0000003A, 0x0000003A,/* MP_MISC_DCM_CFG0 */
	0x0C53A5C0, 0x00078100, 0x00078100,/* MCUSYS_DCM_CFG0 */
	0x0C53A900, 0x0000000F, 0x0000000F,/* EMI_WFIFO */
	0x0C53C880, 0x0001000F, 0x0001000F,/* MP0_DCM_CFG0 */
	0x0C53C89C, 0x00000011, 0x00000011,/* MP0_DCM_CFG7 */
	0x0D0A007C, 0x00000002, 0x00000000,/* dbg_mode */
	0x10001070, 0xC0D07FFB, 0xC0D00603,/* INFRA_BUS_DCM_CTRL */
	0x10001074, 0xA03FFFFB, 0xA03F83E3,/* PERI_BUS_DCM_CTRL */
	0x100010A0, 0x0000000F, 0x00000000,/* P2P_RX_CLK_ON */
	0x100010A4, 0x00000100, 0x00000100,/* MODULE_SW_CG_2_SET */
	0x100010A8, 0x00000100, 0x00000000,/* MODULE_SW_CG_2_CLR */
	0x10001A30, 0x0007F000, 0x00030000,/* INFRA_AXIMEM_IDLE_BIT_EN_0 */
	0x10002028, 0x0000007E, 0x0000007E,/* INFRA_EMI_DCM_CFG0 */
	0x1000202C, 0xFFFFFFFF, 0x40388000,/* INFRA_EMI_DCM_CFG1 */
	0x10002034, 0xFFFFFFFF, 0x000000FF,/* INFRA_EMI_DCM_CFG3 */
	0x10002038, 0xFFFFFFFF, 0x00000007,/* TOP_CK_ANCHOR_CFG */
	0x1000A000, 0x80000000, 0x80000000,/* SEJ_CON */
	0x1001A208, 0x0000FFFF, 0x0000FFFF,/* DXCC_NEW_HWDCM_CFG */
	0x10022034, 0x10000003, 0x10000003,/* VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_0 */
	0x10022038, 0x040003E0, 0x04000000,/* VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_1 */
	0x1002203C, 0x000003E0, 0x00000000,/* VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_2 */
	0x10022058, 0x00400000, 0x00400000,/* VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_9 */
	0x1002205C, 0x00001000, 0x00001000,/* VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_10 */
	0x102280F0, 0x00000007, 0x00000007,/* GCE_CTL_INT0 */
	0x10309300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1030A300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1030B300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1030C300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x10728F88, 0x00000007, 0x00000007,/* I3C0_CHN_HW_CG_EN */
	0x10729F88, 0x00000007, 0x00000007,/* I2C1_CHN_HW_CG_EN */
	0x10943008, 0x40000FFF, 0x40000FFF,/* SSPM_DCM_CTRL */
	0x11200700, 0x000F0000, 0x00000000,/* RESREG */
	0x112300B4, 0xFFA00000, 0x00000000,/* PATCH_BIT1 */
	0x11C10480, 0x00000007, 0x00000007,/* DCM_ON */
	0x11FA0014, 0x08000000, 0x00000000,/* MP_GLB_DIG_14 */
	0x13FBF010, 0x0003FF7F, 0x0000C03F,/* MFG_DCM_CON_0 */
	0x13FBF024, 0x00000001, 0x00000001,/* MFG_ASYNC_CON_1 */
	0x13FBF0B0, 0x00000700, 0x00000000,/* MFG_GLOBAL_CON */
	0x13FBF0B4, 0x00000010, 0x00000010,/* MFG_QCHANNEL_CON */
	0x14000120, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_1ST_DIS0 */
	0x14000130, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_1ST_DIS1 */
	0x14000140, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_2ND_DIS0 */
	0x14000150, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_2ND_DIS1 */
	0x140001B0, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_1ST_DIS2 */
	0x140001C0, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_2ND_DIS2 */
	0x14002300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x14003014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x14004014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1400E1F0, 0xFFFFFFFF, 0x00000000,/* DISP_POSTMASK_FUNC_DCM0 */
	0x1400E1F4, 0xFFFFFFFF, 0x00000000,/* DISP_POSTMASK_FUNC_DCM1 */
	0x14016050, 0x007FFFFF, 0x00000000,/* MMU_DCM_DIS */
	0x1401B300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1401C300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1401E300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1502E014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1502F300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1582E014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1602E014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1602F018, 0x00000001, 0x00000000,/* VDEC_DCM_CON */
	0x1602F218, 0x00000001, 0x00000000,/* LAT_DCM_CON */
	0x17010014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x17030300, 0x00000001, 0x00000000,/* JPGENC_DCM_CTRL */
	0x1A001014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1A002014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1A00C300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1A00D300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1A00F014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1A010014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1B00E300, 0x000000FE, 0x00000000,/* SMI_DCM */
	0x1B00F014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1B10F014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
	0x1F000150, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS0 */
	0x1F000160, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS1 */
	0x1F000170, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS2 */
	0x1F000180, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS3 */
	0x1F000190, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS4 */
	0x1F0001A0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS0 */
	0x1F0001B0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS1 */
	0x1F0001C0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS2 */
	0x1F0001D0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS3 */
	0x1F0001E0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS4 */
	0x1F002014, 0x0000FFF0, 0x0000FFF0,/* SMI_LARB_CON_SET */
};

const unsigned int *AP_DCM_Golden_Setting_tcl_gs_suspend =
		AP_DCM_Golden_Setting_tcl_gs_suspend_data;

unsigned int AP_DCM_Golden_Setting_tcl_gs_suspend_len = 282;

const unsigned int AP_DCM_Golden_Setting_tcl_gs_sodi_data[] = {
/*	Address		Mask		Golden Setting Value */
	0x0D0A007C, 0x00000002, 0x00000000,/* dbg_mode */
	0x1001A208, 0x0000FFFF, 0x0000FFFF,/* DXCC_NEW_HWDCM_CFG */
	0x10943008, 0x40000FFF, 0x40000FFF,/* SSPM_DCM_CTRL */
	0x112300B4, 0xFFA00000, 0x00000000,/* PATCH_BIT1 */
	0x11C10480, 0x00000007, 0x00000007,/* DCM_ON */
	0x14000120, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_1ST_DIS0 */
	0x14000130, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_1ST_DIS1 */
	0x14000140, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_2ND_DIS0 */
	0x14000150, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_2ND_DIS1 */
	0x140001B0, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_1ST_DIS2 */
	0x140001C0, 0xFFFFFFFF, 0x00000000,/* MMSYS_HW_DCM_2ND_DIS2 */
	0x1400E1F0, 0xFFFFFFFF, 0x00000000,/* DISP_POSTMASK_FUNC_DCM0 */
	0x1400E1F4, 0xFFFFFFFF, 0x00000000,/* DISP_POSTMASK_FUNC_DCM1 */
	0x14016050, 0x007FFFFF, 0x00000000,/* MMU_DCM_DIS */
	0x1602F018, 0x00000001, 0x00000000,/* VDEC_DCM_CON */
	0x1602F218, 0x00000001, 0x00000000,/* LAT_DCM_CON */
	0x17030300, 0x00000001, 0x00000000,/* JPGENC_DCM_CTRL */
	0x1F000150, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS0 */
	0x1F000160, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS1 */
	0x1F000170, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS2 */
	0x1F000180, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS3 */
	0x1F000190, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_1ST_DIS4 */
	0x1F0001A0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS0 */
	0x1F0001B0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS1 */
	0x1F0001C0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS2 */
	0x1F0001D0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS3 */
	0x1F0001E0, 0xFFFFFFFF, 0x00000000,/* MDPSYS_HW_DCM_2ND_DIS4 */
};

const unsigned int *AP_DCM_Golden_Setting_tcl_gs_sodi =
		AP_DCM_Golden_Setting_tcl_gs_sodi_data;

unsigned int AP_DCM_Golden_Setting_tcl_gs_sodi_len = 90;
