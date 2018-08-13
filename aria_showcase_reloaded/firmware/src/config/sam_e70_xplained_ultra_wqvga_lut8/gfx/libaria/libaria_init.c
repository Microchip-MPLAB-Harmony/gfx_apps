/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Implementation File

  File Name:
    libaria_init.c

  Summary:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated implementation from the MPLAB Harmony
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

#include "gfx/libaria/libaria_init.h"

laScheme DarkBlueBaseScheme;
laScheme MainMenuScheme;
laScheme BlueForegroundScheme;
laScheme BarGraphWidgetScheme;
laScheme defaultScheme;
laScheme CircularSliderScheme;
laScheme LightBlueBaseScheme;
laScheme DataSeriesC;
laScheme DataSeriesA;
laScheme GrayForegroundScheme;
laScheme DataSeriesB;
laScheme BlackBaseScheme;
laScheme RedlineScheme;
laScheme DarkGrayForegroundScheme;
laScheme LightBlueForegroundScheme;
laScheme PieChartDemoScheme;
laScheme MidGrayForegroundScheme;
laScheme BrightPinkBaseScheme;
laScheme CircularSliderDemoScheme;
laScheme WhiteForegroundScheme;
laScheme BrightPurpleBaseScheme;
laScheme BarGraphDemoScheme;
laScheme BlackBackgroundScheme;
laScheme CircularGaugeScheme;
laScheme DarkBlueForeGroundScheme;
laScheme BrightYellowBaseScheme;
laScheme DataSeriesB_Base;
laScheme CircularProgressBarScheme;
laScheme WhiteBackgroundScheme;
laScheme ArcDemoScheme;
laScheme LineGraphDemoScheme;
laScheme DataSeriesA_Base;
laScheme NewScheme;
laScheme BrightOrangeBaseScheme;
laScheme CircularGaugeDemoScheme;
laScheme WhiteBaseScheme;
laScheme BrightBlueBaseScheme;
laScheme LineGraphScheme;
laScheme defaultPaletteScheme;
laImageWidget* ImageWidget1;
laImageWidget* ImageWidget2;
laWidget* PanelWidget1;
laImageWidget* ImageWidget3;
laImageWidget* ImageWidget4;
laWidget* PanelWidget3;
laWidget* PanelWidgetBackQ2;
laWidget* PanelWidget12;
laWidget* PanelWidget10;
laWidget* PanelWidget8;
laWidget* PanelWidget7;
laWidget* PanelWidget6;
laWidget* PanelWidget5;
laButtonWidget* ArcWidgetButton;
laButtonWidget* CircularSliderButton;
laButtonWidget* CircularGaugeButton;
laButtonWidget* PieChartButton;
laButtonWidget* BarGraphDemoButton;
laButtonWidget* LineGraphDemoButton;
laLabelWidget* LabelWidget28;
laLabelWidget* LabelWidget;
laLabelWidget* LabelWidget18;
laButtonWidget* StartArcDemoButtonWidget;
laArcWidget* ArcWidgetIn;
laArcWidget* ArcWidgetInMid;
laArcWidget* ArcWidgetMid;
laArcWidget* ArcWidgetOut;
laArcWidget* ArcWidgetPerimeter;
laButtonWidget* NextButton_ArcDemo;
laWidget* PanelWidget;
laWidget* PanelWidget9;
laImageWidget* ImageWidget10;
laWidget* ArcDemoMenuPanel;
laButtonWidget* HomeButton_ArcDemo;
laWidget* ArcHomeButtonBackPanel;
laWidget* ArcHomeButtonPanelWidget;
laImageWidget* ArcHomeButtonImage;
laArcWidget* TouchImage_ArcDemo;
laLabelWidget* LabelWidget2;
laLabelWidget* LabelWidget31;
laLabelWidget* CircularSliderValueLabel;
laCircularSliderWidget* CircularProgressBar;
laCircularSliderWidget* CircularSliderWidgetControl;
laButtonWidget* CircSlider_NextButton;
laWidget* PanelWidget17;
laWidget* PanelWidget18;
laImageWidget* ImageWidget19;
laButtonWidget* CircSlider_HomeButton;
laWidget* PanelWidget13;
laWidget* PanelWidget14;
laImageWidget* ImageWidget15;
laArcWidget* TouchImage_CircSliderDemo;
laLabelWidget* LabelWidget3;
laLabelWidget* LabelWidget41;
laButtonWidget* CircGauge_NextButton;
laWidget* PanelWidget25;
laWidget* PanelWidget26;
laImageWidget* ImageWidget27;
laLabelWidget* GaugeValueLabelWidget;
laLabelWidget* MphLabel;
laCircularGaugeWidget* CircularGaugeWidget43;
laCircularGaugeWidget* SpeedoCircularGaugeWidget;
laLabelWidget* LabelWidget49;
laLabelWidget* LabelWidget51;
laLabelWidget* LabelWidget53;
laLabelWidget* LabelWidget50;
laLabelWidget* LabelWidget54;
laLabelWidget* LabelWidget55;
laLabelWidget* LabelWidget56;
laLabelWidget* LabelWidget57;
laLabelWidget* LabelWidget59;
laLabelWidget* LabelWidget60;
laLabelWidget* LabelWidget58;
laButtonWidget* CircGauge_HomeButton;
laWidget* PanelWidget21;
laWidget* PanelWidget22;
laImageWidget* ImageWidget23;
laLabelWidget* LabelWidget1;
laButtonWidget* GasButton;
laArcWidget* TouchImage_CircGaugeDemo;
laLabelWidget* LabelWidget5;
laButtonWidget* PieChart_NextButton;
laWidget* PanelWidget33;
laWidget* PanelWidget34;
laImageWidget* ImageWidget35;
laLabelWidget* LabelWidget39;
laPieChartWidget* PieChartWidget2;
laButtonWidget* PieChart_HomeButton;
laWidget* PanelWidget29;
laWidget* PanelWidget30;
laImageWidget* ImageWidget31;
laArcWidget* TouchImage_PieChartDemo;
laLabelWidget* LabelWidget19;
laLabelWidget* LabelWidget4;
laBarGraphWidget* BarGraphWidget8;
laArcWidget* TouchImage_BarGraphDemo;
laLabelWidget* LabelWidget21;
laButtonWidget* BarGraphTouchedButton;
laButtonWidget* BarGraph_NextButton;
laWidget* PanelWidget41;
laWidget* PanelWidget42;
laImageWidget* ImageWidget43;
laButtonWidget* BarGraph_HomeButton;
laWidget* PanelWidget37;
laWidget* PanelWidget38;
laImageWidget* ImageWidget39;
laLabelWidget* LabelWidget;
laLabelWidget* LabelWidget6;
laArcWidget* ArcWidget21;
laArcWidget* ArcWidget23;
laLabelWidget* LabelWidget11;
laLineGraphWidget* LineGraphWidget13;
laButtonWidget* LineGraphTouchedButton;
laArcWidget* TouchImage_LineGraphDemo;
laLabelWidget* LabelWidget23;
laButtonWidget* LineGraph_HomeButton;
laWidget* PanelWidget46;
laWidget* PanelWidget47;
laImageWidget* ImageWidget45;
laButtonWidget* LineGraph_NextButton;
laWidget* PanelWidget54;
laWidget* PanelWidget55;
laImageWidget* ImageWidget56;
laLabelWidget* LabelWidget7;
laLabelWidget* LabelWidget16;
laArcWidget* ArcWidget24;
laArcWidget* ArcWidget25;
laButtonWidget* CheckBoxPhantomButton;
laCheckBoxWidget* CheckBoxWidget17;


