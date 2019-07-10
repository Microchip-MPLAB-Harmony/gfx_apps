#include "gfx/legato/renderer/legato_renderer.h"

#include "gfx/legato/common/legato_math.h"
#include "gfx/legato/datastructure/legato_rectarray.h"

leResult leRenderer_RectLine(const leRect* rect,
                             leColor clr,
                             uint32_t a)
{
    leRenderer_HorzLine(rect->x,
                        rect->y,
                        rect->width - 1,
                        clr,
                        a);
                        
    leRenderer_HorzLine(rect->x,
                        rect->y + rect->height - 1,
                        rect->width - 1,
                        clr,
                        a);
                        
    leRenderer_VertLine(rect->x,
                        rect->y,
                        rect->height - 1,
                        clr,
                        a);
                        
    leRenderer_VertLine(rect->x + rect->width - 1,
                        rect->y,
                        rect->height - 1,
                        clr,
                        a);
    
    return LE_SUCCESS;
}

leResult leRenderer_RectFill(const leRect* rect,
                             leColor clr,
                             uint32_t a)
{
    leRect clipRect;
    lePoint pnt;
    int32_t w, h;
    
    if(leRenderer_CullDrawRect(rect) == LE_TRUE)
        return LE_FAILURE;
        
    leRenderer_ClipDrawRect(rect, &clipRect);
    
    a = leClampi(0, 255, a);
    
    if(a < 255)
    {
        for(h = 0; h < clipRect.height; h++)
        {
            for(w = 0; w < clipRect.width; w++)
            {
                pnt.x = clipRect.x + w;
                pnt.y = clipRect.y + h;
                
                leRenderer_BlendPixel(pnt.x, pnt.y, clr, a);
            }
        } 
    }
    else
    {
        for(h = 0; h < clipRect.height; h++)
        {
            for(w = 0; w < clipRect.width; w++)
            {
                pnt.x = clipRect.x + w;
                pnt.y = clipRect.y + h;
                
                leRenderer_PutPixel(pnt.x, pnt.y, clr);
            }
        } 
    }
    
    
    
    return LE_SUCCESS;
}

leResult leRenderer_HorzGradientRect(const leRect* rect,
                                     leColor clr1,
                                     leColor clr2,
                                     uint32_t a)
{
    lePoint drawPoint;
    leColorMode mode = leGetRenderState()->colorMode;
    leColor clr;
    int32_t val;
    uint32_t percent;
    
    // calculate minimums
    drawPoint.y = rect->y;
    
    for(drawPoint.x = rect->x; drawPoint.x < rect->x + rect->width; drawPoint.x++)
    {
        val = drawPoint.x - rect->x;
        
        percent = lePercentWholeRounded(val, rect->width);
        
        clr = leColorLerp(clr1, clr2, percent, mode);
                                 
        leRenderer_VertLine(drawPoint.x,
                            drawPoint.y,
                            rect->y + rect->height - 1,
                            clr,
                            a);
    }
    
    return LE_SUCCESS;
}
                                          
leResult leRenderer_VertGradientRect(const leRect* rect,
                                     leColor clr1,
                                     leColor clr2,
                                     uint32_t a)
{
    lePoint drawPoint;
    leColorMode mode = leGetRenderState()->colorMode;
    leColor clr;
    int32_t val;
    uint32_t percent;
    
    // calculate minimums
    drawPoint.x = rect->x; 
    
    for(drawPoint.y = rect->y; drawPoint.y < rect->y + rect->height; drawPoint.y++)
    {
        val = drawPoint.y - rect->y;
        
        percent = lePercentWholeRounded(val, rect->height);
        
        clr = leColorLerp(clr1, clr2, percent, mode);
                                 
        leRenderer_HorzLine(drawPoint.x,
                            drawPoint.y,
                            rect->x + rect->width - 1,
                            clr,
                            a);
    }
    
    return LE_SUCCESS;
}