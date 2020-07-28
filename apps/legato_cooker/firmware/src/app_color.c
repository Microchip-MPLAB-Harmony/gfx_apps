#include "app.h"
#include "gfx/legato/generated/le_gen_init.h"
#include "definitions.h"

#include <stdio.h>
#include <string.h>

#define COLOR_SCENE_TIMER_PERIOD_MS 100
#define NUM_COUNT_SEC_TICK (1000/COLOR_SCENE_TIMER_PERIOD_MS)
#define MENU_BAR_BLOCK_EXTEND_PIX 3
#define NUM_MENU_ITEMS 4
#define COLOR_BAR_WIDTH 212
#define CLOCK_BACK_PANEL_HEIGHT 289
#define DIVIDER 5
#define CLOCK_BACK_PANEL_MOVE_INC_PIX 5
#define CLOCK_BACK_PANEL_YPOS 22
#define MODES_BACK_PANEL_XPOS 365
#define MOVE_DIVIDER 5
#define COOK_TIME_SECS 90
#define DEMO_MODE_IDLE_TIMEOUT_SECS 5

typedef enum 
{
            COLOR_SCENE_INIT,
            COLOR_SCENE_PREPARE_MENU0,
            COLOR_SCENE_PREPARE_MENU1,
            COLOR_SCENE_PREPARE_MENU2,
            COLOR_SCENE_PREPARE_MENU3,            
            COLOR_SCENE_PREPARE_MENU4,
            COLOR_SCENE_PREPARE_MENU5,
            COLOR_SCENE_PREPARE_MENU6,
            COLOR_SCENE_PREPARE_MENU7,
            COLOR_SCENE_PREPARE_MENU8,
            COLOR_SCENE_PREPARE_MENU9,
            COLOR_SCENE_PREPARE_MENU10,                    
            COLOR_SCENE_PROCESS,
            COLOR_SCENE_PREPARE,
            COLOR_SCENE_COOKING,
            COLOR_SCENE_DONE,
            COLOR_SCENE_RETURNING,
            COLOR_SCENE_EXIT,                    
} COLOR_SCENE_STATES;

typedef enum
{
    NO_EVENTS,
    START_COOKING,
    STOP_COOKING,
    SELECT_ITEM_0,
    SELECT_ITEM_1,
    SELECT_ITEM_2,
    SELECT_ITEM_3,
    CHANGE_SCENE,
    SET_COOK_TIME,
} SCENE_EVENTS;

typedef struct
{
    unsigned int timeout;
    SCENE_EVENTS event;
} DEMO_MODE_OBJ;

static COLOR_SCENE_STATES color_scene_state = COLOR_SCENE_INIT;
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;
static int tick_count, last_sec, last_min = 0;
static int tick_count_last = 0;
static int x, y;
static SCENE_EVENTS event = NO_EVENTS;
static uint32_t event_parm = 0;
static int cookSec = COOK_TIME_SECS;
static int startCookSec = COOK_TIME_SECS;

static leFixedString hrStr, minStr;
static leChar hrStrBuff[16] = {0};
static leChar minStrBuff[16] = {0};

static DEMO_MODE_OBJ demo_mode_obj[] =
{
    {3, STOP_COOKING},
    {3, SELECT_ITEM_1},
    {3, START_COOKING},
    {10, STOP_COOKING},
    {3, SELECT_ITEM_3},
    {3, START_COOKING},
    {10, STOP_COOKING},
    {3, CHANGE_SCENE},    
};

void color_screen_show(void)
{
    legato_showScreen(screenID_ColorScreen);
}

static void color_send_event(SCENE_EVENTS evt)
{
    event = evt;
}


static void updateClock(unsigned int high, unsigned int low)
{
    char charBuff[16] = {0};

    //create the time character string from hr, min, sec variables
    sprintf(charBuff, "%02u", high); 
    hrStr.fn->setFromCStr(&hrStr, charBuff);    
    ColorScreen_Screen2HourLabel->fn->setString(ColorScreen_Screen2HourLabel, (leString*)&hrStr);   

    sprintf(charBuff, "%02u", low); 
    minStr.fn->setFromCStr(&minStr, charBuff);    
    ColorScreen_Screen2MinuteLabel->fn->setString(ColorScreen_Screen2MinuteLabel, (leString*)&minStr);   
}

