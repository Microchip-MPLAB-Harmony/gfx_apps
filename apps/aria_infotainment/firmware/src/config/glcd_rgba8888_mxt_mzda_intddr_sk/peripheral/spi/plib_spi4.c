/*******************************************************************************
  SPI PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_spi4.c

  Summary:
    SPI4 Source File

  Description:
    This file has implementation of all the interfaces provided for particular
    SPI peripheral.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018-2019 Microchip Technology Inc. and its subsidiaries.
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

#include "plib_spi4.h"

// *****************************************************************************
// *****************************************************************************
// Section: SPI4 Implementation
// *****************************************************************************
// *****************************************************************************

/* Global object to save SPI Exchange related data */
SPI_OBJECT spi4Obj;

#define SPI4_CON_MSTEN                      (1 << _SPI4CON_MSTEN_POSITION)
#define SPI4_CON_CKP                        (0 << _SPI4CON_CKP_POSITION)
#define SPI4_CON_CKE                        (1 << _SPI4CON_CKE_POSITION)
#define SPI4_CON_MODE_32_MODE_16            (0 << _SPI4CON_MODE16_POSITION)
#define SPI4_CON_ENHBUF                     (1 << _SPI4CON_ENHBUF_POSITION)
#define SPI4_CON_MCLKSEL                    (0 << _SPI4CON_MCLKSEL_POSITION)
#define SPI4_CON_MSSEN                      (1 << _SPI4CON_MSSEN_POSITION)
#define SPI4_CON_SMP                        (0 << _SPI4CON_SMP_POSITION)

void SPI4_Initialize ( void )
{
    uint32_t rdata;

    /* Disable SPI4 Interrupts */
    IEC5CLR = 0x8;
    IEC5CLR = 0x10;
    IEC5CLR = 0x20;

    /* STOP and Reset the SPI */
    SPI4CON = 0;

    /* Clear the Receiver buffer */
    rdata = SPI4BUF;
    rdata = rdata;

    /* Clear SPI4 Interrupt flags */
    IFS5CLR = 0x8;
    IFS5CLR = 0x10;
    IFS5CLR = 0x20;

    /* BAUD Rate register Setup */
    SPI4BRG = 49;

    /* CLear the Overflow */
    SPI4STATCLR = _SPI4STAT_SPIROV_MASK;

    /*
    MSTEN = 1
    CKP = 0
    CKE = 1
    MODE<32,16> = 0
    ENHBUF = 1
    MSSEN = 1
    MCLKSEL = 0
    */
    SPI4CONSET = (SPI4_CON_MSSEN | SPI4_CON_MCLKSEL | SPI4_CON_ENHBUF | SPI4_CON_MODE_32_MODE_16 | SPI4_CON_CKE | SPI4_CON_CKP | SPI4_CON_MSTEN | SPI4_CON_SMP);

    /* Enable transmit interrupt when transmit buffer is completely empty (STXISEL = '01') */
    /* Enable receive interrupt when the receive buffer is not empty (SRXISEL = '01') */
    SPI4CONSET = 0x00000005;

    /* Initialize global variables */
    spi4Obj.transferIsBusy = false;
    spi4Obj.callback = NULL;

    /* Enable SPI4 */
    SPI4CONSET = _SPI4CON_ON_MASK;
}

bool SPI4_TransferSetup (SPI_TRANSFER_SETUP* setup, uint32_t spiSourceClock )
{
    uint32_t t_brg;
    uint32_t baudHigh;
    uint32_t baudLow;
    uint32_t errorHigh;
    uint32_t errorLow;

    if ((setup == NULL) || (setup->clockFrequency == 0))
    {
        return false;
    }

    if(spiSourceClock == 0)
    {
        // Use Master Clock Frequency set in GUI
        spiSourceClock = 100000000;
    }

    t_brg = (((spiSourceClock / (setup->clockFrequency)) / 2u) - 1u);
    baudHigh = spiSourceClock / (2u * (t_brg + 1u));
    baudLow = spiSourceClock / (2u * (t_brg + 2u));
    errorHigh = baudHigh - setup->clockFrequency;
    errorLow = setup->clockFrequency - baudLow;

    if (errorHigh > errorLow)
    {
        t_brg++;
    }

    if(t_brg > 511)
    {
        return false;
    }

    SPI4BRG = t_brg;
    SPI4CON = (SPI4CON & (~(_SPI4CON_MODE16_MASK | _SPI4CON_MODE32_MASK | _SPI4CON_CKP_MASK | _SPI4CON_CKE_MASK))) |
                            (setup->clockPolarity | setup->clockPhase | setup->dataBits);

    return true;
}

