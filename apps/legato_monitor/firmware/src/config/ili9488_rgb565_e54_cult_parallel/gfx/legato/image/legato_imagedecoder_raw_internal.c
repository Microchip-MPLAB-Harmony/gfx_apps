// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END


#include "gfx/legato/asset/legato_palette.h"
#include "gfx/legato/common/legato_pixelbuffer.h"
#include "gfx/legato/image/legato_image.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/renderer/legato_renderer.h"

extern leRenderState _rendererState;

enum DecoderMode
{
    MODE_NONE,
    MODE_DRAW,
    MODE_COPY,
    MODE_COPY_TO_ADDRESS,
    MODE_DECOMPRESS,
    MODE_DECOMPRESS_TO_ADDRESS
};

static struct
{
    const leImage* img;
    leImage* newImg;
    
    void* tempBuffer;
    
    enum DecoderMode mode;
    
    leRect sourceRect;
    
    int32_t renderX;
    int32_t renderY;
    
    int32_t sourceX;
    int32_t sourceY;
        
    int32_t drawX;
    int32_t drawY;
        
    leColor sourceColor;
    
    uint32_t globalAlpha;

    const lePixelBuffer* palette;
} decodeState;

#define MAX_PIPELINE_STAGES 6

typedef void (*ImageDecodeFn)(uint32_t stage);

static ImageDecodeFn decodePipeline[MAX_PIPELINE_STAGES];
static uint32_t finishStage;

static struct leImageDecoder rawImgDecoder;
    
static void initIndexed(uint32_t stage)
{
    lePixelBuffer paletteBuffer;
    
    lePixelBufferCreate(decodeState.img->palette->colorCount,
                        1,
                        decodeState.img->palette->colorMode,
                        decodeState.img->palette->header.dataAddress,
                        &paletteBuffer); 
    
    decodePipeline[stage + 1](stage + 1);
}

static void decode(uint32_t stage)
{
    int32_t row;
    int32_t col;
    
    for(row = 0; row < decodeState.sourceRect.height; row++)
    {
        decodeState.drawY = decodeState.renderY + row;
        decodeState.sourceY = decodeState.sourceRect.y + row;
    
        for(col = 0; col < decodeState.sourceRect.width; col++)
        {
            // calculate dest offset
            decodeState.drawX = decodeState.renderX + col;
            decodeState.sourceX = decodeState.sourceRect.x + col;
            
            decodePipeline[stage + 1](stage + 1);
        }
    }
    
    if(decodePipeline[finishStage] != NULL)
    {
        decodePipeline[finishStage](finishStage);
    }
}

static void getColor(uint32_t stage)
{
    // get a pixel from the sourced image
    leColor srcColor = lePixelBufferGet(&decodeState.img->buffer,
                                        decodeState.sourceX,
                                        decodeState.sourceY);
    
    // convert the pixel to the destination format if necessary
    decodeState.sourceColor = leRenderer_ConvertColor(srcColor,
                                                      decodeState.img->buffer.mode);
                                                  
    decodePipeline[stage + 1](stage + 1);
}

static void lookup8bppColor(uint32_t stage)
{
    // get the palette index from the source image
    leColor srcColor = lePixelBufferGetIndex_Unsafe(&decodeState.img->buffer,
                                                    decodeState.sourceX + 
                                                   (decodeState.img->buffer.size.width * decodeState.sourceY));
    
    // look up the actual color from the palette
    srcColor = lePalette_Get8bppColor(decodeState.img->palette, srcColor);
    
    // convert the pixel to the destination format if necessary
    decodeState.sourceColor = leRenderer_ConvertColor(srcColor,
                                                      decodeState.img->buffer.mode);
                                                  
    decodePipeline[stage + 1](stage + 1);
}

static void lookup16bppColor(uint32_t stage)
{
    // get the palette index from the source image
    leColor srcColor = lePixelBufferGetIndex_Unsafe(&decodeState.img->buffer,
                                                    decodeState.sourceX + 
                                                   (decodeState.img->buffer.size.width * decodeState.sourceY));
    
    // look up the actual color from the palette
    srcColor = lePalette_Get16bppColor(decodeState.img->palette, srcColor);
    
    // convert the pixel to the destination format if necessary
    decodeState.sourceColor = leRenderer_ConvertColor(srcColor,
                                                      decodeState.img->buffer.mode);
                                                  
    decodePipeline[stage + 1](stage + 1);
}

