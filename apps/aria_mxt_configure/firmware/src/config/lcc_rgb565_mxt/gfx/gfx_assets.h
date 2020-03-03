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
 * Name:   controller
 * Size:   160x177 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset controller;
	
/*********************************
 * GFX Image Asset
 * Name:   mosture
 * Size:   100x89 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset mosture;
	
/*********************************
 * GFX Image Asset
 * Name:   passive_stylus
 * Size:   82x85 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset passive_stylus;
	
/*********************************
 * GFX Image Asset
 * Name:   glove
 * Size:   123x98 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset glove;
	
/*********************************
 * GFX Image Asset
 * Name:   active_stylus
 * Size:   48x125 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset active_stylus;
	
/*********************************
 * GFX Image Asset
 * Name:   ram
 * Size:   110x83 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset ram;
	
/*********************************
 * GFX Image Asset
 * Name:   flash
 * Size:   200x105 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset flash;
	
/*********************************
 * GFX Image Asset
 * Name:   down_arrow
 * Size:   35x19 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset down_arrow;
	
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
 * Name:   HarmonyLogo
 * Size:   197x139 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset HarmonyLogo;
	
/*********************************
 * GFX Image Asset
 * Name:   back
 * Size:   48x41 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset back;
	
/*********************************
 * GFX Image Asset
 * Name:   forward
 * Size:   48x41 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset forward;
	
/*********************************
 * GFX Image Asset
 * Name:   mcu
 * Size:   200x157 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset mcu;
	
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
 * MPLAB Harmony Graphics Font Assets
 *****************************************************************************/
/*********************************
 * GFX Font Asset
 * Name:         TimesNewRoman18
 * Height:       22
 * Style:        Bold
 * Glyph Count:  37
 * Range Count:  14
 * Glyph Ranges: 0x20
			     0x27-0x29
			     0x3A
			     0x41-0x44
			     0x46
			     0x4B-0x4D
			     0x50
			     0x52-0x55
			     0x58
			     0x61
			     0x63-0x69
			     0x6C-0x6F
			     0x72-0x76
			     0x79
 ***********************************/
extern GFXU_FontAsset TimesNewRoman18;
	
/*********************************
 * GFX Font Asset
 * Name:         TimesNewRoman12
 * Height:       15
 * Style:        Plain
 * Glyph Count:  0
 * Range Count:  0
 ***********************************/
extern GFXU_FontAsset TimesNewRoman12;
	
/*****************************************************************************
 * MPLAB Harmony Graphics String Table
 *****************************************************************************/
/*********************************
 * GFX String Table
 * Name:         stringTable
 * Encoding:     ASCII
 * Languages:    default
 * String Count: 21
 ***********************************/
// language IDs
#define language_default    0

// string IDs
#define string_Configure    0
#define string_GFX_MXT_Configure    1
#define string_Load    2
#define string_Store    3
#define string_Test    4
#define string_button_test    5
#define string_load_destination    6
#define string_load_pc    7
#define string_load_programflash    8
#define string_load_sdcard    9
#define string_load_source    10
#define string_load_title    11
#define string_load_usbdrive    12
#define string_stage    13
#define string_stage_source    14
#define string_stage_title    15
#define string_store_done    16
#define string_store_dontsave    17
#define string_store_save    18
#define string_store_title    19
#define string_test_title    20
 
extern GFXU_StringTableAsset stringTable;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* GFX_ASSETS_H */

