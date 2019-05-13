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
 * Name:   Bluetooth
 * Size:   160x160 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Bluetooth;
	
/*********************************
 * GFX Image Asset
 * Name:   Chargers
 * Size:   160x160 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Chargers;
	
/*********************************
 * GFX Image Asset
 * Name:   Fan
 * Size:   160x160 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Fan;
	
/*********************************
 * GFX Image Asset
 * Name:   Music
 * Size:   160x160 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Music;
	
/*********************************
 * GFX Image Asset
 * Name:   Phone
 * Size:   160x160 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Phone;
	
/*********************************
 * GFX Image Asset
 * Name:   CellSignal01
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CellSignal01;
	
/*********************************
 * GFX Image Asset
 * Name:   CellSignal02
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CellSignal02;
	
/*********************************
 * GFX Image Asset
 * Name:   CellSignal03
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CellSignal03;
	
/*********************************
 * GFX Image Asset
 * Name:   CellSignal04
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CellSignal04;
	
/*********************************
 * GFX Image Asset
 * Name:   CellSignal05
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset CellSignal05;
	
/*********************************
 * GFX Image Asset
 * Name:   BatteryExtremelyLow
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset BatteryExtremelyLow;
	
/*********************************
 * GFX Image Asset
 * Name:   BatteryFull
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset BatteryFull;
	
/*********************************
 * GFX Image Asset
 * Name:   BatteryHalf
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset BatteryHalf;
	
/*********************************
 * GFX Image Asset
 * Name:   BatteryLow
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset BatteryLow;
	
/*********************************
 * GFX Image Asset
 * Name:   BatteryOneQuarter
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset BatteryOneQuarter;
	
/*********************************
 * GFX Image Asset
 * Name:   BatteryThreeQuarter
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset BatteryThreeQuarter;
	
/*********************************
 * GFX Image Asset
 * Name:   BatteryCharging
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset BatteryCharging;
	
/*********************************
 * GFX Image Asset
 * Name:   WifiGood
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset WifiGood;
	
/*********************************
 * GFX Image Asset
 * Name:   WifiMedium
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset WifiMedium;
	
/*********************************
 * GFX Image Asset
 * Name:   WifiStrong
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset WifiStrong;
	
/*********************************
 * GFX Image Asset
 * Name:   WifiWeak
 * Size:   30x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset WifiWeak;
	
/*********************************
 * GFX Image Asset
 * Name:   chevron_down
 * Size:   120x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset chevron_down;
	
/*********************************
 * GFX Image Asset
 * Name:   chevron_up
 * Size:   120x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset chevron_up;
	
/*********************************
 * GFX Image Asset
 * Name:   AC_Both
 * Size:   60x60 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset AC_Both;
	
/*********************************
 * GFX Image Asset
 * Name:   AC_Face
 * Size:   60x60 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset AC_Face;
	
/*********************************
 * GFX Image Asset
 * Name:   AC_Feet
 * Size:   60x60 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset AC_Feet;
	
/*********************************
 * GFX Image Asset
 * Name:   AC_Intake
 * Size:   60x60 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset AC_Intake;
	
/*********************************
 * GFX Image Asset
 * Name:   AC_Loop
 * Size:   60x60 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset AC_Loop;
	
/*********************************
 * GFX Image Asset
 * Name:   Defrost
 * Size:   60x60 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Defrost;
	
/*********************************
 * GFX Image Asset
 * Name:   TrayLeft
 * Size:   30x272 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset TrayLeft;
	
/*********************************
 * GFX Image Asset
 * Name:   LidArrowLeft
 * Size:   7x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset LidArrowLeft;
	
/*********************************
 * GFX Image Asset
 * Name:   LidArrowRight
 * Size:   7x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset LidArrowRight;
	
/*********************************
 * GFX Image Asset
 * Name:   TrayLeftPress
 * Size:   30x272 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset TrayLeftPress;
	
/*********************************
 * GFX Image Asset
 * Name:   TrayRight
 * Size:   30x272 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset TrayRight;
	
/*********************************
 * GFX Image Asset
 * Name:   TrayRightPress
 * Size:   30x272 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset TrayRightPress;
	
/*********************************
 * GFX Image Asset
 * Name:   PlainButton
 * Size:   60x62 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PlainButton;
	
/*********************************
 * GFX Image Asset
 * Name:   Trunk
 * Size:   50x50 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Trunk;
	
/*********************************
 * GFX Image Asset
 * Name:   mchp_logo
 * Size:   120x28 pixels
 * Mode:   RGB_888
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset mchp_logo;
	
/*********************************
 * GFX Image Asset
 * Name:   OvalButton
 * Size:   110x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset OvalButton;
	
/*********************************
 * GFX Image Asset
 * Name:   OvalButtonPress
 * Size:   110x30 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset OvalButtonPress;
	
/*********************************
 * GFX Image Asset
 * Name:   PhoneIcon
 * Size:   20x20 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PhoneIcon;
	
/*********************************
 * GFX Image Asset
 * Name:   cover1
 * Size:   120x120 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset cover1;
	
/*********************************
 * GFX Image Asset
 * Name:   cover10
 * Size:   120x120 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset cover10;
	
/*********************************
 * GFX Image Asset
 * Name:   cover2
 * Size:   120x120 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset cover2;
	
/*********************************
 * GFX Image Asset
 * Name:   cover3
 * Size:   120x120 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset cover3;
	
/*********************************
 * GFX Image Asset
 * Name:   cover4
 * Size:   120x120 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset cover4;
	
/*********************************
 * GFX Image Asset
 * Name:   cover5
 * Size:   120x120 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset cover5;
	
/*********************************
 * GFX Image Asset
 * Name:   cover6
 * Size:   120x120 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset cover6;
	
/*********************************
 * GFX Image Asset
 * Name:   cover7
 * Size:   120x120 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset cover7;
	
/*********************************
 * GFX Image Asset
 * Name:   cover8
 * Size:   120x120 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset cover8;
	
/*********************************
 * GFX Image Asset
 * Name:   cover9
 * Size:   120x120 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset cover9;
	
/*********************************
 * GFX Image Asset
 * Name:   NextTrack
 * Size:   60x52 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset NextTrack;
	
/*********************************
 * GFX Image Asset
 * Name:   PlayPause
 * Size:   60x46 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PlayPause;
	
/*********************************
 * GFX Image Asset
 * Name:   Shuffle
 * Size:   60x41 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Shuffle;
	
/*********************************
 * GFX Image Asset
 * Name:   Minus
 * Size:   60x60 pixels
 * Mode:   INDEX_4
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Minus;
	
/*********************************
 * GFX Image Asset
 * Name:   Plus
 * Size:   60x60 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Plus;
	
/*********************************
 * GFX Image Asset
 * Name:   VolumeIcon
 * Size:   30x16 pixels
 * Mode:   INDEX_4
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset VolumeIcon;
	
/*********************************
 * GFX Image Asset
 * Name:   PhoneSmall
 * Size:   26x40 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PhoneSmall;
	
/*********************************
 * GFX Image Asset
 * Name:   BluetoothLogoSmall
 * Size:   30x40 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset BluetoothLogoSmall;
	
/*********************************
 * GFX Image Asset
 * Name:   ChevronSmall
 * Size:   29x34 pixels
 * Mode:   INDEX_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset ChevronSmall;
	
/*********************************
 * GFX Image Asset
 * Name:   PlusSmall
 * Size:   30x30 pixels
 * Mode:   INDEX_4
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset PlusSmall;
	
/*********************************
 * GFX Image Asset
 * Name:   HomeButton
 * Size:   65x67 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset HomeButton;
	
/*********************************
 * GFX Image Asset
 * Name:   microchip_button
 * Size:   60x62 pixels
 * Mode:   RGB_565
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset microchip_button;
	
/*********************************
 * GFX Image Asset
 * Name:   info_text_en
 * Size:   480x384 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset info_text_en;
	
/*********************************
 * GFX Image Asset
 * Name:   Background
 * Size:   128x188 pixels
 * Mode:   INDEX_4
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset Background;
	
/*********************************
 * GFX Image Asset
 * Name:   ChargeMap
 * Size:   1820x1024 pixels
 * Mode:   RGB_888
 * Format: JPEG
 ***********************************/
