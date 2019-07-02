/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_list.h

  Summary:


  Description:
    This module implements list box widget functions.
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

#ifndef LEGATO_LISTWIDGET_H
#define LEGATO_LISTWIDGET_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_LIST_WIDGET_ENABLED == 1 && LE_SCROLLBAR_WIDGET_ENABLED == 1

#include "gfx/legato/image/legato_image.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/list/legato_widget_list.h"
#include "gfx/legato/widget/scrollbar/legato_widget_scrollbar.h"


typedef struct leListWidget leListWidget;

// *****************************************************************************
/* Function Pointer:
    leListWidget_SelectedItemChangedEvent

  Summary:
    Selected item changed event function callback type
*/
typedef void (*leListWidget_SelectedItemChangedEvent)(leListWidget*,
                                                      uint32_t idx,
                                                      leBool selected);

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    leListWidget_SelectionMode

  Summary:
    Defines the list selection modes

  Description:
    Single - a single selection from the list is allowed at any one time
    Multiple - any number of selected items is allowed at any one time
    Contiguous - any number of selected items in a contiguous serious is allowed
                 at any one time

  Remarks:
    None.
*/
typedef enum leListWidget_SelectionMode
{
    LE_LIST_WIDGET_SELECTION_MODE_SINGLE,
    LE_LIST_WIDGET_SELECTION_MODE_MULTIPLE,
    LE_LIST_WIDGET_SELECTION_MODE_CONTIGUOUS
} leListWidget_SelectionMode;

// *****************************************************************************
/* Structure:
    leListItem

  Summary:
    Defines a list item struct

  Description:


  Remarks:
    None.
*/
typedef struct leListItem
{
    const leString* string; // list item string
    const leImage* icon; // list item icon
    leBool selected; // list item selected flag
    leRect rowRect; // list item row rectangle
    leBool enabled; //enable or disable the item
} leListItem;

// DOM-IGNORE-BEGIN
typedef struct leListWidget leListWidget;

#define LE_LISTWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leListWidget_SelectionMode (*getSelectionMode)(const THIS_TYPE* _this); \
    leResult      (*setSelectionMode)(THIS_TYPE* _this, leListWidget_SelectionMode mode); \
    leBool        (*getAllowEmptySelection)(const THIS_TYPE* _this); \
    leResult      (*setAllowEmptySelection)(THIS_TYPE* _this, leBool allow); \
    leRelativePosition  (*getIconPosition)(const THIS_TYPE* _this); \
    leResult      (*setIconPosition)(THIS_TYPE* _this, leRelativePosition pos); \
    uint32_t      (*getIconMargin)(const THIS_TYPE* _this); \
    leResult      (*setIconMargin)(THIS_TYPE* _this, uint32_t mg); \
    uint32_t      (*getItemCount)(const THIS_TYPE* _this); \
    int32_t       (*appendItem)(THIS_TYPE* _this); \
    int32_t       (*insertItem)(THIS_TYPE* _this, int32_t idx); \
    leResult      (*removeItem)(THIS_TYPE* _this, int32_t idx); \
    leResult      (*removeAllItems)(THIS_TYPE* _this); \
    leBool        (*getItemSelected)(const THIS_TYPE* _this, int32_t idx); \
    leResult      (*setItemSelected)(THIS_TYPE* _this, int32_t idx, leBool selected); \
    leResult      (*toggleItemSelected)(THIS_TYPE* _this, int32_t idx); \
    leResult      (*selectAll)(THIS_TYPE* _this); \
    leResult      (*deselectAll)(THIS_TYPE* _this); \
    int32_t       (*getFirstSelectedItem)(const THIS_TYPE* _this); \
    int32_t       (*getLastSelectedItem)(const THIS_TYPE* _this); \
    uint32_t      (*getSelectionCount)(const THIS_TYPE* _this); \
    leString*     (*getItemString)(const THIS_TYPE* _this, int32_t idx); \
    leResult      (*setItemString)(THIS_TYPE* _this, int32_t idx, const leString* str); \
    leImage*      (*getItemIcon)(const THIS_TYPE* _this, int32_t idx); \
    leResult      (*setItemIcon)(THIS_TYPE* _this, int32_t idx, const leImage* img); \
    leBool        (*getItemEnable)(const THIS_TYPE* _this, int32_t idx); \
    leResult      (*setItemEnable)(THIS_TYPE* _this, int32_t idx, leBool b); \
    leResult      (*setItemVisible)(THIS_TYPE* _this, int32_t idx); \
    leListWidget_SelectedItemChangedEvent (*getSelectedItemChangedEventCallback)(const THIS_TYPE* _this); \
    leResult      (*setSelectedItemChangedEventCallback)(THIS_TYPE* _this, leListWidget_SelectedItemChangedEvent cb); \
    
