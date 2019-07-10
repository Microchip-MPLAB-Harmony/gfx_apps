/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_textfield.h

  Summary:


  Description:
    This module implements text field widget functions.
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

#ifndef LEGATO_TEXTFIELD_H
#define LEGATO_TEXTFIELD_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_TEXTFIELD_WIDGET_ENABLED == 1

#include "gfx/legato/widget/legato_editwidget.h"
#include "gfx/legato/string/legato_dynamicstring.h"

typedef struct leTextFieldWidget leTextFieldWidget;

// *****************************************************************************
/* Function Pointer:
    leTextFieldWidget_TextChangedCallback

  Summary:
    Text changed event function callback type
*/
typedef void (*leTextFieldWidget_TextChangedCallback)(leTextFieldWidget*);

// *****************************************************************************
/* Function Pointer:
    leTextFieldWidget_FocusChangedCallback

  Summary:
    Focus changed event function callback type
*/
typedef void (*leTextFieldWidget_FocusChangedCallback)(leTextFieldWidget*, leBool);

// DOM-IGNORE-BEGIN
typedef struct leTextFieldWidget leTextFieldWidget;

#define LE_TEXTFIELDWIDGET_VTABLE(THIS_TYPE) \
    LE_EDITWIDGET_VTABLE(THIS_TYPE) \
    \
    uint32_t   (*getCursorDelay)(const THIS_TYPE* _this); \
    leResult   (*setCursorDelay)(THIS_TYPE* _this, uint32_t dt); \
    leBool     (*getCursorEnabled)(const THIS_TYPE* _this); \
    leResult   (*setCursorEnabled)(THIS_TYPE* _this, leBool en); \
    uint32_t   (*getCursorPosition)(const THIS_TYPE* _this); \
    leResult   (*setCursorPosition)(THIS_TYPE* _this, uint32_t pos); \
    const leString* (*getString)(const THIS_TYPE* txt); \
    leResult   (*setString)(THIS_TYPE* _this, const leString* str); \
    leFont*    (*getFont)(const THIS_TYPE* _this); \
    leResult   (*setFont)(THIS_TYPE* _this, const leFont* fnt); \
    leString*  (*getHintString)(const THIS_TYPE* txt); \
    leResult   (*setHintString)(THIS_TYPE* _this, const leString* str); \
    leResult   (*setClearValueOnFirstEdit)(THIS_TYPE* _this, leBool clr); \
    leTextFieldWidget_TextChangedCallback (*getTextChangedEventCallback)(const THIS_TYPE* _this); \
    leResult   (*setTextChangedEventCallback)(THIS_TYPE* _this, leTextFieldWidget_TextChangedCallback cb); \
    leTextFieldWidget_FocusChangedCallback (*getFocusChangedEventCallback)(const THIS_TYPE* _this); \
    leResult   (*setFocusChangedEventCallback)(THIS_TYPE* _this, leTextFieldWidget_FocusChangedCallback cb); \
    
typedef struct leTextFieldWidgetVTable
{
	LE_TEXTFIELDWIDGET_VTABLE(leTextFieldWidget)
} leTextFieldWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    leTextFieldWidget

  Summary:
    Implementation of a text field widget.

  Description:
    A text field widget is a widget that is capable of displaying a single line
    of editable text.  This widget is capable of receiving edit events from the
    Legato edit event system.  It can also display a blinking cursor.

  Remarks:
    None.
*/
typedef struct leTextFieldWidget
{
    leEditWidget editWidget; // edit widget base class
    
    leTextFieldWidgetVTable* fn;

    const leString* hintText;
    leDynamicString text; // the text to edit

    uint32_t cursorPos; // current cursor position
    uint32_t cursorDelay; // cursor blink delay
    uint32_t cursorTime; // current cursor tick counter
    leBool cursorEnable; // cursor enabled flag
    leBool cursorVisible; // cursor visbility flag
    leBool clearOnFirstEdit; // needs clear on first edit

    leTextFieldWidget_TextChangedCallback textChangedEvent; // text changed event
    leTextFieldWidget_FocusChangedCallback focusChangedEvent; // focus changed event
} leTextFieldWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leTextFieldWidget* leTextFieldWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:


  Parameters:

  Returns:
    leTextFieldWidget*

  Remarks:

*/
LIB_EXPORT leTextFieldWidget* leTextFieldWidget_New();