bool SPI4_Write(void* pTransmitData, size_t txSize)
{
    return(SPI4_WriteRead(pTransmitData, txSize, NULL, 0));
}

bool SPI4_Read(void* pReceiveData, size_t rxSize)
{
    return(SPI4_WriteRead(NULL, 0, pReceiveData, rxSize));
}

bool SPI4_WriteRead (void* pTransmitData, size_t txSize, void* pReceiveData, size_t rxSize)
{
    bool isRequestAccepted = false;
    uint32_t dummyData;

    /* Verify the request */
    if((((txSize > 0) && (pTransmitData != NULL)) || ((rxSize > 0) && (pReceiveData != NULL))) && (spi4Obj.transferIsBusy == false))
    {
        isRequestAccepted = true;
        spi4Obj.txBuffer = pTransmitData;
        spi4Obj.rxBuffer = pReceiveData;
        spi4Obj.rxCount = 0;
        spi4Obj.txCount = 0;
        spi4Obj.dummySize = 0;

        if (pTransmitData != NULL)
        {
            spi4Obj.txSize = txSize;
        }
        else
        {
            spi4Obj.txSize = 0;
        }

        if (pReceiveData != NULL)
        {
            spi4Obj.rxSize = rxSize;
        }
        else
        {
            spi4Obj.rxSize = 0;
        }

        spi4Obj.transferIsBusy = true;

        if (spi4Obj.rxSize > spi4Obj.txSize)
        {
            spi4Obj.dummySize = spi4Obj.rxSize - spi4Obj.txSize;
        }

        /* Clear the receive overflow error if any */
        SPI4STATCLR = _SPI4STAT_SPIROV_MASK;

        /* Make sure there is no data pending in the RX FIFO */
        /* Depending on 8/16/32 bit mode, there may be 16/8/4 bytes in the FIFO */
        while ((bool)(SPI4STAT & _SPI4STAT_SPIRBE_MASK) == false)
        {
            dummyData = SPI4BUF;
            (void)dummyData;
        }

        /* Configure SPI to generate receive interrupt when receive buffer is empty (SRXISEL = '01') */
        SPI4CONCLR = _SPI4CON_SRXISEL_MASK;
        SPI4CONSET = 0x00000001;

        /* Configure SPI to generate transmit interrupt when the transmit shift register is empty (STXISEL = '00')*/
        SPI4CONCLR = _SPI4CON_STXISEL_MASK;

        /* Disable the receive interrupt */
        IEC5CLR = 0x10;

        /* Disable the transmit interrupt */
        IEC5CLR = 0x20;

        /* Clear the receive interrupt flag */
        IFS5CLR = 0x10;

        /* Clear the transmit interrupt flag */
        IFS5CLR = 0x20;

        /* Start the first write here itself, rest will happen in ISR context */
        if((_SPI4CON_MODE32_MASK) == (SPI4CON & (_SPI4CON_MODE32_MASK)))
        {
            spi4Obj.txSize >>= 2;
            spi4Obj.dummySize >>= 2;
            spi4Obj.rxSize >>= 2;

            if(spi4Obj.txCount < spi4Obj.txSize)
            {
                SPI4BUF = *((uint32_t*)spi4Obj.txBuffer);
                spi4Obj.txCount++;
            }
            else if (spi4Obj.dummySize > 0)
            {
                SPI4BUF = (uint32_t)(0xff);
                spi4Obj.dummySize--;
            }
        }
        else if((_SPI4CON_MODE16_MASK) == (SPI4CON & (_SPI4CON_MODE16_MASK)))
        {
            spi4Obj.txSize >>= 1;
            spi4Obj.dummySize >>= 1;
            spi4Obj.rxSize >>= 1;

            if (spi4Obj.txCount < spi4Obj.txSize)
            {
                SPI4BUF = *((uint16_t*)spi4Obj.txBuffer);
                spi4Obj.txCount++;
            }
            else if (spi4Obj.dummySize > 0)
            {
                SPI4BUF = (uint16_t)(0xff);
                spi4Obj.dummySize--;
            }
        }
        else
        {
            if (spi4Obj.txCount < spi4Obj.txSize)
            {
                SPI4BUF = *((uint8_t*)spi4Obj.txBuffer);
                spi4Obj.txCount++;
            }
            else if (spi4Obj.dummySize > 0)
            {
                SPI4BUF = (uint8_t)(0xff);
                spi4Obj.dummySize--;
            }
        }

        if (rxSize > 0)
        {
            /* Enable receive interrupt to complete the transfer in ISR context.
             * Keep the transmit interrupt disabled. Transmit interrupt will be
             * enabled later if txCount < txSize, when rxCount = rxSize.
             */
            IEC5SET = 0x10;
        }
        else
        {
            if (spi4Obj.txCount != spi4Obj.txSize)
            {
                /* Configure SPI to generate transmit buffer empty interrupt only if more than
                 * data is pending (STXISEL = '01')  */
                SPI4CONSET = 0x00000004;
            }
            /* Enable transmit interrupt to complete the transfer in ISR context */
            IEC5SET = 0x20;
        }
    }

    return isRequestAccepted;
}

