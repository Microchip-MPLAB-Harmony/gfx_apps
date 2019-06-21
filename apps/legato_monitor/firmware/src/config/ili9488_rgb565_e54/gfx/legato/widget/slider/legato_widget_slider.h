/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_slider.h

  Summary:


  Description:
    This module implements slider control widget functions.
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
#ifndef LEGATO_SLIDER_H
#define LEGATO_SLIDER_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_SLIDER_WIDGET_ENABLED

#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/string/legato_string.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    leSliderState

  Summary:
    Describes various slider states

  Description:


  Remarks:
    None.
*/
typedef enum leSliderState
{
    LE_SLIDER_STATE_NONE,
    LE_SLIDER_STATE_HANDLE_DOWN,
    LE_SLIDER_STATE_AREA_DOWN
} leSliderState;

typedef struct leSliderWidget leSliderWidget;

// *****************************************************************************
/* Function Pointer:
    leSliderWidget_ValueChangedEvent

  Summary:
    Value changed event function callback type
*/
typedef void (*leSliderWidget_ValueChangedEvent)(leSliderWidget*);

// DOM-IGNORE-BEGIN
typedef struct leSliderWidget leSliderWidget;

#define LE_SLIDERWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leOrientation (*getOrientation)(const THIS_TYPE* _this); \
    leResult  (*setOrientation)(THIS_TYPE* _this, leOrientation align, leBool swapDimensions); \
    uint32_t  (*getGripSize)(const THIS_TYPE* _this); \
    leResult  (*setGripSize)(THIS_TYPE* _this, uint32_t sz); \
    uint32_t  (*getMininumValue)(const THIS_TYPE* _this); \
    leResult  (*setMinimumValue)(THIS_TYPE* _this, uint32_t min); \
    uint32_t  (*getMaximumValue)(const THIS_TYPE* _this); \
    leResult  (*setMaximumValue)(THIS_TYPE* _this, uint32_t max); \
    uint32_t  (*getPercentage)(const THIS_TYPE* _this); \
    leResult  (*setPercentage)(THIS_TYPE* _this, uint32_t per); \
    int32_t   (*getValue)(const THIS_TYPE* _this); \
    leResult  (*setValue)(THIS_TYPE* _this, int32_t val); \
    leResult  (*step)(THIS_TYPE* _this, int32_t amt); \
    leSliderWidget_ValueChangedEvent (*getValueChangedEventCallback)(const THIS_TYPE* _this); \
    leResult  (*setValueChangedEventCallback)(THIS_TYPE* _this, leSliderWidget_ValueChangedEvent cb);
    
typedef struct leSliderWidgetVTable
{
	LE_SLIDERWIDGET_VTABLE(leSliderWidget)
} leSliderWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leSliderWidget

  Summary:
    Implementation of a slider widget struct

  Description:
    A slider bar is a widget that is capable of displaying a range and a slider
    handle.  The slider can be moved between two discreet values and can have
    a variable min and max range.

  Remarks:
    None.
*/
typedef struct leSliderWidget
{
    leWidget widget; // widget base class
    
    leSliderWidgetVTable* fn;

    leSliderState state; // slider state
    leOrientation alignment; // slider alignment

    int32_t min; // slider min value
    int32_t max; // slider max value
    int32_t value; // slider current value
    uint32_t grip; // slider grip size

    leSliderWidget_ValueChangedEvent valueChangedEvent; // value changed event

    lePoint handleDownOffset;
} leSliderWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leSliderWidget* leSliderWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:


  Parameters:

  Returns:
    leSliderWidget*

  Remarks:

*/
LIB_EXPORT leSliderWidget* leSliderWidget_New();

LIB_EXPORT void leSliderWidget_Constructor(leSliderWidget* sld);

#if 0
// *****************************************************************************
/* Function:
    leOrientation leSliderWidget_GetOrientation(leSliderWidget* sld)

  Summary:
    Gets the orientation value for the slider

  Description:


  Parameters:
    leSliderWidget* sld - the widget

  Returns:
    leOrientation

  Remarks:

*/
LIB_EXPORT leOrientation leSliderWidget_GetOrientation(leSliderWidget* sld);

// *****************************************************************************
/* Function:
    leResult leSliderWidget_SetOrientation(leSliderWidget* sld,
                                           leOrientation align,
                                           leBool swapDimensions)

  Summary:


  Description:


  Parameters:
    leSliderWidget* sld - the widget
    leOrientation - the desired slider orientation
    leBool - indicates if the width and height of the slider should be swapped

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leSliderWidget_SetOrientation(leSliderWidget* sld,
                                                  leOrientation align,
                                                  leBool swapDimensions);

// *****************************************************************************
/* Function:
    uint32_t leSliderWidget_GetGripSize(leSliderWidget* sld)

  Summary:
    Gets the current grip size of the slider

  Description:


  Parameters:
    leSliderWidget* sld - the widget

  Returns:
    uint32_t - the current grip size

  Remarks:

*/
LIB_EXPORT uint32_t leSliderWidget_GetGripSize(leSliderWidget* sld);

// *****************************************************************************
/* Function:
    leResult leSliderWidget_SetGripSize(leSliderWidget* sld,
                                        uint32_t size)

  Summary:
    Sets the grip size of the slider

  Description:


  Parameters:
    leSliderWidget* sld - the widget
    uint32_t size - the desired grip size

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leSliderWidget_SetGripSize(leSliderWidget* sld,
                                               uint32_t size);

// *****************************************************************************
/* Function:
    uint32_t leSliderWidget_GetMininumValue(leSliderWidget* sld)

  Summary:
    Gets the minimum value for the slider

  Description:


  Parameters:
    leSliderWidget* sld - the widget

  Returns:
    uint32_t - the minimum slider value

  Remarks:

*/
LIB_EXPORT uint32_t leSliderWidget_GetMininumValue(leSliderWidget* sld);

