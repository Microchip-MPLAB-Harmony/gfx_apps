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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdio.h>
#include "app.h"
#include "app_splash.h"
#include "gfx/hal/inc/gfx_context.h"
#include "gfx/libaria/libaria_init.h"

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

int32_t minx_Left = 0;
int32_t maxx_Left = 0;

int32_t minx_Right = 0;
int32_t maxx_Right = 0;

int32_t miny = 0;
int32_t maxy = 0;

void APP_SetChevronVisibility(bool);

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

static void touchDown(laWidget* widget, laInput_TouchDownEvent* evt)
{
    if (appData.moveLeftTrayIn || appData.moveLeftTrayOut || appData.moveRightTrayIn || appData.moveRightTrayOut)
    {
        evt->event.accepted = LA_FALSE;
    }
    else
    {
        evt->event.accepted = LA_TRUE;
    }
}

static void touchUp(laWidget* widget, laInput_TouchUpEvent* evt)
{
    if (appData.moveLeftTrayIn || appData.moveLeftTrayOut || appData.moveRightTrayIn || appData.moveRightTrayOut)
    {
        evt->event.accepted = LA_FALSE;
    }
    else
    {
        evt->event.accepted = LA_TRUE;
    }
}

static void touchMovedLeft(laWidget* widget, laInput_TouchMovedEvent* evt)
{
    int32_t dx;
    
    if (evt->x > GFX_ActiveContext()->display_info->rect.width / 2)
    {
        //Ignore touch request that is not in the correct position 
        evt->event.accepted = LA_FALSE;
        return;
    }
    
    dx = evt->x - evt->prevX;
    
    if (widget == (laWidget*)LeftTrayLid || widget == (laWidget*)LeftTrayPanel)
    {
		//This is to check if the movement is greater than 30 pixels
		if (abs(dx) > 30)
        {
			//If the movement is significant, we set the flag such that the remainder of the tray movement will
			//be handled by the state machine and the tray would slide in or out fully
            if (dx > 0)
            {
                appData.moveLeftTrayOut = true;            
            }
            else
            {
                appData.moveLeftTrayIn = true;            
            }
        }
    }    

	//The movement is amplified to make sure the tray mimics the movement the finger as close as possible.
	//The value is derived from trial and error
    dx *= 5;
    
    if(LeftTrayPanel->rect.x + dx < minx_Left)
    {
        laWidget_SetPosition((laWidget*)LeftTrayPanel, minx_Left, LeftTrayPanel->rect.y);
        APP_SetChevronVisibility(false);
    }        
    else if(LeftTrayPanel->rect.x + dx > maxx_Left)
    {
        laWidget_SetPosition((laWidget*)LeftTrayPanel, maxx_Left, LeftTrayPanel->rect.y);        
        APP_SetChevronVisibility(true);
    }
    else
    {
        laWidget_Translate((laWidget*)LeftTrayPanel, dx, 0);
        APP_SetChevronVisibility(false);
    }    
    
    evt->event.accepted = LA_TRUE;
}

static void touchMovedRight(laWidget* widget, laInput_TouchMovedEvent* evt)
{
    int32_t dx;
    
    dx = evt->x - evt->prevX;
    
    if (evt->x < GFX_ActiveContext()->display_info->rect.width / 2)
    {
        //Ignore touch request that is not in the correct position 
        evt->event.accepted = LA_FALSE;
        return;
    }

    if (widget == (laWidget*)RightTrayLid || widget == (laWidget*)RightTrayPanel)
    {
		//This is to check if the movement is greater than 30 pixels
		if (abs(dx) > 30)
        {
			//If the movement is significant, we set the flag such that the remainder of the tray movement will
			//be handled by the state machine and the tray would slide in or out fully
			if (dx < 0)
            {
                appData.moveRightTrayOut = true;
            }
            else
            {
                appData.moveRightTrayIn = true;
            }                        
        }        
    }    

	//The movement is amplified to make sure the tray mimics the movement the finger as close as possible.
	//The value is derived from trial and error
	dx *= 3;
    
    if(RightTrayPanel->rect.x + dx < minx_Right)
    {
        laWidget_SetPosition((laWidget*)RightTrayPanel, minx_Right, RightTrayPanel->rect.y);
    }        
    else if(RightTrayPanel->rect.x + dx > maxx_Right)
    {
        laWidget_SetPosition((laWidget*)RightTrayPanel, maxx_Right, RightTrayPanel->rect.y);        
    }
    else
    {
        laWidget_Translate((laWidget*)RightTrayPanel, dx, 0);
    }    
    
    evt->event.accepted = LA_TRUE;
}

