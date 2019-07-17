/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_scrollbar.h

  Summary:


  Description:
    This module implements scroll bar widget functions.
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
#ifndef LEGATO_SCROLLBAR_H
#define LEGATO_SCROLLBAR_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_SCROLLBAR_WIDGET_ENABLED == 1

#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/string/legato_string.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    leScrollBarState

  Summary:
    Defines the various scroll bar state values

  Description:


  Remarks:
    None.
*/
typedef enum leScrollBarState
{
    LE_SCROLLBAR_STATE_NONE,
    LE_SCROLLBAR_STATE_TOP_PRESSED,
    LE_SCROLLBAR_STATE_TOP_INSIDE,
    LE_SCROLLBAR_STATE_BOTTOM_PRESSED,
    LE_SCROLLBAR_STATE_BOTTOM_INSIDE,
    LE_SCROLLBAR_STATE_HANDLE_DOWN
} leScrollBarState;

typedef struct leScrollBarWidget leScrollBarWidget;

// *****************************************************************************
/* Function Pointer:
    leScrollBarWidget_ValueChangedEvent

  Summary:
    Value changed event function callback type
*/
typedef void (*leScrollBarWidget_ValueChangedEvent)(leScrollBarWidget*);

// DOM-IGNORE-BEGIN
typedef struct leScrollBarWidget leScrollBarWidget;

#define LE_SCROLLBARWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leOrientation (*getOrientation)(const THIS_TYPE* _this); \
    leResult      (*setOrientation)(THIS_TYPE* _this, leOrientation align, leBool swapDimensions); \
    uint32_t      (*getMaximumValue)(const THIS_TYPE* _this); \
    leResult      (*setMaximumValue)(THIS_TYPE* _this, uint32_t val); \
    uint32_t      (*getExtentValue)(const THIS_TYPE* _this); \
    leResult      (*setExtentValue)(THIS_TYPE* _this, uint32_t val); \
    uint32_t      (*getScrollPercentage)(const THIS_TYPE* _this); \
    leResult      (*setScrollPercentage)(THIS_TYPE* _this, uint32_t val); \
    uint32_t      (*getScrollValue)(const THIS_TYPE* _this); \
    leResult      (*setScrollValue)(THIS_TYPE* _this, uint32_t val); \
    uint32_t      (*getStepSize)(const THIS_TYPE* _this); \
    leResult      (*setStepSize)(THIS_TYPE* _this, uint32_t val); \
    leResult      (*stepBackward)(THIS_TYPE* _this); \
    leResult      (*stepForward)(THIS_TYPE* _this); \
    leScrollBarWidget_ValueChangedEvent (*getValueChangedEventCallback)(const THIS_TYPE* _this); \
    leResult      (*setValueChangedEventCallback)(THIS_TYPE* _this, leScrollBarWidget_ValueChangedEvent cb); \
    
typedef struct leScrollBarWidgetVTable
{
	LE_SCROLLBARWIDGET_VTABLE(leScrollBarWidget)
} leScrollBarWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leScrollBarWidget

  Summary:
    Implementation of a scroll bar widget.

  Description:
    A scroll bar is a widget that is capable of displaying a range and a scroll
    handle.  The handle can grow and shrink in size depending on the scroll
    range and visible scroll space and can be interacted with to scroll through
    the available space.

  Remarks:
    None.
*/
typedef struct leScrollBarWidget
{
    leWidget widget; // widget base class
    
    leScrollBarWidgetVTable* fn;

    leScrollBarState state; // scrollbar input state
    leOrientation alignment; // scroll bar direction

    uint32_t max; // maximum scroll value
    uint32_t extent; // visible space/handle size
    uint32_t value; // current scroll value
    uint32_t step; // discreet scroll stepping value

    leScrollBarWidget_ValueChangedEvent valueChangedEvent; // value changed callback

    lePoint handleDownOffset;
} leScrollBarWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leScrollBarWidget* leScrollBarWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:


  Parameters:

  Returns:
    leScrollBarWidget*

  Remarks:

