/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_radial_menu.h

  Summary:
    

  Description:
    This module implements radial menu widget functions.
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
#ifndef LEGATO_RADIALMENU_H
#define LEGATO_RADIALMENU_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#if LE_RADIALMENU_WIDGET_ENABLED == 1

#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/widget/image/legato_widget_image.h"
#include "gfx/legato/datastructure/legato_list.h"
#include "gfx/legato/string/legato_string.h"

typedef struct leRadialMenuWidget leRadialMenuWidget;

typedef void (*leRadialMenuWidget_ItemSelectedEvent)(leRadialMenuWidget*, leWidget*, int32_t);
typedef void (*leRadialMenuWidget_ItemProminenceChangedEvent)(leRadialMenuWidget*, leWidget*, int32_t);

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

typedef enum leRadialMenuWidgetState
{
    LE_RADIAL_MENU_INIT,
	LE_RADIAL_MENU_INPUT_READY,
	LE_RADIAL_MENU_HANDLE_USER_MOVE_REQUEST,
    LE_RADIAL_MENU_RESET_TO_INPUT_POS            
} leRadialMenuWidgetState;

typedef enum leRadialMenuWidgetInterpolationMode
{
	LE_RADIAL_MENU_INTERPOLATE_OFF,
	LE_RADIAL_MENU_INTERPOLATE_GRADUAL,
	LE_RADIAL_MENU_INTERPOLATE_PROMINENT
} leRadialMenuWidgetInterpolationMode;

typedef enum leRadialMenuEllipseType
{
	LE_RADIAL_MENU_ELLIPSE_TYPE_DEFAULT,
	LE_RADIAL_MENU_ELLIPSE_TYPE_ORBITAL,
	LE_RADIAL_MENU_ELLIPSE_TYPE_ROLLODEX
} leRadialMenuEllipseType;

// DOM-IGNORE-BEGIN
typedef struct leRadialMenuWidget leRadialMenuWidget;

#define LE_RADIALMENUWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leBool    (*isProminent)(const THIS_TYPE* _this, const leWidget* widget); \
    leResult  (*setProminent)(THIS_TYPE* _this, const leWidget* widget); \
    int32_t   (*getProminentIndex)(const THIS_TYPE* _this); \
    leResult  (*setProminentIndex)(THIS_TYPE* _this, int32_t index); \
    leResult  (*setNumberOfItemsShown)(THIS_TYPE* _this, uint32_t cnt); \
    leResult  (*setHighlightProminent)(THIS_TYPE* _this, leBool hl); \
    int32_t   (*getTheta)(const THIS_TYPE* _this); \
    leResult  (*setTheta)(THIS_TYPE* _this, int32_t tht); \
    leResult  (*setEllipseType)(THIS_TYPE* _this, leRadialMenuEllipseType type); \
    leResult  (*addWidget)(THIS_TYPE* _this, leWidget* wgt); \
    leResult  (*removeWidget)(THIS_TYPE* _this, leWidget* wgt); \
    leWidget* (*getWidgetAtIndex)(const THIS_TYPE* _this, int32_t idx); \
    leResult  (*setWidgetAtIndex)(THIS_TYPE* _this, int32_t idx, leWidget* wgt); \
    leResult  (*removeAllWidgets)(THIS_TYPE* _this); \
    leResult  (*setScaleMode)(THIS_TYPE* _this, leRadialMenuWidgetInterpolationMode mode); \
    leResult  (*setScaleRange)(THIS_TYPE* _this, int32_t min, int32_t max); \
    leResult  (*setBlendMode)(THIS_TYPE* _this, leRadialMenuWidgetInterpolationMode mode); \
    leResult  (*setBlendRange)(THIS_TYPE* _this, int32_t min, int32_t max); \
    leResult  (*setTouchArea)(THIS_TYPE* _this, int32_t x, int32_t y, int32_t width, int32_t height); \
    leResult  (*setDrawEllipse)(THIS_TYPE* _this, leBool b); \
    leRadialMenuWidget_ItemSelectedEvent (*getItemSelectedEventCallback)(const THIS_TYPE* _this); \
    leResult  (*setItemSelectedEventCallback)(THIS_TYPE* _this, leRadialMenuWidget_ItemSelectedEvent cb); \
    leRadialMenuWidget_ItemProminenceChangedEvent (*getItemProminenceChangedEventCallback)(const THIS_TYPE* _this); \
    leResult  (*setItemProminenceChangedEventCallback)(THIS_TYPE* _this, leRadialMenuWidget_ItemProminenceChangedEvent cb); \
    
