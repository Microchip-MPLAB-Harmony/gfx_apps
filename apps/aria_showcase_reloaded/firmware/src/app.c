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
Copyright (c) 2018 released Microchip Technology Inc.  All rights reserved.

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

#include <stdio.h>

#include "app.h"
#include "app_splash.h"
#include "gfx/libaria/libaria_init.h"
#include "gfx/libaria/inc/libaria_widget_line_graph.h"

#define APP_CHECK_EVENT(event) (appData.eventFlags & (1 << event))
#define APP_CLEAR_EVENT(event) (appData.eventFlags &= ~(1 << event))
#define APP_CLEAR_ALL_EVENTS() (appData.eventFlags &= ~(APP_ALL_EVENTS))

#define GRAPH_TOUCH_SERIES 2
#define GRAPH_TOUCH_SAMPLES 16

#define APP_TICK_TIMER_PERIOD_MS 10
#define APP_DEMO_UPDATE_PERIOD_1S (1000/APP_TICK_TIMER_PERIOD_MS)
#define APP_DEMO_UPDATE_PERIOD_200MS (200/APP_TICK_TIMER_PERIOD_MS)

typedef struct graphTouchSample
{
    uint32_t x;
    uint32_t y;
} GRAPH_TOUCH_SAMPLE;

static GRAPH_TOUCH_SAMPLE graphTouchSamples[GRAPH_TOUCH_SAMPLES];


static uint32_t sampleIndex = 0;

 static void graphTouchDown(laWidget* widget, laInput_TouchDownEvent* evt);
 static void graphTouchMoved(laWidget* widget, laInput_TouchMovedEvent* evt);

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

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


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
    appData.demoState = APP_DEMO_STATE_STOPPED;
    appData.eventFlags = 0;
    appData.eventParam = NULL;
}

void APP_SendEvent(APP_EVENT event)
{
    appData.eventFlags |= (1 << event);
}

void APP_SendEventWithParam(APP_EVENT event, void * param)
{
    appData.eventFlags |= (1 << event);
    appData.eventParam = param;
}

void APP_SendTouchEvent(APP_EVENT event, uint32_t x, uint32_t y)
{
    appData.eventFlags |= (1 << event);
    appData.touchParamX = x;
    appData.touchParamY = y;
}

void APP_ChangeState(APP_STATES state)
{
    int32_t screenID = -1;
    
    switch (state)
    {
        case APP_STATE_INIT:
        {
            screenID = -1;
            break;
        }
        case APP_STATE_SPLASH:
        {
            screenID = -1;
            break;
        }
        case APP_STATE_ERROR:
        {
            screenID = -1;
            break;
        }
        case APP_STATE_MAIN_MENU:
        {
            screenID = MainMenu_ID;
            break;
        }
        case APP_STATE_ARC_PRIMITIVE_DEMO:
        {
            screenID = ArcWidgetDemo_ID;
            break;
        }
        case APP_STATE_CIRCULAR_SLIDER_DEMO:
        {
            screenID = CircularSliderDemo_ID;
            break;
        }
        case APP_STATE_CIRCULAR_GAUGE_DEMO:
        {
            screenID = CircularGaugeDemo_ID;
            break;
        }
        case APP_STATE_PIE_CHART_DEMO:
        {
            screenID = PieChartDemo_ID;
            break;
        }
        case APP_STATE_BAR_GRAPH_DEMO:
        {
            screenID = BarGraphDemo_ID;
            break;
        }
        case APP_STATE_LINE_GRAPH_DEMO:
        {
            screenID = LineGraphScreen_ID;
            break;
        }
        default:
        {
            screenID = -1;
            state = APP_STATE_ERROR;
            break;
        }
    }
    
    appData.state = state;
    appData.demoState = APP_DEMO_STATE_STOPPED;
    
    if (screenID >= 0)
        laContext_SetActiveScreen(screenID);
    
    APP_SendEvent(APP_EVENT_INIT_STATE);
}

