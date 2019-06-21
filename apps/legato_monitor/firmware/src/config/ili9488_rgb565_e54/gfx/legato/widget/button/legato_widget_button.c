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

#include "gfx/legato/widget/button/legato_widget_button.h"

#if LE_BUTTON_WIDGET_ENABLED == 1

#include <string.h>

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/renderer/legato_renderer.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          25

#define DEFAULT_IMAGE_MARGIN    10

#define DEFAULT_PRESSED_OFFSET  1

static leButtonWidgetVTable buttonWidgetVTable;

void _leButtonWidget_GetImageRect(const leButtonWidget* _this,
                                  leRect* imgRect,
                                  leRect* imgSrcRect);

void _leButtonWidget_GetTextRect(const leButtonWidget* _this,
                                 leRect* textRect,
                                 leRect* drawRect);

void _leButtonWidget_InvalidateBorderAreas(const leButtonWidget* _this);

static void invalidateImageRect(const leButtonWidget* _this)
{
    leRect imgRect, imgSrcRect;
    
    _leButtonWidget_GetImageRect(_this, &imgRect, &imgSrcRect);
    
    _this->fn->_damageArea(_this, &imgRect);
}

static void invalidateTextRect(const leButtonWidget* _this)
{
    leRect textRect, drawRect;
    
    _leButtonWidget_GetTextRect(_this, &textRect, &drawRect);
    
    _this->fn->_damageArea(_this, &drawRect);
}

void leButtonWidget_Constructor(leButtonWidget* _this)
{
    /* call base class constructor */
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&buttonWidgetVTable;
    _this->fn = &buttonWidgetVTable;

    _this->widget.type = LE_WIDGET_BUTTON;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->state = LE_BUTTON_STATE_UP;
    _this->toggleable = LE_FALSE;

    _this->widget.borderType = LE_WIDGET_BORDER_BEVEL;

    _this->string = NULL;
    
    _this->imageMargin = DEFAULT_IMAGE_MARGIN;
    _this->pressedOffset = DEFAULT_PRESSED_OFFSET;
    
    _this->pressedImage = NULL;
    _this->releasedImage = NULL;
}

leButtonWidget* leButtonWidget_New()
{
    leButtonWidget* wgt = NULL;

    wgt = LE_MALLOC(sizeof(leButtonWidget));
    
    if(wgt == NULL)
        return NULL;
    
    leButtonWidget_Constructor(wgt);

    return wgt;
}

void _leWidget_Destructor(leWidget* wgt);

void _leButtonWidget_Destructor(leButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    _this->string = NULL;
    _this->pressedImage = NULL;
    _this->releasedImage = NULL;

    /* call base class destructor */
    _leWidget_Destructor((leWidget*)_this);
}



static leBool getToggleable(const leButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->toggleable;
}

static leResult setToggleable(leButtonWidget* _this,
                              leBool toggleable)
{
    LE_ASSERT_THIS();
    
    _this->toggleable = toggleable == 0 ? LE_FALSE : LE_TRUE;
    
    return LE_SUCCESS;
}

static leBool getPressed(const leButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->state == LE_BUTTON_STATE_DOWN ||
           _this->state == LE_BUTTON_STATE_TOGGLED;
}

static leResult setPressed(leButtonWidget* _this,
                           leBool pressed)
{
    leBool dirty = LE_FALSE;

    LE_ASSERT_THIS();
    
    if(pressed == LE_TRUE && _this->state == LE_BUTTON_STATE_TOGGLED)
        return LE_FAILURE;
        
    if(pressed == LE_TRUE)
    {
        if(_this->pressedEvent != NULL)
        {
            _this->pressedEvent(_this);
        }
            
        // move to toggled state
        if(_this->toggleable == LE_TRUE)
        {
            _this->state = LE_BUTTON_STATE_TOGGLED;
        }
        // throw released event immediately
        else
        {
            if(_this->releasedEvent != NULL)
            {
                _this->releasedEvent(_this);
            }
        }
    }
    else
    {
        _this->state = LE_BUTTON_STATE_UP;
        
        if(_this->releasedEvent != NULL)
        {
            _this->releasedEvent(_this);
        }
    }
    
    // try to find a reason to redraw
    if(_this->pressedImage != NULL && 
       _this->pressedImage != _this->releasedImage)
    {
        dirty = LE_TRUE;
    }
       
    if(_this->widget.borderType == LE_WIDGET_BORDER_BEVEL)
    {
        dirty = LE_TRUE;
    }
        
    if(_this->pressedOffset != 0 &&
       (_this->pressedImage != NULL ||
       (_this->string != NULL && _this->string->fn->isEmpty(_this->string) == LE_FALSE)))
    {
        dirty = LE_TRUE;
    }
        
    if(dirty == LE_TRUE)
    {
        _this->fn->invalidate(_this);
    }
        
    return LE_SUCCESS;
}

