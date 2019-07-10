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

#include "gfx/legato/widget/checkbox/legato_widget_checkbox.h"

#if LE_CHECKBOX_WIDGET_ENABLED == 1

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/renderer/legato_renderer.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH    100
#define DEFAULT_HEIGHT   23

#define DEFAULT_IMAGE_MARGIN    10

static leCheckBoxWidgetVTable checkBoxWidgetVTable;

void _leCheckBoxWidget_GetImageRect(const leCheckBoxWidget* cbox,
									leRect* imgRect,
									leRect* imgSrcRect);
									
void _leCheckBoxWidget_GetTextRect(const leCheckBoxWidget* cbox,
								   leRect* textRect,
								   leRect* drawRect);									

/*static void invalidateImageRect(const leCheckBoxWidget* _this)
{
    leRect imgRect, imgSrcRect;
    
    _leCheckBoxWidget_GetImageRect(_this, &imgRect, &imgSrcRect);
    
    _this->fn->_damageArea(_this, &imgRect);
}

static void invalidateTextRect(const leCheckBoxWidget* _this)
{
    leRect textRect, drawRect;
    
    _leCheckBoxWidget_GetTextRect(_this, &textRect, &drawRect);
    
    _this->fn->_damageArea(_this, &drawRect);
}*/

static void invalidateContents(const leCheckBoxWidget* _this)
{
    LE_ASSERT_THIS();

    _this->fn->invalidate(_this);
}

static void languageChanging(leCheckBoxWidget* _this)
{   
    LE_ASSERT_THIS();
    
    if(_this->string != NULL)
    {
        _this->fn->invalidate(_this);
    }
}

void _leCheckBoxWidget_Constructor(leCheckBoxWidget* _this)
{
    LE_ASSERT_THIS();
    
    /* call base class constructor */
    leWidget_Constructor((leWidget*)_this);

    _this->widget.fn = (void*)&checkBoxWidgetVTable;
    _this->fn = &checkBoxWidgetVTable;

    _this->widget.type = LE_WIDGET_CHECKBOX;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->checked = LE_FALSE;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;

    _this->string = NULL;

    _this->imageMargin = DEFAULT_IMAGE_MARGIN;

    _this->widget.halign = LE_HALIGN_LEFT;
    _this->widget.valign = LE_VALIGN_MIDDLE;
    
    _this->checkedImage = NULL;
    _this->uncheckedImage = NULL;
}

void _leWidget_Destructor(leWidget* _this);

void _leCheckBoxWidget_Destructor(leCheckBoxWidget* _this)
{
    LE_ASSERT_THIS();
    
    _this->string = NULL;
    
    /* call base class destructor */
    _leWidget_Destructor((leWidget*)_this);
}

leCheckBoxWidget* leCheckBoxWidget_New()
{
    leCheckBoxWidget* wgt = NULL;

    wgt = LE_MALLOC(sizeof(leCheckBoxWidget));

    if(wgt == NULL)
        return NULL;
    
    _leCheckBoxWidget_Constructor(wgt);

    return wgt;
}

static leBool getChecked(const leCheckBoxWidget* _this)
{
    LE_ASSERT_THIS();
    
    return _this->checked;
}

