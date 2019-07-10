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

#include "gfx/legato/widget/circularslider/legato_widget_circular_slider.h"

#if LE_CIRCULARSLIDER_WIDGET_ENABLED == 1

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_math.h"
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
#define DEFAULT_START_VALUE     0
#define DEFAULT_END_VALUE       100
#define DEFAULT_VALUE           50

#define DEFAULT_DIRECTION       COUNTER_CLOCKWISE

#define DEFAULT_OUTSIDE_BORDER_THICKNESS    5
#define DEFAULT_INSIDE_BORDER_THICKNESS     5
#define DEFAULT_ACTIVE_ARC_THICKNESS        30
#define DEFAULT_SLIDER_BUTTON_THICKNESS     3
#define DEFAULT_SLIDER_BUTTON_RADIUS        15

//static void touchDown(leCircularSliderWidget* _this, leInput_TouchDownEvent* evt);
//static void touchUp(leCircularSliderWidget* _this, leInput_TouchUpEvent* evt);
//static void touchMoved(leCircularSliderWidget* _this, leInput_TouchMoveEvent* evt);

static leCircularSliderWidgetVTable circularSliderWidgetVTable;

//Returns the center point of the circle button in layer space
lePoint _leCircularSliderWidget_GetCircleCenterPointAtValue(leCircularSliderWidget* _this, int32_t value)
{
    //Determine start/end points of activeArc edge
    lePoint innerPoint, outerPoint, center, sliderPoint;
    int32_t valueEndAngle;
    int32_t valueCenterAngle;

    valueCenterAngle = (int32_t) ((value - _this->startValue)* _this->degPerUnit);

    sliderPoint.x = _this->widget.rect.width/2;
    sliderPoint.y = _this->widget.rect.height/2;
    
    leUtils_PointToScreenSpace((leWidget*)_this, &sliderPoint);

    if (_this->direction == CIRCULAR_SLIDER_DIR_COUNTER_CLOCKWISE)
    {
        valueEndAngle = _this->startAngle + valueCenterAngle;
    }
    else
    {
        valueEndAngle = 360 + _this->startAngle - valueCenterAngle; 
    }

    if (valueEndAngle < 0)
        valueEndAngle = -valueEndAngle;

    if (valueEndAngle > 360)
        valueEndAngle %= 360;

    lePolarToXY(_this->radius - _this->outsideBorderArc.thickness, valueEndAngle , &outerPoint);
    lePolarToXY((_this->radius - _this->outsideBorderArc.thickness - _this->activeArc.thickness), 
                valueEndAngle , 
                &innerPoint);

    center.x = sliderPoint.x + (innerPoint.x + ((outerPoint.x - innerPoint.x)/2));
    center.y = sliderPoint.y - (innerPoint.y + ((outerPoint.y - innerPoint.y)/2));

    return center;
}

