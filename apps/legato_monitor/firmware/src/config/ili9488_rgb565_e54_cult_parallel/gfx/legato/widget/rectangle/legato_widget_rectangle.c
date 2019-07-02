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

#include "gfx/legato/widget/rectangle/legato_widget_rectangle.h"

#if LE_RECTANGLE_WIDGET_ENABLED == 1

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

#define DEFAULT_THICKNESS       2

static leRectangleWidgetVTable rectangleWidgetVTable;

void _leRectangleWidget_InvalidateRect(leRectangleWidget* rct);

void leRectangleWidget_Constructor(leRectangleWidget* _this)
{
    LE_ASSERT_THIS();
    
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&rectangleWidgetVTable;
    _this->fn = &rectangleWidgetVTable;
    
    _this->widget.type = LE_WIDGET_RECTANGLE;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_FILL;

    _this->thickness = DEFAULT_THICKNESS;
}

leRectangleWidget* leRectangleWidget_New()
{
    leRectangleWidget* rect = NULL;

    rect = LE_MALLOC(sizeof(leRectangleWidget));

    if(rect == NULL)
        return NULL;
    
    leRectangleWidget_Constructor(rect);

    return rect;
}

void _leWidget_Destructor(leWidget* _this);

static void _leRectangleWidget_Destructor(leRectangleWidget* _this)
{
    LE_ASSERT_THIS();
    
    _leWidget_Destructor((leWidget*)_this);
}

static int32_t _leRectangleWidget_GetThickness(const leRectangleWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->thickness;
}

static leResult _leRectangleWidget_SetThickness(leRectangleWidget* _this,
                                                int32_t thk)
{
    LE_ASSERT_THIS();
    
    if(thk < 0)
        return LE_FAILURE;
        
    if(_this->thickness == thk)
        return LE_SUCCESS;
        
    _leRectangleWidget_InvalidateRect(_this);
        
    _this->thickness = thk;
    
    _leRectangleWidget_InvalidateRect(_this);
            
    return LE_SUCCESS;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leRectangleWidget_Paint(leRectangleWidget* rect);

void _leRectangleWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&rectangleWidgetVTable);
    
    /* overrides from base class */
    rectangleWidgetVTable._destructor = _leRectangleWidget_Destructor;
    rectangleWidgetVTable._paint = _leRectangleWidget_Paint;
    
    /* member functions */
    rectangleWidgetVTable.getThickness = _leRectangleWidget_GetThickness;
    rectangleWidgetVTable.setThickness = _leRectangleWidget_SetThickness;
}

void _leRectangleWidget_FillVTable(leRectangleWidgetVTable* tbl)
{
    *tbl = rectangleWidgetVTable;
}

#endif // LE_RECTANGLE_WIDGET_ENABLED