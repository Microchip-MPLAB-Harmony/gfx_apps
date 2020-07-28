#include "gfx/legato/generated/le_gen_init.h"
#include "definitions.h"
#include "app.h"

#include <stdio.h>
#include <string.h>

#define MAIN_MENU_TIMER_PERIOD_MS 100
#define NUM_COUNT_SEC_TICK (1000/MAIN_MENU_TIMER_PERIOD_MS)
#define PROGRESS_BAR_BLOCK_EXTEND 10
#define DELTA_RECT_PIX 30
#define COOK_TIME_SECS 120
#define DEMO_MODE_IDLE_TIMEOUT_SECS 5

typedef enum
{
    MAIN_MENU_INIT,
    MAIN_MENU_INIT2,
    MAIN_MENU_PROCESS,
    MAIN_MENU_PREPARE_PROGRESS_SCENE1,
    MAIN_MENU_PREPARE_PROGRESS_SCENE2,
    MAIN_MENU_PREPARE_PROGRESS_SCENE3,
    MAIN_MENU_PREPARE_PROGRESS_SCENE4,
    MAIN_MENU_PREPARE_PROGRESS_SCENE5,
    MAIN_MENU_PREPARE_PROGRESS_SCENE6,            
    MAIN_MENU_PREPARE_PROGRESS_SCENE7,
    MAIN_MENU_PREPARE_PROGRESS_SCENE8,
    MAIN_MENU_SHOW_PROGRESS_SCENE,
    MAIN_MENU_PROCESS_PROGRESS_SCENE,
    MAIN_MENU_DONE_PROGRESS_SCENE,
    MAIN_MENU_IDLE_PROGRESS_SCENE,
    MAIN_MENU_EXIT_PROGRESS_SCENE1,
    MAIN_MENU_EXIT_PROGRESS_SCENE2,        
    MAIN_MENU_EXIT_PROGRESS_SCENE3,
    MAIN_MENU_EXIT_PROGRESS_SCENE4,
    MAIN_MENU_EXIT_PROGRESS_SCENE5,
    MAIN_MENU_EXIT_PROGRESS_SCENE6,
    MAIN_MENU_EXIT_PROGRESS_SCENE7,
    MAIN_MENU_SHOW_MAIN,
    MAIN_MENU_CHANGE_SCREEN,
    MAIN_MENU_EXITED,
} MAIN_MENU_SCENE_STATE;

typedef enum
{
    BAKE_MODE,
    COOK_MODE,
    REHEAT_MODE,
    BROIL_MODE,
} OPERATION_MODE;

typedef enum
{
    EVENT_NONE,
    EVENT_START_COOKING,
    EVENT_STOP_COOKING,
    EVENT_PAUSE_COOKING,
    EVENT_CONTINUE_COOKING,
    EVENT_CHANGE_SCENE, 
    EVENT_SET_COOK_TIME,
} MAIN_EVENT;

typedef struct
{
    unsigned int timeout;
    MAIN_EVENT event;
} DEMO_MODE_OBJ;

static MAIN_MENU_SCENE_STATE main_menu_state = MAIN_MENU_INIT;
static OPERATION_MODE mode;
static SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;
static leFixedString hrStr, minStr, progressStr;
static leChar hrStrBuff[16] = {0};
static leChar minStrBuff[16] = {0};
static leChar progressStrBuff[16] = {0};
char charBuff[16] = {0};    
static int tick_count, sec_count = 0;
static unsigned int width, x;
static int tick_count_last = 0;
static int cookSec = COOK_TIME_SECS;
static MAIN_EVENT event = EVENT_NONE;
static uint32_t event_parm = 0;

unsigned int clock_sec = 0;
unsigned int clock_min = 0;
unsigned int clock_hr = 12;

//This should match the listwheel items
leImage * smart_favorites_images[] =
{
    &hotdog70,
    &kabobs70,
    &meat70,
    &bacon70,
    &veggies70,    
};

leImage * mode_images[] = 
{
    &bake100,
    &cook100,
    &reheat100,
    &broil100,
    
};

