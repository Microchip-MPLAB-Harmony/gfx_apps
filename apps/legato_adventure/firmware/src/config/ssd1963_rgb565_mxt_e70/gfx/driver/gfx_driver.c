/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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
#include "gfx/driver/gfx_driver.h"

#define COSINE_TABLE_ENTRIES 90

#define TRIG_SCALAR 256

typedef gfxColor (*color_convert_fn_ptr)(gfxColor);

static gfxColor no_conv(gfxColor color);

int32_t gfxScaleIntegerSigned(int32_t num, int32_t oldMax, int32_t newMax);
uint32_t gfxScaleInteger(uint32_t num, uint32_t oldMax, uint32_t newMax);


/* color conversion function definitions */
static gfxColor gs8_rgb332(gfxColor color);
static gfxColor gs8_rgb565(gfxColor color);
static gfxColor gs8_rgba5551(gfxColor color);
static gfxColor gs8_rgb888(gfxColor color);
static gfxColor gs8_rgba8888(gfxColor color);
static gfxColor gs8_argb8888(gfxColor color);

static gfxColor rgb332_gs8(gfxColor color);
static gfxColor rgb332_rgb565(gfxColor color);
static gfxColor rgb332_rgba5551(gfxColor color);
static gfxColor rgb332_rgb888(gfxColor color);
static gfxColor rgb332_rgba8888(gfxColor color);
static gfxColor rgb332_argb8888(gfxColor color);

static gfxColor rgb565_gs8(gfxColor color);
static gfxColor rgb565_rgb332(gfxColor color);
static gfxColor rgb565_rgba5551(gfxColor color);
static gfxColor rgb565_rgb888(gfxColor color);
static gfxColor rgb565_rgba8888(gfxColor color);
static gfxColor rgb565_argb8888(gfxColor color);

static gfxColor rgba5551_gs8(gfxColor color);
static gfxColor rgba5551_rgb332(gfxColor color);
static gfxColor rgba5551_rgb565(gfxColor color);
static gfxColor rgba5551_rgb888(gfxColor color);
static gfxColor rgba5551_rgba8888(gfxColor color);
static gfxColor rgba5551_argb8888(gfxColor color);

static gfxColor rgb888_gs8(gfxColor color);
static gfxColor rgb888_rgb332(gfxColor color);
static gfxColor rgb888_rgb565(gfxColor color);
static gfxColor rgb888_rgba5551(gfxColor color);
static gfxColor rgb888_rgba8888(gfxColor color);
static gfxColor rgb888_argb8888(gfxColor color);

static gfxColor rgba8888_gs8(gfxColor color);
static gfxColor rgba8888_rgb332(gfxColor color);
static gfxColor rgba8888_rgb565(gfxColor color);
static gfxColor rgba8888_rgba5551(gfxColor color);
static gfxColor rgba8888_rgb888(gfxColor color);
static gfxColor rgba8888_argb8888(gfxColor color);

static gfxColor argb8888_rgba5551(gfxColor color);
static gfxColor argb8888_rgb888(gfxColor color);
static gfxColor argb8888_rgba8888(gfxColor color);

#if 0
static gfxColor lut_gs8(gfxColor color);
static gfxColor lut_rgb332(gfxColor color);
static gfxColor lut_rgb565(gfxColor color);
static gfxColor lut_rgba5551(gfxColor color);
static gfxColor lut_rgb888(gfxColor color);
static gfxColor lut_rgba8888(gfxColor color);
static gfxColor lut_argb8888(gfxColor color);
#endif

/* color conversion function matrix */
color_convert_fn_ptr gfx_color_convert_table[GFX_COLOR_MODE_COUNT][GFX_COLOR_MODE_COUNT] =
{
//                GS8            RGB332            RGB565            RGBA_5551           RGB_888           RGBA_8888           ARGB_8888           LUT1      LUT4      LUT8
/* GS8       */ { &no_conv,      &gs8_rgb332,      &gs8_rgb565,      &gs8_rgba5551,      &gs8_rgb888,      &gs8_rgba8888,      &gs8_argb8888,      &no_conv, &no_conv, &no_conv },
/* RGB332    */ { &rgb332_gs8,   &no_conv,         &rgb332_rgb565,   &rgb332_rgba5551,   &rgb332_rgb888,   &rgb332_rgba8888,   &rgb332_argb8888,   &no_conv, &no_conv, &no_conv },
/* RGB565    */ { &rgb565_gs8,   &rgb565_rgb332,   &no_conv,         &rgb565_rgba5551,   &rgb565_rgb888,   &rgb565_rgba8888,   &rgb565_argb8888,   &no_conv, &no_conv, &no_conv },
/* RGBA_5551 */ { &rgba5551_gs8, &rgba5551_rgb332, &rgba5551_rgb565, &no_conv,           &rgba5551_rgb888, &rgba5551_rgba8888, &rgba5551_argb8888, &no_conv, &no_conv, &no_conv },
/* RGB_888   */ { &rgb888_gs8,   &rgb888_rgb332,   &rgb888_rgb565,   &rgb888_rgba5551,   &no_conv,         &rgb888_rgba8888,   &rgb888_argb8888,   &no_conv, &no_conv, &no_conv },
/* RGBA_8888 */ { &rgba8888_gs8, &rgba8888_rgb332, &rgba8888_rgb565, &rgba8888_rgba5551, &rgba8888_rgb888, &no_conv,           &rgba8888_argb8888, &no_conv, &no_conv, &no_conv },
/* ARGB_8888 */ { &rgb888_gs8,   &rgb888_rgb332,   &rgb888_rgb565,   &argb8888_rgba5551, &argb8888_rgb888, &argb8888_rgba8888, &no_conv,           &no_conv, &no_conv, &no_conv },
/* LUT1      */ { &no_conv,      &no_conv,         &no_conv,         &no_conv,           &no_conv,         &no_conv,           &no_conv,           &no_conv, &no_conv, &no_conv },
/* LUT4      */ { &no_conv,      &no_conv,         &no_conv,         &no_conv,           &no_conv,         &no_conv,           &no_conv,           &no_conv, &no_conv, &no_conv },
/* LUT8      */ { &no_conv,      &no_conv,         &no_conv,         &no_conv,           &no_conv,         &no_conv,           &no_conv,           &no_conv, &no_conv, &no_conv },
};