static void ScreenCreate_SplashScreen(laScreen* screen);
static void ScreenCreate_MainMenu(laScreen* screen);
static void ScreenCreate_ArcWidgetDemo(laScreen* screen);
static void ScreenCreate_CircularSliderDemo(laScreen* screen);
static void ScreenCreate_CircularGaugeDemo(laScreen* screen);
static void ScreenCreate_PieChartDemo(laScreen* screen);
static void ScreenCreate_BarGraphDemo(laScreen* screen);
static void ScreenCreate_LineGraphScreen(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&DarkBlueBaseScheme, GFX_COLOR_MODE_RGB_565);
    DarkBlueBaseScheme.base = 0xFC;
    DarkBlueBaseScheme.highlight = 0xFC;
    DarkBlueBaseScheme.highlightLight = 0xF;
    DarkBlueBaseScheme.shadow = 0x8;
    DarkBlueBaseScheme.shadowDark = 0xED;
    DarkBlueBaseScheme.foreground = 0x0;
    DarkBlueBaseScheme.foregroundInactive = 0xFE;
    DarkBlueBaseScheme.foregroundDisabled = 0x8;
    DarkBlueBaseScheme.background = 0xF;
    DarkBlueBaseScheme.backgroundInactive = 0xFE;
    DarkBlueBaseScheme.backgroundDisabled = 0xFC;
    DarkBlueBaseScheme.text = 0x0;
    DarkBlueBaseScheme.textHighlight = 0xC;
    DarkBlueBaseScheme.textHighlightText = 0xF;
    DarkBlueBaseScheme.textInactive = 0xFE;
    DarkBlueBaseScheme.textDisabled = 0xF6;

    laScheme_Initialize(&MainMenuScheme, GFX_COLOR_MODE_RGB_565);
    MainMenuScheme.base = 0x3C;
    MainMenuScheme.highlight = 0xFC;
    MainMenuScheme.highlightLight = 0xF;
    MainMenuScheme.shadow = 0x8;
    MainMenuScheme.shadowDark = 0xED;
    MainMenuScheme.foreground = 0x0;
    MainMenuScheme.foregroundInactive = 0xFE;
    MainMenuScheme.foregroundDisabled = 0x8;
    MainMenuScheme.background = 0x6D;
    MainMenuScheme.backgroundInactive = 0xFE;
    MainMenuScheme.backgroundDisabled = 0xFC;
    MainMenuScheme.text = 0xF;
    MainMenuScheme.textHighlight = 0xC;
    MainMenuScheme.textHighlightText = 0xF;
    MainMenuScheme.textInactive = 0xFE;
    MainMenuScheme.textDisabled = 0xF6;

    laScheme_Initialize(&BlueForegroundScheme, GFX_COLOR_MODE_RGB_565);
    BlueForegroundScheme.base = 0xFC;
    BlueForegroundScheme.highlight = 0xFC;
    BlueForegroundScheme.highlightLight = 0xF;
    BlueForegroundScheme.shadow = 0x8;
    BlueForegroundScheme.shadowDark = 0xED;
    BlueForegroundScheme.foreground = 0x4A;
    BlueForegroundScheme.foregroundInactive = 0xFE;
    BlueForegroundScheme.foregroundDisabled = 0x8;
    BlueForegroundScheme.background = 0xF;
    BlueForegroundScheme.backgroundInactive = 0xFE;
    BlueForegroundScheme.backgroundDisabled = 0xFC;
    BlueForegroundScheme.text = 0x0;
    BlueForegroundScheme.textHighlight = 0xC;
    BlueForegroundScheme.textHighlightText = 0xF;
    BlueForegroundScheme.textInactive = 0xFE;
    BlueForegroundScheme.textDisabled = 0xF6;

    laScheme_Initialize(&BarGraphWidgetScheme, GFX_COLOR_MODE_RGB_565);
    BarGraphWidgetScheme.base = 0xC2;
    BarGraphWidgetScheme.highlight = 0xFC;
    BarGraphWidgetScheme.highlightLight = 0xF;
    BarGraphWidgetScheme.shadow = 0x8;
    BarGraphWidgetScheme.shadowDark = 0xED;
    BarGraphWidgetScheme.foreground = 0x12;
    BarGraphWidgetScheme.foregroundInactive = 0xFE;
    BarGraphWidgetScheme.foregroundDisabled = 0x8;
    BarGraphWidgetScheme.background = 0xF;
    BarGraphWidgetScheme.backgroundInactive = 0xFE;
    BarGraphWidgetScheme.backgroundDisabled = 0xFC;
    BarGraphWidgetScheme.text = 0x4;
    BarGraphWidgetScheme.textHighlight = 0xC;
    BarGraphWidgetScheme.textHighlightText = 0xF;
    BarGraphWidgetScheme.textInactive = 0xFE;
    BarGraphWidgetScheme.textDisabled = 0xF6;

    laScheme_Initialize(&defaultScheme, GFX_COLOR_MODE_RGB_565);
    defaultScheme.base = 0xFC;
    defaultScheme.highlight = 0xFC;
    defaultScheme.highlightLight = 0xF;
    defaultScheme.shadow = 0x8;
    defaultScheme.shadowDark = 0xED;
    defaultScheme.foreground = 0x0;
    defaultScheme.foregroundInactive = 0xFE;
    defaultScheme.foregroundDisabled = 0x8;
    defaultScheme.background = 0xF;
    defaultScheme.backgroundInactive = 0xFE;
    defaultScheme.backgroundDisabled = 0xFC;
    defaultScheme.text = 0x0;
    defaultScheme.textHighlight = 0xC;
    defaultScheme.textHighlightText = 0xF;
    defaultScheme.textInactive = 0xFE;
    defaultScheme.textDisabled = 0xF6;

    laScheme_Initialize(&CircularSliderScheme, GFX_COLOR_MODE_RGB_565);
    CircularSliderScheme.base = 0x5D;
    CircularSliderScheme.highlight = 0xFC;
    CircularSliderScheme.highlightLight = 0xF;
    CircularSliderScheme.shadow = 0x8;
    CircularSliderScheme.shadowDark = 0xED;
    CircularSliderScheme.foreground = 0xCF;
    CircularSliderScheme.foregroundInactive = 0xDE;
    CircularSliderScheme.foregroundDisabled = 0x8;
    CircularSliderScheme.background = 0xF;
    CircularSliderScheme.backgroundInactive = 0xFE;
    CircularSliderScheme.backgroundDisabled = 0xFC;
    CircularSliderScheme.text = 0x0;
    CircularSliderScheme.textHighlight = 0xC;
    CircularSliderScheme.textHighlightText = 0xF;
    CircularSliderScheme.textInactive = 0xFE;
    CircularSliderScheme.textDisabled = 0xF6;

    laScheme_Initialize(&LightBlueBaseScheme, GFX_COLOR_MODE_RGB_565);
    LightBlueBaseScheme.base = 0xFC;
    LightBlueBaseScheme.highlight = 0xFC;
    LightBlueBaseScheme.highlightLight = 0xF;
    LightBlueBaseScheme.shadow = 0x8;
    LightBlueBaseScheme.shadowDark = 0xED;
    LightBlueBaseScheme.foreground = 0x0;
    LightBlueBaseScheme.foregroundInactive = 0xFE;
    LightBlueBaseScheme.foregroundDisabled = 0x8;
    LightBlueBaseScheme.background = 0xF;
    LightBlueBaseScheme.backgroundInactive = 0xFE;
    LightBlueBaseScheme.backgroundDisabled = 0xFC;
    LightBlueBaseScheme.text = 0x0;
    LightBlueBaseScheme.textHighlight = 0xC;
    LightBlueBaseScheme.textHighlightText = 0xF;
    LightBlueBaseScheme.textInactive = 0xFE;
    LightBlueBaseScheme.textDisabled = 0xF6;

    laScheme_Initialize(&DataSeriesC, GFX_COLOR_MODE_RGB_565);
    DataSeriesC.base = 0x9C;
    DataSeriesC.highlight = 0xFC;
    DataSeriesC.highlightLight = 0xF;
    DataSeriesC.shadow = 0x8;
    DataSeriesC.shadowDark = 0xED;
    DataSeriesC.foreground = 0x2;
    DataSeriesC.foregroundInactive = 0xFE;
    DataSeriesC.foregroundDisabled = 0x8;
    DataSeriesC.background = 0xF;
    DataSeriesC.backgroundInactive = 0xFE;
    DataSeriesC.backgroundDisabled = 0xFC;
    DataSeriesC.text = 0x0;
    DataSeriesC.textHighlight = 0xC;
    DataSeriesC.textHighlightText = 0xF;
    DataSeriesC.textInactive = 0xFE;
    DataSeriesC.textDisabled = 0xF6;

    laScheme_Initialize(&DataSeriesA, GFX_COLOR_MODE_RGB_565);
    DataSeriesA.base = 0xD1;
    DataSeriesA.highlight = 0xFC;
    DataSeriesA.highlightLight = 0xF;
    DataSeriesA.shadow = 0x8;
    DataSeriesA.shadowDark = 0xED;
    DataSeriesA.foreground = 0x1;
    DataSeriesA.foregroundInactive = 0xFE;
    DataSeriesA.foregroundDisabled = 0x8;
    DataSeriesA.background = 0xF;
    DataSeriesA.backgroundInactive = 0xFE;
    DataSeriesA.backgroundDisabled = 0xFC;
    DataSeriesA.text = 0x0;
    DataSeriesA.textHighlight = 0xC;
    DataSeriesA.textHighlightText = 0xF;
    DataSeriesA.textInactive = 0xFE;
    DataSeriesA.textDisabled = 0xF6;

    laScheme_Initialize(&GrayForegroundScheme, GFX_COLOR_MODE_RGB_565);
    GrayForegroundScheme.base = 0xFC;
    GrayForegroundScheme.highlight = 0xFC;
    GrayForegroundScheme.highlightLight = 0xF;
    GrayForegroundScheme.shadow = 0x8;
    GrayForegroundScheme.shadowDark = 0xED;
    GrayForegroundScheme.foreground = 0xFA;
    GrayForegroundScheme.foregroundInactive = 0xFE;
    GrayForegroundScheme.foregroundDisabled = 0x8;
    GrayForegroundScheme.background = 0xF;
    GrayForegroundScheme.backgroundInactive = 0xFE;
    GrayForegroundScheme.backgroundDisabled = 0xFC;
    GrayForegroundScheme.text = 0x0;
    GrayForegroundScheme.textHighlight = 0xC;
    GrayForegroundScheme.textHighlightText = 0xF;
    GrayForegroundScheme.textInactive = 0xFE;
    GrayForegroundScheme.textDisabled = 0xF6;

    laScheme_Initialize(&DataSeriesB, GFX_COLOR_MODE_RGB_565);
    DataSeriesB.base = 0x92;
    DataSeriesB.highlight = 0xFC;
    DataSeriesB.highlightLight = 0xF;
    DataSeriesB.shadow = 0x8;
    DataSeriesB.shadowDark = 0xED;
    DataSeriesB.foreground = 0x4;
    DataSeriesB.foregroundInactive = 0xFE;
    DataSeriesB.foregroundDisabled = 0x8;
    DataSeriesB.background = 0xF;
    DataSeriesB.backgroundInactive = 0xFE;
    DataSeriesB.backgroundDisabled = 0xFC;
    DataSeriesB.text = 0x0;
    DataSeriesB.textHighlight = 0xC;
    DataSeriesB.textHighlightText = 0xF;
    DataSeriesB.textInactive = 0xFE;
    DataSeriesB.textDisabled = 0xF6;

    laScheme_Initialize(&BlackBaseScheme, GFX_COLOR_MODE_RGB_565);
    BlackBaseScheme.base = 0x0;
    BlackBaseScheme.highlight = 0xFC;
    BlackBaseScheme.highlightLight = 0xF;
    BlackBaseScheme.shadow = 0x8;
    BlackBaseScheme.shadowDark = 0xED;
    BlackBaseScheme.foreground = 0x0;
    BlackBaseScheme.foregroundInactive = 0xFE;
    BlackBaseScheme.foregroundDisabled = 0x8;
    BlackBaseScheme.background = 0xF;
    BlackBaseScheme.backgroundInactive = 0xFE;
    BlackBaseScheme.backgroundDisabled = 0xFC;
    BlackBaseScheme.text = 0x0;
    BlackBaseScheme.textHighlight = 0xC;
    BlackBaseScheme.textHighlightText = 0xF;
    BlackBaseScheme.textInactive = 0xFE;
    BlackBaseScheme.textDisabled = 0xF6;

    laScheme_Initialize(&RedlineScheme, GFX_COLOR_MODE_RGB_565);
    RedlineScheme.base = 0xFC;
    RedlineScheme.highlight = 0xFC;
    RedlineScheme.highlightLight = 0xF;
    RedlineScheme.shadow = 0x8;
    RedlineScheme.shadowDark = 0xED;
    RedlineScheme.foreground = 0x81;
    RedlineScheme.foregroundInactive = 0xFE;
    RedlineScheme.foregroundDisabled = 0x8;
    RedlineScheme.background = 0xF;
    RedlineScheme.backgroundInactive = 0xFE;
    RedlineScheme.backgroundDisabled = 0xFC;
    RedlineScheme.text = 0x0;
    RedlineScheme.textHighlight = 0xC;
    RedlineScheme.textHighlightText = 0xF;
    RedlineScheme.textInactive = 0xFE;
    RedlineScheme.textDisabled = 0xF6;

    laScheme_Initialize(&DarkGrayForegroundScheme, GFX_COLOR_MODE_RGB_565);
    DarkGrayForegroundScheme.base = 0xFC;
    DarkGrayForegroundScheme.highlight = 0xFC;
    DarkGrayForegroundScheme.highlightLight = 0xF;
    DarkGrayForegroundScheme.shadow = 0x8;
    DarkGrayForegroundScheme.shadowDark = 0xED;
    DarkGrayForegroundScheme.foreground = 0xEF;
    DarkGrayForegroundScheme.foregroundInactive = 0xFE;
    DarkGrayForegroundScheme.foregroundDisabled = 0x8;
    DarkGrayForegroundScheme.background = 0xF;
    DarkGrayForegroundScheme.backgroundInactive = 0xFE;
    DarkGrayForegroundScheme.backgroundDisabled = 0xFC;
    DarkGrayForegroundScheme.text = 0x0;
    DarkGrayForegroundScheme.textHighlight = 0xC;
    DarkGrayForegroundScheme.textHighlightText = 0xF;
    DarkGrayForegroundScheme.textInactive = 0xFE;
    DarkGrayForegroundScheme.textDisabled = 0xF6;

    laScheme_Initialize(&LightBlueForegroundScheme, GFX_COLOR_MODE_RGB_565);
    LightBlueForegroundScheme.base = 0xFC;
    LightBlueForegroundScheme.highlight = 0xFC;
    LightBlueForegroundScheme.highlightLight = 0xF;
    LightBlueForegroundScheme.shadow = 0x8;
    LightBlueForegroundScheme.shadowDark = 0xED;
    LightBlueForegroundScheme.foreground = 0x98;
    LightBlueForegroundScheme.foregroundInactive = 0xFE;
    LightBlueForegroundScheme.foregroundDisabled = 0x8;
    LightBlueForegroundScheme.background = 0xF;
    LightBlueForegroundScheme.backgroundInactive = 0xFE;
    LightBlueForegroundScheme.backgroundDisabled = 0xFC;
    LightBlueForegroundScheme.text = 0x0;
    LightBlueForegroundScheme.textHighlight = 0xC;
    LightBlueForegroundScheme.textHighlightText = 0xF;
    LightBlueForegroundScheme.textInactive = 0xFE;
    LightBlueForegroundScheme.textDisabled = 0xF6;

    laScheme_Initialize(&PieChartDemoScheme, GFX_COLOR_MODE_RGB_565);
    PieChartDemoScheme.base = 0xD;
    PieChartDemoScheme.highlight = 0xFC;
    PieChartDemoScheme.highlightLight = 0xF;
    PieChartDemoScheme.shadow = 0x8;
    PieChartDemoScheme.shadowDark = 0xED;
    PieChartDemoScheme.foreground = 0x0;
    PieChartDemoScheme.foregroundInactive = 0xFE;
    PieChartDemoScheme.foregroundDisabled = 0x8;
    PieChartDemoScheme.background = 0xDA;
    PieChartDemoScheme.backgroundInactive = 0xFE;
    PieChartDemoScheme.backgroundDisabled = 0xFC;
    PieChartDemoScheme.text = 0x0;
    PieChartDemoScheme.textHighlight = 0xC;
    PieChartDemoScheme.textHighlightText = 0xF;
    PieChartDemoScheme.textInactive = 0xFE;
    PieChartDemoScheme.textDisabled = 0xF6;

    laScheme_Initialize(&MidGrayForegroundScheme, GFX_COLOR_MODE_RGB_565);
    MidGrayForegroundScheme.base = 0xFC;
    MidGrayForegroundScheme.highlight = 0xFC;
    MidGrayForegroundScheme.highlightLight = 0xF;
    MidGrayForegroundScheme.shadow = 0x8;
    MidGrayForegroundScheme.shadowDark = 0xED;
    MidGrayForegroundScheme.foreground = 0xFD;
    MidGrayForegroundScheme.foregroundInactive = 0xFE;
    MidGrayForegroundScheme.foregroundDisabled = 0x8;
    MidGrayForegroundScheme.background = 0xF;
    MidGrayForegroundScheme.backgroundInactive = 0xFE;
    MidGrayForegroundScheme.backgroundDisabled = 0xFC;
    MidGrayForegroundScheme.text = 0x0;
    MidGrayForegroundScheme.textHighlight = 0xC;
    MidGrayForegroundScheme.textHighlightText = 0xF;
    MidGrayForegroundScheme.textInactive = 0xFE;
    MidGrayForegroundScheme.textDisabled = 0xF6;

    laScheme_Initialize(&BrightPinkBaseScheme, GFX_COLOR_MODE_RGB_565);
    BrightPinkBaseScheme.base = 0xD;
    BrightPinkBaseScheme.highlight = 0xFC;
    BrightPinkBaseScheme.highlightLight = 0xF;
    BrightPinkBaseScheme.shadow = 0x8;
    BrightPinkBaseScheme.shadowDark = 0xED;
    BrightPinkBaseScheme.foreground = 0xD;
    BrightPinkBaseScheme.foregroundInactive = 0xFE;
    BrightPinkBaseScheme.foregroundDisabled = 0x8;
    BrightPinkBaseScheme.background = 0xF;
    BrightPinkBaseScheme.backgroundInactive = 0xFE;
    BrightPinkBaseScheme.backgroundDisabled = 0xFC;
    BrightPinkBaseScheme.text = 0x0;
    BrightPinkBaseScheme.textHighlight = 0xC;
    BrightPinkBaseScheme.textHighlightText = 0xF;
    BrightPinkBaseScheme.textInactive = 0xFE;
    BrightPinkBaseScheme.textDisabled = 0xF6;

    laScheme_Initialize(&CircularSliderDemoScheme, GFX_COLOR_MODE_RGB_565);
    CircularSliderDemoScheme.base = 0x68;
    CircularSliderDemoScheme.highlight = 0xFC;
    CircularSliderDemoScheme.highlightLight = 0xF;
    CircularSliderDemoScheme.shadow = 0x8;
    CircularSliderDemoScheme.shadowDark = 0xED;
    CircularSliderDemoScheme.foreground = 0x0;
    CircularSliderDemoScheme.foregroundInactive = 0xFE;
    CircularSliderDemoScheme.foregroundDisabled = 0x8;
    CircularSliderDemoScheme.background = 0x92;
    CircularSliderDemoScheme.backgroundInactive = 0xFE;
    CircularSliderDemoScheme.backgroundDisabled = 0xFC;
    CircularSliderDemoScheme.text = 0x0;
    CircularSliderDemoScheme.textHighlight = 0xC;
    CircularSliderDemoScheme.textHighlightText = 0xF;
    CircularSliderDemoScheme.textInactive = 0xFE;
    CircularSliderDemoScheme.textDisabled = 0xF6;

    laScheme_Initialize(&WhiteForegroundScheme, GFX_COLOR_MODE_RGB_565);
    WhiteForegroundScheme.base = 0x0;
    WhiteForegroundScheme.highlight = 0xFC;
    WhiteForegroundScheme.highlightLight = 0xF;
    WhiteForegroundScheme.shadow = 0x8;
    WhiteForegroundScheme.shadowDark = 0xED;
    WhiteForegroundScheme.foreground = 0xF;
    WhiteForegroundScheme.foregroundInactive = 0xFE;
    WhiteForegroundScheme.foregroundDisabled = 0x8;
    WhiteForegroundScheme.background = 0xF;
    WhiteForegroundScheme.backgroundInactive = 0xFE;
    WhiteForegroundScheme.backgroundDisabled = 0xFC;
    WhiteForegroundScheme.text = 0x0;
    WhiteForegroundScheme.textHighlight = 0xC;
    WhiteForegroundScheme.textHighlightText = 0xF;
    WhiteForegroundScheme.textInactive = 0xFE;
    WhiteForegroundScheme.textDisabled = 0xF6;

    laScheme_Initialize(&BrightPurpleBaseScheme, GFX_COLOR_MODE_RGB_565);
    BrightPurpleBaseScheme.base = 0x86;
    BrightPurpleBaseScheme.highlight = 0xFC;
    BrightPurpleBaseScheme.highlightLight = 0xF;
    BrightPurpleBaseScheme.shadow = 0x8;
    BrightPurpleBaseScheme.shadowDark = 0xED;
    BrightPurpleBaseScheme.foreground = 0x80;
    BrightPurpleBaseScheme.foregroundInactive = 0xFE;
    BrightPurpleBaseScheme.foregroundDisabled = 0x8;
    BrightPurpleBaseScheme.background = 0xF;
    BrightPurpleBaseScheme.backgroundInactive = 0xFE;
    BrightPurpleBaseScheme.backgroundDisabled = 0xFC;
    BrightPurpleBaseScheme.text = 0x0;
    BrightPurpleBaseScheme.textHighlight = 0xC;
    BrightPurpleBaseScheme.textHighlightText = 0xF;
    BrightPurpleBaseScheme.textInactive = 0xFE;
    BrightPurpleBaseScheme.textDisabled = 0xF6;

    laScheme_Initialize(&BarGraphDemoScheme, GFX_COLOR_MODE_RGB_565);
    BarGraphDemoScheme.base = 0xCF;
    BarGraphDemoScheme.highlight = 0xFC;
    BarGraphDemoScheme.highlightLight = 0xF;
    BarGraphDemoScheme.shadow = 0x8;
    BarGraphDemoScheme.shadowDark = 0xED;
    BarGraphDemoScheme.foreground = 0x0;
    BarGraphDemoScheme.foregroundInactive = 0xFE;
    BarGraphDemoScheme.foregroundDisabled = 0x8;
    BarGraphDemoScheme.background = 0xDE;
    BarGraphDemoScheme.backgroundInactive = 0xFE;
    BarGraphDemoScheme.backgroundDisabled = 0xFC;
    BarGraphDemoScheme.text = 0x0;
    BarGraphDemoScheme.textHighlight = 0xC;
    BarGraphDemoScheme.textHighlightText = 0xF;
    BarGraphDemoScheme.textInactive = 0xFE;
    BarGraphDemoScheme.textDisabled = 0xF6;

    laScheme_Initialize(&BlackBackgroundScheme, GFX_COLOR_MODE_RGB_565);
    BlackBackgroundScheme.base = 0xFC;
    BlackBackgroundScheme.highlight = 0xFC;
    BlackBackgroundScheme.highlightLight = 0xF;
    BlackBackgroundScheme.shadow = 0x8;
    BlackBackgroundScheme.shadowDark = 0xED;
    BlackBackgroundScheme.foreground = 0x0;
    BlackBackgroundScheme.foregroundInactive = 0xFE;
    BlackBackgroundScheme.foregroundDisabled = 0x8;
    BlackBackgroundScheme.background = 0x0;
    BlackBackgroundScheme.backgroundInactive = 0xFE;
    BlackBackgroundScheme.backgroundDisabled = 0xFC;
    BlackBackgroundScheme.text = 0x0;
    BlackBackgroundScheme.textHighlight = 0xC;
    BlackBackgroundScheme.textHighlightText = 0xF;
    BlackBackgroundScheme.textInactive = 0xFE;
    BlackBackgroundScheme.textDisabled = 0xF6;

    laScheme_Initialize(&CircularGaugeScheme, GFX_COLOR_MODE_RGB_565);
    CircularGaugeScheme.base = 0xFC;
    CircularGaugeScheme.highlight = 0xFC;
    CircularGaugeScheme.highlightLight = 0xF;
    CircularGaugeScheme.shadow = 0x8;
    CircularGaugeScheme.shadowDark = 0xED;
    CircularGaugeScheme.foreground = 0x7B;
    CircularGaugeScheme.foregroundInactive = 0x0;
    CircularGaugeScheme.foregroundDisabled = 0x8;
    CircularGaugeScheme.background = 0x0;
    CircularGaugeScheme.backgroundInactive = 0xFE;
    CircularGaugeScheme.backgroundDisabled = 0xFC;
    CircularGaugeScheme.text = 0x0;
    CircularGaugeScheme.textHighlight = 0xC;
    CircularGaugeScheme.textHighlightText = 0xF;
    CircularGaugeScheme.textInactive = 0xFE;
    CircularGaugeScheme.textDisabled = 0xF6;

    laScheme_Initialize(&DarkBlueForeGroundScheme, GFX_COLOR_MODE_RGB_565);
    DarkBlueForeGroundScheme.base = 0xFC;
    DarkBlueForeGroundScheme.highlight = 0xFC;
    DarkBlueForeGroundScheme.highlightLight = 0xF;
    DarkBlueForeGroundScheme.shadow = 0x8;
    DarkBlueForeGroundScheme.shadowDark = 0xED;
    DarkBlueForeGroundScheme.foreground = 0x1A;
    DarkBlueForeGroundScheme.foregroundInactive = 0xFE;
    DarkBlueForeGroundScheme.foregroundDisabled = 0x8;
    DarkBlueForeGroundScheme.background = 0xF;
    DarkBlueForeGroundScheme.backgroundInactive = 0xFE;
    DarkBlueForeGroundScheme.backgroundDisabled = 0xFC;
    DarkBlueForeGroundScheme.text = 0x0;
    DarkBlueForeGroundScheme.textHighlight = 0xC;
    DarkBlueForeGroundScheme.textHighlightText = 0xF;
    DarkBlueForeGroundScheme.textInactive = 0xFE;
    DarkBlueForeGroundScheme.textDisabled = 0xF6;

    laScheme_Initialize(&BrightYellowBaseScheme, GFX_COLOR_MODE_RGB_565);
    BrightYellowBaseScheme.base = 0xB;
    BrightYellowBaseScheme.highlight = 0xFC;
    BrightYellowBaseScheme.highlightLight = 0xF;
    BrightYellowBaseScheme.shadow = 0x8;
    BrightYellowBaseScheme.shadowDark = 0xED;
    BrightYellowBaseScheme.foreground = 0xB;
    BrightYellowBaseScheme.foregroundInactive = 0xFE;
    BrightYellowBaseScheme.foregroundDisabled = 0x8;
    BrightYellowBaseScheme.background = 0xF;
    BrightYellowBaseScheme.backgroundInactive = 0xFE;
    BrightYellowBaseScheme.backgroundDisabled = 0xFC;
    BrightYellowBaseScheme.text = 0x0;
    BrightYellowBaseScheme.textHighlight = 0xC;
    BrightYellowBaseScheme.textHighlightText = 0xF;
    BrightYellowBaseScheme.textInactive = 0xFE;
    BrightYellowBaseScheme.textDisabled = 0xF6;

    laScheme_Initialize(&DataSeriesB_Base, GFX_COLOR_MODE_RGB_565);
    DataSeriesB_Base.base = 0xFC;
    DataSeriesB_Base.highlight = 0xFC;
    DataSeriesB_Base.highlightLight = 0xF;
    DataSeriesB_Base.shadow = 0x8;
    DataSeriesB_Base.shadowDark = 0xED;
    DataSeriesB_Base.foreground = 0x0;
    DataSeriesB_Base.foregroundInactive = 0xFE;
    DataSeriesB_Base.foregroundDisabled = 0x8;
    DataSeriesB_Base.background = 0xF;
    DataSeriesB_Base.backgroundInactive = 0xFE;
    DataSeriesB_Base.backgroundDisabled = 0xFC;
    DataSeriesB_Base.text = 0x0;
    DataSeriesB_Base.textHighlight = 0xC;
    DataSeriesB_Base.textHighlightText = 0xF;
    DataSeriesB_Base.textInactive = 0xFE;
    DataSeriesB_Base.textDisabled = 0xF6;

    laScheme_Initialize(&CircularProgressBarScheme, GFX_COLOR_MODE_RGB_565);
    CircularProgressBarScheme.base = 0x6;
    CircularProgressBarScheme.highlight = 0xFC;
    CircularProgressBarScheme.highlightLight = 0xF;
    CircularProgressBarScheme.shadow = 0x8;
    CircularProgressBarScheme.shadowDark = 0xED;
    CircularProgressBarScheme.foreground = 0x24;
    CircularProgressBarScheme.foregroundInactive = 0x9E;
    CircularProgressBarScheme.foregroundDisabled = 0x8;
    CircularProgressBarScheme.background = 0xF;
    CircularProgressBarScheme.backgroundInactive = 0xFE;
    CircularProgressBarScheme.backgroundDisabled = 0xFC;
    CircularProgressBarScheme.text = 0x0;
    CircularProgressBarScheme.textHighlight = 0xC;
    CircularProgressBarScheme.textHighlightText = 0xF;
    CircularProgressBarScheme.textInactive = 0xFE;
    CircularProgressBarScheme.textDisabled = 0xF6;

    laScheme_Initialize(&WhiteBackgroundScheme, GFX_COLOR_MODE_RGB_565);
    WhiteBackgroundScheme.base = 0xF;
    WhiteBackgroundScheme.highlight = 0xFC;
    WhiteBackgroundScheme.highlightLight = 0xF;
    WhiteBackgroundScheme.shadow = 0x8;
    WhiteBackgroundScheme.shadowDark = 0xED;
    WhiteBackgroundScheme.foreground = 0x0;
    WhiteBackgroundScheme.foregroundInactive = 0xFE;
    WhiteBackgroundScheme.foregroundDisabled = 0x8;
    WhiteBackgroundScheme.background = 0xF;
    WhiteBackgroundScheme.backgroundInactive = 0xFE;
    WhiteBackgroundScheme.backgroundDisabled = 0xFC;
    WhiteBackgroundScheme.text = 0x0;
    WhiteBackgroundScheme.textHighlight = 0xC;
    WhiteBackgroundScheme.textHighlightText = 0xF;
    WhiteBackgroundScheme.textInactive = 0xFE;
    WhiteBackgroundScheme.textDisabled = 0xF6;

    laScheme_Initialize(&ArcDemoScheme, GFX_COLOR_MODE_RGB_565);
    ArcDemoScheme.base = 0x21;
    ArcDemoScheme.highlight = 0xFC;
    ArcDemoScheme.highlightLight = 0xF;
    ArcDemoScheme.shadow = 0x8;
    ArcDemoScheme.shadowDark = 0xED;
    ArcDemoScheme.foreground = 0x0;
    ArcDemoScheme.foregroundInactive = 0xFE;
    ArcDemoScheme.foregroundDisabled = 0x8;
    ArcDemoScheme.background = 0x9C;
    ArcDemoScheme.backgroundInactive = 0xFE;
    ArcDemoScheme.backgroundDisabled = 0xFC;
    ArcDemoScheme.text = 0x0;
    ArcDemoScheme.textHighlight = 0xC;
    ArcDemoScheme.textHighlightText = 0xF;
    ArcDemoScheme.textInactive = 0xFE;
    ArcDemoScheme.textDisabled = 0xF6;

    laScheme_Initialize(&LineGraphDemoScheme, GFX_COLOR_MODE_RGB_565);
    LineGraphDemoScheme.base = 0x86;
    LineGraphDemoScheme.highlight = 0xFC;
    LineGraphDemoScheme.highlightLight = 0xF;
    LineGraphDemoScheme.shadow = 0x8;
    LineGraphDemoScheme.shadowDark = 0xED;
    LineGraphDemoScheme.foreground = 0x0;
    LineGraphDemoScheme.foregroundInactive = 0xFE;
    LineGraphDemoScheme.foregroundDisabled = 0x8;
    LineGraphDemoScheme.background = 0xBC;
    LineGraphDemoScheme.backgroundInactive = 0xFE;
    LineGraphDemoScheme.backgroundDisabled = 0xFC;
    LineGraphDemoScheme.text = 0x0;
    LineGraphDemoScheme.textHighlight = 0xC;
    LineGraphDemoScheme.textHighlightText = 0xF;
    LineGraphDemoScheme.textInactive = 0xFE;
    LineGraphDemoScheme.textDisabled = 0xF6;

    laScheme_Initialize(&DataSeriesA_Base, GFX_COLOR_MODE_RGB_565);
    DataSeriesA_Base.base = 0xFC;
    DataSeriesA_Base.highlight = 0xFC;
    DataSeriesA_Base.highlightLight = 0xF;
    DataSeriesA_Base.shadow = 0x8;
    DataSeriesA_Base.shadowDark = 0xED;
    DataSeriesA_Base.foreground = 0x0;
    DataSeriesA_Base.foregroundInactive = 0xFE;
    DataSeriesA_Base.foregroundDisabled = 0x8;
    DataSeriesA_Base.background = 0xF;
    DataSeriesA_Base.backgroundInactive = 0xFE;
    DataSeriesA_Base.backgroundDisabled = 0xFC;
    DataSeriesA_Base.text = 0x0;
    DataSeriesA_Base.textHighlight = 0xC;
    DataSeriesA_Base.textHighlightText = 0xF;
    DataSeriesA_Base.textInactive = 0xFE;
    DataSeriesA_Base.textDisabled = 0xF6;

    laScheme_Initialize(&NewScheme, GFX_COLOR_MODE_RGB_565);
    NewScheme.base = 0xD;
    NewScheme.highlight = 0xFC;
    NewScheme.highlightLight = 0xF;
    NewScheme.shadow = 0x8;
    NewScheme.shadowDark = 0xED;
    NewScheme.foreground = 0xDA;
    NewScheme.foregroundInactive = 0xFE;
    NewScheme.foregroundDisabled = 0x8;
    NewScheme.background = 0xF;
    NewScheme.backgroundInactive = 0xFE;
    NewScheme.backgroundDisabled = 0xFC;
    NewScheme.text = 0x0;
    NewScheme.textHighlight = 0xC;
    NewScheme.textHighlightText = 0xF;
    NewScheme.textInactive = 0xFE;
    NewScheme.textDisabled = 0xF6;

    laScheme_Initialize(&BrightOrangeBaseScheme, GFX_COLOR_MODE_RGB_565);
    BrightOrangeBaseScheme.base = 0xCF;
    BrightOrangeBaseScheme.highlight = 0xFC;
    BrightOrangeBaseScheme.highlightLight = 0xF;
    BrightOrangeBaseScheme.shadow = 0x8;
    BrightOrangeBaseScheme.shadowDark = 0xED;
    BrightOrangeBaseScheme.foreground = 0xCF;
    BrightOrangeBaseScheme.foregroundInactive = 0xFE;
    BrightOrangeBaseScheme.foregroundDisabled = 0x8;
    BrightOrangeBaseScheme.background = 0xF;
    BrightOrangeBaseScheme.backgroundInactive = 0xFE;
    BrightOrangeBaseScheme.backgroundDisabled = 0xFC;
    BrightOrangeBaseScheme.text = 0x0;
    BrightOrangeBaseScheme.textHighlight = 0xC;
    BrightOrangeBaseScheme.textHighlightText = 0xF;
    BrightOrangeBaseScheme.textInactive = 0xFE;
    BrightOrangeBaseScheme.textDisabled = 0xF6;

    laScheme_Initialize(&CircularGaugeDemoScheme, GFX_COLOR_MODE_RGB_565);
    CircularGaugeDemoScheme.base = 0xB;
    CircularGaugeDemoScheme.highlight = 0xFC;
    CircularGaugeDemoScheme.highlightLight = 0xF;
    CircularGaugeDemoScheme.shadow = 0x8;
    CircularGaugeDemoScheme.shadowDark = 0xED;
    CircularGaugeDemoScheme.foreground = 0x0;
    CircularGaugeDemoScheme.foregroundInactive = 0xFE;
    CircularGaugeDemoScheme.foregroundDisabled = 0x8;
    CircularGaugeDemoScheme.background = 0xE4;
    CircularGaugeDemoScheme.backgroundInactive = 0xFE;
    CircularGaugeDemoScheme.backgroundDisabled = 0xFC;
    CircularGaugeDemoScheme.text = 0x0;
    CircularGaugeDemoScheme.textHighlight = 0xC;
    CircularGaugeDemoScheme.textHighlightText = 0xF;
    CircularGaugeDemoScheme.textInactive = 0xFE;
    CircularGaugeDemoScheme.textDisabled = 0xF6;

    laScheme_Initialize(&WhiteBaseScheme, GFX_COLOR_MODE_RGB_565);
    WhiteBaseScheme.base = 0xF;
    WhiteBaseScheme.highlight = 0xFC;
    WhiteBaseScheme.highlightLight = 0xF;
    WhiteBaseScheme.shadow = 0x8;
    WhiteBaseScheme.shadowDark = 0xED;
    WhiteBaseScheme.foreground = 0x0;
    WhiteBaseScheme.foregroundInactive = 0xFE;
    WhiteBaseScheme.foregroundDisabled = 0x8;
    WhiteBaseScheme.background = 0xF;
    WhiteBaseScheme.backgroundInactive = 0xFE;
    WhiteBaseScheme.backgroundDisabled = 0xFC;
    WhiteBaseScheme.text = 0x0;
    WhiteBaseScheme.textHighlight = 0xC;
    WhiteBaseScheme.textHighlightText = 0xF;
    WhiteBaseScheme.textInactive = 0xFE;
    WhiteBaseScheme.textDisabled = 0xF6;

    laScheme_Initialize(&BrightBlueBaseScheme, GFX_COLOR_MODE_RGB_565);
    BrightBlueBaseScheme.base = 0xE;
    BrightBlueBaseScheme.highlight = 0xFC;
    BrightBlueBaseScheme.highlightLight = 0xF;
    BrightBlueBaseScheme.shadow = 0x8;
    BrightBlueBaseScheme.shadowDark = 0xED;
    BrightBlueBaseScheme.foreground = 0xE;
    BrightBlueBaseScheme.foregroundInactive = 0xFE;
    BrightBlueBaseScheme.foregroundDisabled = 0x8;
    BrightBlueBaseScheme.background = 0xF;
    BrightBlueBaseScheme.backgroundInactive = 0xFE;
    BrightBlueBaseScheme.backgroundDisabled = 0xFC;
    BrightBlueBaseScheme.text = 0x0;
    BrightBlueBaseScheme.textHighlight = 0xC;
    BrightBlueBaseScheme.textHighlightText = 0xF;
    BrightBlueBaseScheme.textInactive = 0xFE;
    BrightBlueBaseScheme.textDisabled = 0xF6;

    laScheme_Initialize(&LineGraphScheme, GFX_COLOR_MODE_RGB_565);
    LineGraphScheme.base = 0xB5;
    LineGraphScheme.highlight = 0xFC;
    LineGraphScheme.highlightLight = 0xF;
    LineGraphScheme.shadow = 0x8;
    LineGraphScheme.shadowDark = 0xED;
    LineGraphScheme.foreground = 0x1;
    LineGraphScheme.foregroundInactive = 0xFE;
    LineGraphScheme.foregroundDisabled = 0x8;
    LineGraphScheme.background = 0xF;
    LineGraphScheme.backgroundInactive = 0xFE;
    LineGraphScheme.backgroundDisabled = 0xFC;
    LineGraphScheme.text = 0x33;
    LineGraphScheme.textHighlight = 0xC;
    LineGraphScheme.textHighlightText = 0xF;
    LineGraphScheme.textInactive = 0xFE;
    LineGraphScheme.textDisabled = 0xF6;

    laScheme_Initialize(&defaultPaletteScheme, GFX_COLOR_MODE_RGB_565);
    defaultPaletteScheme.base = 0xFC;
    defaultPaletteScheme.highlight = 0xFC;
    defaultPaletteScheme.highlightLight = 0xF;
    defaultPaletteScheme.shadow = 0x8;
    defaultPaletteScheme.shadowDark = 0xED;
    defaultPaletteScheme.foreground = 0x0;
    defaultPaletteScheme.foregroundInactive = 0xFE;
    defaultPaletteScheme.foregroundDisabled = 0x8;
    defaultPaletteScheme.background = 0xF;
    defaultPaletteScheme.backgroundInactive = 0xFE;
    defaultPaletteScheme.backgroundDisabled = 0xFC;
    defaultPaletteScheme.text = 0x0;
    defaultPaletteScheme.textHighlight = 0xC;
    defaultPaletteScheme.textHighlightText = 0xF;
    defaultPaletteScheme.textInactive = 0xFE;
    defaultPaletteScheme.textDisabled = 0xF6;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    GFX_Set(GFXF_GLOBAL_PALETTE, globalColorPalette);
    laContext_SetStringTable(&stringTable);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SplashScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_MainMenu);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_ArcWidgetDemo);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_CircularSliderDemo);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_CircularGaugeDemo);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_PieChartDemo);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_BarGraphDemo);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_LineGraphScreen);
    laContext_AddScreen(screen);

    laContext_SetActiveScreen(0);

	return 0;
}

