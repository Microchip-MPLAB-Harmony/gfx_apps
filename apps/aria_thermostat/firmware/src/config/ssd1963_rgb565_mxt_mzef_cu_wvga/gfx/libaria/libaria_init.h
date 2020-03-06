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



extern laScheme defaultScheme;
extern laScheme redScheme;
extern laScheme whiteScheme;
extern laScheme coolingScheme;
extern laScheme warmingScheme;
extern laScheme blueScheme;
extern laImageWidget* Pic32Logo;
extern laImageWidget* HarmonyLogoWidget;
extern laImageWidget* SplashBar;
extern laImageWidget* SplashBarLogo;
extern laImageWidget* ImageWidget_BackgroundRight;
extern laImageWidget* ImageWidget_BackgroundLeft;
extern laImageWidget* ImageWidget_Backplate;
extern laButtonWidget* ButtonWidget_TouchCatcher;
extern laImageWidget* ImageWidget_FrontTopLeft;
extern laImageWidget* ImageWidget_FrontTopMiddle;
extern laImageWidget* ImageWidget_FrontTopRight;
extern laImageWidget* ImageWidget_FrontMiddleLeft;
extern laImageWidget* ImageWidget_FrontMiddle;
extern laImageWidget* ImageWidget_FrontMiddleRight;
extern laImageWidget* ImageWidget_FrontBottomLeft;
extern laImageWidget* ImageWidget_FrontBottomMiddle;
extern laImageWidget* ImageWidget_FrontBottomRight;
extern laImageSequenceWidget* ImageSequenceWidget_TimeDot;
extern laButtonWidget* ButtonWidget_Microchip;
extern laButtonWidget* ButtonWidget_MHGS;
extern laLabelWidget* LabelWidget_Temp;
extern laLabelWidget* LabelWidget_Action;
extern laArcWidget* ArcWidget_CurrentTemp;
extern laArcWidget* ArcWidget_Indicator;
extern laCircularSliderWidget* CircularSlider_TouchTrack;
extern laWidget* PanelWidget_InfoBackground;
extern laImageWidget* ImageWidget_InfoBackground;
extern laLabelWidget* LabelWidget_InfoTitle;
extern laLabelWidget* LabelWidget_InfoContent;
extern laButtonWidget* ButtonWidget_BackToMain;





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
