/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_line_graph.h

  Summary:


  Description:
    This module implements line graph drawing widget functions.
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

#ifndef LEGATO_WIDGET_LINE_GRAPH_H
#define LEGATO_WIDGET_LINE_GRAPH_H

#include "gfx/legato/common/legato_common.h"

#if LE_LINEGRAPH_WIDGET_ENABLED == 1

#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Enumeration:
    leLineGraphValueAxis

  Summary:
    The value axis index value
*/
typedef enum leLineGraphValueAxis
{
    LINE_GRAPH_AXIS_0 = 0,
//  LINE_GRAPH_AXIS_1, //unsupported
} leLineGraphValueAxis;

// *****************************************************************************
/* Enumeration:
    leLineGraphTickPosition

  Summary:
    The tick position relative to axis
*/
typedef enum leLineGraphTickPosition
{
    LINE_GRAPH_TICK_IN,
    LINE_GRAPH_TICK_OUT,
    LINE_GRAPH_TICK_CENTER,
} leLineGraphTickPosition;

// *****************************************************************************
/* Enumeration:
    leLineGraphDataPointType

  Summary:
    The graph data point type
*/
typedef enum leLineGraphDataPointType
{
    LINE_GRAPH_DATA_POINT_NONE,
    LINE_GRAPH_DATA_POINT_CIRCLE,
    LINE_GRAPH_DATA_POINT_SQUARE,
} leLineGraphDataPointType;

// *****************************************************************************
/* Structure:
    leLineGraphDataSeries

  Summary:
    The data series object that contains the series properties and data

  Description:


  Remarks:
    None.
*/
typedef struct leLineGraphDataSeries
{
    const leScheme* scheme;
    leArray data;
    leLineGraphValueAxis axis;
    leLineGraphDataPointType pointType;
    uint32_t pointSize;
    leBool fillPoints;
    leBool drawLines;
} leLineGraphDataSeries;

// *****************************************************************************
/* Structure:
    leLineGraphCategory

  Summary:
    Contains the Category properties

  Description:


  Remarks:
    None.
*/
typedef struct leLineGraphCategory
{
    const leString* text;
    int32_t stackValue;
} leLineGraphCategory;

// DOM-IGNORE-BEGIN

typedef struct leLineGraphWidget leLineGraphWidget;

