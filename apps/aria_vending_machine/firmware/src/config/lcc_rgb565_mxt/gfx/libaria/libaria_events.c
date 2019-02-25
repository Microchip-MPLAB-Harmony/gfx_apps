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

#include "app.h"
#include "gfx/libaria/libaria_events.h"

// ButtonItem0 - ReleasedEvent
void ButtonItem0_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_ItemSelect(0);
}

// ButtonItem1 - ReleasedEvent
void ButtonItem1_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_ItemSelect(1);
}

// ButtonItem2 - ReleasedEvent
void ButtonItem2_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_ItemSelect(2);
}

// ButtonItem3 - ReleasedEvent
void ButtonItem3_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_ItemSelect(3);
}

// ButtonItem4 - ReleasedEvent
void ButtonItem4_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_ItemSelect(4);
}

// ButtonItem5 - ReleasedEvent
void ButtonItem5_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_ItemSelect(5);
}

// ButtonUp - ReleasedEvent
void ButtonUp_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_PageUp();
}

// ButtonDown - ReleasedEvent
void ButtonDown_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_PageDown();
}

// ButtonLanguage_Main - ReleasedEvent
void ButtonLanguage_Main_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_CycleLanguage();
}

// ButtonLanguage_Item - ReleasedEvent
void ButtonLanguage_Item_ReleasedEvent(laButtonWidget* btn)
{
    // Custom Action
    APP_CycleLanguage();
}

// ButtonMain_Item - ReleasedEvent
void ButtonMain_Item_ReleasedEvent(laButtonWidget* btn)
{
    // Show Screen (MainScreen) - Show Screen - MainScreen
    laContext_SetActiveScreen(MainScreen_ID);

    // Custom Action
    APP_GoToMain();
}





