/*******************************************************************************
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_image.h

  Summary:
    Defines image assets

  Description:
    Image drawing at specified coordinates
*******************************************************************************/

// DOM-IGNORE-BEGIN
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
#ifndef LE_IMAGE_H
#define LE_IMAGE_H
//DOM-IGNORE-END

#include "gfx/legato/common/legato_common.h"

#include "gfx/legato/common/legato_color.h"
#include "gfx/legato/common/legato_pixelbuffer.h"
#include "gfx/legato/core/legato_stream.h"

typedef struct lePalette lePalette;

// *****************************************************************************
/* Enumeration:
    leImageFormat

  Summary:
    Indicates the image encoding format
*/
typedef enum leImageFormat
{
    LE_IMAGE_FORMAT_RAW = 0,
    LE_IMAGE_FORMAT_RLE,
    //LE_IMAGE_FORMAT_JPEG,
    //LE_IMAGE_FORMAT_PNG
} leImageFormat;

#define LE_IMAGE_FORMAT_COUNT (LE_IMAGE_FORMAT_RLE + 1)

// *****************************************************************************
/* Enumeration:
    leImageFlags

  Summary:
    A list of flags describing an image asset
*/
typedef enum leImageFlags
{
    LE_IMAGE_USE_MASK_COLOR  = 1 << 0,
    LE_IMAGE_USE_MASK_MAP    = 1 << 1,
    LE_IMAGE_USE_ALPHA_MAP   = 1 << 2,
    LE_IMAGE_INTERNAL_ALLOC  = 1 << 3
} leImageFlags;

typedef enum leImageFilterMode
{
    LE_IMAGE_NEAREST_NEIGHBOR,
    LE_IMAGE_BILINEAR,
} leImageFilterMode;

typedef struct leImageMap
{
    leStreamDescriptor header;
    lePixelBuffer buffer;
} leImageMap;

// *****************************************************************************
/* Structure:
    leImage

  Summary:
    Describes an image asset.
    
    header - standard asset header
    format - the format of the image.  this directly affects which decoder
             is invoked when rendering the image
    width - the width of the image in pixels
    height - the height of the image in pixels
    colorMode - the color mode of the image
    compType - the compression mode of the image
    flags - indicates of the mask field is used
    mask - may contain a masking color for the image.  blit operations may 
           reference this value and reject image pixels that match this
           value.  This can either be a single color mode or a pointer to an
           image map data array.

    alphaMask - pointer to an array of per-pixel alpha blending values

    palette - will contain a valid pointer to a palette asset if thie image
              is an index map instead of a color image
*/
typedef struct leImage
{
    leStreamDescriptor header;
    leImageFormat format;
    lePixelBuffer buffer;
    leImageFlags flags;

    union
    {
        leColor color;
        leImageMap* map;
    } mask;

    leImageMap* alphaMap;

    lePalette* palette;
} leImage;

LIB_EXPORT leResult leImage_Create(leImage* img,
                                   uint32_t width,
                                   uint32_t height,
                                   leColorMode mode,
                                   void* data,
                                   uint32_t locationID);

LIB_EXPORT leImage* leImage_Allocate(uint32_t width,
                                     uint32_t height,
                                     leColorMode mode);

LIB_EXPORT leResult leImage_Free(leImage* img);

typedef struct leImageDecoder
{
    leBool   (*supportsImage)(const leImage* img);
    leResult (*draw)(const leImage* img, const leRect* srcRect, int32_t x, int32_t y, uint32_t a);
    leResult (*copy)(const leImage* src, leImage* dst, const leRect* srcRect);
    leResult (*render)(const leImage* src, leImage* dst, const leRect* srcRect, leBool applyAlpha);
    leResult (*resize)(const leImage* src, leImage* dest, const leRect* srcRect, uint32_t width, uint32_t height);
    void     (*exec)(void);
    leBool   (*isDone)(void);
    void     (*free)(void);
} leImageDecoder;

void leImage_InitDecoders();

#if LE_STREAMING_ENABLED == 1
typedef struct leImageStreamDecoder
{
    leStreamManager base;
} leImageStreamDecoder;
#endif

// *****************************************************************************
/* Function:
    leResult leDrawImage(void);

  Summary:
    Draws a portion of the given image at the specified coordinates.
     
  Parameters:
    leImage* img - pointer to the image asset to draw
    leRect* sourceRect - the source rectangle of the image to blit   
    int32_t dest_x - the x position to draw to
    int32_t dest_y - the y position to draw to
    uint32_t a - global alpha amount to apply

  Returns:
    leResult
*/
LIB_EXPORT leResult leImage_Draw(const leImage* img,
                                 leRect* sourceRect,
                                 int32_t x,
                                 int32_t y,
                                 uint32_t a);

#ifdef NOT_IMPLEMENTED
LIB_EXPORT  leResult leImage_Copy(const leImage* src,
                                  leImage* dst,
                                  leRect* sourceRect);
                                 
LIB_EXPORT leResult leImage_Render(const leImage* img,
                                   leImage* dst,
                                   leRect* sourceRect,
                                   leBool applyAlpha);

LIB_EXPORT leResult leImage_Resize(const leImage* src,
                                   leImage* dst,
                                   leRect* sourceRect,
                                   uint32_t width,
                                   uint32_t height,
                                   leImageFilterMode mode);
#endif

#endif /* LE_IMAGE_H */