/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_groupbox.h

  Summary:


  Description:
    This module implements group box widget functions.
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

#ifndef LEGATO_GROUPBOX_H
#define LEGATO_GROUPBOX_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_GROUPBOX_WIDGET_ENABLED

#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/string/legato_string.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// DOM-IGNORE-BEGIN
typedef struct leGroupBoxWidget leGroupBoxWidget;

#define LE_GROUPBOXWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leString*        (*getString)(const THIS_TYPE* _this); \
    leResult         (*setString)(THIS_TYPE* _this, const leString* str); \
    
typedef struct leGroupBoxWidgetVTable
{
	LE_GROUPBOXWIDGET_VTABLE(leGroupBoxWidget)
} leGroupBoxWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Enumeration:
    leGroupBoxWidget

  Summary:
    Group box struct definition.

  Description:
    A group box is a widget that is similar to a basic panel but provides
    a line border and title text.  Used for grouping and describing widgets
    of similar function.

  Remarks:
    None.
*/
typedef struct leGroupBoxWidget
{
    leWidget widget; // widget base class
    
    leGroupBoxWidgetVTable* fn;

    const leString* string; // group box title text
} leGroupBoxWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leGroupBoxWidget* leGroupBoxWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Parameters:
    void

  Returns:
    leGroupBoxWidget*

  Remarks:

*/
LIB_EXPORT leGroupBoxWidget* leGroupBoxWidget_New();

void leGroupBoxWidget_Constructor(leGroupBoxWidget* box);

#if 0
// *****************************************************************************
/* Function:
    leResult leGroupBoxWidget_GetText(leGroupBoxWidget* lbl, leString* str)

  Summary:
    Gets the text value for the group box.

  Description:
    This function allocates memory and initializes the input string pointer.  The
    caller is responsible for managing the memory once this function returns.

  Parameters:
    leGroupBoxWidget* box - the widget
    leString* str - a pointer to an leString object

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leGroupBoxWidget_GetText(leGroupBoxWidget* box, leString* str);

// *****************************************************************************
/* Function:
    void leGroupBoxWidget_SetText(leGroupBoxWidget* box, leString str)

  Summary:
    Sets the text value for the group box.

  Description:
    This function copies the contents of the input string into its internal
    string buffer.  The input string can then be freed or altered without
    affecting the label's internal string value.

  Parameters:
    leGroupBoxWidget* box - the widget
    leString str - an leString object

  Returns:
    void

  Remarks:

*/
LIB_EXPORT leResult leGroupBoxWidget_SetText(leGroupBoxWidget* box, leString str);

// *****************************************************************************
/* Function:
    leHAlignment leGroupBoxWidget_GetAlignment(leGroupBoxWidget* box)

  Summary:
    Gets the horizontal alignmnet for the group box title text

  Description:


  Parameters:
    leGroupBoxWidget* box - the widget

  Returns:
    leHAlignment - the current halign value

  Remarks:

*/
LIB_EXPORT leHAlignment leGroupBoxWidget_GetAlignment(leGroupBoxWidget* box);

// *****************************************************************************
/* Function:
    leResult leGroupBoxWidget_SetAlignment(leGroupBoxWidget* box,
                                           leHAlignment align)

  Summary:
    Sets the alignment for the group box title text

  Description:


  Parameters:
    leGroupBoxWidget* box - the widget
    leHAlignment - the desired halign value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leGroupBoxWidget_SetAlignment(leGroupBoxWidget* box,
                                                  leHAlignment align);

// DOM-IGNORE-BEGIN
// internal use only
void _leGroupBoxWidget_GetTextRect(leGroupBoxWidget* box,
                                   leRect* textRect,
                                   leRect* drawRect);
// DOM-IGNORE-END
#endif

#endif // LE_GROUPBOX_WIDGET_ENABLED
#endif /* LEGATO_GROUPBOX_H */