#include "gfx/legato/renderer/legato_renderer.h"

#include "gfx/legato/common/legato_math.h"

#include <math.h>

/* renderer function use only */
extern leRenderState _rendererState;

typedef enum 
{
    ON_LINE,
    LEFT_OF_LINE,
    RIGHT_OF_LINE,
} POINT_LINE_POS;

leResult leRenderer_ArcLine(int32_t x,
                            int32_t y, 
                            int32_t r,
                            int32_t startAngle,
                            int32_t centerAngle,
                            leColor clr,
                            uint32_t a)
{
    int32_t sa = startAngle;
    lePoint p;

    while (sa != (startAngle + startAngle))
    {
        lePolarToXY(r, sa, &p);
        
        p.x += x;
        p.y += y;
        
        if(leRectContainsPoint(&_rendererState.drawRect, &p) == LE_TRUE)
        {
            leRenderer_PutPixel(p.x, p.y, clr);
        }
        
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

// This function returns the relative horizontal position of a point from a line.
// Works only if test point and line are in the same half plane (Q1 & Q2, or Q3 & Q4).
POINT_LINE_POS pointRelPositionFromLine(lePoint* linePt0,
                                        lePoint* linePt1,
                                        lePoint* point)
{
    int sign = (linePt1->x - linePt0->x) * (point->y - linePt0->y) - 
               (linePt1->y - linePt0->y) * (point->x - linePt0->x);

    if (linePt1->y < 0)
    {
        sign = -sign;
    }
    
    if (sign > 0)
    {
        return LEFT_OF_LINE;
    }
    else if (sign < 0)
    {
        return RIGHT_OF_LINE;
    }

    return ON_LINE;
}

/*
static leColor getArcSoftEdgeColor(uint32_t oRadSqd, 
                                   uint32_t iRadSqd, 
                                   uint32_t thicknessSqd,
                                   uint32_t ptRadSqd,
                                   leGradient* gradient)
{
    leColor color;

    //test with outer radius
    if ((oRadSqd - ptRadSqd) < 8)
    {
        color = leColorLerp(gradient->c0,
                            gradient->c1,
                            20,
                            _rendererState.colorMode);
    }
    else if ((oRadSqd - ptRadSqd) < 32)
    {
        color = leColorLerp(gradient->c0,
                            gradient->c1,
                            40,
                            _rendererState.colorMode);
    }
    else if ((oRadSqd - ptRadSqd) < 50)
    {
        color = leColorLerp(gradient->c0,
                            gradient->c1,
                            60,
                            _rendererState.colorMode);
    }    
    else if ((oRadSqd - ptRadSqd) < 72)
    {
        color = leColorLerp(gradient->c0,
                            gradient->c1,
                            80,
                            _rendererState.colorMode);
    }
    //Do not test inner edge if full circle
    else if (thicknessSqd == oRadSqd)
    {
        color = gradient->c1;
    }
    else if ((ptRadSqd - iRadSqd) < 8)
    {
        color = leColorLerp(gradient->c0,
                            gradient->c1,
                            20,
                            _rendererState.colorMode);
    }
    else if ((ptRadSqd - iRadSqd) < 32)
    {
        color = leColorLerp(gradient->c0,
                            gradient->c1,
                            40,
                            _rendererState.colorMode);
    }
    else if ((ptRadSqd - iRadSqd) < 50)
    {
        color = leColorLerp(gradient->c0,
                            gradient->c1,
                            60,
                            _rendererState.colorMode);
    }    
    else if ((ptRadSqd - iRadSqd) < 72)
    {
        color = leColorLerp(gradient->c0,
                            gradient->c1,
                            80,
                            _rendererState.colorMode);
    }
    else
    {
        color = gradient->c1;
    }

    return color;
}
*/

#if LE_USE_ARC_SCAN_FILL == 1
//This function does a scan fill from +y -> -y, -x -> +x or
// Q2, Q1, Q3, Q4 in terms of quadrants. Points outside the 
// arc fill area are discarded.
leResult leRenderer_ArcFill(leRect* drawRect,
                            int32_t x,
                            int32_t y,
                            int32_t r,
                            int32_t startAngle,
                            int32_t centerAngle,
                            uint32_t thickness,
                            leColor clr,
                            leBool antialias,
                            uint32_t a)
{
    lePoint topRectPt, botRectPt; //Top and bottom points of arc rectangle
    lePoint arcStartPt0, arcStartPt1, arcEndPt0, arcEndPt1; //Points of arc edges
    lePoint drawPt; //Point to draw
    lePoint scanPt;
    int32_t endAngle;
    uint32_t ptRadiusSqrd, oCirRadSqrd, iCirRadSqrd; //Square of radii
    uint32_t absStartAngle, absEndAngle; //start and end angles in positive angles
    leArcDir dir;
    //uint32_t thicknessSqd;
    
    if(leRenderer_CullDrawRect(drawRect) == LE_TRUE)
        return LE_FAILURE;

    thickness = (thickness < (uint32_t)r) ? thickness : (uint32_t)r;
    
    //thicknessSqd = thickness * thickness;

    //Don't care about wrapping 
    if (centerAngle == 0)
        return LE_SUCCESS;

    startAngle %= 360;
    centerAngle %= 360;

    //Determine points of arc edges
    if (startAngle >= 0)
    {
        absStartAngle = startAngle;
    }
    else
    {
        absStartAngle = 360 + startAngle;
    }
    
    lePolarToXY(r, absStartAngle, &arcStartPt1);
    lePolarToXY(r - thickness, absStartAngle, &arcStartPt0);

    endAngle = startAngle + centerAngle;
    
    if (endAngle >= 0)
    {
        absEndAngle = endAngle;
    }
    else
    {
        absEndAngle = 360 + endAngle;
    }
    
    absEndAngle %= 360;

    lePolarToXY(r, absEndAngle, &arcEndPt1);
    lePolarToXY(r - thickness, absEndAngle, &arcEndPt0);

    if (centerAngle > 0)
    {
        dir  = LE_CCW;
    }
    else
    {
        dir = LE_CW;
    }

    //Determine bounding rectangle points
    topRectPt.x = - ((int32_t)r);
    topRectPt.y = r;
    botRectPt.x = r;
    botRectPt.y = -((int32_t)r);

    oCirRadSqrd = r * r;
    iCirRadSqrd = (r - thickness) * (r - thickness);

    //Scan thru the points in arc rectangle, per quadrant and filter points that are outside
    //Only scan if the arc overlaps with the quadrant
    if (leArcsOverlapQuadrant(absStartAngle, 
                              absEndAngle, 
                              dir, 
                              LE_Q2) == LE_TRUE)
    {
        for (scanPt.y = topRectPt.y; scanPt.y >= 0; scanPt.y--)
        {
            for (scanPt.x = topRectPt.x; scanPt.x <= 0; scanPt.x++)
            {
                ptRadiusSqrd = (scanPt.x * scanPt.x) + (scanPt.y * scanPt.y);
                
                //If point is outside outer circle, skip
                if (ptRadiusSqrd > oCirRadSqrd)
                    continue;
                
                //If point is outside inner circle, done scanning x
                if (ptRadiusSqrd < iCirRadSqrd)
                    break;

                if (absStartAngle == absEndAngle)
                {
                    //Circle, do not filter, draw all points
                }
                else if ((absStartAngle <= 180 && absStartAngle > 90) && 
                         (absEndAngle <= 180 && absEndAngle > 90))
                {
                    //If both start and end angles are in Q2
                    //If CCW, exclude points RIGHT of start line and LEFT of end line
                    if (dir == LE_CCW) 
                    {
                        if (absStartAngle < absEndAngle)
                        {
                            //Include points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != RIGHT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) != LEFT_OF_LINE))
                            {
                                //Do nothing
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (absStartAngle > absEndAngle)
                        {
                            //exclude points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == RIGHT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == LEFT_OF_LINE))
                                continue;                            
                        }
                        else
                        {
                            if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != ON_LINE)
                                continue;
                        }
                    }
                    //If CW, exclude points LEFT of start line and RIGHT of end line
                    else
                    {
                        if (absStartAngle > absEndAngle)
                        {
                            //Include points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != LEFT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) != RIGHT_OF_LINE))
                            {
                                //Do nothing
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (absStartAngle < absEndAngle)
                        {
                            //exclude points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == LEFT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == RIGHT_OF_LINE))
                                continue;                            
                        }
                        else
                        {
                            if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != ON_LINE)
                                continue;
                        }
                    }
                }
                else if (absStartAngle <= 180 && absStartAngle > 90)
                {
                    //If CCW, exclude points RIGHT of start line
                    if (dir == LE_CCW)
                    {
                        if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == RIGHT_OF_LINE)
                            continue;
                    }
                    //If CW, exclude points LEFT of start line
                    else
                    {
                        if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == LEFT_OF_LINE)
                            continue;
                    }
                }
                //If end angle is in Q2, test agains Q2
                else if (absEndAngle <= 180 && absEndAngle > 90)
                {
                    //If CCW, exclude points LEFT of start line
                    if (dir == LE_CCW)
                    {
                        if (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == LEFT_OF_LINE)
                            continue;
                    }
                    //If CCW, exclude points RIGHT of start line
                    else
                    {
                        if (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == RIGHT_OF_LINE)
                            continue;
                    }
                }

                //Soften edge colors if anti-aliased
                
                
                drawPt.x = x + scanPt.x;
                drawPt.y = y - scanPt.y;

                if(leRenderer_CullDrawPoint(&drawPt) == LE_TRUE)
                {
                    leRenderer_PutPixel(drawPt.x, drawPt.y, clr);
                }
            }
        }
    }

    //Don't scan thru Q1 points if not needed. Optimize?
    if(leArcsOverlapQuadrant(absStartAngle, 
                             absEndAngle, 
                             dir, 
                             LE_Q1) == LE_TRUE)
    {
        for (scanPt.y = topRectPt.y; scanPt.y >= 0; scanPt.y--)
        {
            for (scanPt.x = 0; scanPt.x < botRectPt.x; scanPt.x++)
            {
                ptRadiusSqrd = (scanPt.x * scanPt.x) + (scanPt.y * scanPt.y);
                
                //If point is outside outer circle, skip
                if (ptRadiusSqrd < iCirRadSqrd)
                    continue;

                //If point is outside outer circle, done scanning x
                if (ptRadiusSqrd > oCirRadSqrd)
                    break;
                
                if (absStartAngle == absEndAngle)
                {
                    //Circle, do not filter, draw all points
                }
                else if ((absStartAngle <= 90 && absStartAngle >= 0) && 
                   (absEndAngle <= 90 && absEndAngle >= 0))
                {
                    //If both start and end angles are in Q1
                    //If CCW, exclude points RIGHT of start line and LEFT of end line
                    if (dir == LE_CCW) 
                    {
                        if (absStartAngle < absEndAngle)
                        {
                            //Include points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != RIGHT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) != LEFT_OF_LINE))
                            {
                                //Do nothing
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (absStartAngle > absEndAngle)
                        {
                            //exclude points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == RIGHT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == LEFT_OF_LINE))
                                continue;                            
                        }
                        else
                        {
                            if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != ON_LINE)
                                continue;
                        }
                    }
                    else
                    {
                        if (absStartAngle > absEndAngle)
                        {
                            //Include points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != LEFT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) != RIGHT_OF_LINE))
                            {
                                //Do nothing
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (absStartAngle < absEndAngle)
                        {
                            //exclude points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == LEFT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == RIGHT_OF_LINE))
                                continue;                            
                        }
                        else
                        {
                            if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != ON_LINE)
                                continue;
                        }
                    }
                }
                else if (absStartAngle <= 90 && absStartAngle >= 0)
                {
                    //If CCW, exclude points RIGHT of start line
                    if (dir == LE_CCW)
                    {
                        if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == RIGHT_OF_LINE)
                            continue;
                    }
                    //If CW, exclude points LEFT of start line
                    else
                    {
                        if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == LEFT_OF_LINE)
                            continue;
                    }
                }
                //If end angle is in Q1, test agains Q1
                else if (absEndAngle <= 90 && absEndAngle >= 0)
                {
                    //If CCW, exclude points LEFT of start line
                    if (dir == LE_CCW)
                    {
                        if (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == LEFT_OF_LINE)
                            continue;
                    }
                    //If CW, exclude points RIGHT of start line
                    else
                    {
                        if (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == RIGHT_OF_LINE)
                            continue;
                    }
                }

                drawPt.x = x + scanPt.x;
                drawPt.y = y - scanPt.y;

                if(leRenderer_CullDrawPoint(&drawPt) == LE_TRUE)
                {
                    leRenderer_PutPixel(drawPt.x, drawPt.y, clr);
                }
            }
        }
    }

    //Don't scan thru Q3 points if not needed. Optimize?
    if(leArcsOverlapQuadrant(absStartAngle, 
                             absEndAngle, 
                             dir, 
                             LE_Q3) == LE_TRUE)
    {
        for (scanPt.y = 0; scanPt.y > botRectPt.y; scanPt.y--)
        {
            for (scanPt.x = topRectPt.x; scanPt.x <= 0; scanPt.x++)
            {
                ptRadiusSqrd = (scanPt.x * scanPt.x) + (scanPt.y * scanPt.y);
                
                //If point is outside outer circle, skip
                if (ptRadiusSqrd > oCirRadSqrd)
                    continue;
                
                //If point is outside inner circle, done scanning x
                if (ptRadiusSqrd < iCirRadSqrd)
                    break;

                if (absStartAngle == absEndAngle)
                {
                    //Circle, do not filter, draw all points
                }
                else if ((absStartAngle <= 270 && absStartAngle > 180) && 
                   (absEndAngle <= 270 && absEndAngle > 180))
                {
                    //If CCW, exclude points RIGHT of start line and LEFT of end line
                    if (dir == LE_CCW) 
                    {
                        if (absStartAngle < absEndAngle)
                        {
                            //Include points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != LEFT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) != RIGHT_OF_LINE))
                            {
                                //Do nothing
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (absStartAngle > absEndAngle)
                        {
                            //exclude points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == LEFT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == RIGHT_OF_LINE))
                                continue;                            
                        }
                        else
                        {
                            if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != ON_LINE)
                                continue;
                        }
                    }
                    else
                    {
                        if (absStartAngle > absEndAngle)
                        {
                            //Include points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != RIGHT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) != LEFT_OF_LINE))
                            {
                                //Do nothing
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (absStartAngle < absEndAngle)
                        {
                            //exclude points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == RIGHT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == LEFT_OF_LINE))
                                continue;                            
                        }
                        else
                        {
                            if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != ON_LINE)
                                continue;
                        }
                    }
                }
                else if (absStartAngle <= 270 && absStartAngle > 180)
                {
                    //If CCW, exclude points LEFT of start line
                    if (dir == LE_CCW)
                    {
                        if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == LEFT_OF_LINE)
                            continue;
                    }
                    //If CW, exclude points RIGHT of start line
                    else
                    {
                        if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == RIGHT_OF_LINE)
                            continue;
                    }
                }
                else if (absEndAngle <= 270 && absEndAngle > 180)
                {
                    //If CCW, exclude points RIGHT of end line
                    if (dir == LE_CCW)
                    {
                        if (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == RIGHT_OF_LINE)
                            continue;
                    }
                    //If CW, exclude points LEFT of end line
                    else
                    {
                                                //corner case: if radius is too small, and end angle is close to 180, 
                        //the end line approximates to a horizontal line. in this case, 
                        //just draw all points in the quadrant
                        if (arcEndPt0.y == 0 && arcEndPt1.y == 0)
                        {
                            //draw all points
                        }
                        else if (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == LEFT_OF_LINE)
                            continue;
                    }
                }

                drawPt.x = x + scanPt.x;
                drawPt.y = y - scanPt.y;

                if(leRenderer_CullDrawPoint(&drawPt) == LE_TRUE)
                {
                    leRenderer_PutPixel(drawPt.x, drawPt.y, clr);
                }
            }
        }
    }

    //Don't scan thru Q4 points if not needed. Optimize?
    if(leArcsOverlapQuadrant(absStartAngle, 
                             absEndAngle, 
                             dir, 
                             LE_Q4) == LE_TRUE)
    {
        for (scanPt.y = 0; scanPt.y > botRectPt.y; scanPt.y--)
        {
            for (scanPt.x = 0; scanPt.x < botRectPt.x; scanPt.x++)
            {
                ptRadiusSqrd = (scanPt.x * scanPt.x) + (scanPt.y * scanPt.y);
                
                //If point is outside outer circle, skip
                if (ptRadiusSqrd < iCirRadSqrd)
                    continue;

                //If point is outside outer circle, done scanning x
                if (ptRadiusSqrd > oCirRadSqrd)
                    break;

                if (absStartAngle == absEndAngle)
                {
                    //Circle or almost a circle, do not filter, draw all points
                }
                else if ((absStartAngle < 360 && absStartAngle > 270) && 
                   (absEndAngle < 360 && absEndAngle > 270))
                {
                    //If CCW, exclude points RIGHT of start line and LEFT of end line
                    if (dir == LE_CCW) 
                    {
                        if (absStartAngle < absEndAngle)
                        {
                            //Include points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != LEFT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) != RIGHT_OF_LINE))
                            {
                                //Do nothing
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (absStartAngle > absEndAngle)
                        {
                            //exclude points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == LEFT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == RIGHT_OF_LINE))
                                continue;                            
                        }
                        else
                        {
                            if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != ON_LINE)
                                continue;
                        }
                    }
                    else
                    {
                        if (absStartAngle > absEndAngle)
                        {
                            //Include points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != RIGHT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) != LEFT_OF_LINE))
                            {
                                //Do nothing
                            }
                            else
                            {
                                continue;
                            }
                        }
                        else if (absStartAngle < absEndAngle)
                        {
                            //exclude points between the two angles
                            if ((pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == RIGHT_OF_LINE)
                                && (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == LEFT_OF_LINE))
                                continue;                            
                        }
                        else
                        {
                            if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) != ON_LINE)
                                continue;
                        }
                    }
                }
                else if (absStartAngle < 360 && absStartAngle > 270)
                {
                    //If CCW, exclude points LEFT of start line
                    if (dir == LE_CCW)
                    {
                        if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == LEFT_OF_LINE)
                            continue;
                    }
                    //If CW, exclude points RIGHT of start line
                    else
                    {
                        if (pointRelPositionFromLine(&arcStartPt0, &arcStartPt1, &scanPt) == RIGHT_OF_LINE)
                            continue;
                    }
                }
                else if (absEndAngle < 360 && absEndAngle > 270)
                {
                    //If CCW, exclude points RIGHT of end line
                    if (dir == LE_CCW)
                    {
                        //corner case: if radius is too small, and end angle is close to 360, 
                        //the end line approximates to a horizontal line. in this case, 
                        //just draw all points in the quadrant
                        if (arcEndPt0.y == 0 && arcEndPt1.y == 0)
                        {
                            //draw all points
                        }
                        else if (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == RIGHT_OF_LINE)
                            continue;
                    }
                    //If CW, exclude points LEFT of end line
                    else
                    {
                        if (pointRelPositionFromLine(&arcEndPt0, &arcEndPt1, &scanPt) == LEFT_OF_LINE)
                            continue;
                    }
                }
                
                drawPt.x = x + scanPt.x;
                drawPt.y = y - scanPt.y;

                if(leRenderer_CullDrawPoint(&drawPt) == LE_TRUE)
                {
                    leRenderer_PutPixel(drawPt.x, drawPt.y, clr);
                }
            }
        }
    }

    return LE_SUCCESS;
}

