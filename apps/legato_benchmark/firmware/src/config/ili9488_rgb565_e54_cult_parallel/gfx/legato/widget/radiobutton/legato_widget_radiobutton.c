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

#include "gfx/legato/widget/radiobutton/legato_widget_radiobutton.h"

#if LE_RADIOBUTTON_WIDGET_ENABLED == 1

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/widget/radiobutton/legato_radiobutton_group.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          25

#define DEFAULT_IMAGE_MARGIN    10

#define DEFAULT_CIRCLE_SIZE     12

static leRadioButtonWidgetVTable radioButtonWidgetVTable;

void _leRadioButtonWidget_Paint(leRadioButtonWidget* _this);

void _leRadioButtonWidget_GetImageRect(const leRadioButtonWidget* btn,
									   leRect* imgRect,
									   leRect* imgSrcRect);

void _leRadioButtonWidget_GetTextRect(const leRadioButtonWidget* btn,
								      leRect* textRect,
								      leRect* drawRect);

static void _invalidateImageRect(const leRadioButtonWidget* _this)
{
    leRect imgRect, imgSrcRect;
    
    _leRadioButtonWidget_GetImageRect(_this, &imgRect, &imgSrcRect);
    
    _this->fn->_damageArea(_this, &imgRect);
}

static void _invalidateTextRect(const leRadioButtonWidget* _this)
{
    leRect textRect, drawRect;
    
    _leRadioButtonWidget_GetTextRect(_this, &textRect, &drawRect);
    
    _this->fn->_damageArea(_this, &drawRect);
}

static void _invalidateContents(const leRadioButtonWidget* _this)
{
    if(_this->text != NULL)
    {
        _invalidateTextRect(_this);
    }
        
    _invalidateImageRect(_this);
}

static void languageChanging(leRadioButtonWidget* _this)
{
    if(_this->text != NULL)
    {
        _invalidateContents(_this);
    }
}

void leRadioButtonWidget_Constructor(leRadioButtonWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&radioButtonWidgetVTable;
    _this->fn = &radioButtonWidgetVTable;
    
    _this->widget.type = LE_WIDGET_RADIOBUTTON;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->selected = LE_TRUE;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;

    _this->text = NULL;
    
    _this->imageMargin = DEFAULT_IMAGE_MARGIN;

    _this->widget.halign = LE_HALIGN_LEFT;
    _this->widget.valign = LE_VALIGN_MIDDLE;
    
    _this->selectedImage = NULL;
    _this->unselectedImage = NULL;
    _this->circleButtonSize = DEFAULT_CIRCLE_SIZE;
}

void _leWidget_Destructor(leWidget* wgt);

static void destructor(leRadioButtonWidget* _this)
{
    if(_this->group != NULL)
    {
        leRadioButtonGroup_RemoveButton(_this->group, _this);   
    }
    
    _this->text = NULL;
    
    _leWidget_Destructor((leWidget*)_this);
}

/*leWidgetUpdateState _leRadioButtonWidget_Update(leRadioButtonWidget* _this)
{

}*/

leRadioButtonWidget* leRadioButtonWidget_New()
{
    leRadioButtonWidget* btn = NULL;

    btn = LE_MALLOC(sizeof(leRadioButtonWidget));

    if(btn == NULL)
        return btn;
        
    leRadioButtonWidget_Constructor(btn);

    return btn;
}

static leRadioButtonGroup* getGroup(const leRadioButtonWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->group;
}

static leBool getSelected(const leRadioButtonWidget* _this)
{
    LE_ASSERT_THIS();

    if(_this->group == NULL)
        return LE_TRUE;

    return _this->group->selected == _this;
}

static leResult setSelected(leRadioButtonWidget* _this)
{
    leResult res;
    
    LE_ASSERT_THIS();
    
    if(_this->selected == LE_TRUE)
        return LE_FAILURE;

    if(_this->group == NULL)
        return LE_SUCCESS;
   
    _invalidateContents(_this);
    
    res = leRadioButtonGroup_SelectButton(_this->group, _this);
    
    if(res == LE_SUCCESS)
    {
        _invalidateContents(_this);
    }
    
    return res;
}

static void select(leRadioButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    if(_this->selected == LE_TRUE)
        return;
    
    _invalidateContents(_this);

    _this->selected = LE_TRUE;

    if(_this->selectedEvent != NULL)
    {
        _this->selectedEvent(_this);
    }
        
    _invalidateContents(_this);
}

