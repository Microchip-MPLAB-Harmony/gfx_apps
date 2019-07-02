/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_listwheel.h

  Summary:


  Description:
    This module implements list wheel (drawing-style list box) widget functions.
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
#ifndef LEGATO_LISTWHEELWIDGET_H
#define LEGATO_LISTWHEELWIDGET_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_LISTWHEEL_WIDGET_ENABLED == 1

//#include "gfx/legato/datastructure/legato_list.h"
#include "gfx/legato/image/legato_image.h"
#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/string/legato_string.h"

typedef struct leListWheelWidget leListWheelWidget;

// *****************************************************************************
/* Function Pointer:
    leListWheelWidget_SelectedItemChangedEvent

  Summary:
    Selected item changed event function callback type
*/
typedef void (*leListWheelWidget_SelectedItemChangedEvent)(leListWheelWidget*,
                                                           int32_t idx);

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    leListWheelIndicatorFill

  Summary:
    Indicates the fill type for the listwheel indicator area.
*/
typedef enum leListWheelIndicatorFill
{
    LE_LISTWHEEL_INDICATOR_FILL_NONE,
    LE_LISTWHEEL_INDICATOR_FILL_SOLID,
    LE_LISTWHEEL_INDICATOR_FILL_GRADIENT,
} leListWheelIndicatorFill;

// *****************************************************************************
/* Enumeration:
    leListWheelEffects

  Summary:
    Indicates the zoom effects for the list wheel items.
*/
typedef enum leListWheelZoomEffects
{
    LE_LISTWHEEL_ZOOM_EFFECT_NONE,
    LE_LISTWHEEL_ZOOM_EFFECT_VSCALE,
    LE_LISTWHEEL_ZOOM_EFFECT_FULL_SCALE,
    LE_LISTWHEEL_ZOOM_EFFECT_FIXED_SCALE,
} leListWheelZoomEffects;

// *****************************************************************************
/* Structure:
    leListWheelItem

  Summary:
    Implementation of a list wheel widget item struct

  Description:
    A list wheel item contains either a text string, an icon, or both

  Remarks:
    None.
*/
typedef struct leListWheelItem
{
    const leString* string;
    const leImage* icon;
} leListWheelItem;

// DOM-IGNORE-BEGIN
typedef struct leListWheelWidget leListWheelWidget;

#define LE_LISTWHEELWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    uint32_t            (*getVisibleItemCount)(const THIS_TYPE* _this); \
    leResult            (*setVisibleItemCount)(THIS_TYPE* _this, uint32_t cnt); \
    leRelativePosition  (*getIconPosition)(const THIS_TYPE* _this); \
    leResult            (*setIconPosition)(THIS_TYPE* _this, leRelativePosition pos); \
    uint32_t            (*getIconMargin)(const THIS_TYPE* _this); \
    leResult            (*setIconMargin)(THIS_TYPE* _this, uint32_t mg); \
    leBool              (*getShowIndicators)(const THIS_TYPE* _this); \
    leResult            (*setShowIndicators)(THIS_TYPE* _this, leBool b); \
    uint32_t            (*getIndicatorArea)(const THIS_TYPE* _this); \
    leResult            (*setIndicatorArea)(THIS_TYPE* _this, uint32_t area); \
    leBool              (*getShaded)(const THIS_TYPE* _this); \
    leResult            (*setShaded)(THIS_TYPE* _this, leBool b); \
    uint32_t            (*getFlickInitSpeed)(const THIS_TYPE* _this); \
    leResult            (*setFlickInitSpeed)(THIS_TYPE* _this, uint32_t sp); \
    uint32_t            (*getMaxMomentum)(const THIS_TYPE* _this); \
    leResult            (*setMaxMomentum)(THIS_TYPE* _this, uint32_t max); \
    uint32_t            (*getMomentumFalloffRate)(const THIS_TYPE* _this); \
    leResult            (*setMomentumFalloffRate)(THIS_TYPE* _this, uint32_t percent); \
    uint32_t            (*getRotationUpdateRate)(const THIS_TYPE* _this); \
    leResult            (*setRotationUpdateRate)(THIS_TYPE* _this, uint32_t ms); \
    uint32_t            (*getItemCount)(const THIS_TYPE* _this); \
    int32_t             (*appendItem)(THIS_TYPE* _this); \
    int32_t             (*insertItem)(THIS_TYPE* _this, int32_t idx); \
    leResult            (*removeItem)(THIS_TYPE* _this, int32_t idx); \
    leResult            (*removeAllItems)(THIS_TYPE* _this); \
    int32_t             (*getSelectedItem)(const THIS_TYPE* _this); \
    leResult            (*setSelectedItem)(THIS_TYPE* _this, int32_t idx); \
    leResult            (*selectPreviousItem)(THIS_TYPE* _this); \
    leResult            (*selectNextItem)(THIS_TYPE* _this); \
    leString*           (*getItemString)(const THIS_TYPE* _this, int32_t idx); \
    leResult            (*setItemString)(THIS_TYPE* _this, int32_t idx, const leString* str); \
    leImage*            (*getItemIcon)(const THIS_TYPE* _this, int32_t idx); \
    leResult            (*setItemIcon)(THIS_TYPE* _this, int32_t idx, const leImage* img); \
    leListWheelWidget_SelectedItemChangedEvent (*getSelectedItemChangedEventCallback)(const THIS_TYPE* _this); \
    leResult            (*setSelectedItemChangedEventCallback)(THIS_TYPE* _this, leListWheelWidget_SelectedItemChangedEvent cb); \
    leListWheelIndicatorFill (*getIndicatorFill)(const THIS_TYPE* _this); \
    leResult            (*setIndicatorFill)(THIS_TYPE* _this, leListWheelIndicatorFill fill); \
    leListWheelZoomEffects (*getZoomEffects)(const THIS_TYPE* _this); \
    leResult            (*setZoomEffects)(THIS_TYPE* _this, leListWheelZoomEffects zfx); \
    leBool              (*getAutoHideWheel)(const THIS_TYPE* _this); \
    leResult            (*setAutoHideWheel)(THIS_TYPE* _this, leBool b); \
    
