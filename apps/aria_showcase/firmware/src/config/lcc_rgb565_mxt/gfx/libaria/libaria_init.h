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

#define LIBARIA_SCREEN_COUNT   14

// reference IDs for generated libaria screens
// screen "AlphaBlendingHelpScreen"
#define AlphaBlendingHelpScreen_ID    12

// screen "FifthScreen"
#define FifthScreen_ID    6

// screen "FirstScreen"
#define FirstScreen_ID    2

// screen "FourthScreen"
#define FourthScreen_ID    5

// screen "KeypadHelpScreen"
#define KeypadHelpScreen_ID    11

// screen "ListWheelHelpScreen"
#define ListWheelHelpScreen_ID    9

// screen "MainMenu"
#define MainMenu_ID    1

// screen "MainMenuHelp"
#define MainMenuHelp_ID    8

// screen "SecondScreen"
#define SecondScreen_ID    3

// screen "SettingsScreen"
#define SettingsScreen_ID    7

// screen "SlideshowHelpScreen"
#define SlideshowHelpScreen_ID    13

// screen "SplashScreen"
#define SplashScreen_ID    0

// screen "ThirdScreen"
#define ThirdScreen_ID    4

// screen "TouchTestHelpScreen"
#define TouchTestHelpScreen_ID    10



