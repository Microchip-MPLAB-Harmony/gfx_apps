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
        // Add default input events here. These will be loaded if no events were
    // recorded.
    // ex. LibAria_DemoModeAddInputEvent(delay, index, event, x, y);
    //CUSTOM CODE - DO NOT MODIFY OR REMOVE
    LibAria_DemoModeAddInputEvent(7830, 2, 0, 196, 164);
    LibAria_DemoModeAddInputEvent(30, 4, 0, 196, 164);
    LibAria_DemoModeAddInputEvent(8130, 2, 0, 468, 52);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 468, 52);
    LibAria_DemoModeAddInputEvent(2290, 2, 0, 248, 174);
    LibAria_DemoModeAddInputEvent(90, 4, 0, 248, 174);
    LibAria_DemoModeAddInputEvent(2780, 2, 0, 351, 153);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 351, 153);
    LibAria_DemoModeAddInputEvent(780, 2, 0, 255, 143);
    LibAria_DemoModeAddInputEvent(90, 4, 0, 255, 143);
    LibAria_DemoModeAddInputEvent(670, 2, 0, 150, 143);
    LibAria_DemoModeAddInputEvent(90, 4, 0, 150, 143);
    LibAria_DemoModeAddInputEvent(830, 2, 0, 245, 246);
    LibAria_DemoModeAddInputEvent(50, 4, 0, 245, 246);
    LibAria_DemoModeAddInputEvent(6610, 2, 0, 245, 251);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 245, 251);
    LibAria_DemoModeAddInputEvent(1450, 2, 0, 449, 70);
    LibAria_DemoModeAddInputEvent(90, 4, 0, 449, 70);
    LibAria_DemoModeAddInputEvent(980, 2, 0, 456, 67);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 456, 67);
    LibAria_DemoModeAddInputEvent(1250, 2, 0, 462, 53);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 462, 53);
    LibAria_DemoModeAddInputEvent(2910, 2, 0, 256, 157);
    LibAria_DemoModeAddInputEvent(90, 4, 0, 256, 157);
    LibAria_DemoModeAddInputEvent(4440, 2, 0, 358, 136);
    LibAria_DemoModeAddInputEvent(110, 4, 0, 358, 136);
    LibAria_DemoModeAddInputEvent(530, 2, 0, 250, 138);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 250, 138);
    LibAria_DemoModeAddInputEvent(770, 2, 0, 154, 143);
    LibAria_DemoModeAddInputEvent(90, 4, 0, 154, 143);
    LibAria_DemoModeAddInputEvent(1420, 2, 0, 246, 247);
    LibAria_DemoModeAddInputEvent(40, 4, 0, 246, 247);
    LibAria_DemoModeAddInputEvent(6230, 2, 0, 260, 144);
    LibAria_DemoModeAddInputEvent(90, 4, 0, 260, 144);
    LibAria_DemoModeAddInputEvent(700, 2, 0, 251, 248);
    LibAria_DemoModeAddInputEvent(40, 4, 0, 251, 248);
    LibAria_DemoModeAddInputEvent(4350, 2, 0, 368, 135);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 368, 135);
    LibAria_DemoModeAddInputEvent(550, 2, 0, 261, 243);
    LibAria_DemoModeAddInputEvent(50, 4, 0, 261, 243);
    LibAria_DemoModeAddInputEvent(8150, 2, 0, 464, 55);
    LibAria_DemoModeAddInputEvent(460, 4, 0, 464, 55);
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
