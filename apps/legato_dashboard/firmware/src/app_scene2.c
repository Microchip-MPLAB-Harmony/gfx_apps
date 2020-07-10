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
#include "app.h"
#include "definitions.h"

#define MAX_NEEDLE_VALUE 226

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
    if (newAngle < 360 && rightNeedles[newAngle].imgAst != NULL)
    {
        appSetLayerFrame(1, 
                         (uint32_t) rightNeedles[newAngle].imgAst->buffer.pixels, 
                         rightNeedles[newAngle].x - 513,
                         rightNeedles[newAngle].y,
                         rightNeedles[newAngle].imgAst->buffer.size.width, 
                         rightNeedles[newAngle].imgAst->buffer.size.height);     
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

static void UpdateGauges(uint32_t leftGaugeValue, uint32_t rightGaugeValue)
{
    uint32_t updateLeft = 0, updateRight = 0;
    
    if (leftGaugeValue < 360 && rightNeedles[leftGaugeValue].imgAst != NULL)
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

static void SetGaugeTarget(int x, int y)
{
    if (x < 220)
    {
        if (y < 110)
            targetLeftNeedleAngle = MAX_NEEDLE_VALUE;
        else if (y > 370)
            targetLeftNeedleAngle = 0;
        else
            targetLeftNeedleAngle = MAX_NEEDLE_VALUE - ((y - 110) * MAX_NEEDLE_VALUE) / 260;
    }
    else if (x >= 580)
    {
        if (y < 110)
            targetRightNeedleAngle = MAX_NEEDLE_VALUE;
        else if (y > 370)
            targetRightNeedleAngle = 0;
        else
            targetRightNeedleAngle = MAX_NEEDLE_VALUE - ((y - 110) * MAX_NEEDLE_VALUE) / 260;
    }
    else
    {
        if (x < 291)
            targetRightNeedleAngle = MAX_NEEDLE_VALUE;
        else if (x > 516)
            targetRightNeedleAngle = 0;
        else
            targetRightNeedleAngle = MAX_NEEDLE_VALUE - (x - 291) / 2;

        if (y < 131)
            targetLeftNeedleAngle = MAX_NEEDLE_VALUE;
        else if (y > 356)
            targetLeftNeedleAngle = 0;
        else
            targetLeftNeedleAngle = MAX_NEEDLE_VALUE - (y - 131) / 2;
    }
}

static void app_touchDownHandler(const SYS_INP_TouchStateEvent* const evt)
{
    SetGaugeTarget(evt->x, evt->y);
    
    //Detect double tap
    if (animCounter > lastTouchDownCount && (animCounter - lastTouchDownCount < DOUBLE_TAP_COUNT_LIMIT))
        appData.scene_state = APP_SCENE_STATE_SWITCH_SCENE_1_2_0;
        
    lastTouchDownCount = animCounter;
}

static void app_touchUpHandler(const SYS_INP_TouchStateEvent* const evt)
{

}

static void app_touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt)
{
    SetGaugeTarget(evt->x, evt->y);
}

static void APP_Scene2_EffectsCallback(unsigned int canvasID,
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

void APP_Process_Scene2(void)
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
            
            APP_SCENE2_initialize_needle_lookup_table();

            gfxcSetEffectsCallback(0, APP_Scene2_EffectsCallback, NULL);
            gfxcSetEffectsCallback(1, APP_Scene2_EffectsCallback, NULL);
            gfxcSetEffectsCallback(2, APP_Scene2_EffectsCallback, NULL);
            
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
                
                if (nextLeftNeedleAngle < MAX_NEEDLE_VALUE)
                {
                    nextLeftNeedleAngle++;
                    updateNeeded = 1;
                }
                
                if (nextRightNeedleAngle < MAX_NEEDLE_VALUE)
                {
                    nextRightNeedleAngle++;
                    updateNeeded = 1;
                }
                
                if (updateNeeded == 1)
                {
                    UpdateGauges(nextLeftNeedleAngle, nextRightNeedleAngle);
                }
                
                if (nextLeftNeedleAngle == MAX_NEEDLE_VALUE && nextRightNeedleAngle == MAX_NEEDLE_VALUE)
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
                }
                
                animCounterOld = animCounter;
            }           

           break;
       }       
       case APP_SCENE_STATE_PROCESS_TASKS:
       {
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
                }
                
                animCounterOld = animCounter;
            }           
            break;
        }
        case APP_SCENE_STATE_SWITCH_SCENE_1_2_0:
       {
            SYS_INP_RemoveListener(inputListenerID);
                   
            leftGaugeAnimDone = false;
            rightGaugeAnimDone = false;                
            gfxcStartEffectFade(1, 255, 0, 10);
            gfxcStartEffectFade(2, 255, 0, 10);
            
            backgroundAnimDone = false;
            gfxcStartEffectMove(0,
                            GFXC_FX_MOVE_DEC,
                            -800,
                            0,
                            0,
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
                appData.state = APP_STATE_PROCESS_SCENE1;
            }
                
           break;
       }       
       default:
           break;
   }
}