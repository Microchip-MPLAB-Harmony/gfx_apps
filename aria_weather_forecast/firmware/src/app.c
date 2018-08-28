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
#include "gfx/hal/gfx.h"
#include "gfx/gfx_assets.h"
#include "gfx/libaria/libaria_init.h"
#include "gfx/libaria/inc/libaria_utils.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

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

int hourlyActualTemp[3][7] = {
    {30, 36, 43, 45, 46, 46, 44},
    {26, 28, 29, 30, 31, 32, 30},
    {22, 23, 25, 25, 25, 24, 22},
};

int hourlyRealTemp[3][7] = {
    {22, 34, 42, 43, 43, 44, 41},
    {36, 38, 39, 40, 41, 42, 40},
    {12, 13, 15, 15, 15, 14, 12},
};

int hourlyPrepcipitation[3][7] = {
    {25, 25, 33, 50, 50, 50, 80},
    {75, 75, 80, 85, 90, 90, 90},
    {75, 80, 75, 65, 55, 50, 25},
};

int hourlyHumidity[3][7] = {
    {80, 80, 75, 75, 75, 70, 75},
    {90, 90, 90, 85, 85, 90, 90},
    {75, 75, 65, 65, 65, 65, 60},
};

int dailyActualTemp[3][7] = {
    {38, 39, 40, 39, 38, 37, 36},
    {25, 24, 23, 20, 19, 28, 27},
    {22, 33, 30, 22, 21, 29, 28},
};

int dailyRealTemp[3][7] = {
    {28, 29, 30, 29, 28, 27, 26},
    {30, 29, 22, 19, 18, 32, 31},
    {12, 36, 33, 22, 21, 32, 30},
};

int dailyPrepcipitation[3][7] = {
    {80, 25, 0, 0, 25, 25, 50},
    {25, 25, 90, 90, 85, 35, 25},
    {75, 10, 5, 65, 65, 0, 0},
};

int dailyHumidity[3][7] = {
    {80, 60, 50, 50, 65, 70, 75},
    {80, 80, 90, 85, 85, 80, 80},
    {65, 50, 45, 55, 55, 45, 50},
};

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************



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
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;


}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */
uint32_t i;

uint32_t frame = 0;

uint32_t currentLanguage = 0;
uint32_t currentWeather = 0;

void _app_UpdateData( void )
{
    uint32_t language = laContext_GetStringLanguage();

    for (int i = 0; i < 7; ++i)
    {
        if (appData.displayState == APP_DISPLAY_HOURLY)
        {
            laLineGraphWidget_SetDataInSeries(TempLineGraph, 0, i, hourlyActualTemp[language][i]);        
            laLineGraphWidget_SetDataInSeries(TempLineGraph, 1, i, hourlyRealTemp[language][i]);        
            
            laBarGraphWidget_SetDataInSeries(TempPrecipitaionGraph, 0, i, hourlyPrepcipitation[language][i]);
            laBarGraphWidget_SetDataInSeries(TempPrecipitaionGraph, 1, i, hourlyHumidity[language][i]);
            
            laWidget_SetVisible(PanelWidget_Hourly, LA_TRUE);
            laWidget_SetVisible(PanelWidget_Daily, LA_FALSE);
        }
        else
        {
            laLineGraphWidget_SetDataInSeries(TempLineGraph, 0, i, dailyActualTemp[language][i]);        
            laLineGraphWidget_SetDataInSeries(TempLineGraph, 1, i, dailyRealTemp[language][i]);        
            
            laBarGraphWidget_SetDataInSeries(TempPrecipitaionGraph, 0, i, dailyPrepcipitation[language][i]);
            laBarGraphWidget_SetDataInSeries(TempPrecipitaionGraph, 1, i, dailyHumidity[language][i]);

            laWidget_SetVisible(PanelWidget_Hourly, LA_FALSE);
            laWidget_SetVisible(PanelWidget_Daily, LA_TRUE);
        }
    }
}

void app_toggleDisplay( void )
{
    if (appData.displayState == APP_DISPLAY_DAILY)
    {
        app_displayHourly();
    }
    else
    {
        app_displayDaily();
    }
}

void app_displayHourly( void )
{
    if (appData.displayState == APP_DISPLAY_HOURLY)
        return;
    
    appData.displayState = APP_DISPLAY_HOURLY;

    _app_UpdateData();
}

void app_displayDaily( void )
{
    if (appData.displayState == APP_DISPLAY_DAILY)
        return;
    
    appData.displayState = APP_DISPLAY_DAILY;        

    _app_UpdateData();
}

void app_cycleLanguage()
{
    uint32_t language = laContext_GetStringLanguage();
    
    if(language == language_English)
    {
        laContext_SetStringLanguage(language_Chinese);
        laImageWidget_SetImage(WeatherImage,&lightning);
    }
    else if(language == language_Chinese)
    {
        laContext_SetStringLanguage(language_Spanish);
        laImageWidget_SetImage(WeatherImage,&cloudy);
    }
    else if(language == language_Spanish)
    {
        laContext_SetStringLanguage(language_English);
        laImageWidget_SetImage(WeatherImage,&windy);
    }
    
    _app_UpdateData();
}

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            appData.state = APP_STATE_SPLASH;            
            break;
        }

        case APP_STATE_SPLASH:
        {
            if (APP_IsSplashScreenComplete())
            {
                laContext_SetActiveScreen(MainScreen_ID);                

                appData.state = APP_STATE_DRAW;
            }
            break;
        }
        
        case APP_STATE_DRAW:
        {
            // Do not continue to trigger any redraw if any layer hasn't been completely drawn
            if (laContext_IsDrawing())
                break;

            if (laContext_GetActiveScreen() && 
                laContext_GetActiveScreen()->id != MainScreen_ID)
                 break;
            
            appData.state = APP_STATE_DONE;
            break;
        }

        case APP_STATE_DONE:
        {
            break;
        }
    }
}

 

/*******************************************************************************
 End of File
 */
