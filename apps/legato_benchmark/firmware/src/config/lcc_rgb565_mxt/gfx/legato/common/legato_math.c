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

#include <math.h>

#include "gfx/legato/common/legato_math.h"

#define COSINE_TABLE_ENTRIES 90

const int16_t _cosTable[COSINE_TABLE_ENTRIES + 1] =
{
    256, 256, 256, 256, 255, 255, 255, 254, 254, 253,
    252, 251, 250, 249, 248, 247, 246, 245, 243, 242,
    241, 239, 237, 236, 234, 232, 230, 228, 226, 224,
    222, 219, 217, 215, 212, 210, 207, 204, 202, 199,
    196, 193, 190, 187, 184, 181, 178, 175, 171, 168,
    165, 161, 158, 154, 150, 147, 143, 139, 136, 132,
    128, 124, 120, 116, 112, 108, 104, 100, 96,  92,
    88,  83,  79,  75,  71,  66,  62,  58,  53,  49,
    44,  40,  36,  31,  27,  22,  18,  13,  9,   4,
    0
};

int16_t leNormalize360(int16_t t)
{
    if (t >= 360)
    {
        t -= 360;
    }

    if (t < 0)
    {
        t += 360;
    }
    
    return t;
}

int16_t leSineCosineGet(int16_t v, LE_TRIG_FUNCTION_TYPE type)
{
    // if angle is neg, convert to pos equivalent
    if (v < 0)
    {
    	v += 360;   					
    }
           
    if(v > COSINE_TABLE_ENTRIES * 3)
    {
        v -= (COSINE_TABLE_ENTRIES * 3);
    
        if (type == LE_TRIG_SINE_TYPE)
        {
            return (-_cosTable[v]);
        }
        else
        {
            return (_cosTable[COSINE_TABLE_ENTRIES - v]);
        }
    }
    else if(v > COSINE_TABLE_ENTRIES * 2)
    {
        v -= (COSINE_TABLE_ENTRIES * 2);
        
        if (type == LE_TRIG_SINE_TYPE)
        {
            return (-_cosTable[(COSINE_TABLE_ENTRIES - v)]);
        }
        else
        {
            return (-_cosTable[v]);
        }
    }
    else if(v > COSINE_TABLE_ENTRIES)
    {
        v -= (COSINE_TABLE_ENTRIES);
        
        if (type == LE_TRIG_SINE_TYPE)
        {
            return (_cosTable[v]);
        }
        else
        {
            return (-_cosTable[COSINE_TABLE_ENTRIES - v]);
        }
    }
    else
    {
        if (type == LE_TRIG_SINE_TYPE)
        {
            return (_cosTable[COSINE_TABLE_ENTRIES - v]);
        }
        else
        {
            return (_cosTable[v]);
        }    
    }
}

leResult lePolarToXY(int32_t r, int32_t a, lePoint* p)
{
    p->x = (r * leSineCosineGet(a, LE_TRIG_COSINE_TYPE)) / 256;
    p->y = (r * leSineCosineGet(a, LE_TRIG_SINE_TYPE)) / 256;
    
    return LE_SUCCESS;
}

leResult leEllipsePoint(int32_t t, int32_t a, int32_t b, int32_t theta, lePoint* p)
{
    p->x = (a * leSineCosineGet(t, LE_TRIG_COSINE_TYPE) * leSineCosineGet(theta, LE_TRIG_COSINE_TYPE) / (256 * 256))
            - (b * leSineCosineGet(t, LE_TRIG_SINE_TYPE) * leSineCosineGet(theta, LE_TRIG_SINE_TYPE) / (256 * 256));
            
    p->y = (a * leSineCosineGet(t, LE_TRIG_COSINE_TYPE) * leSineCosineGet(theta, LE_TRIG_SINE_TYPE) / (256 * 256))
            + (b * leSineCosineGet(t, LE_TRIG_SINE_TYPE) * leSineCosineGet(theta, LE_TRIG_COSINE_TYPE) / (256 * 256));
    
    return LE_SUCCESS;
}