static void deselect(leRadioButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    if(_this->selected == LE_FALSE)
        return;

    _invalidateContents(_this);
    
    _this->selected = LE_FALSE;

    if(_this->deselectedEvent != NULL)
    {
        _this->deselectedEvent(_this);
    }
        
    _invalidateContents(_this);
}

static leString* getText(const leRadioButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    return (leString*)_this->text;
}

static leResult setText(leRadioButtonWidget* _this,
                        const leString* str)
{
    LE_ASSERT_THIS();
    
    _this->text = str;    
    
    _invalidateContents(_this);
    
    return LE_SUCCESS;
}

static leImage* getSelectedImage(const leRadioButtonWidget* _this)
{
    LE_ASSERT_THIS();

    return (leImage*)_this->selectedImage;
}

static leResult setSelectedImage(leRadioButtonWidget* _this,
                                 const leImage* img)
{
    LE_ASSERT_THIS();

    if(_this->selectedImage == img)
        return LE_SUCCESS;

    _invalidateContents(_this);

    _this->selectedImage = img;

    _invalidateContents(_this);
    
    return LE_SUCCESS;
}

static leImage* getUnselectedImage(const leRadioButtonWidget* _this)
{
    LE_ASSERT_THIS();

    return (leImage*)_this->unselectedImage;
}

static leResult setUnselectedImage(leRadioButtonWidget* _this,
                                   const leImage* img)
{
    LE_ASSERT_THIS();
        
    if(_this->unselectedImage == img)
        return LE_SUCCESS;
        
    _invalidateContents(_this);

    _this->unselectedImage = img;

    _invalidateContents(_this);
    
    return LE_SUCCESS;
}

static leRelativePosition getImagePosition(const leRadioButtonWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->imagePosition;
}

static leResult setImagePosition(leRadioButtonWidget* _this,
                                 leRelativePosition pos)
{
    LE_ASSERT_THIS();
    
    if(_this->imagePosition == pos)
        return LE_SUCCESS;
    
    _invalidateContents(_this);
    
    _this->imagePosition = pos;
    
    _invalidateContents(_this);
    
    return LE_SUCCESS;
}

static uint32_t getImageMargin(const leRadioButtonWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->imageMargin;
}

static leResult setImageMargin(leRadioButtonWidget* _this,
                               uint32_t mg)
{
    LE_ASSERT_THIS();
    
    if(_this->imageMargin == mg)
        return LE_SUCCESS;
        
    _invalidateContents(_this);
    
    _this->imageMargin = mg;
    
    _invalidateContents(_this);
    
    return LE_SUCCESS;
}

static leRadioButtonWidget_SelectedEvent getSelectedEventCallback(const leRadioButtonWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->selectedEvent;
}

static leResult setSelectedEventCallback(leRadioButtonWidget* _this,
                                         leRadioButtonWidget_SelectedEvent cb)
{
    LE_ASSERT_THIS();

    if(_this->selectedEvent == cb)
        return LE_FAILURE;

    _this->selectedEvent = cb;
    
    return LE_SUCCESS;
}

static leRadioButtonWidget_DeselectedEvent getDeselectedEventCallback(const leRadioButtonWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->deselectedEvent;
}

static leResult setDeselectedEventCallback(leRadioButtonWidget* _this,
                                           leRadioButtonWidget_DeselectedEvent cb)
{
    LE_ASSERT_THIS();
    
    if(_this->deselectedEvent == cb)
        return LE_FAILURE;

    _this->deselectedEvent = cb;
    
    return LE_SUCCESS;
}

static uint32_t getCircleButtonSize(const leRadioButtonWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->circleButtonSize;
}

