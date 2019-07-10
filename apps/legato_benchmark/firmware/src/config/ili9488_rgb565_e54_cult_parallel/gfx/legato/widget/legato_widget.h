/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget.h

  Summary:


  Description:
    This module implements top level widget control functions.
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

#ifndef LEGATO_WIDGET_H
#define LEGATO_WIDGET_H
//DOM-IGNORE-END


#include "gfx/legato/common/legato_common.h"
#include "gfx/legato/common/legato_rect.h"
#include "gfx/legato/core/legato_event.h"
#include "gfx/legato/core/legato_scheme.h"
#include "gfx/legato/datastructure/legato_array.h"

// DOM-IGNORE-BEGIN
#define DEFAULT_BORDER_MARGIN   4
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

/*
Enumeration:
        leWidgetType

    Summary:
        Specifies the different widget types used in the library

    Description:
        This enumeration specifies the different widget types
        used in the library.

    Remarks:
        None.
 */
typedef enum leWidgetType
{
    LE_WIDGET_WIDGET,
#if LE_ARC_WIDGET_ENABLED == 1
    LE_WIDGET_ARC,
#endif
#if LE_BARGRAPH_WIDGET_ENABLED == 1
    LE_WIDGET_BAR_GRAPH,
#endif
#if LE_BUTTON_WIDGET_ENABLED == 1
    LE_WIDGET_BUTTON,
#endif
#if LE_BUTTON_WIDGET_ENABLED == 1
    LE_WIDGET_CHECKBOX,
#endif
#if LE_CIRCLE_WIDGET_ENABLED == 1
    LE_WIDGET_CIRCLE,
#endif
#if LE_CIRCULARGAUGE_WIDGET_ENABLED == 1
    LE_WIDGET_CIRCULAR_GAUGE,
#endif
#if LE_CIRCULARSLIDER_WIDGET_ENABLED == 1
    LE_WIDGET_CIRCULAR_SLIDER,
#endif
#if LE_DRAWSURFACE_WIDGET_ENABLED == 1
    LE_WIDGET_DRAWSURFACE,
#endif
#if LE_IMAGE_WIDGET_ENABLED == 1
    LE_WIDGET_IMAGE,
#endif
#if LE_IMAGEPLUS_WIDGET_ENABLED == 1
    LE_WIDGET_IMAGEPLUS,
#endif
#if LE_IMAGESEQUENCE_WIDGET_ENABLED == 1
    LE_WIDGET_IMAGESEQUENCE,
#endif
#if LE_GRADIENT_WIDGET_ENABLED == 1
    LE_WIDGET_GRADIENT,
#endif
#if LE_GROUPBOX_WIDGET_ENABLED == 1
    LE_WIDGET_GROUPBOX,
#endif
#if LE_KEYPAD_WIDGET_ENABLED  == 1 && LE_BUTTON_WIDGET_ENABLED == 1
    LE_WIDGET_KEYPAD,
#endif
#if LE_LABEL_WIDGET_ENABLED == 1
    LE_WIDGET_LABEL,
#endif
#if LE_LINE_WIDGET_ENABLED == 1
    LE_WIDGET_LINE,
#endif
#if LE_LINEGRAPH_WIDGET_ENABLED == 1
    LE_WIDGET_LINE_GRAPH,
#endif
#if LE_LIST_WIDGET_ENABLED && LE_SCROLLBAR_WIDGET_ENABLED == 1
    LE_WIDGET_LIST,
#endif
#if LE_LISTWHEEL_WIDGET_ENABLED == 1
    LE_WIDGET_LISTWHEEL,
#endif
#if LE_PIECHART_WIDGET_ENABLED == 1
    LE_WIDGET_PIE_CHART,
#endif
#if LE_PROGRESSBAR_WIDGET_ENABLED == 1
    LE_WIDGET_PROGRESSBAR,
#endif
#if LE_RADIALMENU_WIDGET_ENABLED == 1
    LE_WIDGET_RADIAL_MENU,
#endif
#if LE_RADIOBUTTON_WIDGET_ENABLED == 1
    LE_WIDGET_RADIOBUTTON,
#endif
#if LE_RECTANGLE_WIDGET_ENABLED == 1
    LE_WIDGET_RECTANGLE,
#endif
#if LE_SCROLLBAR_WIDGET_ENABLED == 1
    LE_WIDGET_SCROLLBAR,
#endif
#if LE_SLIDER_WIDGET_ENABLED == 1
    LE_WIDGET_SLIDER,
#endif
#if LE_TEXTFIELD_WIDGET_ENABLED == 1
    LE_WIDGET_TEXTFIELD,
#endif
#if LE_TOUCHTEST_WIDGET_ENABLED == 1
    LE_WIDGET_TOUCHTEST,
#endif
#if LE_WINDOW_WIDGET_ENABLED == 1
    LE_WIDGET_WINDOW,
#endif
    // begin custom types, not essential but good for identifying base pointers

    // end custom types
    //LE_WIDGET_LAST = LE_WIDGET_WINDOW, // change this if adding custom
    //LE_WIDGET_TYPE_COUNT = LE_WIDGET_LAST + 1
} leWidgetType;

