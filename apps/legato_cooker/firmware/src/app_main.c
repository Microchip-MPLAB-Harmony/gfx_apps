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
    HourLabel->fn->setString(HourLabel, (leString*)&hrStr);   
    
    sprintf(charBuff, "%02u", clock_min); 
    minStr.fn->setFromCStr(&minStr, charBuff);    
    MinuteLabel->fn->setString(MinuteLabel, (leString*)&minStr);   
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
            
            DemoModeOnButton->fn->setVisible(DemoModeOnButton, sec_count%2);
        }
        else
        {
            DemoModeOnButton->fn->setVisible(DemoModeOnButton, LE_TRUE);
        }
    
        if (clock_dot_visible == true)
        {
            clock_dot_visible = false;
            ColonLabel->fn->setVisible(ColonLabel, LE_FALSE);
        }
        else
        {
            clock_dot_visible = true;
            ColonLabel->fn->setVisible(ColonLabel, LE_TRUE);
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
    leScheme* scheme = (show == true) ? &WhiteTextScheme : &OffWhiteTextScheme;
    
    MainPanel->fn->setVisible(MainPanel, lshow);
    PanelWidget3->fn->setVisible(PanelWidget3, lshow);
    ImageWidget1->fn->setVisible(ImageWidget1, lshow);
    ImageWidget2->fn->setVisible(ImageWidget2, lshow);
    ImageWidget3->fn->setVisible(ImageWidget3, lshow);
    ImageWidget4->fn->setVisible(ImageWidget4, lshow);
    ImageWidget8->fn->setVisible(ImageWidget8, lshow);
    
    HourLabel->fn->setScheme(HourLabel, scheme);
    ColonLabel->fn->setScheme(ColonLabel, scheme);
    MinuteLabel->fn->setScheme(MinuteLabel, scheme);
    
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
                                                              string_DefaultMinute,
                                                              0));    
    
    leFixedString_Constructor(&minStr, minStrBuff, 16);
    minStr.fn->setFont(&minStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              string_DefaultMinute,
                                                              0));
    
    leFixedString_Constructor(&progressStr, progressStrBuff, 16);
    progressStr.fn->setFont(&progressStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              string_DefaultCookTime,
                                                              0));
    
    DemoModeOnButton->fn->setPressed(DemoModeOnButton, (leBool) (demo_mode_on == false));
    
    SliderButton0->fn->installEventFilter(SliderButton0, main_eventFilter);
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
            PanelWidget0->fn->setX(PanelWidget0, 0);   
            
            //Restore and show black rects to hide border
            RectangleWidget0->fn->setVisible(RectangleWidget0, LE_TRUE);
            RectangleWidget1->fn->setVisible(RectangleWidget1, LE_TRUE);
            RectangleWidget2->fn->setVisible(RectangleWidget2, LE_TRUE);
            RectangleWidget3->fn->setVisible(RectangleWidget3, LE_TRUE); 
            RectangleWidget0->fn->setWidth(RectangleWidget0, 340);
            RectangleWidget0->fn->setX(RectangleWidget0, 66);
            RectangleWidget1->fn->setWidth(RectangleWidget1, 340);
            RectangleWidget1->fn->setX(RectangleWidget1, 66);
            
            //Reset and hide the progress indicators
            ProgressBarWidget0->fn->setValue(ProgressBarWidget0, 0);
            ProgressBarWidget0->fn->setVisible(ProgressBarWidget0, LE_FALSE);
            CookTimeLabel->fn->setVisible(CookTimeLabel, LE_FALSE);
            CancelButton->fn->setPressedImage(CancelButton, &cancel_80);
            CancelButton->fn->setReleasedImage(CancelButton, &cancel_80);            
            CancelButton->fn->setVisible(CancelButton, LE_FALSE);
            
            //Prepare and Hide the Mode Image
            ModeImageWidget->fn->setVisible(ModeImageWidget, LE_FALSE);
            ModeImageWidget->fn->setImage(ModeImageWidget, mode_images[mode]);
            
            main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE3;
            
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE3:
        {
            RectangleWidget3->fn->setVisible(RectangleWidget3, LE_FALSE); 
            main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE4;
            
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE4:            
        {
            uint32_t length = RectangleWidget0->fn->getWidth(RectangleWidget0);
            uint32_t xpos = RectangleWidget0->fn->getX(RectangleWidget0);

            if (length > DELTA_RECT_PIX)
            {
                RectangleWidget0->fn->setWidth(RectangleWidget0, length - DELTA_RECT_PIX);
                RectangleWidget0->fn->setX(RectangleWidget0, xpos + DELTA_RECT_PIX);
                RectangleWidget1->fn->setWidth(RectangleWidget1, length - DELTA_RECT_PIX);
                RectangleWidget1->fn->setX(RectangleWidget1, xpos + DELTA_RECT_PIX);
            }
            else
            {
                RectangleWidget0->fn->setVisible(RectangleWidget0, LE_FALSE);
                RectangleWidget1->fn->setVisible(RectangleWidget1, LE_FALSE);
                RectangleWidget1->fn->setVisible(RectangleWidget2, LE_FALSE);
                
                main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE5;
            }
                
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE5:
        {
            width = ProgressBarWidget0->fn->getWidth(ProgressBarWidget0);
            x = ProgressBarWidget0->fn->getX(ProgressBarWidget0);
                        
            ProgressBarWidget0->fn->setVisible(ProgressBarWidget0, LE_TRUE);
            ProgressBarWidget0->fn->setValue(ProgressBarWidget0, 0);       
            
            ProgressBarWidget0->fn->setX(ProgressBarWidget0, x + (width*3)/8);
            ProgressBarWidget0->fn->setWidth(ProgressBarWidget0, width/4);
            
            main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE6;
            break;
        }        
        case MAIN_MENU_PREPARE_PROGRESS_SCENE6:
        {
            width = ProgressBarWidget0->fn->getWidth(ProgressBarWidget0);
            x = ProgressBarWidget0->fn->getX(ProgressBarWidget0);
            
            if (width < 280 - PROGRESS_BAR_BLOCK_EXTEND)
            {
                ProgressBarWidget0->fn->setWidth(ProgressBarWidget0, 
                                            width + PROGRESS_BAR_BLOCK_EXTEND);
                ProgressBarWidget0->fn->setX(ProgressBarWidget0, x - PROGRESS_BAR_BLOCK_EXTEND/2);
            }
            else
            {
                ProgressBarWidget0->fn->setWidth(ProgressBarWidget0, 280);
                ProgressBarWidget0->fn->setX(ProgressBarWidget0, 104);
                main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE7;
            }
            
            break;
        }
        case MAIN_MENU_PREPARE_PROGRESS_SCENE7:
        {
            CookTimeLabel->fn->setVisible(CookTimeLabel, LE_TRUE);
            
            main_menu_state = MAIN_MENU_PREPARE_PROGRESS_SCENE8;
            break;
        }        
        case MAIN_MENU_PREPARE_PROGRESS_SCENE8:
        {
            ModeImageWidget->fn->setVisible(ModeImageWidget, LE_TRUE);  
            CancelButton->fn->setVisible(CancelButton, LE_TRUE);            
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
                    CookTimeLabel->fn->setString(CookTimeLabel, (leString*)&progressStr);    
                    ProgressBarWidget0->fn->setValue(ProgressBarWidget0, event_parm);
                    
                    CookTimeLabel->fn->setVisible(CookTimeLabel, LE_TRUE);
                    
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
                    CookTimeLabel->fn->setString(CookTimeLabel, (leString*)&progressStr);                       
                    
                    ProgressBarWidget0->fn->setValue(ProgressBarWidget0, 
                                        100 - (100 * cookSec) / COOK_TIME_SECS);
                    
                    cookSec--;
                    
                }
                else
                {
                    cookSec = COOK_TIME_SECS;
                    
                    ProgressBarWidget0->fn->setValue(ProgressBarWidget0, 100);
                            sprintf(charBuff, "Done"); 
                            progressStr.fn->setFromCStr(&progressStr, charBuff);    
                    CookTimeLabel->fn->setString(CookTimeLabel, (leString*)&progressStr);   
                    CancelButton->fn->setPressedImage(CancelButton, &ok_80);
                    CancelButton->fn->setReleasedImage(CancelButton, &ok_80);
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
                if (CookTimeLabel->fn->getVisible(CookTimeLabel) == LE_TRUE)
                    CookTimeLabel->fn->setVisible(CookTimeLabel, LE_FALSE);
                else
                    CookTimeLabel->fn->setVisible(CookTimeLabel, LE_TRUE);
                
                last_sec_count = sec_count;
            }
            
            switch(event)
            {
                case EVENT_CONTINUE_COOKING:
                {
                    if (main_menu_state == MAIN_MENU_IDLE_PROGRESS_SCENE)
                    {
                        main_menu_state = MAIN_MENU_PROCESS_PROGRESS_SCENE;
                        CookTimeLabel->fn->setVisible(CookTimeLabel, LE_TRUE);                        
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
                    CookTimeLabel->fn->setString(CookTimeLabel, (leString*)&progressStr);    
                    ProgressBarWidget0->fn->setValue(ProgressBarWidget0, event_parm);
                    
                    CookTimeLabel->fn->setVisible(CookTimeLabel, LE_TRUE);
                    
                    //cook time has been adjusted, switch back to idle/paused state
                    if (main_menu_state == MAIN_MENU_DONE_PROGRESS_SCENE)
                    {
                        CancelButton->fn->setPressedImage(CancelButton, &cancel_80);
                        CancelButton->fn->setReleasedImage(CancelButton, &cancel_80);  
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
            ModeImageWidget->fn->setVisible(ModeImageWidget, LE_FALSE);  
            CancelButton->fn->setVisible(CancelButton, LE_FALSE);   
            main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE2;
            
            break;
        }
        case MAIN_MENU_EXIT_PROGRESS_SCENE2:
        {
            width = ProgressBarWidget0->fn->getWidth(ProgressBarWidget0);
            x = ProgressBarWidget0->fn->getX(ProgressBarWidget0);
            
            if (width > PROGRESS_BAR_BLOCK_EXTEND)
            {
                ProgressBarWidget0->fn->setWidth(ProgressBarWidget0, 
                                            width - PROGRESS_BAR_BLOCK_EXTEND);
                ProgressBarWidget0->fn->setX(ProgressBarWidget0, x + PROGRESS_BAR_BLOCK_EXTEND/2);
            }
            else
            {
                char charBuff[16] = {0}; 
                
                ProgressBarWidget0->fn->setWidth(ProgressBarWidget0, 0);
                ProgressBarWidget0->fn->setVisible(ProgressBarWidget0, LE_FALSE);
                
                sprintf(charBuff, "2:00"); 
                progressStr.fn->setFromCStr(&progressStr, charBuff);    
                CookTimeLabel->fn->setString(CookTimeLabel, (leString*)&progressStr);                       
                                    
                CookTimeLabel->fn->setVisible(CookTimeLabel, LE_FALSE);   
                main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE3;
            }
            break;
        }
        case MAIN_MENU_EXIT_PROGRESS_SCENE3:
        {
            PanelWidget0->fn->setX(PanelWidget0, 480); 
            
            main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE4;
            
            break;
        }
        case MAIN_MENU_EXIT_PROGRESS_SCENE4:
        {
            ImageWidget1->fn->setVisible(ImageWidget1, LE_TRUE);
            ImageWidget8->fn->setVisible(ImageWidget8, LE_TRUE);  
            
            main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE5;
            break;
        }
        case MAIN_MENU_EXIT_PROGRESS_SCENE5:
        {
            ImageWidget3->fn->setVisible(ImageWidget3, LE_TRUE);
            ImageWidget4->fn->setVisible(ImageWidget4, LE_TRUE);
            PanelWidget3->fn->setVisible(PanelWidget3, LE_TRUE);
                
            main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE6;
            break;
        }
        case MAIN_MENU_EXIT_PROGRESS_SCENE6:
        {
            ImageWidget2->fn->setVisible(ImageWidget2, LE_TRUE);
            
            main_menu_state = MAIN_MENU_EXIT_PROGRESS_SCENE7;
            
            break;
        }
        case MAIN_MENU_EXIT_PROGRESS_SCENE7:
        {
            MainPanel->fn->setVisible(MainPanel, LE_TRUE); 
            
            main_menu_state = MAIN_MENU_SHOW_MAIN;
            
            break;
        }        
        case MAIN_MENU_SHOW_MAIN:
        {
            HourLabel->fn->setScheme(HourLabel, &WhiteTextScheme);
            ColonLabel->fn->setScheme(ColonLabel, &WhiteTextScheme);
            MinuteLabel->fn->setScheme(MinuteLabel, &WhiteTextScheme);            
            
            main_menu_state = MAIN_MENU_PROCESS;
            
            break;
        }
        case MAIN_MENU_CHANGE_SCREEN:
        {
    
            SliderButton0->fn->removeEventFilter(SliderButton0, main_eventFilter);
    
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

void ListWheelWidget2_OnSelectionChanged(leListWheelWidget* lst, int32_t idx)
{
    ImageWidget8->fn->setImage(ImageWidget8, smart_favorites_images[idx]);
}

void BakeButton_OnReleased(leButtonWidget* btn)
{
    startMode(BAKE_MODE);
}

void CookButton_OnReleased(leButtonWidget* btn)
{
    startMode(COOK_MODE);
}

void BroilButton_OnReleased(leButtonWidget* btn)
{
    startMode(BROIL_MODE);
}

void ReheatButton_OnReleased(leButtonWidget* btn)
{
    startMode(REHEAT_MODE);
}

void CancelButton_OnReleased(leButtonWidget* btn)
{
    main_send_event(EVENT_STOP_COOKING);
}

void RestartButton_OnPressed(leButtonWidget* btn)
{
    main_send_event(EVENT_PAUSE_COOKING);
}

void RestartButton_OnReleased(leButtonWidget* btn)
{
    main_send_event(EVENT_CONTINUE_COOKING);
}

void ButtonWidget0_OnReleased(leButtonWidget* btn)
{
    main_send_event(EVENT_CHANGE_SCENE);
}

void DemoModeOnButton_OnPressed(leButtonWidget* btn)
{
    demo_mode_on = false;
}
void DemoModeOnButton_OnReleased(leButtonWidget* btn)
{
    demo_mode_on = true;
}
