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

#define LIBARIA_SCREEN_COUNT   4

// reference IDs for generated libaria screens
// screen "FPSCounters"
#define FPSCounters_ID    1

// screen "FPSImages"
#define FPSImages_ID    3

// screen "FPSMotion"
#define FPSMotion_ID    2

// screen "SplashScreen"
#define SplashScreen_ID    0



extern laScheme LightGreenBackgroundScheme;
extern laScheme LightPinkFillScheme;
extern laScheme LightBlueFillScheme;
extern laScheme LightBlueBackgroundScheme;
extern laScheme PurpleFillScheme;
extern laScheme RedFillScheme;
extern laScheme BlueFillScheme;
extern laScheme defaultScheme;
extern laScheme LightRedBackgroundScheme;
extern laScheme BrownFillScheme;
extern laScheme WhiteBackgroundScheme;
extern laScheme BlackFillScheme;
extern laScheme OrangeFillScheme;
extern laScheme PinkFillScheme;
extern laScheme YellowFillScheme;
extern laScheme WhiteFillScheme;
extern laImageWidget* ImageWidget1;
extern laImageWidget* ImageWidget2;
extern laWidget* PanelWidget;
extern laImageWidget* ImageWidget3;
extern laImageWidget* ImageWidget4;
extern laLabelWidget* Counter1LabelWidget;
extern laWidget* PanelWidget3;
extern laLabelWidget* LabelWidget4;
extern laLabelWidget* RefreshRateLabelWidget;
extern laLabelWidget* RefreshRateCountLabelWidget;
extern laButtonWidget* CounterSizeDownButton;
extern laButtonWidget* CounterSizeUpButton;
extern laLabelWidget* LabelWidget1;
extern laButtonWidget* NextButton;
extern laLabelWidget* StringSizeIdxLabel;
extern laLabelWidget* LabelWidget32;
extern laButtonWidget* FPSButtonCounter;
extern laRectangleWidget* RectMotionWidget10;
extern laRectangleWidget* RectMotionWidget9;
extern laRectangleWidget* RectMotionWidget8;
extern laRectangleWidget* RectMotionWidget7;
extern laRectangleWidget* RectMotionWidget6;
extern laRectangleWidget* RectMotionWidget5;
extern laRectangleWidget* RectMotionWidget4;
extern laRectangleWidget* RectMotionWidget3;
extern laRectangleWidget* RectMotionWidget2;
extern laRectangleWidget* RectMotionWidget1;
extern laWidget* PanelWidget2;
extern laLabelWidget* LabelWidget3;
extern laLabelWidget* LabelWidget5;
extern laLabelWidget* RefreshRateMotionLabelWidget;
extern laLabelWidget* LabelWidget10;
extern laButtonWidget* MotionMenuNextButton;
extern laButtonWidget* MotionMenuPlusButton;
extern laButtonWidget* MotionMenuMinusButton;
extern laLabelWidget* LabelWidget33;
extern laLabelWidget* NumRectCountLabel;
extern laLabelWidget* LabelWidget11;
extern laLabelWidget* SquareSizeLabel;
extern laButtonWidget* RectSizeDownButtonWidget;
extern laButtonWidget* RectSizeUpButtonWidget;
extern laButtonWidget* FPSButtonMotion;
extern laImageWidget* ImageRenderWidget;
extern laWidget* PanelWidget48;
extern laLabelWidget* LabelWidget49;
extern laLabelWidget* LabelWidget51;
extern laLabelWidget* ImageRefRateCountLabel;
extern laLabelWidget* LabelWidget53;
extern laButtonWidget* ImageNextButtonWidget;
extern laButtonWidget* ImageSizeDownButtonWidget;
extern laButtonWidget* ImageSizeUpButtonWidget;
extern laLabelWidget* LabelWidget57;
extern laLabelWidget* ImageSizeLabel;
extern laLabelWidget* LabelWidget;
extern laLabelWidget* ImageTypeLabel;
extern laButtonWidget* ImageTypePrevButtonWidget;
extern laButtonWidget* ImageTypeNextButtonWidget;
extern laButtonWidget* FPSButtonImages;


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
