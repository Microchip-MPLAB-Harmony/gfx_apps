/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_keypad.h

  Summary:


  Description:
    This module implements keypad widget functions.
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
#ifndef LEGATO_KEYPAD_H
#define LEGATO_KEYPAD_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_KEYPAD_WIDGET_ENABLED == 1 && LE_BUTTON_WIDGET_ENABLED == 1

#include "gfx/legato/widget/legato_editwidget.h"
#include "gfx/legato/string/legato_string.h"

typedef struct leKeyPadWidget leKeyPadWidget;
typedef struct leButtonWidget leButtonWidget;

// *****************************************************************************
/* Function Pointer:
    leKeyPadWidget_KeyClickEvent

  Summary:
    Key click event function callback type
*/
typedef void (*leKeyPadWidget_KeyClickEvent)(leKeyPadWidget*,
                                             leButtonWidget*,
                                             uint32_t,
                                             uint32_t);

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Structure:
    leKeyPadCellAction

  Summary:
    Defines an assigned action to a key pad cell

  Description:


  Remarks:
    None.
*/
typedef enum leKeyPadCellAction
{
    LE_KEYPAD_CELL_ACTION_NONE,
    LE_KEYPAD_CELL_ACTION_APPEND,
    LE_KEYPAD_CELL_ACTION_SET,
    LE_KEYPAD_CELL_ACTION_BACKSPACE,
    LE_KEYPAD_CELL_ACTION_CLEAR,
    LE_KEYPAD_CELL_ACTION_ACCEPT
} leKeyPadCellAction;

// *****************************************************************************
/* Structure:
    leKeyPadActionTrigger

  Summary:
    Defines the trigger for keypad action and events

  Description:


  Remarks:
    None.
*/
typedef enum leKeyPadActionTrigger
{
    LE_KEYPAD_TRIGGER_KEYRELEASED,
    LE_KEYPAD_TRIGGER_KEYPRESSED,
} leKeyPadActionTrigger;

// *****************************************************************************
/* Structure:
    leKeyPadCell

  Summary:
    Defines a key pad cell struct

  Description:
    A key pad is made up of an array of key pad cells.  Each cell is individually
    an leButtonWidget, an action, a value, and a few other options.

  Remarks:
    None.
*/
typedef struct leKeyPadCell
{
    leBool enabled; // indicates if the cell should be drawn
    leButtonWidget* button; // the button that handles the cell input events
                            // and rendering
    leKeyPadCellAction action; // the action that occurs when the cell is
                               // activated
    const leString* value; // the value that is passed to the edit event system
} leKeyPadCell;

// DOM-IGNORE-BEGIN

#define LE_KEYPADWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leKeyPadActionTrigger (*getKeyPadActionTrigger)(const THIS_TYPE* _this); \
    leResult              (*setKeyPadActionTrigger)(THIS_TYPE* _this, leKeyPadActionTrigger trg); \
    leKeyPadWidget_KeyClickEvent (*getKeyClickEventCallback)(const THIS_TYPE* _this); \
    leResult              (*setKeyClickEventCallback)(THIS_TYPE* _this, leKeyPadWidget_KeyClickEvent cb); \
    leBool                (*getKeyEnabled)(const THIS_TYPE* _this, uint32_t row, uint32_t col); \
    leResult              (*setKeyEnabled)(THIS_TYPE* _this, uint32_t row, uint32_t col, leBool b); \
    leKeyPadCellAction    (*getKeyAction)(const THIS_TYPE* _this, uint32_t row, uint32_t col); \
    leResult              (*setKeyAction)(THIS_TYPE* _this, uint32_t row, uint32_t col, leKeyPadCellAction action); \
    leString*             (*getKeyValue)(const THIS_TYPE* _this, uint32_t row, uint32_t col); \
    leResult              (*setKeyValue)(THIS_TYPE* _this, uint32_t row, uint32_t col, const leString* val); \
    leButtonWidget*       (*getCellButton)(const THIS_TYPE* _this, uint32_t row, uint32_t col); \
    
typedef struct leKeyPadWidgetVTable
{
	LE_KEYPADWIDGET_VTABLE(leKeyPadWidget)
} leKeyPadWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leKeyPadCell

  Summary:
    Defines a key pad widget struct

  Description:
    A key pad is a widget that is comprised of an array of leButtonWidgets.
    This widget serves to issue edit events based on application or input
    interaction.  Receptor edit widgets can then receive these edit events
    and react accordingly.

  Remarks:
    None.