/*
  From RGB to YUV

   Y = 0.299R + 0.587G + 0.114B
   U = 0.492 (B-Y)
   V = 0.877 (R-Y)

   It can also be represented as:

   Y =  0.299R + 0.587G + 0.114B
   U = -0.147R - 0.289G + 0.436B
   V =  0.615R - 0.515G - 0.100B


   From YUV to RGB

   R = Y + 1.140V
   G = Y - 0.395U - 0.581V
   B = Y + 2.032U
*/

static gfxColor no_conv(gfxColor color)
{
    return color;
}

/*
grayscale conversion formula
0.21 R + 0.72 G + 0.07 B
*/

static gfxColor gs8_rgb332(gfxColor color)
{
    gfxColor res;

    // red
    res = color & RGB_332_RED_MASK;

    // green
    res |= res >> 3;

    // blue
    res |= res >> 6;

    return res;
}

static gfxColor gs8_rgb565(gfxColor color)
{
    gfxColor res;

    // red
    res = (color & 0xF8) << 8;

    // green
    res |= (color & 0xFC) << 3;

    // blue
    res |= (color & 0xF8) >> 3;

    return res;
}

static gfxColor gs8_rgba5551(gfxColor color)
{
    gfxColor res;

    // red
    res = (color & 0xF8) << 8;

    // green
    res |= (color & 0xF8) << 3;

    // blue
    res |= (color & 0xF8) >> 2;

    // alpha
    res |= RGBA_5551_ALPHA_MASK;

    return res;
}

static gfxColor gs8_rgb888(gfxColor color)
{
    // blue
    gfxColor res = color;

    // red
    res = color << 16;

    // green
    res |= color << 8;

    // green
    res |= color;

    return res;
}

static gfxColor gs8_rgba8888(gfxColor color)
{
    gfxColor res;

    // red
    res = color << 24;

    // green
    res |= color << 16;

    // blue
    res |= color << 8;

    // alpha
    res |= 0xFF;

    return res;
}

static gfxColor gs8_argb8888(gfxColor color)
{
    gfxColor res;

    // red
    res = color << 16;

    // green
    res |= color << 8;

    // blue
    res |= color;

    // alpha
    res |= 0xFF000000;

    return res;
}

static gfxColor rgb332_gs8(gfxColor color)
{
    //0.21 R + 0.72 G + 0.07 B
    uint32_t red, green, blue;

    red = (color & RGB_332_RED_MASK) >> 5;
    red = gfxScaleInteger(red, RGB_3_BITS, 55);

    green = (color & RGB_332_GREEN_MASK) >> 2;
    green = gfxScaleInteger(green, RGB_3_BITS, 183);

    blue = (color & RGB_332_BLUE_MASK);
    blue = gfxScaleInteger(blue, RGB_2_BITS, 17);

    return red + green + blue;
}

static gfxColor rgb332_rgb565(gfxColor color)
{
    uint32_t red, green, blue;

    red = ((color & RGB_332_RED_MASK) << 8) | 0x1800;
    green = ((color & RGB_332_GREEN_MASK) << 6) | 0xE0;
    blue = ((color & RGB_332_BLUE_MASK) << 3) | 0x3;

    return red | green | blue;
}

static gfxColor rgb332_rgba5551(gfxColor color)
{
    uint32_t red, green, blue;

    red = ((color & RGB_332_RED_MASK) << 8) | 0x1800;
    green = ((color & RGB_332_GREEN_MASK) << 6) | 0xC0;
    blue = ((color & RGB_332_BLUE_MASK) << 4) | 0x6;

    return red | green | blue;
}

static gfxColor rgb332_rgb888(gfxColor color)
{
    uint32_t red, green, blue;

    red = ((color & RGB_332_RED_MASK) << 16) | 0x1F0000;
    green = ((color & RGB_332_GREEN_MASK) << 11) | 0x1F00;
    blue = ((color & RGB_332_BLUE_MASK) << 6) | 0x1F;

    return red | green | blue;
}

static gfxColor rgb332_rgba8888(gfxColor color)
{
    uint32_t red, green, blue;

    red = ((color & RGB_332_RED_MASK) << 24) | 0x1F000000;
    green = ((color & RGB_332_GREEN_MASK) << 19) | 0x1F0000;
    blue = ((color & RGB_332_BLUE_MASK) << 14) | 0x1F00;

    return red | green | blue | 0xFF;
}

static gfxColor rgb332_argb8888(gfxColor color)
{
    uint32_t red, green, blue;

    red = ((color & RGB_332_RED_MASK) << 16) | 0x1F0000;
    green = ((color & RGB_332_GREEN_MASK) << 11) | 0x1F00;
    blue = ((color & RGB_332_BLUE_MASK) << 6) | 0x1F;

    return 0xFF000000 | red | green | blue;
}

static gfxColor rgb565_gs8(gfxColor color)
{
    //0.21 R + 0.72 G + 0.07 B
    uint32_t red, green, blue;

    red = (color & RGB_565_RED_MASK) >> 11;
    red = gfxScaleInteger(red, 7, 55);

    green = (color & RGB_565_GREEN_MASK) >> 5;
    green = gfxScaleInteger(green, 7, 183);

    blue = (color & RGB_565_BLUE_MASK);
    blue = gfxScaleInteger(blue, 7, 17);

    return red + green + blue;
}

static gfxColor rgb565_rgb332(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & 0xE000) >> 8;
    green = (color & 0x700) >> 6;
    blue = (color & 0x18) >> 3;

    return red | green | blue;
}

static gfxColor rgb565_rgba5551(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & RGB_565_RED_MASK);
    green = (color & RGBA_5551_GREEN_MASK);
    blue = (color & RGB_565_BLUE_MASK) << 1;

    return red | green | blue | RGBA_5551_ALPHA_MASK;
}

static gfxColor rgb565_rgb888(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & RGB_565_RED_MASK) << 8;
    green = (color & RGB_565_GREEN_MASK) << 5;
    blue = (color & RGB_565_BLUE_MASK) << 3;

    return red | green | blue;
}

static gfxColor rgb565_rgba8888(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & RGB_565_RED_MASK) << 16;
    green = (color & RGB_565_GREEN_MASK) << 13;
    blue = (color & RGB_565_BLUE_MASK) << 11;

    return red | green | blue | 0xFF;
}

static gfxColor rgb565_argb8888(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & RGB_565_RED_MASK) << 8;
    green = (color & RGB_565_GREEN_MASK) << 5;
    blue = (color & RGB_565_BLUE_MASK) << 3;

    return 0xFF000000 | red | green | blue;
}

static gfxColor rgba5551_gs8(gfxColor color)
{
    return color;
}