/*
Enumeration:
        leBackgroundType

    Summary:
        Specifies the different background types used for the widgets in the library

    Description:
        Specifies the different background types used for the widgets in the library

        None - No background fill.  Widget must defer to its parent to erase dirty
               pixels.  This may cause additional overhead as clean pixels may be
               repainted as well.

        Fill - a scheme color is used to fill the widget rectangle.

        Cache - a local framebuffer cache is maintained by the widget and used to
                clean up dirty pixels.  Will not cause a parent repaint event but
                will use additional memory to contain the cache.

    Remarks:
        None.
 */
typedef enum leBackgroundType
{
    LE_WIDGET_BACKGROUND_NONE,
    LE_WIDGET_BACKGROUND_FILL,
    LE_WIDGET_BACKGROUND_LAST = LE_WIDGET_BACKGROUND_FILL
} leBackgroundType;

/*
Enumeration:
        leBorderType

    Summary:
        Specifies the different border types used for the widgets in the library

    Description:
        Specifies the different border types used for the widgets in the library

    Remarks:
        None.
 */
typedef enum leBorderType
{
    LE_WIDGET_BORDER_NONE,
    LE_WIDGET_BORDER_LINE,
    LE_WIDGET_BORDER_BEVEL,
    LE_WIDGET_BORDER_LAST = LE_WIDGET_BORDER_BEVEL
} leBorderType;

/*
Enumeration:
        leWidgetDirtyState

    Summary:
        Specifies the different dirty states the widget can be assigned

    Description:
        Specifies the different dirty states the widget can be assigned
        This decides whether the particular widget would be re-drawn or not.
        Dirty widget are re-drawn and clean are not painted over.

    Remarks:
        None.
 */
typedef enum leWidgetDirtyState
{
    LE_WIDGET_DIRTY_STATE_CLEAN,
    LE_WIDGET_DIRTY_STATE_CHILD,
    LE_WIDGET_DIRTY_STATE_DIRTY,
} leWidgetDirtyState;

/*
Enumeration:
        leWidgetDrawState

    Summary:
        Specifies the different draw states the widget can be assigned

    Description:
        Specifies the different draw states the widget can be assigned

    Remarks:
        None.
 */
typedef enum leWidgetDrawState
{
    LE_WIDGET_DRAW_STATE_READY,
    LE_WIDGET_DRAW_STATE_DONE,

    // widget-specific draw states start here
} leWidgetDrawState;

typedef struct leWidget_MoveEvent
{
    leEvent evt;
    
    int32_t oldX;
    int32_t oldY;
    int32_t newX;
    int32_t newY;
} leWidget_MoveEvent;

typedef struct leWidget_ResizeEvent
{
    leEvent evt;
    
    uint32_t oldWidth;
    uint32_t oldHeight;
    uint32_t newWidth;
    uint32_t newHeight;
} leWidget_ResizeEvent;

// *****************************************************************************
/* Structure:
    leWidgetEvent

  Summary:
    Basic widget event definition
*/
typedef struct leWidgetEvent
{
    leEventID id;
    leBool accepted;
    leWidget* owner;
} leWidgetEvent;


// *****************************************************************************
/* Structure:
    leInput_TouchDownEvent_t

  Summary:
    Register and handle the touch press detect event

  Description:
    Register and handle the touch press detect event

  Remarks:
    None.
*/
typedef struct leWidgetEvent_TouchDown
{
    leWidgetEvent event;

    int32_t touchID;
    int32_t x;
    int32_t y;
} leWidgetEvent_TouchDown;

// *****************************************************************************
/* Structure:
    leInput_TouchUpEvent

  Summary:
    Register and handle the touch release detect event

  Description:
    Register and handle the touch release detect event

  Remarks:
    None.
*/
typedef struct leWidgetEvent_TouchUp
{
    leWidgetEvent event;

    int32_t touchID;
    int32_t x;
    int32_t y;
} leWidgetEvent_TouchUp;

// *****************************************************************************
/* Structure:
    leInput_TouchMoveEvent

  Summary:
    Register and handle the touch coordinates changed event

  Description:
    Register and handle the touch coordinates changed event

  Remarks:
    None.
*/
typedef struct leWidgetEvent_TouchMove
{
    leWidgetEvent event;

    int32_t touchID;
    int32_t prevX;
    int32_t prevY;
    int32_t x;
    int32_t y;
} leWidgetEvent_TouchMove;

void leWidgetEvent_Accept(leWidgetEvent* evt, leWidget* owner);

// *****************************************************************************
/* Struct Definition:
    leWidgetEventFilter

  Summary:
    Struct that defines an event filter.  Event filters allow a
    receiver to discard undesirable events
*/
typedef struct
{
    leBool (*filterEvent)(leWidget* target, leWidgetEvent* evt, void* data);
    void* data;
} leWidgetEventFilter;

// DOM-IGNORE-BEGIN
typedef struct leWidget leWidget;

