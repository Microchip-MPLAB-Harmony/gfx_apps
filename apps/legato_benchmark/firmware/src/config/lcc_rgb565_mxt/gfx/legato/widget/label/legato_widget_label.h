/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_label.h

  Summary:


  Description:
    This module implements label (text) widget functions.
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
#ifndef LEGATO_LABEL_H
#define LEGATO_LABEL_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_LABEL_WIDGET_ENABLED

#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/string/legato_string.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// DOM-IGNORE-BEGIN
typedef struct leLabelWidget leLabelWidget;

#define LE_LABELWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leString*  (*getString)(const THIS_TYPE* _this); \
    leResult   (*setString)(THIS_TYPE* _this, leString* str); \
    
typedef struct leLabelWidgetVTable
{
	LE_LABELWIDGET_VTABLE(leLabelWidget)
} leLabelWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leLabelWidget

  Summary:
    Implementation of a label widget struct

  Description:
    A label widget is a simple widget that draws a string of text.

  Remarks:
    None.
*/
typedef struct leLabelWidget
{
    leWidget widget; // widget base class

    leLabelWidgetVTable* fn;

    const leString* string; // string to draw
} leLabelWidget;


// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leLabelWidget* leLabelWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:


  Parameters:

  Returns:
    leLabelWidget*

  Remarks:

*/
LIB_EXPORT leLabelWidget* leLabelWidget_New();

LIB_EXPORT void leLabelWidget_Constructor(leLabelWidget* lbl);

#if 0
// *****************************************************************************
/* Function:
    leResult leLabelWidget_GetText(leLabelWidget* lbl, leString* str)

  Summary:
    Gets the text value for the label.

  Description:
    This function allocates memory and initializes the input string pointer.  The
    caller is responsible for managing the memory once this function returns.

  Parameters:
    leLabelWidget* lbl - the widget
    leString* str - a pointer to an leString object

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leLabelWidget_GetText(leLabelWidget* lbl, leString* str);

// *****************************************************************************
/* Function:
    leResult leLabelWidget_SetText(leLabelWidget* lbl, leString str)

  Summary:
    Sets the text value for the label.

  Description:
    This function copies the contents of the input string into its internal
    string buffer.  The input string can then be freed or altered without
    affecting the label's internal string value.

  Parameters:
    leLabelWidget* lbl - the widget
    leString str - an leString object

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leLabelWidget_SetText(leLabelWidget* lbl, leString str);

// *****************************************************************************
/* Function:
    int32_t leLabelWidget_GetTextLineSpace(leLabelWidget* lbl)

  Summary:
    Returns the line spacing in pixels for the label text. If < 0, the
    ascent value of the string's font is used.

  Description:

  Parameters:
    leLabelWidget* lbl - the label to reference

  Returns:
    int32_t - the line spacing in pixels

  Remarks:

*/
LIB_EXPORT int32_t leLabelWidget_GetTextLineSpace(leLabelWidget* lbl);

// *****************************************************************************
/* Function:
    leResult leLabelWidget_SetTextLineSpace(leLabelWidget* lbl, int32_t pixels)

  Summary:
    Sets the line space in pixels of the text in the label widget. A value < 0
    sets the spacing to the ascent value of the string's font.

  Description:

  Parameters:
    leLabelWidget* lbl - the label to modify
    int32_t pixels - the line space, in pixels

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leLabelWidget_SetTextLineSpace(leLabelWidget* lbl, int32_t pixels);
#endif

#endif // LE_LABEL_WIDGET_ENABLED
#endif /* LEGATO_LABEL_H */
