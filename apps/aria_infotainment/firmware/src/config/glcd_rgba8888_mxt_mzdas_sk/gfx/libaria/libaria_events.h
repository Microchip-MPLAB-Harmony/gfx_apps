/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Definitions Header

  File Name:
    libaria_events.h

  Summary:
    Build-time generated definitions header based on output by the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated definitions header based on output by the MPLAB Harmony
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

#ifndef _LIBARIA_EVENTS_H
#define _LIBARIA_EVENTS_H

#include "gfx/libaria/libaria.h"
#include "gfx/libaria/libaria_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

// Generated Event Handler - Origin: ButtonACFace, Event: PressedEvent
void ButtonACFace_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonACFace, Event: ReleasedEvent
void ButtonACFace_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonACBoth, Event: PressedEvent
void ButtonACBoth_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonACBoth, Event: ReleasedEvent
void ButtonACBoth_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonACFeet, Event: PressedEvent
void ButtonACFeet_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonACFeet, Event: ReleasedEvent
void ButtonACFeet_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonDefrost, Event: PressedEvent
void ButtonDefrost_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonACIntake, Event: PressedEvent
void ButtonACIntake_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonACIntake, Event: ReleasedEvent
void ButtonACIntake_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonACLoop, Event: PressedEvent
void ButtonACLoop_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonACLoop, Event: ReleasedEvent
void ButtonACLoop_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonACSync, Event: PressedEvent
void ButtonACSync_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonACSync, Event: ReleasedEvent
void ButtonACSync_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: CircularSliderACRight, Event: ValueChangedEvent
void CircularSliderACRight_ValueChangedEvent(laCircularSliderWidget * slider, int32_t value);

// Generated Event Handler - Origin: CircularSliderACRight, Event: PressedEvent
void CircularSliderACRight_PressedEvent(laCircularSliderWidget * slider, int32_t value);

// Generated Event Handler - Origin: CircularSliderACLeft, Event: ValueChangedEvent
void CircularSliderACLeft_ValueChangedEvent(laCircularSliderWidget * slider, int32_t value);

// Generated Event Handler - Origin: CircularSliderACLeft, Event: PressedEvent
void CircularSliderACLeft_PressedEvent(laCircularSliderWidget * slider, int32_t value);

// Generated Event Handler - Origin: TextFieldPhone, Event: TextChangedEvent
void TextFieldPhone_TextChangedEvent(laTextFieldWidget* txt);

// Generated Event Handler - Origin: TextFieldPhone, Event: FocusChangedEvent
void TextFieldPhone_FocusChangedEvent(laTextFieldWidget* txt, laBool focus);

// Generated Event Handler - Origin: ButtonBackspace, Event: ReleasedEvent
void ButtonBackspace_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonCall, Event: PressedEvent
void ButtonCall_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonPhone1, Event: ReleasedEvent
void ButtonPhone1_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonPhone2, Event: ReleasedEvent
void ButtonPhone2_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonPhone3, Event: ReleasedEvent
void ButtonPhone3_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonPhone4, Event: ReleasedEvent
void ButtonPhone4_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonPhone5, Event: ReleasedEvent
void ButtonPhone5_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonPhone6, Event: ReleasedEvent
void ButtonPhone6_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonPhone7, Event: ReleasedEvent
void ButtonPhone7_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonPhone8, Event: ReleasedEvent
void ButtonPhone8_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonPhone9, Event: ReleasedEvent
void ButtonPhone9_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonPhoneStar, Event: ReleasedEvent
void ButtonPhoneStar_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonPhone0, Event: ReleasedEvent
void ButtonPhone0_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonPhonePound, Event: ReleasedEvent
void ButtonPhonePound_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonBluetoothPhone1, Event: PressedEvent
void ButtonBluetoothPhone1_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonBluetoothPhone2, Event: PressedEvent
void ButtonBluetoothPhone2_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonNavRead, Event: PressedEvent
void ButtonNavRead_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonShuffle, Event: PressedEvent
void ButtonShuffle_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonShuffle, Event: ReleasedEvent
void ButtonShuffle_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonPlayPause, Event: PressedEvent
void ButtonPlayPause_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonNextTrack, Event: PressedEvent
void ButtonNextTrack_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonNextTrack, Event: ReleasedEvent
void ButtonNextTrack_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonVolumeUp, Event: PressedEvent
void ButtonVolumeUp_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonVolumeDown, Event: PressedEvent
void ButtonVolumeDown_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: LeftTrayLid, Event: ReleasedEvent
void LeftTrayLid_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ModeSelector, Event: ItemProminenceChangedEvent
void ModeSelector_ItemProminenceChangedEvent(laRadialMenuWidget * mn, laWidget * prominentWidget, int32_t value);

// Generated Event Handler - Origin: ButtonGPU, Event: ReleasedEvent
void ButtonGPU_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonInfo, Event: ReleasedEvent
void ButtonInfo_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: RightTrayLid, Event: ReleasedEvent
void RightTrayLid_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonChevronUp, Event: ReleasedEvent
void ButtonChevronUp_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonChevronDown, Event: ReleasedEvent
void ButtonChevronDown_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ReturnToMainButton, Event: ReleasedEvent
void ReturnToMainButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: ButtonSplashScreen, Event: ReleasedEvent
void ButtonSplashScreen_ReleasedEvent(laButtonWidget* btn);



//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // _LIBARIA_EVENTS_H
/*******************************************************************************
 End of File
*/
