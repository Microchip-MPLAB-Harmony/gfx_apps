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

#include "gfx/legato/widget/touchtest/legato_widget_touchtest.h"

#if LE_TOUCHTEST_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

static leTouchTestWidgetVTable touchTestWidgetVTable;

void _leTouchTestWidget_GetLineRects(const leTouchTestWidget* _this,
                                     uint32_t idx,
                                     leRect* horzRect,
                                     leRect* vertRect);

void leTouchTestWidget_Constructor(leTouchTestWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&touchTestWidgetVTable;
    _this->fn = &touchTestWidgetVTable;
    
    _this->widget.type = LE_WIDGET_TOUCHTEST;
    _this->state = LE_TOUCHTEST_STATE_UP;

    // override base class methods
    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_FILL;
    
    _this->size = 0;
    _this->start = 0;
    _this->next = 0;

    _this->cb = NULL;
}

void _leWidget_Destructor(leWidget* wgt);

static void destructor(leTouchTestWidget* _this)
{
    _leWidget_Destructor((leWidget*)_this);
}

/*void _leTouchTestWidget_Update(leTouchTestWidget* _this)
{

}*/

leTouchTestWidget* leTouchTestWidget_New()
{
    leTouchTestWidget* tch = NULL;

    tch = LE_MALLOC(sizeof(leTouchTestWidget));

    if(tch == NULL)
        return NULL;
    
    leTouchTestWidget_Constructor(tch);

    return tch;
}

static leResult addPoint(leTouchTestWidget* _this,
                         lePoint* pnt)
{
    LE_ASSERT_THIS();
        
    if(_this->size > 0 && _this->next == _this->start)
    {
        _this->start++;
    }
       
    if(_this->size < LE_TOUCHTEST_MEMORY_SIZE)
    {
        _this->size++;
    }
        
    _this->pnts[_this->next] = *pnt;
    
    //printf("adding point %i: %i, %i\n", _this->next, pnt->x, pnt->y);
        
    _this->next += 1;
    
    if(_this->next >= LE_TOUCHTEST_MEMORY_SIZE)
    {
        _this->next = 0;
    }
        
    if(_this->cb != NULL)
    {
        _this->cb(_this, pnt);
    }

    _this->fn->invalidate(_this);

    return LE_SUCCESS;
}

static leResult clearPoints(leTouchTestWidget* _this)
{
    LE_ASSERT_THIS();

    _this->start = 0;
    _this->size = 0;
    _this->next = 0;

    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leTouchTestWidget_PointAddedEventCallback getPointAddedEventCallback(const leTouchTestWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->cb;
}

static leResult setPointAddedEventCallback(leTouchTestWidget* _this,
                                           leTouchTestWidget_PointAddedEventCallback cb)
{
    LE_ASSERT_THIS();

    _this->cb = cb;
    
    return LE_SUCCESS;
}

static void handleTouchDownEvent(leTouchTestWidget* _this,
                                 leWidgetEvent_TouchDown* evt)
{
    lePoint pnt;
    
    LE_ASSERT_THIS();
    
    pnt.x = evt->x;
    pnt.y = evt->y;

    leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);

    _this->state = LE_TOUCHTEST_STATE_DOWN;
    
    leUtils_PointScreenToLocalSpace((leWidget*)_this, &pnt);
    
    addPoint(_this, &pnt);

    //printf("_this touch down\n");
}

static void handleTouchUpEvent(leTouchTestWidget* _this,
                               leWidgetEvent_TouchUp* evt)
{
    LE_ASSERT_THIS();

    leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);
    _this->state = LE_TOUCHTEST_STATE_UP;

    //printf("_this touch up\n");
    
    _this->fn->clearPoints(_this);
}

static void handleTouchMovedEvent(leTouchTestWidget* _this,
                                  leWidgetEvent_TouchMove* evt)
{
    leRect rect;
    lePoint pnt;
    
    LE_ASSERT_THIS();
    
    rect = _this->fn->rectToScreen(_this);

    pnt.x = evt->x;
    pnt.y = evt->y;

    leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);

    if(leRectContainsPoint(&rect, &pnt) == LE_TRUE)
    {
        leUtils_PointScreenToLocalSpace((leWidget*)_this, &pnt);
        
        _this->fn->addPoint(_this, &pnt);
    }
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leTouchTestWidget_Paint(leTouchTestWidget* _this);

void _leTouchTestWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&touchTestWidgetVTable);
    
    /* overrides from base class */
    touchTestWidgetVTable._destructor = destructor;
    touchTestWidgetVTable._paint = _leTouchTestWidget_Paint;
    touchTestWidgetVTable.touchDownEvent = handleTouchDownEvent;
    touchTestWidgetVTable.touchUpEvent = handleTouchUpEvent;
    touchTestWidgetVTable.touchMoveEvent = handleTouchMovedEvent;
    
    /* member functions */
    touchTestWidgetVTable.addPoint = addPoint;
    touchTestWidgetVTable.clearPoints = clearPoints;
    touchTestWidgetVTable.getPointAddedEventCallback = getPointAddedEventCallback;
    touchTestWidgetVTable.setPointAddedEventCallback = setPointAddedEventCallback;
}

void _leTouchTestWidget_FillVTable(leTouchTestWidgetVTable* tbl)
{
    *tbl = touchTestWidgetVTable;
}

#endif // LE_TOUCHTEST_WIDGET_ENABLED