static void Timer_Callback ( uintptr_t context)
{
    tick_count++;
    
    if (tick_count > NUM_COUNT_SEC_TICK)
    {
        tick_count = 0;
        idle_secs++;        
        clock_sec++;
        if (clock_sec == 60)
        {
            {
                clock_sec = 0;
                clock_min++;
                if (clock_min == 60)
                {
                    clock_min = 0;
                    clock_hr++;
                    if (clock_hr == 24)
                    {
                        clock_hr = 0;
                    }
                }
            }
        }
        
        if (idle_secs > DEMO_MODE_IDLE_TIMEOUT_SECS && 
            demo_mode_on == true)
        {
            demo_mode_count_secs++;
            if (demo_mode_count_secs > demo_mode_obj[demo_mode_event_idx].timeout)
            {
                event = demo_mode_obj[demo_mode_event_idx].event;
                demo_mode_count_secs = 0;
                demo_mode_event_idx = 
                        (demo_mode_event_idx < sizeof(demo_mode_obj)/sizeof(DEMO_MODE_OBJ) - 1) ? 
                        demo_mode_event_idx + 1 : 0;
            }
            
            ColorScreen_ButtonWidget6->fn->setVisible(ColorScreen_ButtonWidget6, clock_sec%2);
        }
        else
        {
            ColorScreen_ButtonWidget6->fn->setVisible(ColorScreen_ButtonWidget6, LE_TRUE);
        }
    }  
}

static void Rect_PreAnimate(leRectangleWidget * widget)
{
    widget->fn->setVisible(widget, LE_TRUE);
    widget->fn->setWidth(widget, 0);    
}

static bool Rect_Animate(leRectangleWidget * widget, int32_t x, uint32_t width)
{
    uint32_t cur_width = widget->fn->getWidth(widget);
    bool done = false;
    
    if (width - cur_width > DIVIDER)
    {
        widget->fn->setWidth(widget, 
                             cur_width + (width - cur_width)/DIVIDER);
    }
    else
    {
        widget->fn->setWidth(widget, width);
        done = true;
    }    
    
    return done;
    
}

