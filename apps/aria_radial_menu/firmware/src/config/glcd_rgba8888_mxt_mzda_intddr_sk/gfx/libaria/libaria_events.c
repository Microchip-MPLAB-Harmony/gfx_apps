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
    libaria_events.c

  Summary:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/

#include "gfx/libaria/libaria_events.h"
#include "app.h"

// RadialMenuWidget_Main - ItemSelectedEvent
void RadialMenuWidget_Main_ItemSelectedEvent(laRadialMenuWidget * mn, laWidget * selectedWidget, int32_t value)
{
    // Menu Select
    APP_SwitchScreenRequest(value);
}

// RadialMenuWidget_Main - ItemProminenceChangedEvent
void RadialMenuWidget_Main_ItemProminenceChangedEvent(laRadialMenuWidget * mn, laWidget * prominentWidget, int32_t value)
{
    // Set Prominent
    APP_SelectItem(value);
}

// InfoButton - ReleasedEvent
void InfoButton_ReleasedEvent(laButtonWidget* btn)
{
    // SetAppState
    APP_GoToInfoState();

    // SwitchToInfo - Show Screen - InfoScreen
    laContext_SetActiveScreen(InfoScreen_ID);
}

// ReturnToMainButton - ReleasedEvent
void ReturnToMainButton_ReleasedEvent(laButtonWidget* btn)
{
    // ReturnToMain - Show Screen - MainScreen
    laContext_SetActiveScreen(MainScreen_ID);

    // SwitchAppState
    APP_GoToMainState();
}

// ButtonWidget - ReleasedEvent
void ButtonWidget_ReleasedEvent(laButtonWidget* btn)
{
    // ChangeScreenToSplash - Show Screen - SplashScreen
    laContext_SetActiveScreen(SplashScreen_ID);

    // UpdateAppToSplash
    APP_GoToSplashState(false);
}

// ButtonWidget4 - ReleasedEvent
void ButtonWidget4_ReleasedEvent(laButtonWidget* btn)
{
    // GoToInfoState
    APP_GoToInfoState();

    // Show Screen (InfoScreen) - Show Screen - InfoScreen
    laContext_SetActiveScreen(InfoScreen_ID);
}

// ButtonWidget2 - ReleasedEvent
void ButtonWidget2_ReleasedEvent(laButtonWidget* btn)
{
    // SetAppState
    APP_GoToMainState();

    // Show Screen (MainScreen) - Show Screen - MainScreen
    laContext_SetActiveScreen(MainScreen_ID);
}

// ButtonWidget8 - ReleasedEvent
void ButtonWidget8_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (MainScreen) - Show Screen - MainScreen
    laContext_SetActiveScreen(MainScreen_ID);

    // Custom Action
    APP_GoToMainState();
}

// ButtonWidget6 - ReleasedEvent
void ButtonWidget6_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_GoToInfoState();

    // Show Screen (InfoScreen) - Show Screen - InfoScreen
    laContext_SetActiveScreen(InfoScreen_ID);
}

// ButtonWidget3 - ReleasedEvent
void ButtonWidget3_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_GoToMainState();

    // Show Screen (MainScreen) - Show Screen - MainScreen
    laContext_SetActiveScreen(MainScreen_ID);
}

// ButtonWidget1 - ReleasedEvent
void ButtonWidget1_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_GoToInfoState();

    // Show Screen (InfoScreen) - Show Screen - InfoScreen
    laContext_SetActiveScreen(InfoScreen_ID);
}





