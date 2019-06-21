/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_bar_graph.h

  Summary:


  Description:
    This module implements bar graph drawing widget functions.
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
//DOM-IGNORE-END

#ifndef LEGATO_WIDGET_BAR_GRAPH_H
#define LEGATO_WIDGET_BAR_GRAPH_H

#include "gfx/legato/common/legato_common.h"

#if LE_BAR_GRAPH_WIDGET_ENABLED

#include "gfx/legato/string/legato_dynamicstring.h"
#include "gfx/legato/widget/legato_widget.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************
#define MAX_TICK_LABEL_DIGITS 10
#define MAX_TICK_LABEL_VALUE 999999999
#define LABEL_OFFSET_MIN_PIX 5

// *****************************************************************************
/* Enumeration:
    leBarGraphValueAxis

  Summary:
    The value axis index value
*/
typedef enum leBarGraphValueAxis
{
    BAR_GRAPH_AXIS_0 = 0,
//  BAR_GRAPH_AXIS_1, //unsupported
} leBarGraphValueAxis;

// *****************************************************************************
/* Enumeration:
    leBarGraphTickPosition

  Summary:
    The tick position relative to axis
*/
typedef enum leBarGraphTickPosition
{
    BAR_GRAPH_TICK_IN,
    BAR_GRAPH_TICK_OUT,
    BAR_GRAPH_TICK_CENTER,
} leBarGraphTickPosition;

// *****************************************************************************
/* Structure:
    leBarGraphDataSeries

  Summary:
    The data series object that contains the series properties and data

  Description:


  Remarks:
    None.
*/
typedef struct leBarGraphDataSeries
{
    const leScheme* scheme;
    leArray data;
    leBarGraphValueAxis axis;
} leBarGraphDataSeries;

// DOM-IGNORE-BEGIN
typedef struct leBarGraphWidget leBarGraphWidget;

