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
Copyright (c) 2018 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
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
    // START OF CUSTOM CODE. DO NOT MODIFY OR REMOVE!!!
    LibAria_DemoModeAddInputEvent(0x217a, DEMO_MODE_INPUT_PRESS, 0, 0x26, 0x07F);
    LibAria_DemoModeAddInputEvent(0x82, DEMO_MODE_INPUT_RELEASE, 0, 0x26, 0x07F);

    //Turn the list wheels
    LibAria_DemoModeAddInputEvent(0x384, DEMO_MODE_INPUT_PRESS, 0, 0x87, 0x09D);
    LibAria_DemoModeAddInputEvent(0x28, DEMO_MODE_INPUT_MOVE, 0, 0x87, 0x99);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x88, 0x93);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x8A, 0x08C);
    LibAria_DemoModeAddInputEvent(0xA, DEMO_MODE_INPUT_MOVE, 0, 0x8D, 0x07D);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x91, 0x62);
    LibAria_DemoModeAddInputEvent(0xA, DEMO_MODE_INPUT_MOVE, 0, 0x96, 0x45);
    LibAria_DemoModeAddInputEvent(0x001E, DEMO_MODE_INPUT_RELEASE, 0, 0x96, 0x45);
    LibAria_DemoModeAddInputEvent(0x02C6, DEMO_MODE_INPUT_PRESS, 0, 0xCE, 0x09B);
    LibAria_DemoModeAddInputEvent(0x28, DEMO_MODE_INPUT_MOVE, 0, 0xCF, 0x98);
    LibAria_DemoModeAddInputEvent(0x001E, DEMO_MODE_INPUT_MOVE, 0, 0xD0, 0x92);
    LibAria_DemoModeAddInputEvent(0xA, DEMO_MODE_INPUT_MOVE, 0, 0xD1, 0x08D);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0xD2, 0x86);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0xD4, 0x78);
    LibAria_DemoModeAddInputEvent(0xA, DEMO_MODE_INPUT_MOVE, 0, 0xD6, 0x05E);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0xDB, 0x03F);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_RELEASE, 0, 0xDB, 0x03F);
    LibAria_DemoModeAddInputEvent(0x3E8, DEMO_MODE_INPUT_PRESS, 0, 0x10A, 0x0A1);
    LibAria_DemoModeAddInputEvent(0x003C, DEMO_MODE_INPUT_MOVE, 0, 0x10A, 0x09D);
    LibAria_DemoModeAddInputEvent(0x001E, DEMO_MODE_INPUT_MOVE, 0, 0x10A, 0x97);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x10A, 0x92);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x10A, 0x08B);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x10C, 0x74);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x10F, 0x05E);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x113, 0x43);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_RELEASE, 0, 0x113, 0x43);

    //Next screen -> Touch test
    LibAria_DemoModeAddInputEvent(0x0AA0, DEMO_MODE_INPUT_PRESS, 0, 0x19B, 0x0FA);
    LibAria_DemoModeAddInputEvent(0x64, DEMO_MODE_INPUT_RELEASE, 0, 0x19B, 0x0FA);
    LibAria_DemoModeAddInputEvent(0x500, DEMO_MODE_INPUT_PRESS, 0, 0xB8, 0x0AC);
    LibAria_DemoModeAddInputEvent(0x32, DEMO_MODE_INPUT_MOVE, 0, 0xBA, 0x0AA);
    LibAria_DemoModeAddInputEvent(0x001E, DEMO_MODE_INPUT_MOVE, 0, 0xBD, 0x0A7);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0xC1, 0x0A5);
    LibAria_DemoModeAddInputEvent(0xA, DEMO_MODE_INPUT_MOVE, 0, 0xC6, 0x0A1);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0xCD, 0x09E);
    LibAria_DemoModeAddInputEvent(0xA, DEMO_MODE_INPUT_MOVE, 0, 0xD5, 0x99);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x0, 0x93);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0xEF, 0x08C);
    LibAria_DemoModeAddInputEvent(0xA, DEMO_MODE_INPUT_MOVE, 0, 0x101, 0x83);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x113, 0x79);
    LibAria_DemoModeAddInputEvent(0xA, DEMO_MODE_INPUT_MOVE, 0, 0x125, 0x06F);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x134, 0x67);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x140, 0x60);
    LibAria_DemoModeAddInputEvent(0xA, DEMO_MODE_INPUT_MOVE, 0, 0x14B, 0x05A);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x155, 0x55);
    LibAria_DemoModeAddInputEvent(0xA, DEMO_MODE_INPUT_MOVE, 0, 0x15E, 0x50);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x166, 0x04B);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_MOVE, 0, 0x16E, 0x47);
    LibAria_DemoModeAddInputEvent(0x14, DEMO_MODE_INPUT_RELEASE, 0, 0x16E, 0x47);

    //Next Screen -> Keypad Screen
    LibAria_DemoModeAddInputEvent(0x04B0, DEMO_MODE_INPUT_PRESS, 0, 0x191, 0x0FF);
    LibAria_DemoModeAddInputEvent(0x008C, DEMO_MODE_INPUT_RELEASE, 0, 0x191, 0x0FF);
    LibAria_DemoModeAddInputEvent(0x04C4, DEMO_MODE_INPUT_PRESS, 0, 0xF0, 0x03F);
    LibAria_DemoModeAddInputEvent(0x006E, DEMO_MODE_INPUT_RELEASE, 0, 0xF0, 0x03F);
    LibAria_DemoModeAddInputEvent(0x02EE, DEMO_MODE_INPUT_PRESS, 0, 0x13F, 0x0CE);
    LibAria_DemoModeAddInputEvent(0x78, DEMO_MODE_INPUT_RELEASE, 0, 0x13F, 0x0CE);
    LibAria_DemoModeAddInputEvent(0x140, DEMO_MODE_INPUT_PRESS, 0, 0x161, 0x08B);
    LibAria_DemoModeAddInputEvent(0x005A, DEMO_MODE_INPUT_RELEASE, 0, 0x161, 0x08B);
    LibAria_DemoModeAddInputEvent(0x02D0, DEMO_MODE_INPUT_PRESS, 0, 0x87, 0x0CF);
    LibAria_DemoModeAddInputEvent(0x82, DEMO_MODE_INPUT_RELEASE, 0, 0x87, 0x0CF);
    LibAria_DemoModeAddInputEvent(0x104, DEMO_MODE_INPUT_PRESS, 0, 0xA7, 0x08E);
    LibAria_DemoModeAddInputEvent(0x005A, DEMO_MODE_INPUT_RELEASE, 0, 0xA7, 0x08E);
    LibAria_DemoModeAddInputEvent(0x02EE, DEMO_MODE_INPUT_PRESS, 0, 0x18F, 0x87);
    LibAria_DemoModeAddInputEvent(0x78, DEMO_MODE_INPUT_RELEASE, 0, 0x18F, 0x87);
    LibAria_DemoModeAddInputEvent(0x01FE, DEMO_MODE_INPUT_PRESS, 0, 0x7B, 0x0D0);
    LibAria_DemoModeAddInputEvent(0x64, DEMO_MODE_INPUT_RELEASE, 0, 0x7B, 0x0D0);
    LibAria_DemoModeAddInputEvent(0x136, DEMO_MODE_INPUT_PRESS, 0, 0x106, 0x0AC);
    LibAria_DemoModeAddInputEvent(0x64, DEMO_MODE_INPUT_RELEASE, 0, 0x106, 0x0AC);
    LibAria_DemoModeAddInputEvent(0x136, DEMO_MODE_INPUT_PRESS, 0, 0x166, 0x85);
    LibAria_DemoModeAddInputEvent(0x006E, DEMO_MODE_INPUT_RELEASE, 0, 0x166, 0x85);
    LibAria_DemoModeAddInputEvent(0x262, DEMO_MODE_INPUT_PRESS, 0, 0x1C3, 0x08A);
    LibAria_DemoModeAddInputEvent(0x82, DEMO_MODE_INPUT_RELEASE, 0, 0x1C3, 0x08A);

    //Next Screen -> Alpha Blending Demo Screen
    LibAria_DemoModeAddInputEvent(0x924, DEMO_MODE_INPUT_PRESS, 0, 0x193, 0x0FE);
    LibAria_DemoModeAddInputEvent(0x78, DEMO_MODE_INPUT_RELEASE, 0, 0x193, 0x0FE);
    LibAria_DemoModeAddInputEvent(0x085C, DEMO_MODE_INPUT_PRESS, 0, 0x196, 0x31);
    LibAria_DemoModeAddInputEvent(0x006E, DEMO_MODE_INPUT_RELEASE, 0, 0x196, 0x31);
    LibAria_DemoModeAddInputEvent(0x528, DEMO_MODE_INPUT_PRESS, 0, 0x196, 0x37);
    LibAria_DemoModeAddInputEvent(0x005A, DEMO_MODE_INPUT_RELEASE, 0, 0x196, 0x37);
    LibAria_DemoModeAddInputEvent(0x04F6, DEMO_MODE_INPUT_PRESS, 0, 0x192, 0x09D);
    LibAria_DemoModeAddInputEvent(0x030C, DEMO_MODE_INPUT_RELEASE, 0, 0x192, 0x09D);

    // Next Screen -> Slideshow screen
    LibAria_DemoModeAddInputEvent(0x076C, DEMO_MODE_INPUT_PRESS, 0, 0x189, 0x0FA);
    LibAria_DemoModeAddInputEvent(0x00AA, DEMO_MODE_INPUT_RELEASE, 0, 0x189, 0x0FA);
    LibAria_DemoModeAddInputEvent(0x060E, DEMO_MODE_INPUT_PRESS, 0, 0x132, 0x0F3);
    LibAria_DemoModeAddInputEvent(0x006E, DEMO_MODE_INPUT_RELEASE, 0, 0x132, 0x0F3);
    LibAria_DemoModeAddInputEvent(0x1C02, DEMO_MODE_INPUT_PRESS, 0, 0x12E, 0x0F2);
    LibAria_DemoModeAddInputEvent(0x003C, DEMO_MODE_INPUT_RELEASE, 0, 0x12E, 0x0F2);
    LibAria_DemoModeAddInputEvent(0x406, DEMO_MODE_INPUT_PRESS, 0, 0xB0, 0x0F4);
    LibAria_DemoModeAddInputEvent(0x78, DEMO_MODE_INPUT_RELEASE, 0, 0xB0, 0x0F4);
    LibAria_DemoModeAddInputEvent(0x1928, DEMO_MODE_INPUT_PRESS, 0, 0xB3, 0x0EC);
    LibAria_DemoModeAddInputEvent(0x64, DEMO_MODE_INPUT_RELEASE, 0, 0xB3, 0x0EC);

    // Back to Home screen
    LibAria_DemoModeAddInputEvent(0x5E6, DEMO_MODE_INPUT_PRESS, 0, 0x1C2, 0x0FC);
    LibAria_DemoModeAddInputEvent(0x00AA, DEMO_MODE_INPUT_RELEASE, 0, 0x1C2, 0x0FC);

    // Open help info screen
    LibAria_DemoModeAddInputEvent(0x055A, DEMO_MODE_INPUT_PRESS, 0, 0xF, 0x0FC);
    LibAria_DemoModeAddInputEvent(0x64, DEMO_MODE_INPUT_RELEASE, 0, 0xF, 0x0FC);

    // Close help info screen
    LibAria_DemoModeAddInputEvent(0x14c8, DEMO_MODE_INPUT_PRESS, 0, 0x1D1, 0x14);
    LibAria_DemoModeAddInputEvent(0x50, DEMO_MODE_INPUT_RELEASE, 0, 0x1D1, 0x14);

    // Open the settings screen
    LibAria_DemoModeAddInputEvent(0x938, DEMO_MODE_INPUT_PRESS, 0, 0x1CB, 0x0FA);
    LibAria_DemoModeAddInputEvent(0x96, DEMO_MODE_INPUT_RELEASE, 0, 0x1CB, 0x0FA);

    // Switch to Chinese
    LibAria_DemoModeAddInputEvent(0x049C, DEMO_MODE_INPUT_PRESS, 0, 0x138, 0x35);
    LibAria_DemoModeAddInputEvent(0x96, DEMO_MODE_INPUT_RELEASE, 0, 0x138, 0x35);

    LibAria_DemoModeAddInputEvent(0x03D4, DEMO_MODE_INPUT_PRESS, 0, 0x1D0, 0x0F3);
    LibAria_DemoModeAddInputEvent(0x00AA, DEMO_MODE_INPUT_RELEASE, 0, 0x1D0, 0x0F3);
    LibAria_DemoModeAddInputEvent(0x069A, DEMO_MODE_INPUT_PRESS, 0, 0x13, 0x0F5);
    LibAria_DemoModeAddInputEvent(0x78, DEMO_MODE_INPUT_RELEASE, 0, 0x13, 0x0F5);
    LibAria_DemoModeAddInputEvent(0x085C, DEMO_MODE_INPUT_PRESS, 0, 0x1D2, 0x16);
    LibAria_DemoModeAddInputEvent(0x008C, DEMO_MODE_INPUT_RELEASE, 0, 0x1D2, 0x16);
    LibAria_DemoModeAddInputEvent(0x474, DEMO_MODE_INPUT_PRESS, 0, 0x1cf, 0xfe);
    LibAria_DemoModeAddInputEvent(0x78, DEMO_MODE_INPUT_RELEASE, 0, 0x1CF, 0x0FE);
    LibAria_DemoModeAddInputEvent(0x528, DEMO_MODE_INPUT_PRESS, 0, 0xB3, 0x31);
    LibAria_DemoModeAddInputEvent(0x82, DEMO_MODE_INPUT_RELEASE, 0, 0xB3, 0x31);

    // Back to home screen
    LibAria_DemoModeAddInputEvent(0x03D4, DEMO_MODE_INPUT_PRESS, 0, 0x1CB, 0x0FA);
    LibAria_DemoModeAddInputEvent(0x96, DEMO_MODE_INPUT_RELEASE, 0, 0x1CB, 0x0FA);
    // END OF CUSTOM CODE
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