extern GFXU_ImageAsset ChargeMap;
	
/*****************************************************************************
 * MPLAB Harmony Graphics Palette Assets
 *****************************************************************************/
/*********************************
 * GFX Palette Asset
 * Name:   MicrochipLogo_palette
 * Colors: 227
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset MicrochipLogo_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   Bluetooth_palette
 * Colors: 61
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset Bluetooth_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   Chargers_palette
 * Colors: 67
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset Chargers_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   Fan_palette
 * Colors: 60
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset Fan_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   Music_palette
 * Colors: 58
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset Music_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   Phone_palette
 * Colors: 35
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset Phone_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   CellSignal01_palette
 * Colors: 24
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset CellSignal01_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   CellSignal02_palette
 * Colors: 21
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset CellSignal02_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   CellSignal03_palette
 * Colors: 28
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset CellSignal03_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   CellSignal04_palette
 * Colors: 20
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset CellSignal04_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   CellSignal05_palette
 * Colors: 56
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset CellSignal05_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   BatteryExtremelyLow_palette
 * Colors: 33
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset BatteryExtremelyLow_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   BatteryFull_palette
 * Colors: 43
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset BatteryFull_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   BatteryHalf_palette
 * Colors: 33
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset BatteryHalf_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   BatteryLow_palette
 * Colors: 19
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset BatteryLow_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   BatteryOneQuarter_palette
 * Colors: 26
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset BatteryOneQuarter_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   BatteryThreeQuarter_palette
 * Colors: 38
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset BatteryThreeQuarter_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   BatteryCharging_palette
 * Colors: 46
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset BatteryCharging_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   WifiGood_palette
 * Colors: 49
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset WifiGood_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   WifiMedium_palette
 * Colors: 40
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset WifiMedium_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   WifiStrong_palette
 * Colors: 52
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset WifiStrong_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   WifiWeak_palette
 * Colors: 26
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset WifiWeak_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   chevron_down_palette
 * Colors: 60
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset chevron_down_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   AC_Both_palette
 * Colors: 59
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset AC_Both_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   AC_Face_palette
 * Colors: 52
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset AC_Face_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   AC_Feet_palette
 * Colors: 55
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset AC_Feet_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   AC_Intake_palette
 * Colors: 48
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset AC_Intake_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   AC_Loop_palette
 * Colors: 50
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset AC_Loop_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   Defrost_palette
 * Colors: 57
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset Defrost_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   TrayLeft_palette
 * Colors: 26
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset TrayLeft_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   LidArrowLeft_palette
 * Colors: 27
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset LidArrowLeft_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   TrayLeftPress_palette
 * Colors: 44
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset TrayLeftPress_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   PlainButton_palette
 * Colors: 73
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset PlainButton_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   Trunk_palette
 * Colors: 85
 * Format: RGB_888
 ***********************************/
