/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Definitions Header

  File Name:
    libaria_macros.h

  Summary:
    Build-time generated definitions header based on output by the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated definitions header based on output by the MPLAB Harmony
    Graphics Composer.

    Created with MPLAB Harmony Version 3.0
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
// DOM-IGNORE-END

#ifndef _LIBARIA_INIT_H
#define _LIBARIA_INIT_H

#include "gfx/libaria/libaria.h"
#include "gfx/libaria/libaria_events.h"

#include "gfx/gfx_assets.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

#define LIBARIA_SCREEN_COUNT   7

// reference IDs for generated libaria screens
// screen "load_screen"
#define load_screen_ID    3

// screen "main_screen"
#define main_screen_ID    1

// screen "splash_screen"
#define splash_screen_ID    0

// screen "stage_screen"
#define stage_screen_ID    2

// screen "store_screen"
#define store_screen_ID    6

// screen "test_screen"
#define test_screen_ID    5

// screen "test_screen_buttons"
#define test_screen_buttons_ID    4



extern laScheme defaultScheme;
extern laScheme TouchTestScheme;
extern laImageWidget* ImageWidget1;
extern laImageWidget* ImageWidget2;
extern laWidget* PanelWidget3;
extern laImageWidget* ImageWidget3;
extern laImageWidget* ImageWidget4;
extern laLabelWidget* LabelWidget1;
extern laImageWidget* ImageWidget;
extern laButtonWidget* mainLoadButton;
extern laButtonWidget* mainTestButton;
extern laImageWidget* ImageWidget;
extern laImageWidget* ImageWidget;
extern laImageWidget* ImageWidget5;
extern laImageWidget* ImageWidget6;
extern laProgressBarWidget* stageProgressBar;
extern laLabelWidget* LabelWidget10;
extern laButtonWidget* ButtonWidget19;
extern laLabelWidget* LabelWidget26;
extern laImageWidget* ImageWidget28;
extern laImageWidget* ImageWidget35;
extern laButtonWidget* stageButton;
extern laRadioButtonWidget* stageProgramRadioButton;
extern laRadioButtonWidget* stageSDCardRadioButton;
extern laRadioButtonWidget* stageUSBRadioButton;
extern laRadioButtonWidget* stagePCRadioButton;
extern laButtonWidget* stageSDCardButton;
extern laButtonWidget* stagePCButton;
extern laButtonWidget* stageProgramButton;
extern laButtonWidget* stageUsbButton;
extern laButtonWidget* stageNextButton;
extern laImageWidget* ImageWidget8;
extern laImageWidget* ImageWidget10;
extern laButtonWidget* loadButton;
extern laProgressBarWidget* loadProgressBar;
extern laLabelWidget* LabelWidget13;
extern laButtonWidget* ButtonWidget14;
extern laLabelWidget* LabelWidget15;
extern laRadioButtonWidget* loadProgramRadioButton;
extern laRadioButtonWidget* loadSDCardRadioButton;
extern laRadioButtonWidget* loadUSBRadioButton;
extern laRadioButtonWidget* loadPCRadioButton;
extern laButtonWidget* loadProgramButton;
extern laButtonWidget* loadSDCardButton;
extern laButtonWidget* loadPCButton;
extern laButtonWidget* loadUSBBUtton;
extern laButtonWidget* loadNextButton;
extern laKeyPadWidget* KeyPadWidget2;
extern laButtonWidget* ButtonWidget3;
extern laButtonWidget* ButtonWidget4;
extern laLabelWidget* LabelWidget6;
extern laTouchTestWidget* TouchTestWidget25;
extern laButtonWidget* ButtonWidget20;
extern laLabelWidget* LabelWidget32;
extern laButtonWidget* testStoreButton;
extern laButtonWidget* ButtonWidget5;
extern laProgressBarWidget* storeProgressBar;
extern laButtonWidget* ButtonWidget21;
extern laButtonWidget* storeSaveButton;
extern laImageWidget* ImageWidget29;
extern laLabelWidget* LabelWidget30;
extern laImageWidget* ImageWidget34;
extern laButtonWidget* storeDoneButton;


int32_t libaria_initialize(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // _LIBARIA_INIT_H
/*******************************************************************************
 End of File
*/
