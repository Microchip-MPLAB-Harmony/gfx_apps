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

static SYS_INP_InputListener app_inputListener;

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


static void UpdateLeftNeedle(uint32_t newAngle)
{
    if (newAngle < 360 && leftNeedles[newAngle].imgAst != NULL)
    {
        appSetLayerFrame(1, 
                         (uint32_t) leftNeedles[newAngle].imgAst->buffer.pixels, 
                         leftNeedles[newAngle].x,
                         leftNeedles[newAngle].y,
                         leftNeedles[newAngle].imgAst->buffer.size.width, 
                         leftNeedles[newAngle].imgAst->buffer.size.height);               
    }
}

static void UpdateRightNeedle(uint32_t newAngle)
{
    if (newAngle < 360 && rightNeedles[newAngle].imgAst != NULL)
    {
        appSetLayerFrame(2, 
                         (uint32_t) rightNeedles[newAngle].imgAst->buffer.pixels, 
                         rightNeedles[newAngle].x,
                         rightNeedles[newAngle].y,
                         rightNeedles[newAngle].imgAst->buffer.size.width, 
                         rightNeedles[newAngle].imgAst->buffer.size.height);             
    }
}

void SetGaugeTarget(int x, int y)
{
    if (x < 220)
    {
        if (y < 110)
            targetLeftNeedleAngle = 180;
        else if (y > 370)
            targetLeftNeedleAngle = 0;
        else
            targetLeftNeedleAngle = 180 - ((y - 110) * 180) / 260;
    }
    else if (x >= 580)
    {
        if (y < 110)
            targetRightNeedleAngle = 180;
        else if (y > 370)
            targetRightNeedleAngle = 0;
        else
            targetRightNeedleAngle = 180 - ((y - 110) * 180) / 260;
    }
    else
    {
        if (x < 220)
            targetRightNeedleAngle = 180;
        else if (x > 580)
            targetRightNeedleAngle = 0;
        else
            targetRightNeedleAngle = 180 - (x - 220) / 2;

        if (y < 60)
            targetLeftNeedleAngle = 180;
        else if (y > 420)
            targetLeftNeedleAngle = 0;
        else
            targetLeftNeedleAngle = 180 - (y - 60) / 2;
    }
}

static void UpdateGauges(uint32_t leftGaugeValue, uint32_t rightGaugeValue)
{
    uint32_t updateLeft = 0, updateRight = 0;
    
    if (leftGaugeValue < 360 && leftNeedles[leftGaugeValue].imgAst != NULL)
        updateLeft = 1;
    
    if (rightGaugeValue < 360 && rightNeedles[rightGaugeValue].imgAst != NULL)
        updateRight = 1;
    
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

void APP_Scene1_EffectsCallback(unsigned int canvasID,
                                GFXC_FX_TYPE effect,
                                GFXC_FX_STATUS status,
                                void * parm)
{
    if (status == GFXC_FX_DONE)
    {
        switch (canvasID)
        {
            case 0:
                backgroundAnimDone = true;
                break;
            case 1:
                leftGaugeAnimDone = true;
                break;
            case 2:
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
    else
        SetGaugeTarget(evt->x, evt->y);

    demoModeCounter = 0;
    lastTouchDownCount = animCounter;
}

static void app_touchUpHandler(const SYS_INP_TouchStateEvent* const evt)
{

}

static void app_touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt)
{
    SetGaugeTarget(evt->x, evt->y);
    demoModeCounter = 0;    
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
        
        if (demoModeCounter < ANIM_DEMO_MODE_RUN_PERIOD_MS/ANIM_DEMO_MODE_TIMER_PERIOD_MS)
        {
            targetLeftNeedleAngle = demoModeGaugeValues[demoModeValuesIndex].left;
            targetRightNeedleAngle = demoModeGaugeValues[demoModeValuesIndex].right;

            demoModeValuesIndex = (demoModeValuesIndex < 
                        sizeof(demoModeGaugeValues)/sizeof(DEMO_MODE_GAUGE_VALUES) - 1) ?
                        demoModeValuesIndex + 1 : 0;
            
            
            demoModeCounter++;
        }
        else
        {
            demoModeCounter = 0;
            appData.scene_state = APP_SCENE_STATE_SWITCH_SCENE_1_2_0;
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

            APP_SCENE1_initialize_needle_lookup_table();
            
            gfxcSetEffectsCallback(0, APP_Scene1_EffectsCallback, NULL);
            gfxcSetEffectsCallback(1, APP_Scene1_EffectsCallback, NULL);
            gfxcSetEffectsCallback(2, APP_Scene1_EffectsCallback, NULL);
            
            appData.scene_state = APP_SCENE_STATE_READY_EVENT_HANDLERS;
            
            break;
       }
       case APP_SCENE_STATE_READY_EVENT_HANDLERS:
       {
            UpdateGauges(0, 0);
                        
            appData.scene_state = APP_SCENE_STATE_INTRO_NEEDLES_UP;
            
            backgroundAnimDone = false;
            leftGaugeAnimDone = false;
            rightGaugeAnimDone = false;
            
            gfxcStartEffectFade(1, 0, 255, 10);
            gfxcStartEffectFade(2, 0, 255, 10);
            
            break;
       }
       case APP_SCENE_STATE_INTRO_NEEDLES_UP:
       {
            if (animCounterOld != animCounter)
            {
                uint32_t updateNeeded = 0;
                
                if (nextLeftNeedleAngle < 180)
                {
                    nextLeftNeedleAngle++;
                    updateNeeded = 1;
                }
                
                if (nextRightNeedleAngle < 180)
                {
                    nextRightNeedleAngle++;
                    updateNeeded = 1;
                }
                
                if (updateNeeded == 1)
                {
                    UpdateGauges(nextLeftNeedleAngle, nextRightNeedleAngle);
                }
                
                if (nextLeftNeedleAngle == 180 && nextRightNeedleAngle == 180)
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
       case APP_SCENE_STATE_SWITCH_SCENE_1_2_0:
       {
            SYS_INP_RemoveListener(inputListenerID);
            SYS_TIME_TimerStop(selfDemoTimer);
            SYS_TIME_TimerDestroy(selfDemoTimer);            
                   
            leftGaugeAnimDone = false;
            rightGaugeAnimDone = false;                
            gfxcStartEffectFade(1, 255, 0, 10);
            gfxcStartEffectFade(2, 255, 0, 10);
           
            backgroundAnimDone = false;
            gfxcStartEffectMove(0,
                                GFXC_FX_MOVE_DEC,
                                0,
                                0,
                                -800,
                                0,
                                10);
           
            appData.scene_state = APP_SCENE_STATE_SWITCH_SCENE_WAIT;
            
            break;
       }
       case APP_SCENE_STATE_SWITCH_SCENE_WAIT:
       {
            if (backgroundAnimDone == true &&
                backgroundAnimDone == true &&
                backgroundAnimDone == true)
            {
                appData.scene_state = APP_SCENE_STATE_INIT;
                appData.state = APP_STATE_PROCESS_SCENE2;
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
