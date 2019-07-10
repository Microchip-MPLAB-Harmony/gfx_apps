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

#include "gfx/legato/widget/slider/legato_widget_slider.h"

#if LE_SLIDER_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_math.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/widget/legato_widget.h"


#define DEFAULT_WIDTH           20
#define DEFAULT_HEIGHT          100

#define DEFAULT_MIN             0
#define DEFAULT_MAX             100
#define DEFAULT_VALUE           0

#define DEFAULT_STEP            1
#define DEFAULT_GRIP            10

static leSliderWidgetVTable sliderWidgetVTable;

void _leSliderWidget_GetSlideAreaRect(const leSliderWidget* sld, leRect* rect);
void _leSliderWidget_GetHandleRect(const leSliderWidget* sld, leRect* rect);
void _leSliderWidget_InvalidateBorderAreas(const leSliderWidget* sld);

/*
static void invalidateSlideArea(leSliderWidget* _this)
{
    leRect rect;
    
    _leSliderWidget_GetSlideAreaRect(_this, &rect);
    
    leRenderer_DamageArea(leUtils_GetLayer((leWidget*)_this),
                          &rect,
                          LE_FALSE);
}*/

static void invalidateHandle(const leSliderWidget* _this)
{
    leRect rect;
    
    _leSliderWidget_GetHandleRect(_this, &rect);
    leUtils_RectToScreenSpace((leWidget*)_this, &rect);
    
    _this->fn->_damageArea(_this, &rect);
}

const uint32_t _getPercentFromPoint(const leSliderWidget* _this,
                                    const lePoint* pnt)
{
    leRect scrollRect;
    int32_t val;
    
    _leSliderWidget_GetSlideAreaRect(_this, &scrollRect);
    leUtils_RectToScreenSpace((leWidget*)_this, &scrollRect);

    if(_this->alignment == LE_ORIENTATION_VERTICAL)
    {
        // translate rect and point in to rect space
        val = scrollRect.height - (pnt->y - scrollRect.y);
        scrollRect.y = 0;
        
        if(val <= 0)
        {
            return 0;
        }
        else if(val >= scrollRect.height)
        {
            return 100;
        }
            
        return lePercentWholeRounded(val, scrollRect.height);
    }
    else
    {
        // translate rect and point in to rect space
        val = pnt->x - scrollRect.x;
        scrollRect.x = 0;
        
        if(val <= 0)
        {
            return 0;
        }
        else if(val >= scrollRect.width)
        {
            return 100;
        }
        
        return lePercentWholeRounded(val, scrollRect.width);
    }
}

static uint32_t _getValueFromPercent(const leSliderWidget* _this,
                                     uint32_t per)
{
    int32_t max, val;
    
    if(per == 0)
    {
        return _this->min;
    }
    else if(per == 100)
    {
        return _this->max;
    }
    
    // zero based range
    max = _this->max - _this->min;
    
    val = lePercentOf(max, per);
        
    return val - _this->min;
}

void leSliderWidget_Constructor(leSliderWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&sliderWidgetVTable;
    _this->fn = &sliderWidgetVTable;
    
    _this->widget.type = LE_WIDGET_SLIDER;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->state = LE_SLIDER_STATE_NONE;

    _this->widget.borderType = LE_WIDGET_BORDER_BEVEL;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_FILL;

    _this->alignment = LE_ORIENTATION_VERTICAL;
    
    _this->min = DEFAULT_MIN;
    _this->max = DEFAULT_MAX;
    _this->value = DEFAULT_VALUE;
    _this->grip = DEFAULT_GRIP;
}

void _leWidget_Destructor(leWidget* wgt);

static void destructor(leSliderWidget* _this)
{
    _leWidget_Destructor((leWidget*)_this);
}

leSliderWidget* leSliderWidget_New()
{
    leSliderWidget* sld = NULL;

    sld = LE_MALLOC(sizeof(leSliderWidget));
    
    leSliderWidget_Constructor(sld);

    return sld;
}

static leOrientation getOrientation(const leSliderWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->alignment;
}

