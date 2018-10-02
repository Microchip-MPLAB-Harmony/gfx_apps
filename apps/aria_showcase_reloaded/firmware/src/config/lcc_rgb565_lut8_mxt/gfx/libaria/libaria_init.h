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

#define LIBARIA_SCREEN_COUNT   8

// reference IDs for generated libaria screens
// screen "ArcWidgetDemo"
#define ArcWidgetDemo_ID    2

// screen "BarGraphDemo"
#define BarGraphDemo_ID    6

// screen "CircularGaugeDemo"
#define CircularGaugeDemo_ID    4

// screen "CircularSliderDemo"
#define CircularSliderDemo_ID    3

// screen "LineGraphScreen"
#define LineGraphScreen_ID    7

// screen "MainMenu"
#define MainMenu_ID    1

// screen "PieChartDemo"
#define PieChartDemo_ID    5

// screen "SplashScreen"
#define SplashScreen_ID    0



extern laScheme DarkBlueBaseScheme;
extern laScheme MainMenuScheme;
extern laScheme BlueForegroundScheme;
extern laScheme BarGraphWidgetScheme;
extern laScheme defaultScheme;
extern laScheme CircularSliderScheme;
extern laScheme LightBlueBaseScheme;
extern laScheme DataSeriesC;
extern laScheme DataSeriesA;
extern laScheme GrayForegroundScheme;
extern laScheme DataSeriesB;
extern laScheme BlackBaseScheme;
extern laScheme RedlineScheme;
extern laScheme DarkGrayForegroundScheme;
extern laScheme LightBlueForegroundScheme;
extern laScheme PieChartDemoScheme;
extern laScheme MidGrayForegroundScheme;
extern laScheme BrightPinkBaseScheme;
extern laScheme CircularSliderDemoScheme;
extern laScheme WhiteForegroundScheme;
extern laScheme BrightPurpleBaseScheme;
extern laScheme BarGraphDemoScheme;
extern laScheme BlackBackgroundScheme;
extern laScheme CircularGaugeScheme;
extern laScheme DarkBlueForeGroundScheme;
extern laScheme BrightYellowBaseScheme;
extern laScheme DataSeriesB_Base;
extern laScheme CircularProgressBarScheme;
extern laScheme WhiteBackgroundScheme;
extern laScheme ArcDemoScheme;
extern laScheme LineGraphDemoScheme;
extern laScheme DataSeriesA_Base;
extern laScheme NewScheme;
extern laScheme BrightOrangeBaseScheme;
extern laScheme CircularGaugeDemoScheme;
extern laScheme WhiteBaseScheme;
extern laScheme BrightBlueBaseScheme;
extern laScheme LineGraphScheme;
extern laScheme defaultPaletteScheme;
extern laImageWidget* ImageWidget1;
extern laImageWidget* ImageWidget2;
extern laWidget* PanelWidget1;
extern laImageWidget* ImageWidget3;
extern laImageWidget* ImageWidget4;
extern laWidget* PanelWidget3;
extern laWidget* PanelWidgetBackQ2;
extern laWidget* PanelWidget12;
extern laWidget* PanelWidget10;
extern laWidget* PanelWidget8;
extern laWidget* PanelWidget7;
extern laWidget* PanelWidget6;
extern laWidget* PanelWidget5;
extern laButtonWidget* ArcWidgetButton;
extern laButtonWidget* CircularSliderButton;
extern laButtonWidget* CircularGaugeButton;
extern laButtonWidget* PieChartButton;
extern laButtonWidget* BarGraphDemoButton;
extern laButtonWidget* LineGraphDemoButton;
extern laLabelWidget* LabelWidget28;
extern laLabelWidget* LabelWidget;
extern laLabelWidget* LabelWidget18;
extern laButtonWidget* StartArcDemoButtonWidget;
extern laArcWidget* ArcWidgetIn;
extern laArcWidget* ArcWidgetInMid;
extern laArcWidget* ArcWidgetMid;
extern laArcWidget* ArcWidgetOut;
extern laArcWidget* ArcWidgetPerimeter;
extern laButtonWidget* NextButton_ArcDemo;
extern laWidget* PanelWidget;
extern laWidget* PanelWidget9;
extern laImageWidget* ImageWidget10;
extern laWidget* ArcDemoMenuPanel;
extern laButtonWidget* HomeButton_ArcDemo;
extern laWidget* ArcHomeButtonBackPanel;
extern laWidget* ArcHomeButtonPanelWidget;
extern laImageWidget* ArcHomeButtonImage;
extern laArcWidget* TouchImage_ArcDemo;
extern laLabelWidget* LabelWidget2;
extern laLabelWidget* LabelWidget31;
extern laLabelWidget* CircularSliderValueLabel;
extern laCircularSliderWidget* CircularProgressBar;
extern laCircularSliderWidget* CircularSliderWidgetControl;
extern laButtonWidget* CircSlider_NextButton;
extern laWidget* PanelWidget17;
extern laWidget* PanelWidget18;
extern laImageWidget* ImageWidget19;
extern laButtonWidget* CircSlider_HomeButton;
extern laWidget* PanelWidget13;
extern laWidget* PanelWidget14;
extern laImageWidget* ImageWidget15;
extern laArcWidget* TouchImage_CircSliderDemo;
extern laLabelWidget* LabelWidget3;
extern laLabelWidget* LabelWidget41;
extern laButtonWidget* CircGauge_NextButton;
extern laWidget* PanelWidget25;
extern laWidget* PanelWidget26;
extern laImageWidget* ImageWidget27;
extern laLabelWidget* GaugeValueLabelWidget;
extern laLabelWidget* MphLabel;
extern laCircularGaugeWidget* CircularGaugeWidget43;
extern laCircularGaugeWidget* SpeedoCircularGaugeWidget;
extern laLabelWidget* LabelWidget49;
extern laLabelWidget* LabelWidget51;
extern laLabelWidget* LabelWidget53;
extern laLabelWidget* LabelWidget50;
extern laLabelWidget* LabelWidget54;
extern laLabelWidget* LabelWidget55;
extern laLabelWidget* LabelWidget56;
extern laLabelWidget* LabelWidget57;
extern laLabelWidget* LabelWidget59;
extern laLabelWidget* LabelWidget60;
extern laLabelWidget* LabelWidget58;
extern laButtonWidget* CircGauge_HomeButton;
extern laWidget* PanelWidget21;
extern laWidget* PanelWidget22;
extern laImageWidget* ImageWidget23;
extern laLabelWidget* LabelWidget1;
extern laButtonWidget* GasButton;
extern laArcWidget* TouchImage_CircGaugeDemo;
extern laLabelWidget* LabelWidget5;
extern laButtonWidget* PieChart_NextButton;
extern laWidget* PanelWidget33;
extern laWidget* PanelWidget34;
extern laImageWidget* ImageWidget35;
extern laLabelWidget* LabelWidget39;
extern laPieChartWidget* PieChartWidget2;
extern laButtonWidget* PieChart_HomeButton;
extern laWidget* PanelWidget29;
extern laWidget* PanelWidget30;
extern laImageWidget* ImageWidget31;
extern laArcWidget* TouchImage_PieChartDemo;
extern laLabelWidget* LabelWidget19;
extern laLabelWidget* LabelWidget4;
extern laBarGraphWidget* BarGraphWidget8;
extern laArcWidget* TouchImage_BarGraphDemo;
extern laLabelWidget* LabelWidget21;
extern laButtonWidget* BarGraphTouchedButton;
extern laButtonWidget* BarGraph_NextButton;
extern laWidget* PanelWidget41;
extern laWidget* PanelWidget42;
extern laImageWidget* ImageWidget43;
extern laButtonWidget* BarGraph_HomeButton;
extern laWidget* PanelWidget37;
extern laWidget* PanelWidget38;
extern laImageWidget* ImageWidget39;
extern laLabelWidget* LabelWidget;
extern laLabelWidget* LabelWidget6;
extern laArcWidget* ArcWidget21;
extern laArcWidget* ArcWidget23;
extern laLabelWidget* LabelWidget11;
extern laLineGraphWidget* LineGraphWidget13;
extern laButtonWidget* LineGraphTouchedButton;
extern laArcWidget* TouchImage_LineGraphDemo;
extern laLabelWidget* LabelWidget23;
extern laButtonWidget* LineGraph_HomeButton;
extern laWidget* PanelWidget46;
extern laWidget* PanelWidget47;
extern laImageWidget* ImageWidget45;
extern laButtonWidget* LineGraph_NextButton;
extern laWidget* PanelWidget54;
extern laWidget* PanelWidget55;
extern laImageWidget* ImageWidget56;
extern laLabelWidget* LabelWidget7;
extern laLabelWidget* LabelWidget16;
extern laArcWidget* ArcWidget24;
extern laArcWidget* ArcWidget25;
extern laButtonWidget* CheckBoxPhantomButton;
extern laCheckBoxWidget* CheckBoxWidget17;


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
