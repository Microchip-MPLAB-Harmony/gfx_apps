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

#define LIBARIA_SCREEN_COUNT   5

// reference IDs for generated libaria screens
// screen "SplashScreen"
#define SplashScreen_ID    0

// screen "assetLayout"
#define assetLayout_ID    4

// screen "controllerScreen"
#define controllerScreen_ID    2

// screen "homeScreen"
#define homeScreen_ID    1

// screen "infoScreen"
#define infoScreen_ID    3



extern laScheme controllerTitle;
extern laScheme RedScheme;
extern laScheme helpScheme;
extern laScheme GreenScheme;
extern laScheme SettingsScheme;
extern laScheme infoScreen;
extern laScheme WhiteScheme;
extern laScheme YellowScheme;
extern laScheme clockScheme;
extern laImageWidget* Pic32Logo;
extern laImageWidget* HarmonyLogoWidget;
extern laWidget* PanelWidget;
extern laImageWidget* SplashBar;
extern laImageWidget* SplashBarLogo;
extern laButtonWidget* ButtonWidget1;
extern laLabelWidget* centerClockLabel;
extern laImageWidget* ImageWidget3;
extern laLabelWidget* LabelWidget4;
extern laButtonWidget* StartButton;
extern laLabelWidget* TimeLabel;
extern laButtonWidget* HomeButton;
extern laButtonWidget* FishButtonWidget;
extern laButtonWidget* PizzaButtonWidget;
extern laButtonWidget* VegeButtonWidget;
extern laButtonWidget* StartStopButton;
extern laButtonWidget* DoneButton;
extern laCircularGaugeWidget* FishGaugeWidget;
extern laCircularGaugeWidget* PizzaGaugeWidget;
extern laCircularGaugeWidget* TurkeyGaugeWidget;
extern laImageSequenceWidget* Flames;
extern laLabelWidget* LabelWidget15;
extern laButtonWidget* ButtonWidget16;
extern laLabelWidget* LabelWidget17;
extern laLabelWidget* LabelWidget18;
extern laLabelWidget* LabelWidget19;
extern laLabelWidget* LabelWidget20;
extern laLabelWidget* LabelWidget21;
extern laCircularGaugeWidget* CircularGaugeWidget22;
extern laLabelWidget* LabelWidget23;
extern laImageWidget* ImageWidget24;
extern laImageWidget* ImageWidget25;
extern laImageWidget* ImageWidget26;
extern laImageWidget* ImageWidget27;
extern laImageWidget* ImageWidget28;
extern laImageWidget* ImageWidget29;
extern laImageWidget* ImageWidget30;


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
