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
#include "gfx/hal/inc/gfx_math.h"
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

static void touchDownNav(laWidget* widget, laInput_TouchDownEvent* evt)
{
    APP_MoveTrayIn();
    
    switch(evt->touchID)
    {
        case 0:
        {
            appData.touchDown0 = true;
            break;
        }
        case 1:
        {
            appData.touchDown1 = true;
            break;
        }
    }

    evt->event.accepted = LA_TRUE;
}

static void touchUpNav(laWidget* widget, laInput_TouchUpEvent* evt)
{
    APP_MoveTrayIn();

    switch(evt->touchID)
    {
        case 0:
        {
            appData.touchDown0 = false;
            break;
        }
        case 1:
        {
            appData.touchDown1 = false;
            break;
        }
    }

    evt->event.accepted = LA_TRUE;
}

static void touchMoveNav(laWidget* widget, laInput_TouchMovedEvent* evt)
{
    APP_MoveTrayIn();

    evt->event.accepted = LA_TRUE;
    int32_t dx = evt->x - evt->prevX;
    int32_t dy = evt->y - evt->prevY;
    
    switch(evt->touchID)
    {
        case 0:
        {
            // image translate
            if(appData.touchDown1 == false)
            {
                NavMap->transformX += dx;
                NavMap->transformY += dy;
            }
            else if (appData.touchDown0 == true 
                    && appData.touchDown1 == true)
            {
                dy *= 3;
                dx = ((dy * 100) * (int32_t)appData.aspectRatio) / 10000;

                if (NavMap->touch0.y > NavMap->touch1.y)
                {
                    if ((NavMap->widget.rect.width - 2 * NavMap->transformX) < (NavMap->image->width + NavMap->transformWidth + dx)
                            && (NavMap->widget.rect.height - 2 * NavMap->transformY) < (NavMap->image->height + NavMap->transformHeight + dy))
                    {
                        NavMap->transformWidth += dx;
                        NavMap->transformHeight += dy;
                    }
                }
                else
                {
                    if ((NavMap->widget.rect.width - 2 * NavMap->transformX) < (NavMap->image->width + NavMap->transformWidth - dx)
                            && (NavMap->widget.rect.height - 2 * NavMap->transformY) < (NavMap->image->height + NavMap->transformHeight - dy))
                    {
                        NavMap->transformWidth -= dx;
                        NavMap->transformHeight -= dy;
                    }
                }
            }
            NavMap->touch0.x = evt->x;
            NavMap->touch0.y = evt->y;
            break;
        }
        case 1:
        {
            if (appData.touchDown0 == true 
                    && appData.touchDown1 == true)
            {
                dy *= 3;
                dx = ((dy * 100) * (int32_t)appData.aspectRatio) / 10000;

                if (NavMap->touch0.y > NavMap->touch1.y)
                {
                    if ((NavMap->widget.rect.width - 2 * NavMap->transformX) < (NavMap->image->width + NavMap->transformWidth - dx)
                            && (NavMap->widget.rect.height - 2 * NavMap->transformY) < (NavMap->image->height + NavMap->transformHeight - dy))
                    {
                        NavMap->transformWidth -= dx;
                        NavMap->transformHeight -= dy;
                    }
                }
                else
                {
                    if ((NavMap->widget.rect.width - 2 * NavMap->transformX) < (NavMap->image->width + NavMap->transformWidth + dx)
                            && (NavMap->widget.rect.height - 2 * NavMap->transformY) < (NavMap->image->height + NavMap->transformHeight + dy))
                    {
                        NavMap->transformWidth += dx;
                        NavMap->transformHeight += dy;
                    }
                }

                NavMap->touch1.x = evt->x;
                NavMap->touch1.y = evt->y;
            }
            break;
        }
    }
    
    NavMap->preserveAspect = LA_TRUE;
    laWidget_Invalidate((laWidget*)NavMap);
}

static void touchDownGeneric(laWidget* widget, laInput_TouchDownEvent* evt)
{
    APP_MoveTrayIn();
    
    evt->event.accepted = LA_TRUE;
}

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

void APP_ModeUp( void )
{
    int index = laRadialMenuWidget_GetProminentIndex(ModeSelector);

    index++;
    
    if (index >= ModeSelector->widgetList.size)
    {
        index = 0;
    }

    ModeSelector->userRequestedAngleDiff += 40;
    laRadialMenuWidget_SetProminentIndex(ModeSelector, index);
}

