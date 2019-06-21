/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_circular_slider.h

  Summary:


  Description:
    This module implements slider drawing widget functions.
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

#ifndef LEGATO_WIDGET_CIRCULAR_SLIDER_H
#define LEGATO_WIDGET_CIRCULAR_SLIDER_H

#include "gfx/legato/common/legato_common.h"

#if LE_CIRCULAR_SLIDER_WIDGET_ENABLED

#include "gfx/legato/widget/legato_widget.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Structure:
    leCircularSliderWidgetDir

  Summary:
    Direction of the slider

  Description:
    Direction of the slider

  Remarks:
    None.
*/
typedef enum leCircularSliderWidgetDir
{
    CIRCULAR_SLIDER_DIR_COUNTER_CLOCKWISE,
    CIRCULAR_SLIDER_DIR_CLOCKWISE,
} leCircularSliderWidgetDir;

// *****************************************************************************
/* Structure:
    leCircularSliderButtonState

  Summary:
    State of the slider button

  Description:
    State of the slider button

  Remarks:
    None.
*/
typedef enum leCircularSliderButtonState
{
    LE_CIRCULAR_SLIDER_STATE_UP,
    LE_CIRCULAR_SLIDER_STATE_DOWN,
} leCircularSliderButtonState;

// *****************************************************************************
/* Enumeration:
    leCircularSliderWidgetArcType

  Summary:
    The arcs that compose the circular slider

  Description:
    The arcs that compose the circular slider

  Remarks:
    None.
*/
typedef enum leCircularSliderWidgetArcType
{
    OUTSIDE_CIRCLE_BORDER,
    INSIDE_CIRCLE_BORDER,
    ACTIVE_AREA,
    INACTIVE_AREA,
    CIRCLE_BUTTON,
} leCircularSliderWidgetArcType;

// *****************************************************************************
/* Structure:
    leCircularSliderArc

  Summary:
    Internal structure for the arcs in the circular slider widget

  Description:
    Describs the arc instances in the circular gauge widget

  Remarks:
    None.
*/
typedef struct leCircularSliderArc
{
    leBool visible;
    int32_t startAngle;
    int32_t centerAngle;
    uint32_t radius;
    uint32_t thickness;
    const leScheme* scheme;
} leCircularSliderArc;

typedef struct leCircularSliderWidget leCircularSliderWidget;

// *****************************************************************************
/* Function Pointer:
    leCircularSliderWidget_PressedEvent

  Summary:
    Button pressed event function callback type
*/
typedef void (*leCircularSliderWidget_PressedEvent)(leCircularSliderWidget *, int32_t);

// *****************************************************************************
/* Function Pointer:
    leCircularSliderWidget_ValueChangedEvent

  Summary:
    Value changed event function callback type
*/
typedef void (*leCircularSliderWidget_ValueChangedEvent)(leCircularSliderWidget *, int32_t);

// *****************************************************************************
/* Function Pointer:
    leCircularSliderWidget_ReleasedEvent

  Summary:
    Button released event function callback type
*/
typedef void (*leCircularSliderWidget_ReleasedEvent)(leCircularSliderWidget *, int32_t);

// DOM-IGNORE-BEGIN

