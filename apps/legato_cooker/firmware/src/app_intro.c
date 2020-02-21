#include "gfx/legato/generated/le_gen_init.h"
#include "definitions.h"

#include <stdio.h>
#include <string.h>

#define ALPHA_INC 10
typedef enum
{
    INTRO_STATE_0,
    INTRO_STATE_1,
    INTRO_STATE_2,
    INTRO_STATE_3,
    INTRO_STATE_4,
    INTRO_STATE_5,            
} INTO_STATES;

INTO_STATES intro_state;
        
void Intro_OnShow(void)
{
    intro_state = INTRO_STATE_0;
    ImageWidget5->fn->setAlphaAmount(ImageWidget5, 0);
    ImageWidget7->fn->setAlphaEnabled(ImageWidget7, LE_TRUE);
    ImageWidget7->fn->setAlphaAmount(ImageWidget7, 0);
}

void Intro_OnHide(void)
{
    
}

void Intro_OnUpdate(void)
{
    static unsigned int alpha;
    
    if(leGetRenderState()->frameState != LE_FRAME_READY || leEvent_GetCount() != 0)
        return;
    
    switch(intro_state)
    {
        case INTRO_STATE_0:
        {
            intro_state = INTRO_STATE_1;
            break;
        }
        case INTRO_STATE_1:
        {
            GFX_DISP_INTF_PIN_BACKLIGHT_Set();
            intro_state = INTRO_STATE_2;
            break;
        }
        case INTRO_STATE_2:
        {
            alpha = ImageWidget5->fn->getAlphaAmount(ImageWidget5);
            
            if (alpha < 255 - ALPHA_INC)
                ImageWidget5->fn->setAlphaAmount(ImageWidget5, alpha + ALPHA_INC);
            else
            {
                ImageWidget5->fn->setAlphaAmount(ImageWidget5, 255);
                intro_state = INTRO_STATE_3;
            }
            
            break;
        }
        case INTRO_STATE_3:
        {
            alpha = ImageWidget7->fn->getAlphaAmount(ImageWidget7);
            
            if (alpha < 255 - ALPHA_INC)
                ImageWidget7->fn->setAlphaAmount(ImageWidget7, alpha + ALPHA_INC);
            else
            {
                ImageWidget7->fn->setAlphaAmount(ImageWidget7, 255);
                intro_state = INTRO_STATE_4;
            }
            
            break;
        }
        case INTRO_STATE_4:
        {
            alpha = ImageWidget7->fn->getAlphaAmount(ImageWidget7);
            
            if (alpha > ALPHA_INC)
                ImageWidget7->fn->setAlphaAmount(ImageWidget7, alpha - ALPHA_INC);
            else
            {
                ImageWidget7->fn->setAlphaAmount(ImageWidget7, 0);
                intro_state = INTRO_STATE_5;
            }
            break;
        }
        case INTRO_STATE_5:
        {
            alpha = ImageWidget5->fn->getAlphaAmount(ImageWidget5);
            
            if (alpha > ALPHA_INC)
                ImageWidget5->fn->setAlphaAmount(ImageWidget5, alpha - ALPHA_INC);
            else
            {
                ImageWidget5->fn->setAlphaAmount(ImageWidget5, 0);
                GFX_DISP_INTF_PIN_BACKLIGHT_Clear();
                main_screen_show();
            }
            break;
        }        
        default:
            break;
    }
}