static void ScreenCreate_SplashScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &defaultScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget1 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget1, 120, 40);
    laWidget_SetSize((laWidget*)ImageWidget1, 240, 139);
    laWidget_SetScheme((laWidget*)ImageWidget1, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget1, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget1, &PIC32Logo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget1);

    ImageWidget2 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget2, 120, 40);
    laWidget_SetSize((laWidget*)ImageWidget2, 240, 139);
    laWidget_SetVisible((laWidget*)ImageWidget2, LA_FALSE);
    laWidget_SetScheme((laWidget*)ImageWidget2, &WhiteBackgroundScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageWidget2, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget2, &HarmonyLogo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget2);

    PanelWidget1 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget1, 0, 207);
    laWidget_SetSize((laWidget*)PanelWidget1, 480, 65);
    laWidget_SetScheme((laWidget*)PanelWidget1, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PanelWidget1, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget1);

    ImageWidget3 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget3, 480, 0);
    laWidget_SetSize((laWidget*)ImageWidget3, 480, 65);
    laWidget_SetScheme((laWidget*)ImageWidget3, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget3, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget3, &Bar);
    laWidget_AddChild((laWidget*)PanelWidget1, (laWidget*)ImageWidget3);

    ImageWidget4 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget4, 17, 23);
    laWidget_SetSize((laWidget*)ImageWidget4, 144, 39);
    laWidget_SetVisible((laWidget*)ImageWidget4, LA_FALSE);
    laWidget_SetScheme((laWidget*)ImageWidget4, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget4, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget4, &MicrochipLogo);
    laWidget_AddChild((laWidget*)PanelWidget1, (laWidget*)ImageWidget4);

}

