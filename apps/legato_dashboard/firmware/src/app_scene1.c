/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdio.h>
#include "app.h"
#include "definitions.h"
#include "gfx/canvas/gfx_canvas_api.h"
#include "gfx/driver/controller/glcd/plib_glcd.h"
#include "gfx/driver/controller/glcd/drv_gfx_glcd.h"

static uint32_t targetLeftNeedleAngle = 0;
static uint32_t targetRightNeedleAngle = 0;
static uint32_t nextLeftNeedleAngle = 0;
static uint32_t nextRightNeedleAngle = 0;
static uint32_t currentLeftNeedleAngle = 0;
static uint32_t currentRightNeedleAngle = 0;
static bool backgroundAnimDone = false;
static bool leftGaugeAnimDone = false;
static bool rightGaugeAnimDone = false;
static unsigned int maxNeedleValue;

static SYS_INP_InputListener app_inputListener;

static int lastX, lastY;
static bool leftEdgeDownFlag = false;
static bool rightEdgeDownFlag = false;
static bool topEdgeDownFlag = false;
static unsigned int lastTouchDownCount = 0;
static int inputListenerID = 0;

extern SYS_TIME_HANDLE timer;
static volatile unsigned int demoModeCounter = 0;;
static volatile unsigned int demoModeValuesIndex = 0;

static SYS_TIME_HANDLE selfDemoTimer;

static DEMO_MODE_GAUGE_VALUES demoModeGaugeValues[] =
{
    {180, 180},
    {0, 0},
    {180, 0},
    {0, 180},
    {0, 0},
    {180, 0},
    {95, 180},
    {180, 0},
};

static DEMO_MODE_GAUGE_VALUES demoModeGaugeValues2[] =
{
    {226, 226},
    {0, 0},
    {226, 0},
    {0, 226},
    {0, 0},
    {226, 0},
    {110, 226},
    {226, 0},
};