bool SPI4_IsBusy (void)
{
    return ( (spi4Obj.transferIsBusy) || ((SPI4STAT & _SPI4STAT_SRMT_MASK) == 0));
}

void SPI4_CallbackRegister (SPI_CALLBACK callback, uintptr_t context)
{
    spi4Obj.callback = callback;

    spi4Obj.context = context;
}

void SPI4_RX_InterruptHandler (void)
{
    uint32_t receivedData = 0;

    /* Check if the receive buffer is empty or not */
    if ((bool)(SPI4STAT & _SPI4STAT_SPIRBE_MASK) == false)
    {
        /* Receive buffer is not empty. Read the received data. */
        receivedData = SPI4BUF;

        if (spi4Obj.rxCount < spi4Obj.rxSize)
        {
            /* Copy the received data to the user buffer */
            if((_SPI4CON_MODE32_MASK) == (SPI4CON & (_SPI4CON_MODE32_MASK)))
            {
                ((uint32_t*)spi4Obj.rxBuffer)[spi4Obj.rxCount++] = receivedData;
            }
            else if((_SPI4CON_MODE16_MASK) == (SPI4CON & (_SPI4CON_MODE16_MASK)))
            {
                ((uint16_t*)spi4Obj.rxBuffer)[spi4Obj.rxCount++] = receivedData;
            }
            else
            {
                ((uint8_t*)spi4Obj.rxBuffer)[spi4Obj.rxCount++] = receivedData;
            }
            if ((spi4Obj.rxCount == spi4Obj.rxSize) && (spi4Obj.txCount < spi4Obj.txSize))
            {
                /* Reception of all bytes is complete. However, there are few more
                 * bytes to be transmitted as txCount != txSize. Finish the
                 * transmission of the remaining bytes from the transmit interrupt. */

                /* Disable the receive interrupt */
                IEC5CLR = 0x10;

                /* Generate TX interrupt when buffer is completely empty (STXISEL = '00') */
                SPI4CONCLR = _SPI4CON_STXISEL_MASK;
                SPI4CONSET = 0x00000004;

                /* Enable the transmit interrupt. Callback will be given from the
                 * transmit interrupt, when all bytes are shifted out. */
                IEC5SET = 0x20;
            }
        }
        if (spi4Obj.rxCount < spi4Obj.rxSize)
        {
            /* More bytes pending to be received .. */
            if((_SPI4CON_MODE32_MASK) == (SPI4CON & (_SPI4CON_MODE32_MASK)))
            {
                if (spi4Obj.txCount < spi4Obj.txSize)
                {
                    SPI4BUF = ((uint32_t*)spi4Obj.txBuffer)[spi4Obj.txCount++];
                }
                else if (spi4Obj.dummySize > 0)
                {
                    SPI4BUF = (uint32_t)(0xff);
                    spi4Obj.dummySize--;
                }
            }
            else if((_SPI4CON_MODE16_MASK) == (SPI4CON & (_SPI4CON_MODE16_MASK)))
            {
                if (spi4Obj.txCount < spi4Obj.txSize)
                {
                    SPI4BUF = ((uint16_t*)spi4Obj.txBuffer)[spi4Obj.txCount++];
                }
                else if (spi4Obj.dummySize > 0)
                {
                    SPI4BUF = (uint16_t)(0xff);
                    spi4Obj.dummySize--;
                }
            }
            else
            {
                if (spi4Obj.txCount < spi4Obj.txSize)
                {
                    SPI4BUF = ((uint8_t*)spi4Obj.txBuffer)[spi4Obj.txCount++];
                }
                else if (spi4Obj.dummySize > 0)
                {
                    SPI4BUF = (uint8_t)(0xff);
                    spi4Obj.dummySize--;
                }
            }
        }
        else
        {
            if((spi4Obj.rxCount == spi4Obj.rxSize) && (spi4Obj.txCount == spi4Obj.txSize))
            {
                /* Clear receiver overflow error if any */
                SPI4STATCLR = _SPI4STAT_SPIROV_MASK;

                /* Disable receive interrupt */
                IEC5CLR = 0x10;

                /* Transfer complete. Give a callback */
                spi4Obj.transferIsBusy = false;

                if(spi4Obj.callback != NULL)
                {
                    spi4Obj.callback(spi4Obj.context);
                }
            }
        }
    }

    /* Clear SPI4 RX Interrupt flag */
    /* This flag should cleared only after reading buffer */
    IFS5CLR = 0x10;
}

