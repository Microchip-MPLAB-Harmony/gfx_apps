/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_widget_progressbar.h

  Summary:


  Description:
    This module implements progress bar widget functions.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2017 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
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

#ifndef LIBARIA_PROGRESSBAR_H
#define LIBARIA_PROGRESSBAR_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_common.h"

#if LA_PROGRESSBAR_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_widget.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    laProgressBarDirection_t

  Summary:
    Defines the valid values for the progress bar widget fill directions.

  Description:


  Remarks:
    None.
*/
typedef enum laProgressBarDirection_t
{
    LA_PROGRESSBAR_DIRECTION_RIGHT,
    LA_PROGRESSBAR_DIRECTION_UP,
    LA_PROGRESSBAR_DIRECTION_LEFT,
    LA_PROGRESSBAR_DIRECTION_DOWN
} laProgressBarDirection;

typedef struct laProgressBarWidget_t laProgressBar;

typedef void (*laProgressBar_ValueChangedEventCallback)(laProgressBar*, uint32_t);

// *****************************************************************************
/* Structure:
    laProgressBarDirection_t

  Summary:
    Implementation of a progressbar widget struct

  Description:
    A progress bar widget is a widget that can fill itself with a color based
    on a given percentage from 0-100.  This is often used to visually illustrate
    the progress of some other activity over time.

  Remarks:
    None.
*/
typedef struct laProgressBarWidget_t
{
    laWidget widget; // base widget class

    laProgressBarDirection direction; // the fill direction of the bar

    uint32_t value; // fill percentage

    laProgressBar_ValueChangedEventCallback cb; // value changed callback
} laProgressBarWidget;

// DOM-IGNORE-BEGIN
// internal use only
void _laProgressBarWidget_Constructor(laProgressBarWidget* bar);
void _laProgressBarWidget_Destructor(laProgressBarWidget* bar);

void _laProgressBarWidget_Paint(laProgressBarWidget* bar);
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    laProgressBarWidget* laProgressBarWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:


  Parameters:

  Returns:
    laProgressBarWidget*

  Remarks:

*/
LIB_EXPORT laProgressBarWidget* laProgressBarWidget_New();

// *****************************************************************************
/* Function:
    laProgressBarDirection laProgressBarWidget_GetDirection(laProgressBarWidget* bar)

  Summary:
    Gets the fill direction value for a progress bar widget

  Description:


  Parameters:
    laProgressBarWidget* bar - the widget

  Returns:
    laProgressBarDirection - the fill direction value

  Remarks:

*/
LIB_EXPORT laProgressBarDirection laProgressBarWidget_GetDirection(laProgressBarWidget* bar);

// *****************************************************************************
/* Function:
    laResult laProgressBarWidget_SetDirection(laProgressBarWidget* bar,
                                              laProgressBarDirection dir)

  Summary:
    Sets the fill direction for a progress bar widget

  Description:


  Parameters:
    laProgressBarWidget* bar - the widget
    laProgressBarDirection dir - the desired fill direction

  Returns:
    laResult - the operation result

  Remarks:

*/
LIB_EXPORT laResult laProgressBarWidget_SetDirection(laProgressBarWidget* bar, laProgressBarDirection dir);

// *****************************************************************************
/* Function:
    uint32_t laProgressBarWidget_GetValue(laProgressBarWidget* bar)

  Summary:
    Gets the percentage value for a progress bar.

  Description:

  Parameters:
    laProgressBarWidget* bar - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t laProgressBarWidget_GetValue(laProgressBarWidget* bar);

// *****************************************************************************
/* Function:
    laResult laProgressBarWidget_SetValue(laProgressBarWidget* bar, uint32_t value)

  Summary:
    Sets the percentage value for a progress bar.  Valid values are 0 - 100.

  Description:


  Parameters:
    laProgressBarWidget* bar - the widget
    uint32_t value - the desired value

  Returns:
    laResult - the operation result

  Remarks:

*/
LIB_EXPORT laResult laProgressBarWidget_SetValue(laProgressBarWidget* bar, uint32_t value);

// *****************************************************************************
/* Function:
    laProgressBar_ValueChangedEventCallback laProgressBarWidget_GetValueChangedEventCallback(laProgressBarWidget* bar)

  Summary:
    Gets the currently set value changed event callback.

  Description:


  Parameters:
    laProgressBarWidget* bar - the widget

  Returns:
    laProgressBar_ValueChangedEventCallback - the current callback pointer or NULL

  Remarks:

*/
LIB_EXPORT laProgressBar_ValueChangedEventCallback laProgressBarWidget_GetValueChangedEventCallback(laProgressBarWidget* bar);

// *****************************************************************************
/* Function:
    laResult laProgressBarWidget_SetValueChangedCallback(laProgressBarWidget* bar, laProgressBar_ValueChangedEventCallback cb)

  Summary:
    Sets the desired value changed event callback pointer

  Description:


  Parameters:
    laProgressBarWidget* bar - the widget
    laProgressBar_ValueChangedEventCallback - a valid callback pointer or NULL

  Returns:
    laResult - the operation result

  Remarks:

*/
LIB_EXPORT laResult laProgressBarWidget_SetValueChangedCallback(laProgressBarWidget* bar, laProgressBar_ValueChangedEventCallback cb);

// DOM-IGNORE-BEGIN
// internal use only
void _laProgressBarWidget_GetBarRect(laProgressBarWidget* bar,
                                     int32_t val1,
                                     int32_t val2,
                                     GFX_Rect* barRect);
// DOM-IGNORE-END

#endif // LA_PROGRESSBAR_WIDGET_ENABLED
#endif /* LIBARIA_PROGRESSBAR_H */