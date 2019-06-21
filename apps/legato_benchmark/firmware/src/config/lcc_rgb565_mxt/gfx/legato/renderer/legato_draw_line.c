#include "gfx/legato/renderer/legato_renderer.h"

#include "gfx/legato/common/legato_math.h"
#include "gfx/legato/datastructure/legato_rectarray.h"

leResult leRenderer_HorzLine(int32_t x,
                             int32_t y,
                             int32_t w,
                             leColor clr,
                             uint32_t a)
{
    leRect clipRect;
    leRect drawRect;
    lePoint pnt;
    int32_t i;
    
    drawRect.x = x;
    drawRect.y = y;
    drawRect.width = w;
    drawRect.height = 1;
    
    if(leRenderer_CullDrawRect(&drawRect) == LE_TRUE)
        return LE_FAILURE;
        
    leRenderer_ClipDrawRect(&drawRect, &clipRect);
    
    pnt.y = clipRect.y;
    
    a = leClampi(0, 255, a);
    
    if(a < 255)
    {
        for(i = 0; i < clipRect.width; i++)
        {
            pnt.x = clipRect.x + i;
            
            leRenderer_BlendPixel(pnt.x, pnt.y, clr, a);
        }
    }
    else
    {
        for(i = 0; i < clipRect.width; i++)
        {
            pnt.x = clipRect.x + i;
            
            leRenderer_PutPixel(pnt.x, pnt.y, clr);
        }
    }
    
    return LE_SUCCESS;
}

leResult leRenderer_VertLine(int32_t x,
                             int32_t y,
                             int32_t h,
                             leColor clr,
                             uint32_t a)
{
    leRect clipRect;
    leRect drawRect;
    lePoint pnt;
    int32_t i;
    
    drawRect.x = x;
    drawRect.y = y;
    drawRect.width = 1;
    drawRect.height = h;
    
    if(leRenderer_CullDrawRect(&drawRect) == LE_TRUE)
        return LE_FAILURE;
        
    leRenderer_ClipDrawRect(&drawRect, &clipRect);
    
    pnt.x = clipRect.x;
    
    a = leClampi(0, 255, a);
    
    if(a < 255)
    {
        for(i = 0; i < clipRect.height; i++)
        {
            pnt.y = clipRect.y + i;
            
            leRenderer_BlendPixel(pnt.x, pnt.y, clr, a);
        }
    }
    else
    {
        for(i = 0; i < clipRect.height; i++)
        {
            pnt.y = clipRect.y + i;
            
            leRenderer_PutPixel(pnt.x, pnt.y, clr);
        }
    } 
    
    return LE_SUCCESS;
}

typedef void (*LinePutPixelFn)(int32_t, int32_t, leColor, uint32_t);

static void linePutPixel(int32_t x,
                         int32_t y,
                         leColor clr,
                         uint32_t a)
{
    leRenderer_PutPixel(x, y, clr);
}

static void lineBlendPixel(int32_t x,
                           int32_t y,
                           leColor clr,
                           uint32_t a)
{
    leRenderer_BlendPixel(x, y, clr, a);
}

leResult leRenderer_DrawLine(int32_t x0,
                             int32_t y0,
                             int32_t x1,
                             int32_t y1,
                             leColor clr,
                             uint32_t a)
{
    int32_t dx, sx, dy, sy, e2, err;
    lePoint lp1, lp2, drawPoint;
    
    LinePutPixelFn putPixelFn;
    
    a = leClampi(0, 255, a);
    
    if(a < 255)
    {
        putPixelFn = lineBlendPixel;
    }
    else
    {
        putPixelFn = linePutPixel;
    }

    lp1.x = x0;
    lp1.y = y0;

    lp2.x = x1;
    lp2.y = y1;

    dx = lp2.x - lp1.x;
    
    if(dx < 0)
        dx *= -1;
        
    sx = lp1.x < lp2.x ? 1 : -1;
    
    dy = lp2.y - lp1.y;
    
    if(dy < 0)
        dy *= -1;
        
    dy *= -1;
    
    sy = lp1.y < lp2.y ? 1 : -1; 
    err = dx + dy;
       
    for(;;)
    {  
        drawPoint.x = lp1.x;
        drawPoint.y = lp1.y;
        
        if(leRenderer_CullDrawPoint(&drawPoint) == LE_FALSE)
        {
            putPixelFn(drawPoint.x, drawPoint.y, clr, a);
        }
        
        if(lp1.x == lp2.x && lp1.y == lp2.y)
            break;
        
        e2 = 2 * err;
        
        if(e2 >= dy)
        {
            err += dy;
            lp1.x += sx;
        }
        
        if(e2 <= dx)
        {
            err += dx;
            lp1.y += sy;
        }
    }
   
    return LE_SUCCESS;
}

leResult leRenderer_EllipseLine(int32_t x,
                                int32_t y,
                                int32_t a,
                                int32_t b,
                                int32_t theta,
                                int32_t startAngle,
                                int32_t centerAngle,
                                leColor clr,
                                uint32_t alpha)
{
    int32_t sa = startAngle;
    lePoint p;
    lePoint lp = lePoint_Zero;

    while (sa != (startAngle + centerAngle))
    {
        leEllipsePoint(sa, a, b, theta, &p);
        
        p.x += x;
        p.y += y;
        
#if LE_ALPHA_BLENDING_ENABLED == 1
        leRenderer_BlendPixel(p.x, p.y, clr, alpha);
#else
        leRenderer_PutPixel(p.x, p.y, clr);
#endif

        if (sa != startAngle)
        {     
            leRenderer_DrawLine(lp.x,
                                lp.y,
                                p.x,
                                p.y,
                                clr,
                                alpha);
        }

        lp.x = x;
        lp.y = y;
        
        //Clockwise
        if (centerAngle < 0)
        {
            sa--;
        }
        //Counter-clockwise
        else
        {
            sa++;
        }
    }

    return LE_SUCCESS;
}