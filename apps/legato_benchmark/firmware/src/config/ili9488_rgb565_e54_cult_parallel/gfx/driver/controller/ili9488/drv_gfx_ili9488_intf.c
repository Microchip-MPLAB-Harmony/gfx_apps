// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
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

/*******************************************************************************
  MPLAB Harmony Generated Driver Implementation File

  File Name:
    drv_gfx_ili9488_intf.c

  Summary:
    Implements DBIB parallel interface for the ILI9488

  Description:
    Implements DBIB parallel interface for the ILI9488. 

    Created with MPLAB Harmony Version 3.0
 *******************************************************************************/

#include "definitions.h"

#include "drv_gfx_ili9488_cmd_defs.h"
#include "drv_gfx_ili9488_common.h"

#include "gfx/interface/drv_gfx_disp_intf.h"

#define ILI9488_NCSAssert(intf)   GFX_Disp_Intf_PinControl(intf, \
                                    GFX_DISP_INTF_PIN_CS, \
                                    GFX_DISP_INTF_PIN_CLEAR)

#define ILI9488_NCSDeassert(intf) GFX_Disp_Intf_PinControl(intf, \
                                    GFX_DISP_INTF_PIN_CS, \
                                    GFX_DISP_INTF_PIN_SET)

//Width of data bus
typedef uint8_t DBUS_WIDTH_T;

uint8_t ContextHandle = 0;
typedef enum
{
	LCDEBI_STATUS_NO_TRANSFER = 0,
	LCDEBI_STATUS_SERVICE_TRANSFER,
	LCDEBI_STATUS_DATA_TRANSFER_REGISTERS_PHASE,
	LCDEBI_STATUS_DATA_TRANSFER_DATA_PHASE
}LCDEBI_TRANSFER_STATUS_TYPE;

typedef struct
{
	uint32_t data_buffer_size;
	uint8_t *data_buffer_ptr;
	uint8_t partial_frames;
} EBI_TRANSFER_FIFO_TYPE;

static volatile LCDEBI_TRANSFER_STATUS_TYPE Ebi_Transfer_Status;
static EBI_TRANSFER_FIFO_TYPE Ebi_Transfer_Fifo;
#define DMA_LCD_CHANNEL_DATA_TRANSFER DMAC_CHANNEL_0
#define DATABUS_PTR (&(PORT_REGS->GROUP[2].PORT_OUT))

static void LcdEbi_TransferCompleteCallback(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle);
void LcdEbi_SendOnlyDataBuffer(uint8_t * data_buffer, uint32_t data_buffer_size);
void LcdEbi_SendServiceAndDataBuffer(uint8_t *service_buffer,
                                     uint8_t service_buffer_size,
                                     uint8_t * data_buffer,
                                     uint32_t data_buffer_size);
void LcdEBi_DisableWRnPin(void);
void LcdEBi_EnableWRnPin(void);


/** 
  Function:
    static int ILI9488_Intf_Read(struct ILI9488_DRV *drv, 
                                 uint8_t cmd, 
                                 uint8_t *data,
                                 int bytes)

  Summary:
    Sends read command and returns response from the ILI9488 device.

  Description:
    This function will do a write operation over the parallel interface to send 
    the read command to the ILI9488, and then do a read operation to read the 
    response.

  Parameters:
    drv         - ILI9488 driver handle
    cmd         - Read command
    data        - Buffer to store read data
    bytes       - Number of bytes to read
 
Returns:
    * 0       - Operation successful
    * -1       - Operation failed


 */
static int ILI9488_Intf_Read(struct ILI9488_DRV *drv,
                             uint8_t cmd,
                             uint8_t *data,
                             int bytes) 
{
    GFX_Disp_Intf intf;
    int retval = -1;

    if ((!drv) || (!data) || (bytes <= 0))
        return -1;

    intf = (GFX_Disp_Intf) drv->port_priv;
    
    ILI9488_NCSAssert(intf);

    retval = GFX_Disp_Intf_Write(intf, &cmd, 1);
    if (retval == -1)
    {
        ILI9488_NCSDeassert(intf);
        return -1;
    }
    
    retval = GFX_Disp_Intf_ReadData(intf, data, bytes);
    
    ILI9488_NCSDeassert(intf);

    return retval;
}

