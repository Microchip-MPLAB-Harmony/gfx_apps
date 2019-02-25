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

void APP_GoToMain( void )
{
    appData.state = APP_STATE_MAIN;
}

void APP_CycleLanguage( void )
{
    uint32_t language = laContext_GetStringLanguage();
    
    if(language == language_English)
    {
        laContext_SetStringLanguage(language_Chinese);
    }
    else if(language == language_Chinese)
    {
        laContext_SetStringLanguage(language_Spanish);
    }
    else if(language == language_Spanish)
    {
        laContext_SetStringLanguage(language_English);
    }
}

void APP_UpdateItemSelected( void )
{
    if (laContext_IsDrawing())
        return;

    if (laContext_GetActiveScreen() && 
        laContext_GetActiveScreen()->id != ItemScreen_ID)
        return;
    
    if (appData.state != APP_STATE_ITEM)
        return;

    laWidget_SetEnabled(PanelLoading_Item, LA_FALSE);
    laWidget_SetVisible(PanelLoading_Item, LA_FALSE);
    laWidget_SetEnabled((laWidget*)ImageLoading_Item, LA_FALSE);
    laWidget_SetVisible((laWidget*)ImageLoading_Item, LA_FALSE);

    laImageWidget_SetImage(ImageItem_Item, appData.items[appData.itemSelected].image);
}

void APP_PopulateMenuItems( void )
{
    int i = 0;
    int itemsPerPage = 6;
    
    for(i = 0; i < itemsPerPage; ++i)
    {
        appData.menuItems[i] = appData.items[i + appData.currentPage * itemsPerPage];

        if (appData.menuItems[i].image != NULL)
        {
            laButtonWidget_SetPressedImage(appData.itemButtons[i], appData.menuItems[i].image);
            laButtonWidget_SetReleasedImage(appData.itemButtons[i], appData.menuItems[i].image);
        }
    }
}

void APP_PageUp( void )
{
    if (laContext_IsDrawing())
        return;

    if (laContext_GetActiveScreen() && 
        laContext_GetActiveScreen()->id != MainScreen_ID)
        return;
    
    if (appData.state != APP_STATE_MAIN)
        return;

    appData.state = APP_STATE_MAIN_LOADING;
    appData.loadTickCounter = 0;
    appData.loadTime = 0;
    
    laWidget_SetEnabled(PanelLoading_Main, LA_TRUE);
    laWidget_SetVisible(PanelLoading_Main, LA_TRUE);
    laWidget_SetEnabled((laWidget*)ImageLoading_Main, LA_TRUE);
    laWidget_SetVisible((laWidget*)ImageLoading_Main, LA_TRUE);

    if (--appData.currentPage < 0)
    {
        appData.currentPage = appData.totalPages - 1;
    }
}

void APP_PageDown( void )
{
    if (laContext_IsDrawing())
        return;

    if (laContext_GetActiveScreen() && 
        laContext_GetActiveScreen()->id != MainScreen_ID)
        return;
    
    if (appData.state != APP_STATE_MAIN)
        return;

    appData.state = APP_STATE_MAIN_LOADING; 
    appData.loadTickCounter = 0;
    appData.loadTime = 0;

    laWidget_SetEnabled(PanelLoading_Main, LA_TRUE);
    laWidget_SetVisible(PanelLoading_Main, LA_TRUE);
    laWidget_SetEnabled((laWidget*)ImageLoading_Main, LA_TRUE);
    laWidget_SetVisible((laWidget*)ImageLoading_Main, LA_TRUE);

    if (++appData.currentPage >= appData.totalPages)
    {
        appData.currentPage = 0;
    }
}

void APP_ItemSelect(int itemNum)
{
    if (laContext_IsDrawing())
        return;

    if (laContext_GetActiveScreen() && 
        laContext_GetActiveScreen()->id != MainScreen_ID)
        return;
    
    if (appData.state != APP_STATE_MAIN)
        return;

    laContext_SetActiveScreen(ItemScreen_ID);                

    appData.state = APP_STATE_ITEM_LOADING;
    
    appData.itemSelected = itemNum + appData.currentPage * APP_NUM_ITEMS_PER_PAGE;

    if(appData.itemSelected > appData.totalItems)
    {
        appData.itemSelected = appData.totalItems - 1;
    }
}

void APP_HandleLoadIcon( void )
{
    // Do not continue to trigger any redraw if any layer hasn't been completely drawn
    if (laContext_IsDrawing())
        return;

    if (laContext_GetActiveScreen()->id != MainScreen_ID &&
        laContext_GetActiveScreen()->id != ItemScreen_ID)
         return;

    if (appData.loadTickCounter++ < 500)
        return;

    if (laContext_GetActiveScreen()->id == MainScreen_ID)
    {
        laImageSequenceWidget_ShowNextImage(ImageLoading_Main);
    }
    else
    {
        laImageSequenceWidget_ShowNextImage(ImageLoading_Item);
    }
    appData.loadTickCounter = 0;
    appData.loadTime++;

    if (appData.loadTime >= 12)
    {
        if (laContext_GetActiveScreen()->id == MainScreen_ID)
        {
            appData.needPopulateMenu = true;
            appData.state = APP_STATE_MAIN;
        }
        else
        {
            appData.state = APP_STATE_ITEM;
        }
    }
}

