/*******************************************************************************
  MPLAB Harmony Application List Wheel Screen Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    screen_ListWheel.c

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

#include "gfx/legato/generated/le_gen_init.h"

static enum
{
    EVENT_LISTWHEEL_SHOW_NEXT,
    EVENT_LISTWHEEL_SHOW_HELP,
    EVENT_LISTWHEEL_SHOW_MAIN,
    EVENT_LISTWHEEL_SHOW_DEMO,
    EVENT_LISTWHEEL_NONE,
} listWheelScreenEvent;

static uint32_t eventScreenTable[] = 
{
    [EVENT_LISTWHEEL_SHOW_NEXT] = screenID_TouchTestDemoScreen,
    [EVENT_LISTWHEEL_SHOW_HELP] = screenID_ListWheelHelpScreen,
    [EVENT_LISTWHEEL_SHOW_MAIN] = screenID_MainMenu,
    [EVENT_LISTWHEEL_SHOW_DEMO] = screenID_ListWheelDemoScreen,
};

//List wheel demo screen event handlers
void ListWheelDemoScreen_OnShow(void)
{
    listWheelScreenEvent = EVENT_LISTWHEEL_NONE;
}

void ListWheelDemoScreen_OnUpdate(void)
{
    if (listWheelScreenEvent < EVENT_LISTWHEEL_NONE)
    {
        legato_showScreen(eventScreenTable[listWheelScreenEvent]);
        listWheelScreenEvent = EVENT_LISTWHEEL_NONE;
    }
}

void event_ListWheelDemoScreen_ListWheelHelpButton_OnReleased(leButtonWidget* btn)
{
    listWheelScreenEvent = EVENT_LISTWHEEL_SHOW_HELP;
}

void event_ListWheelDemoScreen_ListWheelHomeButton_OnReleased(leButtonWidget* btn)
{
    listWheelScreenEvent = EVENT_LISTWHEEL_SHOW_MAIN;
}

void event_ListWheelDemoScreen_ListWheel1_OnSelectionChanged(leListWheelWidget* lst, int32_t idx)
{
    if (idx == 2 || idx == 3)
        lst->fn->setSelectedItem(lst, 1);
    else if (idx == 4 || idx == 5)
        lst->fn->setSelectedItem(lst, 0);
}

void event_ListWheelDemoScreen_ListWheelNextButton_OnReleased(leButtonWidget* btn)
{
    listWheelScreenEvent = EVENT_LISTWHEEL_SHOW_NEXT;
}


//List wheel help screen event handlers
void ListWheelHelpScreen_OnShow(void)
{
    listWheelScreenEvent = EVENT_LISTWHEEL_NONE;    
}

void ListWheelHelpScreen_OnUpdate(void)
{
    if (listWheelScreenEvent < EVENT_LISTWHEEL_NONE)
    {
        legato_showScreen(eventScreenTable[listWheelScreenEvent]);
        listWheelScreenEvent = EVENT_LISTWHEEL_NONE;
    }
}

void event_ListWheelHelpScreen_ListWheelHelpCloseButton_OnReleased(leButtonWidget* btn)
{
    listWheelScreenEvent = EVENT_LISTWHEEL_SHOW_DEMO;
}