static gfxColor rgba5551_rgb332(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & 0xE000) >> 8;
    green = (color & 0x700) >> 6;
    blue = (color & 0x30) >> 4;

    return red | green | blue;
}

static gfxColor rgba5551_rgb565(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & RGBA_5551_RED_MASK);
    green = (color & RGBA_5551_GREEN_MASK) | 0x20;
    blue = (color & RGBA_5551_BLUE_MASK) >> 1;

    return red | green | blue;
}

static gfxColor rgba5551_rgb888(gfxColor color)
{
    uint32_t red, green, blue;

    red = ((color & RGBA_5551_RED_MASK) << 8) | 0x70000;
    green = ((color & RGBA_5551_GREEN_MASK) << 5) | 0x700;
    blue = ((color & RGBA_5551_BLUE_MASK) << 2) | 0x7;

    return red | green | blue;
}

static gfxColor rgba5551_rgba8888(gfxColor color)
{
    uint32_t red, green, blue;

    red = ((color & RGBA_5551_RED_MASK) << 16) | 0x7000000;
    green = ((color & RGBA_5551_GREEN_MASK) << 13) | 0x70000;
    blue = ((color & RGBA_5551_BLUE_MASK) << 10) | 0x700;

    return red | green | blue | ((color & RGBA_5551_ALPHA_MASK) > 0 ? 0xFF : 0x0);
}

static gfxColor rgba5551_argb8888(gfxColor color)
{
    uint32_t red, green, blue;

    red = ((color & RGBA_5551_RED_MASK) << 8) | 0x70000;
    green = ((color & RGBA_5551_GREEN_MASK) << 5) | 0x700;
    blue = ((color & RGBA_5551_BLUE_MASK) << 2) | 0x7;

    return ((color & RGBA_5551_ALPHA_MASK) > 0 ? 0xFF000000 : 0x0) | red | green | blue;
}

static gfxColor rgb888_gs8(gfxColor color)
{
    return color;
}

static gfxColor rgb888_rgb332(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & 0xE00000) >> 17;
    green = (color & 0xE000) >> 8;
    blue = (color & 0xC0) >> 4;

    return red | green | blue;
}

static gfxColor rgb888_rgb565(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & 0xF80000) >> 8;
    green = (color & 0xFC00) >> 5;
    blue = (color & 0xF8) >> 3;

    return red | green | blue;
}

static gfxColor rgb888_rgba5551(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & 0xF80000) >> 8;
    green = (color & 0xF800) >> 5;
    blue = (color & 0xF8) >> 2;

    return red | green | blue | RGBA_5551_ALPHA_MASK;
}

static gfxColor rgb888_rgba8888(gfxColor color)
{
    return (color << 8) | 0xFF;
}

static gfxColor rgb888_argb8888(gfxColor color)
{
    return color | 0xFF000000;
}

static gfxColor rgba8888_gs8(gfxColor color)
{
    return color;
}

static gfxColor rgba8888_rgb332(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & 0xE0000000) >> 24;
    green = (color & 0xE00000) >> 19;
    blue = (color & 0xC000) >> 14;

    return red | green | blue;
}

static gfxColor rgba8888_rgb565(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & 0xF8000000) >> 16;
    green = (color & 0xFC0000) >> 13;
    blue = (color & 0xF800) >> 11;

    return red | green | blue;
}

static gfxColor rgba8888_rgba5551(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & 0xF8000000) >> 16;
    green = (color & 0xF80000) >> 13;
    blue = (color & 0xF800) >> 10;

    return red | green | blue | ((color & RGBA_8888_ALPHA_MASK) > 0 ? RGBA_5551_ALPHA_MASK : 0);
}

static gfxColor rgba8888_rgb888(gfxColor color)
{
    gfxColor res;

    // red
    res  = (color & 0xFF000000) >> 8;

    // green
    res |= (color & 0x00FF0000) >> 8;

    // blue
    res |= (color & 0x0000FF00) >> 8;

    return res;
}

static gfxColor rgba8888_argb8888(gfxColor color)
{
    return (color >> 8) | (((color & 0xFF) << 24));
}

static gfxColor argb8888_rgba5551(gfxColor color)
{
    uint32_t red, green, blue;

    red = (color & 0xF80000) >> 8;
    green = (color & 0xF800) >> 5;
    blue = (color & 0xF8) >> 2;

    return red | green | blue | ((color & RGBA_8888_ALPHA_MASK) > 0 ? RGBA_5551_ALPHA_MASK : 0);
}

static gfxColor argb8888_rgb888(gfxColor color)
{
    return color & 0xFFFFFF;
}

static gfxColor argb8888_rgba8888(gfxColor color)
{
    return (color << 8) | ((color & 0xFF000000) >> 24);
}


const gfxColorModeInfo gfxColorInfoTable[] =
{

    {1,8,  GFX_BPP8,  {0x0,0x0,0x0,0x0},{0x0,0x0,0x0,0x0}},                        // GFX_COLOR_MODE_GS_8
    {1,8,  GFX_BPP8,  {0xE0,0x1C,0x3,0x0},{0x0,0x0,0x0,0x0}},                      // GFX_COLOR_MODE_RGB_332
    {2,16, GFX_BPP16, {0xF800,0x07E0,0x001F,0x0},{11,5,0,0}},                      // GFX_COLOR_MODE_RGB_565
    {2,16, GFX_BPP16, {0xF800,0x07C0,0x003E,0x1},{11,6,1,0}},                      // GFX_COLOR_MODE_RGBA_5551
    {3,24, GFX_BPP24, {0xFF0000,0x00FF00,0x0000FF,0x0},{16,8,0,0}},                // GFX_COLOR_MODE_RGB_888
    {4,32, GFX_BPP32, {0xFF000000,0x00FF0000,0x0000FF00,0x000000FF},{24,16,8,0}},  // GFX_COLOR_MODE_RGBA_8888
    {4,32, GFX_BPP32, {0x00FF0000,0x0000FF00,0x000000FF,0xFF000000},{16,8,0,24}},  // GFX_COLOR_MODE_ARGB_8888
    {1,1,  GFX_BPP1,  {0x0,0x0,0x0,0x0},{0x0,0x0,0x0,0x0}},                        // GFX_COLOR_MODE_INDEX_1
    {1,4,  GFX_BPP4,  {0x0,0x0,0x0,0x0},{0x0,0x0,0x0,0x0}},                        // GFX_COLOR_MODE_INDEX_4
    {1,8,  GFX_BPP8,  {0x0,0x0,0x0,0x0},{0x0,0x0,0x0,0x0}},                        // GFX_COLOR_MODE_INDEX_8
};