static void Set_SelectedMenuItem(int index)
{
    if (color_scene_state != COLOR_SCENE_PROCESS)
        return;
    
    ColorScreen_MenuItem1Label->fn->setScheme(ColorScreen_MenuItem1Label, &UnselectedItemTextScheme);
    ColorScreen_MenuItem2Label->fn->setScheme(ColorScreen_MenuItem2Label, &UnselectedItemTextScheme);
    ColorScreen_MenuItem3Label->fn->setScheme(ColorScreen_MenuItem3Label, &UnselectedItemTextScheme);
    ColorScreen_MenuItem4Label->fn->setScheme(ColorScreen_MenuItem4Label, &UnselectedItemTextScheme);
    
    ColorScreen_ButtonImage1->fn->setSize(ColorScreen_ButtonImage1, 64, 64);
    ColorScreen_ButtonImage2->fn->setSize(ColorScreen_ButtonImage2, 64, 64);
    ColorScreen_ButtonImage3->fn->setSize(ColorScreen_ButtonImage3, 64, 64);
    ColorScreen_Button4Image->fn->setSize(ColorScreen_Button4Image, 64, 64);
    
    ColorScreen_ButtonImage1->fn->setPosition(ColorScreen_ButtonImage1, 15, 2);
    ColorScreen_ButtonImage2->fn->setPosition(ColorScreen_ButtonImage2, 25, 2);
    ColorScreen_ButtonImage3->fn->setPosition(ColorScreen_ButtonImage3, 15, 2);
    ColorScreen_Button4Image->fn->setPosition(ColorScreen_Button4Image, 25, 2);
    

    switch(index)
    {
        case 0:
        {
            ColorScreen_MenuItem1Label->fn->setScheme(ColorScreen_MenuItem1Label, &WhiteTextScheme);
            ColorScreen_ButtonImage1->fn->setSize(ColorScreen_ButtonImage1, 70, 70);
            ColorScreen_ButtonImage1->fn->setPosition(ColorScreen_ButtonImage1, 13, 0);
            
            ColorScreen_ProgressRect->fn->setScheme(ColorScreen_ProgressRect, &Button1Scheme);
            
            startCookSec = 200;
                    
            break;
        }
        case 1:
        {
            ColorScreen_MenuItem2Label->fn->setScheme(ColorScreen_MenuItem2Label, &WhiteTextScheme);
            ColorScreen_ButtonImage2->fn->setSize(ColorScreen_ButtonImage2, 70, 70);
            ColorScreen_ButtonImage2->fn->setPosition(ColorScreen_ButtonImage2, 23, 0);
            
            ColorScreen_ProgressRect->fn->setScheme(ColorScreen_ProgressRect, &Button2Scheme);
            
            startCookSec = 110;
                    
            break;
        }
        case 2:
        {
            ColorScreen_MenuItem3Label->fn->setScheme(ColorScreen_MenuItem3Label, &WhiteTextScheme);
            ColorScreen_ButtonImage3->fn->setSize(ColorScreen_ButtonImage3, 70, 70);
            ColorScreen_ButtonImage3->fn->setPosition(ColorScreen_ButtonImage3, 13, 0);                    
                 
            ColorScreen_ProgressRect->fn->setScheme(ColorScreen_ProgressRect, &Button3Scheme);
            
            startCookSec = 60;
            
            break;
        }
        case 3:
        {
            ColorScreen_MenuItem4Label->fn->setScheme(ColorScreen_MenuItem4Label, &WhiteTextScheme);
            ColorScreen_Button4Image->fn->setSize(ColorScreen_Button4Image, 70, 70);
            ColorScreen_Button4Image->fn->setPosition(ColorScreen_Button4Image, 23, 0);                    
                    
            ColorScreen_ProgressRect->fn->setScheme(ColorScreen_ProgressRect, &Button4Scheme);
            
            startCookSec = 50;
            
            break;
        }
        default:
        {
            break;
        }
    }
}

static leBool color_filterEvent(leWidget* target, leWidgetEvent* evt, void* data)
{
    switch(evt->id)
    {
        case LE_EVENT_TOUCH_DOWN:
        case LE_EVENT_TOUCH_MOVE:            
        {
            int x;
            uint32_t width = target->fn->getWidth(target);
            int startx = target->fn->getX(target);
            
            if (evt->id == LE_EVENT_TOUCH_DOWN)
            {
                leWidgetEvent_TouchDown * down = (leWidgetEvent_TouchDown *) evt;
                x = down->x;
            }
            else
            {
                leWidgetEvent_TouchMove * move = (leWidgetEvent_TouchMove *) evt;
                x = move->x;
            }

            if (x < startx)
                event_parm = 0;
            else if (x > startx + width)
                event_parm = 100;
            else
                event_parm = ((x - startx) * 100)/width;
            
            event = SET_COOK_TIME;
            
            evt->accepted = LE_TRUE;
            
            break;
        }
        default:
            break;
    }
    return LE_FALSE;
}

static leWidgetEventFilter color_eventFilter =
{
    color_filterEvent,
    NULL
};

