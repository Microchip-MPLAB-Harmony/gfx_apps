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

#include "gfx/legato/widget/window/legato_widget_window.h"

#if LE_WINDOW_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

#define DEFAULT_ICON_MARGIN     6

static leWindowWidgetVTable windowWidgetVTable;

void _leWindowWidget_GetTitleBarRect(const leWindowWidget* win, leRect* barRect);

void _leWindowWidget_GetIconRect(const leWindowWidget* win,
                                 leRect* imgRect,
                                 leRect* imgSrcRect);

void _leWindowWidget_GetTextRect(const leWindowWidget* win,
                                 leRect* textRect,
                                 leRect* drawRect);

static void _invalidateTitleBar(const leWindowWidget* _this)
{
    leRect barRect;
    
    _leWindowWidget_GetTitleBarRect(_this, &barRect);
    
    _this->fn->_damageArea(_this, &barRect);
}

static void _invalidateTitleText(const leWindowWidget* _this)
{
    leRect textRect, drawRect;
    
    _leWindowWidget_GetTextRect(_this, &textRect, &drawRect);
                          
    _this->fn->_damageArea(_this, &drawRect);
}

static void languageChanging(leWindowWidget* _this)
{
    if(_this->title != NULL)
    {
        _invalidateTitleText(_this);
    }
}

void leWindowWidget_Constructor(leWindowWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.type = LE_WIDGET_WINDOW;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->iconMargin = DEFAULT_ICON_MARGIN;

    _this->widget.borderType = LE_WIDGET_BORDER_BEVEL;

    _this->title = NULL;
}

void _leWidget_Destructor(leWidget* wgt);

static void destructor(leWindowWidget* _this)
{
    _this->title = NULL;

    _leWidget_Destructor((leWidget*)_this);
}

leWindowWidget* leWindowWidget_New()
{
    leWindowWidget* win = NULL;

    win = LE_MALLOC(sizeof(leWindowWidget));

    leWindowWidget_Constructor(win);

    return win;
}

static leString* getTitle(const leWindowWidget* _this)
{
    LE_ASSERT_THIS();
    
    return (leString*)_this->title;
}

static leResult setTitle(leWindowWidget* _this,
                         const leString* str)
{
    LE_ASSERT_THIS();
    
    _this->title = str;
    
    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

static leImage* getIcon(const leWindowWidget* _this)
{
    LE_ASSERT_THIS();
        
    return (leImage*)_this->icon;
}
                                                              
static leResult setIcon(leWindowWidget* _this,
                        const leImage* img)
{
    LE_ASSERT_THIS();
        
    if(_this->icon == img)
        return LE_SUCCESS;
        
    _this->icon = img;
    
    _invalidateTitleBar(_this);
    
    return LE_SUCCESS;
}

static uint32_t getIconMargin(const leWindowWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->iconMargin;
}
                                               
static leResult setIconMargin(leWindowWidget* _this,
                              uint32_t mg)
{
    LE_ASSERT_THIS();
        
    if(_this->iconMargin == mg)
        return LE_SUCCESS;

    _this->iconMargin = mg;

    _invalidateTitleBar(_this);
    
    return LE_SUCCESS;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leWindowWidget_Paint(leWindowWidget* _this);

void _leWindowWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&windowWidgetVTable);
    
    /* overrides from base class */
    windowWidgetVTable._destructor = destructor;
    windowWidgetVTable._paint = _leWindowWidget_Paint;
    windowWidgetVTable.languageChangeEvent = languageChanging;
    
    /* member functions */
    windowWidgetVTable.getTitle = getTitle;
    windowWidgetVTable.setTitle = setTitle;
    windowWidgetVTable.getIcon = getIcon;
    windowWidgetVTable.setIcon = setIcon;
    windowWidgetVTable.getIconMargin = getIconMargin;
    windowWidgetVTable.setIconMargin = setIconMargin;
}

void _leWindowWidget_FillVTable(leWindowWidgetVTable* tbl)
{
    *tbl = windowWidgetVTable;
}

#endif // LE_WINDOW_WIDGET_ENABLED