static leResult setCircleButtonSize(leRadioButtonWidget* _this,
                                    uint32_t size)
{
    LE_ASSERT_THIS();

    if(size < DEFAULT_CIRCLE_SIZE)
        return LE_FAILURE;
    
    if((int32_t)size > _this->widget.rect.height)
        return LE_FAILURE;
    
    if((int32_t)size > _this->widget.rect.width)
        return LE_FAILURE;

    if((int32_t)size == _this->circleButtonSize)
        return LE_SUCCESS;
    
    _this->circleButtonSize = size;
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static void handleTouchDownEvent(leRadioButtonWidget* _this,
                                 leWidgetEvent_TouchDown* evt)
{
    leRect imgRect, imgSrcRect, widgetRect, clipRect;
    lePoint pt;
        
    LE_ASSERT_THIS();
    
    _leRadioButtonWidget_GetImageRect(_this, &imgRect, &imgSrcRect);
    
    widgetRect = _this->fn->rectToScreen(_this);
    
    leRectClip(&imgRect, &widgetRect, &clipRect);
    
    pt.x = evt->x;
    pt.y = evt->y;
    
    if(leRectContainsPoint(&clipRect, &pt) == LE_TRUE &&
       _this->selected == LE_FALSE)
    {
        leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);
    }
}

static void handleTouchUpEvent(leRadioButtonWidget* _this,
                               leWidgetEvent_TouchUp* evt)
{
    leRect imgRect, imgSrcRect, widgetRect, clipRect;
    lePoint pt;
    
    LE_ASSERT_THIS();
    
    _leRadioButtonWidget_GetImageRect(_this, &imgRect, &imgSrcRect);
    
    widgetRect = _this->fn->rectToScreen(_this);
    
    leRectClip(&imgRect, &widgetRect, &clipRect);

    pt.x = evt->x;
    pt.y = evt->y;

    leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);

    if(leRectContainsPoint(&clipRect, &pt) == LE_TRUE)
    {
        leRadioButtonGroup_SelectButton(_this->group, _this);
    }
    
    //printf("cbox touch up\n");
}

static void handleTouchMovedEvent(leRadioButtonWidget* _this,
                                  leWidgetEvent_TouchMove* evt)
{
    LE_ASSERT_THIS();

    leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leRadioButtonWidget_Paint(leRadioButtonWidget* _this);

void _leRadioButtonWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&radioButtonWidgetVTable);
    
    /* overrides from base class */
    radioButtonWidgetVTable._destructor = destructor;
    radioButtonWidgetVTable._paint = _leRadioButtonWidget_Paint;
    radioButtonWidgetVTable.invalidateContents = _invalidateContents;
    radioButtonWidgetVTable.languageChangeEvent = languageChanging;
    radioButtonWidgetVTable.touchDownEvent = handleTouchDownEvent;
    radioButtonWidgetVTable.touchUpEvent = handleTouchUpEvent;
    radioButtonWidgetVTable.touchMoveEvent = handleTouchMovedEvent;
    
    /* member functions */
    radioButtonWidgetVTable.getGroup = getGroup;
    radioButtonWidgetVTable.getSelected = getSelected;
    radioButtonWidgetVTable.setSelected = setSelected;
    radioButtonWidgetVTable.select = select;
    radioButtonWidgetVTable.deselect = deselect;
    radioButtonWidgetVTable.getText = getText;
    radioButtonWidgetVTable.setText = setText;
    radioButtonWidgetVTable.getSelectedImage = getSelectedImage;
    radioButtonWidgetVTable.setSelectedImage = setSelectedImage;
    radioButtonWidgetVTable.getUnselectedImage = getUnselectedImage;
    radioButtonWidgetVTable.setUnselectedImage = setUnselectedImage;
    radioButtonWidgetVTable.getImagePosition = getImagePosition;
    radioButtonWidgetVTable.setImagePosition = setImagePosition;
    radioButtonWidgetVTable.getImageMargin = getImageMargin;
    radioButtonWidgetVTable.setImageMargin = setImageMargin;
    radioButtonWidgetVTable.getSelectedEventCallback = getSelectedEventCallback;
    radioButtonWidgetVTable.setSelectedEventCallback = setSelectedEventCallback;
    radioButtonWidgetVTable.getDeselectedEventCallback = getDeselectedEventCallback;
    radioButtonWidgetVTable.setDeselectedEventCallback = setDeselectedEventCallback;
    radioButtonWidgetVTable.getCircleButtonSize = getCircleButtonSize;
    radioButtonWidgetVTable.setCircleButtonSize = setCircleButtonSize;
}

void _leRadioButtonWidget_FillVTable(leRadioButtonWidgetVTable* tbl)
{
    *tbl = radioButtonWidgetVTable;
}

#endif // LE_RADIOBUTTON_WIDGET_ENABLED