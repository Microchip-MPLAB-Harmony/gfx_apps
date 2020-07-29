/*******************************************************************************
  MPLAB Harmony Application Keypad Screen Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    screen_Keypad.c

  Summary:
    This file contains the source code for the keypad demo screen.

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
#define NUM_KEYPAD_ROWS 4
#define NUM_KEYPAD_COLS 10

static enum
{
    EVENT_KEYPAD_SHOW_NEXT,
    EVENT_KEYPAD_SHOW_HELP,
    EVENT_KEYPAD_SHOW_MAIN,
    EVENT_KEYPAD_SHOW_DEMO,
    EVENT_KEYPAD_NONE,
} keyPadScreenEvent;

static uint32_t eventScreenTable[] = 
{
    [EVENT_KEYPAD_SHOW_NEXT] = screenID_AlphaBlendingDemoScreen,
    [EVENT_KEYPAD_SHOW_HELP] = screenID_KeypadHelpScreen,
    [EVENT_KEYPAD_SHOW_MAIN] = screenID_MainMenu,
    [EVENT_KEYPAD_SHOW_DEMO] = screenID_KeypadDemoScreen,
};

char keypadChar[NUM_KEYPAD_ROWS][NUM_KEYPAD_COLS] = {
    {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
    {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
    {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '?'},
    {'z', 'x', 'c', 'v', 'b', 'n', 'm', ' ', '<', '>'}
};

void KeypadDemoScreen_OnShow(void)
{
    keyPadScreenEvent = EVENT_KEYPAD_NONE;
}

void KeypadDemoScreen_OnHide(void)
{
}

void KeypadDemoScreen_OnUpdate(void)
{
    if (keyPadScreenEvent < EVENT_KEYPAD_NONE)
    {
        legato_showScreen(eventScreenTable[keyPadScreenEvent]);
        keyPadScreenEvent = EVENT_KEYPAD_NONE;
    }   
}

void event_KeypadDemoScreen_KeypadHelpButton_OnReleased(leButtonWidget* btn)
{
    keyPadScreenEvent = EVENT_KEYPAD_SHOW_HELP;
}

void event_KeypadDemoScreen_KeypadHomeButton_OnReleased(leButtonWidget* btn)
{
    keyPadScreenEvent = EVENT_KEYPAD_SHOW_MAIN;
}

void event_KeypadDemoScreen_KeypadNextButton_OnReleased(leButtonWidget* btn)
{
    keyPadScreenEvent = EVENT_KEYPAD_SHOW_NEXT;
}

void event_KeypadDemoScreen_TextFieldWidget1_OnFocusChanged(leTextFieldWidget* txt, leBool focused)
{
    if (focused == LE_TRUE)
    {
        KeypadDemoScreen_KeyPadWidget1->fn->setVisible(KeypadDemoScreen_KeyPadWidget1, LE_TRUE);
    }
}
   
//Keypad Help Screen Event Handlers
void event_KeypadHelpScreen_KeypadHelpCloseButton_OnReleased(leButtonWidget* btn)
{
    keyPadScreenEvent = EVENT_KEYPAD_SHOW_DEMO;
}

void KeypadHelpScreen_OnShow(void)
{
    keyPadScreenEvent = EVENT_KEYPAD_NONE;
}

void KeypadHelpScreen_OnUpdate(void)
{
    if (keyPadScreenEvent < EVENT_KEYPAD_NONE)
    {
        legato_showScreen(eventScreenTable[keyPadScreenEvent]);
        keyPadScreenEvent = EVENT_KEYPAD_NONE;
    }     
}

