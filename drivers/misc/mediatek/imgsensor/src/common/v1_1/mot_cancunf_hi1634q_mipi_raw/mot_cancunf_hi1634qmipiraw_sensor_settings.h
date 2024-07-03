/*
 * Copyright (C) 2016 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

/*****************************************************************************
 *
 * Filename:
 * ---------
 *     MOT_CANCUNF_HI1634Qmipi_Sensor_Setting.h
 *
 * Project:
 * --------
 *     ALPS
 *
 * Description:
 * ------------
 *     CMOS sensor header file
 *
 ****************************************************************************/
#ifndef _MOT_CANCUNF_HI1634QMIPI_SENSOR_SETTING_H
#define _MOT_CANCUNF_HI1634QMIPI_SENSOR_SETTING_H

// Hi1634Q_2.0.8.9_gain_cal_1696Mbps_20191125
static kal_uint16 mot_cancunf_hi1634q_init_setting[] = {
/*
DISP_DATE = "2022-04-13 10:33:55"
DISP_FORMAT = BAYER10_PACKED
DISP_DATAORDER = GR_QUAD
MIPI_LANECNT = 4
I2C_SPEED = 400
*/
0x0790, 0x0100,
0x2000, 0x1001,
0x2002, 0x0000,
0x2006, 0x40B2,
0x2008, 0xB038,
0x200A, 0x8430,
0x200C, 0x40B2,
0x200E, 0xB082,
0x2010, 0x8476,
0x2012, 0x40B2,
0x2014, 0xB0F4,
0x2016, 0x847A,
0x2018, 0x40B2,
0x201A, 0xB128,
0x201C, 0x8434,
0x201E, 0x40B2,
0x2020, 0xB19C,
0x2022, 0x8488,
0x2024, 0x40B2,
0x2026, 0xB236,
0x2028, 0x8486,
0x202A, 0x40B2,
0x202C, 0xB43E,
0x202E, 0x871E,
0x2030, 0x40B2,
0x2032, 0xB3B8,
0x2034, 0x86C8,
0x2036, 0x4130,
0x2038, 0x120B,
0x203A, 0x120A,
0x203C, 0x403B,
0x203E, 0x0261,
0x2040, 0x4B6A,
0x2042, 0xC3EB,
0x2044, 0x0000,
0x2046, 0x1292,
0x2048, 0xD000,
0x204A, 0x4ACB,
0x204C, 0x0000,
0x204E, 0xB3EB,
0x2050, 0x0000,
0x2052, 0x2411,
0x2054, 0x421F,
0x2056, 0x85DA,
0x2058, 0xD21F,
0x205A, 0x85D8,
0x205C, 0x930F,
0x205E, 0x2404,
0x2060, 0x40F2,
0x2062, 0xFF80,
0x2064, 0x0619,
0x2066, 0x3C07,
0x2068, 0x90F2,
0x206A, 0x0011,
0x206C, 0x0619,
0x206E, 0x2803,
0x2070, 0x50F2,
0x2072, 0xFFF0,
0x2074, 0x0619,
0x2076, 0x40B2,
0x2078, 0xB3BE,
0x207A, 0x86D0,
0x207C, 0x413A,
0x207E, 0x413B,
0x2080, 0x4130,
0x2082, 0x120B,
0x2084, 0x120A,
0x2086, 0x8231,
0x2088, 0x430A,
0x208A, 0x93C2,
0x208C, 0x0C0A,
0x208E, 0x2404,
0x2090, 0xB3D2,
0x2092, 0x0B05,
0x2094, 0x2401,
0x2096, 0x431A,
0x2098, 0x403B,
0x209A, 0x8438,
0x209C, 0x422D,
0x209E, 0x403E,
0x20A0, 0x192A,
0x20A2, 0x403F,
0x20A4, 0x86EC,
0x20A6, 0x12AB,
0x20A8, 0x422D,
0x20AA, 0x403E,
0x20AC, 0x86EC,
0x20AE, 0x410F,
0x20B0, 0x12AB,
0x20B2, 0x930A,
0x20B4, 0x2003,
0x20B6, 0xD3D2,
0x20B8, 0x1921,
0x20BA, 0x3C09,
0x20BC, 0x403D,
0x20BE, 0x0200,
0x20C0, 0x422E,
0x20C2, 0x403F,
0x20C4, 0x86EC,
0x20C6, 0x1292,
0x20C8, 0x8448,
0x20CA, 0xC3D2,
0x20CC, 0x1921,
0x20CE, 0x1292,
0x20D0, 0xD046,
0x20D2, 0x403B,
0x20D4, 0x8438,
0x20D6, 0x422D,
0x20D8, 0x410E,
0x20DA, 0x403F,
0x20DC, 0x86EC,
0x20DE, 0x12AB,
0x20E0, 0x422D,
0x20E2, 0x403E,
0x20E4, 0x86EC,
0x20E6, 0x403F,
0x20E8, 0x192A,
0x20EA, 0x12AB,
0x20EC, 0x5231,
0x20EE, 0x413A,
0x20F0, 0x413B,
0x20F2, 0x4130,
0x20F4, 0x4382,
0x20F6, 0x052C,
0x20F8, 0x4F0D,
0x20FA, 0x930D,
0x20FC, 0x3402,
0x20FE, 0xE33D,
0x2100, 0x531D,
0x2102, 0xF03D,
0x2104, 0x07F0,
0x2106, 0x4D0E,
0x2108, 0xC312,
0x210A, 0x100E,
0x210C, 0x110E,
0x210E, 0x110E,
0x2110, 0x110E,
0x2112, 0x930F,
0x2114, 0x3803,
0x2116, 0x4EC2,
0x2118, 0x052C,
0x211A, 0x3C04,
0x211C, 0x4EC2,
0x211E, 0x052D,
0x2120, 0xE33D,
0x2122, 0x531D,
0x2124, 0x4D0F,
0x2126, 0x4130,
0x2128, 0x120B,
0x212A, 0x425F,
0x212C, 0x0205,
0x212E, 0xC312,
0x2130, 0x104F,
0x2132, 0x114F,
0x2134, 0x114F,
0x2136, 0x114F,
0x2138, 0x114F,
0x213A, 0x114F,
0x213C, 0x4F0B,
0x213E, 0xF31B,
0x2140, 0x5B0B,
0x2142, 0x5B0B,
0x2144, 0x5B0B,
0x2146, 0x503B,
0x2148, 0xD1CC,
0x214A, 0x1292,
0x214C, 0xD004,
0x214E, 0x93C2,
0x2150, 0x86BF,
0x2152, 0x240B,
0x2154, 0xB2E2,
0x2156, 0x0400,
0x2158, 0x2008,
0x215A, 0x425F,
0x215C, 0x86BB,
0x215E, 0xD36F,
0x2160, 0xF37F,
0x2162, 0x5F0F,
0x2164, 0x5F0B,
0x2166, 0x4BA2,
0x2168, 0x0402,
0x216A, 0x93C2,
0x216C, 0x86C1,
0x216E, 0x2414,
0x2170, 0x421F,
0x2172, 0x86C6,
0x2174, 0x4FA2,
0x2176, 0x8606,
0x2178, 0x425F,
0x217A, 0x86BD,
0x217C, 0x425E,
0x217E, 0x86BA,
0x2180, 0x5F0F,
0x2182, 0x5E0F,
0x2184, 0x5F0F,
0x2186, 0x4F0E,
0x2188, 0x521E,
0x218A, 0x86CA,
0x218C, 0x4EA2,
0x218E, 0x8600,
0x2190, 0x521F,
0x2192, 0x86CC,
0x2194, 0x4FA2,
0x2196, 0x8602,
0x2198, 0x413B,
0x219A, 0x4130,
0x219C, 0x8231,
0x219E, 0xD3D2,
0x21A0, 0x7A12,
0x21A2, 0xC3D2,
0x21A4, 0x0F00,
0x21A6, 0x422D,
0x21A8, 0x403E,
0x21AA, 0x06D6,
0x21AC, 0x410F,
0x21AE, 0x1292,
0x21B0, 0x8438,
0x21B2, 0x93C2,
0x21B4, 0x86C1,
0x21B6, 0x243B,
0x21B8, 0x421F,
0x21BA, 0x0402,
0x21BC, 0x0B00,
0x21BE, 0x7304,
0x21C0, 0x0000,
0x21C2, 0x4F82,
0x21C4, 0x0402,
0x21C6, 0x421F,
0x21C8, 0x7100,
0x21CA, 0xF03F,
0x21CC, 0x0003,
0x21CE, 0x0800,
0x21D0, 0x7A10,
0x21D2, 0x931F,
0x21D4, 0x2425,
0x21D6, 0x931F,
0x21D8, 0x281C,
0x21DA, 0x932F,
0x21DC, 0x2414,
0x21DE, 0x903F,
0x21E0, 0x0003,
0x21E2, 0x240B,
0x21E4, 0x425E,
0x21E6, 0x86BB,
0x21E8, 0xEE0F,
0x21EA, 0xF31F,
0x21EC, 0x5F0F,
0x21EE, 0x4F1F,
0x21F0, 0xB466,
0x21F2, 0x9382,
0x21F4, 0x7112,
0x21F6, 0x27E2,
0x21F8, 0x3C1C,
0x21FA, 0x41A2,
0x21FC, 0x06D6,
0x21FE, 0x4192,
0x2200, 0x0002,
0x2202, 0x06D8,
0x2204, 0x3FEF,
0x2206, 0x4192,
0x2208, 0x0002,
0x220A, 0x06DA,
0x220C, 0x41A2,
0x220E, 0x06DC,
0x2210, 0x3FE9,
0x2212, 0x4192,
0x2214, 0x0004,
0x2216, 0x06DA,
0x2218, 0x4192,
0x221A, 0x0006,
0x221C, 0x06DC,
0x221E, 0x3FE2,
0x2220, 0x4192,
0x2222, 0x0006,
0x2224, 0x06D6,
0x2226, 0x4192,
0x2228, 0x0004,
0x222A, 0x06D8,
0x222C, 0x3FDB,
0x222E, 0x1292,
0x2230, 0xD058,
0x2232, 0x5231,
0x2234, 0x4130,
0x2236, 0x93C2,
0x2238, 0x86C1,
0x223A, 0x2427,
0x223C, 0x430C,
0x223E, 0x4C0F,
0x2240, 0x5F0F,
0x2242, 0x5F0F,
0x2244, 0x5F0F,
0x2246, 0x5F0F,
0x2248, 0x5F0F,
0x224A, 0x4F1D,
0x224C, 0x84C4,
0x224E, 0x4F1E,
0x2250, 0x84C6,
0x2252, 0x4F9F,
0x2254, 0x84C0,
0x2256, 0x84C4,
0x2258, 0x4F9F,
0x225A, 0x84C2,
0x225C, 0x84C6,
0x225E, 0x4D8F,
0x2260, 0x84C0,
0x2262, 0x4E8F,
0x2264, 0x84C2,
0x2266, 0x4F1D,
0x2268, 0x84CC,
0x226A, 0x4F1E,
0x226C, 0x84CE,
0x226E, 0x4F9F,
0x2270, 0x84C8,
0x2272, 0x84CC,
0x2274, 0x4F9F,
0x2276, 0x84CA,
0x2278, 0x84CE,
0x227A, 0x4D8F,
0x227C, 0x84C8,
0x227E, 0x4E8F,
0x2280, 0x84CA,
0x2282, 0x531C,
0x2284, 0x903C,
0x2286, 0x0005,
0x2288, 0x3BDA,
0x228A, 0x1292,
0x228C, 0xD056,
0x228E, 0x4130,
0x2290, 0x7400,
0x2292, 0x8058,
0x2294, 0x1807,
0x2296, 0x00E0,
0x2298, 0x7002,
0x229A, 0x17C7,
0x229C, 0x7000,
0x229E, 0x1305,
0x22A0, 0x0006,
0x22A2, 0x001F,
0x22A4, 0x0055,
0x22A6, 0x00DB,
0x22A8, 0x0012,
0x22AA, 0x1754,
0x22AC, 0x206F,
0x22AE, 0x009E,
0x22B0, 0x00DD,
0x22B2, 0x5023,
0x22B4, 0x00DE,
0x22B6, 0x005B,
0x22B8, 0x0119,
0x22BA, 0x0390,
0x22BC, 0x00D1,
0x22BE, 0x0055,
0x22C0, 0x0040,
0x22C2, 0x0553,
0x22C4, 0x0456,
0x22C6, 0x5041,
0x22C8, 0x700D,
0x22CA, 0x2F99,
0x22CC, 0x2318,
0x22CE, 0x005C,
0x22D0, 0x7000,
0x22D2, 0x1586,
0x22D4, 0x0001,
0x22D6, 0x2032,
0x22D8, 0x0012,
0x22DA, 0x0008,
0x22DC, 0x0343,
0x22DE, 0x0148,
0x22E0, 0x2123,
0x22E2, 0x0046,
0x22E4, 0x05DD,
0x22E6, 0x00DE,
0x22E8, 0x00DD,
0x22EA, 0x00DC,
0x22EC, 0x00DE,
0x22EE, 0x07D6,
0x22F0, 0x5061,
0x22F2, 0x704F,
0x22F4, 0x2F99,
0x22F6, 0x005C,
0x22F8, 0x5080,
0x22FA, 0x4D90,
0x22FC, 0x50A1,
0x22FE, 0x2122,
0x2300, 0x7800,
0x2302, 0xC08C,
0x2304, 0x0001,
0x2306, 0x9038,
0x2308, 0x59F7,
0x230A, 0x903B,
0x230C, 0x121C,
0x230E, 0x9034,
0x2310, 0x1218,
0x2312, 0x8C34,
0x2314, 0x0180,
0x2316, 0x8DC0,
0x2318, 0x01C0,
0x231A, 0x7400,
0x231C, 0x8058,
0x231E, 0x1807,
0x2320, 0x00E0,
0x2322, 0x00DF,
0x2324, 0x0047,
0x2326, 0x7000,
0x2328, 0x17C5,
0x232A, 0x0046,
0x232C, 0x0095,
0x232E, 0x7000,
0x2330, 0x148C,
0x2332, 0x005B,
0x2334, 0x0014,
0x2336, 0x001D,
0x2338, 0x216F,
0x233A, 0x005E,
0x233C, 0x00DD,
0x233E, 0x2244,
0x2340, 0x001C,
0x2342, 0x00DE,
0x2344, 0x005B,
0x2346, 0x0519,
0x2348, 0x0150,
0x234A, 0x0091,
0x234C, 0x00D5,
0x234E, 0x0040,
0x2350, 0x0393,
0x2352, 0x0356,
0x2354, 0x5021,
0x2356, 0x700D,
0x2358, 0x2F99,
0x235A, 0x2318,
0x235C, 0x005C,
0x235E, 0x0006,
0x2360, 0x0016,
0x2362, 0x425A,
0x2364, 0x0012,
0x2366, 0x0008,
0x2368, 0x0403,
0x236A, 0x01C8,
0x236C, 0x2123,
0x236E, 0x0046,
0x2370, 0x095D,
0x2372, 0x00DE,
0x2374, 0x00DD,
0x2376, 0x00DC,
0x2378, 0x00DE,
0x237A, 0x04D6,
0x237C, 0x5041,
0x237E, 0x704F,
0x2380, 0x2F99,
0x2382, 0x7000,
0x2384, 0x1702,
0x2386, 0x202C,
0x2388, 0x0016,
0x238A, 0x5060,
0x238C, 0x2122,
0x238E, 0x7800,
0x2390, 0xC08C,
0x2392, 0x0001,
0x2394, 0x903B,
0x2396, 0x121C,
0x2398, 0x9034,
0x239A, 0x1218,
0x239C, 0x8DC0,
0x239E, 0x01C0,
0x23A0, 0x0000,
0x23A2, 0xB290,
0x23A4, 0x0000,
0x23A6, 0xB290,
0x23A8, 0xB302,
0x23AA, 0x0002,
0x23AC, 0x0000,
0x23AE, 0xB31A,
0x23B0, 0x0000,
0x23B2, 0xB31A,
0x23B4, 0xB390,
0x23B6, 0x0002,
0x23B8, 0xB3A0,
0x23BA, 0xB3AC,
0x23BC, 0xFCE0,
0x23BE, 0x0040,
0x23C0, 0x0040,
0x23C2, 0x0040,
0x23C4, 0x0045,
0x23C6, 0x004C,
0x23C8, 0x0050,
0x23CA, 0x005A,
0x23CC, 0x005D,
0x23CE, 0x0064,
0x23D0, 0x0066,
0x23D2, 0x0068,
0x23D4, 0x0071,
0x23D6, 0x0078,
0x23D8, 0x007D,
0x23DA, 0x0087,
0x23DC, 0x008C,
0x23DE, 0x0094,
0x23E0, 0x0098,
0x23E2, 0x00AD,
0x23E4, 0x00B0,
0x23E6, 0x00C3,
0x23E8, 0x00C4,
0x23EA, 0x00D9,
0x23EC, 0x00DE,
0x23EE, 0x00F0,
0x23F0, 0x00FF,
0x23F2, 0x0106,
0x23F4, 0x011A,
0x23F6, 0x0117,
0x23F8, 0x0133,
0x23FA, 0x0126,
0x23FC, 0x0126,
0x23FE, 0x0040,
0x2400, 0x0040,
0x2402, 0x0040,
0x2404, 0x0045,
0x2406, 0x004C,
0x2408, 0x0050,
0x240A, 0x005A,
0x240C, 0x005D,
0x240E, 0x0064,
0x2410, 0x0066,
0x2412, 0x006B,
0x2414, 0x0071,
0x2416, 0x0078,
0x2418, 0x007D,
0x241A, 0x0087,
0x241C, 0x008C,
0x241E, 0x0094,
0x2420, 0x0098,
0x2422, 0x00AD,
0x2424, 0x00B0,
0x2426, 0x00C3,
0x2428, 0x00C4,
0x242A, 0x00D9,
0x242C, 0x00DE,
0x242E, 0x00F0,
0x2430, 0x00FF,
0x2432, 0x0106,
0x2434, 0x011A,
0x2436, 0x0117,
0x2438, 0x0133,
0x243A, 0x0126,
0x243C, 0x0126,
0x243E, 0x0041,
0x2440, 0x0060,
0x2442, 0x0124,
0x2444, 0x023B,
0x2446, 0x05FC,
0x2448, 0x0041,
0x244A, 0x0060,
0x244C, 0x0124,
0x244E, 0x023B,
0x2450, 0x05FC,
0x2452, 0x0041,
0x2454, 0x004E,
0x2456, 0x007D,
0x2458, 0x01B8,
0x245A, 0x05FC,
0x245C, 0x0041,
0x245E, 0x004B,
0x2460, 0x0078,
0x2462, 0x019D,
0x2464, 0x05FC,
0x2466, 0x72D8,
0x2468, 0x278D,
0x0262, 0x0600,
0x026A, 0xFFFF,
0x026C, 0x00FF,
0x026E, 0x0000,
0x0360, 0x0E8E,
0x040C, 0x01EB,
0x0600, 0x1132,
0x0604, 0x8008,
0x0644, 0x07FE,
0x0676, 0x07FF,
0x0678, 0x0002,
0x06A8, 0x0350,
0x06AA, 0x0160,
0x06AC, 0x0041,
0x06AE, 0x03FC,
0x06B4, 0x3FFF,
0x06CC, 0x00FF,
0x06E2, 0xFF00,
0x052A, 0x0000,
0x052C, 0x0000,
0x0F00, 0x0000,
0x0B20, 0x0100,
0x1102, 0x0008,
0x1106, 0x0124,
0x11C2, 0x0400,
0x0902, 0x0003,
0x0904, 0x0003,
0x0912, 0x0303,
0x0914, 0x0300,
0x0A04, 0xB4C5,
0x0A06, 0xC400,
0x0A08, 0xA881,
0x0A0E, 0xFEC0,
0x0A12, 0x0000,
0x0A18, 0x0010,
0x0A20, 0x0015,
0x070C, 0x0000,
0x0780, 0x010E,
0x1202, 0x1E00,
0x1204, 0xD700,
0x1210, 0x8028,
0x1216, 0xA0A0,
0x1218, 0x00A0,
0x121A, 0x0000,
0x121C, 0x4128,
0x121E, 0x0000,
0x1220, 0x0000,
0x1222, 0x28FA,
0x105C, 0x0F0B,
0x1958, 0x0041,
0x195A, 0x0060,
0x195C, 0x0124,
0x195E, 0x023B,
0x1960, 0x05FC,
0x1962, 0x0041,
0x1964, 0x0060,
0x1966, 0x0124,
0x1968, 0x023B,
0x196A, 0x05FC,
0x196C, 0x0041,
0x196E, 0x004E,
0x1970, 0x007D,
0x1972, 0x01B8,
0x1974, 0x05FC,
0x1976, 0x0041,
0x1978, 0x004B,
0x197A, 0x0078,
0x197C, 0x019D,
0x197E, 0x05FC,
0x1980, 0x0082,
0x1982, 0x001F,
0x1984, 0x2006,
0x1986, 0x0031,
0x1988, 0x0308,
0x198A, 0x0000,
0x198C, 0x0F86,
0x198E, 0x0000,
0x1990, 0x310D,
0x1992, 0x0000,
0x1994, 0x3E88,
0x1996, 0x0002,
0x19C0, 0x0082,
0x19C2, 0x001F,
0x19C4, 0x2006,
0x19C6, 0x0031,
0x19C8, 0x0308,
0x19CA, 0x0000,
0x19CC, 0x0F86,
0x19CE, 0x0000,
0x19D0, 0x310D,
0x19D2, 0x0000,
0x19D4, 0x3E88,
0x19D6, 0x0002,
0x1A00, 0x0071,
0x1A02, 0x0053,
0x1A04, 0x0000,
0x1A06, 0x0016,
0x1A08, 0x01B7,
0x1A0A, 0x0000,
0x1A0C, 0x034B,
0x1A0E, 0x0000,
0x1A10, 0x171E,
0x1A12, 0x0000,
0x1A14, 0x0999,
0x1A16, 0x0002,
0x1A40, 0x008A,
0x1A42, 0x005E,
0x1A44, 0x0000,
0x1A46, 0x0012,
0x1A48, 0x01E5,
0x1A4A, 0x0000,
0x1A4C, 0x03CE,
0x1A4E, 0x0000,
0x1A50, 0x1853,
0x1A52, 0x0000,
0x1A54, 0x0030,
0x1A56, 0x0000,
0x19BC, 0x2000,
0x19FC, 0x2000,
0x1A3C, 0x2000,
0x1A7C, 0x2000,
0x361C, 0x0000,
0x027E, 0x0100,
0x0B02, 0x0100,
};