#else

static int32_t circleGetXGivenY(int32_t r, int32_t y)
{
    if (-r < y && y < r)
        return (int32_t) sqrt(r*r - y*y);

    return 0;
}

//Draws horizontal lines to fill arc
static void drawArcFillLine(int32_t x,
                            int32_t y, 
                            const lePoint* drawPtStart,
                            const lePoint* drawPtEnd,
                            leColor clr)
{
    //Circle, do not filter, draw all points
    lePoint start, end;

    //startX should always be less or equal to endX.
    if (drawPtStart->x > drawPtEnd->x ||
        drawPtStart->y != drawPtEnd->y)
        return;
    
    start.x = x + drawPtStart->x;
    start.y = y - drawPtStart->y;
                
    end.x = x + drawPtEnd->x;
    end.y = y - drawPtEnd->y;
    
    leRenderer_DrawLine(start.x, start.y, end.x, end.y, clr);
}

//This fill algorithm draws lines between the arc boundaries.
//This can take advantage of the GPU's line draw operation.
leResult leRenderer_ArcFill(int32_t x,
                            int32_t y,
                            int32_t r,
                            int32_t startAngle,
                            int32_t centerAngle,
                            uint32_t thickness,
                            leColor clr)
{
    lePoint topRectPt; //Top and bottom points of arc rectangle
    lePoint arcStartPt0, arcStartPt1, arcEndPt0, arcEndPt1; //Points of arc edges
    lePoint scanPt;
    int32_t endAngle;
    uint32_t absStartAngle, absEndAngle; //start and end angles in positive angles
    leArcDir dir;
    uint32_t quadrantFlag = 0;
    
    lePoint drawPtStart, drawPtEnd;
    
    thickness = (thickness < (uint32_t)r) ? thickness : (uint32_t)r;
    
    //Don't care about wrapping 
    if (centerAngle == 0)
        return LE_SUCCESS;

    startAngle %= 360;
    centerAngle %= 360;

    //Determine points of arc edges
    if (startAngle >= 0)
    {
        absStartAngle = startAngle;
    }
    else
    {
        absStartAngle = 360 + startAngle;
    }
    
    lePolarToXY(r, absStartAngle, &arcStartPt1);
    lePolarToXY(r - thickness, absStartAngle, &arcStartPt0);

    endAngle = startAngle + centerAngle;
    
    if (endAngle >= 0)
    {
        absEndAngle = endAngle;
    }
    else
    {
        absEndAngle = 360 + endAngle;
    }
    
    absEndAngle %= 360;

    lePolarToXY(r, absEndAngle, &arcEndPt1);
    lePolarToXY(r - thickness, absEndAngle, &arcEndPt0);

    if (centerAngle > 0)
    {
        dir = LE_CCW;
    }
    else
    {
        dir = LE_CW;
    }

    //Determine bounding rectangle points
    topRectPt.x = - ((int32_t)r);
    topRectPt.y = r;

    //Scan thru the points in arc rectangle, per quadrant and filter points that are outside
    
    //Set the quadrant flag
    if(leArcsOverlapQuadrant(absStartAngle, 
                             absEndAngle, 
                             dir, 
                             LE_Q1) == LE_TRUE)
    {
        quadrantFlag |= (1 << LE_Q1);
    }
    
    if (leArcsOverlapQuadrant(absStartAngle, 
                              absEndAngle, 
                              dir, 
                              LE_Q2) == LE_TRUE)
    {
        quadrantFlag |= (1 << LE_Q2);
    }
    
    if (leArcsOverlapQuadrant(absStartAngle, 
                              absEndAngle, 
                              dir, 
                              LE_Q3) == LE_TRUE)
    {
        quadrantFlag |= (1 << LE_Q3);
    }
    
    if (leArcsOverlapQuadrant(absStartAngle, 
                              absEndAngle, 
                              dir, 
                              LE_Q4) == LE_TRUE)
    {
        quadrantFlag |= (1 << LE_Q4);
    }
    
    for (scanPt.y = topRectPt.y; scanPt.y >= 0; scanPt.y--)
    {
        int32_t outX, inX;

        outX = circleGetXGivenY(r, scanPt.y);
        inX = circleGetXGivenY(r - thickness, scanPt.y);
        
        drawPtStart.y = scanPt.y;
        drawPtEnd.y = drawPtStart.y;
        
        //Only scan if the arc overlaps with the quadrant
        if (scanPt.y >= 0 && quadrantFlag & (1 << LE_Q2))
        {
            do 
            {
                drawPtStart.x = -outX;
                drawPtEnd.x = -inX;            

                if (absStartAngle == absEndAngle)
                {
                    //Otherwise, draw all points
                    drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                }
                //If both start and end angles are in Q2
                else if ((90 <= absStartAngle && absStartAngle <= 180 ) && 
                         (90 <= absEndAngle && absEndAngle <= 180 ))
                {
                    //If CCW, exclude points RIGHT of start line and LEFT of end line
                    if (dir == LE_CCW) 
                    {
                        if (absEndAngle > absStartAngle)
                        {
                            int32_t xPoint;

                            if (drawPtStart.y > arcStartPt1.y || drawPtStart.y < arcEndPt0.y)
                                continue;

                            //Clip start of line from the arc end edge
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStart.y);
                            
                            if (arcEndPt0.y != arcEndPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }
                            
                            //Clip end of line from the arc start edge
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtEnd.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (absStartAngle > absEndAngle) 
                        {
                            int32_t xPoint;
                            lePoint drawPtStartCopy = drawPtStart;
                            lePoint drawPtEndCopy = drawPtEnd;

                            //Draw lines right of end Angle
                            if(drawPtStartCopy.y > arcEndPt1.y)
                            {
                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);
                            }
                            else if(drawPtStartCopy.y <= arcEndPt1.y &&
                                    drawPtStartCopy.y >= arcEndPt0.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStartCopy.y);
                                if(arcEndPt0.y != arcEndPt1.y && xPoint > drawPtStartCopy.x)
                                {
                                    drawPtStartCopy.x = xPoint;
                                }
                                
                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);
                            }

                            //Draw lines left of Start Angle Edge
                            if (drawPtEndCopy.y >= arcStartPt0.y &&
                                drawPtEndCopy.y <= arcStartPt1.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtEndCopy.y);
                                if (arcStartPt0.y != arcStartPt1.y && xPoint < drawPtEndCopy.x)
                                    drawPtEndCopy.x = xPoint;

                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }
                            else if (drawPtEndCopy.y < arcStartPt0.y)
                            {
                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }
                        }
                    }
                    //If CW, exclude points LEFT of start line and RIGHT of end line
                    else
                    {
                        if (absEndAngle > absStartAngle)
                        {
                            int32_t xPoint;
                            lePoint drawPtStartCopy = drawPtStart;
                            lePoint drawPtEndCopy = drawPtEnd;

                            //Draw lines right of start Angle
                            if (drawPtStartCopy.y > arcStartPt1.y)
                            {
                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);
                            }
                            else if (drawPtStartCopy.y <= arcStartPt1.y &&
                                     drawPtStartCopy.y >= arcStartPt0.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                                
                                if (arcStartPt0.y != arcStartPt1.y && xPoint > drawPtStartCopy.x)
                                {
                                   drawPtStartCopy.x = xPoint;
                                }
                                
                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);
                            }

                            //Clip end point to arc start edge
                            if (drawPtEndCopy.y <= arcEndPt0.y)
                            {
                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }
                            else if (drawPtEndCopy.y > arcEndPt0.y &&
                                     drawPtEndCopy.y < arcEndPt1.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStart.y);
                                
                                if (arcEndPt0.y != arcEndPt1.y && xPoint < drawPtEndCopy.x)
                                {
                                    drawPtEndCopy.x = xPoint;
                                }
                                
                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }

                        }
                        else if (absStartAngle > absEndAngle)
                        {
                            int32_t xPoint;

                            if (drawPtStart.y > arcEndPt1.y || drawPtStart.y < arcStartPt0.y)
                                continue;

                            //Clip line from the arc end edge
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }
                            
                            //Clip line from the arc start edge
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtEnd.y);
                            
                            if (arcEndPt0.y != arcEndPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                }
                else if (absStartAngle <= 180 && absStartAngle > 90) 
                {
                    //If CCW, exclude points RIGHT of start line
                    if (dir == LE_CCW) 
                    {
                        int32_t xPoint;

                        if (drawPtStart.y > arcStartPt1.y)
                            continue;

                        //Clip end point to arc start edge
                        if (drawPtStart.y >= arcStartPt0.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint < drawPtEnd.x)
                            {    
                                drawPtEnd.x = xPoint;
                            }
                                
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtStart.y < arcStartPt0.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                    //If CW, start point to arc start edge
                    else 
                    {
                        int32_t xPoint;

                        if (drawPtStart.y < arcStartPt0.y)
                            continue;

                        if (drawPtStart.x < arcStartPt1.x)
                        {
                            drawPtStart.x = arcStartPt1.x;
                        }
                        
                        if (drawPtStart.y >= arcStartPt1.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtStart.y >= arcStartPt0.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                }
                //If end angle is in Q2, test agains Q2
                else if (absEndAngle <= 180 && absEndAngle > 90) 
                {
                    if (dir == LE_CCW) 
                    {
                        int32_t xPoint;

                        if (drawPtStart.y > arcEndPt0.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStart.y);
                            
                            if (arcEndPt0.y != arcEndPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                    else 
                    {
                        int32_t xPoint;

                        //Clip end point to arc end edge
                        if (drawPtStart.y < arcEndPt0.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtStart.y >= arcEndPt0.y &&
                                 drawPtStart.y <= arcEndPt1.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStart.y);
                            
                            if (arcEndPt0.y != arcEndPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }

                    }
                }
                else 
                {
                    //Otherwise, draw all points
                    drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                }
            }
            while(0);
        }

        //Don't scan thru Q1 points if not needed. Optimize?
        if (scanPt.y >= 0 && quadrantFlag & (1 << LE_Q1))
        {
            do
            {
                drawPtStart.x = inX;
                drawPtEnd.x = outX;            

                if (absStartAngle == absEndAngle)
                {
                    //Otherwise, draw all points
                    drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                }
                //If both start and end angles are in Q1
                else if ((absStartAngle <= 90 && absStartAngle >= 0) && 
                         (absEndAngle <= 90 && absEndAngle >= 0))
                {
                    if (dir == LE_CCW) 
                    {
                        //If CCW, exclude points RIGHT of start line and LEFT of end line
                        if (absEndAngle > absStartAngle) 
                        {
                            int32_t xPoint;

                            if (drawPtStart.y > arcEndPt1.y || 
                                drawPtStart.y < arcStartPt0.y)
                                continue;

                            //Clip start of line from the arc end edge
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStart.y);
                            if (arcEndPt0.y != arcEndPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }
                            
                            //Clip end of line from the arc start edge
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtEnd.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (absStartAngle > absEndAngle) 
                        {
                            int32_t xPoint;
                            lePoint drawPtStartCopy = drawPtStart;
                            lePoint drawPtEndCopy = drawPtEnd;

                            //Draw lines right of End Angle
                            if (drawPtStartCopy.y < arcEndPt0.y)
                            {
                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);                            
                            }
                            else if (drawPtStartCopy.y >= arcEndPt0.y &&
                                     drawPtStartCopy.y <= arcEndPt1.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStartCopy.y);
                                
                                if (arcEndPt0.y != arcEndPt1.y && xPoint > drawPtStartCopy.x)
                                {
                                    drawPtStartCopy.x = xPoint;
                                }

                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);
                            }

                            //Draw lines left of Start Angle Edge
                            if (drawPtEndCopy.y > arcStartPt1.y)
                            {  
                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }
                            else if (drawPtEndCopy.y <= arcStartPt1.y &&
                                     drawPtEndCopy.y >= arcStartPt0.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtEndCopy.y);
                                
                                if (arcStartPt0.y != arcStartPt1.y && xPoint < drawPtEndCopy.x)
                                {
                                    drawPtEndCopy.x = xPoint;
                                }

                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }
                        }
                    }
                    //If CW, exclude points LEFT of start line and RIGHT of end line
                    else
                    {
                        if (absEndAngle > absStartAngle) 
                        {
                            int32_t xPoint;
                            lePoint drawPtStartCopy = drawPtStart;
                            lePoint drawPtEndCopy = drawPtEnd;

                            //Draw lines right of start Angle
                            if (drawPtStartCopy.y <= arcStartPt0.y)
                            {
                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);
                            }
                            else if (drawPtStartCopy.y < arcStartPt1.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                                
                                if (arcStartPt0.y != arcStartPt1.y && xPoint > drawPtStartCopy.x)
                                {
                                    drawPtStartCopy.x = xPoint;
                                }
                                
                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);
                            }

                            //Clip end point to arc end edge
                            if (drawPtEndCopy.y > arcEndPt1.y)
                            {
                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }
                            else if (drawPtEndCopy.y <= arcEndPt1.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStart.y);
                                
                                if (arcEndPt0.y != arcEndPt1.y && xPoint < drawPtEnd.x)
                                {
                                    drawPtEndCopy.x = xPoint;
                                }
                                
                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);                            
                            }
                        }
                        else if (absStartAngle > absEndAngle) 
                        {
                            int32_t xPoint;

                            //Clip start point from the arc start edge
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }
                            
                            //Clip start point from the arc end edge
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtEnd.y);
                            
                            if (arcEndPt0.y != arcEndPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                }
                else if (0 <= absStartAngle && absStartAngle <= 90 )
                {
                    //If CCW, clip end point to start edge
                    if (dir == LE_CCW) 
                    {
                        int32_t xPoint;

                        if (drawPtEnd.x > arcStartPt1.x)
                        {
                            drawPtEnd.x = arcStartPt1.x;
                        }
                        
                        //Clip end point to arc start edge
                        if (drawPtStart.y >= arcStartPt1.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtStart.y < arcStartPt1.y &&
                                 drawPtStart.y >= arcStartPt0.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                    //If CW, exclude points LEFT of start line
                    else 
                    {
                        int32_t xPoint;

                        if (drawPtStart.y <= arcStartPt0.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtStart.y >= arcStartPt0.y &&
                                 drawPtStart.y <= arcStartPt1.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                }
                //If end angle is in Q1, test agains Q1
                else if (absEndAngle <= 90 && absEndAngle >= 0)
                {
                    if (dir == LE_CCW) 
                    {
                        int32_t xPoint;

                        if (drawPtStart.y <= arcEndPt0.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtStart.y <= arcEndPt1.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStart.y);
                            
                            if (arcEndPt0.y != arcEndPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                    else 
                    {
                        int32_t xPoint;

                        if (drawPtEnd.x > arcEndPt1.x)
                            drawPtEnd.x = arcEndPt1.x;

                        //Clip end point to arc end edge
                        if (drawPtStart.y >= arcEndPt1.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtStart.y >= arcEndPt0.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStart.y);
                            
                            if (arcEndPt0.y != arcEndPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                }
                else
                {
                    //Otherwise, draw all points
                    drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                }
            }
            while(0);
        }

        drawPtStart.y = -scanPt.y;
        drawPtEnd.y = drawPtStart.y;

        //Fill Q3 area
        if (drawPtStart.y <= 0 && quadrantFlag & (1 << LE_Q3))
        {
            do
            {
                drawPtStart.x = -outX;
                drawPtEnd.x = -inX;

                if (absStartAngle == absEndAngle)
                {
                    //Otherwise, draw all points
                    drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                }
                //If both start and end angles are in Q1
                else if ((180 <= absStartAngle && absStartAngle <= 270 ) && 
                         (180 <= absEndAngle && absEndAngle <= 270))
                {
                    if (dir == LE_CCW) 
                    {
                        //If CCW, exclude points RIGHT of start line and LEFT of end line
                        if (absEndAngle > absStartAngle) 
                        {
                            int32_t xPoint;

                            if (drawPtStart.y > arcStartPt0.y ||
                                drawPtStart.y < arcEndPt1.y)
                                continue;

                            //Clip start of line from the arc start edge
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }
                            
                            //Clip end of line from the arc end edge
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtEnd.y);
                            
                            if (arcEndPt0.y != arcEndPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (absStartAngle > absEndAngle) 
                        {
                            int32_t xPoint;
                            lePoint drawPtStartCopy = drawPtStart;
                            lePoint drawPtEndCopy = drawPtEnd;

                            //Draw lines right of Start Angle
                            if (drawPtStartCopy.y < arcStartPt1.y)
                            {
                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);                            
                            }
                            else if (drawPtStartCopy.y >= arcStartPt1.y &&
                                     drawPtStartCopy.y <= arcStartPt0.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStartCopy.y);
                                
                                if (arcStartPt1.y != arcStartPt0.y && xPoint > drawPtStartCopy.x)
                                {
                                    drawPtStartCopy.x = xPoint;
                                }

                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);
                            }

                            //Draw lines left of End Angle Edge
                            if (drawPtEndCopy.y > arcEndPt0.y)
                            {  
                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }
                            else if (drawPtEndCopy.y <= arcEndPt0.y &&
                                     drawPtEndCopy.y >= arcEndPt1.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcEndPt1, arcEndPt0, drawPtEndCopy.y);
                                
                                if (arcEndPt1.y != arcEndPt0.y && xPoint < drawPtEndCopy.x)
                                {
                                    drawPtEndCopy.x = xPoint;
                                }

                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }
                        }
                    }
                    //If CW, exclude points LEFT of start line and RIGHT of end line
                    else
                    {
                        if (absEndAngle > absStartAngle) 
                        {
                            int32_t xPoint;
                            lePoint drawPtStartCopy = drawPtStart;
                            lePoint drawPtEndCopy = drawPtEnd;

                            //Draw lines left of start arc edge
                            if (drawPtEndCopy.y >= arcStartPt0.y)
                            {
                                drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                            }
                            else if (drawPtEndCopy.y < arcStartPt0.y &&
                                     drawPtEndCopy.y >= arcStartPt1.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtEndCopy.y);
                                
                                if (arcStartPt0.y != arcStartPt1.y && xPoint < drawPtEndCopy.x)
                                {
                                    drawPtEndCopy.x = xPoint;
                                }

                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }

                            if (drawPtStartCopy.x < arcEndPt1.x)
                            {
                                drawPtStartCopy.x = arcEndPt1.x;
                            }
                            
                            //Draw lines right of end arc edge
                            if (drawPtStartCopy.y <= arcEndPt1.y)
                            {
                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);                            
                            }
                            else if (drawPtEndCopy.y <= arcEndPt0.y &&
                                     drawPtEndCopy.y >= arcEndPt1.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStartCopy.y);
                                
                                if (arcEndPt0.y != arcEndPt1.y && xPoint > drawPtStartCopy.x)
                                {
                                    drawPtStartCopy.x = xPoint;
                                }
                                
                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);                            
                            }
                        }
                        else if (absStartAngle > absEndAngle)
                        {
                            int32_t xPoint;

                            if (drawPtStart.y > arcEndPt0.y ||
                                drawPtStart.y < arcStartPt1.y)
                                continue;

                            //Clip start point from the arc start edge
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStart.y);
                            
                            if (arcEndPt0.y != arcEndPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }
                            
                            //Clip start point from the arc end edge
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtEnd.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                }
                else if (180 <= absStartAngle && absStartAngle <= 270 )
                {
                    //If CCW, draw lines from start arc edge
                    if (dir == LE_CCW) 
                    {
                        int32_t xPoint;

                        if (drawPtStart.x < arcStartPt1.x)
                        {
                            drawPtStart.x = arcStartPt1.x;
                        }
                        
                        if (drawPtStart.y <= arcStartPt1.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtStart.y > arcStartPt1.y &&
                                 drawPtStart.y <= arcStartPt0.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }

                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                    //If CW, draw lines to start arc edge
                    else 
                    {
                        int32_t xPoint;

                        if (drawPtEnd.y >= arcStartPt0.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtEnd.y < arcStartPt0.y &&
                                 drawPtEnd.y >= arcStartPt1.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                }
                //If end angle is in Q3, test against Q3
                else if (180 <= absEndAngle && absEndAngle <= 270)
                {
                    //CCW, draw line to end arc edge
                    if (dir == LE_CCW) 
                    {
                        int32_t xPoint;

                        if (drawPtEnd.y >= arcEndPt0.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtEnd.y <= arcEndPt0.y && 
                                 drawPtEnd.y >= arcEndPt1.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStart.y);
                            
                            if (arcEndPt0.y != arcEndPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }

                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                    //CW, draw line from end arc edge
                    else 
                    {
                        int32_t xPoint;

                        if (drawPtStart.x < arcEndPt1.x)
                        {
                            drawPtStart.x = arcEndPt1.x;
                        }
                        
                        if (drawPtStart.y <= arcEndPt1.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtStart.y <= arcEndPt0.y &&
                                 drawPtStart.y >= arcEndPt1.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStart.y);
                            
                            if (arcStartPt1.y != arcEndPt0.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }

                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                }
                else
                {
                    //Otherwise, draw all points
                    drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                }
            }
            while(0);
        }

        if (drawPtStart.y <= 0 && quadrantFlag & (1 << LE_Q4))
        {
            do
            {
                drawPtStart.x = inX;
                drawPtEnd.x = outX;            

                if (absStartAngle == absEndAngle)
                {
                    //Otherwise, draw all points
                    drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                }
                //If both start and end angles are in Q1
                else if ((270 <= absStartAngle && absStartAngle <= 360 ) && 
                         (270 <= absEndAngle && absEndAngle <= 360))
                {
                    if (dir == LE_CCW) 
                    {
                        if (absEndAngle > absStartAngle) 
                        {
                            //Draw line from arc start to arc end
                            int32_t xPoint;

                            if (drawPtStart.y > arcEndPt0.y ||
                                drawPtStart.y < arcStartPt1.y)
                                continue;

                            //Clip start of line from the arc start edge
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }
                            
                            //Clip end of line from the arc end edge
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtEnd.y);
                            
                            if (arcEndPt0.y != arcEndPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (absStartAngle > absEndAngle) 
                        {
                            int32_t xPoint;
                            lePoint drawPtStartCopy = drawPtStart;
                            lePoint drawPtEndCopy = drawPtEnd;

                            //Draw lines right of Start Angle
                            if (drawPtStartCopy.y > arcStartPt0.y)
                            {
                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);                            
                            }
                            else if (drawPtStartCopy.y >= arcStartPt1.y &&
                                     drawPtStartCopy.y <= arcStartPt0.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStartCopy.y);
                                
                                if (arcStartPt1.y != arcStartPt0.y && xPoint > drawPtStartCopy.x)
                                {
                                    drawPtStartCopy.x = xPoint;
                                }

                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);
                            }

                            //Draw lines left of End Angle Edge
                            if (drawPtEndCopy.y < arcEndPt1.y)
                            {  
                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }
                            else if (drawPtEndCopy.y <= arcEndPt0.y &&
                                     drawPtEndCopy.y >= arcEndPt1.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcEndPt1, arcEndPt0, drawPtEndCopy.y);
                                
                                if (arcEndPt1.y != arcEndPt0.y && xPoint < drawPtEndCopy.x)
                                {
                                    drawPtEndCopy.x = xPoint;
                                }

                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }
                        }
                    }
                    //If CW, exclude points LEFT of start line and RIGHT of end line
                    else
                    {
                        if (absEndAngle > absStartAngle)
                        {
                            int32_t xPoint;
                            lePoint drawPtStartCopy = drawPtStart;
                            lePoint drawPtEndCopy = drawPtEnd;

                            if (drawPtEndCopy.x > arcStartPt1.x)
                            {
                                drawPtEndCopy.x = arcStartPt1.x;
                            }
                            
                            //Draw lines left of start arc edge
                            if (drawPtEndCopy.y <= arcStartPt1.y)
                            {
                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }
                            else if (drawPtEndCopy.y <= arcStartPt0.y &&
                                     drawPtEndCopy.y > arcStartPt1.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtEndCopy.y);
                                
                                if (arcStartPt0.y != arcStartPt1.y && xPoint < drawPtEndCopy.x)
                                {
                                    drawPtEndCopy.x = xPoint;
                                }

                                drawArcFillLine(x, y, &drawPtStart, &drawPtEndCopy, clr);
                            }

                            //Draw lines right of end arc edge
                            if (drawPtStartCopy.y >= arcEndPt0.y)
                            {
                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);                            
                            }
                            else if (drawPtEndCopy.y < arcEndPt0.y &&
                                     drawPtEndCopy.y >= arcEndPt1.y)
                            {
                                xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStartCopy.y);
                                
                                if (arcEndPt0.y != arcEndPt1.y && xPoint > drawPtStartCopy.x)
                                {
                                    drawPtStartCopy.x = xPoint;
                                }
                                
                                drawArcFillLine(x, y, &drawPtStartCopy, &drawPtEnd, clr);                            
                            }
                        }
                        else if (absStartAngle > absEndAngle)
                        {
                            int32_t xPoint;

                            //Draw line from the arc end edge
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStart.y);
                            
                            if (arcEndPt0.y != arcEndPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }
                            
                            //Draw line to the arc start edge
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtEnd.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                }
                else if (270 <= absStartAngle && absStartAngle <= 360)
                {
                    //If CCW, draw lines from start arc edge
                    if (dir == LE_CCW) 
                    {
                        int32_t xPoint;

                        if (drawPtStart.y >= arcStartPt0.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtStart.y >= arcStartPt1.y &&
                                 drawPtStart.y < arcStartPt0.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }

                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                    //If CW, draw lines to start arc edge
                    else 
                    {
                        int32_t xPoint;

                        if (drawPtEnd.x > arcStartPt1.x)
                        {
                            drawPtEnd.x = arcStartPt1.x;
                        }
                        
                        if (drawPtEnd.y <= arcStartPt1.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtEnd.y <= arcStartPt0.y &&
                                 drawPtEnd.y > arcStartPt1.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcStartPt0, arcStartPt1, drawPtStart.y);
                            
                            if (arcStartPt0.y != arcStartPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                }
                //If end angle is in Q4, test agains Q4
                else if (270 <= absEndAngle && absEndAngle <= 360)
                {
                    //CCW, draw line from end arc edge
                    if (dir == LE_CCW) 
                    {
                        int32_t xPoint;

                        if (drawPtEnd.x > arcEndPt1.x)
                        {
                            drawPtEnd.x = arcEndPt1.x;
                        }
                        
                        if (drawPtEnd.y <= arcEndPt1.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtEnd.y <= arcEndPt0.y && 
                                 drawPtEnd.y > arcEndPt1.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtEnd.y);
                            
                            if (arcEndPt0.y != arcEndPt1.y && xPoint < drawPtEnd.x)
                            {
                                drawPtEnd.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                    //CW, draw line from end arc edge
                    else 
                    {
                        int32_t xPoint;

                        if (drawPtStart.y >= arcEndPt0.y)
                        {
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                        else if (drawPtStart.y < arcEndPt0.y &&
                                 drawPtStart.y >= arcEndPt1.y)
                        {
                            xPoint = leGetXGivenYOnLine(arcEndPt0, arcEndPt1, drawPtStart.y);
                            
                            if (arcStartPt1.y != arcEndPt0.y && xPoint > drawPtStart.x)
                            {
                                drawPtStart.x = xPoint;
                            }
                            
                            drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                        }
                    }
                }
                else
                {
                    //Otherwise, draw all points
                    drawArcFillLine(x, y, &drawPtStart, &drawPtEnd, clr);
                }
            }
            while(0);
        }
    }

    return LE_SUCCESS;
}
#endif
