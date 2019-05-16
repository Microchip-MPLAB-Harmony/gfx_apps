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

#include "gfx/libaria/libaria_events.h"
#include "app.h"

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





