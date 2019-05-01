/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Implementation File

  File Name:
    libaria_demo_mode.c

  Summary:
    Build-time generated implementation of the graphics demo mode.

  Description:
    Build-time generated implementation of the graphics demo mode.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

// CUSTOM CODE - DO NOT REMOVE 
#include "app.h"
#include "system/console/sys_debug.h"
// CUSTOM CODE END
#include "system/time/sys_time.h"
#include "gfx/libaria/libaria_harmony.h"
#include "gfx/libaria/libaria_demo_mode.h"
#include "gfx/libaria/libaria.h"

#include "system/input/sys_input.h"

#include "app.h"

typedef enum
{
    DEMO_TASK_INIT = 0,
    DEMO_INIT,
    DEMO_RECORDING,
    DEMO_IDLE,
    DEMO_STARTING,
    DEMO_RUNNING,
    DEMO_RESTARTING,
    DEMO_STOPPING,
    DEMO_STOPPED,
} LIBARIA_DEMO_MODE_STATE;

typedef struct 
{
    DEMO_MODE_INPUT_TYPE touchEvent;
    uint32_t delayMSECS;
    int32_t index;
    int32_t x;
    int32_t y;
} LIBARIA_DEMO_EVENT_t;

typedef struct
{
    LIBARIA_DEMO_MODE_STATE state;
    uint32_t prevEventTick;
    volatile uint32_t recordTicks;
    volatile uint32_t demoEventFlags;
    uint32_t idleTimeOutMSECS;
    uint32_t numEvents;
    uint32_t maxEvents;
    int32_t pendingEvent;
    SYS_TIME_HANDLE demoRunTimer;
    SYS_TIME_HANDLE demoTimeoutTimer;
    SYS_TIME_HANDLE recordTickTimer;
    LIBARIA_DEMO_EVENT_t demoEvents[MAX_DEMO_EVENTS];
} LIBARIA_DEMO_EVENTS_t;

static LIBARIA_DEMO_EVENTS_t demoModeEvents;
static SYS_INP_InputListener inputListener;

static void LibAria_RestartDemoModeTimerCallback(uintptr_t context)
{
    LibAria_DemoModeSendEvent(DEMO_EVENT_START);
}
static void LibAria_DemoModeRunTimerCallback(uintptr_t context)
{
    LibAria_DemoModeSendEvent(DEMO_EVENT_NEXT_EVENT);
}

static void LibAria_DemoModeStartTimerCallback (uintptr_t context)
{
    LibAria_DemoModeSendEvent(DEMO_EVENT_START);
}


void LibAria_DemoModeSendEvent(uint32_t event)
{
    demoModeEvents.demoEventFlags |= (event);
}

void LibAria_DemoModeAddInputEvent(uint32_t dt_ms,
                                   DEMO_MODE_INPUT_TYPE te,
                                   int32_t index,
                                   int32_t x,
                                   int32_t y)
{
    if (demoModeEvents.numEvents < demoModeEvents.maxEvents)
    {
        dt_ms = (dt_ms == 0) ? 1 : dt_ms;
        demoModeEvents.demoEvents[demoModeEvents.numEvents].delayMSECS = dt_ms;
        demoModeEvents.demoEvents[demoModeEvents.numEvents].touchEvent = te;
        demoModeEvents.demoEvents[demoModeEvents.numEvents].index = index;
        demoModeEvents.demoEvents[demoModeEvents.numEvents].x = x;
        demoModeEvents.demoEvents[demoModeEvents.numEvents].y = y;
        demoModeEvents.numEvents++;
                
		// CUSTOM CODE - DO NOT REMOVE
        //SYS_DEBUG_Print("\nLibAria_DemoModeAddInputEvent(%u, %u, %d, %d, %d);\r", dt_ms, te, index, x, y);
		// CUSTOM CODE END
    }
}

void LibAria_DemoModeRecordInputEvent(DEMO_MODE_INPUT_TYPE te,
                                      int32_t index,
                                      int32_t x,
                                      int32_t y)
{
}

