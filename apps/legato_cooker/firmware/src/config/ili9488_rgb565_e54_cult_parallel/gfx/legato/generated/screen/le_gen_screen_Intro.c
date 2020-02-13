#include "gfx/legato/generated/screen/le_gen_screen_Intro.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget6;
leImageWidget* ImageWidget5;
leImageWidget* ImageWidget7;


static leBool showing = LE_FALSE;

leResult screenInit_Intro()
{
    return LE_SUCCESS;
}

leResult screenShow_Intro()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget6 = leWidget_New();
    PanelWidget6->fn->setPosition(PanelWidget6, 0, 0);
    PanelWidget6->fn->setSize(PanelWidget6, 480, 320);
    PanelWidget6->fn->setScheme(PanelWidget6, &WhiteBackgroundScheme);
    root0->fn->addChild(root0, PanelWidget6);

    ImageWidget5 = leImageWidget_New();
    ImageWidget5->fn->setPosition(ImageWidget5, 0, 0);
    ImageWidget5->fn->setSize(ImageWidget5, 161, 33);
    ImageWidget5->fn->setAlphaEnabled(ImageWidget5, LE_TRUE);
    ImageWidget5->fn->setBackgroundType(ImageWidget5, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget5->fn->setImage(ImageWidget5, &Microchip_logo_150x30);
    root0->fn->addChild(root0, (leWidget*)ImageWidget5);

    ImageWidget7 = leImageWidget_New();
    ImageWidget7->fn->setPosition(ImageWidget7, 177, 98);
    ImageWidget7->fn->setSize(ImageWidget7, 120, 120);
    ImageWidget7->fn->setBackgroundType(ImageWidget7, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget7->fn->setImage(ImageWidget7, &MHGC_120x120);
    root0->fn->addChild(root0, (leWidget*)ImageWidget7);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    Intro_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_Intro()
{
    Intro_OnUpdate();
}

void screenHide_Intro()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget6 = NULL;
    ImageWidget5 = NULL;
    ImageWidget7 = NULL;
    showing = LE_FALSE;

    Intro_OnHide();
}

void screenDestroy_Intro()
{

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