typedef struct leListWidgetVTable
{
	LE_LISTWIDGET_VTABLE(leListWidget)
} leListWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leListWidget

  Summary:
    Defines the implementation of a list widget

  Description:
    A list widget is a widget that contains a series of vertical nodes.  Each
    node can have text, an image, or both, and can be selected or not.  The list
    has a built-in scrollbar.  This allows the list to be larger than the visible
    area of the widget.

  Remarks:
    None.
*/
typedef struct leListWidget
{
    leWidget widget; // list base class
    
    leListWidgetVTable* fn;

    leListWidget_SelectionMode mode; // list selection mode
    leBool allowEmpty; // indicates if the list must always have at least one
                       // selected item

    leArray items; // list containing the list items

    leRelativePosition iconPos; // icon position for the list icons
    uint32_t iconMargin; // margin for the list icons

    uint32_t itemDown; // tracks whether an input event is in process

    leScrollBarWidget* scrollbar; // internal scrollbar for this widget

    leListWidget_SelectedItemChangedEvent cb; // item selected changed event
} leListWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leListWidget* leListWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the managment of this memory until the
    widget is added to a widget tree.

  Description:


  Parameters:

  Returns:
    leListWidget* lst - the widget

  Remarks:

*/
LIB_EXPORT leListWidget* leListWidget_New();

LIB_EXPORT void leListWidget_Constructor(leListWidget* lst);

#if 0

// *****************************************************************************
/* Function:
    leListWidget_SelectionMode leListWidget_GetSelectionMode(leListWidget* lst)

  Summary:
    Gets the selection mode for the list

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    leListWidget_SelectionMode - the list selection mode

  Remarks:

*/
LIB_EXPORT leListWidget_SelectionMode leListWidget_GetSelectionMode(leListWidget* lst);

// *****************************************************************************
/* Function:
    leResult leListWidget_SetSelectionMode(leListWidget* lst,
                                           leListWidget_SelectionMode mode)

  Summary:
    Set the list selection mode

  Description:


  Parameters:
    leListWidget* lst - the widget
    leListWidget_SelectionMode mode - the desired list selection mode

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWidget_SetSelectionMode(leListWidget* lst,
                                                  leListWidget_SelectionMode mode);

// *****************************************************************************
/* Function:
    leBool leListWidget_GetAllowEmptySelection(leListWidget* lst)

  Summary:
    Returns true of the list allows an empty selection set

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    leBool - true if the list allows an empty selection set

  Remarks:

*/
LIB_EXPORT leBool leListWidget_GetAllowEmptySelection(leListWidget* lst);

// *****************************************************************************
/* Function:
    leResult leListWidget_SetAllowEmptySelection(leListWidget* lst,
                                                 leBool allow)

  Summary:
    Configures the list to allow an empty selection set.

  Description:


  Parameters:
    leListWidget* lst - the widget
    leBool allow - the desired empty selection set mode

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWidget_SetAllowEmptySelection(leListWidget* lst,
                                                        leBool allow);

// *****************************************************************************
/* Function:
    leHAlignment leListWidget_GetAlignment(leListWidget* lst)

  Summary:
    Gets the horizontal alignment for the list widget

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    leHAlignment - the current list halign mode

  Remarks:

*/
LIB_EXPORT leHAlignment leListWidget_GetAlignment(leListWidget* lst);