void APP_ClearEvent(APP_EVENT event)
{
    appData.eventFlags &= ~(1 << event);
}

bool APP_CheckEvent(APP_EVENT event)
{
    bool retval = APP_CHECK_EVENT(event);
    APP_CLEAR_EVENT(event); 
    
    return retval;
}

void APP_MainMenuProcessEvents(void)
{
    if (APP_CheckEvent(APP_EVENT_INIT_STATE))
    {
        APP_CLEAR_ALL_EVENTS();
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_ARC_PRIMITIVE_SCREEN))
    {
        APP_ChangeState(APP_STATE_ARC_PRIMITIVE_DEMO);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_CIRCULAR_SLIDER_SCREEN))
    {
        APP_ChangeState(APP_STATE_CIRCULAR_SLIDER_DEMO);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_CIRCULAR_GAUGE_SCREEN))
    {
        APP_ChangeState(APP_STATE_CIRCULAR_GAUGE_DEMO);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_PIE_CHART_SCREEN))
    {
        APP_ChangeState(APP_STATE_PIE_CHART_DEMO);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_BAR_GRAPH_SCREEN))
    {
        APP_ChangeState(APP_STATE_BAR_GRAPH_DEMO);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_LINE_GRAPH_SCREEN))
    {
        APP_ChangeState(APP_STATE_LINE_GRAPH_DEMO);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_RADIAL_MENU_SCREEN))
    {
        APP_ChangeState(APP_STATE_RADIAL_MENU_DEMO);
    }    
}

void APP_ArcDemoProcessEvents(void)
{
    if (APP_CheckEvent(APP_EVENT_INIT_STATE))
    {
        APP_CLEAR_ALL_EVENTS();
        
        appData.demoState = APP_DEMO_STATE_STOPPED;
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_MAIN_MENU))
    {
        APP_ChangeState(APP_STATE_MAIN_MENU);
    }
    else if (APP_CheckEvent(APP_EVENT_START_WIDGET_DEMO))
    {
        laWidget_SetVisible((laWidget*) TouchImage_ArcDemo, LA_FALSE);
        
        appData.demoState = APP_DEMO_STATE_RUNNING;
    }
    else if (APP_CheckEvent(APP_EVENT_STOP_WIDGET_DEMO))
    {
        appData.demoState = APP_DEMO_STATE_STOPPED;
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_NEXT_SCREEN))
    {
        APP_ChangeState(APP_STATE_CIRCULAR_SLIDER_DEMO);
    }

    if (appData.demoState == APP_DEMO_STATE_RUNNING)
    {
        #define INSIDE_ANGLE_INC 5
        #define OUTSIDE_ANGLE_INC 5

        int32_t inStartAngle = 0, midStartAngle = 0, midCenterAngle = 0;
        int32_t perCenterAngle = 0;
        static int32_t inc = 20;

        inStartAngle = laArcWidget_GetStartAngle(ArcWidgetIn);
        laArcWidget_SetStartAngle(ArcWidgetIn, inStartAngle + INSIDE_ANGLE_INC);

        inStartAngle = laArcWidget_GetStartAngle(ArcWidgetInMid);
        laArcWidget_SetStartAngle(ArcWidgetInMid, inStartAngle + INSIDE_ANGLE_INC);

        midStartAngle = laArcWidget_GetStartAngle(ArcWidgetMid);
        midCenterAngle = laArcWidget_GetCenterAngle(ArcWidgetMid);

        if (midStartAngle > 160)
        {
            inc = -OUTSIDE_ANGLE_INC;
        }
        else if (midStartAngle < 20)
        {
            inc = OUTSIDE_ANGLE_INC;
        }

        laArcWidget_SetStartAngle(ArcWidgetMid, midStartAngle + inc);
        laArcWidget_SetCenterAngle(ArcWidgetMid, midCenterAngle - 2*inc);
        laArcWidget_SetStartAngle(ArcWidgetOut, midStartAngle + inc);
        laArcWidget_SetCenterAngle(ArcWidgetOut, - (360 - (midCenterAngle - 2*inc)));

        perCenterAngle = laArcWidget_GetCenterAngle(ArcWidgetPerimeter);
        perCenterAngle -= 30;

        if (perCenterAngle < -360)
            perCenterAngle = 360;

        laArcWidget_SetCenterAngle(ArcWidgetPerimeter, perCenterAngle);
    }
}

