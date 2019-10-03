/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "app_splash.h"
#include "mxt_config.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
/* example definition of a XCFG filename existing on sdcard or usb drive */
static char * XCFG_FILENAME = "maxtouch.xcfg";

/* example definition of a RAW filename existing on sdcard or usb drive */
static char * RAW_FILENAME = "maxtouch.raw";

DRV_MAXTOUCH_Firmware config;
laProgressBarWidget* progressBar;
DRV_MAXTOUCH_ConfigProgress_FnPtr funcPtr;

#define MXT_MOUNT_NAME    "/mnt/mydrive"
#define MXT_DEV_NAME      "/dev/mmcblka1"
#define PROGRESS_COMPLETE 100

uint8_t APP_MAKE_BUFFER_DMA_READY readBuffer[APP_READ_BUFFER_SIZE] ;
uint8_t APP_MAKE_BUFFER_DMA_READY configFile[8192];
uint8_t APP_MAKE_BUFFER_DMA_READY uartReceivedData;

uint8_t * d = &configFile[0];

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

// drv_maxtouch callback handlers
static void App_LoadFlashProgressHandler(uint32_t progress);
static void App_LoadSDCardProgressHandler(uint32_t progress);
static void App_LoadPCProgressHandler(uint32_t progress);
static void App_LoadUSBDriveProgressHandler(uint32_t progress);
static void App_SaveProgressHandler(uint32_t progress);
static void App_FileReader(char * ptr);
static bool App_FileEof(void);
static bool App_FileXCFG(char * cfg);

/*******************************************************
 * USB CDC Device Events - Application Event Handler
 *******************************************************/
USB_DEVICE_CDC_EVENT_RESPONSE APP_USBDeviceCDCEventHandler
(
    USB_DEVICE_CDC_INDEX index ,
    USB_DEVICE_CDC_EVENT event ,
    void* pData,
    uintptr_t userData
)
{
    APP_DATA * appDataObject;
    appDataObject = (APP_DATA *)userData;
    USB_CDC_CONTROL_LINE_STATE * controlLineStateData;
    uint16_t * breakData;

    switch ( event )
    {
        case USB_DEVICE_CDC_EVENT_GET_LINE_CODING:

            /* This means the host wants to know the current line
             * coding. This is a control transfer request. Use the
             * USB_DEVICE_ControlSend() function to send the data to
             * host.  */

             USB_DEVICE_ControlSend(appDataObject->usbDevHandle,
                    &appDataObject->getLineCodingData, sizeof(USB_CDC_LINE_CODING));

            break;

        case USB_DEVICE_CDC_EVENT_SET_LINE_CODING:

            /* This means the host wants to set the line coding.
             * This is a control transfer request. Use the
             * USB_DEVICE_ControlReceive() function to receive the
             * data from the host */
            appData.isSetLineCodingCommandInProgress = true;
            appData.isBaudrateDataReceived = false;
            USB_DEVICE_ControlReceive(appDataObject->usbDevHandle,
                    &appDataObject->setLineCodingData, sizeof(USB_CDC_LINE_CODING));

            break;

        case USB_DEVICE_CDC_EVENT_SET_CONTROL_LINE_STATE:

            /* This means the host is setting the control line state.
             * Read the control line state. We will accept this request
             * for now. */

            controlLineStateData = (USB_CDC_CONTROL_LINE_STATE *)pData;
            appDataObject->controlLineStateData.dtr = controlLineStateData->dtr;
            appDataObject->controlLineStateData.carrier =
                    controlLineStateData->carrier;

            USB_DEVICE_ControlStatus(appDataObject->usbDevHandle, USB_DEVICE_CONTROL_STATUS_OK);

            break;

        case USB_DEVICE_CDC_EVENT_SEND_BREAK:

            /* This means that the host is requesting that a break of the
             * specified duration be sent. Read the break duration */

            breakData = (uint16_t *)pData;
            appDataObject->breakData = *breakData;

            /* Complete the control transfer by sending a ZLP  */
            USB_DEVICE_ControlStatus(appDataObject->usbDevHandle, USB_DEVICE_CONTROL_STATUS_OK);
            break;

        case USB_DEVICE_CDC_EVENT_READ_COMPLETE:

            /* This means that the host has sent some data*/
            appDataObject->isCDCReadComplete = true;
            appDataObject->readLength =
                    ((USB_DEVICE_CDC_EVENT_DATA_READ_COMPLETE*)pData)->length;
            break;

        case USB_DEVICE_CDC_EVENT_CONTROL_TRANSFER_DATA_RECEIVED:

            /* The data stage of the last control transfer is
             * complete. */
            if (appData.isSetLineCodingCommandInProgress == true)
            {
               /* We have received set line coding command from the Host.
                * DRV_USART_BaudSet() function is not interrupt safe and it
                * should not be called here. It is called in APP_Tasks()
                * function. The ACK for Status stage of the control transfer is
                * send in the APP_Tasks() function.  */
                appData.isSetLineCodingCommandInProgress = false;
                appData.isBaudrateDataReceived = true;
            }
            else
            {
				/* ACK the Status stage of the Control transfer */
                USB_DEVICE_ControlStatus(appDataObject->usbDevHandle, USB_DEVICE_CONTROL_STATUS_OK);
            }
            break;

        case USB_DEVICE_CDC_EVENT_CONTROL_TRANSFER_DATA_SENT:

            /* This means the GET LINE CODING function data is valid. We dont
             * do much with this data in this demo. */
            break;
        case USB_DEVICE_CDC_EVENT_CONTROL_TRANSFER_ABORTED:
            /* The control transfer has been aborted */
            if (appData.isSetLineCodingCommandInProgress == true)
            {
                appData.isSetLineCodingCommandInProgress = false;
                appData.isBaudrateDataReceived = false;
            }

            break;
        case USB_DEVICE_CDC_EVENT_WRITE_COMPLETE:

            /* This means that the data write got completed. We can schedule
             * the next read. */

            break;

        default:
            break;
    }

    return USB_DEVICE_CDC_EVENT_RESPONSE_NONE;
}

