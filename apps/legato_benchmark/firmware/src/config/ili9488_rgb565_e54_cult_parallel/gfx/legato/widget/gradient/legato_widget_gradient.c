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

#include "gfx/legato/widget/gradient/legato_widget_gradient.h"

#if LE_GRADIENT_WIDGET_ENABLED

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"

#define DEFAULT_WIDTH           100
#define DEFAULT_HEIGHT          100

static leGradientWidgetVTable gradientWidgetVTable;

void leGradientWidget_Constructor(leGradientWidget* _this)
{
    leWidget_Constructor((leWidget*)_this);
    
    _this->widget.fn = (void*)&gradientWidgetVTable;
    _this->fn = &gradientWidgetVTable;
    
    _this->widget.type = LE_WIDGET_GRADIENT;

    _this->widget.rect.width = DEFAULT_WIDTH;
    _this->widget.rect.height = DEFAULT_HEIGHT;

    _this->widget.borderType = LE_WIDGET_BORDER_NONE;
    _this->widget.backgroundType = LE_WIDGET_BACKGROUND_FILL;

    _this->dir = LE_DIRECTION_RIGHT;
}

void _leWidget_Destructor(leWidget* _this);

void _leGradientWidget_Destructor(leGradientWidget* _this)
{
    _leWidget_Destructor((leWidget*)_this);
}

leGradientWidget* leGradientWidget_New()
{
    leGradientWidget* grad = NULL;

    grad = LE_MALLOC(sizeof(leGradientWidget));

    if(grad == NULL)
        return NULL;
    
    leGradientWidget_Constructor(grad);

    return grad;
}

static leDirection getDirection(const leGradientWidget* _this)
{
    LE_ASSERT_THIS();
        
    return _this->dir;
}

static leResult setDirection(leGradientWidget* _this,
                             leDirection dir)
{
    LE_ASSERT_THIS();
        
    if(_this->dir == dir)
        return LE_SUCCESS;
        
    _this->dir = dir;
    
    _this->fn->invalidate(_this);
        
    return LE_SUCCESS;
}

void _leWidget_FillVTable(leWidgetVTable* tbl);
void _leGradientWidget_Paint(leGradientWidget* _this);

void _leGradientWidget_GenerateVTable()
{
    _leWidget_FillVTable((void*)&gradientWidgetVTable);
    
    /* overrides from base class */
    gradientWidgetVTable._destructor = _leGradientWidget_Destructor;
    gradientWidgetVTable._paint = _leGradientWidget_Paint;
    
    /* member functions */
    gradientWidgetVTable.getDirection = getDirection;
    gradientWidgetVTable.setDirection = setDirection;
}

void _leGradientWidget_FillVTable(leGradientWidgetVTable* tbl)
{
    *tbl = gradientWidgetVTable;
}

#endif // LE_GRADIENT_WIDGET_ENABLED