LIB_EXPORT void leTextFieldWidget_Constructor(leTextFieldWidget* txt);

#if 0
// *****************************************************************************
/* Function:
    leResult leTextFieldWidget_GetText(leTextFieldWidget* txt, leString* str)

  Summary:
    Gets the text value for the box.

  Description:
    This function allocates memory and initializes the input string pointer.  The
    caller is responsible for managing the memory once this function returns.

  Parameters:
    leTextFieldWidget* txt - the widget
    leString* str - a pointer to an leString object

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leTextFieldWidget_GetText(leTextFieldWidget* txt, leString* str);

// *****************************************************************************
/* Function:
    leResult leTextFieldWidget_SetText(leTextFieldWidget* txt, leString str)

  Summary:
    Sets the text value for the box.

  Description:
    This function copies the contents of the input string into its internal
    string buffer.  The input string can then be freed or altered without
    affecting the label's internal string value.

  Parameters:
    leTextFieldWidget* txt - the widget
    leString str - an leString object

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leTextFieldWidget_SetText(leTextFieldWidget* txt, leString str);

// *****************************************************************************
/* Function:
    leHAlignment leTextFieldWidget_GetAlignment(leTextFieldWidget* txt)

  Summary:
    Gets the text horizontal alignment value.

  Description:


  Parameters:
    leTextFieldWidget* txt - the widget

  Returns:
    leHAlignment - the horizontal alignment value

  Remarks:

*/
LIB_EXPORT leHAlignment leTextFieldWidget_GetAlignment(leTextFieldWidget* txt);

// *****************************************************************************
/* Function:
    leResult leTextFieldWidget_SetAlignment(leTextFieldWidget* txt,
                                            leHAlignment align)

  Summary:
    Sets the text horizontal alignment value

  Description:


  Parameters:
    leTextFieldWidget* txt - the widget
    leHAlignment - the horizontal alignment value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leTextFieldWidget_SetAlignment(leTextFieldWidget* txt,
                                                   leHAlignment align);

// *****************************************************************************
/* Function:
    uint32_t leTextFieldWidget_GetCursorDelay(leTextFieldWidget* txt)

  Summary:
    Gets the current cursor delay.

  Description:


  Parameters:
    leTextFieldWidget* txt - the widget

  Returns:
    uint32_t - the current delay value

  Remarks:

*/
LIB_EXPORT uint32_t leTextFieldWidget_GetCursorDelay(leTextFieldWidget* txt);

// *****************************************************************************
/* Function:
    leResult leTextFieldWidget_SetCursorDelay(leTextFieldWidget* txt,
                                          uint32_t dt)

  Summary:
    Sets the cursor delay value

  Description:
    This value is typically expressed in milliseconds

  Parameters:
    leTextFieldWidget* txt - the widget
    uint32_t dt - the cursor delay value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leTextFieldWidget_SetCursorDelay(leTextFieldWidget* txt,
                                                     uint32_t dt);

// *****************************************************************************
/* Function:
    leBool leTextFieldWidget_GetCursorEnabled(leTextFieldWidget* txt)

  Summary:
    Gets the cursor enabled value

  Description:


  Parameters:
    leTextFieldWidget* txt - the widget

  Returns:
    leBool - the cursor enabled flag value

  Remarks:

*/
LIB_EXPORT leBool leTextFieldWidget_GetCursorEnabled(leTextFieldWidget* txt);

// *****************************************************************************
/* Function:
    leResult leTextFieldWidget_SetCursorEnabled(leTextFieldWidget* txt,
                                                leBool en)

  Summary:
    Sets the cursor enabled value flag

  Description:
    The cursor enabled flag controls whether the cursor will display or not

  Parameters:
    leTextFieldWidget* txt - the widget
    leBool en - the desired flag state

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leTextFieldWidget_SetCursorEnabled(leTextFieldWidget* txt,
                                                       leBool en);

// *****************************************************************************
/* Function:
    uint32_t leTextFieldWidget_GetCursorPosition(leTextFieldWidget* txt)

  Summary:
    Gets the current edit cursor position

  Description:
    This cursor will appear to the left of the character at index of the string

  Parameters:
    leTextFieldWidget* txt - the widget

  Returns:
    uint32_t - the index of the cursor

  Remarks:

*/
LIB_EXPORT uint32_t leTextFieldWidget_GetCursorPosition(leTextFieldWidget* txt);