void leCircularSliderWidget_Constructor(leCircularSliderWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&circularSliderWidgetVTable;
    _this->fn = &circularSliderWidgetVTable;

    _this->widget.type = LE_WIDGET_ARC;
    
    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_NONE;

    _this->radius = DEFAULT_RADIUS;
    _this->startAngle = DEFAULT_START_ANGLE;
    _this->startValue = DEFAULT_START_VALUE;
    _this->endValue = DEFAULT_END_VALUE;
    _this->value = DEFAULT_VALUE;

    _this->direction = CIRCULAR_SLIDER_DIR_COUNTER_CLOCKWISE;
    _this->roundEdges = LE_TRUE;
    _this->sticky = LE_TRUE;
    _this->buttonTouch = LE_TRUE;

    _this->outsideBorderArc.visible = LE_TRUE;
    _this->radius = DEFAULT_RADIUS;
    _this->outsideBorderArc.thickness = DEFAULT_OUTSIDE_BORDER_THICKNESS;
    _this->outsideBorderArc.startAngle = _this->startAngle;
    _this->outsideBorderArc.centerAngle = 360;
    _this->outsideBorderArc.scheme = _this->widget.scheme;

    _this->activeArc.visible = LE_TRUE;
    _this->activeArc.radius = _this->radius - _this->outsideBorderArc.thickness;
    _this->activeArc.thickness = DEFAULT_ACTIVE_ARC_THICKNESS;
    _this->activeArc.startAngle = _this->startAngle;
    _this->activeArc.centerAngle = 180;
    _this->activeArc.scheme = _this->widget.scheme;

    _this->inActiveArc.visible = LE_TRUE;
    _this->inActiveArc.radius = _this->activeArc.radius;
    _this->inActiveArc.thickness = _this->activeArc.thickness;
    _this->inActiveArc.startAngle = _this->activeArc.startAngle + _this->activeArc.centerAngle;
    _this->inActiveArc.centerAngle = 180;
    _this->inActiveArc.scheme = _this->widget.scheme;

    _this->insideBorderArc.visible = LE_TRUE;
    _this->insideBorderArc.radius = _this->activeArc.radius - _this->activeArc.thickness;
    _this->insideBorderArc.thickness = DEFAULT_INSIDE_BORDER_THICKNESS;
    _this->insideBorderArc.startAngle = _this->startAngle;
    _this->insideBorderArc.centerAngle = 360;
    _this->insideBorderArc.scheme = _this->widget.scheme;

    _this->circleButtonArc.visible = LE_TRUE;
    _this->circleButtonArc.radius = DEFAULT_SLIDER_BUTTON_RADIUS;
    _this->circleButtonArc.thickness = DEFAULT_SLIDER_BUTTON_THICKNESS;
    _this->circleButtonArc.startAngle = 0;
    _this->circleButtonArc.centerAngle = 360;
    _this->circleButtonArc.scheme = _this->widget.scheme;

    if (_this->endValue != _this->startValue)
    {
        _this->degPerUnit = (float) (360) / (float) (leAbsoluteValue(_this->endValue - _this->startValue));
    }
    else
    {
        _this->degPerUnit = 0;
    }
}

void _leWidget_Destructor(leWidget* _this);

void _leCircularSliderWidget_Destructor(leCircularSliderWidget* _this)
{
    _leWidget_Destructor((leWidget*)_this);
}

leCircularSliderWidget* leCircularSliderWidget_New()
{
    leCircularSliderWidget* slider = NULL;

    slider = LE_MALLOC(sizeof(leCircularSliderWidget));

    if(slider == NULL)
        return NULL;
    
    leCircularSliderWidget_Constructor(slider);

    return slider;
}

static uint32_t getRadius(const leCircularSliderWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->radius;
}