typedef struct leListWheelWidgetVTable
{
	LE_LISTWHEELWIDGET_VTABLE(leListWheelWidget)
} leListWheelWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leListWheelWidget

  Summary:
    Implementation of a list wheel widget struct

  Description:
    A list wheel widget is a widget that is similar to a normal list widget
    but can be dragged up or down to cycle through a single active value.  This
    widget is also capable of momentum and motion over time.

  Remarks:
    None.
*/
typedef struct leListWheelWidget
{
    leWidget widget; // widget base class
    
    leListWheelWidgetVTable* fn;

    leArray items; // list of items for the wheel
    int32_t selectedItem; // currently selected item
    int32_t visibleItems; // number of visible items in the wheel
                          // must be odd and >= 3
    int32_t topItem; // the current top item

    leRelativePosition iconPos; // the icon position of the items
    uint32_t iconMargin; // the icon margin of the items

    leBool showIndicators; // controls the visibility of the horizontal
                           // indicator bars in the center of the widget
    uint32_t indicatorArea; // controls the distance between the indicator bars

    uint32_t shaded; // determins if the background of the widget uses gradient
                     // shading to show depth

    int32_t cycleDistance; // determins the amount of drag distance needed
                           // to cycle between items
    int32_t cycleDelta; // tracks the current amount of drag distance

    // these track drag movement over time
    int32_t firstTouchY;
    int32_t touchY;
    int32_t lastTouchY;
    leBool  stillTouching;

    int32_t minFlickDelta; // amount of distance that must be dragged in a single
                           // frame to trigger momentum mode

    int32_t momentum; // current momentum value
    int32_t maxMomentum; // maximum momentum value
    int32_t momentumFalloff; // momentum falloff rate
    int32_t rotation; // determines actual rotation of the wheel
    int32_t rotationCounter; // time-based limiter for rotation calculations
    int32_t rotationTick; // rotation time accumulator

    leBool snapPending;

    leListWheelIndicatorFill indicatorFill; // the indicator's fill type
    leListWheelZoomEffects zoomEffects; // zoomEffects
    leBool autoHideWheel;   //auto hides the wheel
    leBool hideWheel;       //flag to hide/show the wheel

    struct
    {
        int32_t y;
        int32_t per;

        uint32_t nextItem;
    } paintState;

    leListWheelWidget_SelectedItemChangedEvent cb; // item changed callback

    leBorderType borderTypeCache; // Copy of border type, used to restore borders on auto-hide
    leBackgroundType backgroundTypeCache; // Copy of background type, used to restore borders on auto-hide
} leListWheelWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leListWheelWidget* leListWheelWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:


  Parameters:

  Returns:
    leListWheelWidget*

  Remarks:

*/
LIB_EXPORT leListWheelWidget* leListWheelWidget_New();