typedef struct leRadialMenuWidgetVTable
{
	LE_RADIALMENUWIDGET_VTABLE(leRadialMenuWidget)
} leRadialMenuWidgetVTable; 

// DOM-IGNORE-END

typedef struct leRadialMenuItemNode
{
	leWidget* widget; // point to the widget of the item
	int32_t t; // the angle in degress between 0 - 360, representing the relative position of the item on the track
	
	//leWidgetInputHandler inputHandler; 
    
	//leWidget_TouchDownEvent_FnPtr origTouchDown; //the widget item's original touch down event, 
                                                 //allows the radial menu to work as a hub to route to the appropriate widget
	//leWidget_TouchUpEvent_FnPtr origTouchUp; //the widget item's original touch up event
                                                 //allows the radial menu to work as a hub to route to the appropriate widget
	//leWidget_TouchMovedEvent_FnPtr origTouchMoved; //the widget item's original touch move event

    leRect origSize;  //the original size of the widget, it is a reference point for scaling
    uint32_t origAlphaAmount; //the original alpha value of the widget, it is a reference point for scaling
    
} leRadialMenuItemNode;

// *****************************************************************************
/* Enumeration:
    leRadialMenuWidget

  Summary:
    Implementation of a radial menu widget struct

  Description:
    A radial menu is a master widget that manages the movement, in an elliptical 
	track, of a list of widgets.  It also manages the draw order and scaling of 
	each widget item.

	It is essentially a group of widgets which provides a mutually exclusive 
	selection capability so that only one item may be selected at any one time.

  Remarks:
    None.
*/
typedef struct leRadialMenuWidget
{
    leWidget widget; // widget base class
    
    leRadialMenuWidgetVTable* fn;

	leRadialMenuWidgetState state;

    int32_t prominentIndex;
    int32_t lastProminentIndex;
	int32_t userRequestedAngleDiff; // the angle for the radial menu to rotate as requested by user
	int32_t targetAngleDiff; // the angle for the radial menu to rotate for prominent item to be in front
    int32_t userRequestedDirection; // tracks the direction that the user requested for rotation
    
    leBool drawEllipse; // indicates if the radial menu is selected
    leBool highlightProminent; // highlight the prominent widget

	leImageWidget* highlighter; // this widget manages the selector art asset
    
	int32_t a;  // the half-length of the 0-180 axis of the ellipse
	int32_t b;  // the half-length of the 90-270 axis of the ellipse
	int32_t theta; // the angle of rotation of the entire ellipse
	
    leBool touchPressed; // keep track of users touch input
    
    leBool ellipseChanged; // keeps track if the elliptical track has changed
    
	leRadialMenuWidgetInterpolationMode scaleMode;  // the enable item size scaling within the widget

	int32_t maxSizePercent;  // the maximum size scale between 1 - 200%
	int32_t minSizePercent;  // the minimum size scale between 1 - 200%

	leRect touchArea; // the area specified within the widget that touch events are detected

	leRadialMenuWidgetInterpolationMode blendMode; // the enable item alpha scaling within the widget

	int32_t maxAlphaAmount;  // the maximum alpha between 0 - 255
	int32_t minAlphaAmount;  // the minimum alpha between 0 - 255

    uint32_t itemsShown; // keeps count of how many items to visible, this number should be less than or equal to total number of widget items
    leList widgetList; // this is the list of widgets
    leList shownList; // this is the partial list of widgets shown
    leList hiddenList; // this is the partial list of widgets hidden

    leRadialMenuItemNode* widestWidgetItem; // keeps track of which widget is the widgets for major axis calculation
    leRadialMenuItemNode* tallestWidgetItem; // keeps track of which widget is the widgets for minor axis calculation
    
    leRadialMenuWidget_ItemSelectedEvent itemSelectedEvent; // an item is selected event callback
	leRadialMenuWidget_ItemProminenceChangedEvent itemProminenceChangedEvent; // whenever a new item is in prominence event callback

    leRadialMenuEllipseType ellipseType;
} leRadialMenuWidget;


// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leRadialMenuWidget* leRadialMenuWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the management of this memory until the widget is added to
    a widget tree.

  Description:
    

  Parameters:
    
  Returns:
    leRadialMenuWidget*
    
  Remarks:
    
*/
LIB_EXPORT leRadialMenuWidget* leRadialMenuWidget_New();

LIB_EXPORT void leRadialMenuWidget_Constructor(leRadialMenuWidget* rad);

#if 0

// *****************************************************************************
/* Function:
    leBool leRadialMenuWidget_IsProminent(leRadialMenuWidget* mn, leWidget* widget)

  Summary:
    Returns true if this radial menu item is currently in the primary selectable position

  Description:
    

  Parameters:
    leRadialMenuWidget* mn - the radial menu widget
	leWidget* mn - the item widget to inspect

  Returns:
    leBool - true if this widget is currently prominent
    
  Remarks:
    
*/
LIB_EXPORT leBool leRadialMenuWidget_IsProminent(leRadialMenuWidget* mn, leWidget* widget);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetProminent(leRadialMenuWidget* mn, leWidget* widget)

  Summary:
    Sets this widget as prominent.

  Description:
    If this widget belongs to a radial menu then this function will
    cycle the radial menu to show the widget in the primary selectable position.

  Parameters:
  leRadialMenuWidget* mn - the radial menu widget
  leWidget* widget - the item widget to show prominence

  Returns:
    leResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT leResult leRadialMenuWidget_SetProminent(leRadialMenuWidget* mn, leWidget* widget);

// *****************************************************************************
/* Function:
    int32_t leRadialMenuWidget_GetProminentIndex(leRadialMenuWidget* mn)

  Summary:
    Gets the index of the widget within the radial menu that is prominent

  Description:
    Returns the index of the widget that is in the primary selectable position.

  Parameters:
    leRadialMenuWidget* mn - the radial menu widget

  Returns:
    int32_t - the index of the widget, returns -1 if there is a failure
    
  Remarks:
    
*/
LIB_EXPORT int32_t leRadialMenuWidget_GetProminentIndex(leRadialMenuWidget* mn);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetNumberOfItemsShown(leRadialMenuWidget* mn, int32_t num)

  Summary:
    Sets the number of items visible on the menu

  Description:
    Sets the number of items visible on the menu, this number can be less than or equal to
    the total number of items

  Parameters:
    leRadialMenuWidget* mn - the radial menu widget
    int32_t num - the number of widgets shown

  Returns:
    leResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT leResult leRadialMenuWidget_SetNumberOfItemsShown(leRadialMenuWidget* mn, int32_t num);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetProminentIndex(leRadialMenuWidget* mn, int32_t index)

  Summary:
    Sets a widget with index within the radial menu as prominent

  Description:
    If the index supplied is within the range of widgets within te radial menu then 
    this function will cycle the radial menu to show the widget 
    in the primary selectable position.

  Parameters:
    leRadialMenuWidget* mn - the radial menu widget
    int32_t index - the item widget to show prominence

  Returns:
    leResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT leResult leRadialMenuWidget_SetProminentIndex(leRadialMenuWidget* mn, uint32_t index);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetHighlightProminent(leRadialMenuWidget* mn, leBool enable)

  Summary:
    Sets the item widget to highlight when it is at the prominent location

  Description:
    This tells the radial menu widget to enable/disable the ability for the prominent item widget to be
    highlighted when it comes to rest at the prominent location.
 
  Parameters:
    leRadialMenuWidget* mn - the radial menu widget
    leBool enable - the item widget to highlight when prominent

  Returns:
    leResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT leResult leRadialMenuWidget_SetHighlightProminent(leRadialMenuWidget* mn, leBool enable);

