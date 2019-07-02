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

#include "gfx/legato/widget/drawsurface/legato_widget_drawsurface.h"

#if LE_DRAWSURFACE_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

static leDrawSurfaceWidgetVTable drawSurfaceWidgetVTable;

void leDrawSurfaceWidget_Constructor(leDrawSurfaceWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&drawSurfaceWidgetVTable;
    _this->fn = &drawSurfaceWidgetVTable;

    _this->widget.type = LE_WIDGET_DRAWSURFACE;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_FILL;

    _this->cb = NULL;
}

void _leWidget_Destructor(leWidget* wgt);

void _leDrawSurfaceWidget_Destructor(leDrawSurfaceWidget* _this)
{
    _leWidget_Destructor((leWidget*)_this);
}

leDrawSurfaceWidget* leDrawSurfaceWidget_New()
{
    leDrawSurfaceWidget* sfc = NULL;

    sfc = LE_MALLOC(sizeof(leDrawSurfaceWidget));

    if(sfc == NULL)
        return NULL;
    
    leDrawSurfaceWidget_Constructor(sfc);

    return sfc;
}

static leDrawSurfaceWidget_DrawCallback getDrawCallback(const leDrawSurfaceWidget* _this)
{
    LE_ASSERT_THIS();

    return _this->cb;
}

static leResult setDrawCallback(leDrawSurfaceWidget* _this,
                                leDrawSurfaceWidget_DrawCallback cb)
{
    LE_ASSERT_THIS();

    if(_this->cb == cb)
        return LE_SUCCESS;

    _this->cb = cb;

    _this->fn->invalidate(_this);
    
    return LE_SUCCESS;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leDrawSurfaceWidget_Paint(leDrawSurfaceWidget* _this);

void _leDrawSurfaceWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&drawSurfaceWidgetVTable);
    
    /* overrides from base class */
    drawSurfaceWidgetVTable._destructor = _leDrawSurfaceWidget_Destructor;
    drawSurfaceWidgetVTable._paint = _leDrawSurfaceWidget_Paint;
    
    /* member functions */
    drawSurfaceWidgetVTable.getDrawCallback = getDrawCallback;
    drawSurfaceWidgetVTable.setDrawCallback = setDrawCallback;
}

void _leDrawSurfaceWidget_FillVTable(leDrawSurfaceWidgetVTable* tbl)
{
    *tbl = drawSurfaceWidgetVTable;
}

#endif // LE_DRAWSURFACE_WIDGET_ENABLED