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

#include <gfx/legato/legato.h>
#include "gfx/legato/widget/progressbar/legato_widget_progressbar.h"

#if LE_PROGRESSBAR_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          25

static leProgressBarWidgetVTable progressBarWidgetVTable;

void _leProgressBarWidget_GetBarRect(const leProgressBarWidget* bar,
                                     int32_t val1,
                                     int32_t val2,
                                     leRect* barRect);

static void _invalidateBar(leProgressBarWidget* _this,
                           int32_t oldVal,
                           int32_t newVal)
{
    leRect barRect;
    
    _leProgressBarWidget_GetBarRect(_this, oldVal, newVal, &barRect);
    
    _this->fn->_damageArea(_this, &barRect);
}

void leProgressBarWidget_Constructor(leProgressBarWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&progressBarWidgetVTable;
    _this->fn = &progressBarWidgetVTable;
    
    _this->widget.type = LE_WIDGET_PROGRESSBAR;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_BEVEL;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_FILL;

    _this->direction = LE_DIRECTION_RIGHT;

    _this->cb = NULL;
}

void _leWidget_Destructor(leWidget* wgt);

static void destructor(leProgressBarWidget* _this)
{
    _leWidget_Destructor((leWidget*)_this);
}

leProgressBarWidget* leProgressBarWidget_New()
{
    leProgressBarWidget* bar = NULL;

    bar = LE_MALLOC(sizeof(leProgressBarWidget));

    if(bar == NULL)
        return NULL;
    
    leProgressBarWidget_Constructor(bar);

    return bar;
}

static leProgressBarDirection getDirection(const leProgressBarWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->direction;
}

static leResult setDirection(leProgressBarWidget* _this,
                             leProgressBarDirection dir)
{
    LE_ASSERT_THIS();
        
    if(_this->direction == dir)
        return LE_SUCCESS;
        
    _this->direction = dir;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static uint32_t getValue(const leProgressBarWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->value;
}

static leResult setValue(leProgressBarWidget* _this,
                         uint32_t value)
{
    uint32_t oldVal;
    
    LE_ASSERT_THIS();
    
    if(_this->value == value)
        return LE_SUCCESS;
    
    if(value > 100)
    {
        value = 100;
    }
    
    oldVal = _this->value;
    
    _this->value = value;
    
    if(_this->cb != NULL)
    {
        _this->cb(_this, value);
    }
    
    _invalidateBar(_this, oldVal, _this->value);
        
    return LE_SUCCESS;
}

static leProgressBar_ValueChangedEventCallback getValueChangedEventCallback(const leProgressBar* _this)
{
    LE_ASSERT_THIS();
        
    return _this->cb;
}

static leResult setValueChangedCallback(leProgressBar* _this,
                                        leProgressBar_ValueChangedEventCallback cb)
{
    LE_ASSERT_THIS();
        
    _this->cb = cb;
        
    return LE_SUCCESS;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leProgressBarWidget_Paint(leProgressBarWidget* _this);

void _leProgressBarWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&progressBarWidgetVTable);
    
    /* overrides from base class */
    progressBarWidgetVTable._destructor = destructor;
    progressBarWidgetVTable._paint = _leProgressBarWidget_Paint;
    
    /* member functions */
    progressBarWidgetVTable.getDirection = getDirection;
    progressBarWidgetVTable.setDirection = setDirection;
    progressBarWidgetVTable.getValue = getValue;
    progressBarWidgetVTable.setValue = setValue;
    progressBarWidgetVTable.getValueChangedEventCallback = getValueChangedEventCallback;
    progressBarWidgetVTable.setValueChangedCallback = setValueChangedCallback;
}

void _leProgressBarWidget_FillVTable(leProgressBarWidgetVTable* tbl)
{
    *tbl = progressBarWidgetVTable;
}

#endif // LE_PROGRESSBAR_WIDGET_ENABLED