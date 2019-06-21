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

#include "gfx/legato/widget/label/legato_widget_label.h"

#if LE_LABEL_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/renderer/legato_renderer.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          25

static leLabelWidgetVTable labelWidgetVTable;

void _leLabelWidget_GetTextRect(const leLabelWidget* lbl,
                                leRect* textRect,
								leRect* drawRect);

static void invalidateContents(const leLabelWidget* lbl)
{
    leRect textRect, drawRect;
    
    _leLabelWidget_GetTextRect(lbl, &textRect, &drawRect);
    
    lbl->fn->_damageArea(lbl, &drawRect);
}

static void languageChanging(leLabelWidget* _this)
{
    if(_this->string != NULL &&
       _this->string->fn->isEmpty(_this->string) == LE_FALSE)
    {
        _this->fn->invalidate(_this);
    }
}

void leLabelWidget_Constructor(leLabelWidget* _this)
{
    LE_ASSERT_THIS();
        
    leWidget_Constructor((leWidget*)_this);

    _this->widget.fn = (void*)&labelWidgetVTable;
    _this->fn = &labelWidgetVTable;
    
    _this->widget.type = LE_WIDGET_LABEL;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
     
    _this->string = NULL;
}

void _leWidget_Destructor(leWidget* _this);

static void _leLabelWidget_Destructor(leLabelWidget* _this)
{
    LE_ASSERT_THIS();
    
    _this->string = NULL;
    
    _leWidget_Destructor((leWidget*)_this);
}

/*void _leLabelWidget_Update(leLabelWidget* lbl)
{

}*/

leLabelWidget* leLabelWidget_New()
{
    leLabelWidget* lbl = NULL;

    lbl = LE_MALLOC(sizeof(leLabelWidget));

    leLabelWidget_Constructor(lbl);

    return lbl;
}

static leString* getString(const leLabelWidget* _this)
{
    LE_ASSERT_THIS();
    
    return (leString*)_this->string;
}

static leResult setString(leLabelWidget* _this,
                          leString* str)
{
    LE_ASSERT_THIS();

    _this->string = str;
        
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leLabelWidget_Paint(leLabelWidget* _this);

void _leLabelWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&labelWidgetVTable);
    
    /* overrides from base class */
    labelWidgetVTable._destructor = _leLabelWidget_Destructor;
    labelWidgetVTable._paint = _leLabelWidget_Paint;
    labelWidgetVTable.languageChangeEvent = languageChanging;
    
    /* member functions */
    labelWidgetVTable.getString = getString;
    labelWidgetVTable.setString = setString;
    labelWidgetVTable.invalidateContents = invalidateContents;
}

void _leLabelWidget_FillVTable(leLabelWidgetVTable* tbl)
{
    *tbl = labelWidgetVTable;
}

#endif // LE_LABEL_WIDGET_ENABLED