uint32_t gfxColorChannelRed(gfxColor clr, gfxColorMode mode)
{
    return (clr & gfxColorInfoTable[mode].mask.red) >> gfxColorInfoTable[mode].shift.red;
}

uint32_t gfxColorChannelGreen(gfxColor clr, gfxColorMode mode)
{
    return (clr & gfxColorInfoTable[mode].mask.green) >> gfxColorInfoTable[mode].shift.green;
}

uint32_t gfxColorChannelBlue(gfxColor clr, gfxColorMode mode)
{
    return (clr & gfxColorInfoTable[mode].mask.blue) >> gfxColorInfoTable[mode].shift.blue;
}

uint32_t gfxColorChannelAlpha(gfxColor clr, gfxColorMode mode)
{
    if(mode == GFX_COLOR_MODE_RGBA_5551 ||
       mode == GFX_COLOR_MODE_RGBA_8888 ||
       mode == GFX_COLOR_MODE_ARGB_8888)
        return (clr & gfxColorInfoTable[mode].mask.alpha) >> gfxColorInfoTable[mode].shift.alpha;

    return 0xFF;
}

const int16_t _gfxCosTable[COSINE_TABLE_ENTRIES + 1] =
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

int32_t gfxNormalizeAngle(int32_t t)
{
    while(t >= 360)
    {
        t -= 360;
    }

    while(t < 0)
    {
        t += 360;
    }

    return t;
}

int32_t gfxSin(int32_t v)
{
    // if angle is neg, convert to pos equivalent
    v = gfxNormalizeAngle(v);

    if(v > COSINE_TABLE_ENTRIES * 3)
    {
        v -= (COSINE_TABLE_ENTRIES * 3);

        return (-_gfxCosTable[v]);
    }
    else if(v > COSINE_TABLE_ENTRIES * 2)
    {
        v -= (COSINE_TABLE_ENTRIES * 2);

        return (-_gfxCosTable[(COSINE_TABLE_ENTRIES - v)]);
    }
    else if(v > COSINE_TABLE_ENTRIES)
    {
        v -= (COSINE_TABLE_ENTRIES);

        return (_gfxCosTable[v]);
    }
    else
    {
        return (_gfxCosTable[COSINE_TABLE_ENTRIES - v]);
    }
}

int32_t gfxCos(int32_t v)
{
    // if angle is neg, convert to pos equivalent
    v = gfxNormalizeAngle(v);

    if(v > COSINE_TABLE_ENTRIES * 3)
    {
        v -= (COSINE_TABLE_ENTRIES * 3);

        return (_gfxCosTable[COSINE_TABLE_ENTRIES - v]);
    }
    else if(v > COSINE_TABLE_ENTRIES * 2)
    {
        v -= (COSINE_TABLE_ENTRIES * 2);

        return (-_gfxCosTable[v]);
    }
    else if(v > COSINE_TABLE_ENTRIES)
    {
        v -= (COSINE_TABLE_ENTRIES);

        return (-_gfxCosTable[COSINE_TABLE_ENTRIES - v]);
    }
    else
    {
        return (_gfxCosTable[v]);
    }
}



gfxResult gfxPolarToXY(int32_t r, int32_t a, gfxPoint* p)
{
    p->x = (r * gfxCos(a) / TRIG_SCALAR);
    p->y = (r * gfxSin(a) / TRIG_SCALAR);

    return GFX_SUCCESS;
}

gfxResult gfxEllipsePoint(int32_t t, int32_t a, int32_t b, int32_t theta, gfxPoint* p)
{
    t = gfxNormalizeAngle(t);

    p->x = (a * gfxCos(t) * gfxCos(theta) / (TRIG_SCALAR * TRIG_SCALAR)) -
           (b * gfxSin(t) * gfxSin(theta) / (TRIG_SCALAR * TRIG_SCALAR));

    p->y = (a * gfxCos(t) * gfxSin(theta) / (TRIG_SCALAR * TRIG_SCALAR)) +
           (b * gfxSin(t) * gfxCos(theta) / (TRIG_SCALAR * TRIG_SCALAR));

    return GFX_SUCCESS;
}

double gfxAtan(double x)
{
    //use math.h atan for now. will optimize with LUT if needed.
    return atan(x);
}

int32_t gfxMini(int32_t l, int32_t r)
{
    return l < r ? l : r;
}

int32_t gfxMaxi(int32_t l, int32_t r)
{
    return l > r ? l : r;
}

float gfxMinf(float l, float r)
{
    return l < r ? l : r;
}

float gfxMaxf(float l, float r)
{
    return l > r ? l : r;
}

int32_t gfxClampi(int32_t min, int32_t max, int32_t i)
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

float gfxClampf(float min, float max, float f)
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

uint32_t gfxPercent(uint32_t l, uint32_t r)
{
    return (l * 10000) / r;
}

uint32_t gfxPercentWhogfxRounded(uint32_t l, uint32_t r)
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

uint32_t gfxPercentOf(uint32_t num, uint32_t percent)
{
    int whl = ((num * 100) * percent) / 10000;
    int dec = (((num * 1000) * percent) / 10000) % 10;

    if(dec >= 5)
    {
        whl++;
    }

    return whl;
}

void gfxPercentOfDec(uint32_t num, uint32_t percent, uint32_t* whl, uint32_t* dec)
{
    *whl = ((num * 100) * percent) / 10000;
    *dec = (((num * 1000) * percent) / 1000) % 100;
}

/*int32_t gfxScaleInteger(int num, int oldMax, int newMax)
{
    num = gfxPercent(num, oldMax);
    num = gfxPercentOf(newMax, num);

    return num;
}*/

int32_t gfxScaleIntegerSigned(int32_t num, int32_t oldMax, int32_t newMax)
{
    float percent;

    percent = (float)num / (float)oldMax;
    percent *= newMax;

    return (int32_t)percent;
}


uint32_t gfxScaleInteger(uint32_t num, uint32_t oldMax, uint32_t newMax)
{
    float percent;

    percent = (float)num / (float)oldMax;
    percent *= newMax;

    return (uint32_t)percent;
}

/*void gfxRebaseValue(int32_t imin, int32_t ival, uint32_t* uval)
{
    int32_t min, max;

    if(imin == ival)
    {
        *uval = 0;

        return;
    }

    *umax = imax - min;
}*/

uint32_t gfxAbsoluteValue(int32_t val)
{
    uint32_t temp = val >> 31;

    val ^= temp;
    val += temp & 1;

    return (uint32_t)val;
}