static leResult setOrientation(leSliderWidget* _this,
                               leOrientation align,
                               leBool swapDimensions)
{
    uint32_t t;
    
    LE_ASSERT_THIS();
        
    if(_this->alignment == align)
        return LE_SUCCESS;

    _this->alignment = align;
    
    // reverse dimensions
    if(swapDimensions == LE_TRUE)
    {
        t = _this->widget.rect.width;
        _this->widget.rect.width = _this->widget.rect.height;
        _this->widget.rect.height = t;
    }
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static uint32_t getGripSize(const leSliderWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->grip;
}

static leResult setGripSize(leSliderWidget* _this,
                            uint32_t size)
{
    LE_ASSERT_THIS();
        
    if(_this->grip == size)
        return LE_SUCCESS;
        
    invalidateHandle(_this);
        
    _this->grip = size;
    
    invalidateHandle(_this);
        
    return LE_SUCCESS;
}

static uint32_t getMininumValue(const leSliderWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->min;
}

static leResult setMinimumValue(leSliderWidget* _this, 
                                uint32_t val)
{
    LE_ASSERT_THIS();
        
    if(_this->min == val)
        return LE_SUCCESS;
        
    invalidateHandle(_this);
        
    _this->min = val;
    
    invalidateHandle(_this);
    
    if(_this->valueChangedEvent != NULL)
    {
        _this->valueChangedEvent(_this);
    }
        
    return LE_SUCCESS;
}
                                                      
static uint32_t getMaximumValue(const leSliderWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->max;
}

static leResult setMaximumValue(leSliderWidget* _this,
                                uint32_t val)
{
    LE_ASSERT_THIS();
        
    if(_this->max == val)
        return LE_SUCCESS;
    
    invalidateHandle(_this);
   
    _this->max = val;
    
    invalidateHandle(_this);
        
    if(_this->valueChangedEvent != NULL)
    {
        _this->valueChangedEvent(_this);
    }
        
    return LE_SUCCESS;
}                                                 

static uint32_t getPercentage(const leSliderWidget* _this)
{
    LE_ASSERT_THIS();
        
    return lePercentWholeRounded(_this->value, _this->max - _this->min);
}

static leResult setPercentage(leSliderWidget* _this,
                              uint32_t val)
{
    uint32_t value;

    LE_ASSERT_THIS();

    value = lePercentOf(_this->max - _this->min, val) + _this->min;

    if(_this->value == value)
        return LE_SUCCESS;

    invalidateHandle(_this);

    _this->value = value;

    invalidateHandle(_this);

    if(_this->valueChangedEvent != NULL)
    {
        _this->valueChangedEvent(_this);
    }
    
    return LE_SUCCESS;
} 
                                                                                                               
static int32_t getValue(const leSliderWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->value;
}

static leResult setValue(leSliderWidget* _this,
                         int32_t val) 
{
    LE_ASSERT_THIS();
        
    if(_this->value == val)
        return LE_SUCCESS;
        
    if(val > _this->max)
    {
        val = _this->max;
    }
        
    if(val < _this->min)
    {
        val = _this->min;
    }
        
    invalidateHandle(_this); 
   
    _this->value = val;
    
    invalidateHandle(_this);
    
    if(_this->valueChangedEvent != NULL)
    {
        _this->valueChangedEvent(_this);
    }
        
    return LE_SUCCESS;
}

static leResult step(leSliderWidget* _this,
                     int32_t amount)
{
    LE_ASSERT_THIS();
    
    if(amount == 0)
        return LE_FAILURE;
    
    invalidateHandle(_this);
    
    if(amount < 0)
    {
        _this->value -= amount;
        
        if(_this->value < _this->min)
        {
            _this->value = _this->min;
        }
    }
    else
    {
        _this->value += amount;
        
        if(_this->value > _this->max)
        {
            _this->value = _this->max;
        }
    }
        
    if(_this->valueChangedEvent != NULL)
    {
        _this->valueChangedEvent(_this);
    }
        
    //printf("%u\n", _this->value);
        
    invalidateHandle(_this);
        
    return LE_SUCCESS;
}

static leSliderWidget_ValueChangedEvent getValueChangedEventCallback(const leSliderWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->valueChangedEvent;
}

static leResult setValueChangedEventCallback(leSliderWidget* _this,
                                             leSliderWidget_ValueChangedEvent cb)
{
    LE_ASSERT_THIS();
    
    if(_this->valueChangedEvent == cb)
        return LE_FAILURE;

    _this->valueChangedEvent = cb;
    
    return LE_SUCCESS;
}

static void handleTouchDownEvent(leSliderWidget* _this,
                                 leWidgetEvent_TouchDown* evt)
{
    leRect rect;
    lePoint pnt;
    uint32_t percent;
    uint32_t value;
    
    LE_ASSERT_THIS();

    pnt.x = evt->x;
    pnt.y = evt->y;
    
    // already guaranteed to be inside widget rectangle, accept event
    leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);
    
    // was the handle touched
    _leSliderWidget_GetHandleRect(_this, &rect);
    leUtils_RectToScreenSpace((leWidget*)_this, &rect);
    
    if(leRectContainsPoint(&rect, &pnt) == LE_TRUE)
    {
        _this->handleDownOffset.x = evt->x - rect.x - (rect.width / 2);
        _this->handleDownOffset.y = evt->y - rect.y - (rect.height / 2);
    }
    else
    {
        _this->handleDownOffset.x = 0;
        _this->handleDownOffset.y = 0;
        
        percent = _getPercentFromPoint(_this, &pnt);
        
        value = _getValueFromPercent(_this, percent);
        
        if(_this->value != value)
        {
            invalidateHandle(_this);
            
            _this->value = value;
            
            invalidateHandle(_this);
            
            if(_this->valueChangedEvent != NULL)
            {
                _this->valueChangedEvent(_this);
            }
        }
    }
    
    _this->state = LE_SLIDER_STATE_HANDLE_DOWN;
}