#define LE_WIDGET_VTABLE(THIS_TYPE) \
    leWidgetType       (*getType)(const THIS_TYPE* _this); \
    int32_t            (*getX)(const THIS_TYPE* _this); \
    leResult           (*setX)(THIS_TYPE* _this, int32_t x); \
    int32_t            (*getY)(const THIS_TYPE* _this); \
    leResult           (*setY)(THIS_TYPE* _this, int32_t y); \
    leResult           (*setPosition)(THIS_TYPE* _this, int32_t x, int32_t y); \
    leResult           (*translate)(THIS_TYPE* _this, int32_t x, int32_t y); \
    uint32_t           (*getWidth)(const THIS_TYPE* _this); \
    leResult           (*setWidth)(THIS_TYPE* _this, uint32_t w); \
    uint32_t           (*getHeight)(const THIS_TYPE* _this); \
    leResult           (*setHeight)(THIS_TYPE* _this, uint32_t h); \
    leResult           (*setSize)(THIS_TYPE* _this, uint32_t w, uint32_t h); \
    leResult           (*resize)(THIS_TYPE* _this, int32_t w, int32_t h); \
    leBool             (*getAlphaEnabled)(const THIS_TYPE* _this); \
    leBool             (*getCumulativeAlphaEnabled)(const THIS_TYPE* _this); \
    leResult           (*setAlphaEnabled)(THIS_TYPE* _this, leBool enbl); \
    uint32_t           (*getAlphaAmount)(const THIS_TYPE* _this); \
    uint32_t           (*getCumulativeAlphaAmount)(const THIS_TYPE* _this); \
    leResult           (*setAlphaAmount)(THIS_TYPE* _this, uint32_t a); \
    leBool             (*isOpaque)(const THIS_TYPE* _this); \
    leBool             (*getEnabled)(const THIS_TYPE* _this); \
    leResult           (*setEnabled)(THIS_TYPE* _this, leBool enbl); \
    leBool             (*getVisible)(const THIS_TYPE* _this); \
    leResult           (*setVisible)(THIS_TYPE* _this, leBool vis); \
    leRect             (*localRect)(const THIS_TYPE* _this); \
    leRect             (*rectToParent)(const THIS_TYPE* _this); \
    leRect             (*rectToScreen)(const THIS_TYPE* _this); \
    leResult           (*addChild)(THIS_TYPE* _this, leWidget* chld); \
    leResult           (*removeChild)(THIS_TYPE* _this, leWidget* chld); \
    void               (*removeAllChildren)(THIS_TYPE* _this); \
    leWidget*          (*getRootWidget)(const THIS_TYPE* _this); \
    leResult           (*setParent)(THIS_TYPE* _this, leWidget* pnt); \
    uint32_t           (*getChildCount)(const THIS_TYPE* _this); \
    leWidget*          (*getChildAtIndex)(const THIS_TYPE* _this, uint32_t idx); \
    uint32_t           (*getIndexOfChild)(const THIS_TYPE* _this, const leWidget* chld); \
    leBool             (*containsDescendent)(const THIS_TYPE* _this, const leWidget* wgt); \
    leScheme*          (*getScheme)(const THIS_TYPE* _this); \
    leResult           (*setScheme)(THIS_TYPE* _this, leScheme* schm); \
    leBorderType       (*getBorderType)(const THIS_TYPE* _this); \
    leResult           (*setBorderType)(THIS_TYPE* _this, leBorderType type); \
    leBackgroundType   (*getBackgroundType)(const THIS_TYPE* _this); \
    leResult           (*setBackgroundType)(THIS_TYPE* _this, leBackgroundType type); \
    /*uint32_t           (*getOptimizationFlags)(const THIS_TYPE* _this);*/ \
    /*leResult           (*setOptimizationFlags)(THIS_TYPE* _this, uint32_t flgs);*/ \
    leHAlignment       (*getHAlignment)(const THIS_TYPE* _this); \
    leResult           (*setHAlignment)(THIS_TYPE* _this, leHAlignment halgn); \
    leVAlignment       (*getVAlignment)(const THIS_TYPE* _this); \
    leResult           (*setVAlignment)(THIS_TYPE* _this, leVAlignment valgn); \
    leMargin           (*getMargins)(const THIS_TYPE* _this); \
    leResult           (*setMargins)(THIS_TYPE* _this, uint32_t l, uint32_t t, uint32_t r, uint32_t b); \
    uint32_t           (*getCornerRadius)(const THIS_TYPE* _this); \
    leResult           (*setCornerRadius)(THIS_TYPE* _this, uint32_t rad); \
    leBool             (*hasFocus)(const THIS_TYPE* _this); \
    leResult           (*setFocus)(THIS_TYPE* _this); \
    /*leResult           (*setExternalInputHandler)(THIS_TYPE* _this, leWidgetInputHandler hndlr);*/ \
    void               (*invalidate)(const THIS_TYPE* _this); \
    /*void             (*invalidateRect)(const THIS_TYPE* _this, const leRect* rect);*/ \
    void               (*invalidateContents)(const THIS_TYPE* _this); \
    leResult           (*installEventFilter)(THIS_TYPE* _this, leWidgetEventFilter fltr); \
    leResult           (*removeEventFilter)(THIS_TYPE* _this, leWidgetEventFilter fltr); \
    void               (*update)(THIS_TYPE* _this, uint32_t dt); \
    \
    void               (*moveEvent)(THIS_TYPE* _this, leWidget_MoveEvent* evt); \
    void               (*resizeEvent)(THIS_TYPE* _this, leWidget_ResizeEvent* evt); \
    void               (*focusGainedEvent)(THIS_TYPE* _this); \
    void               (*focusLostEvent)(THIS_TYPE* _this); \
    void               (*languageChangeEvent)(THIS_TYPE* _this); \
    void               (*touchDownEvent)(THIS_TYPE* _this, leWidgetEvent_TouchDown* evt); \
    void               (*touchUpEvent)(THIS_TYPE* _this, leWidgetEvent_TouchUp* evt); \
    void               (*touchMoveEvent)(THIS_TYPE* _this, leWidgetEvent_TouchMove* evt); \
    \
    void               (*_destructor)(THIS_TYPE* _this); \
    \
    void               (*_handleEvent)(THIS_TYPE* _this, leEvent* evt); \
    void               (*_validateChildren)(THIS_TYPE* _this); \
    void               (*_increaseDirtyState)(THIS_TYPE* _this, uint32_t state); \
    void               (*_setDirtyState)(THIS_TYPE* _this, uint32_t state); \
    void               (*_clearDirtyState)(THIS_TYPE* _this); \
    void               (*_invalidateBorderAreas)(const THIS_TYPE* _this); \
    void               (*_damageArea)(const THIS_TYPE* _this, leRect* rect); \
    void               (*_paint)(THIS_TYPE* _this); \
    
