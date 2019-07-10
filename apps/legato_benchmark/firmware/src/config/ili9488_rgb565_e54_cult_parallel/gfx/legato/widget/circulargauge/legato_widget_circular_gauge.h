/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_circular_gauge.h

  Summary:


  Description:
    This module implements circular gauge drawing widget functions.
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
//DOM-IGNORE-END

#ifndef LEGATO_WIDGET_CIRCULAR_GAUGE_H
#define LEGATO_WIDGET_CIRCULAR_GAUGE_H

#include "gfx/legato/common/legato_common.h"

#if LE_CIRCULARGAUGE_WIDGET_ENABLED == 1

#include "gfx/legato/core/legato_scheme.h"
#include "gfx/legato/datastructure/legato_array.h"
#include "gfx/legato/string/legato_dynamicstring.h"
#include "gfx/legato/widget/legato_widget.h"


// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

typedef struct leCircularGaugeWidget leCircularGaugeWidget;

// *****************************************************************************
/* Structure:
    leCircularGaugeWidgetDir

  Summary:
    Direction of the gauge

  Description:
    Direction of the gauge

  Remarks:
    None.
*/
typedef enum leCircularGaugeWidgetDir
{
    CIRCULAR_GAUGE_DIR_CLOCKWISE,
    CIRCULAR_GAUGE_DIR_COUNTER_CLOCKWISE,
} leCircularGaugeWidgetDir;

// *****************************************************************************
/* Structure:
    leCircularGaugeWidgetDir

  Summary:
    Direction of the gauge

  Description:
    Direction of the gauge

  Remarks:
    None.
*/
typedef enum leCircularGaugeWidgetLabelPosition
{
    CIRCULAR_GAUGE_LABEL_OUTSIDE,
    CIRCULAR_GAUGE_LABEL_INSIDE,
} leCircularGaugeWidgetLabelPosition;

// *****************************************************************************
/* Structure:
    leCircularGaugeWidgetArcType

  Summary:
    Type of arc

  Description:
    Type of arc

  Remarks:
    None.
*/
typedef enum leCircularGaugeWidgetArcType
{
    ANGLE_ARC,
    VALUE_ARC,
} leCircularGaugeWidgetArcType;

// *****************************************************************************
/* Function Pointer:
    leCircularGaugeWidget_ValueChangedEvent

  Summary:
    Value changed event function callback type
*/
typedef void (*leCircularGaugeWidget_ValueChangedEvent)(leCircularGaugeWidget*,
                                                        int32_t value);


// DOM-IGNORE-BEGIN