/*********************************************
 * Application USB Device Layer Event Handler
 *********************************************/

void APP_USBDeviceEventHandler(USB_DEVICE_EVENT event, void * eventData, uintptr_t context)
{
    uint8_t configurationValue;
    switch(event)
    {
        case USB_DEVICE_EVENT_RESET:
        case USB_DEVICE_EVENT_DECONFIGURED:

            /* USB device is reset or device is deconfigured.
             * This means that USB device layer is about to deininitialize
             * all function drivers. Update LEDs to indicate
             * reset/deconfigured state. */

            appData.deviceIsConfigured = false;

            break;

        case USB_DEVICE_EVENT_CONFIGURED:

            /* Check the configuration */
            configurationValue = ((USB_DEVICE_EVENT_DATA_CONFIGURED *)eventData)->configurationValue;
            if (configurationValue == 1)
            {
                /* The device is in configured state. Update LED indication */

                /* Register the CDC Device application event handler here.
                 * Note how the appData object pointer is passed as the
                 * user data */

                USB_DEVICE_CDC_EventHandlerSet(USB_DEVICE_CDC_INDEX_0,
                        APP_USBDeviceCDCEventHandler, (uintptr_t)&appData);

                /* mark that set configuration is complete */
                appData.deviceIsConfigured = true;

            }
            break;

        case USB_DEVICE_EVENT_SUSPENDED:

            /* Update LEDs */
            break;


        case USB_DEVICE_EVENT_POWER_DETECTED:

            /* VBUS is detected. Attach the device */
            USB_DEVICE_Attach(appData.usbDevHandle);
            break;

        case USB_DEVICE_EVENT_POWER_REMOVED:

            /* VBUS is removed. Detach the device */
            USB_DEVICE_Detach (appData.usbDevHandle);
            break;

        /* These events are not used in this demo. */
        case USB_DEVICE_EVENT_RESUMED:
        case USB_DEVICE_EVENT_ERROR:
        default:
            break;
    }
}


// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/*****************************************************
 * This function is called in every step of the
 * application state machine.
 *****************************************************/

bool APP_StateReset(void)
{
    /* This function returns true if the device
     * was reset  */

    bool retVal;

    if(appData.deviceIsConfigured == false)
    {
        appData.state = APP_STATE_WAIT_FOR_CONFIGURATION;
        appData.readTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
        appData.writeTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
        appData.isCDCReadComplete = true;
        appData.isCDCWriteComplete = true;

        retVal = true;

        appData.isSetLineCodingCommandInProgress = false;
        appData.isBaudrateDataReceived = false;
    }
    else
    {
        retVal = false;
    }

    return(retVal);
}

/***************************************************************************
 * This function Handles the Set Line coding command from Host.
 ***************************************************************************/
void _APP_SetLineCodingHandler(void)
{
    /* Acknowledge the Status stage of the Control transfer */
    USB_DEVICE_ControlStatus(appData.usbDevHandle, USB_DEVICE_CONTROL_STATUS_OK);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
     /* Device Layer Handle  */
    appData.usbDevHandle = USB_DEVICE_HANDLE_INVALID;

    /* USART Driver Handle */
    appData.usartHandle = DRV_HANDLE_INVALID;

    /* CDC Instance index for this app object00*/
    appData.cdcInstance = USB_DEVICE_CDC_INDEX_0;

    /* app state */
    appData.state = APP_STATE_INIT;

    /* device configured status */
    appData.deviceIsConfigured = false;

    /* Initial get line coding state */
    appData.getLineCodingData.dwDTERate = 9600;
    appData.getLineCodingData.bDataBits = 8;
    appData.getLineCodingData.bParityType = 0;
    appData.getLineCodingData.bCharFormat = 0;

    /* Read Transfer Handle */
    appData.readTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;

    /* Write Transfer Handle */
    appData.writeTransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;

    /* Initialize the read complete flag */
    appData.isCDCReadComplete = true;

    /*Initialize the write complete flag*/
    appData.isCDCWriteComplete = true;

    /*Initialize the buffer pointers */
    appData.readBuffer = &readBuffer[0];

    appData.uartReceivedData = &uartReceivedData;

    appData.uartTxCount = 0;

    /* Initialize the Set Line coding flags */
    appData.isBaudrateDataReceived = false;
    appData.isSetLineCodingCommandInProgress = false;
    
    appData.buttonState = BUTTON_STATE_IDLE;   
    appData.buttonDelay = 0;        // used for button debounce

    /* Place the App state machine in its initial state. */
    config.data = RAW_FILENAME;
    config.reader = &App_FileReader;
    config.eof = &App_FileEof;
//    config.progress = &App_StageProgramProgressHandler;
    appData.epDataReadPending = false;

}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
*/