void APP_CircularSliderDemoProcessEvents(void)
{
    if (APP_CheckEvent(APP_EVENT_CIRCULAR_SLIDER_SET_VALUE_LABEL))
    {
        int32_t value = laCircularSliderWidget_GetValue(CircularSliderWidgetControl);
        char strbuff[5] = {0};
        laString str;

        sprintf(strbuff, "%ld", value);
        
        laCircularSliderWidget_SetValue((laCircularSliderWidget*)CircularProgressBar, value);

        str = laString_CreateFromCharBuffer(strbuff, 
            GFXU_StringFontIndexLookup(&stringTable, string_NumsBig, 0));

        laLabelWidget_SetText(CircularSliderValueLabel, str);

        laString_Destroy(&str);
        
        laWidget_SetVisible((laWidget*) TouchImage_CircSliderDemo, LA_FALSE);
    }

    if (APP_CheckEvent(APP_EVENT_INIT_STATE))
    {
        APP_CLEAR_ALL_EVENTS();
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_MAIN_MENU))
    {
        APP_ChangeState(APP_STATE_MAIN_MENU);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_NEXT_SCREEN))
    {
        APP_ChangeState(APP_STATE_CIRCULAR_GAUGE_DEMO);
    }    
}

void APP_CircularGaugeDemoProcessEvents(void)
{
    static int32_t tachoValue = 0;
    static int32_t speedoValue = 0;
    static int32_t speedInc = 0;
    static int32_t tachoInc = 0;

    if (APP_CheckEvent(APP_EVENT_CIRCULAR_GAUGE_GAS_PRESSED))
    {
        laWidget_SetVisible((laWidget*) TouchImage_CircGaugeDemo, LA_FALSE);
        
        speedInc += 1;
        tachoInc += 1;
    }
    else if (APP_CheckEvent(APP_EVENT_CIRCULAR_GAUGE_GAS_RELEASED))
    {
        APP_CLEAR_EVENT(APP_EVENT_CIRCULAR_GAUGE_GAS_RELEASED);

        speedInc = 0;
        tachoInc = 0;
    }

    if (APP_CheckEvent(APP_EVENT_INIT_STATE))
    {
        APP_CLEAR_ALL_EVENTS();

        tachoValue = 0;
        speedoValue = 0;
        speedInc = 0;
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_MAIN_MENU))
    {
        APP_ChangeState(APP_STATE_MAIN_MENU);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_NEXT_SCREEN))
    {
        APP_ChangeState(APP_STATE_PIE_CHART_DEMO);
    }            

    if (speedInc != 0)
    {
        char strbuff[5] = {0};
        laString str;

        speedoValue += speedInc;
        if (speedoValue < 0)
            speedoValue = 0;
        else if (speedoValue > 160)
            speedoValue = 160;

        sprintf(strbuff, "%ld", speedoValue);

        str = laString_CreateFromCharBuffer(strbuff, 
            GFXU_StringFontIndexLookup(&stringTable, string_NumsMed, 0));

        laLabelWidget_SetText(GaugeValueLabelWidget, str);

        laString_Destroy(&str); 

    }
    else if (speedoValue > 0)
    {
        char strbuff[5] = {0};
        laString str;

        speedoValue -= 1;

        if (speedoValue < 0)
            speedoValue = 0;

        sprintf(strbuff, "%ld", speedoValue);

        str = laString_CreateFromCharBuffer(strbuff, 
            GFXU_StringFontIndexLookup(&stringTable, string_NumsMed, 0));

        laLabelWidget_SetText(GaugeValueLabelWidget, str);

        laString_Destroy(&str); 
    }
    else if (speedoValue != 0)
    {
        speedoValue = 0;
    }

    if (tachoInc != 0)
    {
        tachoValue += tachoInc;
        if (tachoValue < 0)
            tachoValue = 0;
        else if (tachoValue > 100)
            tachoValue = 100;
    }
    else if (tachoValue > 0)
    {
        tachoValue -= 1;
        if (tachoValue < 0)
            tachoValue = 0;
    }
    else if (tachoValue != 0)
    {
        tachoValue = 0;
    }

    laCircularGaugeWidget_SetValue(CircularGaugeWidget43, tachoValue);
    laCircularGaugeWidget_SetValue(SpeedoCircularGaugeWidget, speedoValue);
}

