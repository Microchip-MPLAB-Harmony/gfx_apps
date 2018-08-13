/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Implementation File

  File Name:
    libaria_events.c

  Summary:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

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

#include "gfx/libaria/libaria_events.h"

// START OF CUSTOM CODE - DO NOT MODIFY OR REMOVE!!!
#include <stdio.h>
#include "system/time/sys_time.h"

static laString sliderValueLabelString;
static SYS_TIME_HANDLE handleTimerFF = SYS_TIME_HANDLE_INVALID;
static SYS_TIME_HANDLE handleTimerPlay = SYS_TIME_HANDLE_INVALID;

static void Timer_Callback ( uintptr_t context)
{
    laImageSequenceWidget_ShowNextImage(ImageSequenceWidget1);
}
// END OF CUSTOM CODE 

// ButtonWidget13 - ReleasedEvent
void ButtonWidget13_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchToSlider - Show Screen - FirstScreen
    laContext_SetActiveScreen(FirstScreen_ID);
}

// ButtonWidget14 - ReleasedEvent
void ButtonWidget14_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchToAlpha - Show Screen - FourthScreen
    laContext_SetActiveScreen(FourthScreen_ID);
}

// ButtonWidget15 - ReleasedEvent
void ButtonWidget15_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchToSlideShow - Show Screen - FifthScreen
    laContext_SetActiveScreen(FifthScreen_ID);
}

// ButtonWidget16 - ReleasedEvent
void ButtonWidget16_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchToTouch - Show Screen - SecondScreen
    laContext_SetActiveScreen(SecondScreen_ID);
}

// ButtonWidget17 - ReleasedEvent
void ButtonWidget17_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchToKeypad - Show Screen - ThirdScreen
    laContext_SetActiveScreen(ThirdScreen_ID);
}

// ButtonWidget18 - ReleasedEvent
void ButtonWidget18_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (MainMenuHelp) - Show Screen - MainMenuHelp
    laContext_SetActiveScreen(MainMenuHelp_ID);
}

// ButtonWidget19 - ReleasedEvent
void ButtonWidget19_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchToSettings - Show Screen - SettingsScreen
    laContext_SetActiveScreen(SettingsScreen_ID);
}

// ButtonWidget29 - ReleasedEvent
void ButtonWidget29_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (FirstScreen) - Show Screen - FirstScreen
    laContext_SetActiveScreen(FirstScreen_ID);
}

// ButtonWidget1 - ReleasedEvent
void ButtonWidget1_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (ListWheelHelpScreen) - Show Screen - ListWheelHelpScreen
    laContext_SetActiveScreen(ListWheelHelpScreen_ID);
}

// ButtonWidget7 - ReleasedEvent
void ButtonWidget7_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchToMain - Show Screen - MainMenu
    laContext_SetActiveScreen(MainMenu_ID);
}

// ListWheel1 - SelectedItemChangedEvent
void ListWheel1_SelectedItemChangedEvent(laListWheelWidget* whl, uint32_t idx)
{
    // Custom Action
    if (idx == 2 || idx == 3)
        laListWheelWidget_SetSelectedItem((laListWheelWidget*)ListWheel1, 1);
    else if (idx == 4 || idx == 5)
        laListWheelWidget_SetSelectedItem((laListWheelWidget*)ListWheel1, 0); 
}

// ButtonWidget30 - ReleasedEvent
void ButtonWidget30_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (SecondScreen) - Show Screen - SecondScreen
    laContext_SetActiveScreen(SecondScreen_ID);
}

// ButtonWidget2 - ReleasedEvent
void ButtonWidget2_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (TouchTestHelpScreen) - Show Screen - TouchTestHelpScreen
    laContext_SetActiveScreen(TouchTestHelpScreen_ID);
}

// ButtonWidget3 - ReleasedEvent
void ButtonWidget3_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchToMain - Show Screen - MainMenu
    laContext_SetActiveScreen(MainMenu_ID);
}

// ButtonWidget31 - ReleasedEvent
void ButtonWidget31_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (ThirdScreen) - Show Screen - ThirdScreen
    laContext_SetActiveScreen(ThirdScreen_ID);
}

// KeyPadWidget1 - KeyClickEvent
void KeyPadWidget1_KeyClickEvent(laKeyPadWidget* pad, laButtonWidget* btn, uint32_t row, uint32_t col)
{
}

// ButtonWidget5 - ReleasedEvent
void ButtonWidget5_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (KeypadHelpScreen) - Show Screen - KeypadHelpScreen
    laContext_SetActiveScreen(KeypadHelpScreen_ID);
}

// ButtonWidget6 - ReleasedEvent
void ButtonWidget6_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchToMain - Show Screen - MainMenu
    laContext_SetActiveScreen(MainMenu_ID);
}

// ButtonWidget32 - ReleasedEvent
void ButtonWidget32_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (FourthScreen) - Show Screen - FourthScreen
    laContext_SetActiveScreen(FourthScreen_ID);
}