#define LE_BARGRAPHWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    uint32_t                (*getTickLength)(const THIS_TYPE* _this); \
    leResult                (*setTickLength)(THIS_TYPE* _this, uint32_t len); \
    uint32_t                (*getMinValue)(const THIS_TYPE* _this, leBarGraphValueAxis axis); \
    leResult                (*setMinValue)(THIS_TYPE* _this, leBarGraphValueAxis axis, int32_t min); \
    uint32_t                (*getMaxValue)(const THIS_TYPE* _this, leBarGraphValueAxis axis); \
    leResult                (*setMaxValue)(THIS_TYPE* _this, leBarGraphValueAxis axis, int32_t max); \
    leBool                  (*getValueAxisLabelsVisible)(const THIS_TYPE* _this, leBarGraphValueAxis axis); \
    leResult                (*setValueAxisLabelsVisible)(THIS_TYPE* _this, leBarGraphValueAxis axis, leBool vis); \
    leBool                  (*getValueAxisTicksVisible)(const THIS_TYPE* _this, leBarGraphValueAxis axis); \
    leResult                (*setValueAxisTicksVisible)(THIS_TYPE* _this, leBarGraphValueAxis axis, leBool vis); \
    uint32_t                (*getValueAxisTicksInterval)(const THIS_TYPE* _this, leBarGraphValueAxis axis); \
    leResult                (*setValueAxisTicksInterval)(THIS_TYPE* _this, leBarGraphValueAxis axis, uint32_t itv); \
    leBarGraphTickPosition  (*getValueAxisTicksPosition)(const THIS_TYPE* _this, leBarGraphValueAxis axis); \
    leResult                (*setValueAxisTicksPosition)(THIS_TYPE* _this, leBarGraphValueAxis axis, leBarGraphTickPosition pos); \
    leBool                  (*getValueAxisSubticksVisible)(const THIS_TYPE* _this, leBarGraphValueAxis axis); \
    leResult                (*setValueAxisSubticksVisible)(THIS_TYPE* _this, leBarGraphValueAxis axis, leBool vis); \
    uint32_t                (*getValueAxisSubticksInterval)(const THIS_TYPE* _this, leBarGraphValueAxis axis); \
    leResult                (*setValueAxisSubticksInterval)(THIS_TYPE* _this, leBarGraphValueAxis axis, uint32_t itv); \
    leBarGraphTickPosition  (*getValueAxisSubticksPosition)(const THIS_TYPE* _this, leBarGraphValueAxis axis); \
    leResult                (*setValueAxisSubticksPosition)(THIS_TYPE* _this, leBarGraphValueAxis axis, leBarGraphTickPosition pos); \
    leBool                  (*getCategoryAxisTicksVisible)(const THIS_TYPE* _this); \
    leResult                (*setCategoryAxisTicksVisible)(THIS_TYPE* _this, leBool vis); \
    leBarGraphTickPosition  (*getCategoryAxisTicksPosition)(const THIS_TYPE* _this); \
    leResult                (*setCategoryAxisTicksPosition)(THIS_TYPE* _this, leBarGraphTickPosition pos); \
    leBool                  (*getCategoryAxisLabelsVisible)(const THIS_TYPE* _this); \
    leResult                (*setCategoryAxisLabelsVisible)(THIS_TYPE* _this, leBool vis); \
    leResult                (*addSeries)(THIS_TYPE* _this, uint32_t* seriesID); \
    leScheme*               (*getSeriesScheme)(const THIS_TYPE* _this, uint32_t seriesID); \
    leResult                (*setSeriesScheme)(THIS_TYPE* _this, uint32_t seriesID, const leScheme* schm); \
    leResult                (*addDataToSeries)(THIS_TYPE* _this, uint32_t seriesID, int32_t val, uint32_t* idx); \
    leResult                (*setDataInSeries)(THIS_TYPE* _this, uint32_t seriesID, uint32_t index, int32_t value); \
    leResult                (*clearData)(THIS_TYPE* _this); \
    leResult                (*setTicksLabelString)(THIS_TYPE* _this, const leString* str); \
    leResult                (*setTicksLabelFont)(THIS_TYPE* _this, const leFont* font); \
    leBool                  (*getGridLinesVisible)(const THIS_TYPE* _this, leBarGraphValueAxis axis); \
    leResult                (*setGridLinesVisible)(THIS_TYPE* _this, leBarGraphValueAxis axis, leBool vis); \
    leResult                (*addCategory)(THIS_TYPE* _this, uint32_t* id); \
    leString*               (*getCategoryString)(const THIS_TYPE* _this, uint32_t id); \
    leResult                (*setCategoryString)(THIS_TYPE* _this, uint32_t id, const leString* str); \
    leBool                  (*getStacked)(const THIS_TYPE* _this); \
    leResult                (*setStacked)(THIS_TYPE* _this, leBool stk); \
    leBool                  (*getFillGraphArea)(const THIS_TYPE* _this); \
    leResult                (*setFillGraphArea)(THIS_TYPE* _this, leBool fill); \
    
    

typedef struct leBarGraphWidgetVTable
{
	LE_BARGRAPHWIDGET_VTABLE(leBarGraphWidget)
} leBarGraphWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leBarGraphWidget

  Summary:
    Implementation of a bar graph widget.

  Description:
    A bar graph widget draws a bar graph. All coordinates are expressed in local widget space.

    The color of the graph is determined by the widget scheme's 'foreground'
    color.

  Remarks:
    None.
*/
typedef struct leBarGraphWidget
{
    leWidget widget; // base widget header

    leBarGraphWidgetVTable* fn;

    uint32_t tickLength;
    leBool fillGraphArea;

    //Value axis properties
    int32_t maxValue;
    int32_t minValue;
    uint32_t tickInterval;
    uint32_t subtickInterval;
    leBool valueAxisLabelsVisible;
    leBool valueAxisTicksVisible;
    leBool valueAxisSubticksVisible;
    leBool valueGridLinesVisible;
    leBool stacked;
    leArray dataSeriesArray;
    leDynamicString ticksLabelString;
    leBarGraphTickPosition valueAxisTicksPosition;
    leBarGraphTickPosition valueAxisSubticksPosition;

    //Category axis properties
    leBool categAxisLabelsVisible;
    leBool categAxisTicksVisible;
    leBarGraphTickPosition categAxisTicksPosition;
    leArray categories;
    
    // paint state
    leRect graphRect;
    lePoint originPoint;
    int32_t originValue;
    uint32_t alpha;
    float pixelsPerUnit;
} leBarGraphWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leBarGraphWidget* leBarGraphWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the management of this memory until the
    widget is added to a widget tree.

  Description:

  Parameters:
    void

  Returns:
    leBarGraphWidget*

  Remarks:

*/
LIB_EXPORT leBarGraphWidget* leBarGraphWidget_New();

LIB_EXPORT leResult leBarGraphWidget_Constructor(leBarGraphWidget* wgt);

#if 0
// *****************************************************************************
/* Function:
    uint32_t leBarGraphWidget_GetTickLength(leBarGraphWidget* graph)

  Summary:
    Returns the length of the ticks

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget

  Returns:
    uint32_t - tick length

  Remarks:

*/
LIB_EXPORT uint32_t leBarGraphWidget_GetTickLength(leBarGraphWidget* graph);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetTickLength(leBarGraphWidget* graph, uint32_t length)

  Summary:
    Sets the length of the ticks

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    uint32_t length - length in pixels

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetTickLength(leBarGraphWidget* graph, uint32_t length);

// *****************************************************************************
/* Function:
    uint32_t leBarGraphWidget_GetMaxValue(leBarGraphWidget* graph, leBarGraphValueAxis axis)

  Summary:
    Returns the max value of the axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget

  Returns:
    uint32_t - max value

  Remarks:

*/
LIB_EXPORT uint32_t leBarGraphWidget_GetMaxValue(leBarGraphWidget* graph, leBarGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetMaxValue(leBarGraphWidget* graph, leBarGraphValueAxis axis, int32_t value)

  Summary:
    Sets the max value of the axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the value axis index
    int32_t value - max value

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetMaxValue(leBarGraphWidget* graph, leBarGraphValueAxis axis, int32_t value);

// *****************************************************************************
/* Function:
    uint32_t leBarGraphWidget_GetMinValue(leBarGraphWidget* graph, leBarGraphValueAxis axis)

  Summary:
    Returns the min value of the axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget

  Returns:
    uint32_t - min value

  Remarks:

*/
LIB_EXPORT uint32_t leBarGraphWidget_GetMinValue(leBarGraphWidget* graph, leBarGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetMinValue(leBarGraphWidget* graph, leBarGraphValueAxis axis, int32_t value)

  Summary:
    Sets the min value of the axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the value axis index
    int32_t value - min value

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetMinValue(leBarGraphWidget* graph, leBarGraphValueAxis axis, int32_t value);

// *****************************************************************************
/* Function:
    leBool leBarGraphWidget_GetValueAxisLabelsVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis)

  Summary:
    Returns LE_TRUE if the value axis labels are visible

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the value axis labels are visible

  Remarks:

*/
LIB_EXPORT leBool leBarGraphWidget_GetValueAxisLabelsVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetValueAxisLabelsVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis, leBool visible)

  Summary:
    Shows/Hides the labels in the value axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the value axis index
    leBool visible - shows the labels if LE_TRUE

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetValueAxisLabelsVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis, leBool visible);

// *****************************************************************************
/* Function:
    leBool leBarGraphWidget_GetValueAxisTicksVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis)

  Summary:
    Returns LE_TRUE if the value axis ticks are visible

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the value axis ticks are visible

  Remarks:

*/
LIB_EXPORT leBool leBarGraphWidget_GetValueAxisTicksVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetValueAxisTicksVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis, leBool visible)

  Summary:
    Shows/Hides the ticks in the value axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the value axis index
    leBool visible - shows the ticks if LE_TRUE

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetValueAxisTicksVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis, leBool visible);