/** 
  Function:
    int ILI9488_Intf_WriteCmd(struct ILI9488_DRV *drv,
                              uint8_t cmd,
                              uint8_t *parms,
                              int num_parms)

  Summary:
    Sends write command and parameters to the ILI9488 device.

  Description:
    This function will do a write operation to send the write command 
    and its parameters to the ILI9488.


  Parameters:
    drv         - ILI9488 driver handle
    cmd         - Read command
    parms       - Pointer to array of 8-bit parameters
    bytes       - Number of command parameters
 
Returns:
    * 0       - Operation successful
    * -1       - Operation failed

 
 */
int ILI9488_Intf_WriteCmd(struct ILI9488_DRV *drv,
                          uint8_t cmd,
                          uint8_t *parms,
                          int num_parms) 
{
    int returnValue = 0;
//    GFX_Disp_Intf intf;

    if (!drv)
        return -1;

//    intf = (GFX_Disp_Intf ) drv->port_priv;
    
    // Write the command and parameters
//    returnValue = GFX_Disp_Intf_WriteCommandParm(intf, cmd, parms, num_parms);
    
    LcdEbi_SendServiceAndDataBuffer(&cmd, 1, parms, num_parms);
   
    return returnValue;
}

/** 
  Function:
    int ILI9488_Intf_WritePixels(struct ILI9488_DRV *drv,
                                 uint32_t start_x,
                                 uint32_t start_y,
                                 uint8_t *data,
                                 unsigned int num_pixels)

  Summary:
    Writes pixel data to ILI9488 GRAM from specified position.

  Description:
    This function will first write the start column, page information, then 
    write the pixel data to the ILI9488 GRAM.

  Parameters:
    drv             - ILI9488 driver handle
    start_x         - Start column position
    start_y         - Start page position
    data            - Array of 8-bit pixel data (8-bit/pixel RGB)
    num_pixels      - Number of pixels
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed

 */
int ILI9488_Intf_WritePixels(struct ILI9488_DRV *drv,
                             uint32_t start_x,
                             uint32_t start_y,
                             uint8_t *data,
                             unsigned int num_pixels)
{
    int returnValue = 0;
//    GFX_Disp_Intf intf;
    uint8_t buf[4];
    uint8_t cmd;
    
    if (!drv)
        return -1;
    
//    intf = (GFX_Disp_Intf) drv->port_priv;
    
//    ILI9488_NCSAssert(intf);
    
    //Set column
    buf[0] = (start_x >> 8);
    buf[1] = (start_x & 0xff);
    buf[2] = (((DRV_ILI9488_GetDisplayWidth() - 1) & 0xff00) >> 8);
    buf[3] = ((DRV_ILI9488_GetDisplayWidth() - 1) & 0xff);
//    returnValue = GFX_Disp_Intf_WriteCommandParm(intf,
//                                       ILI9488_CMD_COLUMN_ADDRESS_SET,
//                                       buf,
//                                       4);
//    if (0 != returnValue)
//    {
//        ILI9488_NCSDeassert(intf);
//        return -1;
//    }
    
    cmd = ILI9488_CMD_COLUMN_ADDRESS_SET;
    LcdEbi_SendServiceAndDataBuffer(&cmd, 1, buf, 4);

    //Set page
    buf[0] = (start_y >> 8);
    buf[1] = (start_y & 0xff);
    buf[2] = (((DRV_ILI9488_GetDisplayHeight() - 1) & 0xff00) >> 8);
    buf[3] = ((DRV_ILI9488_GetDisplayHeight() - 1) & 0xff);

    //    returnValue = GFX_Disp_Intf_WriteCommandParm(intf,
//                                       ILI9488_CMD_PAGE_ADDRESS_SET,
//                                       buf,
//                                       4);
//    if (0 != returnValue)
//    {
//        ILI9488_NCSDeassert(intf);
//        return -1;
//    }
    
    cmd = ILI9488_CMD_PAGE_ADDRESS_SET;
    LcdEbi_SendServiceAndDataBuffer(&cmd, 1, buf, 4);

//    returnValue = GFX_Disp_Intf_WriteCommandParm(intf,
//                                       ILI9488_CMD_MEMORY_WRITE,
//                                       (uint8_t *) data,
//                                       num_pixels * 2);
    
    cmd = ILI9488_CMD_MEMORY_WRITE;
    LcdEbi_SendServiceAndDataBuffer(&cmd, 1, data, num_pixels * 2);

//    ILI9488_NCSDeassert(intf);

    return returnValue;
}