#define LE_LINEGRAPHWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    uint32_t                 (*getTickLength)(const THIS_TYPE* _this); \
    leResult                 (*setTickLength)(THIS_TYPE* _this, uint32_t len); \
    leBool                   (*getStacked)(const THIS_TYPE* _this); \
    leResult                 (*setStacked)(THIS_TYPE* _this, leBool stk); \
    int32_t                  (*getMaxValue)(const THIS_TYPE* _this, leLineGraphValueAxis axis); \
    leResult                 (*setMaxValue)(THIS_TYPE* _this, leLineGraphValueAxis axis, int32_t val); \
    int32_t                  (*getMinValue)(const THIS_TYPE* _this, leLineGraphValueAxis axis); \
    leResult                 (*setMinValue)(THIS_TYPE* _this, leLineGraphValueAxis axis, int32_t val); \
    leBool                   (*getValueAxisLabelsVisible)(const THIS_TYPE* _this, leLineGraphValueAxis axis); \
    leResult                 (*setValueAxisLabelsVisible)(THIS_TYPE* _this, leLineGraphValueAxis axis, leBool vis); \
    leBool                   (*getFillGraphArea)(const THIS_TYPE* _this); \
    leResult                 (*setFillGraphArea)(THIS_TYPE* _this, leBool fill); \
    leBool                   (*getFillSeriesArea)(const THIS_TYPE* _this); \
    leResult                 (*setFillSeriesArea)(THIS_TYPE* _this, leBool fill); \
    leBool                   (*getGridLinesVisible)(const THIS_TYPE* _this, leLineGraphValueAxis axis); \
    leResult                 (*setGridLinesVisible)(THIS_TYPE* _this, leLineGraphValueAxis axis, leBool visible); \
    leBool                   (*getValueAxisTicksVisible)(const THIS_TYPE* _this, leLineGraphValueAxis axis); \
    leResult                 (*setValueAxisTicksVisible)(THIS_TYPE* _this, leLineGraphValueAxis axis, leBool vis); \
    uint32_t                 (*getValueAxisTickInterval)(const THIS_TYPE* _this, leLineGraphValueAxis axis); \
    leResult                 (*setValueAxisTickInterval)(THIS_TYPE* _this, leLineGraphValueAxis axis, uint32_t inv); \
    uint32_t                 (*getValueAxisSubtickInterval)(const THIS_TYPE* _this, leLineGraphValueAxis axis); \
    leResult                 (*setValueAxisSubtickInterval)(THIS_TYPE* _this, leLineGraphValueAxis axis, uint32_t inv); \
    leBool                   (*getValueAxisSubticksVisible)(const THIS_TYPE* _this, leLineGraphValueAxis axis); \
    leResult                 (*setValueAxisSubticksVisible)(THIS_TYPE* _this, leLineGraphValueAxis axis, leBool vis); \
    leBool                   (*getCategoryAxisTicksVisible)(const THIS_TYPE* _this); \
    leResult                 (*setCategoryAxisTicksVisible)(THIS_TYPE* _this, leBool vis); \
    int32_t                  (*addCategory)(THIS_TYPE* _this); \
    leString*                (*getCategoryString)(const THIS_TYPE* _this, int32_t categoryID); \
    leResult                 (*setCategoryString)(THIS_TYPE* _this, int32_t categoryID, const leString* str); \
    int32_t                  (*addSeries)(THIS_TYPE* _this); \
    int32_t                  (*addDataToSeries)(THIS_TYPE* _this, int32_t seriesID, int32_t val); \
    leResult                 (*setDataInSeries)(THIS_TYPE* _this, int32_t seriesID, int32_t idx, int32_t val); \
    leScheme*                (*getSeriesScheme)(const THIS_TYPE* _this, int32_t seriesID); \
    leResult                 (*setSeriesScheme)(THIS_TYPE* _this, int32_t seriesID, const leScheme* schm); \
    leBool                   (*getSeriesFillPoints)(const THIS_TYPE* _this, int32_t seriesID); \
    leResult                 (*setSeriesFillPoints)(THIS_TYPE* _this, int32_t seriesID, leBool fill); \
    leBool                   (*getSeriesLinesVisible)(const THIS_TYPE* _this, int32_t seriesID); \
    leResult                 (*setSeriesLinesVisible)(THIS_TYPE* _this, int32_t seriesID, leBool vis); \
    leLineGraphDataPointType (*getSeriesPointType)(const THIS_TYPE* _this, int32_t seriesID); \
    leResult                 (*setSeriesPointType)(THIS_TYPE* _this, int32_t seriesID, leLineGraphDataPointType type); \
    uint32_t                 (*getSeriesPointSize)(const THIS_TYPE* _this, int32_t seriesID); \
    leResult                 (*setSeriesPointSize)(THIS_TYPE* _this, int32_t seriesID, uint32_t size); \
    leResult                 (*clear)(THIS_TYPE* _this); \
    leResult                 (*setTicksLabelFont)(THIS_TYPE* _this, const leFont* font); \
    leBool                   (*getCategoryAxisLabelsVisible)(const THIS_TYPE* _this); \
    leResult                 (*setCategoryAxisLabelsVisible)(THIS_TYPE* _this, leBool vis); \
    leLineGraphTickPosition  (*getValueAxisTicksPosition)(const THIS_TYPE* _this, leLineGraphValueAxis axis); \
    leResult                 (*setValueAxisTicksPosition)(THIS_TYPE* _this, leLineGraphValueAxis axis, leLineGraphTickPosition position); \
    leLineGraphTickPosition  (*getValueAxisSubticksPosition)(const THIS_TYPE* _this, leLineGraphValueAxis axis); \
    leResult                 (*setValueAxisSubticksPosition)(THIS_TYPE* _this, leLineGraphValueAxis axis, leLineGraphTickPosition position); \
    leLineGraphTickPosition  (*getCategoryAxisTicksPosition)(const THIS_TYPE* _this); \
    leResult                 (*setCategoryAxisTicksPosition)(THIS_TYPE* _this, leLineGraphTickPosition position); \

