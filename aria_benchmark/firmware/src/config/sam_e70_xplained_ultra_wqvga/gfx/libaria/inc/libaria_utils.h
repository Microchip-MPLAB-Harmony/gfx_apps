/*******************************************************************************
 Module for Microchip Graphics Library - Aria User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    libaria_utils.h

  Summary:
    General internal utilities for the library
    
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2017 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/

#ifndef LIBARIA_UTILS_H
#define LIBARIA_UTILS_H
//DOM-IGNORE-END

#include "gfx/libaria/inc/libaria_common.h"

typedef struct laLayer_t laLayer;
typedef struct laWidget_t laWidget;
typedef struct GFX_Point_t GFX_Point;
typedef struct GFX_Rect_t GFX_Rect;
typedef struct laList_t laList;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

/*  Function:
        laWidget* laUtils_Pick(int32_t x, int32_t y)
 
    Summary:
        Finds the top-most visible widget in the tree at the given coordinates.
        
    Parameters:
        int32_t x - the x coordinate of the pick point
        int32_t y - the y coordinate of the pick point
        
    Returns:
        laWidget* - the result widget    
*/
LIB_EXPORT laWidget* laUtils_Pick(int32_t x, int32_t y);

/*  Function:
        laWidget* laUtils_PickFromLayer(const laLayer* layer, int32_t x, int32_t y)
 
    Summary:
        Finds the top-most visible widget in a layer at the given coordinates.
        
    Parameters:
        int32_t x - the x coordinate of the pick point
        int32_t y - the y coordinate of the pick point
        
    Returns:
        laWidget* - the result widget    
*/
LIB_EXPORT laWidget* laUtils_PickFromLayer(const laLayer* layer, int32_t x, int32_t y);

/*  Function:
        void laUtils_PickRect(laLayer* layer, GFX_Rect rect, laList* list)
 
    Summary:
        Finds all of the visible widgets in the given rectangular area.
        
    Parameters:
        laLayer* layer - the layer to analyze
        GFX_Rect - the rectangle pick area
        laList* list - the result list
        
    Returns:
        void
*/
void laUtils_PickRect(laLayer* layer, GFX_Rect rect, laList* list);

/*  Function:
        laLayer* laUtils_GetLayer(laWidget* widget)
 
    Summary:
        Finds the root parent of a widget, which should be a layer
        
    Parameters:
        laWidget* widget - the subject widget
        
    Returns:
        laLayer* - the widget's owning layer
*/
laLayer* laUtils_GetLayer(laWidget* widget);

/*  Function:
        void laUtils_PointToLayerSpace(laWidget* widget, GFX_Point* pnt)
 
    Summary:
        Converts a point from widget space into layer space
        
    Parameters:
        laWidget* widget - the subject widget
        GFX_Point* pnt - the point to convert
        
    Returns:
        void
*/
void laUtils_PointToLayerSpace(laWidget* widget, GFX_Point* pnt);

/*  Function:
        void laUtils_PointLayerToLocalSpace(laWidget* widget, GFX_Point* pnt)
 
    Summary:
        Converts a point from layer space into the local space of a widget
        
    Parameters:
        laWidget* widget - the subject widget
        GFX_Point* pnt - the point to convert
        
    Returns:
        void
*/
void laUtils_PointScreenToLocalSpace(laWidget* widget, GFX_Point* pnt);

/*  Function:
        void laUtils_ClipRectToParent(laWidget* widget, GFX_Rect* rect)
 
    Summary:
        Clips a rectangle to the parent of a widget
        
    Parameters:
        laWidget* widget - the subject widget
        GFX_Rect* rect - the rectangle to clip
        
    Returns:
        void
*/
void laUtils_ClipRectToParent(laWidget* widget, GFX_Rect* rect);

/*  Function:
        GFX_Rect laUtils_WidgetLocalRect(laWidget* widget)
 
    Summary:
        Returns the bounding rectangle of a widget in local space
        
    Parameters:
        laWidget* widget - the subject widget
                
    Returns:
        GFX_Rect - the bounding rectangle
*/
GFX_Rect laUtils_WidgetLocalRect(laWidget* widget);

/*  Function:
        GFX_Rect laUtils_WidgetLayerRect(laWidget* widget)
 
    Summary:
        Returns the bounding rectangle of a widget in layer space
        
    Parameters:
        laWidget* widget - the subject widget
                
    Returns:
        GFX_Rect - the bounding rectangle
*/
GFX_Rect laUtils_WidgetLayerRect(laWidget* widget);

/*  Function:
        void laUtils_RectToParentSpace(laWidget* widget, GFX_Rect* rect)
 
    Summary:
        Converts a rectangle from widget local space to widget parent
        space.  Widget must be a child of a layer for this to function.
        
    Parameters:
        laWidget* widget - the subject widget
        GFX_Rect* rect - the rectangle to convert
        
    Returns:
        void
*/
void laUtils_RectToParentSpace(laWidget* widget, GFX_Rect* rect);