extern GFXU_PaletteAsset Trunk_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   OvalButton_palette
 * Colors: 28
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset OvalButton_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   OvalButtonPress_palette
 * Colors: 43
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset OvalButtonPress_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   PhoneIcon_palette
 * Colors: 34
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset PhoneIcon_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   NextTrack_palette
 * Colors: 56
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset NextTrack_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   PlayPause_palette
 * Colors: 52
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset PlayPause_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   Shuffle_palette
 * Colors: 52
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset Shuffle_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   Minus_palette
 * Colors: 10
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset Minus_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   Plus_palette
 * Colors: 19
 * Format: RGB_888
 ***********************************/
extern GFXU_PaletteAsset Plus_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   VolumeIcon_palette
 * Colors: 10
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset VolumeIcon_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   PhoneSmall_palette
 * Colors: 22
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset PhoneSmall_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   BluetoothLogoSmall_palette
 * Colors: 52
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset BluetoothLogoSmall_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   ChevronSmall_palette
 * Colors: 22
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset ChevronSmall_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   PlusSmall_palette
 * Colors: 8
 * Format: RGB_565
 ***********************************/
extern GFXU_PaletteAsset PlusSmall_palette;
	
/*********************************
 * GFX Palette Asset
 * Name:   Background_palette
 * Colors: 8
 * Format: RGB_888
 ***********************************/
extern GFXU_PaletteAsset Background_palette;
	
/*****************************************************************************
 * MPLAB Harmony Graphics Font Assets
 *****************************************************************************/
/*********************************
 * GFX Font Asset
 * Name:         NotoSans_Bold
 * Height:       24
 * Style:        Antialias
 * Glyph Count:  32
 * Range Count:  13
 * Glyph Ranges: 0x20
			     0x30-0x3A
			     0x41-0x43
			     0x47-0x48
			     0x4C-0x4D
			     0x50
			     0x61
			     0x63
			     0x65
			     0x68-0x69
			     0x6D-0x70
			     0x72-0x73
			     0x79
 ***********************************/