extern laScheme defaultScheme;
extern laScheme ListWheelScheme;
extern laScheme AlternateGradientScheme;
extern laScheme RadioButtonsOnDarkScheme;
extern laScheme whiteScheme;
extern laScheme BlackBackground;
extern laScheme BackgroundGradientScheme;
extern laScheme MainMenuGradientScheme;
extern laScheme TouchTestScheme;
extern laScheme GradientScheme;
extern laImageWidget* Pic32Logo;
extern laImageWidget* HarmonyLogoWidget;
extern laWidget* PanelWidget;
extern laImageWidget* SplashBar;
extern laImageWidget* SplashBarLogo;
extern laGradientWidget* GradientWidget1;
extern laButtonWidget* ButtonWidget13;
extern laButtonWidget* ButtonWidget14;
extern laButtonWidget* ButtonWidget15;
extern laButtonWidget* ButtonWidget16;
extern laButtonWidget* ButtonWidget17;
extern laButtonWidget* ButtonWidget18;
extern laLabelWidget* LabelWidget1;
extern laLabelWidget* LabelWidget2;
extern laImageWidget* ImageWidget3;
extern laImageWidget* ImageWidget4;
extern laButtonWidget* ButtonWidget19;
extern laButtonWidget* ButtonWidget29;
extern laGradientWidget* GradientWidget3;
extern laButtonWidget* ButtonWidget1;
extern laButtonWidget* ButtonWidget7;
extern laRectangleWidget* RectangleWidget2;
extern laLabelWidget* LabelWidget3;
extern laListWheelWidget* ListWheel2;
extern laListWheelWidget* ListWheel4;
extern laListWheelWidget* ListWheel5;
extern laListWheelWidget* ListWheel1;
extern laLabelWidget* LabelWidget4;
extern laLabelWidget* LabelWidget5;
extern laButtonWidget* ButtonWidget30;
extern laGradientWidget* GradientWidget2;
extern laTouchTestWidget* TouchTestWidget1;
extern laLabelWidget* LabelWidget6;
extern laImageWidget* ImageWidget5;
extern laButtonWidget* ButtonWidget2;
extern laButtonWidget* ButtonWidget3;
extern laLabelWidget* LabelWidget7;
extern laButtonWidget* ButtonWidget31;
extern laGradientWidget* GradientWidget4;
extern laKeyPadWidget* KeyPadWidget1;
extern laTextFieldWidget* TextFieldWidget1;
extern laButtonWidget* ButtonWidget5;
extern laButtonWidget* ButtonWidget6;
extern laLabelWidget* LabelWidget8;
extern laButtonWidget* ButtonWidget32;
extern laGradientWidget* GradientWidget5;
extern laWidget* PanelWidget1;
extern laSliderWidget* SliderWidget1;
extern laLabelWidget* SliderValueLabelWidget;
extern laWidget* PanelWidget2;
extern laImageWidget* ImageWidget1;
extern laImageWidget* ImageWidget2;
extern laButtonWidget* ButtonWidget4;
extern laButtonWidget* ButtonWidget8;
extern laLabelWidget* LabelWidget9;
extern laButtonWidget* ButtonWidget33;
extern laButtonWidget* SliderUpButtonWidget;
extern laButtonWidget* SliderDownButtonWidget;
extern laGradientWidget* GradientWidget6;
extern laImageSequenceWidget* ImageSequenceWidget1;
extern laButtonWidget* ButtonWidget9;
extern laButtonWidget* ButtonWidget11;
extern laLabelWidget* LabelWidget10;
extern laButtonWidget* ButtonWidget10;
extern laButtonWidget* ButtonWidget20;
extern laButtonWidget* ButtonWidget21;
extern laButtonWidget* ButtonWidget22;
extern laImageWidget* SSStatusImageWidget;
extern laGradientWidget* GradientWidget7;
extern laButtonWidget* ButtonWidget12;
extern laWidget* PanelWidget3;
extern laLabelWidget* LabelWidget11;
extern laRadioButtonWidget* RadioButtonChinese;
extern laRadioButtonWidget* RadioButtonEnglish;
extern laButtonWidget* ButtonWidgetChinese;
extern laButtonWidget* ButtonWidgetEnglish;
extern laButtonWidget* ButtonWidget23;
extern laImageWidget* ImageWidget6;
extern laLabelWidget* LabelWidget12;
extern laLabelWidget* LabelWidget13;
extern laLabelWidget* LabelWidget14;
extern laLabelWidget* LabelWidget15;
extern laLabelWidget* LabelWidget16;
extern laLabelWidget* LabelWidget17;
extern laLabelWidget* LabelWidget18;
extern laLabelWidget* LabelWidget19;
extern laLabelWidget* LabelWidget20;
extern laImageWidget* ImageWidget7;
extern laImageWidget* ImageWidget8;
extern laImageWidget* ImageWidget9;
extern laImageWidget* ImageWidget10;
extern laImageWidget* ImageWidget11;
extern laImageWidget* ImageWidget12;
extern laImageWidget* ImageWidget13;
extern laImageWidget* ImageWidget14;
extern laLabelWidget* LabelWidget21;
extern laButtonWidget* ButtonWidget24;
extern laLabelWidget* LabelWidget22;
extern laLabelWidget* LabelWidget24;
extern laImageWidget* ImageWidget16;
extern laImageWidget* ImageWidget17;
extern laButtonWidget* ButtonWidget25;
extern laLabelWidget* LabelWidget25;
extern laLabelWidget* LabelWidget26;
extern laLabelWidget* LabelWidget28;
extern laImageWidget* ImageWidget19;
extern laImageWidget* ImageWidget20;
extern laButtonWidget* ButtonWidget26;
extern laLabelWidget* LabelWidget29;
extern laLabelWidget* LabelWidget30;
extern laLabelWidget* LabelWidget32;
extern laImageWidget* ImageWidget22;
extern laButtonWidget* ButtonWidget27;
extern laImageWidget* ImageWidget23;
extern laLabelWidget* LabelWidget33;
extern laLabelWidget* LabelWidget34;
extern laLabelWidget* LabelWidget35;
extern laLabelWidget* LabelWidget23;
extern laImageWidget* ImageWidget15;
extern laButtonWidget* ButtonWidget28;
extern laImageWidget* ImageWidget18;
extern laLabelWidget* LabelWidget27;
extern laLabelWidget* LabelWidget31;
extern laLabelWidget* LabelWidget36;
extern laLabelWidget* LabelWidget37;
extern laLabelWidget* LabelWidget38;
extern laLabelWidget* LabelWidget39;
extern laImageWidget* ImageWidget21;
extern laImageWidget* ImageWidget24;
extern laImageWidget* ImageWidget25;
extern laImageWidget* ImageWidget26;


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
