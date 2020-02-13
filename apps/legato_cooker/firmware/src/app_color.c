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
static int cookSec = COOK_TIME_SECS;
static int startCookSec = COOK_TIME_SECS;

static unsigned int idle_secs = 0;
static unsigned int demo_mode_count_secs = 0;
static unsigned int demo_mode_event_idx = 0;

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
    
    //reset demo mode
    idle_secs = 0;
    demo_mode_event_idx = 0;
}


static void updateClock(unsigned int high, unsigned int low)
{
    char charBuff[16] = {0};

    //create the time character string from hr, min, sec variables
    sprintf(charBuff, "%02u", high); 
    hrStr.fn->setFromCStr(&hrStr, charBuff);    
    Screen2HourLabel->fn->setString(Screen2HourLabel, (leString*)&hrStr);   

    sprintf(charBuff, "%02u", low); 
    minStr.fn->setFromCStr(&minStr, charBuff);    
    Screen2MinuteLabel->fn->setString(Screen2MinuteLabel, (leString*)&minStr);   
}

static void Timer_Callback ( uintptr_t context)
{
    tick_count++;
    
    if (tick_count > NUM_COUNT_SEC_TICK)
    {
        tick_count = 0;
        
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
        
                idle_secs++;
        
        if (idle_secs > DEMO_MODE_IDLE_TIMEOUT_SECS)
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
    
    MenuItem1Label->fn->setScheme(MenuItem1Label, &UnselectedItemTextScheme);
    MenuItem2Label->fn->setScheme(MenuItem2Label, &UnselectedItemTextScheme);
    MenuItem3Label->fn->setScheme(MenuItem3Label, &UnselectedItemTextScheme);
    MenuItem4Label->fn->setScheme(MenuItem4Label, &UnselectedItemTextScheme);
    
    ButtonImage1->fn->setSize(ButtonImage1, 64, 64);
    ButtonImage2->fn->setSize(ButtonImage2, 64, 64);
    ButtonImage3->fn->setSize(ButtonImage3, 64, 64);
    Button4Image->fn->setSize(Button4Image, 64, 64);
    
    ButtonImage1->fn->setPosition(ButtonImage1, 15, 2);
    ButtonImage2->fn->setPosition(ButtonImage2, 25, 2);
    ButtonImage3->fn->setPosition(ButtonImage3, 15, 2);
    Button4Image->fn->setPosition(Button4Image, 25, 2);
    

    switch(index)
    {
        case 0:
        {
            MenuItem1Label->fn->setScheme(MenuItem1Label, &WhiteTextScheme);
            ButtonImage1->fn->setSize(ButtonImage1, 70, 70);
            ButtonImage1->fn->setPosition(ButtonImage1, 13, 0);
            
            ProgressRect->fn->setScheme(ProgressRect, &Button1Scheme);
            
            startCookSec = 200;
                    
            break;
        }
        case 1:
        {
            MenuItem2Label->fn->setScheme(MenuItem2Label, &WhiteTextScheme);
            ButtonImage2->fn->setSize(ButtonImage2, 70, 70);
            ButtonImage2->fn->setPosition(ButtonImage2, 23, 0);
            
            ProgressRect->fn->setScheme(ProgressRect, &Button2Scheme);
            
            startCookSec = 110;
                    
            break;
        }
        case 2:
        {
            MenuItem3Label->fn->setScheme(MenuItem3Label, &WhiteTextScheme);
            ButtonImage3->fn->setSize(ButtonImage3, 70, 70);
            ButtonImage3->fn->setPosition(ButtonImage3, 13, 0);                    
                 
            ProgressRect->fn->setScheme(ProgressRect, &Button3Scheme);
            
            startCookSec = 60;
            
            break;
        }
        case 3:
        {
            MenuItem4Label->fn->setScheme(MenuItem4Label, &WhiteTextScheme);
            Button4Image->fn->setSize(Button4Image, 70, 70);
            Button4Image->fn->setPosition(Button4Image, 23, 0);                    
                    
            ProgressRect->fn->setScheme(ProgressRect, &Button4Scheme);
            
            startCookSec = 50;
            
            break;
        }
        default:
        {
            break;
        }
    }
}

void ColorScreen_OnShow(void)
{
    //Hide the other menu items
    MenuItem2->fn->setVisible(MenuItem2, LE_FALSE);
    MenuItem3->fn->setVisible(MenuItem3, LE_FALSE);
    MenuItem4->fn->setVisible(MenuItem4, LE_FALSE);

    //Hide all the menu item images
    ButtonImage1->fn->setVisible(ButtonImage1, LE_FALSE);
    ButtonImage2->fn->setVisible(ButtonImage2, LE_FALSE);
    ButtonImage3->fn->setVisible(ButtonImage3, LE_FALSE);
    Button4Image->fn->setVisible(Button4Image, LE_FALSE);

    //Hide all the background gray rects
    ButtonRect1Back->fn->setVisible(ButtonRect1Back, LE_FALSE);
    Button2RectBack->fn->setVisible(Button2RectBack, LE_FALSE);
    Button3RectBack->fn->setVisible(Button3RectBack, LE_FALSE);
    Button4RectBack->fn->setVisible(Button4RectBack, LE_FALSE);

    //Hide all the menu labels
    MenuItem1Label->fn->setVisible(MenuItem1Label, LE_FALSE);
    MenuItem2Label->fn->setVisible(MenuItem2Label, LE_FALSE);
    MenuItem3Label->fn->setVisible(MenuItem3Label, LE_FALSE);
    MenuItem4Label->fn->setVisible(MenuItem4Label, LE_FALSE);

    // Hide the clock panel
    Screen2MainClockPanel->fn->setVisible(Screen2MainClockPanel, LE_FALSE);

    //Hide the Banner
    Screen2LabelPanel->fn->setY(Screen2LabelPanel, -76);

    //Hide the mode buttons
    CookButtonWidget->fn->setVisible(CookButtonWidget, LE_FALSE);
    ReheatButtonWidget->fn->setVisible(ReheatButtonWidget, LE_FALSE);

    //Hide the clock label
    Screen2ClockLabel->fn->setVisible(Screen2ClockLabel, LE_FALSE);
    
    //Hide the progress rectangle
    ProgressRect->fn->setX(ProgressRect, -153);
    ProgressRect->fn->setY(ProgressRect, 30);

    //Hide the back panels
    PanelWidget5->fn->setY(PanelWidget5, 320);
    PanelWidget4->fn->setX(PanelWidget4, 480);
    
    leFixedString_Constructor(&hrStr, hrStrBuff, 16);
    hrStr.fn->setFont(&hrStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              string_DefaultHour2,
                                                              0));    
    
    leFixedString_Constructor(&minStr, minStrBuff, 16);
    minStr.fn->setFont(&minStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              string_DefaultMinute,
                                                              0));
    
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
            QuickSelectionsPanel->fn->setX(QuickSelectionsPanel, 0);
            
            Rect_PreAnimate(Button1Rect);
            
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
            if (Rect_Animate(Button1Rect, 0, COLOR_BAR_WIDTH) == true)
            {
                MenuItem1Label->fn->setVisible(MenuItem1Label, LE_TRUE);
                ButtonImage1->fn->setVisible(ButtonImage1, LE_TRUE);
                MenuItem2->fn->setVisible(MenuItem2, LE_TRUE);
                ButtonImage2->fn->setVisible(ButtonImage2, LE_FALSE);

                Rect_PreAnimate(Button2Rect);

                color_scene_state = COLOR_SCENE_PREPARE_MENU3;
            }
            break;
        }
        case COLOR_SCENE_PREPARE_MENU3:
        {    
            if (Rect_Animate(Button2Rect, 0, COLOR_BAR_WIDTH) == true)
            {
                MenuItem2Label->fn->setVisible(MenuItem2Label, LE_TRUE);
                ButtonImage2->fn->setVisible(ButtonImage2, LE_TRUE);                
                MenuItem3->fn->setVisible(MenuItem3, LE_TRUE);
                ButtonImage3->fn->setVisible(ButtonImage3, LE_FALSE);

                Rect_PreAnimate(Button3Rect);

                color_scene_state = COLOR_SCENE_PREPARE_MENU4;
            }
            break;
        }
        case COLOR_SCENE_PREPARE_MENU4:
        {    
            if (Rect_Animate(Button3Rect, 0, COLOR_BAR_WIDTH) == true)
            {
                MenuItem3Label->fn->setVisible(MenuItem3Label, LE_TRUE);
                ButtonImage3->fn->setVisible(ButtonImage3, LE_TRUE);
                MenuItem4->fn->setVisible(MenuItem4, LE_TRUE);
                
                Button4Image->fn->setVisible(Button4Image, LE_FALSE);

                Rect_PreAnimate(Button4Rect);

                color_scene_state = COLOR_SCENE_PREPARE_MENU5;
            }
            break;
        }
        case COLOR_SCENE_PREPARE_MENU5:
        {    
            if (Rect_Animate(Button4Rect, 0, COLOR_BAR_WIDTH) == true)
            {
                MenuItem4Label->fn->setVisible(MenuItem4Label, LE_TRUE);                
                Button4Image->fn->setVisible(Button4Image, LE_TRUE);
                    
                color_scene_state = COLOR_SCENE_PREPARE_MENU6;
            }            
            break;
        }
        case COLOR_SCENE_PREPARE_MENU6:
        {
            ButtonRect1Back->fn->setVisible(ButtonRect1Back, LE_TRUE);
            Button2RectBack->fn->setVisible(Button2RectBack, LE_TRUE);
            Button3RectBack->fn->setVisible(Button3RectBack, LE_TRUE);
            Button4RectBack->fn->setVisible(Button4RectBack, LE_TRUE);
            
            Set_SelectedMenuItem(0);
            
            color_scene_state = COLOR_SCENE_PREPARE_MENU7;
            break;
        }
        case COLOR_SCENE_PREPARE_MENU7:
        {
            //animate the clock back panel            
            y = PanelWidget5->fn->getY(PanelWidget5);

            if ( y - CLOCK_BACK_PANEL_YPOS > MOVE_DIVIDER)
            {
                PanelWidget5->fn->setY(PanelWidget5, y - (y - CLOCK_BACK_PANEL_YPOS)/MOVE_DIVIDER);
            }
            else
            {
                PanelWidget5->fn->setY(PanelWidget5, CLOCK_BACK_PANEL_YPOS);
                Screen2MainClockPanel->fn->setVisible(Screen2MainClockPanel, LE_TRUE);   
                updateClock(clock_hr, clock_min);
                
                color_scene_state = COLOR_SCENE_PREPARE_MENU8;
            }

            break;
        }
        case COLOR_SCENE_PREPARE_MENU8:
        {
            //animate the modes panel
            x = PanelWidget4->fn->getX(PanelWidget4);

            if ( x - MODES_BACK_PANEL_XPOS > MOVE_DIVIDER)
            {
                PanelWidget4->fn->setX(PanelWidget4, x - (x - MODES_BACK_PANEL_XPOS)/MOVE_DIVIDER);
            }
            else
            {
                PanelWidget4->fn->setX(PanelWidget4, MODES_BACK_PANEL_XPOS);
                CookButtonWidget->fn->setVisible(CookButtonWidget, LE_TRUE);
                ReheatButtonWidget->fn->setVisible(ReheatButtonWidget, LE_TRUE);             
                color_scene_state = COLOR_SCENE_PREPARE_MENU9;
            }
            
            break;
        }
        case COLOR_SCENE_PREPARE_MENU9:
        {
            //Animate the label panel
            y = Screen2LabelPanel->fn->getY(Screen2LabelPanel);

            if ( y < 0)
            {
                Screen2LabelPanel->fn->setY(Screen2LabelPanel, y + 1);
            }
            else
            {
                Screen2LabelPanel->fn->setY(Screen2LabelPanel, 0);
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
                if (Screen2ColonLabel->fn->getVisible(Screen2ColonLabel) == LE_TRUE)
                    Screen2ColonLabel->fn->setVisible(Screen2ColonLabel, LE_FALSE);
                else
                    Screen2ColonLabel->fn->setVisible(Screen2ColonLabel, LE_TRUE);
                
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
            CookButtonWidget->fn->setPressedImage(CookButtonWidget, &cancel_80);
            CookButtonWidget->fn->setReleasedImage(CookButtonWidget, &cancel_80);
            ReheatButtonWidget->fn->setVisible(ReheatButtonWidget, LE_FALSE);
            Screen2ColonLabel->fn->setVisible(Screen2ColonLabel, LE_TRUE);
            updateClock(cookSec/60, cookSec%60);
            
            color_scene_state = COLOR_SCENE_COOKING;
            
            cookSec = startCookSec;
            
            break;
        }
        case COLOR_SCENE_COOKING:
        {
            //start progress bar
            if (tick_count_last != tick_count)
            {
                tick_count_last = tick_count;
                        
                if (cookSec > 0)
                {
                    updateClock(cookSec/60, cookSec%60);
                    
                    ProgressRect->fn->setX(ProgressRect, 
                                       (-153 * cookSec) / COOK_TIME_SECS);
                    
                    cookSec--;
                    
                }
                else
                {
                    cookSec = startCookSec;
                    
                    ProgressRect->fn->setX(ProgressRect, 0);
                    
                    CookButtonWidget->fn->setPressedImage(CookButtonWidget, &ok_80);
                    CookButtonWidget->fn->setReleasedImage(CookButtonWidget, &ok_80);
                    
                    updateClock(0, 0);

                    color_scene_state = COLOR_SCENE_DONE; 
                }
            }
            
            if (event == STOP_COOKING)
            {
                color_scene_state = COLOR_SCENE_RETURNING;
                event = NO_EVENTS;
            }
            
            break;
        }
        case COLOR_SCENE_DONE:
        {
            if (last_sec != clock_sec)
            {
                if (Screen2MainClockPanel->fn->getVisible(Screen2MainClockPanel) == LE_TRUE)
                {
                    Screen2MainClockPanel->fn->setVisible(Screen2MainClockPanel, LE_FALSE);
                }
                else
                {
                    Screen2MainClockPanel->fn->setVisible(Screen2MainClockPanel, LE_TRUE);
                }
                
                last_sec = clock_sec;
            }
            
            if (event == STOP_COOKING)
            {
                Screen2MainClockPanel->fn->setVisible(Screen2MainClockPanel, LE_TRUE);
                color_scene_state = COLOR_SCENE_RETURNING;
                event = NO_EVENTS;
            }
            
            break;
        }
        case COLOR_SCENE_RETURNING:
        {
            cookSec = startCookSec;
            
            x = ProgressRect->fn->getX(ProgressRect);
            
            if (x > -153)
            {
                ProgressRect->fn->setX(ProgressRect, x - 10);
            }
            else
            {
                updateClock(clock_hr, clock_min);
                
                ReheatButtonWidget->fn->setPressedImage(ReheatButtonWidget, &reheat100);
                ReheatButtonWidget->fn->setReleasedImage(ReheatButtonWidget, &reheat100);
                ReheatButtonWidget->fn->setVisible(ReheatButtonWidget, LE_TRUE);                

                CookButtonWidget->fn->setPressedImage(CookButtonWidget, &cook100);
                CookButtonWidget->fn->setReleasedImage(CookButtonWidget, &cook100);
                CookButtonWidget->fn->setVisible(CookButtonWidget, LE_TRUE);                
                
                color_scene_state = COLOR_SCENE_PROCESS;
            }
                
            break;
        }  
        case COLOR_SCENE_EXIT:
        {
            GFX_DISP_INTF_PIN_BACKLIGHT_Clear();
            SYS_TIME_TimerDestroy(timer);
            
            main_screen_show();
            
            break;
        }
        default:
            break;
                
    }
}

void ButtonWidget1_OnPressed(leButtonWidget* btn)
{
    color_send_event(SELECT_ITEM_0);
}

void ButtonWidget4_OnPressed(leButtonWidget* btn)
{
    color_send_event(SELECT_ITEM_3);
}

void ButtonWidget3_OnPressed(leButtonWidget* btn)
{
    color_send_event(SELECT_ITEM_2);
}

void ButtonWidget2_OnPressed(leButtonWidget* btn)
{
    color_send_event(SELECT_ITEM_1);
}

void ReheatButtonWidget_OnPressed(leButtonWidget* btn)
{
    color_send_event(START_COOKING);
}

void CookButtonWidget_OnPressed(leButtonWidget* btn)
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

void ButtonWidget5_OnPressed(leButtonWidget* btn)
{
    color_send_event(CHANGE_SCENE);
}