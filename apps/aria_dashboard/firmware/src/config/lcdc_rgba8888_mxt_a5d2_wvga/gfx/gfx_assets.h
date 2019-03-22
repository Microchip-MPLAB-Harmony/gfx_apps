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
 * Name:   BackGroundWVGA
 * Size:   800x417 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset BackGroundWVGA;
	
/*********************************
 * GFX Image Asset
 * Name:   IndicatorLights
 * Size:   209x67 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset IndicatorLights;
	
/*********************************
 * GFX Image Asset
 * Name:   TurnLeft
 * Size:   29x31 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset TurnLeft;
	
/*********************************
 * GFX Image Asset
 * Name:   TurnRight
 * Size:   27x29 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset TurnRight;
	
/*********************************
 * GFX Image Asset
 * Name:   Globe
 * Size:   180x114 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Globe;
	
/*********************************
 * GFX Image Asset
 * Name:   DriveModeSport
 * Size:   241x20 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset DriveModeSport;
	
/*********************************
 * GFX Image Asset
 * Name:   Bar
 * Size:   800x91 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Bar;
	
/*********************************
 * GFX Image Asset
 * Name:   MicrochipLogo
 * Size:   202x55 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset MicrochipLogo;
	
/*********************************
 * GFX Image Asset
 * Name:   PIC0MPLAB100
 * Size:   372x214 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PIC0MPLAB100;
	
/*********************************
 * GFX Image Asset
 * Name:   PIC25MPLAB75
 * Size:   372x214 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PIC25MPLAB75;
	
/*********************************
 * GFX Image Asset
 * Name:   PIC50MPLAB50
 * Size:   372x214 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PIC50MPLAB50;
	
/*********************************
 * GFX Image Asset
 * Name:   PIC75MPLAB25
 * Size:   372x214 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PIC75MPLAB25;
	
/*********************************
 * GFX Image Asset
 * Name:   PIC100MPLAB0
 * Size:   372x214 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PIC100MPLAB0;
	
/*********************************
 * GFX Image Asset
 * Name:   enginestartstop120
 * Size:   120x105 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset enginestartstop120;
	
/*********************************
 * GFX Image Asset
 * Name:   enginestartstop120on
 * Size:   120x105 pixels
 * Mode:   RGBA_8888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset enginestartstop120on;
	
/*****************************************************************************
 * MPLAB Harmony Graphics Font Assets
 *****************************************************************************/
/*********************************
 * GFX Font Asset
 * Name:         ArialBlack_GearLabelFont
 * Height:       80
 * Style:        Plain
 * Glyph Count:  9
 * Range Count:  4
 * Glyph Ranges: 0x31-0x36
			     0x44
			     0x4E
			     0x50
 ***********************************/
extern GFXU_FontAsset ArialBlack_GearLabelFont;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialBlack_SpeedoLabelFont
 * Height:       99
 * Style:        Plain
 * Glyph Count:  10
 * Range Count:  1
 * Glyph Ranges: 0x30-0x39
 ***********************************/
extern GFXU_FontAsset ArialBlack_SpeedoLabelFont;
	
/*********************************
 * GFX Font Asset
 * Name:         Arial_18_BI_Font
 * Height:       22
 * Style:        Bold, Italic
 * Glyph Count:  15
 * Range Count:  6
 * Glyph Ranges: 0x2E
			     0x30-0x39
			     0x46
			     0x48
			     0x4D
			     0x50
 ***********************************/
extern GFXU_FontAsset Arial_18_BI_Font;
	
/*********************************
 * GFX Font Asset
 * Name:         Arial_12_BI_Font
 * Height:       15
 * Style:        Bold, Italic
 * Glyph Count:  14
 * Range Count:  5
 * Glyph Ranges: 0x30-0x39
			     0x67
			     0x69
			     0x6D
			     0x70
 ***********************************/
extern GFXU_FontAsset Arial_12_BI_Font;
	
/*********************************
 * GFX Font Asset
 * Name:         Arial
 * Height:       56
 * Style:        Bold, Italic
 * Glyph Count:  2
 * Range Count:  2
 * Glyph Ranges: 0x32
			     0x37
 ***********************************/
extern GFXU_FontAsset Arial;
	
/*****************************************************************************
 * MPLAB Harmony Graphics String Table
 *****************************************************************************/
/*********************************
 * GFX String Table
 * Name:         stringTable
 * Encoding:     ASCII
 * Languages:    default
 * String Count: 15
 ***********************************/
// language IDs
#define language_default    0

// string IDs
#define string_ClimateControlStringDefault    0
#define string_ClimateControlUnitStringDefault    1
#define string_GearLabelStringDefault    2
#define string_GearLabelStringSet    3
#define string_MPGUnitString    4
#define string_MPGValueString    5
#define string_MPHLabelString    6
#define string_OdoLabelStringDefault    7
#define string_OdoLabelStringSet    8
#define string_OdoMilesLabelString    9
#define string_SpeedoLabelStringDefault    10
#define string_SpeedoLabelStringSet    11
#define string_TripAStringDefault    12
#define string_TripBStringDefault    13
#define string_TripStringSet    14
 
extern GFXU_StringTableAsset stringTable;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* GFX_ASSETS_H */