static void LibAria_LoadDefaultEvents(void)
{
    // Add default input events here. These will be loaded if no events were
    // recorded.
    // CUSTOM CODE - DO NOT REMOVE 
    LibAria_DemoModeAddInputEvent(8780, 2, 0, 100, 183);
    LibAria_DemoModeAddInputEvent(220, 1, 0, 95, 183);
    LibAria_DemoModeAddInputEvent(220, 1, 0, 93, 183);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 66, 175);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 62, 172);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 56, 166);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 53, 157);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 51, 149);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 49, 146);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 49, 145);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 48, 144);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 47, 144);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 47, 147);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 47, 148);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 46, 149);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 46, 151);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 46, 153);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 46, 154);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 46, 156);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 49, 162);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 50, 163);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 54, 170);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 59, 176);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 67, 182);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 76, 187);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 80, 189);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 89, 190);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 102, 190);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 117, 190);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 130, 184);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 139, 181);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 142, 180);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 148, 175);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 151, 171);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 156, 164);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 159, 156);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 160, 150);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 160, 145);
    LibAria_DemoModeAddInputEvent(180, 1, 0, 160, 143);
    LibAria_DemoModeAddInputEvent(180, 4, 0, 160, 143);
    LibAria_DemoModeAddInputEvent(1760, 2, 0, 281, 198);
    LibAria_DemoModeAddInputEvent(380, 4, 0, 281, 198);
    LibAria_DemoModeAddInputEvent(2120, 2, 0, 285, 126);
    LibAria_DemoModeAddInputEvent(220, 1, 0, 285, 131);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 285, 132);
    LibAria_DemoModeAddInputEvent(120, 4, 0, 285, 132);
    LibAria_DemoModeAddInputEvent(1440, 2, 0, 271, 74);
    LibAria_DemoModeAddInputEvent(260, 4, 0, 271, 74);
    LibAria_DemoModeAddInputEvent(1360, 2, 0, 202, 74);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 202, 74);
    LibAria_DemoModeAddInputEvent(740, 2, 0, 205, 139);
    LibAria_DemoModeAddInputEvent(180, 4, 0, 205, 139);
    LibAria_DemoModeAddInputEvent(720, 2, 0, 273, 205);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 273, 205);
    LibAria_DemoModeAddInputEvent(600, 2, 0, 200, 209);
    LibAria_DemoModeAddInputEvent(120, 4, 0, 200, 209);
    LibAria_DemoModeAddInputEvent(1440, 2, 0, 379, 186);
    LibAria_DemoModeAddInputEvent(140, 1, 0, 385, 186);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 387, 186);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 397, 180);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 411, 176);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 418, 173);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 426, 170);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 428, 169);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 434, 166);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 440, 163);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 441, 162);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 442, 162);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 442, 161);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 443, 161);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 444, 160);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 444, 159);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 444, 158);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 445, 157);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 445, 156);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 445, 155);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 446, 154);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 447, 151);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 448, 150);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 448, 149);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 449, 145);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 449, 144);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 449, 143);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 450, 142);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 450, 141);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 447, 143);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 447, 144);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 446, 145);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 443, 147);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 442, 149);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 440, 150);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 430, 157);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 427, 158);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 422, 161);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 404, 167);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 382, 169);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 375, 169);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 360, 166);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 347, 163);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 343, 162);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 334, 159);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 332, 159);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 331, 159);
    LibAria_DemoModeAddInputEvent(340, 4, 0, 331, 159);
    LibAria_DemoModeAddInputEvent(1120, 2, 0, 243, 249);
    LibAria_DemoModeAddInputEvent(160, 4, 0, 243, 249);
    LibAria_DemoModeAddInputEvent(1880, 2, 0, 6, 206);
    LibAria_DemoModeAddInputEvent(180, 1, 0, 11, 206);
    LibAria_DemoModeAddInputEvent(140, 1, 0, 12, 206);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 19, 206);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 29, 206);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 44, 206);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 56, 206);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 71, 208);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 82, 208);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 91, 209);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 98, 209);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 104, 209);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 110, 210);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 118, 210);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 122, 210);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 125, 210);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 128, 210);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 129, 210);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 130, 210);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 131, 210);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 132, 210);
    LibAria_DemoModeAddInputEvent(40, 4, 0, 132, 210);
    LibAria_DemoModeAddInputEvent(1840, 2, 0, 98, 63);
    LibAria_DemoModeAddInputEvent(200, 1, 0, 98, 69);
    LibAria_DemoModeAddInputEvent(220, 1, 0, 98, 70);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 98, 80);
    LibAria_DemoModeAddInputEvent(140, 1, 0, 95, 88);
    LibAria_DemoModeAddInputEvent(140, 1, 0, 94, 94);
    LibAria_DemoModeAddInputEvent(160, 1, 0, 92, 107);
    LibAria_DemoModeAddInputEvent(140, 1, 0, 92, 122);
    LibAria_DemoModeAddInputEvent(140, 1, 0, 92, 141);
    LibAria_DemoModeAddInputEvent(140, 1, 0, 92, 170);
    LibAria_DemoModeAddInputEvent(140, 1, 0, 92, 195);
    LibAria_DemoModeAddInputEvent(160, 4, 0, 91, 202);
    LibAria_DemoModeAddInputEvent(2940, 2, 0, 289, 143);
    LibAria_DemoModeAddInputEvent(580, 1, 0, 283, 143);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 281, 143);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 276, 143);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 259, 140);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 247, 137);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 244, 134);
    LibAria_DemoModeAddInputEvent(120, 4, 0, 244, 133);
    LibAria_DemoModeAddInputEvent(20, 2, 0, 316, 128);
    LibAria_DemoModeAddInputEvent(40, 4, 0, 316, 128);
    LibAria_DemoModeAddInputEvent(40, 2, 0, 310, 130);
    LibAria_DemoModeAddInputEvent(220, 4, 0, 310, 130);
    LibAria_DemoModeAddInputEvent(780, 2, 0, 275, 142);
    LibAria_DemoModeAddInputEvent(140, 1, 0, 275, 148);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 275, 149);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 278, 153);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 284, 164);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 288, 175);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 289, 179);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 290, 181);
    LibAria_DemoModeAddInputEvent(1100, 4, 0, 290, 181);
    LibAria_DemoModeAddInputEvent(1120, 2, 0, 161, 117);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 168, 117);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 172, 117);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 180, 117);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 216, 130);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 255, 151);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 288, 170);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 315, 185);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 331, 195);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 338, 201);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 338, 201);
    LibAria_DemoModeAddInputEvent(60, 2, 0, 300, 137);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 295, 134);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 292, 134);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 287, 133);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 263, 129);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 246, 126);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 239, 125);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 237, 125);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 236, 125);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 236, 127);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 236, 128);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 238, 128);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 245, 128);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 249, 126);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 252, 124);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 252, 122);
    LibAria_DemoModeAddInputEvent(1, 4, 0, 252, 122);
    LibAria_DemoModeAddInputEvent(1100, 2, 0, 93, 203);
    LibAria_DemoModeAddInputEvent(320, 2, 1, 398, 90);
    LibAria_DemoModeAddInputEvent(300, 1, 1, 393, 90);
    LibAria_DemoModeAddInputEvent(120, 1, 1, 389, 92);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 100, 200);
    LibAria_DemoModeAddInputEvent(100, 1, 1, 382, 95);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 105, 196);
    LibAria_DemoModeAddInputEvent(100, 1, 1, 370, 101);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 117, 189);
    LibAria_DemoModeAddInputEvent(120, 1, 1, 348, 107);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 131, 180);
    LibAria_DemoModeAddInputEvent(120, 1, 1, 313, 111);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 150, 167);
    LibAria_DemoModeAddInputEvent(100, 1, 1, 282, 113);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 165, 158);
    LibAria_DemoModeAddInputEvent(100, 1, 1, 264, 113);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 175, 149);
    LibAria_DemoModeAddInputEvent(100, 1, 1, 255, 113);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 181, 145);
    LibAria_DemoModeAddInputEvent(120, 1, 1, 254, 113);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 178, 144);
    LibAria_DemoModeAddInputEvent(120, 4, 1, 254, 113);
    LibAria_DemoModeAddInputEvent(40, 4, 0, 178, 144);
    LibAria_DemoModeAddInputEvent(1560, 2, 0, 7, 180);
    LibAria_DemoModeAddInputEvent(180, 1, 0, 14, 180);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 16, 182);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 23, 183);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 27, 183);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 46, 184);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 68, 185);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 102, 185);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 128, 186);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 143, 186);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 152, 186);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 161, 186);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 172, 186);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 178, 186);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 183, 186);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 186, 186);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 189, 186);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 191, 186);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 192, 186);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 193, 186);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 194, 186);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 195, 186);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 193, 186);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 191, 186);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 186, 187);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 183, 187);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 171, 187);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 141, 188);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 94, 188);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 58, 188);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 29, 188);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 22, 188);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 15, 185);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 11, 185);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 5, 185);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 4, 185);
    LibAria_DemoModeAddInputEvent(40, 4, 0, 4, 185);
    LibAria_DemoModeAddInputEvent(180, 2, 0, 209, 137);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 209, 137);
    LibAria_DemoModeAddInputEvent(40, 2, 0, 197, 142);
    LibAria_DemoModeAddInputEvent(220, 4, 0, 197, 142);
    LibAria_DemoModeAddInputEvent(1260, 2, 0, 194, 138);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 194, 138);
    LibAria_DemoModeAddInputEvent(60, 2, 0, 192, 143);
    LibAria_DemoModeAddInputEvent(200, 4, 0, 192, 143);
    LibAria_DemoModeAddInputEvent(1080, 2, 0, 3, 168);
    LibAria_DemoModeAddInputEvent(160, 1, 0, 10, 168);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 12, 168);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 22, 168);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 26, 168);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 41, 172);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 78, 177);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 122, 181);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 151, 184);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 161, 185);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 175, 187);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 182, 187);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 187, 188);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 191, 188);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 195, 188);
    LibAria_DemoModeAddInputEvent(40, 4, 0, 196, 188);
    LibAria_DemoModeAddInputEvent(760, 2, 0, 86, 19);
    LibAria_DemoModeAddInputEvent(120, 4, 0, 86, 19);
    LibAria_DemoModeAddInputEvent(1900, 2, 0, 414, 191);
    LibAria_DemoModeAddInputEvent(180, 4, 0, 414, 191);
    LibAria_DemoModeAddInputEvent(2100, 2, 0, 476, 139);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 471, 139);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 468, 139);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 460, 139);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 455, 139);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 422, 139);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 371, 139);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 320, 139);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 298, 139);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 293, 139);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 289, 139);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 285, 139);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 282, 139);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 279, 139);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 277, 137);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 274, 137);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 272, 137);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 270, 137);
    LibAria_DemoModeAddInputEvent(20, 4, 0, 270, 137);
    LibAria_DemoModeAddInputEvent(480, 2, 0, 4, 152);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 9, 152);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 11, 152);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 18, 152);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 23, 152);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 52, 148);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 102, 146);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 151, 145);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 175, 145);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 187, 145);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 192, 145);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 196, 147);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 200, 147);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 202, 147);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 203, 147);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 204, 147);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 205, 147);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 206, 147);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 206, 147);
    LibAria_DemoModeAddInputEvent(780, 2, 0, 88, 15);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 88, 15);
    LibAria_DemoModeAddInputEvent(2080, 2, 0, 250, 109);
    LibAria_DemoModeAddInputEvent(160, 1, 0, 256, 109);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 259, 109);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 271, 109);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 276, 109);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 296, 109);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 301, 109);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 318, 109);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 332, 112);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 333, 112);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 337, 113);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 341, 114);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 343, 114);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 340, 114);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 334, 115);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 327, 115);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 313, 115);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 279, 116);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 244, 116);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 197, 116);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 188, 113);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 164, 113);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 128, 112);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 121, 111);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 109, 111);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 99, 111);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 80, 111);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 65, 111);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 59, 111);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 56, 111);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 56, 114);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 74, 116);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 91, 116);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 119, 116);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 171, 117);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 202, 119);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 266, 123);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 314, 127);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 343, 130);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 397, 135);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 410, 135);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 439, 137);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 446, 137);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 452, 138);
    LibAria_DemoModeAddInputEvent(40, 4, 0, 457, 139);
    LibAria_DemoModeAddInputEvent(700, 2, 0, 86, 120);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 91, 120);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 95, 120);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 99, 120);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 127, 122);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 204, 125);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 268, 126);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 392, 127);
    LibAria_DemoModeAddInputEvent(20, 4, 0, 443, 128);
    LibAria_DemoModeAddInputEvent(2000, 2, 0, 252, 258);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 252, 258);
    LibAria_DemoModeAddInputEvent(900, 2, 0, 270, 245);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 270, 245);
    LibAria_DemoModeAddInputEvent(860, 2, 0, 93, 249);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 93, 249);
    LibAria_DemoModeAddInputEvent(1100, 2, 0, 139, 244);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 139, 244);
    LibAria_DemoModeAddInputEvent(640, 2, 0, 108, 243);
    LibAria_DemoModeAddInputEvent(120, 4, 0, 108, 243);
    LibAria_DemoModeAddInputEvent(440, 2, 0, 70, 250);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 70, 250);
    LibAria_DemoModeAddInputEvent(580, 2, 0, 186, 131);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 192, 131);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 195, 131);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 198, 131);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 208, 131);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 225, 131);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 248, 131);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 290, 131);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 299, 133);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 325, 136);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 373, 142);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 403, 144);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 424, 145);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 427, 145);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 434, 145);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 436, 145);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 440, 145);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 443, 145);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 444, 145);
    LibAria_DemoModeAddInputEvent(20, 4, 0, 445, 146);
    LibAria_DemoModeAddInputEvent(1160, 2, 0, 78, 236);
    LibAria_DemoModeAddInputEvent(220, 4, 0, 78, 236);
    LibAria_DemoModeAddInputEvent(2300, 2, 0, 9, 164);
    LibAria_DemoModeAddInputEvent(120, 1, 0, 15, 162);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 18, 162);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 28, 162);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 33, 162);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 58, 162);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 89, 166);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 117, 171);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 135, 174);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 146, 176);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 152, 178);
    LibAria_DemoModeAddInputEvent(40, 4, 0, 152, 178);
    LibAria_DemoModeAddInputEvent(400, 2, 0, 100, 11);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 100, 11);
    LibAria_DemoModeAddInputEvent(2600, 2, 0, 368, 134);
    LibAria_DemoModeAddInputEvent(180, 4, 0, 368, 134);
    LibAria_DemoModeAddInputEvent(280, 2, 0, 373, 176);
    LibAria_DemoModeAddInputEvent(60, 4, 0, 373, 176);
    LibAria_DemoModeAddInputEvent(120, 2, 0, 311, 185);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 311, 185);
    LibAria_DemoModeAddInputEvent(80, 2, 0, 298, 127);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 298, 127);
    LibAria_DemoModeAddInputEvent(100, 2, 0, 344, 72);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 344, 72);
    LibAria_DemoModeAddInputEvent(140, 2, 0, 426, 79);
    LibAria_DemoModeAddInputEvent(120, 4, 0, 426, 79);
    LibAria_DemoModeAddInputEvent(120, 2, 0, 431, 141);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 431, 141);
    LibAria_DemoModeAddInputEvent(180, 2, 0, 408, 206);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 408, 206);
    LibAria_DemoModeAddInputEvent(2020, 2, 0, 237, 78);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 237, 78);
    LibAria_DemoModeAddInputEvent(1060, 2, 0, 171, 144);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 171, 144);
    LibAria_DemoModeAddInputEvent(1740, 2, 0, 186, 178);
    LibAria_DemoModeAddInputEvent(120, 4, 0, 186, 178);
    LibAria_DemoModeAddInputEvent(1280, 2, 0, 187, 213);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 187, 213);
    LibAria_DemoModeAddInputEvent(1500, 2, 0, 10, 201);
    LibAria_DemoModeAddInputEvent(140, 1, 0, 16, 201);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 18, 201);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 24, 201);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 28, 201);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 45, 201);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 101, 201);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 157, 201);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 203, 201);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 209, 201);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 224, 201);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 235, 201);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 240, 203);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 243, 203);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 247, 203);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 248, 203);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 249, 203);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 250, 203);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 251, 203);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 252, 203);
    LibAria_DemoModeAddInputEvent(120, 4, 0, 252, 203);
    LibAria_DemoModeAddInputEvent(480, 2, 0, 115, 14);
    LibAria_DemoModeAddInputEvent(160, 4, 0, 115, 14);
    LibAria_DemoModeAddInputEvent(3360, 2, 0, 469, 126);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 462, 126);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 459, 126);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 447, 126);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 442, 126);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 420, 126);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 397, 124);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 367, 122);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 361, 122);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 354, 122);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 348, 122);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 342, 122);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 336, 122);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 330, 122);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 324, 124);
    LibAria_DemoModeAddInputEvent(20, 4, 0, 324, 124);
    LibAria_DemoModeAddInputEvent(900, 2, 0, 451, 89);
    LibAria_DemoModeAddInputEvent(200, 4, 0, 451, 89);
    LibAria_DemoModeAddInputEvent(1440, 2, 0, 298, 208);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 290, 202);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 288, 199);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 278, 186);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 271, 168);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 267, 150);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 266, 139);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 266, 129);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 266, 121);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 270, 112);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 272, 105);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 273, 100);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 273, 99);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 274, 99);
    LibAria_DemoModeAddInputEvent(300, 1, 0, 274, 102);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 274, 103);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 274, 105);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 274, 116);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 272, 130);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 271, 150);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 271, 164);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 271, 180);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 273, 192);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 274, 205);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 276, 217);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 277, 224);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 278, 231);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 278, 234);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 279, 236);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 279, 237);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 279, 238);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 279, 239);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 279, 240);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 279, 241);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 279, 242);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 279, 243);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 280, 243);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 280, 244);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 280, 245);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 280, 246);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 280, 247);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 280, 247);
    LibAria_DemoModeAddInputEvent(4100, 2, 0, 451, 231);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 451, 231);
    // CUSTOM CODE END
}