static void touchMovedUpDown(laWidget* widget, laInput_TouchMovedEvent* evt)
{
    int32_t dy;
    
    dy = evt->y - evt->prevY;
    
	//The movement is amplified to make sure the vertical movement mimics the finger as close as possible.
	//The value is derived from trial and error
	dy *= 3;
    dy /= 2;
    
    if(InfoTextDragPanel->widget.rect.y + dy < miny)
    {
        laWidget_SetPosition((laWidget*)InfoTextDragPanel, InfoTextDragPanel->widget.rect.x, miny);
    }        
    else if(InfoTextDragPanel->widget.rect.y + dy > maxy)
    {
        laWidget_SetPosition((laWidget*)InfoTextDragPanel, InfoTextDragPanel->widget.rect.x, maxy);        
    }
    else
    {
        laWidget_Translate((laWidget*)InfoTextDragPanel, 0, dy);
    }    
    
    evt->event.accepted = LA_TRUE;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

void APP_SelectItem(int32_t value)
{
    static bool bufferFill = false;
    
    if (!laContext_IsDrawing() && bufferFill == true)
    {
        laWidget_Invalidate(&laContext_GetActiveScreen()->layers[0]->widget);
        bufferFill = false;
    }
    
    if (value == appData.mode)
        return;
    
    switch(value)
    {
        case MODE_AC:
        {
            laWidget_SetEnabled((laWidget*)ClimateControlPanel, LA_TRUE);
            laWidget_SetVisible((laWidget*)ClimateControlPanel, LA_TRUE);
            laWidget_SetEnabled((laWidget*)NavPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)NavPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)PhonePanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)PhonePanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)BluetoothPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)BluetoothPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)MusicPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)MusicPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)ListContacts, LA_FALSE);
            laWidget_SetVisible((laWidget*)ListContacts, LA_FALSE);
            break;
        }
        case MODE_NAV:
        {
            laWidget_SetEnabled((laWidget*)NavPanel, LA_TRUE);
            laWidget_SetVisible((laWidget*)NavPanel, LA_TRUE);
            laWidget_SetEnabled((laWidget*)PhonePanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)PhonePanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)BluetoothPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)BluetoothPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)MusicPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)MusicPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)ClimateControlPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)ClimateControlPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)ListContacts, LA_FALSE);
            laWidget_SetVisible((laWidget*)ListContacts, LA_FALSE);
            break;
        }
        case MODE_BT:
        {
            laWidget_SetEnabled((laWidget*)BluetoothPanel, LA_TRUE);
            laWidget_SetVisible((laWidget*)BluetoothPanel, LA_TRUE);
            laWidget_SetEnabled((laWidget*)NavPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)NavPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)PhonePanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)PhonePanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)MusicPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)MusicPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)ClimateControlPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)ClimateControlPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)ListContacts, LA_FALSE);
            laWidget_SetVisible((laWidget*)ListContacts, LA_FALSE);
            break;
        }
        case MODE_MUSIC:
        {
            laWidget_SetEnabled((laWidget*)MusicPanel, LA_TRUE);
            laWidget_SetVisible((laWidget*)MusicPanel, LA_TRUE);
            laWidget_SetEnabled((laWidget*)NavPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)NavPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)PhonePanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)PhonePanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)BluetoothPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)BluetoothPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)ClimateControlPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)ClimateControlPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)ListContacts, LA_FALSE);
            laWidget_SetVisible((laWidget*)ListContacts, LA_FALSE);
            break;
        }
        case MODE_PHONE:
        {
            laWidget_SetEnabled((laWidget*)PhonePanel, LA_TRUE);
            laWidget_SetVisible((laWidget*)PhonePanel, LA_TRUE);
            laWidget_SetEnabled((laWidget*)ListContacts, LA_TRUE);
            laWidget_SetVisible((laWidget*)ListContacts, LA_TRUE);
            laWidget_SetEnabled((laWidget*)NavPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)NavPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)BluetoothPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)BluetoothPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)MusicPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)MusicPanel, LA_FALSE);
            laWidget_SetEnabled((laWidget*)ClimateControlPanel, LA_FALSE);
            laWidget_SetVisible((laWidget*)ClimateControlPanel, LA_FALSE);
            break;
        }
    }
    
    appData.mode = value;
    bufferFill = true;
}


