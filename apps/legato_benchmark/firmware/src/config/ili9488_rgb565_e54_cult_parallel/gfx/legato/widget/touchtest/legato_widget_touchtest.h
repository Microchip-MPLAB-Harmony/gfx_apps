/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_touchtest.h

  Summary:


  Description:
    This module implements graphical touch test (box) widget functions.
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
#ifndef LEGATO_TOUCHTEST_H
#define LEGATO_TOUCHTEST_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_TOUCHTEST_WIDGET_ENABLED

#include "gfx/legato/widget/legato_widget.h"

// DOM-IGNORE-BEGIN
#define LE_TOUCHTEST_MEMORY_SIZE 20
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    leTouchTestState

  Summary:
    Touch test states

  Description:


  Remarks:
    None.
*/
typedef enum leTouchTestState
{
    LE_TOUCHTEST_STATE_UP,
    LE_TOUCHTEST_STATE_DOWN
} leTouchTestState;

typedef struct leTouchTestWidget leTouchTestWidget;

// *****************************************************************************
/* Function Pointer:
    leTouchTestWidget_PointAddedEventCallback

  Summary:
    Point added event function callback type
*/
typedef void (*leTouchTestWidget_PointAddedEventCallback)(leTouchTestWidget*, lePoint*);


// DOM-IGNORE-BEGIN
typedef struct leTouchTestWidget leTouchTestWidget;

#define LE_TOUCHTESTWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leResult  (*addPoint)(THIS_TYPE* _this, lePoint* pnt); \
    leResult  (*clearPoints)(THIS_TYPE* _this); \
    leTouchTestWidget_PointAddedEventCallback (*getPointAddedEventCallback)(const THIS_TYPE* _this); \
    leResult  (*setPointAddedEventCallback)(THIS_TYPE* _this, leTouchTestWidget_PointAddedEventCallback cb); \
    
typedef struct leTouchTestWidgetVTable
{
	LE_TOUCHTESTWIDGET_VTABLE(leTouchTestWidget)
} leTouchTestWidgetVTable; 

// DOM-IGNORE-END


// *****************************************************************************
/* Structure:
    leTouchTestWidget

  Summary:
    Implementation of a touch test widget struct

  Description:
    The touch test widget is a specialized widget that displays intersecting
    lines based on input events.  This can help visualize touch interaction
    and aid determining accurate input coordinates.

  Remarks:
    None.
*/
typedef struct leTouchTestWidget
{
    leWidget widget; // widget base class
    
    leTouchTestWidgetVTable* fn;

    leTouchTestState state; // touch test state

    lePoint pnts[LE_TOUCHTEST_MEMORY_SIZE]; // touch point array
    uint32_t size; // current number of valid touch points

    uint32_t start; // first valid touch point
    uint32_t next; // next available touch point entry

    leTouchTestWidget_PointAddedEventCallback cb; // point added callback
} leTouchTestWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leTouchTestWidget* leTouchTestWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:


  Parameters:

  Returns:
    leTouchTestWidget*

  Remarks:

*/
LIB_EXPORT leTouchTestWidget* leTouchTestWidget_New();

LIB_EXPORT void leTouchTestWidget_Constructor(leTouchTestWidget* tch);

#if 0
// *****************************************************************************
/* Function:
    leResult leTouchTest_AddPoint(leTouchTestWidget* tch, lePoint* pnt)

  Summary:
    Adds a point to the touch test widget.  The point will then be displayed.

  Description:


  Parameters:
    leTouchTestWidget* tch - the widget
    lePoint* pnt - a pointer to the point to add

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leTouchTest_AddPoint(leTouchTestWidget* tch, lePoint* pnt);

// *****************************************************************************
/* Function:
    leResult leTouchTest_ClearPoints(leTouchTestWidget* tch)

  Summary:
    Clears all of the existing touch points

  Description:


  Parameters:
    leTouchTestWidget* tch - the widget

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leTouchTest_ClearPoints(leTouchTestWidget* tch);

// *****************************************************************************
/* Function:
    leTouchTestWidget_PointAddedEventCallback leTouchTestWidget_GetPointAddedEventCallback(leTouchTestWidget* txt)

  Summary:
    Gets the current point added event callback

  Description:


  Parameters:
    leTouchTestWidget* tch - the widget

  Returns:
    leTouchTestWidget_PointAddedEventCallback - a valid pointer or NULL

  Remarks:

*/
LIB_EXPORT leTouchTestWidget_PointAddedEventCallback leTouchTestWidget_GetPointAddedEventCallback(leTouchTestWidget* txt);

// *****************************************************************************
/* Function:
    leResult leTouchTestWidget_SetPointAddedEventCallback(leTouchTestWidget* txt,
                                                          leTouchTestWidget_PointAddedEventCallback cb)

  Summary:
    Sets the point added event callback

  Description:


  Parameters:
    leTouchTestWidget* tch - the widget
    leTouchTestWidget_PointAddedEventCallback cb - a valid pointer or NULL

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leTouchTestWidget_SetPointAddedEventCallback(leTouchTestWidget* txt,
                                                                 leTouchTestWidget_PointAddedEventCallback cb);
// DOM-IGNORE-BEGIN
// internal use only
void _leTouchTestWidget_GetLineRects(leTouchTestWidget* tch,
                                     uint32_t idx,
                                     leRect* horzRect,
                                     leRect* vertRect);
// DOM-IGNORE-END

#endif

#endif // LE_TOUCHTEST_WIDGET_ENABLED
#endif /* LEGATO_TOUCHTEST_H */