#define LE_CIRCULARSLIDERWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    uint32_t                 (*getRadius)(const THIS_TYPE* _this); \
    leResult                 (*setRadius)(THIS_TYPE* _this, uint32_t rad); \
    uint32_t                 (*getStartAngle)(const THIS_TYPE* _this); \
    leResult                 (*setStartAngle)(THIS_TYPE* _this, uint32_t ang); \
    uint32_t                 (*getArcThickness)(const THIS_TYPE* _this, leCircularSliderWidgetArcType type); \
    leResult                 (*setArcThickness)(THIS_TYPE* _this, leCircularSliderWidgetArcType type, uint32_t thck); \
    uint32_t                 (*getArcRadius)(const THIS_TYPE* _this, leCircularSliderWidgetArcType type); \
    leResult                 (*setArcRadius)(THIS_TYPE* _this, leCircularSliderWidgetArcType type, uint32_t rad); \
    leScheme*                (*getArcScheme)(const THIS_TYPE* _this, leCircularSliderWidgetArcType type); \
    leResult                 (*setArcScheme)(THIS_TYPE* _this, leCircularSliderWidgetArcType type, const leScheme* schm); \
    leBool                   (*getArcVisible)(const THIS_TYPE* _this, leCircularSliderWidgetArcType type); \
    leResult                 (*setArcVisible)(THIS_TYPE* _this, leCircularSliderWidgetArcType type, leBool vis); \
    uint32_t                 (*getStartValue)(const THIS_TYPE* _this); \
    leResult                 (*setStartValue)(THIS_TYPE* _this, uint32_t val); \
    uint32_t                 (*getEndValue)(const THIS_TYPE* _this); \
    leResult                 (*setEndValue)(THIS_TYPE* _this, uint32_t val); \
    uint32_t                 (*getValue)(const THIS_TYPE* _this); \
    leResult                 (*setValue)(THIS_TYPE* _this, uint32_t val); \
    leBool                   (*getRoundEdges)(const THIS_TYPE* _this); \
    leResult                 (*setRoundEdges)(THIS_TYPE* _this, leBool rnd); \
    leBool                   (*getStickyButton)(const THIS_TYPE* _this); \
    leResult                 (*setStickyButton)(THIS_TYPE* _this, leBool stk); \
    leBool                   (*getTouchOnButtonOnly)(const THIS_TYPE* _this); \
    leResult                 (*setTouchOnButtonOnly)(THIS_TYPE* _this, leBool tch); \
    leCircularSliderWidgetDir (*getDirection)(const THIS_TYPE* _this); \
    leResult                 (*setDirection)(THIS_TYPE* _this, leCircularSliderWidgetDir dir); \
    leResult                 (*setPressedEventCallback)(THIS_TYPE* _this, leCircularSliderWidget_PressedEvent cb); \
    leResult                 (*setValueChangedEventCallback)(THIS_TYPE* _this, leCircularSliderWidget_ValueChangedEvent cb); \
    leResult                 (*setReleasedEventCallback)(THIS_TYPE* _this, leCircularSliderWidget_ReleasedEvent cb); \

typedef struct leCircularSliderWidgetVTable
{
	LE_CIRCULARSLIDERWIDGET_VTABLE(leCircularSliderWidget)
} leCircularSliderWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leCircularSliderWidget

  Summary:
    Implementation of a slider widget.

  Description:
    A slider widget draws a slider of the specified origin and radius inside
    the widget bounds.  All coordinates are expressed in local widget space.

    The color of the slider is determined by the widget scheme's 'foreground'
    color.

  Remarks:
    None.
*/
typedef struct leCircularSliderWidget
{
    leWidget widget; // base widget header
    
    leCircularSliderWidgetVTable* fn;

    uint32_t radius; // the radius of the slider

    uint32_t startAngle; //the start angle of the slider

    uint32_t value;      //the value of the slider
    uint32_t startValue; //the start value of the slider
    uint32_t endValue;   //the end value of the slider
    float degPerUnit;   //degrees per unit in the slider

    leBool roundEdges; //round edges
    leBool sticky; //snaps to start value before wrapping around
    leBool buttonTouch; //only button is active to touch

    leCircularSliderWidgetDir direction;    //the direction of the slider

    leCircularSliderArc activeArc;            //the arc for the slider value
    leCircularSliderArc inActiveArc;          //the arc for the slider remainder
    leCircularSliderArc outsideBorderArc;     //the arc for the outside border
    leCircularSliderArc insideBorderArc;      //the arc for the inside border
    leCircularSliderArc circleButtonArc;      //the arc for the circle button

    leCircularSliderButtonState btnState;   //the state of the circular slider button

    leCircularSliderWidget_PressedEvent pressedCallback;
    leCircularSliderWidget_ValueChangedEvent valueChangedCallback;
    leCircularSliderWidget_ReleasedEvent releasedCallback;
} leCircularSliderWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leCircularSliderWidget* leCircularSliderWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the management of this memory until the
    widget is added to a widget tree.

  Description:


  Parameters:
    void

  Returns:
    leCircularSliderWidget*

  Remarks:

*/
LIB_EXPORT leCircularSliderWidget* leCircularSliderWidget_New();

LIB_EXPORT void leCircularSliderWidget_Constructor(leCircularSliderWidget* slider);

#if 0
// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_GetOrigin(leCircularSliderWidget* slider, int32_t* x, int32_t* y)

  Summary:
    Gets the origin coordinates of a slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    int32_t* x - pointer to an integer pointer to store x
    int32_t* y - pointer to an integer pointer to store y

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_GetOrigin(leCircularSliderWidget* slider, int32_t* x, int32_t* y);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetOrigin(leCircularSliderWidget* slider, int32_t x, int32_t y)

  Summary:
    Sets the origin coordiates of a slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    int32_t x - the desired x origin coordinate
    int32_t y - the desired y origin coordinate

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetOrigin(leCircularSliderWidget* slider, int32_t x, int32_t y);

// *****************************************************************************
/* Function:
    uint32_t leCircularSliderWidget_GetRadius(leCircularSliderWidget* slider)

  Summary:
    Gets the radius of a slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircularSliderWidget_GetRadius(leCircularSliderWidget* slider);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetRadius(leCircularSliderWidget* slider, uint32_t rad)

  Summary:
    Sets the radius of a slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    uint32_t red - the desired radius value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetRadius(leCircularSliderWidget* slider, uint32_t rad);

// *****************************************************************************
/* Function:
    int32_t leCircularSliderWidget_GetStartAngle(leCircularSliderWidget* slider)

  Summary:
    Returns the start angle of a slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircularSliderWidget_GetStartAngle(leCircularSliderWidget* slider);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetStartAngle(leCircularSliderWidget* slider, int32_t angle)

  Summary:
    Sets the start angle of a slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    int32_t angle - the desired start angle value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetStartAngle(leCircularSliderWidget* slider, uint32_t angle);

// *****************************************************************************
/* Function:
    uint32_t leCircularSliderWidget_GetArcThickness(leCircularSliderWidget* slider, leCircularSliderWidgetArcType type)

  Summary:
    Returns the thickness of an arc in the slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    leCircularSliderWidgetArcType type - the type of arc

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircularSliderWidget_GetArcThickness(leCircularSliderWidget* slider,
                                                           leCircularSliderWidgetArcType type);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetArcThickness(leCircularSliderWidget* slider,
                                                    leCircularSliderWidgetArcType type,
                                                    uint32_t thickness)

  Summary:
    Sets the thickness of an arc in the slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    leCircularSliderWidgetArcType type - the type of arc
    uint32_t thickness - the thickness of the arc

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetArcThickness(leCircularSliderWidget* slider,
                                                           leCircularSliderWidgetArcType type,
                                                           uint32_t thickness);

// *****************************************************************************
/* Function:
    uint32_t leCircularSliderWidget_GetArcRadius(leCircularSliderWidget* slider, leCircularSliderWidgetArcType type)

  Summary:
    Returns the radius of an arc in the slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    leCircularSliderWidgetArcType type - the type of arc

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircularSliderWidget_GetArcRadius(leCircularSliderWidget* slider,
                                                        leCircularSliderWidgetArcType type);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetStartValue(leCircularSliderWidget* slider, uint32_t value)

  Summary:
    Sets the start value of the slider widget

  Description:

  Parameters:
    leCircularSliderWidget* slider - the widget
    uint32_t value

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetArcRadius(leCircularSliderWidget* slider,
                                                        leCircularSliderWidgetArcType type,
                                                        uint32_t radius);

// *****************************************************************************
/* Function:
    leScheme * leCircularSliderWidget_GetArcScheme(leCircularSliderWidget* slider, leCircularSliderWidgetArcType type)

  Summary:
    Returns the scheme of an arc in the slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    leCircularSliderWidgetArcType type - the type of arc

  Returns:
    leScheme *

  Remarks:

*/
LIB_EXPORT leScheme * leCircularSliderWidget_GetArcScheme(leCircularSliderWidget* slider,
                                                          leCircularSliderWidgetArcType type);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetArcScheme(leCircularSliderWidget* slider,
                                                        leCircularSliderWidgetArcType type,
                                                        leScheme * scheme)

  Summary:
    Sets the scheme of the specified arc

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    leCircularSliderWidgetArcType type - the type of arc
    leScheme * scheme - scheme

  Returns:
    leBool

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetArcScheme(leCircularSliderWidget* slider,
                                                        leCircularSliderWidgetArcType type,
                                                        leScheme * scheme);

