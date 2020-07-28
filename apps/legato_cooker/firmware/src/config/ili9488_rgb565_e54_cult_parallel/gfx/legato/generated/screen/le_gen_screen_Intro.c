#include "gfx/legato/generated/screen/le_gen_screen_Intro.h"

// screen member widget declarations
leWidget* root0;

leWidget* Intro_PanelWidget6;
leImageWidget* Intro_ImageWidget5;
leImageWidget* Intro_ImageWidget7;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Intro()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Intro()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Intro_PanelWidget6 = leWidget_New();
    Intro_PanelWidget6->fn->setPosition(Intro_PanelWidget6, 0, 0);
    Intro_PanelWidget6->fn->setSize(Intro_PanelWidget6, 480, 320);
    Intro_PanelWidget6->fn->setScheme(Intro_PanelWidget6, &WhiteBackgroundScheme);
    root0->fn->addChild(root0, (leWidget*)Intro_PanelWidget6);

    Intro_ImageWidget5 = leImageWidget_New();
    Intro_ImageWidget5->fn->setPosition(Intro_ImageWidget5, 0, 0);
    Intro_ImageWidget5->fn->setSize(Intro_ImageWidget5, 161, 33);
    Intro_ImageWidget5->fn->setAlphaEnabled(Intro_ImageWidget5, LE_TRUE);
    Intro_ImageWidget5->fn->setBackgroundType(Intro_ImageWidget5, LE_WIDGET_BACKGROUND_NONE);
    Intro_ImageWidget5->fn->setBorderType(Intro_ImageWidget5, LE_WIDGET_BORDER_NONE);
    Intro_ImageWidget5->fn->setImage(Intro_ImageWidget5, (leImage*)&Microchip_logo_150x30);
    root0->fn->addChild(root0, (leWidget*)Intro_ImageWidget5);

    Intro_ImageWidget7 = leImageWidget_New();
    Intro_ImageWidget7->fn->setPosition(Intro_ImageWidget7, 177, 98);
    Intro_ImageWidget7->fn->setSize(Intro_ImageWidget7, 120, 120);
    Intro_ImageWidget7->fn->setBackgroundType(Intro_ImageWidget7, LE_WIDGET_BACKGROUND_NONE);
    Intro_ImageWidget7->fn->setBorderType(Intro_ImageWidget7, LE_WIDGET_BORDER_NONE);
    Intro_ImageWidget7->fn->setImage(Intro_ImageWidget7, (leImage*)&MHGC_120x120);
    root0->fn->addChild(root0, (leWidget*)Intro_ImageWidget7);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    Intro_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Intro()
{
    Intro_OnUpdate(); // raise event
}

void screenHide_Intro()
{
    Intro_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Intro_PanelWidget6 = NULL;
    Intro_ImageWidget5 = NULL;
    Intro_ImageWidget7 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Intro()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Intro(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        default:
        {
            return NULL;
        }
    }
}