static leResult setChecked(leCheckBoxWidget* _this,
                           leBool checked)
{
    LE_ASSERT_THIS();
        
    if(_this->checked == checked)
        return LE_SUCCESS;
        
    _this->checked = checked;
    
    if (_this->checked == LE_TRUE && _this->checkedEvent != NULL)
    {
        _this->checkedEvent(_this);
    }
    else if (_this->checked == LE_FALSE && _this->uncheckedEvent != NULL)
    {
        _this->uncheckedEvent(_this);
    }

    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static leString* getString(const leCheckBoxWidget* _this)
{
    LE_ASSERT_THIS();
    
    return (leString*)_this->string;
}

static leResult setString(leCheckBoxWidget* _this,
                          const leString* str)
{
    LE_ASSERT_THIS();
        
    _this->string = str;

    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static leImage* getCheckedImage(const leCheckBoxWidget* _this)
{
    LE_ASSERT_THIS();

    return (leImage*)_this->checkedImage;
}

static leResult setCheckedImage(leCheckBoxWidget* _this,
                                leImage* img)
{
    LE_ASSERT_THIS();

    _this->checkedImage = img;

    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static leImage* getUncheckedImage(const leCheckBoxWidget* _this)
{
    LE_ASSERT_THIS();

    return (leImage*)_this->uncheckedImage;
}

static leResult setUncheckedImage(leCheckBoxWidget* _this,
                                  leImage* img)
{
    LE_ASSERT_THIS();

    _this->uncheckedImage = img;

    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static leRelativePosition getImagePosition(const leCheckBoxWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->imagePosition;
}

static leResult setImagePosition(leCheckBoxWidget* _this,
                                 leRelativePosition pos)
{
    LE_ASSERT_THIS();
    
    _this->imagePosition = pos;

    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static uint32_t getImageMargin(const leCheckBoxWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->imageMargin;
}

static leResult setImageMargin(leCheckBoxWidget* _this,
                               uint32_t mg)
{
    LE_ASSERT_THIS();
    
    _this->imageMargin = mg;

    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static leCheckBoxWidget_CheckedEvent getCheckedEventCallback(const leCheckBoxWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->checkedEvent;
}

static leResult setCheckedEventCallback(leCheckBoxWidget* _this,
                                        leCheckBoxWidget_CheckedEvent cb)
{
    LE_ASSERT_THIS();

    _this->checkedEvent = cb;
    
    return LE_SUCCESS;
}

static leCheckBoxWidget_UncheckedEvent getUncheckedEventCallback(const leCheckBoxWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->uncheckedEvent;
}

static leResult setUncheckedEventCallback(leCheckBoxWidget* _this,
                                          leCheckBoxWidget_UncheckedEvent cb)
{
    LE_ASSERT_THIS();

    _this->uncheckedEvent = cb;
    
    return LE_SUCCESS;
}

static void handleTouchDownEvent(leCheckBoxWidget* _this,
                                 leWidgetEvent_TouchDown* evt)
{
    leRect imgRect, imgSrcRect;
    lePoint pt;
    
    LE_ASSERT_THIS();
    
    _leCheckBoxWidget_GetImageRect(_this, &imgRect, &imgSrcRect);
    
    pt.x = evt->x;
    pt.y = evt->y;
    
    if(leRectContainsPoint(&imgRect, &pt) == LE_TRUE)
    {
        leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);

       // printf("cbox touch down\n");
    }
}

static void handleTouchUpEvent(leCheckBoxWidget* _this,
                               leWidgetEvent_TouchUp* evt)
{
    leRect imgRect, imgSrcRect;
    lePoint pnt;
    
    LE_ASSERT_THIS();

    pnt.x = evt->x;
    pnt.y = evt->y;

    leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);

    _leCheckBoxWidget_GetImageRect(_this, &imgRect, &imgSrcRect);
    
    if(leRectContainsPoint(&imgRect, &pnt) == LE_TRUE)
    {
        _this->fn->setChecked(_this, !_this->checked);
    }
}

static void handleTouchMovedEvent(leCheckBoxWidget* _this,
                                  leWidgetEvent_TouchMove* evt)
{
    LE_ASSERT_THIS();

    leWidgetEvent_Accept((leWidgetEvent*)evt, (leWidget*)_this);
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leCheckBoxWidget_Paint(leCheckBoxWidget* _this);

void _leCheckBoxWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&checkBoxWidgetVTable);
    
    /* overrides from base class */
    checkBoxWidgetVTable._destructor = _leCheckBoxWidget_Destructor;
    checkBoxWidgetVTable.languageChangeEvent = languageChanging;
    checkBoxWidgetVTable._paint = _leCheckBoxWidget_Paint;
    checkBoxWidgetVTable.invalidateContents = invalidateContents;
    checkBoxWidgetVTable.touchDownEvent = handleTouchDownEvent;
    checkBoxWidgetVTable.touchUpEvent = handleTouchUpEvent;
    checkBoxWidgetVTable.touchMoveEvent = handleTouchMovedEvent;
    
    /* member functions */
    checkBoxWidgetVTable.getChecked = getChecked;
    checkBoxWidgetVTable.setChecked = setChecked;
    checkBoxWidgetVTable.getCheckedImage = getCheckedImage;
    checkBoxWidgetVTable.setCheckedImage = setCheckedImage;
    checkBoxWidgetVTable.getUncheckedImage = getUncheckedImage;
    checkBoxWidgetVTable.setUncheckedImage = setUncheckedImage;
    checkBoxWidgetVTable.getImagePosition = getImagePosition;
    checkBoxWidgetVTable.setImagePosition = setImagePosition;
    checkBoxWidgetVTable.getImageMargin = getImageMargin;
    checkBoxWidgetVTable.setImageMargin = setImageMargin;
    checkBoxWidgetVTable.getString = getString;
    checkBoxWidgetVTable.setString = setString;
    checkBoxWidgetVTable.getCheckedEventCallback = getCheckedEventCallback;
    checkBoxWidgetVTable.setCheckedEventCallback = setCheckedEventCallback;
    checkBoxWidgetVTable.getUncheckedEventCallback = getUncheckedEventCallback;
    checkBoxWidgetVTable.setUncheckedEventCallback = setUncheckedEventCallback;
}

void _leCheckBoxWidget_FillVTable(leCheckBoxWidgetVTable* tbl)
{
    *tbl = checkBoxWidgetVTable;
}

#endif // LE_CHECKBOX_WIDGET_ENABLED