static leString* getString(const leButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    return (leString*)_this->string;
}

static leResult setString(leButtonWidget* _this,
                         const leString* str)
{
    LE_ASSERT_THIS();

    _this->string = str;
        
    invalidateTextRect(_this);
        
    return LE_SUCCESS;
}

static leImage* getPressedImage(const leButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    return (leImage*)_this->pressedImage;
}

static leResult setPressedImage(leButtonWidget* _this,
                                leImage* img)
{
    LE_ASSERT_THIS();
    
    _this->pressedImage = img;

    _this->fn->invalidateContents(_this);
    
    return LE_SUCCESS;
}

static leImage* getReleasedImage(const leButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    return (leImage*)_this->releasedImage;
}

static leResult setReleasedImage(leButtonWidget* _this,
                                 leImage* img)
{
    LE_ASSERT_THIS();
    
    _this->releasedImage = img;

    _this->fn->invalidateContents(_this);
    
    return LE_SUCCESS;
}

static leRelativePosition getImagePosition(const leButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->imagePosition;
}

static leResult setImagePosition(leButtonWidget* _this,
                                 leRelativePosition pos)
{
    LE_ASSERT_THIS();
    
    if(_this->imagePosition == pos)
        return LE_SUCCESS;
    
    _this->fn->invalidateContents(_this);
    
    _this->imagePosition = pos;
    
    _this->fn->invalidateContents(_this);
    
    return LE_SUCCESS;
}

static uint32_t getImageMargin(const leButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->imageMargin;
}

static leResult setImageMargin(leButtonWidget* _this,
                               uint32_t mg)
{
    LE_ASSERT_THIS();
    
    if(_this->imageMargin == mg)
        return LE_SUCCESS;
        
    _this->fn->invalidateContents(_this);
    
    _this->imageMargin = mg;
    
    _this->fn->invalidateContents(_this);
    
    return LE_SUCCESS;
}

static int32_t getPressedOffset(const leButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->pressedOffset;
}

static leResult setPressedOffset(leButtonWidget* _this,
                                 int32_t offs)
{
    LE_ASSERT_THIS();
    
    if(_this->pressedOffset == offs)
        return LE_SUCCESS;
        
    if(_this->state != LE_BUTTON_STATE_UP)
    {
        _this->fn->invalidateContents(_this);
    }
       
    _this->pressedOffset = offs;
    
    if(_this->state != LE_BUTTON_STATE_UP)
    {
        _this->fn->invalidateContents(_this);
    }
        
    return LE_SUCCESS;
}

static leButtonWidget_PressedEvent getPressedEventCallback(const leButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->pressedEvent;
}

static leResult setPressedEventCallback(leButtonWidget* _this,
                                        leButtonWidget_PressedEvent cb)
{   
    LE_ASSERT_THIS();
    
    _this->pressedEvent = cb;
    
    return LE_SUCCESS;
}

static leButtonWidget_ReleasedEvent getReleasedEventCallback(const leButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->releasedEvent;
}

static leResult setReleasedEventCallback(leButtonWidget* _this,
                                         leButtonWidget_ReleasedEvent cb)
{
    LE_ASSERT_THIS();
    
    _this->releasedEvent = cb;
    
    return LE_SUCCESS;
}

static void invalidateContents(const leButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    if(_this->string != NULL && _this->string->fn->isEmpty(_this->string) == LE_FALSE)
    {
        invalidateTextRect(_this);
    }
        
    if((_this->state != LE_BUTTON_STATE_UP && _this->pressedImage != NULL) ||
       (_this->state == LE_BUTTON_STATE_UP && _this->releasedImage != NULL))
    {
        invalidateImageRect(_this);
    }
}

static void languageChanging(leButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    if(_this->string != NULL && _this->string->fn->isEmpty(_this->string) == LE_FALSE)
    {
        _this->fn->invalidateContents(_this);
    }
}