static void APP_SCENE2_initialize_needle_lookup_table(void)
{
    memset(leftNeedles, 0, sizeof(leftNeedles));
    memset(rightNeedles, 0, sizeof(rightNeedles));
    
    appSetRightNeedleImageData(&n_02_84_240, 44, 535, 233);
    appSetRightNeedleImageData(&n_04_85_242, 42, 536, 235);
    appSetRightNeedleImageData(&n_06_84_244, 40, 536, 237);
    appSetRightNeedleImageData(&n_08_88_246, 38, 539, 239);
    appSetRightNeedleImageData(&n_10_89_248, 36, 540, 240);
    appSetRightNeedleImageData(&n_12_91_250, 34, 541, 241);
    appSetRightNeedleImageData(&n_14_90_251, 32, 540, 240);
    appSetRightNeedleImageData(&n_16_92_254, 30, 542, 242);
    appSetRightNeedleImageData(&n_18_93_256, 28, 543, 243);
    appSetRightNeedleImageData(&n_20_95_258, 26, 545, 244);
    appSetRightNeedleImageData(&n_22_98_259, 24, 546, 246);
    appSetRightNeedleImageData(&n_24_99_262, 22, 547, 247);
    appSetRightNeedleImageData(&n_26_97_255, 20, 546, 250);
    appSetRightNeedleImageData(&n_28_104_257, 18, 553, 252);
    appSetRightNeedleImageData(&n_30_106_259, 16, 555, 253);
    appSetRightNeedleImageData(&n_32_108_261, 14, 556, 255);
    appSetRightNeedleImageData(&n_34_110_264, 12, 559, 256);
    appSetRightNeedleImageData(&n_36_111_273, 10, 559, 256);
    appSetRightNeedleImageData(&n_38_117_275, 8, 563, 257);
    appSetRightNeedleImageData(&n_40_120_277, 6, 565, 259);
    appSetRightNeedleImageData(&n_42_121_280, 4, 566, 259);
    appSetRightNeedleImageData(&n_44_125_280, 2, 568, 259);
    appSetRightNeedleImageData(&n_46_127_280, 0, 569, 258);

    appSetRightNeedleImageData(&n000_88_238, 46, 539, 231);
    appSetRightNeedleImageData(&n002_88_233, 48, 539, 227);
    appSetRightNeedleImageData(&n004_89_228, 50, 539, 223);
    appSetRightNeedleImageData(&n006_88_223, 52, 539, 219);
    appSetRightNeedleImageData(&n008_89_219, 54, 540, 216);
    appSetRightNeedleImageData(&n010_89_214, 56, 539, 212);
    appSetRightNeedleImageData(&n012_90_210, 58, 540, 209);
    appSetRightNeedleImageData(&n014_91_209, 60, 541, 208);
    appSetRightNeedleImageData(&n016_89_205, 62, 539, 205);
    appSetRightNeedleImageData(&n018_91_200, 64, 540, 201);
    appSetRightNeedleImageData(&n020_92_196, 66, 541, 198);
    appSetRightNeedleImageData(&n022_94_191, 68, 542, 193);
    appSetRightNeedleImageData(&n024_96_187, 70, 544, 189);
    appSetRightNeedleImageData(&n026_97_183, 72, 545, 185);
    appSetRightNeedleImageData(&n028_100_177, 74, 549, 180);
    appSetRightNeedleImageData(&n030_102_173, 76, 551, 177);
    appSetRightNeedleImageData(&n032_104_170, 78, 552, 172);
    appSetRightNeedleImageData(&n034_107_167, 80, 556, 169);
    appSetRightNeedleImageData(&n036_110_163, 82, 559, 165);
    appSetRightNeedleImageData(&n038_112_159, 84, 561, 161);
    appSetRightNeedleImageData(&n040_115_155, 86, 563, 158);
    appSetRightNeedleImageData(&n042_118_152, 88, 565, 156);
    appSetRightNeedleImageData(&n044_121_149, 90, 568, 154);
    appSetRightNeedleImageData(&n046_125_145, 92, 570, 151);
    appSetRightNeedleImageData(&n048_128_142, 94, 573, 148);
    appSetRightNeedleImageData(&n050_132_139, 96, 577, 146);
    appSetRightNeedleImageData(&n052_135_136, 98, 580, 143);
    appSetRightNeedleImageData(&n054_138_154, 100, 583, 141);
    appSetRightNeedleImageData(&n056_142_131, 102, 586, 139);
    appSetRightNeedleImageData(&n058_146_128, 104, 589, 136);
    appSetRightNeedleImageData(&n060_149_126, 106, 590, 134);
    appSetRightNeedleImageData(&n062_153_123, 108, 593, 133);
    appSetRightNeedleImageData(&n064_157_121, 110, 597, 131);
    appSetRightNeedleImageData(&n066_161_118, 112, 601, 128);
    appSetRightNeedleImageData(&n068_165_116, 114, 604, 127);
    appSetRightNeedleImageData(&n070_170_115, 116, 608, 126);
    appSetRightNeedleImageData(&n072_174_113, 118, 611, 124);
    appSetRightNeedleImageData(&n074_177_110, 120, 614, 122);
    appSetRightNeedleImageData(&n076_182_110, 122, 619, 122);
    appSetRightNeedleImageData(&n078_187_109, 124, 624, 120);
    appSetRightNeedleImageData(&n080_191_108, 126, 628, 119);
    appSetRightNeedleImageData(&n082_196_107, 128, 632, 119);
    appSetRightNeedleImageData(&n084_200_106, 130, 634, 118);
    appSetRightNeedleImageData(&n086_205_106, 132, 639, 118);
    appSetRightNeedleImageData(&n088_207_105, 134, 641, 117);
    
    appSetRightNeedleImageData(&n000_627_238, 226, 690, 231);
    appSetRightNeedleImageData(&n002_626_235, 224, 689, 228);
    appSetRightNeedleImageData(&n004_626_232, 222, 689, 225);
    appSetRightNeedleImageData(&n006_626_227, 220, 689, 221);
    appSetRightNeedleImageData(&n008_625_223, 218, 688, 217);
    appSetRightNeedleImageData(&n010_624_218, 216, 687, 212);
    appSetRightNeedleImageData(&n012_624_213, 214, 687, 208);
    appSetRightNeedleImageData(&n014_623_209, 212, 686, 205);
    appSetRightNeedleImageData(&n016_625_205, 210, 689, 202);
    appSetRightNeedleImageData(&n018_625_200, 208, 689, 198);
    appSetRightNeedleImageData(&n020_624_196, 206, 688, 195);
    appSetRightNeedleImageData(&n022_623_191, 204, 687, 191);
    appSetRightNeedleImageData(&n024_622_186, 202, 687, 188);
    appSetRightNeedleImageData(&n026_621_183, 200, 686, 184);
    appSetRightNeedleImageData(&n028_620_177, 198, 685, 179);
    appSetRightNeedleImageData(&n030_618_174, 196, 683, 177);
    appSetRightNeedleImageData(&n032_617_170, 194, 683, 173);
    appSetRightNeedleImageData(&n034_616_166, 192, 682, 170);
    appSetRightNeedleImageData(&n036_615_163, 190, 681, 166);
    appSetRightNeedleImageData(&n038_613_159, 188, 679, 163);
    appSetRightNeedleImageData(&n040_612_155, 186, 678, 159);
    appSetRightNeedleImageData(&n042_610_152, 184, 677, 157);
    appSetRightNeedleImageData(&n044_608_149, 182, 675, 155);
    appSetRightNeedleImageData(&n046_607_145, 180, 675, 152);
    appSetRightNeedleImageData(&n048_605_142, 178, 674, 149);
    appSetRightNeedleImageData(&n050_603_139, 176, 672, 147);
    appSetRightNeedleImageData(&n052_602_136, 174, 672, 144);
    appSetRightNeedleImageData(&n054_601_134, 172, 672, 142);
    appSetRightNeedleImageData(&n056_599_131, 170, 670, 140);
    appSetRightNeedleImageData(&n058_597_128, 168, 669, 137);
    appSetRightNeedleImageData(&n060_596_125, 166, 669, 135);
    appSetRightNeedleImageData(&n062_594_123, 164, 667, 133);
    appSetRightNeedleImageData(&n064_592_121, 162, 665, 131);
    appSetRightNeedleImageData(&n066_590_118, 160, 663, 128);
    appSetRightNeedleImageData(&n068_588_116, 158, 661, 126);
    appSetRightNeedleImageData(&n070_586_115, 156, 660, 125);
    appSetRightNeedleImageData(&n072_584_113, 154, 658, 123);
    appSetRightNeedleImageData(&n074_583_111, 152, 659, 122);
    appSetRightNeedleImageData(&n076_581_110, 150, 659, 122);
    appSetRightNeedleImageData(&n078_577_109, 148, 657, 121);
    appSetRightNeedleImageData(&n080_576_108, 146, 655, 120);
    appSetRightNeedleImageData(&n082_576_107, 144, 653, 119);
    appSetRightNeedleImageData(&n084_571_106, 142, 652, 119);
    appSetRightNeedleImageData(&n086_570_106, 140, 651, 119);
    appSetRightNeedleImageData(&n088_569_105, 138, 650, 118);
    appSetRightNeedleImageData(&n090_567_105, 136, 649, 119);


}


static void UpdateLeftNeedle(uint32_t newAngle)
{
    if (newAngle < 360)
    {
        if (appData.state == APP_STATE_PROCESS_SCENE1 &&
            leftNeedles[newAngle].imgAst != NULL)
        {
            appSetLayerFrame(LEFT_NEEDLE_CANVAS_ID, 
                         (uint32_t) leftNeedles[newAngle].imgAst->buffer.pixels, 
                         leftNeedles[newAngle].x,
                         leftNeedles[newAngle].y,
                         leftNeedles[newAngle].imgAst->buffer.size.width, 
                         leftNeedles[newAngle].imgAst->buffer.size.height);               
        }
        else if (appData.state == APP_STATE_PROCESS_SCENE2 &&
                rightNeedles[newAngle].imgAst != NULL)
        {
            appSetLayerFrame(LEFT_NEEDLE_CANVAS_ID, 
                             (uint32_t) rightNeedles[newAngle].imgAst->buffer.pixels, 
                             rightNeedles[newAngle].x - 513,
                             rightNeedles[newAngle].y,
                             rightNeedles[newAngle].imgAst->buffer.size.width, 
                             rightNeedles[newAngle].imgAst->buffer.size.height);  
        }
    }
}

