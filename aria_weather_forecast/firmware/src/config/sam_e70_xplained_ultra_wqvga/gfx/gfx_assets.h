/*******************************************************************************
  MPLAB Harmony Graphics Asset Header File

  File Name:
    gfx_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
	MPLAB Harmony Graphics Stack.

  Description:
    Header file containing a list of asset specifications for use with the
	MPLAB Harmony Graphics Stack.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2018 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
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
// DOM-IGNORE-END

#ifndef GFX_ASSETS_H
#define GFX_ASSETS_H

#include "gfx/utils/gfx_utils.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END 

/*** Generated Asset Descriptors ***/
/*****************************************************************************
 * MPLAB Harmony Graphics Asset Location IDs
 *****************************************************************************/
#define GFXU_ASSET_LOCATION_ID_INTERNAL    0
 
/*****************************************************************************
 * MPLAB Harmony Graphics Image Assets
 *****************************************************************************/
/*********************************
 * GFX Image Asset
 * Name:   clouds3
 * Size:   480x106 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset clouds3;
	
/*********************************
 * GFX Image Asset
 * Name:   colon
 * Size:   3x12 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset colon;
	
/*********************************
 * GFX Image Asset
 * Name:   gradient2
 * Size:   346x76 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset gradient2;
	
/*********************************
 * GFX Image Asset
 * Name:   mchpLogo
 * Size:   32x32 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset mchpLogo;
	
/*********************************
 * GFX Image Asset
 * Name:   cloud_icon
 * Size:   64x64 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset cloud_icon;
	
/*********************************
 * GFX Image Asset
 * Name:   rain_icon_sm
 * Size:   64x64 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset rain_icon_sm;
	
/*********************************
 * GFX Image Asset
 * Name:   sun_icon_sm
 * Size:   64x64 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset sun_icon_sm;
	
/*********************************
 * GFX Image Asset
 * Name:   Bar
 * Size:   480x65 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Bar;
	
/*********************************
 * GFX Image Asset
 * Name:   HarmonyLogo
 * Size:   197x139 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset HarmonyLogo;
	
/*********************************
 * GFX Image Asset
 * Name:   MicrochipLogo
 * Size:   144x39 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset MicrochipLogo;
	
/*********************************
 * GFX Image Asset
 * Name:   PIC32Logo
 * Size:   240x62 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PIC32Logo;
	
/*********************************
 * GFX Image Asset
 * Name:   CrossFade0
 * Size:   240x139 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CrossFade0;
	
/*********************************
 * GFX Image Asset
 * Name:   CrossFade1
 * Size:   240x139 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CrossFade1;
	
/*********************************
 * GFX Image Asset
 * Name:   CrossFade2
 * Size:   240x139 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CrossFade2;
	
/*********************************
 * GFX Image Asset
 * Name:   CrossFade3
 * Size:   240x139 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CrossFade3;
	
/*****************************************************************************
 * MPLAB Harmony Graphics Palette Assets
 *****************************************************************************/
/*********************************
 * GFX Palette Asset
 * Name:   gradient2_palette
 * Colors: 23
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset gradient2_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   Bar_palette
 * Colors: 52
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset Bar_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   MicrochipLogo_palette
 * Colors: 234
 * Format: RGB_888
 ***********************************/
extern GFXU_PaletteAsset MicrochipLogo_palette;
	
/*****************************************************************************
 * MPLAB Harmony Graphics Font Assets
 *****************************************************************************/
/*********************************
 * GFX Font Asset
 * Name:         ArialUnicodeMS20
 * Height:       28
 * Style:        Plain
 * Glyph Count:  86
 * Range Count:  38
 * Glyph Ranges: 0x20
			     0x25
			     0x2B
			     0x2F-0x35
			     0x38-0x3A
			     0x41-0x45
			     0x48-0x49
			     0x4B-0x59
			     0x61-0x65
			     0x67-0x70
			     0x72-0x7A
			     0xED
			     0xF1
			     0x4E91
			     0x4F4E
			     0x524D
			     0x53D6
			     0x591A
			     0x592A
			     0x5B9A
			     0x5EA6
			     0x5F53
			     0x6307
			     0x6570
			     0x6B61
			     0x6D88
			     0x6E2F
			     0x6E7F
			     0x7684
			     0x76EE
			     0x78BA
			     0x8FCE
			     0x901F
			     0x9633
			     0x96E8
			     0x9805
			     0x98CE
			     0x9999
 ***********************************/
extern GFXU_FontAsset ArialUnicodeMS20;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialUnicodeMS_Large
 * Height:       65
 * Style:        Plain
 * Glyph Count:  8
 * Range Count:  7
 * Glyph Ranges: 0x20
			     0x33
			     0x36-0x37
			     0x39
			     0x43
			     0x46
			     0xB0
 ***********************************/
extern GFXU_FontAsset ArialUnicodeMS_Large;
	
/*****************************************************************************
 * MPLAB Harmony Graphics String Table
 *****************************************************************************/
/*********************************
 * GFX String Table
 * Name:         stringTable
 * Encoding:     UTF8
 * Languages:    English, Chinese, Spanish
 * String Count: 29
 ***********************************/
// language IDs
#define language_English    0
#define language_Chinese    1
#define language_Spanish    2

// string IDs
#define string_Cancel    0
#define string_Chandler    1
#define string_Cloudy    2
#define string_Current    3
#define string_Item1    4
#define string_Item2    5
#define string_Item3    6
#define string_Item4    7
#define string_Item5    8
#define string_LanguageID    9
#define string_LayerTitle    10
#define string_LocalizationTitle    11
#define string_Ok    12
#define string_Quit    13
#define string_Rain    14
#define string_SmallString    15
#define string_Start    16
#define string_Stop    17
#define string_Sunny    18
#define string_TimeHour    19
#define string_TimeMinute    20
#define string_Welcome    21
#define string_degrees    22
#define string_humidity    23
#define string_ninemph    24
#define string_thirteenpercent    25
#define string_uvindex    26
#define string_uvlow    27
#define string_windspeed    28
 
extern GFXU_StringTableAsset stringTable;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* GFX_ASSETS_H */

