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
 * Name:   CircularGauge
 * Size:   60x60 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CircularGauge;
	
/*********************************
 * GFX Image Asset
 * Name:   Bar
 * Size:   480x65 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Bar;
	
/*********************************
 * GFX Image Asset
 * Name:   HarmonyLogo
 * Size:   197x139 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset HarmonyLogo;
	
/*********************************
 * GFX Image Asset
 * Name:   MicrochipLogo
 * Size:   144x39 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset MicrochipLogo;
	
/*********************************
 * GFX Image Asset
 * Name:   PIC32Logo
 * Size:   240x62 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PIC32Logo;
	
/*********************************
 * GFX Image Asset
 * Name:   TouchScreen
 * Size:   70x70 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset TouchScreen;
	
/*********************************
 * GFX Image Asset
 * Name:   CrossFade0
 * Size:   240x139 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CrossFade0;
	
/*********************************
 * GFX Image Asset
 * Name:   CrossFade1
 * Size:   240x139 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CrossFade1;
	
/*********************************
 * GFX Image Asset
 * Name:   CrossFade2
 * Size:   240x139 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CrossFade2;
	
/*********************************
 * GFX Image Asset
 * Name:   CrossFade3
 * Size:   240x139 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CrossFade3;
	
/*********************************
 * GFX Image Asset
 * Name:   CircularSliderFill100x100
 * Size:   100x100 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CircularSliderFill100x100;
	
/*********************************
 * GFX Image Asset
 * Name:   ArcDemoIconFilled100x100
 * Size:   100x100 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset ArcDemoIconFilled100x100;
	
/*********************************
 * GFX Image Asset
 * Name:   CircularGaugeFilled100x100
 * Size:   100x100 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CircularGaugeFilled100x100;
	
/*********************************
 * GFX Image Asset
 * Name:   BarGraphFilled100x100
 * Size:   100x100 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset BarGraphFilled100x100;
	
/*********************************
 * GFX Image Asset
 * Name:   LineGraphFilled100x100
 * Size:   100x100 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset LineGraphFilled100x100;
	
/*********************************
 * GFX Image Asset
 * Name:   PieChartFilled100x100
 * Size:   100x100 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PieChartFilled100x100;
	
/*********************************
 * GFX Image Asset
 * Name:   ArcDemoNextButtonFilled30x30
 * Size:   30x30 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset ArcDemoNextButtonFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   BarGraphHomeButtonFilled30x30
 * Size:   30x30 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset BarGraphHomeButtonFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   BarGraphNextButtonFilled30x30
 * Size:   30x30 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset BarGraphNextButtonFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   CircGaugeHomeButtonFilled30x30
 * Size:   30x30 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CircGaugeHomeButtonFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   CircGaugeNextButtonFilled30x30
 * Size:   30x30 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CircGaugeNextButtonFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   CircSliderHomeButtonFilled30x30
 * Size:   30x30 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CircSliderHomeButtonFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   CircSliderNextButtonFilled30x30
 * Size:   30x30 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CircSliderNextButtonFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   LineGraphHomeButtonFilled30x30
 * Size:   30x30 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset LineGraphHomeButtonFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   LineGraphNextButtonFilled30x30
 * Size:   30x30 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset LineGraphNextButtonFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   PieChartHomeButtonFilled30x30
 * Size:   30x30 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PieChartHomeButtonFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   PieChartNextButtonFilled30x30
 * Size:   30x30 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PieChartNextButtonFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   ArcDemoHomeButtonFilled30x30
 * Size:   30x30 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset ArcDemoHomeButtonFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   LineGraphTouchScreenFilled30x30
 * Size:   70x70 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset LineGraphTouchScreenFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   ArcDemoTouchScreenFilled30x30
 * Size:   70x70 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset ArcDemoTouchScreenFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   BarGraphTouchScreenFilled30x30
 * Size:   70x70 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset BarGraphTouchScreenFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   CircGaugeTouchScreenFilled30x30
 * Size:   70x70 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset CircGaugeTouchScreenFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   CircSliderTouchScreenFilled30x30
 * Size:   70x70 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset CircSliderTouchScreenFilled30x30;
	
/*********************************
 * GFX Image Asset
 * Name:   PieChartTouchScreenFilled30x30
 * Size:   70x70 pixels
 * Mode:   ARGB_8888
 * Format: PNG
 ***********************************/