typedef struct leWidgetVTable
{
	LE_WIDGET_VTABLE(leWidget)
} leWidgetVTable;


typedef struct leWidget leWidget;
typedef struct leRectArray leRectArray;

typedef void (*leWidget_DrawFunction_FnPtr)(void*);

// DOM-IGNORE-END

/* Structure:
        leWidget

    Summary:
        Specifies Graphics widget structure to manage all properties and events associated with the widget

    Description:
        Specifies Graphics widget structure to manage all properties and events associated with the widget.
        It also contains information about the parent and children for the widget to manage the tree structure that the library supports.


    Remarks:
        None.

*/
typedef struct leWidget
{
    leWidgetVTable* fn;
    
    uint32_t id;  // the id of the widget
    leWidgetType type; // the type of the widget

    leBool visible; // the widget visible flag
    leBool enabled; // the widget enabled flag

    leRect rect; // the bounding rectangle of the widget
    uint32_t cornerRadius; //corner radius, draws round corners if > 0
    
    leHAlignment halign; // horizontal alignment of the widget
    leVAlignment valign; // vertical alignment of the widget

    leMargin margin; // the margin settings for the widget

    leBorderType borderType; // the widget border type
    leBackgroundType backgroundType; // the widget background type

    uint32_t optimizationFlags; // optimization flags

    uint32_t drawCount; // number of times this widget has been drawn
                        // for the active screen

    leBool alphaEnabled;    // indicates that the global alpha blending
                            // setting is enabled for this widget
    uint32_t alphaAmount;   // the global alpha amount to apply to this
                            // widget (cumulative with parent widgets)

    uint32_t dirtyState;    // the widget's dirty state
    uint32_t drawState;     // the widget's draw state

    leWidget_DrawFunction_FnPtr drawFunc; // the next draw function to call

    const leScheme* scheme; // the widget's color scheme

    //leWidgetInputHandler externalHandler;

    leWidgetEventFilter eventFilters[LE_WIDGET_MAX_EVENT_FILTERS];

    leBool root;      // indicates if this widget is a root widget
    leWidget* parent; // pointer to the widget's parent
    leArray children;  // pointers for the widget's children
} leWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

/*    Function:
        leWidget* leWidget_New()

    Summary:
        Create a new widget.


    Description:
        Create a new widget, allocate memory for the widget through the current
        active context.  Returns a widget object pointer.  Application is
        responsible for managing the widget pointer until the widget is added
        to a widget tree.

    Parameters:


    Returns:
        lawidget*

*/
LIB_EXPORT leWidget* leWidget_New();

LIB_EXPORT void leWidget_Constructor(leWidget* wgt);

/*    Function:
        void leWidget_Delete(leWidget* wgt)

    Summary:
        Delete the widget object specified

    Description:
        Delete a widget object specified, de-allocate memory for the widget
        through the current active context.  All child widgets are also
        destructed and freed.

    Parameters:
        lawidget*

    Returns:
        void

*/
LIB_EXPORT void leWidget_Delete(leWidget* wgt);

#if 0

/*    Function:
        int32_t leWidget_GetX(leWidget* wgt)

    Summary:
        Returns the widget rectangles upper left corner x-coordinate

    Description:
        Returns the widget rectangles upper left corner x-coordinate

    Parameters:
        lawidget* wgt - the widget

    Returns:
        uint32_t

*/
LIB_EXPORT int32_t leWidget_GetX(leWidget* wgt);

/*    Function:
        leResult leWidget_SetX(leWidget* wgt, int32_t x)

    Summary:
        Sets the widget's x coordinate position

    Description:
        Sets the widget's x coordinate position

    Parameters:
        lawidget* wgt - the widget
        int32_t x - the desired x value

    Returns:
        leResult - result of the operation

*/
LIB_EXPORT leResult leWidget_SetX(leWidget* wgt, int32_t x);

/*    Function:
        int32_t leWidget_GetY(leWidget* wgt)

    Summary:
        Returns the widget rectangles upper left corner y-coordinate

    Description:
        Returns the widget rectangles upper left corner y-coordinate

    Parameters:
        lawidget* wgt - the widget

    Returns:
        uint32_t - the y value

*/
LIB_EXPORT int32_t leWidget_GetY(leWidget* wgt);

/*    Function:
        leResult leWidget_SetY(leWidget* wgt, int32_t y)

    Summary:
        Sets the widget's y coordinate position

    Description:
        Sets the widget's y coordinate position

    Parameters:
        lawidget* wgt - the widget
        int32_t y - the desired y value

    Returns:
        leResult - result of the operation

*/
LIB_EXPORT leResult leWidget_SetY(leWidget* wgt, int32_t y);