/*  Function:
        void laUtils_RectFromParentSpace(laWidget* widget, GFX_Rect* rect)
 
    Summary:
        Converts a rectangle from widget parent space to widget local
        space
        
    Parameters:
        laWidget* widget - the subject widget
        GFX_Rect* rect - the rectangle to convert
        
    Returns:
        void
*/
void laUtils_RectFromParentSpace(laWidget* widget, GFX_Rect* rect);

/*  Function:
        void laUtils_RectFromLayerSpace(laWidget* widget, GFX_Rect* rect)
 
    Summary:
        Converts a rectangle from layer space to widget local space
        
    Parameters:
        laWidget* widget - the subject widget
        GFX_Rect* rect - the rectangle to convert
        
    Returns:
        void
*/
void laUtils_RectFromLayerSpace(laWidget* widget, GFX_Rect* rect);

/*  Function:
        void laUtils_RectToLayerSpace(laWidget* widget, GFX_Rect* rect)
 
    Summary:
        Converts a rectangle from widget local space to layer space
        
    Parameters:
        laWidget* widget - the subject widget
        GFX_Rect* rect - the rectangle to convert
        
    Returns:
        void
*/
void laUtils_RectToLayerSpace(laWidget* widget, GFX_Rect* rect);

/*  Function:
        void laUtils_RectToScreenSpace(laWidget* widget, GFX_Rect* rect)
 
    Summary:
        Converts a rectangle from widget local space to screen space
        
    Parameters:
        laWidget* widget - the subject widget
        GFX_Rect* rect - the rectangle to convert
        
    Returns:
        void
*/
void laUtils_RectToScreenSpace(laWidget* widget, GFX_Rect* rect);

/*  Function:
        laBool laUtils_ChildIntersectsParent(laWidget* parent, laWidget* child)
 
    Summary:
        Performs an intersection test between a parent widget and a child
        widget
        
    Parameters:
        laWidget* parent - the parent widget
        laWidget* child - the child widget
        
    Returns:
        laBool - result of the intersection test
*/
laBool laUtils_ChildIntersectsParent(laWidget* parent, laWidget* child);

/*  Function:
        laBool laUtils_GetNextHighestWidget(laWidget* wgt)
 
    Summary:
        Gets the next highest Z order widget in the tree from 'wgt'
        
    Parameters:
        laWidget* wgt - the widget to analyze
        
    Returns:
        laWidget* - the next highest widget or NULL if 'wgt' is
        already the highest
*/
laWidget* laUtils_GetNextHighestWidget(laWidget* wgt);

/*  Function:
        void laUtils_ArrangeRectangle(GFX_Rect* sub,
                                      GFX_Rect obj,
                                      GFX_Rect bounds,
                                      laHAlignment hAlignment,
                                      laVAlignment vAlignment,
                                      laRelativePosition position,
                                      uint8_t leftMargin,
                                      uint8_t topMargin,
                                      uint8_t rightMargin,
                                      uint8_t bottomMargin,
                                      uint16_t rectMargin)
 
    Summary:
        Calculates the position of a rectangle within the given bounds and
        in accordance with the given parameters.  A use case for this is
        when an image and a text rectangle must be arranged in a button box.  
        This version of the algorithm will calculate the location of the
        image rectangle.
        
    Parameters:
        GFX_Rect* sub - the bounds of the subject rectangle (image)
        GFX_Rect obj - the bounds of the object rectangle (text)
        GFX_Rect bounds - the bounds of the bounding rectangle (widget)
        laHAlignment hAlignment - the horizontal alignment of the rects
        laVAlignment vAlignment - the vertical alignment of the rects
        laRelativePosition position - the relative position of the rectangles
        uint8_t leftMargin - the left margin of the bounding rectangle
        uint8_t topMargin - the top margin of the bounding rectangle
        uint8_t rightMargin - the right margin of the bounding rectangle
        uint8_t bottomMargin - the bottom margin of the bounding rectangle
        uint16_t rectMargin - the distance between the image and the text rects
        
    Returns:
        void
        
    Remarks:
        The x and y position of sub will be manipulated by this function.  The
        dimensions of the rectangle should be set before calling and should
        remain unchanged after execution.
*/
void laUtils_ArrangeRectangle(GFX_Rect* sub,
                              GFX_Rect obj,
                              GFX_Rect bounds,
                              laHAlignment hAlignment,
                              laVAlignment vAlignment,
                              laRelativePosition position,
                              uint8_t leftMargin,
                              uint8_t topMargin,
                              uint8_t rightMargin,
                              uint8_t bottomMargin,
                              uint16_t rectMargin);