/** 
  Function:
    int ILI9488_Intf_ReadPixels(struct ILI9488_DRV *drv,
                                uint32_t x,
                                uint32_t y,
                                uint16_t *value,
                                unsigned int num_pixels)

  Summary:
    Read pixel data from specified position in ILI9488 GRAM.

  Description:
    This function will first write the start column, page information, then
    read the pixel data from the ILI9488 GRAM.

  Parameters:
    drv             - ILI9488 driver handle
    x               - Column position
    y               - Page position
    value           - Value to store the read pixel color (8-bit/pixel RGB)
    num_pixels      - Number of pixels to read
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed

 */
int ILI9488_Intf_ReadPixels(struct ILI9488_DRV *drv,
                            uint32_t x,
                            uint32_t y,
                            uint8_t *value,
                            unsigned int num_pixels)
{
    int returnValue = -1;
    GFX_Disp_Intf intf;
    uint8_t buf[4];
    unsigned int i;
    DBUS_WIDTH_T pixel[3] = {0};

    if (!drv)
        return -1;

    intf = (GFX_Disp_Intf) drv->port_priv;
    
    ILI9488_NCSAssert(intf);
    
    //Set column
    buf[0] = ((x & 0xff00) >> 8);
    buf[1] = (x & 0xff);
    buf[2] = (((DRV_ILI9488_GetDisplayWidth() - 1) & 0xff00) >> 8);
    buf[3] = ((DRV_ILI9488_GetDisplayWidth() - 1) & 0xff);
    returnValue = GFX_Disp_Intf_WriteCommandParm(intf,
                                       ILI9488_CMD_COLUMN_ADDRESS_SET,
                                       buf,
                                       4);
    if (0 != returnValue)
    {
        ILI9488_NCSDeassert(intf);    
        return -1;
    }

    //Set page
    buf[0] = ((y & 0xff00) >> 8);
    buf[1] = (y & 0xff);
    buf[2] = (((DRV_ILI9488_GetDisplayHeight() - 1) & 0xff00) >> 8);
    buf[3] = ((DRV_ILI9488_GetDisplayHeight() - 1) & 0xff);
    returnValue = GFX_Disp_Intf_WriteCommandParm(intf,
                                       ILI9488_CMD_PAGE_ADDRESS_SET,
                                       buf,
                                       4);
    if (0 != returnValue)
    {
        ILI9488_NCSAssert(intf);        
        return -1;
    }

    returnValue = GFX_Disp_Intf_WriteCommand(intf, ILI9488_CMD_MEMORY_READ);
    if (0 != returnValue)
    {
        ILI9488_NCSDeassert(intf);
        return -1;
    }
    
    // Read the dummy byte
    returnValue = GFX_Disp_Intf_ReadData(intf, pixel, 1);
    if (0 != returnValue)
    {
        ILI9488_NCSDeassert(intf);        
        return -1;
    }    

    // Read the pixel data
    for (i = 0; i < num_pixels; i++)
    {
        // In 8-bit mode, each 8-bit read gets one color in RGB565 color mode.
        // Read 3 bytes to get R, G, and B.
        returnValue = GFX_Disp_Intf_ReadData(intf, pixel, 3);
        if (0 != returnValue)
        {
            ILI9488_NCSDeassert(intf);        
            return -1;
        }
        
        value[i * drv->bytesPerPixelBuffer] = (pixel[0] | (pixel[1] >> 5));
        value[(i * drv->bytesPerPixelBuffer) + 1] = 
                                    ((pixel[1] & 0x1c) << 3) | (pixel[2] >> 3);
    }

    ILI9488_NCSDeassert(intf);

    return 0;
}

/** 
  Function:
    int ILI9488_Intf_ReadCmd(struct ILI9488_DRV *drv, 
                             uint8_t cmd, 
                             uint8_t *data,
                             int bytes);

  Summary:
    Sends read command and reads response from ILI9488.

  Description:
    This function will fist write the the read command and then read back the 
    response from the ILI9488 GRAM.

  Parameters:
    drv             - ILI9488 driver handle
    cmd             - Read command
    data            - Buffer to store the read data to
    bytes           - Number of bytes to read
 
  Returns:
    * 0       Operation successful
    * -1       Operation failed
 
  Remarks:
    This function only supports 8-, 24- or 32-bit reads.

 */