void APP_PieChartDemoProcessEvents(void)
{
    if (APP_CheckEvent(APP_EVENT_PIE_CHART_PRESSED))
    {
        #define TOUCHED_OFFSET 10
        #define TOUCHED_RADIUS 100
        #define UNTOUCHED_RADIUS 90

        uint32_t index;
        uint32_t offset;
        uint32_t radius;

        APP_CLEAR_EVENT(APP_EVENT_PIE_CHART_PRESSED);

        laWidget_SetVisible((laWidget*) TouchImage_PieChartDemo, LA_FALSE);

        index = (uint32_t) appData.eventParam;

        radius = laPieChartWidget_GetEntryRadius(PieChartWidget2, index);
        offset = laPieChartWidget_GetEntryOffset(PieChartWidget2, index);

        if (radius == UNTOUCHED_RADIUS && offset == 0)
        {
            laPieChartWidget_SetEntryRadius(PieChartWidget2, index, TOUCHED_RADIUS);
        }
        else if (radius == TOUCHED_RADIUS && offset == 0)
        {
            laPieChartWidget_SetEntryOffset(PieChartWidget2, index, TOUCHED_OFFSET);
        }
        else if (radius == TOUCHED_RADIUS && offset == TOUCHED_OFFSET)
        {
            laPieChartWidget_SetEntryRadius(PieChartWidget2, index, UNTOUCHED_RADIUS);
        }
        else
        {
            laPieChartWidget_SetEntryRadius(PieChartWidget2, index, UNTOUCHED_RADIUS);
            laPieChartWidget_SetEntryOffset(PieChartWidget2, index, 0);
        }
    }
    else if (APP_CheckEvent(APP_EVENT_INIT_STATE))
    {
        APP_CLEAR_ALL_EVENTS();
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_MAIN_MENU))
    {
        APP_ChangeState(APP_STATE_MAIN_MENU);
    }            
    else if (APP_CheckEvent(APP_EVENT_GOTO_NEXT_SCREEN))
    {
        APP_ChangeState(APP_STATE_BAR_GRAPH_DEMO);
    }    
}


void APP_GraphRefreshBarGraphData(laBarGraphWidget * graph)
{
    uint32_t i = 0;
    uint32_t j = sampleIndex;
    for (i = 0; i < GRAPH_TOUCH_SAMPLES; i++, j++)
    {
        if (j >= GRAPH_TOUCH_SAMPLES)
            j = 0;
        
        laBarGraphWidget_SetDataInSeries(graph,
                    0, i, graphTouchSamples[j].x);
        laBarGraphWidget_SetDataInSeries(graph,
                    1, i, graphTouchSamples[j].y);        
    }
}

