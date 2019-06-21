/*******************************************************************************
  MPLAB Harmony Generated Driver Implementation File

  File Name:
    drv_gfx_intf_spi4.c

  Summary:
    Implements the display interface driver over SPI

  Description:
    Implements the 4-line SPI interface driver

    Created with MPLAB Harmony Version 3.0
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

#include "driver/spi/drv_spi.h"

#include "drv_gfx_disp_intf.h"

/** SPI_TRANS_STATUS

  Summary:
    Enum type of SPI transaction status

 */
typedef enum 
{
    SPI_TRANS_IDLE,
    SPI_TRANS_CMD_WR_PENDING,
    SPI_TRANS_CMD_RD_PENDING,
    SPI_TRANS_DONE,
    SPI_TRANS_FAIL,
} GFX_DISP_INTF_SPI_TRANS_STATUS;

/** GFX_INTF_SPI

  Summary:
    Structure contains status and handles for SPI interface.
    
 */
typedef struct
{    
    /* SPI Device handle */
    DRV_HANDLE drvSPIHandle;
    
    /* Transfer handle */
    DRV_SPI_TRANSFER_HANDLE drvSPITransferHandle;
    
    /* SPI transaction status */
    volatile GFX_DISP_INTF_SPI_TRANS_STATUS drvSPITransStatus;    
} GFX_DISP_INTF_SPI;

static GFX_DISP_INTF_SPI intf;

/* ************************************************************************** */

/** 
  Function:
    static void GFX_Disp_Intf_CallBack(DRV_SPI_BUFFER_EVENT event, 
                                       DRV_SPI_BUFFER_HANDLE bufferHandle, 
                                       void * context )

  Summary:
    Callback function called by SPI driver to deliver events.

  Description:

    This callback will set the ILI9488 SPI driver's SPI transaction status 
    based on the event.


  Parameters:
    event           - SPI buffer event
    bufferHandle    - SPI buffer handle
    context         - SPI transaction context

  Returns:
    None

 */
static void GFX_Disp_Intf_CallBack(DRV_SPI_TRANSFER_EVENT event,
                                   DRV_SPI_TRANSFER_HANDLE bufferHandle,
                                   uintptr_t context)
{
    volatile GFX_DISP_INTF_SPI_TRANS_STATUS *status = 
                    ((GFX_DISP_INTF_SPI_TRANS_STATUS *) context);

   if (!status)
        return;

    switch (event) 
    {
        case DRV_SPI_TRANSFER_EVENT_COMPLETE:
        {
            *status = SPI_TRANS_DONE;
        
            break;
        }
        case DRV_SPI_TRANSFER_EVENT_ERROR:
        {
            *status = SPI_TRANS_FAIL;
        }
        default:
        {
            break;
        }
    }
}

GFX_Disp_Intf GFX_Disp_Intf_Open(uint32_t index)
{   
    intf.drvSPIHandle = DRV_SPI_Open(index, DRV_IO_INTENT_READWRITE);
    
    if (DRV_HANDLE_INVALID == intf.drvSPIHandle)
    {
        return -1;
    }

    DRV_SPI_TransferEventHandlerSet(intf.drvSPIHandle,
                                    GFX_Disp_Intf_CallBack,
                                    (uintptr_t)&intf.drvSPITransStatus );

    return (GFX_Disp_Intf)&intf;
}

void GFX_Disp_Intf_Close()
{
    DRV_SPI_Close(intf.drvSPIHandle);
}

int32_t GFX_Disp_Intf_PinControl(GFX_DISP_INTF_PIN pin, GFX_DISP_INTF_PIN_VALUE value)
{
    int32_t res = -1;
        
    switch(pin)
    {
        case GFX_DISP_INTF_PIN_CS:
        {
#ifdef GFX_DISP_INTF_PIN_CS_Set
            if(value == GFX_DISP_INTF_PIN_CLEAR)
            {
                GFX_DISP_INTF_PIN_CS_Clear();
            }
            else
            {
                GFX_DISP_INTF_PIN_CS_Set();
            }
            
            res = 0;
#endif
            break;
        }
        case GFX_DISP_INTF_PIN_WR:
        {
#ifdef GFX_DISP_INTF_PIN_WR_Set
            if (value == GFX_DISP_INTF_PIN_CLEAR)
            {
                GFX_DISP_INTF_PIN_WR_Clear();
            }
            else
            {
                GFX_DISP_INTF_PIN_WR_Set();
            }
            
            res = 0;            
#endif
            break;
        }
        case GFX_DISP_INTF_PIN_RD:
        {
#ifdef GFX_DISP_INTF_PIN_RD_Set
            if (value == GFX_DISP_INTF_PIN_CLEAR)
            {
                GFX_DISP_INTF_PIN_RD_Clear();
            }
            else
            {
                GFX_DISP_INTF_PIN_RD_Set();
            }
            
            res = 0;
#endif
            break;
        }
        case GFX_DISP_INTF_PIN_RSDC:
        {
#ifdef GFX_DISP_INTF_PIN_RSDC_Set
            if (value == GFX_DISP_INTF_PIN_CLEAR)
            {
                GFX_DISP_INTF_PIN_RSDC_Clear();
            }
            else
            {
                GFX_DISP_INTF_PIN_RSDC_Set();
            }
            
            res = 0;
#endif            
            break;
        }
        default:
        {
            break;
        }
    }
    
    return res;
}