// *****************************************************************************
/* Function:
    leResult leListWidget_SetAlignment(leListWidget* lst,
                                       leHAlignment align)

  Summary:
    Sets the horizontal alignment mode for the list widget.

  Description:


  Parameters:
    leListWidget* lst - the widget
    leHAlignment align - the desired halign mode

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWidget_SetAlignment(leListWidget* lst,
                                              leHAlignment align);

// *****************************************************************************
/* Function:
    leRelativePosition leListWidget_GetIconPosition(leListWidget* lst)

  Summary:
    Gets the icon position for the list

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    leRelativePosition - the current icon position

  Remarks:

*/
LIB_EXPORT leRelativePosition leListWidget_GetIconPosition(leListWidget* lst);

// *****************************************************************************
/* Function:
    leResult leListWidget_SetIconPosition(leListWidget* lst,
                                          leRelativePosition pos)

  Summary:
    Sets the icon position for the list widget

  Description:


  Parameters:
    leListWidget* lst - the widget
    leRelativePosition pos - the relative position setting

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWidget_SetIconPosition(leListWidget* lst,
                                                 leRelativePosition pos);
// *****************************************************************************
/* Function:
    uint32_t leListWidget_GetIconMargin(leListWidget* lst)

  Summary:
    Gets the icon margin value for the list widget

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    uint32_t - the icon margin value

  Remarks:

*/
LIB_EXPORT uint32_t leListWidget_GetIconMargin(leListWidget* lst);

// *****************************************************************************
/* Function:
    leResult leListWidget_SetIconMargin(leListWidget* lst, uint32_t mg)

  Summary:
    Sets the icon margin value for the list widget.

  Description:
    The icon margin value is the distance between the icon image and the text.

  Parameters:
    leListWidget* lst - the widget
    uint32_t mg - the margin value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWidget_SetIconMargin(leListWidget* lst, uint32_t mg);

// *****************************************************************************
/* Function:
    uint32_t leListWidget_GetItemCount(leListWidget* lst)

  Summary:
    Gets the number of items currently contained in the list

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    uint32_t - the number of items in the list

  Remarks:

*/
LIB_EXPORT uint32_t leListWidget_GetItemCount(leListWidget* lst);

// *****************************************************************************
/* Function:
    uint32_t leListWidget_AppendItem(leListWidget* lst)

  Summary:
    Appends a new item entry to the list.  The initial value of the item
    will be empty.

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    uint32_t - the index of the newly appended item

  Remarks:

*/
LIB_EXPORT uint32_t leListWidget_AppendItem(leListWidget* lst);

// *****************************************************************************
/* Function:
    uint32_t leListWidget_InsertItem(leListWidget* lst, uint32_t idx)

  Summary:
    Attempts to insert a new item at the desired index.  Existing items at
    idx or greater will be shuffled one index to the right.

  Description:


  Parameters:
    leListWidget* lst - the widget
    uint32_t idx - the desired index of the new item

  Returns:
    uint32_t - the index of the inserted item

  Remarks:

*/
LIB_EXPORT uint32_t leListWidget_InsertItem(leListWidget* lst, uint32_t idx);

// *****************************************************************************
/* Function:
    leResult leListWidget_RemoveItem(leListWidget* lst, uint32_t idx)

  Summary:
    Attempts to remove an item from the list.

  Description:


  Parameters:
    leListWidget* lst - the widget
    uint32_t idx - the index to remove from the list

  Returns:
    leResult - the operation result

  Remarks:
    The memory owned by the string item will be freed automatically.
*/
LIB_EXPORT leResult leListWidget_RemoveItem(leListWidget* lst, uint32_t idx);

// *****************************************************************************
/* Function:
    leResult leListWidget_RemoveAllItems(leListWidget* lst)

  Summary:
    Attempts to remove all items from the list.

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    leResult - the operation result

  Remarks:
    All memory owned by each item string will be freed automatically.
*/
LIB_EXPORT leResult leListWidget_RemoveAllItems(leListWidget* lst);

// *****************************************************************************
/* Function:
    leBool leListWidget_GetItemSelected(leListWidget* lst,
                                        uint32_t idx)

  Summary:
    Returns true if the item at the given index is currently selected.

  Description:


  Parameters:
    leListWidget* lst - the widget
    uint32_t idx - the index to consider

  Returns:
    leBool - the selection state of the item

  Remarks:

*/
LIB_EXPORT leBool leListWidget_GetItemSelected(leListWidget* lst,
                                               uint32_t idx);

