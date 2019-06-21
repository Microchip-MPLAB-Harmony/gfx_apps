/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_arc.h

  Summary:


  Description:
    This module implements arc drawing widget functions.
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

#ifndef LEGATO_WIDGET_ARC_H
#define LEGATO_WIDGET_ARC_H

#include "gfx/legato/common/legato_common.h"

#if LE_ARC_WIDGET_ENABLED

#include "gfx/legato/widget/legato_widget.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// DOM-IGNORE-BEGIN
typedef struct leArcWidget leArcWidget;

#define LE_ARCWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    uint32_t    (*getRadius)(const THIS_TYPE* _this); \
    leResult    (*setRadius)(THIS_TYPE* _this, uint32_t rad); \
    int32_t     (*getStartAngle)(const THIS_TYPE* _this); \
    leResult    (*setStartAngle)(THIS_TYPE* _this, int32_t ang); \
    uint32_t    (*getThickness)(const THIS_TYPE* _this); \
    leResult    (*setThickness)(THIS_TYPE* _this, uint32_t val); \
    int32_t     (*getCenterAngle)(const THIS_TYPE* _this); \
    leResult    (*setCenterAngle)(THIS_TYPE* _this, int32_t ang); \
    leBool      (*getRoundEdge)(const THIS_TYPE* _this); \
    leResult    (*setRoundEdge)(THIS_TYPE* _this, leBool rnd); \
    
typedef struct leArcWidgetVTable
{
	LE_ARCWIDGET_VTABLE(leArcWidget)
} leArcWidgetVTable; 

// *****************************************************************************
/* Structure:
    leArcWidget

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
typedef struct leArcWidget
{
    leWidget widget; // base widget header
    
    leArcWidgetVTable* fn;

    uint32_t radius; // the radius of the arc

    uint32_t startAngle; //the start angle of the arc
    int32_t centerAngle; //the center angle of the arc
    uint32_t endAngle; //the end angle of the arc
    uint32_t thickness; //the thickness of the arc

    leBool roundEdge; //draws round edge if true.
} leArcWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leArcWidget* leArcWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the management of this memory until the
    widget is added to a widget tree.

  Description:


  Parameters:
    void

  Returns:
    leArcWidget*

  Remarks:

*/
LIB_EXPORT leArcWidget* leArcWidget_New();

LIB_EXPORT leResult leArcWidget_Constructor(leArcWidget* wgt);

// *****************************************************************************
/* Function:
    uint32_t leArcWidget_GetRadius(leArcWidget* arc)

  Summary:
    Gets the radius of a arc widget

  Description:


  Parameters:
    leArcWidget* arc - the widget

  Returns:
    uint32_t

  Remarks:

*/
//LIB_EXPORT uint32_t leArcWidget_GetRadius(leArcWidget* arc);

// *****************************************************************************
/* Function:
    leResult leArcWidget_SetRadius(leArcWidget* arc, uint32_t rad)

  Summary:
    Sets the radius of a arc widget

  Description:


  Parameters:
    leArcWidget* arc - the widget
    uint32_t red - the desired radius value

  Returns:
    leResult - the operation result

  Remarks:

*/
//LIB_EXPORT leResult leArcWidget_SetRadius(leArcWidget* arc, uint32_t rad);

// *****************************************************************************
/* Function:
    int32_t leArcWidget_GetStartAngle(leArcWidget* arc)

  Summary:
    Returns the start angle of a arc widget

  Description:


  Parameters:
    leArcWidget* arc - the widget

  Returns:
    uint32_t

  Remarks:

*/
//LIB_EXPORT int32_t leArcWidget_GetStartAngle(leArcWidget* arc);

// *****************************************************************************
/* Function:
    leResult leArcWidget_SetStartAngle(leArcWidget* arc, int32_t angle)

  Summary:
    Sets the start angle of a arc widget

  Description:


  Parameters:
    leArcWidget* arc - the widget
    int32_t angle - the desired start angle value

  Returns:
    leResult - the operation result

  Remarks:

*/
//LIB_EXPORT leResult leArcWidget_SetStartAngle(leArcWidget* arc, int32_t angle);

// *****************************************************************************
/* Function:
    uint32_t leArcWidget_GetThickness(leArcWidget* arc)

  Summary:
    Gets the thickness of the arc

  Description:


  Parameters:
    leArcWidget* arc - the widget

  Returns:
    uint32_t

  Remarks:

*/
//LIB_EXPORT uint32_t leArcWidget_GetThickness(leArcWidget* arc);

// *****************************************************************************
/* Function:
    leResult leArcWidget_SetThickness(leArcWidget* arc, uint32_t thickness)

  Summary:
    Sets the thickness of the arc widget

  Description:


  Parameters:
    leArcWidget* arc - the widget
    uint32_t thickness - the desired thickness value

  Returns:
    leResult - the operation result

  Remarks:

*/
//LIB_EXPORT leResult leArcWidget_SetThickness(leArcWidget* arc, uint32_t thickness);

// *****************************************************************************
/* Function:
    int32_t leArcWidget_GetCenterAngle(leArcWidget* arc)

  Summary:
    Gets the center angle of the arc widget

  Description:


  Parameters:
    leArcWidget* arc - the widget

  Returns:
    int32_t

  Remarks:

*/
//LIB_EXPORT int32_t leArcWidget_GetCenterAngle(leArcWidget* arc);

// *****************************************************************************
/* Function:
    leResult leArcWidget_SetCenterAngle(leArcWidget* arc, int32_t angle)

  Summary:
    Sets the center angle of the arc widget

  Description:


  Parameters:
    leArcWidget* arc - the widget
    int32_t angle - the desired center angle value

  Returns:
    leResult - the operation result

  Remarks:

*/
//LIB_EXPORT leResult leArcWidget_SetCenterAngle(leArcWidget* arc, int32_t angle);

// *****************************************************************************
/* Function:
    leBool leArcWidget_GetRoundEdge(leArcWidget* arc)

  Summary:
    Returns true if the arc has round edges

  Description:


  Parameters:
    leArcWidget* arc - the widget

  Returns:
    leBool

  Remarks:

*/
//LIB_EXPORT leBool leArcWidget_GetRoundEdge(leArcWidget* arc);

// *****************************************************************************
/* Function:
    leResult leArcWidget_GetRoundEdge(leArcWidget* arc, leBool round)

  Summary:
    Sets the arc edge to round

  Description:


  Parameters:
    leArcWidget* arc - the widget
    leBool round - sets the arc edge round if LE_TRUE

  Returns:
    leResult - the operation result

  Remarks:

*/
//LIB_EXPORT leResult leArcWidget_SetRoundEdge(leArcWidget* arc, leBool round);

#endif // LE_ARC_WIDGET_ENABLED
#endif /* LEGATO_WIDGET_ARC_H */