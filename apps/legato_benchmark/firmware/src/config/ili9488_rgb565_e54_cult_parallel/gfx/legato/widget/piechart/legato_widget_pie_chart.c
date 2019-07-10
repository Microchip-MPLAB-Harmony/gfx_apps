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

#include "gfx/legato/widget/piechart/legato_widget_pie_chart.h"

#if LE_PIECHART_WIDGET_ENABLED == 1

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_math.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_fixedstring.h"
#include "gfx/legato/widget/legato_widget.h"


#define DEFAULT_WIDTH           101
#define DEFAULT_HEIGHT          101

#define DEFAULT_RADIUS          50
#define DEFAULT_LABEL_OFFSET    40
#define DEFAULT_START_ANGLE     0
#define DEFAULT_CENTER_ANGLE    180
#define DEFAULT_VALUE           10

static lePieChartWidgetVTable pieChartWidgetVTable;

void lePieChartWidget_Constructor(lePieChartWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&pieChartWidgetVTable;
    _this->fn = &pieChartWidgetVTable;

    _this->widget.type = LE_WIDGET_ARC;
    
    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_NONE;

    _this->startAngle = DEFAULT_START_ANGLE;
    _this->centerAngle = DEFAULT_CENTER_ANGLE;
    
    _this->labelsVisible = LE_TRUE;
    _this->labelsOffset = DEFAULT_LABEL_OFFSET;
    
    leArray_Create(&_this->pieArray);
}

void _leWidget_Destructor(leWidget* _this);

static void destructor(lePieChartWidget* _this)
{
    _this->fn->clear(_this);
    
    _leWidget_Destructor((leWidget*)_this);
}

lePieChartWidget* lePieChartWidget_New()
{
    lePieChartWidget* chart = NULL;

    chart = LE_MALLOC(sizeof(lePieChartWidget));

    if(chart == NULL)
        return NULL;
    
    lePieChartWidget_Constructor(chart);

    return chart;
}

static int32_t getStartAngle(const lePieChartWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->startAngle;
}