/*    Function:
        int32_t leWidget_GetWidth(leWidget* wgt)

    Summary:
        Returns the widget rectangles width

    Description:
        Returns the widget rectangles width

    Parameters:
        lawidget* wgt - the widget

    Returns:
        uint32_t - the widget's y coordinate value

*/
LIB_EXPORT int32_t leWidget_GetWidth(leWidget* wgt);

/*    Function:
        leResult leWidget_SetWidth(leWidget* wgt, int32_t width)

    Summary:
        Sets the widget's width value

    Description:
        Sets the widget's width value

    Parameters:
        lawidget* wgt - the widget
        int32_t width - the desired width value, must be > 0

    Returns:
        leResult - result of the operation

*/
LIB_EXPORT leResult leWidget_SetWidth(leWidget* wgt, int32_t width);

/*    Function:
        int32_t leWidget_GetHeight(leWidget* wgt)

    Summary:
        Returns the widget rectangles height

    Description:
        Returns the widget rectangles height

    Parameters:
        lawidget* wgt - the widget

    Returns:
        uint32_t - the widget's width value

*/
LIB_EXPORT int32_t leWidget_GetHeight(leWidget* wgt);

/*    Function:
        leResult leWidget_SetHeight(leWidget* wgt, int32_t height)

    Summary:
        Sets the widget's height value

    Description:
        Sets the widget's height value

    Parameters:
        lawidget* wgt - the widget
        int32_t height - the desired height value, must be > 0

    Returns:
        leResult - result of the operation

*/
LIB_EXPORT leResult leWidget_SetHeight(leWidget* wgt, int32_t height);

// *****************************************************************************
/* Function:
    leBool leWidget_GetAlphaEnable(leWidget* wgt)

  Summary:
    Return the alpha enable property of the widget

  Description:
    Return the alpha enable property of the widget

  Parameters:
    lawidget* wgt - the widget

  Returns:
    leBool - the widget's alpha enable flag value

  Remarks:

*/
LIB_EXPORT leBool leWidget_GetAlphaEnable(leWidget* wgt);

// *****************************************************************************
/* Function:
    leBool leWidget_GetCumulativeAlphaEnable(leWidget* wgt)

  Summary:
    Determines if this or any ancestor widget has alpha enabled

  Description:


  Parameters:
    lawidget* wgt - the widget

  Returns:
    leBool - whether the widget has alpha enabled

  Remarks:

*/
LIB_EXPORT leBool leWidget_GetCumulativeAlphaEnable(leWidget* wgt);

// *****************************************************************************
/* Function:
    leResult leWidget_SetAlphaEnable(leWidget* wgt, leBool enable)

  Summary:
    Set the alpha enable property of the widget with the boolean
    value specified

  Description:
    Set the alpha enable property of the widget with the boolean
    value specified

  Parameters:
    lawidget* wgt - the widget
    leBool enable - the desired alpha enable flag value

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leWidget_SetAlphaEnable(leWidget* wgt, leBool enable);

// *****************************************************************************
/* Function:
    uint32_t leWidget_GetAlphaAmount(leWidget* wgt)

  Summary:
    Return the widget's global alpha amount

  Description:
    Return the widget's global alpha amount

  Parameters:
    lawidget* wgt - the widget


  Returns:
    uint32_t - the widget's global alpha amount

  Remarks:

*/
LIB_EXPORT uint32_t leWidget_GetAlphaAmount(leWidget* wgt);


// *****************************************************************************
/* Function:
    uint32_t leWidget_GetCumulativeAlphaAmount(leWidget* wgt)

  Summary:
    Calculates the cumulative alpha amount for a hierarchy of widgets

  Description:
    Alpha blending amounts are cumulative from parent to child.  If a parent
    is blended at 50% then logically a child should also implicitely be
    blended at 50%. If a child further explictely enables blending at 50% then
    the cumulative amount is 25%.

  Parameters:
    lawidget* wgt - the widget

  Returns:
    uint32_t - the cumulative blending amount

  Remarks:

*/
LIB_EXPORT uint32_t leWidget_GetCumulativeAlphaAmount(leWidget* wgt);

// *****************************************************************************
/* Function:
    leResult leWidget_SetAlphaAmount(leWidget* wgt, uint32_t alpha)

  Summary:
    Set the widget's global alpha amount to the specified alpha amount

  Description:
    Set the widget's global alpha amount to the specified alpha amount.  Widgets
    may enable alpha blending even for color modes that don't support an alpha
    channel.

  Parameters:
    leWidget* wgt - the widget
    uint32_t alpha - the desired global alpha amount

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leWidget_SetAlphaAmount(leWidget* wgt, uint32_t alpha);

// *****************************************************************************
/* Function:
    leBool leWidget_isOpaque(leWidget* wgt)

  Summary:
    Returns true if the widget is considered opaque.

  Description:
    Opacity is determined by a number of factors including: cumulative alpha
    amount, background type, and the opaque optimization flag.

  Parameters:
    leWidget* wgt - the widget

  Returns:
    leBool - true if the widget is fully opaque

  Remarks:

*/
LIB_EXPORT leBool leWidget_isOpaque(leWidget* wgt);