static void UpdateRightNeedle(uint32_t newAngle)
{
    if (newAngle < 360 && rightNeedles[newAngle].imgAst != NULL)
    {
        appSetLayerFrame(RIGHT_NEEDLE_CANVAS_ID, 
                         (uint32_t) rightNeedles[newAngle].imgAst->buffer.pixels, 
                         rightNeedles[newAngle].x,
                         rightNeedles[newAngle].y,
                         rightNeedles[newAngle].imgAst->buffer.size.width, 
                         rightNeedles[newAngle].imgAst->buffer.size.height);             
    }
}

void SetGaugeTarget(int x, int y)
{
    switch (appData.state)
    {
        case APP_STATE_PROCESS_SCENE1:
        {
            if (x < 220)
            {
                if (y < 110)
                    targetLeftNeedleAngle = maxNeedleValue;
                else if (y > 370)
                    targetLeftNeedleAngle = 0;
                else
                    targetLeftNeedleAngle = maxNeedleValue - ((y - 110) * 180) / 260;
            }
            else if (x >= 580)
            {
                if (y < 110)
                    targetRightNeedleAngle = maxNeedleValue;
                else if (y > 370)
                    targetRightNeedleAngle = 0;
                else
                    targetRightNeedleAngle = maxNeedleValue - ((y - 110) * 180) / 260;
            }
            else
            {
                if (x < 220)
                    targetRightNeedleAngle = maxNeedleValue;
                else if (x > 580)
                    targetRightNeedleAngle = 0;
                else
                    targetRightNeedleAngle = maxNeedleValue - (x - 220) / 2;

                if (y < 60)
                    targetLeftNeedleAngle = maxNeedleValue;
                else if (y > 420)
                    targetLeftNeedleAngle = 0;
                else
                    targetLeftNeedleAngle = maxNeedleValue - (y - 60) / 2;
            }
            break;
        }
        case APP_STATE_PROCESS_SCENE2:
        {
            if (x < 220)
            {
                if (y < 110)
                    targetLeftNeedleAngle = maxNeedleValue;
                else if (y > 370)
                    targetLeftNeedleAngle = 0;
                else
                    targetLeftNeedleAngle = maxNeedleValue - ((y - 110) * maxNeedleValue) / 260;
            }
            else if (x >= 580)
            {
                if (y < 110)
                    targetRightNeedleAngle = maxNeedleValue;
                else if (y > 370)
                    targetRightNeedleAngle = 0;
                else
                    targetRightNeedleAngle = maxNeedleValue - ((y - 110) * maxNeedleValue) / 260;
            }
            else
            {
                if (x < 291)
                    targetRightNeedleAngle = maxNeedleValue;
                else if (x > 516)
                    targetRightNeedleAngle = 0;
                else
                    targetRightNeedleAngle = maxNeedleValue - (x - 291) / 2;

                if (y < 131)
                    targetLeftNeedleAngle = maxNeedleValue;
                else if (y > 356)
                    targetLeftNeedleAngle = 0;
                else
                    targetLeftNeedleAngle = maxNeedleValue - (y - 131) / 2;
            }
            break;
        }
        default:
            break;
    }
}

static void UpdateGauges(uint32_t leftGaugeValue, uint32_t rightGaugeValue)
{
    uint32_t updateLeft = 0, updateRight = 0;
    
    switch (appData.state)
    {
        case APP_STATE_PROCESS_SCENE1:
        {
            if (leftGaugeValue < 360 && leftNeedles[leftGaugeValue].imgAst != NULL)
                updateLeft = 1;
            
            if (rightGaugeValue < 360 && rightNeedles[rightGaugeValue].imgAst != NULL)
                updateRight = 1;
            
            break;
        }
        case APP_STATE_PROCESS_SCENE2:
        {   
            if (leftGaugeValue < 360 && rightNeedles[leftGaugeValue].imgAst != NULL)
                updateLeft = 1;

            if (rightGaugeValue < 360 && rightNeedles[rightGaugeValue].imgAst != NULL)
                updateRight = 1;
            break;
        }
        default:
            break;
    }
    
    if (updateRight || updateLeft)
    {
        if (updateRight)
        {
            UpdateRightNeedle(rightGaugeValue);
            currentRightNeedleAngle = rightGaugeValue;
        }
        
        if (updateLeft)
        {
            UpdateLeftNeedle(leftGaugeValue);
            currentLeftNeedleAngle = leftGaugeValue;
        }
    }
}

