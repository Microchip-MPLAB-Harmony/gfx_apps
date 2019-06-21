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

#include "gfx/legato/widget/circle/legato_widget_circle.h"

#if LE_CIRCLE_WIDGET_ENABLED

#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/renderer/legato_renderer.h"
#include "gfx/legato/widget/legato_widget.h"

#include "gfx/legato/widget/legato_widget_skin_classic_common.h"

enum
{
    NOT_STARTED = LE_WIDGET_DRAW_STATE_READY,
    DONE = LE_WIDGET_DRAW_STATE_DONE,
    DRAW_BACKGROUND,
    DRAW_CIRCLE,
    DRAW_BORDER,
};

static struct
{
    uint32_t alpha;
} paintState;

static void drawBackground(leCircleWidget* cir);
static void drawCircle(leCircleWidget* cir);
static void drawBorder(leCircleWidget* cir);

static void nextState(leCircleWidget* cir)
{
    switch(cir->widget.drawState)
    {
        case NOT_STARTED:
        {
#if LE_ALPHA_BLENDING_ENABLED == 1
            if(cir->fn->getCumulativeAlphaEnabled(cir) == LE_TRUE)
            {
                paintState.alpha = cir->fn->getCumulativeAlphaAmount(cir);
            }
#else
            paintState.alpha = 255;
#endif
            
            if(cir->widget.backgroundType != LE_WIDGET_BACKGROUND_NONE) 
            {
                cir->widget.drawState = DRAW_BACKGROUND;
                cir->widget.drawFunc = (leWidget_DrawFunction_FnPtr)&drawBackground;

                return;
            }
        }
        case DRAW_BACKGROUND:
        {
            cir->widget.drawState = DRAW_CIRCLE;
            cir->widget.drawFunc = (leWidget_DrawFunction_FnPtr)&drawCircle;
    
            return;
        }
        case DRAW_CIRCLE:
        {            
            if(cir->widget.borderType != LE_WIDGET_BORDER_NONE)
            {
                cir->widget.drawFunc = (leWidget_DrawFunction_FnPtr)&drawBorder;
                cir->widget.drawState = DRAW_BORDER;
                
                return;
            }
        }
        case DRAW_BORDER:
        {
            cir->widget.drawState = DONE;
            cir->widget.drawFunc = NULL;
        }
    }
}

static void drawBackground(leCircleWidget* cir)
{
    leWidget_SkinClassic_DrawStandardBackground((leWidget*)cir);
    
    nextState(cir);
}

static void drawCircle(leCircleWidget* cir)
{
    lePoint p;
    leRect circleRect;
    
    p.x = cir->x;
    p.y = cir->y;
    
    leUtils_PointToScreenSpace((leWidget*)cir, &p);
    
    circleRect.x = p.x - cir->radius;
    circleRect.y = p.y - cir->radius;
    circleRect.width = cir->radius * 2;
    circleRect.height = cir->radius * 2;
    
    leRenderer_ArcFill(&circleRect,
                       p.x,
                       p.y,
                       cir->radius,
                       0,
                       360,
                       cir->thickness,
                       cir->widget.scheme->foreground,
                       LE_FALSE,
                       paintState.alpha);
        
    if (cir->filled == LE_TRUE && cir->thickness < cir->radius)
    {
        leRenderer_ArcFill(&circleRect,
                           p.x,
                           p.y,
                           cir->radius - cir->thickness,
                           0,
                           360,
                           cir->radius - cir->thickness,
                           cir->widget.scheme->background,
                           LE_FALSE,
                           paintState.alpha);
    }

    nextState(cir);
}

static void drawBorder(leCircleWidget* cir)
{    
    if(cir->widget.borderType == LE_WIDGET_BORDER_LINE)
    {
        leWidget_SkinClassic_DrawStandardLineBorder((leWidget*)cir);
    }
    else if(cir->widget.borderType == LE_WIDGET_BORDER_BEVEL)
    {
        leWidget_SkinClassic_DrawStandardRaisedBorder((leWidget*)cir);
    }
    
    nextState(cir);
}

void _leCircleWidget_Paint(leCircleWidget* cir)
{
    if(cir->widget.scheme == NULL)
    {
        cir->widget.drawState = DONE;
        
        return;
    }
    
    if(cir->widget.drawState == NOT_STARTED)
    {
        nextState(cir);
    }
    
    while(cir->widget.drawState != DONE)
    {
        cir->widget.drawFunc((leWidget*)cir);
        
#if LE_PREEMPTION_LEVEL == 2
        break;
#endif
    }
}

#endif // LE_CIRCLE_WIDGET_ENABLED