void APP_Tasks ( void )
{
    static int value=0;
    
    APP_Button_Tasks();

    if ((appData.deviceIsConfigured) && (appData.isBaudrateDataReceived))
    {
		 appData.isBaudrateDataReceived = false;
        _APP_SetLineCodingHandler();
    }

    /* Update the application state machine based
     * on the current state */

    switch(appData.state)
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
        
            if (appInitialized)
            {
                appData.state = APP_STATE_SPLASH;                
            }
            break;
        }
        
        case APP_STATE_SPLASH:
        {            
            if (APP_IsSplashScreenComplete())
            {
                laContext_SetActiveScreen(main_screen_ID);
                appData.state = APP_STATE_IDLE;
            }
            break;
        }
            
        case APP_STATE_OPENUSB:

            /* Open the device layer */
            appData.usbDevHandle = USB_DEVICE_Open( USB_DEVICE_INDEX_0, DRV_IO_INTENT_READWRITE );

            if(appData.usbDevHandle != USB_DEVICE_HANDLE_INVALID)
            {
                /* Register a callback with device layer to get event notification (for end point 0) */
                USB_DEVICE_EventHandlerSet(appData.usbDevHandle,  APP_USBDeviceEventHandler, 0);

                /* Application waits for device configuration. */
                appData.state = APP_STATE_WAIT_FOR_CONFIGURATION;
            }
            else
            {
                /* The Device Layer is not ready to be opened. We should try
                 * again later. */
            }

            break;

       case APP_STATE_WAIT_FOR_CONFIGURATION:

            /* Check if the device is configured */
            if(appData.deviceIsConfigured)
            {
                /* Schedule the first read from CDC function driver */
                appData.state = APP_STATE_CHECK_CDC_READ;
                appData.isCDCReadComplete = false;
				
                USB_DEVICE_CDC_Read (appData.cdcInstance, &(appData.readTransferHandle),
                        appData.readBuffer, APP_READ_BUFFER_SIZE);
            }
            break;

        case APP_STATE_CHECK_CDC_READ:

            if(APP_StateReset())
            {
                break;
            }
            
            if ( appData.tick > 100000 )
            {
                appData.isReadingFile = false;
                if ( App_FileXCFG((char*)&configFile[0]) )
                {
                    config.type = DRV_MAXTOUCH_RAW_FILE;
                }
                else
                {
                    config.type = DRV_MAXTOUCH_XCFG_FILE;
                }
                config.data = &configFile[0];
                progressBar = loadProgressBar;   
                config.progress = &App_LoadPCProgressHandler;
                DRV_MAXTOUCH_ConfigLoad ( sysObj.drvMAXTOUCH, &config );
                
                appData.state = APP_STATE_IDLE;
            }

            /* If CDC read is complete, send the received data to the UART. */
            if(appData.isCDCReadComplete == true)
            {											
                appData.isCDCReadComplete = false;

                /* This means we have sent all the data. We schedule the next
                 * CDC Read. */
                strcpy((char*)d, (const char*)appData.readBuffer);
                d += appData.readLength;
//                *d = EOF;
                    laProgressBarWidget_SetValue(loadProgressBar,  50);
                USB_DEVICE_CDC_Read (appData.cdcInstance, &appData.readTransferHandle,
                    appData.readBuffer, APP_READ_BUFFER_SIZE);
                
                appData.isReadingFile = true;
                if ( appData.tick++ > 8000 )
                {
                    if ( value++ < 100 )
                        laProgressBarWidget_SetValue(loadProgressBar,  value);
                    appData.tick=0;
                }

            } 
            else 
            {
                if ( appData.isReadingFile )
                {
                    appData.tick++;
                }
            }
            break;

        case APP_STATE_SDHC_MOUNT_CONFIG_DISK:
        {
            if(SYS_FS_Mount(MXT_DEV_NAME, MXT_MOUNT_NAME, FAT, 0, NULL) != 0)
            {
                /* The disk could not be mounted. Try
                 * mounting again until success. */
                appData.state = APP_STATE_SDHC_MOUNT_CONFIG_DISK;
            }
            else
            {
                /* Mount was successful. Unmount the disk, for testing. */
                appData.state = APP_STATE_SDHC_OPEN_CONFIG_FILE;
            }
            break;
        }
        
        case APP_STATE_SDHC_OPEN_CONFIG_FILE:
            appData.fileHandle = SYS_FS_FileOpen(XCFG_FILENAME,
                    (SYS_FS_FILE_OPEN_READ));
            if(appData.fileHandle == SYS_FS_HANDLE_INVALID)
            {
                /* Could not open the file. Error out*/
                appData.state = APP_STATE_ERROR;
            }
            else
            {
                /* load configuration data */
                progressBar = loadProgressBar;   
                config.type = DRV_MAXTOUCH_UNKNOWN_FILE;
                config.data = XCFG_FILENAME;
                config.progress = &App_LoadSDCardProgressHandler;
                DRV_MAXTOUCH_ConfigLoad ( sysObj.drvMAXTOUCH, &config );
                appData.state = APP_STATE_IDLE;
                appData.epDataReadPending = true;
            }
            break;

        case APP_STATE_SDHC_CLOSE_CONFIG_FILE:
            /* Close both files */
            SYS_FS_FileClose(appData.fileHandle);

            /* The test was successful. Lets idle. */
            appData.state = APP_STATE_IDLE;
            break;
            
            
        case APP_STATE_READ_PROGRAM_FLASH:
            /* load configuration data */
            config.type = DRV_MAXTOUCH_RAW_FLASH;
            config.data = &mxt336T_config[0];
            config.progress = &App_LoadFlashProgressHandler;
            progressBar = loadProgressBar;   
            DRV_MAXTOUCH_ConfigLoad ( sysObj.drvMAXTOUCH, &config );
            appData.state = APP_STATE_IDLE;
            break;
            
        case APP_STATE_IDLE:
            /* The application comes here when the demo has completed
             * successfully. Glow LED1. */
            break;
            
        case APP_STATE_ERROR:
            break;
            
        default:
            break;
    }
}