/*  Function:
        void laUtils_ArrangeRectangleRelative(GFX_Rect* sub,
                                              GFX_Rect obj,
                                              GFX_Rect bounds,
                                              laHAlignment hAlignment,
                                              laVAlignment vAlignment,
                                              laRelativePosition position,
                                              uint8_t leftMargin,
                                              uint8_t topMargin,
                                              uint8_t rightMargin,
                                              uint8_t bottomMargin,
                                              uint16_t rectMargin)
 
    Summary:
        Calculates the position of a rectangle within the given bounds and
        in accordance with the given parameters.  A use case for this is
        when an image and a text rectangle must be arranged in a button box.  
        This version of the algorithm will calculate the location of the
        text rectangle.
        
    Parameters:
        GFX_Rect* sub - the bounds of the subject rectangle (text)
        GFX_Rect obj - the bounds of the object rectangle (image)
        GFX_Rect bounds - the bounds of the bounding rectangle (widget)
        laHAlignment hAlignment - the horizontal alignment of the rects
        laVAlignment vAlignment - the vertical alignment of the rects
        laRelativePosition position - the relative position of the rectangles
        uint8_t leftMargin - the left margin of the bounding rectangle
        uint8_t topMargin - the top margin of the bounding rectangle
        uint8_t rightMargin - the right margin of the bounding rectangle
        uint8_t bottomMargin - the bottom margin of the bounding rectangle
        uint16_t rectMargin - the distance between the image and the text rects
        
    Returns:
        void
        
    Remarks:
        The x and y position of sub will be manipulated by this function.  The
        dimensions of the rectangle should be set before calling and should
        remain unchanged after execution.
*/
void laUtils_ArrangeRectangleRelative(GFX_Rect* sub,
                                      GFX_Rect obj,
                                      GFX_Rect bounds,
                                      laHAlignment hAlignment,
                                      laVAlignment vAlignment,
                                      laRelativePosition position,
                                      uint8_t leftMargin,
                                      uint8_t topMargin,
                                      uint8_t rightMargin,
                                      uint8_t bottomMargin,
                                      uint16_t rectMargin);

/*  Function:
        laBool laUtils_OcclusionCullTest(laWidget* widget)
 
    Summary:
        Performs an occlusion test for a widget in the tree.  A widget is
        occluded if it is completely covered by one or more widgets.  This
        is useful for culling widgets before the rasterizing phase.
        
    Parameters:
        laWidget* widget - the widget to test
        
    Returns:
        laBool - result of the occlusion test
*/                                     
laBool laUtils_OcclusionCullTest(laWidget* widget);

/*  Function:
        void laUtils_ListOcclusionCullTest(laList* list, GFX_Rect rect)
 
    Summary:
        Performs an occlusion test on a list of widgets an a rectangular
        area.  This attempts to find only the topmost widgets for the given
        area.  If a widget is completely occluded then it is removed from
        the list.  Any widgets that remain in the list should be redrawn
        by the rasterizer.
        
    Parameters:
        laList* list - the widget list to test
        GFX_Rect rect - the occlusion area
        
    Returns:
        void
*/    
void laUtils_ListOcclusionCullTest(laList* list, GFX_Rect rect);

laBool laUtils_WidgetIsOccluded(laWidget* wgt, const GFX_Rect* rect);


// *****************************************************************************
/* Function:
    void laUtils_ScreenToOrientedSpace(const GFX_Point* point,
                                       const GFX_Rect* rect,
                                       GFX_Orientation ori)

  Summary:
    Takes a point in screen space and returns a transformed version in oriented
    space.

  Parameters:
    const GFX_Point* point - the point to transform
    const GFX_Rect* rect - the screen dimensionrectangle
    GFX_Orientation - the orientation setting
    
  Returns:
    GFX_Point
*/  
GFX_Point laUtils_ScreenToOrientedSpace(const GFX_Point* pnt,
                                        const GFX_Rect* rect,
                                        GFX_Orientation ori);

// *****************************************************************************
/* Function:
    void laUtils_ScreenToMirroredSpace(const GFX_Point* point,
                                       const GFX_Rect* rect,
                                       GFX_Orientation ori)

  Summary:
    Takes a point in screen space and returns a transformed version in mirrored
    space.

  Parameters:
    const GFX_Point* point - the point to transform
    const GFX_Rect* rect - the screen dimensionrectangle
    GFX_Orientation - the orientation setting
    
  Returns:
    GFX_Point
*/                                        
GFX_Point laUtils_ScreenToMirroredSpace(const GFX_Point* pnt,
                                        const GFX_Rect* rect,
                                        GFX_Orientation ori);                                       

#endif // LIBARIA_UTILS_H