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
#include "bsp/bsp.h"
#include "app_splash.h"
#include "gfx/hal/inc/gfx_math.h"
#include "gfx/hal/inc/gfx_context.h"
#include "gfx/libaria/inc/libaria_context.h"
#include "gfx/gfx_assets.h"
#include "config/glcd_rgba8888_mxt_mzdas_sk/gfx/libaria/libaria_init.h"

extern laScheme defaultScheme;
extern laScheme clearScheme;
extern laScheme labelModeScheme1;
extern laScheme titleLabelScheme;
extern laScheme labelModeScheme0;
extern laScheme labelModeScheme3;
extern laScheme GradientScheme;
extern laScheme labelModeScheme2;
extern laScheme blackScheme;
extern laImageWidget* ImageWidget1;
extern laImageWidget* ImageWidget3;
extern laImageWidget* ImageWidget2;
extern laImageWidget* ImageWidget4;
extern laImageWidget* ImageWidget;
extern laLabelWidget* LabelWidget3;
extern laRadialMenuWidget* RadialMenuWidget_Main;
extern laImagePlusWidget* RadialMenuWidget_Main_Item0;
extern laImagePlusWidget* RadialMenuWidget_Main_Item1;
extern laImagePlusWidget* RadialMenuWidget_Main_Item2;
extern laImagePlusWidget* RadialMenuWidget_Main_Item3;
extern laButtonWidget* InfoButton;
extern laLabelWidget* ModeLabel;
extern laImageWidget* InfoPageHarmonyLogo;
extern laImageWidget* ImageWidget7;
extern laImageWidget* ImageWidget;
extern laWidget* InfoTextDragPanel;
extern laImageWidget* InfoTextImage;
extern laWidget* PanelWidget1;
extern laLabelWidget* TextTitle;
extern laButtonWidget* ReturnToMainButton;
extern laButtonWidget* ButtonWidget;
extern laImageWidget* ImageWidget;
extern laLabelWidget* LabelWidget;
extern laButtonWidget* ButtonWidget4;
extern laRadialMenuWidget* RadialMenuWidget_Album;
extern laImagePlusWidget* RadialMenuWidget_Album_Item0;
extern laImagePlusWidget* RadialMenuWidget_Album_Item1;
extern laImagePlusWidget* RadialMenuWidget_Album_Item2;
extern laImagePlusWidget* RadialMenuWidget_Album_Item3;
extern laImagePlusWidget* RadialMenuWidget_Album_Item4;
extern laImagePlusWidget* RadialMenuWidget_Album_Item5;
extern laImagePlusWidget* RadialMenuWidget_Album_Item6;
extern laImagePlusWidget* RadialMenuWidget_Album_Item7;
extern laImagePlusWidget* RadialMenuWidget_Album_Item8;
extern laImagePlusWidget* RadialMenuWidget_Album_Item9;
extern laButtonWidget* ButtonWidget2;
extern laImageWidget* ImageWidget;
extern laLabelWidget* LabelWidget7;
extern laRadialMenuWidget* RadialMenuWidget_Business;
extern laImagePlusWidget* RadialMenuWidget_Business_Item0;
extern laImagePlusWidget* RadialMenuWidget_Business_Item1;
extern laImagePlusWidget* RadialMenuWidget_Business_Item2;
extern laImagePlusWidget* RadialMenuWidget_Business_Item3;
extern laImagePlusWidget* RadialMenuWidget_Business_Item4;
extern laImagePlusWidget* RadialMenuWidget_Business_Item5;
extern laButtonWidget* ButtonWidget8;
extern laButtonWidget* ButtonWidget6;
extern laLabelWidget* LabelWidget2;
extern laRadialMenuWidget* RadialMenuWidget4;
extern laImagePlusWidget* RadialMenuWidget4_Item0;
extern laImagePlusWidget* RadialMenuWidget4_Item1;
extern laImagePlusWidget* RadialMenuWidget4_Item2;
extern laImagePlusWidget* RadialMenuWidget4_Item3;
extern laImagePlusWidget* RadialMenuWidget4_Item4;
extern laImagePlusWidget* RadialMenuWidget4_Item5;
extern laImagePlusWidget* RadialMenuWidget4_Item6;
extern laButtonWidget* ButtonWidget3;
extern laButtonWidget* ButtonWidget1;

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

int32_t miny = 0;
int32_t maxy = 0;

