/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Implementation File

  File Name:
    libaria_events.c

  Summary:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated implementation from the MPLAB Harmony
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

//CUSTOM CODE - DO NOT REMOVE OR MODIFY!!
#include "app.h"
//END OF CUSTOM CODE

#include "gfx/libaria/libaria_events.h"

// ButtonWidget_SwitchCity - ReleasedEvent
void ButtonWidget_SwitchCity_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    app_cycleLanguage();
}

// ButtonWidget_SwitchTemp - ReleasedEvent
void ButtonWidget_SwitchTemp_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    app_toggleDisplay();
}

// ButtonWidget_SwitchHumidity - ReleasedEvent
void ButtonWidget_SwitchHumidity_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    app_toggleDisplay();
}

// ButtonWidget_Hourly - ReleasedEvent
void ButtonWidget_Hourly_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    app_displayHourly();
}

// ButtonWidget_Daily - ReleasedEvent
void ButtonWidget_Daily_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    app_displayDaily();
}

// ButtonWidget_City - ReleasedEvent
void ButtonWidget_City_ReleasedEvent(laButtonWidget* btn)
{
    // SwitchLanguage
    app_cycleLanguage();
}





