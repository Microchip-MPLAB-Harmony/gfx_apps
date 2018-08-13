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

#define LIBARIA_SCREEN_COUNT   2

// reference IDs for generated libaria screens
// screen "MainScreen"
#define MainScreen_ID    1

// screen "SplashScreen"
#define SplashScreen_ID    0



extern laScheme Red;
extern laScheme MyScheme;
extern laScheme Blue;
extern laScheme Yellow;
extern laScheme Purple;
extern laScheme GrayScheme;
extern laScheme TitleBarScheme;
extern laScheme WhiteScheme;
extern laScheme TextBoxScheme;
extern laScheme Green;
extern laScheme TextWhite;
extern laScheme GradientScheme;
extern laImageWidget* ImageWidget1;
extern laImageWidget* ImageWidget2;
extern laWidget* PanelWidget3;
extern laImageWidget* ImageWidget3;
extern laImageWidget* ImageWidget4;
extern laImageWidget* ImageWidget9;
extern laLabelWidget* TimeLabel;
extern laLabelWidget* LabelWidget2;
extern laImageSequenceWidget* ImageSequenceWidget1;
extern laLabelWidget* MinuteLabel;
extern laButtonWidget* ButtonWidget2;
extern laLabelWidget* LabelWidget5;
extern laWidget* PanelWidget2;
extern laWidget* PanelWidget6;
extern laWidget* PanelWidget1;
extern laWidget* PanelWidget5;
extern laButtonWidget* ButtonWidget1;
extern laImageWidget* CloudIcon;
extern laImageWidget* ImageWidget10;
extern laLabelWidget* LabelWidget1;
extern laLabelWidget* LabelWidget3;
extern laLabelWidget* LabelWidget11;
extern laLabelWidget* LabelWidget12;
extern laImageWidget* ImageWidget5;
extern laLabelWidget* LabelWidget6;
extern laLabelWidget* LabelWidget8;
extern laLabelWidget* LabelWidget9;
extern laLabelWidget* LabelWidget10;


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
