/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */
/*****************************************************************************
 *
 * Filename:
 * ---------
 *	 mot_cancunf_s5kjns_Sensor_setting.h
 *
 * Project:
 * --------
 * Description:
 * ------------
 *	 CMOS sensor header file
 *
 ****************************************************************************/
#ifndef _MOT_CANCUNF_S5KJNS_SENSOR_SETTING_H
#define _MOT_CANCUNF_S5KJNS_SENSOR_SETTING_H

kal_uint16 addr_data_pair_init_mot_cancunf_s5kjns[] = {
//init setting
//0x6028, 0x4000,
//0x0000, 0x0001,
//0x0000, 0x38EE,
//0x001E, 0x000B,
//0x6028, 0x4000,
//0x6010, 0x0001,
//p13
//0x6226, 0x0001,
0x6028, 0x2400,
0x602A, 0x35CC,
0x6F12, 0x1C80,
0x6F12, 0x0024,
0x6F12, 0xA88C,
0x6F12, 0x0024,
0x602A, 0x1354,
0x6F12, 0x0100,
0x6F12, 0x7017,
0x602A, 0x13B2,
0x6F12, 0x0000,
0x602A, 0x1236,
0x6F12, 0x0000,
0x602A, 0x1A0A,
0x6F12, 0x4C0A,
0x602A, 0x2210,
0x6F12, 0x3401,
0x602A, 0x2176,
0x6F12, 0x6400,
0x602A, 0x222E,
0x6F12, 0x0001,
0x602A, 0x06B6,
0x6F12, 0x0A00,
0x602A, 0x06BC,
0x6F12, 0x1001,
0x602A, 0x2140,
0x6F12, 0x0101,
0x602A, 0x1A0E,
0x6F12, 0x9600,
0x602A, 0x19FC,
0x6F12, 0x0B00,
0x6028, 0x4000,
0xF44E, 0x0011,
0xF44C, 0x0B0B,
0xF44A, 0x0006,
0x0118, 0x0002,
0x011A, 0x0001,
0x0FEA, 0x1940,
0x0BCC, 0x0000,
};