// *****************************************************************************
/* Function:
    leRect leWidget_RectToParentSpace(leWidget* wgt)

  Summary:
    Returns the rectangle containing the parent of the widget specified

  Description:
    Returns the rectangle containing the parent of the widget specified
    If the widget and the parent are not null, the rectangle defining
    the parent widget with its upper left corner x and y coordinates is returned

  Parameters:
    leWidget* wgt - the widget

  Returns:
    leRect - the widget rectangle in parent space

  Remarks:

*/
LIB_EXPORT leRect leWidget_RectToParentSpace(leWidget* wgt);

// *****************************************************************************
/* Function:
    leRect leWidget_RectToScreenSpace(leWidget* wgt)

  Summary:
    Transforms a widget rectangle from local space to screen space coordinates.

  Description:

  Parameters:
    leWidget* wgt - the widget

  Returns:
    leRect - the transformed rectangle

  Remarks:

*/
LIB_EXPORT leRect leWidget_RectToScreenSpace(leWidget* wgt);

// *****************************************************************************
/* Function:
    leResult leWidget_AddChild(leWidget* parent, leWidget* child)

  Summary:
    Adds the child to the parent widget specified in the argument

  Description:
    The function checks to see if the child and parent are valid, removes the child from its current parents children list, and assigns the child to the parent widget specified.
    The child is attached at the end of the list of the parent widgets children list.

  Parameters:
    leWidget* parent - the parent widget
    leWidget* child - the child to add

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_AddChild(leWidget* parent, leWidget* child);

// *****************************************************************************
/* Function:
    leResult leWidget_RemoveChild(leWidget* parent, leWidget* child)

  Summary:
    Removes the child from the parent widget specified in the argument

  Description:
    The function checks to see if the child and parent are valid, removes the child from its current parents children list

  Parameters:
    leWidget* parent - the parent widget
    leWidget* child - the child to remove

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_RemoveChild(leWidget* parent, leWidget* child);

// *****************************************************************************
/* Function:
    leResult leWidget_SetParent(leWidget* wgt, leWidget* parent)

  Summary:
    Sets the parent of the child widget to that specified in the argument list

  Description:
    The function checks to see if the child and parent are valid, removes the child from its current parents children list, and assigns the child to the parent widget specified.
    The child is attached at the end of the list of the parent widgets children list.

  Parameters:
    leWidget* wgt - the widget
    leWidget* parent - the desired parent widget

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_SetParent(leWidget* wgt, leWidget* parent);

// *****************************************************************************
/* Function:
    uint32_t leWidget_GetChildCount(leWidget* parent)

  Summary:
    Returns the size of the children list of the specified parent widget

  Description:
    Returns the size of the children list of the specified parent widget

  Parameters:
    leWidget* wgt - the widget

  Returns:
    uint32_t - the number of children of this widget

  Remarks:

*/
LIB_EXPORT uint32_t leWidget_GetChildCount(leWidget* parent);

// *****************************************************************************
/* Function:
    leWidget* leWidget_GetChildAtIndex(leWidget* parent, uint32_t idx)

  Summary:
    Fetches the child at the specified index from the children list of the
    specified parent widget

  Description:
    Fetches the child at the specified index from the children list of the
    specified parent widget

  Parameters:
    leWidget* wgt - the widget
    uint32_t idx - the desired child index

  Returns:
    leWidget* - a valid child pointer or NULL

  Remarks:

*/
LIB_EXPORT leWidget* leWidget_GetChildAtIndex(leWidget* parent, uint32_t idx);

// *****************************************************************************
/* Function:
    int32_t leWidget_GetIndexOfChild(leWidget* parent, leWidget* child)

  Summary:
    Fetches the index of the child from the children list of the specified
    parent widget

  Description:
    Traverses the children list of the specified parent widget and finds the
    index of the child widget specified.

  Parameters:
    leWidget* parent - the parent widget
    leWidget* child - the child widget

  Returns:
    int32_t - the index of the given child pointer or -1 if not found

  Remarks:

*/
LIB_EXPORT int32_t leWidget_GetIndexOfChild(leWidget* parent, leWidget* child);

/*    Function:
        void leWidget_DeleteAllDescendants(leWidget* wgt)

    Summary:
        Deletes all of the descendants of the given widget.

    Description:
        All descendants of this widget are removed and deleted.

    Parameters:
        lawidget*

    Returns:
        void

*/
LIB_EXPORT void leWidget_DeleteAllDescendants(leWidget* wgt);

// *****************************************************************************
/* Function:
    leBool leWidget_GetEnabled(leWidget* wgt)

  Summary:
    Returns the boolean value of the widget enabled property

  Description:
    Returns the boolean value of the widget enabled property.  The widget enable
    flag often governs things like appearing 'greyed out' and prohibits user
    interactiong if it is false.  Widgets must individually support this flag.

  Parameters:
    leWidget* wgt - the widget

  Returns:
    leBool - the value of the enabled flag

  Remarks:

*/
LIB_EXPORT leBool leWidget_GetEnabled(leWidget* wgt);

// *****************************************************************************
/* Function:
    leResult leWidget_SetEnabled(leWidget* wgt, leBool enable)

  Summary:
    Sets the boolean value of the widget enabled property

  Description:
    Sets the boolean value of the widget enabled property

  Parameters:
    leWidget* wgt - the widget
    leBool - the desired enabled flag value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_SetEnabled(leWidget* wgt, leBool enable);

// *****************************************************************************
/* Function:
    leBool leWidget_GetVisible(leWidget* wgt)

  Summary:
    Returns the boolean value of the widget visible property

  Description:
    Returns the boolean value of the widget visible property.  Widgets that are
    invisible will be skipped during the rendering phase.  All descendants also
    logically become invisible when an ancestor does.

  Parameters:
    leWidget* wgt - the widget

  Returns:
    leBool - the flag value

  Remarks:

*/
LIB_EXPORT leBool leWidget_GetVisible(leWidget* wgt);

