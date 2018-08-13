/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Implementation File

  File Name:
    libaria_events.c

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

//CUSTOM CODE - DO NOT MODIFY OR REMOVE!!
#include "app.h"
//END OF CUSTOM CODE

#include "gfx/libaria/libaria_events.h"

// ArcWidgetButton - ReleasedEvent
void ArcWidgetButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_ARC_PRIMITIVE_SCREEN);
}

// CircularSliderButton - ReleasedEvent
void CircularSliderButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_CIRCULAR_SLIDER_SCREEN);
}

// CircularGaugeButton - ReleasedEvent
void CircularGaugeButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_CIRCULAR_GAUGE_SCREEN);
}

// PieChartButton - ReleasedEvent
void PieChartButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_PIE_CHART_SCREEN);
}

// BarGraphDemoButton - ReleasedEvent
void BarGraphDemoButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_BAR_GRAPH_SCREEN);
}

// LineGraphDemoButton - ReleasedEvent
void LineGraphDemoButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_LINE_GRAPH_SCREEN);
}

// StartArcDemoButtonWidget - PressedEvent
void StartArcDemoButtonWidget_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_START_WIDGET_DEMO);
}

// StartArcDemoButtonWidget - ReleasedEvent
void StartArcDemoButtonWidget_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_STOP_WIDGET_DEMO);
}

// NextButton_ArcDemo - ReleasedEvent
void NextButton_ArcDemo_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_NEXT_SCREEN);
}

// HomeButton_ArcDemo - PressedEvent
void HomeButton_ArcDemo_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_MAIN_MENU);  
}

// CircularSliderWidgetControl - ValueChangedEvent
void CircularSliderWidgetControl_ValueChangedEvent(laCircularSliderWidget * slider, int32_t value)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_CIRCULAR_SLIDER_SET_VALUE_LABEL);
}

// CircSlider_NextButton - ReleasedEvent
void CircSlider_NextButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_NEXT_SCREEN);
}

// CircSlider_HomeButton - ReleasedEvent
void CircSlider_HomeButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_MAIN_MENU);  
}

// CircGauge_NextButton - ReleasedEvent
void CircGauge_NextButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_NEXT_SCREEN);
}

// CircGauge_HomeButton - ReleasedEvent
void CircGauge_HomeButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_MAIN_MENU);  
}

// GasButton - PressedEvent
void GasButton_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_CIRCULAR_GAUGE_GAS_PRESSED);
}

// GasButton - ReleasedEvent
void GasButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_CIRCULAR_GAUGE_GAS_RELEASED);
}

// PieChart_NextButton - ReleasedEvent
void PieChart_NextButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_NEXT_SCREEN);
}

// PieChartWidget2 - PressedEvent
void PieChartWidget2_PressedEvent(laPieChartWidget * chart, uint32_t value)
{
    // Custom Action
    APP_SendEventWithParam(APP_EVENT_PIE_CHART_PRESSED, (void *) value);
}

// PieChart_HomeButton - ReleasedEvent
void PieChart_HomeButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_MAIN_MENU);  
}

// BarGraph_NextButton - ReleasedEvent
void BarGraph_NextButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_NEXT_SCREEN);
}

// BarGraph_HomeButton - ReleasedEvent
void BarGraph_HomeButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_MAIN_MENU);  
}

// LineGraphTouchedButton - PressedEvent
void LineGraphTouchedButton_PressedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_START_WIDGET_DEMO);
}

// LineGraphTouchedButton - ReleasedEvent
void LineGraphTouchedButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_STOP_WIDGET_DEMO);
}

// LineGraph_HomeButton - ReleasedEvent
void LineGraph_HomeButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_MAIN_MENU);  
}

// LineGraph_NextButton - ReleasedEvent
void LineGraph_NextButton_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_SendEvent(APP_EVENT_GOTO_NEXT_SCREEN);
}

// CheckBoxPhantomButton - PressedEvent
void CheckBoxPhantomButton_PressedEvent(laButtonWidget* btn)
{
    // Set Check State (CheckBoxWidget17) - Set Check State - CheckBoxWidget17
    laCheckBoxWidget_SetChecked(CheckBoxWidget17, LA_TRUE);
}

// CheckBoxPhantomButton - ReleasedEvent
void CheckBoxPhantomButton_ReleasedEvent(laButtonWidget* btn)
{
    // Set Check State (CheckBoxWidget17) - Set Check State - CheckBoxWidget17
    laCheckBoxWidget_SetChecked(CheckBoxWidget17, LA_FALSE);
}

// CheckBoxWidget17 - CheckedEvent
void CheckBoxWidget17_CheckedEvent(laCheckBoxWidget* cbox)
{
    // Fill Series Area (LineGraphWidget13) - Fill Series Area - LineGraphWidget13
    laLineGraphWidget_SetFillSeriesArea((laLineGraphWidget*)LineGraphWidget13, LA_TRUE );
}

// CheckBoxWidget17 - UncheckedEvent
void CheckBoxWidget17_UncheckedEvent(laCheckBoxWidget* cbox)
{
    // Fill Series Area (LineGraphWidget13) - Fill Series Area - LineGraphWidget13
    laLineGraphWidget_SetFillSeriesArea((laLineGraphWidget*)LineGraphWidget13, LA_FALSE );
}