int ILI9488_Intf_ReadCmd(struct ILI9488_DRV *drv,
                         uint8_t cmd,
                         uint8_t *data,
                         int bytes)
{
    int returnValue = -1;
    uint8_t buff[5];
    GFX_Disp_Intf intf;    

    //API supports only 8-, 24-, or 32-bit reads
    if ((!drv) || (!data) ||
        ((bytes != 1) && (bytes != 3) && (bytes != 4)))
        return -1;
    
    intf = (GFX_Disp_Intf) drv->port_priv;
    
    ILI9488_NCSAssert(intf);
    returnValue = ILI9488_Intf_Read(drv, cmd, buff, bytes + 1);
    ILI9488_NCSDeassert(intf);    
    
    
    return returnValue;
}

// *****************************************************************************

/** 
  Function:
    GFX_Result ILI9488_Intf_Open(ILI9488_DRV *drv)

  Summary:
    Opens the specified port to the ILI9488 device.

  Description:
    In SPI mode, this function will open the SPI port, allocate the port-specific
    data structures and set the port operation handler functions. When done 
    using the port, ILI9488_Intf_Close must be called to free up the data 
    structures and close the port.

  Parameters:
    drv         - ILI9488 driver handle
 
  Returns:
    * 0       - Operation successful
    * -1       - Operation failed

 */
int ILI9488_Intf_Open(ILI9488_DRV *drv)
{
    GFX_Disp_Intf intf;
    
    if (!drv)
        return -1;
    
    DMAC_ChannelCallbackRegister(DMA_LCD_CHANNEL_DATA_TRANSFER,
                                 LcdEbi_TransferCompleteCallback,
                                 (uintptr_t) &ContextHandle);
    
    //Set GPIO control for WR to high
    PORT_REGS->GROUP[1].PORT_DIRSET = (1 << 9);
    PORT_REGS->GROUP[1].PORT_OUTSET = (1 << 9);
    LcdEBi_DisableWRnPin();
    
    drv->port_priv = (void *) GFX_Disp_Intf_Open();
    
    intf = (GFX_Disp_Intf) drv->port_priv;

    ILI9488_NCSDeassert(intf);

    return 0;
}

/** 
  Function:
    void ILI9488_Intf_Close(ILI9488_DRV *drv)

  Summary:
    Closes the HW interface to the ILI9488 device.

  Description:
    This function will close the specified interface, free the port-specific
    data structures and unset the port operation handler functions.

  Parameters:
    drv         - ILI9488 driver handle
 
  Returns:
    None.

 */
void ILI9488_Intf_Close(ILI9488_DRV *drv) 
{
    GFX_Disp_Intf intf;
    
    if (!drv)
        return;

    intf = (GFX_Disp_Intf) drv->port_priv;
    
    ILI9488_NCSDeassert(intf);
    
    GFX_Disp_Intf_Close((GFX_Disp_Intf) drv->port_priv);

    drv->port_priv = NULL;
}

LCDEBI_TRANSFER_STATUS_TYPE Ebi_GetTransferStatus(void)
{
	return Ebi_Transfer_Status;
}

void LcdEbi_SendServiceAndDataBuffer(uint8_t *service_buffer,
                                     uint8_t service_buffer_size,
                                     uint8_t * data_buffer,
                                     uint32_t data_buffer_size)
{
    while (Ebi_GetTransferStatus() != LCDEBI_STATUS_NO_TRANSFER);
    
	/* Connect D/C pin to TC4 timer peripheral */
    GFX_DISP_INTF_PIN_RSDC_Clear();

	Ebi_Transfer_Status = LCDEBI_STATUS_DATA_TRANSFER_REGISTERS_PHASE;
	
	Ebi_Transfer_Fifo.data_buffer_ptr = data_buffer;
	Ebi_Transfer_Fifo.partial_frames = 1;
				
	for (uint8_t idx = 2; data_buffer_size > 0xFFFF; idx *= 2)
	{
		data_buffer_size /= 2;
		Ebi_Transfer_Fifo.partial_frames = idx;
	}
	
	Ebi_Transfer_Fifo.data_buffer_size = data_buffer_size;

    GFX_DISP_INTF_PIN_CS_Clear();
    GFX_DISP_INTF_PIN_RSDC_Clear();
    LcdEBi_EnableWRnPin();	
    
    DMAC_ChannelTransfer(DMA_LCD_CHANNEL_DATA_TRANSFER, (void*)service_buffer, (void*)DATABUS_PTR, service_buffer_size);        
    
    while (Ebi_GetTransferStatus() != LCDEBI_STATUS_NO_TRANSFER);
    
    GFX_DISP_INTF_PIN_CS_Set();
    LcdEBi_DisableWRnPin();    
}

