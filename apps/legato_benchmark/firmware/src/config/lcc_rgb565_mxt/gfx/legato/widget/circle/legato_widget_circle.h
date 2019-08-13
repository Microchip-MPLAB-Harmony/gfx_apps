/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_circle.h

  Summary:


  Description:
    This module implements circle drawing widget functions.
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
#ifndef LEGATO_CIRCLE_H
#define LEGATO_CIRCLE_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_CIRCLE_WIDGET_ENABLED == 1

#include "gfx/legato/widget/legato_widget.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// DOM-IGNORE-BEGIN
typedef struct leCircleWidget leCircleWidget;

#define LE_CIRCLEWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    lePoint          (*getOrigin)(const THIS_TYPE* _this); \
    leResult         (*setOrigin)(THIS_TYPE* _this, const lePoint org); \
    int32_t          (*getOriginX)(const THIS_TYPE* _this); \
    leResult         (*setOriginX)(THIS_TYPE* _this, const int32_t x); \
    int32_t          (*getOriginY)(const THIS_TYPE* _this); \
    leResult         (*setOriginY)(THIS_TYPE* _this, const int32_t y); \
    uint32_t         (*getRadius)(const THIS_TYPE* _this); \
    leResult         (*setRadius)(THIS_TYPE* _this, uint32_t rad); \
    uint32_t         (*getThickness)(const THIS_TYPE* _this); \
    leResult         (*setThickness)(THIS_TYPE* _this, uint32_t thk); \
    leBool           (*getFilled)(const THIS_TYPE* _this); \
    leResult         (*setFilled)(THIS_TYPE* _this, leBool fill); \
    
typedef struct leCircleWidgetVTable
{
	LE_CIRCLEWIDGET_VTABLE(leCircleWidget)
} leCircleWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leCircleWidget

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
typedef struct leCircleWidget
{
    leWidget widget; // base widget header
    
    leCircleWidgetVTable* fn;

    int32_t x; // the origin x cooridnate
    int32_t y; // the origin y coordinate
    int32_t radius; // the radius of the circle
    int32_t thickness; // the thickness of the circle outline
    leBool filled; // fills the circle area
} leCircleWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leCircleWidget* leCircleWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:


  Parameters:
    void

  Returns:
    leCircleWidget*

  Remarks:

*/
LIB_EXPORT leCircleWidget* leCircleWidget_New();

LIB_EXPORT void leCircleWidget_Constructor(leCircleWidget* cir);

#if 0
// *****************************************************************************
/* Function:
    leResult leCircleWidget_GetOrigin(leCircleWidget* cir, int32_t* x, int32_t* y)

  Summary:
    Gets the origin coordiates of a circle widget

  Description:


  Parameters:
    leCircleWidget* cir - the widget
    int32_t* x - pointer to an integer pointer to store x
    int32_t* y - pointer to an integer pointer to store y

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCircleWidget_GetOrigin(leCircleWidget* cir, int32_t* x, int32_t* y);

// *****************************************************************************
/* Function:
    leResult leCircleWidget_SetOrigin(leCircleWidget* cir, int32_t x, int32_t y)

  Summary:
    Sets the origin coordiates of a circle widget

  Description:


  Parameters:
    leCircleWidget* cir - the widget
    int32_t x - the desired x origin coordinate
    int32_t y - the desired y origin coordinate

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCircleWidget_SetOrigin(leCircleWidget* cir, int32_t x, int32_t y);

// *****************************************************************************
/* Function:
    uint32_t leCircleWidget_GetRadius(leCircleWidget* cir)

  Summary:
    Gets the radius of a circle widget

  Description:


  Parameters:
    leCircleWidget* cir - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircleWidget_GetRadius(leCircleWidget* cir);

// *****************************************************************************
/* Function:
    leResult leCircleWidget_SetRadius(leCircleWidget* cir, uint32_t rad)

  Summary:
    Sets the radius of a circle widget

  Description:


  Parameters:
    leCircleWidget* cir - the widget
    uint32_t red - the desired radius value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCircleWidget_SetRadius(leCircleWidget* cir, uint32_t rad);

// *****************************************************************************
/* Function:
    uint32_t leCircleWidget_GetThickness(leCircleWidget* cir)

  Summary:
    Gets the thickness of a circle widget

  Description:


  Parameters:
    leCircleWidget* cir - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircleWidget_GetThickness(leCircleWidget* cir);

// *****************************************************************************
/* Function:
    leResult leCircleWidget_SetThickness(leCircleWidget* cir, uint32_t thickness)

  Summary:
    Sets the thickness of a circle widget

  Description:


  Parameters:
    leCircleWidget* cir - the widget
    uint32_t thickness - the desired thickness value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCircleWidget_SetThickness(leCircleWidget* cir, uint32_t thickness);

// *****************************************************************************
/* Function:
    leBool leCircleWidget_GetFilled(leCircleWidget* cir)

  Summary:
    Gets the filled state of a circle widget

  Description:


  Parameters:
    leCircleWidget* cir - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t leCircleWidget_GetFilled(leCircleWidget* cir);

// *****************************************************************************
/* Function:
    leResult leCircleWidget_SetFilled(leCircleWidget* cir, leBool filled)

  Summary:
    Sets the filled state of a circle widget

  Description:


  Parameters:
    leCircleWidget* cir - the widget
    leBool thickness - filled or not

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leCircleWidget_SetFilled(leCircleWidget* cir, leBool filled);
#endif

#endif // LE_CIRCLE_WIDGET_ENABLED
#endif /* LEGATO_CIRCLE_H */