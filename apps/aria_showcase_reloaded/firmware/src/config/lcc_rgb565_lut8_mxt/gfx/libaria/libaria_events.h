/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Definitions Header

  File Name:
    libaria_events.h

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
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _LIBARIA_EVENTS_H
#define _LIBARIA_EVENTS_H

#include "gfx/libaria/libaria.h"
#include "gfx/libaria/libaria_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

// Generated Event Handler - Origin: ArcWidgetButton, Event: ReleasedEvent
void ArcWidgetButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: CircularSliderButton, Event: ReleasedEvent
void CircularSliderButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: CircularGaugeButton, Event: ReleasedEvent
void CircularGaugeButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: PieChartButton, Event: ReleasedEvent
void PieChartButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: BarGraphDemoButton, Event: ReleasedEvent
void BarGraphDemoButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: LineGraphDemoButton, Event: ReleasedEvent
void LineGraphDemoButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: StartArcDemoButtonWidget, Event: PressedEvent
void StartArcDemoButtonWidget_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: StartArcDemoButtonWidget, Event: ReleasedEvent
void StartArcDemoButtonWidget_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: NextButton_ArcDemo, Event: ReleasedEvent
void NextButton_ArcDemo_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: HomeButton_ArcDemo, Event: PressedEvent
void HomeButton_ArcDemo_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: CircularSliderWidgetControl, Event: ValueChangedEvent
void CircularSliderWidgetControl_ValueChangedEvent(laCircularSliderWidget * slider, int32_t value);

// Generated Event Handler - Origin: CircSlider_NextButton, Event: ReleasedEvent
void CircSlider_NextButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: CircSlider_HomeButton, Event: ReleasedEvent
void CircSlider_HomeButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: CircGauge_NextButton, Event: ReleasedEvent
void CircGauge_NextButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: CircGauge_HomeButton, Event: ReleasedEvent
void CircGauge_HomeButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: GasButton, Event: PressedEvent
void GasButton_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: GasButton, Event: ReleasedEvent
void GasButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: PieChart_NextButton, Event: ReleasedEvent
void PieChart_NextButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: PieChartWidget2, Event: PressedEvent
void PieChartWidget2_PressedEvent(laPieChartWidget * chart, uint32_t value);

// Generated Event Handler - Origin: PieChart_HomeButton, Event: ReleasedEvent
void PieChart_HomeButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: BarGraph_NextButton, Event: ReleasedEvent
void BarGraph_NextButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: BarGraph_HomeButton, Event: ReleasedEvent
void BarGraph_HomeButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: LineGraphTouchedButton, Event: PressedEvent
void LineGraphTouchedButton_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: LineGraphTouchedButton, Event: ReleasedEvent
void LineGraphTouchedButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: LineGraph_HomeButton, Event: ReleasedEvent
void LineGraph_HomeButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: LineGraph_NextButton, Event: ReleasedEvent
void LineGraph_NextButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: CheckBoxPhantomButton, Event: PressedEvent
void CheckBoxPhantomButton_PressedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: CheckBoxPhantomButton, Event: ReleasedEvent
void CheckBoxPhantomButton_ReleasedEvent(laButtonWidget* btn);

// Generated Event Handler - Origin: CheckBoxWidget17, Event: CheckedEvent
void CheckBoxWidget17_CheckedEvent(laCheckBoxWidget* cbox);

// Generated Event Handler - Origin: CheckBoxWidget17, Event: UncheckedEvent
void CheckBoxWidget17_UncheckedEvent(laCheckBoxWidget* cbox);



//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // _LIBARIA_EVENTS_H
/*******************************************************************************
 End of File
*/
