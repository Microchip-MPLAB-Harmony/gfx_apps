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

#include "gfx/legato/widget/radialmenu/legato_widget_radial_menu.h"

#if LE_RADIAL_MENU_WIDGET_ENABLED

#include "gfx/legato/common/legato_math.h"
#include "gfx/legato/common/legato_utils.h"
#include "gfx/legato/renderer/legato_renderer.h"
#include "gfx/legato/string/legato_string.h"
#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/widget/legato_widget_skin_classic_common.h"

enum
{
    NOT_STARTED = LE_WIDGET_DRAW_STATE_READY,
    DONE = LE_WIDGET_DRAW_STATE_DONE,
    DRAW_BACKGROUND,
	ARRANGE_ITEMS,
	DRAW_ELLIPSE,
};

static struct
{
    uint32_t alpha;
} paintState;

static void drawBackground(leRadialMenuWidget* mn);
static void drawEllipse(leRadialMenuWidget* mn);
static void arrangeItems(leRadialMenuWidget* mn);

static void nextState(leRadialMenuWidget* mn)
{
    switch(mn->widget.drawState)
    {
        case NOT_STARTED:
        {
#if LE_ALPHA_BLENDING_ENABLED == 1
            if(mn->fn->getCumulativeAlphaEnabled(mn) == LE_TRUE)
            {
                paintState.alpha = mn->fn->getCumulativeAlphaAmount(mn);
            }
#else
            paintState.alpha = 255;
#endif

            if(mn->widget.backgroundType != LE_WIDGET_BACKGROUND_NONE) 
            {
                mn->widget.drawState = DRAW_BACKGROUND;
                mn->widget.drawFunc = (leWidget_DrawFunction_FnPtr)&drawBackground;

                return;
            }
        }
        case DRAW_BACKGROUND:
        {
            if(mn->drawEllipse == LE_TRUE)
            {
                mn->widget.drawState = DRAW_ELLIPSE;
                mn->widget.drawFunc = (leWidget_DrawFunction_FnPtr)&drawEllipse;
            }
            else
            {
                mn->widget.drawState = ARRANGE_ITEMS;
                mn->widget.drawFunc = (leWidget_DrawFunction_FnPtr)&arrangeItems;                
            }
            return;
        }
        case DRAW_ELLIPSE:
        {            
            if(mn->widgetList.size > 0)
            {
                mn->widget.drawState = ARRANGE_ITEMS;
                mn->widget.drawFunc = (leWidget_DrawFunction_FnPtr)&arrangeItems;                
            }
            else
            {
                mn->widget.drawState = DONE;
                mn->widget.drawFunc = NULL;                
            }
            return;
        }
        case ARRANGE_ITEMS:
        {
            mn->widget.drawState = DONE;
            mn->widget.drawFunc = NULL;                
            return;
        }
    }
}

static void drawBackground(leRadialMenuWidget* mn)
{
    leWidget_SkinClassic_DrawBackground(&mn->widget, mn->widget.scheme->background);        

    nextState(mn);
}

static void drawEllipse(leRadialMenuWidget* mn)
{
    lePoint centerPoint = lePoint_Zero;
    
    leUtils_PointToScreenSpace((leWidget*)mn, &centerPoint);

    centerPoint.x += mn->widget.rect.width / 2;
    centerPoint.y += mn->widget.rect.height / 2;
    
    leRenderer_EllipseLine(centerPoint.x,
                           centerPoint.y,
                           mn->a,
                           mn->b,
                           mn->theta,
                           0,
                           360,
                           mn->widget.scheme->foreground,
                           paintState.alpha);
    
    nextState(mn);
}

//Weigh the angle t between 90 (prominent) and 270 (sunken) and returns a percent, t has to be between 0 to 360
uint32_t _weighAngle(int32_t t)
{
    int32_t angle;
    
    t = leNormalize360(t);
    
    if (t >= 90 && t <= 270)
    {
        angle = t - 90;
    }
    else if (t < 90)
    {
        angle = 90 - t;
    }
    else
    {
        angle = 450 - t;
    }

    //Calculate the percent scale relative to prominent (90) and minimum (270)
    return lePercentWholeRounded(angle, 180);
}

static leResult _insertionSort(leList* list, leRadialMenuItemNode* item)
{
    uint32_t i, percentTest, percentNew; 
    leRadialMenuItemNode* testItem;
    
    if (list->size == 0)
    {
        leList_PushFront(list, item);
        return LE_SUCCESS;
    }
    
    percentNew = _weighAngle(item->t);

    for(i = 0; i < list->size; ++i)
    {
        testItem = leList_Get(list,i);

        percentTest = _weighAngle(testItem->t);

        if (percentNew > percentTest)
        {
            leList_InsertAt(list, item, i);
            return LE_SUCCESS;
        }
    }

    //if we got here without an insertion, item goes to the back
    leList_PushBack(list, item);
    
    return LE_SUCCESS;
}