/* preview/capture 4080*3060@30fps*/
kal_uint16 addr_data_pair_preview_mot_cancunf_s5kjns[] = {
0x6028, 0x2400,
0x602A, 0x1A28,
0x6F12, 0x4C00,
0x602A, 0x065A,
0x6F12, 0x0000,
0x602A, 0x139E,
0x6F12, 0x0100,
0x602A, 0x139C,
0x6F12, 0x0000,
0x602A, 0x13A0,
0x6F12, 0x0A00,
0x6F12, 0x0120,
0x602A, 0x2072,
0x6F12, 0x0000,
0x602A, 0x1A64,
0x6F12, 0x0301,
0x6F12, 0xFF00,
0x602A, 0x19E6,
0x6F12, 0x0200,
0x602A, 0x1A30,
0x6F12, 0x3401,
0x602A, 0x19F4,
0x6F12, 0x0606,
0x602A, 0x19F8,
0x6F12, 0x1010,
0x602A, 0x1B26,
0x6F12, 0x6F80,
0x6F12, 0xA060,
0x602A, 0x1A3C,
0x6F12, 0x6207,
0x602A, 0x1A48,
0x6F12, 0x6207,
0x602A, 0x1444,
0x6F12, 0x2000,
0x6F12, 0x2000,
0x602A, 0x144C,
0x6F12, 0x3F00,
0x6F12, 0x3F00,
0x602A, 0x7F6C,
0x6F12, 0x0100,
0x6F12, 0x2F00,
0x6F12, 0xFA00,
0x6F12, 0x2400,
0x6F12, 0xE500,
0x602A, 0x0650,
0x6F12, 0x0600,
0x602A, 0x0654,
0x6F12, 0x0000,
0x602A, 0x1A46,
0x6F12, 0x8A00,
0x602A, 0x1A52,
0x6F12, 0xBF00,
0x602A, 0x0674,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x602A, 0x0668,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x602A, 0x0684,
0x6F12, 0x4001,
0x602A, 0x0688,
0x6F12, 0x4001,
0x602A, 0x147C,
0x6F12, 0x1000,
0x602A, 0x1480,
0x6F12, 0x1000,
0x602A, 0x19F6,
0x6F12, 0x0904,
0x602A, 0x0812,
0x6F12, 0x0000,
0x602A, 0x1A02,
0x6F12, 0x1800,
0x602A, 0x2104,
0x6F12, 0x0018,
0x602A, 0x2148,
0x6F12, 0x0100,
0x602A, 0x2042,
0x6F12, 0x1A00,
0x602A, 0x0874,
0x6F12, 0x0100,
0x602A, 0x09C0,
0x6F12, 0x2008,
0x602A, 0x09C4,
0x6F12, 0x2000,
0x602A, 0x19FE,
0x6F12, 0x0E1C,
0x602A, 0x4D92,
0x6F12, 0x0100,
0x602A, 0x8A88,
0x6F12, 0x0100,
0x602A, 0x4D94,
0x6F12, 0x0005,
0x6F12, 0x000A,
0x6F12, 0x0010,
0x6F12, 0x0810,
0x6F12, 0x000A,
0x6F12, 0x0040,
0x6F12, 0x0810,
0x6F12, 0x0810,
0x6F12, 0x8002,
0x6F12, 0xFD03,
0x6F12, 0x0010,
0x6F12, 0x1510,
0x602A, 0x3570,
0x6F12, 0x0000,
0x602A, 0x3574,
0x6F12, 0x0000,
0x602A, 0x21E4,
0x6F12, 0x0400,
0x602A, 0x21EC,
0x6F12, 0x8000,
0x602A, 0x2080,
0x6F12, 0x0101,
0x6F12, 0xFF00,
0x6F12, 0x7F01,
0x6F12, 0x0001,
0x6F12, 0x8001,
0x6F12, 0xD244,
0x6F12, 0xD244,
0x6F12, 0x14F4,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x20BA,
0x6F12, 0x121C,
0x6F12, 0x111C,
0x6F12, 0x54F4,
0x602A, 0x120E,
0x6F12, 0x1000,
0x602A, 0x212E,
0x6F12, 0x0200,
0x602A, 0x13AE,
0x6F12, 0x0101,
0x602A, 0x0718,
0x6F12, 0x0001,
0x602A, 0x0710,
0x6F12, 0x0002,
0x6F12, 0x0804,
0x6F12, 0x0100,
0x602A, 0x1B5C,
0x6F12, 0x0000,
0x602A, 0x0786,
0x6F12, 0x7701,
0x602A, 0x2022,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x602A, 0x1360,
0x6F12, 0x0100,
0x602A, 0x1376,
0x6F12, 0x0100,
0x6F12, 0x6038,
0x6F12, 0x7038,
0x6F12, 0x8038,
0x602A, 0x1386,
0x6F12, 0x0B00,
0x602A, 0x06FA,
0x6F12, 0x0000,
0x602A, 0x4A94,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x0A76,
0x6F12, 0x1000,
0x602A, 0x0AEE,
0x6F12, 0x1000,
0x602A, 0x0B66,
0x6F12, 0x1000,
0x602A, 0x0BDE,
0x6F12, 0x1000,
0x602A, 0x0BE8,
0x6F12, 0x3000,
0x6F12, 0x3000,
0x602A, 0x0C56,
0x6F12, 0x1000,
0x602A, 0x0C60,
0x6F12, 0x3000,
0x6F12, 0x3000,
0x602A, 0x0CB6,
0x6F12, 0x0100,
0x602A, 0x0CF2,
0x6F12, 0x0001,
0x602A, 0x0CF0,
0x6F12, 0x0101,
0x602A, 0x11B8,
0x6F12, 0x0100,
0x602A, 0x11F6,
0x6F12, 0x0020,
0x602A, 0x4A74,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x218E,
0x6F12, 0x0000,
0x602A, 0x2268,
0x6F12, 0xF279,
0x602A, 0x5006,
0x6F12, 0x0000,
0x602A, 0x500E,
0x6F12, 0x0100,
0x602A, 0x4E70,
0x6F12, 0x2062,
0x6F12, 0x5501,
0x602A, 0x06DC,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6028, 0x4000,
0xF46A, 0xAE80,
0x0344, 0x0000,
0x0346, 0x000C,
0x0348, 0x1FFF,
0x034A, 0x1813,
0x034C, 0x0FF0,
0x034E, 0x0BF4,
0x0350, 0x0008,
0x0352, 0x0008,
0x0900, 0x0122,
0x0380, 0x0002,
0x0382, 0x0002,
0x0384, 0x0002,
0x0386, 0x0002,
0x0110, 0x1002,
0x0114, 0x0301,
0x0116, 0x2B00,
0x0136, 0x1800,
0x013E, 0x0000,
0x0300, 0x0006,
0x0302, 0x0001,
0x0304, 0x0004,
0x0306, 0x008C,
0x0308, 0x0008,
0x030A, 0x0001,
0x030C, 0x0000,
0x030E, 0x0004,
0x0310, 0x00A5,
0x0312, 0x0000,
0x080E, 0x0000,
0x0340, 0x1140,
0x0342, 0x1080,
0x0702, 0x0000,
0x0202, 0x0100,
0x0200, 0x0100,
0x0D00, 0x0101,
0x0D02, 0x0101,
0x0D04, 0x0102,
0x6226, 0x0000,
};

