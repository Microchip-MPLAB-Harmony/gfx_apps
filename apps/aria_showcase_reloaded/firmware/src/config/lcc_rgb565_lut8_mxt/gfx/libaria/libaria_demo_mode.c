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
    // ex. LibAria_DemoModeAddInputEvent(delay, index, event, x, y);
// CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!    
    LibAria_DemoModeAddInputEvent(5050, 2, 0, 62, 89);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 62, 89);
    LibAria_DemoModeAddInputEvent(3640, 2, 0, 237, 168);
    LibAria_DemoModeAddInputEvent(1250, 4, 0, 237, 168);
    LibAria_DemoModeAddInputEvent(2960, 2, 0, 462, 24);
    LibAria_DemoModeAddInputEvent(110, 4, 0, 462, 24);
    LibAria_DemoModeAddInputEvent(1310, 2, 0, 314, 92);
    LibAria_DemoModeAddInputEvent(160, 1, 0, 320, 92);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 322, 92);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 323, 92);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 326, 94);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 331, 97);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 340, 102);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 349, 110);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 356, 115);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 361, 121);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 368, 131);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 372, 136);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 375, 145);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 377, 150);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 377, 155);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 377, 162);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 375, 167);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 372, 174);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 369, 179);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 365, 184);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 360, 191);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 357, 195);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 352, 200);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 348, 202);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 346, 204);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 344, 205);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 343, 206);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 346, 206);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 351, 203);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 357, 198);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 367, 188);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 372, 181);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 376, 174);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 377, 162);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 375, 154);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 368, 142);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 362, 135);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 354, 128);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 341, 121);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 333, 118);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 320, 117);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 312, 120);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 304, 124);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 293, 132);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 287, 137);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 280, 146);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 276, 151);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 274, 156);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 273, 162);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 273, 167);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 276, 175);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 279, 180);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 282, 184);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 289, 191);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 294, 195);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 301, 200);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 306, 202);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 311, 204);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 315, 206);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 317, 206);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 319, 207);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 320, 208);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 321, 208);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 322, 208);
    LibAria_DemoModeAddInputEvent(420, 1, 0, 322, 209);
    LibAria_DemoModeAddInputEvent(250, 4, 0, 322, 209);
    LibAria_DemoModeAddInputEvent(1020, 2, 0, 459, 31);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 459, 31);
    LibAria_DemoModeAddInputEvent(980, 2, 0, 381, 185);
    LibAria_DemoModeAddInputEvent(2910, 4, 0, 381, 185);
    LibAria_DemoModeAddInputEvent(8390, 2, 0, 456, 37);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 456, 37);
    LibAria_DemoModeAddInputEvent(1170, 2, 0, 276, 205);
    LibAria_DemoModeAddInputEvent(110, 4, 0, 276, 205);
    LibAria_DemoModeAddInputEvent(340, 2, 0, 290, 138);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 290, 138);
    LibAria_DemoModeAddInputEvent(460, 2, 0, 225, 114);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 225, 114);
    LibAria_DemoModeAddInputEvent(250, 2, 0, 158, 150);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 158, 150);
    LibAria_DemoModeAddInputEvent(220, 2, 0, 190, 220);
    LibAria_DemoModeAddInputEvent(110, 4, 0, 190, 220);
    LibAria_DemoModeAddInputEvent(530, 2, 0, 282, 203);
    LibAria_DemoModeAddInputEvent(110, 4, 0, 282, 203);
    LibAria_DemoModeAddInputEvent(210, 2, 0, 288, 138);
    LibAria_DemoModeAddInputEvent(110, 4, 0, 288, 138);
    LibAria_DemoModeAddInputEvent(230, 2, 0, 214, 102);
    LibAria_DemoModeAddInputEvent(110, 4, 0, 214, 102);
    LibAria_DemoModeAddInputEvent(230, 2, 0, 147, 159);
    LibAria_DemoModeAddInputEvent(120, 4, 0, 147, 159);
    LibAria_DemoModeAddInputEvent(230, 2, 0, 179, 230);
    LibAria_DemoModeAddInputEvent(110, 4, 0, 179, 230);
    LibAria_DemoModeAddInputEvent(1140, 2, 0, 283, 210);
    LibAria_DemoModeAddInputEvent(130, 4, 0, 283, 210);
    LibAria_DemoModeAddInputEvent(210, 2, 0, 292, 128);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 292, 128);
    LibAria_DemoModeAddInputEvent(210, 2, 0, 222, 107);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 222, 107);
    LibAria_DemoModeAddInputEvent(1270, 2, 0, 234, 112);
    LibAria_DemoModeAddInputEvent(110, 4, 0, 234, 112);
    LibAria_DemoModeAddInputEvent(380, 2, 0, 293, 137);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 293, 137);
    LibAria_DemoModeAddInputEvent(380, 2, 0, 170, 165);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 170, 165);
    LibAria_DemoModeAddInputEvent(290, 2, 0, 208, 236);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 208, 236);
    LibAria_DemoModeAddInputEvent(440, 2, 0, 217, 215);
    LibAria_DemoModeAddInputEvent(90, 4, 0, 217, 215);
    LibAria_DemoModeAddInputEvent(750, 2, 0, 166, 168);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 166, 168);
    LibAria_DemoModeAddInputEvent(310, 2, 0, 283, 210);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 283, 210);
    LibAria_DemoModeAddInputEvent(680, 2, 0, 461, 32);
    LibAria_DemoModeAddInputEvent(110, 4, 0, 461, 32);
    LibAria_DemoModeAddInputEvent(2600, 2, 0, 49, 249);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 55, 246);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 59, 244);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 63, 242);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 68, 240);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 73, 238);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 88, 232);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 99, 228);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 127, 219);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 154, 210);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 167, 206);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 191, 198);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 202, 194);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 221, 186);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 239, 179);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 247, 176);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 264, 169);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 272, 165);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 288, 158);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 304, 152);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 311, 149);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 327, 143);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 334, 140);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 347, 135);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 358, 130);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 364, 128);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 374, 124);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 379, 122);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 389, 119);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 396, 116);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 400, 115);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 404, 114);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 406, 114);
    LibAria_DemoModeAddInputEvent(130, 1, 0, 399, 118);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 394, 120);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 388, 123);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 369, 131);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 354, 136);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 320, 146);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 304, 150);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 274, 159);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 261, 163);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 235, 171);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 211, 180);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 201, 183);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 182, 191);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 173, 195);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 157, 202);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 142, 209);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 135, 213);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 121, 220);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 114, 223);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 101, 229);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 90, 235);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 85, 238);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 76, 243);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 71, 245);
    LibAria_DemoModeAddInputEvent(10, 4, 0, 66, 247);
    LibAria_DemoModeAddInputEvent(2020, 2, 0, 453, 32);
    LibAria_DemoModeAddInputEvent(110, 4, 0, 453, 32);
    LibAria_DemoModeAddInputEvent(920, 2, 0, 61, 236);
    LibAria_DemoModeAddInputEvent(130, 1, 0, 65, 231);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 68, 229);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 73, 227);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 78, 225);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 103, 215);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 131, 207);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 172, 195);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 217, 181);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 262, 167);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 318, 148);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 360, 132);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 393, 117);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 409, 112);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 406, 116);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 381, 129);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 312, 157);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 241, 182);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 179, 204);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 126, 225);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 84, 242);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 50, 252);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 37, 254);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 48, 248);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 90, 229);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 158, 201);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 226, 175);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 302, 147);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 352, 128);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 390, 115);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 416, 108);
    LibAria_DemoModeAddInputEvent(10, 4, 0, 422, 108);
    LibAria_DemoModeAddInputEvent(4740, 2, 0, 446, 42);
    LibAria_DemoModeAddInputEvent(120, 4, 0, 446, 42);
    LibAria_DemoModeAddInputEvent(2740, 2, 0, 19, 39);
    LibAria_DemoModeAddInputEvent(150, 4, 0, 19, 39);
//END OF CUSTOM CODE       
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
                APP_Initialize();
                laContext_SetActiveScreen(0);

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