static DEMO_MODE_OBJ demo_mode_obj[] =
{
    {3, EVENT_STOP_COOKING},
    {3, EVENT_START_COOKING},
    {5, EVENT_PAUSE_COOKING},
    {3, EVENT_CONTINUE_COOKING},
    {10, EVENT_STOP_COOKING},
    {3, EVENT_CHANGE_SCENE},
};

static void updateClock(void)
{
    char charBuff[16] = {0};

    clock_sec++;
    if (clock_sec == 60)
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

    //create the time character string from hr, min, sec variables
    sprintf(charBuff, "%02u", clock_hr); 
    hrStr.fn->setFromCStr(&hrStr, charBuff);    
    MainMenu_HourLabel->fn->setString(MainMenu_HourLabel, (leString*)&hrStr);   
    
    sprintf(charBuff, "%02u", clock_min); 
    minStr.fn->setFromCStr(&minStr, charBuff);    
    MainMenu_MinuteLabel->fn->setString(MainMenu_MinuteLabel, (leString*)&minStr);   
}

static void startMode(OPERATION_MODE new_mode)
{
    mode = new_mode;
    event = EVENT_START_COOKING;
}
static void Timer_Callback ( uintptr_t context)
{
    static bool clock_dot_visible = true;

    tick_count++;
    
    if (tick_count > NUM_COUNT_SEC_TICK)
    {
        tick_count = 0;
        sec_count++;
        idle_secs++;
        
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
            
            MainMenu_DemoModeOnButton->fn->setVisible(MainMenu_DemoModeOnButton, sec_count%2);
        }
        else
        {
            MainMenu_DemoModeOnButton->fn->setVisible(MainMenu_DemoModeOnButton, LE_TRUE);
        }
    
        if (clock_dot_visible == true)
        {
            clock_dot_visible = false;
            MainMenu_ColonLabel->fn->setVisible(MainMenu_ColonLabel, LE_FALSE);
        }
        else
        {
            clock_dot_visible = true;
            MainMenu_ColonLabel->fn->setVisible(MainMenu_ColonLabel, LE_TRUE);
        }

        updateClock();
    }
}

static void main_send_event(MAIN_EVENT evt)
{
    event = evt;
}

void main_screen_show(void)
{
    main_menu_state = MAIN_MENU_INIT;
    event = EVENT_NONE;
    legato_showScreen(screenID_MainMenu);
}

static bool show_main_menu(bool show)
{
    leBool lshow = (show == true) ? LE_TRUE : LE_FALSE;
    const leScheme* scheme = (show == true) ? &WhiteTextScheme : &OffWhiteTextScheme;
    
    MainMenu_MainPanel->fn->setVisible(MainMenu_MainPanel, lshow);
    MainMenu_PanelWidget3->fn->setVisible(MainMenu_PanelWidget3, lshow);
    MainMenu_ImageWidget1->fn->setVisible(MainMenu_ImageWidget1, lshow);
    MainMenu_ImageWidget2->fn->setVisible(MainMenu_ImageWidget2, lshow);
    MainMenu_ImageWidget3->fn->setVisible(MainMenu_ImageWidget3, lshow);
    MainMenu_ImageWidget4->fn->setVisible(MainMenu_ImageWidget4, lshow);
    MainMenu_ImageWidget8->fn->setVisible(MainMenu_ImageWidget8, lshow);
    
    MainMenu_HourLabel->fn->setScheme(MainMenu_HourLabel, scheme);
    MainMenu_ColonLabel->fn->setScheme(MainMenu_ColonLabel, scheme);
    MainMenu_MinuteLabel->fn->setScheme(MainMenu_MinuteLabel, scheme);
    
    return true;
}


static leBool main_filterEvent(leWidget* target, leWidgetEvent* evt, void* data)
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
            
            event = EVENT_SET_COOK_TIME;
            
            evt->accepted = LE_TRUE;
            
            break;
        }
        default:
            break;
    }
    
    return LE_FALSE;
}

static leWidgetEventFilter main_eventFilter =
{
    main_filterEvent,
    NULL
};