// *****************************************************************************
/* Function:
    leBool leBarGraphWidget_GetValueAxisSubticksVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis)

  Summary:
    Returns LE_TRUE if the value axis subticks are visible

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the value axis subticks are visible

  Remarks:

*/
LIB_EXPORT leBool leBarGraphWidget_GetValueAxisSubticksVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetValueAxisSubticksVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis, leBool visible)

  Summary:
    Shows/Hides the subticks in the value axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the value axis index
    leBool visible - shows the subticks if LE_TRUE

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetValueAxisSubticksVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis, leBool visible);

// *****************************************************************************
/* Function:
    uint32_t leBarGraphWidget_GetValueAxisTickInterval(leBarGraphWidget* graph, leBarGraphValueAxis axis)

  Summary:
    Returns the interval between major ticks in the value axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the value axis index

  Returns:
    uint32_t - ticks in pixels

  Remarks:

*/
LIB_EXPORT uint32_t leBarGraphWidget_GetValueAxisTickInterval(leBarGraphWidget* graph, leBarGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetValueAxisTickInterval(leBarGraphWidget* graph, leBarGraphValueAxis axis, uint32_t interval)

  Summary:
    Sets the tick interval in the value axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the value axis index
    uint32_t interval - tick interval in pixels

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetValueAxisTickInterval(leBarGraphWidget* graph, leBarGraphValueAxis axis, uint32_t interval);

// *****************************************************************************
/* Function:
    uint32_t leBarGraphWidget_GetValueAxisSubtickInterval(leBarGraphWidget* graph, leBarGraphValueAxis axis)

  Summary:
    Returns the interval between minor ticks in the value axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the value axis index

  Returns:
    uint32_t - ticks in pixels

  Remarks:

*/
LIB_EXPORT uint32_t leBarGraphWidget_GetValueAxisSubtickInterval(leBarGraphWidget* graph, leBarGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetValueAxisSubtickInterval(leBarGraphWidget* graph, leBarGraphValueAxis axis, uint32_t interval)

  Summary:
    Sets the minor tick interval in the value axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the value axis index
    uint32_t interval - tick interval in pixels

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetValueAxisSubtickInterval(leBarGraphWidget* graph, leBarGraphValueAxis axis, uint32_t interval);



// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_AddSeries(leBarGraphWidget* graph, uint32_t * seriesID)

  Summary:
    Adds a series to the graph

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    uint32_t * seriesID - destination of the returned series ID

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_AddSeries(leBarGraphWidget* graph, uint32_t * seriesID);

// *****************************************************************************
/* Function:
    leScheme * leBarGraphWidget_GetSeriesScheme(leBarGraphWidget* graph, uint32_t seriesID)

  Summary:
    Returns scheme of the specified series

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget

  Returns:
    leScheme * - scheme of the specified series

  Remarks:

*/
LIB_EXPORT leScheme * leBarGraphWidget_GetSeriesScheme(leBarGraphWidget* graph, uint32_t seriesID);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetSeriesScheme(leBarGraphWidget* graph, uint32_t seriesID, leScheme * scheme)

  Summary:
    Sets the color scheme of the series

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    int32_t seriesID - the series ID, if negative the last series is referenced
    leScheme * scheme - the color scheme

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetSeriesScheme(leBarGraphWidget* graph, int32_t seriesID, leScheme * scheme);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_AddDataToSeries(leBarGraphWidget* graph, uint32_t seriesID, uint32_t categoryID, int32_t value)

  Summary:
    Adds a data (value) to the specified series at categoryID index

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    uint32_t seriesID - the series ID
    int32_t value - the value
    uint32_t * index - the destination to return the index of the added data

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_AddDataToSeries(leBarGraphWidget* graph, uint32_t seriesID, int32_t value, uint32_t * index);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetDataInSeries(leBarGraphWidget* graph,
                                              uint32_t seriesID,
                                              uint32_t index,
                                              int32_t value);
  Summary:
    Sets the value of the entry in the series index. The entry should have
    been previously

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    uint32_t seriesID - the series ID
    uint32_t index - the index of the data
    int32_t value - the value

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetDataInSeries(leBarGraphWidget* graph,
                                          uint32_t seriesID,
                                          uint32_t index,
                                          int32_t value);


// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_DestroyAll(leBarGraphWidget* graph)

  Summary:
    Destroys data, series and categories and frees the memory allocated

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_DestroyAll(leBarGraphWidget* graph);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetTicksLabelsStringID(leBarGraphWidget* graph, uint32_t stringID)

  Summary:
    Sets the ID of the superset string used for the value axis tick labels

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    uint32_t stringID - the string ID

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetTicksLabelsStringID(leBarGraphWidget* graph, uint32_t stringID);

// *****************************************************************************
/* Function:
    leBool leBarGraphWidget_GetGridLinesVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis)

  Summary:
    Returns LE_TRUE if the axis gridlines are visible

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the value axis index

  Returns:
    leBool - LE_TRUE if the axis gridlines are visible

  Remarks:

*/
LIB_EXPORT leBool leBarGraphWidget_GetGridLinesVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetGridLinesVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis, leBool visible)

  Summary:
    Shows/Hides the gridlines

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - category ID
    leBool visible - shows the gridlines if LE_TRUE

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetGridLinesVisible(leBarGraphWidget* graph, leBarGraphValueAxis axis, leBool visible);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_AddCategory(leBarGraphWidget* graph, uint32_t * id)

  Summary:
    Adds a category to the graph

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    uint32_t * id - destination of the ID of the new category

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_AddCategory(leBarGraphWidget* graph, uint32_t * id);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_GetCategoryText(leBarGraphWidget* graph, uint32_t categoryID, leString * str)

  Summary:
    Gets a copy of the string used to label the category

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    uint32_t categoryID - category ID
    leString * str - destination of the copied string

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_GetCategoryText(leBarGraphWidget* graph, uint32_t categoryID, leString * str);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetCategoryText(leBarGraphWidget* graph, uint32_t categoryID, leString str)

  Summary:
    Sets the string used to label the category

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    int32_t categoryID - category ID, if -1 the last category is assigned
    leString str - the string to use

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetCategoryText(leBarGraphWidget* graph, int32_t categoryID, leString str);

// *****************************************************************************
/* Function:
    leBool leBarGraphWidget_GetStacked(leBarGraphWidget* graph)

  Summary:
    Returns LE_TRUE if the bars are stacked

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leBool leBarGraphWidget_GetStacked(leBarGraphWidget* graph);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetStacked(leBarGraphWidget* graph, leBool stacked)

  Summary:
    Stacks the bar graph

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBool stacked - if LE_TRUE, the bars are stacked

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetStacked(leBarGraphWidget* graph, leBool stacked);

// *****************************************************************************
/* Function:
    leBool leBarGraphWidget_GetCategoryAxisTicksVisible(leBarGraphWidget* graph)

  Summary:
    Returns LE_TRUE if the category axis ticks are visible

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the category axis ticks are visible

  Remarks:

*/
LIB_EXPORT leBool leBarGraphWidget_GetCategoryAxisTicksVisible(leBarGraphWidget* graph);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetCategoryAxisTicksVisible(leBarGraphWidget* graph, leBool visible)

  Summary:
    Shows/Hides the category axis ticks

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBool visible - if LE_TRUE, the axis ticks are shown

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetCategoryAxisTicksVisible(leBarGraphWidget* graph, leBool visible);

// *****************************************************************************
/* Function:
    leBool leBarGraphWidget_GetCategoryAxisLabelsVisible(leBarGraphWidget* graph)

  Summary:
    Returns LE_TRUE if the category axis labels are visible

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the category axis labels are visible

  Remarks:

*/
LIB_EXPORT leBool leBarGraphWidget_GetCategoryAxisLabelsVisible(leBarGraphWidget* graph);

// *****************************************************************************
/* Function:
    LIB_EXPORT leResult leBarGraphWidget_SetCategoryAxisLabelsVisible(leBarGraphWidget* graph, leBool visible)

  Summary:
    Shows/Hides the category axis labels

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBool visible - if LE_TRUE, the axis labels are shown

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetCategoryAxisLabelsVisible(leBarGraphWidget* graph, leBool visible);

// *****************************************************************************
/* Function:
    leBool leBarGraphWidget_GetFillGraphArea(leBarGraphWidget* graph)

  Summary:
    Returns LE_TRUE if the category axis labels are visible

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the category axis labels are visible

  Remarks:

*/
LIB_EXPORT leBool leBarGraphWidget_GetFillGraphArea(leBarGraphWidget* graph);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetFillGraphArea(leBarGraphWidget* graph, leBool fill)

  Summary:
    Sets the graph area filled or not

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBool fill - if LE_TRUE, fills the graph area

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetFillGraphArea(leBarGraphWidget* graph, leBool fill);

// *****************************************************************************
/* Function:
    leBarGraphTickPosition leBarGraphWidget_GetValueAxisTicksPosition(leBarGraphWidget* graph, leBarGraphValueAxis axis)

  Summary:
    Returns the position of the ticks in the axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the index of the value axis

  Returns:
    leBarGraphTickPosition - the tick position

  Remarks:

*/
LIB_EXPORT leBarGraphTickPosition leBarGraphWidget_GetValueAxisTicksPosition(leBarGraphWidget* graph, leBarGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetValueAxisTicksPosition(leBarGraphWidget* graph, leBarGraphValueAxis axis, leBarGraphTickPosition position)

  Summary:
    Sets the position of the ticks in the value axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the value axis index
    leBarGraphTickPosition position - the tick position

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetValueAxisTicksPosition(leBarGraphWidget* graph, leBarGraphValueAxis axis, leBarGraphTickPosition position);

// *****************************************************************************
/* Function:
    leBarGraphTickPosition leBarGraphWidget_GetValueAxisSubticksPosition(leBarGraphWidget* graph, leBarGraphValueAxis axis)

  Summary:
    Returns the position of the subticks in the axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the index of the value axis

  Returns:
    leBarGraphTickPosition - the subtick position

  Remarks:

*/
LIB_EXPORT leBarGraphTickPosition leBarGraphWidget_GetValueAxisSubticksPosition(leBarGraphWidget* graph, leBarGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetValueAxisSubticksPosition(leBarGraphWidget* graph, leBarGraphValueAxis axis, leBarGraphTickPosition position)

  Summary:
    Sets the position of the subticks in the value axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphValueAxis axis - the value axis index
    leBarGraphTickPosition position  - position of the subticks

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetValueAxisSubticksPosition(leBarGraphWidget* graph, leBarGraphValueAxis axis, leBarGraphTickPosition position);

// *****************************************************************************
/* Function:
    leBarGraphTickPosition leBarGraphWidget_GetCategoryAxisTicksPosition(leBarGraphWidget* graph)

  Summary:
    Returns the position of the ticks in the category axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget

  Returns:
    leBarGraphTickPosition - position of the ticks in the category axis

  Remarks:

*/
LIB_EXPORT leBarGraphTickPosition leBarGraphWidget_GetCategoryAxisTicksPosition(leBarGraphWidget* graph);

// *****************************************************************************
/* Function:
    leResult leBarGraphWidget_SetCategoryAxisTicksPosition(leBarGraphWidget* graph, leBarGraphTickPosition position)

  Summary:
    Sets the position of the ticks in the category axis

  Description:

  Parameters:
    leBarGraphWidget* graph - the widget
    leBarGraphTickPosition position  - position of the ticks

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leBarGraphWidget_SetCategoryAxisTicksPosition(leBarGraphWidget* graph, leBarGraphTickPosition position);

// DOM-IGNORE-BEGIN
//Internal use only
void _leBarGraphWidget_GetGraphRect(leBarGraphWidget* graph,
                                           leRect * graphRect);
// DOM-IGNORE-END
#endif

#endif // LE_BAR_GRAPH_WIDGET_ENABLED
#endif /* LEGATO_WIDGET_BAR_GRAPH_H */