static void handleTouchUpEvent(leSliderWidget* _this,
                               leWidgetEvent_TouchUp* evt)
{
    LE_ASSERT_THIS();

    leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);
    
    _this->state = LE_SLIDER_STATE_NONE;
}

static void handleTouchMovedEvent(leSliderWidget* _this,
                                  leWidgetEvent_TouchMove* evt)
{
    lePoint pnt;
    uint32_t percent;
    
    LE_ASSERT_THIS();

    pnt.x = evt->x;
    pnt.y = evt->y;

    leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);

    if(_this->state == LE_SLIDER_STATE_HANDLE_DOWN)
    {
        pnt.x = evt->x - _this->handleDownOffset.x;
        pnt.y = evt->y - _this->handleDownOffset.y;
        
        //printf("%i, %i\n", pnt.x, pnt.y);
        
        percent = _getPercentFromPoint(_this, &pnt);
        
        //printf("%u\n", percent);
        
        percent = _getValueFromPercent(_this, percent);
        
        //printf("    %u, %u\n", percent, i);
        
        if(percent != _this->value)
        {
            invalidateHandle(_this);
            
            _this->value = percent;
            
            invalidateHandle(_this);
            
            if(_this->valueChangedEvent != NULL)
            {
                _this->valueChangedEvent(_this);
            }
        }
    }
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leSliderWidget_Paint(leSliderWidget* _this);

void _leSliderWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&sliderWidgetVTable);
    
    /* overrides from base class */
    sliderWidgetVTable._destructor = destructor;
    sliderWidgetVTable._paint = _leSliderWidget_Paint;
    sliderWidgetVTable._invalidateBorderAreas = _leSliderWidget_InvalidateBorderAreas;
    sliderWidgetVTable.touchDownEvent = handleTouchDownEvent;
    sliderWidgetVTable.touchUpEvent = handleTouchUpEvent;
    sliderWidgetVTable.touchMoveEvent = handleTouchMovedEvent;
    
    /* member functions */
    sliderWidgetVTable.getOrientation = getOrientation;
    sliderWidgetVTable.setOrientation = setOrientation;
    sliderWidgetVTable.getGripSize = getGripSize;
    sliderWidgetVTable.setGripSize = setGripSize;
    sliderWidgetVTable.getMininumValue = getMininumValue;
    sliderWidgetVTable.setMinimumValue = setMinimumValue;
    sliderWidgetVTable.getMaximumValue = getMaximumValue;
    sliderWidgetVTable.setMaximumValue = setMaximumValue;
    sliderWidgetVTable.getPercentage = getPercentage;
    sliderWidgetVTable.setPercentage = setPercentage;
    sliderWidgetVTable.getValue = getValue;
    sliderWidgetVTable.setValue = setValue;
    sliderWidgetVTable.step = step;
    sliderWidgetVTable.getValueChangedEventCallback = getValueChangedEventCallback;
    sliderWidgetVTable.setValueChangedEventCallback = setValueChangedEventCallback;
}

void _leSliderWidget_FillVTable(leSliderWidgetVTable* tbl)
{
    *tbl = sliderWidgetVTable;
}

#endif // LE_SLIDER_WIDGET_ENABLED