// FourthScreen - ShowEvent
void FourthScreen_ShowEvent(laScreen* scr)
{
    // OnShow
    char value[4] = {0};
    uint32_t sliderPercentage = laSliderWidget_GetSliderPercentage(SliderWidget1);
        
    snprintf(value, 4, "%ld", sliderPercentage);
        
    sliderValueLabelString = laString_CreateFromCharBuffer(value, &ArialUnicodeMS);
    laLabelWidget_SetText(SliderValueLabelWidget, sliderValueLabelString);
}

// FourthScreen - HideEvent
void FourthScreen_HideEvent(laScreen* scr)
{
    // OnHide
    laString_Destroy(&sliderValueLabelString);
}

// SliderWidget1 - ValueChangedEvent
void SliderWidget1_ValueChangedEvent(laSliderWidget* sld)
{
    // ChangeValue
    char value[4] = {0};
    uint32_t sliderPercentage = laSliderWidget_GetSliderPercentage(sld);
    
    snprintf(value, 4, "%ld", sliderPercentage);
    
    laString_Destroy(&sliderValueLabelString);
    sliderValueLabelString = laString_CreateFromCharBuffer(value, &ArialUnicodeMS);
    laLabelWidget_SetText(SliderValueLabelWidget, sliderValueLabelString);

    // ChangeValue
    laWidget_SetAlphaAmount((laWidget*)ImageWidget2, 255 - laSliderWidget_GetSliderValue(sld));
    laWidget_SetAlphaAmount((laWidget*)ImageWidget1, laSliderWidget_GetSliderValue(sld));
}

// ButtonWidget4 - ReleasedEvent
void ButtonWidget4_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (AlphaBlendingHelpScreen) - Show Screen - AlphaBlendingHelpScreen
    laContext_SetActiveScreen(AlphaBlendingHelpScreen_ID);
}

// ButtonWidget8 - ReleasedEvent
void ButtonWidget8_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchToMain - Show Screen - MainMenu
    laContext_SetActiveScreen(MainMenu_ID);
}

// ButtonWidget33 - ReleasedEvent
void ButtonWidget33_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (FifthScreen) - Show Screen - FifthScreen
    laContext_SetActiveScreen(FifthScreen_ID);
}

// SliderUpButtonWidget - ReleasedEvent
void SliderUpButtonWidget_ReleasedEvent(laButtonWidget* btn)
{
    // SliderUp
    uint32_t sliderPercentage = laSliderWidget_GetSliderPercentage(SliderWidget1);
    
    if (sliderPercentage < 100)
        sliderPercentage = sliderPercentage + 1;

    laSliderWidget_SetSliderPercentage(SliderWidget1, sliderPercentage);
}

// SliderDownButtonWidget - ReleasedEvent
void SliderDownButtonWidget_ReleasedEvent(laButtonWidget* btn)
{
    // SliderDown
    uint32_t sliderPercentage = laSliderWidget_GetSliderPercentage(SliderWidget1);
    
    if (sliderPercentage > 0)
        sliderPercentage = sliderPercentage - 1;
    
    laSliderWidget_SetSliderPercentage(SliderWidget1, sliderPercentage);
}

// FifthScreen - HideEvent
void FifthScreen_HideEvent(laScreen* scr)
{
    // Custom Action
    if (handleTimerPlay != SYS_TIME_HANDLE_INVALID)
        SYS_TIME_TimerDestroy(handleTimerPlay);
        
    if (handleTimerFF != SYS_TIME_HANDLE_INVALID)
        SYS_TIME_TimerDestroy(handleTimerFF);
    
    handleTimerPlay = SYS_TIME_HANDLE_INVALID;
    handleTimerFF = SYS_TIME_HANDLE_INVALID;
}

// ButtonWidget9 - ReleasedEvent
void ButtonWidget9_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (SlideshowHelpScreen) - Show Screen - SlideshowHelpScreen
    laContext_SetActiveScreen(SlideshowHelpScreen_ID);
}

// ButtonWidget11 - ReleasedEvent
void ButtonWidget11_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchToMain - Show Screen - MainMenu
    laContext_SetActiveScreen(MainMenu_ID);
}

// ButtonWidget10 - ReleasedEvent
void ButtonWidget10_ReleasedEvent(laButtonWidget* btn)
{
    // Show Previous (ImageSequenceWidget1) - Show Previous - ImageSequenceWidget1
    laImageSequenceWidget_ShowPreviousImage((laImageSequenceWidget*)ImageSequenceWidget1);
}

// ButtonWidget20 - ReleasedEvent
void ButtonWidget20_ReleasedEvent(laButtonWidget* btn)
{
    // Show Next (ImageSequenceWidget1) - Show Next - ImageSequenceWidget1
    laImageSequenceWidget_ShowNextImage((laImageSequenceWidget*)ImageSequenceWidget1);
}

