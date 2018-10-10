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





