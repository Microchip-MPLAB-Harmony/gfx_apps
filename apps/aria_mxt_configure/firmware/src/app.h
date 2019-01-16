/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
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
//DOM-IGNORE-END

#ifndef _APP_H
#define _APP_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "definitions.h"
#include "system/fs/sys_fs.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

    /*** Application Instance 0 Configuration ***/
#define APP_READ_BUFFER_SIZE 512

/* Macro defines USB internal DMA Buffer criteria*/
#define APP_MAKE_BUFFER_DMA_READY  __attribute__((aligned(16)))
    
// *****************************************************************************
/* Application States

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* Application's state machine's initial state. */
    APP_STATE_INIT=0,
            
    /* The app splash screen */
    APP_STATE_SPLASH,
            
    /* Open USB driver */
    APP_STATE_OPENUSB,

    /* Application waits for device configuration */
    APP_STATE_WAIT_FOR_CONFIGURATION,

    /* Check if we got data from CDC */
    APP_STATE_CHECK_CDC_READ,

    /* A character is received from the UART */
    APP_STATE_CHECK_UART_RECEIVE,

    /* The app mounts the disk */
    APP_STATE_SDHC_MOUNT_CONFIG_DISK,

    /* The app opens the file to read */
    APP_STATE_SDHC_OPEN_CONFIG_FILE,
            
    /* The app closes the file*/
    APP_STATE_SDHC_CLOSE_CONFIG_FILE,
            
    /* The app closes the file and idles */
    APP_STATE_IDLE,
            
    /* Application error occurred */
    APP_STATE_ERROR

} APP_STATES;

typedef enum
{
    APP_LOAD_SOURCE_PROGRAMFLASH,
    APP_LOAD_SOURCE_SDCARD,
    APP_LOAD_SOURCE_USBDRIVE,
    APP_LOAD_SOURCE_PC
} APP_LOAD_SOURCE;

typedef enum
{
    APP_STAGE_SOURCE_PROGRAMFLASH,
    APP_STAGE_SOURCE_SDCARD,
    APP_STAGE_SOURCE_USBDRIVE,
    APP_STAGE_SOURCE_PC
} APP_STAGE_SOURCE;

typedef enum
{
    BUTTON_STATE_IDLE=0,
    BUTTON_STATE_PRESSED,
    BUTTON_STATE_BUTTON0_PRESSED,
    BUTTON_STATE_WAIT_RESET_HIGH,                   
    BUTTON_STATE_WAIT_RESET_LOW,
    BUTTON_STATE_WAIT_MFB_HIGH
} BUTTON_STATES;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* SYS_FS File handle for 1st file */
    SYS_FS_HANDLE      fileHandle;
    
    /* Application's load source */
    APP_LOAD_SOURCE    loadSource;
  
    /* Application's load source */
    APP_STAGE_SOURCE    stageSource;
    
   /* Device layer handle returned by device layer open function */
    USB_DEVICE_HANDLE usbDevHandle;

    /* Application CDC Instance */
    USB_DEVICE_CDC_INDEX cdcInstance;

    /* Application USART Driver handle */
    DRV_HANDLE usartHandle;
    
    /* Application state*/
    APP_STATES state;

    /* Track device configuration */
    bool deviceIsConfigured;

    /* Read Data Buffer */
    uint8_t * readBuffer;

    /* Set Line Coding Data */
    USB_CDC_LINE_CODING setLineCodingData;

    /* Get Line Coding Data */
    USB_CDC_LINE_CODING getLineCodingData;

    /* Control Line State */
    USB_CDC_CONTROL_LINE_STATE controlLineStateData;

    /* Break data */
    uint16_t breakData;

    /* Read transfer handle */
    USB_DEVICE_CDC_TRANSFER_HANDLE readTransferHandle;

    /* Write transfer handle */
    USB_DEVICE_CDC_TRANSFER_HANDLE writeTransferHandle;

    /* True if a character was read */
    bool isCDCReadComplete;

    /* True if a character was written*/
    bool isCDCWriteComplete;

    /* True if a character was read */
    bool isUSARTReadComplete;

    /* True if a character was written*/
    bool isUSARTWriteComplete;

    /* UART1 received data */
    uint8_t * uartReceivedData;

    /* Read Buffer Length*/
    size_t readLength;

    /* Current UART TX Count*/
    size_t uartTxCount;

    /* This flag is uses to check if Host has requested to change baudrate*/
    bool isBaudrateDataReceived;

    /* This flag used to check if the Set Line coding command is in progress */
    bool isSetLineCodingCommandInProgress;

    /* Configuration value */
    uint8_t configValue;

    /* speed */
    USB_SPEED speed;

    /* ep data sent */
    bool epDataWritePending;

    /* ep data received */
    bool epDataReadPending;

    /* Transfer handle */
    USB_DEVICE_TRANSFER_HANDLE writeTranferHandle;

    /* Transfer handle */
    USB_DEVICE_TRANSFER_HANDLE readTranferHandle;

    /* The transmit endpoint address */
    USB_ENDPOINT_ADDRESS endpointTx;

    /* The receive endpoint address */
    USB_ENDPOINT_ADDRESS endpointRx;

    /* Tracks the alternate setting */
    uint8_t altSetting;
    
    BUTTON_STATES buttonState;   
    uint16_t buttonDelay; 
    
    bool isReadingFile;
    int tick;
 
} APP_DATA;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the
    application in its initial state and prepares it to run so that its
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_Tasks ( void );

void APP_Button_Tasks();

void APP_OnProgramFlashSelected(void);
void APP_OnSDCardSelected(void);
void APP_OnUSBDriveSelected(void);

void APP_OnLoadButtonReleased(void);
void APP_OnLoadProgramButtonReleased(void);
void APP_OnLoadSDCardButtonReleased(void);
void APP_OnLoadPCButtonReleased(void);
void APP_OnLoadUSBButtonReleased(void);
void APP_OnLoadTestButtonReleased(void);
void APP_OnLoadScreenShow(void);

void APP_OnSaveButtonReleased(void);
void APP_OnPCStreamReleased(void);
void APP_OnGotoSaveButtonReleased(void);

void APP_OnStageButtonReleased(void);
void APP_OnStageSDCardButtonReleased(void);
void APP_OnStagePCButtonReleased(void);
void APP_OnStageProgramButtonReleased(void);
void APP_OnStageUSBCardButtonReleased(void);

#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