/* normal video 4080*2296@30fps*/
kal_uint16 addr_data_pair_normal_video_mot_cancunf_s5kjns[] = {
0x6028, 0x2400,
0x602A, 0x1A28,
0x6F12, 0x4C00,
0x602A, 0x065A,
0x6F12, 0x0000,
0x602A, 0x139E,
0x6F12, 0x0100,
0x602A, 0x139C,
0x6F12, 0x0000,
0x602A, 0x13A0,
0x6F12, 0x0A00,
0x6F12, 0x0120,
0x602A, 0x2072,
0x6F12, 0x0000,
0x602A, 0x1A64,
0x6F12, 0x0301,
0x6F12, 0xFF00,
0x602A, 0x19E6,
0x6F12, 0x0200,
0x602A, 0x1A30,
0x6F12, 0x3401,
0x602A, 0x19F4,
0x6F12, 0x0606,
0x602A, 0x19F8,
0x6F12, 0x1010,
0x602A, 0x1B26,
0x6F12, 0x6F80,
0x6F12, 0xA060,
0x602A, 0x1A3C,
0x6F12, 0x6207,
0x602A, 0x1A48,
0x6F12, 0x6207,
0x602A, 0x1444,
0x6F12, 0x2000,
0x6F12, 0x2000,
0x602A, 0x144C,
0x6F12, 0x3F00,
0x6F12, 0x3F00,
0x602A, 0x7F6C,
0x6F12, 0x0100,
0x6F12, 0x2F00,
0x6F12, 0xFA00,
0x6F12, 0x2400,
0x6F12, 0xE500,
0x602A, 0x0650,
0x6F12, 0x0600,
0x602A, 0x0654,
0x6F12, 0x0000,
0x602A, 0x1A46,
0x6F12, 0x8A00,
0x602A, 0x1A52,
0x6F12, 0xBF00,
0x602A, 0x0674,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x602A, 0x0668,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x602A, 0x0684,
0x6F12, 0x4001,
0x602A, 0x0688,
0x6F12, 0x4001,
0x602A, 0x147C,
0x6F12, 0x1000,
0x602A, 0x1480,
0x6F12, 0x1000,
0x602A, 0x19F6,
0x6F12, 0x0904,
0x602A, 0x0812,
0x6F12, 0x0000,
0x602A, 0x1A02,
0x6F12, 0x1800,
0x602A, 0x2104,
0x6F12, 0x0018,
0x602A, 0x2148,
0x6F12, 0x0100,
0x602A, 0x2042,
0x6F12, 0x1A00,
0x602A, 0x0874,
0x6F12, 0x0100,
0x602A, 0x09C0,
0x6F12, 0x2008,
0x602A, 0x09C4,
0x6F12, 0x2000,
0x602A, 0x19FE,
0x6F12, 0x0E1C,
0x602A, 0x4D92,
0x6F12, 0x0100,
0x602A, 0x8A88,
0x6F12, 0x0100,
0x602A, 0x4D94,
0x6F12, 0x0005,
0x6F12, 0x000A,
0x6F12, 0x0010,
0x6F12, 0x0810,
0x6F12, 0x000A,
0x6F12, 0x0040,
0x6F12, 0x0810,
0x6F12, 0x0810,
0x6F12, 0x8002,
0x6F12, 0xFD03,
0x6F12, 0x0010,
0x6F12, 0x1510,
0x602A, 0x3570,
0x6F12, 0x0000,
0x602A, 0x3574,
0x6F12, 0x0000,
0x602A, 0x21E4,
0x6F12, 0x0400,
0x602A, 0x21EC,
0x6F12, 0x8000,
0x602A, 0x2080,
0x6F12, 0x0101,
0x6F12, 0xFF00,
0x6F12, 0x7F01,
0x6F12, 0x0001,
0x6F12, 0x8001,
0x6F12, 0xD244,
0x6F12, 0xD244,
0x6F12, 0x14F4,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x20BA,
0x6F12, 0x121C,
0x6F12, 0x111C,
0x6F12, 0x54F4,
0x602A, 0x120E,
0x6F12, 0x1000,
0x602A, 0x212E,
0x6F12, 0x0200,
0x602A, 0x13AE,
0x6F12, 0x0101,
0x602A, 0x0718,
0x6F12, 0x0001,
0x602A, 0x0710,
0x6F12, 0x0002,
0x6F12, 0x0804,
0x6F12, 0x0100,
0x602A, 0x1B5C,
0x6F12, 0x0000,
0x602A, 0x0786,
0x6F12, 0x7701,
0x602A, 0x2022,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x602A, 0x1360,
0x6F12, 0x0100,
0x602A, 0x1376,
0x6F12, 0x0100,
0x6F12, 0x6038,
0x6F12, 0x7038,
0x6F12, 0x8038,
0x602A, 0x1386,
0x6F12, 0x0B00,
0x602A, 0x06FA,
0x6F12, 0x0000,
0x602A, 0x4A94,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x0A76,
0x6F12, 0x1000,
0x602A, 0x0AEE,
0x6F12, 0x1000,
0x602A, 0x0B66,
0x6F12, 0x1000,
0x602A, 0x0BDE,
0x6F12, 0x1000,
0x602A, 0x0BE8,
0x6F12, 0x3000,
0x6F12, 0x3000,
0x602A, 0x0C56,
0x6F12, 0x1000,
0x602A, 0x0C60,
0x6F12, 0x3000,
0x6F12, 0x3000,
0x602A, 0x0CB6,
0x6F12, 0x0100,
0x602A, 0x0CF2,
0x6F12, 0x0001,
0x602A, 0x0CF0,
0x6F12, 0x0101,
0x602A, 0x11B8,
0x6F12, 0x0100,
0x602A, 0x11F6,
0x6F12, 0x0020,
0x602A, 0x4A74,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x218E,
0x6F12, 0x0000,
0x602A, 0x2268,
0x6F12, 0xF279,
0x602A, 0x5006,
0x6F12, 0x0000,
0x602A, 0x500E,
0x6F12, 0x0100,
0x602A, 0x4E70,
0x6F12, 0x2062,
0x6F12, 0x5501,
0x602A, 0x06DC,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6028, 0x4000,
0xF46A, 0xAE80,
0x0344, 0x0000,
0x0346, 0x0308,
0x0348, 0x1FFF,
0x034A, 0x1517,
0x034C, 0x0FF0,
0x034E, 0x08F8,
0x0350, 0x0008,
0x0352, 0x0008,
0x0900, 0x0122,
0x0380, 0x0002,
0x0382, 0x0002,
0x0384, 0x0002,
0x0386, 0x0002,
0x0110, 0x1002,
0x0114, 0x0301,
0x0116, 0x2B00,
0x0136, 0x1800,
0x013E, 0x0000,
0x0300, 0x0006,
0x0302, 0x0001,
0x0304, 0x0004,
0x0306, 0x008C,
0x0308, 0x0008,
0x030A, 0x0001,
0x030C, 0x0000,
0x030E, 0x0004,
0x0310, 0x00A5,
0x0312, 0x0000,
0x080E, 0x0000,
0x0340, 0x1140,
0x0342, 0x1080,
0x0702, 0x0000,
0x0202, 0x0100,
0x0200, 0x0100,
0x0D00, 0x0101,
0x0D02, 0x0101,
0x0D04, 0x0102,
0x6226, 0x0000,
};