static void lookup24bppColor(uint32_t stage)
{
    // get the palette index from the source image
    leColor srcColor = lePixelBufferGetIndex_Unsafe(&decodeState.img->buffer,
                                                    decodeState.sourceX + 
                                                   (decodeState.img->buffer.size.width * decodeState.sourceY));
    
    // look up the actual color from the palette
    srcColor = lePalette_Get24bppColor(decodeState.img->palette, srcColor);
    
    // convert the pixel to the destination format if necessary
    decodeState.sourceColor = leRenderer_ConvertColor(srcColor,
                                                      decodeState.img->buffer.mode);
                                                  
    decodePipeline[stage + 1](stage + 1);
}

static void lookup32bppColor(uint32_t stage)
{
    // get the palette index from the source image
    leColor srcColor = lePixelBufferGetIndex_Unsafe(&decodeState.img->buffer,
                                                    decodeState.sourceX + 
                                                   (decodeState.img->buffer.size.width * decodeState.sourceY));
    
    // look up the actual color from the palette
    srcColor = lePalette_Get32bppColor(decodeState.img->palette, srcColor);
    
    // convert the pixel to the destination format if necessary
    decodeState.sourceColor = leRenderer_ConvertColor(srcColor,
                                                      decodeState.img->buffer.mode);
                                                  
    decodePipeline[stage + 1](stage + 1);
}

static void rejectMaskedColor(uint32_t stage)
{
    // compare color to mask
    if(decodeState.sourceColor == decodeState.img->mask)
        return;
        
    decodePipeline[stage + 1](stage + 1);
}

static void writeRawColor(uint32_t stage)
{
    // write color
    leRenderer_PutPixel(decodeState.drawX,
                        decodeState.drawY,
                        decodeState.sourceColor);
                        
    
}

static void writeBlendedColor(uint32_t stage)
{
    // write color
    leRenderer_BlendPixel(decodeState.drawX,
                          decodeState.drawY,
                          decodeState.sourceColor,
                          decodeState.globalAlpha);
}

static leBool _supportsImage(const leImage* img)
{
    return img->format == LE_IMAGE_FORMAT_RAW &&
           img->header.dataLocation == LE_ASSET_LOCATION_ID_INTERNAL;
}

static leResult _draw(const leImage* img,
                      const leRect* srcRect,
                      int32_t x,
                      int32_t y,
                      uint32_t a)
{
    uint32_t idx;
    
    if(decodeState.mode != MODE_NONE)
        return LE_FAILURE;
    
    decodeState.mode = MODE_DRAW;
    
    decodeState.sourceRect = *srcRect;
    decodeState.img = img;
    decodeState.renderX = x;
    decodeState.renderY = y;
    decodeState.globalAlpha = a;
    
    for(idx = 0; idx < MAX_PIPELINE_STAGES; idx++)
    {
        decodePipeline[idx] = NULL;
    }
    
    idx = 0;
    
    if(img->buffer.mode >= LE_COLOR_MODE_INDEX_1 && img->buffer.mode <= LE_COLOR_MODE_INDEX_8)
    {
        decodePipeline[idx++] = initIndexed;
        decodePipeline[idx++] = decode;
        
        switch(img->palette->colorMode)
        {
            case LE_COLOR_MODE_GS_8:
            case LE_COLOR_MODE_RGB_332:
            {
                decodePipeline[idx++] = lookup8bppColor;
                    
                break;
            }
            case LE_COLOR_MODE_RGB_565:
            case LE_COLOR_MODE_RGBA_5551:
            {
                decodePipeline[idx++] = lookup16bppColor;
                
                break;
            }
            case LE_COLOR_MODE_RGB_888:
            {
                decodePipeline[idx++] = lookup24bppColor;
                    
                break;
            }
            case LE_COLOR_MODE_RGBA_8888:
            case LE_COLOR_MODE_ARGB_8888:
            {
                decodePipeline[idx++] = lookup32bppColor;
                    
                break;
            }
            default:
            {
                decodePipeline[idx++] = lookup8bppColor;
                
                break;
            }
        }
        
        if((img->flags & LE_IMAGE_USE_MASK) > 0)
        {
            decodePipeline[idx++] = rejectMaskedColor;
        }
        
        if(decodeState.globalAlpha != 255)
        {
            decodePipeline[idx++] = writeBlendedColor;
        }
        else
        {
            decodePipeline[idx++] = writeRawColor;
        }
        
        finishStage = idx;
    }
    else if(img->buffer.mode >= LE_COLOR_MODE_RGBA_5551 && img->buffer.mode <= LE_COLOR_MODE_ARGB_8888)
    {
        decodePipeline[idx++] = decode;
        decodePipeline[idx++] = getColor;
        
        if((img->flags & LE_IMAGE_USE_MASK) > 0)
        {
            decodePipeline[idx++] = rejectMaskedColor;
        }
        
        decodePipeline[idx++] = writeBlendedColor;
        
        finishStage = idx;
    }
    else
    {
        decodePipeline[idx++] = decode;
        decodePipeline[idx++] = getColor;
        
        if((img->flags & LE_IMAGE_USE_MASK) > 0)
        {
            decodePipeline[idx++] = rejectMaskedColor;
        }
        
        if(decodeState.globalAlpha != 255)
        {
            decodePipeline[idx++] = writeBlendedColor;
        }
        else
        {
            decodePipeline[idx++] = writeRawColor;
        }
        
        finishStage = idx;
    }
    
    return LE_SUCCESS;
}

