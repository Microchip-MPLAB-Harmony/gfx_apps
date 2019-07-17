/*******************************************************************************
  MPLAB Harmony Application Settings Screen Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    screen_Settings.c

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
    EVENT_SETTINGS_SET_LANGUAGE_CHINESE,
    EVENT_SETTINGS_SET_LANGUAGE_ENGLISH,
    EVENT_SETTINGS_SHOW_MAIN_MENU,
    EVENT_SETTINGS_NONE,
} settingsScreenEvent;

void SettingsScreen_OnShow(void)
{
    uint32_t language =  leGetStringLanguage();
    
    settingsScreenEvent = EVENT_SETTINGS_NONE;
            
    switch(language)
    {
    	case language_Chinese:
            RadioButtonChinese->fn->setSelected(RadioButtonChinese);
        	break;
    	case language_English:
    	default:
            RadioButtonEnglish->fn->setSelected(RadioButtonEnglish);
    		break;
    }
}

void SettingsScreen_OnUpdate(void)
{
    switch(settingsScreenEvent)
    {
        case EVENT_SETTINGS_SET_LANGUAGE_CHINESE:
            RadioButtonChinese->fn->setSelected(RadioButtonChinese);
            leSetStringLanguage(1);
            break;
        case EVENT_SETTINGS_SET_LANGUAGE_ENGLISH:
            RadioButtonEnglish->fn->setSelected(RadioButtonEnglish);
            leSetStringLanguage(0);
            break;
        case EVENT_SETTINGS_SHOW_MAIN_MENU:
            legato_showScreen(screenID_MainMenu);
            break;
        default:
            break;
    }
    
    settingsScreenEvent = EVENT_SETTINGS_NONE;
}

void SettingsHomeButton_OnReleased(leButtonWidget* btn)
{
    settingsScreenEvent = EVENT_SETTINGS_SHOW_MAIN_MENU;
}

void ButtonWidgetChinese_OnReleased(leButtonWidget* btn)
{
    settingsScreenEvent = EVENT_SETTINGS_SET_LANGUAGE_CHINESE;
}

void ButtonWidgetEnglish_OnReleased(leButtonWidget* btn)
{
    settingsScreenEvent = EVENT_SETTINGS_SET_LANGUAGE_ENGLISH;
}