extern GFXU_FontAsset NotoSans_Bold;
	
/*********************************
 * GFX Font Asset
 * Name:         NotoSans_Bold_Small
 * Height:       17
 * Style:        Bold, Antialias
 * Glyph Count:  17
 * Range Count:  12
 * Glyph Ranges: 0x20
			     0x2B
			     0x31-0x32
			     0x34-0x35
			     0x3A
			     0x41
			     0x44-0x45
			     0x54
			     0x69
			     0x6B
			     0x6D-0x6E
			     0x73-0x74
 ***********************************/
extern GFXU_FontAsset NotoSans_Bold_Small;
	
/*********************************
 * GFX Font Asset
 * Name:         NotoSans_Regular
 * Height:       23
 * Style:        Bold, Antialias
 * Glyph Count:  42
 * Range Count:  19
 * Glyph Ranges: 0x20
			     0x2E
			     0x30-0x39
			     0x43-0x44
			     0x46-0x47
			     0x4D-0x50
			     0x52-0x53
			     0x55
			     0x59
			     0x5C
			     0x61
			     0x63
			     0x65
			     0x67-0x69
			     0x6B-0x6C
			     0x6E-0x6F
			     0x72-0x74
			     0x77-0x79
			     0xB0
 ***********************************/
extern GFXU_FontAsset NotoSans_Regular;
	
/*********************************
 * GFX Font Asset
 * Name:         NotoSans_Regular_Large
 * Height:       39
 * Style:        Antialias
 * Glyph Count:  26
 * Range Count:  11
 * Glyph Ranges: 0x20
			     0x23
			     0x2A
			     0x30-0x39
			     0x44
			     0x46
			     0x61
			     0x64-0x65
			     0x6D-0x6F
			     0x72-0x75
			     0x2190
 ***********************************/
extern GFXU_FontAsset NotoSans_Regular_Large;
	
/*********************************
 * GFX Font Asset
 * Name:         NotoSans_Regular_Small
 * Height:       14
 * Style:        Antialias
 * Glyph Count:  26
 * Range Count:  1
 * Glyph Ranges: 0x41-0x5A
 ***********************************/
extern GFXU_FontAsset NotoSans_Regular_Small;
	
/*****************************************************************************
 * MPLAB Harmony Graphics String Table
 *****************************************************************************/
/*********************************
 * GFX String Table
 * Name:         stringTable
 * Encoding:     UTF8
 * Languages:    default
 * String Count: 46
 ***********************************/
// language IDs
#define language_default    0

// string IDs
#define string_Slogan    0
#define string_String_ACSync    1
#define string_String_ACTemp    2
#define string_String_AlphabetEight    3
#define string_String_AlphabetFive    4
#define string_String_AlphabetFour    5
#define string_String_AlphabetNine    6
#define string_String_AlphabetSeven    7
#define string_String_AlphabetSix    8
#define string_String_AlphabetThree    9
#define string_String_AlphabetTwo    10
#define string_String_AlphabetZero    11
#define string_String_Backspace    12
#define string_String_ConnectPhone    13
#define string_String_Contacts1    14
#define string_String_Contacts2    15
#define string_String_Contacts3    16
#define string_String_Contacts4    17
#define string_String_Contacts5    18
#define string_String_Contacts6    19
#define string_String_Distance    20
#define string_String_ETA    21
#define string_String_Eight    22
#define string_String_Features    23
#define string_String_Five    24
#define string_String_Four    25
#define string_String_GPUOff    26
#define string_String_GPUOn    27
#define string_String_Nine    28
#define string_String_Numbers    29
#define string_String_One    30
#define string_String_PixelTwo    31
#define string_String_Plus    32
#define string_String_Pound    33
#define string_String_Seven    34
#define string_String_Six    35
#define string_String_Space    36
#define string_String_Star    37
#define string_String_TempCelcius    38
#define string_String_TempValues    39
#define string_String_Three    40
#define string_String_Time    41
#define string_String_TravelTime    42
#define string_String_Two    43
#define string_String_Zero    44
#define string_TitleString    45
 
extern GFXU_StringTableAsset stringTable;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* GFX_ASSETS_H */