#define BUTTON_DEBOUNCE 50
#define LONG_BUTTON_PRESS 1000

void APP_Button_Tasks()
{      
   //BUTTON PROCESSING
    /* Check the buttons' current state. */         
    switch ( appData.buttonState )
    {
        case BUTTON_STATE_IDLE:
        {
//            if ( SWITCH_Get()==SWITCH_STATE_PRESSED )                
//            {
                appData.buttonState=BUTTON_STATE_PRESSED;               
//            }
        }
        break;                

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

/* load screen */
void APP_OnLoadScreenShow()
{
    /* ensure that program radio button is not selected */
    laRadioButtonWidget_SetSelected(loadUSBRadioButton);
}

void APP_OnLoadButtonReleased()
{
    
    if ( DRV_MAXTOUCH_Status(sysObj.drvMAXTOUCH) == SYS_STATUS_READY )
    {                        
        switch ( appData.loadSource )
        {
            case APP_LOAD_SOURCE_PROGRAMFLASH:
                appData.state = APP_STATE_READ_PROGRAM_FLASH;
                break;

            case APP_LOAD_SOURCE_SDCARD:
                appData.state = APP_STATE_SDHC_MOUNT_CONFIG_DISK;
                break;

            case APP_LOAD_SOURCE_USBDRIVE:
                config.progress = &App_LoadUSBDriveProgressHandler;
                break;
                
            case APP_LOAD_SOURCE_PC:
                config.type = DRV_MAXTOUCH_UNKNOWN_FILE;
                config.data = XCFG_FILENAME;
                appData.state = APP_STATE_OPENUSB;
                config.progress = &App_LoadPCProgressHandler;
        }
    
    }
}

void APP_OnSaveButtonReleased()
{
    if ( DRV_MAXTOUCH_Status(sysObj.drvMAXTOUCH) == SYS_STATUS_READY )
    {                        
        /* save configuration data */
        progressBar = storeProgressBar;   
        DRV_MAXTOUCH_ConfigSave ( sysObj.drvMAXTOUCH, &App_SaveProgressHandler );
    } 
}

void APP_OnLoadProgramButtonReleased()
{
    appData.loadSource = APP_LOAD_SOURCE_PROGRAMFLASH;
    laRadioButtonWidget_SetSelected(loadProgramRadioButton);
    laWidget_SetVisible((laWidget*)loadButton, true);
    laWidget_SetVisible((laWidget*)ImageWidget10, true);
}

void APP_OnLoadSDCardButtonReleased()
{
    appData.loadSource = APP_LOAD_SOURCE_SDCARD;
    laRadioButtonWidget_SetSelected(loadSDCardRadioButton);
    laWidget_SetVisible((laWidget*)loadButton, true);
    laWidget_SetVisible((laWidget*)ImageWidget10, true);
}

void APP_OnLoadUSBButtonReleased()
{
    appData.loadSource = APP_LOAD_SOURCE_USBDRIVE;
    laRadioButtonWidget_SetSelected(loadUSBRadioButton);
    laWidget_SetVisible((laWidget*)loadButton, true);
    laWidget_SetVisible((laWidget*)ImageWidget10, true);
}

void APP_OnLoadPCButtonReleased()
{
    appData.loadSource = APP_LOAD_SOURCE_PC;
    laRadioButtonWidget_SetSelected(loadPCRadioButton);
    laWidget_SetVisible((laWidget*)loadButton, true);
    laWidget_SetVisible((laWidget*)ImageWidget10, true);
}

void App_LoadFlashProgressHandler(uint32_t progress)
{
    if ( progress > 0 ) 
        laProgressBarWidget_SetValue(progressBar,  progress);
    
    if ( progress == PROGRESS_COMPLETE )
    {
        laWidget_SetVisible((laWidget*)loadButton, false);
        laWidget_SetVisible((laWidget*)ImageWidget10, false);
        laWidget_SetVisible((laWidget*)loadNextButton, true);
    }
}

void App_LoadPCProgressHandler(uint32_t progress)
{
    if ( progress > 0 ) 
        laProgressBarWidget_SetValue(progressBar,  progress);
    
    if ( progress == PROGRESS_COMPLETE )
    {
        laWidget_SetVisible((laWidget*)loadButton, false);
        laWidget_SetVisible((laWidget*)ImageWidget10, false);
        laWidget_SetVisible((laWidget*)loadNextButton, true);
    }
}

void App_LoadUSBDriveProgressHandler(uint32_t progress)
{
    if ( progress > 0 ) 
        laProgressBarWidget_SetValue(progressBar,  progress);
    
    if ( progress == PROGRESS_COMPLETE )
    {
        laWidget_SetVisible((laWidget*)loadButton, false);
        laWidget_SetVisible((laWidget*)ImageWidget10, false);
        laWidget_SetVisible((laWidget*)loadNextButton, true);
    }
}

void App_LoadSDCardProgressHandler(uint32_t progress)
{
    if ( progress > 0 ) 
        laProgressBarWidget_SetValue(progressBar,  progress);
    
    if ( progress == PROGRESS_COMPLETE )
    {
        laWidget_SetVisible((laWidget*)loadButton, false);
        laWidget_SetVisible((laWidget*)ImageWidget10, false);
        laWidget_SetVisible((laWidget*)loadNextButton, true);
    }
}

void App_SaveProgressHandler(uint32_t progress)
{
    if ( progress > 0 ) 
        laProgressBarWidget_SetValue(progressBar,  progress);
        
    if ( progress == PROGRESS_COMPLETE )
    {
        laWidget_SetVisible((laWidget*)storeSaveButton, false);
        laWidget_SetVisible((laWidget*)ImageWidget10, false);
        laWidget_SetVisible((laWidget*)storeDoneButton, true);
    }
}

/* SD Card callback routines */
void App_FileReader(char * ptr)
{
    char c;
      
    /* read line */
    SYS_FS_FileRead( appData.fileHandle, (void *)&c, 1);
    while ((c != '\n') && (SYS_FS_FileEOF( appData.fileHandle) == false ))
    {
        *ptr++ = c;
        SYS_FS_FileRead(appData.fileHandle, (void *)&c, 1);
    }
    ptr = '\0';
}

bool App_FileEof()
{
    return SYS_FS_FileEOF(appData.fileHandle);
}

bool App_FileXCFG(char * cfg)
{   
	if (strncmp(cfg, "OBP_RAW V1", strlen("OBP_RAW V1"))) {
		return false;
	}
    return true;
}
    
/*******************************************************************************
 End of File
 */
