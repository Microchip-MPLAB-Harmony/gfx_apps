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
#include "app.h"

// ButtonWidget1 - ReleasedEvent
void ButtonWidget1_ReleasedEvent(laButtonWidget* btn)
{
    // showInfoScreen - Show Screen - infoScreen
    laContext_SetActiveScreen(infoScreen_ID);
}

// StartButton - PressedEvent
void StartButton_PressedEvent(laButtonWidget* btn)
{
    // onStartButtonPressed - Show Screen - controllerScreen
    laContext_SetActiveScreen(controllerScreen_ID);
}

// controllerScreen - ShowEvent
void controllerScreen_ShowEvent(laScreen* scr)
{
    // activateControllerScreen
    APP_AnimateControllerScreen();
}

// HomeButton - ReleasedEvent
void HomeButton_ReleasedEvent(laButtonWidget* btn)
{
    // showHomeScreen - Show Screen - homeScreen
    laContext_SetActiveScreen(homeScreen_ID);
}

// FishButtonWidget - ReleasedEvent
void FishButtonWidget_ReleasedEvent(laButtonWidget* btn)
{
    // onFishButtonRelease
    APP_OnFishButtonRelease();
}

// PizzaButtonWidget - ReleasedEvent
void PizzaButtonWidget_ReleasedEvent(laButtonWidget* btn)
{
    // onPizzaButtonRelease
    APP_OnPizzaButtonRelease();
}

// VegeButtonWidget - ReleasedEvent
void VegeButtonWidget_ReleasedEvent(laButtonWidget* btn)
{
    // onVegeButtonRelease
    APP_OnVegeButtonRelease();
}

// StartStopButton - PressedEvent
void StartStopButton_PressedEvent(laButtonWidget* btn)
{
    // onStartButtonToggled
    APP_OnStartButtonToggled();
}

// StartStopButton - ReleasedEvent
void StartStopButton_ReleasedEvent(laButtonWidget* btn)
{
    // onStartButtonToggled
    APP_OnStartButtonToggled();
}

// DoneButton - ReleasedEvent
void DoneButton_ReleasedEvent(laButtonWidget* btn)
{
    // onButtonDone
    APP_OnButtonDoneReleased();
}

// ButtonWidget16 - ReleasedEvent
void ButtonWidget16_ReleasedEvent(laButtonWidget* btn)
{
    // showControllerScreen1 - Show Screen - homeScreen
    laContext_SetActiveScreen(homeScreen_ID);
}





