/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2017 MediaTek Inc.
 */

#ifndef _MTK_MDPM_PLATFORM_H_
#define _MTK_MDPM_PLATFORM_H_

#include <mtk_mdpm_api.h>
#define POWER_TYPE_NUM 2
#define MD_POWER_METER_ENABLE 1

#if MD_POWER_METER_ENABLE
/* #define MD_POWER_UT */
#endif

#define MAX_MD1_POWER	4000	/* mW */
#define MAX_DBM_POWER	\
	(MAX_PW_MD1_PA_4G_upL1_SECTION_1 + MAX_PW_MD1_RF_4G_upL1_SECTION_1)

#define GUARDING_PATTERN	0

#define SECTION_LEN	0xFFFFFFFF
/* total 4 byte, 6 section =  11 11111 11111 11111 11111 11111 11111 */
#define SECTION_VALUE	0x1F
/* each section is 0x1F = bit(11111) */

enum section_level_tbl {
	BIT_SECTION_1 = 0,
	BIT_SECTION_2 = 5,
	BIT_SECTION_3 = 10,
	BIT_SECTION_4 = 15,
	BIT_SECTION_5 = 20,
	BIT_SECTION_6 = 25,
	SECTION_NUM = 6
};

enum md1_scenario {
	S_STANDBY = 0,
	S_4G_DL_1CC,
	S_2G_CONNECT,
	S_3G_C2K_TALKING,
	S_3G_4G_C2K_PAGING,
	S_3G_C2K_DATALINK,
	S_C2K_SHDR,
	S_4G_DL_2CC,
	SCENARIO_NUM
};

enum share_mem_mapping {	/* each of 4 byte */
	DBM_2G_TABLE = 0,
	DBM_3G_TABLE,
	DBM_4G_TABLE,
	DBM_4G_1_TABLE,
	DBM_4G_2_TABLE,
	DBM_4G_3_TABLE,
	DBM_4G_4_TABLE,
	DBM_4G_5_TABLE,
	DBM_4G_6_TABLE,
	DBM_4G_7_TABLE,
	DBM_4G_8_TABLE,
	DBM_4G_9_TABLE,
	DBM_4G_10_TABLE,
	DBM_4G_11_TABLE,
	DBM_4G_12_TABLE,
	DBM_TDD_TABLE,
	DBM_C2K_1_TABLE,
	DBM_C2K_2_TABLE,
	DBM_C2K_3_TABLE,
	DBM_C2K_4_TABLE,
	SECTION_LEVLE_2G,
	SECTION_LEVLE_3G,
	SECTION_LEVLE_4G,
	SECTION_1_LEVLE_4G,
	SECTION_2_LEVLE_4G,
	SECTION_3_LEVLE_4G,
	SECTION_4_LEVLE_4G,
	SECTION_5_LEVLE_4G,
	SECTION_6_LEVLE_4G,
	SECTION_7_LEVLE_4G,
	SECTION_8_LEVLE_4G,
	SECTION_9_LEVLE_4G,
	SECTION_10_LEVLE_4G,
	SECTION_11_LEVLE_4G,
	SECTION_12_LEVLE_4G,
	SECTION_LEVLE_TDD,
	SECTION_1_LEVLE_C2K,
	SECTION_2_LEVLE_C2K,
	SECTION_3_LEVLE_C2K,
	SECTION_4_LEVLE_C2K,
	SHARE_MEM_BLOCK_NUM
};

/*
 * MD1 Section level (can't more than SECTION_VALUE)
 */
/* Each section has only 5 bits. The range is from 0 to 31 */

//Samuel: move to platform
enum md1_section_level_tbl_2g {
	VAL_MD1_2G_SECTION_1 = 31,
	VAL_MD1_2G_SECTION_2 = 29,
	VAL_MD1_2G_SECTION_3 = 27,
	VAL_MD1_2G_SECTION_4 = 21,
	VAL_MD1_2G_SECTION_5 = 15,
	VAL_MD1_2G_SECTION_6 = 0
};

enum md1_section_level_tbl_3g {
	VAL_MD1_3G_SECTION_1 = 21,
	VAL_MD1_3G_SECTION_2 = 20,
	VAL_MD1_3G_SECTION_3 = 19,
	VAL_MD1_3G_SECTION_4 = 16,
	VAL_MD1_3G_SECTION_5 = 13,
	VAL_MD1_3G_SECTION_6 = 0
};

enum md1_section_level_tbl_4g_upL1 {
	VAL_MD1_4G_upL1_SECTION_1 = 20,
	VAL_MD1_4G_upL1_SECTION_2 = 18,
	VAL_MD1_4G_upL1_SECTION_3 = 16,
	VAL_MD1_4G_upL1_SECTION_4 = 14,
	VAL_MD1_4G_upL1_SECTION_5 = 11,
	VAL_MD1_4G_upL1_SECTION_6 = 0
};