static void APP_SCENE1_initialize_needle_lookup_table(void)
{
    memset(leftNeedles, 0, sizeof(leftNeedles));
    memset(rightNeedles, 0, sizeof(rightNeedles));
    
    //Q1 Needles (0 - 90) for Right Gauge
    appSetRightNeedleImageData(&n000_627_238, 90, 627, 238);
    appSetRightNeedleImageData(&n002_626_235, 92, 626, 235);
    appSetRightNeedleImageData(&n004_626_232, 94, 626, 232);
    appSetRightNeedleImageData(&n006_626_227, 96, 626, 227);
    appSetRightNeedleImageData(&n008_625_223, 98, 625, 223);
    appSetRightNeedleImageData(&n010_624_218, 100, 624, 218);
    appSetRightNeedleImageData(&n012_624_213, 102, 624, 213);
    appSetRightNeedleImageData(&n014_623_209, 104, 623, 209);
    appSetRightNeedleImageData(&n016_625_205, 106, 625, 205);
    appSetRightNeedleImageData(&n018_625_200, 108, 625, 200);
    appSetRightNeedleImageData(&n020_624_196, 110, 624, 196);
    appSetRightNeedleImageData(&n022_623_191, 112, 623, 191);
    appSetRightNeedleImageData(&n024_622_186, 114, 622, 186);
    appSetRightNeedleImageData(&n026_621_183, 116, 621, 183);
    appSetRightNeedleImageData(&n028_620_177, 118, 620, 177);
    appSetRightNeedleImageData(&n030_618_174, 120, 618, 174);
    appSetRightNeedleImageData(&n032_617_170, 122, 617, 170);
    appSetRightNeedleImageData(&n034_616_166, 124, 616, 166);
    appSetRightNeedleImageData(&n036_615_163, 126, 615, 163);
    appSetRightNeedleImageData(&n038_613_159, 128, 613, 159);
    appSetRightNeedleImageData(&n040_612_155, 130, 612, 155);
    appSetRightNeedleImageData(&n042_610_152, 132, 610, 152);
    appSetRightNeedleImageData(&n044_608_149, 134, 608, 149);
    appSetRightNeedleImageData(&n046_607_145, 136, 607, 145);
    appSetRightNeedleImageData(&n048_605_142, 138, 605, 142);
    appSetRightNeedleImageData(&n050_603_139, 140, 603, 139);
    appSetRightNeedleImageData(&n052_602_136, 142, 602, 136);
    appSetRightNeedleImageData(&n054_601_134, 144, 601, 134);
    appSetRightNeedleImageData(&n056_599_131, 146, 599, 131);
    appSetRightNeedleImageData(&n058_597_128, 148, 597, 128);
    appSetRightNeedleImageData(&n060_596_125, 150, 596, 125);
    appSetRightNeedleImageData(&n062_594_123, 152, 594, 123);
    appSetRightNeedleImageData(&n064_592_121, 154, 592, 121);
    appSetRightNeedleImageData(&n066_590_118, 156, 590, 118);
    appSetRightNeedleImageData(&n068_588_116, 158, 588, 116);
    appSetRightNeedleImageData(&n070_586_115, 160, 586, 115);
    appSetRightNeedleImageData(&n072_584_113, 162, 584, 113);
    appSetRightNeedleImageData(&n074_583_111, 164, 583, 111);
    appSetRightNeedleImageData(&n076_581_110, 166, 581, 110);
    appSetRightNeedleImageData(&n078_577_109, 168, 577, 109);
    appSetRightNeedleImageData(&n080_576_108, 170, 576, 108);
    appSetRightNeedleImageData(&n082_576_107, 172, 576, 107);
    appSetRightNeedleImageData(&n084_571_106, 174, 571, 106);
    appSetRightNeedleImageData(&n086_570_106, 176, 570, 106);
    appSetRightNeedleImageData(&n088_569_105, 178, 569, 105);
    appSetRightNeedleImageData(&n090_567_105, 180, 567, 105);

    //Q2 Needles (90 - 180)
    appSetLeftNeedleImageData(&n000_88_238, 90, 88, 238);
    appSetLeftNeedleImageData(&n002_88_233, 92, 88, 233);
    appSetLeftNeedleImageData(&n004_89_228, 94, 89, 228);
    appSetLeftNeedleImageData(&n006_88_223, 96, 88, 223);
    appSetLeftNeedleImageData(&n008_89_219, 98, 89, 219);
    appSetLeftNeedleImageData(&n010_89_214, 100, 89, 214);
    appSetLeftNeedleImageData(&n012_90_210, 102, 90, 210);
    appSetLeftNeedleImageData(&n014_91_209, 104, 91, 209);
    appSetLeftNeedleImageData(&n016_89_205, 106, 89, 205);
    appSetLeftNeedleImageData(&n018_91_200, 108, 91, 200);
    appSetLeftNeedleImageData(&n020_92_196, 110, 92, 196);
    appSetLeftNeedleImageData(&n022_94_191, 112, 94, 191);
    appSetLeftNeedleImageData(&n024_96_187, 114, 96, 187);
    appSetLeftNeedleImageData(&n026_97_183, 116, 97, 183);
    appSetLeftNeedleImageData(&n028_100_177, 118, 100, 177);
    appSetLeftNeedleImageData(&n030_102_173, 120, 102, 173);
    appSetLeftNeedleImageData(&n032_104_170, 122, 104, 170);
    appSetLeftNeedleImageData(&n034_107_167, 124, 107, 167);
    appSetLeftNeedleImageData(&n036_110_163, 126, 110, 163);
    appSetLeftNeedleImageData(&n038_112_159, 128, 112, 159);
    appSetLeftNeedleImageData(&n040_115_155, 130, 115, 155);
    appSetLeftNeedleImageData(&n042_118_152, 132, 118, 152);
    appSetLeftNeedleImageData(&n044_121_149, 134, 121, 149);
    appSetLeftNeedleImageData(&n046_125_145, 136, 125, 145);
    appSetLeftNeedleImageData(&n048_128_142, 138, 128, 142);
    appSetLeftNeedleImageData(&n050_132_139, 140, 132, 139);
    appSetLeftNeedleImageData(&n052_135_136, 142, 135, 136);
    appSetLeftNeedleImageData(&n054_138_154, 144, 138, 134);
    appSetLeftNeedleImageData(&n056_142_131, 146, 142, 131);
    appSetLeftNeedleImageData(&n058_146_128, 148, 146, 128);
    appSetLeftNeedleImageData(&n060_149_126, 150, 149, 126);
    appSetLeftNeedleImageData(&n062_153_123, 152, 153, 123);
    appSetLeftNeedleImageData(&n064_157_121, 154, 157, 121);
    appSetLeftNeedleImageData(&n066_161_118, 156, 161, 118);
    appSetLeftNeedleImageData(&n068_165_116, 158, 165, 116);
    appSetLeftNeedleImageData(&n070_170_115, 160, 170, 115);
    appSetLeftNeedleImageData(&n072_174_113, 162, 174, 113);
    appSetLeftNeedleImageData(&n074_177_110, 164, 177, 110);
    appSetLeftNeedleImageData(&n076_182_110, 166, 182, 110);
    appSetLeftNeedleImageData(&n078_187_109, 168, 187, 109);
    appSetLeftNeedleImageData(&n080_191_108, 170, 191, 108);
    appSetLeftNeedleImageData(&n082_196_107, 172, 196, 107);
    appSetLeftNeedleImageData(&n084_200_106, 174, 200, 106);
    appSetLeftNeedleImageData(&n086_205_106, 176, 205, 106);
    appSetLeftNeedleImageData(&n088_207_105, 178, 207, 105);
    appSetLeftNeedleImageData(&n090_210_106, 180, 210, 106);

    //Q3 leftNeedles (180 - 270)
    appSetLeftNeedleImageData(&n_02_84_240, 88, 84, 240);
    appSetLeftNeedleImageData(&n_04_85_242, 86, 85, 242);
    appSetLeftNeedleImageData(&n_06_84_244, 84, 84, 244);
    appSetLeftNeedleImageData(&n_08_88_246, 82, 88, 246);
    appSetLeftNeedleImageData(&n_10_89_248, 80, 89, 248);
    appSetLeftNeedleImageData(&n_12_91_250, 78, 91, 250);
    appSetLeftNeedleImageData(&n_14_90_251, 76, 90, 251);
    appSetLeftNeedleImageData(&n_16_92_254, 74, 92, 254);
    appSetLeftNeedleImageData(&n_18_93_256, 72, 93, 256);
    appSetLeftNeedleImageData(&n_20_95_258, 70, 95, 258);
    appSetLeftNeedleImageData(&n_22_98_259, 68, 98, 259);
    appSetLeftNeedleImageData(&n_24_99_262, 66, 99, 262);
    appSetLeftNeedleImageData(&n_26_97_255, 64, 98, 264);
    appSetLeftNeedleImageData(&n_28_104_257, 62, 105, 266);
    appSetLeftNeedleImageData(&n_30_106_259, 60, 107, 269);
    appSetLeftNeedleImageData(&n_32_108_261, 58, 110, 271);
    appSetLeftNeedleImageData(&n_34_110_264, 56, 110, 271);
    appSetLeftNeedleImageData(&n_36_111_273, 54, 111, 273);
    appSetLeftNeedleImageData(&n_38_117_275, 52, 117, 275);
    appSetLeftNeedleImageData(&n_40_120_277, 50, 120, 277);
    appSetLeftNeedleImageData(&n_42_121_280, 48, 121, 280);
    appSetLeftNeedleImageData(&n_44_125_280, 46, 123, 282);
    appSetLeftNeedleImageData(&n_46_127_280, 44, 126, 282);
    appSetLeftNeedleImageData(&n_48_129_282, 42, 127, 283);
    appSetLeftNeedleImageData(&n_50_136_285, 40, 136, 284);
    appSetLeftNeedleImageData(&n_52_140_285, 38, 140, 285);
    appSetLeftNeedleImageData(&n_54_140_286, 36, 140, 286);
    appSetLeftNeedleImageData(&n_56_147_287, 34, 147, 287);
    appSetLeftNeedleImageData(&n_58_150_289, 32, 150, 289);
    appSetLeftNeedleImageData(&n_60_151_289, 30, 151, 289);
    appSetLeftNeedleImageData(&n_62_159_292, 28, 159, 292);
    appSetLeftNeedleImageData(&n_64_163_293, 26, 163, 293);
    appSetLeftNeedleImageData(&n_66_167_294, 24, 167, 294);
    appSetLeftNeedleImageData(&n_68_16_295, 22, 168, 295);
    appSetLeftNeedleImageData(&n_70_175_295, 20, 175, 295);
    appSetLeftNeedleImageData(&n_72_180_296, 18, 180, 296);
    appSetLeftNeedleImageData(&n_74_184_296, 16, 184, 296);
    appSetLeftNeedleImageData(&n_76_188_297, 14, 188, 297);
    appSetLeftNeedleImageData(&n_78_193_297, 12, 193, 297);
    appSetLeftNeedleImageData(&n_80_197_299, 10, 197, 299);
    appSetLeftNeedleImageData(&n_82_200_300, 8, 200, 300);
    appSetLeftNeedleImageData(&n_84_206_301, 6, 206, 301);
    appSetLeftNeedleImageData(&n_86_211_301, 4, 211, 301);
    appSetLeftNeedleImageData(&n_88_214_302, 2, 214, 302);
    appSetLeftNeedleImageData(&n_90_217_301, 0, 217, 301);

     //Q4 Needles (270 - 358) for Right Gauge
    appSetRightNeedleImageData(&n270_559_301, 0, 559, 301);
    appSetRightNeedleImageData(&n272_562_302, 2, 562, 302);
    appSetRightNeedleImageData(&n274_564_301, 4, 564, 301);
    appSetRightNeedleImageData(&n276_566_301, 6, 566, 301);
    appSetRightNeedleImageData(&n278_569_300, 8, 569, 300);
    appSetRightNeedleImageData(&n280_570_299, 10, 570, 299);
    appSetRightNeedleImageData(&n282_572_298, 12, 572, 298);
    appSetRightNeedleImageData(&n284_574_297, 14, 574, 297);
    appSetRightNeedleImageData(&n286_576_297, 16, 576, 297);
    appSetRightNeedleImageData(&n288_578_296, 18, 578, 296);
    appSetRightNeedleImageData(&n290_580_295, 20, 580, 295);
    appSetRightNeedleImageData(&n292_582_295, 22, 582, 295);
    appSetRightNeedleImageData(&n294_583_294, 24, 583, 294);
    appSetRightNeedleImageData(&n296_585_293, 26, 585, 293);
    appSetRightNeedleImageData(&n298_587_292, 28, 587, 292);
    appSetRightNeedleImageData(&n300_587_290, 30, 587, 290);
    appSetRightNeedleImageData(&n302_591_290, 32, 591, 290);
    appSetRightNeedleImageData(&n304_592_288, 34, 592, 288);
    appSetRightNeedleImageData(&n306_595_287, 36, 595, 287);
    appSetRightNeedleImageData(&n308_597_285, 38, 597, 285);
    appSetRightNeedleImageData(&n310_599_285, 40, 599, 285);
    appSetRightNeedleImageData(&n312_597_282, 42, 597, 282);
    appSetRightNeedleImageData(&n314_602_282, 44, 602, 282);
    appSetRightNeedleImageData(&n316_604_280, 46, 604, 280);
    appSetRightNeedleImageData(&n318_606_280, 48, 606, 280);
    appSetRightNeedleImageData(&n320_607_277, 50, 607, 277);
    appSetRightNeedleImageData(&n322_608_275, 52, 608, 275);
    appSetRightNeedleImageData(&n324_611_274, 54, 611, 274);
    appSetRightNeedleImageData(&n326_613_271, 56, 613, 271);
    appSetRightNeedleImageData(&n328_611_271, 58, 611, 271);
    appSetRightNeedleImageData(&n330_613_269, 60, 613, 269);
    appSetRightNeedleImageData(&n332_615_266, 62, 615, 266);
    appSetRightNeedleImageData(&n334_620_264, 64, 620, 264);
    appSetRightNeedleImageData(&n336_617_262, 66, 617, 262);
    appSetRightNeedleImageData(&n338_618_259, 68, 618, 259);
    appSetRightNeedleImageData(&n340_621_259, 70, 621, 259);
    appSetRightNeedleImageData(&n342_622_256, 72, 622, 256);
    appSetRightNeedleImageData(&n344_623_254, 74, 623, 254);
    appSetRightNeedleImageData(&n346_619_251, 76, 619, 251);
    appSetRightNeedleImageData(&n348_624_250, 78, 624, 250);
    appSetRightNeedleImageData(&n350_625_248, 80, 625, 248);
    appSetRightNeedleImageData(&n352_625_246, 82, 625, 246);
    appSetRightNeedleImageData(&n354_629_244, 84, 629, 244);
    appSetRightNeedleImageData(&n356_629_242, 86, 629, 242);
    appSetRightNeedleImageData(&n358_629_240, 88, 629, 240);
}