static void ScreenCreate_MainMenu(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &MainMenuScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    PanelWidget3 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget3, 240, 136);
    laWidget_SetSize((laWidget*)PanelWidget3, 240, 136);
    laWidget_SetScheme((laWidget*)PanelWidget3, &MainMenuScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget3, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget3, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget3);

    PanelWidgetBackQ2 = laWidget_New();
    laWidget_SetSize((laWidget*)PanelWidgetBackQ2, 240, 136);
    laWidget_SetScheme((laWidget*)PanelWidgetBackQ2, &MainMenuScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidgetBackQ2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidgetBackQ2, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidgetBackQ2);

    PanelWidget12 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget12, 135, 154);
    laWidget_SetSize((laWidget*)PanelWidget12, 100, 100);
    laWidget_SetScheme((laWidget*)PanelWidget12, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget12, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget12, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget12);

    PanelWidget10 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget10, 24, 154);
    laWidget_SetSize((laWidget*)PanelWidget10, 100, 100);
    laWidget_SetScheme((laWidget*)PanelWidget10, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget10, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget10, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget10);

    PanelWidget8 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget8, 365, 24);
    laWidget_SetSize((laWidget*)PanelWidget8, 100, 100);
    laWidget_SetScheme((laWidget*)PanelWidget8, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget8, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget8, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget8);

    PanelWidget7 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget7, 254, 25);
    laWidget_SetSize((laWidget*)PanelWidget7, 100, 100);
    laWidget_SetScheme((laWidget*)PanelWidget7, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget7, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget7, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget7);

    PanelWidget6 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget6, 135, 24);
    laWidget_SetSize((laWidget*)PanelWidget6, 100, 100);
    laWidget_SetScheme((laWidget*)PanelWidget6, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget6, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget6, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget6);

    PanelWidget5 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget5, 24, 24);
    laWidget_SetSize((laWidget*)PanelWidget5, 100, 100);
    laWidget_SetScheme((laWidget*)PanelWidget5, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget5, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget5, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, PanelWidget5);

    ArcWidgetButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)ArcWidgetButton, 20, 20);
    laWidget_SetSize((laWidget*)ArcWidgetButton, 100, 100);
    laWidget_SetScheme((laWidget*)ArcWidgetButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ArcWidgetButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ArcWidgetButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(ArcWidgetButton, &ArcDemoIconFilled100x100);
    laButtonWidget_SetReleasedImage(ArcWidgetButton, &ArcDemoIconFilled100x100);
    laButtonWidget_SetReleasedEventCallback(ArcWidgetButton, &ArcWidgetButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)ArcWidgetButton);

    CircularSliderButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)CircularSliderButton, 131, 20);
    laWidget_SetSize((laWidget*)CircularSliderButton, 100, 100);
    laWidget_SetScheme((laWidget*)CircularSliderButton, &CircularSliderDemoScheme);
    laWidget_SetBackgroundType((laWidget*)CircularSliderButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CircularSliderButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(CircularSliderButton, &CircularSliderFill100x100);
    laButtonWidget_SetReleasedImage(CircularSliderButton, &CircularSliderFill100x100);
    laButtonWidget_SetReleasedEventCallback(CircularSliderButton, &CircularSliderButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)CircularSliderButton);

    CircularGaugeButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)CircularGaugeButton, 250, 20);
    laWidget_SetSize((laWidget*)CircularGaugeButton, 100, 100);
    laWidget_SetScheme((laWidget*)CircularGaugeButton, &CircularGaugeDemoScheme);
    laWidget_SetBackgroundType((laWidget*)CircularGaugeButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CircularGaugeButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(CircularGaugeButton, &CircularGaugeFilled100x100);
    laButtonWidget_SetReleasedImage(CircularGaugeButton, &CircularGaugeFilled100x100);
    laButtonWidget_SetReleasedEventCallback(CircularGaugeButton, &CircularGaugeButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)CircularGaugeButton);

    PieChartButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)PieChartButton, 361, 20);
    laWidget_SetSize((laWidget*)PieChartButton, 100, 100);
    laWidget_SetScheme((laWidget*)PieChartButton, &PieChartDemoScheme);
    laWidget_SetBackgroundType((laWidget*)PieChartButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PieChartButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(PieChartButton, &PieChartFilled100x100);
    laButtonWidget_SetReleasedImage(PieChartButton, &PieChartFilled100x100);
    laButtonWidget_SetReleasedEventCallback(PieChartButton, &PieChartButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)PieChartButton);

    BarGraphDemoButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)BarGraphDemoButton, 20, 150);
    laWidget_SetSize((laWidget*)BarGraphDemoButton, 100, 100);
    laWidget_SetScheme((laWidget*)BarGraphDemoButton, &BarGraphDemoScheme);
    laWidget_SetBackgroundType((laWidget*)BarGraphDemoButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)BarGraphDemoButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(BarGraphDemoButton, &BarGraphFilled100x100);
    laButtonWidget_SetReleasedImage(BarGraphDemoButton, &BarGraphFilled100x100);
    laButtonWidget_SetReleasedEventCallback(BarGraphDemoButton, &BarGraphDemoButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)BarGraphDemoButton);

    LineGraphDemoButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)LineGraphDemoButton, 131, 150);
    laWidget_SetSize((laWidget*)LineGraphDemoButton, 100, 100);
    laWidget_SetScheme((laWidget*)LineGraphDemoButton, &LineGraphDemoScheme);
    laWidget_SetBackgroundType((laWidget*)LineGraphDemoButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LineGraphDemoButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedImage(LineGraphDemoButton, &LineGraphFilled100x100);
    laButtonWidget_SetReleasedImage(LineGraphDemoButton, &LineGraphFilled100x100);
    laButtonWidget_SetReleasedEventCallback(LineGraphDemoButton, &LineGraphDemoButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)LineGraphDemoButton);

    LabelWidget28 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget28, 339, 188);
    laWidget_SetSize((laWidget*)LabelWidget28, 130, 73);
    laWidget_SetScheme((laWidget*)LabelWidget28, &MainMenuScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget28, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget28, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget28, laString_CreateFromID(string_AriaShowcase));
    laLabelWidget_SetHAlignment(LabelWidget28, LA_HALIGN_RIGHT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget28);

    LabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget, 368, 226);
    laWidget_SetSize((laWidget*)LabelWidget, 100, 25);
    laWidget_SetScheme((laWidget*)LabelWidget, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget, laString_CreateFromID(string_Reloaded));
    laLabelWidget_SetHAlignment(LabelWidget, LA_HALIGN_LEFT);
    laLabelWidget_SetVAlignment(LabelWidget, LA_VALIGN_TOP);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget);

}

