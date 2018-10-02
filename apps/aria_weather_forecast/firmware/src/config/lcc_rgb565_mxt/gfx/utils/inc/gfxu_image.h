/*******************************************************************************
 Module for Microchip Graphics Library - Graphics Utilities Library

  Company:
    Microchip Technology Inc.

  File Name:
    gfx_image.h

  Summary:
    Defines image assets

  Description:
    Image drawing at specified coordinates
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2017 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
#ifndef GFXU_IMAGE_H
#define GFXU_IMAGE_H
//DOM-IGNORE-END

#include "gfx/utils/inc/gfxu_global.h"

typedef struct GFXU_PaletteAsset_t GFXU_PaletteAsset;

// *****************************************************************************
/* Enumeration:
    GFXU_ImageFormat_t

  Summary:
    Indicates the image encoding format
*/
typedef enum GFXU_ImageFormat_t
{
    GFXU_IMAGE_FORMAT_RAW = 0,
    GFXU_IMAGE_FORMAT_JPEG,
    GFXU_IMAGE_FORMAT_PNG
} GFXU_ImageFormat;

// *****************************************************************************
/* Enumeration:
    GFXU_ImageCompressionType_t

  Summary:
    Indicates the image compression type, only applies to RAW types
*/
typedef enum GFXU_ImageCompressionType_t
{
    GFXU_IMAGE_COMPRESSION_NONE = 0,
    GFXU_IMAGE_COMPRESSION_RLE
} GFXU_ImageCompressionType;

// *****************************************************************************
/* Enumeration:
    GFXU_ImageFlags_t

  Summary:
    A list of flags describing an image asset
*/
typedef enum GFXU_ImageFlags_t
{
    GFXU_IMAGE_USE_MASK          = 0x1,
    GFXU_IMAGE_SUPPORTS_CLIPPING = 0x2,
    GFXU_IMAGE_DIRECT_BLIT       = 0x4,
} GFXU_ImageFlags;

// *****************************************************************************
/* Structure:
    GFXU_ImageAsset_t

  Summary:
    Describes an image asset.
    
    header - standard asset header
    format - the format of the image.  this directly affects which decoder
             is invoked when rendering the image
    width - the width of the image in pixels
    height - the height of the image in pixels
    colorMode - the color mode of the image
    compType - the compression mode of the image
    useMask - indicates of the mask field is used
    mask - may contain a masking color for the image.  blit operations may 
           reference this value and reject image pixels that match this
           value
    palette - will contain a valid pointer to a palette asset if thie image
              is an index map instead of a color image
*/
typedef struct GFXU_ImageAsset_t
{
    GFXU_AssetHeader header;
    GFXU_ImageFormat format;
    uint32_t width;
    uint32_t height;
    uint32_t bufferWidth;
    uint32_t bufferHeight;
    GFX_ColorMode colorMode;
    GFXU_ImageCompressionType compType;
    GFXU_ImageFlags flags;
    GFX_Color mask;
    GFXU_PaletteAsset* palette;
} GFXU_ImageAsset;

// *****************************************************************************
/* Function:
    GFX_Result GFXU_DrawImage(void);

  Summary:
    Draws a portion of the given image at the specified coordinates.
     
  Parameters:
    GFXU_ImageAsset* img - pointer to the image asset to draw
    int32_t src_x - the x position of the source image to draw
                    (0 if whole image)
    int32_t src_y - the y position of the source image to draw
                    (0 if whole image)
    int32_t src_width - the width of the source rectangle to draw
                        (source width if whole image)
    int32_t src_width - the height of the source rectangle to draw
                        (source height if whole image)   
    int32_t dest_x - the x position to draw to
    int32_t dest_y - the y position to draw to
    GFXU_MemoryIntf* read_cb - a pointer to a memory interface to use for
                               memory operations, not needed for internal
                               assets
    GFXU_ExternalAssetReader** reader - will return as a valid pointer if
                          the image asset is located in an external source.
                          If this is the case then the caller is responsible
                          for servicing the external asset reader state
                          machine until completion.  The caller is then
                          responsible for freeing the reader's memory.
  Returns:
    GFX_Result
*/
LIB_EXPORT GFX_Result GFXU_DrawImage(GFXU_ImageAsset* img,
                                     int32_t src_x,
                                     int32_t src_y,
                                     int32_t src_width,
                                     int32_t src_height,
                                     int32_t dest_x,
                                     int32_t dest_y,
                                     GFXU_MemoryIntf* read_cb,
                                     GFXU_ExternalAssetReader** reader);

// *****************************************************************************
/* Function:
    GFX_Result GFXU_PreprocessImage(GFXU_ImageAsset* img,
                                    uint32_t destAddress,
                                    GFX_ColorMode destMode,
                                    GFX_Bool padBuffer);

  Summary:
    Preprocesses an image to a specified memory address.
     
  Description:
    This function preprocesses an image asset through the HAL pipeline
    and renders it to a given address, in a given color mode, and can pad
    the image buffer dimensions to be powers of 2 as required by some 
    graphics accelerators.
    
    This function is also useful for pre-staging images into run-time memory
    locations.
    
    The caller is required to ensure that the destination address is capable of 
    containing the result.  The size can be calculated by using the method:
    
    GFX_ColorInfo[destMode].size * img->width * img->height
    
    This function only works with images that are located in a core accessible
    memory location like SRAM or DDR.  If the image is located in an external
    source then GFXU_DrawImage should be called directly.  The caller will then
    need to service the media streaing state machine.  Once finished the
    image asset descriptor must be changed manually.  This function can be used
    as a reference on how to accomplish this.
     
  Parameters:
    GFXU_ImageAsset* img - pointer to the image asset to draw
    uint32_t destAddress - the address to render the image to
    GFX_ColorMode destMode - the desired output mode of the image
    GFX_Bool padBuffer - indicates that the image buffer dimensions should be
                         padded to equal powers of 2 (required by some GPUs)
    GFXU_MemoryIntf* read_cb - a pointer to a memory interface to use for
                               memory operations, not needed for internal
                               assets
    GFXU_ExternalAssetReader** reader - will return as a valid pointer if
                          the image asset is located in an external source.
                          If this is the case then the caller is responsible
                          for servicing the external asset reader state
                          machine until completion.  The caller is then
                          responsible for freeing the reader's memory.
  Returns:
    GFX_Result - the result of the operation
*/
LIB_EXPORT GFX_Result GFXU_PreprocessImage(GFXU_ImageAsset* img,
                                           uint32_t destAddress,
                                           GFX_ColorMode destMode,
                                           GFX_Bool padBuffer);

#endif /* GFXU_IMAGE_H */