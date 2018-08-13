#include "gfx/libaria/inc/libaria_widget_rectangle.h"

#if LA_RECTANGLE_WIDGET_ENABLED

#include "gfx/libaria/inc/libaria_context.h"
#include "gfx/libaria/inc/libaria_draw.h"
#include "gfx/libaria/inc/libaria_layer.h"
#include "gfx/libaria/inc/libaria_string.h"
#include "gfx/libaria/inc/libaria_utils.h"
#include "gfx/libaria/inc/libaria_widget.h"

#include "gfx/libaria/inc/libaria_widget_skin_classic_common.h"

enum
{
    NOT_STARTED = LA_WIDGET_DRAW_STATE_READY,
    DONE = LA_WIDGET_DRAW_STATE_DONE,
    DRAW_BACKGROUND,
    DRAW_EDGE,
    DRAW_BORDER,
};

static void drawBackground(laRectangleWidget* rct);
static void drawEdge(laRectangleWidget* rct);
static void drawBorder(laRectangleWidget* rct);

void _laRectangleWidget_InvalidateRect(laRectangleWidget* rct)
{
	GFX_Rect rect, dmgRect;
	
	if(rct->thickness == 0)
	    return;
	    
	rect = laUtils_WidgetLayerRect((laWidget*)rct);
	    
	if(rect.width <= rct->thickness || rect.height <= rct->thickness)
	{
	    laWidget_Invalidate((laWidget*)rct);

		return;
	}

	// left line
	dmgRect.x = rect.x;
	dmgRect.y = rect.y;
	dmgRect.width = rct->thickness;
	dmgRect.height = rect.height;

	laLayer_AddDamageRect(laUtils_GetLayer((laWidget*)rct), &dmgRect, LA_TRUE);

	// top line
	dmgRect.width = rect.width;
	dmgRect.height = rct->thickness;

	laLayer_AddDamageRect(laUtils_GetLayer((laWidget*)rct), &dmgRect, LA_TRUE);

	// right line
	dmgRect.x = rect.x + rect.width - rct->thickness;
	dmgRect.y = rect.y;
	dmgRect.width = rct->thickness;
	dmgRect.height = rect.height;

	laLayer_AddDamageRect(laUtils_GetLayer((laWidget*)rct), &dmgRect, LA_TRUE);

	// bottom line
	dmgRect.x = rect.x;
	dmgRect.y = rect.y + rect.height - rct->thickness;
	dmgRect.width = rect.width;
	dmgRect.height = rct->thickness;

	laLayer_AddDamageRect(laUtils_GetLayer((laWidget*)rct), &dmgRect, LA_TRUE);
}

static void nextState(laRectangleWidget* rct)
{
    switch(rct->widget.drawState)
    {
        case NOT_STARTED:
        {
            if(rct->widget.backgroundType != LA_WIDGET_BACKGROUND_NONE) 
            {
                rct->widget.drawState = DRAW_BACKGROUND;
                rct->widget.drawFunc = (laWidget_DrawFunction_FnPtr)&drawBackground;

                return;
            }
        }
        case DRAW_BACKGROUND:
        {
            if(rct->thickness > 0)
            {
                rct->widget.drawState = DRAW_EDGE;
                rct->widget.drawFunc = (laWidget_DrawFunction_FnPtr)&drawEdge;
                
                return;
            }
        }
        case DRAW_EDGE:
        {            
            if(rct->widget.borderType != LA_WIDGET_BORDER_NONE)
            {
                rct->widget.drawFunc = (laWidget_DrawFunction_FnPtr)&drawBorder;
                rct->widget.drawState = DRAW_BORDER;
                
                return;
            }
        }
        case DRAW_BORDER:
        {
            rct->widget.drawState = DONE;
            rct->widget.drawFunc = NULL;
        }
    }
}

static void drawBackground(laRectangleWidget* rct)
{
    laWidget_SkinClassic_DrawStandardBackground((laWidget*)rct);
    
    nextState(rct);
}