*/
typedef struct leKeyPadWidget
{
    leWidget widget; // widget base class
    
    leKeyPadWidgetVTable* fn;

    uint32_t rows; // number of button rows
    uint32_t cols; // number of button columns

    leKeyPadActionTrigger trigger; //trigger for action and events

    leKeyPadCell* cells; // key cell array

    leKeyPadWidget_KeyClickEvent clickEvt; // key click callback event
} leKeyPadWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leKeyPadWidget* leKeyPadWidget_New(uint32_t rows, uint32_t cols)

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:


  Parameters:
    uint32_t - number of rows to create
    uint32_t - number of columns to create

  Returns:
    leKeyPadWidget*

  Remarks:

*/
LIB_EXPORT leKeyPadWidget* leKeyPadWidget_New(uint32_t rows,
                                              uint32_t cols);

LIB_EXPORT void leKeyPadWidget_Constructor(leKeyPadWidget* pad,
                                           uint32_t rows,
                                           uint32_t cols);

#if 0
// *****************************************************************************
/* Function:
    leKeyPadActionTrigger leKeyPadWidget_SetKeyPadActionTrigger(leKeyPadWidget* pad)

  Summary:
    Gets the current trigger for keypad edit action and events

  Description:

  Parameters:
    leKeyPadWidget* pad - the widget

  Returns:
    leKeyPadActionTrigger - the trigger

  Remarks:

*/
LIB_EXPORT leKeyPadActionTrigger leKeyPadWidget_GetKeyPadActionTrigger(leKeyPadWidget* pad);

// *****************************************************************************
/* Function:
    leResult leKeyPadWidget_SetKeyPadActionTrigger(leKeyPadWidget* pad,
                                                   leKeyPadActionTrigger trigger)

  Summary:
    Sets the current trigger for keypad edit action and events

  Description:
    Keypad actions and events callback will be called based on the trigger

  Parameters:
    leKeyPadWidget* pad - the widget
    leKeyPadActionTrigger trigger - the trigger

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leKeyPadWidget_SetKeyPadActionTrigger(leKeyPadWidget* pad,
                                                          leKeyPadActionTrigger trigger);


// *****************************************************************************
/* Function:
    leKeyPadWidget_KeyClickEvent leKeyPadWidget_GetKeyClickEventCallback(leKeyPadWidget* pad)

  Summary:
    Gets the current key click event callback pointer

  Description:


  Parameters:
    leKeyPadWidget* pad - the widget

  Returns:
    leKeyPadWidget_KeyClickEvent - the callback pointer

  Remarks:

*/
LIB_EXPORT leKeyPadWidget_KeyClickEvent leKeyPadWidget_GetKeyClickEventCallback(leKeyPadWidget* pad);

// *****************************************************************************
/* Function:
    leResult leKeyPadWidget_SetKeyClickEventCallback(leKeyPadWidget* pad,
                                                     leKeyPadWidget_KeyClickEvent cb)

  Summary:
    Sets the current key click event callback pointer

  Description:
    The key click event callback pointer is issued any time a button is
    interacted with.

  Parameters:
    leKeyPadWidget* pad - the widget
    leKeyPadWidget_KeyClickEvent cb - the callback pointer

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leKeyPadWidget_SetKeyClickEventCallback(leKeyPadWidget* pad,
                                                            leKeyPadWidget_KeyClickEvent cb);

// *****************************************************************************
/* Function:
    leBool leKeyPadWidget_GetKeyEnabled(leKeyPadWidget* pad,
                                        uint32_t row,
                                        uint32_t col)

  Summary:
    Gets the enabled flag for a cell at a given row/column

  Description:


  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column

  Returns:
    leBool - the flag value

  Remarks:

*/
LIB_EXPORT leBool leKeyPadWidget_GetKeyEnabled(leKeyPadWidget* pad,
                                               uint32_t row,
                                               uint32_t col);

// *****************************************************************************
/* Function:
    leResult leKeyPadWidget_SetKeyEnabled(leKeyPadWidget* pad,
                                          uint32_t row,
                                          uint32_t col,
                                          leBool enabled)

  Summary:
    Sets the enabled flag for a cell at the given row/column

  Description:
    The enabled flag controls the visibility and interactibility of a key pad
    cell.  This enables the key pad to be configured to match such examples as
    a phone dialer key pad with twelve buttons total but the buttons to the left
    and right of the zero button not being drawn.

  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column
    leBool enabled - the flag value

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leKeyPadWidget_SetKeyEnabled(leKeyPadWidget* pad,
                                                 uint32_t row,
                                                 uint32_t col,
                                                 leBool enabled);

// *****************************************************************************
/* Function:
    leResult leKeyPadWidget_GetKeyText(leKeyPadWidget* pad,
                                       uint32_t row,
                                       uint32_t col,
                                       leString* str)

  Summary:
    Returns a copy of the display text for a given cell at row/column

  Description:
    This function allocates memory for the input string argument.  The application
    becomes responsible for the management of the memory after function
    completion.

    The input string does not need to be initialized in any fashion before
    calling this function.

  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column
    leString* str - a pointer to an leString object

  Returns:
    leResult - the result of the operation

  Remarks:
*/
LIB_EXPORT leResult leKeyPadWidget_GetKeyText(leKeyPadWidget* pad,
                                              uint32_t row,
                                              uint32_t col,
                                              leString* str);