typedef struct leLineGraphWidgetVTable
{
	LE_LINEGRAPHWIDGET_VTABLE(leLineGraphWidget)
} leLineGraphWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    leLineGraphWidget

  Summary:
    Implementation of a line graph widget.

  Description:
    A line graph widget draws a line graph. All coordinates are expressed in local widget space.

    The color of the graph is determined by the widget scheme's 'foreground'
    color.

  Remarks:
    None.
*/
typedef struct leLineGraphWidget
{
    leWidget widget; // base widget header

    leLineGraphWidgetVTable* fn;

    uint32_t tickLength;
    leBool fillGraphArea;
    leBool fillValueArea;

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
    leArray dataSeries;
    const leFont* ticksLabelFont; // ticks label font
    leLineGraphTickPosition valueAxisTicksPosition;
    leLineGraphTickPosition valueAxisSubticksPosition;

    //Category axis properties
    leBool categAxisLabelsVisible;
    leBool categAxisTicksVisible;
    leLineGraphTickPosition categAxisTicksPosition;
    leArray categories;
} leLineGraphWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leLineGraphWidget* leLineGraphWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the management of this memory until the
    widget is added to a widget tree.

  Description:

  Parameters:
    void

  Returns:
    leLineGraphWidget*

  Remarks:

*/
LIB_EXPORT leLineGraphWidget* leLineGraphWidget_New();

LIB_EXPORT void leLineGraphWidget_Constructor(leLineGraphWidget* graph);

#if 0
// *****************************************************************************
/* Function:
    uint32_t leLineGraphWidget_GetTickLength(leLineGraphWidget* graph)

  Summary:
    Returns the length of the ticks

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    uint32_t - tick length

  Remarks:

*/
LIB_EXPORT uint32_t leLineGraphWidget_GetTickLength(leLineGraphWidget* graph);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetTickLength(leLineGraphWidget* graph, uint32_t length)

  Summary:
    Sets the length of the ticks

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    uint32_t length - length in pixels

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetTickLength(leLineGraphWidget* graph, uint32_t length);

// *****************************************************************************
/* Function:
    uint32_t leLineGraphWidget_GetMaxValue(leLineGraphWidget* graph, leLineGraphValueAxis axis)

  Summary:
    Returns the max value of the axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    uint32_t - max value

  Remarks:

*/
LIB_EXPORT uint32_t leLineGraphWidget_GetMaxValue(leLineGraphWidget* graph, leLineGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetMaxValue(leLineGraphWidget* graph, leLineGraphValueAxis axis, int32_t value)

  Summary:
    Sets the max value of the axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the value axis index
    int32_t value - max value

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetMaxValue(leLineGraphWidget* graph, leLineGraphValueAxis axis, int32_t value);

// *****************************************************************************
/* Function:
    uint32_t leLineGraphWidget_GetMinValue(leLineGraphWidget* graph, leLineGraphValueAxis axis)

  Summary:
    Returns the min value of the axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    uint32_t - min value

  Remarks:

*/
LIB_EXPORT uint32_t leLineGraphWidget_GetMinValue(leLineGraphWidget* graph, leLineGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetMinValue(leLineGraphWidget* graph, leLineGraphValueAxis axis, int32_t value)

  Summary:
    Sets the min value of the axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the value axis index
    int32_t value - min value

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetMinValue(leLineGraphWidget* graph, leLineGraphValueAxis axis, int32_t value);

// *****************************************************************************
/* Function:
    leBool leLineGraphWidget_GetValueAxisLabelsVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis)

  Summary:
    Returns LE_TRUE if the value axis labels are visible

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the value axis labels are visible

  Remarks:

*/
LIB_EXPORT leBool leLineGraphWidget_GetValueAxisLabelsVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetValueAxisLabelsVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis, leBool visible)

  Summary:
    Shows/Hides the labels in the value axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the value axis index
    leBool visible - shows the labels if LE_TRUE

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetValueAxisLabelsVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis, leBool visible);

// *****************************************************************************
/* Function:
    leBool leLineGraphWidget_GetValueAxisTicksVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis)

  Summary:
    Returns LE_TRUE if the value axis ticks are visible

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the value axis ticks are visible

  Remarks:

*/
LIB_EXPORT leBool leLineGraphWidget_GetValueAxisTicksVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetValueAxisTicksVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis, leBool visible)

  Summary:
    Shows/Hides the ticks in the value axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the value axis index
    leBool visible - shows the ticks if LE_TRUE

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetValueAxisTicksVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis, leBool visible);