void APP_Scene_EffectsCallback(unsigned int canvasID,
                                GFXC_FX_TYPE effect,
                                GFXC_FX_STATUS status,
                                void * parm)
{
    if (status == GFXC_FX_DONE)
    {
        switch (canvasID)
        {
            case BACKGROUND_CANVAS_ID:
                backgroundAnimDone = true;
                break;
            case LEFT_NEEDLE_CANVAS_ID:
                leftGaugeAnimDone = true;
                break;
            case RIGHT_NEEDLE_CANVAS_ID:
                rightGaugeAnimDone = true;
                break;
            default:
                break;
        }
    }
}

static void app_touchDownHandler(const SYS_INP_TouchStateEvent* const evt)
{
    if (animCounter > lastTouchDownCount && (animCounter - lastTouchDownCount < DOUBLE_TAP_COUNT_LIMIT))
        appData.scene_state = APP_SCENE_STATE_SWITCH_SCENE_1_2_0;
    
    switch (appData.state)
    {
        case APP_STATE_PROCESS_SCENE1:
        {
            if (evt->x > RIGHT_EDGE_TOUCH_X_MIN)
            {
                rightEdgeDownFlag = true;
                lastX = evt->x;
                lastY = evt->y;
            }
            else if (evt->y < TOP_EDGE_TOUCH_Y_MAX)
            {
                topEdgeDownFlag = true;
                lastX = evt->x;
                lastY = evt->y;
            }
            else
            {
                topEdgeDownFlag = false;
                rightEdgeDownFlag = false;
            }
            break;
        }
        case APP_STATE_PROCESS_SCENE2:
        {   
            if (evt->x < LEFT_EDGE_TOUCH_X_MAX)
            {
                leftEdgeDownFlag = true;
                lastX = evt->x;
                lastY = evt->y;
            }
            else if (evt->y < TOP_EDGE_TOUCH_Y_MAX)
            {
                topEdgeDownFlag = true;
                lastX = evt->x;
                lastY = evt->y;
            }
            else
            {
                topEdgeDownFlag = false;
                leftEdgeDownFlag = false;
            }
            break;
        }
        default:
            break;
    }    
    
    
    SetGaugeTarget(evt->x, evt->y);    
    
    demoModeCounter = 0;
    lastTouchDownCount = animCounter;
}