static void ScreenCreate_ArcWidgetDemo(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &ArcDemoScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    LabelWidget18 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget18, 112, 15);
    laWidget_SetSize((laWidget*)LabelWidget18, 256, 25);
    laWidget_SetScheme((laWidget*)LabelWidget18, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget18, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget18, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget18, laString_CreateFromID(string_ArcPrimitiveDemo));
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget18);

    StartArcDemoButtonWidget = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)StartArcDemoButtonWidget, 0, 50);
    laWidget_SetSize((laWidget*)StartArcDemoButtonWidget, 479, 220);
    laWidget_SetScheme((laWidget*)StartArcDemoButtonWidget, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)StartArcDemoButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)StartArcDemoButtonWidget, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedEventCallback(StartArcDemoButtonWidget, &StartArcDemoButtonWidget_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(StartArcDemoButtonWidget, &StartArcDemoButtonWidget_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)StartArcDemoButtonWidget);

    ArcWidgetIn = laArcWidget_New();
    laWidget_SetPosition((laWidget*)ArcWidgetIn, 170, 100);
    laWidget_SetSize((laWidget*)ArcWidgetIn, 120, 120);
    laWidget_SetEnabled((laWidget*)ArcWidgetIn, LA_FALSE);
    laWidget_SetScheme((laWidget*)ArcWidgetIn, &GrayForegroundScheme);
    laWidget_SetBackgroundType((laWidget*)ArcWidgetIn, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ArcWidgetIn, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(ArcWidgetIn, 60);
    laArcWidget_SetStartAngle(ArcWidgetIn, 225);
    laArcWidget_SetCenterAngle(ArcWidgetIn, 270);
    laArcWidget_SetThickness(ArcWidgetIn, 5);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ArcWidgetIn);

    ArcWidgetInMid = laArcWidget_New();
    laWidget_SetPosition((laWidget*)ArcWidgetInMid, 160, 90);
    laWidget_SetSize((laWidget*)ArcWidgetInMid, 140, 140);
    laWidget_SetEnabled((laWidget*)ArcWidgetInMid, LA_FALSE);
    laWidget_SetScheme((laWidget*)ArcWidgetInMid, &BrightOrangeBaseScheme);
    laWidget_SetBackgroundType((laWidget*)ArcWidgetInMid, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ArcWidgetInMid, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(ArcWidgetInMid, 65);
    laArcWidget_SetStartAngle(ArcWidgetInMid, 145);
    laArcWidget_SetCenterAngle(ArcWidgetInMid, 70);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ArcWidgetInMid);

    ArcWidgetMid = laArcWidget_New();
    laWidget_SetPosition((laWidget*)ArcWidgetMid, 140, 70);
    laWidget_SetSize((laWidget*)ArcWidgetMid, 180, 180);
    laWidget_SetEnabled((laWidget*)ArcWidgetMid, LA_FALSE);
    laWidget_SetScheme((laWidget*)ArcWidgetMid, &MidGrayForegroundScheme);
    laWidget_SetBackgroundType((laWidget*)ArcWidgetMid, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ArcWidgetMid, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(ArcWidgetMid, 85);
    laArcWidget_SetStartAngle(ArcWidgetMid, 45);
    laArcWidget_SetCenterAngle(ArcWidgetMid, 270);
    laArcWidget_SetThickness(ArcWidgetMid, 3);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ArcWidgetMid);

    ArcWidgetOut = laArcWidget_New();
    laWidget_SetPosition((laWidget*)ArcWidgetOut, 130, 60);
    laWidget_SetSize((laWidget*)ArcWidgetOut, 200, 200);
    laWidget_SetEnabled((laWidget*)ArcWidgetOut, LA_FALSE);
    laWidget_SetScheme((laWidget*)ArcWidgetOut, &BrightOrangeBaseScheme);
    laWidget_SetBackgroundType((laWidget*)ArcWidgetOut, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ArcWidgetOut, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(ArcWidgetOut, 92);
    laArcWidget_SetStartAngle(ArcWidgetOut, 45);
    laArcWidget_SetCenterAngle(ArcWidgetOut, -90);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ArcWidgetOut);

    ArcWidgetPerimeter = laArcWidget_New();
    laWidget_SetPosition((laWidget*)ArcWidgetPerimeter, 120, 50);
    laWidget_SetSize((laWidget*)ArcWidgetPerimeter, 220, 220);
    laWidget_SetEnabled((laWidget*)ArcWidgetPerimeter, LA_FALSE);
    laWidget_SetScheme((laWidget*)ArcWidgetPerimeter, &BlueForegroundScheme);
    laWidget_SetBackgroundType((laWidget*)ArcWidgetPerimeter, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ArcWidgetPerimeter, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(ArcWidgetPerimeter, 105);
    laArcWidget_SetStartAngle(ArcWidgetPerimeter, 90);
    laArcWidget_SetCenterAngle(ArcWidgetPerimeter, 360);
    laArcWidget_SetThickness(ArcWidgetPerimeter, 5);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ArcWidgetPerimeter);

    NextButton_ArcDemo = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)NextButton_ArcDemo, 420, 0);
    laWidget_SetSize((laWidget*)NextButton_ArcDemo, 60, 60);
    laWidget_SetScheme((laWidget*)NextButton_ArcDemo, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)NextButton_ArcDemo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)NextButton_ArcDemo, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(NextButton_ArcDemo, &NextButton_ArcDemo_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)NextButton_ArcDemo);

    PanelWidget = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget, 15, 19);
    laWidget_SetSize((laWidget*)PanelWidget, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)NextButton_ArcDemo, PanelWidget);

    PanelWidget9 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget9, 19, 15);
    laWidget_SetSize((laWidget*)PanelWidget9, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget9, &ArcDemoScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget9, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget9, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)NextButton_ArcDemo, PanelWidget9);

    ImageWidget10 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget10, 19, 15);
    laWidget_SetSize((laWidget*)ImageWidget10, 30, 30);
    laWidget_SetScheme((laWidget*)ImageWidget10, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget10, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget10, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget10, &ArcDemoNextButtonFilled30x30);
    laWidget_AddChild((laWidget*)NextButton_ArcDemo, (laWidget*)ImageWidget10);

    ArcDemoMenuPanel = laWidget_New();
    laWidget_SetPosition((laWidget*)ArcDemoMenuPanel, 0, 61);
    laWidget_SetSize((laWidget*)ArcDemoMenuPanel, 58, 210);
    laWidget_SetScheme((laWidget*)ArcDemoMenuPanel, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ArcDemoMenuPanel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ArcDemoMenuPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, ArcDemoMenuPanel);

    HomeButton_ArcDemo = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)HomeButton_ArcDemo, 1, 0);
    laWidget_SetSize((laWidget*)HomeButton_ArcDemo, 60, 60);
    laWidget_SetScheme((laWidget*)HomeButton_ArcDemo, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)HomeButton_ArcDemo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)HomeButton_ArcDemo, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetHAlignment(HomeButton_ArcDemo, LA_HALIGN_LEFT);
    laButtonWidget_SetVAlignment(HomeButton_ArcDemo, LA_VALIGN_TOP);
    laButtonWidget_SetPressedEventCallback(HomeButton_ArcDemo, &HomeButton_ArcDemo_PressedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)HomeButton_ArcDemo);

    ArcHomeButtonBackPanel = laWidget_New();
    laWidget_SetPosition((laWidget*)ArcHomeButtonBackPanel, 19, 19);
    laWidget_SetSize((laWidget*)ArcHomeButtonBackPanel, 30, 30);
    laWidget_SetScheme((laWidget*)ArcHomeButtonBackPanel, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)ArcHomeButtonBackPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ArcHomeButtonBackPanel, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)HomeButton_ArcDemo, ArcHomeButtonBackPanel);

    ArcHomeButtonPanelWidget = laWidget_New();
    laWidget_SetPosition((laWidget*)ArcHomeButtonPanelWidget, 15, 15);
    laWidget_SetSize((laWidget*)ArcHomeButtonPanelWidget, 30, 30);
    laWidget_SetScheme((laWidget*)ArcHomeButtonPanelWidget, &ArcDemoScheme);
    laWidget_SetBackgroundType((laWidget*)ArcHomeButtonPanelWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ArcHomeButtonPanelWidget, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)HomeButton_ArcDemo, ArcHomeButtonPanelWidget);

    ArcHomeButtonImage = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ArcHomeButtonImage, 15, 15);
    laWidget_SetSize((laWidget*)ArcHomeButtonImage, 30, 30);
    laWidget_SetScheme((laWidget*)ArcHomeButtonImage, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ArcHomeButtonImage, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ArcHomeButtonImage, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ArcHomeButtonImage, &ArcDemoHomeButtonFilled30x30);
    laWidget_AddChild((laWidget*)HomeButton_ArcDemo, (laWidget*)ArcHomeButtonImage);

    TouchImage_ArcDemo = laArcWidget_New();
    laWidget_SetPosition((laWidget*)TouchImage_ArcDemo, 180, 110);
    laWidget_SetSize((laWidget*)TouchImage_ArcDemo, 101, 101);
    laWidget_SetEnabled((laWidget*)TouchImage_ArcDemo, LA_FALSE);
    laWidget_SetScheme((laWidget*)TouchImage_ArcDemo, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)TouchImage_ArcDemo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TouchImage_ArcDemo, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(TouchImage_ArcDemo, 30);
    laArcWidget_SetCenterAngle(TouchImage_ArcDemo, 360);
    laArcWidget_SetThickness(TouchImage_ArcDemo, 5);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TouchImage_ArcDemo);

    LabelWidget2 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget2, 16, 37);
    laWidget_SetSize((laWidget*)LabelWidget2, 69, 25);
    laWidget_SetScheme((laWidget*)LabelWidget2, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget2, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget2, laString_CreateFromID(string_TouchHere));
    laWidget_AddChild((laWidget*)TouchImage_ArcDemo, (laWidget*)LabelWidget2);

}

static void ScreenCreate_CircularSliderDemo(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &CircularSliderDemoScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    LabelWidget31 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget31, 103, 16);
    laWidget_SetSize((laWidget*)LabelWidget31, 278, 25);
    laWidget_SetScheme((laWidget*)LabelWidget31, &CircularSliderDemoScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget31, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget31, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget31, laString_CreateFromID(string_CircularSliderDemo));
    laLabelWidget_SetHAlignment(LabelWidget31, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget31);

    CircularSliderValueLabel = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)CircularSliderValueLabel, 126, 132);
    laWidget_SetSize((laWidget*)CircularSliderValueLabel, 59, 37);
    laWidget_SetScheme((laWidget*)CircularSliderValueLabel, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)CircularSliderValueLabel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CircularSliderValueLabel, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(CircularSliderValueLabel, laString_CreateFromID(string_DefaultValueBig));
    laWidget_AddChild((laWidget*)layer0, (laWidget*)CircularSliderValueLabel);

    CircularProgressBar = laCircularSliderWidget_New();
    laWidget_SetPosition((laWidget*)CircularProgressBar, 80, 79);
    laWidget_SetSize((laWidget*)CircularProgressBar, 147, 146);
    laWidget_SetScheme((laWidget*)CircularProgressBar, &CircularProgressBarScheme);
    laWidget_SetBackgroundType((laWidget*)CircularProgressBar, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CircularProgressBar, LA_WIDGET_BORDER_NONE);
    laCircularSliderWidget_SetRadius(CircularProgressBar, 70);
    laCircularSliderWidget_SetStartAngle(CircularProgressBar, 270);
    laCircularSliderWidget_SetStickyButton(CircularProgressBar, LA_FALSE);
    laCircularSliderWidget_SetTouchOnButtonOnly(CircularProgressBar, LA_FALSE);
    laCircularSliderWidget_SetDirection(CircularProgressBar, CIRCULAR_SLIDER_DIR_CLOCKWISE);
    laCircularSliderWidget_SetArcThickness(CircularProgressBar, INSIDE_CIRCLE_BORDER, 2);
    laCircularSliderWidget_SetArcThickness(CircularProgressBar, ACTIVE_AREA, 15);
    laCircularSliderWidget_SetArcVisible(CircularProgressBar, CIRCLE_BUTTON, LA_FALSE);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)CircularProgressBar);

    CircularSliderWidgetControl = laCircularSliderWidget_New();
    laWidget_SetPosition((laWidget*)CircularSliderWidgetControl, 240, 70);
    laWidget_SetSize((laWidget*)CircularSliderWidgetControl, 170, 171);
    laWidget_SetScheme((laWidget*)CircularSliderWidgetControl, &CircularSliderScheme);
    laWidget_SetBackgroundType((laWidget*)CircularSliderWidgetControl, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CircularSliderWidgetControl, LA_WIDGET_BORDER_NONE);
    laCircularSliderWidget_SetRadius(CircularSliderWidgetControl, 70);
    laCircularSliderWidget_SetStartAngle(CircularSliderWidgetControl, 270);
    laCircularSliderWidget_SetTouchOnButtonOnly(CircularSliderWidgetControl, LA_FALSE);
    laCircularSliderWidget_SetArcVisible(CircularSliderWidgetControl, OUTSIDE_CIRCLE_BORDER, LA_FALSE);
    laCircularSliderWidget_SetArcVisible(CircularSliderWidgetControl, INSIDE_CIRCLE_BORDER, LA_FALSE);
    laCircularSliderWidget_SetArcThickness(CircularSliderWidgetControl, ACTIVE_AREA, 10);
    laCircularSliderWidget_SetArcRadius(CircularSliderWidgetControl, CIRCLE_BUTTON, 25);
    laCircularSliderWidget_SetArcScheme(CircularSliderWidgetControl, CIRCLE_BUTTON, &CircularSliderScheme);
    laCircularSliderWidget_SetValueChangedEventCallback(CircularSliderWidgetControl, &CircularSliderWidgetControl_ValueChangedEvent);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)CircularSliderWidgetControl);

    CircSlider_NextButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)CircSlider_NextButton, 420, 0);
    laWidget_SetSize((laWidget*)CircSlider_NextButton, 60, 60);
    laWidget_SetScheme((laWidget*)CircSlider_NextButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)CircSlider_NextButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CircSlider_NextButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(CircSlider_NextButton, &CircSlider_NextButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)CircSlider_NextButton);

    PanelWidget17 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget17, 15, 19);
    laWidget_SetSize((laWidget*)PanelWidget17, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget17, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget17, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget17, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)CircSlider_NextButton, PanelWidget17);

    PanelWidget18 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget18, 19, 15);
    laWidget_SetSize((laWidget*)PanelWidget18, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget18, &CircularSliderDemoScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget18, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget18, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)CircSlider_NextButton, PanelWidget18);

    ImageWidget19 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget19, 19, 15);
    laWidget_SetSize((laWidget*)ImageWidget19, 30, 30);
    laWidget_SetScheme((laWidget*)ImageWidget19, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget19, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget19, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget19, &CircSliderNextButtonFilled30x30);
    laWidget_AddChild((laWidget*)CircSlider_NextButton, (laWidget*)ImageWidget19);

    CircSlider_HomeButton = laButtonWidget_New();
    laWidget_SetSize((laWidget*)CircSlider_HomeButton, 60, 60);
    laWidget_SetScheme((laWidget*)CircSlider_HomeButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)CircSlider_HomeButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CircSlider_HomeButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(CircSlider_HomeButton, &CircSlider_HomeButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)CircSlider_HomeButton);

    PanelWidget13 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget13, 19, 19);
    laWidget_SetSize((laWidget*)PanelWidget13, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget13, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget13, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget13, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)CircSlider_HomeButton, PanelWidget13);

    PanelWidget14 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget14, 15, 15);
    laWidget_SetSize((laWidget*)PanelWidget14, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget14, &CircularSliderDemoScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget14, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget14, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)CircSlider_HomeButton, PanelWidget14);

    ImageWidget15 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget15, 15, 15);
    laWidget_SetSize((laWidget*)ImageWidget15, 30, 30);
    laWidget_SetScheme((laWidget*)ImageWidget15, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget15, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget15, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget15, &CircSliderHomeButtonFilled30x30);
    laWidget_AddChild((laWidget*)CircSlider_HomeButton, (laWidget*)ImageWidget15);

    TouchImage_CircSliderDemo = laArcWidget_New();
    laWidget_SetPosition((laWidget*)TouchImage_CircSliderDemo, 288, 63);
    laWidget_SetSize((laWidget*)TouchImage_CircSliderDemo, 75, 64);
    laWidget_SetEnabled((laWidget*)TouchImage_CircSliderDemo, LA_FALSE);
    laWidget_SetScheme((laWidget*)TouchImage_CircSliderDemo, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)TouchImage_CircSliderDemo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TouchImage_CircSliderDemo, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(TouchImage_CircSliderDemo, 30);
    laArcWidget_SetCenterAngle(TouchImage_CircSliderDemo, 360);
    laArcWidget_SetThickness(TouchImage_CircSliderDemo, 5);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TouchImage_CircSliderDemo);

    LabelWidget3 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget3, 4, 18);
    laWidget_SetSize((laWidget*)LabelWidget3, 69, 25);
    laWidget_SetScheme((laWidget*)LabelWidget3, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget3, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget3, laString_CreateFromID(string_TouchHere));
    laWidget_AddChild((laWidget*)TouchImage_CircSliderDemo, (laWidget*)LabelWidget3);

}

