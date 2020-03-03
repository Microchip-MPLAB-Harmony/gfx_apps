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
 * Mode:   RGB_888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Bar;
	
/*********************************
 * GFX Image Asset
 * Name:   HarmonyLogo
 * Size:   197x139 pixels
 * Mode:   RGB_888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset HarmonyLogo;
	
/*********************************
 * GFX Image Asset
 * Name:   PIC32Logo
 * Size:   240x62 pixels
 * Mode:   RGB_888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PIC32Logo;
	
/*********************************
 * GFX Image Asset
 * Name:   MicrochipLogo
 * Size:   144x39 pixels
 * Mode:   RGB_888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset MicrochipLogo;
	
/*********************************
 * GFX Image Asset
 * Name:   iv_help
 * Size:   403x256 pixels
 * Mode:   RGB_888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset iv_help;
	
/*********************************
 * GFX Image Asset
 * Name:   iv_ninety
 * Size:   64x64 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset iv_ninety;
	
/*********************************
 * GFX Image Asset
 * Name:   iv_ninety_pressed
 * Size:   64x64 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset iv_ninety_pressed;
	
/*********************************
 * GFX Image Asset
 * Name:   iv_oneEighty_pressed
 * Size:   64x64 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset iv_oneEighty_pressed;
	
/*********************************
 * GFX Image Asset
 * Name:   iv_twoSeventy
 * Size:   64x64 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset iv_twoSeventy;
	
/*********************************
 * GFX Image Asset
 * Name:   iv_twoSeventy_pressed
 * Size:   64x64 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset iv_twoSeventy_pressed;
	
/*********************************
 * GFX Image Asset
 * Name:   iv_zero
 * Size:   64x64 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset iv_zero;
	
/*********************************
 * GFX Image Asset
 * Name:   iv_zero_pressed
 * Size:   64x64 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset iv_zero_pressed;
	
/*********************************
 * GFX Image Asset
 * Name:   iv_oneEighty
 * Size:   64x64 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset iv_oneEighty;
	
/*********************************
 * GFX Image Asset
 * Name:   bubbles
 * Size:   480x272 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset bubbles;
	
/*********************************
 * GFX Image Asset
 * Name:   goldengate
 * Size:   480x272 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset goldengate;
	
/*********************************
 * GFX Image Asset
 * Name:   leopard
 * Size:   480x272 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset leopard;
	
/*****************************************************************************
 * MPLAB Harmony Graphics Font Assets
 *****************************************************************************/
/*********************************
 * GFX Font Asset
 * Name:         TrebuchetMS
 * Height:       27
 * Style:        Plain
 * Glyph Count:  20
 * Range Count:  15
 * Glyph Ranges: 0x20
			     0x26
			     0x41
			     0x47
			     0x49
			     0x4D
			     0x50
			     0x56
			     0x61
			     0x65
			     0x67
			     0x69
			     0x6D
			     0x6F
			     0x72-0x77
 ***********************************/
extern GFXU_FontAsset TrebuchetMS;
	
/*********************************
 * GFX Font Asset
 * Name:         TrebuchetMS_1
 * Height:       17
 * Style:        Plain
 * Glyph Count:  12
 * Range Count:  8
 * Glyph Ranges: 0x20
			     0x50
			     0x65-0x66
			     0x68
			     0x6C-0x6D
			     0x6F-0x70
			     0x72-0x73
			     0x7A
 ***********************************/
extern GFXU_FontAsset TrebuchetMS_1;
	
/*****************************************************************************
 * MPLAB Harmony Graphics String Table
 *****************************************************************************/
/*********************************
 * GFX String Table
 * Name:         stringTable
 * Encoding:     ASCII
 * Languages:    default
 * String Count: 4
 ***********************************/
// language IDs
#define language_default    0

// string IDs
#define string_Help    0
#define string_Hint    1
#define string_Name    2
#define string_ZoomString    3
 
extern GFXU_StringTableAsset stringTable;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* GFX_ASSETS_H */