static kal_uint16 mot_cancunf_2320x1312_30fps_setting[] = {
0x0B00, 0x0000,
0x0204, 0x0408,
0x0206, 0x02C6,
0x020A, 0x0EA6,
0x020E, 0x0EAA,
0x0224, 0x01E4,
0x022A, 0x0016,
0x022C, 0x0E2A,
0x022E, 0x0C2A,
0x0234, 0x2222,
0x0236, 0x2222,
0x0238, 0x2222,
0x023A, 0x2222,
0x0268, 0x0108,
0x0400, 0x0E10,
0x0404, 0x0008,
0x0406, 0x1244,
0x0408, 0x0001,
0x040E, 0x0200,
0x0440, 0x011D,
0x0D00, 0x4000,
0x0D28, 0x0004,
0x0D2A, 0x0923,
0x0602, 0x3112,
0x0608, 0x0248,
0x067A, 0x0303,
0x067C, 0x0303,
0x06DE, 0x0303,
0x06E0, 0x0303,
0x06E4, 0x8A00,
0x06E6, 0x8A00,
0x06E8, 0x8A00,
0x06EA, 0x8A00,
0x0524, 0x5858,
0x0526, 0x5858,
0x0F04, 0x0008,
0x0F06, 0x0002,
0x0F08, 0x0011,
0x0F0A, 0x2233,
0x0B04, 0x009C,
0x0B12, 0x0910,
0x0B14, 0x0520,
0x0B30, 0x0000,
0x1100, 0x1100,
0x1108, 0x0002,
0x1116, 0x0000,
0x1118, 0x0290,
0x0A0A, 0x8388,
0x0A10, 0xB040,
0x0A1E, 0x0013,
0x0C00, 0x0021,
0x0C14, 0x0008,
0x0C16, 0x0002,
0x0C18, 0x0920,
0x0C1A, 0x0580,
0x0708, 0x6F81,
0x0736, 0x0050,
0x0738, 0x0002,
0x073C, 0x0700,
0x0746, 0x00D4,
0x0748, 0x0002,
0x074A, 0x0900,
0x074C, 0x0100,
0x074E, 0x0100,
0x1200, 0x4946,
0x1206, 0x1800,
0x122E, 0x0490,
0x1230, 0x0248,
0x1000, 0x0300,
0x1002, 0xC311,
0x1004, 0x2BB0,
0x1010, 0x06CC,
0x1012, 0x0093,
0x1020, 0xC107,
0x1022, 0x081F,
0x1024, 0x0509,
0x1026, 0x0B0A,
0x1028, 0x1409,
0x102A, 0x0C0A,
0x102C, 0x1500,
0x1066, 0x06EF,
0x1600, 0x0400,
};