/* 3rd video call 2040*1528@30fps*/
kal_uint16 addr_data_pair_slim_video_mot_cancunf_s5kjns[] = {
0x6028, 0x2400,
0x602A, 0x1A28,
0x6F12, 0x4C00,
0x602A, 0x065A,
0x6F12, 0x0000,
0x602A, 0x139E,
0x6F12, 0x0300,
0x602A, 0x139C,
0x6F12, 0x0000,
0x602A, 0x13A0,
0x6F12, 0x0A00,
0x6F12, 0x0020,
0x602A, 0x2072,
0x6F12, 0x0000,
0x602A, 0x1A64,
0x6F12, 0x0301,
0x6F12, 0x3F00,
0x602A, 0x19E6,
0x6F12, 0x0201,
0x602A, 0x1A30,
0x6F12, 0x3401,
0x602A, 0x19F4,
0x6F12, 0x0606,
0x602A, 0x19F8,
0x6F12, 0x1010,
0x602A, 0x1B26,
0x6F12, 0x6F80,
0x6F12, 0xA020,
0x602A, 0x1A3C,
0x6F12, 0x5207,
0x602A, 0x1A48,
0x6F12, 0x5207,
0x602A, 0x1444,
0x6F12, 0x2100,
0x6F12, 0x2100,
0x602A, 0x144C,
0x6F12, 0x4200,
0x6F12, 0x4200,
0x602A, 0x7F6C,
0x6F12, 0x0100,
0x6F12, 0x3100,
0x6F12, 0xF700,
0x6F12, 0x2600,
0x6F12, 0xE100,
0x602A, 0x0650,
0x6F12, 0x0600,
0x602A, 0x0654,
0x6F12, 0x0000,
0x602A, 0x1A46,
0x6F12, 0x8600,
0x602A, 0x1A52,
0x6F12, 0xBF00,
0x602A, 0x0674,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x602A, 0x0668,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x602A, 0x0684,
0x6F12, 0x4001,
0x602A, 0x0688,
0x6F12, 0x4001,
0x602A, 0x147C,
0x6F12, 0x1000,
0x602A, 0x1480,
0x6F12, 0x1000,
0x602A, 0x19F6,
0x6F12, 0x0904,
0x602A, 0x0812,
0x6F12, 0x0000,
0x602A, 0x1A02,
0x6F12, 0x0800,
0x602A, 0x2104,
0x6F12, 0x8E12,
0x602A, 0x2148,
0x6F12, 0x0100,
0x602A, 0x2042,
0x6F12, 0x1A00,
0x602A, 0x0874,
0x6F12, 0x1100,
0x602A, 0x09C0,
0x6F12, 0x9800,
0x602A, 0x09C4,
0x6F12, 0x9800,
0x602A, 0x19FE,
0x6F12, 0x0E1C,
0x602A, 0x4D92,
0x6F12, 0x0100,
0x602A, 0x8A88,
0x6F12, 0x0100,
0x602A, 0x4D94,
0x6F12, 0x4001,
0x6F12, 0x0004,
0x6F12, 0x0010,
0x6F12, 0x0810,
0x6F12, 0x0004,
0x6F12, 0x0010,
0x6F12, 0x0810,
0x6F12, 0x0810,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0010,
0x6F12, 0x0010,
0x602A, 0x3570,
0x6F12, 0x0000,
0x602A, 0x3574,
0x6F12, 0x0000,
0x602A, 0x21E4,
0x6F12, 0x0400,
0x602A, 0x21EC,
0x6F12, 0x1001,
0x602A, 0x2080,
0x6F12, 0x0100,
0x6F12, 0x7F00,
0x6F12, 0x0002,
0x6F12, 0x8000,
0x6F12, 0x0002,
0x6F12, 0xC244,
0x6F12, 0xD244,
0x6F12, 0x14F4,
0x6F12, 0x141C,
0x6F12, 0x111C,
0x6F12, 0x54F4,
0x602A, 0x20BA,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x120E,
0x6F12, 0x1000,
0x602A, 0x212E,
0x6F12, 0x0A00,
0x602A, 0x13AE,
0x6F12, 0x0102,
0x602A, 0x0718,
0x6F12, 0x0005,
0x602A, 0x0710,
0x6F12, 0x0004,
0x6F12, 0x0401,
0x6F12, 0x0100,
0x602A, 0x1B5C,
0x6F12, 0x0300,
0x602A, 0x0786,
0x6F12, 0x7701,
0x602A, 0x2022,
0x6F12, 0x0101,
0x6F12, 0x0101,
0x602A, 0x1360,
0x6F12, 0x0000,
0x602A, 0x1376,
0x6F12, 0x0200,
0x6F12, 0x6038,
0x6F12, 0x7038,
0x6F12, 0x8038,
0x602A, 0x1386,
0x6F12, 0x0B00,
0x602A, 0x06FA,
0x6F12, 0x1000,
0x602A, 0x4A94,
0x6F12, 0x0C00,
0x6F12, 0x0900,
0x6F12, 0x0600,
0x6F12, 0x0900,
0x6F12, 0x0900,
0x6F12, 0x0900,
0x6F12, 0x0900,
0x6F12, 0x0900,
0x6F12, 0x0600,
0x6F12, 0x0900,
0x6F12, 0x0C00,
0x6F12, 0x0900,
0x6F12, 0x0900,
0x6F12, 0x0900,
0x6F12, 0x0900,
0x6F12, 0x0900,
0x602A, 0x0A76,
0x6F12, 0x1000,
0x602A, 0x0AEE,
0x6F12, 0x1000,
0x602A, 0x0B66,
0x6F12, 0x1000,
0x602A, 0x0BDE,
0x6F12, 0x1000,
0x602A, 0x0BE8,
0x6F12, 0x3000,
0x6F12, 0x3000,
0x602A, 0x0C56,
0x6F12, 0x1000,
0x602A, 0x0C60,
0x6F12, 0x3000,
0x6F12, 0x3000,
0x602A, 0x0CB6,
0x6F12, 0x0000,
0x602A, 0x0CF2,
0x6F12, 0x0001,
0x602A, 0x0CF0,
0x6F12, 0x0101,
0x602A, 0x11B8,
0x6F12, 0x0000,
0x602A, 0x11F6,
0x6F12, 0x0010,
0x602A, 0x4A74,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0xD8FF,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0xD8FF,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x218E,
0x6F12, 0x0000,
0x602A, 0x2268,
0x6F12, 0xF279,
0x602A, 0x5006,
0x6F12, 0x0000,
0x602A, 0x500E,
0x6F12, 0x0100,
0x602A, 0x4E70,
0x6F12, 0x2062,
0x6F12, 0x5501,
0x602A, 0x06DC,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6028, 0x4000,
0xF46A, 0xAE80,
0x0344, 0x0000,
0x0346, 0x0010,
0x0348, 0x1FFF,
0x034A, 0x180F,
0x034C, 0x07F8,
0x034E, 0x05F8,
0x0350, 0x0004,
0x0352, 0x0004,
0x0900, 0x0144,
0x0380, 0x0002,
0x0382, 0x0006,
0x0384, 0x0002,
0x0386, 0x0006,
0x0110, 0x1002,
0x0114, 0x0301,
0x0116, 0x2B00,
0x0136, 0x1800,
0x013E, 0x0000,
0x0300, 0x0006,
0x0302, 0x0001,
0x0304, 0x0004,
0x0306, 0x0096,
0x0308, 0x0008,
0x030A, 0x0001,
0x030C, 0x0000,
0x030E, 0x0004,
0x0310, 0x00A5,
0x0312, 0x0000,
0x080E, 0x0000,
0x0340, 0x1310,
0x0342, 0x1000,
0x0702, 0x0000,
0x0202, 0x0100,
0x0200, 0x0100,
0x0D00, 0x0101,
0x0D02, 0x0101,
0x0D04, 0x0102,
0x6226, 0x0000,
};