void ColorScreen_OnShow(void)
{
    //Hide the other menu items
    ColorScreen_MenuItem2->fn->setVisible(ColorScreen_MenuItem2, LE_FALSE);
    ColorScreen_MenuItem3->fn->setVisible(ColorScreen_MenuItem3, LE_FALSE);
    ColorScreen_MenuItem4->fn->setVisible(ColorScreen_MenuItem4, LE_FALSE);

    //Hide all the menu item images
    ColorScreen_ButtonImage1->fn->setVisible(ColorScreen_ButtonImage1, LE_FALSE);
    ColorScreen_ButtonImage2->fn->setVisible(ColorScreen_ButtonImage2, LE_FALSE);
    ColorScreen_ButtonImage3->fn->setVisible(ColorScreen_ButtonImage3, LE_FALSE);
    ColorScreen_Button4Image->fn->setVisible(ColorScreen_Button4Image, LE_FALSE);

    //Hide all the background gray rects
    ColorScreen_ButtonRect1Back->fn->setVisible(ColorScreen_ButtonRect1Back, LE_FALSE);
    ColorScreen_Button2RectBack->fn->setVisible(ColorScreen_Button2RectBack, LE_FALSE);
    ColorScreen_Button3RectBack->fn->setVisible(ColorScreen_Button3RectBack, LE_FALSE);
    ColorScreen_Button4RectBack->fn->setVisible(ColorScreen_Button4RectBack, LE_FALSE);

    //Hide all the menu labels
    ColorScreen_MenuItem1Label->fn->setVisible(ColorScreen_MenuItem1Label, LE_FALSE);
    ColorScreen_MenuItem2Label->fn->setVisible(ColorScreen_MenuItem2Label, LE_FALSE);
    ColorScreen_MenuItem3Label->fn->setVisible(ColorScreen_MenuItem3Label, LE_FALSE);
    ColorScreen_MenuItem4Label->fn->setVisible(ColorScreen_MenuItem4Label, LE_FALSE);

    // Hide the clock panel
    ColorScreen_Screen2MainClockPanel->fn->setVisible(ColorScreen_Screen2MainClockPanel, LE_FALSE);

    //Hide the Banner
    ColorScreen_Screen2LabelPanel->fn->setY(ColorScreen_Screen2LabelPanel, -76);

    //Hide the mode buttons
    ColorScreen_CookButtonWidget->fn->setVisible(ColorScreen_CookButtonWidget, LE_FALSE);
    ColorScreen_ReheatButtonWidget->fn->setVisible(ColorScreen_ReheatButtonWidget, LE_FALSE);

    //Hide the progress rectangle
    ColorScreen_ProgressRect->fn->setX(ColorScreen_ProgressRect, -153);
    ColorScreen_ProgressRect->fn->setY(ColorScreen_ProgressRect, 30);

    //Hide the back panels
    ColorScreen_PanelWidget5->fn->setY(ColorScreen_PanelWidget5, 320);
    ColorScreen_PanelWidget4->fn->setX(ColorScreen_PanelWidget4, 480);
    
    leFixedString_Constructor(&hrStr, hrStrBuff, 16);
    hrStr.fn->setFont(&hrStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DefaultHour2,
                                                              0));    
    
    leFixedString_Constructor(&minStr, minStrBuff, 16);
    minStr.fn->setFont(&minStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DefaultMinute,
                                                              0));
    
    ColorScreen_ButtonWidget6->fn->setPressed(ColorScreen_ButtonWidget6, (leBool) (demo_mode_on == false));
    
    ColorScreen_SliderButton2->fn->installEventFilter(ColorScreen_SliderButton2, color_eventFilter);
    
    color_scene_state = COLOR_SCENE_INIT;
    event = NO_EVENTS;
}

void ColorScreen_OnHide(void)
{
    hrStr.fn->destructor(&hrStr);
    minStr.fn->destructor(&minStr);
}