// *****************************************************************************
/* Function:
    leBool leCircularSliderWidget_GetArcVisible(leCircularSliderWidget* slider, leCircularSliderWidgetArcType type)

  Summary:
    Returns true if the specified arc is visible

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    leCircularSliderWidgetArcType type - the type of arc

  Returns:
    leBool

  Remarks:

*/
LIB_EXPORT leBool leCircularSliderWidget_GetArcVisible(leCircularSliderWidget* slider,
                                                         leCircularSliderWidgetArcType type);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetArcVisible(leCircularSliderWidget* slider,
                                                         leCircularSliderWidgetArcType type,
                                                         leBool visible)

  Summary:
    Shows/Hides the specified arc visible

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    leCircularSliderWidgetArcType type - the type of arc
    leBool visible - show/hide

  Returns:
    leBool

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetArcVisible(leCircularSliderWidget* slider,
                                                         leCircularSliderWidgetArcType type,
                                                         leBool visible);

// *****************************************************************************
/* Function:
    uint32_t leCircularSliderWidget_GetStartValue(leCircularSliderWidget* slider)

  Summary:
    Gets the start value of the slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircularSliderWidget_GetStartValue(leCircularSliderWidget* slider);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetStartValue(leCircularSliderWidget* slider, uint32_t value)

  Summary:
    Sets the start value of the slider widget

  Description:

  Parameters:
    leCircularSliderWidget* slider - the widget
    uint32_t value

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetStartValue(leCircularSliderWidget* slider, uint32_t value);

// *****************************************************************************
/* Function:
    uint32_t leCircularSliderWidget_GetEndValue(leCircularSliderWidget* slider)

  Summary:
    Gets the end value of the slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircularSliderWidget_GetEndValue(leCircularSliderWidget* slider);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetEndValue(leCircularSliderWidget* slider, uint32_t value)

  Summary:
    Sets the end value of the slider widget

  Description:

  Parameters:
    leCircularSliderWidget* slider - the widget
    uint32_t value

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetEndValue(leCircularSliderWidget* slider, uint32_t value);

// *****************************************************************************
/* Function:
    uint32_t leCircularSliderWidget_GetValue(leCircularSliderWidget* slider)

  Summary:
    Gets the value of the slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircularSliderWidget_GetValue(leCircularSliderWidget* slider);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetValue(leCircularSliderWidget* slider, uint32_t value)

  Summary:
    Sets the value of the slider widget

  Description:

  Parameters:
    leCircularSliderWidget* slider - the widget
    uint32_t value

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetValue(leCircularSliderWidget* slider, uint32_t value);

// *****************************************************************************
/* Function:
    leBool leCircularSliderWidget_GetRoundEdges(leCircularSliderWidget* slider)

  Summary:
    Returns true if the slider has rounded edges

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget

  Returns:
    leBool

  Remarks:

*/
LIB_EXPORT leBool leCircularSliderWidget_GetRoundEdges(leCircularSliderWidget* slider);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetRoundEdges(leCircularSliderWidget* slider, leBool round)

  Summary:
    If round = true, the slider active area edges are round

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    leBool round

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetRoundEdges(leCircularSliderWidget* slider, leBool round);

