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
 * Height:       26
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
 * Height:       18
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