// *****************************************************************************
/* Function:
    int32_t leRadialMenuWidget_GetTheta(leRadialMenuWidget* mn)

  Summary:
    Gets the theta value for the radial menu.

  Description:
    This function returns the current value of theta

  Parameters:
    leRadialMenuWidget* mn - the widget
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/
LIB_EXPORT int32_t leRadialMenuWidget_GetTheta(leRadialMenuWidget* mn);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetTheta(leRadialMenuWidget* mn,
                                         int32_t theta)

  Summary:
    Sets the theta value for the radial menu.

  Description:
    This function sets the theta (angle of rotation of the ellipse)

  Parameters:
    leRadialMenuWidget* mn - the widget
    int32_t theta - angle in degrees of rotation relative to the y-axis of the ellipse
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/                                             
LIB_EXPORT leResult leRadialMenuWidget_SetTheta(leRadialMenuWidget* mn,
                                                int32_t theta);


// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetEllipseType(leRadialMenuWidget* mn,
                                               leRadialMenuEllipseType type)

  Summary:
    Sets the ellipse type for the radial menu track.

  Description:
    This function sets the ellipse type for the radial menu.  There are three types:
    DEFAULT - the elliptical track is best-fit based on the width and height of the 
              radial menu widget and all the item widgets with scaling factored in.
              The theta angle value is used for the ellipse but only in a limited way.
    ORBITAL - the elliptical track is flatter and factors in the theta angle value more.
              Some of the items may be clipped out of the widget area depending on the 
              size of radial widget and the theta angle
    ROLLODEX - the elliptical track is vertical in-nature and visually simular to a rollodex

  Parameters:
    leRadialMenuWidget* mn - the widget
    leRadialMenuEllipseType type - type of ellipse
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/                                             
LIB_EXPORT leResult leRadialMenuWidget_SetEllipseType(leRadialMenuWidget* mn,
                                                      leRadialMenuEllipseType type);


// *****************************************************************************
/* Function:
    leWidget* leRadialMenuWidget_GetWidget(leRadialMenuWidget* mn, int32_t index)

  Summary:
    Gets the pointer for the widget by index

  Description:
    Returns the pointer to the widget

  Parameters:
    leRadialMenuWidget* mn - the radial menu widget
	uint32_t index - index value

  Returns:
    leWidget* - the pointer to the widget at the index value on the list
	Returns NULL if the index is out-of-range of the current list
    
  Remarks:
    
*/    
LIB_EXPORT leWidget* leRadialMenuWidget_GetWidget(leRadialMenuWidget* mn, uint32_t index);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetWidgetAt(leRadialMenuWidget* mn, 
											leWidget* widget,
											int32_t index)

  Summary:
    Insert a widget to the radial menu at the index specified

  Description:
    

  Parameters:
    leRadialMenuWidget* mn - the widget
	leWidget* widget - the item widget 
	uint32_t index - index value
    
  Returns:
    leResult - the operation result, returns LE_SUCCESS if the set was successful
				returns fail if the index value is out of the range of the widget list

    
  Remarks:
    
*/    
LIB_EXPORT leResult leRadialMenuWidget_SetWidgetAt(leRadialMenuWidget* mn,
                                                   leWidget* widget,
                                                   uint32_t index);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_AddWidget(leRadialMenuWidget* mn, leWidget* widget)

  Summary:
    Add a widget to the radial menu

  Description:
    Adds a widget for the radial menu to manage, increments the total item count

  Parameters:
    leRadialMenuWidget* mn - the radial menu widget
	leWidget* widget - the item widget

  Returns:
	leResult - the operation result

  Remarks:
    
*/    
LIB_EXPORT leResult leRadialMenuWidget_AddWidget(leRadialMenuWidget* mn, leWidget* widget);