void APP_GraphRefreshLineGraphData(laLineGraphWidget * graph)
{
    uint32_t i = 0;
    uint32_t j = sampleIndex;
    for (i = 0; i < GRAPH_TOUCH_SAMPLES; i++, j++)
    {
        if (j >= GRAPH_TOUCH_SAMPLES)
            j = 0;
        
        laLineGraphWidget_SetDataInSeries(graph,
                    0, i, graphTouchSamples[j].x);
        laLineGraphWidget_SetDataInSeries(graph,
                    1, i, graphTouchSamples[j].y);        
    }
}

void APP_BarGraphDemoProcessEvents(void)
{
    if (APP_CheckEvent(APP_EVENT_INIT_STATE))
    {
        APP_CLEAR_ALL_EVENTS();

        appData.demoState = APP_DEMO_STATE_STOPPED;
        laWidget_OverrideTouchDownEvent((laWidget*)BarGraphTouchedButton, &graphTouchDown);
        laWidget_OverrideTouchMovedEvent((laWidget*)BarGraphTouchedButton, &graphTouchMoved);
        
        memset(graphTouchSamples, 0, GRAPH_TOUCH_SAMPLES*sizeof(GRAPH_TOUCH_SAMPLE));

        sampleIndex = 0;
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_MAIN_MENU))
    {
        APP_ChangeState(APP_STATE_MAIN_MENU);
    }            
    else if (APP_CheckEvent(APP_EVENT_GOTO_NEXT_SCREEN))
    {
        APP_ChangeState(APP_STATE_LINE_GRAPH_DEMO);
    }
    else if (APP_CheckEvent(APP_EVENT_GRAPH_TOUCHED_DOWN) ||
             APP_CheckEvent(APP_EVENT_GRAPH_TOUCHED_MOVE))
    {
        laWidget_SetVisible((laWidget*) TouchImage_BarGraphDemo, LA_FALSE);
        
        graphTouchSamples[sampleIndex].x = appData.touchParamX;
        graphTouchSamples[sampleIndex].y = appData.touchParamY;
        
        sampleIndex++;
        
        if (sampleIndex >= GRAPH_TOUCH_SAMPLES)
        {
            sampleIndex = 0;
        }
        
        APP_GraphRefreshBarGraphData(BarGraphWidget8);
    }
}

void APP_LineGraphDemoProcessEvents(void)
{

    if (APP_CheckEvent(APP_EVENT_INIT_STATE))
    {
        APP_CLEAR_ALL_EVENTS();

        appData.demoState = APP_DEMO_STATE_STOPPED;
        laWidget_OverrideTouchDownEvent((laWidget*)LineGraphTouchedButton, &graphTouchDown);
        laWidget_OverrideTouchMovedEvent((laWidget*)LineGraphTouchedButton, &graphTouchMoved);
        
        memset(graphTouchSamples, 0, GRAPH_TOUCH_SAMPLES * sizeof(GRAPH_TOUCH_SAMPLE));

        sampleIndex = 0;
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_NEXT_SCREEN))
    {
#if 0 //ndef NO_RADIAL_MENU_DEMO
        APP_ChangeState(APP_STATE_RADIAL_MENU_DEMO);
#else
        APP_ChangeState(APP_STATE_ARC_PRIMITIVE_DEMO);        
#endif        
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_MAIN_MENU))
    {
        APP_ChangeState(APP_STATE_MAIN_MENU);
    }
    else if (APP_CheckEvent(APP_EVENT_GRAPH_TOUCHED_DOWN) ||
             APP_CheckEvent(APP_EVENT_GRAPH_TOUCHED_MOVE))
    {
        laWidget_SetVisible((laWidget*) TouchImage_LineGraphDemo, LA_FALSE);
        
        graphTouchSamples[sampleIndex].x = appData.touchParamX;
        graphTouchSamples[sampleIndex].y = appData.touchParamY;
        
        sampleIndex++;
        
        if (sampleIndex >= GRAPH_TOUCH_SAMPLES)
        {
            sampleIndex = 0;
        }
        
        APP_GraphRefreshLineGraphData(LineGraphWidget13);
    }
}