enum md1_section_level_tbl_4g_upL2 {
	VAL_MD1_4G_upL2_SECTION_1 = 20,
	VAL_MD1_4G_upL2_SECTION_2 = 18,
	VAL_MD1_4G_upL2_SECTION_3 = 16,
	VAL_MD1_4G_upL2_SECTION_4 = 14,
	VAL_MD1_4G_upL2_SECTION_5 = 11,
	VAL_MD1_4G_upL2_SECTION_6 = 0
};

enum md1_section_level_tbl_tdd {
	VAL_MD1_TDD_SECTION_1 = 21,
	VAL_MD1_TDD_SECTION_2 = 19,
	VAL_MD1_TDD_SECTION_3 = 18,
	VAL_MD1_TDD_SECTION_4 = 16,
	VAL_MD1_TDD_SECTION_5 = 13,
	VAL_MD1_TDD_SECTION_6 = 0
};

enum md1_section_level_tbl_c2k {
	VAL_MD1_C2K_SECTION_1 = 23,
	VAL_MD1_C2K_SECTION_2 = 22,
	VAL_MD1_C2K_SECTION_3 = 20,
	VAL_MD1_C2K_SECTION_4 = 17,
	VAL_MD1_C2K_SECTION_5 = 16,
	VAL_MD1_C2K_SECTION_6 = 0
};

/*
 * MD1 Scenario power
 */

enum md1_scenario_max_pwr_tbl {
	MAX_PW_STANDBY = 1,
	MAX_PW_4G_DL_1CC = 210,
	MAX_PW_2G_CONNECT = 36,
	MAX_PW_3G_C2K_TALKING = 78,
	MAX_PW_3G_4G_C2K_PAGING = 2,
	MAX_PW_3G_C2K_DATALINK = 190,
	MAX_PW_C2K_SHDR = 27,
	MAX_PW_4G_DL_2CC = 342
};

enum md1_scenario_avg_pwr_tbl {
	AVG_PW_STANDBY = 1,
	AVG_PW_4G_DL_1CC = 210,
	AVG_PW_2G_CONNECT = 36,
	AVG_PW_3G_C2K_TALKING = 78,
	AVG_PW_3G_4G_C2K_PAGING = 2,
	AVG_PW_3G_C2K_DATALINK = 190,
	AVG_PW_C2K_SHDR = 27,
	AVG_PW_4G_DL_2CC = 342
};

/*
 * MD1 PA power
 */

enum md1_pa_max_pwr_tbl_2g {
	MAX_PW_MD1_PA_2G_SECTION_1 = 800,
	MAX_PW_MD1_PA_2G_SECTION_2 = 388,
	MAX_PW_MD1_PA_2G_SECTION_3 = 300,
	MAX_PW_MD1_PA_2G_SECTION_4 = 248,
	MAX_PW_MD1_PA_2G_SECTION_5 = 132,
	MAX_PW_MD1_PA_2G_SECTION_6 = 92
};

enum md1_pa_avg_pwr_tbl_2g {
	AVG_PW_MD1_PA_2G_SECTION_1 = 800,
	AVG_PW_MD1_PA_2G_SECTION_2 = 388,
	AVG_PW_MD1_PA_2G_SECTION_3 = 300,
	AVG_PW_MD1_PA_2G_SECTION_4 = 248,
	AVG_PW_MD1_PA_2G_SECTION_5 = 132,
	AVG_PW_MD1_PA_2G_SECTION_6 = 92
};

enum md1_pa_max_pwr_tbl_3g {
	MAX_PW_MD1_PA_3G_SECTION_1 = 1745,
	MAX_PW_MD1_PA_3G_SECTION_2 = 1260,
	MAX_PW_MD1_PA_3G_SECTION_3 = 966,
	MAX_PW_MD1_PA_3G_SECTION_4 = 614,
	MAX_PW_MD1_PA_3G_SECTION_5 = 352,
	MAX_PW_MD1_PA_3G_SECTION_6 = 190
};

enum md1_pa_avg_pwr_tbl_3g {
	AVG_PW_MD1_PA_3G_SECTION_1 = 1745,
	AVG_PW_MD1_PA_3G_SECTION_2 = 1260,
	AVG_PW_MD1_PA_3G_SECTION_3 = 966,
	AVG_PW_MD1_PA_3G_SECTION_4 = 614,
	AVG_PW_MD1_PA_3G_SECTION_5 = 352,
	AVG_PW_MD1_PA_3G_SECTION_6 = 190
};