// *****************************************************************************
/* Function:
    leBool leCircularSliderWidget_GetStickyButton(leCircularSliderWidget* slider)

  Summary:
    Returns true if the slider button sticks to the start/end value

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget

  Returns:
    leBool

  Remarks:

*/
LIB_EXPORT leBool leCircularSliderWidget_GetStickyButton(leCircularSliderWidget* slider);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetStickyButton(leCircularSliderWidget* slider, leBool c)

  Summary:
    If snap = true, the slider button sticks to the start/end value of the slider

  Description:
    When sticky is enabled, the slider button will not immediately wrap past the start or end value
    if the button is dragged past the start angle. If the button is dragged past the threshold of 90 degrees
    beyond the start angle, only then will the slider value wrap around.


  Parameters:
    leCircularSliderWidget* slider - the widget
    leBool sticky - set button as sticky

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetStickyButton(leCircularSliderWidget* slider, leBool sticky);


// *****************************************************************************
/* Function:
    leCircularSliderWidgetDir leCircularSliderWidget_GetDirection(leCircularSliderWidget* slider)

  Summary:
    Returns direction of the slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget

  Returns:
    leCircularSliderWidgetDir

  Remarks:

*/

// *****************************************************************************
/* Function:
    leBool leCircularSliderWidget_GetTouchOnButtonOnly(leCircularSliderWidget* slider)

  Summary:
    Returns true if the slider slider only responds to touch inside the button area

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget

  Returns:
    leBool

  Remarks:

*/
LIB_EXPORT leBool leCircularSliderWidget_GetTouchOnButtonOnly(leCircularSliderWidget* slider);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetTouchOnButtonOnly(leCircularSliderWidget* slider, leBool buttonOnly)

  Summary:
    If buttonOnly = true, the slider will only respond to touches inside the button area

  Description:

  Parameters:
    leCircularSliderWidget* slider - the widget
    leBool buttonOnly - set touch to button only

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetTouchOnButtonOnly(leCircularSliderWidget* slider, leBool buttonOnly);


// *****************************************************************************
/* Function:
    leCircularSliderWidgetDir leCircularSliderWidget_GetDirection(leCircularSliderWidget* slider)

  Summary:
    Returns direction of the slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget

  Returns:
    leCircularSliderWidgetDir

  Remarks:

*/

LIB_EXPORT leCircularSliderWidgetDir leCircularSliderWidget_GetDirection(leCircularSliderWidget* slider);

// *****************************************************************************
/* Function:
    leResult leCircularSliderWidget_SetDirection(leCircularSliderWidget* slider, leCircularSliderWidgetDir dir)

  Summary:
    Sets the direction of the slider widget

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    leCircularSliderWidgetDir dir - direction

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetDirection(leCircularSliderWidget* slider, leCircularSliderWidgetDir dir);


// *****************************************************************************
/* Function:
    leCircularSliderWidget_SetPressedEventCallback(leCircularSliderWidget* slider, leCircularSliderWidget_ValueChangedEvent cb)

  Summary:
    Sets the function that gets called when the slider button is pressed

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    leCircularSliderWidget_PressedEvent cb - the callback function

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetPressedEventCallback(leCircularSliderWidget* slider, leCircularSliderWidget_PressedEvent cb);

// *****************************************************************************
/* Function:
    leCircularSliderWidget_SetValueChangedEventCallback(leCircularSliderWidget* slider, leCircularSliderWidget_ValueChangedEvent cb)

  Summary:
    Sets the function that gets called when the slider value changes

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    leCircularSliderWidget_ValueChangedEvent cb - the callback function

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetValueChangedEventCallback(leCircularSliderWidget* slider, leCircularSliderWidget_ValueChangedEvent cb);

// *****************************************************************************
/* Function:
    leCircularSliderWidget_SetReleasedEventCallback(leCircularSliderWidget* slider, leCircularSliderWidget_ReleasedEvent cb)

  Summary:
    Sets the function that gets called when the slider button is released

  Description:


  Parameters:
    leCircularSliderWidget* slider - the widget
    leCircularSliderWidget_ReleasedEvent cb - the callback function

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leCircularSliderWidget_SetReleasedEventCallback(leCircularSliderWidget* slider, leCircularSliderWidget_ReleasedEvent cb);
#endif

#endif // LE_CIRCULAR_SLIDER_WIDGET_ENABLED
#endif /* LEGATO_WIDGET_CIRCULAR_SLIDER_H */