#define LE_CIRCULARGAUGEWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    uint32_t                 (*getRadius)(const THIS_TYPE* _this); \
    leResult                 (*setRadius)(THIS_TYPE* _this, uint32_t rad); \
    int32_t                  (*getStartAngle)(const THIS_TYPE* _this); \
    leResult                 (*setStartAngle)(THIS_TYPE* _this, int32_t ang); \
    int32_t                  (*getCenterAngle)(const THIS_TYPE* _this); \
    leResult                 (*setCenterAngle)(THIS_TYPE* _this, int32_t ang); \
    leResult                 (*addValueArc)(THIS_TYPE* _this, int32_t startVal, int32_t endVal, uint32_t rad, uint32_t thk, leScheme* schm); \
    leResult                 (*addAngularArc)(THIS_TYPE* _this, int32_t startAng, int32_t endAng, uint32_t rad, uint32_t thk, leScheme* schm); \
    leResult                 (*deleteArcs)(THIS_TYPE* _this); \
    leResult                 (*addMinorTicks)(THIS_TYPE* _this, int32_t startVal, int32_t endVal, uint32_t rad, uint32_t len, uint32_t interval, leScheme* schm); \
    leResult                 (*deleteMinorTicks)(THIS_TYPE* _this); \
    leResult                 (*addMinorTickLabels)(THIS_TYPE* _this, int32_t startVal, int32_t endVal, uint32_t rad, leCircularGaugeWidgetLabelPosition pos, uint32_t interval, leScheme* schm); \
    leResult                 (*deleteMinorTickLabels)(THIS_TYPE* _this); \
    int32_t                  (*getValue)(const THIS_TYPE* _this); \
    leResult                 (*setValue)(THIS_TYPE* _this, int32_t val); \
    int32_t                  (*getStartValue)(const THIS_TYPE* _this); \
    leResult                 (*setStartValue)(THIS_TYPE* _this, int32_t val); \
    int32_t                  (*getEndValue)(const THIS_TYPE* _this); \
    leResult                 (*setEndValue)(THIS_TYPE* _this, int32_t val); \
    leBool                   (*getTicksVisible)(const THIS_TYPE* _this); \
    leResult                 (*setTicksVisible)(THIS_TYPE* _this, leBool vis); \
    int32_t                  (*getTickValue)(const THIS_TYPE* _this); \
    leResult                 (*setTickValue)(THIS_TYPE* _this, int32_t val); \
    uint32_t                 (*getTickLength)(const THIS_TYPE* _this); \
    leResult                 (*setTickLength)(THIS_TYPE* _this, uint32_t len); \
    leBool                   (*getTickLabelsVisible)(const THIS_TYPE* _this); \
    leResult                 (*setTickLabelsVisible)(THIS_TYPE* _this, leBool vis); \
    leBool                   (*getHandVisible)(const THIS_TYPE* _this); \
    leResult                 (*setHandVisible)(THIS_TYPE* _this, leBool vis); \
    uint32_t                 (*getHandRadius)(const THIS_TYPE* _this); \
    leResult                 (*setHandRadius)(THIS_TYPE* _this, uint32_t rad); \
    leBool                   (*getCenterCircleVisible)(const THIS_TYPE* _this); \
    leResult                 (*setCenterCircleVisible)(THIS_TYPE* _this, leBool vis); \
    uint32_t                 (*getCenterCircleRadius)(const THIS_TYPE* _this); \
    leResult                 (*setCenterCircleRadius)(THIS_TYPE* _this, uint32_t rad); \
    uint32_t                 (*getCenterCircleThickness)(const THIS_TYPE* _this); \
    leResult                 (*setCenterCircleThickness)(THIS_TYPE* _this, uint32_t thk); \
    leResult                 (*setTickLabelFont)(THIS_TYPE* _this, const leFont* font); \
    leResult                 (*setValueChangedEventCallback)(THIS_TYPE* _this, leCircularGaugeWidget_ValueChangedEvent cb); \

typedef struct leCircularGaugeWidgetVTable
{
	LE_CIRCULARGAUGEWIDGET_VTABLE(leCircularGaugeWidget)
} leCircularGaugeWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leCircularGaugeWidget

  Summary:
    Implementation of a circular gauge widget.

  Description:
    A circular gauge widget draws a circular gauge of the specified properties
    inside the widget bounds.  All coordinates are expressed in local widget space.

  Remarks:
    None.
*/
typedef struct leCircularGaugeWidget
{
    leWidget widget; // base widget header
    
    leCircularGaugeWidgetVTable* fn;

    //Widget properties
    int32_t value;
    int32_t startValue;
    int32_t endValue;
    uint32_t radius; // the radius of the circular gauge
    uint32_t startAngle; //the start angle of the outer arc
    int32_t centerAngle; //the center angle of the outer arc
    leCircularGaugeWidgetDir dir; //the turn direction of the gauge

    //Tick properties
    leBool ticksVisible; // are ticks visible
    uint32_t tickLength; //length of ticks (towards center)
    int32_t tickValue; // tick value (delta)

    //Tick label properties
    leBool tickLabelsVisible; // are tick labels visible
    const leFont* ticksLabelFont; // ticks label font

    //hand properties
    leBool handVisible;
    uint32_t handRadius;
    leBool centerCircleVisible;
    uint32_t centerCircleRadius;
    uint32_t centerCircleThickness;

    //Advanced config arrays
    leArray arcsArray; //ArcsArray list
    leArray ticksArray; //ArcsArray list
    leArray labelsArray; //ArcsArray list


    leCircularGaugeWidget_ValueChangedEvent cb; //value changed event callback

} leCircularGaugeWidget;

// *****************************************************************************
/* Structure:
    leCircularGaugeArc

  Summary:
    Internal structure for the arcs in the circular gauge widget

  Description:
    Describs the arc instances in the circular gauge widget

  Remarks:
    None.
*/
typedef struct leCircularGaugeArc
{
    leCircularGaugeWidgetArcType type;
    int32_t startAngle;
    int32_t endAngle;
    int32_t startValue;
    int32_t endValue;
    uint32_t radius;
    uint32_t thickness;
    leScheme* scheme;
} leCircularGaugeArc;

