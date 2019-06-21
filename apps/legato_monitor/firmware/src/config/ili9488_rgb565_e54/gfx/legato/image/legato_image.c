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

#include "gfx/legato/image/legato_image.h"

#include "gfx/legato/common/legato_rect.h"
#include "gfx/legato/renderer/legato_renderer.h"

#define MAX_IMAGE_DECODER_COUNT 10

static leImageDecoder* decoders[MAX_IMAGE_DECODER_COUNT];

leImageDecoder* _leRawImageDecoder_Init(void);
leImageDecoder* _leRLEImageDecoder_Init(void);

void leImage_InitDecoders()
{
    uint32_t decIdx = 0;
    
    decoders[decIdx++] = _leRawImageDecoder_Init();
    decoders[decIdx++] = _leRLEImageDecoder_Init();
}

leResult leImage_Draw(const leImage* img,
                      leRect* sourceRect,
                      int32_t x,
                      int32_t y,
                      uint32_t a)
{
    leRect imgRect, sourceClipRect, drawRect, clipRect;
    leRect dmgRect = leRenderer_GetDrawRect();
    uint32_t decIdx;
    
    if(img == NULL)
        return LE_FAILURE;

    imgRect.x = 0;
    imgRect.y = 0;
    imgRect.width = img->buffer.size.width;
    imgRect.height = img->buffer.size.height;
    
    /* make sure the source rect is within the source bounds */
    if(leRectIntersects(&imgRect, sourceRect) == LE_FALSE)
        return LE_FAILURE;
        
    leRectClip(&imgRect, sourceRect, &sourceClipRect);
    
    drawRect.x = x;
    drawRect.y = y;
    drawRect.width = sourceClipRect.width;
    drawRect.height = sourceClipRect.height;
    
    /* make sure the dest rect is within the damaged rect area */   
    clipRect = leRectClipAdj(&drawRect, &dmgRect, &sourceClipRect);
    
    if(sourceClipRect.width < 0 || sourceClipRect.height < 0)
        return LE_FAILURE;
        
    for(decIdx = 0; decIdx < MAX_IMAGE_DECODER_COUNT; decIdx++)
    {
        if(decoders[decIdx] != NULL && decoders[decIdx]->supportsImage(img) == LE_TRUE)
        {
            decoders[decIdx]->draw(img,
                                   &sourceClipRect,
                                   clipRect.x,
                                   clipRect.y,
                                   a);
                                   
            decoders[decIdx]->exec();
            decoders[decIdx]->free();
        }
    }

    #if 0

    if(img->header.dataLocation == LE_ASSET_LOCATION_INTERNAL)
    {
        if(img->format == LE_IMAGE_FORMAT_RAW)
        {
            if(img->compType == LE_IMAGE_COMPRESSION_NONE)
            {
#if LE_EXTERNAL_STREAMING_ENABLED == 1
                if(img->header.dataLocation == LE_ASSET_LOCATION_INTERNAL)
                {
#endif
                    return leDrawImageRawInternal(img,
                                                  &sourceClipRect,
                                                  clipRect.x,
                                                  clipRect.y);
#if LE_EXTERNAL_STREAMING_ENABLED == 1
                }
                else
                {
                    return leDrawImageRawExternal(img,
                                                  source_clip_rect.x,
                                                  source_clip_rect.y,
                                                  source_clip_rect.width,
                                                  source_clip_rect.height,
                                                  dest_x,
                                                  dest_y);
                }
#endif
            }
            else if(img->compType == LE_IMAGE_COMPRESSION_RLE)
            {
#if LE_EXTERNAL_STREAMING_ENABLED == 1
                if(img->header.dataLocation == LE_ASSET_LOCATION_INTERNAL)
                {
#endif
                    return leDrawImageRLEInternal(img,
                                                  sourceRect,
                                                  x,
                                                  y);
#if LE_EXTERNAL_STREAMING_ENABLED == 1
                }
                else
                {
                    return leDrawImageRLEExternal(img,
                                                  sourceRect,
                                                  x,
                                                  y);
                }
#endif
            }
        }
#if GFX_UTIL_PNG_DECODER_ENABLED
		else if (img->format == LE_IMAGE_FORMAT_PNG)
        {
            return leDrawImagePngInternal(img,
                                          sourceRect,
                                          dest_x,
                                          dest_y);        
        }
#endif //GFX_UTIL_PNG_DECODER_ENABLED
#if GFX_UTIL_JPEG_DECODER_ENABLED
		else if (img->format == leIMAGE_FORMAT_JPEG)
        {
            if(memIntf == NULL)
                createDefaultMemIntf(&localMemIntf);
            else
                localMemIntf = *memIntf;
            
            return leDrawImageJpgInternal(img,
                                  source_clip_rect.x,
                                  source_clip_rect.y,
                                  source_clip_rect.width,
                                  source_clip_rect.height,
                                  dest_x,
                                  dest_y,
                                  &localMemIntf);                
        }
#endif //GFX_UTIL_JPEG_DECODER_ENABLED
    }
    #if 0
	else if (reader != NULL && memIntf != NULL)
    {
        if(img->format == LE_IMAGE_FORMAT_RAW)
        {
            
        }
#if GFX_UTIL_JPEG_DECODER_ENABLED
		else if (img->format == leIMAGE_FORMAT_JPEG)
        {
            return leDrawImageJpgExternal(img,
                                  source_clip_rect.x,
                                  source_clip_rect.y,
                                  source_clip_rect.width,
                                  source_clip_rect.height,
                                  dest_x,
                                  dest_y);                
        }
#endif //GFX_UTIL_JPEG_DECODER_ENABLED
#if GFX_UTIL_PNG_DECODER_ENABLED
		else if (img->format == leIMAGE_FORMAT_PNG)
        {
            return leDrawImagePngExternal(img,
                                  source_clip_rect.x,
                                  source_clip_rect.y,
                                  source_clip_rect.width,
                                  source_clip_rect.height,
                                  dest_x,
                                  dest_y);                
        }
#endif //GFX_UTIL_PNG_DECODER_ENABLED
	}
	#endif
	#endif
    return LE_FAILURE;
}

