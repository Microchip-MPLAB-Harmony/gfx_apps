/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_widget_line.h

  Summary:


  Description:
    This module implements line draw widget functions.
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
#ifndef LIBARIA_LINE_H
#define LIBARIA_LINE_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_common.h"

#if LA_LINE_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_widget.h"

typedef struct laLineWidget_t laLineWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Structure:
    laLineWidget_t

  Summary:
    Defines the implementation of a line widget struct

  Description:
    A line widget draws a simple line shape within the confines of its
    bounding rectangle.  All coordinates are expressed in local widget space.

    The color of the line is determined by the widget scheme's 'foreground'
    color.

  Remarks:
    None.
*/
typedef struct laLineWidget_t
{
    laWidget widget; // widget base class

    int32_t x1; // point 1 x
    int32_t y1; // point 1 y
    int32_t x2; // point 2 x
    int32_t y2; // point 2 y
} laLineWidget;

// DOM-IGNORE-BEGIN
// internal use only
void _laLineWidget_Constructor(laLineWidget* line);
void _laLineWidget_Destructor(laLineWidget* line);

void _laLineWidget_Paint(laLineWidget* line);
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    laLineWidget* laLineWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:


  Parameters:

  Returns:
    laLineWidget*

  Remarks:

*/
LIB_EXPORT laLineWidget* laLineWidget_New();

// *****************************************************************************
/* Function:
    laResult laLineWidget_GetStartPoint(laLineWidget* line, int32_t* x, int32_t* y)

  Summary:
    Gets the coordinates for the first point of the line.

  Description:


  Parameters:
    laLineWidget* line - the widget
    int32_t* x - pointer to an int to store the x coordinate
    int32_t* y - pointer to tan int to store the y coordinate

  Returns:
    laResult - the result of the operation

  Remarks:

*/
LIB_EXPORT laResult laLineWidget_GetStartPoint(laLineWidget* line, int32_t* x, int32_t* y);

// *****************************************************************************
/* Function:
    laResult laLineWidget_SetStartPoint(laLineWidget* line, int32_t x, int32_t y)

  Summary:
    Sets the cooridnate for the first point of the line

  Description:


  Parameters:
    laLineWidget* line - the widget
    int32_t x - the x coordinate value
    int32_t y - the y coordinate value

  Returns:
    laResult - the result of the operation

  Remarks:

*/
LIB_EXPORT laResult laLineWidget_SetStartPoint(laLineWidget* line, int32_t x, int32_t y);

// *****************************************************************************
/* Function:
    laResult laLineWidget_GetEndPoint(laLineWidget* line, int32_t* x, int32_t* y)

  Summary:
    Gets the coordinates for the second point of the line.

  Description:


  Parameters:
    laLineWidget* line - the widget
    int32_t* x - pointer to an int to store the x coordinate
    int32_t* y - pointer to tan int to store the y coordinate

  Returns:
    laResult - the result of the operation

  Remarks:

*/
LIB_EXPORT laResult laLineWidget_GetEndPoint(laLineWidget* line, int32_t* x, int32_t* y);

// *****************************************************************************
/* Function:
    laResult laLineWidget_SetEndPoint(laLineWidget* line, int32_t x, int32_t y)

  Summary:
    Sets the cooridnate for the second point of the line

  Description:


  Parameters:
    laLineWidget* line - the widget
    int32_t x - the x coordinate value
    int32_t y - the y coordinate value

  Returns:
    laResult - the result of the operation

  Remarks:

*/
LIB_EXPORT laResult laLineWidget_SetEndPoint(laLineWidget* line, int32_t x, int32_t y);

#endif // LA_LINE_WIDGET_ENABLED
#endif /* LIBARIA_LINE_H */