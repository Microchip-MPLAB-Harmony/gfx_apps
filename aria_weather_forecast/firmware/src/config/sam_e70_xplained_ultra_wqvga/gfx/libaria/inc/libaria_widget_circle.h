/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_widget_circle.h

  Summary:


  Description:
    This module implements circle drawing widget functions.
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
#ifndef LIBARIA_CIRCLE_H
#define LIBARIA_CIRCLE_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_common.h"

#if LA_CIRCLE_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_widget.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Structure:
    laCircleWidget_t

  Summary:
    Implementation of a circle widget.

  Description:
    A circle widget draws a circle of the specified origin and radius inside
    the widget bounds.  All coordinates are expressed in local widget space.

    The color of the circle is determined by the widget scheme's 'foreground'
    color.

  Remarks:
    None.
*/
typedef struct laCircleWidget_t
{
    laWidget widget; // base widget header

    int32_t x; // the origin x cooridnate
    int32_t y; // the origin y coordinate
    int32_t radius; // the radius of the circle
    int32_t thickness; // the thickness of the circle outline
    laBool filled; // fills the circle area
} laCircleWidget;

// DOM-IGNORE-BEGIN
// internal use only
void _laCircleWidget_Constructor(laCircleWidget* cir);
void _laCircleWidget_Destructor(laCircleWidget* cir);

void _laCircleWidget_Paint(laCircleWidget* cir);
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    laCircleWidget* laCircleWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:


  Parameters:
    void

  Returns:
    laCircleWidget*

  Remarks:

*/
LIB_EXPORT laCircleWidget* laCircleWidget_New();

// *****************************************************************************
/* Function:
    laResult laCircleWidget_GetOrigin(laCircleWidget* cir, int32_t* x, int32_t* y)

  Summary:
    Gets the origin coordiates of a circle widget

  Description:


  Parameters:
    laCircleWidget* cir - the widget
    int32_t* x - pointer to an integer pointer to store x
    int32_t* y - pointer to an integer pointer to store y

  Returns:
    laResult - the operation result

  Remarks:

*/
LIB_EXPORT laResult laCircleWidget_GetOrigin(laCircleWidget* cir, int32_t* x, int32_t* y);

// *****************************************************************************
/* Function:
    laResult laCircleWidget_SetOrigin(laCircleWidget* cir, int32_t x, int32_t y)

  Summary:
    Sets the origin coordiates of a circle widget

  Description:


  Parameters:
    laCircleWidget* cir - the widget
    int32_t x - the desired x origin coordinate
    int32_t y - the desired y origin coordinate

  Returns:
    laResult - the operation result

  Remarks:

*/
LIB_EXPORT laResult laCircleWidget_SetOrigin(laCircleWidget* cir, int32_t x, int32_t y);

// *****************************************************************************
/* Function:
    uint32_t laCircleWidget_GetRadius(laCircleWidget* cir)

  Summary:
    Gets the radius of a circle widget

  Description:


  Parameters:
    laCircleWidget* cir - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t laCircleWidget_GetRadius(laCircleWidget* cir);

// *****************************************************************************
/* Function:
    laResult laCircleWidget_SetRadius(laCircleWidget* cir, uint32_t rad)

  Summary:
    Sets the radius of a circle widget

  Description:


  Parameters:
    laCircleWidget* cir - the widget
    uint32_t red - the desired radius value

  Returns:
    laResult - the operation result

  Remarks:

*/
LIB_EXPORT laResult laCircleWidget_SetRadius(laCircleWidget* cir, uint32_t rad);

// *****************************************************************************
/* Function:
    uint32_t laCircleWidget_GetThickness(laCircleWidget* cir)

  Summary:
    Gets the thickness of a circle widget

  Description:


  Parameters:
    laCircleWidget* cir - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t laCircleWidget_GetThickness(laCircleWidget* cir);

// *****************************************************************************
/* Function:
    laResult laCircleWidget_SetThickness(laCircleWidget* cir, uint32_t thickness)

  Summary:
    Sets the thickness of a circle widget

  Description:


  Parameters:
    laCircleWidget* cir - the widget
    uint32_t thickness - the desired thickness value

  Returns:
    laResult - the operation result

  Remarks:

*/
LIB_EXPORT laResult laCircleWidget_SetThickness(laCircleWidget* cir, uint32_t thickness);

// *****************************************************************************
/* Function:
    laBool laCircleWidget_GetFilled(laCircleWidget* cir)

  Summary:
    Gets the filled state of a circle widget

  Description:


  Parameters:
    laCircleWidget* cir - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t laCircleWidget_GetFilled(laCircleWidget* cir);

// *****************************************************************************
/* Function:
    laResult laCircleWidget_SetFilled(laCircleWidget* cir, laBool filled)

  Summary:
    Sets the filled state of a circle widget

  Description:


  Parameters:
    laCircleWidget* cir - the widget
    laBool thickness - filled or not

  Returns:
    laResult - the operation result

  Remarks:

*/
LIB_EXPORT laResult laCircleWidget_SetFilled(laCircleWidget* cir, laBool filled);

#endif // LA_CIRCLE_WIDGET_ENABLED
#endif /* LIBARIA_CIRCLE_H */