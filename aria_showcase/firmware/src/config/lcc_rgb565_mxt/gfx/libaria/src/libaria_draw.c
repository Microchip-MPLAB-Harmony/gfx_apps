#include "gfx/libaria/inc/libaria_draw.h"
#include "gfx/libaria/inc/libaria_context.h"

#include "gfx/hal/gfx.h"

void laDraw_LineBorder(GFX_Rect* rect, GFX_Color color)
{
    GFX_Set(GFXF_DRAW_MODE, GFX_DRAW_LINE);

    GFX_Set(GFXF_DRAW_COLOR, color);
    GFX_DrawRect(rect->x, rect->y, rect->width, rect->height);
}

void laDraw_2x1BevelBorder(GFX_Rect* rect,
                           GFX_Color topOuterColor,
                           GFX_Color topInnerColor,
                           GFX_Color bottomOuterColor)
{
    GFX_Set(GFXF_DRAW_MODE, GFX_DRAW_LINE);

    // top outer lines
    GFX_Set(GFXF_DRAW_COLOR, topOuterColor);
    GFX_DrawLine(rect->x,
                 rect->y,
                 rect->x + rect->width - 1,
                 rect->y);

    GFX_DrawLine(rect->x,
                 rect->y + 1,
                 rect->x,
                 rect->y + rect->height - 1);

    // top inner lines
    GFX_Set(GFXF_DRAW_COLOR, topInnerColor);
    GFX_DrawLine(rect->x + 1,
                 rect->y + 1,
                 rect->x + rect->width - 2,
                 rect->y + 1);

    GFX_DrawLine(rect->x + 1,
                 rect->y + 1,
                 rect->x + 1,
                 rect->y + rect->height - 2);

    // bottom outer lines
    GFX_Set(GFXF_DRAW_COLOR, bottomOuterColor);
    GFX_DrawLine(rect->x,
                 rect->y + rect->height - 1,
                 rect->x + rect->width - 1,
                 rect->y + rect->height - 1);
    
    GFX_DrawLine(rect->x + rect->width - 1,
                 rect->y + 1,
                 rect->x + rect->width - 1,
                 rect->y + rect->height - 1);
}

void laDraw_1x2BevelBorder(GFX_Rect* rect,
                           GFX_Color topColor,
                           GFX_Color bottomInnerColor,
                           GFX_Color bottomOuterColor)
{
    GFX_Set(GFXF_DRAW_MODE, GFX_DRAW_LINE);

    // top outer lines
    GFX_Set(GFXF_DRAW_COLOR, topColor);
    GFX_DrawLine(rect->x,
                 rect->y,
                 rect->x + rect->width - 2,
                 rect->y);

    GFX_DrawLine(rect->x,
                 rect->y + 1,
                 rect->x,
                 rect->y + rect->height - 2);

    // bottom inner lines
    GFX_Set(GFXF_DRAW_COLOR, bottomInnerColor);
    GFX_DrawLine(rect->x + 1,
                 rect->y + rect->height - 2,
                 rect->x + rect->width - 2,
                 rect->y + rect->height - 2);
    
    GFX_DrawLine(rect->x + rect->width - 2,
                 rect->y + 1,
                 rect->x + rect->width - 2,
                 rect->y + rect->height - 3);

    // bottom outer lines
    GFX_Set(GFXF_DRAW_COLOR, bottomOuterColor);
    GFX_DrawLine(rect->x,
                 rect->y + rect->height - 1,
                 rect->x + rect->width - 1,
                 rect->y + rect->height - 1);
    
    GFX_DrawLine(rect->x + rect->width - 1,
                 rect->y,
                 rect->x + rect->width - 1,
                 rect->y + rect->height - 2);
}

void laDraw_2x2BevelBorder(GFX_Rect* rect,
                           GFX_Color topOuterColor,
                           GFX_Color topInnerColor,
                           GFX_Color bottomInnerColor,
                           GFX_Color bottomOuterColor)
{
    GFX_Set(GFXF_DRAW_MODE, GFX_DRAW_LINE);

    // top outer lines
    GFX_Set(GFXF_DRAW_COLOR, topOuterColor);
    GFX_DrawLine(rect->x,
                 rect->y,
                 rect->x + rect->width - 2,
                 rect->y);

    GFX_DrawLine(rect->x,
                 rect->y + 1,
                 rect->x,
                 rect->y + rect->height - 2);

    // top inner lines
    GFX_Set(GFXF_DRAW_COLOR, topInnerColor);
    GFX_DrawLine(rect->x + 1,
                 rect->y + 1,
                 rect->x + rect->width - 3,
                 rect->y + 1);

    GFX_DrawLine(rect->x + 1,
                 rect->y + 1,
                 rect->x + 1,
                 rect->y + rect->height - 3);

    // bottom inner lines
    GFX_Set(GFXF_DRAW_COLOR, bottomInnerColor);
    GFX_DrawLine(rect->x + 1,
                 rect->y + rect->height - 2,
                 rect->x + rect->width - 2,
                 rect->y + rect->height - 2);
    
    GFX_DrawLine(rect->x + rect->width - 2,
                 rect->y + 1,
                 rect->x + rect->width - 2,
                 rect->y + rect->height - 3);

    // bottom outer lines
    GFX_Set(GFXF_DRAW_COLOR, bottomOuterColor);
    GFX_DrawLine(rect->x,
                 rect->y + rect->height - 1,
                 rect->x + rect->width - 1,
                 rect->y + rect->height - 1);
    
    GFX_DrawLine(rect->x + rect->width - 1,
                 rect->y,
                 rect->x + rect->width - 1,
                 rect->y + rect->height - 2);
}