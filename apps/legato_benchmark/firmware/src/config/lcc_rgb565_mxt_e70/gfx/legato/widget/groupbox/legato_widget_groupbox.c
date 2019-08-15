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

#include "gfx/legato/widget/groupbox/legato_widget_groupbox.h"

#if LE_GROUPBOX_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

void _leGroupBoxWidget_GetTextRect(const leGroupBoxWidget* box,
								   leRect* textRect,
								   leRect* drawRect);

static void invalidateTextRect(const leGroupBoxWidget* _this)
{
    leRect textRect, drawRect;
    
    _leGroupBoxWidget_GetTextRect(_this, &textRect, &drawRect);
    
    _this->fn->_damageArea(_this, &drawRect);
}

static void stringPreinvalidate(const leString* str,
                                leGroupBoxWidget* box)
{
    invalidateTextRect(box);
}

static void stringInvalidate(const leString* str,
                             leGroupBoxWidget* box)
{
    invalidateTextRect(box);
}

static void onLanguageChanging(leGroupBoxWidget* _this)
{
    LE_ASSERT_THIS();
    
    if(_this->string != NULL)
    {
        _this->fn->invalidate(_this);
    }
}

static leGroupBoxWidgetVTable groupBoxWidgetVTable;

void leGroupBoxWidget_Constructor(leGroupBoxWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&groupBoxWidgetVTable;
    _this->fn = &groupBoxWidgetVTable;

    _this->widget.type = LE_WIDGET_GROUPBOX;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;

    _this->string = NULL;
}

void _leWidget_Destructor(leWidget* _this);

void _leGroupBoxWidget_Destructor(leGroupBoxWidget* _this)
{
    _this->string = NULL;

    _leWidget_Destructor((leWidget*)_this);
}

leGroupBoxWidget* leGroupBoxWidget_New()
{
    leGroupBoxWidget* box = NULL;

    box = LE_MALLOC(sizeof(leGroupBoxWidget));

    leGroupBoxWidget_Constructor(box);

    return box;
}

static leString* getString(const leGroupBoxWidget* _this)
{
    LE_ASSERT_THIS();
    
    return (leString*)_this->string;
}

static leResult setString(leGroupBoxWidget* _this,
                          const leString* str)
{
    LE_ASSERT_THIS();

    if(_this->string != NULL)
    {
        invalidateTextRect(_this);

        _this->string->fn->setPreInvalidateCallback((leString*)_this->string,
                                                    NULL,
                                                    NULL);

        _this->string->fn->setInvalidateCallback((leString*)_this->string,
                                                 NULL,
                                                 NULL);
    }

    _this->string = str;

    _this->string->fn->setPreInvalidateCallback((leString*)_this->string,
                                                (void*)stringPreinvalidate,
                                                _this);

    _this->string->fn->setInvalidateCallback((leString*)_this->string,
                                             (void*)stringInvalidate,
                                             _this);

    invalidateTextRect(_this);
    
    return LE_SUCCESS;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leGroupBoxWidget_Paint(leGroupBoxWidget* _this);

void _leGroupBoxWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&groupBoxWidgetVTable);
    
    /* overrides from base class */
    groupBoxWidgetVTable._destructor = _leGroupBoxWidget_Destructor;
    groupBoxWidgetVTable._paint = _leGroupBoxWidget_Paint;
    groupBoxWidgetVTable.languageChangeEvent = onLanguageChanging;
    
    /* member functions */
    groupBoxWidgetVTable.getString = getString;
    groupBoxWidgetVTable.setString = setString;
}

void _leGroupBoxWidget_FillVTable(leGroupBoxWidgetVTable* tbl)
{
    *tbl = groupBoxWidgetVTable;
}

#endif // LE_GROUPBOX_WIDGET_ENABLED