// *****************************************************************************
/* Function:
    leResult leKeyPadWidget_SetKeyText(leKeyPadWidget* pad,
                                       uint32_t row,
                                       uint32_t col,
                                       leString str)

  Summary:
    Sets the display text for a given cell at row/column

  Description:
    Sets the display text for a given cell at row/column

  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column
    leString str - an leString object

  Returns:
    leResult - the result of the operation

  Remarks:
*/

LIB_EXPORT leResult leKeyPadWidget_SetKeyText(leKeyPadWidget* pad,
                                              uint32_t row,
                                              uint32_t col,
                                              leString str);

// *****************************************************************************
/* Function:
    leImage* leKeyPadWidget_GetKeyPressedImage(leKeyPadWidget* pad,
                                                              uint32_t row,
                                                              uint32_t col)

  Summary:
    Gets the pressed icon image asset pointer for the display image for
    a key pad cell

  Description:


  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column

  Returns:
    leImage* - pointer to the icon image asset

  Remarks:

*/
LIB_EXPORT leImage* leKeyPadWidget_GetKeyPressedImage(leKeyPadWidget* pad,
                                                              uint32_t row,
                                                              uint32_t col);

// *****************************************************************************
/* Function:
    leResult leKeyPadWidget_SetKeyPressedImage(leKeyPadWidget* pad,
                                               uint32_t row,
                                               uint32_t col,
                                               leImage* img)

  Summary:
    Sets the pressed icon image asset pointer for a key pad cell

  Description:


  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column
    leImage* img - pointer to an image asset

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leKeyPadWidget_SetKeyPressedImage(leKeyPadWidget* pad,
                                                      uint32_t row,
                                                      uint32_t col,
                                                      leImage* img);

// *****************************************************************************
/* Function:
    leImage* leKeyPadWidget_GetKeyReleasedImage(leKeyPadWidget* pad,
                                                        uint32_t row,
                                                        uint32_t col)

  Summary:
    Gets the released icon image asset pointer for the display image for
    a key pad cell

  Description:


  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column

  Returns:
    leImage* - pointer to the icon image asset

  Remarks:

*/
LIB_EXPORT leImage* leKeyPadWidget_GetKeyReleasedImage(leKeyPadWidget* pad,
                                                               uint32_t row,
                                                               uint32_t col);

// *****************************************************************************
/* Function:
    leResult leKeyPadWidget_SetKeyReleasedImage(leKeyPadWidget* pad,
                                                uint32_t row,
                                                uint32_t col,
                                                leImage* img)

  Summary:
    Sets the released icon image asset pointer for a key pad cell

  Description:


  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column
    leImage* img - pointer to an image asset

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leKeyPadWidget_SetKeyReleasedImage(leKeyPadWidget* pad,
                                                       uint32_t row,
                                                       uint32_t col,
                                                       leImage* img);

// *****************************************************************************
/* Function:
    leRelativePosition leKeyPadWidget_GetKeyImagePosition(leKeyPadWidget* pad,
                                                          uint32_t row,
                                                          uint32_t col)

  Summary:
    Gets the image position for a key pad cell

  Description:


  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column

  Returns:
    leRelativePosition - the image position

  Remarks:

*/
LIB_EXPORT leRelativePosition leKeyPadWidget_GetKeyImagePosition(leKeyPadWidget* pad,
                                                                 uint32_t row,
                                                                 uint32_t col);

// *****************************************************************************
/* Function:
    leResult leKeyPadWidget_SetKeyImagePosition(leKeyPadWidget* pad,
                                                uint32_t row,
                                                uint32_t col,
                                                leRelativePosition pos)

  Summary:


  Description:


  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column
    leRelativePosition pos - the desired image position

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leKeyPadWidget_SetKeyImagePosition(leKeyPadWidget* pad,
                                                       uint32_t row,
                                                       uint32_t col,
                                                       leRelativePosition pos);

// *****************************************************************************
/* Function:
    uint32_t leKeyPadWidget_GetKeyImageMargin(leKeyPadWidget* pad,
                                              uint32_t row,
                                              uint32_t col)

  Summary:
    Gets the key pad cell image margin value

  Description:
    The image margin value is the space between the image and the text

  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column

  Returns:
    uint32_t - the margin value

  Remarks:

*/
LIB_EXPORT uint32_t leKeyPadWidget_GetKeyImageMargin(leKeyPadWidget* pad,
                                                     uint32_t row,
                                                     uint32_t col);