double leAtan(double x)
{
    //use math.h atan for now. will optimize with LUT if needed.
    return atan(x);
}

int32_t leMini(int32_t l, int32_t r)
{
    return l < r ? l : r;
}

int32_t leMaxi(int32_t l, int32_t r)
{
    return l > r ? l : r;
}

float leMinf(float l, float r)
{
    return l < r ? l : r;
}

float leMaxf(float l, float r)
{
    return l > r ? l : r;
}

int32_t leClampi(int32_t min, int32_t max, int32_t i)
{
    if(i < min)
    {
        return min;
    }
    else if(i > max)
    {
        return max;
    }
        
    return i;
}

float leClampf(float min, float max, float f)
{
    if(f < min)
    {
        return min;
    }
    else if(f > max)
    {
        return max;
    }
        
    return f;
}

uint32_t lePercent(uint32_t l, uint32_t r)
{
    return (l * 10000) / r;
}

uint32_t lePercentWholeRounded(uint32_t l, uint32_t r)
{
    int32_t per = ((((int32_t)l * 10000) / (int32_t)r) + 50) / 100;
    
    if (per < 0)
    {
        return 0;
    }
    else
    {
        return per;
    }    
}

uint32_t lePercentOf(uint32_t num, uint32_t percent)
{
    int whl = ((num * 100) * percent) / 10000;
    int dec = (((num * 1000) * percent) / 10000) % 10;
    
    if(dec >= 5)
    {
        whl++;
    }
    
    return whl;
}

void lePercentOfDec(uint32_t num, uint32_t percent, uint32_t* whl, uint32_t* dec)
{
    *whl = ((num * 100) * percent) / 10000;
    *dec = (((num * 1000) * percent) / 1000) % 100;
}

/*int32_t leScaleInteger(int num, int oldMax, int newMax)
{
    num = lePercent(num, oldMax);
    num = lePercentOf(newMax, num);
    
    return num;
}*/

int32_t leScaleIntegerSigned(int32_t num, int32_t oldMax, int32_t newMax)
{
    float percent;
    
    percent = (float)num / (float)oldMax;
    percent *= newMax;
    
    return (int32_t)percent;
}


uint32_t leScaleInteger(uint32_t num, uint32_t oldMax, uint32_t newMax)
{
    float percent;
    
    percent = (float)num / (float)oldMax;
    percent *= newMax;
    
    return (uint32_t)percent;
}

/*void leRebaseValue(int32_t imin, int32_t ival, uint32_t* uval)
{
    int32_t min, max;
    
    if(imin == ival)
    {
        *uval = 0;
        
        return;
    }
    
    *umax = imax - min;
}*/

uint32_t leAbsoluteValue(int32_t val)
{
    uint32_t temp = val >> 31;

    val ^= temp;
    val += temp & 1;
    
    return (uint32_t)val;
}

int32_t leLerp(int32_t l, int32_t r, uint32_t per)
{
    int32_t imin, imax;
    uint32_t umax, val;
    
    if(l == r)
        return l;
        
    if(per <= 0)
        return l;
    
    if(per >= 100)
        return r;
        
    imin = l;
    imax = r;
    
    if(l > r)
    {
        imin = r;
        imax = l;
        
		umax = imax - imin;

		val = lePercentOf(umax, per);

		return imax - val;
	}
	else
	{
		umax = imax - imin;

		val = lePercentOf(umax, per);

		return imin + val;
	}        
}

int32_t leDivideRounding(int32_t num, int32_t denom)
{
    int32_t lnum, ldenom, lquo;
    
    if(denom == 0)
        return 0;
        
    lnum = num * 100;
    ldenom = denom;// * 100;
    
    lquo = lnum / ldenom;
    
    if(lquo % 100 >= 50)
    {
        return (num / denom) + 1;
    }
    else
    {
        return num / denom;
    }
}