extern GFXU_ImageAsset PieChartTouchScreenFilled30x30;
	
/*****************************************************************************
 * MPLAB Harmony Graphics Font Assets
 *****************************************************************************/
/*********************************
 * GFX Font Asset
 * Name:         CopperplateGothicLight
 * Height:       18
 * Style:        Bold
 * Glyph Count:  17
 * Range Count:  11
 * Glyph Ranges: 0x20
			     0x41
			     0x52-0x53
			     0x5C
			     0x61
			     0x63-0x65
			     0x68-0x69
			     0x6C
			     0x6E-0x6F
			     0x72-0x73
			     0x77
 ***********************************/
extern GFXU_FontAsset CopperplateGothicLight;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialUnicodeMS
 * Height:       19
 * Style:        Bold
 * Glyph Count:  27
 * Range Count:  12
 * Glyph Ranges: 0x20
			     0x41-0x44
			     0x47
			     0x4C
			     0x50
			     0x53
			     0x57
			     0x61
			     0x63-0x65
			     0x67-0x69
			     0x6C-0x70
			     0x72-0x76
 ***********************************/
extern GFXU_FontAsset ArialUnicodeMS;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialBig
 * Height:       56
 * Style:        Plain
 * Glyph Count:  0
 * Range Count:  0
 ***********************************/
extern GFXU_FontAsset ArialBig;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialMed
 * Height:       29
 * Style:        Plain
 * Glyph Count:  10
 * Range Count:  1
 * Glyph Ranges: 0x30-0x39
 ***********************************/
extern GFXU_FontAsset ArialMed;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialSmall
 * Height:       14
 * Style:        Plain
 * Glyph Count:  34
 * Range Count:  13
 * Glyph Ranges: 0x20
			     0x2D
			     0x30-0x39
			     0x46-0x47
			     0x4A
			     0x4D
			     0x54
			     0x61-0x63
			     0x65
			     0x68-0x69
			     0x6C-0x70
			     0x72-0x75
			     0x78-0x79
 ***********************************/
extern GFXU_FontAsset ArialSmall;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialGaugeLabel
 * Height:       22
 * Style:        Plain
 * Glyph Count:  10
 * Range Count:  1
 * Glyph Ranges: 0x30-0x39
 ***********************************/
extern GFXU_FontAsset ArialGaugeLabel;
	
/*****************************************************************************
 * MPLAB Harmony Graphics String Table
 *****************************************************************************/
/*********************************
 * GFX String Table
 * Name:         stringTable
 * Encoding:     ASCII
 * Languages:    default
 * String Count: 50
 ***********************************/
// language IDs
#define language_default    0

// string IDs
#define string_ArcPrimitiveDemo    0
#define string_AriaShowcase    1
#define string_BarGraphDemo    2
#define string_CircularGaugeDemo    3
#define string_CircularSliderDemo    4
#define string_DefaultGaugeValue    5
#define string_DefaultValueBig    6
#define string_Feb    7
#define string_Fill    8
#define string_Gas    9
#define string_Jan    10
#define string_LineGraphDemo    11
#define string_Mar    12
#define string_NumGauge0    13
#define string_NumGauge1    14
#define string_NumGauge10    15
#define string_NumGauge2    16
#define string_NumGauge3    17
#define string_NumGauge4    18
#define string_NumGauge5    19
#define string_NumGauge6    20
#define string_NumGauge7    21
#define string_NumGauge8    22
#define string_NumGauge9    23
#define string_NumsBig    24
#define string_NumsMed    25
#define string_NumsSmall    26
#define string_PieChartDemo    27
#define string_Reloaded    28
#define string_TouchHere    29
#define string_mph    30
#define string_pt0    31
#define string_pt1    32
#define string_pt10    33
#define string_pt11    34
#define string_pt12    35
#define string_pt13    36
#define string_pt14    37
#define string_pt15    38
#define string_pt2    39
#define string_pt3    40
#define string_pt4    41
#define string_pt5    42
#define string_pt6    43
#define string_pt7    44
#define string_pt8    45
#define string_pt9    46
#define string_rpm    47
#define string_x    48
#define string_y    49
 
extern GFXU_StringTableAsset stringTable;

/*****************************************************************************
 * MPLAB Harmony Graphics Global Palette
 *****************************************************************************/

extern uint16_t globalColorPalette[256];
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* GFX_ASSETS_H */