void APP_ModeDown( void )
{
    int32_t index = laRadialMenuWidget_GetProminentIndex(ModeSelector);

    index--;
    
    if (index < 0)
    {
        index = index - ModeSelector->widgetList.size;
    }

    ModeSelector->userRequestedAngleDiff -= 40;
    laRadialMenuWidget_SetProminentIndex(ModeSelector, ModeSelector->prominentIndex--);
}

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
            laWidget_SetEnabled((laWidget*)LabelACTempLeft, LA_TRUE);
            laWidget_SetVisible((laWidget*)LabelACTempLeft, LA_TRUE);
            laWidget_SetEnabled((laWidget*)LabelACTempRight, LA_TRUE);
            laWidget_SetVisible((laWidget*)LabelACTempRight, LA_TRUE);
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
            laWidget_SetEnabled((laWidget*)LabelACTempLeft, LA_FALSE);
            laWidget_SetVisible((laWidget*)LabelACTempLeft, LA_FALSE);
            laWidget_SetEnabled((laWidget*)LabelACTempRight, LA_FALSE);
            laWidget_SetVisible((laWidget*)LabelACTempRight, LA_FALSE);
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
            laWidget_SetEnabled((laWidget*)LabelACTempLeft, LA_FALSE);
            laWidget_SetVisible((laWidget*)LabelACTempLeft, LA_FALSE);
            laWidget_SetEnabled((laWidget*)LabelACTempRight, LA_FALSE);
            laWidget_SetVisible((laWidget*)LabelACTempRight, LA_FALSE);
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
            laWidget_SetEnabled((laWidget*)LabelACTempLeft, LA_FALSE);
            laWidget_SetVisible((laWidget*)LabelACTempLeft, LA_FALSE);
            laWidget_SetEnabled((laWidget*)LabelACTempRight, LA_FALSE);
            laWidget_SetVisible((laWidget*)LabelACTempRight, LA_FALSE);
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
            laWidget_SetEnabled((laWidget*)LabelACTempLeft, LA_FALSE);
            laWidget_SetVisible((laWidget*)LabelACTempLeft, LA_FALSE);
            laWidget_SetEnabled((laWidget*)LabelACTempRight, LA_FALSE);
            laWidget_SetVisible((laWidget*)LabelACTempRight, LA_FALSE);
            break;
        }
    }
    
    appData.mode = value;
    bufferFill = true;
}

void APP_HandleTray(int32_t value)
{
    switch (value)
    {
        case 0:
        {
            if (LeftTrayPanel->rect.x >= maxx_Left)
            {
                APP_MoveTrayIn();
            }
            else if (LeftTrayPanel->rect.x <= minx_Left)
            {
                appData.moveLeftTrayOut = true;
                appData.moveLeftTrayIn = false;
            }
            break;
        }
        case 1:
        {
            if (RightTrayPanel->rect.x <= minx_Right)
            {
                APP_MoveTrayIn();
            }
            else if (RightTrayPanel->rect.x >= maxx_Right)
            {
                appData.moveRightTrayOut = true;
                appData.moveRightTrayIn = false;
            }
            break;
        }
    }
}

void APP_MoveTrayIn( void )
{
    appData.moveLeftTrayIn = true;
    appData.moveRightTrayIn = true;
    appData.moveLeftTrayOut = false;
    appData.moveRightTrayOut = false;
}

void APP_SetChevronVisibility(bool enable)
{
    laBool la_enable = enable == true ? LA_TRUE : LA_FALSE;

    laWidget_SetEnabled((laWidget*)ButtonChevronUp, la_enable);
    laWidget_SetVisible((laWidget*)ButtonChevronUp, la_enable);
    laWidget_SetEnabled((laWidget*)ButtonChevronDown, la_enable);
    laWidget_SetVisible((laWidget*)ButtonChevronDown, la_enable);
    
    laWidget_Invalidate(PanelUpChevron);
    laWidget_Invalidate(PanelDownChevron);
}

void APP_ToggleGPU( void )
{
    //Do not process request unless the tray is completely out
    if (RightTrayPanel->rect.x > minx_Right)
    {
        return;
    }

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
    appData.state = APP_STATE_MAIN_PRETRANSITION;                     
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
    //Set the button states directly to avoid triggering button events
    switch(mode)
    {
        case MODE_FACE:
            ButtonACFace->state = LA_BUTTON_STATE_DOWN;
            ButtonACBoth->state = LA_BUTTON_STATE_UP;
            ButtonACFeet->state = LA_BUTTON_STATE_UP;
            break;
        case MODE_BOTH:
            ButtonACFace->state = LA_BUTTON_STATE_UP;
            ButtonACBoth->state = LA_BUTTON_STATE_DOWN;
            ButtonACFeet->state = LA_BUTTON_STATE_UP;
            break;
        case MODE_FEET:
            ButtonACFace->state = LA_BUTTON_STATE_UP;
            ButtonACBoth->state = LA_BUTTON_STATE_UP;
            ButtonACFeet->state = LA_BUTTON_STATE_DOWN;
            break;
    }

    laWidget_Invalidate((laWidget*)ButtonACFace);
    laWidget_Invalidate((laWidget*)ButtonACBoth);
    laWidget_Invalidate((laWidget*)ButtonACFeet);
    
    appData.acMode = mode;
}

void APP_ACIntake(int32_t mode)
{
    //Set the button states directly to avoid triggering button events
    switch(mode)
    {
        case MODE_INTAKE:
            ButtonACIntake->state = LA_BUTTON_STATE_DOWN;
            ButtonACLoop->state = LA_BUTTON_STATE_UP;
            break;
        case MODE_LOOP:
            ButtonACIntake->state = LA_BUTTON_STATE_UP;
            ButtonACLoop->state = LA_BUTTON_STATE_DOWN;
            break;
    }

    laWidget_Invalidate((laWidget*)ButtonACIntake);
    laWidget_Invalidate((laWidget*)ButtonACLoop);

    appData.intakeMode = mode;
}

