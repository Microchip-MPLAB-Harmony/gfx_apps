#include "gfx/utils/inc/gfxu_image.h"
#include "gfx/utils/inc/gfxu_palette.h"
#include "gfx/utils/inc/gfxu_image_utils.h"
#include "gfx/hal/inc/gfx_context.h"

static GFX_Result drawIndexImage(GFXU_ImageAsset* img,
                                 int32_t src_x,
                                 int32_t src_y,
                                 int32_t src_width,
                                 int32_t src_height,
                                 int32_t dest_x,
                                 int32_t dest_y)
{
    GFX_PixelBuffer paletteBuffer;
    GFX_Point dest_point;
    GFX_Color color;
    uint32_t lastBlock = 0;
    uint32_t lastOffset = 0;
    GFX_ColorMode layerMode;
    GFX_BitsPerPixel bpp;
    
    uint32_t idx;

    int32_t row;
    int32_t col;
    
    dest_point.x = dest_x;
    dest_point.y = dest_y;
    
    GFX_PixelBufferCreate(img->palette->colorCount,
                          1,
                          img->palette->colorMode,
                          img->palette->header.dataAddress,
                          &paletteBuffer);
                          
    if(GFX_Set(GFXF_DRAW_PALETTE, &paletteBuffer) == GFX_FAILURE)
        return GFX_FAILURE;
    
    if(GFX_Get(GFXF_COLOR_MODE, &layerMode) == GFX_FAILURE)
        return GFX_FAILURE;
        
    // enable mask color if necessary
    GFX_Set(GFXF_DRAW_MASK_ENABLE,
           (img->flags & GFXU_IMAGE_USE_MASK) > 0);
    
    if((img->flags & GFXU_IMAGE_USE_MASK) > 0)
    {
        GFX_Set(GFXF_DRAW_MASK_ENABLE, GFX_TRUE);
        GFX_Set(GFXF_DRAW_MASK_VALUE, GFX_ColorConvert(img->palette->colorMode,
                                                       layerMode,
                                                       img->mask));
    }
    else
    {
        GFX_Set(GFXF_DRAW_MASK_ENABLE, GFX_FALSE);
    }
    
    for(row = 0; row < src_height; row++)
    {
        for(col = 0; col < src_width; col++)
        {
            idx = src_x + col + ((src_y + row) * img->width);
            
            bpp = GFX_ColorModeInfoGet(img->colorMode).bppOrdinal;
            
            //bpp = GFX_ColorInfo[9].bppOrdinal;
            
            // get the offset into the index table
            color = getOffsetFromIndexAndBPP(idx, bpp);
            
            // get the RLE data of the index
            color = getRLEDataAtIndex(img->header.dataAddress,
                                      img->width * img->height,
                                      color,
                                      &lastBlock,
                                      &lastOffset);
            
            // get the value from the RLE block
            color = getDiscreteValueAtIndex(idx, color, img->colorMode);
                
            //printf("%u", color);
                
            // convert the color value to the destination color
            color = GFX_ColorConvert(img->colorMode, layerMode, color);
                
            // set the draw color
            if(GFX_Set(GFXF_DRAW_COLOR, color) == GFX_FAILURE)
                return GFX_FAILURE;
                
            
            

            // draw the pixel                            
            GFX_DrawPixel(dest_point.x + col, dest_point.y + row);
        }
        
        //row = row;
        
        //printf("\n", color);
    }
    
    return GFX_SUCCESS;
}

static GFX_Result drawColorImage(GFXU_ImageAsset* img,
                                 int32_t src_x,
                                 int32_t src_y,
                                 int32_t src_width,
                                 int32_t src_height,
                                 int32_t dest_x,
                                 int32_t dest_y)
{
    GFX_Context* context = GFX_ActiveContext();
    GFX_Point dest_point;
    GFX_Color color;
    uint32_t lastBlock = 0;
    uint32_t lastOffset = 0;
    GFX_ColorMode layerMode;
    
    GFX_DrawState pixelDrawState;
    
    uint32_t idx;

    int32_t row;
    int32_t col;
    
    dest_point.x = dest_x;
    dest_point.y = dest_y;
    
    if(GFX_Get(GFXF_COLOR_MODE, &layerMode) == GFX_FAILURE)
        return GFX_FAILURE;
       
    // enable mask color if necessary
    if((img->flags & GFXU_IMAGE_USE_MASK) > 0)
    {
        GFX_Set(GFXF_DRAW_MASK_ENABLE, GFX_TRUE);
        GFX_Set(GFXF_DRAW_MASK_VALUE, img->mask);
    }
    else
    {
        GFX_Set(GFXF_DRAW_MASK_ENABLE, GFX_FALSE);
    }
    
    pixelDrawState = context->draw;
    
    for(row = 0; row < src_height; row++)
    {
        for(col = 0; col < src_width; col++)
        {
            idx = src_x + col + ((src_y + row) * img->width);
            
            // get the RLE data of the index
            color = getRLEDataAtIndex(img->header.dataAddress,
                                      img->width * img->height,
                                      idx,
                                      &lastBlock,
                                      &lastOffset);
                                    
            pixelDrawState.colorMode = img->colorMode;
            pixelDrawState.color = color;
            
            GFX_DrawPixelByDrawState(dest_point.x + col, dest_point.y + row, pixelDrawState);
        }
    }
    
    return GFX_SUCCESS;
}

GFX_Result GFXU_DrawImageRLEInternal(GFXU_ImageAsset* img,
                                     int32_t src_x,
                                     int32_t src_y,
                                     int32_t src_width,
                                     int32_t src_height,
                                     int32_t dest_x,
                                     int32_t dest_y)
{
    switch(img->colorMode)
    {
        case GFX_COLOR_MODE_INDEX_1:
        case GFX_COLOR_MODE_INDEX_4:
        case GFX_COLOR_MODE_INDEX_8:
        {
            return drawIndexImage(img,
                                  src_x,
                                  src_y,
                                  src_width,
                                  src_height,
                                  dest_x,
                                  dest_y);
        }
        case GFX_COLOR_MODE_RGBA_5551:
        case GFX_COLOR_MODE_RGBA_8888:
        case GFX_COLOR_MODE_ARGB_8888:
        {
            //Process alpha channel for these RAW formats
            GFX_BlendMode blendMode;
            GFX_Get(GFXF_DRAW_BLEND_MODE, &blendMode);
            GFX_Set(GFXF_DRAW_BLEND_MODE, blendMode | GFX_BLEND_CHANNEL);
            //No break, fall through
        }
        case GFX_COLOR_MODE_GS_8:
        case GFX_COLOR_MODE_RGB_332:
        case GFX_COLOR_MODE_RGB_565:
        case GFX_COLOR_MODE_RGB_888:
        case GFX_COLOR_MODE_YUV:
        {
            return drawColorImage(img,
                                  src_x,
                                  src_y,
                                  src_width,
                                  src_height,
                                  dest_x,
                                  dest_y);
        }
    };
        
    return GFX_FAILURE;
}