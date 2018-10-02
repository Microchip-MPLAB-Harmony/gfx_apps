/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_widget_rectangle.h

  Summary:
    

  Description:
    This module implements rectangle drawing widget functions.
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

#ifndef LIBARIA_RECTANGLE_H
#define LIBARIA_RECTANGLE_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_common.h"

#if LA_RECTANGLE_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_widget.h"

typedef struct laRectangleWidget_t laRectangleWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    laRectangleWidget_t

  Summary:
    Implementation of a rectangle widget struct

  Description:
    A rectangle widget draws a basic rectangle of a given thickness using the
    widget's bounding box as the dimensions.

  Remarks:
    None.
*/
typedef struct laRectangleWidget_t
{
    laWidget widget; // widget base class

    int32_t thickness; // rectangle border thickness
} laRectangleWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    laRectangleWidget* laRectangleWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:
    

  Parameters:
    
  Returns:
    laRectangleWidget*
    
  Remarks:
    
*/
LIB_EXPORT laRectangleWidget* laRectangleWidget_New();

// *****************************************************************************
/* Function:
    int32_t laRectangleWidget_GetThickness(laRectangleWidget* rect)

  Summary:
    Gets the rectangle border thickness setting

  Description:
    

  Parameters:
    laRectangleWidget* rect - the widget
    
  Returns:
    int32_t - the border thickness setting
    
  Remarks:
    
*/
LIB_EXPORT int32_t laRectangleWidget_GetThickness(laRectangleWidget* rect);

// *****************************************************************************
/* Function:
    laResult laRectangleWidget_SetThickness(laRectangleWidget* rect,
                                            int32_t thk)

  Summary:
    Sets the rectangle border thickness setting

  Description:
    

  Parameters:
    laRectangleWidget* rect - the widget
    int32_t thk - the thickness setting
    
  Returns:
    laResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT laResult laRectangleWidget_SetThickness(laRectangleWidget* rect,
                                                   int32_t thk);

// DOM-IGNORE-BEGIN
// internal use only
void _laRectangleWidget_InvalidateRect(laRectangleWidget* rct);
// DOM-IGNORE-END

#endif // LA_RECTANGLE_WIDGET_ENABLED
#endif /* LIBARIA_RECTANGLE_H */