void SPI4_TX_InterruptHandler (void)
{
    /* If there are more words to be transmitted, then transmit them here and keep track of the count */
    if((SPI4STAT & _SPI4STAT_SPITBE_MASK) == _SPI4STAT_SPITBE_MASK)
    {
        if (spi4Obj.txCount < spi4Obj.txSize)
        {
            if((_SPI4CON_MODE32_MASK) == (SPI4CON & (_SPI4CON_MODE32_MASK)))
            {
                SPI4BUF = ((uint32_t*)spi4Obj.txBuffer)[spi4Obj.txCount++];
            }
            else if((_SPI4CON_MODE16_MASK) == (SPI4CON & (_SPI4CON_MODE16_MASK)))
            {
                SPI4BUF = ((uint16_t*)spi4Obj.txBuffer)[spi4Obj.txCount++];
            }
            else
            {
                SPI4BUF = ((uint8_t*)spi4Obj.txBuffer)[spi4Obj.txCount++];
            }

            if (spi4Obj.txCount == spi4Obj.txSize)
            {
                /* All bytes are submitted to the SPI module. Now, enable transmit
                 * interrupt when the shift register is empty (STXISEL = '00')*/
                SPI4CONCLR = _SPI4CON_STXISEL_MASK;
            }
        }
        else if ((spi4Obj.txCount == spi4Obj.txSize) && (SPI4STAT & _SPI4STAT_SRMT_MASK))
        {
            /* This part of code is executed when the shift register is empty. */

            /* Clear receiver overflow error if any */
            SPI4STATCLR = _SPI4STAT_SPIROV_MASK;

            /* Disable transmit interrupt */
            IEC5CLR = 0x20;

            /* Transfer complete. Give a callback */
            spi4Obj.transferIsBusy = false;

            if(spi4Obj.callback != NULL)
            {
                spi4Obj.callback(spi4Obj.context);
            }
        }
    }
    /* Clear the transmit interrupt flag */
    IFS5CLR = 0x20;
}

