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

#include "gfx/legato/widget/circle/legato_widget_circle.h"

#if LE_CIRCLE_WIDGET_ENABLED == 1

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           101
#define DEFAULT_HEIGHT          101

#define DEFAULT_ORIGIN_X        50
#define DEFAULT_ORIGIN_Y        50

#define DEFAULT_RADIUS          50

static leCircleWidgetVTable circleWidgetVTable;

void _leCircleWidget_Constructor(leCircleWidget* _this)
{
    LE_ASSERT_THIS();
    
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&circleWidgetVTable;
    _this->fn = &circleWidgetVTable;

    _this->widget.type = LE_WIDGET_CIRCLE;
    
    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_NONE;

    _this->x = DEFAULT_ORIGIN_X;
    _this->y = DEFAULT_ORIGIN_Y;
    _this->radius = DEFAULT_RADIUS;
}

void _leWidget_Destructor(leWidget* wgt);

void _leCircleWidget_Destructor(leCircleWidget* _this)
{
    LE_ASSERT_THIS();
    
    _leWidget_Destructor((leWidget*)_this);
}

leCircleWidget* leCircleWidget_New()
{
    leCircleWidget* cir = NULL;

    cir = LE_MALLOC(sizeof(leCircleWidget));

    if(cir == NULL)
        return NULL;
    
    _leCircleWidget_Constructor(cir);

    return cir;
}

static lePoint getOrigin(const leCircleWidget* _this)
{
    lePoint pnt;
    
    LE_ASSERT_THIS();
    
    pnt.x = _this->x;
    pnt.y = _this->y;
        
    return pnt;
}

static leResult setOrigin(leCircleWidget* _this,
                          lePoint org)
{
    LE_ASSERT_THIS();
        
    if(_this->x == org.x && _this->y == org.y)
        return LE_SUCCESS;
        
    _this->x = org.x;
    _this->y = org.y;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static int32_t getOriginX(const leCircleWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->x;
}

static leResult setOriginX(leCircleWidget* _this,
                           int32_t x)
{
    LE_ASSERT_THIS();
        
    if(_this->x == x)
        return LE_SUCCESS;
        
    _this->x = x;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static int32_t getOriginY(const leCircleWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->y;
}

static leResult setOriginY(leCircleWidget* _this,
                           int32_t y)
{
    LE_ASSERT_THIS();
        
    if(_this->y == y)
        return LE_SUCCESS;
        
    _this->y = y;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getRadius(const leCircleWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->radius;
}

static leResult setRadius(leCircleWidget* _this,
                          uint32_t rad)
{
    LE_ASSERT_THIS();
        
    if(_this->radius == rad)
        return LE_SUCCESS;
        
    _this->radius = rad;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getThickness(const leCircleWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->thickness;
}

static leResult setThickness(leCircleWidget* _this,
                             uint32_t thickness)
{
    LE_ASSERT_THIS();
    
    if(thickness < 1)
        return LE_FAILURE;
        
    if(_this->thickness == thickness)
        return LE_SUCCESS;
        
    _this->thickness = thickness;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leBool getFilled(const leCircleWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->filled;
}

static leResult setFilled(leCircleWidget* _this,
                          leBool filled)
{
    LE_ASSERT_THIS();
        
    if(_this->filled == filled)
        return LE_SUCCESS;
        
    _this->filled = filled;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leCircleWidget_Paint(leCircleWidget* _this);

void _leCircleWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&circleWidgetVTable);
    
    /* overrides from base class */
    circleWidgetVTable._destructor = _leCircleWidget_Destructor;
    circleWidgetVTable._paint = _leCircleWidget_Paint;
    
    /* member functions */
    circleWidgetVTable.getOrigin = getOrigin;
    circleWidgetVTable.setOrigin = setOrigin;
    circleWidgetVTable.getOriginX = getOriginX;
    circleWidgetVTable.setOriginX = setOriginX;
    circleWidgetVTable.getOriginY = getOriginY;
    circleWidgetVTable.setOriginY = setOriginY;
    circleWidgetVTable.getRadius = getRadius;
    circleWidgetVTable.setRadius = setRadius;
    circleWidgetVTable.getThickness = getThickness;
    circleWidgetVTable.setThickness = setThickness;
    circleWidgetVTable.getFilled = getFilled;
    circleWidgetVTable.setFilled = setFilled;
}

void _leCircleWidget_FillVTable(leCircleWidgetVTable* tbl)
{
    *tbl = circleWidgetVTable;
}

#endif // LE_CIRCLE_WIDGET_ENABLED