static leResult setRadius(leCircularSliderWidget* _this,
                          uint32_t rad)
{
    LE_ASSERT_THIS();
        
    if(_this->radius == rad)
        return LE_SUCCESS;
        
    if (_this->radius < (_this->outsideBorderArc.thickness + 
                         _this->activeArc.thickness + 
                         _this->insideBorderArc.thickness))
        return LE_FAILURE;

    _this->radius = rad;
    _this->radius = rad;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getStartAngle(const leCircularSliderWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->startAngle;
}

static leResult setStartAngle(leCircularSliderWidget* _this,
                              uint32_t angle)
{
    LE_ASSERT_THIS();
        
    if(_this->startAngle == angle)
        return LE_SUCCESS;

    if (angle > 360)
        angle = angle % 360;
    
    _this->startAngle = angle;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getStartValue(const leCircularSliderWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->startValue;
}

static leResult setStartValue(leCircularSliderWidget* _this,
                              uint32_t value)
{
    LE_ASSERT_THIS();
        
    if(_this->startValue == value)
        return LE_SUCCESS;

    if (value > _this->endValue)
        return LE_FAILURE;
        
    _this->startValue = value;

    if (_this->endValue != _this->startValue)
        _this->degPerUnit = (float) (360) / (float) (leAbsoluteValue(_this->endValue - _this->startValue));
    else
        _this->degPerUnit = 0;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getEndValue(const leCircularSliderWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->endValue;
}

static leResult setEndValue(leCircularSliderWidget* _this,
                            uint32_t value)
{
    LE_ASSERT_THIS();
        
    if(_this->endValue == value)
        return LE_SUCCESS;

    if (value < _this->startValue)
        return LE_FAILURE;
        
    _this->endValue = value;

    if (_this->endValue != _this->startValue)
    {
        _this->degPerUnit = (float) (360) / (float) (leAbsoluteValue(_this->endValue - _this->startValue));
    }
    else
    {
        _this->degPerUnit = 0;
    }
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getValue(const leCircularSliderWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->value;
}

static leRect _getDamagedRect(leCircularSliderWidget* _this,
                              uint32_t newValue)
{
    lePoint centerPtOld, centerPtNew;
    leRect rect, damagedRect = leRect_Zero, widgetRect;
    int32_t valueCenterAngleOld, valueCenterAngleNew, valueEndAngleOld, valueEndAngleNew;
    uint32_t offset = 0;
    uint32_t sliderThickness;
    leArcDir dir = LE_CCW;
    
    valueCenterAngleOld = (int32_t) ((_this->value - _this->startValue)* _this->degPerUnit);
    valueCenterAngleNew = (int32_t) ((newValue - _this->startValue)* _this->degPerUnit);
    
    if (_this->direction == CIRCULAR_SLIDER_DIR_COUNTER_CLOCKWISE)
    {
        valueEndAngleOld = _this->startAngle + valueCenterAngleOld;
        valueEndAngleNew = _this->startAngle + valueCenterAngleNew;
    }
    else
    {
        valueEndAngleOld = 360 + _this->startAngle - valueCenterAngleOld;
        valueEndAngleNew = 360 + _this->startAngle - valueCenterAngleNew;
    }

    if (valueEndAngleOld < 0)
        valueEndAngleOld = -valueEndAngleOld;

    if (valueEndAngleOld > 360)
        valueEndAngleOld %= 360;
    
    if (valueEndAngleNew < 0)
        valueEndAngleNew = -valueEndAngleNew;

    if (valueEndAngleNew > 360)
        valueEndAngleNew %= 360;    
    
    centerPtOld = _leCircularSliderWidget_GetCircleCenterPointAtValue(_this, _this->value);
    centerPtNew = _leCircularSliderWidget_GetCircleCenterPointAtValue(_this, newValue);
    
    sliderThickness = _this->outsideBorderArc.thickness +
        _this->activeArc.thickness + _this->insideBorderArc.thickness;
            
    if (_this->circleButtonArc.visible == LE_TRUE)
        offset = _this->circleButtonArc.radius;
    
    if (offset < sliderThickness/2)
        offset = sliderThickness/2;
    
    //Combine the rects for old and new value
    rect.x = centerPtOld.x - offset;
    rect.y = centerPtOld.y - offset;
    rect.width = rect.height = offset * 2;
    
    damagedRect = rect;
        
    rect.x = centerPtNew.x - offset;
    rect.y = centerPtNew.y - offset;
    rect.width = rect.height = offset * 2;
    
    damagedRect = leRectCombine(&damagedRect, &rect);
    
    //Combine the rects for traversed quadrants
    widgetRect = _this->fn->localRect(_this);
    leUtils_RectToScreenSpace((leWidget*)_this, &widgetRect);
    
    rect.width = _this->radius;
    rect.height = _this->radius;
    
    if (_this->direction == CIRCULAR_SLIDER_DIR_COUNTER_CLOCKWISE)
    {
        if (newValue < _this->value)
        {
            dir = LE_CW;
        }
        else
        {
            dir = LE_CCW;
        }
    }
    else
    {    
        if (newValue < _this->value)
        {
            dir = LE_CCW;
        }
        else
        {
            dir = LE_CW;
        }
    }
        
    if (leArcsOverlapQuadrant(valueEndAngleOld, 
                              valueEndAngleNew, 
                              dir,
                              LE_Q1) == LE_TRUE)
    {
        rect.x = widgetRect.x + widgetRect.width / 2;
        rect.y = widgetRect.y + widgetRect.height / 2 - _this->radius;
        
        damagedRect = leRectCombine(&damagedRect, &rect);
    }
        
    if (leArcsOverlapQuadrant(valueEndAngleOld, 
                              valueEndAngleNew, 
                              dir,
                              LE_Q2) == LE_TRUE)
    {
        rect.x = widgetRect.x + widgetRect.width / 2 - _this->radius;
        rect.y = widgetRect.y + widgetRect.height / 2 - _this->radius;
        
        damagedRect = leRectCombine(&damagedRect, &rect);
    }
        
    if (leArcsOverlapQuadrant(valueEndAngleOld, 
                              valueEndAngleNew, 
                              dir,
                              LE_Q3) == LE_TRUE)
    {   
        rect.x = widgetRect.x + widgetRect.width / 2 - _this->radius;
        rect.y = widgetRect.y + widgetRect.height / 2;
        
        damagedRect = leRectCombine(&damagedRect, &rect);
    }
        
    if (leArcsOverlapQuadrant(valueEndAngleOld, 
                              valueEndAngleNew, 
                              dir,
                              LE_Q4) == LE_TRUE)

    {
        rect.x = widgetRect.x + widgetRect.width / 2;
        rect.y = widgetRect.y + widgetRect.height / 2;
        
        damagedRect = leRectCombine(&damagedRect, &rect);
    }
            
    return damagedRect;
}

static leResult setValue(leCircularSliderWidget* _this,
                         uint32_t value)
{
    leRect damagedRect;
    
    LE_ASSERT_THIS();
        
    if(_this->value == value)
        return LE_SUCCESS;

    if (value < _this->startValue || value > _this->endValue)
        return LE_FAILURE;
    
    damagedRect = _getDamagedRect(_this, value);

    _this->fn->_damageArea(_this, &damagedRect);

    _this->value = value;
    
    if (_this->valueChangedCallback != NULL)
    {
        _this->valueChangedCallback(_this, _this->value);
    }
        
    return LE_SUCCESS;
}

static leBool getRoundEdges(const leCircularSliderWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->roundEdges;
}

static leResult setRoundEdges(leCircularSliderWidget* _this,
                              leBool round)
{
    LE_ASSERT_THIS();
        
    if(_this->roundEdges == round)
        return LE_SUCCESS;
        
    _this->roundEdges = round;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leBool getStickyButton(const leCircularSliderWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->sticky;
}

static leResult setStickyButton(leCircularSliderWidget* _this,
                                leBool sticky)
{
    LE_ASSERT_THIS();
        
    if(_this->sticky == sticky)
        return LE_SUCCESS;
        
    _this->sticky = sticky;
    
    //_this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leBool getTouchOnButtonOnly(const leCircularSliderWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->buttonTouch;
}

static leResult setTouchOnButtonOnly(leCircularSliderWidget* _this,
                                     leBool buttonOnly)
{
    LE_ASSERT_THIS();

    if(_this->buttonTouch == buttonOnly)
        return LE_SUCCESS;
        
    _this->buttonTouch = buttonOnly;
    
    //_this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}


static uint32_t getArcThickness(const leCircularSliderWidget* _this, 
                                leCircularSliderWidgetArcType type)
{
    LE_ASSERT_THIS();
    
    switch(type)
    {
        case OUTSIDE_CIRCLE_BORDER:
            return _this->outsideBorderArc.thickness;
        case INSIDE_CIRCLE_BORDER:
            return _this->insideBorderArc.thickness;
        case ACTIVE_AREA:
            return _this->activeArc.thickness;
        case INACTIVE_AREA:
            return _this->inActiveArc.thickness;
        case CIRCLE_BUTTON:
            return _this->circleButtonArc.thickness;
        default:
            break;
    }
        
    return 0;
}

static leResult setArcThickness(leCircularSliderWidget* _this, 
                                leCircularSliderWidgetArcType type,
                                uint32_t thickness)
{
    LE_ASSERT_THIS();

    switch(type)
    {
        case OUTSIDE_CIRCLE_BORDER:
        {
            //if (thickness == _this->outsideBorderArc.thickness)
            //    return LE_SUCCESS;

            if (thickness > _this->radius)
                return LE_FAILURE;
            
            if (thickness > (_this->radius - _this->activeArc.thickness - _this->insideBorderArc.thickness))
                return LE_FAILURE;

            _this->outsideBorderArc.thickness = thickness;

            break;
        }
        case ACTIVE_AREA:
        { 
            //if (thickness == _this->activeArc.thickness)
            //    return LE_SUCCESS;

            if (thickness > _this->radius - _this->outsideBorderArc.thickness)
                return LE_FAILURE;
            
            if (thickness > (_this->radius - _this->outsideBorderArc.thickness - _this->insideBorderArc.thickness))
                return LE_FAILURE;

            _this->activeArc.thickness = thickness;
            _this->inActiveArc.thickness = thickness;

            _this->insideBorderArc.radius = _this->activeArc.radius - _this->activeArc.thickness;

            break;
        }

        case INSIDE_CIRCLE_BORDER:
        {
            //if (thickness == _this->insideBorderArc.thickness)
            //    return LE_SUCCESS;

            if (thickness > _this->radius - _this->outsideBorderArc.thickness - _this->activeArc.thickness)
                return LE_FAILURE;
            
            _this->insideBorderArc.thickness = thickness;
        
            break;
        }
        case CIRCLE_BUTTON:
        {
            //if (thickness == _this->circleButtonArc.thickness)
            //    return LE_SUCCESS;

            if (thickness > _this->circleButtonArc.radius)
                return LE_FAILURE;

            _this->circleButtonArc.thickness = thickness;

            break;
        }
        default:
            return LE_FAILURE;
    }

    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getArcRadius(const leCircularSliderWidget* _this,
                             leCircularSliderWidgetArcType type)
{
    LE_ASSERT_THIS();

    switch(type)
    {
        case CIRCLE_BUTTON:
            return _this->circleButtonArc.radius;
        default:
            break;
    }
        
    return 0;
}

static leResult setArcRadius(leCircularSliderWidget* _this,
                             leCircularSliderWidgetArcType type,
                             uint32_t rad)
{
    LE_ASSERT_THIS();

    switch(type)
    {
        case CIRCLE_BUTTON:
        {
            if (_this->circleButtonArc.radius == rad)
                return LE_SUCCESS;
            
            if (rad > _this->radius)
                return LE_FAILURE;

            _this->circleButtonArc.radius = rad;

            break;
        }
        default:
            return LE_FAILURE;
    }
        
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leScheme* getArcScheme(const leCircularSliderWidget* _this,
                              leCircularSliderWidgetArcType type)
{
    LE_ASSERT_THIS();

    switch(type)
    {
        case CIRCLE_BUTTON:
            return (leScheme*)_this->circleButtonArc.scheme;
        default:
            return (leScheme*)_this->widget.scheme;
            break;
    }
        
    return NULL;
}

static leResult setArcScheme(leCircularSliderWidget* _this,
                             leCircularSliderWidgetArcType type,
                             const leScheme* scheme)
{
    LE_ASSERT_THIS();

    switch(type)
    {
        //Only the circle button has a different scheme from parent widget
        case CIRCLE_BUTTON:
            _this->circleButtonArc.scheme = scheme;
            break;
        default:
            return LE_FAILURE;
    }
        
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leBool getArcVisible(const leCircularSliderWidget* _this,
                            leCircularSliderWidgetArcType type)
{
    LE_ASSERT_THIS();

    switch(type)
    {
        case OUTSIDE_CIRCLE_BORDER:
            return _this->outsideBorderArc.visible;
        case INSIDE_CIRCLE_BORDER:
            return _this->insideBorderArc.visible;
        case ACTIVE_AREA:
            return _this->activeArc.visible;
        case INACTIVE_AREA:
            return _this->inActiveArc.visible;
        case CIRCLE_BUTTON:
            return _this->circleButtonArc.visible;
        default:
            break;
    }
        
    return LE_FALSE;
}

static leResult setArcVisible(leCircularSliderWidget* _this,
                              leCircularSliderWidgetArcType type,
                              leBool visible)
{
    LE_ASSERT_THIS();

    switch(type)
    {
        case OUTSIDE_CIRCLE_BORDER:
        {
            if (_this->outsideBorderArc.visible == visible)
                return LE_SUCCESS;

            _this->outsideBorderArc.visible = visible;
            
            break;
        }
        case INSIDE_CIRCLE_BORDER:
        {
            if (_this->insideBorderArc.visible == visible)
                return LE_SUCCESS;

            _this->insideBorderArc.visible = visible;
            
            break;
        }
        case ACTIVE_AREA:
        {
            if (_this->activeArc.visible == visible)
                return LE_SUCCESS;

            _this->activeArc.visible = visible;
            
            break;
        }
        case INACTIVE_AREA:
        {
            if (_this->inActiveArc.visible == visible)
                return LE_SUCCESS;

            _this->inActiveArc.visible = visible;
            
            break;
        }
        case CIRCLE_BUTTON:
        {
            if (_this->circleButtonArc.visible == visible)
                return LE_SUCCESS;

            _this->circleButtonArc.visible = visible;
            
            break;
        }
        default:
            return LE_FAILURE;
    }
        
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leCircularSliderWidgetDir getDirection(const leCircularSliderWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->direction;
}

static leResult setDirection(leCircularSliderWidget* _this,
                             leCircularSliderWidgetDir dir)
{
    LE_ASSERT_THIS();
        
    if(_this->direction == dir)
        return LE_SUCCESS;
        
    _this->direction = dir;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leResult setPressedEventCallback(leCircularSliderWidget* _this,
                                        leCircularSliderWidget_PressedEvent cb)
{
    LE_ASSERT_THIS();

    _this->pressedCallback = cb;
        
    return LE_SUCCESS;
}

static leResult setValueChangedEventCallback(leCircularSliderWidget* _this,
                                             leCircularSliderWidget_ValueChangedEvent cb)
{
    LE_ASSERT_THIS();

    _this->valueChangedCallback = cb;
        
    return LE_SUCCESS;
}

static leResult setReleasedEventCallback(leCircularSliderWidget* _this,
                                         leCircularSliderWidget_ReleasedEvent cb)
{
    LE_ASSERT_THIS();
        
    _this->releasedCallback = cb;

    return LE_SUCCESS;
}

static uint32_t _getSliderValueAtPoint(leCircularSliderWidget* _this,
                                       lePoint pnt)
{
    uint32_t angle;
    uint32_t value;
    
    if (pnt.x > 0 && pnt.y > 0)
    {
        //Q1
        angle = (int32_t) ((double) leAtan((double) pnt.y / pnt.x) * (double)(180 / 3.1416));
    }
    else if (pnt.x < 0 && pnt.y > 0)
    {
        //Q2
        angle = (int32_t) ((double) leAtan((double) pnt.y / pnt.x) * (double)(180 / 3.1416));
        angle = 180 + angle;
    }
    else if (pnt.x > 0 && pnt.y < 0)
    {
        //Q4
        angle = (int32_t) ((double) leAtan((double) pnt.y / pnt.x) * (double)(180 / 3.1416));
        angle = 360 + angle;
    }
    else if (pnt.x < 0 && pnt.y < 0)
    {
        //Q3
        angle = (int32_t) ((double) leAtan((double) pnt.y / pnt.x) * (double)(180 / 3.1416));
        angle = 180 + angle;
    }
    else if (pnt.x == 0 && pnt.y >= 0)
    {
        // +y
        angle = 90;
    }
    else if (pnt.x == 0 && pnt.y < 0)
    {
        // -y
        angle = 270;
    }
    else if (pnt.y == 0 && pnt.x > 0)
    {
        // +x
        angle = 0;
    }
    else
    {
        // -x
        angle = 180;
    }

    if (_this->direction == CIRCULAR_SLIDER_DIR_COUNTER_CLOCKWISE)
    {
        if (angle > _this->startAngle)
        {
            value = _this->startValue + (_this->endValue - _this->startValue) * (angle - _this->startAngle)/ 360;
        }
        else //wrapped around
        {
            value = _this->startValue + (_this->endValue - _this->startValue) * (360 - _this->startAngle)/ 360 +
                    (_this->endValue - _this->startValue) * angle/360;
        }
    }
    else
    {
        if (angle < _this->startAngle)
        {
            value = _this->startValue + (_this->endValue - _this->startValue) * (_this->startAngle - angle) / 360;
        }
        else
        {
            value = _this->startValue + (_this->endValue - _this->startValue) * _this->startAngle/360 +
                    (_this->endValue - _this->startValue) * (360 - angle)/360;
        }
    }
    
    return value;
    
}

static void handleTouchDownEvent(leCircularSliderWidget* _this,
                                 leWidgetEvent_TouchDown* evt)
{
    lePoint pnt;
    
    LE_ASSERT_THIS();

    pnt.x = evt->x;
    pnt.y = evt->y;

    //If circular button is visible, set button state touch is within circle
    if (_this->circleButtonArc.visible == LE_TRUE)
    {
        leUtils_PointScreenToLocalSpace((leWidget*)_this, &pnt);
        
        if (_this->buttonTouch == LE_TRUE)
        {
            lePoint buttonCenter = _leCircularSliderWidget_GetCircleCenterPointAtValue(_this, _this->value);

            leUtils_PointScreenToLocalSpace((leWidget*)_this, &buttonCenter);

            //Measure distance of point from center and see if it is within radius
            if ((uint32_t)(((pnt.x - buttonCenter.x) * (pnt.x - buttonCenter.x)) + 
                ((pnt.y - buttonCenter.y) * (pnt.y - buttonCenter.y))) <= 
                (_this->circleButtonArc.radius * _this->circleButtonArc.radius))
            {

                _this->btnState = LE_CIRCULAR_SLIDER_STATE_DOWN;

                if (_this->pressedCallback != NULL)
                {
                    _this->pressedCallback(_this, _this->value);
                }

                leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);
            }
            else
            {
                _this->btnState = LE_CIRCULAR_SLIDER_STATE_UP;
            }
        }
        else
        {
            lePoint pntLocal;
            uint32_t ptRadSqd;
            uint32_t value;
            
            uint32_t touchOutRad = _this->radius - 
                                   (_this->activeArc.thickness/2) + 
                                   _this->circleButtonArc.radius;
            
            uint32_t touchInRad = _this->radius - 
                                   (_this->activeArc.thickness/2) -
                                   _this->circleButtonArc.radius;
            
            pntLocal.x = pnt.x - _this->widget.rect.width/2;
            pntLocal.y = _this->widget.rect.height/2 - pnt.y;
            
            ptRadSqd = (pntLocal.x) * (pntLocal.x) + 
                       (pntLocal.y) * (pntLocal.y);

            //Measure distance of point from center and see if it is within radius            
            if ((ptRadSqd <= (touchOutRad * touchOutRad)) &&
                (ptRadSqd >= (touchInRad * touchInRad)))
            {

                _this->btnState = LE_CIRCULAR_SLIDER_STATE_DOWN;

                if (_this->pressedCallback != NULL)
                {
                    _this->pressedCallback(_this, _this->value);
                }

                leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);
                
                value = _getSliderValueAtPoint(_this, pntLocal);
                
                _this->fn->setValue(_this, value);
            }
            else
            {
                _this->btnState = LE_CIRCULAR_SLIDER_STATE_UP;
            }
        }
    }
}

static void handleTouchUpEvent(leCircularSliderWidget* _this,
                               leWidgetEvent_TouchUp* evt)
{
    LE_ASSERT_THIS();
    
    if (_this->btnState == LE_CIRCULAR_SLIDER_STATE_DOWN)
    {
        leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);
        
        _this->btnState = LE_CIRCULAR_SLIDER_STATE_UP;
    
        if (_this->releasedCallback != NULL)
        {
            _this->releasedCallback(_this, _this->value);
        }
    }
}

static void handleTouchMovedEvent(leCircularSliderWidget* _this, leWidgetEvent_TouchMove* evt)
{
//    uint32_t touchPntRadSqd;
    lePoint pnt;
    uint32_t value;
    uint32_t snapThreshold;
    
    LE_ASSERT_THIS();

    pnt.x = evt->x;
    pnt.y = evt->y;

    snapThreshold = (_this->endValue > _this->startValue) ? 
                     (_this->endValue - _this->startValue)/4 : 
                     (_this->startValue - _this->endValue)/4;
    
    if (_this->circleButtonArc.visible == LE_TRUE && 
        _this->btnState == LE_CIRCULAR_SLIDER_STATE_DOWN)
    {
        leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);
    
        //Adjust point relative to widget local
        leUtils_PointScreenToLocalSpace((leWidget*)_this, &pnt);

        //Adjust point relative widget center/origin
        pnt.x -= _this->widget.rect.width/2; 
        pnt.y = _this->widget.rect.height/2 - pnt.y;
    
//        touchPntRadSqd = pnt.x * pnt.x + pnt.y * pnt.y;

        //Limit move point to within the touch button only
//        if ((touchPntRadSqd > ((_this->activeArc.radius + (_this->activeArc.thickness/2) + _this->circleButtonArc.radius) * 
//                               (_this->activeArc.radius + (_this->activeArc.thickness/2) + _this->circleButtonArc.radius))) ||
//            (touchPntRadSqd < 
//             ((_this->activeArc.radius - (_this->activeArc.thickness/2) - _this->circleButtonArc.radius) * 
//              (_this->activeArc.radius - (_this->activeArc.thickness/2) - _this->circleButtonArc.radius))))
//        {
//            //_this->btnState = LE_CIRCULAR_SLIDER_STATE_UP;
//            return;
//        }

        value = _getSliderValueAtPoint(_this, pnt);

        if (_this->sticky == LE_TRUE)
        {
            if ((_this->endValue - _this->value) < snapThreshold)
            {
                if ((value - _this->startValue) < snapThreshold)
                    value = _this->endValue;
            }
            
            else if ((_this->value - _this->startValue) < snapThreshold)
            {
                if ((_this->endValue - value) < snapThreshold)
                    value = _this->startValue;
            }
        }

        _this->fn->setValue(_this, value);
    }
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leCircularSliderWidget_Paint(leCircularSliderWidget* _this);

void _leCircularSliderWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&circularSliderWidgetVTable);
    
    /* overrides from base class */
    circularSliderWidgetVTable._destructor = _leCircularSliderWidget_Destructor;
    circularSliderWidgetVTable._paint = _leCircularSliderWidget_Paint;
    circularSliderWidgetVTable.touchDownEvent = handleTouchDownEvent;
    circularSliderWidgetVTable.touchUpEvent = handleTouchUpEvent;
    circularSliderWidgetVTable.touchMoveEvent = handleTouchMovedEvent;
    
    /* member functions */
    circularSliderWidgetVTable.getRadius = getRadius;
    circularSliderWidgetVTable.setRadius = setRadius;
    circularSliderWidgetVTable.getStartAngle = getStartAngle;
    circularSliderWidgetVTable.setStartAngle = setStartAngle;
    circularSliderWidgetVTable.getArcThickness = getArcThickness;
    circularSliderWidgetVTable.setArcThickness = setArcThickness;
    circularSliderWidgetVTable.getArcRadius = getArcRadius;
    circularSliderWidgetVTable.setArcRadius = setArcRadius;
    circularSliderWidgetVTable.getArcScheme = getArcScheme;
    circularSliderWidgetVTable.setArcScheme = setArcScheme;
    circularSliderWidgetVTable.getArcVisible = getArcVisible;
    circularSliderWidgetVTable.setArcVisible = setArcVisible;
    circularSliderWidgetVTable.getStartValue = getStartValue;
    circularSliderWidgetVTable.setStartValue = setStartValue;
    circularSliderWidgetVTable.getEndValue = getEndValue;
    circularSliderWidgetVTable.setEndValue = setEndValue;
    circularSliderWidgetVTable.getValue = getValue;
    circularSliderWidgetVTable.setValue = setValue;
    circularSliderWidgetVTable.getRoundEdges = getRoundEdges;
    circularSliderWidgetVTable.setRoundEdges = setRoundEdges;
    circularSliderWidgetVTable.getStickyButton = getStickyButton;
    circularSliderWidgetVTable.setStickyButton = setStickyButton;
    circularSliderWidgetVTable.getTouchOnButtonOnly = getTouchOnButtonOnly;
    circularSliderWidgetVTable.setTouchOnButtonOnly = setTouchOnButtonOnly;
    circularSliderWidgetVTable.getDirection = getDirection;
    circularSliderWidgetVTable.setDirection = setDirection;
    circularSliderWidgetVTable.setPressedEventCallback = setPressedEventCallback;
    circularSliderWidgetVTable.setValueChangedEventCallback = setValueChangedEventCallback;
    circularSliderWidgetVTable.setReleasedEventCallback = setReleasedEventCallback;
}

void _leCircularSliderWidget_FillVTable(leCircularSliderWidgetVTable* tbl)
{
    *tbl = circularSliderWidgetVTable;
}

#endif // LE_CIRCULARSLIDER_WIDGET_ENABLED
