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
