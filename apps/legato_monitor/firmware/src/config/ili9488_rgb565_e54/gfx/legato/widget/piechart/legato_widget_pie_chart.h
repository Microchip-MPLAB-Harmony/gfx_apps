/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_widget_pie_chart.h

  Summary:


  Description:
    This module implements pie chart drawing widget functions.
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

#ifndef LEGATO_WIDGET_PIE_CHART_H
#define LEGATO_WIDGET_PIE_CHART_H

#include "gfx/legato/common/legato_common.h"

#if LE_PIE_CHART_WIDGET_ENABLED == 1

#include "gfx/legato/asset/legato_font.h"
#include "gfx/legato/widget/legato_widget.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

typedef struct lePieChartPie
{
    uint32_t value;
    uint32_t radius;
    uint32_t offset;
    const leScheme* scheme;
} lePieChartPie;

typedef struct lePieChartWidget lePieChartWidget;

// *****************************************************************************
/* Function Pointer:
    lePieChartWidget_PressedEvent

  Summary:
    Chart pressed event function callback type
*/
typedef void (*lePieChartWidget_PressedEvent)(lePieChartWidget*, uint32_t);


// DOM-IGNORE-BEGIN
typedef struct lePieChartWidget lePieChartWidget;

#define LE_PIECHARTWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    int32_t             (*getStartAngle)(const THIS_TYPE* _this); \
    leResult            (*setStartAngle)(THIS_TYPE* _this, int32_t ang); \
    int32_t             (*getCenterAngle)(const THIS_TYPE* _this); \
    leResult            (*setCenterAngle)(THIS_TYPE* _this, int32_t ang); \
    int32_t             (*addEntry)(THIS_TYPE* _this); \
    leResult            (*clear)(THIS_TYPE* _this); \
    uint32_t            (*getEntryValue)(const THIS_TYPE* _this, int32_t idx); \
    leResult            (*setEntryValue)(THIS_TYPE* _this, int32_t idx, uint32_t val); \
    uint32_t            (*getEntryRadius)(const THIS_TYPE* _this, int32_t idx); \
    leResult            (*setEntryRadius)(THIS_TYPE* _this, int32_t idx, uint32_t rad); \
    uint32_t            (*getEntryOffset)(const THIS_TYPE* _this, int32_t idx); \
    leResult            (*setEntryOffset)(THIS_TYPE* _this, int32_t idx, uint32_t offs); \
    leScheme*           (*getEntryScheme)(const THIS_TYPE* _this, int32_t idx); \
    leResult            (*setEntryScheme)(THIS_TYPE* _this, int32_t idx, const leScheme* schm); \
    lePieChartWidget_PressedEvent (*getPressedEventCallback)(const THIS_TYPE* _this); \
    leResult            (*setPressedEventCallback)(THIS_TYPE* _this, lePieChartWidget_PressedEvent cb); \
    leFont*             (*getLabelFont)(const THIS_TYPE* _this); \
    leResult            (*setLabelFont)(THIS_TYPE* _this, const leFont* fnt); \
    leBool              (*getLabelsVisible)(const THIS_TYPE* _this); \
    leResult            (*setLabelsVisible)(THIS_TYPE* _this, leBool vis); \
    uint32_t            (*getLabelsOffset)(const THIS_TYPE* _this); \
    leResult            (*setLabelsOffset)(THIS_TYPE* _this, uint32_t offs); \
    
typedef struct lePieChartWidgetVTable
{
	LE_PIECHARTWIDGET_VTABLE(lePieChartWidget)
} lePieChartWidgetVTable; 

// DOM-IGNORE-END

// *****************************************************************************
/* Structure:
    lePieChartWidget

  Summary:
    Implementation of a pie chart widget.

  Description:
    A chart widget draws a chart of the specified origin and radius inside
    the widget bounds.  All coordinates are expressed in local widget space.

    The color of the chart is determined by the widget scheme's 'foreground'
    color.

  Remarks:
    None.
*/
typedef struct lePieChartWidget
{
    leWidget widget; // base widget header

    lePieChartWidgetVTable* fn;

    uint32_t startAngle;                    //the start angle of the chart
    int32_t centerAngle;                    //the center angle of the chart

    leArray pieArray;                       //list of pie/data

    //Label properties
    leBool labelsVisible;                   // are labels visible
    uint32_t labelsOffset;                  // offset of labels from center of pie
    const leFont* labelFont;                // label

    lePieChartWidget_PressedEvent pressedCallback;
} lePieChartWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    lePieChartWidget* lePieChartWidget_New()

  Summary:
    Allocates memory for and initializes a new widget of this type.  The
    application is responsible for the management of this memory until the
    widget is added to a widget tree.

  Description:


  Parameters:
    void

  Returns:
    lePieChartWidget*

  Remarks:

*/
LIB_EXPORT lePieChartWidget* lePieChartWidget_New();

LIB_EXPORT void lePieChartWidget_Constructor(lePieChartWidget* chart);

#if 0
// *****************************************************************************
/* Function:
    leResult lePieChartWidget_GetOrigin(lePieChartWidget* chart, int32_t* x, int32_t* y)

  Summary:
    Gets the origin coordinates of a chart widget

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    int32_t* x - pointer to an integer pointer to store x
    int32_t* y - pointer to an integer pointer to store y

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_GetOrigin(lePieChartWidget* chart, int32_t* x, int32_t* y);

// *****************************************************************************
/* Function:
    leResult lePieChartWidget_SetOrigin(lePieChartWidget* chart, int32_t x, int32_t y)

  Summary:
    Sets the origin coordiates of a chart widget

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    int32_t x - the desired x origin coordinate
    int32_t y - the desired y origin coordinate

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_SetOrigin(lePieChartWidget* chart, int32_t x, int32_t y);

// *****************************************************************************
/* Function:
    int32_t lePieChartWidget_GetStartAngle(lePieChartWidget* chart)

  Summary:
    Returns the start angle of a chart widget

  Description:


  Parameters:
    lePieChartWidget* chart - the widget

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT int32_t lePieChartWidget_GetStartAngle(lePieChartWidget* chart);

// *****************************************************************************
/* Function:
    leResult lePieChartWidget_SetStartAngle(lePieChartWidget* chart, int32_t angle)

  Summary:
    Sets the start angle of a chart widget

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    int32_t angle - the desired start angle value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_SetStartAngle(lePieChartWidget* chart, int32_t angle);

// *****************************************************************************
/* Function:
    int32_t lePieChartWidget_GetCenterAngle(lePieChartWidget* chart)

  Summary:
    Sets the center angle of the chart widget

  Description:


  Parameters:
    lePieChartWidget* chart - the widget

  Returns:
    int32_t

  Remarks:

*/
LIB_EXPORT int32_t lePieChartWidget_GetCenterAngle(lePieChartWidget* chart);

// *****************************************************************************
/* Function:
    leResult lePieChartWidget_SetCenterAngle(lePieChartWidget* chart, int32_t angle)

  Summary:
    Sets the center angle of the chart widget

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    int32_t angle - the desired center angle value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_SetCenterAngle(lePieChartWidget* chart, int32_t angle);

// *****************************************************************************
/* Function:
    leResult lePieChartWidget_AddEntry(lePieChartWidget* chart, int32_t * index)

  Summary:
    Adds an entry to the pie chart

  Description:
    The entry is always added to the end of the set. The index of the new entry
    is returned thru the index parameter.

  Parameters:
    lePieChartWidget* chart - the widget
    int32_t * index - returns the index of the entry

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_AddEntry(lePieChartWidget* chart, int32_t * index);

// *****************************************************************************
/* Function:
    leResult lePieChartWidget_DeleteEntries(lePieChartWidget* chart)

  Summary:
    Deletes ALL the data in the pie chart

  Description:

  Parameters:
    lePieChartWidget* chart - the widget

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_DeleteEntries(lePieChartWidget* chart);

// *****************************************************************************
/* Function:
    uint32_t lePieChartWidget_GetEntryValue(lePieChartWidget* chart, uint32_t index)

  Summary:
    Returns the value of the entry at the specified index

  Description:

  Parameters:
    lePieChartWidget* chart - the widget
    uint32_t index - the entry index

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t lePieChartWidget_GetEntryValue(lePieChartWidget* chart, uint32_t index);

// *****************************************************************************
/* Function:
    leResult lePieChartWidget_SetEntryValue(lePieChartWidget* chart, uint32_t index, uint32_t value)

  Summary:
    Sets the value of an entry at index

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    uint32_t index - entry index
    uint32_t value - entry value

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_SetEntryValue(lePieChartWidget* chart, uint32_t index, uint32_t value);

// *****************************************************************************
/* Function:
    uint32_t lePieChartWidget_GetEntryRadius(lePieChartWidget* chart, uint32_t index)

  Summary:
    Returns the radius of the entry at the specified index

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    uint32_t index - the entry index

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t lePieChartWidget_GetEntryRadius(lePieChartWidget* chart, uint32_t index);

// *****************************************************************************
/* Function:
    leResult lePieChartWidget_SetEntryRadius(lePieChartWidget* chart, uint32_t index, uint32_t rad)

  Summary:
    Sets the radius of an entry at index

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    uint32_t index - entry index
    uint32_t rad - entry radius

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_SetEntryRadius(lePieChartWidget* chart, uint32_t index, uint32_t rad);

// *****************************************************************************
/* Function:
    uint32_t lePieChartWidget_GetEntryOffset(lePieChartWidget* chart, uint32_t index)

  Summary:
    Returns the offset of the entry at the specified index

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    uint32_t index - the entry index

  Returns:
    uint32_t

  Remarks:

*/
LIB_EXPORT uint32_t lePieChartWidget_GetEntryOffset(lePieChartWidget* chart, uint32_t index);