int32_t gfxLerp(int32_t l, int32_t r, uint32_t per)
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

                val = gfxPercentOf(umax, per);

                return imax - val;
        }
        else
        {
                umax = imax - imin;

                val = gfxPercentOf(umax, per);

                return imin + val;
        }
}

int32_t gfxDivideRounding(int32_t num, int32_t denom)
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
gfxBool gfxArcsOverlapQuadrant(int32_t startAnggfxArc0,
                             int32_t endAnggfxArc0,
                             gfxArcDir dir,
                             uint32_t quadrant)
{
    uint32_t baseAngle;
    int32_t angle;
    gfxBool retval = GFX_FALSE;
    int32_t quadStartAngle, quadEndAngle;
    int32_t startTestAngle, endTestAngle;

    switch (quadrant)
    {
        case GFX_Q1:
        {
            quadStartAngle = 0;
            quadEndAngle = 90;

            break;
        }
        case GFX_Q2:
        {
            quadStartAngle = 91;
            quadEndAngle = 180;

            break;
        }
        case GFX_Q3:
        {
            quadStartAngle = 181;
            quadEndAngle = 270;

            break;
        }
        case GFX_Q4:
        {
            quadStartAngle = 271;
            quadEndAngle = 360;

            break;
        }
        default:
        {
            return GFX_FALSE;
        }
    }

    //Re-orient angles to a CCW orientation
    if (dir == GFX_CW)
    {
        angle = startAnggfxArc0;
        startAnggfxArc0 = endAnggfxArc0;
        endAnggfxArc0 = angle;
    }

    //if arc wraps around 0/360, do triple arc test
    if (startAnggfxArc0 > endAnggfxArc0)
    {
        //split between (start -> 360) and (0 -> end)
        startTestAngle = startAnggfxArc0;
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
            retval = GFX_TRUE;
        }
        else if (baseAngle == 1 && (quadEndAngle >= startTestAngle))
        {
            retval = GFX_TRUE;
        }
        else
        {
            //split between (start -> 360) and (0 -> end)
            startTestAngle = 0;
            endTestAngle = endAnggfxArc0;

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
                retval = GFX_TRUE;
            }
            else if (baseAngle == 1 && (quadEndAngle >= startTestAngle))
            {
                retval = GFX_TRUE;
            }
        }
    }
    else if (startAnggfxArc0 < endAnggfxArc0)
    {
        if (startAnggfxArc0 <= quadStartAngle)
        {
            baseAngle = 0;
        }
        else
        {
            baseAngle = 1;
        }

        if (baseAngle == 0 && (endAnggfxArc0 >= quadStartAngle))
        {
            retval = GFX_TRUE;
        }
        else if (baseAngle == 1 && (quadEndAngle >= startAnggfxArc0))
        {
            retval = GFX_TRUE;
        }
    }
    else //circle
    {
        retval = GFX_TRUE;
    }

    return retval;
}

void gfxSortPointsX(gfxPoint* p1, gfxPoint* p2)
{
    gfxPoint tpt;

    if(p1->x > p2->x)
    {
        tpt = *p1;
        *p2 = *p1;
        *p1 = tpt;
    }
}

void gfxSortPointsY(gfxPoint* p1, gfxPoint* p2)
{
    gfxPoint tpt;

    if(p1->y > p2->y)
    {
        tpt = *p1;
        *p2 = *p1;
        *p1 = tpt;
    }
}

int32_t gfxGetXGivenYOnLine(gfxPoint p1, gfxPoint p2, int32_t y)
{
    if (p1.y == p2.y)
        return p1.x;

    return (p1.x - ((p1.x - p2.x) * (p1.y - y))/(p1.y - p2.y));
}

int32_t gfxGetYGivenXOnLine(gfxPoint p1, gfxPoint p2, int32_t x)
{
    if (p1.x == p2.x)
        return p1.y;

    return (p1.y - ((p1.y - p2.y) * (p1.x - x))/(p1.x - p2.x));
}

gfxPoint gfxRotatePoint(gfxPoint pos,
                      gfxPoint org,
                      int32_t ang)
{
    gfxPoint res = gfxPoint_Zero;

    pos.x -= org.x;
    pos.y -= org.y;

    int32_t sinVal = gfxSin(-ang);
    int32_t cosVal = gfxCos(-ang);

    res.x = ((pos.x * cosVal) / TRIG_SCALAR) - ((pos.y * sinVal) / TRIG_SCALAR);
    res.y = ((pos.x * sinVal) / TRIG_SCALAR) + ((pos.y * cosVal) / TRIG_SCALAR);

    res.x += org.x;
    res.y += org.y;

    return res;
}

gfxRect gfxRotatedRectBounds(gfxRect rect,
                           gfxPoint org,
                           int32_t ang)
{
    gfxPoint point[4];
    gfxRect res;
    int32_t minX = 99999;
    int32_t maxX = -99999;
    int32_t minY = 99999;
    int32_t maxY = -99999;

    uint32_t i;

    point[0].x = 0;
    point[0].y = 0;

    point[1].x = rect.width;
    point[1].y = 0;

    point[2].x = 0;
    point[2].y = rect.height;

    point[3].x = point[1].x;
    point[3].y = point[2].y;

    point[0] = gfxRotatePoint(point[0], org, ang);
    point[1] = gfxRotatePoint(point[1], org, ang);
    point[2] = gfxRotatePoint(point[2], org, ang);
    point[3] = gfxRotatePoint(point[3], org, ang);

    for(i = 0; i < 4; i++)
    {
        if(point[i].x < minX)
        {
            minX = point[i].x;
        }

        if(point[i].x > maxX)
        {
            maxX = point[i].x;
        }

        if(point[i].y < minY)
        {
            minY = point[i].y;
        }

        if(point[i].y > maxY)
        {
            maxY = point[i].y;
        }
    }

    res.x = rect.x + minX;
    res.y = rect.y + minY;
    res.width = maxX - minX;
    res.height = maxY - minY;

    return res;
}

gfxBool gfxRectContainsPoint(const gfxRect* rect, const gfxPoint* point)
{
    if(point->x < rect->x || point->x >= rect->x + rect->width ||
       point->y < rect->y || point->y >= rect->y + rect->height)
        return GFX_FALSE;

    return GFX_TRUE;
}