static void arrangeItems(leRadialMenuWidget* mn)
{
    lePoint itemPos;
//    leRect mnScreenRect;
    leRadialMenuItemNode* item;
    uint32_t i,percent;
    leList drawOrderList;
    
    leList_Create(&drawOrderList);

//    mnScreenRect = leWidget_RectToScreenSpace((leWidget*)mn);
    for (i = 0; i < mn->hiddenList.size; ++i)
    {
        item = leList_Get(&mn->hiddenList, i);

        item->widget->fn->setVisible(item->widget, LE_FALSE);
    }
    
    for (i = 0; i < mn->shownList.size; ++i)
    {
        item = leList_Get(&mn->shownList, i);
        
        percent = 100 - _weighAngle(item->t);

        switch(mn->blendMode)
        {
            case LE_RADIAL_MENU_INTERPOLATE_GRADUAL:
            {
                item->widget->alphaAmount = leLerp(mn->minAlphaAmount, mn->maxAlphaAmount, percent);                
            
                break;
            }
            case LE_RADIAL_MENU_INTERPOLATE_OFF:
            {
                item->widget->alphaAmount = item->origAlphaAmount;
            
                break;
            }
            case LE_RADIAL_MENU_INTERPOLATE_PROMINENT:
            {
                if (mn->fn->isProminent(mn, item->widget))
                {
                    item->widget->alphaAmount = mn->maxAlphaAmount;
                }
                else
                {
                    item->widget->alphaAmount = mn->minAlphaAmount;
                }                
            
                break;
            }
        }

        switch(mn->scaleMode)
        {
            case LE_RADIAL_MENU_INTERPOLATE_GRADUAL:
            {
                item->widget->rect.width = item->origSize.width * leLerp(mn->minSizePercent, mn->maxSizePercent, percent) / 100;                
                item->widget->rect.height = item->origSize.height * leLerp(mn->minSizePercent, mn->maxSizePercent, percent) / 100;                
            
                break;
            }
            case LE_RADIAL_MENU_INTERPOLATE_OFF:
            {
                item->widget->rect.width = item->origSize.width;
                item->widget->rect.height = item->origSize.height;        
            
                break;
            }
            case LE_RADIAL_MENU_INTERPOLATE_PROMINENT:
            {
                if(mn->fn->isProminent(mn, item->widget))
                {
                    item->widget->rect.width = item->origSize.width * (int32_t)mn->maxSizePercent / 100;
                    item->widget->rect.height = item->origSize.height * (int32_t)mn->maxSizePercent / 100;                
                }
                else
                {
                    item->widget->rect.width = item->origSize.width * (int32_t)mn->minSizePercent / 100;
                    item->widget->rect.height = item->origSize.height * (int32_t)mn->minSizePercent / 100;        
                }                
            
                break;
            }
        }

        //Establish widget positions
        leEllipsePoint(item->t, mn->a, mn->b, mn->theta, &itemPos);

        itemPos.x = itemPos.x + mn->widget.rect.width / 2 - item->widget->rect.width / 2;
        itemPos.y = itemPos.y + mn->widget.rect.height / 2 - item->widget->rect.height / 2;
        
        item->widget->fn->setPosition(item->widget, itemPos.x, itemPos.y);        
        
        //This step is to setup arranging the draw order of each item
        leArray_Remove(&mn->widget.children, item->widget);
        
        item->widget->fn->setVisible(item->widget, LE_TRUE);
        
        //Sort by inserting into empty list
        _insertionSort(&drawOrderList, item);
    }

    //Re-add each widget item back as child from back to front
    for (i = 0; i < drawOrderList.size; ++i)
    {
        item = leList_Get(&drawOrderList, i);

        leArray_PushBack(&mn->widget.children, item->widget);
    }

    leList_Clear(&drawOrderList);

    nextState(mn);
}

void _leRadialMenuWidget_Paint(leRadialMenuWidget* mn)
{
    if(mn->widget.scheme == NULL)
    {
        mn->widget.drawState = DONE;
        
        return;
    }
    
    if(mn->widget.drawState == NOT_STARTED)
    {
        nextState(mn);
    }
    
    while(mn->widget.drawState != DONE)
    {
        mn->widget.drawFunc((leWidget*)mn);
        
#if LE_PREEMPTION_LEVEL == 2
        break;
#endif
    }
}

#endif // LE_RADIALMENU_WIDGET_ENABLED