int32_t GFX_Disp_Intf_WriteCommand(uint8_t cmd)
{
    GFX_Disp_Intf_PinControl(GFX_DISP_INTF_PIN_RSDC, GFX_DISP_INTF_PIN_CLEAR);
    
    return GFX_Disp_Intf_Write(&cmd, 1);
}

int32_t GFX_Disp_Intf_WriteData(uint8_t* data, int bytes)
{
    GFX_Disp_Intf_PinControl(GFX_DISP_INTF_PIN_RSDC, GFX_DISP_INTF_PIN_SET);
    
    return GFX_Disp_Intf_Write(data, bytes);
}

int32_t GFX_Disp_Intf_ReadData(uint8_t* data, int bytes)
{
    GFX_Disp_Intf_PinControl(GFX_DISP_INTF_PIN_RSDC, GFX_DISP_INTF_PIN_SET);
    
    return GFX_Disp_Intf_Read(data, bytes);
}

int32_t GFX_Disp_Intf_ReadCommandData(uint8_t cmd, uint8_t* data, int num_data)
{
    int32_t retval;

    retval = GFX_Disp_Intf_WriteCommand(cmd);
    
    if (retval != 0)
        return -1;

    GFX_Disp_Intf_PinControl(GFX_DISP_INTF_PIN_RSDC, GFX_DISP_INTF_PIN_SET);
    
    return GFX_Disp_Intf_Read(data, num_data);
}

int32_t GFX_Disp_Intf_WriteCommandParm(uint8_t cmd, uint8_t* parm, int num_parms)
{
    int32_t retval;
    
    GFX_Disp_Intf_PinControl(GFX_DISP_INTF_PIN_RSDC, GFX_DISP_INTF_PIN_CLEAR);
    
    retval = GFX_Disp_Intf_Write(&cmd, 1);
    
    if (retval != 0)
        return -1;
    
    if (num_parms > 0 && parm != NULL)
    {
        GFX_Disp_Intf_PinControl(GFX_DISP_INTF_PIN_RSDC, GFX_DISP_INTF_PIN_SET);
        
        retval = GFX_Disp_Intf_Write(parm, num_parms);
    }

    return retval;
}

int32_t GFX_Disp_Intf_Write(uint8_t* data, int bytes)
{
    if(bytes == 0 || data == NULL)
        return -1;
    
    intf.drvSPITransStatus = SPI_TRANS_CMD_WR_PENDING;
    
    DRV_SPI_WriteTransferAdd(intf.drvSPIHandle,
                            (void *) data,
                            (size_t) bytes,
                            (void *) &intf.drvSPITransferHandle);
                            
    if (DRV_SPI_TRANSFER_HANDLE_INVALID == intf.drvSPITransferHandle)
    {
        return -1;
    }
    
    while (SPI_TRANS_CMD_WR_PENDING == intf.drvSPITransStatus);
    
    return 0;
}


int32_t GFX_Disp_Intf_Read(uint8_t* data, int bytes)
{
    if(bytes == 0 || data == NULL)
        return -1;
    
    // Read the valid pixels
    intf.drvSPITransStatus = SPI_TRANS_CMD_RD_PENDING;
    
    DRV_SPI_ReadTransferAdd(intf.drvSPIHandle,
                            (void *) data,
                            bytes,
                            (void *) &intf.drvSPITransferHandle);
    
    if(DRV_SPI_TRANSFER_HANDLE_INVALID == intf.drvSPITransferHandle)
        return -1;

    //Wait for the callback (full block/no timeout)
    while (SPI_TRANS_CMD_RD_PENDING == intf.drvSPITransStatus);
    
    return 0;
}

int32_t GFX_Disp_Intf_WriteData16(uint16_t* data, int num)
{
    //Not supported
    return -1;
}

int32_t GFX_Disp_Intf_ReadData16(uint16_t* data, int num)
{
    //Not supported
    return -1;
}

/* *****************************************************************************
 End of File
 */