gfxBool gfxRectContainsRect(const gfxRect* l_rect, const gfxRect* r_rect)
{
    if (l_rect->x <= r_rect->x &&
        r_rect->x  + r_rect->width - 1 <= l_rect->x + l_rect->width - 1 &&
        l_rect->y <= r_rect->y &&
        r_rect->y  + r_rect->height - 1 <= l_rect->y + l_rect->height - 1)
        return GFX_TRUE;

    return GFX_FALSE;
}

gfxBool gfxRectIntersects(const gfxRect* l_rect, const gfxRect* r_rect)
{
    if (l_rect->x <= r_rect->x + r_rect->width - 1 &&
        r_rect->x <= l_rect->x + l_rect->width - 1 &&
        l_rect->y <= r_rect->y + r_rect->height - 1)
        return r_rect->y <= l_rect->y + l_rect->height - 1;

    return GFX_FALSE;
}

gfxRect gfxRectCombine(const gfxRect* l_rect,
                     const gfxRect* r_rect)
{
    gfxRect rect;

    rect.x = gfxMini(l_rect->x, r_rect->x);
    rect.y = gfxMini(l_rect->y, r_rect->y);

    rect.width = gfxMaxi(l_rect->x + l_rect->width, r_rect->x + r_rect->width) - rect.x;
    rect.height = gfxMaxi(l_rect->y + l_rect->height, r_rect->y + r_rect->height) - rect.y;

    return rect;
}

gfxRect gfxRectClipAdj(const gfxRect* l_rect,
                         const gfxRect* r_rect,
                         gfxRect* adj)
{
    gfxRect res;

    res = *l_rect;

    if(res.x < r_rect->x)
    {
        adj->x += r_rect->x - res.x;
        adj->width -= r_rect->x - res.x;

        res.x = r_rect->x;
        res.width -= res.x - l_rect->x;
    }
    else
        res.x = l_rect->x;

    if(res.x + res.width > r_rect->x + r_rect->width)
    {
        adj->width -= res.width - (r_rect->x + r_rect->width - res.x);

        res.width = r_rect->x + r_rect->width - res.x;
    }

    if(res.y < r_rect->y)
    {
        adj->y += r_rect->y - res.y;
        adj->height -= r_rect->y - res.y;

        res.y = r_rect->y;
        res.height -= res.y - l_rect->y;
    }
    else
        res.y = l_rect->y;

    if(res.y + res.height > r_rect->y + r_rect->height)
    {
        adj->height -= res.height - (r_rect->y + r_rect->height - res.y);

        res.height = r_rect->y + r_rect->height - res.y;
    }

    return res;
}

void gfxRectClip(const gfxRect* l_rect,
                  const gfxRect* r_rect,
                  gfxRect* result)
{
    gfxRect res;

    res = *l_rect;

    if(res.x < r_rect->x)
    {
        res.x = r_rect->x;
        res.width -= res.x - l_rect->x;
    }

    if(res.x + res.width - 1 > r_rect->x + r_rect->width - 1)
        res.width = r_rect->x + r_rect->width - res.x;

    if(res.y < r_rect->y)
    {
        res.y = r_rect->y;
        res.height -= res.y - l_rect->y;
    }

    if(res.y + res.height > r_rect->y + r_rect->height)
        res.height = r_rect->y + r_rect->height - res.y;

    *result = res;
}

gfxRect gfxRectFromPoints(const gfxPoint* p1,
                            const gfxPoint* p2)
{
    gfxRect res;
    int32_t minx, miny, maxx, maxy;

    if(p1->x < p2->x)
    {
        minx = p1->x;
        maxx = p2->x;
    }
    else
    {
        minx = p2->x;
        maxx = p1->x;
    }

    if(p1->y < p2->y)
    {
        miny = p1->y;
        maxy = p2->y;
    }
    else
    {
        miny = p2->y;
        maxy = p1->y;
    }

    res.x = minx;
    res.y = miny;

    res.width = maxx - minx + 1;
    res.height = maxy - miny + 1;

    return res;
}

void gfxRectToPoints(const gfxRect* rect,
                      gfxPoint* p1,
                      gfxPoint* p2)
{
    p1->x = rect->x;
    p1->y = rect->y;
    p2->x = rect->x + rect->width - 1;
    p2->y = rect->y + rect->height - 1;
}

uint32_t gfxRectSplit(const gfxRect* sub,
                       const gfxRect* obj,
                       gfxRect res[4])
{
    gfxRect rem = *sub;
    uint32_t count = 0;

    // rectangles actually have to intersect
    if(gfxRectIntersects(sub, obj) == GFX_FALSE)
        return 0;

    // left subrect
    if(rem.x < obj->x)
    {
        res[count].x = rem.x;
        res[count].y = rem.y;
        res[count].width = obj->x - rem.x;
        res[count].height = rem.height;

        rem.x += res[count].width;
        rem.width -= res[count].width;

        count++;
    }

    // right subrect
    if(rem.x + rem.width > obj->x + obj->width)
    {
        res[count].x = (rem.x + rem.width) - ((rem.x + rem.width) - (obj->x + obj->width));
        res[count].y = rem.y;
        res[count].width = rem.x + rem.width - res[count].x;
        res[count].height = rem.height;

        rem.width -= res[count].width;

        count++;
    }

    // top subrect
    if(rem.y < obj->y)
    {
        res[count].x = rem.x;
        res[count].y = rem.y;
        res[count].width = rem.width;
        res[count].height = obj->y - rem.y;

        rem.y += res[count].height;
        rem.height -= res[count].height;

        count++;
    }

    // bottom subrect
    if(rem.y + rem.height > obj->y + obj->height)
    {
        res[count].x = rem.x;
        res[count].y = (rem.y + rem.height) - ((rem.y + rem.height) - (obj->y + obj->height));
        res[count].width = rem.width;
        res[count].height = rem.y + rem.height - res[count].y;

        rem.height -= res[count].height;

        count++;
    }

    return count;
}

int32_t gfxRectCompare(const gfxRect* l, const gfxRect* r)
{
    return l->x == r->x && l->y == r->y &&
           l->width == r->width && l->height == r->height;
}

gfxBool gfxRectsAreSimilar(const gfxRect* l,
                             const gfxRect* r)
{
    //gfxRect combinedRect;
    //uint32_t lArea, rArea, cArea;

    // check for horizontal adjacency
    if(l->y == r->y &&
       l->height == r->height &&
       (l->x + l->width + 1 == r->x ||
        r->x + r->width + 1 == l->x))
        return GFX_TRUE;

    // check for vertical adjacency
    if(l->x == r->x &&
       l->width == r->width &&
       (l->y + l->height + 1 == r->y ||
        r->y + r->height + 1 == l->y))
        return GFX_TRUE;

    return GFX_FALSE;

    // check rectangle areas
    /*lArea = l->width * l->height;
    rArea = r->width * r->height;

    combinedRect = gfxRectCombine(l, r);

    cArea = combinedRect.width * combinedRect.height;

    // if combined area is less than the cumulative area
    // of the two rectangles then these rectangles are
    // similar
    if(cArea >= lArea + rArea)
        return GFX_FALSE;

    return GFX_TRUE;*/
}