static void touchDown(leButtonWidget* _this,
                      leInput_TouchDownEvent* evt)
{
    leBool dirty = LE_FALSE;
    
    LE_ASSERT_THIS();
    
    evt->event.accepted = LE_TRUE;

    if(_this->toggleable == LE_TRUE)
    {
        if(_this->state != LE_BUTTON_STATE_TOGGLED)
        {
            _this->state = LE_BUTTON_STATE_DOWN;

            if(_this->pressedEvent != NULL)
            {
                _this->pressedEvent(_this);
            }
        }
    }
    else
    {
        _this->state = LE_BUTTON_STATE_DOWN;

        if(_this->pressedEvent != NULL)
        {
            _this->pressedEvent(_this);
        }
    }

    // try to find a reason to redraw
    if(_this->pressedImage != NULL && _this->pressedImage != _this->releasedImage)
    {
        dirty = LE_TRUE;
    }
        
    if(_this->widget.borderType == LE_WIDGET_BORDER_BEVEL)
    {
        dirty = LE_TRUE;
    }
        
    if(_this->pressedOffset != 0 &&
       (_this->pressedImage != NULL ||
       (_this->string != NULL && _this->string->fn->isEmpty(_this->string) == LE_FALSE)))
    {
        dirty = LE_TRUE;
    }
        
    if(dirty == LE_TRUE)
    {
        _this->fn->invalidate(_this);
    }
        
    //printf("button touch down\n");
}

static void touchUp(leButtonWidget* _this,
                    leInput_TouchUpEvent* evt)
{
    leRect rect;
    lePoint pnt;
    
    leBool dirty = LE_FALSE;
    
    LE_ASSERT_THIS();
    
    rect = _this->fn->localRect(_this);

    pnt.x = evt->x;
    pnt.y = evt->y;

    evt->event.accepted = LE_TRUE;

    leUtils_ClipRectToParent(_this->widget.parent, &rect);
    leUtils_RectToScreenSpace((leWidget*)_this, &rect);
    
    //Toggle buttons will not respond to touch outside the button area
    if ((leRectContainsPoint(&rect, &pnt) == LE_FALSE) && 
        (_this->toggleable == LE_TRUE))
    {
        return;
    }

    if(leRectContainsPoint(&rect, &pnt) == LE_TRUE)
    {
        if(_this->toggleable == LE_TRUE)
        {
            if(_this->state == LE_BUTTON_STATE_TOGGLED)
            {
                _this->state = LE_BUTTON_STATE_UP;

                if(_this->releasedEvent != NULL)
                {
                    _this->releasedEvent(_this);
                }
                
                //printf("_this released\n");
            }
            else
            {
                _this->state = LE_BUTTON_STATE_TOGGLED;
            }
        }
        else
        {
            _this->state = LE_BUTTON_STATE_UP;

            if(_this->releasedEvent != NULL)
            {
                _this->releasedEvent(_this);
            }
            
            //printf("_this released\n");
        }
    }
    else
    {
        if(_this->toggleable == LE_TRUE)
        {
            if(_this->state != LE_BUTTON_STATE_TOGGLED)
            {
                _this->state = LE_BUTTON_STATE_UP;
            }
        }
        else
        {
            _this->state = LE_BUTTON_STATE_UP;
        }
    }
    
    // try to find a reason to redraw
    if(_this->pressedImage != NULL &&
       _this->pressedImage != _this->releasedImage)
    {
        dirty = LE_TRUE;
    }
        
    if(_this->widget.borderType == LE_WIDGET_BORDER_BEVEL)
    {
        dirty = LE_TRUE;
    }
        
    if(_this->pressedOffset != 0 &&
       (_this->pressedImage != NULL ||
       (_this->string != NULL && _this->string->fn->isEmpty(_this->string) == LE_FALSE)))
    {
        dirty = LE_TRUE;
    }
        
    if(dirty == LE_TRUE)
    {
        _this->fn->invalidate(_this);
    }
    
    //printf("button touch up\n");
}