// *****************************************************************************
/* Function:
    leResult leWidget_SetVisible(leWidget* wgt, leBool visible)

  Summary:
    Sets the boolean value of the widget visible property

  Description:
    Sets the boolean value of the widget visible property

  Parameters:
    leWidget* wgt - the widget
    leBool - the desired setting

  Returns:
    leResult - the operation result

  Remarks:
    
*/
LIB_EXPORT leResult leWidget_SetVisible(leWidget* wgt, leBool visible);

// *****************************************************************************
/* Function:
    leScheme* leWidget_GetScheme(leWidget* wgt)

  Summary:
    Returns the scheme associated with the specified widget

  Description:
    Returns the scheme associated with the specified widget

  Parameters:
    leWidget* wgt - the widget

  Returns:
    leScheme* - a pointer to the active scheme for a widget

  Remarks:

*/
LIB_EXPORT leScheme* leWidget_GetScheme(leWidget* wgt);

// *****************************************************************************
/* Function:
    void leWidget_SetScheme(leWidget* wgt, leScheme* scheme)

  Summary:
    Sets the scheme variable for the specified widget

  Description:
    Sets the scheme variable for the specified widget.  The scheme defines the
    appearance of the widget.  Setting this to NULL may result in undefined
    behavior if the widget doesn't properly support a NULL scheme.

  Parameters:
    leWidget* wgt - the widget
    leScheme* scheme - a pointer to a scheme or NULL

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_SetScheme(leWidget* wgt,
                                       leScheme* scheme);

// *****************************************************************************
/* Function:
    void leWidget_SetPosition(leWidget* wgt, int32_t x, int32_t y)

  Summary:
    Changes the widget position to the new defined x and y coordinates.

  Description:
    Changes the widget position to the new defined x and y coordinates.  Moving
    widgets can be expensive as it needs to repaint multiple areas of its
    parent widget.

  Parameters:
    leWidget* wgt - the widget
    int32_t x - the new x coordinate
    int32_t y - the new y coordinate

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_SetPosition(leWidget* wgt,
                                         int32_t x,
                                         int32_t y);

// *****************************************************************************
/* Function:
    void leWidget_Translate(leWidget* wgt, int32_t x, int32_t y)

  Summary:
    Changes the widget position by moving the widget by the defined
    x and y increments.

  Description:
    Changes the widget position by moving the widget by the defined
    x and y increments.Moving widgets can be expensive as it needs to
    repaint multiple areas of its parent widget.


  Parameters:
    leWidget* wgt - the widget
    int32_t x - the amount to move in x
    int32_t y - the amount to move in y

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_Translate(leWidget* wgt,
                                       int32_t x,
                                       int32_t y);

// *****************************************************************************
/* Function:
    void leWidget_SetSize(leWidget* wgt, uint32_t width, uint32_t height)

  Summary:
    Changes the widget size to the new defined width and height dimensions.

  Description:
    Changes the widget size to the new width and height dimensions.

  Parameters:
    leWidget* wgt - the widget
    int32_t width - the new width size
    int32_t height - the new height size

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_SetSize(leWidget* wgt,
                                     uint32_t width,
                                     uint32_t height);

// *****************************************************************************
/* Function:
    void leWidget_Resize(leWidget* wgt, int32_t width, int32_t height)

  Summary:
    Changes the widget size by the new defined width and height increments.

  Description:
    Changes the widget size by the new defined width and height increments.

  Parameters:
    leWidget* wgt - the widget
    int32_t width - the amount to change the width by
    int32_t height - the amount ot change the height by

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_Resize(leWidget* wgt, int32_t width, int32_t height);

// *****************************************************************************
/* Function:
    leBorderType leWidget_GetBorderType(leWidget* wgt)

  Summary:
    Return the border type associated with the widget object

  Description:
    Return the border type associated with the widget object

  Parameters:
    leWidget* wgt - the widget

  Returns:
    leBorderType - the current widget border type

  Remarks:

*/
LIB_EXPORT leBorderType leWidget_GetBorderType(leWidget* wgt);

// *****************************************************************************
/* Function:
    leResult leWidget_SetBorderType(leWidget* wgt, leBorderType type)

  Summary:
    Set the border type associated with the widget object

  Description:
    Set the border type associated with the widget object

  Parameters:
    leWidget* wgt - the widget
    leBorderType type - the desired border type

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_SetBorderType(leWidget* wgt, leBorderType type);

// *****************************************************************************
/* Function:
    leBackgroundType leWidget_GetBackgroundType(leWidget* wgt)

  Summary:
    Return the property value 'background type' associated with the widget object

  Description:
    Return the property value 'background type' associated with the widget object
    The background type property decides if the widget background is drawn and
    re-drawn. If background is none, the entire parent widget will be re-drawn
    in the event that the widget gets dirty and needs re-drawing.

  Parameters:
    leWidget* wgt - the widget

  Returns:
    leBackgroundType - the current background type

  Remarks:

*/
LIB_EXPORT leBackgroundType leWidget_GetBackgroundType(leWidget* wgt);