// *****************************************************************************
/* Function:
    leBool leLineGraphWidget_GetValueAxisSubticksVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis)

  Summary:
    Returns LE_TRUE if the value axis subticks are visible

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the value axis subticks are visible

  Remarks:

*/
LIB_EXPORT leBool leLineGraphWidget_GetValueAxisSubticksVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetValueAxisSubticksVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis, leBool visible)

  Summary:
    Shows/Hides the subticks in the value axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the value axis index
    leBool visible - shows the subticks if LE_TRUE

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetValueAxisSubticksVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis, leBool visible);

// *****************************************************************************
/* Function:
    uint32_t leLineGraphWidget_GetValueAxisTickInterval(leLineGraphWidget* graph, leLineGraphValueAxis axis)

  Summary:
    Returns the interval between major ticks in the value axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the value axis index

  Returns:
    uint32_t - ticks in pixels

  Remarks:

*/
LIB_EXPORT uint32_t leLineGraphWidget_GetValueAxisTickInterval(leLineGraphWidget* graph, leLineGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetValueAxisTickInterval(leLineGraphWidget* graph, leLineGraphValueAxis axis, uint32_t interval)

  Summary:
    Sets the tick interval in the value axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the value axis index
    uint32_t interval - tick interval in pixels

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetValueAxisTickInterval(leLineGraphWidget* graph, leLineGraphValueAxis axis, uint32_t interval);

// *****************************************************************************
/* Function:
    uint32_t leLineGraphWidget_GetValueAxisSubtickInterval(leLineGraphWidget* graph, leLineGraphValueAxis axis)

  Summary:
    Returns the interval between minor ticks in the value axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the value axis index

  Returns:
    uint32_t - ticks in pixels

  Remarks:

*/
LIB_EXPORT uint32_t leLineGraphWidget_GetValueAxisSubtickInterval(leLineGraphWidget* graph, leLineGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetValueAxisSubtickInterval(leLineGraphWidget* graph, leLineGraphValueAxis axis, uint32_t interval)

  Summary:
    Sets the minor tick interval in the value axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the value axis index
    uint32_t interval - tick interval in pixels

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetValueAxisSubtickInterval(leLineGraphWidget* graph, leLineGraphValueAxis axis, uint32_t interval);



// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_AddSeries(leLineGraphWidget* graph, uint32_t * seriesID)

  Summary:
    Adds a series to the graph

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    uint32_t * seriesID - destination of the returned series ID

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_AddSeries(leLineGraphWidget* graph, uint32_t * seriesID);

// *****************************************************************************
/* Function:
    leScheme * leLineGraphWidget_GetSeriesScheme(leLineGraphWidget* graph, uint32_t seriesID)

  Summary:
    Returns scheme of the specified series

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    leScheme * - scheme of the specified series

  Remarks:

*/
LIB_EXPORT leScheme * leLineGraphWidget_GetSeriesScheme(leLineGraphWidget* graph, uint32_t seriesID);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetSeriesScheme(leLineGraphWidget* graph, uint32_t seriesID, leScheme * scheme)

  Summary:
    Sets the color scheme of the series

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    int32_t seriesID - the series ID, if negative the last series is referenced
    leScheme * scheme - the color scheme

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetSeriesScheme(leLineGraphWidget* graph, int32_t seriesID, leScheme * scheme);

// *****************************************************************************
/* Function:
   leBool leLineGraphWidget_GetSeriesFillPoints(leLineGraphWidget* graph, uint32_t seriesID)

  Summary:
    Returns LE_TRUE if the series points are filled

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the series points are filled

  Remarks:

*/
LIB_EXPORT leBool leLineGraphWidget_GetSeriesFillPoints(leLineGraphWidget* graph, uint32_t seriesID);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetSeriesFillPoints(leLineGraphWidget* graph, int32_t seriesID, leBool fill)

  Summary:
    Sets the series points filled

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    int32_t seriesID - the series ID, if negative the last series is referenced
    leBool fill - fills the points if LE_TRUE

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetSeriesFillPoints(leLineGraphWidget* graph, int32_t seriesID, leBool fill);

// *****************************************************************************
/* Function:
   leBool leLineGraphWidget_GetSeriesLinesVisible(leLineGraphWidget* graph, uint32_t seriesID)

  Summary:
    Returns LE_TRUE if the series lines are visible

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the series lines are visible

  Remarks:

*/
LIB_EXPORT leBool leLineGraphWidget_GetSeriesLinesVisible(leLineGraphWidget* graph, uint32_t seriesID);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetSeriesLinesVisible(leLineGraphWidget* graph, int32_t seriesID, leBool visible)

  Summary:
    Shows/hides the lines between series points

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    int32_t seriesID - the series ID, if negative the last series is referenced
    leBool fill - Shows the lines between series data points if LE_TRUE

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetSeriesLinesVisible(leLineGraphWidget* graph, int32_t seriesID, leBool visible);

// *****************************************************************************
/* Function:
   leLineGraphDataPointType leLineGraphWidget_GetSeriesPointType(leLineGraphWidget* graph, uint32_t seriesID)

  Summary:
    Returns the type of point drawn for the series data points

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    uint32_t seriesID - the series ID,

  Returns:
    leLineGraphDataPointType - the point type

  Remarks:

*/
LIB_EXPORT leLineGraphDataPointType leLineGraphWidget_GetSeriesPointType(leLineGraphWidget* graph, uint32_t seriesID);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetSeriesPointType(leLineGraphWidget* graph, int32_t seriesID, leLineGraphDataPointType type)

  Summary:
    Sets the type of point drawn for the series data points

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    int32_t seriesID - the series ID, if negative the last series is referenced
    leLineGraphDataPointType type - point type

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetSeriesPointType(leLineGraphWidget* graph, int32_t seriesID, leLineGraphDataPointType type);

// *****************************************************************************
/* Function:
    uint32_t leLineGraphWidget_GetSeriesPointSize(leLineGraphWidget* graph, uint32_t seriesID)

  Summary:
    Returns the size of the drawn point

  Description:
    For circular points, this value is the radius
    For square points, the length of each side is twice the value

  Parameters:
    leLineGraphWidget* graph - the widget
    uint32_t seriesID - the series ID

  Returns:
    uint32_t - the point size

  Remarks:

*/
LIB_EXPORT uint32_t leLineGraphWidget_GetSeriesPointSize(leLineGraphWidget* graph, uint32_t seriesID);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetSeriesPointSize(leLineGraphWidget* graph, int32_t seriesID, uint32_t size)

  Summary:
    Sets the size of the point drawn for the series data

  Description:
    For circular points, this value sets the radius
    For square points, the length of each side is twice the value

  Parameters:
    leLineGraphWidget* graph - the widget
    int32_t seriesID - the series ID, if negative the last series is referenced
    uint32_t size - size in pixels

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetSeriesPointSize(leLineGraphWidget* graph, int32_t seriesID, uint32_t size);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_AddDataToSeries(leLineGraphWidget* graph, uint32_t seriesID, uint32_t categoryID, int32_t value)

  Summary:
    Adds a data (value) to the specified series at categoryID index

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    uint32_t seriesID - the series ID
    int32_t value - the value
    uint32_t * index - the destination to return the index of the added data

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_AddDataToSeries(leLineGraphWidget* graph, uint32_t seriesID, int32_t value, uint32_t * index);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetDataInSeries(leLineGraphWidget* graph,
                                              uint32_t seriesID,
                                              uint32_t index,
                                              int32_t value);
  Summary:
    Sets the value of the entry in the series index. The entry should have
    been previously

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    uint32_t seriesID - the series ID
    uint32_t index - the index of the data
    int32_t value - the value

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetDataInSeries(leLineGraphWidget* graph,
                                          uint32_t seriesID,
                                          uint32_t index,
                                          int32_t value);


// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_DestroyAll(leLineGraphWidget* graph)

  Summary:
    Destroys data, series and categories and frees the memory allocated

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_DestroyAll(leLineGraphWidget* graph);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetStringTable(leLineGraphWidget* graph, leStringTable * stringTable)

  Summary:
    Sets the string table used for the generated axis labels

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leStringTable * stringTable - the string table

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetStringTable(leLineGraphWidget* graph, leStringTable * stringTable);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetTicksLabelsStringID(leLineGraphWidget* graph, uint32_t stringID)

  Summary:
    Sets the ID of the superset string used for the value axis tick labels

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    uint32_t stringID - the string ID

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetTicksLabelsStringID(leLineGraphWidget* graph, uint32_t stringID);

// *****************************************************************************
/* Function:
    leBool leLineGraphWidget_GetGridLinesVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis)

  Summary:
    Returns LE_TRUE if the axis gridlines are visible

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the value axis index

  Returns:
    leBool - LE_TRUE if the axis gridlines are visible

  Remarks:

*/
LIB_EXPORT leBool leLineGraphWidget_GetGridLinesVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetGridLinesVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis, leBool visible)

  Summary:
    Shows/Hides the gridlines

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - category ID
    leBool visible - shows the gridlines if LE_TRUE

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetGridLinesVisible(leLineGraphWidget* graph, leLineGraphValueAxis axis, leBool visible);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_AddCategory(leLineGraphWidget* graph, uint32_t * id)

  Summary:
    Adds a category to the graph

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    uint32_t * id - destination of the ID of the new category

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_AddCategory(leLineGraphWidget* graph, uint32_t * id);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_GetCategoryText(leLineGraphWidget* graph, uint32_t categoryID, leString * str)

  Summary:
    Gets a copy of the string used to label the category

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    uint32_t categoryID - category ID
    leString * str - destination of the copied string

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_GetCategoryText(leLineGraphWidget* graph, uint32_t categoryID, leString * str);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetCategoryText(leLineGraphWidget* graph, uint32_t categoryID, leString str)

  Summary:
    Sets the string used to label the category

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    int32_t categoryID - category ID, if -1 the last category is assigned
    leString str - the string to use

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetCategoryText(leLineGraphWidget* graph, int32_t categoryID, leString str);

// *****************************************************************************
/* Function:
    leBool leLineGraphWidget_GetStacked(leLineGraphWidget* graph)

  Summary:
    Returns LE_TRUE if the bars are stacked

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leBool leLineGraphWidget_GetStacked(leLineGraphWidget* graph);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetStacked(leLineGraphWidget* graph, leBool stacked)

  Summary:
    Stacks the line graph

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leBool stacked - if LE_TRUE, the bars are stacked

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetStacked(leLineGraphWidget* graph, leBool stacked);

// *****************************************************************************
/* Function:
    leBool leLineGraphWidget_GetCategoryAxisTicksVisible(leLineGraphWidget* graph)

  Summary:
    Returns LE_TRUE if the category axis ticks are visible

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the category axis ticks are visible

  Remarks:

*/
LIB_EXPORT leBool leLineGraphWidget_GetCategoryAxisTicksVisible(leLineGraphWidget* graph);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetCategoryAxisTicksVisible(leLineGraphWidget* graph, leBool visible)

  Summary:
    Shows/Hides the category axis ticks

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leBool visible - if LE_TRUE, the axis ticks are shown

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetCategoryAxisTicksVisible(leLineGraphWidget* graph, leBool visible);

// *****************************************************************************
/* Function:
    leBool leLineGraphWidget_GetCategoryAxisLabelsVisible(leLineGraphWidget* graph)

  Summary:
    Returns LE_TRUE if the category axis labels are visible

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the category axis labels are visible

  Remarks:

*/
LIB_EXPORT leBool leLineGraphWidget_GetCategoryAxisLabelsVisible(leLineGraphWidget* graph);

// *****************************************************************************
/* Function:
    LIB_EXPORT leResult leLineGraphWidget_SetCategoryAxisLabelsVisible(leLineGraphWidget* graph, leBool visible)

  Summary:
    Shows/Hides the category axis labels

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leBool visible - if LE_TRUE, the axis labels are shown

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetCategoryAxisLabelsVisible(leLineGraphWidget* graph, leBool visible);

// *****************************************************************************
/* Function:
    leBool leLineGraphWidget_GetFillGraphArea(leLineGraphWidget* graph)

  Summary:
    Returns LE_TRUE if the graph area is filled

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the graph area is filled

  Remarks:

*/
LIB_EXPORT leBool leLineGraphWidget_GetFillGraphArea(leLineGraphWidget* graph);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetFillGraphArea(leLineGraphWidget* graph, leBool fill)

  Summary:
    Sets the graph area filled or not

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leBool fill - if LE_TRUE, fills the graph area

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetFillGraphArea(leLineGraphWidget* graph, leBool fill);

// *****************************************************************************
/* Function:
    leBool leLineGraphWidget_GetFillSeriesArea(leLineGraphWidget* graph)

  Summary:
    Returns LE_TRUE if the series area are filled

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    leBool - LE_TRUE if the series area is filled

  Remarks:

*/
LIB_EXPORT leBool leLineGraphWidget_GetFillSeriesArea(leLineGraphWidget* graph);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetFillGraphArea(leLineGraphWidget* graph, leBool fill)

  Summary:
    Sets the series area filled or not

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leBool fill - if LE_TRUE, fills the series area

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetFillSeriesArea(leLineGraphWidget* graph, leBool fill);

// *****************************************************************************
/* Function:
    leLineGraphTickPosition leLineGraphWidget_GetValueAxisTicksPosition(leLineGraphWidget* graph, leLineGraphValueAxis axis)

  Summary:
    Returns the position of the ticks in the axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the index of the value axis

  Returns:
    leLineGraphTickPosition - the tick position

  Remarks:

*/
LIB_EXPORT leLineGraphTickPosition leLineGraphWidget_GetValueAxisTicksPosition(leLineGraphWidget* graph, leLineGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetValueAxisTicksPosition(leLineGraphWidget* graph, leLineGraphValueAxis axis, leLineGraphTickPosition position)

  Summary:
    Sets the position of the ticks in the value axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the value axis index
    leLineGraphTickPosition position - the tick position

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetValueAxisTicksPosition(leLineGraphWidget* graph, leLineGraphValueAxis axis, leLineGraphTickPosition position);

// *****************************************************************************
/* Function:
    leLineGraphTickPosition leLineGraphWidget_GetValueAxisSubticksPosition(leLineGraphWidget* graph, leLineGraphValueAxis axis)

  Summary:
    Returns the position of the subticks in the axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the index of the value axis

  Returns:
    leLineGraphTickPosition - the subtick position

  Remarks:

*/
LIB_EXPORT leLineGraphTickPosition leLineGraphWidget_GetValueAxisSubticksPosition(leLineGraphWidget* graph, leLineGraphValueAxis axis);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetValueAxisSubticksPosition(leLineGraphWidget* graph, leLineGraphValueAxis axis, leLineGraphTickPosition position)

  Summary:
    Sets the position of the subticks in the value axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphValueAxis axis - the value axis index
    leLineGraphTickPosition position  - position of the subticks

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetValueAxisSubticksPosition(leLineGraphWidget* graph, leLineGraphValueAxis axis, leLineGraphTickPosition position);

// *****************************************************************************
/* Function:
    leLineGraphTickPosition leLineGraphWidget_GetCategoryAxisTicksPosition(leLineGraphWidget* graph)

  Summary:
    Returns the position of the ticks in the category axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget

  Returns:
    leLineGraphTickPosition - position of the ticks in the category axis

  Remarks:

*/
LIB_EXPORT leLineGraphTickPosition leLineGraphWidget_GetCategoryAxisTicksPosition(leLineGraphWidget* graph);

// *****************************************************************************
/* Function:
    leResult leLineGraphWidget_SetCategoryAxisTicksPosition(leLineGraphWidget* graph, leLineGraphTickPosition position)

  Summary:
    Sets the position of the ticks in the category axis

  Description:

  Parameters:
    leLineGraphWidget* graph - the widget
    leLineGraphTickPosition position  - position of the ticks

  Returns:
    leResult - the result of the operation

  Remarks:

*/
LIB_EXPORT leResult leLineGraphWidget_SetCategoryAxisTicksPosition(leLineGraphWidget* graph, leLineGraphTickPosition position);

// DOM-IGNORE-BEGIN
// internal use only
void _leLineGraphWidget_GetGraphRect(leLineGraphWidget* graph,
                                           leRect * graphRect);

lePoint _leLineGraphWidget_GetValuePoint(leLineGraphWidget* graph,
                                     uint32_t seriesID,
                                     uint32_t categoryIndex,
                                     lePoint originPoint);

lePoint _leLineGraphWidget_GetOriginPoint(leLineGraphWidget* graph);
// DOM-IGNORE-END

#endif

#endif // LE_LINEGRAPH_WIDGET_ENABLED
#endif /* LEGATO_WIDGET_LINE_GRAPH_H */
