#include "gfx/libaria/inc/libaria_widget_touchtest.h"

#if LA_TOUCHTEST_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_context.h"
#include "gfx/libaria/inc/libaria_draw.h"
#include "gfx/libaria/inc/libaria_layer.h"
#include "gfx/libaria/inc/libaria_string.h"
#include "gfx/libaria/inc/libaria_utils.h"
#include "gfx/libaria/inc/libaria_widget.h"

#include "gfx/libaria/inc/libaria_widget_skin_classic_common.h"

#include "gfx/hal/inc/gfx_math.h"
#include "gfx/hal/inc/gfx_util.h"

enum
{
    NOT_STARTED = LA_WIDGET_DRAW_STATE_READY,
    DONE = LA_WIDGET_DRAW_STATE_DONE,
    DRAW_BACKGROUND,
    DRAW_LINES,
    DRAW_BORDER,
};

void _laTouchTestWidget_GetLineRects(laTouchTestWidget* tch,
                                     uint32_t idx,
                                     GFX_Rect* horzRect,
                                     GFX_Rect* vertRect)
{
    GFX_Rect widgetRect = laUtils_WidgetLayerRect((laWidget*)tch);
    //GFX_Point pnt = tch->pnts[idx];
    
    //laUtils_PointToLayerSpace((laWidget*)tch, 
    
    horzRect->x = widgetRect.x;
    horzRect->y = widgetRect.y + tch->pnts[idx].y;
    horzRect->width = widgetRect.width;
    horzRect->height = 1;

    vertRect->x = widgetRect.x + tch->pnts[idx].x;
    vertRect->y = widgetRect.y;
    vertRect->width = 1;
    vertRect->height = widgetRect.height;
}

static void drawBackground(laTouchTestWidget* tch);
static void drawLines(laTouchTestWidget* tch);
static void drawBorder(laTouchTestWidget* tch);

static void nextState(laTouchTestWidget* tch)
{
    switch(tch->widget.drawState)
    {
        case NOT_STARTED:
        {
            if(tch->widget.backgroundType != LA_WIDGET_BACKGROUND_NONE) 
            {
                tch->widget.drawState = DRAW_BACKGROUND;
                tch->widget.drawFunc = (laWidget_DrawFunction_FnPtr)&drawBackground;

                return;
            }
        }
        case DRAW_BACKGROUND:
        {
            if(tch->size > 0)
            {
                tch->widget.drawState = DRAW_LINES;
                tch->widget.drawFunc = (laWidget_DrawFunction_FnPtr)&drawLines;
                
                return;
            }
        }
        case DRAW_LINES:
        {
            if(tch->widget.borderType != LA_WIDGET_BORDER_NONE)
            {
                tch->widget.drawFunc = (laWidget_DrawFunction_FnPtr)&drawBorder;
                tch->widget.drawState = DRAW_BORDER;
                
                return;
            }
        }
        case DRAW_BORDER:
        {
            tch->widget.drawState = DONE;
            tch->widget.drawFunc = NULL;
        }
    }
}

static void drawBackground(laTouchTestWidget* tch)
{
    laWidget_SkinClassic_DrawStandardBackground((laWidget*)tch);
    
    nextState(tch);
}

static void drawLines(laTouchTestWidget* tch)
{
    GFX_Rect widgetRect, vertRect, horzRect, clipRect;
    uint32_t per;
    uint32_t i, j;
    GFX_Color c1, c2;
    
    laLayer* layer = laUtils_GetLayer((laWidget*)tch);
    
    widgetRect = laUtils_WidgetLayerRect((laWidget*)tch);
    
    // draw lines
    j = tch->start;
    
    GFX_Set(GFXF_DRAW_MASK_ENABLE, GFX_FALSE);
    GFX_Set(GFXF_DRAW_MODE, GFX_DRAW_FILL);
    
    for(i = 0; i < tch->size; i++)
    {
        if(j >= tch->size)
            j = 0;
            
        _laTouchTestWidget_GetLineRects(tch, j, &horzRect, &vertRect);
        
        if(GFX_RectIntersects(&horzRect, &layer->clippedDrawingRect) == GFX_TRUE)
        {
            GFX_RectClip(&horzRect, &layer->clippedDrawingRect, &clipRect);
            
            per = GFX_PercentWholeRounded(tch->pnts[j].y, widgetRect.height);
            
            c1 = tch->widget.scheme->foreground;
            c2 = tch->widget.scheme->foregroundInactive;
            
            GFX_Set(GFXF_DRAW_COLOR, GFX_ColorLerp(c1,
                                                   c2,
                                                   per,
                                                   laContext_GetActive()->colorMode));
            
            GFX_DrawRect(clipRect.x,
                         clipRect.y,
                         clipRect.width,
                         clipRect.height);
        }
        
        if(GFX_RectIntersects(&vertRect, &layer->clippedDrawingRect) == GFX_TRUE)
        {
            GFX_RectClip(&vertRect, &layer->clippedDrawingRect, &clipRect);
        
            per = GFX_PercentWholeRounded(tch->pnts[j].x, widgetRect.width);
            
            c1 = tch->widget.scheme->background;
            c2 = tch->widget.scheme->backgroundInactive;
            
            GFX_Set(GFXF_DRAW_COLOR, GFX_ColorLerp(c1,
                                                   c2,
                                                   per,
                                                   laContext_GetActive()->colorMode));
            
            GFX_DrawRect(clipRect.x,
                         clipRect.y,
                         clipRect.width,
                         clipRect.height);
        }
        
        j++;
    }

    nextState(tch);
}

static void drawBorder(laTouchTestWidget* tch)
{
    if(tch->widget.borderType == LA_WIDGET_BORDER_LINE)
        laWidget_SkinClassic_DrawStandardLineBorder((laWidget*)tch);
    else if(tch->widget.borderType == LA_WIDGET_BORDER_BEVEL)
        laWidget_SkinClassic_DrawStandardRaisedBorder((laWidget*)tch);
    
    nextState(tch);
}

void _laTouchTestWidget_Paint(laTouchTestWidget* tch)
{
    laContext* context = laContext_GetActive();
    
    if(tch->widget.scheme == NULL)
    {
        tch->widget.drawState = DONE;
        
        return;
    }

    if(tch->widget.drawState == NOT_STARTED)
        nextState(tch);
    
    while(tch->widget.drawState != DONE)
    {
        tch->widget.drawFunc((laWidget*)tch);
        
        if(context->preemptLevel == LA_PREEMPTION_LEVEL_2)
            break;
    }
}

#endif // LA_TOUCHTEST_WIDGET_ENABLED