static gfxColor gfxIndexGet1bpp(const gfxPixelBuffer* const buffer,
                            const uint32_t idx)
{
    uint32_t offs;
    uint8_t byte;
    gfxColor color;
    
    offs = (idx % 8);
            
    byte = *(((uint8_t*)buffer->pixels) + (idx >> 3));
    
    color = byte & (0x80 >> offs);
    
    color >>= 7 - offs;
    
    return color;
}

static gfxColor gfxIndexGet4bpp(const gfxPixelBuffer* const buffer,
                              const uint32_t idx)
{
    uint32_t offs;
    uint8_t byte;
    gfxColor color;
    
    byte = *(((uint8_t*)buffer->pixels) + (idx >> 1));
    
    if(idx % 2 > 0)
    {
        offs = 0xF;
        color = byte & offs;
    }
    else
    {
        offs = 0xF0;
        color = (byte & offs) >> 0x4;
    }
    
    return color;
}

static gfxColor gfxIndexGet(const gfxPixelBuffer* const buffer,
                          const uint32_t idx)
{
    uint8_t* buf_ptr;
    gfxColor color = 0;
    uint32_t i;

    buf_ptr = ((uint8_t*)buffer->pixels) + (gfxColorInfoTable[buffer->mode].bpp >> 3) * idx;
    
    for(i = 0; i < gfxColorInfoTable[buffer->mode].bpp >> 3; i++)
        ((uint8_t*)&color)[i] = buf_ptr[i];
    
    return color;
}
                               
typedef gfxColor (*PixelBufferIndexGet_FnPtr)(const gfxPixelBuffer* const,
                                               const uint32_t);
                                               
PixelBufferIndexGet_FnPtr gfxIndexGet_FnTable[] =
{
    &gfxIndexGet1bpp,
    &gfxIndexGet4bpp,
    &gfxIndexGet,
    &gfxIndexGet,
    &gfxIndexGet,
    &gfxIndexGet
};

typedef gfxColor (*GetPixel_FnPtr)(uint8_t*);

static gfxColor gfxGet1byte(uint8_t* ptr)
{
    gfxColor clr = ptr[0];

    return clr;
}

static gfxColor gfxGet2byte(uint8_t* ptr)
{
    gfxColor clr = ((uint16_t*)ptr)[0];

    return clr;
}

static gfxColor gfxGet3byte(uint8_t* ptr)
{
    gfxColor clr;
    
    clr = ptr[0];
    clr |= ptr[1] << 8;
    clr |= ptr[2] << 16;
    
    return clr;
}

static gfxColor gfxGet4byte(uint8_t* ptr)
{
    gfxColor clr = ((uint32_t*)ptr)[0];
    
    return clr;
}

GetPixel_FnPtr gfxPixelGet_FnTable[] =
{
    &gfxGet1byte,
    &gfxGet2byte,
    &gfxGet3byte,
    &gfxGet4byte
};

typedef gfxResult (*SetPixel_FnPtr)(uint8_t*, gfxColor);

static gfxResult gfxSet1byte(uint8_t* ptr, gfxColor clr)
{
    ptr[0] = (uint8_t)clr;
    
    return GFX_SUCCESS;
}

static gfxResult gfxSet2byte(uint8_t* ptr, gfxColor clr)
{
    *((uint16_t*)ptr) = (uint16_t)clr;
    
    return GFX_SUCCESS;
}

static gfxResult gfxSet3byte(uint8_t* ptr, gfxColor clr)
{
    ptr[0] = (uint8_t)(clr & 0xFF);
    ptr[1] = (uint8_t)((clr & 0xFF00) >> 8);
    ptr[2] = (uint8_t)((clr & 0xFF0000) >> 16);
    
    return GFX_SUCCESS;
}

static gfxResult gfxSet4byte(uint8_t* ptr, gfxColor clr)
{
    *((uint32_t*)ptr) = clr;
    
    return GFX_SUCCESS;
}

SetPixel_FnPtr gfxPixelSet_FnTable[] =
{
    &gfxSet1byte,
    &gfxSet2byte,
    &gfxSet3byte,
    &gfxSet4byte
};

gfxResult gfxPixelBufferCreate(const int32_t width,
                             const int32_t height,
                             const gfxColorMode mode,
                             const void* const address,
                             gfxPixelBuffer* buffer)
{
    if(buffer == NULL)
        return GFX_FAILURE;

    buffer->size.width = width;
    buffer->size.height = height;
    buffer->pixel_count = width * height;
    buffer->flags = GFX_BF_NONE;

    buffer->mode = mode;

    switch(mode)
    {
        case GFX_COLOR_MODE_INDEX_1:
        {
            buffer->buffer_length = (width * height) / 8;
            
            if((width * height) % 8 > 0)
                buffer->buffer_length += 1;
                        
            break;
        }
        case GFX_COLOR_MODE_INDEX_4:
        {
            buffer->buffer_length = (width * height) / 2;
            
            if((width * height) % 2 > 0)
                buffer->buffer_length += 1;
        
            break;
        }
        case GFX_COLOR_MODE_INDEX_8:
        {
            buffer->buffer_length = (width * height);
        
            break;
        }
        default:
        {
            buffer->buffer_length = width * height * ((gfxColorInfoTable[buffer->mode].bpp >> 3));
        }
    }

    buffer->pixels = (void*)address;

    return GFX_SUCCESS;
}

gfxBuffer gfxPixelBufferOffsetGet(const gfxPixelBuffer* const buffer,
                                uint32_t x,
                                uint32_t y)
{
    uint8_t* buf_ptr;

    if(buffer == NULL)
        return NULL;

    buf_ptr = (uint8_t*)buffer->pixels;
    
    if(x * y >= buffer->pixel_count)
        return NULL;
    
    return buf_ptr +
            gfxColorInfoTable[buffer->mode].size *
            (x + (y * buffer->size.width));
}

