/*******************************************************************************
  MPLAB Harmony Application Main Menu Screen Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    screen_MainMenu.c

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
    EVENT_MAIN_SHOW_LIST_WHEEL_DEMO,
    EVENT_MAIN_SHOW_TOUCH_TEST_DEMO,
    EVENT_MAIN_SHOW_KEYPAD_DEMO,
    EVENT_MAIN_SHOW_ALPHA_DEMO,
    EVENT_MAIN_SHOW_SLIDESHOW_DEMO,
    EVENT_MAIN_SHOW_MAIN_MENU_HELP,
    EVENT_MAIN_SHOW_MAIN_MENU_SETTINGS,
    EVENT_MAIN_SHOW_NEXT_DEMO,
    EVENT_MAIN_SHOW_MAIN,
    EVENT_MAIN_NONE,
} mainMenuEvent;

static uint32_t eventScreenTable[] = 
{
    [EVENT_MAIN_SHOW_LIST_WHEEL_DEMO] = screenID_ListWheelDemoScreen,
    [EVENT_MAIN_SHOW_TOUCH_TEST_DEMO] = screenID_TouchTestDemoScreen,
    [EVENT_MAIN_SHOW_KEYPAD_DEMO] = screenID_KeypadDemoScreen,
    [EVENT_MAIN_SHOW_ALPHA_DEMO] = screenID_AlphaBlendingDemoScreen,
    [EVENT_MAIN_SHOW_SLIDESHOW_DEMO] = screenID_SlideShowDemoScreen,
    [EVENT_MAIN_SHOW_MAIN_MENU_HELP] = screenID_MainMenuHelp,
    [EVENT_MAIN_SHOW_MAIN_MENU_SETTINGS] = screenID_SettingsScreen,
    [EVENT_MAIN_SHOW_NEXT_DEMO] = screenID_ListWheelDemoScreen,
    [EVENT_MAIN_SHOW_MAIN] = screenID_MainMenu,
};

void MainMenu_OnShow(void)
{
    mainMenuEvent = EVENT_MAIN_NONE;
}

void MainMenu_OnUpdate(void)
{
    if (mainMenuEvent < EVENT_MAIN_NONE)
    {
        legato_showScreen(eventScreenTable[mainMenuEvent]);
        mainMenuEvent = EVENT_MAIN_NONE;
    }
}

void ListwheelDemoMenuButton_OnReleased(leButtonWidget* btn)
{
    mainMenuEvent = EVENT_MAIN_SHOW_LIST_WHEEL_DEMO;    
}

void AlphaBlendingDemoMenuButton_OnReleased(leButtonWidget* btn)
{
    mainMenuEvent = EVENT_MAIN_SHOW_ALPHA_DEMO;
}

void SlideShowDemoMenuButton_OnReleased(leButtonWidget* btn)
{
    mainMenuEvent = EVENT_MAIN_SHOW_SLIDESHOW_DEMO;
}

void TouchTestDemoMenuDemo_OnReleased(leButtonWidget* btn)
{
    mainMenuEvent = EVENT_MAIN_SHOW_TOUCH_TEST_DEMO;
}

void KeypadDemoMenuButton_OnReleased(leButtonWidget* btn)
{
    mainMenuEvent = EVENT_MAIN_SHOW_KEYPAD_DEMO;
}

void MainMenuHelpButton_OnReleased(leButtonWidget* btn)
{
    mainMenuEvent = EVENT_MAIN_SHOW_MAIN_MENU_HELP;
}

void MainMenuSettingsButton_OnReleased(leButtonWidget* btn)
{
    mainMenuEvent = EVENT_MAIN_SHOW_MAIN_MENU_SETTINGS;
}

void MainMenuNextButton_OnReleased(leButtonWidget* btn)
{
    mainMenuEvent = EVENT_MAIN_SHOW_NEXT_DEMO;
}

//Main Menu Help Screen Event Handlers
void MainMenuHelp_OnShow(void)
{
    mainMenuEvent = EVENT_MAIN_NONE;    
}

void MainMenuHelp_OnUpdate(void)
{
    if (mainMenuEvent < EVENT_MAIN_NONE)
    {
        legato_showScreen(eventScreenTable[mainMenuEvent]);
        mainMenuEvent = EVENT_MAIN_NONE;
    }
}

void MainMenuHelpCloseButton_OnReleased(leButtonWidget* btn)
{
    mainMenuEvent = EVENT_MAIN_SHOW_MAIN;
}