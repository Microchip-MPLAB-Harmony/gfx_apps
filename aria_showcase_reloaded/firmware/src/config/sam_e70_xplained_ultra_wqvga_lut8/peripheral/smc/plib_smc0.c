/*******************************************************************
  Company:
    Microchip Technology Inc.
    Memory System Service SMC Initialization File

  File Name:
    plib_smc0.c

  Summary:
    Static Memory Controller (SMC).
    This file contains the source code to initialize the SMC controller

  Description:
    SMC configuration interface
    The SMC System Memory interface provides a simple interface to manage 8-bit and 16-bit
    parallel devices.

  *******************************************************************/

/*******************************************************************************
Copyright (c) 2017-18 released Microchip Technology Inc.  All rights reserved.

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
#include "plib_smc0.h"
#include "device.h"


/* Function:
    void SMC0_Initialize( void )

  Summary:
    Initializes hardware and data for the given instance of the SMC module.

  Description:
    This function initializes the SMC timings according to the external parralel device requirements.

  Returns:
  None.
 */

void SMC0_Initialize( void )
{


    /* Chip Select CS0 Timings */
    /* Setup SMC SETUP register */
    SMC_REGS->SMC_CS_NUMBER[0].SMC_SETUP= SMC_SETUP_NWE_SETUP(1) | SMC_SETUP_NCS_WR_SETUP(0) | SMC_SETUP_NRD_SETUP(16) | SMC_SETUP_NCS_RD_SETUP(16);

    /* Setup SMC CYCLE register */
    SMC_REGS->SMC_CS_NUMBER[0].SMC_CYCLE= SMC_CYCLE_NWE_CYCLE(6) | SMC_CYCLE_NRD_CYCLE(3);

    /* Setup SMC_PULSE register */
    SMC_REGS->SMC_CS_NUMBER[0].SMC_PULSE= SMC_PULSE_NWE_PULSE(6) | SMC_PULSE_NCS_WR_PULSE(6) | SMC_PULSE_NRD_PULSE(16) | SMC_PULSE_NCS_RD_PULSE(16);

    /* Setup SMC MODE register */
    SMC_REGS->SMC_CS_NUMBER[0].SMC_MODE= SMC_MODE_EXNW_MODE_DISABLED    \
                                           | SMC_MODE_READ_MODE_Msk  | SMC_MODE_DBW_16_BIT | SMC_MODE_BAT_BYTE_SELECT;





} /* SMC0_Initialize */

/*******************************************************************************
 End of File
*/