LIB_EXPORT void leListWheelWidget_Constructor(leListWheelWidget* whl);

#if 0
// *****************************************************************************
/* Function:
    leHAlignment leListWheelWidget_GetAlignment(leListWheelWidget* whl)

  Summary:
    Gets the horizontal alignment for the list widget

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    leHAlignment - the current list halign mode

  Remarks:

*/
LIB_EXPORT leHAlignment leListWheelWidget_GetAlignment(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetAlignment(leListWheelWidget* whl,
                                                  leHAlignment align)

  Summary:
    Sets the horizontal alignment mode for the list widget.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget
    leHAlignment align - the desired halign mode

  Returns:
    leResult

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetAlignment(leListWheelWidget* whl,
                                                   leHAlignment align);

// *****************************************************************************
/* Function:
    uint32_t leListWheelWidget_GetVisibleItemCount(leListWheelWidget* whl)

  Summary:
    Returns the list's visible item count

  Description:


  Parameters:
    leListWidget* lst - the widget

  Returns:
    uint32_t - the number of visible items

  Remarks:

*/
LIB_EXPORT uint32_t leListWheelWidget_GetVisibleItemCount(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetVisibleItemCount(leListWheelWidget* whl,
                                                   uint32_t cnt)

  Summary:
    Sets the number of visible items in the list.  Must be greater than or equal
    to three and must be an odd number.

  Description:


  Parameters:
    leListWidget* lst - the widget
    uint32_t cnt - the desired number of items

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetVisibleItemCount(leListWheelWidget* whl,
                                                          uint32_t cnt);


// *****************************************************************************
/* Function:
    leRelativePosition leListWheelWidget_GetIconPosition(leListWheelWidget* whl)

  Summary:
    Sets the icon position for the list wheel widget.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    leRelativePosition - the current icon position

  Remarks:

*/
LIB_EXPORT leRelativePosition leListWheelWidget_GetIconPosition(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetIconPosition(leListWheelWidget* whl,
                                                      leRelativePosition pos)

  Summary:
    Sets the icon position for the list wheel widget

  Description:


  Parameters:
    leListWheelWidget* whl - the widget
    leRelativePosition pos - the relative position setting

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetIconPosition(leListWheelWidget* whl,
                                                      leRelativePosition pos);

// *****************************************************************************
/* Function:
    uint32_t leListWheelWidget_GetIconMargin(leListWheelWidget* whl)

  Summary:
    Gets the icon margin value for the list wheel widget

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    uint32_t - the icon margin value

  Remarks:

*/
LIB_EXPORT uint32_t leListWheelWidget_GetIconMargin(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetIconMargin(leListWheelWidget* whl, uint32_t mg)

  Summary:
    Sets the icon margin value for the list widget.

  Description:
    The icon margin value is the distance between the icon image and the text.

  Parameters:
    leListWheelWidget* whl - the widget
    uint32_t mg - the margin value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetIconMargin(leListWheelWidget* whl,
                                                    uint32_t mg);

// *****************************************************************************
/* Function:
    leBool leListWheelWidget_GetShowIndicators(leListWheelWidget* whl)

  Summary:
    Returns true if the list is displaying its selected item indicators

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    leBool - true if the indicators are being shown

  Remarks:

*/
LIB_EXPORT leBool leListWheelWidget_GetShowIndicators(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetShowIndicators(leListWheelWidget* whl,
                                                 leBool b)

  Summary:
    Configures the list to display the selected item indicator bars

  Description:


  Parameters:
    leListWheelWidget* whl - the widget
    leBool b - configures the indicator bar display state

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetShowIndicators(leListWheelWidget* whl,
                                                        leBool b);

// *****************************************************************************
/* Function:
    uint32_t leListWheelWidget_GetIndicatorArea(leListWheelWidget* whl)

  Summary:
    Returns the spacing for the selected item indicator bars.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    uint32_t - the display area

  Remarks:

*/
LIB_EXPORT uint32_t leListWheelWidget_GetIndicatorArea(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetIndicatorArea(leListWheelWidget* whl,
                                                uint32_t area)

  Summary:
    Configures the display area for the list selection indicator bars

  Description:
    This space is measured from the middle of the widget outward.

  Parameters:
    leListWheelWidget* whl - the widget
    uint32_t area - the display area for the indicator bars

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetIndicatorArea(leListWheelWidget* whl,
                                                       uint32_t area);

// *****************************************************************************
/* Function:
    leBool leListWheelWidget_GetShaded(leListWheelWidget* whl)

  Summary:
    Returns true if the list is using gradient shading to illustrate depth

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    leBool - true gradient shading is being used

  Remarks:

*/
LIB_EXPORT leBool leListWheelWidget_GetShaded(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetShaded(leListWheelWidget* whl,
                                         leBool b)

  Summary:
    Configures the list to use gradient or flat background shading

  Description:


  Parameters:
    leListWheelWidget* whl - the widget
    leBool b - true if gradient shading should be used

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetShaded(leListWheelWidget* whl,
                                                leBool b);

// *****************************************************************************
/* Function:
    uint32_t leListWheelWidget_GetFlickInitSpeed(leListWheelWidget* whl)

  Summary:
    Returns the flick init speed for the wheel.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    uint32_t - the flick init speed value

  Remarks:

*/
LIB_EXPORT uint32_t leListWheelWidget_GetFlickInitSpeed(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetFlickInitSpeed(leListWheelWidget* whl,
                                                 uint32_t speed)

  Summary:
    Configures the flick init speed for the list wheel

  Description:
    The flick init speed is the drag distance needed to move the wheel into
    momentum mode.  It is the distance that must be covered from one Legato
    update frame to another.

  Parameters:
    leListWheelWidget* whl - the widget
    uint32_t speed - the flick init speed value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetFlickInitSpeed(leListWheelWidget* whl,
                                                        uint32_t speed);

// *****************************************************************************
/* Function:
    uint32_t leListWheelWidget_GetMaxMomentum(leListWheelWidget* whl)

  Summary:
    Returns the maximum momentum value for the wheel.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    uint32_t - the maximum momentum value.

  Remarks:

*/
LIB_EXPORT uint32_t leListWheelWidget_GetMaxMomentum(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetMaxMomentum(leListWheelWidget* whl,
                                              uint32_t max)

  Summary:
    Configures the maximum momentum value for the wheel

  Description:
    When a wheel is in momenum mode addition drag/flick gestures will add
    more momentum to the wheel.  The maximum momentum value governs the maximum
    speed at which the wheel can rotate at any single point in time.

  Parameters:
    leListWheelWidget* whl - the widget
    uint32_t max - the maximum momentum value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetMaxMomentum(leListWheelWidget* whl,
                                                     uint32_t max);

// *****************************************************************************
/* Function:
    uint32_t leListWheelWidget_GetMomentumFalloffRate(leListWheelWidget* whl)

  Summary:
    Returns the momentum falloff rate for the wheel.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    uint32_t - the momentum falloff rate value.

  Remarks:

*/
LIB_EXPORT uint32_t leListWheelWidget_GetMomentumFalloffRate(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetMomentumFalloffRate(leListWheelWidget* whl,
                                                      uint32_t rate)

  Summary:
    Configures the momentum falloff rate for the wheel

  Description:
    When a wheel is in momenum mode and during each rotation update tick the
    wheel will reduce its current momentum value by this falloff percentage.
    The higher this value is the faster a wheel will slow down.  The wheel is
    limited to integer math so the lowest this value can be is one.

  Parameters:
    leListWheelWidget* whl - the widget
    uint32_t max - the momentum falloff value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetMomentumFalloffRate(leListWheelWidget* whl,
                                                             uint32_t rate);

// *****************************************************************************
/* Function:
    uint32_t leListWheelWidget_GetRotationUpdateRate(leListWheelWidget* whl)

  Summary:
    Returns the wheel rotation update rate.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    uint32_t - the rotation update rate value.

  Remarks:

*/
LIB_EXPORT uint32_t leListWheelWidget_GetRotationUpdateRate(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetRotationUpdateRate(leListWheelWidget* whl,
                                                     uint32_t ms)

  Summary:
    Configures the rotation update rate for a wheel

  Description:
    When a wheel is in momenum mode it may be too costly to update with every
    Legato update loop call.  This value can delay a wheel update.  For instance,
    if Legato is updating every 20ms, the wheel can be set to update every 60ms
    and it will update approximately every three to four Legato updates.  This
    can cut down on the number of repaints the wheel needs to perform and can
    also slow the wheel down it if is rotating too fast for the application
    to handle.  This value is typically expressed in milliseconds.

  Parameters:
    leListWheelWidget* whl - the widget
    uint32_t ms - the desired rotation update rate

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetRotationUpdateRate(leListWheelWidget* whl,
                                                            uint32_t ms);

// *****************************************************************************
/* Function:
    uint32_t leListWheelWidget_GetItemCount(leListWheelWidget* whl)

  Summary:
    Gets the number of items currently contained in the list

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    uint32_t - the number of items in the list

  Remarks:

*/
LIB_EXPORT uint32_t leListWheelWidget_GetItemCount(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    uint32_t leListWheelWidget_AppendItem(leListWheelWidget* whl)

  Summary:
    Appends a new item entry to the list.  The initial value of the item
    will be empty.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    uint32_t - the index of the newly appended item

  Remarks:

*/
LIB_EXPORT uint32_t leListWheelWidget_AppendItem(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    uint32_t leListWheelWidget_InsertItem(leListWheelWidget* whl, uint32_t idx)

  Summary:
    Attempts to insert a new item at the desired index.  Existing items at
    idx or greater will be shuffled one index to the right.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget
    uint32_t idx - the desired index of the new item

  Returns:
    uint32_t - the index of the inserted item

  Remarks:

*/
LIB_EXPORT uint32_t leListWheelWidget_InsertItem(leListWheelWidget* whl, uint32_t idx);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_RemoveItem(leListWheelWidget* whl, uint32_t idx)

  Summary:
    Attempts to remove an item from the list.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget
    uint32_t idx - the index to remove from the list

  Returns:
    leResult - the operation result

  Remarks:
    The memory owned by the string item will be freed automatically.
*/
LIB_EXPORT leResult leListWheelWidget_RemoveItem(leListWheelWidget* whl, uint32_t idx);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_RemoveAllItems(leListWheelWidget* whl)

  Summary:
    Attempts to remove all items from the list.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    leResult - the operation result

  Remarks:
    All memory owned by each item string will be freed automatically.
*/
LIB_EXPORT leResult leListWheelWidget_RemoveAllItems(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    int32_t leListWheelWidget_GetSelectedItem(leListWheelWidget* whl)

  Summary:
    Returns the index of the currently selected item.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    int32_t - the index of the selected item or -1 if an error occured

  Remarks:

*/
LIB_EXPORT int32_t leListWheelWidget_GetSelectedItem(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetSelectedItem(leListWheelWidget* whl,
                                               uint32_t idx)

  Summary:
    Attempts to set the selectedi tem index

  Description:


  Parameters:
    leListWheelWidget* whl - the widget
    uint32_t idx - the desired selected item index

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetSelectedItem(leListWheelWidget* whl,
                                                      uint32_t idx);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SelectPreviousItem(leListWheelWidget* whl)

  Summary:
    Attempts to move the selected item index to the previous item in the list.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SelectPreviousItem(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SelectNextItem(leListWheelWidget* whl)

  Summary:
    Attempts to move the selected item index to the next item in the list.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SelectNextItem(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_GetItemString(leListWheelWidget* whl,
                                           uint32_t idx,
                                           leString* str)

  Summary:
    Gets the text value for an item in the list.

  Description:
    This function allocates memory and initializes the input string pointer.  The
    caller is responsible for managing the memory once this function returns.

  Parameters:
    leListWheelWidget* whl - the widget
    uint32_t idx - the index to consider
    leString* str - a pointer to an leString object

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_GetItemString(leListWheelWidget* whl,
                                                  uint32_t idx,
                                                  leString* str);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetItemString(leListWheelWidget* whl,
                                           uint32_t index,
                                           leString str)

  Summary:
    Sets the text value for an item in the list.

  Description:
    This function copies the contents of the input string into its internal
    string buffer.  The input string can then be freed or altered without
    affecting the label's internal string value.

  Parameters:
    leListWheelWidget* whl - the widget
    uint32_t idx - the index to consider
    leString str - an leString object

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetItemString(leListWheelWidget* whl,
                                                  uint32_t index,
                                                  leString str);


// *****************************************************************************
/* Function:
    leImage* leListWheelWidget_GetItemIcon(leListWheelWidget* whl,
                                                   uint32_t index)

  Summary:
    Gets the pointer to the image asset for the icon for the item at the given
    index.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget
    uint32_t idx - the index to consider

  Returns:
    leImage* - the image asset pointer or NULL

  Remarks:

*/
LIB_EXPORT leImage* leListWheelWidget_GetItemIcon(leListWheelWidget* whl,
                                                          uint32_t index);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetItemIcon(leListWheelWidget* whl,
                                           uint32_t index,
                                           leImage* img)

  Summary:
    Sets the icon pointer for a given index.

  Description:


  Parameters:
    leListWheelWidget* whl - the widget
    uint32_t idx - the index to configure
    leImage* - the image asset pointer to use as the icon

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetItemIcon(leListWheelWidget* whl,
                                                  uint32_t index,
                                                  leImage* img);



// *****************************************************************************
/* Function:
    leListWheelWidget_SelectedItemChangedEvent leListWheelWidget_GetSelectedItemChangedEventCallback(leListWheelWidget* whl)

  Summary:
    Gets the callback for the item selected changed event

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    leListWheelWidget_SelectedItemChangedEvent - the current pointer to the callback or NULL

  Remarks:

*/
LIB_EXPORT leListWheelWidget_SelectedItemChangedEvent leListWheelWidget_GetSelectedItemChangedEventCallback(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetSelectedItemChangedEventCallback(leListWheelWidget* whl,
                                                                   leListWheelWidget_SelectedItemChangedEvent cb)

  Summary:


  Description:
    This callback is called whenver the wheel's selected item changes.

  Parameters:
    leListWheelWidget* whl - the widget
    leListWheelWidget_SelectedItemChangedEvent - the desired pointer to callback or NULL

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetSelectedItemChangedEventCallback(leListWheelWidget* whl,
                                                                          leListWheelWidget_SelectedItemChangedEvent cb);

// *****************************************************************************
/* Function:
    leListWheelIndicatorFill leListWheelWidget_GetIndicatorFill(leListWheelWidget* whl)

  Summary:
    Gets the indicator area fill type

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    leListWheelIndicatorFill - the indicator area fill type

  Remarks:

*/
LIB_EXPORT leListWheelIndicatorFill leListWheelWidget_GetIndicatorFill(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetIndicatorFill(leListWheelWidget* whl, leListWheelIndicatorFill fill)

  Summary:
    Sets the indicator fill type

  Description:
    Sets the indicator fill type

  Parameters:
    leListWheelWidget* whl - the widget
    leListWheelIndicatorFill fill - fill type

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetIndicatorFill(leListWheelWidget* whl, leListWheelIndicatorFill fill);

// *****************************************************************************
/* Function:
    leListWheelZoomEffects leListWheelWidget_GetZoomEffects(leListWheelWidget* whl)

  Summary:
    Gets the list wheel zoom effect

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    leListWheelZoomEffects - the list wheel zoom effect type

  Remarks:

*/
LIB_EXPORT leListWheelZoomEffects leListWheelWidget_GetZoomEffects(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetZoomEffects(leListWheelWidget* whl, leListWheelZoomEffects zoomEffects)

  Summary:
    Sets the list wheel zoom effect

  Description:
    Sets the list wheel zoom effect

  Parameters:
    leListWheelWidget* whl - the widget
    leListWheelZoomEffects zoomEffects - the zoom effect

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetZoomEffects(leListWheelWidget* whl, leListWheelZoomEffects zoomEffects);

// *****************************************************************************
/* Function:
    leListWheelIndicatorFill leListWheelWidget_GetAutoHideWheel(leListWheelWidget* whl)

  Summary:
    Returns the list wheel auto hide setting

  Description:


  Parameters:
    leListWheelWidget* whl - the widget

  Returns:
    leBool - true if the list wheel is set to auto hide

  Remarks:

*/
LIB_EXPORT leBool leListWheelWidget_GetAutoHideWheel(leListWheelWidget* whl);

// *****************************************************************************
/* Function:
    leResult leListWheelWidget_SetAutoHideWheel(leListWheelWidget* whl, leBool autoHide)

  Summary:
    Sets the list wheel to auto hide when not active

  Description:
    Sets the list wheel to auto hide when not active

  Parameters:
    leListWheelWidget* whl - the widget
    leBool autoHide - sets the list wheel to auto hide

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leListWheelWidget_SetAutoHideWheel(leListWheelWidget* whl, leBool autoHide);

// DOM-IGNORE-BEGIN
// internal use only
void _leListWheelWidget_GetItemTextRect(leListWheelWidget* whl,
                                        uint32_t idx,
                                        uint32_t pos,
                                        leRect* textRect,
                                        leRect* drawRect);

// internal use only
void _leListWheelWidget_GetItemIconRect(leListWheelWidget* whl,
                                        uint32_t idx,
                                        uint32_t pos,
                                        leRect* imgRect,
                                        leRect* imgSrcRect);
// DOM-IGNORE-END

#endif

#endif // LE_LISTWHEEL_WIDGET_ENABLED
#endif /* LEGATO_LISTWHEELWIDGET_H */