static void app_touchUpHandler(const SYS_INP_TouchStateEvent* const evt)
{
    rightEdgeDownFlag = false;
    leftEdgeDownFlag = false;
    topEdgeDownFlag = false;
}

static void app_touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt)
{
    if (appData.scene_state != APP_SCENE_STATE_PROCESS_TASKS)
        return;
    
    switch (appData.state)
    {
        case APP_STATE_PROCESS_SCENE1:
        {
            if ((rightEdgeDownFlag == true) &&
                (lastX > evt->x) && 
                (lastX - evt->x > SWIPE_THRESHOLD_PIXELS) &&
                (appData.state == APP_STATE_PROCESS_SCENE1))
            {
                    appData.scene_state = APP_SCENE_STATE_SWITCH_SCENE_1_2_0;
            }
            else if ((topEdgeDownFlag == true) &&
                (lastY < evt->y) && 
                (evt->y - lastY > SWIPE_THRESHOLD_PIXELS))
            {
                    appData.scene_state = APP_SCENE_STATE_SHOW_HELP;
            }    
            else
            {
                SetGaugeTarget(evt->x, evt->y);
            }
            break;
        }
        case APP_STATE_PROCESS_SCENE2:
        {
            if ((leftEdgeDownFlag == true) &&
                (lastX < evt->x) && 
                (evt->x - lastX > SWIPE_THRESHOLD_PIXELS))
            {
                    appData.scene_state = APP_SCENE_STATE_SWITCH_SCENE_1_2_0;
            }
            else if ((topEdgeDownFlag == true) &&
                    (lastY < evt->y) && 
                    (evt->y - lastY > SWIPE_THRESHOLD_PIXELS))
            {
                    appData.scene_state = APP_SCENE_STATE_SHOW_HELP;
            }    
            else
            {
                SetGaugeTarget(evt->x, evt->y);
            }
            break;
        }
        default:
            break;
    }
    
    leftEdgeDownFlag = false;
    rightEdgeDownFlag = false;
    topEdgeDownFlag = false;    
    demoModeCounter = 0; 
    
    lastX = evt->x;
    lastY = evt->y;
}