void APP_SyncAC(void)
{
    static char charBuff[5];
    laString str;
    int32_t value;

    appData.rightTemp = appData.leftTemp;
    
    sprintf(charBuff, "%u", appData.rightTemp);

    str = laString_CreateFromCharBuffer(charBuff, &NotoSans_Regular);
    
    value = laCircularSliderWidget_GetValue(CircularSliderACLeft);
    laCircularSliderWidget_SetValue(CircularSliderACRight, value);
    
    laLabelWidget_SetText(LabelACTempLeft, str);
    laLabelWidget_SetText(LabelACTempRight, str);
    
    laWidget_Invalidate((laWidget*)LabelACTempLeft);
    laWidget_Invalidate((laWidget*)LabelACTempRight);

    laString_Destroy(&str);
}

void APP_RightACChange(int32_t value)
{
    static char charBuff[5];
    laString str;
    
    value /= 10;
    appData.rightTemp = 27 - value;

    sprintf(charBuff, "%u", appData.rightTemp);

    str = laString_CreateFromCharBuffer(charBuff, &NotoSans_Regular);
    
    laLabelWidget_SetText(LabelACTempRight, str);

    laString_Destroy(&str);
}

void APP_LeftACChange(int32_t value)
{
    static char charBuff[5];
    laString str;
    
    value /= 10;
    appData.leftTemp = 27 - value;

    sprintf(charBuff, "%u", appData.leftTemp);
    
    str = laString_CreateFromCharBuffer(charBuff, &NotoSans_Regular);
    
    laLabelWidget_SetText(LabelACTempLeft, str);
    
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
    
    MusicSelector->userRequestedAngleDiff += 900;
    laRadialMenuWidget_SetProminentIndex(MusicSelector, index);
}

void APP_MusicPlayTrack(void)
{
    int index = laRadialMenuWidget_GetProminentIndex(MusicSelector);

    index++;
    
    if (index >= MusicSelector->widgetList.size)
    {
        index = 0;
    }

    MusicSelector->userRequestedAngleDiff += 30;
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
    
    appData.acMode = MODE_FACE;
    appData.intakeMode = MODE_INTAKE;
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
        
        //Use this state to set AC modes before the transition
        case APP_STATE_MAIN_PRETRANSITION:
        {
            // Do not continue to trigger any redraw if any layer hasn't been completely drawn
            if (laContext_IsDrawing())
                break;
                
            if (laContext_GetActive()->activeScreen->id != MainScreen_ID)
                break;

            appData.leftTemp = appData.rightTemp = 22;

            APP_ACMode(appData.acMode);
            APP_ACIntake(appData.intakeMode);
            
            appData.aspectRatio = GFX_PercentWholeRounded(NavMap->image->width, NavMap->image->height);

            appData.state = APP_STATE_MAIN_TRANSITION;
            
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

                laWidget_OverrideTouchDownEvent((laWidget*)IconPanel, &touchDownGeneric);
                laWidget_OverrideTouchDownEvent((laWidget*)ClimateControlPanel, &touchDownGeneric);
                laWidget_OverrideTouchDownEvent((laWidget*)NavPanel, &touchDownGeneric);
                laWidget_OverrideTouchDownEvent((laWidget*)PhonePanel, &touchDownGeneric);
                laWidget_OverrideTouchDownEvent((laWidget*)BluetoothPanel, &touchDownGeneric);
                laWidget_OverrideTouchDownEvent((laWidget*)MusicPanel, &touchDownGeneric);
                
                laWidget_OverrideTouchMovedEvent((laWidget*)ButtonNavRead, &touchMoveNav);
                laWidget_OverrideTouchUpEvent((laWidget*)ButtonNavRead, &touchUpNav);                
                laWidget_OverrideTouchDownEvent((laWidget*)ButtonNavRead, &touchDownNav);
                
                APP_SelectItem(MODE_AC);
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

            if (appData.mode == MODE_MUSIC
                    && MusicSelector->state == LA_RADIAL_MENU_HANDLE_USER_MOVE_REQUEST)
            {
                APP_MoveTrayIn();
            }
            
            if (LeftTrayPanel != NULL && LeftTrayLid != NULL
                    && RightTrayPanel != NULL && RightTrayLid != NULL)
            {
                if (appData.gpuButtonNeedsUpdate == true)
                {                    
                    if (appData.isGPUOn == true)
                    {
                        if (LabelGPU != NULL)
                        {
                            laLabelWidget_SetText(LabelGPU, laString_CreateFromID(string_String_GPUOff));
                            laWidget_Invalidate((laWidget*)ButtonGPU);
                        }        
                    }
                    else
                    {
                        if (LabelGPU != NULL)
                        {
                            laLabelWidget_SetText(LabelGPU, laString_CreateFromID(string_String_GPUOn));            
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