/* 60fps video 2040*1148@60fps*/
kal_uint16 addr_data_pair_60fps_s5kjns[] = {
0x6028, 0x2400,
0x602A, 0x1A28,
0x6F12, 0x4C00,
0x602A, 0x065A,
0x6F12, 0x0000,
0x602A, 0x139E,
0x6F12, 0x0300,
0x602A, 0x139C,
0x6F12, 0x0000,
0x602A, 0x13A0,
0x6F12, 0x0A00,
0x6F12, 0x0020,
0x602A, 0x2072,
0x6F12, 0x0000,
0x602A, 0x1A64,
0x6F12, 0x0301,
0x6F12, 0x3F00,
0x602A, 0x19E6,
0x6F12, 0x0201,
0x602A, 0x1A30,
0x6F12, 0x3401,
0x602A, 0x19F4,
0x6F12, 0x0606,
0x602A, 0x19F8,
0x6F12, 0x1010,
0x602A, 0x1B26,
0x6F12, 0x6F80,
0x6F12, 0xA020,
0x602A, 0x1A3C,
0x6F12, 0x5207,
0x602A, 0x1A48,
0x6F12, 0x5207,
0x602A, 0x1444,
0x6F12, 0x2100,
0x6F12, 0x2100,
0x602A, 0x144C,
0x6F12, 0x4200,
0x6F12, 0x4200,
0x602A, 0x7F6C,
0x6F12, 0x0100,
0x6F12, 0x3100,
0x6F12, 0xF700,
0x6F12, 0x2600,
0x6F12, 0xE100,
0x602A, 0x0650,
0x6F12, 0x0600,
0x602A, 0x0654,
0x6F12, 0x0000,
0x602A, 0x1A46,
0x6F12, 0x8600,
0x602A, 0x1A52,
0x6F12, 0xBF00,
0x602A, 0x0674,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x602A, 0x0668,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x602A, 0x0684,
0x6F12, 0x4001,
0x602A, 0x0688,
0x6F12, 0x4001,
0x602A, 0x147C,
0x6F12, 0x1000,
0x602A, 0x1480,
0x6F12, 0x1000,
0x602A, 0x19F6,
0x6F12, 0x0904,
0x602A, 0x0812,
0x6F12, 0x0000,
0x602A, 0x1A02,
0x6F12, 0x0800,
0x602A, 0x2104,
0x6F12, 0x8E12,
0x602A, 0x2148,
0x6F12, 0x0100,
0x602A, 0x2042,
0x6F12, 0x1A00,
0x602A, 0x0874,
0x6F12, 0x1100,
0x602A, 0x09C0,
0x6F12, 0x9800,
0x602A, 0x09C4,
0x6F12, 0x9800,
0x602A, 0x19FE,
0x6F12, 0x0E1C,
0x602A, 0x4D92,
0x6F12, 0x0100,
0x602A, 0x8A88,
0x6F12, 0x0100,
0x602A, 0x4D94,
0x6F12, 0x4001,
0x6F12, 0x0004,
0x6F12, 0x0010,
0x6F12, 0x0810,
0x6F12, 0x0004,
0x6F12, 0x0010,
0x6F12, 0x0810,
0x6F12, 0x0810,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0010,
0x6F12, 0x0010,
0x602A, 0x3570,
0x6F12, 0x0000,
0x602A, 0x3574,
0x6F12, 0x0000,
0x602A, 0x21E4,
0x6F12, 0x0400,
0x602A, 0x21EC,
0x6F12, 0x8001,
0x602A, 0x2080,
0x6F12, 0x0100,
0x6F12, 0x7F00,
0x6F12, 0x0002,
0x6F12, 0x8000,
0x6F12, 0x0002,
0x6F12, 0xC244,
0x6F12, 0xD244,
0x6F12, 0x14F4,
0x6F12, 0x141C,
0x6F12, 0x111C,
0x6F12, 0x54F4,
0x602A, 0x20BA,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x120E,
0x6F12, 0x1000,
0x602A, 0x212E,
0x6F12, 0x0A00,
0x602A, 0x13AE,
0x6F12, 0x0102,
0x602A, 0x0718,
0x6F12, 0x0005,
0x602A, 0x0710,
0x6F12, 0x0004,
0x6F12, 0x0401,
0x6F12, 0x0100,
0x602A, 0x1B5C,
0x6F12, 0x0300,
0x602A, 0x0786,
0x6F12, 0x7701,
0x602A, 0x2022,
0x6F12, 0x0101,
0x6F12, 0x0101,
0x602A, 0x1360,
0x6F12, 0x0000,
0x602A, 0x1376,
0x6F12, 0x0200,
0x6F12, 0x6038,
0x6F12, 0x7038,
0x6F12, 0x8038,
0x602A, 0x1386,
0x6F12, 0x0B00,
0x602A, 0x06FA,
0x6F12, 0x0000,
0x602A, 0x4A94,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x0A76,
0x6F12, 0x1000,
0x602A, 0x0AEE,
0x6F12, 0x1000,
0x602A, 0x0B66,
0x6F12, 0x1000,
0x602A, 0x0BDE,
0x6F12, 0x1000,
0x602A, 0x0BE8,
0x6F12, 0x3000,
0x6F12, 0x3000,
0x602A, 0x0C56,
0x6F12, 0x1000,
0x602A, 0x0C60,
0x6F12, 0x3000,
0x6F12, 0x3000,
0x602A, 0x0CB6,
0x6F12, 0x0000,
0x602A, 0x0CF2,
0x6F12, 0x0001,
0x602A, 0x0CF0,
0x6F12, 0x0101,
0x602A, 0x11B8,
0x6F12, 0x0000,
0x602A, 0x11F6,
0x6F12, 0x0010,
0x602A, 0x4A74,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x218E,
0x6F12, 0x0000,
0x602A, 0x2268,
0x6F12, 0xF279,
0x602A, 0x5006,
0x6F12, 0x0000,
0x602A, 0x500E,
0x6F12, 0x0100,
0x602A, 0x4E70,
0x6F12, 0x2062,
0x6F12, 0x5501,
0x602A, 0x06DC,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6028, 0x4000,
0xF46A, 0xAE80,
0x0344, 0x0000,
0x0346, 0x0300,
0x0348, 0x1FFF,
0x034A, 0x151F,
0x034C, 0x07F8,
0x034E, 0x047C,
0x0350, 0x0004,
0x0352, 0x0006,
0x0900, 0x0144,
0x0380, 0x0002,
0x0382, 0x0006,
0x0384, 0x0002,
0x0386, 0x0006,
0x0110, 0x1002,
0x0114, 0x0301,
0x0116, 0x2B00,
0x0136, 0x1800,
0x013E, 0x0000,
0x0300, 0x0006,
0x0302, 0x0001,
0x0304, 0x0004,
0x0306, 0x0096,
0x0308, 0x0008,
0x030A, 0x0001,
0x030C, 0x0000,
0x030E, 0x0004,
0x0310, 0x00A5,
0x0312, 0x0000,
0x080E, 0x0000,
0x0340, 0x0648,
0x0342, 0x1840,
0x0702, 0x0000,
0x0202, 0x0100,
0x0200, 0x0100,
0x0D00, 0x0101,
0x0D02, 0x0101,
0x0D04, 0x0102,
0x6226, 0x0000,
};