// *****************************************************************************
/* Function:
    leResult leWidget_SetBackgroundType(leWidget* wgt, leBackgroundType type)

  Summary:
    Set the property value 'background type' associated with the widget object

  Description:
    Set the property value 'draw background' associated with the widget object

  Parameters:
    leWidget* wgt - the widget
    leBackgroundType type - the desired background type

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_SetBackgroundType(leWidget* wgt,
                                               leBackgroundType type);

// *****************************************************************************
/* Function:
    leBool leWidget_GetOptimizationFlags(leWidget* wgt)

  Summary:
    Returns the optimization flags for the widget

  Description:


  Parameters:
    leWidget* wgt - the widget

  Returns:
    leBool - the flag value

  Remarks:

*/
LIB_EXPORT leBool leWidget_GetOptimizationFlags(leWidget* wgt);

// *****************************************************************************
/* Function:
    leResult leWidget_SetOptimizationFlags(leWidget* wgt, uint32_t flags)

  Summary:
    Sets the optimizations for a widget

  Description:
    See the optimizations enum for a descriptions of the individual flags

  Parameters:
    leWidget* wgt - the widget

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_SetOptimizationFlags(leWidget* wgt, uint32_t flags);

// *****************************************************************************
/* Function:
    leResult leWidget_GetMargin (leWidget* wgt, leMargin* mg)

  Summary:
    Returns the margin value associated with the widget in the leMargin pointer

  Description:
    Returns the margin value associated with the widget in the leMargin pointer

  Parameters:
    leWidget* wgt - the widget
    leMargin* mg - a pointer to an leMargin object to store the margin values

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_GetMargin (leWidget* wgt, leMargin* mg);

// *****************************************************************************
/* Function:
    leResult leWidget_SetMargins(leWidget* wgt,
                                 uint32_t left,
                                 uint32_t top,
                                 uint32_t right,
                                 uint32_t bottom)

  Summary:
    Set the margin value for left, right, top and bottom margins associated
    with the widget

  Description:
    Set the margin value for left, right, top and bottom margins associated
    with the widget.  Margins are a generic property and it is up to the
    individual widget to implement them (or not).

  Parameters:
    leWidget* wgt - the widget
    uint32_t left - the left margin value
    uint32_t top - the top margin value
    uint32_t right - the right margin value
    uint32_t bottom - the bottom margin value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_SetMargins(leWidget* wgt,
                                        uint32_t left,
                                        uint32_t top,
                                        uint32_t right,
                                        uint32_t bottom);

// *****************************************************************************
/* Function:
    uint32_t leWidget_GetCornerRadius(leWidget* wgt)

  Summary:
    Returns the corner radius of the widget

  Description:
    Returns the corner radius of the widget

  Parameters:
    leWidget* wgt - the widget

  Returns:
    uint32_t - the corner radius

  Remarks:

*/
LIB_EXPORT uint32_t leWidget_GetCornerRadius(leWidget* wgt);

// *****************************************************************************
/* Function:
    leResult leWidget_SetCornerRadius(leWidget* wgt,
                                      uint32_t radius)

  Summary:
    Sets the widget corner radius.

  Description:
    Sets the widget corner radius. A widget with non-zero corner radius will have
    round edges. This only supports widgets with non-beveled borders.

  Parameters:
    leWidget* wgt - the widget
    uint32_t radius - the radius

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_SetCornerRadius(leWidget* wgt,
                                            uint32_t radius);

// *****************************************************************************
/* Function:
    leBool leWidget_HasFocus(leWidget* wgt)

  Summary:
    Checks if the widget specified has focus in the current context

  Description:
    Checks if the widget specified has focus in the current context

  Parameters:
    leWidget* wgt - the widget

  Returns:
    leBool - true of the widget currently has context focus

  Remarks:

*/
LIB_EXPORT leBool leWidget_HasFocus(leWidget* wgt);

// *****************************************************************************
/* Function:
    leResult leWidget_SetFocus(leWidget* wgt)

  Summary:
    Set the widget into focus for the current context.

  Description:
    Set the widget into focus for the current context.
    The input events etc are received by the widget once it is in focus

  Parameters:
    leWidget* wgt - the widget

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult leWidget_SetFocus(leWidget* wgt);

// *****************************************************************************
/* Function:
    void leWidget_Invalidate(leWidget* wgt)

  Summary:
    Invalidates the specified widget.

  Description:
    This function invalidates the specified widget.  Invalid widgets are redrawn
    during the next paint loop call.  This function may also invalidate the
    widget's parent, siblings, ancestors, or cousins.

  Parameters:
    leWidget* wgt - the widget

  Returns:
    void

  Remarks:

*/
LIB_EXPORT void leWidget_Invalidate(leWidget* wgt);

// DOM-IGNORE-BEGIN
// internal use only
void _leWidget_Invalidate(leWidget* wgt, const leRect* rect);

void _leWidget_ValidateChildren(leWidget* wgt);

void _leWidget_IncreaseDirtyState(leWidget* wgt, uint32_t state);
void _leWidget_SetDirtyState(leWidget* wgt, uint32_t state);
void _leWidget_ClearDirtyState(leWidget* wgt);
// DOM-IGNORE-END

#endif

#endif /* LEGATO_WIDGET_H */