#if 0
leResult lePreprocessImage(leImage* img,
                           uint32_t destAddress,
                           leColorMode destMode,
                           leBool padBuffer)
{
#if 0
    lePixelBuffer buf;
    uint32_t width = img->width;
    uint32_t height = img->height;
    uint32_t p;
    leRect rect;
    leBool alphaEnable;
    
    if(img->header.dataLocation != 0)
        return 0;
    
    if(padBuffer == LE_TRUE)
    {
        if(width && !(width & (width - 1)) == 0)
        {
            p = 1;
            
            while(width >= p)
                p <<= 1;
            
            width = p;
        }
        
        if(height && !(height & (height - 1)) == 0)
        {
            p = 1;
            
            while(height >= p)
                p <<= 1;
            
            height = p;
        }
    }   
    
    lePixelBufferCreate(width,
                          height,
                          destMode,
                          (void*)destAddress,
                          &buf);
    
    if((img->flags & leIMAGE_USE_MASK) > 0)
    {
        rect.x = 0;
        rect.y = 0;
        rect.width = buf.size.width;
        rect.height = buf.size.height;
        
        lePixelBufferAreaFill(&buf, &rect, leColorConvert(img->colorMode, destMode, img->mask));
    }
    else
    {
        memset(buf.pixels, 0, buf.buffer_length);
    }
    
    GFX_Get(GFXF_DRAW_ALPHA_ENABLE, &alphaEnable);
    GFX_Set(GFXF_DRAW_ALPHA_ENABLE, LE_FALSE);
    GFX_Set(GFXF_DRAW_TARGET, &buf);
    
    GFX_Begin();
    leDrawImage(img,
                   0,
                   0,
                   img->width,
                   img->height,
                   0,
                   0,
                   NULL,
                   NULL);
    GFX_End();
    
    GFX_Set(GFXF_DRAW_TARGET, NULL);
    GFX_Set(GFXF_DRAW_ALPHA_ENABLE, alphaEnable);
    
    img->header.dataAddress = (void*)destAddress;
    img->header.dataLocation = 0;
    img->header.dataSize = buf.buffer_length;
    img->bufferWidth = buf.size.width;
    img->bufferHeight = buf.size.height;
    img->format = leIMAGE_FORMAT_RAW;
    img->compType = leIMAGE_COMPRESSION_NONE;
    
    if((img->flags & leIMAGE_USE_MASK) > 0)
        img->mask = leColorConvert(img->colorMode, destMode, img->mask);
    else
        img->mask = 0;
    
    img->palette = NULL;
    img->colorMode = destMode;
    #endif
    return LE_SUCCESS;
}

#endif

leImage* leImage_Decompress(const leImage* img)
{
    if(img == NULL || img->format == LE_IMAGE_FORMAT_RAW)
        return NULL;
        
    return NULL;
}