// event handlers
void MainMenu_OnShow(void)
{
    leFixedString_Constructor(&hrStr, hrStrBuff, 16);
    hrStr.fn->setFont(&hrStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DefaultMinute,
                                                              0));    
    
    leFixedString_Constructor(&minStr, minStrBuff, 16);
    minStr.fn->setFont(&minStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DefaultMinute,
                                                              0));
    
    leFixedString_Constructor(&progressStr, progressStrBuff, 16);
    progressStr.fn->setFont(&progressStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              stringID_DefaultCookTime,
                                                              0));
    
    MainMenu_DemoModeOnButton->fn->setPressed(MainMenu_DemoModeOnButton, (leBool) (demo_mode_on == false));
    
    MainMenu_SliderButton0->fn->installEventFilter(MainMenu_SliderButton0, main_eventFilter);
}

void MainMenu_OnHide(void)
{
    hrStr.fn->destructor(&hrStr);
    minStr.fn->destructor(&minStr);
    progressStr.fn->destructor(&progressStr);
}

void MainMenu_OnUpdate(void)
{
    //Wait for the library to be done drawing before processing events/animation
    if(leGetRenderState()->frameState != LE_FRAME_READY || leEvent_GetCount() != 0)
        return;
    
    switch(main_menu_state)
    {
        case MAIN_MENU_INIT:
        {
            idle_secs = 0;
            demo_mode_count_secs = 0;
            demo_mode_event_idx = 0;
            
            timer = SYS_TIME_CallbackRegisterMS(Timer_Callback, 1, MAIN_MENU_TIMER_PERIOD_MS, SYS_TIME_PERIODIC);
            
            main_menu_state = MAIN_MENU_INIT2;
            
            break;
        }
        case MAIN_MENU_INIT2:
        {
            main_menu_state = MAIN_MENU_PROCESS;
            
            GFX_DISP_INTF_PIN_BACKLIGHT_Set();
            
            break;
        }
        case MAIN_MENU_PROCESS:
        {
            switch(event)
            {
                case EVENT_START_COOKING:
                {
                    main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE1;
                    event = EVENT_NONE;
                    break;
                }
                case EVENT_CHANGE_SCENE:
                {
                    main_menu_state = MAIN_MENU_CHANGE_SCREEN;
                    event = EVENT_NONE;
                    break;
                }                    
                default:
                    break;
            }
            
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE1:
        {
            show_main_menu(false);
            main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE2;
            
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE2:
        {
            //Prepare to show progress panel
            MainMenu_PanelWidget0->fn->setX(MainMenu_PanelWidget0, 0);   
            
            //Restore and show black rects to hide border
            MainMenu_RectangleWidget0->fn->setVisible(MainMenu_RectangleWidget0, LE_TRUE);
            MainMenu_RectangleWidget1->fn->setVisible(MainMenu_RectangleWidget1, LE_TRUE);
            MainMenu_RectangleWidget2->fn->setVisible(MainMenu_RectangleWidget2, LE_TRUE);
            MainMenu_RectangleWidget3->fn->setVisible(MainMenu_RectangleWidget3, LE_TRUE); 
            MainMenu_RectangleWidget0->fn->setWidth(MainMenu_RectangleWidget0, 340);
            MainMenu_RectangleWidget0->fn->setX(MainMenu_RectangleWidget0, 66);
            MainMenu_RectangleWidget1->fn->setWidth(MainMenu_RectangleWidget1, 340);
            MainMenu_RectangleWidget1->fn->setX(MainMenu_RectangleWidget1, 66);
            
            //Reset and hide the progress indicators
            MainMenu_ProgressBarWidget0->fn->setValue(MainMenu_ProgressBarWidget0, 0);
            MainMenu_ProgressBarWidget0->fn->setVisible(MainMenu_ProgressBarWidget0, LE_FALSE);
            MainMenu_CookTimeLabel->fn->setVisible(MainMenu_CookTimeLabel, LE_FALSE);
            MainMenu_CancelButton->fn->setPressedImage(MainMenu_CancelButton, &cancel_80);
            MainMenu_CancelButton->fn->setReleasedImage(MainMenu_CancelButton, &cancel_80);            
            MainMenu_CancelButton->fn->setVisible(MainMenu_CancelButton, LE_FALSE);
            
            //Prepare and Hide the Mode Image
            MainMenu_ModeImageWidget->fn->setVisible(MainMenu_ModeImageWidget, LE_FALSE);
            MainMenu_ModeImageWidget->fn->setImage(MainMenu_ModeImageWidget, mode_images[mode]);
            
            main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE3;
            
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE3:
        {
            MainMenu_RectangleWidget3->fn->setVisible(MainMenu_RectangleWidget3, LE_FALSE); 
            main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE4;
            
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE4:            
        {
            uint32_t length = MainMenu_RectangleWidget0->fn->getWidth(MainMenu_RectangleWidget0);
            uint32_t xpos = MainMenu_RectangleWidget0->fn->getX(MainMenu_RectangleWidget0);

            if (length > DELTA_RECT_PIX)
            {
                MainMenu_RectangleWidget0->fn->setWidth(MainMenu_RectangleWidget0, length - DELTA_RECT_PIX);
                MainMenu_RectangleWidget0->fn->setX(MainMenu_RectangleWidget0, xpos + DELTA_RECT_PIX);
                MainMenu_RectangleWidget1->fn->setWidth(MainMenu_RectangleWidget1, length - DELTA_RECT_PIX);
                MainMenu_RectangleWidget1->fn->setX(MainMenu_RectangleWidget1, xpos + DELTA_RECT_PIX);
            }
            else
            {
                MainMenu_RectangleWidget0->fn->setVisible(MainMenu_RectangleWidget0, LE_FALSE);
                MainMenu_RectangleWidget1->fn->setVisible(MainMenu_RectangleWidget1, LE_FALSE);
                MainMenu_RectangleWidget1->fn->setVisible(MainMenu_RectangleWidget2, LE_FALSE);
                
                main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE5;
            }
                
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE5:
        {
            width = MainMenu_ProgressBarWidget0->fn->getWidth(MainMenu_ProgressBarWidget0);
            x = MainMenu_ProgressBarWidget0->fn->getX(MainMenu_ProgressBarWidget0);
                        
            MainMenu_ProgressBarWidget0->fn->setVisible(MainMenu_ProgressBarWidget0, LE_TRUE);
            MainMenu_ProgressBarWidget0->fn->setValue(MainMenu_ProgressBarWidget0, 0);       
            
            MainMenu_ProgressBarWidget0->fn->setX(MainMenu_ProgressBarWidget0, x + (width*3)/8);
            MainMenu_ProgressBarWidget0->fn->setWidth(MainMenu_ProgressBarWidget0, width/4);
            
            main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE6;
            break;
        }        
        case MAIN_MENU_PREPARE_PROGRESS_SCENE6:
        {
            width = MainMenu_ProgressBarWidget0->fn->getWidth(MainMenu_ProgressBarWidget0);
            x = MainMenu_ProgressBarWidget0->fn->getX(MainMenu_ProgressBarWidget0);
            
            if (width < 280 - PROGRESS_BAR_BLOCK_EXTEND)
            {
                MainMenu_ProgressBarWidget0->fn->setWidth(MainMenu_ProgressBarWidget0, 
                                            width + PROGRESS_BAR_BLOCK_EXTEND);
                MainMenu_ProgressBarWidget0->fn->setX(MainMenu_ProgressBarWidget0, x - PROGRESS_BAR_BLOCK_EXTEND/2);
            }
            else
            {
                MainMenu_ProgressBarWidget0->fn->setWidth(MainMenu_ProgressBarWidget0, 280);
                MainMenu_ProgressBarWidget0->fn->setX(MainMenu_ProgressBarWidget0, 104);
                main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE7;
            }
            
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE7:
        {
            MainMenu_CookTimeLabel->fn->setVisible(MainMenu_CookTimeLabel, LE_TRUE);
            
            main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE8;
            break;
        }        
        case MAIN_MENU_PREPARE_PROGRESS_SCENE8:
        {
            MainMenu_ModeImageWidget->fn->setVisible(MainMenu_ModeImageWidget, LE_TRUE);  
            MainMenu_CancelButton->fn->setVisible(MainMenu_CancelButton, LE_TRUE);            
            cookSec = COOK_TIME_SECS;
                        
            main_menu_state = MAIN_MENU_PROCESS_PROGRESS_SCENE;
            
            break;
        }        
        case MAIN_MENU_PROCESS_PROGRESS_SCENE:
        {
            switch(event)
            {
                case EVENT_STOP_COOKING:
                {
                    main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE1;
            
                    event = EVENT_NONE;
                    
                    break;
                }
                case EVENT_PAUSE_COOKING:
                {
                    main_menu_state = MAIN_MENU_IDLE_PROGRESS_SCENE;
                    
                    event = EVENT_NONE;
                    
                    break;
                }
                case EVENT_SET_COOK_TIME:
                {
                    cookSec = COOK_TIME_SECS - (event_parm * COOK_TIME_SECS) / 100;
            
                    sprintf(charBuff, "%u:%02u", cookSec/60, cookSec%60); 
                    progressStr.fn->setFromCStr(&progressStr, charBuff);    
                    MainMenu_CookTimeLabel->fn->setString(MainMenu_CookTimeLabel, (leString*)&progressStr);    
                    MainMenu_ProgressBarWidget0->fn->setValue(MainMenu_ProgressBarWidget0, event_parm);
                    
                    MainMenu_CookTimeLabel->fn->setVisible(MainMenu_CookTimeLabel, LE_TRUE);
                    
                    event = EVENT_NONE;
                    
                    break;
                }                  
                default:
                {
            if (tick_count_last != tick_count)
            {
                tick_count_last = tick_count;
                        
                if (cookSec > 0)
                {
                            sprintf(charBuff, "%u:%02u", cookSec/60, cookSec%60); 
                            progressStr.fn->setFromCStr(&progressStr, charBuff);    
                    MainMenu_CookTimeLabel->fn->setString(MainMenu_CookTimeLabel, (leString*)&progressStr);                       
                    
                    MainMenu_ProgressBarWidget0->fn->setValue(MainMenu_ProgressBarWidget0, 
                                        100 - (100 * cookSec) / COOK_TIME_SECS);
                    
                    cookSec--;
                    
                }
                else
                {
                    cookSec = COOK_TIME_SECS;
                    
                    MainMenu_ProgressBarWidget0->fn->setValue(MainMenu_ProgressBarWidget0, 100);
                            sprintf(charBuff, "Done"); 
                            progressStr.fn->setFromCStr(&progressStr, charBuff);    
                    MainMenu_CookTimeLabel->fn->setString(MainMenu_CookTimeLabel, (leString*)&progressStr);   
                    MainMenu_CancelButton->fn->setPressedImage(MainMenu_CancelButton, &ok_80);
                    MainMenu_CancelButton->fn->setReleasedImage(MainMenu_CancelButton, &ok_80);
                    main_menu_state = MAIN_MENU_DONE_PROGRESS_SCENE; 
                }
            }
                    break;
                }
            }
            
            break;
        }
        case MAIN_MENU_IDLE_PROGRESS_SCENE:
        case MAIN_MENU_DONE_PROGRESS_SCENE:
        {
            static int last_sec_count = 0;
            
            if (last_sec_count != sec_count)
            {
                if (MainMenu_CookTimeLabel->fn->getVisible(MainMenu_CookTimeLabel) == LE_TRUE)
                    MainMenu_CookTimeLabel->fn->setVisible(MainMenu_CookTimeLabel, LE_FALSE);
                else
                    MainMenu_CookTimeLabel->fn->setVisible(MainMenu_CookTimeLabel, LE_TRUE);
                
                last_sec_count = sec_count;
            }
            
            switch(event)
            {
                case EVENT_CONTINUE_COOKING:
                {
                    if (main_menu_state == MAIN_MENU_IDLE_PROGRESS_SCENE)
                    {
                        main_menu_state = MAIN_MENU_PROCESS_PROGRESS_SCENE;
                        MainMenu_CookTimeLabel->fn->setVisible(MainMenu_CookTimeLabel, LE_TRUE);                        
                    }
                    
                    event = EVENT_NONE;
                    break;
                }
                case EVENT_STOP_COOKING:
                {
                    main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE1;
                    
                    event = EVENT_NONE;
                    break;
                }
                case EVENT_SET_COOK_TIME:
                {
                    cookSec = COOK_TIME_SECS - (event_parm * COOK_TIME_SECS) / 100;
            
                    sprintf(charBuff, "%u:%02u", cookSec/60, cookSec%60); 
                    progressStr.fn->setFromCStr(&progressStr, charBuff);    
                    MainMenu_CookTimeLabel->fn->setString(MainMenu_CookTimeLabel, (leString*)&progressStr);    
                    MainMenu_ProgressBarWidget0->fn->setValue(MainMenu_ProgressBarWidget0, event_parm);
                    
                    MainMenu_CookTimeLabel->fn->setVisible(MainMenu_CookTimeLabel, LE_TRUE);
                    
                    //cook time has been adjusted, switch back to idle/paused state
                    if (main_menu_state == MAIN_MENU_DONE_PROGRESS_SCENE)
                    {
                        MainMenu_CancelButton->fn->setPressedImage(MainMenu_CancelButton, &cancel_80);
                        MainMenu_CancelButton->fn->setReleasedImage(MainMenu_CancelButton, &cancel_80);  
                        main_menu_state = MAIN_MENU_PROCESS_PROGRESS_SCENE;
                    }
                    
                    event = EVENT_NONE;
                    
                    break;
                }
                default:
                    break;
            }
            
            break;
        }
        case MAIN_MENU_EXIT_PROGRESS_SCENE1:
        {
            MainMenu_ModeImageWidget->fn->setVisible(MainMenu_ModeImageWidget, LE_FALSE);  
            MainMenu_CancelButton->fn->setVisible(MainMenu_CancelButton, LE_FALSE);   
            main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE2;
            
            break;
        }
        case MAIN_MENU_EXIT_PROGRESS_SCENE2:
        {
            width = MainMenu_ProgressBarWidget0->fn->getWidth(MainMenu_ProgressBarWidget0);
            x = MainMenu_ProgressBarWidget0->fn->getX(MainMenu_ProgressBarWidget0);
            
            if (width > PROGRESS_BAR_BLOCK_EXTEND)
            {
                MainMenu_ProgressBarWidget0->fn->setWidth(MainMenu_ProgressBarWidget0, 
                                            width - PROGRESS_BAR_BLOCK_EXTEND);
                MainMenu_ProgressBarWidget0->fn->setX(MainMenu_ProgressBarWidget0, x + PROGRESS_BAR_BLOCK_EXTEND/2);
            }
            else
            {
                char charBuff[16] = {0}; 
                
                MainMenu_ProgressBarWidget0->fn->setWidth(MainMenu_ProgressBarWidget0, 0);
                MainMenu_ProgressBarWidget0->fn->setVisible(MainMenu_ProgressBarWidget0, LE_FALSE);
                
                sprintf(charBuff, "2:00"); 
                progressStr.fn->setFromCStr(&progressStr, charBuff);    
                MainMenu_CookTimeLabel->fn->setString(MainMenu_CookTimeLabel, (leString*)&progressStr);                       
                                    
                MainMenu_CookTimeLabel->fn->setVisible(MainMenu_CookTimeLabel, LE_FALSE);   
                main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE3;
            }
            break;
        }
        case MAIN_MENU_EXIT_PROGRESS_SCENE3:
        {
            MainMenu_PanelWidget0->fn->setX(MainMenu_PanelWidget0, 480); 
            
            main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE4;
            
            break;
        }
        case MAIN_MENU_EXIT_PROGRESS_SCENE4:
        {
            MainMenu_ImageWidget1->fn->setVisible(MainMenu_ImageWidget1, LE_TRUE);
            MainMenu_ImageWidget8->fn->setVisible(MainMenu_ImageWidget8, LE_TRUE);  
            
            main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE5;
            break;
        }
        case MAIN_MENU_EXIT_PROGRESS_SCENE5:
        {
            MainMenu_ImageWidget3->fn->setVisible(MainMenu_ImageWidget3, LE_TRUE);
            MainMenu_ImageWidget4->fn->setVisible(MainMenu_ImageWidget4, LE_TRUE);
            MainMenu_PanelWidget3->fn->setVisible(MainMenu_PanelWidget3, LE_TRUE);
                
            main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE6;
            break;
        }
        case MAIN_MENU_EXIT_PROGRESS_SCENE6:
        {
            MainMenu_ImageWidget2->fn->setVisible(MainMenu_ImageWidget2, LE_TRUE);
            
            main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE7;
            
            break;
        }
        case MAIN_MENU_EXIT_PROGRESS_SCENE7:
        {
            MainMenu_MainPanel->fn->setVisible(MainMenu_MainPanel, LE_TRUE); 
            
            main_menu_state = MAIN_MENU_SHOW_MAIN;
            
            break;
        }        
        case MAIN_MENU_SHOW_MAIN:
        {
            MainMenu_ColonLabel->fn->setScheme(MainMenu_ColonLabel, &WhiteTextScheme);
            MainMenu_HourLabel->fn->setScheme(MainMenu_HourLabel, &WhiteTextScheme);
            MainMenu_MinuteLabel->fn->setScheme(MainMenu_MinuteLabel, &WhiteTextScheme);            
            
            main_menu_state = MAIN_MENU_PROCESS;
            
            break;
        }
        case MAIN_MENU_CHANGE_SCREEN:
        {
    
            MainMenu_SliderButton0->fn->removeEventFilter(MainMenu_SliderButton0, main_eventFilter);
    
            SYS_TIME_TimerDestroy(timer);


            color_screen_show();

            GFX_DISP_INTF_PIN_BACKLIGHT_Clear();            
            
            main_menu_state = MAIN_MENU_EXITED;
            
            break;
        }
        case MAIN_MENU_EXITED:
        {
            break;
        }
        default:
            break;
    }
}

void event_MainMenu_ListWheelWidget2_OnSelectionChanged(leListWheelWidget* lst, int32_t idx)
{
    MainMenu_ImageWidget8->fn->setImage(MainMenu_ImageWidget8, smart_favorites_images[idx]);
}

void event_MainMenu_BakeButton_OnReleased(leButtonWidget* btn)
{
    startMode(BAKE_MODE);
}

void event_MainMenu_CookButton_OnReleased(leButtonWidget* btn)
{
    startMode(COOK_MODE);
}

void event_MainMenu_BroilButton_OnReleased(leButtonWidget* btn)
{
    startMode(BROIL_MODE);
}

void event_MainMenu_ReheatButton_OnReleased(leButtonWidget* btn)
{
    startMode(REHEAT_MODE);
}

void event_MainMenu_CancelButton_OnReleased(leButtonWidget* btn)
{
    main_send_event(EVENT_STOP_COOKING);
}

void event_MainMenu_RestartButton_OnPressed(leButtonWidget* btn)
{
    main_send_event(EVENT_PAUSE_COOKING);
}

void event_MainMenu_RestartButton_OnReleased(leButtonWidget* btn)
{
    main_send_event(EVENT_CONTINUE_COOKING);
}

void event_MainMenu_ButtonWidget0_OnReleased(leButtonWidget* btn)
{
    main_send_event(EVENT_CHANGE_SCENE);
}

void event_MainMenu_DemoModeOnButton_OnPressed(leButtonWidget* btn)
{
    demo_mode_on = false;
}
void event_MainMenu_DemoModeOnButton_OnReleased(leButtonWidget* btn)
{
    demo_mode_on = true;
}