//Returns true if arc overlaps with quadrant
leBool leArcsOverlapQuadrant(int32_t startAngleArc0, 
                             int32_t endAngleArc0, 
                             leArcDir dir, 
                             uint32_t quadrant)
{
    uint32_t baseAngle;
    int32_t angle;
    leBool retval = LE_FALSE;
    int32_t quadStartAngle, quadEndAngle;
    int32_t startTestAngle, endTestAngle;

    switch (quadrant)
    {
        case LE_Q1:
        {
            quadStartAngle = 0;
            quadEndAngle = 90;
        
            break;
        }
        case LE_Q2:
        {
            quadStartAngle = 91;
            quadEndAngle = 180;
        
            break;
        }
        case LE_Q3:
        {
            quadStartAngle = 181;
            quadEndAngle = 270;
        
            break;
        }
        case LE_Q4:
        {
            quadStartAngle = 271;
            quadEndAngle = 360;
        
            break;
        }
        default:
        {
            return LE_FALSE;
        }
    }

    //Re-orient angles to a CCW orientation
    if (dir == LE_CW)
    {
        angle = startAngleArc0;
        startAngleArc0 = endAngleArc0;
        endAngleArc0 = angle;
    }

    //if arc wraps around 0/360, do triple arc test
    if (startAngleArc0 > endAngleArc0)
    {
        //split between (start -> 360) and (0 -> end)
        startTestAngle = startAngleArc0;
        endTestAngle = 360;

        if (startTestAngle <= quadStartAngle)
        {
            baseAngle = 0;
        }
        else
        {
            baseAngle = 1;
        }
        
        if (baseAngle == 0 && (endTestAngle >= quadStartAngle))
        {
            retval = LE_TRUE;
        }
        else if (baseAngle == 1 && (quadEndAngle >= startTestAngle))
        {
            retval = LE_TRUE;
        }
        else
        {
            //split between (start -> 360) and (0 -> end)
            startTestAngle = 0;
            endTestAngle = endAngleArc0;

            if (startTestAngle <= quadStartAngle) 
            {
                baseAngle = 0;
            }
            else
            {
                baseAngle = 1;
            }
            
            if (baseAngle == 0 && (endTestAngle >= quadStartAngle))
            {
                retval = LE_TRUE;
            }
            else if (baseAngle == 1 && (quadEndAngle >= startTestAngle))
            {
                retval = LE_TRUE;
            }
        }
    }
    else if (startAngleArc0 < endAngleArc0)
    {
        if (startAngleArc0 <= quadStartAngle)
        {
            baseAngle = 0;
        }
        else
        {
            baseAngle = 1;
        }
        
        if (baseAngle == 0 && (endAngleArc0 >= quadStartAngle))
        {
            retval = LE_TRUE;
        }
        else if (baseAngle == 1 && (quadEndAngle >= startAngleArc0))
        {
            retval = LE_TRUE;
        }
    }
    else //circle
    {
        retval = LE_TRUE;
    }
    
    return retval;
}

void leSortPointsX(lePoint* p1, lePoint* p2)
{
    lePoint tpt;
    
    if(p1->x > p2->x)
    {
        tpt = *p1;
        *p2 = *p1;
        *p1 = tpt;
    }
}

void leSortPointsY(lePoint* p1, lePoint* p2)
{
    lePoint tpt;
    
    if(p1->y > p2->y)
    {
        tpt = *p1;
        *p2 = *p1;
        *p1 = tpt;
    }
}

int32_t leGetXGivenYOnLine(lePoint p1, lePoint p2, int32_t y)
{
    if (p1.y == p2.y)
        return p1.x;
    
    return (p1.x - ((p1.x - p2.x) * (p1.y - y))/(p1.y - p2.y));
}

int32_t leGetYGivenXOnLine(lePoint p1, lePoint p2, int32_t x)
{
    if (p1.x == p2.x)
        return p1.y;
    
    return (p1.y - ((p1.y - p2.y) * (p1.x - x))/(p1.x - p2.x));
}