void APP_RadialMenuDemoProcessEvents(void)
{

    if (APP_CheckEvent(APP_EVENT_INIT_STATE))
    {
        APP_CLEAR_ALL_EVENTS();
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_NEXT_SCREEN))
    {
        APP_ChangeState(APP_STATE_ARC_PRIMITIVE_DEMO);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_MAIN_MENU))
    {
        APP_ChangeState(APP_STATE_MAIN_MENU);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_ARC_PRIMITIVE_SCREEN))
    {
        APP_ChangeState(APP_STATE_ARC_PRIMITIVE_DEMO);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_BAR_GRAPH_SCREEN))
    {
        APP_ChangeState(APP_STATE_BAR_GRAPH_DEMO);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_CIRCULAR_GAUGE_SCREEN))
    {
        APP_ChangeState(APP_STATE_CIRCULAR_GAUGE_DEMO);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_CIRCULAR_SLIDER_SCREEN))
    {
        APP_ChangeState(APP_STATE_CIRCULAR_SLIDER_DEMO);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_LINE_GRAPH_SCREEN))
    {
        APP_ChangeState(APP_STATE_LINE_GRAPH_DEMO);
    }
    else if (APP_CheckEvent(APP_EVENT_GOTO_PIE_CHART_SCREEN))
    {
        APP_ChangeState(APP_STATE_PIE_CHART_DEMO);
    }
    
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
        case APP_STATE_MAIN_MENU:
        {
            APP_MainMenuProcessEvents();
            break;
        }

        case APP_STATE_ARC_PRIMITIVE_DEMO:
        {
            APP_ArcDemoProcessEvents();
            break;
        }
        case APP_STATE_CIRCULAR_SLIDER_DEMO:
        {
            APP_CircularSliderDemoProcessEvents();
            break;
        }
        case APP_STATE_CIRCULAR_GAUGE_DEMO:
        {
            APP_CircularGaugeDemoProcessEvents();
            break;            
        }
        case APP_STATE_PIE_CHART_DEMO:
        {
            APP_PieChartDemoProcessEvents();
            break;
        }
        case APP_STATE_BAR_GRAPH_DEMO:
        {
            APP_BarGraphDemoProcessEvents();
            break;
        }
        case APP_STATE_LINE_GRAPH_DEMO:
        {
            APP_LineGraphDemoProcessEvents();
            break;
        }
        case APP_STATE_RADIAL_MENU_DEMO:
        {
            APP_RadialMenuDemoProcessEvents();
            break;
        }        
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
            
            if (APP_MAX_EVENTS >= 32)
            {
                APP_ChangeState(APP_STATE_ERROR);
                appInitialized = false;
                break;
            }
            
            if (appInitialized)
            {
                APP_ChangeState(APP_STATE_SPLASH);
            }
            break;
        }
        case APP_STATE_SPLASH:
        {            
            if (APP_IsSplashScreenComplete())
            {
                APP_ChangeState(APP_STATE_MAIN_MENU);
            }
        
            break;
        }        
        case APP_STATE_ERROR:
        {
            //ERROR STATE
            break;
        }
            
        /* The default state should never be executed. */
        default:
        {
            break;
        }
    }
   
}

static void graphTouchDown(laWidget* widget, laInput_TouchDownEvent* evt)
{

    APP_SendTouchEvent(APP_EVENT_GRAPH_TOUCHED_DOWN, evt->x, evt->y);
    evt->event.accepted = LA_TRUE;
}
 
 static void graphTouchMoved(laWidget* widget, laInput_TouchMovedEvent* evt)
 {
     APP_SendTouchEvent(APP_EVENT_GRAPH_TOUCHED_MOVE, evt->x, evt->y);
     evt->event.accepted = LA_TRUE;
 }


/*******************************************************************************
 End of File
 */
