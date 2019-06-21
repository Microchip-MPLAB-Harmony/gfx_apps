/*******************************************************************************
 Module for Microchip Graphics Library - Hardware Abstraction Layer

  Company:
    Microchip Technology Inc.

  File Name:
    drv_gfx_intf.h

  Summary:
    Contains 4-line SPI GFX interface driver definitions and interface prototypes.

  Description:
    Contains 4-line SPI GFX interface driver definitions and interface prototypes.
*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#ifndef _DRV_GFX_DISP_INTF_H    /* Guard against multiple inclusion */
#define _DRV_GFX_DISP_INTF_H

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stddef.h>

#define GFX_Disp_Intf    uint32_t

/** GFX_DISP_INTF_PIN

  Summary:
    Enum of GFX Intf pins.
    
*/
typedef enum
{
    GFX_DISP_INTF_PIN_CS,        //Chip Select
    GFX_DISP_INTF_PIN_WR,        //Write Strobe
    GFX_DISP_INTF_PIN_RD,        //Read Strobe
    GFX_DISP_INTF_PIN_RSDC,      //Register Select or Data/Command
} GFX_DISP_INTF_PIN;

/** GFX_DISP_INTF_PIN_VALUE

  Summary:
    Enum of GFX Intf pin values.
    
*/
typedef enum
{
    GFX_DISP_INTF_PIN_CLEAR = 0,
    GFX_DISP_INTF_PIN_SET = 1,
} GFX_DISP_INTF_PIN_VALUE;

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

/** 
  Function:
    GFX_Disp_Intf_Open(unsigned int index)

  Summary:
    Opens the interface to the graphics display

  Description:
    This opens the interface to the graphics display (e.g., SPI, parallel).

  Parameters:
    index       - port index
 
  Returns:
    * 0 if failed
*/
GFX_Disp_Intf GFX_Disp_Intf_Open(uint32_t index);

/** 
  Function:
    void GFX_Disp_Intf_Close()

  Summary:
    Closes the interface to the graphics display

  Description:

  Parameters:
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed
*/
void GFX_Disp_Intf_Close();

/** 
  Function:
    int32_t GFX_Disp_Intf_PinControl(GFX_INTF_PIN pin, GFX_INTF_PIN_VALUE value)

  Summary:
    Sets the value of the GFX control pin

  Description:

  Parameters:
    intf - the interface handle
    pin - the control pin
    value - the value
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed
*/
int32_t GFX_Disp_Intf_PinControl(GFX_DISP_INTF_PIN pin, GFX_DISP_INTF_PIN_VALUE value);

/** 
  Function:
    int32_t GFX_Disp_Intf_WriteCommand(uint8_t cmd)

  Summary:
    Asserts the RS/DCx control pin (LOW) and writes the 8-bit command

  Description:

  Parameters:
    intf - the interface handle
    cmd - the command
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed
*/
int32_t GFX_Disp_Intf_WriteCommand(uint8_t cmd);

/** 
  Function:
    int32_t GFX_Disp_Intf_WriteCommandParm(uint8_t cmd, uint8_t* parm, int num_parms)

  Summary:
    Writes a command and its parameters to the interface.

  Description:
    Asserts the RS/DCx control pin (LOW), writes the 8-bit command, 
    Deasserts the RS/DCx control pin (HIGH, writes the n-byte parameter)

  Parameters:
    intf - the interface handle
    cmd - the command
    parm - byte array containing the command parameters
    num_parms - the number for parameters
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed
*/
int32_t GFX_Disp_Intf_WriteCommandParm(uint8_t cmd, uint8_t* parm, int num_parms);

/** 
  Function:
    int32_t GFX_Disp_Intf_WriteData(uint8_t* data, int bytes)

  Summary:
    Deasserts the RS/DCx control pin (HIGH) and writes the byte stream to the interface

  Description:

  Parameters:
    intf - the interface handle
    data - the byte stream
    bytes - the number of bytes in the data stream
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed
*/
int32_t GFX_Disp_Intf_WriteData(uint8_t* data, int bytes);

/** 
  Function:
    int32_t GFX_Disp_Intf_WriteData16(uint16_t* data, int num)

  Summary:
    Deasserts the RS/DCx control pin (HIGH) and writes the data to the interface
    in 16-bit chunks. Interface must support 16-bit wide data transfers, otherwise
    will return -1

  Description:

  Parameters:
    intf - the interface handle
    data - the data to write
    num - the number of bytes in the data stream
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed or not supported
*/
int32_t GFX_Disp_Intf_WriteData16(uint16_t* data, int num);

/** 
  Function:
    int32_t GFX_Disp_Intf_ReadData(uint8_t* data, int bytes)

  Summary:
    Deasserts the RS/DCx control pin (HIGH) and reads a bytes from the interface

  Description:

  Parameters:
    intf - the interface handle
    data - the destination buffer
    bytes - the number of bytes to read
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed
*/
int32_t GFX_Disp_Intf_ReadData(uint8_t* data, int bytes);

/** 
  Function:
    int32_t GFX_Disp_Intf_ReadCommandData(uint8_t cmd, uint8_t* data, int num_data)

  Summary:
    Writes a byte command (cmd) to the interface and read num_data bytes from the interface
    RS/DCx control pin is asserted (LOW) when the cmd is sent, and deasserted (HIGH) when the data is read
    The RD strobe is asserted for each byte read.

  Description:

  Parameters:
    intf - the interface handle
    cmd - the 8-bit command to send
    data - the destination byte buffer
    bytes - the number of bytes to read
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed
*/
int32_t GFX_Disp_Intf_ReadCommandData(uint8_t cmd, uint8_t* data, int num_data);

/** 
  Function:
    int32_t GFX_Disp_Intf_ReadData16(uint16_t* data, int num)

  Summary:
    Deasserts the RS/DCx control pin (HIGH) and reads 16-bit data chunks from the 
    interface.

  Description:
    Interface must support 16-bit data reads, otherwise -1 will
    be returned.

  Parameters:
    intf - the interface handle
    data - the destination buffer
    bytes - the number of chunks to read
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed or not supported
*/
int32_t GFX_Disp_Intf_ReadData16(uint16_t* data, int num);

/** 
  Function:
    int32_t GFX_Disp_Intf_Write(uint8_t* data, int bytes)

  Summary:
    Writes the byte stream to the interface, control pins are not set

  Description:

  Parameters:
    intf - the interface handle
    data - the byte stream
    bytes - the number of bytes in the data stream
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed
*/
int32_t GFX_Disp_Intf_Write(uint8_t* data, int bytes);

/** 
  Function:
    int32_t GFX_Disp_Intf_Read(uint8_t* data, int bytes)

  Summary:
    Reads a byte stream from the interface, control pins are not set

  Description:

  Parameters:
    intf - the interface handle
    data - the byte stream
    bytes - the number of bytes in the data stream
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed
*/
int32_t GFX_Disp_Intf_Read(uint8_t* data, int bytes);

/** 
  Function:
    GFX_Disp_Intf_WriteDataByte(uint8_t data);

  Summary:
    Writes a single byte, RSDC control pin is set

  Description:

  Parameters:
    intf - the interface handle
    data - the byte stream
    bytes - the number of bytes in the data stream
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed
*/
int32_t GFX_Disp_Intf_WriteDataByte(uint8_t data);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _DRV_GFX_DISP_INTF_H */

/* *****************************************************************************
 End of File
 */