void APP_Process_DemoMode(bool demoModeRunning)
{
    if (demoModeRunning == false)
        return;
   
    switch (appData.scene_state) 
    {
       case APP_SCENE_STATE_PROCESS_TASKS:
       {
            if (demoModeCounter < ANIM_DEMO_MODE_RUN_PERIOD_MS/ANIM_DEMO_MODE_TIMER_PERIOD_MS)
            {
                switch (appData.state)
                {
                    case APP_STATE_PROCESS_SCENE1:
                    {
                        targetLeftNeedleAngle = demoModeGaugeValues[demoModeValuesIndex].left;
                        targetRightNeedleAngle = demoModeGaugeValues2[demoModeValuesIndex].right;
                        break;
                    }
                    case APP_STATE_PROCESS_SCENE2:
                    {
                        targetLeftNeedleAngle = demoModeGaugeValues[demoModeValuesIndex].left;
                        targetRightNeedleAngle = demoModeGaugeValues2[demoModeValuesIndex].right;
                        break;
                    }
                    default:
                        break;
                }

                demoModeValuesIndex = (demoModeValuesIndex < 
                            sizeof(demoModeGaugeValues)/sizeof(DEMO_MODE_GAUGE_VALUES) - 1) ?
                            demoModeValuesIndex + 1 : 0;


                demoModeCounter++;
            }
            else
            {
                appData.scene_state = APP_SCENE_STATE_SHOW_HELP;
            }           
           break;
       }
       case APP_SCENE_STATE_IDLE_HELP:
       {
           demoModeCounter++;
           
            if (demoModeCounter > ANIM_DEMO_MODE_HELP_PERIOD_MS/ANIM_DEMO_MODE_TIMER_PERIOD_MS)
            {
                appData.scene_state = APP_SCENE_STATE_SWITCH_SCENE_1_2_0;
                demoModeCounter = 0;
            }
           break;
       }
       default:
           break;
    }
}

static void animTimer_DemoMode ( uintptr_t context )
{
    static bool demoModeRunning = false;
    
    if (demoModeCounter > ANIM_DEMO_MODE_IDLE_PERIOD_MS/ANIM_DEMO_MODE_TIMER_PERIOD_MS)
    {
        if (demoModeRunning == false)
        {
            demoModeRunning = true;
        }
    }
    else
    {
        if (demoModeRunning == true)
        {
            demoModeRunning = false;
        }
        
        demoModeCounter++;
    }
    
    APP_Process_DemoMode(demoModeRunning);
}