// *****************************************************************************
/* Function:
    leResult leListWidget_SetItemSelected(leListWidget* lst,
                                          uint32_t idx,
                                          leBool selected)

  Summary:
    Attempts to set the item at idx as selected.

  Description:


  Parameters:
    leListWidget* lst - the widget
    uint32_t idx - the index to consider
    leBool - the select state to set to the item

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leListWidget_SetItemSelected(leListWidget* lst,
                                                 uint32_t idx,
                                                 leBool selected);

// *****************************************************************************
/* Function:
    leResult leListWidget_ToggleItemSelected(leListWidget* lst,
                                             uint32_t idx)

  Summary:
    Attempts to toggle the selected state of the item at idx.

  Description:


  Parameters:
    leListWidget* lst - the widget
    uint32_t idx - the index to consider

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWidget_ToggleItemSelected(leListWidget* lst,
                                                    uint32_t idx);

// *****************************************************************************
/* Function:
    leResult leListWidget_SelectAll(leListWidget* lst)

  Summary:
    Attempts to set all item states to selected.

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWidget_SelectAll(leListWidget* lst);

// *****************************************************************************
/* Function:
    leResult leListWidget_DeselectAll(leListWidget* lst)

  Summary:
    Attempts to set all item states as not selected.

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWidget_DeselectAll(leListWidget* lst);


// *****************************************************************************
/* Function:
    uint32_t leListWidget_GetFirstSelectedItem(leListWidget* lst)

  Summary:
    Returns the lowest selected item index.

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    uint32_t - the lowest selected item index or -1 if nothing is selected.

  Remarks:

*/
LIB_EXPORT uint32_t leListWidget_GetFirstSelectedItem(leListWidget* lst);

// *****************************************************************************
/* Function:
    uint32_t leListWidget_GetLastSelectedItem(leListWidget* lst)

  Summary:
    Returns the highest selected item index.

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    uint32_t - the highest selected item index or -1 if nothing is selected.

  Remarks:

*/
LIB_EXPORT uint32_t leListWidget_GetLastSelectedItem(leListWidget* lst);

// *****************************************************************************
/* Function:
    uint32_t leListWidget_GetSelectionCount(leListWidget* lst)

  Summary:
    Returns the number of selected items in the list.

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    uint32_t - the number of selected items

  Remarks:

*/
LIB_EXPORT uint32_t leListWidget_GetSelectionCount(leListWidget* lst);


// *****************************************************************************
/* Function:
    leResult leListWidget_GetItemString(leListWidget* lst,
                                      uint32_t idx,
                                      leString* str)

  Summary:
    Gets the text value for an item in the list.

  Description:
    This function allocates memory and initializes the input string pointer.  The
    caller is responsible for managing the memory once this function returns.

  Parameters:
    leListWidget* lst - the widget
    uint32_t idx - the index to consider
    leString* str - a pointer to an leString object

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWidget_GetItemString(leListWidget* lst,
                                             uint32_t idx,
                                             leString* str);

// *****************************************************************************
/* Function:
    leResult leListWidget_SetItemString(leListWidget* lst,
                                      uint32_t index,
                                      leString str)

  Summary:
    Sets the text value for an item in the list.

  Description:
    This function copies the contents of the input string into its internal
    string buffer.  The input string can then be freed or altered without
    affecting the label's internal string value.

  Parameters:
    leListWidget* lst - the widget
    uint32_t idx - the index to consider
    leString str - an leString object

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWidget_SetItemString(leListWidget* lst,
                                             uint32_t index,
                                             leString str);

// *****************************************************************************
/* Function:
    leImage* leListWidget_GetItemIcon(leListWidget* lst,
                                              uint32_t idx)

  Summary:
    Gets the pointer to the image asset for the icon for the item at the given
    index.

  Description:


  Parameters:
    leListWidget* lst - the widget
    uint32_t idx - the index to consider

  Returns:
    leImage* - the image asset pointer or NULL

  Remarks:

*/
LIB_EXPORT leImage* leListWidget_GetItemIcon(leListWidget* lst,
                                                     uint32_t idx);