// *****************************************************************************
/* Function:
    leResult leTextFieldWidget_SetCursorPosition(leTextFieldWidget* txt,
                                                 uint32_t pos)

  Summary:
    Sets the position of the cursor

  Description:
    The cursor will appear to the left of the character at pos

  Parameters:
    leTextFieldWidget* txt - the widget
    uint32_t pos - the position of the cursor in character indices

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leTextFieldWidget_SetCursorPosition(leTextFieldWidget* txt,
                                                        uint32_t pos);

// *****************************************************************************
/* Function:
    leTextFieldWidget_TextChangedCallback leTextFieldWidget_GetTextChangedEventCallback(leTextFieldWidget* txt)

  Summary:
    Gets the current text changed event callback pointer

  Description:


  Parameters:
    leTextFieldWidget* txt - the widget

  Returns:
    leTextFieldWidget_TextChangedCallback - a valid pointer or NULL

  Remarks:

*/
LIB_EXPORT leTextFieldWidget_TextChangedCallback leTextFieldWidget_GetTextChangedEventCallback(leTextFieldWidget* txt);

// *****************************************************************************
/* Function:
    leResult leTextFieldWidget_SetTextChangedEventCallback(leTextFieldWidget* txt,
                                                           leTextFieldWidget_TextChangedCallback cb)

  Summary:
    Sets the text changed event callback pointer

  Description:


  Parameters:
    leTextFieldWidget* txt - the widget
    leTextFieldWidget_TextChangedCallback - a valid pointer or NULL

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leTextFieldWidget_SetTextChangedEventCallback(leTextFieldWidget* txt,
                                                                  leTextFieldWidget_TextChangedCallback cb);
// *****************************************************************************
/* Function:
    leResult leTextFieldWidget_SetClearOnFirstEdit(leTextFieldWidget* txt,
                                                   leBool clear)

  Summary:
    Sets the flag to indicate that the text field will be cleared on first edit.

  Description:


  Parameters:
    leTextFieldWidget* txt - the widget
    leBool clear - the desired flag state

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leTextFieldWidget_SetClearOnFirstEdit(leTextFieldWidget* txt, leBool clear);

// *****************************************************************************
/* Function:
    leTextFieldWidget_FocusChangedCallback leTextFieldWidget_GetFocusChangedEventCallback(leTextFieldWidget* txt)

  Summary:
    Gets the current focus changed event callback pointer

  Description:


  Parameters:
    leTextFieldWidget* txt - the widget

  Returns:
    leTextFieldWidget_FocusChangedCallback - a valid pointer or NULL

  Remarks:

*/
LIB_EXPORT leTextFieldWidget_FocusChangedCallback leTextFieldWidget_GetFocusChangedEventCallback(leTextFieldWidget* txt);

// *****************************************************************************
/* Function:
    leResult leTextFieldWidget_SetFocusChangedEventCallback(leTextFieldWidget* txt,
                                                           leTextFieldWidget_FocusChangedCallback cb)

  Summary:
    Sets the focus changed event callback pointer

  Description:


  Parameters:
    leTextFieldWidget* txt - the widget
    leTextFieldWidget_FocusChangedCallback - a valid pointer or NULL

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leTextFieldWidget_SetFocusChangedEventCallback(leTextFieldWidget* txt,
                                                       leTextFieldWidget_FocusChangedCallback cb);

// DOM-IGNORE-BEGIN
// internal use only
void _leTextFieldWidget_TouchDownEvent(leTextFieldWidget* txt, gauge* evt);
void _leTextFieldWidget_TouchUpEvent(leTextFieldWidget* txt, leWidgetEvent_TouchUp* evt);
void _leTextFieldWidget_TouchMovedEvent(leTextFieldWidget* txt, leWidgetEvent_TouchMove* evt);

void _leTextFieldWidget_FocusGained(leWidget* widget);
void _leTextFieldWidget_FocusLost(leWidget* widget);

void _leTextFieldWidget_GetTextRect(leTextFieldWidget* txt,
                                    leRect* textRect,
                                    leRect* drawRect);

void _leTextFieldWidget_GetCursorRect(leTextFieldWidget* txt, leRect* cursorRect);
// DOM-IGNORE-END
#endif

#endif // LE_TEXTFIELD_WIDGET_ENABLED
#endif /* LEGATO_TEXTFIELD_H */