static void drawEdge(laRectangleWidget* rct)
{
    GFX_Rect widgetRect, edgeRect, clipRect;
    laLayer* layer = laUtils_GetLayer((laWidget*)rct);
    
    widgetRect = laUtils_WidgetLocalRect((laWidget*)rct);

    // move the rect to parent space
    laUtils_RectToLayerSpace((laWidget*)rct, &widgetRect);
    
    GFX_Set(GFXF_DRAW_MODE, GFX_DRAW_FILL);
    GFX_Set(GFXF_DRAW_COLOR, rct->widget.scheme->foreground);
    
    // left bar
    edgeRect.x = widgetRect.x;
    edgeRect.y = widgetRect.y;
    edgeRect.width = rct->thickness;
    edgeRect.height = widgetRect.height; 
    
    if(GFX_RectIntersects(&layer->clippedDrawingRect, &edgeRect) == GFX_TRUE)
    {
        GFX_RectClip(&edgeRect, &layer->clippedDrawingRect, &clipRect);
    
        GFX_DrawRect(edgeRect.x,
                     edgeRect.y,
                     edgeRect.width,
                     edgeRect.height);
    }
                 
    // top bar
    edgeRect.x = widgetRect.x + rct->thickness;
    edgeRect.width = widgetRect.width - (rct->thickness * 2);
    edgeRect.height = rct->thickness; 
                 
    if(GFX_RectIntersects(&layer->clippedDrawingRect, &edgeRect) == GFX_TRUE)
    {
        GFX_RectClip(&edgeRect, &layer->clippedDrawingRect, &clipRect);
    
        GFX_DrawRect(edgeRect.x,
                     edgeRect.y,
                     edgeRect.width,
                     edgeRect.height);
    }
                 
    // right bar
    edgeRect.x = widgetRect.x + widgetRect.width - rct->thickness;
    edgeRect.width = rct->thickness;
    edgeRect.height = widgetRect.height; 
                 
    if(GFX_RectIntersects(&layer->clippedDrawingRect, &edgeRect) == GFX_TRUE)
    {
        GFX_RectClip(&edgeRect, &layer->clippedDrawingRect, &clipRect);
    
        GFX_DrawRect(edgeRect.x,
                     edgeRect.y,
                     edgeRect.width,
                     edgeRect.height);
    }
                 
    // bottom bar
    edgeRect.x = widgetRect.x + rct->thickness;
    edgeRect.y = widgetRect.y + widgetRect.height - rct->thickness;
    edgeRect.width = widgetRect.width - (rct->thickness * 2);
    edgeRect.height = rct->thickness; 
                 
    if(GFX_RectIntersects(&layer->clippedDrawingRect, &edgeRect) == GFX_TRUE)
    {
        GFX_RectClip(&edgeRect, &layer->clippedDrawingRect, &clipRect);
    
        GFX_DrawRect(edgeRect.x,
                     edgeRect.y,
                     edgeRect.width,
                     edgeRect.height);
    }
    
    nextState(rct);
}

static void drawBorder(laRectangleWidget* rct)
{
    if(rct->widget.borderType == LA_WIDGET_BORDER_LINE)
        laWidget_SkinClassic_DrawStandardLineBorder((laWidget*)rct);
    else if(rct->widget.borderType == LA_WIDGET_BORDER_BEVEL)
        laWidget_SkinClassic_DrawStandardRaisedBorder((laWidget*)rct);
    
    nextState(rct);
}

void _laRectangleWidget_Paint(laRectangleWidget* rct)
{
    laContext* context = laContext_GetActive();
    
    if(rct->widget.scheme == NULL)
    {
        rct->widget.drawState = DONE;
        
        return;
    }
    
    if(rct->widget.drawState == NOT_STARTED)
        nextState(rct);
    
    while(rct->widget.drawState != DONE)
    {
        rct->widget.drawFunc((laWidget*)rct);
        
        if(context->preemptLevel == LA_PREEMPTION_LEVEL_2)
            break;
    }
}

#endif // LA_RECTANGLE_WIDGET_ENABLED