enum md1_pa_max_pwr_tbl_4g_upL1 {
	MAX_PW_MD1_PA_4G_upL1_SECTION_1 = 1962,
	MAX_PW_MD1_PA_4G_upL1_SECTION_2 = 1530,
	MAX_PW_MD1_PA_4G_upL1_SECTION_3 = 1083,
	MAX_PW_MD1_PA_4G_upL1_SECTION_4 = 564,
	MAX_PW_MD1_PA_4G_upL1_SECTION_5 = 360,
	MAX_PW_MD1_PA_4G_upL1_SECTION_6 = 194
};

enum md1_pa_avg_pwr_tbl_4g_upL1 {
	AVG_PW_MD1_PA_4G_upL1_SECTION_1 = 1962,
	AVG_PW_MD1_PA_4G_upL1_SECTION_2 = 1530,
	AVG_PW_MD1_PA_4G_upL1_SECTION_3 = 1083,
	AVG_PW_MD1_PA_4G_upL1_SECTION_4 = 564,
	AVG_PW_MD1_PA_4G_upL1_SECTION_5 = 360,
	AVG_PW_MD1_PA_4G_upL1_SECTION_6 = 194
};

enum md1_pa_max_pwr_tbl_4g_upL2 {
	MAX_PW_MD1_PA_4G_upL2_SECTION_1 = 1962,
	MAX_PW_MD1_PA_4G_upL2_SECTION_2 = 1530,
	MAX_PW_MD1_PA_4G_upL2_SECTION_3 = 1083,
	MAX_PW_MD1_PA_4G_upL2_SECTION_4 = 564,
	MAX_PW_MD1_PA_4G_upL2_SECTION_5 = 360,
	MAX_PW_MD1_PA_4G_upL2_SECTION_6 = 194
};

enum md1_pa_avg_pwr_tbl_4g_upL2 {
	AVG_PW_MD1_PA_4G_upL2_SECTION_1 = 1962,
	AVG_PW_MD1_PA_4G_upL2_SECTION_2 = 1530,
	AVG_PW_MD1_PA_4G_upL2_SECTION_3 = 1083,
	AVG_PW_MD1_PA_4G_upL2_SECTION_4 = 564,
	AVG_PW_MD1_PA_4G_upL2_SECTION_5 = 360,
	AVG_PW_MD1_PA_4G_upL2_SECTION_6 = 194
};

enum md1_max_pa_pwr_tbl_c2k {
	MAX_PW_MD1_PA_C2K_SECTION_1 = 2084,
	MAX_PW_MD1_PA_C2K_SECTION_2 = 1548,
	MAX_PW_MD1_PA_C2K_SECTION_3 = 1146,
	MAX_PW_MD1_PA_C2K_SECTION_4 = 767,
	MAX_PW_MD1_PA_C2K_SECTION_5 = 535,
	MAX_PW_MD1_PA_C2K_SECTION_6 = 329
};

enum md1_avg_pa_pwr_tbl_c2k {
	AVG_PW_MD1_PA_C2K_SECTION_1 = 2084,
	AVG_PW_MD1_PA_C2K_SECTION_2 = 1548,
	AVG_PW_MD1_PA_C2K_SECTION_3 = 1146,
	AVG_PW_MD1_PA_C2K_SECTION_4 = 767,
	AVG_PW_MD1_PA_C2K_SECTION_5 = 535,
	AVG_PW_MD1_PA_C2K_SECTION_6 = 329
};

/*
 * MD1 RF power
 */
enum md1_max_rf_pwr_tbl_2g {
	MAX_PW_MD1_RF_2G_SECTION_1 = 40,
	MAX_PW_MD1_RF_2G_SECTION_2 = 40,
	MAX_PW_MD1_RF_2G_SECTION_3 = 40,
	MAX_PW_MD1_RF_2G_SECTION_4 = 40,
	MAX_PW_MD1_RF_2G_SECTION_5 = 40,
	MAX_PW_MD1_RF_2G_SECTION_6 = 40
};

enum md1_avg_rf_pwr_tbl_2g {
	AVG_PW_MD1_RF_2G_SECTION_1 = 40,
	AVG_PW_MD1_RF_2G_SECTION_2 = 40,
	AVG_PW_MD1_RF_2G_SECTION_3 = 40,
	AVG_PW_MD1_RF_2G_SECTION_4 = 40,
	AVG_PW_MD1_RF_2G_SECTION_5 = 40,
	AVG_PW_MD1_RF_2G_SECTION_6 = 40
};

enum md1_rf_max_pwr_tbl_3g {
	MAX_PW_MD1_RF_3G_SECTION_1 = 158,
	MAX_PW_MD1_RF_3G_SECTION_2 = 154,
	MAX_PW_MD1_RF_3G_SECTION_3 = 142,
	MAX_PW_MD1_RF_3G_SECTION_4 = 138,
	MAX_PW_MD1_RF_3G_SECTION_5 = 134,
	MAX_PW_MD1_RF_3G_SECTION_6 = 133
};

