/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_widget_arc.h

  Summary:


  Description:
    This module implements arc drawing widget functions.
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
//DOM-IGNORE-END

#ifndef LIBARIA_WIDGET_ARC_H
#define LIBARIA_WIDGET_ARC_H

#include "gfx/libaria/inc/libaria_common.h"

#if LA_ARC_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_widget.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Structure:
    laArcWidget_t

  Summary:
    Implementation of a arc widget.

  Description:
    A arc widget draws a arc of the specified origin and radius inside
    the widget bounds.  All coordinates are expressed in local widget space.

    The color of the arc is determined by the widget scheme's 'foreground'
    color.

  Remarks:
    None.
*/
typedef struct laArcWidget_t
{
    laWidget widget; // base widget header

    uint32_t radius; // the radius of the arc

    uint32_t startAngle; //the start angle of the arc
    int32_t centerAngle; //the center angle of the arc
    uint32_t endAngle; //the end angle of the arc
    uint32_t thickness; //the thickness of the arc

    laBool roundEdge; //draws round edge if true.
} laArcWidget;

// DOM-IGNORE-BEGIN
// internal use only
void _laArcWidget_Constructor(laArcWidget* arc);
void _laArcWidget_Destructor(laArcWidget* arc);

void _laArcWidget_Paint(laArcWidget* arc);
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    laArcWidget* laArcWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the management of this memory until the
    widget is added to a widget tree.

  Description:


  Parameters:
    void

  Returns:
    laArcWidget*

  Remarks:

*/
LIB_EXPORT laArcWidget* laArcWidget_New();

// *****************************************************************************
/* Function:
    uint32_t laArcWidget_GetRadius(laArcWidget* arc)

  Summary:
    Gets the radius of a arc widget

  Description:


  Parameters:
    laArcWidget* arc - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t laArcWidget_GetRadius(laArcWidget* arc);

// *****************************************************************************
/* Function:
    laResult laArcWidget_SetRadius(laArcWidget* arc, uint32_t rad)

  Summary:
    Sets the radius of a arc widget

  Description:


  Parameters:
    laArcWidget* arc - the widget
    uint32_t red - the desired radius value

  Returns:
    laResult - the operation result

  Remarks:

*/
LIB_EXPORT laResult laArcWidget_SetRadius(laArcWidget* arc, uint32_t rad);

// *****************************************************************************
/* Function:
    int32_t laArcWidget_GetStartAngle(laArcWidget* arc)

  Summary:
    Returns the start angle of a arc widget

  Description:


  Parameters:
    laArcWidget* arc - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT int32_t laArcWidget_GetStartAngle(laArcWidget* arc);

// *****************************************************************************
/* Function:
    laResult laArcWidget_SetStartAngle(laArcWidget* arc, int32_t angle)

  Summary:
    Sets the start angle of a arc widget

  Description:


  Parameters:
    laArcWidget* arc - the widget
    int32_t angle - the desired start angle value

  Returns:
    laResult - the operation result

  Remarks:

*/
LIB_EXPORT laResult laArcWidget_SetStartAngle(laArcWidget* arc, int32_t angle);

// *****************************************************************************
/* Function:
    uint32_t laArcWidget_GetThickness(laArcWidget* arc)

  Summary:
    Gets the thickness of the arc

  Description:


  Parameters:
    laArcWidget* arc - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t laArcWidget_GetThickness(laArcWidget* arc);

// *****************************************************************************
/* Function:
    laResult laArcWidget_SetThickness(laArcWidget* arc, uint32_t thickness)

  Summary:
    Sets the thickness of the arc widget

  Description:


  Parameters:
    laArcWidget* arc - the widget
    uint32_t thickness - the desired thickness value

  Returns:
    laResult - the operation result

  Remarks:

*/
LIB_EXPORT laResult laArcWidget_SetThickness(laArcWidget* arc, uint32_t thickness);

// *****************************************************************************
/* Function:
    int32_t laArcWidget_GetCenterAngle(laArcWidget* arc)

  Summary:
    Gets the center angle of the arc widget

  Description:


  Parameters:
    laArcWidget* arc - the widget

  Returns:
    int32_t

  Remarks:

*/
LIB_EXPORT int32_t laArcWidget_GetCenterAngle(laArcWidget* arc);

// *****************************************************************************
/* Function:
    laResult laArcWidget_SetCenterAngle(laArcWidget* arc, int32_t angle)

  Summary:
    Sets the center angle of the arc widget

  Description:


  Parameters:
    laArcWidget* arc - the widget
    int32_t angle - the desired center angle value

  Returns:
    laResult - the operation result

  Remarks:

*/
LIB_EXPORT laResult laArcWidget_SetCenterAngle(laArcWidget* arc, int32_t angle);

// *****************************************************************************
/* Function:
    laBool laArcWidget_GetRoundEdge(laArcWidget* arc)

  Summary:
    Returns true if the arc has round edges

  Description:


  Parameters:
    laArcWidget* arc - the widget

  Returns:
    laBool

  Remarks:

*/
LIB_EXPORT laBool laArcWidget_GetRoundEdge(laArcWidget* arc);

// *****************************************************************************
/* Function:
    laResult laArcWidget_GetRoundEdge(laArcWidget* arc, laBool round)

  Summary:
    Sets the arc edge to round

  Description:


  Parameters:
    laArcWidget* arc - the widget
    laBool round - sets the arc edge round if LA_TRUE

  Returns:
    laResult - the operation result

  Remarks:

*/
LIB_EXPORT laResult laArcWidget_SetRoundEdge(laArcWidget* arc, laBool round);

#endif // LA_ARC_WIDGET_ENABLED
#endif /* LIBARIA_WIDGET_ARC_H */