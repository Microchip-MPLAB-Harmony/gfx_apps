/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_widget_gradient.h

  Summary:
    

  Description:
    This module implements gradient drawing widget functions.
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

#ifndef LIBARIA_GRADIENT_H
#define LIBARIA_GRADIENT_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_common.h"

#if LA_GRADIENT_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_widget.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    laGradientWidgetDirection_t

  Summary:
    Implementation of a gradient widget.

  Description:
    A gradient widget is similar to a panel widget with the exception that it
    can draw a gradient color for its background.  This operation can be more
    costly than drawing a solid color and should be used sparingly.

    Gradient uses 'foreground' and 'foreground inactive' as its interpolated
    background draw colors.

  Remarks:
    None.
*/        
typedef enum laGradientWidgetDirection_t
{
    LA_GRADIENT_DIRECTION_RIGHT,
    LA_GRADIENT_DIRECTION_DOWN,
    LA_GRADIENT_DIRECTION_LEFT,
    LA_GRADIENT_DIRECTION_UP
} laGradientWidgetDirection;

// *****************************************************************************
/* Enumeration:
    laGradientWidget_t

  Summary:
    Gradient widget struct definition.

  Description:
    

  Remarks:
    None.
*/    
typedef struct laGradientWidget_t
{
    laWidget widget; // widget base class

    laGradientWidgetDirection dir; // gradient direction
} laGradientWidget;

void _laGradientWidget_Constructor(laGradientWidget* grad);
void _laGradientWidget_Destructor(laGradientWidget* grad);

void _laGradientWidget_Paint(laGradientWidget* grad);


// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    laGradientWidget* laGradientWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:
    

  Parameters:
    void
    
  Returns:
    laGradientWidget*
    
  Remarks:
    
*/
LIB_EXPORT laGradientWidget* laGradientWidget_New();

// *****************************************************************************
/* Function:
    laGradientWidgetDirection laGradientWidget_GetDirection(laGradientWidget* grad)

  Summary:
    Gets the gradient direction value for this widget.

  Description:
    

  Parameters:
    laGradientWidget* grad - the widget
    
  Returns:
    laGradientWidgetDirection - the current gradient direction
    
  Remarks:
    
*/
LIB_EXPORT laGradientWidgetDirection laGradientWidget_GetDirection(laGradientWidget* grad);

// *****************************************************************************
/* Function:
    laResult laGradientWidget_SetDirection(laGradientWidget* grad, laGradientWidgetDirection dir)

  Summary:
    Sets the gradient direction value for this widget.

  Description:
    

  Parameters:
    laGradientWidget* grad - the widget
    laGradientWidgetDirection dir - the desired gradient direction 
    
  Returns:
    laResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT laResult laGradientWidget_SetDirection(laGradientWidget* grad, laGradientWidgetDirection dir);

#endif // LA_GRADIENT_WIDGET_ENABLED
#endif /* LIBARIA_RECTANGLE_H */