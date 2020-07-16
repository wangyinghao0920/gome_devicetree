/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#include <utils/Log.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>

#include "camera_custom_nvram.h"
#include "camera_custom_lens.h"
#include "lens_para_DW9714AF.h"

const NVRAM_LENS_PARA_STRUCT DW9714AF_LENS_PARA_DEFAULT_VALUE =
{
    //Version
    NVRAM_CAMERA_LENS_FILE_VERSION,

    // Focus Range NVRAM
    {0, 1023},

    // AF NVRAM
    {
        // ------------------------------ sAF_Coef -----------------------------------------
        {
            {
                270, // i4Offset
                17,  // i4NormalNum
                17,  // i4MacroNum
                1,   // i4InfIdxOffset
                6,   // i4MacroIdxOffset
                {
                    0,   14,  27,  41,  57,  73,  87,  101, 117, 133,
                    155, 177, 199, 221, 254, 287, 320, 0,   0,   0,
                    0,   0,   0,   0,   0,   0,   0,   0,   0,   0
                }
            },
            15, // i4THRES_MAIN;
            10, // i4THRES_SUB;
            1,  // i4AFC_FAIL_CNT;
            0,  // i4FAIL_POS;

            4,  // i4INIT_WAIT;
            {500, 500, 500, 500, 500}, // i4FRAME_WAIT
            0,  // i4DONE_WAIT;
        },

        // -------------------- sAF_TH ---------------------
        {
            8, // i4ISONum;
            {100, 150, 200, 300, 400, 600, 800, 1600},

            // SGG1~7
            {{21, 21, 21, 20, 20, 19, 19, 18},
             {30, 30, 30, 30, 29, 29, 28, 27},
             {44, 44, 43, 43, 43, 42, 42, 40},
             {63, 62, 62, 62, 62, 61, 61, 60},
             {89, 89, 89, 89, 88, 88, 88, 87},
             {127, 127, 127, 127, 126, 126, 126, 125},
             {181, 180, 180, 180, 180, 180, 180, 179}},

            // horizontal FV min. threshold
            {2000, 2000, 2000, 1000, 1000, 1000, 800, 800},

            // horizontal FV threshold
            {2, 2, 2, 2, 3, 3, 4, 4},//{3, 3, 3, 4, 4, 5, 6, 8},//{4,4,5,6,7,7,8,12},

            // horizontal FV min. threshold
            {2000, 2000, 2000, 1000, 1000, 1000, 800, 800},

            // horizontal FV threshold
            {2, 2, 2, 2, 3, 3, 4, 4},//{3, 3, 3, 4, 4, 5, 6, 8},//{4,4,5,6,7,7,8,12},

            // vertical FV min. threshold
            {0, 0, 0, 0, 0, 0, 0, 0},

            // vertical FV threshold
            {2, 2, 2, 2, 3, 3, 4, 4},//{3, 4, 4, 5, 5, 6, 6, 6},//{6, 6, 6, 8, 8, 8, 10, 14},//{9,9,9,9,10,10,11,13},
        },

        // --- Common use ---
        1,  // i4ReadOTP; 				// 0: disable, 1:enable
        3,  // i4StatGain;
        0,  // i4LV_THRES;
        280,// i4InfPos;
        33, // i4FRAME_TIME
        {0, 100, 200, 350, 500},     // back jump
        500,//i4BackJumpPos

        20, //i4AFC_STEP_SIZE;
        18, // i4SPOT_PERCENT_W;        // AFC window location
        24, // i4SPOT_PERCENT_H;        // AFC window location
        0,  // i4CHANGE_CNT_DELTA;

        1,  // i4AFS_STEP_MIN_ENABLE;
        4,  // i4AFS_STEP_MIN_NORMAL;
        4,  // i4AFS_STEP_MIN_MACRO;

        5,  // i4FIRST_FV_WAIT;
        12, // i4FV_1ST_STABLE_THRES;
        10000,  // i4FV_1ST_STABLE_OFFSET;
        6,  // i4FV_1ST_STABLE_NUM;
        6,  // i4FV_1ST_STABLE_CNT;
        50, // i4FV_SHOCK_THRES;
        30000, // i4FV_SHOCK_OFFSET;
        5,  // i4FV_VALID_CNT;
        20, // i4FV_SHOCK_FRM_CNT;
        5,  // i4FV_SHOCK_CNT;

        // --- FaceAF ---
        70, // i4FDWinPercent;
        20, // i4FDSizeDiff;
        7, // i4FD_DETECT_CNT;
        6,  // i4FD_NONE_CNT;

        // --- AFv1.1/AFv1.2 ---
        1,  // i4LeftSearchEnable;       //[0] 0:disable, 1:enable
        0,  // i4LeftJumpStep;           //[1] when disable left peak search, left step= 3 + i4LeftJumpStep
        0,  // No use
        0,  // i4AfDoneDelay;            //[3] AF done happen delay count
        0,  // i4ZoomInWinChg;           //[4] enable AF window change with Zoom-in
        1,  // i4SensorEnable;           //[5] AF use sensor lister => 0:disable, 1:enable
        0,  // i4PostureComp;            //[6] post comp max offset => 0:disable, others:enable
        2,  // i4SceneMonitorLevel;      //[7] scenechange enhancement level => 0:original, 1~3:from stable to sensitive

        // Scene Monitor
        // {Type, Off, Thr{by level}, Cnt{by level}}
        // Type: 1 is &&, 0 is ||
        // Off : value, min=0 is more sensitive
        // Thr : percentage(value for gyro/acce), min=0 is more sensitive
        // Cnt : value, max=30 is more stable
        // preview params
        {1,                                       // FV 0:disable, 1:enable
         0,100000,{ 40, 40, 30}, { 15, 10, 10},   //    chg; chgT lower to sensitive, chgN bigger to stable
         1, 50000,{ 25, 25, 25}, { 10,  7,  5} }, //    stb; stbT should fix, stbN bigger to stable
        {1,                                       // GS 0:disable, 1:enable
         0,   15, { 20, 20, 15}, { 15, 10, 10},   //    chg; chgT lower to sensitive, chgN bigger to stable
         1,    5, {  5, 10, 10}, { 10,  7,  5} }, //    stb; stbT should fix, stbN bigger to stable
        {1,                                       // AEB 0:disable, 1:enable
         0,   15, { 30, 30, 25}, { 33, 30, 30},   //    chg; chgT lower to sensitive, chgN bigger to stable
         1,    5, { 10, 10, 10}, { 10,  7,  5} }, //    stb; stbT should fix, stbN bigger to stable
        {1,                                       // GYRO 0:disable, 1:enable
         0,    0, { 80, 77, 60}, {  7,  6,  3},   //    chg; off=0, chgT lower to sensitive, chgN bigger to stable
         1,    0, { 10, 10, 10}, { 10,  7,  5} }, //    stb; off=0, stbT should fix, stbN bigger to stable
        {1,                                       // ACCE 0:disable, 1:enable
         0,    0, { 80, 77, 60}, { 15, 11, 11},   //    chg; off=0, chgT lower to sensitive, chgN bigger to stable
         1,    0, { 50, 50, 50}, { 10,  7,  5} }, //    stb; off=0, stbT should fix, stbN bigger to stable


        // --- AFv2.0 ---
        1,  // i4FvExtractEnable;           // 0:disable, 1:enable (for faceAF)
        40, // i4FvExtractThr               // percentage, fixed

        1,  // i4DampingCompEnable;         // 0:disable, 1:enable
        {7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 0, 0, 0, 0, 0},        // { step1, step2, ... , step 15(atmost) }

        1,  // i4DirSelectEnable;           // 0:disable, 1:enable
        -1, // i4InfDir;                    // 1:right, -1:left, 2:reverse, 0:keep
        -1, // i4MidDir;                    // "
        -1, // i4MacDir;                    // "
        40, // i4RatioInf;                  // below % of tableLength belongs to INF
        70, // i4RatioMac;                  // above % of tableLength belongs to MAC ; should be larger than i4RatioInf
        1,  // i4StartBoundEnable;          // 0:disable, 1:enable
        3,  // i4StartCamCAF;               // 0:keep current, -1:force to INF, X:set to boundary if within X steps
        3,  // i4StartCamTAF;               // "
        1,  // i4FpsRemapTblEnable;         // 0:disable, 1:enable
        {10, 12}, // i4FpsThres[2];        // two fps threshold {very-low, low}
        {0, 0},   // i4TableClipPt[2];     // clip pts at macro side
        {80, 90}, // i4TableRemapPt[2];    // percentage of new/org table length

        // --- Easytuning ---
        {0}, // i4EasyTuning[100]

        // --- DampingTbls ---
        {
            12,     // [0] 0:use i4DampingRdirComp/i4DampingLdirComp, N: use following sDpComp tbl, N is also max shutterIdx
            120,    // [1] shutter_base, shutter = idx * 1/shutter_base (sec)
            10,     // [2] sDpComp_tbl_size
            30, 70, 100, // [3]~[5] position ratio[%]

            // shutterIdx=1, ratio[3], calibration table right & left
            1,
            100, 100, 100,
              0,  0,  0,  0, -1, -2,  0, -7, -1,  0,    // Right comp 1 ~ comp sDpComp_tbl_size
              0,  0,  0,  2,  1,  2,  2,  1,  0,  3,    // Left comp 1 ~ comp sDpComp_tbl_size
            // shutterIdx=2
            2,
            100, 100, 100,
              0,  0,  0,  0, -1, -2,  0, -7, -1,  0,
              0,  0,  0,  2,  1,  2,  2,  1,  0,  3,
            3,
            100, 100, 100,
             -2, -5, -8, -9,-13,-15,-12,-33,-27,-16,
              2,  4,  6, 11, 14, 18, 16, 16, 20, 48,
            4,
            100, 100, 100,
             -3, -7,-12,-12,-19,-21,-29,-40,-52,-26,
              3,  7,  9, 17, 20, 25, 29, 23, 28, 60,
            5,
             80,  80,  80,
             -3, -7,-12,-12,-19,-21,-29,-40,-52,-26,
              3,  7,  9, 17, 20, 25, 29, 23, 28, 60,
            6,
             66,  66,  66,
             -3, -7,-12,-12,-19,-21,-29,-40,-52,-26,
              3,  7,  9, 17, 20, 25, 29, 23, 28, 60,
            7,
             57,  57,  57,
             -3, -7,-12,-12,-19,-21,-29,-40,-52,-26,
              3,  7,  9, 17, 20, 25, 29, 23, 28, 60,
            8,
             50,  50,  50,
             -3, -7,-12,-12,-19,-21,-29,-40,-52,-26,
              3,  7,  9, 17, 20, 25, 29, 23, 28, 60,
            9,
             44,  44,  44,
             -3, -7,-12,-12,-19,-21,-29,-40,-52,-26,
              3,  7,  9, 17, 20, 25, 29, 23, 28, 60,
            10,
             40,  40,  40,
             -3, -7,-12,-12,-19,-21,-29,-40,-52,-26,
              3,  7,  9, 17, 20, 25, 29, 23, 28, 60,
            11,
             36,  36,  36,
             -3, -7,-12,-12,-19,-21,-29,-40,-52,-26,
              3,  7,  9, 17, 20, 25, 29, 23, 28, 60,
            // shutterIdx=maxShutterIdx
            12,
             33,  33,  33,
             -3, -7,-12,-12,-19,-21,-29,-40,-52,-26,
              3,  7,  9, 17, 20, 25, 29, 23, 28, 60,
        }, // i4DampingTbls[500]

        // --- AFv2.5 ---
        {0},// i4Coefs[100];

        // --- AFv3.x --
        //i4AFv3Config[64]
        {               // Scene change parameters ; set both h_count and l_count as 0 to disable
         20000,         // [0] FV reliable TH
         50,            // [1] Zone number change percentage for judge to scene change
         66,            // [2] high-low frame time ms threshold

         18, 4, 3,      // [3~5] G-sum scene change ratio, h_count, l_count TH
         6, 4, 3,       // [6~8] G-sum scene stable ratio, h_count, l_count TH
         230, 35, 4, 3, // [9~12] FV scene change u_ratio, d_ratio, h_count, l_count TH
         18, 2, 2,      // [13~15] FV scene stable ratio, h_count, l_count TH

         15, 5, 3,      // [16~18] G-sum scene change ratio, h_count, l_count TH (Video)
         3, 10, 5,      // [19~21] G-sum scene stable ratio, h_count, l_count TH (Video)
         230, 30, 5, 3, // [22~25] FV scene change u_ratio, d_ratio, h_count, l_count TH (Video)
         8, 10, 5,      // [26~28] FV scene stable ratio, h_count, l_count TH (Video)
         0, 0,          // [29~30]
         0, 0, 0,       // [31~33] Ghist change thr, h_cnt, l_cnt
         0, 0, 0,       // [34~36] Ghist stable thr, h_cnt, l_cnt
         0, 0, 0,       // [37~39] Ghist change thr, h_cnt, l_cnt (video)
         0, 0, 0,       // [40~42] Ghist stable thr, h_cnt, l_cnt (video)
        },

        {// i4PLAFCoefs[64]
            1,          // [0] af_enable_pl
            2500,       // [1] pl_tuning_point_r_top
            2000000,    // [2] pl_tuning_point_a_s
            300,        // [3] pl_tuning_point_r_s
            8000000,    // [4] pl_tuning_point_a_b
            140,        // [5] pl_tuning_point_r_b
            70,         // [6] pl_bound_limit
            0x43C11,    // [7] pl_control_bit
            40,         // [8] pl_temperature_error
        },


        //i4HybridAFCoefs[64]
        {
        	  //[0] use default paramter
        	  1,
        	  //[1][2] tracking width and height
            37, 39,
            //[3][4] maximan PD window in the tracking range[1][2]
            3, 3,
            //[5][6][7][8][9] Reserved
            0,0,0,0,0,
            //[10] fine search smooth to peak
            0,
            //[11][12] fine search step [11]inf [12]mac
            70,50,
            //[13][14] fine search step at face case [13]inf [14]mac
            90,80,
            //[15][16] fine search step at touch case [15]inf [16]mac
            100,100,
            //[17]~[19] Reserved
            0,0,0,
            //[20] AF mark confidence
            20,
            //[21] AF mark fps
            15,
            //[22] Reserved
            0,
            //[23][24] trigger skip count when target in the converge threshold [23]CAF [24]TAF
            3,3,
            //[25] Moving low confidence count
            5,
            //[26] Moving timeout
            40,
            //[27] Fine search timeout
            12,
            //[28]~[32] Reserved
            0,0,0,0,0,
            //[33] Fine search control bit
            0x4F,
            //[34] Fine search interstep
            0,
            //[35] Reserved
            0,
            //[36][37][38] multi-source priority
            321,321,123,
            //[39]Reserved
            0,
            //[40] fine search scene stable mask
            0x1F,//[0x18]gyro acce,[0x1F]full
            //[41][42][43][44][45] fine search stable count, FV,GS,GH,ACCE,GYRO
            2,2,2,3,3,
            //[46]~[63] Reserved
            0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0
        },
        //i4PDAFCoefs[64]
        {
        	  //[0] use default paramter
            1,
            //[1] enable
            1,
            //[2][3] weak, strong threshold for continue AF
            50, 110,
            //[4][5] weak, strong threshold for touch AF
            50, 110,
            //[6][7] weak, strong threshold
            50, 70,
            //[8] wait source timeout
            5,
            //[9][10] update target each time. [9]CAF [10]TAF
            1,0,
            //[11][12] moving speed and speed mode at infinity. [11]mode [12]speed
            3,66,
            //[13][14] moving speed and speed mode at macro. [11]mode [12]speed
            3,66,
            //[15][16] extend param for moving [15]inf [16]mac
            120,120,
            //[17] touch assist move speed
            65,
            //[18][19] converage threshold [18]inf [19]mac
            150,150,
            //[20] reserved
            0,
            //[21]~[26] PD scene change param
            0,10,90,10,90,70,
            //[27]~[31]
            0,0,0,0,0,
            //[32]~[34]
            200,200,1,
            //[35]~[63] reserved
            0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0
        },
        //i4LDAFCoefs[64]
        {
            //[0] use default paramter
            1,
            //[1] enable
            0,
            //[2][3] weak, strong threshold for continue AF
            50, 110,
            //[4][5] weak, strong threshold for touch AF
            50, 110,
            //[6][7] weak, strong threshold
            50, 70,
            //[8] wait source timeout
            5,
            //[9][10] update target each time. [9]CAF [10]TAF
            0,0,
            //[11][12] moving speed and mode at infinity. [11]mode [12]speed
            1,66,
            //[13][14] moving speed and mode at macro. [11]mode [12]speed
            1,66,
            //[15][16] extend param for moving [15]inf [16]mac
            100,100,
            //[17] touch assist move speed
            65,
            //[18][19] converage threshold [18]inf [19]mac
            150,150,
            //[20] reserved
            0,
            //[21]~[26] LD scene change param
            0,10,90,10,90,70,
            //[27]~[64] reserved
            0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0
        },
        //i4SDAFCoefs[64]
        {
            //[0] use default paramter
            1,
            //[1] enable
            0,
            //[2][3] weak, strong threshold for continue AF
            50, 110,
            //[4][5] weak, strong threshold for touch AF
            50, 110,
            //[6][7] weak, strong threshold
            50, 70,
            //[8] wait source timeout
            5,
            //[9][10] update target each time. [9]CAF [10]TAF
            0,0,
            //[11][12] moving speed and mode at infinity. [11]mode [12]speed
            1,66,
            //[13][14] moving speed and mode at macro. [11]mode [12]speed
            1,66,
            //[15][16] extend param for moving [15]inf [16]mac
            100,100,
            //[17] touch assist move speed
            65,
            //[18][19] converage threshold [18]inf [19]mac
            150,150,
            //[20] reserved
            0,
            //[21]~[26] SD scene change param
            0,10,90,10,90,70,
            //[27]~[64] reserved
            0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0
        },
        {0},//i4FaceAFCoefs[64]
        {0},//i43DAFCoefs[64]

        {
            // Multi-zone parameters
            //[0][1]multi-zone AF area width, height
            37, 38,

            //[2][3]Normal main & sub TH
            10, 7,

            //[4][5]Strong peak main & sub TH
            30, 20,

            //[6]Long sample number TH
            6,

            //[7][8]Long sample main & sub TH
            15, 10,

            //[9]Extreme long sample number TH
            10,

            //[10][11]Extreme long sample main & sub TH
            50, 40,

            //[12][13]Normal & strong increase/decrease ratio
            7,  10,

            //[14][15]Flat FV ratio and sample TH
            10,  4,

            //[16][17] G-sum & Saturation count abnormal ratio
            10, 20,

            //[18]G-sum abnormal ratio while S-cnt abnormal
            2,

            //[19]S-cnt reliable TH
            100,

            //[20]Concave ratio TH
            5,

            //[21]Unknown sample TH
            3,

            //[22]FV reliable TH
            20000,

            //[23][24][25][26]preserve
            0,1,2,4,

            //[27]preserve
            50,

            //[28][29]Macro & inf green braket tolerance
            30, 20,

            //[30]~[47]Reserved
            0,  0,
            0,  0,
            0,0,0,
            0,  0,
            0,  0,
            0,  0,
            0,0,0,
            0,  0,

            //[48]ROI overlap scale
            130,

            //[49]Saturation level TH
            230,

            //[50] Back sample from current pos or near group center
            3,

            //[51]Fail position index
            3,

            //[52] only trigger by focused zone change (preview)
            0,

            // [53]~[63] Reserved
            0,0,0,0,0,0,0,0,0,0,0

        },//i4MultiAFCoefs[64]
        {0},//i4TempErr[64]
        {
        //[0] ROI compensation enable
        1,

        //[1]Extract method enable
        1,

        //[2]Extract Gyro TH
        10,

        //[3]Extract G-sum stable TH
        24,

        //[4]Extract S-cnt stable TH
        48,

        //[5]Zoom effect scale ratio N/10000
        618

        //[6]~[63] Reserved
        },//i4ZoEffect[64]
        {0},//i4DualAFCoefs[512]

        // --- reserved ---
        {0} //[256]
    },
    {//PD_NVRAM_T
        {//PD_CALIBRATION_DATA_T
            {0},
            0,
        },
        {//PD_ALGO_TUNING_T
            36,
            28,
            {30, 150,200,300,400},
            {384,410,435,461,486},
            {
                {0,0,0,0,0,0},
                {0,0,0,0,0,0},
            {0,20,20,20,20,20},
            {0,20,60,60,60,60},
            {0,20,60,60,60,60},
            {0,20,60,60,60,100}
            },
            240,     //i4SaturateLevel
            1,//8,   //i4SaturateThr
            1,       //i4ConfThr
            {0},
        },
    },

    { //DUALCAM_NVRAM_T
        0,
        0,
        {0}
    },

    // SCENARIO NVRAM
    {
        GET_DW9714AF_LENS_PARA_DEFAULT_VALUE<CAM_SCENARIO_PREVIEW>(),
        GET_DW9714AF_LENS_PARA_DEFAULT_VALUE<CAM_SCENARIO_VIDEO>(),
        GET_DW9714AF_LENS_PARA_DEFAULT_VALUE<CAM_SCENARIO_CAPTURE>(),
        GET_DW9714AF_LENS_PARA_DEFAULT_VALUE<CAM_SCENARIO_PREVIEW>(),
        GET_DW9714AF_LENS_PARA_DEFAULT_VALUE<CAM_SCENARIO_PREVIEW>(),
        GET_DW9714AF_LENS_PARA_DEFAULT_VALUE<CAM_SCENARIO_CUSTOM3>(),
        GET_DW9714AF_LENS_PARA_DEFAULT_VALUE<CAM_SCENARIO_PREVIEW>()
    },

    {0}
};

UINT32 DW9714AF_getDefaultData(VOID *pDataBuf, UINT32 size)
{
	UINT32 dataSize = sizeof(NVRAM_LENS_PARA_STRUCT);

    if ((pDataBuf == NULL) || (size < dataSize))
    {
        return 1;
    }

	// copy from Buff to global struct
    memcpy(pDataBuf, &DW9714AF_LENS_PARA_DEFAULT_VALUE, dataSize);

    return 0;
}

PFUNC_GETLENSDEFAULT pDW9714AF_getDefaultData = DW9714AF_getDefaultData;

