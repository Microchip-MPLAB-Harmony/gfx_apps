/*******************************************************************************
  Board Support Package Header File.

  Company:
    Microchip Technology Inc.

  File Name:
    bsp.h

  Summary:
    Board Support Package Header File 

  Description:
    This file contains constants, macros, type definitions and function
    declarations 
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

#ifndef _BSP_H
#define _BSP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "device.h"

// *****************************************************************************
// *****************************************************************************
// Section: BSP Macros
// *****************************************************************************
// *****************************************************************************
/*** LED Macros for BSP_LED_3 ***/
#define BSP_LED_3_Toggle() (LATHINV = (1<<2))
#define BSP_LED_3_Get() ((PORTH >> 2) & 0x1)
#define BSP_LED_3_On() (LATHSET = (1<<2))
#define BSP_LED_3_Off() (LATHCLR = (1<<2))
/*** LED Macros for BSP_LED_D7 ***/
#define BSP_LED_D7_Toggle() (LATHINV = (1<<11))
#define BSP_LED_D7_Get() ((PORTH >> 11) & 0x1)
#define BSP_LED_D7_On() (LATHSET = (1<<11))
#define BSP_LED_D7_Off() (LATHCLR = (1<<11))
/*** LED Macros for BSP_LED_2 ***/
#define BSP_LED_2_Toggle() (LATHINV = (1<<1))
#define BSP_LED_2_Get() ((PORTH >> 1) & 0x1)
#define BSP_LED_2_On() (LATHSET = (1<<1))
#define BSP_LED_2_Off() (LATHCLR = (1<<1))
/*** LED Macros for BSP_LED_1 ***/
#define BSP_LED_1_Toggle() (LATHINV = (1<<0))
#define BSP_LED_1_Get() ((PORTH >> 0) & 0x1)
#define BSP_LED_1_On() (LATHSET = (1<<0))
#define BSP_LED_1_Off() (LATHCLR = (1<<0))
/*** LED Macros for BSP_LED_D6 ***/
#define BSP_LED_D6_Toggle() (LATHINV = (1<<6))
#define BSP_LED_D6_Get() ((PORTH >> 6) & 0x1)
#define BSP_LED_D6_On() (LATHSET = (1<<6))
#define BSP_LED_D6_Off() (LATHCLR = (1<<6))




// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void BSP_Initialize(void)

  Summary:
    Performs the necessary actions to initialize a board

  Description:
    This function initializes the LED and Switch ports on the board.  This
    function must be called by the user before using any APIs present on this
    BSP.

  Precondition:
    None.

  Parameters:
    None

  Returns:
    None.

  Example:
    <code>
    //Initialize the BSP
    BSP_Initialize();
    </code>

  Remarks:
    None
*/

void BSP_Initialize(void);

#endif // _BSP_H

/*******************************************************************************
 End of File
*/
