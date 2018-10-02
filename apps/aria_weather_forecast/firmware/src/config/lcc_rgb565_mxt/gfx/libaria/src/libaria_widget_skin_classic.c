#include "gfx/libaria/inc/libaria_widget.h"

#include "gfx/libaria/inc/libaria_context.h"
#include "gfx/libaria/inc/libaria_draw.h"
#include "gfx/libaria/inc/libaria_utils.h"

#include "gfx/libaria/inc/libaria_widget_skin_classic_common.h"

enum
{
    NOT_STARTED = LA_WIDGET_DRAW_STATE_READY,
    DONE = LA_WIDGET_DRAW_STATE_DONE,
    DRAW_BORDER,
};

static void drawBackground(laWidget* wdg);
static void drawBorder(laWidget* wdg);

static void drawBackground(laWidget* wdg)
{
    //GFX_Rect rect;
    
    //printf("button painting\n");
    
    if(wdg->backgroundType == LA_WIDGET_BACKGROUND_FILL)
    {
        //Only support round corners for no or line borders
        if (wdg->cornerRadius > 0 && 
            (wdg->borderType == LA_WIDGET_BORDER_NONE || 
             wdg->borderType == LA_WIDGET_BORDER_LINE))
        {
            laWidget_SkinClassic_DrawRoundCornerBackground(wdg, wdg->scheme->base);
        }
        else
        {
            laWidget_SkinClassic_DrawBackground(wdg, wdg->scheme->base);
        }
        
    }
    else if(wdg->backgroundType == LA_WIDGET_BACKGROUND_CACHE)
        laWidget_SkinClassic_DrawBlit(wdg, wdg->cache);

    if(wdg->borderType != LA_WIDGET_BORDER_NONE)
    {
        wdg->drawState = DRAW_BORDER;
        wdg->drawFunc = (laWidget_DrawFunction_FnPtr)&drawBorder;
    }
    else
    {
        wdg->drawState = DONE;
        wdg->drawFunc = NULL;
        
        return;
    }
    
    if(laContext_GetActive()->preemptLevel < LA_PREEMPTION_LEVEL_2)
        wdg->drawFunc((laWidget*)wdg);
}

static void drawBorder(laWidget* wdg)
{
    if(wdg->borderType == LA_WIDGET_BORDER_LINE)
        laWidget_SkinClassic_DrawStandardLineBorder(wdg);
    else if(wdg->borderType == LA_WIDGET_BORDER_BEVEL)
        laWidget_SkinClassic_DrawStandardRaisedBorder(wdg);
        
    wdg->drawState = DONE;
    wdg->drawFunc = NULL;
}

void _laWidget_Paint(laWidget* wdg)
{
    if(wdg->scheme == NULL)
    {
        wdg->drawState = DONE;
        
        return;
    }
    
    if(wdg->drawState == NOT_STARTED)
        wdg->drawFunc = (laWidget_DrawFunction_FnPtr)&drawBackground;
    
    wdg->drawFunc((laWidget*)wdg);
}