void ColorScreen_OnUpdate(void)
{
    //Wait for the library to be done drawing before processing events/animation
    if(leGetRenderState()->frameState != LE_FRAME_READY || leEvent_GetCount() != 0)
        return;
    
    switch(color_scene_state)
    {
        case COLOR_SCENE_INIT:
        {
            timer = SYS_TIME_CallbackRegisterMS(Timer_Callback, 
                    1, COLOR_SCENE_TIMER_PERIOD_MS, 
                    SYS_TIME_PERIODIC);
            
            event = NO_EVENTS;
            idle_secs = 0;
            demo_mode_count_secs = 0;
            demo_mode_event_idx = 0;
            
            color_scene_state = COLOR_SCENE_PREPARE_MENU0;
            
            break;
        }
        case COLOR_SCENE_PREPARE_MENU0:
        {
            //Move the panel in to the scene
            ColorScreen_QuickSelectionsPanel->fn->setX(ColorScreen_QuickSelectionsPanel, 0);
            
            Rect_PreAnimate(ColorScreen_Button1Rect);
            
            color_scene_state = COLOR_SCENE_PREPARE_MENU1;
            
            break;
        }
        case COLOR_SCENE_PREPARE_MENU1:
        {   
            GFX_DISP_INTF_PIN_BACKLIGHT_Set();
            
            color_scene_state = COLOR_SCENE_PREPARE_MENU2;
            break;
        }
        case COLOR_SCENE_PREPARE_MENU2:
        {
            if (Rect_Animate(ColorScreen_Button1Rect, 0, COLOR_BAR_WIDTH) == true)
            {
                ColorScreen_MenuItem1Label->fn->setVisible(ColorScreen_MenuItem1Label, LE_TRUE);
                ColorScreen_ButtonImage1->fn->setVisible(ColorScreen_ButtonImage1, LE_TRUE);
                ColorScreen_MenuItem2->fn->setVisible(ColorScreen_MenuItem2, LE_TRUE);
                ColorScreen_ButtonImage2->fn->setVisible(ColorScreen_ButtonImage2, LE_FALSE);

                Rect_PreAnimate(ColorScreen_Button2Rect);

                color_scene_state = COLOR_SCENE_PREPARE_MENU3;
            }
            break;
        }
        case COLOR_SCENE_PREPARE_MENU3:
        {    
            if (Rect_Animate(ColorScreen_Button2Rect, 0, COLOR_BAR_WIDTH) == true)
            {
                ColorScreen_MenuItem2Label->fn->setVisible(ColorScreen_MenuItem2Label, LE_TRUE);
                ColorScreen_ButtonImage2->fn->setVisible(ColorScreen_ButtonImage2, LE_TRUE);                
                ColorScreen_MenuItem3->fn->setVisible(ColorScreen_MenuItem3, LE_TRUE);
                ColorScreen_ButtonImage3->fn->setVisible(ColorScreen_ButtonImage3, LE_FALSE);

                Rect_PreAnimate(ColorScreen_Button3Rect);

                color_scene_state = COLOR_SCENE_PREPARE_MENU4;
            }
            break;
        }
        case COLOR_SCENE_PREPARE_MENU4:
        {    
            if (Rect_Animate(ColorScreen_Button3Rect, 0, COLOR_BAR_WIDTH) == true)
            {
                ColorScreen_MenuItem3Label->fn->setVisible(ColorScreen_MenuItem3Label, LE_TRUE);
                ColorScreen_ButtonImage3->fn->setVisible(ColorScreen_ButtonImage3, LE_TRUE);
                ColorScreen_MenuItem4->fn->setVisible(ColorScreen_MenuItem4, LE_TRUE);
                
                ColorScreen_Button4Image->fn->setVisible(ColorScreen_Button4Image, LE_FALSE);

                Rect_PreAnimate(ColorScreen_Button4Rect);

                color_scene_state = COLOR_SCENE_PREPARE_MENU5;
            }
            break;
        }
        case COLOR_SCENE_PREPARE_MENU5:
        {    
            if (Rect_Animate(ColorScreen_Button4Rect, 0, COLOR_BAR_WIDTH) == true)
            {
                ColorScreen_MenuItem4Label->fn->setVisible(ColorScreen_MenuItem4Label, LE_TRUE);                
                ColorScreen_Button4Image->fn->setVisible(ColorScreen_Button4Image, LE_TRUE);
                    
                color_scene_state = COLOR_SCENE_PREPARE_MENU6;
            }            
            break;
        }
        case COLOR_SCENE_PREPARE_MENU6:
        {
            ColorScreen_ButtonRect1Back->fn->setVisible(ColorScreen_ButtonRect1Back, LE_TRUE);
            ColorScreen_Button2RectBack->fn->setVisible(ColorScreen_Button2RectBack, LE_TRUE);
            ColorScreen_Button3RectBack->fn->setVisible(ColorScreen_Button3RectBack, LE_TRUE);
            ColorScreen_Button4RectBack->fn->setVisible(ColorScreen_Button4RectBack, LE_TRUE);
            
            Set_SelectedMenuItem(0);
            
            color_scene_state = COLOR_SCENE_PREPARE_MENU7;
            break;
        }
        case COLOR_SCENE_PREPARE_MENU7:
        {
            //animate the clock back panel            
            y = ColorScreen_PanelWidget5->fn->getY(ColorScreen_PanelWidget5);

            if ( y - CLOCK_BACK_PANEL_YPOS > MOVE_DIVIDER)
            {
                ColorScreen_PanelWidget5->fn->setY(ColorScreen_PanelWidget5, y - (y - CLOCK_BACK_PANEL_YPOS)/MOVE_DIVIDER);
            }
            else
            {
                ColorScreen_PanelWidget5->fn->setY(ColorScreen_PanelWidget5, CLOCK_BACK_PANEL_YPOS);
                ColorScreen_Screen2MainClockPanel->fn->setVisible(ColorScreen_Screen2MainClockPanel, LE_TRUE);   
                updateClock(clock_hr, clock_min);
                
                color_scene_state = COLOR_SCENE_PREPARE_MENU8;
            }

            break;
        }
        case COLOR_SCENE_PREPARE_MENU8:
        {
            //animate the modes panel
            x = ColorScreen_PanelWidget4->fn->getX(ColorScreen_PanelWidget4);

            if ( x - MODES_BACK_PANEL_XPOS > MOVE_DIVIDER)
            {
                ColorScreen_PanelWidget4->fn->setX(ColorScreen_PanelWidget4, x - (x - MODES_BACK_PANEL_XPOS)/MOVE_DIVIDER);
            }
            else
            {
                ColorScreen_PanelWidget4->fn->setX(ColorScreen_PanelWidget4, MODES_BACK_PANEL_XPOS);
                ColorScreen_CookButtonWidget->fn->setVisible(ColorScreen_CookButtonWidget, LE_TRUE);
                ColorScreen_ReheatButtonWidget->fn->setVisible(ColorScreen_ReheatButtonWidget, LE_TRUE);             
                color_scene_state = COLOR_SCENE_PREPARE_MENU9;
            }
            
            break;
        }
        case COLOR_SCENE_PREPARE_MENU9:
        {
            //Animate the label panel
            y = ColorScreen_Screen2LabelPanel->fn->getY(ColorScreen_Screen2LabelPanel);

            if ( y < 0)
            {
                ColorScreen_Screen2LabelPanel->fn->setY(ColorScreen_Screen2LabelPanel, y + 1);
            }
            else
            {
                ColorScreen_Screen2LabelPanel->fn->setY(ColorScreen_Screen2LabelPanel, 0);
                color_scene_state = COLOR_SCENE_PREPARE_MENU10;
            }            

            break;
        }
        case COLOR_SCENE_PREPARE_MENU10:
        {
            color_scene_state = COLOR_SCENE_PROCESS;
            break;
        }
        case COLOR_SCENE_PROCESS:
        {
            if (last_sec != clock_sec)
            {
                if (ColorScreen_Screen2ColonLabel->fn->getVisible(ColorScreen_Screen2ColonLabel) == LE_TRUE)
                    ColorScreen_Screen2ColonLabel->fn->setVisible(ColorScreen_Screen2ColonLabel, LE_FALSE);
                else
                    ColorScreen_Screen2ColonLabel->fn->setVisible(ColorScreen_Screen2ColonLabel, LE_TRUE);
                
                last_sec = clock_sec;
            }
            
            if (last_min != clock_min)
            {
                updateClock(clock_hr, clock_min);           
                
                last_min = clock_min;
            }
            
            switch(event)
            {
                case START_COOKING:
                    color_scene_state = COLOR_SCENE_PREPARE;
                    break;
                case SELECT_ITEM_0:
                {
                    Set_SelectedMenuItem(0);
                    break;
                }
                case SELECT_ITEM_1:
                {
                    Set_SelectedMenuItem(1);
                    break;
                }
                case SELECT_ITEM_2:
                {
                    Set_SelectedMenuItem(2);
                    break;
                }
                case SELECT_ITEM_3:
                {
                    Set_SelectedMenuItem(3);                    
                    break;
                }
                case CHANGE_SCENE:
                {
                    color_scene_state = COLOR_SCENE_EXIT;
                    break;
                }
                default:
                    break;
            }
            
            event = NO_EVENTS;
            
            break;
        }
        case COLOR_SCENE_PREPARE:
        {
            ColorScreen_CookButtonWidget->fn->setPressedImage(ColorScreen_CookButtonWidget, &cancel2);
            ColorScreen_CookButtonWidget->fn->setReleasedImage(ColorScreen_CookButtonWidget, &cancel2);
            ColorScreen_ReheatButtonWidget->fn->setVisible(ColorScreen_ReheatButtonWidget, LE_FALSE);
            ColorScreen_Screen2ColonLabel->fn->setVisible(ColorScreen_Screen2ColonLabel, LE_TRUE);
            
            updateClock(cookSec/60, cookSec%60);
            
            color_scene_state = COLOR_SCENE_COOKING;
            
            cookSec = startCookSec;
            
            break;
        }
        case COLOR_SCENE_COOKING:
        {
            switch(event)
            {
                case STOP_COOKING:
                {
                    color_scene_state = COLOR_SCENE_RETURNING;
                    event = NO_EVENTS;
                    break;
                }
                case SET_COOK_TIME:
                {
                    cookSec = startCookSec - (event_parm * startCookSec) / 100;
            
                    updateClock(cookSec/60, cookSec%60);
                    
                    ColorScreen_ProgressRect->fn->setX(ColorScreen_ProgressRect, 
                                               (-153 * cookSec) / startCookSec);                    
                    
                    event = NO_EVENTS;
                    
                    break;
                }
                default:
                {
            //start progress bar
            if (tick_count_last != tick_count)
            {
                tick_count_last = tick_count;
                        
                if (cookSec > 0)
                {
                    updateClock(cookSec/60, cookSec%60);
                    
                    ColorScreen_ProgressRect->fn->setX(ColorScreen_ProgressRect, 
                                               (-153 * cookSec) / startCookSec);
                    
                    cookSec--;
                }
                else
                {
                    cookSec = startCookSec;
                    
                    ColorScreen_ProgressRect->fn->setX(ColorScreen_ProgressRect, 0);
                    
                            ColorScreen_CookButtonWidget->fn->setPressedImage(ColorScreen_CookButtonWidget, &ok2);
                            ColorScreen_CookButtonWidget->fn->setReleasedImage(ColorScreen_CookButtonWidget, &ok2);
                    
                    updateClock(0, 0);

                    color_scene_state = COLOR_SCENE_DONE; 
                }
            }
            
                    break;
                }
            }
            
            break;
        }
        case COLOR_SCENE_DONE:
        {
            if (last_sec != clock_sec)
            {
                if (ColorScreen_Screen2MainClockPanel->fn->getVisible(ColorScreen_Screen2MainClockPanel) == LE_TRUE)
                {
                    ColorScreen_Screen2MainClockPanel->fn->setVisible(ColorScreen_Screen2MainClockPanel, LE_FALSE);
                }
                else
                {
                    ColorScreen_Screen2MainClockPanel->fn->setVisible(ColorScreen_Screen2MainClockPanel, LE_TRUE);
                }
                
                last_sec = clock_sec;
            }
            
            switch(event)
            {
                case STOP_COOKING:
            {
                ColorScreen_Screen2MainClockPanel->fn->setVisible(ColorScreen_Screen2MainClockPanel, LE_TRUE);
                color_scene_state = COLOR_SCENE_RETURNING;
                event = NO_EVENTS;
                    
                    break;
                }
                case SET_COOK_TIME:
                {
                    cookSec = startCookSec - (event_parm * startCookSec) / 100;
            
                    updateClock(cookSec/60, cookSec%60);
                    
                    ColorScreen_ProgressRect->fn->setX(ColorScreen_ProgressRect, 
                                               (-153 * cookSec) / startCookSec);  
                    
                    ColorScreen_Screen2MainClockPanel->fn->setVisible(ColorScreen_Screen2MainClockPanel, LE_TRUE);
                    ColorScreen_CookButtonWidget->fn->setPressedImage(ColorScreen_CookButtonWidget, &cancel2);
                    ColorScreen_CookButtonWidget->fn->setReleasedImage(ColorScreen_CookButtonWidget, &cancel2);                    
                    
                    color_scene_state = COLOR_SCENE_COOKING;
                    
                    event = NO_EVENTS;
                    
                    break;
                }
                default:
                    break;
            }
            
            break;
        }
        case COLOR_SCENE_RETURNING:
        {
            cookSec = startCookSec;
            
            x = ColorScreen_ProgressRect->fn->getX(ColorScreen_ProgressRect);
            
            if (x > -153)
            {
                ColorScreen_ProgressRect->fn->setX(ColorScreen_ProgressRect, x - 10);
            }
            else
            {
                updateClock(clock_hr, clock_min);
                
                ColorScreen_ReheatButtonWidget->fn->setPressedImage(ColorScreen_ReheatButtonWidget, &reheat2);
                ColorScreen_ReheatButtonWidget->fn->setReleasedImage(ColorScreen_ReheatButtonWidget, &reheat2);
                ColorScreen_ReheatButtonWidget->fn->setVisible(ColorScreen_ReheatButtonWidget, LE_TRUE);                

                ColorScreen_CookButtonWidget->fn->setPressedImage(ColorScreen_CookButtonWidget, &cook2);
                ColorScreen_CookButtonWidget->fn->setReleasedImage(ColorScreen_CookButtonWidget, &cook2);
                ColorScreen_CookButtonWidget->fn->setVisible(ColorScreen_CookButtonWidget, LE_TRUE);                
                
                color_scene_state = COLOR_SCENE_PROCESS;
            }
                
            break;
        }  
        case COLOR_SCENE_EXIT:
        {
    
            ColorScreen_SliderButton2->fn->removeEventFilter(ColorScreen_SliderButton2, color_eventFilter);
    
            GFX_DISP_INTF_PIN_BACKLIGHT_Clear();
            
            SYS_TIME_TimerDestroy(timer);
            
            main_screen_show();
            
            break;
        }
        default:
            break;
                
    }
}