*/
LIB_EXPORT leScrollBarWidget* leScrollBarWidget_New();

LIB_EXPORT void leScrollBarWidget_Constructor(leScrollBarWidget* bar);

#if 0
// *****************************************************************************
/* Function:
    leOrientation leScrollBarWidget_GetOrientation(leScrollBarWidget* bar)

  Summary:
    Gets the orientation value for the scroll bar

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget

  Returns:
    leOrientation - the orientation value

  Remarks:

*/
LIB_EXPORT leOrientation leScrollBarWidget_GetOrientation(leScrollBarWidget* bar);

// *****************************************************************************
/* Function:
    leResult leScrollBarWidget_SetOrientation(leScrollBarWidget* bar,
                                              leOrientation align)

  Summary:
    Sets the orientation value of the scroll bar

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget
    leOrientation - the desired orientation value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leScrollBarWidget_SetOrientation(leScrollBarWidget* bar,
                                                     leOrientation align,
                                                     leBool swapDimensions);

// *****************************************************************************
/* Function:
    uint32_t leScrollBarWidget_GetMaxinumValue(leScrollBarWidget* bar)

  Summary:
    Gets the maximum scroll value

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget

  Returns:
    uint32_t - the maximum scroll value

  Remarks:

*/
LIB_EXPORT uint32_t leScrollBarWidget_GetMaxinumValue(leScrollBarWidget* bar);

// *****************************************************************************
/* Function:
    leResult leScrollBarWidget_SetMaximumValue(leScrollBarWidget* bar,
                                               uint32_t val)
  Summary:
    Sets the maximum scroll value

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget
    uint32_t val - the desired maximum scroll value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leScrollBarWidget_SetMaximumValue(leScrollBarWidget* bar,
                                                      uint32_t val);

// *****************************************************************************
/* Function:
    uint32_t leScrollBarWidget_GetExtentValue(leScrollBarWidget* bar)

  Summary:
    Gets the current scroll bar extent value

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget

  Returns:
    uint32_t - the extent value

  Remarks:

*/
LIB_EXPORT uint32_t leScrollBarWidget_GetExtentValue(leScrollBarWidget* bar);

// *****************************************************************************
/* Function:
    leResult leScrollBarWidget_SetExtentValue(leScrollBarWidget* bar,
                                              uint32_t val)
  Summary:
    Sets the scroll bar extent value

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget
    uint32_t val - the extent value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leScrollBarWidget_SetExtentValue(leScrollBarWidget* bar,
                                                     uint32_t val);

// *****************************************************************************
/* Function:
    uint32_t leScrollBarWidget_GetScrollValue(leScrollBarWidget* bar)

  Summary:
    Gets the current scroll value

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget

  Returns:
    uint32_t - the scroll value

  Remarks:

*/
LIB_EXPORT uint32_t leScrollBarWidget_GetScrollValue(leScrollBarWidget* bar);

// *****************************************************************************
/* Function:
    leResult leScrollBarWidget_SetScrollValue(leScrollBarWidget* bar,
                                                     uint32_t val)
  Summary:
    Sets the current scroll value

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget
    uint32_t - the desired scroll value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leScrollBarWidget_SetScrollValue(leScrollBarWidget* bar,
                                                     uint32_t val);

// *****************************************************************************
/* Function:
    uint32_t leScrollBarWidget_GetScrollPercentage(leScrollBarWidget* bar)

  Summary:
    Gets the current scroll value as a percentage

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget

  Returns:
    uint32_t - the scroll percentage

  Remarks:

*/
LIB_EXPORT uint32_t leScrollBarWidget_GetScrollPercentage(leScrollBarWidget* bar);

