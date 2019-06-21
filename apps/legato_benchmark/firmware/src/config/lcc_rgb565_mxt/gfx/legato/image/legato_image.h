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

#include "gfx/legato/asset/legato_asset.h"
#include "gfx/legato/common/legato_color.h"
#include "gfx/legato/common/legato_pixelbuffer.h"

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
    LE_IMAGE_USE_MASK  = 0x1,
} leImageFlags;

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
           value
    palette - will contain a valid pointer to a palette asset if thie image
              is an index map instead of a color image
*/
typedef struct leImage
{
    leAssetHeader header;
    leImageFormat format;
    lePixelBuffer buffer;
    leImageFlags flags;
    leColor mask;
    lePalette* palette;
} leImage;

typedef struct leImageDecoder
{
    leBool   (*supportsImage)(const leImage* img);
    leResult (*draw)(const leImage* img, const leRect* srcRect, int32_t x, int32_t y, uint32_t a);
    leResult (*copy)(const leImage* img, leImage* newImg);
    leResult (*copyToAddress)(const leImage* img, void* address, leImage* newImg);
    leResult (*decompress)(const leImage* img, leImage* newImg);
    leResult (*decompressToAddress)(const leImage* img, void* address, leImage* newImg);
    void     (*exec)(void);
    leBool   (*isDone)(void);
    void     (*free)(void);
} leImageDecoder;

void leImage_InitDecoders();

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
      
LIB_EXPORT leImage* leImage_Copy(const leImage* img,
                                 void* addr,
                                 leBool allocate);
                                 
LIB_EXPORT leImage* leImage_Decompress(const leImage* img);
                                                          

// *****************************************************************************
/* Function:
    leResult lePreprocessImage(leImage* img,
                                    uint32_t destAddress,
                                    leColorMode destMode,
                                    leBool padBuffer);

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
    
    leColorInfo[destMode].size * img->width * img->height
    
    This function only works with images that are located in a core accessible
    memory location like SRAM or DDR.  If the image is located in an external
    source then leDrawImage should be called directly.  The caller will then
    need to service the media streaing state machine.  Once finished the
    image asset descriptor must be changed manually.  This function can be used
    as a reference on how to accomplish this.
     
  Parameters:
    leImage* img - pointer to the image asset to draw
    uint32_t destAddress - the address to render the image to
    leColorMode destMode - the desired output mode of the image
    leBool padBuffer - indicates that the image buffer dimensions should be
                         padded to equal powers of 2 (required by some GPUs)

  Returns:
    leResult - the result of the operation
*/
#if 0
LIB_EXPORT leResult lePreprocessImage(leImage* img,
                                           uint32_t destAddress,
                                           leColorMode destMode,
                                           leBool padBuffer);
#endif

#endif /* LE_IMAGE_H */