static void ScreenCreate_CircularGaugeDemo(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &CircularGaugeDemoScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    LabelWidget41 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget41, 103, 11);
    laWidget_SetSize((laWidget*)LabelWidget41, 278, 25);
    laWidget_SetScheme((laWidget*)LabelWidget41, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget41, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget41, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget41, laString_CreateFromID(string_CircularGaugeDemo));
    laLabelWidget_SetHAlignment(LabelWidget41, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget41);

    CircGauge_NextButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)CircGauge_NextButton, 420, 0);
    laWidget_SetSize((laWidget*)CircGauge_NextButton, 60, 60);
    laWidget_SetScheme((laWidget*)CircGauge_NextButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)CircGauge_NextButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CircGauge_NextButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(CircGauge_NextButton, &CircGauge_NextButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)CircGauge_NextButton);

    PanelWidget25 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget25, 15, 19);
    laWidget_SetSize((laWidget*)PanelWidget25, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget25, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget25, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget25, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)CircGauge_NextButton, PanelWidget25);

    PanelWidget26 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget26, 19, 15);
    laWidget_SetSize((laWidget*)PanelWidget26, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget26, &CircularGaugeDemoScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget26, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget26, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)CircGauge_NextButton, PanelWidget26);

    ImageWidget27 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget27, 19, 15);
    laWidget_SetSize((laWidget*)ImageWidget27, 30, 30);
    laWidget_SetScheme((laWidget*)ImageWidget27, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget27, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget27, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget27, &CircGaugeNextButtonFilled30x30);
    laWidget_AddChild((laWidget*)CircGauge_NextButton, (laWidget*)ImageWidget27);

    GaugeValueLabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)GaugeValueLabelWidget, 242, 153);
    laWidget_SetSize((laWidget*)GaugeValueLabelWidget, 44, 30);
    laWidget_SetScheme((laWidget*)GaugeValueLabelWidget, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)GaugeValueLabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)GaugeValueLabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(GaugeValueLabelWidget, laString_CreateFromID(string_DefaultGaugeValue));
    laWidget_AddChild((laWidget*)layer0, (laWidget*)GaugeValueLabelWidget);

    MphLabel = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)MphLabel, 251, 175);
    laWidget_SetSize((laWidget*)MphLabel, 29, 25);
    laWidget_SetScheme((laWidget*)MphLabel, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)MphLabel, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)MphLabel, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(MphLabel, laString_CreateFromID(string_mph));
    laLabelWidget_SetHAlignment(MphLabel, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)MphLabel);

    CircularGaugeWidget43 = laCircularGaugeWidget_New();
    laWidget_SetPosition((laWidget*)CircularGaugeWidget43, 102, 59);
    laWidget_SetSize((laWidget*)CircularGaugeWidget43, 220, 204);
    laWidget_SetScheme((laWidget*)CircularGaugeWidget43, &CircularGaugeScheme);
    laWidget_SetBackgroundType((laWidget*)CircularGaugeWidget43, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CircularGaugeWidget43, LA_WIDGET_BORDER_NONE);
    laCircularGaugeWidget_SetRadius(CircularGaugeWidget43, 100);
    laCircularGaugeWidget_SetStartAngle(CircularGaugeWidget43, 270);
    laCircularGaugeWidget_SetCenterAngle(CircularGaugeWidget43, -230);
    laCircularGaugeWidget_SetValue(CircularGaugeWidget43, 0);
    laCircularGaugeWidget_SetEndValue(CircularGaugeWidget43, 100);
    laCircularGaugeWidget_SetTickLength(CircularGaugeWidget43, 15);
    laCircularGaugeWidget_SetTickLabelsVisible(CircularGaugeWidget43, LA_FALSE);
    laCircularGaugeWidget_SetTicksLabelsStringID(CircularGaugeWidget43, string_NumsSmall);
    laCircularGaugeWidget_SetStringTable(CircularGaugeWidget43, &stringTable);
    laCircularGaugeWidget_SetHandRadius(CircularGaugeWidget43, 80);
    laCircularGaugeWidget_SetCenterCircleVisible(CircularGaugeWidget43, LA_FALSE);
    laCircularGaugeWidget_SetCenterCircleRadius(CircularGaugeWidget43, 10);
    laCircularGaugeWidget_SetCenterCircleThickness(CircularGaugeWidget43, 10);
    laCircularGaugeWidget_AddValueArc(CircularGaugeWidget43, 0, 100, 100, 5, &BlackBaseScheme);
    laCircularGaugeWidget_AddValueArc(CircularGaugeWidget43, 0, 75, 95, 20, &GrayForegroundScheme);
    laCircularGaugeWidget_AddAngularArc(CircularGaugeWidget43, 0, 360, 10, 10, &BlackBaseScheme);
    laCircularGaugeWidget_AddValueArc(CircularGaugeWidget43, 75, 100, 95, 20, NULL);
    laCircularGaugeWidget_AddMinorTicks(CircularGaugeWidget43, 2, 100, 100, 10, 2, &BlackBackgroundScheme);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)CircularGaugeWidget43);

    SpeedoCircularGaugeWidget = laCircularGaugeWidget_New();
    laWidget_SetPosition((laWidget*)SpeedoCircularGaugeWidget, 220, 120);
    laWidget_SetSize((laWidget*)SpeedoCircularGaugeWidget, 148, 150);
    laWidget_SetScheme((laWidget*)SpeedoCircularGaugeWidget, &CircularGaugeScheme);
    laWidget_SetBackgroundType((laWidget*)SpeedoCircularGaugeWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SpeedoCircularGaugeWidget, LA_WIDGET_BORDER_NONE);
    laCircularGaugeWidget_SetRadius(SpeedoCircularGaugeWidget, 55);
    laCircularGaugeWidget_SetStartAngle(SpeedoCircularGaugeWidget, 210);
    laCircularGaugeWidget_SetCenterAngle(SpeedoCircularGaugeWidget, 230);
    laCircularGaugeWidget_SetValue(SpeedoCircularGaugeWidget, 0);
    laCircularGaugeWidget_SetEndValue(SpeedoCircularGaugeWidget, 160);
    laCircularGaugeWidget_SetTickValue(SpeedoCircularGaugeWidget, 40);
    laCircularGaugeWidget_SetTicksLabelsStringID(SpeedoCircularGaugeWidget, string_NumsSmall);
    laCircularGaugeWidget_SetStringTable(SpeedoCircularGaugeWidget, &stringTable);
    laCircularGaugeWidget_SetCenterCircleThickness(SpeedoCircularGaugeWidget, 5);
    laCircularGaugeWidget_AddValueArc(SpeedoCircularGaugeWidget, 0, 80, 48, 6, &GrayForegroundScheme);
    laCircularGaugeWidget_AddValueArc(SpeedoCircularGaugeWidget, 0, 160, 50, 2, &defaultScheme);
    laCircularGaugeWidget_AddValueArc(SpeedoCircularGaugeWidget, 80, 160, 48, 6, &RedlineScheme);
    laCircularGaugeWidget_AddMinorTicks(SpeedoCircularGaugeWidget, 10, 150, 55, 3, 10, &GrayForegroundScheme);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)SpeedoCircularGaugeWidget);

    LabelWidget49 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget49, 215, 253);
    laWidget_SetSize((laWidget*)LabelWidget49, 15, 19);
    laWidget_SetScheme((laWidget*)LabelWidget49, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget49, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget49, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget49, laString_CreateFromID(string_NumGauge0));
    laLabelWidget_SetHAlignment(LabelWidget49, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget49);

    LabelWidget51 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget51, 115, 231);
    laWidget_SetSize((laWidget*)LabelWidget51, 16, 20);
    laWidget_SetScheme((laWidget*)LabelWidget51, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget51, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget51, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget51, laString_CreateFromID(string_NumGauge2));
    laLabelWidget_SetHAlignment(LabelWidget51, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget51);

    LabelWidget53 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget53, 95, 192);
    laWidget_SetSize((laWidget*)LabelWidget53, 16, 19);
    laWidget_SetScheme((laWidget*)LabelWidget53, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget53, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget53, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget53, laString_CreateFromID(string_NumGauge3));
    laLabelWidget_SetHAlignment(LabelWidget53, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget53);

    LabelWidget50 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget50, 161, 253);
    laWidget_SetSize((laWidget*)LabelWidget50, 14, 21);
    laWidget_SetScheme((laWidget*)LabelWidget50, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget50, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget50, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget50, laString_CreateFromID(string_NumGauge1));
    laLabelWidget_SetHAlignment(LabelWidget50, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget50);

    LabelWidget54 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget54, 90, 152);
    laWidget_SetSize((laWidget*)LabelWidget54, 13, 19);
    laWidget_SetScheme((laWidget*)LabelWidget54, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget54, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget54, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget54, laString_CreateFromID(string_NumGauge4));
    laLabelWidget_SetHAlignment(LabelWidget54, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget54);

    LabelWidget55 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget55, 96, 106);
    laWidget_SetSize((laWidget*)LabelWidget55, 15, 19);
    laWidget_SetScheme((laWidget*)LabelWidget55, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget55, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget55, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget55, laString_CreateFromID(string_NumGauge5));
    laLabelWidget_SetHAlignment(LabelWidget55, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget55);

    LabelWidget56 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget56, 126, 70);
    laWidget_SetSize((laWidget*)LabelWidget56, 15, 19);
    laWidget_SetScheme((laWidget*)LabelWidget56, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget56, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget56, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget56, laString_CreateFromID(string_NumGauge6));
    laLabelWidget_SetHAlignment(LabelWidget56, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget56);

    LabelWidget57 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget57, 166, 42);
    laWidget_SetSize((laWidget*)LabelWidget57, 15, 19);
    laWidget_SetScheme((laWidget*)LabelWidget57, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget57, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget57, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget57, laString_CreateFromID(string_NumGauge7));
    laLabelWidget_SetHAlignment(LabelWidget57, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget57);

    LabelWidget59 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget59, 252, 52);
    laWidget_SetSize((laWidget*)LabelWidget59, 15, 19);
    laWidget_SetScheme((laWidget*)LabelWidget59, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget59, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget59, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget59, laString_CreateFromID(string_NumGauge9));
    laLabelWidget_SetHAlignment(LabelWidget59, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget59);

    LabelWidget60 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget60, 290, 80);
    laWidget_SetSize((laWidget*)LabelWidget60, 25, 19);
    laWidget_SetScheme((laWidget*)LabelWidget60, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget60, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget60, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget60, laString_CreateFromID(string_NumGauge10));
    laLabelWidget_SetHAlignment(LabelWidget60, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget60);

    LabelWidget58 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget58, 210, 37);
    laWidget_SetSize((laWidget*)LabelWidget58, 15, 19);
    laWidget_SetScheme((laWidget*)LabelWidget58, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget58, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget58, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget58, laString_CreateFromID(string_NumGauge8));
    laLabelWidget_SetHAlignment(LabelWidget58, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget58);

    CircGauge_HomeButton = laButtonWidget_New();
    laWidget_SetSize((laWidget*)CircGauge_HomeButton, 60, 60);
    laWidget_SetScheme((laWidget*)CircGauge_HomeButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)CircGauge_HomeButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CircGauge_HomeButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(CircGauge_HomeButton, &CircGauge_HomeButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)CircGauge_HomeButton);

    PanelWidget21 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget21, 19, 19);
    laWidget_SetSize((laWidget*)PanelWidget21, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget21, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget21, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget21, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)CircGauge_HomeButton, PanelWidget21);

    PanelWidget22 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget22, 15, 15);
    laWidget_SetSize((laWidget*)PanelWidget22, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget22, &CircularGaugeDemoScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget22, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget22, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)CircGauge_HomeButton, PanelWidget22);

    ImageWidget23 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget23, 15, 15);
    laWidget_SetSize((laWidget*)ImageWidget23, 30, 30);
    laWidget_SetScheme((laWidget*)ImageWidget23, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget23, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget23, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget23, &CircGaugeHomeButtonFilled30x30);
    laWidget_AddChild((laWidget*)CircGauge_HomeButton, (laWidget*)ImageWidget23);

    LabelWidget1 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget1, 184, 114);
    laWidget_SetSize((laWidget*)LabelWidget1, 57, 25);
    laWidget_SetScheme((laWidget*)LabelWidget1, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget1, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget1, laString_CreateFromID(string_rpm));
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget1);

    GasButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)GasButton, 0, 54);
    laWidget_SetSize((laWidget*)GasButton, 480, 216);
    laWidget_SetScheme((laWidget*)GasButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)GasButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)GasButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedEventCallback(GasButton, &GasButton_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(GasButton, &GasButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)GasButton);

    TouchImage_CircGaugeDemo = laArcWidget_New();
    laWidget_SetPosition((laWidget*)TouchImage_CircGaugeDemo, 386, 129);
    laWidget_SetSize((laWidget*)TouchImage_CircGaugeDemo, 75, 64);
    laWidget_SetEnabled((laWidget*)TouchImage_CircGaugeDemo, LA_FALSE);
    laWidget_SetScheme((laWidget*)TouchImage_CircGaugeDemo, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)TouchImage_CircGaugeDemo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TouchImage_CircGaugeDemo, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(TouchImage_CircGaugeDemo, 30);
    laArcWidget_SetCenterAngle(TouchImage_CircGaugeDemo, 360);
    laArcWidget_SetThickness(TouchImage_CircGaugeDemo, 5);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TouchImage_CircGaugeDemo);

    LabelWidget5 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget5, 4, 18);
    laWidget_SetSize((laWidget*)LabelWidget5, 69, 25);
    laWidget_SetScheme((laWidget*)LabelWidget5, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget5, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget5, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget5, laString_CreateFromID(string_TouchHere));
    laWidget_AddChild((laWidget*)TouchImage_CircGaugeDemo, (laWidget*)LabelWidget5);

}