static void copyStage(uint32_t stage)
{
    // copy old buffer attributes
    decodeState.newImg->buffer.pixels = decodeState.tempBuffer;
    
    // copy old data to new address
    memcpy(decodeState.newImg->buffer.pixels,
           decodeState.img->buffer.pixels,
           decodeState.img->buffer.buffer_length);
}

static leResult _copy(const leImage* img,
                      leImage* newImg)
{
    uint32_t idx = 0;
    
    if(decodeState.mode != MODE_NONE)
        return LE_FAILURE;
        
    // allocate a new buffer
    decodeState.tempBuffer = LE_MALLOC(img->buffer.buffer_length);
    
    if(decodeState.tempBuffer == NULL)
        return LE_FAILURE;
    
    decodeState.newImg = newImg;
    decodeState.mode = MODE_COPY;
 
    decodePipeline[idx++] = copyStage;
        
    return LE_SUCCESS;
}

static void copyToAddressStage(uint32_t stage)
{   
    // copy old data to new address
    memcpy(decodeState.newImg->buffer.pixels,
           decodeState.img->buffer.pixels,
           decodeState.img->buffer.buffer_length);
}

static leResult _copyToAddress(const leImage* img,
                               void* address,
                               leImage* newImg)
{
    uint32_t idx = 0;
    
    if(address == NULL)
        return LE_FAILURE;
        
    // copy old buffer attributes
    decodeState.img = img;
    decodeState.newImg = newImg;
    decodeState.newImg->buffer.pixels = address;
    
    decodeState.mode = MODE_COPY_TO_ADDRESS;
 
    decodePipeline[idx++] = copyToAddressStage;
    
    return LE_SUCCESS;
}

static leResult _decompress(const leImage* img,
                            leImage* newImg)
{
    return LE_SUCCESS;
}

static leResult _decompressToAddress(const leImage* img,
                                     void* address,
                                     leImage* newImg)
{
    return LE_SUCCESS;
}

static void _exec(void)
{
    if(decodeState.mode == MODE_NONE)
        return;
        
    decodePipeline[0](0);
}

static leBool _isDone(void)
{
    return LE_TRUE;
}

static void _free(void)
{
    if(decodeState.tempBuffer != NULL)
    {
        LE_FREE(decodeState.tempBuffer);
        
        decodeState.tempBuffer = NULL;
    }
    
    decodeState.mode = MODE_NONE;
}

leImageDecoder* _leRawImageDecoder_Init(void)
{
    memset(&decodeState, 0, sizeof(decodeState));

    rawImgDecoder.supportsImage = _supportsImage;
    rawImgDecoder.draw = _draw;
    rawImgDecoder.copy = _copy;
    rawImgDecoder.copyToAddress = _copyToAddress;
    rawImgDecoder.decompress = _decompress;
    rawImgDecoder.decompressToAddress = _decompressToAddress;
    rawImgDecoder.exec = _exec;
    rawImgDecoder.isDone = _isDone;
    rawImgDecoder.free = _free;
    
    return &rawImgDecoder;
}

#if 0