// *****************************************************************************
/* Structure:
    leCircularGaugeTick

  Summary:
    Tick object for the circular gauge

  Description:
    Contains properties of the ticks in the gauge

  Remarks:
    None.
*/
typedef struct leCircularGaugeTick
{
    int32_t startValue;
    int32_t endValue;
    uint32_t interval;
    uint32_t radius;
    uint32_t length;
    leScheme* scheme;
} leCircularGaugeTick;

// *****************************************************************************
/* Structure:
    typedef struct leCircularGaugeLabel


  Summary:
    Label object for the circular gauge

  Description:
    Contains properties of the labels in the gauge

  Remarks:
    None.
*/
typedef struct leCircularGaugeLabel
{
    int32_t startValue;
    int32_t endValue;
    uint32_t interval;
    uint32_t radius;
    leCircularGaugeWidgetLabelPosition position;
    leScheme* scheme;
} leCircularGaugeLabel;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leCircularGaugeWidget* leCircularGaugeWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the management of this memory until the
    widget is added to a widget tree.

  Description:


  Parameters:
    void

  Returns:
    leCircularGaugeWidget*

  Remarks:

*/
LIB_EXPORT leCircularGaugeWidget* leCircularGaugeWidget_New();

LIB_EXPORT void leCircularGaugeWidget_Constructor(leCircularGaugeWidget* gauge);

