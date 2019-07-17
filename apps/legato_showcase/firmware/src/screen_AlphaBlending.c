/*******************************************************************************
  MPLAB Harmony Application Keypad Screen Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    screen_AlphaBlending.c

  Summary:
    This file contains the source code for the alpha blending demo.

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

#include <stdio.h>
#include "gfx/legato/generated/le_gen_init.h"

static leDynamicString alphaValueText;

static enum
{
    EVENT_ALPHA_BLENDING_SHOW_NEXT,
    EVENT_ALPHA_BLENDING_SHOW_HELP,
    EVENT_ALPHA_BLENDING_SHOW_MAIN,
    EVENT_ALPHA_BLENDING_SHOW_DEMO,
    EVENT_ALPHA_BLENDING_ALPHA_UP,
    EVENT_ALPHA_BLENDING_ALPHA_DOWN,
    EVENT_ALPHA_BLENDING_SLIDER_VALUE_CHANGED,
    EVENT_ALPHA_BLENDING_NONE,
} alphaBlendingScreenEvent;

static uint32_t eventScreenTable[] = 
{
    [EVENT_ALPHA_BLENDING_SHOW_NEXT] = screenID_SlideShowDemoScreen,
    [EVENT_ALPHA_BLENDING_SHOW_HELP] = screenID_AlphaBlendingHelpScreen,
    [EVENT_ALPHA_BLENDING_SHOW_MAIN] = screenID_MainMenu,
    [EVENT_ALPHA_BLENDING_SHOW_DEMO] = screenID_AlphaBlendingDemoScreen,
};

//Alpha Blending screen events
void AlphaBlendingDemoScreen_OnShow(void)
{
    leFont* font = NULL;
    
    alphaBlendingScreenEvent = EVENT_ALPHA_BLENDING_NONE;
    
    font = leStringTable_GetStringFont(&stringTable, string_Keypad_0, 0);
    
    leDynamicString_Constructor(&alphaValueText);
    alphaValueText.fn->setFont(&alphaValueText, font);
}

void AlphaBlendingDemoScreen_OnHide(void)
{
    alphaValueText.fn->destructor(&alphaValueText);
}

static void UpdateAlphaValue(unsigned int value)
{
    char charBuff[4] = {0};
    
    sprintf(charBuff, "%u", value);
    
    alphaValueText.fn->setFromCStr(&alphaValueText, charBuff);
    SliderValueLabelWidget->fn->setString(SliderValueLabelWidget, (leString*)&alphaValueText);    
    
    ImageWidget1->fn->setAlphaAmount(ImageWidget1, value);
    ImageWidget2->fn->setAlphaAmount(ImageWidget2, 255 - value);
}

void AlphaBlendingDemoScreen_OnUpdate(void)
{
    switch(alphaBlendingScreenEvent)
    {
        case EVENT_ALPHA_BLENDING_SHOW_NEXT:
        case EVENT_ALPHA_BLENDING_SHOW_HELP:
        case EVENT_ALPHA_BLENDING_SHOW_MAIN:
        case EVENT_ALPHA_BLENDING_SHOW_DEMO:
            legato_showScreen(eventScreenTable[alphaBlendingScreenEvent]);
            break;
        case EVENT_ALPHA_BLENDING_ALPHA_UP:
        {
            uint32_t sliderValue = SliderWidget1->fn->getValue(SliderWidget1);
            
            if (sliderValue < 255)
            {
                sliderValue++;
                SliderWidget1->fn->setValue(SliderWidget1, sliderValue);
                UpdateAlphaValue(sliderValue);
            }
            
            break;
        }
        case EVENT_ALPHA_BLENDING_ALPHA_DOWN:
        {
            uint32_t sliderValue = SliderWidget1->fn->getValue(SliderWidget1);
            
            if (sliderValue > 0)
            {
                sliderValue--;
                SliderWidget1->fn->setValue(SliderWidget1, sliderValue);
                UpdateAlphaValue(sliderValue);
            }
            
            break;
        }
        case EVENT_ALPHA_BLENDING_SLIDER_VALUE_CHANGED:
        {
            uint32_t sliderValue = SliderWidget1->fn->getValue(SliderWidget1);
            UpdateAlphaValue(sliderValue);
            break;
        }
        default:
            break;
    }
    
    alphaBlendingScreenEvent = EVENT_ALPHA_BLENDING_NONE;
}

void SliderWidget1_OnValueChanged(leSliderWidget* sld)
{
    alphaBlendingScreenEvent = EVENT_ALPHA_BLENDING_SLIDER_VALUE_CHANGED;
}

void AlphaHelpButton_OnReleased(leButtonWidget* btn)
{
    alphaBlendingScreenEvent = EVENT_ALPHA_BLENDING_SHOW_HELP;
}

void AlphaHomeButton_OnReleased(leButtonWidget* btn)
{
    alphaBlendingScreenEvent = EVENT_ALPHA_BLENDING_SHOW_MAIN;
}

void AlphaNextButton_OnReleased(leButtonWidget* btn)
{
    alphaBlendingScreenEvent = EVENT_ALPHA_BLENDING_SHOW_NEXT;
}

void SliderUpButtonWidget_OnReleased(leButtonWidget* btn)
{
    alphaBlendingScreenEvent = EVENT_ALPHA_BLENDING_ALPHA_UP;
}

void SliderDownButtonWidget_OnReleased(leButtonWidget* btn)
{
    alphaBlendingScreenEvent = EVENT_ALPHA_BLENDING_ALPHA_DOWN;
}

//Alpha Blending Help Screen Events
void AlphaBlendingHelpScreen_OnShow(void)
{
    alphaBlendingScreenEvent = EVENT_ALPHA_BLENDING_NONE;
}

void AlphaBlendingHelpScreen_OnUpdate(void)
{
    if (alphaBlendingScreenEvent == EVENT_ALPHA_BLENDING_SHOW_DEMO)
    {
        legato_showScreen(eventScreenTable[alphaBlendingScreenEvent]);
    }
    
    alphaBlendingScreenEvent = EVENT_ALPHA_BLENDING_NONE;
}

void AlphaHelpCloseButton_OnReleased(leButtonWidget* btn)
{
    alphaBlendingScreenEvent = EVENT_ALPHA_BLENDING_SHOW_DEMO;
}