static void touchDown(laWidget* widget, laInput_TouchDownEvent* evt)
{
	evt->event.accepted = LA_TRUE;
}

static void touchUp(laWidget* widget, laInput_TouchUpEvent* evt)
{
	evt->event.accepted = LA_TRUE;
}

void APP_ToggleGPU(void)
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

static void touchMovedUpDown(laWidget* widget, laInput_TouchMovedEvent* evt)
{
	int32_t dy;

	dy = evt->y - evt->prevY;

	dy *= 3;
	dy /= 2;

	if (InfoTextDragPanel->rect.y + dy < miny)
	{
		laWidget_SetPosition((laWidget*)InfoTextDragPanel, InfoTextDragPanel->rect.x, miny);
	}
	else if (InfoTextDragPanel->rect.y + dy > maxy)
	{
		laWidget_SetPosition((laWidget*)InfoTextDragPanel, InfoTextDragPanel->rect.x, maxy);
	}
	else
	{
		laWidget_Translate((laWidget*)InfoTextDragPanel, 0, dy);
	}

	evt->event.accepted = LA_TRUE;
}

void APP_GoToSplashState(void)
{
	appData.state = APP_STATE_SPLASH;
}

void APP_GoToInfoState(void)
{
	appData.state = APP_STATE_INFO;
}

void APP_GoToMainState(void)
{
	appData.state = APP_STATE_MAIN;
	appData.gpuButtonNeedsUpdate = true;
}

void APP_SwitchScreenRequest(APP_MODE_SELECTIONS select)
{
    switch(select)
    {
        case MODE_SELECT_0:
        {
            APP_GoToInfoState();
            laContext_SetActiveScreen(InfoScreen_ID);
            break;
        }
        case MODE_SELECT_1:
        {
            laContext_SetActiveScreen(BusinessScreen_ID);
            break;
        }
        case MODE_SELECT_2:
        {
            laContext_SetActiveScreen(PortraitScreen_ID);
            break;
        }
        case MODE_SELECT_3:
        {
            laContext_SetActiveScreen(AlbumScreen_ID);
            break;
        }
        default:
            break;
    };    
}

void APP_SelectItem(APP_MODE_SELECTIONS select)
{
    switch(select)
    {
        case MODE_SELECT_0:
        {
            laLabelWidget_SetText(ModeLabel, laString_CreateFromID(string_Mode1));
            laWidget_SetScheme((laWidget*)ModeLabel, &labelModeScheme0);
            break;
        }
        case MODE_SELECT_1:
        {
            laLabelWidget_SetText(ModeLabel, laString_CreateFromID(string_Mode2));
            laWidget_SetScheme((laWidget*)ModeLabel, &labelModeScheme1);
            break;
        }
        case MODE_SELECT_2:
        {
            laLabelWidget_SetText(ModeLabel, laString_CreateFromID(string_Mode3));
            laWidget_SetScheme((laWidget*)ModeLabel, &labelModeScheme2);
            break;
        }
        case MODE_SELECT_3:
        {
            laLabelWidget_SetText(ModeLabel, laString_CreateFromID(string_Mode4));
            laWidget_SetScheme((laWidget*)ModeLabel, &labelModeScheme3);
            break;
        }
        default:
        {
            laLabelWidget_SetText(ModeLabel, laString_CreateFromID(string_Mode3));
            laWidget_SetScheme((laWidget*)ModeLabel, &labelModeScheme2);
            break;
        }
    };    
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
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    appData.phase = RADIAL_PHASE_0;
	appData.launched = false;
	appData.isGPUOn = true;
    appData.rotateDone = true;
    appData.gpuButtonNeedsUpdate = false;
    appData.currentSelectionIndex = 0;    
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
	switch (appData.state)
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
				laContext_GetActiveScreen()->id != 0)
				break;
			
			if (APP_IsSplashScreenComplete())
            {
				if (!appData.launched)
				{
					appData.state = APP_STATE_MAIN;

					appData.launched = true;
					appData.gpuButtonNeedsUpdate = true;

					laContext_SetActiveScreen(1);
				}
				else
				{
					appData.state = APP_STATE_INFO;

					laContext_SetActiveScreen(2);
				}
            }
            break;
        }

        case APP_STATE_MAIN:
        {
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
				miny = 0 - InfoTextDragPanel->rect.height;
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
