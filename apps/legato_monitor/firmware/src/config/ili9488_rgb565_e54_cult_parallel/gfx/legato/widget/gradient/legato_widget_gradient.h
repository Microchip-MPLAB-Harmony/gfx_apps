/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_gradient.h

  Summary:


  Description:
    This module implements gradient drawing widget functions.
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

#ifndef LEGATO_GRADIENT_H
#define LEGATO_GRADIENT_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_GRADIENT_WIDGET_ENABLED

#include "gfx/legato/widget/legato_widget.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************

// DOM-IGNORE-BEGIN

typedef struct leGradientWidget leGradientWidget;

#define LE_GRADIENTWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leDirection (*getDirection)(const THIS_TYPE* _this); \
    leResult                  (*setDirection)(THIS_TYPE* _this, leDirection dir); \

typedef struct leGradientWidgetVTable
{
	LE_GRADIENTWIDGET_VTABLE(leGradientWidget)
} leGradientWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Enumeration:
    leGradientWidget

  Summary:
    Gradient widget struct definition.

  Description:


  Remarks:
    None.
*/
typedef struct leGradientWidget
{
    leWidget widget; // widget base class
    
    leGradientWidgetVTable* fn;

    leDirection dir; // gradient direction
} leGradientWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leGradientWidget* leGradientWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:


  Parameters:
    void

  Returns:
    leGradientWidget*

  Remarks:

*/
LIB_EXPORT leGradientWidget* leGradientWidget_New();

LIB_EXPORT void leGradientWidget_Constructor(leGradientWidget* grad);

#if 0
// *****************************************************************************
/* Function:
    leDirection leGradientWidget_GetDirection(leGradientWidget* grad)

  Summary:
    Gets the gradient direction value for this widget.

  Description:


  Parameters:
    leGradientWidget* grad - the widget

  Returns:
    leDirection - the current gradient direction

  Remarks:

*/
LIB_EXPORT leDirection leGradientWidget_GetDirection(leGradientWidget* grad);

// *****************************************************************************
/* Function:
    leResult leGradientWidget_SetDirection(leGradientWidget* grad, leDirection dir)

  Summary:
    Sets the gradient direction value for this widget.

  Description:


  Parameters:
    leGradientWidget* grad - the widget
    leDirection dir - the desired gradient direction

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leGradientWidget_SetDirection(leGradientWidget* grad, leDirection dir);

#endif

#endif // LE_GRADIENT_WIDGET_ENABLED
#endif /* LEGATO_RECTANGLE_H */