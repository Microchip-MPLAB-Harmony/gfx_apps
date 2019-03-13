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

#include "gfx/libaria/libaria_events.h"
//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!
#include "app.h"
//END OF CUSTOM CODE

// mainLoadButton - ReleasedEvent
void mainLoadButton_ReleasedEvent(laButtonWidget* btn)
{
    // onLoadButtonReleased - Show Screen - stage_screen
    laContext_SetActiveScreen(stage_screen_ID);
}

// mainTestButton - ReleasedEvent
void mainTestButton_ReleasedEvent(laButtonWidget* btn)
{
    // onTestButtonReleased - Show Screen - test_screen_buttons
    laContext_SetActiveScreen(test_screen_buttons_ID);
}

// ButtonWidget19 - ReleasedEvent
void ButtonWidget19_ReleasedEvent(laButtonWidget* btn)
{
    // onLoadExitButtonReleased - Show Screen - main_screen
    laContext_SetActiveScreen(main_screen_ID);
}

// stageButton - ReleasedEvent
void stageButton_ReleasedEvent(laButtonWidget* btn)
{
    // onStageButtonReleased
    APP_OnStageButtonReleased();
}

// stageSDCardButton - ReleasedEvent
void stageSDCardButton_ReleasedEvent(laButtonWidget* btn)
{
    // onStageSDCardButtonReleased
    APP_OnStageSDCardButtonReleased();
}

// stagePCButton - ReleasedEvent
void stagePCButton_ReleasedEvent(laButtonWidget* btn)
{
    // onStagePCButtonReleased
    APP_OnStagePCButtonReleased();
}

// stageProgramButton - ReleasedEvent
void stageProgramButton_ReleasedEvent(laButtonWidget* btn)
{
    // onStageProgramButtonReleased
    APP_OnStageProgramButtonReleased();
}

// stageUsbButton - ReleasedEvent
void stageUsbButton_ReleasedEvent(laButtonWidget* btn)
{
    // onStageUSBCardButtonReleased
    APP_OnStageUSBCardButtonReleased();
}

// stageNextButton - ReleasedEvent
void stageNextButton_ReleasedEvent(laButtonWidget* btn)
{
    // onStageNextButtonReleased - Show Screen - load_screen
    laContext_SetActiveScreen(load_screen_ID);
}

// load_screen - ShowEvent
void load_screen_ShowEvent(laScreen* scr)
{
    // onLoadScreenShow
    APP_OnLoadScreenShow();
}

// loadButton - ReleasedEvent
void loadButton_ReleasedEvent(laButtonWidget* btn)
{
    // onLoadButtonReleased
    APP_OnLoadButtonReleased();
}

// ButtonWidget14 - ReleasedEvent
void ButtonWidget14_ReleasedEvent(laButtonWidget* btn)
{
    // onLoadBackButtonReleased - Show Screen - stage_screen
    laContext_SetActiveScreen(stage_screen_ID);
}

// loadProgramRadioButton - CheckedEvent
void loadProgramRadioButton_CheckedEvent(laRadioButtonWidget* cbox)
{
}

// loadProgramButton - ReleasedEvent
void loadProgramButton_ReleasedEvent(laButtonWidget* btn)
{
    // onLoadProgramButtonReleased
    APP_OnLoadProgramButtonReleased();
}

// loadSDCardButton - ReleasedEvent
void loadSDCardButton_ReleasedEvent(laButtonWidget* btn)
{
    // onLoadSDCardButtonReleased
    APP_OnLoadSDCardButtonReleased();
}

// loadPCButton - ReleasedEvent
void loadPCButton_ReleasedEvent(laButtonWidget* btn)
{
    // onLoadPCButtonReleased
    APP_OnLoadPCButtonReleased();
}

// loadUSBBUtton - ReleasedEvent
void loadUSBBUtton_ReleasedEvent(laButtonWidget* btn)
{
    // onLoadUSBButtonReleased
    APP_OnLoadUSBButtonReleased();
}

// loadNextButton - ReleasedEvent
void loadNextButton_ReleasedEvent(laButtonWidget* btn)
{
    // onLoadNextButtonReleased - Show Screen - test_screen_buttons
    laContext_SetActiveScreen(test_screen_buttons_ID);
}

// ButtonWidget3 - ReleasedEvent
void ButtonWidget3_ReleasedEvent(laButtonWidget* btn)
{
    // onTestScreenButtonBack - Show Screen - stage_screen
    laContext_SetActiveScreen(stage_screen_ID);
}

// ButtonWidget4 - ReleasedEvent
void ButtonWidget4_ReleasedEvent(laButtonWidget* btn)
{
    // onTestButtonScreen - Show Screen - test_screen
    laContext_SetActiveScreen(test_screen_ID);
}

// ButtonWidget20 - ReleasedEvent
void ButtonWidget20_ReleasedEvent(laButtonWidget* btn)
{
    // onTestExitButtonReleased - Show Screen - test_screen_buttons
    laContext_SetActiveScreen(test_screen_buttons_ID);
}

// testStoreButton - ReleasedEvent
void testStoreButton_ReleasedEvent(laButtonWidget* btn)
{
    // onStoreButtonReleased - Show Screen - store_screen
    laContext_SetActiveScreen(store_screen_ID);
}

// ButtonWidget5 - ReleasedEvent
void ButtonWidget5_ReleasedEvent(laButtonWidget* btn)
{
    // onTouchTestScreenForward - Show Screen - store_screen
    laContext_SetActiveScreen(store_screen_ID);
}

// ButtonWidget21 - ReleasedEvent
void ButtonWidget21_ReleasedEvent(laButtonWidget* btn)
{
    // onStoreExitButtonReleased - Show Screen - test_screen
    laContext_SetActiveScreen(test_screen_ID);
}

// storeSaveButton - ReleasedEvent
void storeSaveButton_ReleasedEvent(laButtonWidget* btn)
{
    // onSaveButtonReleased
    APP_OnSaveButtonReleased();
}

// storeDoneButton - ReleasedEvent
void storeDoneButton_ReleasedEvent(laButtonWidget* btn)
{
    // onSaveDoneButtonRelease - Show Screen - main_screen
    laContext_SetActiveScreen(main_screen_ID);
}





