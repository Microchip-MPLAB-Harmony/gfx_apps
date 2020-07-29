/*******************************************************************************
  MPLAB Harmony Application Touch Test Screen Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    screen_TouchTest.c

  Summary:
    This file contains the source code for the demo splash screen.

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

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2019 - 2020 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
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


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "gfx/legato/generated/le_gen_init.h"

static enum
{
    EVENT_TOUCHTEST_SHOW_NEXT,
    EVENT_TOUCHTEST_SHOW_HELP,
    EVENT_TOUCHTEST_SHOW_MAIN,
    EVENT_TOUCHTEST_SHOW_DEMO,
    EVENT_TOUCHTEST_NONE,
} touchTestScreenEvent;

static uint32_t eventScreenTable[] = 
{
    [EVENT_TOUCHTEST_SHOW_NEXT] = screenID_KeypadDemoScreen,
    [EVENT_TOUCHTEST_SHOW_HELP] = screenID_TouchTestHelpScreen,
    [EVENT_TOUCHTEST_SHOW_MAIN] = screenID_MainMenu,
    [EVENT_TOUCHTEST_SHOW_DEMO] = screenID_TouchTestDemoScreen,
};

//Touch test help screen events
void TouchTestHelpScreen_OnShow(void)
{
    touchTestScreenEvent = EVENT_TOUCHTEST_NONE;
}

void TouchTestHelpScreen_OnUpdate(void)
{
    if (touchTestScreenEvent < EVENT_TOUCHTEST_NONE)
    {
        legato_showScreen(eventScreenTable[touchTestScreenEvent]);
        touchTestScreenEvent = EVENT_TOUCHTEST_NONE;
    }    
}

void event_TouchTestHelpScreen_TouchTestHelpCloseButton_OnReleased(leButtonWidget* btn)
{
    touchTestScreenEvent = EVENT_TOUCHTEST_SHOW_DEMO;
}

void event_TouchTestDemoScreen_TouchTestHomeButton_OnReleased(leButtonWidget* btn)
{
    touchTestScreenEvent = EVENT_TOUCHTEST_SHOW_MAIN;
}

//Touch test demo screen events
void TouchTestDemoScreen_OnShow(void)
{
    touchTestScreenEvent = EVENT_TOUCHTEST_NONE;
}

void TouchTestDemoScreen_OnUpdate(void)
{
    if (touchTestScreenEvent < EVENT_TOUCHTEST_NONE)
    {
        legato_showScreen(eventScreenTable[touchTestScreenEvent]);
        touchTestScreenEvent = EVENT_TOUCHTEST_NONE;
    }
}

void event_TouchTestDemoScreen_TouchTestHelpButton_OnReleased(leButtonWidget* btn)
{
    touchTestScreenEvent = EVENT_TOUCHTEST_SHOW_HELP;
}

void event_TouchTestDemoScreen_TouchTestNextButton_OnReleased(leButtonWidget* btn)
{
    touchTestScreenEvent = EVENT_TOUCHTEST_SHOW_NEXT;
}


