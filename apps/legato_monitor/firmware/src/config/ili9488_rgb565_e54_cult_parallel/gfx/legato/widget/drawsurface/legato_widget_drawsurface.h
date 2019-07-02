/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_drawsurface.h

  Summary:


  Description:
    This module implements surface container drawing functions.
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

#ifndef LEGATO_DRAWSURFACE_H
#define LEGATO_DRAWSURFACE_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_DRAWSURFACE_WIDGET_ENABLED

#include "gfx/legato/widget/legato_widget.h"

typedef struct leDrawSurfaceWidget leDrawSurfaceWidget;

// *****************************************************************************
/* Function Pointer:
    leDrawSurfaceWidget_DrawCallback

  Summary:
    Draw surface draw event function callback type
*/
typedef leBool (*leDrawSurfaceWidget_DrawCallback)(leDrawSurfaceWidget* sfc,
                                                   leRect* bounds);

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// DOM-IGNORE-BEGIN
typedef struct leDrawSurfaceWidget leDrawSurfaceWidget;

#define LE_DRAWSURFACEWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leDrawSurfaceWidget_DrawCallback (*getDrawCallback)(const THIS_TYPE* _this); \
    leResult  (*setDrawCallback)(THIS_TYPE* _this, leDrawSurfaceWidget_DrawCallback cb); \
    
typedef struct leDrawSurfaceWidgetVTable
{
	LE_DRAWSURFACEWIDGET_VTABLE(leDrawSurfaceWidget)
} leDrawSurfaceWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leDrawSurfaceWidget

  Summary:
    Implementation of a Drawsurface widget.

  Description:
    A draw surface widget is a special widget that allows an application to
    perform custom HAL draw calls during Legato's paint loop.  To use, create
    and add a draw surface widget to the desired place in the widget tree.
    Then register for the callback through the API
    'leDrawSurfaceWidget_SetDrawCallback'.  This callback occurs during the
    paint loop.  The application should then be free to adjust the HAL
    draw state and issue draw calls as desired.  The HAL layer, buffer, or
    context state must not be adjusted in any way.

    It is also important to not stall for too long during the draw callback.

  Remarks:
    None.
*/
typedef struct leDrawSurfaceWidget
{
    leWidget widget; // the widget base class

    leDrawSurfaceWidgetVTable* fn;

    leDrawSurfaceWidget_DrawCallback cb; // the draw callback
} leDrawSurfaceWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leDrawSurfaceWidget* leDrawSurfaceWidget_New()

  Summary:
    Allocates memory for a new DrawSurface widget.

  Description:
    Allocates memory for a new DrawSurface widget.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Parameters:
    void

  Returns:
    leDrawSurfaceWidget*

  Remarks:

*/
LIB_EXPORT leDrawSurfaceWidget* leDrawSurfaceWidget_New();

LIB_EXPORT void leDrawSurfaceWidget_Constructor(leDrawSurfaceWidget* sfc);

#if 0
// *****************************************************************************
/* Function:
    leDrawSurfaceWidget_DrawCallback leDrawSurfaceWidget_GetDrawCallback(leDrawSurfaceWidget* sfc)

  Summary:
    Returns the pointer to the currently set draw callback.

  Description:


  Parameters:
    leDrawSurfaceWidget* sfc - the widget

  Returns:
    leDrawSurfaceWidget_DrawCallback - a valid callback pointer or NULL

  Remarks:

*/
LIB_EXPORT leDrawSurfaceWidget_DrawCallback leDrawSurfaceWidget_GetDrawCallback(leDrawSurfaceWidget* sfc);

// *****************************************************************************
/* Function:
    leResult leDrawSurfaceWidget_SetDrawCallback(leDrawSurfaceWidget* sfc,
                                                    leDrawSurfaceWidget_DrawCallback cb)

  Summary:
    Sets the draw callback pointer for the draw surface widget.

  Description:
    Sets the draw callback pointer for the draw surface widget.  This callback will
    be called during Legato's paint loop and allows the application to perform
    HAL draw calls.  The application should not adjust HAL layer, buffer, or context
    options in any way during this phase.

    The callback should return LE_TRUE if it has completed drawing.  Returning
    LE_FALSE will indicate to the renderer that the DrawSurface requires more
    time to draw and will call it again during the next paint loop.

  Parameters:
    leDrawSurfaceWidget* sfc - the widget
    leDrawSurfaceWidget_DrawCallback - a valid callback pointer or NULL

  Returns:
    leResult - the result of the operation
*/
LIB_EXPORT leResult leDrawSurfaceWidget_SetDrawCallback(leDrawSurfaceWidget* sfc,
                                                           leDrawSurfaceWidget_DrawCallback cb);
#endif

#endif // LE_DRAWSURFACE_WIDGET_ENABLED
#endif /* LEGATO_DRAWSURFACE_H */