void APP_StockItems( void )
{
    int i = 0;
    
    appData.items[0].image = &Premium_Beer_Icons_01;
    appData.items[0].string = laString_CreateFromID(string_String_Price);
    appData.items[1].image = &Premium_Beer_Icons_02;
    appData.items[1].string = laString_CreateFromID(string_String_Price);
    appData.items[2].image = &Premium_Beer_Icons_03;
    appData.items[2].string = laString_CreateFromID(string_String_Price);
    appData.items[3].image = &Premium_Beer_Icons_04;
    appData.items[3].string = laString_CreateFromID(string_String_Price);
    appData.items[4].image = &Premium_Beer_Icons_05;
    appData.items[4].string = laString_CreateFromID(string_String_Price);
    appData.items[5].image = &Premium_Beer_Icons_06;
    appData.items[5].string = laString_CreateFromID(string_String_Price);

    appData.items[6].image = &Premium_Beer_Icons_07;
    appData.items[6].string = laString_CreateFromID(string_String_Price);
    appData.items[7].image = &Premium_Beer_Icons_08;
    appData.items[7].string = laString_CreateFromID(string_String_Price);
    appData.items[8].image = &Premium_Beer_Icons_09;
    appData.items[8].string = laString_CreateFromID(string_String_Price);
    appData.items[9].image = &Premium_Beer_Icons_10;
    appData.items[9].string = laString_CreateFromID(string_String_Price);
    appData.items[10].image = &Premium_Beer_Icons_11;
    appData.items[10].string = laString_CreateFromID(string_String_Price);
    appData.items[11].image = &Premium_Beer_Icons_12;
    appData.items[11].string = laString_CreateFromID(string_String_Price);

    appData.items[12].image = &Premium_Beer_Icons_13;
    appData.items[12].string = laString_CreateFromID(string_String_Price);
    appData.items[13].image = &Premium_Beer_Icons_14;
    appData.items[13].string = laString_CreateFromID(string_String_Price);
    appData.items[14].image = &Premium_Beer_Icons_15;
    appData.items[14].string = laString_CreateFromID(string_String_Price);
    appData.items[15].image = &Premium_Beer_Icons_16;
    appData.items[15].string = laString_CreateFromID(string_String_Price);
    appData.items[16].image = &Premium_Beer_Icons_17;
    appData.items[16].string = laString_CreateFromID(string_String_Price);
    appData.items[17].image = &Premium_Beer_Icons_18;
    appData.items[17].string = laString_CreateFromID(string_String_Price);

    appData.items[18].image = &Long_Frank_Beer_Icons_01;
    appData.items[18].string = laString_CreateFromID(string_String_Price);
    appData.items[19].image = &Long_Frank_Beer_Icons_02;
    appData.items[19].string = laString_CreateFromID(string_String_Price);
    appData.items[20].image = &Long_Frank_Beer_Icons_03;
    appData.items[20].string = laString_CreateFromID(string_String_Price);
    appData.items[21].image = &Long_Frank_Beer_Icons_04;
    appData.items[21].string = laString_CreateFromID(string_String_Price);
    appData.items[22].image = &Long_Frank_Beer_Icons_05;
    appData.items[22].string = laString_CreateFromID(string_String_Price);
    appData.items[23].image = &Long_Frank_Beer_Icons_06;
    appData.items[23].string = laString_CreateFromID(string_String_Price);

    appData.items[24].image = &Lager_Icons_01;
    appData.items[24].string = laString_CreateFromID(string_String_Price);
    appData.items[25].image = &Lager_Icons_02;
    appData.items[25].string = laString_CreateFromID(string_String_Price);
    appData.items[26].image = &Lager_Icons_03;
    appData.items[26].string = laString_CreateFromID(string_String_Price);
    appData.items[27].image = &Lager_Icons_04;
    appData.items[27].string = laString_CreateFromID(string_String_Price);
    appData.items[28].image = &Lager_Icons_05;
    appData.items[28].string = laString_CreateFromID(string_String_Price);
    appData.items[29].image = &Lager_Icons_06;
    appData.items[29].string = laString_CreateFromID(string_String_Price);

    appData.totalItems = 30;
    appData.currentPage = 0;
    
    appData.totalPages = appData.totalItems / APP_NUM_ITEMS_PER_PAGE;

    //Populate valid indices
    for (i = 0; i < 36; i++)
    {
        if (i < appData.totalItems)
        {
            appData.items[i].idx = i;
        }
        else
        {
            appData.items[i].idx = -1;
        }
    }
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

                appData.state = APP_STATE_LOAD_ITEMS;
            }
            break;
        }
        
        case APP_STATE_LOAD_ITEMS:
        {
            APP_StockItems();
            
            appData.needPopulateMenu = true;
            appData.state = APP_STATE_MAIN;
            break;
        }
        
        case APP_STATE_MAIN_LOADING:
        case APP_STATE_ITEM_LOADING:
        {
            APP_HandleLoadIcon();
            break;
        }

        case APP_STATE_MAIN:
        {
            if (laContext_IsDrawing())
                return;

            if (laContext_GetActiveScreen() && 
                laContext_GetActiveScreen()->id != MainScreen_ID)
                return;

            if (appData.needPopulateMenu == true)
            {
                appData.itemButtons[0] = ButtonItem0;
                appData.itemButtons[1] = ButtonItem1;
                appData.itemButtons[2] = ButtonItem2;
                appData.itemButtons[3] = ButtonItem3;
                appData.itemButtons[4] = ButtonItem4;
                appData.itemButtons[5] = ButtonItem5;

                APP_PopulateMenuItems();
                
                laWidget_SetEnabled(PanelLoading_Main, LA_FALSE);
                laWidget_SetVisible(PanelLoading_Main, LA_FALSE);
                laWidget_SetEnabled((laWidget*)ImageLoading_Main, LA_FALSE);
                laWidget_SetVisible((laWidget*)ImageLoading_Main, LA_FALSE);

                appData.needPopulateMenu = false;
            }
            break;
        }
        case APP_STATE_ITEM:
        {
            APP_UpdateItemSelected();
            break;
        }
        
        default:
        {
            break;
        }
    }
}

 

/*******************************************************************************
 End of File
 */