void APP_SetChevronVisibility(bool enable)
{
    laBool la_enable = enable == true ? LA_TRUE : LA_FALSE;

    //laWidget_SetEnabled((laWidget*)ImageChevronUp, la_enable);
    laWidget_SetVisible((laWidget*)ImageChevronUp, la_enable);
    //laWidget_SetEnabled((laWidget*)ImageChevronDown, la_enable);
    laWidget_SetVisible((laWidget*)ImageChevronDown, la_enable);
    
    laWidget_Invalidate(PanelUpChevron);
    laWidget_Invalidate(PanelDownChevron);
}

void APP_ToggleGPU( void )
{
    appData.isGPUOn = !appData.isGPUOn;
    appData.gpuButtonNeedsUpdate = true;

    if (appData.isGPUOn)
    {
        GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);       
    }
    else
    {
        GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCU);               
    }    
}

void APP_GoToSplashState ( void )
{
    appData.state = APP_STATE_SPLASH;    
}

void APP_GoToInfoState( void )
{
    appData.state = APP_STATE_INFO;        
}

void APP_GoToMainState( void )
{
    appData.state = APP_STATE_MAIN_TRANSITION;                     
    appData.gpuButtonNeedsUpdate = true;
    appData.delayCounter = 0;
    appData.baseLayerAlpha = 0;
    appData.upperLayerAlpha = 0;
    
    laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[0], appData.baseLayerAlpha);
    laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[1], appData.upperLayerAlpha);
    laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[2], appData.upperLayerAlpha);
}

void APP_ACMode(int32_t mode)
{
    appData.acMode = mode;
}

void APP_ACIntake(int32_t mode)
{
    appData.intakeMode = mode;
}

void APP_SyncAC(void)
{
    static char charBuff[2];
    laString str;

    appData.leftTemp = appData.rightTemp;
    
    sprintf(charBuff, "%u", appData.rightTemp);

    str = laString_CreateFromCharBuffer(charBuff, 
        GFXU_StringFontIndexLookup(&stringTable, string_String_TempCelcius, 0));
    
    laLabelWidget_SetText(LabelCelciusRight, str);
    laLabelWidget_SetText(LabelCelciusLeft, str);
    
    laString_Destroy(&str);

    laWidget_Invalidate((laWidget*)LabelCelciusLeft);
    laWidget_Invalidate((laWidget*)LabelCelciusRight);
}

void APP_RightACChange(int32_t value)
{
    static char charBuff[2];
    laString str;
    
    value /= 10;
    appData.rightTemp = 4 + value;

    sprintf(charBuff, "%u", appData.rightTemp);

    str = laString_CreateFromCharBuffer(charBuff, 
        GFXU_StringFontIndexLookup(&stringTable, string_String_TempCelcius, 0));
    
    laLabelWidget_SetText(LabelCelciusRight, str);
    
    laString_Destroy(&str);
}

void APP_LeftACChange(int32_t value)
{
    static char charBuff[2];
    laString str;
    
    value /= 10;
    appData.leftTemp = 4 + value;

    sprintf(charBuff, "%u", appData.leftTemp);
    
    str = laString_CreateFromCharBuffer(charBuff, 
        GFXU_StringFontIndexLookup(&stringTable, string_String_TempCelcius, 0));
    
    laLabelWidget_SetText(LabelCelciusLeft, str);
    
    laString_Destroy(&str);
}

void APP_MusicShuffle(void)
{
    int index = laRadialMenuWidget_GetProminentIndex(MusicSelector);

    index += 5;
    
    if (index >= MusicSelector->widgetList.size)
    {
        index = index - MusicSelector->widgetList.size;
    }
    
    laRadialMenuWidget_SetProminentIndex(MusicSelector, index);
}