static leResult drawIndexImage(leImage* img,
                               leRect* srcRect,
                               int32_t x,
                               int32_t y)
{
#if 0
    //leColorMode colorMode;
    lePixelBuffer pixBuffer, paletteBuffer;
    
    lePixelBufferCreate(img->bufferWidth,
                        img->bufferHeight,
                        img->colorMode,
                        img->header.dataAddress,
                        &pixBuffer);
                          
    lePixelBufferCreate(img->palette->colorCount,
                        1,
                        img->palette->colorMode,
                        img->palette->header.dataAddress,
                        &paletteBuffer);                     
    
    leGetRenderState()->palette = &paletteBuffer;
        
    if((img->flags & LE_IMAGE_USE_MASK) > 0)
    {
        leGetRenderState()->maskEnable = LE_TRUE;
        leGetRenderState()->maskValue = img->mask;
    }
    else
    {
        leGetRenderState()->maskEnable = LE_FALSE;
    }
    #endif
    //return GFX_DrawBlit(&pixBuffer, src_x, src_y, src_width, src_height, dest_x, dest_y);
    
    return LE_FAILURE;
}

static leResult drawColorImage(leImage* img,
                               leRect* srcRect,
                               int32_t x,
                               int32_t y)
{
    int32_t row, col;
    int32_t drawX, drawY;
    leColor srcColor, resColor;
    uint32_t srcX, srcY;
    
    for(row = 0; row < srcRect->height; row++)
    {
        drawY = y + row;
        srcY = srcRect->y + row;
    
        for(col = 0; col < srcRect->width; col++)
        {
            // calculate dest offset
            drawX = x + col;
        
            srcX = srcRect->x + col;
            
            srcColor = lePixelBufferGet(&img->buffer, srcX, srcY);
            
            // look up source color from buffer or palette
            resColor = leRenderer_ConvertColor(srcColor, img->buffer.mode);
            
            // write color
            leRenderer_PutPixel(drawX, drawY, resColor);
        }
    }        
    
    return LE_SUCCESS;                          
}

static leResult drawMaskedColorImage(leImage* img,
                                     leRect* srcRect,
                                     int32_t x,
                                     int32_t y)
{
    int32_t row, col;
    int32_t drawX, drawY;
    leColor srcColor, resColor;
    uint32_t srcX, srcY;
    
    for(row = 0; row < srcRect->height; row++)
    {
        drawY = y + row;
        srcY = srcRect->y + row;
    
        for(col = 0; col < srcRect->width; col++)
        {
            // calculate dest offset
            drawX = x + col;
        
            srcX = srcRect->x + col;
            
            srcColor = lePixelBufferGet(&img->buffer, srcX, srcY);
            
            if(srcColor == img->mask)
                continue;
            
            // look up source color from buffer or palette
            resColor = leRenderer_ConvertColor(srcColor, img->buffer.mode);
            
            // write color
            leRenderer_PutPixel(drawX, drawY, resColor);
        }
    }        
    
    return LE_SUCCESS;                          
}

leResult leDrawImageRawInternal(leImage* img,
                                leRect* sourceRect,
                                int32_t x,
                                int32_t y)
{
    switch(img->buffer.mode)
    {
        case LE_COLOR_MODE_INDEX_1:
        case LE_COLOR_MODE_INDEX_4:
        case LE_COLOR_MODE_INDEX_8:
        {
            return drawIndexImage(img,
                                  sourceRect,
                                  x,
                                  y);
        }
        case LE_COLOR_MODE_RGBA_5551:
        case LE_COLOR_MODE_RGBA_8888:
        case LE_COLOR_MODE_ARGB_8888:
        {
            //Process alpha channel for these RAW formats
            //GFX_BlendMode blendMode;
            //GFX_Get(GFXF_DRAW_BLEND_MODE, &blendMode);
            //GFX_Set(GFXF_DRAW_BLEND_MODE, blendMode | GFX_BLEND_CHANNEL);
            //No break, fall through
        }
        case LE_COLOR_MODE_GS_8:
        case LE_COLOR_MODE_RGB_332:
        case LE_COLOR_MODE_RGB_565:
        case LE_COLOR_MODE_RGB_888:            
        {
            if((img->flags & LE_IMAGE_USE_MASK) > 0)
            {
                return drawMaskedColorImage(img,
                                            sourceRect,
                                            x,
                                            y);
            }
            else
            {
                return drawColorImage(img,
                                      sourceRect,
                                      x,
                                      y);
            }
        }
    };

    return LE_FAILURE;
}
#endif