void event_ColorScreen_ButtonWidget1_OnPressed(leButtonWidget* btn)
{
    color_send_event(SELECT_ITEM_0);
}

void event_ColorScreen_ButtonWidget4_OnPressed(leButtonWidget* btn)
{
    color_send_event(SELECT_ITEM_3);
}

void event_ColorScreen_ButtonWidget3_OnPressed(leButtonWidget* btn)
{
    color_send_event(SELECT_ITEM_2);
}

void event_ColorScreen_ButtonWidget2_OnPressed(leButtonWidget* btn)
{
    color_send_event(SELECT_ITEM_1);
}

void event_ColorScreen_ReheatButtonWidget_OnPressed(leButtonWidget* btn)
{
    color_send_event(START_COOKING);
}

void event_ColorScreen_CookButtonWidget_OnPressed(leButtonWidget* btn)
{
    if (color_scene_state == COLOR_SCENE_PROCESS)
    {
        color_send_event(START_COOKING);
    }
    else if (color_scene_state == COLOR_SCENE_COOKING ||
             color_scene_state == COLOR_SCENE_DONE)
    {
        color_send_event(STOP_COOKING);
    }
}

void event_ColorScreen_ButtonWidget5_OnPressed(leButtonWidget* btn)
{
    color_send_event(CHANGE_SCENE);
}

void event_ColorScreen_ButtonWidget6_OnPressed(leButtonWidget* btn)
{
    demo_mode_on = false;
}


void event_ColorScreen_ButtonWidget6_OnReleased(leButtonWidget* btn)
{
    demo_mode_on = true;
}