gfxBuffer gfxPixelBufferOffsetGet_Unsafe(const gfxPixelBuffer* const buffer,
                                       uint32_t x,
                                       uint32_t y)
{
    uint8_t* buf_ptr;

    buf_ptr = (uint8_t*)buffer->pixels;
    
    return buf_ptr +
           gfxColorInfoTable[buffer->mode].size *
           (x + (y * buffer->size.width));
}

gfxColor gfxPixelBufferGet(const gfxPixelBuffer* const buffer,
                         uint32_t x,
                         uint32_t y)
{
    if(buffer == NULL || x * y >= buffer->pixel_count)
        return 0x0;
        
    return gfxPixelBufferGet_Unsafe(buffer, x, y);
}

gfxColor gfxPixelBufferGet_Unsafe(const gfxPixelBuffer* const buffer,
                                uint32_t x,
                                uint32_t y)
{
    uint8_t* offs_ptr;
    gfxColor color = 0;
    
    offs_ptr = (uint8_t*)gfxPixelBufferOffsetGet(buffer, x, y);
    
    color = gfxPixelGet_FnTable[gfxColorInfoTable[buffer->mode].size - 1](offs_ptr);
            
    return color;
}

gfxResult gfxPixelBufferClipRect(const gfxPixelBuffer* const buffer,
                               const gfxRect* const rect,
                               gfxRect* result)
{
    gfxRect buffer_rect;

    if(buffer == NULL || rect == NULL || result == NULL)
        return GFX_FAILURE;

    buffer_rect.x = 0;
    buffer_rect.y = 0;
    buffer_rect.width = buffer->size.width;
    buffer_rect.height = buffer->size.height;

    // can't clip if rectangles do not overlap in any way
    if(gfxRectIntersects(&buffer_rect, rect) == GFX_FALSE)
        return GFX_FAILURE;

    // clip the rectangles
    gfxRectClip(&buffer_rect, rect, result);

    return GFX_SUCCESS;
}

gfxColor gfxPixelBufferGetIndex(const gfxPixelBuffer* const buffer,
                              const uint32_t idx)
{
    if(idx >= buffer->pixel_count)
        return 0;
        
    return gfxIndexGet_FnTable[gfxColorInfoTable[buffer->mode].bppOrdinal](buffer, idx);
}

gfxColor gfxPixelBufferGetIndex_Unsafe(const gfxPixelBuffer* const buffer,
                                     const uint32_t idx)
{       
    return gfxIndexGet_FnTable[gfxColorInfoTable[buffer->mode].bppOrdinal](buffer, idx);
}

gfxResult gfxPixelBufferSet(const gfxPixelBuffer* const buffer,
                          uint32_t x,
                          uint32_t y,
                          gfxColor color)
{
    // cull the pixel if it falls outside the draw area
    if(x * y >= buffer->pixel_count)
        return GFX_FAILURE;
        
    // set the buffer pixel value
    gfxPixelBufferSet_Unsafe(buffer, x, y, color);

    return GFX_SUCCESS;
}

gfxResult gfxPixelBufferSet_Unsafe(const gfxPixelBuffer* const buffer,
                                 uint32_t x,
                                 uint32_t y,
                                 gfxColor color)
{
    uint8_t* dest_ptr;
    
    //GFX_ASSERT(x * y < buffer->pixel_count);

    // get address of dest pixel
    dest_ptr = (uint8_t*)gfxPixelBufferOffsetGet_Unsafe(buffer, x, y);
    
    gfxPixelSet_FnTable[(gfxColorInfoTable[buffer->mode].bpp >> 3) - 1](dest_ptr, color);

    return GFX_SUCCESS;
}

gfxResult gfxPixelBufferAreaFill(const gfxPixelBuffer* const buffer,
                               uint32_t x,
                               uint32_t y,
                               uint32_t w,
                               uint32_t h,
                               gfxColor color)
{
    gfxRect rect, clip_rect;

    rect.x = x;
    rect.y = y;
    rect.width = w;
    rect.height = h;

    if(buffer == NULL)
        return GFX_FAILURE;

    if(gfxPixelBufferClipRect(buffer,
                             &rect,
                             &clip_rect) == GFX_FAILURE)
        return GFX_FAILURE;

    // fill the buffer
    return gfxPixelBufferAreaFill_Unsafe(buffer,
                                        clip_rect.x,
                                        clip_rect.y,
                                        clip_rect.width,
                                        clip_rect.height,
                                        color);
}

gfxResult gfxPixelBufferAreaFill_Unsafe(const gfxPixelBuffer* const buffer,
                                      uint32_t x,
                                      uint32_t y,
                                      uint32_t w,
                                      uint32_t h,
                                      gfxColor color)
{
    int32_t row, row_max, col, col_max;
    uint32_t drawX;
    uint32_t rowSize;
    void *srcIdx, *destIdx;

    // calculate minimums
    row_max = h;
    col_max = w;

    rowSize = col_max * gfxColorInfoTable[buffer->mode].size;

    // fill the first row
    for(col = 0; col < col_max; col++)
    {
        drawX = x + col;

        // set dest pixel
        gfxPixelBufferSet_Unsafe(buffer, drawX, y, color);
    }

    srcIdx = gfxPixelBufferOffsetGet_Unsafe(buffer, x, y);

    // copy first row to subsequent rows
    for(row = 1; row < row_max; row++)
    {
        destIdx = gfxPixelBufferOffsetGet_Unsafe(buffer, x, y + row);
        //idx = gfxPixelBufferOffsetGet_Unsafe(buffer, x, y + row);

        //idx = (uint8_t*)(((uint32_t)buffer->pixels) + ((y + row) * rowSize));

        memcpy(destIdx, srcIdx, rowSize);
    }

    return GFX_SUCCESS;
}

gfxBool gfxPixelBuffer_IsLocked(const gfxPixelBuffer* const buffer)
{
    if(buffer == NULL)
        return GFX_FALSE;

    return (buffer->flags & GFX_BF_LOCKED) > 0;
}

gfxResult gfxPixelBuffer_SetLocked(gfxPixelBuffer* buffer,
                                 gfxBool locked)
{
    if(buffer == NULL)
        return GFX_FAILURE;

    if(locked == GFX_TRUE)
    {
        buffer->flags |= GFX_BF_LOCKED;
    }
    else
    {
        buffer->flags &= ~(GFX_BF_LOCKED);
    }

    return GFX_SUCCESS;
}

gfxColor gfxColorConvert(gfxColorMode mode_in,
                           gfxColorMode mode_out,
                           gfxColor color)
{
    return gfx_color_convert_table[mode_in][mode_out](color);
}
