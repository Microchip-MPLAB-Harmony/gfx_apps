/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_widget_touchtest.h

  Summary:
    

  Description:
    This module implements graphical touch test (box) widget functions.
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
#ifndef LIBARIA_TOUCHTEST_H
#define LIBARIA_TOUCHTEST_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_common.h"

#if LA_TOUCHTEST_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_widget.h"

#define LA_TOUCHTEST_MEMORY_SIZE 20

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    laTouchTestState_t

  Summary:
    Touch test states

  Description:
    

  Remarks:
    None.
*/
typedef enum laTouchTestState_t
{
    LA_TOUCHTEST_STATE_UP,
    LA_TOUCHTEST_STATE_DOWN
} laTouchTestState;

typedef struct laTouchTestWidget_t laTouchTestWidget;

typedef void (*laTouchTestWidget_PointAddedEventCallback)(laTouchTestWidget*, GFX_Point*);

// *****************************************************************************
/* Structure:
    laTouchTestWidget_t

  Summary:
    Implementation of a touch test widget struct

  Description:
    The touch test widget is a specialized widget that displays intersecting
    lines based on input events.  This can help visualize touch interaction
    and aid determining accurate input coordinates.

  Remarks:
    None.
*/
typedef struct laTouchTestWidget_t
{
    laWidget widget; // widget base class
    
    laTouchTestState state; // touch test state
    
    GFX_Point pnts[LA_TOUCHTEST_MEMORY_SIZE]; // touch point array
    uint32_t size; // current number of valid touch points
    
    uint32_t start; // first valid touch point
    uint32_t next; // next available touch point entry
    
    laTouchTestWidget_PointAddedEventCallback cb; // point added callback
} laTouchTestWidget;

void _laTouchTestWidget_Constructor(laTouchTestWidget* tch);
void _laTouchTestWidget_Destructor(laTouchTestWidget* tch);

void _laTouchTestWidget_Paint(laTouchTestWidget* tch);

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    laTouchTestWidget* laTouchTestWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:
    

  Parameters:
    
  Returns:
    laTouchTestWidget*
    
  Remarks:
    
*/
LIB_EXPORT laTouchTestWidget* laTouchTestWidget_New();

// *****************************************************************************
/* Function:
    laResult laTouchTest_AddPoint(laTouchTestWidget* tch, GFX_Point* pnt)

  Summary:
    Adds a point to the touch test widget.  The point will then be displayed.

  Description:
    

  Parameters:
    laTouchTestWidget* tch - the widget
    GFX_Point* pnt - a pointer to the point to add
    
  Returns:
    laResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT laResult laTouchTest_AddPoint(laTouchTestWidget* tch, GFX_Point* pnt);

// *****************************************************************************
/* Function:
    laResult laTouchTest_ClearPoints(laTouchTestWidget* tch)

  Summary:
    Clears all of the existing touch points

  Description:
    

  Parameters:
    laTouchTestWidget* tch - the widget
        
  Returns:
    laResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT laResult laTouchTest_ClearPoints(laTouchTestWidget* tch);

// *****************************************************************************
/* Function:
    laTouchTestWidget_PointAddedEventCallback laTouchTestWidget_GetPointAddedEventCallback(laTouchTestWidget* txt)

  Summary:
    Gets the current point added event callback

  Description:
    

  Parameters:
    laTouchTestWidget* tch - the widget
        
  Returns:
    laTouchTestWidget_PointAddedEventCallback - a valid pointer or NULL
    
  Remarks:
    
*/
LIB_EXPORT laTouchTestWidget_PointAddedEventCallback laTouchTestWidget_GetPointAddedEventCallback(laTouchTestWidget* txt);

// *****************************************************************************
/* Function:
    laResult laTouchTestWidget_SetPointAddedEventCallback(laTouchTestWidget* txt,
                                                          laTouchTestWidget_PointAddedEventCallback cb)

  Summary:
    Sets the point added event callback

  Description:
    

  Parameters:
    laTouchTestWidget* tch - the widget
    laTouchTestWidget_PointAddedEventCallback cb - a valid pointer or NULL
    
  Returns:
    laResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT laResult laTouchTestWidget_SetPointAddedEventCallback(laTouchTestWidget* txt,
                                                                 laTouchTestWidget_PointAddedEventCallback cb);
// internal use only
void _laTouchTestWidget_GetLineRects(laTouchTestWidget* tch,
                                     uint32_t idx,
                                     GFX_Rect* horzRect,
                                     GFX_Rect* vertRect);


#endif // LA_TOUCHTEST_WIDGET_ENABLED
#endif /* LIBARIA_TOUCHTEST_H */