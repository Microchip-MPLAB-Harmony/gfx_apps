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

#define LIBARIA_SCREEN_COUNT   2

// reference IDs for generated libaria screens
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
extern laImageWidget* ImageWidget1;
extern laImageWidget* ImageWidget2;
extern laWidget* PanelWidget3;
extern laImageWidget* ImageWidget3;
extern laImageWidget* ImageWidget4;
extern laImageWidget* WeatherImage;
extern laImageWidget* ImageWidget_MCHPLogo;
extern laLabelWidget* LabelWidget_City;
extern laLabelWidget* LabelWidget_Temp;
extern laButtonWidget* ButtonWidget_SwitchCity;
extern laWidget* PanelWidget1;
extern laLineGraphWidget* TempLineGraph;
extern laLabelWidget* LabelWidget_FeelLike;
extern laLabelWidget* LabelWidget_ActualTemp;
extern laLabelWidget* LabelWidget_HundredTemp;
extern laLabelWidget* LabelWidget_LowTemp;
extern laButtonWidget* ButtonWidget_SwitchTemp;
extern laWidget* PanelWidget2;
extern laBarGraphWidget* TempPrecipitaionGraph;
extern laLabelWidget* LabelWidget_Precipitation;
extern laLabelWidget* LabelWidget_Humidity;
extern laLabelWidget* LabelWidget_ZeroPercent;
extern laLabelWidget* LabelWidget_FiftyPercent;
extern laLabelWidget* LabelWidget_HundredPercent;
extern laButtonWidget* ButtonWidget_SwitchHumidity;
extern laWidget* ButtonPanel;
extern laButtonWidget* ButtonWidget_Hourly;
extern laButtonWidget* ButtonWidget_Daily;
extern laButtonWidget* ButtonWidget_City;
extern laLabelWidget* LabelWidget_Press;
extern laWidget* PanelWidget_Hourly;
extern laLabelWidget* LabelWidget_Midnight;
extern laLabelWidget* LabelWidget_ThreeAM;
extern laLabelWidget* LabelWidget_SixAM;
extern laLabelWidget* LabelWidget_NineAM;
extern laLabelWidget* LabelWidget_Noon;
extern laLabelWidget* LabelWidget_ThreePM;
extern laLabelWidget* LabelWidget_SixPM;
extern laWidget* PanelWidget_Daily;
extern laLabelWidget* LabelWidget_Sunday;
extern laLabelWidget* LabelWidget_Monday;
extern laLabelWidget* LabelWidget_Tuesday;
extern laLabelWidget* LabelWidget_Wednesday;
extern laLabelWidget* LabelWidget_Thursday;
extern laLabelWidget* LabelWidget_Friday;
extern laLabelWidget* LabelWidget_Saturday;


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
