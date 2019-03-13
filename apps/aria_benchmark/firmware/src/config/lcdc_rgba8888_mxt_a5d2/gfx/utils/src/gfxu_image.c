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

#include "gfx/utils/gfxu_config.h"
#include "gfx/utils/inc/gfxu_image.h"
#include "gfx/utils/inc/gfxu_image_utils.h"

GFX_Result GFXU_DrawImageRawInternal(GFXU_ImageAsset* img,
                                     int32_t src_x,
                                     int32_t src_y,
                                     int32_t src_width,
                                     int32_t src_height,
                                     int32_t dest_x,
                                     int32_t dest_y);
                                     
GFX_Result GFXU_DrawImageRLEInternal(GFXU_ImageAsset* img,
                                     int32_t src_x,
                                     int32_t src_y,
                                     int32_t src_width,
                                     int32_t src_height,
                                     int32_t dest_x,
                                     int32_t dest_y);
                                  
GFX_Result GFXU_DrawImageRawExternal(GFXU_ImageAsset* img,
                                     int32_t src_x,
                                     int32_t src_y,
                                     int32_t src_width,
                                     int32_t src_height,
                                     int32_t dest_x,
                                     int32_t dest_y,
                                     GFXU_MemoryIntf* memoryInterface,
                                     GFXU_ExternalAssetReader** reader);
                                     
GFX_Result GFXU_DrawImageRLEExternal(GFXU_ImageAsset* img,
                                     int32_t src_x,
                                     int32_t src_y,
                                     int32_t src_width,
                                     int32_t src_height,
                                     int32_t dest_x,
                                     int32_t dest_y,
                                     GFXU_MemoryIntf* memoryInterface,
                                     GFXU_ExternalAssetReader** reader);

#if GFX_UTIL_PNG_DECODER_ENABLED
GFX_Result GFXU_DrawImagePngInternal(GFXU_ImageAsset* img,
                                     int32_t src_x,
                                     int32_t src_y,
                                     int32_t src_width,
                                     int32_t src_height,
                                     int32_t dest_x,
                                     int32_t dest_y);
                                     
GFX_Result GFXU_DrawImagePngExternal(GFXU_ImageAsset* img,
                                     int32_t src_x,
                                     int32_t src_y,
                                     int32_t src_width,
                                     int32_t src_height,
                                     int32_t dest_x,
                                     int32_t dest_y,
                                     GFXU_MemoryIntf* memIntf);
#endif //GFX_UTIL_PNG_DECODER_ENABLED

#if GFX_UTIL_JPEG_DECODER_ENABLED
GFX_Result GFXU_DrawImageJpgInternal(GFXU_ImageAsset* img,
                                     int32_t src_x,
                                     int32_t src_y,
                                     int32_t src_width,
                                     int32_t src_height,
                                     int32_t dest_x,
                                     int32_t dest_y,
                                     GFXU_MemoryIntf* memIntf);
                                     
GFX_Result GFXU_DrawImageJpgExternal(GFXU_ImageAsset* img,
                                     int32_t src_x,
                                     int32_t src_y,
                                     int32_t src_width,
                                     int32_t src_height,
                                     int32_t dest_x,
                                     int32_t dest_y,
                                     GFXU_MemoryIntf* memIntf);
#endif //GFX_UTIL_JPEG_DECODER_ENABLED