// *****************************************************************************
/* Function:
	leResult leRadialMenuWidget_RemoveWidget(leRadialMenuWidget* mn, leWidget* widget)

   Summary:
	Removes a widget to the radial menu

   Description:
	Removes a widget for the radial menu to manage, decrements the total item count

   Parameters:
	leRadialMenuWidget* mn - the radial menu widget
	leWidget* widget - the item widget

   Returns:
	leResult - the operation result, returns LE_FAIL if a match is not found

   Remarks:

*/
LIB_EXPORT leResult leRadialMenuWidget_RemoveWidget(leRadialMenuWidget* mn, leWidget* widget);

// *****************************************************************************
/* Function:
	leResult leRadialMenuWidget_ClearItems(leRadialMenuWidget* mn)

  Summary:
    Clears all items in the radial menu widget

  Description:
    Removes all items

  Parameters:
    leRadialMenuWidget* mn - the widget
        
  Returns:
    leResult - the operation result

  Remarks:
    
*/                                                           
LIB_EXPORT leResult leRadialMenuWidget_ClearItems(leRadialMenuWidget* mn);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetSizeScaling(leRadialMenuWidget* mn,
                                                leRadialMenuWidgetScaleType setting)

  Summary:
    Enables per item size scaling for the radial menu

  Description:
    Enable/Disable the ability for the radial menu to scale the items sizes as they
	travel into the background

  Parameters:
    leRadialMenuWidget* mn - the widget
	leRadialMenuWidgetScaleType setting - setting flag
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/    
LIB_EXPORT leResult leRadialMenuWidget_SetSizeScaling(leRadialMenuWidget* mn,
														leRadialMenuWidgetScaleType setting);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetAlphaScaling(leRadialMenuWidget* mn,
														leRadialMenuWidgetScaleType setting)

  Summary:
    Enables per item alpha scaling for the radial menu

  Description:
    Enable/Disable the ability for the radial menu to scale the items alpha as they
	travel into the background

  Parameters:
    leRadialMenuWidget* mn - the widget
	leRadialMenuWidgetScaleType setting - setting flag

  Returns:
    leResult - the operation result
    
  Remarks:
    
*/    
LIB_EXPORT leResult leRadialMenuWidget_SetAlphaScaling(leRadialMenuWidget* mn,
														leRadialMenuWidgetScaleType setting);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetSizeScaleMinMax(leRadialMenuWidget* mn, 
														int32_t min, int32_t max)

  Summary:
    Sets the minimum and maximum size scaling ratio in percent

  Description:
    Sets the minimum and maximum size scaling ratio for the items. These values
	are only used if leRadialMenuWidget_SetSizeScaling is called and 
	size scaling is enabled 

  Parameters:
    leRadialMenuWidget* mn - the widget
	int32_t min - the minimum size scale percentage, it should be between 1 - 200
	int32_t max - the maximum size scale percentage, it should be between 1 - 200

  Returns:
    leResult - the operation result

  Remarks:
    
*/    
LIB_EXPORT leResult leRadialMenuWidget_SetSizeScaleMinMax(leRadialMenuWidget* mn,
															int32_t min, int32_t max);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetAlphaScaleMinMax(leRadialMenuWidget* mn, 
														int32_t min, int32_t max)

  Summary:
    Sets the minimum and maximum alpha scaling ratio

  Description:
    Sets the minimum and maximum alpha scaling ratio for the items. These values
	are only used if leRadialMenuWidget_SetAlphaScaling is called and 
	alpha scaling is enabled 

  Parameters:
    leRadialMenuWidget* mn - the widget
	int32_t min - the minimum alpha scale, it should be between 0 - 255
	int32_t max - the maximum alpha scale, it should be between 0 - 255

  Returns:
    leResult - the operation result

  Remarks:
    
*/    
LIB_EXPORT leResult leRadialMenuWidget_SetAlphaScaleMinMax(leRadialMenuWidget* mn,
															int32_t min, int32_t max);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetTouchArea(leRadialMenuWidget* mn, 
                                int32_t x, int32_t y, int32_t width, int32_t height)

  Summary:
    Sets the area that touch input is allowed within the radial menu widget

  Description:
    Sets the area that touch input is permitted. This area has to be at or smaller
	than the rectangular area of the entire radial menu widget.  The default is
	the bottom half of the widget.

  Parameters:
    leRadialMenuWidget* mn - the widget
	leRect rect - rectangular area, x-y represents offsets in local space

  Returns:
    leResult - the operation result

  Remarks:
    