// *****************************************************************************
/* Function:
    leResult leListWidget_SetItemIcon(leListWidget* lst,
                                      uint32_t idx,
                                      leImage* img)

  Summary:
    Sets the icon pointer for a given index.

  Description:


  Parameters:
    leListWidget* lst - the widget
    uint32_t idx - the index to configure
    leImage* - the image asset pointer to use as the icon

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leListWidget_SetItemIcon(leListWidget* lst,
                                             uint32_t idx,
                                              leImage* img);

// *****************************************************************************
/* Function:
    leResult leListWidget_SetItemVisible(leListWidget* lst,
                                         uint32_t index)

  Summary:


  Description:


  Parameters:
    leListWidget* lst - the widget
    uint32_t index - the index to modify

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leListWidget_SetItemVisible(leListWidget* lst,
                                                uint32_t idx);

// *****************************************************************************
/* Function:
    leBool leListWidget_GetItemEnable(leListWidget* lst,
                                  uint32_t idx)

  Summary:
    Returns the enable state of the item in the list widget

  Description:


  Parameters:
    leListWidget* lst - the widget
    uint32_t index - the index of the item in the list

  Returns:
    leBool - the enable state of the item

  Remarks:

*/
LIB_EXPORT leBool leListWidget_GetItemEnable(leListWidget* lst,
                                               uint32_t idx);

// *****************************************************************************
/* Function:
    leResult leListWidget_SetItemEnable(leListWidget* lst,
                                  uint32_t idx,
                                  leBool newEnableState)

  Summary:
    Enables or disables an item in the list. A disable item becomes
    un-selectable.

  Description:


  Parameters:
    leListWidget* lst - the widget
    uint32_t index - the index of the item in the list
    leBool enable - enable/disable the item

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leListWidget_SetItemEnable(leListWidget* lst,
                                               uint32_t idx,
                                               leBool enable);

// *****************************************************************************
/* Function:
    leListWidget_SelectedItemChangedEvent leListWidget_GetSelectedItemChangedEventCallback(leListWidget* lst)

  Summary:
    Gets the callback for the item selected changed event

  Description:

  Parameters:
    leListWidget* lst - the widget

  Returns:
    leListWidget_SelectedItemChangedEvent - the current pointer to callback or NULL

  Remarks:

*/
LIB_EXPORT leListWidget_SelectedItemChangedEvent leListWidget_GetSelectedItemChangedEventCallback(leListWidget* lst);

// *****************************************************************************
/* Function:
    leResult leListWidget_SetSelectedItemChangedEventCallback(leListWidget* lst,
                                                              leListWidget_SelectedItemChangedEvent cb)

  Summary:
    Sets the callback for the item selected changed event

  Description:
    This callback is called whenver an items selected state is modified.

  Parameters:
    leListWidget* lst - the widget
    leListWidget_SelectedItemChangedEvent - the desired pointer to callback or NULL

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWidget_SetSelectedItemChangedEventCallback(leListWidget* lst,
                                                                     leListWidget_SelectedItemChangedEvent cb);

// DOM-IGNORE-BEGIN
// internal use only
void _leListWidget_GetListRect(leListWidget* lst,
                               leRect* rect);

void _leListWidget_GetRowRect(leListWidget* lst,
                              uint32_t idx,
                              leRect* rect);

// internal use only
int32_t _leListWidget_GetRowY(leListWidget* lst, uint32_t idx);

// internal use only
void _leListWidget_GetLogicalRect(leListWidget* lst, leRect* rect);

void _leListWidget_GetTextRect(leListWidget* lst,
                               uint32_t idx,
                               leRect* textRect,
                               leRect* drawRect);

void _leListWidget_GetIconRect(leListWidget* lst,
                               uint32_t idx,
                               leRect* iconRect,
                               leRect* imgSrcRect);

void _leListWidget_recalculateRowRect(leListWidget* lst,
                                     uint32_t idx);
// DOM-IGNORE-END
#endif

#endif // LE_LIST_WIDGET_ENABLED && LE_SCROLLBAR_WIDGET_ENABLED
#endif /* LEGATO_LISTWIDGET_H */
