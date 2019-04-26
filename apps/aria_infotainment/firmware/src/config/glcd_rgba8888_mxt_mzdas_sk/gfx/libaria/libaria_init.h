/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Definitions Header

  File Name:
    libaria_macros.h

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

#ifndef _LIBARIA_INIT_H
#define _LIBARIA_INIT_H

#include "gfx/libaria/libaria.h"
#include "gfx/libaria/libaria_events.h"

#include "gfx/gfx_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

#define LIBARIA_SCREEN_COUNT   3

// reference IDs for generated libaria screens
// screen "InfoScreen"
#define InfoScreen_ID    2

// screen "MainScreen"
#define MainScreen_ID    1

// screen "SplashScreen"
#define SplashScreen_ID    0



extern laScheme ACButtonScheme;
extern laScheme ACDialScheme;
extern laScheme ClearScheme;
extern laScheme ButtonScheme;
extern laScheme PhoneListScheme;
extern laScheme NewScheme;
extern laScheme WhiteScheme;
extern laScheme TextScheme;
extern laScheme RadialMenuScheme;
extern laScheme VolumeDialScheme;
extern laImageWidget* ImageWidget1;
extern laImageWidget* ImageWidget3;
extern laImageWidget* ImageWidget2;
extern laImageWidget* ImageWidget4;
extern laWidget* ClimateControlPanel;
extern laButtonWidget* ButtonACFace;
extern laButtonWidget* ButtonACBoth;
extern laButtonWidget* ButtonACFeet;
extern laButtonWidget* ButtonDefrost;
extern laButtonWidget* ButtonACIntake;
extern laButtonWidget* ButtonACLoop;
extern laButtonWidget* ButtonACSync;
extern laLabelWidget* LabelSync;
extern laCircularSliderWidget* CircularSliderACRight;
extern laCircularSliderWidget* CircularSliderACLeft;
extern laWidget* PhonePanel;
extern laTextFieldWidget* TextFieldPhone;
extern laButtonWidget* ButtonBackspace;
extern laLabelWidget* LabelBackspace;
extern laButtonWidget* ButtonCall;
extern laImageWidget* ImagePhoneIcon;
extern laWidget* PhoneKeyPadPanel;
extern laButtonWidget* ButtonPhone1;
extern laButtonWidget* ButtonPhone2;
extern laLabelWidget* LabelNumber2;
extern laButtonWidget* ButtonPhone3;
extern laLabelWidget* LabelNumber3;
extern laButtonWidget* ButtonPhone4;
extern laLabelWidget* LabelNumber4;
extern laButtonWidget* ButtonPhone5;
extern laLabelWidget* LabelNumber5;
extern laButtonWidget* ButtonPhone6;
extern laLabelWidget* LabelNumber6;
extern laButtonWidget* ButtonPhone7;
extern laLabelWidget* LabelNumber7;
extern laButtonWidget* ButtonPhone8;
extern laLabelWidget* LabelNumber8;
extern laButtonWidget* ButtonPhone9;
extern laLabelWidget* LabelNumber9;
extern laButtonWidget* ButtonPhoneStar;
extern laButtonWidget* ButtonPhone0;
extern laLabelWidget* LabelNumber0;
extern laButtonWidget* ButtonPhonePound;
extern laListWidget* ListContacts;
extern laWidget* BluetoothPanel;
extern laButtonWidget* ButtonBluetoothPhone1;
extern laImageWidget* ImageSelectBluetoothDevice1;
extern laImageWidget* ImageBluetoothDevice1;
extern laLabelWidget* LabelPhone1;
extern laButtonWidget* ButtonBluetoothPhone2;
extern laImageWidget* ImageSelectBluetoothDevice2;
extern laImageWidget* ImageBluetoohDevice2;
extern laLabelWidget* LabelPhone2;
extern laWidget* NavPanel;
extern laImagePlusWidget* NavMap;
extern laWidget* BottomPanel;
extern laLabelWidget* LabelDistance;
extern laLabelWidget* LabelTravelTime;
extern laLabelWidget* LabelETA;
extern laButtonWidget* ButtonNavRead;
extern laWidget* MusicPanel;
extern laRadialMenuWidget* MusicSelector;
extern laImagePlusWidget* MusicSelector_Item0;
extern laImagePlusWidget* MusicSelector_Item1;
extern laImagePlusWidget* MusicSelector_Item2;
extern laImagePlusWidget* MusicSelector_Item3;
extern laImagePlusWidget* MusicSelector_Item4;
extern laImagePlusWidget* MusicSelector_Item5;
extern laImagePlusWidget* MusicSelector_Item6;
extern laImagePlusWidget* MusicSelector_Item7;
extern laImagePlusWidget* MusicSelector_Item8;
extern laImagePlusWidget* MusicSelector_Item9;
extern laButtonWidget* ButtonShuffle;
extern laButtonWidget* ButtonPlayPause;
extern laButtonWidget* ButtonNextTrack;
extern laImageWidget* ImageVolumeIcon;
extern laButtonWidget* ButtonVolumeUp;
extern laButtonWidget* ButtonVolumeDown;
extern laLineWidget* MusicLine;
extern laWidget* MusicPosition;
extern laWidget* IconPanel;
extern laImageSequenceWidget* CellSignal;
extern laImageSequenceWidget* BatteryPower;
extern laImageSequenceWidget* WifiSignal;
extern laLabelWidget* LabelClock;
extern laImageWidget* ImageMCHPLogo;
extern laLabelWidget* LabelACTempLeft;
extern laLabelWidget* LabelCelciusLeft;
extern laLabelWidget* LabelACTempRight;
extern laLabelWidget* LabelCelciusRight;
extern laWidget* LeftTrayPanel;
extern laButtonWidget* LeftTrayLid;
extern laImageWidget* LeftLidArrow;
extern laWidget* PanelWidget;
extern laRadialMenuWidget* ModeSelector;
extern laImagePlusWidget* ModeSelector_Item0;
extern laImagePlusWidget* ModeSelector_Item1;
extern laImagePlusWidget* ModeSelector_Item2;
extern laImagePlusWidget* ModeSelector_Item3;
extern laImagePlusWidget* ModeSelector_Item4;
extern laWidget* RightTrayPanel;
extern laWidget* RightButtonPanel;
extern laButtonWidget* ButtonGPU;
extern laLabelWidget* LabelGPU;
extern laButtonWidget* ButtonInfo;
extern laImageWidget* ImageTrunk;
extern laButtonWidget* RightTrayLid;
extern laImageWidget* RightLidArrow;
extern laWidget* PanelUpChevron;
extern laButtonWidget* ButtonChevronUp;
extern laWidget* PanelDownChevron;
extern laButtonWidget* ButtonChevronDown;
extern laImageWidget* InfoPageHarmonyLogo;
extern laImageWidget* ImageWidget7;
extern laWidget* InfoTextDragPanel;
extern laImageWidget* InfoText;
extern laWidget* PanelWidget1;
extern laLabelWidget* TextTitle;
extern laButtonWidget* ReturnToMainButton;
extern laButtonWidget* ButtonSplashScreen;




int32_t libaria_preprocess_assets(void);

int32_t libaria_initialize(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // _LIBARIA_INIT_H
/*******************************************************************************
 End of File
*/