static void ScreenCreate_PieChartDemo(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &PieChartDemoScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    PieChart_NextButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)PieChart_NextButton, 420, 0);
    laWidget_SetSize((laWidget*)PieChart_NextButton, 60, 60);
    laWidget_SetScheme((laWidget*)PieChart_NextButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)PieChart_NextButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PieChart_NextButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(PieChart_NextButton, &PieChart_NextButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)PieChart_NextButton);

    PanelWidget33 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget33, 15, 19);
    laWidget_SetSize((laWidget*)PanelWidget33, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget33, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget33, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget33, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)PieChart_NextButton, PanelWidget33);

    PanelWidget34 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget34, 19, 15);
    laWidget_SetSize((laWidget*)PanelWidget34, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget34, &PieChartDemoScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget34, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget34, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)PieChart_NextButton, PanelWidget34);

    ImageWidget35 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget35, 19, 15);
    laWidget_SetSize((laWidget*)ImageWidget35, 30, 30);
    laWidget_SetScheme((laWidget*)ImageWidget35, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget35, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget35, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget35, &PieChartNextButtonFilled30x30);
    laWidget_AddChild((laWidget*)PieChart_NextButton, (laWidget*)ImageWidget35);

    LabelWidget39 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget39, 123, 21);
    laWidget_SetSize((laWidget*)LabelWidget39, 238, 25);
    laWidget_SetScheme((laWidget*)LabelWidget39, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget39, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget39, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget39, laString_CreateFromID(string_PieChartDemo));
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget39);

    PieChartWidget2 = laPieChartWidget_New();
    laWidget_SetPosition((laWidget*)PieChartWidget2, 130, 50);
    laWidget_SetSize((laWidget*)PieChartWidget2, 220, 220);
    laWidget_SetScheme((laWidget*)PieChartWidget2, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)PieChartWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PieChartWidget2, LA_WIDGET_BORDER_NONE);
    laPieChartWidget_SetCenterAngle(PieChartWidget2, 360);
    laPieChartWidget_SetLabelsOffset(PieChartWidget2, 60);
    laPieChartWidget_SetLabelsStringID(PieChartWidget2, string_NumsSmall);
    laPieChartWidget_SetStringTable(PieChartWidget2, &stringTable);
    laPieChartWidget_AddEntry(PieChartWidget2, NULL);
    laPieChartWidget_SetEntryValue(PieChartWidget2, 0, 30);
    laPieChartWidget_SetEntryRadius(PieChartWidget2, 0, 90);
    laPieChartWidget_SetEntryOffset(PieChartWidget2, 0, 0);
    laPieChartWidget_SetEntryScheme(PieChartWidget2, 0, &DarkBlueForeGroundScheme);
    laPieChartWidget_AddEntry(PieChartWidget2, NULL);
    laPieChartWidget_SetEntryValue(PieChartWidget2, 1, 40);
    laPieChartWidget_SetEntryRadius(PieChartWidget2, 1, 90);
    laPieChartWidget_SetEntryOffset(PieChartWidget2, 1, 0);
    laPieChartWidget_SetEntryScheme(PieChartWidget2, 1, &LightBlueForegroundScheme);
    laPieChartWidget_AddEntry(PieChartWidget2, NULL);
    laPieChartWidget_SetEntryValue(PieChartWidget2, 2, 25);
    laPieChartWidget_SetEntryRadius(PieChartWidget2, 2, 90);
    laPieChartWidget_SetEntryOffset(PieChartWidget2, 2, 0);
    laPieChartWidget_SetEntryScheme(PieChartWidget2, 2, &BrightPinkBaseScheme);
    laPieChartWidget_AddEntry(PieChartWidget2, NULL);
    laPieChartWidget_SetEntryValue(PieChartWidget2, 3, 45);
    laPieChartWidget_SetEntryRadius(PieChartWidget2, 3, 90);
    laPieChartWidget_SetEntryOffset(PieChartWidget2, 3, 0);
    laPieChartWidget_SetEntryScheme(PieChartWidget2, 3, &BrightPurpleBaseScheme);
    laPieChartWidget_AddEntry(PieChartWidget2, NULL);
    laPieChartWidget_SetEntryValue(PieChartWidget2, 4, 35);
    laPieChartWidget_SetEntryRadius(PieChartWidget2, 4, 90);
    laPieChartWidget_SetEntryOffset(PieChartWidget2, 4, 0);
    laPieChartWidget_SetEntryScheme(PieChartWidget2, 4, &BrightYellowBaseScheme);
    laPieChartWidget_SetPressedEventCallback(PieChartWidget2, &PieChartWidget2_PressedEvent);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)PieChartWidget2);

    PieChart_HomeButton = laButtonWidget_New();
    laWidget_SetSize((laWidget*)PieChart_HomeButton, 60, 60);
    laWidget_SetScheme((laWidget*)PieChart_HomeButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)PieChart_HomeButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)PieChart_HomeButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(PieChart_HomeButton, &PieChart_HomeButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)PieChart_HomeButton);

    PanelWidget29 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget29, 19, 19);
    laWidget_SetSize((laWidget*)PanelWidget29, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget29, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget29, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget29, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)PieChart_HomeButton, PanelWidget29);

    PanelWidget30 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget30, 15, 15);
    laWidget_SetSize((laWidget*)PanelWidget30, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget30, &PieChartDemoScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget30, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget30, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)PieChart_HomeButton, PanelWidget30);

    ImageWidget31 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget31, 15, 15);
    laWidget_SetSize((laWidget*)ImageWidget31, 30, 30);
    laWidget_SetScheme((laWidget*)ImageWidget31, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget31, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget31, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget31, &PieChartHomeButtonFilled30x30);
    laWidget_AddChild((laWidget*)PieChart_HomeButton, (laWidget*)ImageWidget31);

    TouchImage_PieChartDemo = laArcWidget_New();
    laWidget_SetPosition((laWidget*)TouchImage_PieChartDemo, 226, 143);
    laWidget_SetSize((laWidget*)TouchImage_PieChartDemo, 75, 64);
    laWidget_SetEnabled((laWidget*)TouchImage_PieChartDemo, LA_FALSE);
    laWidget_SetScheme((laWidget*)TouchImage_PieChartDemo, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)TouchImage_PieChartDemo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TouchImage_PieChartDemo, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(TouchImage_PieChartDemo, 30);
    laArcWidget_SetCenterAngle(TouchImage_PieChartDemo, 360);
    laArcWidget_SetThickness(TouchImage_PieChartDemo, 5);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TouchImage_PieChartDemo);

    LabelWidget19 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget19, 4, 18);
    laWidget_SetSize((laWidget*)LabelWidget19, 69, 25);
    laWidget_SetScheme((laWidget*)LabelWidget19, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget19, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget19, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget19, laString_CreateFromID(string_TouchHere));
    laWidget_AddChild((laWidget*)TouchImage_PieChartDemo, (laWidget*)LabelWidget19);

}

static void ScreenCreate_BarGraphDemo(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &BarGraphDemoScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    LabelWidget4 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget4, 119, 20);
    laWidget_SetSize((laWidget*)LabelWidget4, 250, 25);
    laWidget_SetScheme((laWidget*)LabelWidget4, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget4, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget4, laString_CreateFromID(string_BarGraphDemo));
    laLabelWidget_SetHAlignment(LabelWidget4, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget4);

    BarGraphWidget8 = laBarGraphWidget_New();
    laWidget_SetPosition((laWidget*)BarGraphWidget8, 1, 66);
    laWidget_SetSize((laWidget*)BarGraphWidget8, 470, 207);
    laWidget_SetScheme((laWidget*)BarGraphWidget8, &BarGraphWidgetScheme);
    laWidget_SetBackgroundType((laWidget*)BarGraphWidget8, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)BarGraphWidget8, LA_WIDGET_BORDER_NONE);
    laBarGraphWidget_SetStacked(BarGraphWidget8, LA_FALSE);
    laBarGraphWidget_SetMaxValue(BarGraphWidget8, 0, 500);
    laBarGraphWidget_SetValueAxisTickInterval(BarGraphWidget8, 0, 100);
    laBarGraphWidget_SetValueAxisSubtickInterval(BarGraphWidget8, 0, 25);
    laBarGraphWidget_SetTicksLabelsStringID(BarGraphWidget8, string_NumsSmall);
    laBarGraphWidget_SetStringTable(BarGraphWidget8, &stringTable);
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 0, laString_CreateFromID(string_pt0));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 1, laString_CreateFromID(string_pt1));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 2, laString_CreateFromID(string_pt2));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 3, laString_CreateFromID(string_pt3));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 4, laString_CreateFromID(string_pt4));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 5, laString_CreateFromID(string_pt5));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 6, laString_CreateFromID(string_pt6));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 7, laString_CreateFromID(string_pt7));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 8, laString_CreateFromID(string_pt8));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 9, laString_CreateFromID(string_pt9));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 10, laString_CreateFromID(string_pt10));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 11, laString_CreateFromID(string_pt11));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 12, laString_CreateFromID(string_pt12));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 13, laString_CreateFromID(string_pt13));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 14, laString_CreateFromID(string_pt14));
    laBarGraphWidget_AddCategory(BarGraphWidget8, NULL);
    laBarGraphWidget_SetCategoryText(BarGraphWidget8, 15, laString_CreateFromID(string_pt15));
    laBarGraphWidget_AddSeries(BarGraphWidget8, NULL);
    laBarGraphWidget_SetSeriesScheme(BarGraphWidget8, 0, &DarkBlueForeGroundScheme);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 0, 0, NULL);
    laBarGraphWidget_AddSeries(BarGraphWidget8, NULL);
    laBarGraphWidget_SetSeriesScheme(BarGraphWidget8, 1, &LightBlueForegroundScheme);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laBarGraphWidget_AddDataToSeries(BarGraphWidget8, 1, 0, NULL);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)BarGraphWidget8);

    TouchImage_BarGraphDemo = laArcWidget_New();
    laWidget_SetPosition((laWidget*)TouchImage_BarGraphDemo, 206, 122);
    laWidget_SetSize((laWidget*)TouchImage_BarGraphDemo, 75, 64);
    laWidget_SetEnabled((laWidget*)TouchImage_BarGraphDemo, LA_FALSE);
    laWidget_SetScheme((laWidget*)TouchImage_BarGraphDemo, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)TouchImage_BarGraphDemo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TouchImage_BarGraphDemo, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(TouchImage_BarGraphDemo, 30);
    laArcWidget_SetCenterAngle(TouchImage_BarGraphDemo, 360);
    laArcWidget_SetThickness(TouchImage_BarGraphDemo, 5);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TouchImage_BarGraphDemo);

    LabelWidget21 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget21, 4, 18);
    laWidget_SetSize((laWidget*)LabelWidget21, 69, 25);
    laWidget_SetScheme((laWidget*)LabelWidget21, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget21, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget21, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget21, laString_CreateFromID(string_TouchHere));
    laWidget_AddChild((laWidget*)TouchImage_BarGraphDemo, (laWidget*)LabelWidget21);

    BarGraphTouchedButton = laButtonWidget_New();
    laWidget_SetSize((laWidget*)BarGraphTouchedButton, 480, 273);
    laWidget_SetScheme((laWidget*)BarGraphTouchedButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)BarGraphTouchedButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)BarGraphTouchedButton, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)BarGraphTouchedButton);

    BarGraph_NextButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)BarGraph_NextButton, 420, 0);
    laWidget_SetSize((laWidget*)BarGraph_NextButton, 60, 60);
    laWidget_SetScheme((laWidget*)BarGraph_NextButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)BarGraph_NextButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)BarGraph_NextButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(BarGraph_NextButton, &BarGraph_NextButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)BarGraph_NextButton);

    PanelWidget41 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget41, 15, 19);
    laWidget_SetSize((laWidget*)PanelWidget41, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget41, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget41, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget41, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)BarGraph_NextButton, PanelWidget41);

    PanelWidget42 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget42, 19, 15);
    laWidget_SetSize((laWidget*)PanelWidget42, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget42, &BarGraphDemoScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget42, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget42, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)BarGraph_NextButton, PanelWidget42);

    ImageWidget43 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget43, 19, 15);
    laWidget_SetSize((laWidget*)ImageWidget43, 30, 30);
    laWidget_SetScheme((laWidget*)ImageWidget43, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget43, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget43, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget43, &BarGraphNextButtonFilled30x30);
    laWidget_AddChild((laWidget*)BarGraph_NextButton, (laWidget*)ImageWidget43);

    BarGraph_HomeButton = laButtonWidget_New();
    laWidget_SetSize((laWidget*)BarGraph_HomeButton, 60, 60);
    laWidget_SetScheme((laWidget*)BarGraph_HomeButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)BarGraph_HomeButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)BarGraph_HomeButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(BarGraph_HomeButton, &BarGraph_HomeButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)BarGraph_HomeButton);

    PanelWidget37 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget37, 19, 19);
    laWidget_SetSize((laWidget*)PanelWidget37, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget37, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget37, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget37, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)BarGraph_HomeButton, PanelWidget37);

    PanelWidget38 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget38, 15, 15);
    laWidget_SetSize((laWidget*)PanelWidget38, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget38, &BarGraphDemoScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget38, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget38, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)BarGraph_HomeButton, PanelWidget38);

    ImageWidget39 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget39, 15, 15);
    laWidget_SetSize((laWidget*)ImageWidget39, 30, 30);
    laWidget_SetScheme((laWidget*)ImageWidget39, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget39, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget39, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget39, &BarGraphHomeButtonFilled30x30);
    laWidget_AddChild((laWidget*)BarGraph_HomeButton, (laWidget*)ImageWidget39);

    LabelWidget = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget, 198, 48);
    laWidget_SetSize((laWidget*)LabelWidget, 21, 25);
    laWidget_SetScheme((laWidget*)LabelWidget, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget, laString_CreateFromID(string_x));
    laLabelWidget_SetHAlignment(LabelWidget, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget);

    LabelWidget6 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget6, 250, 48);
    laWidget_SetSize((laWidget*)LabelWidget6, 21, 25);
    laWidget_SetScheme((laWidget*)LabelWidget6, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget6, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget6, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget6, laString_CreateFromID(string_y));
    laLabelWidget_SetHAlignment(LabelWidget6, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget6);

    ArcWidget21 = laArcWidget_New();
    laWidget_SetPosition((laWidget*)ArcWidget21, 180, 57);
    laWidget_SetSize((laWidget*)ArcWidget21, 10, 10);
    laWidget_SetScheme((laWidget*)ArcWidget21, &DarkBlueForeGroundScheme);
    laWidget_SetBackgroundType((laWidget*)ArcWidget21, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ArcWidget21, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(ArcWidget21, 10);
    laArcWidget_SetCenterAngle(ArcWidget21, 360);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ArcWidget21);

    ArcWidget23 = laArcWidget_New();
    laWidget_SetPosition((laWidget*)ArcWidget23, 231, 57);
    laWidget_SetSize((laWidget*)ArcWidget23, 10, 10);
    laWidget_SetScheme((laWidget*)ArcWidget23, &LightBlueForegroundScheme);
    laWidget_SetBackgroundType((laWidget*)ArcWidget23, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ArcWidget23, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(ArcWidget23, 10);
    laArcWidget_SetCenterAngle(ArcWidget23, 360);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ArcWidget23);

}