// *****************************************************************************
/* Function:
    leResult leScrollBarWidget_SetScrollPercentage(leScrollBarWidget* bar,
                                                   uint32_t val)
  Summary:
    Sets the current scroll value using a percentage.  Percentage should be a
    value from 0 - 100

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget
    uint32_t val - a value from 0 - 100

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leScrollBarWidget_SetScrollPercentage(leScrollBarWidget* bar,
                                                          uint32_t val);

// *****************************************************************************
/* Function:
    uint32_t leScrollBarWidget_GetStepSize(leScrollBarWidget* bar)

  Summary:
    Gets the current discreet step size

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget

  Returns:
    uint32_t - the current step size

  Remarks:

*/
LIB_EXPORT uint32_t leScrollBarWidget_GetStepSize(leScrollBarWidget* bar);

// *****************************************************************************
/* Function:
    leResult leScrollBarWidget_SetStepSize(leScrollBarWidget* bar,
                                           uint32_t val)

  Summary:
    Sets the current step size

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget
    uint32_t val - the desired step size

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leScrollBarWidget_SetStepSize(leScrollBarWidget* bar,
                                                  uint32_t val);

// *****************************************************************************
/* Function:
    leResult leScrollBarWidget_StepBackward(leScrollBarWidget* bar)

  Summary:
    Moves the scroll value back by the current step size

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leScrollBarWidget_StepBackward(leScrollBarWidget* bar);

// *****************************************************************************
/* Function:
    leResult leScrollBarWidget_StepForward(leScrollBarWidget* bar)

  Summary:
    Moves the scroll value forward by the current step size

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leScrollBarWidget_StepForward(leScrollBarWidget* bar);

// *****************************************************************************
/* Function:
    leScrollBarWidget_ValueChangedEvent leScrollBarWidget_GetValueChangedEventCallback(leScrollBarWidget* bar)

  Summary:
    Gets the current value changed callback function pointer

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget

  Returns:
    leScrollBarWidget_ValueChangedEvent - a valid pointer or NULL

  Remarks:

*/
LIB_EXPORT leScrollBarWidget_ValueChangedEvent leScrollBarWidget_GetValueChangedEventCallback(leScrollBarWidget* bar);

// *****************************************************************************
/* Function:
    leResult leScrollBarWidget_SetValueChangedEventCallback(leScrollBarWidget* bar,
                                                            leScrollBarWidget_ValueChangedEvent cb)
  Summary:
    Sets the value changed event callback pointer

  Description:


  Parameters:
    leScrollBarWidget* bar - the widget
    leScrollBarWidget_ValueChangedEvent - a valid pointer or NULL

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leScrollBarWidget_SetValueChangedEventCallback(leScrollBarWidget* bar,
                                                                   leScrollBarWidget_ValueChangedEvent cb);

// DOM-IGNORE-BEGIN
// internal use only
void _leScrollBarWidget_TouchDownEvent(leScrollBarWidget* bar, gauge* evt);
void _leScrollBarWidget_TouchUpEvent(leScrollBarWidget* bar, leWidgetEvent_TouchUp* evt);
void _leScrollBarWidget_TouchMovedEvent(leScrollBarWidget* bar, leWidgetEvent_TouchMove* evt);

void _leScrollBar_GetUpLeftButtonRect(leScrollBarWidget* bar, leRect* rect);
void _leScrollBar_GetDownRightButtonRect(leScrollBarWidget* bar, leRect* rect);
void _leScrollBar_GetScrollAreaRect(leScrollBarWidget* bar, leRect* rect);
void _leScrollBar_GetHandleRect(leScrollBarWidget* bar, leRect* rect);

uint32_t _leScrollWidget_GetExtent(leScrollBarWidget* bar);
uint32_t _leScrollBar_GetPercentFromPoint(leScrollBarWidget* bar, lePoint* pnt);
uint32_t _leScrollBar_GetValueFromPercent(leScrollBarWidget* bar, uint32_t per);

void _leScrollBarWidget_InvalidateBorderAreas(leScrollBarWidget* bar);
// DOM-IGNORE-END
#endif

#endif // LE_SCROLLBAR_WIDGET_ENABLED
#endif /* LEGATO_SCROLLBAR_H */