void APP_MusicPlayTrack(void)
{
    int index = laRadialMenuWidget_GetProminentIndex(MusicSelector);

    index++;
    
    if (index >= MusicSelector->widgetList.size)
    {
        index = index - MusicSelector->widgetList.size;
    }

    laRadialMenuWidget_SetProminentIndex(MusicSelector, index);
}

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
    appData.launched = false;

    appData.isGPUOn = true;
    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);       
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
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
            if (laContext_GetActiveScreen() && 
                laContext_GetActiveScreen()->id != SplashScreen_ID)
                 break;
           
            if (APP_IsSplashScreenComplete())
            {
                if (!appData.launched)
                {
                    appData.launched = true;
                    
                    APP_GoToMainState();

#ifdef APP_USES_ARIA_GFX_RTOS                   
                    laContext_SendSetActiveScreenEvent_Ext_RTOS(1);
#else                    
                    laContext_SetActiveScreen(MainScreen_ID);
#endif                    
                }
                else
                {
                    appData.state = APP_STATE_INFO;
#ifdef APP_USES_ARIA_GFX_RTOS                    
                    laContext_SendSetActiveScreenEvent_Ext_RTOS(2);
#else
                    laContext_SetActiveScreen(InfoScreen_ID);
#endif                    
                }
            }
        
            break;
        }
        case APP_STATE_MAIN_TRANSITION:
        {
            // Do not continue to trigger any redraw if any layer hasn't been completely drawn
            if (laContext_IsDrawing())
                break;
                
            if (laContext_GetActive()->activeScreen->id != MainScreen_ID)
                break;

            if (appData.delayCounter++ > 100)
            {
                if (appData.baseLayerAlpha < 255)
                {
                    laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[0], appData.baseLayerAlpha++);
                }

                if (appData.upperLayerAlpha < 210)
                {
                    laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[1], appData.upperLayerAlpha);
                    laLayer_SetAlphaAmount(laContext_GetActiveScreen()->layers[2], appData.upperLayerAlpha);
                    
                    appData.upperLayerAlpha++;
                }
                
                appData.delayCounter = 0;
            }
            
            if (appData.baseLayerAlpha >= 255 && appData.upperLayerAlpha >= 210)
            {
                appData.state = APP_STATE_MAIN;
                
                minx_Left = ModeSelector->widget.rect.width * -1;
                maxx_Left = 0;
                minx_Right = GFX_ActiveContext()->display_info->rect.width - RightTrayPanel->rect.width;
                maxx_Right = GFX_ActiveContext()->display_info->rect.width - RightTrayLid->widget.rect.width;                

                laWidget_OverrideTouchMovedEvent((laWidget*)LeftTrayLid, &touchMovedLeft);
                laWidget_OverrideTouchMovedEvent((laWidget*)RightTrayLid, &touchMovedRight);

                laWidget_OverrideTouchDownEvent((laWidget*)LeftTrayPanel, &touchDown);
                laWidget_OverrideTouchMovedEvent((laWidget*)LeftTrayPanel, &touchMovedLeft);
                laWidget_OverrideTouchUpEvent((laWidget*)LeftTrayPanel, &touchUp);                

                laWidget_OverrideTouchDownEvent((laWidget*)RightTrayPanel, &touchDown);
                laWidget_OverrideTouchMovedEvent((laWidget*)RightTrayPanel, &touchMovedRight);
                laWidget_OverrideTouchUpEvent((laWidget*)RightTrayPanel, &touchUp);
                
                APP_SelectItem(laRadialMenuWidget_GetProminentIndex(ModeSelector));
            }
            break;
        }            

        case APP_STATE_MAIN:
        {
            // Do not continue to trigger any redraw if any layer hasn't been completely drawn
            if (laContext_IsDrawing())
                break;
                
            if (laContext_GetActive()->activeScreen->id != MainScreen_ID)
                break;

            if (LeftTrayPanel != NULL && LeftTrayLid != NULL
                    && RightTrayPanel != NULL && RightTrayLid != NULL)
            {
                if (appData.gpuButtonNeedsUpdate == true)
                {                    
                    if (appData.isGPUOn == true)
                    {
                        if (LabelGPU != NULL)
                        {
                            laLabelWidget_SetText(LabelGPU, laString_CreateFromID(string_String_GPUOn));
                            laWidget_Invalidate((laWidget*)ButtonGPU);
                        }        
                    }
                    else
                    {
                        if (LabelGPU != NULL)
                        {
                            laLabelWidget_SetText(LabelGPU, laString_CreateFromID(string_String_GPUOff));            
                            laWidget_Invalidate((laWidget*)ButtonGPU);
                        }        
                    }
                    
#ifdef APP_USES_ARIA_GFX_RTOS
                    laContext_RefreshActiveScreen_Ext_RTOS();
#endif                    
                    appData.gpuButtonNeedsUpdate = false;                    
                }
                
                if (appData.moveRightTrayOut)
                {
                    if (laWidget_GetX(RightTrayPanel) > (minx_Right + 5))
                    {
                        laWidget_Translate((laWidget*)RightTrayPanel, (minx_Right - laWidget_GetX(RightTrayPanel))*3/4, 0);
                    }
                    else
                    {
                        laWidget_SetPosition((laWidget*)RightTrayPanel, minx_Right, RightTrayPanel->rect.y);        
                        appData.moveRightTrayOut = false;
                    }
#ifdef APP_USES_ARIA_GFX_RTOS
                    laContext_RefreshActiveScreen_Ext_RTOS();
#endif
                }
                
                if (appData.moveRightTrayIn)
                {
                    if (laWidget_GetX(RightTrayPanel) < (maxx_Right - 5))
                    {
                        laWidget_Translate((laWidget*)RightTrayPanel, (maxx_Right - laWidget_GetX(RightTrayPanel))*3/4, 0);
                    }
                    else
                    {
                        laWidget_SetPosition((laWidget*)RightTrayPanel, maxx_Right, RightTrayPanel->rect.y);        
                        appData.moveRightTrayIn = false;
                    }

#ifdef APP_USES_ARIA_GFX_RTOS
                    laContext_RefreshActiveScreen_Ext_RTOS();
#endif
                }

                if (appData.moveLeftTrayOut)
                {
                    if (laWidget_GetX(LeftTrayPanel) < (maxx_Left - 5))
                    {
                        laWidget_Translate((laWidget*)LeftTrayPanel, (maxx_Left - laWidget_GetX(LeftTrayPanel))*3/4, 0);

                        APP_SetChevronVisibility(false);
                    }
                    else
                    {
                        laWidget_SetPosition((laWidget*)LeftTrayPanel, maxx_Left, LeftTrayPanel->rect.y);        
                        appData.moveLeftTrayOut = false;
                        
                        APP_SetChevronVisibility(true);
                    }
                    
#ifdef APP_USES_ARIA_GFX_RTOS
                    laContext_RefreshActiveScreen_Ext_RTOS();
#endif
                }

                if (appData.moveLeftTrayIn)
                {
                    if (laWidget_GetX(LeftTrayPanel) > (minx_Left + 5))
                    {
                        laWidget_Translate((laWidget*)LeftTrayPanel, (minx_Left - laWidget_GetX(LeftTrayPanel))*3/4, 0);

                        APP_SetChevronVisibility(false);
                    }
                    else
                    {
                        laWidget_SetPosition((laWidget*)LeftTrayPanel, minx_Left, LeftTrayPanel->rect.y);        
                        appData.moveLeftTrayIn = false;

                        APP_SetChevronVisibility(false);
                    }
                    
#ifdef APP_USES_ARIA_GFX_RTOS
                    laContext_RefreshActiveScreen_Ext_RTOS();
#endif
                }                
            }
            break;
        }
        
        case APP_STATE_INFO:
        {
             // Do not continue to trigger any redraw if any layer hasn't been completely drawn
            if (laContext_IsDrawing())
                break;

            if (laContext_GetActive()->activeScreen->id != 2)
                break;
            
            if (InfoTextDragPanel != NULL)
            {
                miny = 0 - InfoTextDragPanel->widget.rect.height;
                maxy = 0;

                laWidget_OverrideTouchDownEvent((laWidget*)InfoTextDragPanel, &touchDown);
                laWidget_OverrideTouchMovedEvent((laWidget*)InfoTextDragPanel, &touchMovedUpDown);
                laWidget_OverrideTouchUpEvent((laWidget*)InfoTextDragPanel, &touchUp);
            }
            break;
        }
    }
}

/*******************************************************************************
 End of File
 */