void LibAria_DemoModeTouchDownHandler(const SYS_INP_TouchStateEvent* const evt)
{
    LibAria_DemoModeSendEvent(DEMO_EVENT_INPUT);
}

void LibAria_DemoModeTouchUpHandler(const SYS_INP_TouchStateEvent* const evt)
{
    LibAria_DemoModeSendEvent(DEMO_EVENT_INPUT);
}

void LibAria_DemoModeTouchMoveHandler(const SYS_INP_TouchMoveEvent* const evt)
{
    LibAria_DemoModeSendEvent(DEMO_EVENT_INPUT);
}

void LibAria_DemoModeProcessEvents(void)
{
    switch (demoModeEvents.state) 
    {
        case DEMO_INIT:
        {
            demoModeEvents.numEvents = 0; 
            demoModeEvents.idleTimeOutMSECS = DEMO_IDLE_TIMEOUT_S*1000;
            demoModeEvents.maxEvents = MAX_DEMO_EVENTS;
            demoModeEvents.pendingEvent = 0;
            demoModeEvents.demoEventFlags = 0;
            demoModeEvents.demoRunTimer = SYS_TIME_HANDLE_INVALID;
            demoModeEvents.demoTimeoutTimer = SYS_TIME_HANDLE_INVALID;
            demoModeEvents.recordTickTimer = SYS_TIME_HANDLE_INVALID;

                demoModeEvents.state = DEMO_IDLE;
            
            //Start timeout timer
            demoModeEvents.demoTimeoutTimer = SYS_TIME_CallbackRegisterMS
                                              (LibAria_DemoModeStartTimerCallback,
                                              (uintptr_t) & demoModeEvents,
                                              demoModeEvents.idleTimeOutMSECS,
                                              SYS_TIME_SINGLE);
            break;
        }
        case DEMO_IDLE:
        {
            if (demoModeEvents.demoEventFlags & DEMO_EVENT_START)
            {
                // idle timeout timer triggered, start demo
                demoModeEvents.demoEventFlags &= ~DEMO_EVENT_START;
                demoModeEvents.state = DEMO_STARTING;
            }
            
            if (demoModeEvents.demoEventFlags & DEMO_EVENT_INPUT)
            {
                demoModeEvents.demoEventFlags &= ~DEMO_EVENT_INPUT;
                
                //Restart the idle timeout timer
                if (demoModeEvents.demoTimeoutTimer != SYS_TIME_HANDLE_INVALID)
                    SYS_TIME_TimerDestroy(demoModeEvents.demoTimeoutTimer);
                
                demoModeEvents.demoTimeoutTimer = SYS_TIME_CallbackRegisterMS
                                                (LibAria_DemoModeStartTimerCallback,
                                                (uintptr_t) & demoModeEvents,
                                                demoModeEvents.idleTimeOutMSECS,
                                                SYS_TIME_SINGLE);  
                
                demoModeEvents.state = DEMO_IDLE;
            }
            
            if (demoModeEvents.demoEventFlags & DEMO_EVENT_STOP)
            {
                demoModeEvents.demoEventFlags &= ~DEMO_EVENT_STOP;
                demoModeEvents.state = DEMO_STOPPED;
            }
            break;
        }
        case DEMO_STARTING:
        {
            LIBARIA_DEMO_EVENT_t * currEvent;
            
            if (demoModeEvents.numEvents == 0) 
            {
                LibAria_LoadDefaultEvents();
            }

            // START Demo Mode
            if (demoModeEvents.numEvents > 0) 
            {
                demoModeEvents.pendingEvent = 0;
                
                // Initialize app and switch to first screen
                // CUSTOM CODE - DO NOT REMOVE
                APP_GoToSplashState(true);
                laContext_SetActiveScreen(SplashScreen_ID);
                // CUSTOM CODE END

                currEvent = &demoModeEvents.demoEvents[0];

                if (demoModeEvents.demoRunTimer != SYS_TIME_HANDLE_INVALID)
                    SYS_TIME_TimerDestroy(demoModeEvents.demoRunTimer);
                
                demoModeEvents.demoRunTimer = SYS_TIME_CallbackRegisterMS
                                                (LibAria_DemoModeRunTimerCallback,
                                                (uintptr_t) & demoModeEvents,
                                                currEvent->delayMSECS,
                                                SYS_TIME_SINGLE);
                
                demoModeEvents.state = DEMO_RUNNING;
            }
            else
            {
                demoModeEvents.state = DEMO_IDLE;
            }

            break;
        }
        case DEMO_STOPPING:
        {
            if (demoModeEvents.demoTimeoutTimer != SYS_TIME_HANDLE_INVALID)
                SYS_TIME_TimerDestroy(demoModeEvents.demoTimeoutTimer);

            if (demoModeEvents.demoRunTimer != SYS_TIME_HANDLE_INVALID)
                SYS_TIME_TimerDestroy(demoModeEvents.demoRunTimer);

            if (demoModeEvents.recordTickTimer != SYS_TIME_HANDLE_INVALID)
                SYS_TIME_TimerDestroy(demoModeEvents.recordTickTimer);

            demoModeEvents.demoTimeoutTimer = SYS_TIME_HANDLE_INVALID;
            demoModeEvents.demoRunTimer = SYS_TIME_HANDLE_INVALID;
            demoModeEvents.recordTickTimer = SYS_TIME_HANDLE_INVALID;
            
            demoModeEvents.state = DEMO_STOPPED;
        }
        case DEMO_STOPPED:
        {
            if (demoModeEvents.demoEventFlags & DEMO_EVENT_RESTART)
            {
                // received start event
                demoModeEvents.demoEventFlags &= ~DEMO_EVENT_RESTART;
                
                demoModeEvents.state = DEMO_INIT;
            }
            break;
        }
        case DEMO_RUNNING:
        {
            if (demoModeEvents.demoEventFlags & DEMO_EVENT_INPUT)
            {
                // Clear all events
                demoModeEvents.demoEventFlags = 0;
                
                //Restart the idle timeout timer
                if (demoModeEvents.demoRunTimer != SYS_TIME_HANDLE_INVALID)
                    SYS_TIME_TimerDestroy(demoModeEvents.demoRunTimer);

                demoModeEvents.demoRunTimer = SYS_TIME_HANDLE_INVALID;

                if (demoModeEvents.demoTimeoutTimer != SYS_TIME_HANDLE_INVALID)
                    SYS_TIME_TimerDestroy(demoModeEvents.demoTimeoutTimer);
                
                demoModeEvents.demoTimeoutTimer = SYS_TIME_CallbackRegisterMS
                                                (LibAria_DemoModeStartTimerCallback,
                                                (uintptr_t) & demoModeEvents,
                                                demoModeEvents.idleTimeOutMSECS,
                                                SYS_TIME_SINGLE); 
                
                demoModeEvents.state = DEMO_IDLE;
            }

            if (demoModeEvents.demoEventFlags & DEMO_EVENT_STOP)
            {
                demoModeEvents.demoEventFlags = 0;
                demoModeEvents.state = DEMO_STOPPING;
                break;
            }
            
            if (demoModeEvents.demoEventFlags & DEMO_EVENT_NEXT_EVENT)
            {
                LIBARIA_DEMO_EVENT_t * currEvent, * nextEvent;
                
                demoModeEvents.demoEventFlags &= ~DEMO_EVENT_NEXT_EVENT;

                currEvent = &demoModeEvents.demoEvents[demoModeEvents.pendingEvent];

                switch (currEvent->touchEvent) {
                    case DEMO_MODE_INPUT_PRESS:
                        laInput_InjectTouchDown(currEvent->index, currEvent->x, currEvent->y);
                        break;
                    case DEMO_MODE_INPUT_RELEASE:
                        laInput_InjectTouchUp(currEvent->index, currEvent->x, currEvent->y);
                        break;
                    case DEMO_MODE_INPUT_MOVE:
                        laInput_InjectTouchMoved(currEvent->index, currEvent->x, currEvent->y);
                        break;
                    default:
                        break;
                }

                demoModeEvents.pendingEvent++;

                // End of demo events, restart
                if (demoModeEvents.pendingEvent >= demoModeEvents.numEvents) 
                {
                    demoModeEvents.state = DEMO_RESTARTING;

                    if (demoModeEvents.demoRunTimer != SYS_TIME_HANDLE_INVALID)
                        SYS_TIME_TimerDestroy(demoModeEvents.demoRunTimer);

                    demoModeEvents.demoRunTimer = SYS_TIME_CallbackRegisterMS
                                                (LibAria_RestartDemoModeTimerCallback,
                                                (uintptr_t) & demoModeEvents,
                                                (DEMO_REPEAT_TIMEOUT_S*1000),
                                                SYS_TIME_SINGLE);   
                }
                else 
                {
                    nextEvent = &demoModeEvents.demoEvents[demoModeEvents.pendingEvent];

                    if (demoModeEvents.demoRunTimer != SYS_TIME_HANDLE_INVALID)
                         SYS_TIME_TimerDestroy(demoModeEvents.demoRunTimer);
                    
                    demoModeEvents.demoRunTimer = SYS_TIME_CallbackRegisterMS
                                                (LibAria_DemoModeRunTimerCallback,
                                                (uintptr_t) & demoModeEvents,
                                                nextEvent->delayMSECS,
                                                SYS_TIME_SINGLE); 
                    
                    demoModeEvents.state = DEMO_RUNNING;
                }
            }
            break;
        }
        case DEMO_RESTARTING:
        {
            if (demoModeEvents.demoEventFlags & DEMO_EVENT_START)
            {
                demoModeEvents.demoEventFlags &= ~DEMO_EVENT_START;

                demoModeEvents.state = DEMO_STARTING;
            }

            if (demoModeEvents.demoEventFlags & DEMO_EVENT_INPUT)
            {
                // Clear all events
                demoModeEvents.demoEventFlags = 0;

                //Restart the idle timeout timer
                if (demoModeEvents.demoRunTimer != SYS_TIME_HANDLE_INVALID)
                    SYS_TIME_TimerDestroy(demoModeEvents.demoRunTimer);

                demoModeEvents.demoRunTimer = SYS_TIME_HANDLE_INVALID;

                if (demoModeEvents.demoTimeoutTimer != SYS_TIME_HANDLE_INVALID)
                    SYS_TIME_TimerDestroy(demoModeEvents.demoTimeoutTimer);

                demoModeEvents.demoTimeoutTimer = SYS_TIME_CallbackRegisterMS
                                                (LibAria_DemoModeStartTimerCallback,
                                                (uintptr_t) & demoModeEvents,
                                                demoModeEvents.idleTimeOutMSECS,
                                                SYS_TIME_SINGLE);      

                demoModeEvents.state = DEMO_IDLE;
            }

            break;
        }
        //One time demo mode task initialization
        case DEMO_TASK_INIT:
        {
            SYS_INP_ListenerInit(&inputListener);

            inputListener.handleTouchDown = &LibAria_DemoModeTouchDownHandler;
            inputListener.handleTouchUp = &LibAria_DemoModeTouchUpHandler;
            inputListener.handleTouchMove = &LibAria_DemoModeTouchMoveHandler;

            SYS_INP_AddListener(&inputListener);

            demoModeEvents.state = DEMO_INIT;

            break;
        }
        default:
        {
            break;
        }
    }
}
