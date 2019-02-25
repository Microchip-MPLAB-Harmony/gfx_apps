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
// screen "ItemScreen"
#define ItemScreen_ID    2

// screen "MainScreen"
#define MainScreen_ID    1

// screen "SplashScreen"
#define SplashScreen_ID    0



extern laScheme TextOrange;
extern laScheme MyScheme;
extern laScheme TempActualScheme;
extern laScheme Blue;
extern laScheme GrayScheme;
extern laScheme WhiteScheme;
extern laScheme TempRealFeelScheme;
extern laScheme TextGrey;
extern laScheme GradientScheme;
extern laScheme Red;
extern laScheme TextGreen;
extern laScheme TempDailyGraphScheme;
extern laScheme Yellow;
extern laScheme Purple;
extern laScheme TempHourlyGraphScheme;
extern laScheme TitleBarScheme;
extern laScheme Green;
extern laScheme TextWhite;
extern laScheme defaultPaletteScheme;
extern laImageWidget* ImageWidget1;
extern laImageWidget* ImageWidget2;
extern laWidget* PanelWidget3;
extern laImageWidget* ImageWidget3;
extern laImageWidget* ImageWidget4;
extern laWidget* PanelItem0;
extern laButtonWidget* ButtonItem0;
extern laLabelWidget* LabelItem0;
extern laWidget* PanelItem1;
extern laButtonWidget* ButtonItem1;
extern laLabelWidget* LabelItem1;
extern laWidget* PanelItem2;
extern laButtonWidget* ButtonItem2;
extern laLabelWidget* LabelItem2;
extern laWidget* PanelItem3;
extern laButtonWidget* ButtonItem3;
extern laLabelWidget* LabelItem3;
extern laWidget* PanelItem4;
extern laButtonWidget* ButtonItem4;
extern laLabelWidget* LabelItem4;
extern laWidget* PanelItem5;
extern laButtonWidget* ButtonItem5;
extern laLabelWidget* LabelItem5;
extern laButtonWidget* ButtonUp;
extern laButtonWidget* ButtonDown;
extern laButtonWidget* ButtonInfo_Main;
extern laButtonWidget* ButtonLanguage_Main;
extern laWidget* PanelLoading_Main;
extern laImageSequenceWidget* ImageLoading_Main;
extern laWidget* PanelBackgound_Item;
extern laButtonWidget* ButtonLanguage_Item;
extern laImageWidget* ImageItem_Item;
extern laButtonWidget* ButtonBuy_Item;
extern laButtonWidget* ButtonMain_Item;
extern laLabelWidget* LabelItemDetail_Item;
extern laWidget* PanelLoading_Item;
extern laImageSequenceWidget* ImageLoading_Item;


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