/* 120fps 2040*1148@120fps*/
kal_uint16 addr_data_pair_120fps_s5kjns[] = {
0x6028, 0x2400,
0x602A, 0x1A28,
0x6F12, 0x4C00,
0x602A, 0x065A,
0x6F12, 0x0000,
0x602A, 0x139E,
0x6F12, 0x0300,
0x602A, 0x139C,
0x6F12, 0x0000,
0x602A, 0x13A0,
0x6F12, 0x0A00,
0x6F12, 0x0020,
0x602A, 0x2072,
0x6F12, 0x0000,
0x602A, 0x1A64,
0x6F12, 0x0301,
0x6F12, 0x3F00,
0x602A, 0x19E6,
0x6F12, 0x0201,
0x602A, 0x1A30,
0x6F12, 0x3401,
0x602A, 0x19F4,
0x6F12, 0x0606,
0x602A, 0x19F8,
0x6F12, 0x1010,
0x602A, 0x1B26,
0x6F12, 0x6F80,
0x6F12, 0xA020,
0x602A, 0x1A3C,
0x6F12, 0x5207,
0x602A, 0x1A48,
0x6F12, 0x5207,
0x602A, 0x1444,
0x6F12, 0x2100,
0x6F12, 0x2100,
0x602A, 0x144C,
0x6F12, 0x4200,
0x6F12, 0x4200,
0x602A, 0x7F6C,
0x6F12, 0x0100,
0x6F12, 0x3100,
0x6F12, 0xF700,
0x6F12, 0x2600,
0x6F12, 0xE100,
0x602A, 0x0650,
0x6F12, 0x0600,
0x602A, 0x0654,
0x6F12, 0x0000,
0x602A, 0x1A46,
0x6F12, 0x8600,
0x602A, 0x1A52,
0x6F12, 0xBF00,
0x602A, 0x0674,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x6F12, 0x0500,
0x602A, 0x0668,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x6F12, 0x0800,
0x602A, 0x0684,
0x6F12, 0x4001,
0x602A, 0x0688,
0x6F12, 0x4001,
0x602A, 0x147C,
0x6F12, 0x1000,
0x602A, 0x1480,
0x6F12, 0x1000,
0x602A, 0x19F6,
0x6F12, 0x0904,
0x602A, 0x0812,
0x6F12, 0x0000,
0x602A, 0x1A02,
0x6F12, 0x0800,
0x602A, 0x2104,
0x6F12, 0x8E12,
0x602A, 0x2148,
0x6F12, 0x0100,
0x602A, 0x2042,
0x6F12, 0x1A00,
0x602A, 0x0874,
0x6F12, 0x1100,
0x602A, 0x09C0,
0x6F12, 0x9800,
0x602A, 0x09C4,
0x6F12, 0x9800,
0x602A, 0x19FE,
0x6F12, 0x0E1C,
0x602A, 0x4D92,
0x6F12, 0x0100,
0x602A, 0x8A88,
0x6F12, 0x0100,
0x602A, 0x4D94,
0x6F12, 0x4001,
0x6F12, 0x0004,
0x6F12, 0x0010,
0x6F12, 0x0810,
0x6F12, 0x0004,
0x6F12, 0x0010,
0x6F12, 0x0810,
0x6F12, 0x0810,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0010,
0x6F12, 0x0010,
0x602A, 0x3570,
0x6F12, 0x0000,
0x602A, 0x3574,
0x6F12, 0x0000,
0x602A, 0x21E4,
0x6F12, 0x0400,
0x602A, 0x21EC,
0x6F12, 0x8001,
0x602A, 0x2080,
0x6F12, 0x0100,
0x6F12, 0x7F00,
0x6F12, 0x0002,
0x6F12, 0x8000,
0x6F12, 0x0002,
0x6F12, 0xC244,
0x6F12, 0xD244,
0x6F12, 0x14F4,
0x6F12, 0x141C,
0x6F12, 0x111C,
0x6F12, 0x54F4,
0x602A, 0x20BA,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x120E,
0x6F12, 0x1000,
0x602A, 0x212E,
0x6F12, 0x0A00,
0x602A, 0x13AE,
0x6F12, 0x0102,
0x602A, 0x0718,
0x6F12, 0x0005,
0x602A, 0x0710,
0x6F12, 0x0004,
0x6F12, 0x0401,
0x6F12, 0x0100,
0x602A, 0x1B5C,
0x6F12, 0x0300,
0x602A, 0x0786,
0x6F12, 0x7701,
0x602A, 0x2022,
0x6F12, 0x0101,
0x6F12, 0x0101,
0x602A, 0x1360,
0x6F12, 0x0000,
0x602A, 0x1376,
0x6F12, 0x0200,
0x6F12, 0x6038,
0x6F12, 0x7038,
0x6F12, 0x8038,
0x602A, 0x1386,
0x6F12, 0x0B00,
0x602A, 0x06FA,
0x6F12, 0x0000,
0x602A, 0x4A94,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x0A76,
0x6F12, 0x1000,
0x602A, 0x0AEE,
0x6F12, 0x1000,
0x602A, 0x0B66,
0x6F12, 0x1000,
0x602A, 0x0BDE,
0x6F12, 0x1000,
0x602A, 0x0BE8,
0x6F12, 0x3000,
0x6F12, 0x3000,
0x602A, 0x0C56,
0x6F12, 0x1000,
0x602A, 0x0C60,
0x6F12, 0x3000,
0x6F12, 0x3000,
0x602A, 0x0CB6,
0x6F12, 0x0000,
0x602A, 0x0CF2,
0x6F12, 0x0001,
0x602A, 0x0CF0,
0x6F12, 0x0101,
0x602A, 0x11B8,
0x6F12, 0x0000,
0x602A, 0x11F6,
0x6F12, 0x0010,
0x602A, 0x4A74,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x602A, 0x218E,
0x6F12, 0x0000,
0x602A, 0x2268,
0x6F12, 0xF279,
0x602A, 0x5006,
0x6F12, 0x0000,
0x602A, 0x500E,
0x6F12, 0x0100,
0x602A, 0x4E70,
0x6F12, 0x2062,
0x6F12, 0x5501,
0x602A, 0x06DC,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6F12, 0x0000,
0x6028, 0x4000,
0xF46A, 0xAE80,
0x0344, 0x0000,
0x0346, 0x0300,
0x0348, 0x1FFF,
0x034A, 0x151F,
0x034C, 0x07F8,
0x034E, 0x047C,
0x0350, 0x0004,
0x0352, 0x0006,
0x0900, 0x0144,
0x0380, 0x0002,
0x0382, 0x0006,
0x0384, 0x0002,
0x0386, 0x0006,
0x0110, 0x1002,
0x0114, 0x0301,
0x0116, 0x2B00,
0x0136, 0x1800,
0x013E, 0x0000,
0x0300, 0x0006,
0x0302, 0x0001,
0x0304, 0x0004,
0x0306, 0x0096,
0x0308, 0x0008,
0x030A, 0x0001,
0x030C, 0x0000,
0x030E, 0x0004,
0x0310, 0x00A5,
0x0312, 0x0000,
0x080E, 0x0000,
0x0340, 0x08D0,
0x0342, 0x08A0,
0x0702, 0x0000,
0x0202, 0x0100,
0x0200, 0x0100,
0x0D00, 0x0101,
0x0D02, 0x0001,
0x0D04, 0x0102,
0x6226, 0x0000,
};
#endif