void APP_Process_Scene1(void)
{
   switch (appData.scene_state) 
   {
       case APP_SCENE_STATE_INIT:
       {
            targetLeftNeedleAngle = 0;
            targetRightNeedleAngle = 0;
            nextLeftNeedleAngle = 0;
            nextRightNeedleAngle = 0;
            currentLeftNeedleAngle = 0;
            currentRightNeedleAngle = 0;
            demoModeCounter = 0;;
            demoModeValuesIndex = 0;    
            
            backgroundAnimDone = false;
            leftGaugeAnimDone = false;
            rightGaugeAnimDone = false;
            
            leftEdgeDownFlag = false;
            rightEdgeDownFlag = false;
            topEdgeDownFlag = false;
            lastTouchDownCount = 0;
            
            maxNeedleValue = (appData.state == APP_STATE_PROCESS_SCENE1) ?
                SCENE1_MAX_NEEDLE_VALUE : SCENE2_MAX_NEEDLE_VALUE;
            
            gfxcHideCanvas(INFOPAGE_CANVAS_ID);
            gfxcSetWindowPosition(INFOPAGE_CANVAS_ID, 0, 480);
            gfxcCanvasUpdate(INFOPAGE_CANVAS_ID);
            
            gfxcShowCanvas(LEFT_NEEDLE_CANVAS_ID);
            gfxcShowCanvas(RIGHT_NEEDLE_CANVAS_ID);
            gfxcSetWindowAlpha(LEFT_NEEDLE_CANVAS_ID, 0);
            gfxcSetWindowAlpha(RIGHT_NEEDLE_CANVAS_ID, 0);
            gfxcCanvasUpdate(LEFT_NEEDLE_CANVAS_ID);            
            gfxcCanvasUpdate(RIGHT_NEEDLE_CANVAS_ID);   
            
            if (appData.state == APP_STATE_PROCESS_SCENE1)
            {
                APP_SCENE1_initialize_needle_lookup_table();
            }
            else
            {
                APP_SCENE2_initialize_needle_lookup_table();
            }
            
            gfxcSetEffectsCallback(LEFT_NEEDLE_CANVAS_ID, APP_Scene_EffectsCallback, NULL);
            gfxcSetEffectsCallback(RIGHT_NEEDLE_CANVAS_ID, APP_Scene_EffectsCallback, NULL);
            gfxcSetEffectsCallback(BACKGROUND_CANVAS_ID, APP_Scene_EffectsCallback, NULL);
            
            appData.scene_state = APP_SCENE_STATE_READY_EVENT_HANDLERS;
            
            break;
       }
       case APP_SCENE_STATE_READY_EVENT_HANDLERS:
       {
            UpdateGauges(0, 0);
                        
            appData.scene_state = APP_SCENE_STATE_INTRO_NEEDLES_UP;
            
            gfxcStartEffectFade(LEFT_NEEDLE_CANVAS_ID,
                                NEEDLE_FADE_IN_START_ALPHA,
                                NEEDLE_FADE_IN_END_ALPHA,
                                10);
            gfxcStartEffectFade(RIGHT_NEEDLE_CANVAS_ID,
                                NEEDLE_FADE_IN_START_ALPHA,
                                NEEDLE_FADE_IN_END_ALPHA,
                                10);
            
            break;
       }
       case APP_SCENE_STATE_INTRO_NEEDLES_UP:
       {
            if (animCounterOld != animCounter)
            {
                uint32_t updateNeeded = 0;
                
                if (nextLeftNeedleAngle < maxNeedleValue)
                {
                    nextLeftNeedleAngle++;
                    updateNeeded = 1;
                }
                
                if (nextRightNeedleAngle < maxNeedleValue)
                {
                    nextRightNeedleAngle++;
                    updateNeeded = 1;
                }
                
                if (updateNeeded == 1)
                {
                    UpdateGauges(nextLeftNeedleAngle, nextRightNeedleAngle);
                }
                
                if (nextLeftNeedleAngle == maxNeedleValue 
                    && nextRightNeedleAngle == maxNeedleValue)
                {
                    appData.scene_state = APP_SCENE_STATE_INTRO_NEEDLES_DOWN;
                }
                
                animCounterOld = animCounter;
            }
            
           break;
       }
       case APP_SCENE_STATE_INTRO_NEEDLES_DOWN:
       {
            if (animCounterOld != animCounter)
            {
                uint32_t updateNeeded = 0;
                
                if (nextLeftNeedleAngle > 0)
                {
                    nextLeftNeedleAngle--;
                    updateNeeded = 1;
                }
                
                if (nextRightNeedleAngle > 0)
                {
                    nextRightNeedleAngle--;
                    updateNeeded = 1;
                }
                
                if (updateNeeded == 1)
                {
                    UpdateGauges(nextLeftNeedleAngle, nextRightNeedleAngle);
                }
                
                if (nextLeftNeedleAngle == 0 && nextRightNeedleAngle == 0)
                {
                    app_inputListener.handleTouchDown = &app_touchDownHandler;
                    app_inputListener.handleTouchUp = &app_touchUpHandler;
                    app_inputListener.handleTouchMove = &app_touchMoveHandler;

                    inputListenerID = SYS_INP_AddListener(&app_inputListener);                    
                    
                    appData.scene_state = APP_SCENE_STATE_PROCESS_TASKS;
                    
                    //start self demo timer, triggers every second
                    selfDemoTimer = SYS_TIME_CallbackRegisterMS(animTimer_DemoMode, 
                                    NULL,
                                    ANIM_DEMO_MODE_TIMER_PERIOD_MS,
                                    SYS_TIME_PERIODIC);                    
                }
                
                animCounterOld = animCounter;
            }           

           break;
       }       
       case APP_SCENE_STATE_PROCESS_TASKS:
       {
            static unsigned int idleCount = 0;
            
            if (animCounterOld != animCounter)
            {
                uint32_t updateNeeded = 0;
                
                if (nextLeftNeedleAngle < targetLeftNeedleAngle)
                {
                    nextLeftNeedleAngle++;
                    updateNeeded = 1;
                }
                else if (nextLeftNeedleAngle > targetLeftNeedleAngle)
                {
                    nextLeftNeedleAngle--;
                    updateNeeded = 1;
                }
                
                if (nextRightNeedleAngle < targetRightNeedleAngle)
                {
                    nextRightNeedleAngle++;
                    updateNeeded = 1;
                }
                else if (nextRightNeedleAngle > targetRightNeedleAngle)
                {
                    nextRightNeedleAngle--;
                    updateNeeded = 1;
                }                
                
                if (updateNeeded == 1)
                {
                    UpdateGauges(nextLeftNeedleAngle, nextRightNeedleAngle);
                    
                    idleCount = 0;
                    
                    if (APP_GetBacklightBrightness() != ON_BRIGHTNESS)
                        APP_SetBacklightBrightness(ON_BRIGHTNESS);
                }
                else
                {
                    if (idleCount > BACKLIGHT_IDLE_TIMEOUT_COUNT)
                        APP_SetBacklightBrightness(DIM_BRIGHTNESS);
                    else
                        idleCount++;
                    
                }
                
                animCounterOld = animCounter;
            }           
            break;
       }
       case APP_SCENE_STATE_SHOW_HELP:
       {
            gfxcHideCanvas(LEFT_NEEDLE_CANVAS_ID);
            gfxcHideCanvas(RIGHT_NEEDLE_CANVAS_ID);
            
            gfxcCanvasUpdate(LEFT_NEEDLE_CANVAS_ID);            
            gfxcCanvasUpdate(RIGHT_NEEDLE_CANVAS_ID);
            
            gfxcShowCanvas(INFOPAGE_CANVAS_ID);            
            gfxcCanvasUpdate(INFOPAGE_CANVAS_ID);
            gfxcStartEffectMove(INFOPAGE_CANVAS_ID,
                            GFXC_FX_MOVE_DEC,
                            250,
                            -350,
                            250,
                            65,
                            10);      
            
           appData.scene_state = APP_SCENE_STATE_IDLE_HELP;
           break;
       }
       case APP_SCENE_STATE_IDLE_HELP:
       {
           //Do nothing here, waiting for help screen to be closed
           break;
       }
       case APP_SCENE_STATE_HIDE_HELP:
       {
            appData.scene_state = APP_SCENE_STATE_INIT;
            
            break;
       }
       case APP_SCENE_STATE_SWITCH_SCENE_1_2_0:
       {
            SYS_INP_RemoveListener(inputListenerID);
            SYS_TIME_TimerStop(selfDemoTimer);
            SYS_TIME_TimerDestroy(selfDemoTimer);            
                   
            leftGaugeAnimDone = false;
            rightGaugeAnimDone = false;                
            gfxcStartEffectFade(LEFT_NEEDLE_CANVAS_ID,
                                NEEDLE_FADE_OUT_START_ALPHA,
                                NEEDLE_FADE_OUT_END_ALPHA,
                                10);
            gfxcStartEffectFade(RIGHT_NEEDLE_CANVAS_ID,
                                NEEDLE_FADE_OUT_START_ALPHA,
                                NEEDLE_FADE_OUT_END_ALPHA,
                                10);
           
            backgroundAnimDone = false;
            
            if (appData.state == APP_STATE_PROCESS_SCENE1)
            {
                gfxcStartEffectMove(BACKGROUND_CANVAS_ID,
                                    GFXC_FX_MOVE_DEC,
                                    0,
                                    0,
                                    -800,
                                    0,
                                    10);
            }
            else if (appData.state == APP_STATE_PROCESS_SCENE2)
            {
                gfxcStartEffectMove(BACKGROUND_CANVAS_ID,
                                GFXC_FX_MOVE_DEC,
                                -800,
                                0,
                                0,
                                0,
                                10);
            }
           
            appData.scene_state = APP_SCENE_STATE_SWITCH_SCENE_WAIT;
            
            break;
       }
       case APP_SCENE_STATE_SWITCH_SCENE_WAIT:
       {
            if (backgroundAnimDone == true)
            {
                appData.scene_state = APP_SCENE_STATE_INIT;
                appData.state = (appData.state == APP_STATE_PROCESS_SCENE1) ?
                    APP_STATE_PROCESS_SCENE2 : APP_STATE_PROCESS_SCENE1;
            }
                
           break;
       }
       default:
           break;
   }
}
/* *****************************************************************************
 End of File
 */
