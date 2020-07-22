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

// CUSTOM CODE - DO NOT REMOVE 
#include "app.h"
#include "system/debug/sys_debug.h"
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
    // ex. LibAria_DemoModeAddInputEvent(delay, index, event, x, y);

    // CUSTOM CODE - DO NOT REMOVE
    LibAria_DemoModeAddInputEvent(8930, 2, 0, 100, 198);
    LibAria_DemoModeAddInputEvent(110, 1, 0, 107, 198);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 109, 201);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 112, 201);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 115, 202);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 118, 203);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 122, 204);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 126, 206);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 130, 207);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 139, 210);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 149, 213);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 158, 216);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 184, 222);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 205, 225);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 235, 228);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 259, 228);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 287, 225);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 307, 223);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 328, 219);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 350, 213);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 350, 213);
    LibAria_DemoModeAddInputEvent(660, 2, 0, 240, 211);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 240, 211);
    LibAria_DemoModeAddInputEvent(120, 2, 0, 242, 209);
    LibAria_DemoModeAddInputEvent(220, 4, 0, 242, 209);
    LibAria_DemoModeAddInputEvent(510, 2, 0, 261, 236);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 259, 228);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 259, 224);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 259, 219);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 263, 195);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 268, 158);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 270, 131);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 271, 93);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 274, 67);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 275, 48);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 275, 39);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 275, 34);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 275, 30);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 275, 28);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 275, 26);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 275, 24);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 275, 23);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 275, 22);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 275, 21);
    LibAria_DemoModeAddInputEvent(90, 1, 0, 275, 20);
    LibAria_DemoModeAddInputEvent(210, 1, 0, 275, 22);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 275, 23);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 275, 25);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 275, 26);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 275, 29);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 275, 31);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 275, 34);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 272, 41);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 271, 49);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 271, 57);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 270, 79);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 268, 97);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 267, 119);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 266, 136);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 265, 157);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 265, 178);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 265, 207);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 268, 226);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 268, 226);
    LibAria_DemoModeAddInputEvent(260, 2, 0, 287, 68);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 283, 76);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 281, 80);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 275, 98);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 274, 107);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 274, 112);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 274, 117);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 273, 122);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 273, 127);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 273, 132);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 273, 138);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 273, 144);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 272, 150);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 272, 157);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 272, 163);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 272, 170);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 272, 176);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 272, 182);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 272, 189);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 272, 195);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 272, 201);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 272, 207);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 272, 213);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 272, 218);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 272, 223);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 272, 228);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 274, 233);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 274, 238);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 275, 243);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 275, 247);
    LibAria_DemoModeAddInputEvent(20, 4, 0, 275, 247);
    LibAria_DemoModeAddInputEvent(330, 2, 0, 246, 62);
    LibAria_DemoModeAddInputEvent(230, 1, 0, 251, 62);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 252, 64);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 252, 66);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 252, 69);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 252, 74);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 252, 80);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 252, 91);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 249, 106);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 249, 123);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 249, 137);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 247, 154);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 245, 177);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 243, 213);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 242, 233);
    LibAria_DemoModeAddInputEvent(540, 2, 0, 247, 89);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 247, 97);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 244, 101);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 241, 114);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 239, 133);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 239, 158);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 242, 176);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 242, 199);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 242, 215);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 243, 232);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 244, 238);
    LibAria_DemoModeAddInputEvent(950, 2, 0, 461, 246);
    LibAria_DemoModeAddInputEvent(40, 4, 0, 461, 246);
    LibAria_DemoModeAddInputEvent(1170, 2, 0, 368, 206);
    LibAria_DemoModeAddInputEvent(90, 1, 0, 362, 206);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 358, 206);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 354, 208);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 344, 210);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 324, 214);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 305, 216);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 269, 221);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 234, 221);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 211, 219);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 184, 216);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 166, 215);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 145, 210);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 130, 206);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 123, 203);
    LibAria_DemoModeAddInputEvent(530, 2, 0, 225, 233);
    LibAria_DemoModeAddInputEvent(100, 4, 0, 225, 233);
    LibAria_DemoModeAddInputEvent(1050, 2, 0, 98, 133);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 104, 133);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 107, 133);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 112, 135);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 118, 135);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 124, 136);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 140, 138);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 164, 142);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 191, 146);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 272, 158);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 337, 167);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 400, 173);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 430, 175);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 452, 175);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 463, 176);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 471, 176);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 472, 176);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 475, 176);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 476, 176);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 473, 176);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 472, 176);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 470, 176);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 467, 176);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 464, 176);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 461, 176);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 457, 176);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 452, 176);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 447, 176);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 441, 176);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 435, 174);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 410, 172);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 386, 171);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 359, 170);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 290, 168);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 235, 166);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 208, 165);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 171, 161);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 122, 150);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 101, 146);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 57, 136);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 37, 133);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 30, 133);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 23, 133);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 18, 135);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 16, 137);
    LibAria_DemoModeAddInputEvent(40, 4, 0, 16, 137);
    LibAria_DemoModeAddInputEvent(450, 2, 0, 433, 186);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 428, 184);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 424, 184);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 421, 184);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 416, 184);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 411, 186);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 405, 188);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 393, 190);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 376, 191);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 349, 192);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 311, 192);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 266, 188);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 232, 186);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 202, 184);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 183, 183);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 171, 181);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 148, 178);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 122, 174);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 111, 172);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 101, 172);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 97, 172);
    LibAria_DemoModeAddInputEvent(1130, 2, 0, 466, 246);
    LibAria_DemoModeAddInputEvent(90, 4, 0, 466, 246);
    LibAria_DemoModeAddInputEvent(1270, 2, 0, 384, 201);
    LibAria_DemoModeAddInputEvent(110, 1, 0, 377, 201);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 374, 201);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 370, 204);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 366, 205);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 361, 206);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 350, 209);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 330, 213);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 315, 216);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 285, 220);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 252, 222);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 227, 223);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 198, 223);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 177, 220);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 154, 218);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 150, 218);
    LibAria_DemoModeAddInputEvent(1360, 2, 0, 375, 218);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 369, 218);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 366, 218);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 362, 218);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 358, 218);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 352, 218);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 333, 222);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 314, 225);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 296, 228);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 257, 230);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 230, 230);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 206, 227);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 180, 222);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 160, 218);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 140, 213);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 140, 213);
    LibAria_DemoModeAddInputEvent(680, 2, 0, 231, 217);
    LibAria_DemoModeAddInputEvent(120, 4, 0, 231, 217);
    LibAria_DemoModeAddInputEvent(900, 2, 0, 162, 175);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 168, 175);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 171, 173);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 174, 172);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 179, 171);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 184, 170);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 189, 170);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 201, 168);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 216, 168);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 235, 170);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 283, 172);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 325, 169);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 375, 164);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 405, 156);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 427, 146);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 433, 143);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 438, 141);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 445, 138);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 447, 137);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 449, 136);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 450, 135);
    LibAria_DemoModeAddInputEvent(160, 1, 0, 448, 138);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 446, 139);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 444, 141);
    LibAria_DemoModeAddInputEvent(10, 1, 0, 441, 142);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 438, 144);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 434, 146);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 430, 149);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 425, 151);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 414, 156);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 400, 162);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 379, 168);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 316, 176);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 263, 182);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 199, 185);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 146, 182);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 86, 174);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 64, 171);
    LibAria_DemoModeAddInputEvent(430, 2, 0, 397, 174);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 390, 174);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 387, 177);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 382, 178);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 377, 179);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 363, 183);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 344, 187);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 321, 190);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 256, 192);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 209, 190);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 154, 184);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 115, 177);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 69, 167);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 52, 161);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 24, 147);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 24, 147);
    LibAria_DemoModeAddInputEvent(450, 2, 0, 380, 171);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 373, 174);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 370, 175);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 365, 177);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 360, 179);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 355, 181);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 342, 185);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 324, 188);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 302, 190);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 250, 191);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 211, 191);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 165, 187);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 132, 183);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 93, 175);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 77, 169);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 63, 164);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 43, 158);
    LibAria_DemoModeAddInputEvent(700, 2, 0, 375, 196);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 367, 196);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 363, 196);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 358, 198);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 335, 201);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 311, 204);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 292, 205);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 250, 206);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 202, 203);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 164, 197);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 118, 192);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 83, 187);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 67, 184);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 50, 182);
    LibAria_DemoModeAddInputEvent(1870, 2, 0, 340, 185);
    LibAria_DemoModeAddInputEvent(100, 1, 0, 333, 185);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 328, 185);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 322, 185);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 307, 189);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 279, 190);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 229, 190);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 172, 184);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 116, 175);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 78, 169);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 70, 168);
    LibAria_DemoModeAddInputEvent(490, 2, 0, 363, 199);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 356, 202);
    LibAria_DemoModeAddInputEvent(20, 1, 0, 352, 202);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 348, 204);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 338, 206);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 325, 208);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 308, 210);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 269, 210);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 221, 203);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 186, 199);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 145, 193);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 113, 189);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 97, 189);
    LibAria_DemoModeAddInputEvent(400, 2, 0, 370, 188);
    LibAria_DemoModeAddInputEvent(90, 1, 0, 362, 192);
    LibAria_DemoModeAddInputEvent(60, 1, 0, 358, 193);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 354, 195);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 326, 199);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 303, 200);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 276, 200);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 215, 191);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 175, 184);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 133, 174);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 104, 168);
    LibAria_DemoModeAddInputEvent(70, 4, 0, 86, 167);
    LibAria_DemoModeAddInputEvent(370, 2, 0, 380, 190);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 374, 192);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 371, 194);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 366, 196);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 361, 197);
    LibAria_DemoModeAddInputEvent(40, 1, 0, 356, 199);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 332, 202);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 308, 203);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 281, 203);
    LibAria_DemoModeAddInputEvent(80, 1, 0, 224, 196);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 185, 191);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 147, 184);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 105, 176);
    LibAria_DemoModeAddInputEvent(80, 4, 0, 83, 174);
    LibAria_DemoModeAddInputEvent(440, 2, 0, 379, 198);
    LibAria_DemoModeAddInputEvent(70, 1, 0, 373, 200);
    LibAria_DemoModeAddInputEvent(30, 1, 0, 370, 200);
    LibAria_DemoModeAddInputEvent(1, 1, 0, 366, 201);
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
