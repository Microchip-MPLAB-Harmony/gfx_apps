#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
leWidget* root0;

leImageWidget* Screen0_ImageWidget0;
leLabelWidget* Screen0_LabelWidget0;
leImageWidget* Screen0_ImageWidget1;
leButtonWidget* Screen0_ButtonWidget0;

// string list for this screen
static leTableString string_MPLABHarmonyComposer;
static leTableString string_ModifyRegenerateRun;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen0()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen0()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&string_MPLABHarmonyComposer, stringID_MPLABHarmonyComposer);
    leTableString_Constructor(&string_ModifyRegenerateRun, stringID_ModifyRegenerateRun);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 320, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_ImageWidget0 = leImageWidget_New();
    Screen0_ImageWidget0->fn->setPosition(Screen0_ImageWidget0, 0, 0);
    Screen0_ImageWidget0->fn->setSize(Screen0_ImageWidget0, 480, 320);
    Screen0_ImageWidget0->fn->setScheme(Screen0_ImageWidget0, &NewScheme);
    Screen0_ImageWidget0->fn->setBorderType(Screen0_ImageWidget0, LE_WIDGET_BORDER_NONE);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget0);

    Screen0_LabelWidget0 = leLabelWidget_New();
    Screen0_LabelWidget0->fn->setPosition(Screen0_LabelWidget0, 6, 28);
    Screen0_LabelWidget0->fn->setSize(Screen0_LabelWidget0, 315, 45);
    Screen0_LabelWidget0->fn->setBackgroundType(Screen0_LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LabelWidget0->fn->setHAlignment(Screen0_LabelWidget0, LE_HALIGN_CENTER);
    Screen0_LabelWidget0->fn->setString(Screen0_LabelWidget0, (leString*)&string_MPLABHarmonyComposer);
    root0->fn->addChild(root0, (leWidget*)Screen0_LabelWidget0);

    Screen0_ImageWidget1 = leImageWidget_New();
    Screen0_ImageWidget1->fn->setPosition(Screen0_ImageWidget1, 76, 123);
    Screen0_ImageWidget1->fn->setSize(Screen0_ImageWidget1, 170, 170);
    Screen0_ImageWidget1->fn->setBackgroundType(Screen0_ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    Screen0_ImageWidget1->fn->setBorderType(Screen0_ImageWidget1, LE_WIDGET_BORDER_NONE);
    Screen0_ImageWidget1->fn->setImage(Screen0_ImageWidget1, (leImage*)&MHGC_170x170);
    root0->fn->addChild(root0, (leWidget*)Screen0_ImageWidget1);

    Screen0_ButtonWidget0 = leButtonWidget_New();
    Screen0_ButtonWidget0->fn->setPosition(Screen0_ButtonWidget0, 227, 91);
    Screen0_ButtonWidget0->fn->setSize(Screen0_ButtonWidget0, 220, 40);
    Screen0_ButtonWidget0->fn->setString(Screen0_ButtonWidget0, (leString*)&string_ModifyRegenerateRun);
    root0->fn->addChild(root0, (leWidget*)Screen0_ButtonWidget0);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0()
{
}

void screenHide_Screen0()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_ImageWidget0 = NULL;
    Screen0_LabelWidget0 = NULL;
    Screen0_ImageWidget1 = NULL;
    Screen0_ButtonWidget0 = NULL;

    string_MPLABHarmonyComposer.fn->destructor(&string_MPLABHarmonyComposer);
    string_ModifyRegenerateRun.fn->destructor(&string_ModifyRegenerateRun);


    showing = LE_FALSE;
}

void screenDestroy_Screen0()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx)
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

