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

// CUSTOM CODE - DO NOT REMOVE 
#include "app.h"
// CUSTOM CODE END

#include "gfx/libaria/libaria_events.h"

// ButtonACFace - ReleasedEvent
void ButtonACFace_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_ACMode(0);
}

// ButtonACBoth - ReleasedEvent
void ButtonACBoth_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_ACMode(1);
}

// ButtonACFeet - ReleasedEvent
void ButtonACFeet_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_ACMode(2);
}

// ButtonACIntake - ReleasedEvent
void ButtonACIntake_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_ACIntake(0);
}

// ButtonACLoop - ReleasedEvent
void ButtonACLoop_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_ACIntake(1);
}

// ButtonACSync - ReleasedEvent
void ButtonACSync_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SyncAC();
}

// CircularSliderACRight - ValueChangedEvent
void CircularSliderACRight_ValueChangedEvent(laCircularSliderWidget * slider, int32_t value)
{
    // Custom Action
    APP_RightACChange(value);
}

// CircularSliderACLeft - ValueChangedEvent
void CircularSliderACLeft_ValueChangedEvent(laCircularSliderWidget * slider, int32_t value)
{
    // Custom Action
    APP_LeftACChange(value);
}

// ButtonBackspace - ReleasedEvent
void ButtonBackspace_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    TextFieldPhone->editWidget.clear((void*)TextFieldPhone);
}

// ButtonPhone1 - ReleasedEvent
void ButtonPhone1_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    TextFieldPhone->editWidget.append((void*)TextFieldPhone, laString_CreateFromID(string_String_One));
}

// ButtonPhone2 - ReleasedEvent
void ButtonPhone2_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    TextFieldPhone->editWidget.append((void*)TextFieldPhone, laString_CreateFromID(string_String_Two));
}

// ButtonPhone3 - ReleasedEvent
void ButtonPhone3_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    TextFieldPhone->editWidget.append((void*)TextFieldPhone, laString_CreateFromID(string_String_Three));
}

// ButtonPhone4 - ReleasedEvent
void ButtonPhone4_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    TextFieldPhone->editWidget.append((void*)TextFieldPhone, laString_CreateFromID(string_String_Four));
}

// ButtonPhone5 - ReleasedEvent
void ButtonPhone5_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    TextFieldPhone->editWidget.append((void*)TextFieldPhone, laString_CreateFromID(string_String_Five));
}

// ButtonPhone6 - ReleasedEvent
void ButtonPhone6_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    TextFieldPhone->editWidget.append((void*)TextFieldPhone, laString_CreateFromID(string_String_Six));
}

// ButtonPhone7 - ReleasedEvent
void ButtonPhone7_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    TextFieldPhone->editWidget.append((void*)TextFieldPhone, laString_CreateFromID(string_String_Seven));
}

// ButtonPhone8 - ReleasedEvent
void ButtonPhone8_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    TextFieldPhone->editWidget.append((void*)TextFieldPhone, laString_CreateFromID(string_String_Eight));
}

// ButtonPhone9 - ReleasedEvent
void ButtonPhone9_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    TextFieldPhone->editWidget.append((void*)TextFieldPhone, laString_CreateFromID(string_String_Nine));
}

// ButtonPhoneStar - ReleasedEvent
void ButtonPhoneStar_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    TextFieldPhone->editWidget.append((void*)TextFieldPhone, laString_CreateFromID(string_String_Star));
}

// ButtonPhone0 - ReleasedEvent
void ButtonPhone0_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    TextFieldPhone->editWidget.append((void*)TextFieldPhone, laString_CreateFromID(string_String_Zero));
}

// ButtonPhonePound - ReleasedEvent
void ButtonPhonePound_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    TextFieldPhone->editWidget.append((void*)TextFieldPhone, laString_CreateFromID(string_String_Pound));
}

// ButtonShuffle - ReleasedEvent
void ButtonShuffle_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_MusicShuffle();
}

// ButtonNextTrack - ReleasedEvent
void ButtonNextTrack_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_MusicPlayTrack();
}

// ModeSelector - ItemProminenceChangedEvent
void ModeSelector_ItemProminenceChangedEvent(laRadialMenuWidget * mn, laWidget * prominentWidget, int32_t value)
{
    // SelectItem
    APP_SelectItem(value);
}

// ButtonGPU - ReleasedEvent
void ButtonGPU_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_ToggleGPU();
}

// ButtonInfo - ReleasedEvent
void ButtonInfo_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchToInfoScreen - Show Screen - InfoScreen
    laContext_SetActiveScreen(InfoScreen_ID);

    // GoToInfoState
    APP_GoToInfoState();
}

// ReturnToMainButton - ReleasedEvent
void ReturnToMainButton_ReleasedEvent(laButtonWidget* btn)
{
    // ReturnToMain - Show Screen - MainScreen
    laContext_SetActiveScreen(MainScreen_ID);

    // SwitchAppState
    APP_GoToMainState();
}

// ButtonSplashScreen - ReleasedEvent
void ButtonSplashScreen_ReleasedEvent(laButtonWidget* btn)
{
    // ChangeScreenToSplash - Show Screen - SplashScreen
    laContext_SetActiveScreen(SplashScreen_ID);

    // UpdateAppToSplash
    APP_GoToSplashState();
}