// ButtonWidget21 - PressedEvent
void ButtonWidget21_PressedEvent(laButtonWidget* btn)
{
    // FastForwardShow
    //Release Normal SS button
    laButtonWidget_SetPressed((laButtonWidget*)ButtonWidget22, LA_FALSE);
    
    //Start Fast Forward show
    if (handleTimerPlay != SYS_TIME_HANDLE_INVALID)
        SYS_TIME_TimerDestroy(handleTimerPlay);
        
    if (handleTimerFF != SYS_TIME_HANDLE_INVALID)
        SYS_TIME_TimerDestroy(handleTimerFF);
    
    handleTimerPlay = SYS_TIME_HANDLE_INVALID;
    handleTimerFF = SYS_TIME_HANDLE_INVALID;
    
    handleTimerFF = SYS_TIME_CallbackRegisterMS(Timer_Callback, 1, 500, SYS_TIME_PERIODIC);
    
    laImageWidget_SetImage(SSStatusImageWidget, &GFX_FF_Green_20x20);
}

// ButtonWidget21 - ReleasedEvent
void ButtonWidget21_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    if (handleTimerFF != SYS_TIME_HANDLE_INVALID)
        SYS_TIME_TimerDestroy(handleTimerFF);
    
    handleTimerFF = SYS_TIME_HANDLE_INVALID;
    
    laImageWidget_SetImage(SSStatusImageWidget, &GFX_Pause_Pink_20x20);
}

// ButtonWidget22 - PressedEvent
void ButtonWidget22_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    //Release the FF button
    laButtonWidget_SetPressed((laButtonWidget*)ButtonWidget21, LA_FALSE);

    //Start normal slideshow
    if (handleTimerPlay != SYS_TIME_HANDLE_INVALID)
        SYS_TIME_TimerDestroy(handleTimerPlay);
    if (handleTimerFF != SYS_TIME_HANDLE_INVALID)
        SYS_TIME_TimerDestroy(handleTimerFF);
    
    handleTimerPlay = SYS_TIME_HANDLE_INVALID;
    handleTimerFF = SYS_TIME_HANDLE_INVALID;
    
    handleTimerPlay = SYS_TIME_CallbackRegisterMS(Timer_Callback, 1, 2000, SYS_TIME_PERIODIC);
    
    laImageWidget_SetImage(SSStatusImageWidget, &GFX_Play_Green_20x20);
}

// ButtonWidget22 - ReleasedEvent
void ButtonWidget22_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    if (handleTimerPlay != SYS_TIME_HANDLE_INVALID)
        SYS_TIME_TimerDestroy(handleTimerPlay);
    
    handleTimerPlay = SYS_TIME_HANDLE_INVALID;
    
    laImageWidget_SetImage(SSStatusImageWidget, &GFX_Pause_Pink_20x20);
}

// SettingsScreen - ShowEvent
void SettingsScreen_ShowEvent(laScreen* scr)
{
    // SelectLanguage
    // SetActiveLanguage
    // SetActiveLanguage
    uint32_t language = laContext_GetStringLanguage();
            
    switch(language)
    {
    	case language_Chinese:
            laRadioButtonWidget_SetSelected(RadioButtonChinese);
        	break;
    	case language_English:
    	default:
        	laRadioButtonWidget_SetSelected(RadioButtonEnglish);
    		break;
    }
}

// ButtonWidget12 - ReleasedEvent
void ButtonWidget12_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchToHome - Show Screen - MainMenu
    laContext_SetActiveScreen(MainMenu_ID);
}

// RadioButtonChinese - CheckedEvent
void RadioButtonChinese_CheckedEvent(laRadioButtonWidget* cbox)
{
    // SwitchToChinese
    laContext_SetStringLanguage(language_Chinese);
}

// RadioButtonEnglish - CheckedEvent
void RadioButtonEnglish_CheckedEvent(laRadioButtonWidget* cbox)
{
    // SwitchToEnglish
    laContext_SetStringLanguage(language_English);
}

// ButtonWidgetChinese - PressedEvent
void ButtonWidgetChinese_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    laRadioButtonWidget_SetSelected(RadioButtonChinese);
}

// ButtonWidgetEnglish - PressedEvent
void ButtonWidgetEnglish_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    laRadioButtonWidget_SetSelected(RadioButtonEnglish);
}

// ButtonWidget23 - ReleasedEvent
void ButtonWidget23_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (MainMenu) - Show Screen - MainMenu
    laContext_SetActiveScreen(MainMenu_ID);
}

// ButtonWidget24 - ReleasedEvent
void ButtonWidget24_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (FirstScreen) - Show Screen - FirstScreen
    laContext_SetActiveScreen(FirstScreen_ID);
}

// ButtonWidget25 - ReleasedEvent
void ButtonWidget25_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (SecondScreen) - Show Screen - SecondScreen
    laContext_SetActiveScreen(SecondScreen_ID);
}

// ButtonWidget26 - ReleasedEvent
void ButtonWidget26_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (ThirdScreen) - Show Screen - ThirdScreen
    laContext_SetActiveScreen(ThirdScreen_ID);
}

// ButtonWidget27 - ReleasedEvent
void ButtonWidget27_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (FourthScreen) - Show Screen - FourthScreen
    laContext_SetActiveScreen(FourthScreen_ID);
}

// ButtonWidget28 - ReleasedEvent
void ButtonWidget28_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (FifthScreen) - Show Screen - FifthScreen
    laContext_SetActiveScreen(FifthScreen_ID);
}