#if 0
// *****************************************************************************
/* Function:
    uint32_t leCircularGaugeWidget_GetRadius(leCircularGaugeWidget* gauge)

  Summary:
    Gets the radius of a gauge widget

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircularGaugeWidget_GetRadius(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetRadius(leCircularGaugeWidget* gauge, uint32_t rad)

  Summary:
    Sets the radius of a gauge widget

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    uint32_t red - the desired radius value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetRadius(leCircularGaugeWidget* gauge, uint32_t rad);

// *****************************************************************************
/* Function:
    int32_t leCircularGaugeWidget_GetStartAngle(leCircularGaugeWidget* gauge)

  Summary:
    Returns the start angle of the circular gauge

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    int32_t

  Remarks:

*/
LIB_EXPORT int32_t leCircularGaugeWidget_GetStartAngle(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetStartAngle(leCircularGaugeWidget* gauge, int32_t angle)

  Summary:
    Sets the start angle of the gauge.

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    int32_t angle - start angle of the gauge

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetStartAngle(leCircularGaugeWidget* gauge, int32_t angle);

// *****************************************************************************
/* Function:
    int32_t leCircularGaugeWidget_GetCenterAngle(leCircularGaugeWidget* gauge)

  Summary:
    Returns the center angle of the circular gauge

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    int32_t

  Remarks:

*/
LIB_EXPORT int32_t leCircularGaugeWidget_GetCenterAngle(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetCenterAngle(leCircularGaugeWidget* gauge, int32_t angle)

  Summary:
    Sets the center angle of the gauge.

  Description:
    A positive center angle draws the gauge, ticks, and hand in CCW, while a negative center
    angle draws in CW.

  Parameters:
    leCircularGaugeWidget* gauge - the widget
    int32_t angle - center angle of the gauge

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetCenterAngle(leCircularGaugeWidget* gauge, int32_t angle);

// *****************************************************************************
/* Function:
    leCircularGaugeWidgetDir leCircularGaugeWidget_GetDirection(leCircularGaugeWidget* gauge)

  Summary:
    Returns the direction of the gauge.

  Description:
    The direction is automatically set to CW if the center angle is negative, and CCW if the
    center angle is positive.


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    leCircularGaugeWidgetDir

  Remarks:

*/
LIB_EXPORT leCircularGaugeWidgetDir leCircularGaugeWidget_GetDirection(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_AddValueArc(leCircularGaugeWidget* gauge,
                                               int32_t startValue,
                                               int32_t endValue,
                                               uint32_t radius,
                                               uint32_t thickness,
                                               leScheme* scheme)

  Summary:
    Adds a 'value arc' in the gauge.

  Description:
    Value arcs are drawn inside the gauge from the same origin/center but are
    bound by the start and end value of the gauge. A value arc that exceeds the start or
    end value of the gauge will not be drawn.

  Parameters:
    leCircularGaugeWidget* gauge - the widget
    int32_t startAngle - the start angle of the arc (relative to gauge starting angle)
    int32_t endAngle - the end angle of the arc (relative to gauge starting angle)
    uint32_t radius - the radius of the arc
    uint32_t thickness - the fill thickness of the arc
    leScheme* scheme - scheme used for drawing the arc


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_AddValueArc(leCircularGaugeWidget* gauge,
                                                      int32_t startValue,
                                                      int32_t endValue,
                                                      uint32_t radius,
                                                      uint32_t thickness,
                                                      leScheme* scheme);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_AddAngularArc(leCircularGaugeWidget* gauge,
                                                 int32_t startAngle,
                                                 int32_t endAngle,
                                                 uint32_t radius,
                                                 uint32_t thickness,
                                                 leScheme* scheme)

  Summary:
    Adds an 'angular arc' in the gauge.

  Description:
    Angular arcs are drawn inside the gauge from the same origin/center but are
    not bound by the start/end angle/value of the gauge.

  Parameters:
    leCircularGaugeWidget* gauge - the widget
    int32_t startAngle - the start angle of the arc (relative to gauge starting angle)
    int32_t endAngle - the end angle of the arc (relative to gauge starting angle)
    uint32_t radius - the radius of the arc
    uint32_t thickness - the fill thickness of the arc
    leScheme* scheme - scheme used for drawing the arc


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_AddAngularArc(leCircularGaugeWidget* gauge,
                                                        int32_t startAngle,
                                                        int32_t endAngle,
                                                        uint32_t radius,
                                                        uint32_t thickness,
                                                        leScheme* scheme);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_DeleteArcs(leCircularGaugeWidget* gauge)

  Summary:
    Deletes all arcs in the gauge widget

  Description:
    Deletes all arcs in the gauge widget

  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_DeleteArcs(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leCircularGaugeWidget_AddMinorTicks(leCircularGaugeWidget* gauge,
                                      int32_t startValue,
                                      int32_t endValue,
                                      uint32_t radius,
                                      uint32_t length,
                                      uint32_t interval,
                                      leScheme* scheme)

  Summary:
    Adds minor ticks in the gauge.

  Description:

  Parameters:
    leCircularGaugeWidget* gauge - the widget
    int32_t startValue - the start value of the ticks (must be within gauge range)
    int32_t endValue - the end value of the ticks (must be within gauge range)
    uint32_t radius - the radius of the ticks
    uint32_t length - the length of the ticks (drawn inward towards center)
    uint32_t interval - the interval between ticks
    leScheme* scheme - scheme used for drawing the tick (uses foreground)


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_AddMinorTicks(leCircularGaugeWidget* gauge,
                                                        int32_t startValue,
                                                        int32_t endValue,
                                                        uint32_t radius,
                                                        uint32_t length,
                                                        uint32_t interval,
                                                        leScheme* scheme);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_DeleteMinorTicks(leCircularGaugeWidget* gauge)

  Summary:
    Deletes all the minor ticks in the gauge widget

  Description:
    Deletes all the minor ticks in the gauge widget

  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_DeleteMinorTicks(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    lleResult leCircularGaugeWidget_AddMinorTickLabels(leCircularGaugeWidget* gauge,
                                      int32_t startValue,
                                      int32_t endValue,
                                      uint32_t radius,
                                      leCircularGaugeWidgetLabelPosition position,
                                      uint32_t interval,
                                      leScheme* scheme)

  Summary:
    Adds minor tick labels in the gauge.

  Description:

  Parameters:
    leCircularGaugeWidget* gauge - the widget
    int32_t startValue - the start value of the reference tick points (must be within gauge range)
    int32_t endValue - the end value of the reference tick points (must be within gauge range)
    uint32_t radius - the radius of the reference tick points
    uint32_t position - the position of the label relative to the tick points
    uint32_t interval - the interval between ticks
    leScheme* scheme - scheme used for drawing the tick (uses foreground)


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_AddMinorTickLabels(leCircularGaugeWidget* gauge,
                                                             int32_t startValue,
                                                             int32_t endValue,
                                                             uint32_t radius,
                                                             leCircularGaugeWidgetLabelPosition position,
                                                             uint32_t interval,
                                                             leScheme* scheme);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_DeleteMinorTickLabels(leCircularGaugeWidget* gauge)

  Summary:
    Deletes all the minor tick labels in the gauge widget

  Description:
    Deletes all the tick labels in the gauge widget

  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_DeleteMinorTickLabels(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    int32_t leCircularGaugeWidget_GetValue(leCircularGaugeWidget* gauge)

  Summary:
    Returns the value of the gauge hand

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    int32_t

  Remarks:

*/
LIB_EXPORT int32_t leCircularGaugeWidget_GetValue(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetValue(leCircularGaugeWidget* gauge,
                                            int32_t value)

  Summary:
    Sets the value of the gauge hand

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    int32_t value - value of the gauge hand


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetValue(leCircularGaugeWidget* gauge,
                                                   int32_t value);

// *****************************************************************************
/* Function:
    int32_t leCircularGaugeWidget_GetStartValue(leCircularGaugeWidget* gauge)

  Summary:
    Returns the start value of the gauge

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    int32_t

  Remarks:

*/
LIB_EXPORT int32_t leCircularGaugeWidget_GetStartValue(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetStartValue(leCircularGaugeWidget* gauge,
                                               int32_t value)

  Summary:
    Sets the start value of the gauge

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    int32_t value - start value of the gauge


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetStartValue(leCircularGaugeWidget* gauge,
                                                        int32_t value);

// *****************************************************************************
/* Function:
    int32_t leCircularGaugeWidget_GetEndValue(leCircularGaugeWidget* gauge)

  Summary:
    Returns the end value of the gauge

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    int32_t

  Remarks:

*/
LIB_EXPORT int32_t leCircularGaugeWidget_GetEndValue(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetEndValue(leCircularGaugeWidget* gauge,
                                               int32_t value)

  Summary:
    Sets the end value of the gauge

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    int32_t value - end value of the gauge


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetEndValue(leCircularGaugeWidget* gauge,
                                                      int32_t value);

// *****************************************************************************
/* Function:
    leBool leCircularGaugeWidget_GetTicksVisible(leCircularGaugeWidget* gauge)

  Summary:
    Returns LE_TRUE if the ticks in the gauge are visible

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    leBool

  Remarks:

*/
LIB_EXPORT leBool leCircularGaugeWidget_GetTicksVisible(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leCircularGaugeWidget_SetTicksVisible(leCircularGaugeWidget* gauge,
                                       leBool visible)

  Summary:
    Sets the increments/distance between ticks

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    int32_t value - the distance between ticks


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetTicksVisible(leCircularGaugeWidget* gauge,
                                                          leBool visible);

// *****************************************************************************
/* Function:
    int32_t leCircularGaugeWidget_GetTickValue(leCircularGaugeWidget* gauge)

  Summary:
    Returns the tick increment value in the gauge

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    int32_t

  Remarks:

*/
LIB_EXPORT int32_t leCircularGaugeWidget_GetTickValue(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetTickValue(leCircularGaugeWidget* gauge,
                                       int32_t value)

  Summary:
    Sets the increments/distance between ticks

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    int32_t value - the distance between ticks


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetTickValue(leCircularGaugeWidget* gauge,
                                                       int32_t value);

// *****************************************************************************
/* Function:
    uint32_t leCircularGaugeWidget_GetTickLength(leCircularGaugeWidget* gauge)

  Summary:
    Returns the length of the ticks in the gauge in pixels

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircularGaugeWidget_GetTickLength(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetTickLength(leCircularGaugeWidget* gauge,
                                         uint32_t length)

  Summary:
    Sets the length of the ticks

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    uint32_t length - length of the ticks in pixels


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetTickLength(leCircularGaugeWidget* gauge,
                                                        uint32_t length);

// *****************************************************************************
/* Function:
    leBool leCircularGaugeWidget_GetTickLabelsVisible(leCircularGaugeWidget* gauge)

  Summary:
    Returns LE_TRUE if the tick labels are visible

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    leBool

  Remarks:

*/
LIB_EXPORT leBool leCircularGaugeWidget_GetTickLabelsVisible(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetTickLabelsVisible(leCircularGaugeWidget* gauge,
                                               leBool visible)

  Summary:
    Sets the tick labels visible/invisible

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    leBool visible - tick labels are visible if LE_TRUE


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetTickLabelsVisible(leCircularGaugeWidget* gauge,
                                                               leBool visible);

// *****************************************************************************
/* Function:
    leBool leCircularGaugeWidget_GetHandVisible(leCircularGaugeWidget* gauge)

  Summary:
    Returns LE_TRUE if the gauge hand is visible

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    leBool

  Remarks:

*/
LIB_EXPORT leBool leCircularGaugeWidget_GetHandVisible(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetHandVisible(leCircularGaugeWidget* gauge,
                                         leBool visible)

  Summary:
    Sets the hand visible/invisible

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    leBool visible - hand is visible if LE_TRUE


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetHandVisible(leCircularGaugeWidget* gauge,
                                                         leBool visible);

// *****************************************************************************
/* Function:
    uint32_t leCircularGaugeWidget_GetHandRadius(leCircularGaugeWidget* gauge)

  Summary:
    Returns the radius/length of the gauge hand in pixels

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircularGaugeWidget_GetHandRadius(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetHandRadius(leCircularGaugeWidget* gauge,
                                        uint32_t length)

  Summary:
    Sets the radius/length of the hand

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    uint32_t length - length of the hand in pixels


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetHandRadius(leCircularGaugeWidget* gauge,
                                                        uint32_t rad);

// *****************************************************************************
/* Function:
    leBool leCircularGaugeWidget_GetCenterCircleVisible(leCircularGaugeWidget* gauge)

  Summary:
    Returns LE_TRUE if the center circle is visible

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    leBool

  Remarks:

*/
LIB_EXPORT leBool leCircularGaugeWidget_GetCenterCircleVisible(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetCenterCircleVisible(leCircularGaugeWidget* gauge,
                                                 leBool visible)

  Summary:
    Sets the center circle visible/invisible

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    leBool visible - sets visible if LE_TRUE


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetCenterCircleVisible(leCircularGaugeWidget* gauge,
                                                                 leBool visible);

// *****************************************************************************
/* Function:
    uint32_t leCircularGaugeWidget_GetCenterCircleRadius(leCircularGaugeWidget* gauge)

  Summary:
    Returns radius of the center circle

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircularGaugeWidget_GetCenterCircleRadius(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetCenterCircleRadius(leCircularGaugeWidget* gauge,
                                                            uint32_t rad)

  Summary:
    Sets the center radius of the center circle

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    uint32_t rad - radius of the center circle


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetCenterCircleRadius(leCircularGaugeWidget* gauge,
                                                                uint32_t rad);

// *****************************************************************************
/* Function:
    uint32_t leCircularGaugeWidget_GetCenterCircleThickness(leCircularGaugeWidget* gauge)

  Summary:
    Returns thickness of the center circle

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircularGaugeWidget_GetCenterCircleThickness(leCircularGaugeWidget* gauge);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetCenterCircleThickness(leCircularGaugeWidget* gauge,
                                                            uint32_t thickness)

  Summary:
    Sets the thickness of the center circle

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    uint32_t thickness - thickness of the center circle


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetCenterCircleThickness(leCircularGaugeWidget* gauge,
                                                                   uint32_t thickness);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetStringTable(leCircularGaugeWidget* gauge,
                                                  leStringTable * stringTable)

  Summary:
    Sets the string table to be used for the tick labels

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    leStringTable * stringTable - pointer to the string table


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetStringTable(leCircularGaugeWidget* gauge,
                                                         leStringTable * stringTable);

// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetTicksLabelsStringID(leCircularGaugeWidget* gauge,
                                                          uint32_t stringID)

  Summary:
    Sets the ID of the string character superset to be used for the tick labels

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    uint32_t stringID - string ID


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetTicksLabelsStringID(leCircularGaugeWidget* gauge,
                                                                 uint32_t stringID);


// *****************************************************************************
/* Function:
    leResult leCircularGaugeWidget_SetValueChangedEventCallback(leCircularGaugeWidget* gauge,
                                                                 leCircularGaugeWidget_ValueChangedEvent cb)

  Summary:
    Sets the function to be called back when the gauge value changes.

  Description:


  Parameters:
    leCircularGaugeWidget* gauge - the widget
    leCircularGaugeWidget_ValueChangedEvent cb - callback function


  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularGaugeWidget_SetValueChangedEventCallback(leCircularGaugeWidget* gauge,
                                                                        leCircularGaugeWidget_ValueChangedEvent cb);

#endif
#endif // LE_CIRCULARGAUGE_WIDGET_ENABLED
#endif /* LEGATO_WIDGET_CIRCULAR_GAUGE_H */