// *****************************************************************************
/* Function:
    leResult leKeyPadWidget_SetKeyImageMargin(leKeyPadWidget* pad,
                                              uint32_t row,
                                              uint32_t col,
                                              uint32_t mg)

  Summary:
    Sets the key pad cell image margin value for a given cell at row/column

  Description:


  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column
    uint32_t mg - the desired margin value

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leKeyPadWidget_SetKeyImageMargin(leKeyPadWidget* pad,
                                                     uint32_t row,
                                                     uint32_t col,
                                                     uint32_t mg);

// *****************************************************************************
/* Function:
    leBackgroundType leKeyPadWidget_GetKeyBackgroundType(leKeyPadWidget* pad,
                                                         uint32_t row,
                                                         uint32_t col)

  Summary:
    Gets the background type for a key pad cell at row/column

  Description:


  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column

  Returns:
    leBackgroundType - the cell background type

  Remarks:

*/
LIB_EXPORT leBackgroundType leKeyPadWidget_GetKeyDrawBackground(leKeyPadWidget* pad,
                                                                uint32_t row,
                                                                uint32_t col);

// *****************************************************************************
/* Function:
    leResult leKeyPadWidget_SetKeyBackgroundType(leKeyPadWidget* pad,
                                                 uint32_t row,
                                                 uint32_t col,
                                                 leBackgroundType type)

  Summary:
    Sets the background type for a key pad cell at row/column

  Description:


  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column
    leBackgroundType type - the desired background type

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leKeyPadWidget_SetKeyBackgroundType(leKeyPadWidget* pad,
                                                        uint32_t row,
                                                        uint32_t col,
                                                        leBackgroundType type);

// *****************************************************************************
/* Function:
    leKeyPadCellAction leKeyPadWidget_GetKeyAction(leKeyPadWidget* pad,
                                                   uint32_t row,
                                                   uint32_t col)

  Summary:
    Gets the key pad cell action for a cell at row/column

  Description:


  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column

  Returns:
    leKeyPadCellAction - the cell action value

  Remarks:

*/
LIB_EXPORT leKeyPadCellAction leKeyPadWidget_GetKeyAction(leKeyPadWidget* pad,
                                                          uint32_t row,
                                                          uint32_t col);

// *****************************************************************************
/* Function:
    leResult leKeyPadWidget_SetKeyAction(leKeyPadWidget* pad,
                                         uint32_t row,
                                         uint32_t col,
                                         leKeyPadCellAction action)

  Summary:
    Sets the cell action type for a key pad cell at row/column

  Description:
    The cell action is the action that is dispatched to the Legato edit event
    system.  This event will then be received by the active edit event
    receptor widget if one exists.

  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column
    leKeyPadCellAction action - the desired edit action

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leKeyPadWidget_SetKeyAction(leKeyPadWidget* pad,
                                                uint32_t row,
                                                uint32_t col,
                                                leKeyPadCellAction action);

// *****************************************************************************
/* Function:
    leString* leKeyPadWidget_GetKeyValue(leKeyPadWidget* pad,
                                         uint32_t row,
                                         uint32_t col)

  Summary:
    Gets the edit text value for a given key pad cell.

  Description:
    This function allocates memory and returns a valid leString pointer.  The
    caller is responsible for managing the memory once this function returns.

  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column

  Returns:
    leString* - an initialized string containing a copy of the key pad cell
                edit value text

  Remarks:

*/
LIB_EXPORT leString* leKeyPadWidget_GetKeyValue(leKeyPadWidget* pad,
                                                uint32_t row,
                                                uint32_t col);

// *****************************************************************************
/* Function:
    leResult leKeyPadWidget_SetKeyValue(leKeyPadWidget* pad,
                                        uint32_t row,
                                        uint32_t col,
                                        leString str)

  Summary:
    Sets the edit value for a given key pad cell.

  Description:
    The edit value for a key pad cell is the value that is passed to the Legato
    edit event management system.  This may be different than the displayed text
    of the cell or when the cell is using a picture icon and has no display text.

    An input string that references the string table is a valid use case and the
    edit text will change as the active string table language changes.

  Parameters:
    leKeyPadWidget* pad - the widget
    uint32_t row - the indicated row
    uint32_t col - the indicated column
    leString str - the string to set the key value to

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leKeyPadWidget_SetKeyValue(leKeyPadWidget* pad,
                                               uint32_t row,
                                               uint32_t col,
                                               leString str);

// DOM-IGNORE-BEGIN
// internal use only
void _leKeyPadWidget_InvalidateBorderAreas(leKeyPadWidget* pad);
// DOM-IGNORE-END

#endif

#endif // LE_WIDGET_KEYPAD_ENABLED && LE_WIDGET_BUTTON_ENABLED
#endif /* LEGATO_KEYPAD_H */
