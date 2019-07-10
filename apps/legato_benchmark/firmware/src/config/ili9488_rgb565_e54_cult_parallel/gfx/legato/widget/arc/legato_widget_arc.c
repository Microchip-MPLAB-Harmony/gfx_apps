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

#include "gfx/legato/widget/arc/legato_widget_arc.h"

#if LE_ARC_WIDGET_ENABLED == 1

#include <string.h>

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
#define DEFAULT_START_ANGLE     0
#define DEFAULT_CENTER_ANGLE    135
#define DEFAULT_THICKNESS       20

static leArcWidgetVTable arcWidgetVTable;

/* base class constructor and destructor */
void _leWidget_Constructor(leWidget* _this);


void _leArcWidget_Constructor(leArcWidget* _this)
{
    LE_ASSERT_THIS();
    
    /* call base class constructor */
    leWidget_Constructor((leWidget*)_this);

    _this->widget.fn = (void*)&arcWidgetVTable;
    _this->fn = &arcWidgetVTable;

    _this->widget.type = LE_WIDGET_ARC;
    
    //_this->widget.destructor = (leWidget_Destructor_FnPtr)&_leArcWidget_Destructor;

    // override base class methods
    //_this->widget.paint = (leWidget_Paint_FnPtr)&_leArcWidget_Paint;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_NONE;

    _this->radius = DEFAULT_RADIUS;
    _this->startAngle = DEFAULT_START_ANGLE;
    _this->centerAngle = DEFAULT_CENTER_ANGLE;
    _this->thickness = DEFAULT_THICKNESS;
    _this->endAngle = _this->startAngle +  _this->centerAngle;
    
    _this->roundEdge = LE_FALSE;
}

void _leWidget_Destructor(leWidget* _this);

void _leArcWidget_Destructor(leArcWidget* _this)
{
    /* call base class destructor */
    _leWidget_Destructor((leWidget*)_this);
}

leArcWidget* leArcWidget_New()
{
    leArcWidget* wgt = NULL;

    wgt = LE_MALLOC(sizeof(leArcWidget));

    if(wgt == NULL)
        return NULL;
    
    _leArcWidget_Constructor(wgt);

    return wgt;
}

static uint32_t getRadius(const leArcWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->radius;
}

static leResult setRadius(leArcWidget* _this,
                          uint32_t rad)
{
    LE_ASSERT_THIS();
    
    if(_this->radius == rad)
        return LE_SUCCESS;
        
    _this->radius = rad;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static int32_t getStartAngle(const leArcWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->startAngle;
}

static leResult setStartAngle(leArcWidget* _this,
                              int32_t angle)
{
    LE_ASSERT_THIS();
    
    if(_this->startAngle == angle)
        return LE_SUCCESS;
        
    _this->startAngle = angle;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getThickness(const leArcWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->thickness;
}

static leResult setThickness(leArcWidget* _this,
                             uint32_t thickness)
{
    LE_ASSERT_THIS();
    
    if (thickness > _this->radius)
        return LE_FAILURE;

    if(_this->thickness == thickness)
        return LE_SUCCESS;
        
    _this->thickness = thickness;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static int32_t getCenterAngle(const leArcWidget* _this)
{

    LE_ASSERT_THIS();
    return _this->centerAngle;
}

static leResult setCenterAngle(leArcWidget* _this,
                               int32_t angle)
{
    LE_ASSERT_THIS();
    
    if(_this->centerAngle == angle)
        return LE_SUCCESS;
        
    _this->centerAngle = angle;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leBool getRoundEdge(const leArcWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->roundEdge;
}

static leResult setRoundEdge(leArcWidget* _this,
                             leBool round)
{
    LE_ASSERT_THIS();
    
    _this->roundEdge = round;
    
    return LE_SUCCESS;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leArcWidget_Paint(leArcWidget* _this);

void _leArcWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&arcWidgetVTable);
    
    /* overrides from base class */
    arcWidgetVTable._destructor = _leArcWidget_Destructor;
    arcWidgetVTable._paint = _leArcWidget_Paint;
    
    /* member functions */
    arcWidgetVTable.getRadius = getRadius;
    arcWidgetVTable.setRadius = setRadius;
    arcWidgetVTable.getStartAngle = getStartAngle;
    arcWidgetVTable.setStartAngle = setStartAngle;
    arcWidgetVTable.getThickness = getThickness;
    arcWidgetVTable.setThickness = setThickness;
    arcWidgetVTable.getCenterAngle = getCenterAngle;
    arcWidgetVTable.setCenterAngle = setCenterAngle;
    arcWidgetVTable.getRoundEdge = getRoundEdge;
    arcWidgetVTable.setRoundEdge = setRoundEdge;
}

void _leArcWidget_FillVTable(leArcWidgetVTable* tbl)
{
    *tbl = arcWidgetVTable;
}

#endif // LE_ARC_WIDGET_ENABLED