static leResult setStartAngle(lePieChartWidget* _this,
                              int32_t angle)
{
    LE_ASSERT_THIS();
        
    if(_this->startAngle == angle)
        return LE_SUCCESS;
        
    _this->startAngle = angle;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static int32_t getCenterAngle(const lePieChartWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->centerAngle;
}

static leResult setCenterAngle(lePieChartWidget* _this,
                               int32_t angle)
{
    LE_ASSERT_THIS();

    if(_this->centerAngle == angle)
        return LE_SUCCESS;
        
    _this->centerAngle = angle;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static int32_t addEntry(lePieChartWidget* _this)
{
    lePieChartPie* pie;
    
    LE_ASSERT_THIS();
    
    pie = LE_MALLOC(sizeof(lePieChartPie));
    
    if(pie == NULL)
        return LE_FAILURE;
    
    pie->offset = 0;
    pie->radius = DEFAULT_RADIUS;
    pie->scheme = _this->fn->getScheme(_this);
    pie->value = DEFAULT_VALUE;
    
    if(leArray_PushBack(&_this->pieArray, pie) == LE_FAILURE)
    {
        LE_FREE(pie);
        
        return -1;
    }
    
    _this->fn->invalidate(_this);
    
    return _this->pieArray.size - 1;
}

static leResult clear(lePieChartWidget* _this)
{
    uint32_t i;
    
    for(i = 0; i < _this->pieArray.size; i++)
    {
        LE_FREE(_this->pieArray.values[i]);
    }
    
    leArray_Clear(&_this->pieArray);

    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getEntryValue(const lePieChartWidget* _this,
                              int32_t index)
{
    lePieChartPie* pie;
    
    LE_ASSERT_THIS();
    
    pie = (lePieChartPie*)leArray_Get(&_this->pieArray, index);
    
    if(pie == NULL)
        return 0;
    
    return pie->value;
}

static leResult setEntryValue(lePieChartWidget* _this,
                              int32_t index,
                              uint32_t value)
{
    lePieChartPie* pie;
    
    LE_ASSERT_THIS();
        
    pie = (lePieChartPie*)leArray_Get(&_this->pieArray, index);
    
    if(pie == NULL)
        return LE_FAILURE;
    
    if(pie->value == value)
        return LE_SUCCESS;
    
    pie->value = value;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getEntryRadius(const lePieChartWidget* _this,
                               int32_t index)
{
    lePieChartPie* pie;
    
    LE_ASSERT_THIS();
    
    pie = (lePieChartPie*)leArray_Get(&_this->pieArray, index);
    
    if(pie == NULL)
        return 0;
    
    return pie->radius;
}

static leResult setEntryRadius(lePieChartWidget* _this,
                               int32_t index,
                               uint32_t rad)
{
    lePieChartPie* pie;
    
    LE_ASSERT_THIS();
        
    pie = (lePieChartPie*)leArray_Get(&_this->pieArray, index);
    
    if(pie == NULL)
        return LE_FAILURE;
    
    if(pie->radius == rad)
        return LE_SUCCESS;
    
    pie->radius = rad;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getEntryOffset(const lePieChartWidget* _this,
                               int32_t index)
{
    lePieChartPie* pie;
    
    LE_ASSERT_THIS();
    
    pie = (lePieChartPie*)leArray_Get(&_this->pieArray, index);
    
    if(pie == NULL)
        return 0;
    
    return pie->offset;
}

static leResult setEntryOffset(lePieChartWidget* _this,
                               int32_t index,
                               uint32_t offset)
{
    lePieChartPie* pie;
    
    LE_ASSERT_THIS();
        
    pie = (lePieChartPie*)leArray_Get(&_this->pieArray, index);
    
    if(pie == NULL)
        return LE_FAILURE;
    
    if(pie->offset == offset)
        return LE_SUCCESS;
    
    pie->offset = offset;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leScheme* getEntryScheme(const lePieChartWidget* _this,
                                int32_t index)
{
    lePieChartPie* pie;
    
    LE_ASSERT_THIS();
    
    pie = (lePieChartPie*)leArray_Get(&_this->pieArray, index);
    
    if(pie == NULL)
        return 0;
    
    return (leScheme*)pie->scheme;
}

static leResult setEntryScheme(lePieChartWidget* _this, 
                               int32_t index,
                               const leScheme* scheme)
{
    lePieChartPie* pie;
    
    LE_ASSERT_THIS();
        
    pie = (lePieChartPie*)leArray_Get(&_this->pieArray, index);
    
    if(pie == NULL)
        return LE_FAILURE;
    
    if(pie->scheme == scheme)
        return LE_SUCCESS;
    
    pie->scheme = scheme;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static lePieChartWidget_PressedEvent getPressedEventCallback(const lePieChartWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->pressedCallback;
}

static leResult setPressedEventCallback(lePieChartWidget* _this,
                                        lePieChartWidget_PressedEvent cb)
{
    LE_ASSERT_THIS();

    _this->pressedCallback = cb;
        
    return LE_SUCCESS;
}

static leFont* getLabelFont(const lePieChartWidget* _this)
{
    LE_ASSERT_THIS();
    
    return (leFont*)_this->labelFont;
}

static leResult setLabelFont(lePieChartWidget* _this,
                             const leFont* fnt)
{
    LE_ASSERT_THIS();
        
    _this->labelFont = fnt;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leBool getLabelsVisible(const lePieChartWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->labelsVisible;
}

static leResult setLabelsVisible(lePieChartWidget* _this, 
                                 leBool visible)
{
    LE_ASSERT_THIS();

    if(_this->labelsVisible == visible)
        return LE_SUCCESS;

    _this->labelsVisible = visible;

    _this->fn->invalidate(_this);

    return LE_SUCCESS;
}

static uint32_t getLabelsOffset(const lePieChartWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->labelsOffset;
}

static leResult setLabelsOffset(lePieChartWidget* _this, 
                                uint32_t offset)
{
    LE_ASSERT_THIS();

    if(_this->labelsOffset == offset)
        return LE_SUCCESS;

    _this->labelsOffset = offset;

    _this->fn->invalidate(_this);

    return LE_SUCCESS;
}

static int32_t _getPieIndexAtPoint(lePieChartWidget* _this,
                                   lePoint pnt)
{
    int32_t tempAngle, centerAngle;
    uint32_t pointAngle;
    uint32_t startAngle, endAngle;
    uint32_t i;
    uint32_t totalValue = 0;
    lePieChartPie* pie;

    tempAngle = _this->startAngle;
    
    while (tempAngle < 0)
    {
        tempAngle += 360;
    }

    startAngle = tempAngle;
    
    if(startAngle > 360)
    {
        startAngle %= 360;
    }

    if(pnt.x > 0 && pnt.y > 0)
    {
        //Q1
        pointAngle = (int32_t) ((double) leAtan((double) pnt.y / pnt.x) * (double)(180 / 3.1416));
    }
    else if(pnt.x < 0 && pnt.y > 0)
    {
        //Q2
        pointAngle = (int32_t) ((double) leAtan((double) pnt.y / pnt.x) * (double)(180 / 3.1416));
        pointAngle = 180 + pointAngle;
    }
    else if(pnt.x > 0 && pnt.y < 0)
    {
        //Q4
        pointAngle = (int32_t) ((double) leAtan((double) pnt.y / pnt.x) * (double)(180 / 3.1416));
        pointAngle = 360 + pointAngle;
    }
    else if(pnt.x < 0 && pnt.y < 0)
    {
        //Q3
        pointAngle = (int32_t) ((double) leAtan((double) pnt.y / pnt.x) * (double)(180 / 3.1416));
        pointAngle = 180 + pointAngle;
    }
    else if(pnt.x == 0 && pnt.y >= 0)
    {
        // +y
        pointAngle = 90;
    }
    else if(pnt.x == 0 && pnt.y < 0)
    {
        // -y
        pointAngle = 270;
    }
    else if(pnt.y == 0 && pnt.x > 0)
    {
        // +x
        pointAngle = 0;
    }
    else
    {
        // -x
        pointAngle = 180;
    }

    //Get the total
    for (i = 0; i < _this->pieArray.size; i++) 
    {
        pie = leArray_Get(&_this->pieArray, i);
        
        totalValue += pie->value;
    }

    //Test the angle if it's in a pie
    for (i = 0; i < _this->pieArray.size; i++) 
    {
        pie = leArray_Get(&_this->pieArray, i);

        if(_this->centerAngle < 0)
        {
            centerAngle = - ((int32_t) (((float) (-_this->centerAngle) * (float) pie->value)/(float) totalValue + 0.5));
            tempAngle = startAngle + centerAngle;

            while (tempAngle < 0)
            {
                tempAngle += 360;
            }

            endAngle = tempAngle;

            if(endAngle > 360)
            {
                endAngle %= 360;
            }
            
            if(startAngle >= endAngle)
            {
                if(pointAngle <= startAngle && pointAngle >= endAngle)
                {
                    if(((uint32_t) ((pnt.y * pnt.y) + (pnt.x * pnt.x)) <= 
                        (pie->radius + pie->offset) * (pie->radius + pie->offset)))
                    {
                        return i;
                    }
                }
            }
            //Pie overlaps the 0-deg axis
            else
            {
                if(pointAngle <= startAngle || pointAngle >= endAngle)
                {
                    if(((uint32_t) ((pnt.y * pnt.y) + (pnt.x * pnt.x)) <= 
                        (pie->radius + pie->offset) * (pie->radius + pie->offset)))
                    {
                        return i;
                    }
                }
            }
        }
        else
        {
            centerAngle = (int32_t) (((float) (_this->centerAngle) * (float) pie->value)/(float) totalValue + 0.5);
            endAngle = startAngle + centerAngle;

            if(endAngle > 360)
                endAngle %= 360;

            if(startAngle <= endAngle)
            {
                if(pointAngle <= endAngle && 
                    pointAngle >= startAngle)
                {
                    if(((uint32_t) ((pnt.y * pnt.y) + (pnt.x * pnt.x)) <= 
                        (pie->radius + pie->offset) * (pie->radius + pie->offset)))
                    {
                        return i;
                    }
                }
            }
            //Pie overlaps the 0-deg axis
            else
            {
                if(pointAngle <= endAngle || pointAngle >= startAngle)
                {
                    if(((uint32_t) ((pnt.y * pnt.y) + (pnt.x * pnt.x)) <= 
                        (pie->radius + pie->offset) * (pie->radius + pie->offset)))
                    {
                        return i;
                    }
                }
            }
        }

        startAngle = endAngle;
    } 

    return -1;
    
}

static void handleTouchDownEvent(lePieChartWidget* _this,
                                 leWidgetEvent_TouchDown* evt)
{
    lePoint pnt;
    int32_t index;

    pnt.x = evt->x;
    pnt.y = evt->y;

    //Adjust point relative to widget local
    leUtils_PointScreenToLocalSpace((leWidget*)_this, &pnt);

    //Adjust point relative widget center/origin
    pnt.x -= _this->widget.rect.width/2 ; 
    pnt.y = _this->widget.rect.height/2 - pnt.y;

    index = _getPieIndexAtPoint(_this, pnt);
    
    if(index != -1)
    {
        leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);
        
        if(_this->pressedCallback != NULL)  
        {
            _this->pressedCallback(_this, index);
        }    
    }
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _lePieChartWidget_Paint(lePieChartWidget* _this);

void _lePieChartWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&pieChartWidgetVTable);
    
    /* overrides from base class */
    pieChartWidgetVTable._destructor = destructor;
    pieChartWidgetVTable._paint = _lePieChartWidget_Paint;
    pieChartWidgetVTable.touchDownEvent = handleTouchDownEvent;
    
    /* member functions */
    pieChartWidgetVTable.getStartAngle = getStartAngle;
    pieChartWidgetVTable.setStartAngle = setStartAngle;
    pieChartWidgetVTable.getCenterAngle = getCenterAngle;
    pieChartWidgetVTable.setCenterAngle = setCenterAngle;
    pieChartWidgetVTable.addEntry = addEntry;
    pieChartWidgetVTable.clear = clear;
    pieChartWidgetVTable.getEntryValue = getEntryValue;
    pieChartWidgetVTable.setEntryValue = setEntryValue;
    pieChartWidgetVTable.getEntryRadius = getEntryRadius;
    pieChartWidgetVTable.setEntryRadius = setEntryRadius;
    pieChartWidgetVTable.getEntryOffset = getEntryOffset;
    pieChartWidgetVTable.setEntryOffset = setEntryOffset;
    pieChartWidgetVTable.getEntryScheme = getEntryScheme;
    pieChartWidgetVTable.setEntryScheme = setEntryScheme;
    pieChartWidgetVTable.getPressedEventCallback = getPressedEventCallback;
    pieChartWidgetVTable.setPressedEventCallback = setPressedEventCallback;
    pieChartWidgetVTable.getLabelFont = getLabelFont;
    pieChartWidgetVTable.setLabelFont = setLabelFont;
    pieChartWidgetVTable.getLabelsVisible = getLabelsVisible;
    pieChartWidgetVTable.setLabelsVisible = setLabelsVisible;
    pieChartWidgetVTable.getLabelsOffset = getLabelsOffset;
    pieChartWidgetVTable.setLabelsOffset = setLabelsOffset;
}

void _lePieChartWidget_FillVTable(lePieChartWidgetVTable* tbl)
{
    *tbl = pieChartWidgetVTable;
}

#endif // LE_PIECHART_WIDGET_ENABLED