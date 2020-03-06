// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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
    uint32_t numEvents;
    uint32_t maxEvents;
    int32_t pendingEvent;
    SYS_TIME_HANDLE demoRunTimer;
    SYS_TIME_HANDLE demoTimeoutTimer;
    SYS_TIME_HANDLE recordTickTimer;
    LIBARIA_DEMO_EVENT_t demoEvents[MAX_DEMO_EVENTS];
} LIBARIA_DEMO_EVENTS_t;

static LIBARIA_DEMO_EVENTS_t demoModeEvents;
static unsigned int demoModeTimeElapsedSecs = 0;
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
    demoModeTimeElapsedSecs++;
    
    if (demoModeTimeElapsedSecs > DEMO_IDLE_TIMEOUT_S)
    {
        LibAria_DemoModeSendEvent(DEMO_EVENT_START);
        demoModeTimeElapsedSecs = 0;
    }
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

        //SYS_PRINT("\nLibAria_DemoModeAddInputEvent(%u, %u, %d, %d, %d);\r", dt_ms, te, index, x, y);
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

    //CUSTOM CODE - DO NOT REMOVE
    LibAria_DemoModeAddInputEvent(5250, 2, 0, 440, 225);
    LibAria_DemoModeAddInputEvent(560, 4, 0, 440, 225);
    LibAria_DemoModeAddInputEvent(240, 2, 0, 472, 221);
    LibAria_DemoModeAddInputEvent(920, 1, 0, 472, 216);
    LibAria_DemoModeAddInputEvent(190, 1, 0, 472, 218);
    LibAria_DemoModeAddInputEvent(320, 1, 0, 472, 219);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 472, 220);
    LibAria_DemoModeAddInputEvent(380, 1, 0, 472, 218);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 472, 217);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 472, 216);
    LibAria_DemoModeAddInputEvent(180, 1, 0, 472, 215);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 472, 215);
    LibAria_DemoModeAddInputEvent(8600, 2, 0, 91, 264);
    LibAria_DemoModeAddInputEvent(640, 1, 0, 88, 259);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 88, 258);
    LibAria_DemoModeAddInputEvent(450, 1, 0, 87, 258);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 86, 258);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 86, 260);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 85, 260);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 85, 261);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 84, 261);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 84, 262);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 84, 263);
    LibAria_DemoModeAddInputEvent(150, 1, 0, 84, 261);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 84, 260);
    LibAria_DemoModeAddInputEvent(810, 1, 0, 84, 259);
    LibAria_DemoModeAddInputEvent(820, 1, 0, 84, 258);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 84, 260);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 84, 261);
    LibAria_DemoModeAddInputEvent(6080, 2, 0, 56, 32);
    LibAria_DemoModeAddInputEvent(110, 4, 0, 56, 32);
    LibAria_DemoModeAddInputEvent(800, 2, 0, 316, 263);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 320, 271);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 325, 266);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 329, 261);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 332, 253);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 334, 244);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 339, 224);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 344, 204);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 346, 196);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 350, 182);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 353, 168);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 353, 157);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 354, 150);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 354, 147);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 354, 145);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 354, 144);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 354, 147);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 350, 156);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 349, 162);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 349, 170);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 347, 183);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 345, 201);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 343, 218);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 341, 237);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 340, 241);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 338, 257);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 337, 262);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 337, 264);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 336, 267);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 336, 271);
    LibAria_DemoModeAddInputEvent(30, 4, 0, 336, 271);
    LibAria_DemoModeAddInputEvent(1040, 2, 0, 458, 70);
    LibAria_DemoModeAddInputEvent(180, 4, 0, 458, 70);
    LibAria_DemoModeAddInputEvent(750, 2, 0, 463, 229);
    LibAria_DemoModeAddInputEvent(90, 4, 0, 463, 229);
    LibAria_DemoModeAddInputEvent(830, 2, 0, 435, 211);
    LibAria_DemoModeAddInputEvent(890, 1, 0, 435, 206);
    LibAria_DemoModeAddInputEvent(50, 1, 0, 435, 205);
    LibAria_DemoModeAddInputEvent(500, 1, 0, 433, 205);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 432, 205);
    LibAria_DemoModeAddInputEvent(970, 1, 0, 432, 207);
    LibAria_DemoModeAddInputEvent(710, 1, 0, 432, 205);
    LibAria_DemoModeAddInputEvent(1950, 1, 0, 431, 205);
    LibAria_DemoModeAddInputEvent(1860, 1, 0, 431, 204);
    LibAria_DemoModeAddInputEvent(3890, 1, 0, 431, 206);
    LibAria_DemoModeAddInputEvent(2410, 1, 0, 431, 207);
    LibAria_DemoModeAddInputEvent(90, 1, 0, 431, 208);
    LibAria_DemoModeAddInputEvent(1020, 1, 0, 433, 208);
    LibAria_DemoModeAddInputEvent(130, 1, 0, 433, 206);
    LibAria_DemoModeAddInputEvent(600, 1, 0, 434, 206);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 434, 205);
    LibAria_DemoModeAddInputEvent(170, 1, 0, 434, 204);
    LibAria_DemoModeAddInputEvent(320, 1, 0, 434, 203);
    LibAria_DemoModeAddInputEvent(1430, 1, 0, 435, 203);
    LibAria_DemoModeAddInputEvent(60, 4, 0, 435, 203);
    LibAria_DemoModeAddInputEvent(600, 2, 0, 73, 215);
    LibAria_DemoModeAddInputEvent(510, 1, 0, 69, 210);
    LibAria_DemoModeAddInputEvent(90, 1, 0, 69, 209);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 69, 208);
    LibAria_DemoModeAddInputEvent(140, 1, 0, 69, 207);
    LibAria_DemoModeAddInputEvent(190, 1, 0, 69, 206);
    LibAria_DemoModeAddInputEvent(1010, 1, 0, 71, 206);
    LibAria_DemoModeAddInputEvent(3370, 1, 0, 71, 205);
    LibAria_DemoModeAddInputEvent(250, 1, 0, 71, 204);
    LibAria_DemoModeAddInputEvent(270, 1, 0, 71, 203);
    LibAria_DemoModeAddInputEvent(460, 1, 0, 72, 203);
    LibAria_DemoModeAddInputEvent(1920, 1, 0, 72, 205);
    LibAria_DemoModeAddInputEvent(770, 1, 0, 72, 203);
    LibAria_DemoModeAddInputEvent(300, 1, 0, 72, 202);
    LibAria_DemoModeAddInputEvent(2820, 1, 0, 73, 204);
    LibAria_DemoModeAddInputEvent(30, 4, 0, 73, 204);
    LibAria_DemoModeAddInputEvent(2320, 2, 0, 31, 24);
    LibAria_DemoModeAddInputEvent(120, 4, 0, 31, 24);
    LibAria_DemoModeAddInputEvent(1030, 2, 0, 447, 68);
    LibAria_DemoModeAddInputEvent(140, 4, 0, 447, 68);
    LibAria_DemoModeAddInputEvent(970, 2, 0, 447, 252);
    LibAria_DemoModeAddInputEvent(110, 4, 0, 447, 252);
    LibAria_DemoModeAddInputEvent(670, 2, 0, 449, 172);
    LibAria_DemoModeAddInputEvent(370, 4, 0, 449, 172);
    LibAria_DemoModeAddInputEvent(850, 2, 0, 120, 222);
    LibAria_DemoModeAddInputEvent(750, 4, 0, 120, 222);
    //CUSTOM CODE ENDS
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
                                              1000,
                                              SYS_TIME_PERIODIC);
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
                
                //Reset the idle timeout counter
                demoModeTimeElapsedSecs = 0;
                
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
                //CUSTOM CODE - DO NOT REMOVE
                laContext_SetActiveScreen(MainScreen_ID);
                APP_GoToMainState();
                //CUSTOM CODE END

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

                //Reset the timeout counter
                demoModeTimeElapsedSecs = 0;
                
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

                //Reset the timeout counter
                demoModeTimeElapsedSecs = 0;

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