static void ScreenCreate_LineGraphScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer0, &LineGraphDemoScheme);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    LabelWidget11 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget11, 111, 17);
    laWidget_SetSize((laWidget*)LabelWidget11, 263, 25);
    laWidget_SetScheme((laWidget*)LabelWidget11, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget11, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget11, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget11, laString_CreateFromID(string_LineGraphDemo));
    laLabelWidget_SetHAlignment(LabelWidget11, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget11);

    LineGraphWidget13 = laLineGraphWidget_New();
    laWidget_SetPosition((laWidget*)LineGraphWidget13, 0, 66);
    laWidget_SetSize((laWidget*)LineGraphWidget13, 480, 207);
    laWidget_SetScheme((laWidget*)LineGraphWidget13, &LineGraphScheme);
    laWidget_SetBackgroundType((laWidget*)LineGraphWidget13, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LineGraphWidget13, LA_WIDGET_BORDER_NONE);
    laLineGraphWidget_SetMaxValue(LineGraphWidget13, 0, 500);
    laLineGraphWidget_SetValueAxisTickInterval(LineGraphWidget13, 0, 100);
    laLineGraphWidget_SetValueAxisSubtickInterval(LineGraphWidget13, 0, 25);
    laLineGraphWidget_SetTicksLabelsStringID(LineGraphWidget13, string_NumsSmall);
    laLineGraphWidget_SetStringTable(LineGraphWidget13, &stringTable);
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 0, laString_CreateFromID(string_pt0));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 1, laString_CreateFromID(string_pt1));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 2, laString_CreateFromID(string_pt2));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 3, laString_CreateFromID(string_pt3));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 4, laString_CreateFromID(string_pt4));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 5, laString_CreateFromID(string_pt5));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 6, laString_CreateFromID(string_pt6));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 7, laString_CreateFromID(string_pt7));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 8, laString_CreateFromID(string_pt8));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 9, laString_CreateFromID(string_pt9));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 10, laString_CreateFromID(string_pt10));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 11, laString_CreateFromID(string_pt11));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 12, laString_CreateFromID(string_pt12));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 13, laString_CreateFromID(string_pt13));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 14, laString_CreateFromID(string_pt14));
    laLineGraphWidget_AddCategory(LineGraphWidget13, NULL);
    laLineGraphWidget_SetCategoryText(LineGraphWidget13, 15, laString_CreateFromID(string_pt15));
    laLineGraphWidget_AddSeries(LineGraphWidget13, NULL);
    laLineGraphWidget_SetSeriesScheme(LineGraphWidget13, 0, &DataSeriesA);
    laLineGraphWidget_SetSeriesPointType(LineGraphWidget13, 0, LINE_GRAPH_DATA_POINT_CIRCLE);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 0, 0, NULL);
    laLineGraphWidget_AddSeries(LineGraphWidget13, NULL);
    laLineGraphWidget_SetSeriesScheme(LineGraphWidget13, 1, &DataSeriesB);
    laLineGraphWidget_SetSeriesPointType(LineGraphWidget13, 1, LINE_GRAPH_DATA_POINT_SQUARE);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laLineGraphWidget_AddDataToSeries(LineGraphWidget13, 1, 0, NULL);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LineGraphWidget13);

    LineGraphTouchedButton = laButtonWidget_New();
    laWidget_SetSize((laWidget*)LineGraphTouchedButton, 480, 272);
    laWidget_SetScheme((laWidget*)LineGraphTouchedButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LineGraphTouchedButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LineGraphTouchedButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedEventCallback(LineGraphTouchedButton, &LineGraphTouchedButton_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(LineGraphTouchedButton, &LineGraphTouchedButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)LineGraphTouchedButton);

    TouchImage_LineGraphDemo = laArcWidget_New();
    laWidget_SetPosition((laWidget*)TouchImage_LineGraphDemo, 210, 104);
    laWidget_SetSize((laWidget*)TouchImage_LineGraphDemo, 75, 64);
    laWidget_SetEnabled((laWidget*)TouchImage_LineGraphDemo, LA_FALSE);
    laWidget_SetScheme((laWidget*)TouchImage_LineGraphDemo, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)TouchImage_LineGraphDemo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TouchImage_LineGraphDemo, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(TouchImage_LineGraphDemo, 30);
    laArcWidget_SetCenterAngle(TouchImage_LineGraphDemo, 360);
    laArcWidget_SetThickness(TouchImage_LineGraphDemo, 5);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)TouchImage_LineGraphDemo);

    LabelWidget23 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget23, 4, 18);
    laWidget_SetSize((laWidget*)LabelWidget23, 69, 25);
    laWidget_SetScheme((laWidget*)LabelWidget23, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget23, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget23, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget23, laString_CreateFromID(string_TouchHere));
    laWidget_AddChild((laWidget*)TouchImage_LineGraphDemo, (laWidget*)LabelWidget23);

    LineGraph_HomeButton = laButtonWidget_New();
    laWidget_SetSize((laWidget*)LineGraph_HomeButton, 60, 60);
    laWidget_SetScheme((laWidget*)LineGraph_HomeButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LineGraph_HomeButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LineGraph_HomeButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(LineGraph_HomeButton, &LineGraph_HomeButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)LineGraph_HomeButton);

    PanelWidget46 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget46, 19, 19);
    laWidget_SetSize((laWidget*)PanelWidget46, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget46, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget46, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget46, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)LineGraph_HomeButton, PanelWidget46);

    PanelWidget47 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget47, 15, 15);
    laWidget_SetSize((laWidget*)PanelWidget47, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget47, &LineGraphDemoScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget47, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget47, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)LineGraph_HomeButton, PanelWidget47);

    ImageWidget45 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget45, 15, 15);
    laWidget_SetSize((laWidget*)ImageWidget45, 30, 30);
    laWidget_SetScheme((laWidget*)ImageWidget45, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget45, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget45, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget45, &LineGraphHomeButtonFilled30x30);
    laWidget_AddChild((laWidget*)LineGraph_HomeButton, (laWidget*)ImageWidget45);

    LineGraph_NextButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)LineGraph_NextButton, 420, 0);
    laWidget_SetSize((laWidget*)LineGraph_NextButton, 60, 60);
    laWidget_SetScheme((laWidget*)LineGraph_NextButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LineGraph_NextButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LineGraph_NextButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetReleasedEventCallback(LineGraph_NextButton, &LineGraph_NextButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)LineGraph_NextButton);

    PanelWidget54 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget54, 15, 19);
    laWidget_SetSize((laWidget*)PanelWidget54, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget54, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget54, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget54, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)LineGraph_NextButton, PanelWidget54);

    PanelWidget55 = laWidget_New();
    laWidget_SetPosition((laWidget*)PanelWidget55, 19, 15);
    laWidget_SetSize((laWidget*)PanelWidget55, 30, 30);
    laWidget_SetScheme((laWidget*)PanelWidget55, &LineGraphDemoScheme);
    laWidget_SetBackgroundType((laWidget*)PanelWidget55, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)PanelWidget55, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)LineGraph_NextButton, PanelWidget55);

    ImageWidget56 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget56, 19, 15);
    laWidget_SetSize((laWidget*)ImageWidget56, 30, 30);
    laWidget_SetScheme((laWidget*)ImageWidget56, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget56, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget56, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget56, &LineGraphNextButtonFilled30x30);
    laWidget_AddChild((laWidget*)LineGraph_NextButton, (laWidget*)ImageWidget56);

    LabelWidget7 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget7, 178, 48);
    laWidget_SetSize((laWidget*)LabelWidget7, 21, 25);
    laWidget_SetScheme((laWidget*)LabelWidget7, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget7, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget7, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget7, laString_CreateFromID(string_x));
    laLabelWidget_SetHAlignment(LabelWidget7, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget7);

    LabelWidget16 = laLabelWidget_New();
    laWidget_SetPosition((laWidget*)LabelWidget16, 228, 48);
    laWidget_SetSize((laWidget*)LabelWidget16, 21, 25);
    laWidget_SetScheme((laWidget*)LabelWidget16, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)LabelWidget16, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)LabelWidget16, LA_WIDGET_BORDER_NONE);
    laLabelWidget_SetText(LabelWidget16, laString_CreateFromID(string_y));
    laLabelWidget_SetHAlignment(LabelWidget16, LA_HALIGN_LEFT);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)LabelWidget16);

    ArcWidget24 = laArcWidget_New();
    laWidget_SetPosition((laWidget*)ArcWidget24, 161, 57);
    laWidget_SetSize((laWidget*)ArcWidget24, 10, 10);
    laWidget_SetScheme((laWidget*)ArcWidget24, &DataSeriesA);
    laWidget_SetBackgroundType((laWidget*)ArcWidget24, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ArcWidget24, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(ArcWidget24, 5);
    laArcWidget_SetCenterAngle(ArcWidget24, 360);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ArcWidget24);

    ArcWidget25 = laArcWidget_New();
    laWidget_SetPosition((laWidget*)ArcWidget25, 211, 57);
    laWidget_SetSize((laWidget*)ArcWidget25, 10, 10);
    laWidget_SetScheme((laWidget*)ArcWidget25, &DataSeriesB);
    laWidget_SetBackgroundType((laWidget*)ArcWidget25, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ArcWidget25, LA_WIDGET_BORDER_NONE);
    laArcWidget_SetRadius(ArcWidget25, 10);
    laArcWidget_SetCenterAngle(ArcWidget25, 360);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ArcWidget25);

    CheckBoxPhantomButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)CheckBoxPhantomButton, 260, 50);
    laWidget_SetSize((laWidget*)CheckBoxPhantomButton, 80, 25);
    laWidget_SetScheme((laWidget*)CheckBoxPhantomButton, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)CheckBoxPhantomButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CheckBoxPhantomButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetToggleable(CheckBoxPhantomButton, LA_TRUE);
    laButtonWidget_SetPressed(CheckBoxPhantomButton, LA_TRUE);
    laButtonWidget_SetPressedEventCallback(CheckBoxPhantomButton, &CheckBoxPhantomButton_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(CheckBoxPhantomButton, &CheckBoxPhantomButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer0, (laWidget*)CheckBoxPhantomButton);

    CheckBoxWidget17 = laCheckBoxWidget_New();
    laWidget_SetPosition((laWidget*)CheckBoxWidget17, 5, 0);
    laWidget_SetSize((laWidget*)CheckBoxWidget17, 65, 25);
    laWidget_SetScheme((laWidget*)CheckBoxWidget17, &defaultPaletteScheme);
    laWidget_SetBackgroundType((laWidget*)CheckBoxWidget17, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CheckBoxWidget17, LA_WIDGET_BORDER_NONE);
    laCheckBoxWidget_SetChecked(CheckBoxWidget17, LA_TRUE);
    laCheckBoxWidget_SetText(CheckBoxWidget17, laString_CreateFromID(string_Fill));
    laCheckBoxWidget_SetCheckedEventCallback(CheckBoxWidget17, &CheckBoxWidget17_CheckedEvent);
    laCheckBoxWidget_SetUncheckedEventCallback(CheckBoxWidget17, &CheckBoxWidget17_UncheckedEvent);

    laWidget_AddChild((laWidget*)CheckBoxPhantomButton, (laWidget*)CheckBoxWidget17);

}