enum md1_rf_avg_pwr_tbl_3g {
	AVG_PW_MD1_RF_3G_SECTION_1 = 158,
	AVG_PW_MD1_RF_3G_SECTION_2 = 154,
	AVG_PW_MD1_RF_3G_SECTION_3 = 142,
	AVG_PW_MD1_RF_3G_SECTION_4 = 138,
	AVG_PW_MD1_RF_3G_SECTION_5 = 134,
	AVG_PW_MD1_RF_3G_SECTION_6 = 133
};

enum md1_rf_max_pwr_tbl_4g_upL1 {
	MAX_PW_MD1_RF_4G_upL1_SECTION_1 = 261,
	MAX_PW_MD1_RF_4G_upL1_SECTION_2 = 225,
	MAX_PW_MD1_RF_4G_upL1_SECTION_3 = 220,
	MAX_PW_MD1_RF_4G_upL1_SECTION_4 = 217,
	MAX_PW_MD1_RF_4G_upL1_SECTION_5 = 190,
	MAX_PW_MD1_RF_4G_upL1_SECTION_6 = 190
};

enum md1_rf_avg_pwr_tbl_4g_upL1 {
	AVG_PW_MD1_RF_4G_upL1_SECTION_1 = 261,
	AVG_PW_MD1_RF_4G_upL1_SECTION_2 = 225,
	AVG_PW_MD1_RF_4G_upL1_SECTION_3 = 220,
	AVG_PW_MD1_RF_4G_upL1_SECTION_4 = 217,
	AVG_PW_MD1_RF_4G_upL1_SECTION_5 = 190,
	AVG_PW_MD1_RF_4G_upL1_SECTION_6 = 190
};

enum md1_rf_max_pwr_tbl_4g_upL2 {
	MAX_PW_MD1_RF_4G_upL2_SECTION_1 = 261,
	MAX_PW_MD1_RF_4G_upL2_SECTION_2 = 225,
	MAX_PW_MD1_RF_4G_upL2_SECTION_3 = 220,
	MAX_PW_MD1_RF_4G_upL2_SECTION_4 = 217,
	MAX_PW_MD1_RF_4G_upL2_SECTION_5 = 190,
	MAX_PW_MD1_RF_4G_upL2_SECTION_6 = 190
};

enum md1_rf_avg_pwr_tbl_4g_upL2 {
	AVG_PW_MD1_RF_4G_upL2_SECTION_1 = 261,
	AVG_PW_MD1_RF_4G_upL2_SECTION_2 = 225,
	AVG_PW_MD1_RF_4G_upL2_SECTION_3 = 220,
	AVG_PW_MD1_RF_4G_upL2_SECTION_4 = 217,
	AVG_PW_MD1_RF_4G_upL2_SECTION_5 = 190,
	AVG_PW_MD1_RF_4G_upL2_SECTION_6 = 190
};

enum md1_rf_max_pwr_tbl_c2k {
	MAX_PW_MD1_RF_C2K_SECTION_1 = 310,
	MAX_PW_MD1_RF_C2K_SECTION_2 = 310,
	MAX_PW_MD1_RF_C2K_SECTION_3 = 310,
	MAX_PW_MD1_RF_C2K_SECTION_4 = 310,
	MAX_PW_MD1_RF_C2K_SECTION_5 = 310,
	MAX_PW_MD1_RF_C2K_SECTION_6 = 310
};

enum md1_rf_avg_pwr_tbl_c2k {
	AVG_PW_MD1_RF_C2K_SECTION_1 = 310,
	AVG_PW_MD1_RF_C2K_SECTION_2 = 310,
	AVG_PW_MD1_RF_C2K_SECTION_3 = 310,
	AVG_PW_MD1_RF_C2K_SECTION_4 = 310,
	AVG_PW_MD1_RF_C2K_SECTION_5 = 310,
	AVG_PW_MD1_RF_C2K_SECTION_6 = 310
};

#define MAX_DBM_FUNC_NUM 5

struct mdpm {
	int scenario_power[POWER_TYPE_NUM];

	int (*dbm_power_func[MAX_DBM_FUNC_NUM])(u32 *, unsigned int);

};

#ifdef MD_POWER_UT
extern void md_power_meter_ut(void);
#endif
extern void init_md1_section_level(u32 *share_mem);
extern unsigned int get_md1_scenario(u32 share_reg,
	enum mdpm_power_type power_type);
extern int get_md1_scenario_power(unsigned int scenario,
	enum mdpm_power_type power_type);
extern int get_md1_dBm_power(unsigned int scenario, u32 *share_mem,
	enum mdpm_power_type power_type);

#endif /* _MTK_MDPM_PLATFORM_H_ */
