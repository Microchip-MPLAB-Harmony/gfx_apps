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

#include "gfx/legato/widget/line/legato_widget_line.h"

#if LE_LINE_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

static leLineWidgetVTable lineWidgetVTable;

void leLineWidget_Constructor(leLineWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&lineWidgetVTable;
    _this->fn = &lineWidgetVTable;
    
    _this->widget.type = LE_WIDGET_LINE;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_NONE;

    _this->x1 = 0;
    _this->y1 = 0;
    _this->x2 = DEFAULT_WIDTH - 1;
    _this->y2 = DEFAULT_HEIGHT - 1;
}

void _leWidget_Destructor(leWidget* wgt);

static void destructor(leLineWidget* _this)
{
    _leWidget_Destructor((leWidget*)_this);
}

leLineWidget* leLineWidget_New()
{
    leLineWidget* line = NULL;

    line = LE_MALLOC(sizeof(leLineWidget));

    if(line == NULL)
        return NULL;
    
    leLineWidget_Constructor(line);

    return line;
}

static lePoint getStartPoint(const leLineWidget* _this)
{
    lePoint pnt;
    
    LE_ASSERT_THIS();
    
    pnt.x = _this->x1;
    pnt.y = _this->y1;
        
    return pnt;
}

static leResult setStartPoint(leLineWidget* _this,
                              int32_t x,
                              int32_t y)
{
    LE_ASSERT_THIS();
        
    if(_this->x1 == x && _this->y1 == y)
        return LE_SUCCESS;
        
    _this->x1 = x;
    _this->y1 = y;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

static lePoint getEndPoint(const leLineWidget* _this)
{
    lePoint pnt;
    
    LE_ASSERT_THIS();
    
    pnt.x = _this->x2;
    pnt.y = _this->y2;
        
    return pnt;
}

static leResult setEndPoint(leLineWidget* _this,
                            int32_t x,
                            int32_t y)
{
    LE_ASSERT_THIS();
        
    if(_this->x2 == x && _this->y2 == y)
        return LE_SUCCESS;
        
    _this->x2 = x;
    _this->y2 = y;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leLineWidget_Paint(leLineWidget* _this);

void _leLineWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&lineWidgetVTable);
    
    /* overrides from base class */
    lineWidgetVTable._destructor = destructor;
    lineWidgetVTable._paint = _leLineWidget_Paint;
    
    /* member functions */
    lineWidgetVTable.getStartPoint = getStartPoint;
    lineWidgetVTable.setStartPoint = setStartPoint;
    lineWidgetVTable.getEndPoint = getEndPoint;
    lineWidgetVTable.setEndPoint = setEndPoint;
}

void _leLineWidget_FillVTable(leLineWidgetVTable* tbl)
{
    *tbl = lineWidgetVTable;
}

#endif // LE_LINE_WIDGET_ENABLED