static void touchMoved(leButtonWidget* _this,
                       leInput_TouchMoveEvent* evt)
{
    leRect rect;
    lePoint pnt;
    
    leBool dirty = LE_FALSE;

    LE_ASSERT_THIS();
    
    rect = _this->fn->localRect(_this);
    
    pnt.x = evt->x;
    pnt.y = evt->y;

    evt->event.accepted = LE_TRUE;
    
    //Toggle buttons will not respond to touch outside the button area
    if ((leRectContainsPoint(&rect, &pnt) == LE_FALSE) && 
        (_this->toggleable == LE_TRUE))
    {
        return;
    }

    if(_this->state == LE_BUTTON_STATE_DOWN)
    {
        leUtils_ClipRectToParent(_this->widget.parent, &rect);
        leUtils_RectToScreenSpace((leWidget*)_this, &rect);

        if(leRectContainsPoint(&rect, &pnt) == LE_FALSE)
        {
            _this->state = LE_BUTTON_STATE_UP;
            
            // try to find a reason to redraw
            if(_this->pressedImage != NULL && _this->pressedImage != _this->releasedImage)
            {
                dirty = LE_TRUE;
            }
                
            if(_this->widget.borderType == LE_WIDGET_BORDER_BEVEL)
            {
                dirty = LE_TRUE;
            }
                
            if(_this->pressedOffset != 0 &&
               (_this->pressedImage != NULL ||
               (_this->string != NULL && _this->string->fn->isEmpty(_this->string) == LE_FALSE)))
            {
                dirty = LE_TRUE;
            }
                
            if(dirty == LE_TRUE)
            {
                _this->fn->invalidate(_this);
            }
        }
    }
    else if(_this->state == LE_BUTTON_STATE_UP)
    {
        leUtils_ClipRectToParent(_this->widget.parent, &rect);
        leUtils_RectToScreenSpace((leWidget*)_this, &rect);

        if(leRectContainsPoint(&rect, &pnt) == LE_TRUE)
        {
            _this->state = LE_BUTTON_STATE_DOWN;

            // try to find a reason to redraw
            if(_this->pressedImage != NULL && _this->pressedImage != _this->releasedImage)
            {
                dirty = LE_TRUE;
            }
                
            if(_this->widget.borderType == LE_WIDGET_BORDER_BEVEL)
            {
                dirty = LE_TRUE;
            }
                
            if(_this->pressedOffset != 0 &&
               (_this->pressedImage != NULL ||
               (_this->string != NULL && _this->string->fn->isEmpty(_this->string) == LE_FALSE)))
            {
                dirty = LE_TRUE;
            }
                
            if(dirty == LE_TRUE)
            {
                _this->fn->invalidate(_this);
            }
        }
    }
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leButtonWidget_Paint(leButtonWidget* _this);

void _leButtonWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&buttonWidgetVTable);
    
    /* overrides from base class */
    buttonWidgetVTable._destructor = _leButtonWidget_Destructor;
    buttonWidgetVTable.languageChangeEvent = languageChanging;
    buttonWidgetVTable._paint = _leButtonWidget_Paint;
    buttonWidgetVTable.invalidateContents = invalidateContents;
    buttonWidgetVTable._invalidateBorderAreas = _leButtonWidget_InvalidateBorderAreas;
    buttonWidgetVTable.touchDownEvent = touchDown;
    buttonWidgetVTable.touchUpEvent = touchUp;
    buttonWidgetVTable.touchMoveEvent = touchMoved;
    
    /* member functions */
    buttonWidgetVTable.getToggleable = getToggleable;
    buttonWidgetVTable.setToggleable = setToggleable;
    buttonWidgetVTable.getPressed = getPressed;
    buttonWidgetVTable.setPressed = setPressed;
    buttonWidgetVTable.getString = getString;
    buttonWidgetVTable.setString = setString;
    buttonWidgetVTable.getPressedImage = getPressedImage;
    buttonWidgetVTable.setPressedImage = setPressedImage;
    buttonWidgetVTable.getReleasedImage = getReleasedImage;
    buttonWidgetVTable.setReleasedImage = setReleasedImage;
    buttonWidgetVTable.getImagePosition = getImagePosition;
    buttonWidgetVTable.setImagePosition = setImagePosition;
    buttonWidgetVTable.getImageMargin = getImageMargin;
    buttonWidgetVTable.setImageMargin = setImageMargin;
    buttonWidgetVTable.getPressedOffset = getPressedOffset;
    buttonWidgetVTable.setPressedOffset = setPressedOffset;
    buttonWidgetVTable.getPressedEventCallback = getPressedEventCallback;
    buttonWidgetVTable.setPressedEventCallback = setPressedEventCallback;
    buttonWidgetVTable.getReleasedEventCallback = getReleasedEventCallback;
    buttonWidgetVTable.setReleasedEventCallback = setReleasedEventCallback;
}

void _leButtonWidget_FillVTable(leButtonWidgetVTable* tbl)
{
    *tbl = buttonWidgetVTable;
}

#endif // LE_BUTTON_WIDGET_ENABLED
