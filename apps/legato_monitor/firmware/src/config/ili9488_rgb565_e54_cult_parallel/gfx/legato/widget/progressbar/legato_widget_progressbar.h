/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_progressbar.h

  Summary:


  Description:
    This module implements progress bar widget functions.
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

#ifndef LEGATO_PROGRESSBAR_H
#define LEGATO_PROGRESSBAR_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_PROGRESSBAR_WIDGET_ENABLED == 1

#include "gfx/legato/widget/legato_widget.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    leProgressBarDirection

  Summary:
    Defines the valid values for the progress bar widget fill directions.

  Description:


  Remarks:
    None.
*/
typedef enum leProgressBarDirection
{
    LE_PROGRESSBAR_DIRECTION_RIGHT,
    LE_PROGRESSBAR_DIRECTION_UP,
    LE_PROGRESSBAR_DIRECTION_LEFT,
    LE_PROGRESSBAR_DIRECTION_DOWN
} leProgressBarDirection;

// DOM-IGNORE-BEGIN
typedef struct leProgressBarWidget leProgressBar;
// DOM-IGNORE-END

// *****************************************************************************
/* Function Pointer:
    leProgressBar_ValueChangedEventCallback

  Summary:
    Value changed event function callback type
*/
typedef void (*leProgressBar_ValueChangedEventCallback)(leProgressBar*, uint32_t);

// DOM-IGNORE-BEGIN
typedef struct leProgressBarWidget leProgressBarWidget;

#define LE_PROGRESSBARWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leProgressBarDirection (*getDirection)(const THIS_TYPE* _this); \
    leResult               (*setDirection)(THIS_TYPE* _this, leProgressBarDirection dir); \
    uint32_t               (*getValue)(const THIS_TYPE* _this); \
    leResult               (*setValue)(THIS_TYPE* _this, uint32_t value); \
    leProgressBar_ValueChangedEventCallback (*getValueChangedEventCallback)(const THIS_TYPE* _this); \
    leResult               (*setValueChangedCallback)(THIS_TYPE* _this, leProgressBar_ValueChangedEventCallback cb); \
    
typedef struct leProgressBarWidgetVTable
{
	LE_PROGRESSBARWIDGET_VTABLE(leProgressBarWidget)
} leProgressBarWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leProgressBarDirection

  Summary:
    Implementation of a progressbar widget struct

  Description:
    A progress bar widget is a widget that can fill itself with a color based
    on a given percentage from 0-100.  This is often used to visually illustrate
    the progress of some other activity over time.

  Remarks:
    None.
*/
typedef struct leProgressBarWidget
{
    leWidget widget; // base widget class
    
    leProgressBarWidgetVTable* fn;

    leProgressBarDirection direction; // the fill direction of the bar

    uint32_t value; // fill percentage

    leProgressBar_ValueChangedEventCallback cb; // value changed callback
} leProgressBarWidget;


// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leProgressBarWidget* leProgressBarWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:


  Parameters:

  Returns:
    leProgressBarWidget*

  Remarks:

*/
LIB_EXPORT leProgressBarWidget* leProgressBarWidget_New();

LIB_EXPORT void leProgressBarWidget_Constructor(leProgressBarWidget* bar);

#if 0
// *****************************************************************************
/* Function:
    leProgressBarDirection leProgressBarWidget_GetDirection(leProgressBarWidget* bar)

  Summary:
    Gets the fill direction value for a progress bar widget

  Description:


  Parameters:
    leProgressBarWidget* bar - the widget

  Returns:
    leProgressBarDirection - the fill direction value

  Remarks:

*/
LIB_EXPORT leProgressBarDirection leProgressBarWidget_GetDirection(leProgressBarWidget* bar);

// *****************************************************************************
/* Function:
    leResult leProgressBarWidget_SetDirection(leProgressBarWidget* bar,
                                              leProgressBarDirection dir)

  Summary:
    Sets the fill direction for a progress bar widget

  Description:


  Parameters:
    leProgressBarWidget* bar - the widget
    leProgressBarDirection dir - the desired fill direction

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leProgressBarWidget_SetDirection(leProgressBarWidget* bar, leProgressBarDirection dir);

// *****************************************************************************
/* Function:
    uint32_t leProgressBarWidget_GetValue(leProgressBarWidget* bar)

  Summary:
    Gets the percentage value for a progress bar.

  Description:

  Parameters:
    leProgressBarWidget* bar - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leProgressBarWidget_GetValue(leProgressBarWidget* bar);

// *****************************************************************************
/* Function:
    leResult leProgressBarWidget_SetValue(leProgressBarWidget* bar, uint32_t value)

  Summary:
    Sets the percentage value for a progress bar.  Valid values are 0 - 100.

  Description:


  Parameters:
    leProgressBarWidget* bar - the widget
    uint32_t value - the desired value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leProgressBarWidget_SetValue(leProgressBarWidget* bar, uint32_t value);

// *****************************************************************************
/* Function:
    leProgressBar_ValueChangedEventCallback leProgressBarWidget_GetValueChangedEventCallback(leProgressBarWidget* bar)

  Summary:
    Gets the currently set value changed event callback.

  Description:


  Parameters:
    leProgressBarWidget* bar - the widget

  Returns:
    leProgressBar_ValueChangedEventCallback - the current callback pointer or NULL

  Remarks:

*/
LIB_EXPORT leProgressBar_ValueChangedEventCallback leProgressBarWidget_GetValueChangedEventCallback(leProgressBarWidget* bar);

// *****************************************************************************
/* Function:
    leResult leProgressBarWidget_SetValueChangedCallback(leProgressBarWidget* bar, leProgressBar_ValueChangedEventCallback cb)

  Summary:
    Sets the desired value changed event callback pointer

  Description:


  Parameters:
    leProgressBarWidget* bar - the widget
    leProgressBar_ValueChangedEventCallback - a valid callback pointer or NULL

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leProgressBarWidget_SetValueChangedCallback(leProgressBarWidget* bar, leProgressBar_ValueChangedEventCallback cb);

// DOM-IGNORE-BEGIN
// internal use only
void _leProgressBarWidget_GetBarRect(leProgressBarWidget* bar,
                                     int32_t val1,
                                     int32_t val2,
                                     leRect* barRect);
// DOM-IGNORE-END

#endif

#endif // LE_PROGRESSBAR_WIDGET_ENABLED
#endif /* LEGATO_PROGRESSBAR_H */
