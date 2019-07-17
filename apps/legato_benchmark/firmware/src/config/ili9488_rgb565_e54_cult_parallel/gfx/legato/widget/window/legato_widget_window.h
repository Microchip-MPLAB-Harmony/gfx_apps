/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_window.h

  Summary:
    Window Widget

  Description:
    This module implements window container widget functions.
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
#ifndef LEGATO_WINDOW_H
#define LEGATO_WINDOW_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_WINDOW_WIDGET_ENABLED == 1

#include "gfx/legato/image/legato_image.h"
#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/string/legato_string.h"



// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// DOM-IGNORE-BEGIN
typedef struct leWindowWidget leWindowWidget;

#define LE_WINDOWWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    uint32_t  (*getTitleHeight)(const THIS_TYPE* _this); \
    leResult  (*setTitleHeight)(THIS_TYPE* this, uint32_t ht); \
    leString* (*getString)(const THIS_TYPE* _this); \
    leResult  (*setString)(THIS_TYPE* _this, const leString* str); \
    leImage*  (*getIcon)(const THIS_TYPE* _this); \
    leResult  (*setIcon)(THIS_TYPE* _this, const leImage* img); \
    uint32_t  (*getIconMargin)(const THIS_TYPE* this); \
    leResult  (*setIconMargin)(THIS_TYPE* this, uint32_t mg); \
    
typedef struct leWindowWidgetVTable
{
	LE_WINDOWWIDGET_VTABLE(leWindowWidget)
} leWindowWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leWindowWidget

  Summary:
    Implementation of a window widget struct

  Description:
    A window widget is an extension of a basic panel.  It adds a title bar
    with text and an icon.

  Remarks:
    None.
*/
typedef struct leWindowWidget
{
    leWidget widget; // base widget class
    
    leWindowWidgetVTable* fn;

    uint32_t titleHeight; // title height
    const leString* title; // title text

    const leImage* icon; // title icon
    uint32_t iconMargin; // title icon margin
} leWindowWidget;


// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leWindowWidget* leWindowWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:


  Parameters:

  Returns:
    leWindowWidget*

  Remarks:

*/
LIB_EXPORT leWindowWidget* leWindowWidget_New();

LIB_EXPORT void leWindowWidget_Constructor(leWindowWidget* win);

#if 0

// *****************************************************************************
/* Function:
    leResult leWindowWidget_GetTitle(leWindowWidget* win, leString* str)

  Summary:
    Gets the title text for this window.

  Description:
    This function allocates memory and initializes the input string pointer.  The
    caller is responsible for managing the memory once this function returns.

  Parameters:
    leWindowWidget* win - the widget
    leString* str - a pointer to an leString object

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWindowWidget_GetTitle(leWindowWidget* win, leString* str);

// *****************************************************************************
/* Function:
    leResult leWindowWidget_SetTitle(leWindowWidget* win, leString str)

  Summary:
    Sets the title text for the window.

  Description:
    This function copies the contents of the input string into its internal
    string buffer.  The input string can then be freed or altered without
    affecting the label's internal string value.

  Parameters:
    leWindowWidget* win - the widget
    leString str - an leString object

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWindowWidget_SetTitle(leWindowWidget* win, leString str);

// *****************************************************************************
/* Function:
    GFXU_ImageAsset* leWindowWidget_GetIcon(leWindowWidget* win)

  Summary:
    Gets the currently used window icon

  Description:


  Parameters:
    leWindowWidget* win - the widget

  Returns:
    GFXU_ImageAsset*

  Remarks:

*/
LIB_EXPORT GFXU_ImageAsset* leWindowWidget_GetIcon(leWindowWidget* win);

// *****************************************************************************
/* Function:
    leResult leWindowWidget_SetIcon(leWindowWidget* win,
                                    GFXU_ImageAsset* img)

  Summary:
    Sets the image to be used as a window icon

  Description:


  Parameters:
    leWindowWidget* win - the widget
    GFXU_ImageAsset* - pointer to an image asset

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWindowWidget_SetIcon(leWindowWidget* win,
                                           GFXU_ImageAsset* img);

// *****************************************************************************
/* Function:
    uint32_t leWindowWidget_GetIconMargin(leWindowWidget* win)

  Summary:
    Gets the current image icon margin

  Description:


  Parameters:
    leWindowWidget* win - the widget

  Returns:
    uint32_t - the icon margin

  Remarks:

*/
LIB_EXPORT uint32_t leWindowWidget_GetIconMargin(leWindowWidget* win);

// *****************************************************************************
/* Function:
    leResult leWindowWidget_SetIconMargin(leWindowWidget* win, uint32_t mg)

  Summary:
    Sets the image icon margin

  Description:


  Parameters:
    leWindowWidget* win - the widget
    uint32_t mg - the image icon margin value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWindowWidget_SetIconMargin(leWindowWidget* win, uint32_t mg);

// DOM-IGNORE-BEGIN
// internal use only
void leWindowWidget_GetTitleBarRect(leWindowWidget* win, leRect* barRect);
void leWindowWidget_GetIconRect(leWindowWidget* win, leRect* imgRect, leRect* imgSrcRect);
void leWindowWidget_GetTextRect(leWindowWidget* win, leRect* textRect, leRect* drawRect);
// DOM-IGNORE-END

#endif

#endif // LE_WINDOW_WIDGET_ENABLED
#endif /* LEGATO_WINDOW_H */