void LcdEbi_SendOnlyDataBuffer(uint8_t * data_buffer, uint32_t data_buffer_size)
{
    while (Ebi_GetTransferStatus() != LCDEBI_STATUS_NO_TRANSFER)
    {}
    
	Ebi_Transfer_Status = LCDEBI_STATUS_DATA_TRANSFER_DATA_PHASE;
	
	Ebi_Transfer_Fifo.data_buffer_ptr = data_buffer;
	Ebi_Transfer_Fifo.partial_frames = 0;
	
	for (uint8_t idx = 2; data_buffer_size > 0xFFFF; idx *= 2)
	{
		data_buffer_size /= 2;
		Ebi_Transfer_Fifo.partial_frames = idx;
	}
	
	Ebi_Transfer_Fifo.data_buffer_size = data_buffer_size;

    /* Set D/C pin output value high to prepare data transfer */
    GFX_DISP_INTF_PIN_CS_Clear();
    GFX_DISP_INTF_PIN_RSDC_Set();
    LcdEBi_EnableWRnPin();	
    
    DMAC_ChannelTransfer(DMA_LCD_CHANNEL_DATA_TRANSFER, (void*)(Ebi_Transfer_Fifo.data_buffer_ptr), (void*)DATABUS_PTR, Ebi_Transfer_Fifo.data_buffer_size);  
    
    while (Ebi_GetTransferStatus() != LCDEBI_STATUS_NO_TRANSFER){}
    
    GFX_DISP_INTF_PIN_CS_Set();
    LcdEBi_DisableWRnPin();
}

static void LcdEbi_TransferCompleteCallback(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{	
	switch(Ebi_Transfer_Status)
	{
		default:
		case LCDEBI_STATUS_NO_TRANSFER:
			break;
			
		case LCDEBI_STATUS_SERVICE_TRANSFER:
			Ebi_Transfer_Status = LCDEBI_STATUS_NO_TRANSFER;
			break;
		
		case LCDEBI_STATUS_DATA_TRANSFER_REGISTERS_PHASE:
            /* Set D/C pin output value high to prepare data transfer */
            GFX_DISP_INTF_PIN_RSDC_Set();
            
			Ebi_Transfer_Fifo.partial_frames--;
            DMAC_ChannelTransfer(DMA_LCD_CHANNEL_DATA_TRANSFER, (void*)(Ebi_Transfer_Fifo.data_buffer_ptr), (void*)DATABUS_PTR, Ebi_Transfer_Fifo.data_buffer_size); 
			Ebi_Transfer_Status = LCDEBI_STATUS_DATA_TRANSFER_DATA_PHASE;
			break;
					
		case LCDEBI_STATUS_DATA_TRANSFER_DATA_PHASE:
			if (Ebi_Transfer_Fifo.partial_frames > 0)
			{
				Ebi_Transfer_Fifo.partial_frames--;
				Ebi_Transfer_Fifo.data_buffer_ptr += Ebi_Transfer_Fifo.data_buffer_size;
                DMAC_ChannelTransfer(DMA_LCD_CHANNEL_DATA_TRANSFER, (void*)(Ebi_Transfer_Fifo.data_buffer_ptr), (void*)DATABUS_PTR, Ebi_Transfer_Fifo.data_buffer_size); 
			}
			else
			{				
				Ebi_Transfer_Status = LCDEBI_STATUS_NO_TRANSFER;
                //Set pin to high
			}
			break;
	}
}

void LcdEBi_DisableWRnPin(void)
{
    //Disable MUXing
    PORT_REGS->GROUP[1].PORT_PINCFG[9] &= ~(0x1);
    //Output High
}

void LcdEBi_EnableWRnPin(void)
{
    //Enable MUXing
    PORT_REGS->GROUP[1].PORT_PINCFG[9] |= (0x1);
}
/* *****************************************************************************
 End of File
 */
