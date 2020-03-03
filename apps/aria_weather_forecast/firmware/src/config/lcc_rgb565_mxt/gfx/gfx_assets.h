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
 * Name:   Bar
 * Size:   480x65 pixels
 * Mode:   RGB_565
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
 * Mode:   RGB_565
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
	
/*********************************
 * GFX Image Asset
 * Name:   cloudy
 * Size:   272x100 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset cloudy;
	
/*********************************
 * GFX Image Asset
 * Name:   fog
 * Size:   272x100 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset fog;
	
/*********************************
 * GFX Image Asset
 * Name:   lightning
 * Size:   272x100 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset lightning;
	
/*********************************
 * GFX Image Asset
 * Name:   rainbow
 * Size:   272x100 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset rainbow;
	
/*********************************
 * GFX Image Asset
 * Name:   raindrops
 * Size:   272x100 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset raindrops;
	
/*********************************
 * GFX Image Asset
 * Name:   sunny
 * Size:   272x100 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset sunny;
	
/*********************************
 * GFX Image Asset
 * Name:   windy
 * Size:   272x100 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset windy;
	
/*********************************
 * GFX Image Asset
 * Name:   citySkyline
 * Size:   40x40 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset citySkyline;
	
/*****************************************************************************
 * MPLAB Harmony Graphics Palette Assets
 *****************************************************************************/
/*********************************
 * GFX Palette Asset
 * Name:   citySkyline_palette
 * Colors: 63
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset citySkyline_palette;
	
/*****************************************************************************
 * MPLAB Harmony Graphics Font Assets
 *****************************************************************************/
/*********************************
 * GFX Font Asset
 * Name:         ArialUnicodeMS_Medium
 * Height:       19
 * Style:        Antialias
 * Glyph Count:  96
 * Range Count:  45
 * Glyph Ranges: 0x20
			     0x25
			     0x2B
			     0x2F-0x35
			     0x38-0x3A
			     0x41-0x46
			     0x48-0x59
			     0x61-0x65
			     0x67-0x70
			     0x72-0x7A
			     0xED
			     0xF1
			     0x4E00
			     0x4E09
			     0x4E8C
			     0x4E91
			     0x4E94
			     0x4F4E
			     0x516D
			     0x524D
			     0x53D6
			     0x56DB
			     0x591A
			     0x592A
			     0x5B9A
			     0x5C0F
			     0x5E02
			     0x5EA6
			     0x5F53
			     0x6307
			     0x6570
			     0x65E5
			     0x65F6
			     0x6B61
			     0x6BCF
			     0x6D88
			     0x6E7F
			     0x7684
			     0x78BA
			     0x8FCE
			     0x901F
			     0x90FD
			     0x9633
			     0x96E8
			     0x98CE
 ***********************************/
extern GFXU_FontAsset ArialUnicodeMS_Medium;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialUnicodeMS_Large
 * Height:       33
 * Style:        Antialias
 * Glyph Count:  16
 * Range Count:  12
 * Glyph Ranges: 0x20
			     0x41
			     0x4C-0x4D
			     0x61
			     0x64-0x65
			     0x67
			     0x69
			     0x6C
			     0x6E-0x6F
			     0x72-0x73
			     0x4E0A
			     0x6D77
 ***********************************/
extern GFXU_FontAsset ArialUnicodeMS_Large;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialUnicodeMS_Small
 * Height:       13
 * Style:        Antialias
 * Glyph Count:  50
 * Range Count:  26
 * Glyph Ranges: 0x20
			     0x30-0x33
			     0x35-0x36
			     0x38-0x3A
			     0x41-0x43
			     0x48
			     0x50
			     0x54
			     0x61-0x65
			     0x67-0x6A
			     0x6C-0x70
			     0x72-0x77
			     0x79
			     0x4E0B
			     0x4F1A
			     0x5B9E
			     0x5EA6
			     0x6309
			     0x6539
			     0x66F4
			     0x673A
			     0x6E29
			     0x6E7F
			     0x9645
			     0x96E8
			     0x9762
 ***********************************/
extern GFXU_FontAsset ArialUnicodeMS_Small;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialUnicodeMS_Huge
 * Height:       43
 * Style:        Antialias
 * Glyph Count:  7
 * Range Count:  5
 * Glyph Ranges: 0x32-0x33
			     0x35
			     0x37-0x38
			     0x2103
			     0x2109
 ***********************************/
extern GFXU_FontAsset ArialUnicodeMS_Huge;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialUnicodeMS_Tiny
 * Height:       12
 * Style:        Antialias
 * Glyph Count:  31
 * Range Count:  21
 * Glyph Ranges: 0x20
			     0x25
			     0x30-0x33
			     0x35-0x36
			     0x38
			     0x46
			     0x4C
			     0x53
			     0x61
			     0x65
			     0x69
			     0x6B-0x6E
			     0x70
			     0x72-0x75
			     0x2103
			     0x2109
			     0x50CF
			     0x5EA6
			     0x611F
			     0x6E29
			     0x89C9
 ***********************************/
extern GFXU_FontAsset ArialUnicodeMS_Tiny;
	
/*****************************************************************************
 * MPLAB Harmony Graphics String Table
 *****************************************************************************/
/*********************************
 * GFX String Table
 * Name:         stringTable
 * Encoding:     UTF8
 * Languages:    English, Chinese, Spanish
 * String Count: 51
 ***********************************/
// language IDs
#define language_English    0
#define language_Chinese    1
#define language_Spanish    2

// string IDs
#define string_Cancel    0
#define string_City    1
#define string_Cloudy    2
#define string_Current    3
#define string_LanguageID    4
#define string_LayerTitle    5
#define string_LocalizationTitle    6
#define string_Ok    7
#define string_PressToChange    8
#define string_Quit    9
#define string_Rain    10
#define string_Start    11
#define string_Stop    12
#define string_String_0Percent    13
#define string_String_0Temp    14
#define string_String_100Percent    15
#define string_String_100Temp    16
#define string_String_50Percent    17
#define string_String_ActualTemp    18
#define string_String_FeelTemp    19
#define string_String_Friday    20
#define string_String_Humidity    21
#define string_String_Midnight    22
#define string_String_Monday    23
#define string_String_NineAM    24
#define string_String_NinePM    25
#define string_String_Noon    26
#define string_String_Precipitation    27
#define string_String_Saturday    28
#define string_String_SixAM    29
#define string_String_SixPM    30
#define string_String_Sunday    31
#define string_String_ThreeAM    32
#define string_String_ThreePM    33
#define string_String_Thursday    34
#define string_String_Tuesday    35
#define string_String_Wednesday    36
#define string_Sunny    37
#define string_TimeHour    38
#define string_TimeMinute    39
#define string_Welcome    40
#define string_degrees    41
#define string_humidity    42
#define string_lbl_City    43
#define string_lbl_Daily    44
#define string_lbl_Hourly    45
#define string_ninemph    46
#define string_thirteenpercent    47
#define string_uvindex    48
#define string_uvlow    49
#define string_windspeed    50
 
extern GFXU_StringTableAsset stringTable;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* GFX_ASSETS_H */