// *****************************************************************************
/* Function:
    leResult leSliderWidget_SetMinimumValue(leSliderWidget* sld,
                                            uint32_t val)

  Summary:
    Sets the minimum value for the slider

  Description:


  Parameters:
    leSliderWidget* sld - the widget
    uint32_t val - the desired minimum value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leSliderWidget_SetMinimumValue(leSliderWidget* sld,
                                                      uint32_t val);

// *****************************************************************************
/* Function:
    uint32_t leSliderWidget_GetMaxinumValue(leSliderWidget* sld)

  Summary:
    Gets the maximum value for the slider

  Description:


  Parameters:
    leSliderWidget* sld - the widget

  Returns:
    uint32_t - the maximum value for the slider

  Remarks:

*/
LIB_EXPORT uint32_t leSliderWidget_GetMaxinumValue(leSliderWidget* sld);

// *****************************************************************************
/* Function:
    leResult leSliderWidget_SetMaximumValue(leSliderWidget* sld,
                                            uint32_t val)

  Summary:
    Sets the maximum value for the slider

  Description:


  Parameters:
    leSliderWidget* sld - the widget
    uint32_t val - the desired maximum value for the slider

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leSliderWidget_SetMaximumValue(leSliderWidget* sld,
                                                      uint32_t val);

// *****************************************************************************
/* Function:
    uint32_t leSliderWidget_GetSliderValue(leSliderWidget* sld)

  Summary:
    Gets the current slider value

  Description:


  Parameters:
    leSliderWidget* sld - the widget

  Returns:
    uint32_t - the current slider value

  Remarks:

*/
LIB_EXPORT int32_t leSliderWidget_GetSliderValue(leSliderWidget* sld);

// *****************************************************************************
/* Function:
    leResult leSliderWidget_SetSliderValue(leSliderWidget* sld,
                                           int32_t val)

  Summary:
    Sets the current slider value

  Description:
    Must be between slider min and max

  Parameters:
    leSliderWidget* sld - the widget
    uint32_t val - the desired slider value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leSliderWidget_SetSliderValue(leSliderWidget* sld,
                                                  int32_t val);

// *****************************************************************************
/* Function:
    uint32_t leSliderWidget_GetSliderPercentage(leSliderWidget* sld)

  Summary:
    Gets the slider value as a percentage

  Description:


  Parameters:
    leSliderWidget* sld - the widget

  Returns:
    uint32_t - the slider value as a percentage

  Remarks:

*/
LIB_EXPORT uint32_t leSliderWidget_GetSliderPercentage(leSliderWidget* sld);

// *****************************************************************************
/* Function:
    leResult leSliderWidget_SetSliderPercentage(leSliderWidget* sld,
                                                uint32_t val)

  Summary:
    Sets the slider value using a percentage.  Value must be from 0 - 100.

  Description:


  Parameters:
    leSliderWidget* sld - the widget
    uint32_t val - a percentage value from 0 - 100

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leSliderWidget_SetSliderPercentage(leSliderWidget* sld,
                                                       uint32_t val);

// *****************************************************************************
/* Function:
    leResult leSliderWidget_Step(leSliderWidget* sld, int32_t amount)

  Summary:
    Moves the slider by a given amount

  Description:


  Parameters:
    leSliderWidget* sld - the widget
    int32_t amount - the amount by which to adjust the current slider value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leSliderWidget_Step(leSliderWidget* sld, int32_t amount);

// *****************************************************************************
/* Function:
    leSliderWidget_ValueChangedEvent leSliderWidget_GetValueChangedEventCallback(leSliderWidget* sld)

  Summary:
    Gets the current value changed event callback pointer

  Description:


  Parameters:
    leSliderWidget* sld - the widget

  Returns:
    leSliderWidget_ValueChangedEvent - a valid callback or NULL

  Remarks:

*/
LIB_EXPORT leSliderWidget_ValueChangedEvent leSliderWidget_GetValueChangedEventCallback(leSliderWidget* sld);

// *****************************************************************************
/* Function:
    leResult leSliderWidget_SetValueChangedEventCallback(leSliderWidget* sld,
                                                         leSliderWidget_ValueChangedEvent cb)

  Summary:
    Sets the value changed event callback pointer

  Description:


  Parameters:
    leSliderWidget* sld - the widget
    leSliderWidget_ValueChangedEvent - a valid pointer or NULL

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leSliderWidget_SetValueChangedEventCallback(leSliderWidget* sld,
                                                                leSliderWidget_ValueChangedEvent cb);
// DOM-IGNORE-BEGIN
// internal use only
void _leSliderWidget_TouchDownEvent(leSliderWidget* sld, leInput_TouchDownEvent* evt);
void _leSliderWidget_TouchUpEvent(leSliderWidget* sld, leInput_TouchUpEvent* evt);
void _leSliderWidget_TouchMovedEvent(leSliderWidget* sld, leInput_TouchMoveEvent* evt);

void _leSliderWidget_GetSlideAreaRect(leSliderWidget* sld, leRect* rect);
void _leSliderWidget_GetHandleRect(leSliderWidget* sld, leRect* rect);

uint32_t _leSliderWidget_GetPercentFromPoint(leSliderWidget* sld, lePoint* pnt);
uint32_t _leSliderWidget_GetValueFromPercent(leSliderWidget* sld, uint32_t per);

void _leSliderWidget_InvalidateBorderAreas(leSliderWidget* sld);
// DOM-IGNORE-END
#endif

#endif // LE_SLIDER_WIDGET_ENABLED
#endif /* LEGATO_SLIDER_H */