GFX_Result GFXU_DrawImage(GFXU_ImageAsset* img,
                          int32_t src_x,
                          int32_t src_y,
                          int32_t src_width,
                          int32_t src_height,
                          int32_t dest_x,
                          int32_t dest_y,
                          GFXU_MemoryIntf* memIntf,
                          GFXU_ExternalAssetReader** reader)
{
    GFX_Rect image_rect, source_rect, source_clip_rect;
#if GFX_UTIL_JPEG_DECODER_ENABLED
    GFXU_MemoryIntf localMemIntf;
#endif //GFX_UTIL_JPEG_DECODER_ENABLED
    
    if(img == GFX_NULL)
        return GFX_FAILURE;

    image_rect.x = 0;
    image_rect.y = 0;
    image_rect.width = img->width;
    image_rect.height = img->height;
    
    source_rect.x = src_x;
    source_rect.y = src_y;
    source_rect.width = src_width;
    source_rect.height = src_height;
    
    if(GFX_RectIntersects(&image_rect, &source_rect) == GFX_FALSE)
        return GFX_FAILURE;
    
    GFX_RectClip(&image_rect, &source_rect, &source_clip_rect);

    // can't draw an external resource with no callback
    //if(img->header.dataLocation != 0 && reader == GFX_NULL)
    //    return GFX_FAILURE;
    
    if(img->header.dataLocation == GFXU_ASSET_LOCATION_INTERNAL)
    {
        if(img->format == GFXU_IMAGE_FORMAT_RAW)
        {
            if(img->compType == GFXU_IMAGE_COMPRESSION_NONE)
            {
                return GFXU_DrawImageRawInternal(img,
                                      source_clip_rect.x,
                                      source_clip_rect.y,
                                      source_clip_rect.width,
                                      source_clip_rect.height,
                                      dest_x,
                                      dest_y);
            }
            else if(img->compType == GFXU_IMAGE_COMPRESSION_RLE)
            {
                return GFXU_DrawImageRLEInternal(img,
                                      source_clip_rect.x,
                                      source_clip_rect.y,
                                      source_clip_rect.width,
                                      source_clip_rect.height,
                                      dest_x,
                                      dest_y);
            }
            
        }
#if GFX_UTIL_PNG_DECODER_ENABLED
		else if (img->format == GFXU_IMAGE_FORMAT_PNG)
        {
            return GFXU_DrawImagePngInternal(img,
                                  source_clip_rect.x,
                                  source_clip_rect.y,
                                  source_clip_rect.width,
                                  source_clip_rect.height,
                                  dest_x,
                                  dest_y);        
        }
#endif //GFX_UTIL_PNG_DECODER_ENABLED
#if GFX_UTIL_JPEG_DECODER_ENABLED
		else if (img->format == GFXU_IMAGE_FORMAT_JPEG)
        {
            if(memIntf == NULL)
                createDefaultMemIntf(&localMemIntf);
            else
                localMemIntf = *memIntf;
            
            return GFXU_DrawImageJpgInternal(img,
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
	else if (reader != GFX_NULL && memIntf != NULL)
    {
        if(img->format == GFXU_IMAGE_FORMAT_RAW)
        {
            if(img->compType == GFXU_IMAGE_COMPRESSION_NONE)
            {
                return GFXU_DrawImageRawExternal(img,
                                                 source_clip_rect.x,
                                                 source_clip_rect.y,
                                                 source_clip_rect.width,
                                                 source_clip_rect.height,
                                                 dest_x,
                                                 dest_y,
                                                 memIntf,
                                                 reader);
            }
            else if(img->compType == GFXU_IMAGE_COMPRESSION_RLE)
            {
                return GFXU_DrawImageRLEExternal(img,
                                      source_clip_rect.x,
                                      source_clip_rect.y,
                                      source_clip_rect.width,
                                      source_clip_rect.height,
                                      dest_x,
                                      dest_y,
                                      memIntf,
                                      reader);
            }
        }
#if GFX_UTIL_JPEG_DECODER_ENABLED
		else if (img->format == GFXU_IMAGE_FORMAT_JPEG)
        {
            return GFXU_DrawImageJpgExternal(img,
                                  source_clip_rect.x,
                                  source_clip_rect.y,
                                  source_clip_rect.width,
                                  source_clip_rect.height,
                                  dest_x,
                                  dest_y,
                                  memIntf);                
        }
#endif //GFX_UTIL_JPEG_DECODER_ENABLED
#if GFX_UTIL_PNG_DECODER_ENABLED
		else if (img->format == GFXU_IMAGE_FORMAT_PNG)
        {
            return GFXU_DrawImagePngExternal(img,
                                  source_clip_rect.x,
                                  source_clip_rect.y,
                                  source_clip_rect.width,
                                  source_clip_rect.height,
                                  dest_x,
                                  dest_y,
                                  memIntf);                
        }
#endif //GFX_UTIL_PNG_DECODER_ENABLED
	}
    
    return GFX_FAILURE;
}

GFX_Result GFXU_PreprocessImage(GFXU_ImageAsset* img,
                                uint32_t destAddress,
                                GFX_ColorMode destMode,
                                GFX_Bool padBuffer)
{
    GFX_PixelBuffer buf;
    uint32_t width = img->width;
    uint32_t height = img->height;
    uint32_t p;
    GFX_Rect rect;
    GFX_Bool alphaEnable;
    
    if(img->header.dataLocation != 0)
        return 0;
    
    if(padBuffer == GFX_TRUE)
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
    
    GFX_PixelBufferCreate(width,
                          height,
                          destMode,
                          (void*)destAddress,
                          &buf);
    
    if((img->flags & GFXU_IMAGE_USE_MASK) > 0)
    {
        rect.x = 0;
        rect.y = 0;
        rect.width = buf.size.width;
        rect.height = buf.size.height;
        
        GFX_PixelBufferAreaFill(&buf, &rect, GFX_ColorConvert(img->colorMode, destMode, img->mask));
    }
    else
    {
        memset(buf.pixels, 0, buf.buffer_length);
    }
    
    GFX_Get(GFXF_DRAW_ALPHA_ENABLE, &alphaEnable);
    GFX_Set(GFXF_DRAW_ALPHA_ENABLE, GFX_FALSE);
    GFX_Set(GFXF_DRAW_TARGET, &buf);
    
    GFX_Begin();
    GFXU_DrawImage(img,
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
    img->format = GFXU_IMAGE_FORMAT_RAW;
    img->compType = GFXU_IMAGE_COMPRESSION_NONE;
    
    if((img->flags & GFXU_IMAGE_USE_MASK) > 0)
        img->mask = GFX_ColorConvert(img->colorMode, destMode, img->mask);
    else
        img->mask = 0;
    
    img->palette = NULL;
    img->colorMode = destMode;
    
    return GFX_SUCCESS;
}