// *****************************************************************************
/* Function:
    leResult lePieChartWidget_SetEntryOffset(lePieChartWidget* chart, uint32_t index, uint32_t offset)

  Summary:
    Sets the offset of an entry at index

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    uint32_t offset - entry offset
    uint32_t rad - entry radius

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_SetEntryOffset(lePieChartWidget* chart, uint32_t index, uint32_t offset);

// *****************************************************************************
/* Function:
    leScheme * lePieChartWidget_GetEntryScheme(lePieChartWidget* chart, uint32_t index)

  Summary:
    Returns the scheme of the entry at the specified index

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    uint32_t index - the entry index

  Returns:
    leScheme *

  Remarks:

*/
LIB_EXPORT leScheme * lePieChartWidget_GetEntryScheme(lePieChartWidget* chart, uint32_t index);

// *****************************************************************************
/* Function:
    leResult lePieChartWidget_SetEntryScheme(lePieChartWidget* chart, uint32_t index, uint32_t scheme)

  Summary:
    Sets the scheme of an entry at index

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    uint32_t scheme - entry scheme
    uint32_t rad - entry radius

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_SetEntryScheme(lePieChartWidget* chart, uint32_t index, leScheme * scheme);

// *****************************************************************************
/* Function:
    aResult lePieChartWidget_SetPressedEventCallback(lePieChartWidget* chart, lePieChartWidget_PressedEvent cb)

  Summary:
    Sets the function called when the chart is pressed/touched

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    lePieChartWidget_PressedEvent cb - callback function

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_SetPressedEventCallback(lePieChartWidget* chart, lePieChartWidget_PressedEvent cb);

// *****************************************************************************
/* Function:
    leResult lePieChartWidget_SetStringTable(lePieChartWidget* chart, leStringTable * stringTable)

  Summary:
    Sets the string table for the labels

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    leStringTable * stringTable - the string table to use

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_SetStringTable(lePieChartWidget * chart, leStringTable * stringTable);

// *****************************************************************************
/* Function:
    lePieChartWidget_SetLabelsStringID(lePieChartWidget* chart, uint32_t stringID)

  Summary:
    Sets the string asset for the labels

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    uint32_t stringID - the ID of the string asset to use for labels

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_SetLabelsStringID(lePieChartWidget* chart, uint32_t stringID);

// *****************************************************************************
/* Function:
    leBool lePieChartWidget_GetLabelsVisible(lePieChartWidget* chart)

  Summary:
    Returns LE_TRUE if the labels are shown, LE_FALSE if hidden

  Description:


  Parameters:
    lePieChartWidget* chart - the widget

  Returns:
    leBool

  Remarks:

*/
LIB_EXPORT leBool lePieChartWidget_GetLabelsVisible(lePieChartWidget* chart);

// *****************************************************************************
/* Function:
    leResult lePieChartWidget_SetLabelsVisible(lePieChartWidget* chart, leBool visible)

  Summary:
    Shows/hides the data entry labels

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    leBool visible

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_SetLabelsVisible(lePieChartWidget* chart, leBool visible);

// *****************************************************************************
/* Function:
    uint32_t lePieChartWidget_GetLabelsOffset(lePieChartWidget* chart)

  Summary:
    Gets the offsets of the labels from the center

  Description:


  Parameters:
    lePieChartWidget* chart - the widget

  Returns:
    uint32_t - the offset

  Remarks:

*/
LIB_EXPORT uint32_t lePieChartWidget_GetLabelsOffset(lePieChartWidget* chart);

// *****************************************************************************
/* Function:
    leResult lePieChartWidget_SetLabelsOffset(lePieChartWidget* chart, uint32_t offset)

  Summary:
    Sets the offsets of the labels from the center

  Description:


  Parameters:
    lePieChartWidget* chart - the widget
    uint32_t offset

  Returns:
    leResult - the operation result

  Remarks:

*/
LIB_EXPORT leResult lePieChartWidget_SetLabelsOffset(lePieChartWidget* chart, uint32_t offset);

#endif

#endif // LE_PIE_CHART_WIDGET_ENABLED
#endif /* LEGATO_WIDGET_PIE_CHART_H */