static kal_uint16 mot_cancunf_2320x1740_30fps_setting[] = {
/*
DISP_WIDTH = 2320
DISP_HEIGHT = 1740
DISP_NOTE = "QUAD_FULL"
MIPI_SPEED = 1696.00
MIPI_LANE = 4
DISP_DATAORDER = GR_QUAD

////////////////////////////////////////////
// VT CLK: 80.00MHz
// Line length: 710
// Frame length: 3617
// Frame rate: 31.15
// ISP CLK: 169.60MHz
// V-Blank: 1002.88us
// Output bitwidth: 10 bits
// PD output bitwidth: 10 bits
////////////////////////////////////////////
*/
0x0B00, 0x0000,
0x0204, 0x0408,
0x0206, 0x02DA,
0x020A, 0x0E3F,
0x020E, 0x0E43,
0x0224, 0x0038,
0x022A, 0x0016,
0x022C, 0x0E2A,
0x022E, 0x0DD6,
0x0234, 0x2222,
0x0236, 0x2222,
0x0238, 0x2222,
0x023A, 0x2222,
0x0268, 0x0101,
0x0400, 0x0E10,
0x0404, 0x0008,
0x0406, 0x1244,
0x0408, 0x0001,
0x040E, 0x0200,
0x0440, 0x011D,
0x0D00, 0x4000,
0x0D28, 0x0004,
0x0D2A, 0x0923,
0x0602, 0x3112,
0x0608, 0x0248,
0x067A, 0x0303,
0x067C, 0x0303,
0x06DE, 0x0303,
0x06E0, 0x0303,
0x06E4, 0x8A00,
0x06E6, 0x8A00,
0x06E8, 0x8A00,
0x06EA, 0x8A00,
0x0524, 0x5858,
0x0526, 0x5858,
0x0F04, 0x0008,
0x0F06, 0x0002,
0x0F08, 0x0011,
0x0F0A, 0x2233,
0x0B04, 0x009C,
0x0B12, 0x0910,
0x0B14, 0x06CC,
0x0B30, 0x0000,
0x1100, 0x1100,
0x1108, 0x0002,
0x1116, 0x0000,
0x1118, 0x0008,
0x0A0A, 0x8388,
0x0A10, 0xB040,
0x0A1E, 0x0013,
0x0C00, 0x0021,
0x0C14, 0x0008,
0x0C16, 0x0002,
0x0C18, 0x0920,
0x0C1A, 0x0700,
0x0708, 0x6F81,
0x0736, 0x0050,
0x0738, 0x0002,
0x073C, 0x0700,
0x0746, 0x00D4,
0x0748, 0x0002,
0x074A, 0x0900,
0x074C, 0x0100,
0x074E, 0x0100,
0x1200, 0x4946,
0x1206, 0x1800,
0x122E, 0x0490,
0x1230, 0x0248,
0x1000, 0x0300,
0x1002, 0xC311,
0x1004, 0x2BB0,
0x1010, 0x0702,
0x1012, 0x00AE,
0x1020, 0xC107,
0x1022, 0x081F,
0x1024, 0x0509,
0x1026, 0x0B0A,
0x1028, 0x1409,
0x102A, 0x0C0A,
0x102C, 0x1500,
0x1066, 0x0725,
0x1600, 0x0400,
};
#endif