*/    
LIB_EXPORT leResult leRadialMenuWidget_SetTouchArea(leRadialMenuWidget* mn,
                                int32_t x, int32_t y, int32_t width, int32_t height);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetDrawEllipse(leRadialMenuWidget* mn, leBool enable)

  Summary:
    Enables drawing the elliptical track for the radial menu

  Description:
    Enable/Disable the drawing of the elliptical track of travel of the items in the 
 *  radial menu

  Parameters:
    leRadialMenuWidget* mn - the widget
	leRadialMenuWidgetScaleType setting - setting flag

  Returns:
    leResult - the operation result
    
  Remarks:
    
*/    
LIB_EXPORT leResult leRadialMenuWidget_SetDrawEllipse(leRadialMenuWidget* mn, leBool enable);

// *****************************************************************************
/* Function:
    leRadialMenuWidget_ItemSelectedEvent leRadialMenuWidget_GetItemSelectedEventCallback(leRadialMenuWidget* mn)

  Summary:
    Gets the current radial menu item selected event callback

  Description:
    

  Parameters:
    leRadialMenuWidget* mn - the widget
        
  Returns:
    leRadialMenuWidget_ItemSelectedEvent - a valid callback pointer or NULL
    
  Remarks:
    
*/    
LIB_EXPORT leRadialMenuWidget_ItemSelectedEvent leRadialMenuWidget_GetItemSelectedEventCallback(leRadialMenuWidget* mn);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetItemSelectedEventCallback(leRadialMenuWidget* mn,
                                                          leRadialMenuWidget_ItemSelectedEvent cb)

  Summary:
    Sets the radial menu item selected event callback

  Description:
    This callback is called when an item widget in the radial menu becomes selected

  Parameters:
    leRadialMenuWidget* mn - the widget
    leRadialMenuWidget_ItemSelectedEvent - a valid callback pointer or NULL
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/    
LIB_EXPORT leResult leRadialMenuWidget_SetItemSelectedEventCallback(leRadialMenuWidget* mn,
													leRadialMenuWidget_ItemSelectedEvent cb);

// *****************************************************************************
/* Function:
    leRadialMenuWidget_ItemProminenceChangedEvent leRadialMenuWidget_GetItemProminenceChangeddEventCallback(leRadialMenuWidget* mn)

  Summary:
    Gets the current radial menu item prominence change event callback

  Description:
    

  Parameters:
    leRadialMenuWidget* mn - the widget
        
  Returns:
    leRadialMenuWidget_ItemProminenceChangedEvent - a valid callback pointer or NULL
    
  Remarks:
    
*/    
LIB_EXPORT leRadialMenuWidget_ItemProminenceChangedEvent leRadialMenuWidget_GetItemProminenceChangeddEventCallback(leRadialMenuWidget* mn);

// *****************************************************************************
/* Function:
    leResult leRadialMenuWidget_SetItemProminenceChangedEventCallback(leRadialMenuWidget* mn,
                                                            leRadialMenuWidget_ItemProminenceChangedEvent cb)

  Summary:
    Sets the deselected callback pointer

  Description:
    This callback is called when this radial menu is deselected

  Parameters:
    leRadialMenuWidget* mn - the widget
    leRadialMenuWidget_DeselectedEvent - a valid callback pointer or NULL
    
  Returns:
    leResult - the operation result
    
  Remarks:
    
*/    
LIB_EXPORT leResult leRadialMenuWidget_SetItemProminenceChangedEventCallback(leRadialMenuWidget* mn,
												leRadialMenuWidget_ItemProminenceChangedEvent cb);

// DOM-IGNORE-BEGIN
// internal use only
leWidgetUpdateState _leRadialMenuWidget_Update(leRadialMenuWidget* mn);
// DOM-IGNORE-END

#endif

#endif // LE_RADIALMENU_WIDGET_ENABLED
#endif /* LEGATO_RADIALMENU_H */