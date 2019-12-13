#include "gfx/legato/generated/screen/le_gen_screen_InfoScreen.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget0;
leImageWidget* ImageWidget1;
leLabelWidget* LabelWidget0;
leLabelWidget* LabelWidget1;
leLabelWidget* LabelWidget2;
leLabelWidget* LabelWidget3;
leLabelWidget* LabelWidget4;
leLabelWidget* LabelWidget5;
leButtonWidget* ButtonWidget0;

// string list for this screen
static leTableString tableString_String_Demonstrated;
static leTableString tableString_String_Device;
static leTableString tableString_String_GfxController;
static leTableString tableString_String_ColorDepth;
static leTableString tableString_String_Library;
static leTableString tableString_String_Features;
static leTableString tableString_String_PressHere;

// event handlers
static void ButtonWidget0_OnReleased(leButtonWidget* btn)
;


static leBool showing = LE_FALSE;

leResult screenInit_InfoScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_InfoScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_String_Demonstrated, string_String_Demonstrated);
    leTableString_Constructor(&tableString_String_Device, string_String_Device);
    leTableString_Constructor(&tableString_String_GfxController, string_String_GfxController);
    leTableString_Constructor(&tableString_String_ColorDepth, string_String_ColorDepth);
    leTableString_Constructor(&tableString_String_Library, string_String_Library);
    leTableString_Constructor(&tableString_String_Features, string_String_Features);
    leTableString_Constructor(&tableString_String_PressHere, string_String_PressHere);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget0 = leWidget_New();
    PanelWidget0->fn->setPosition(PanelWidget0, 0, 0);
    PanelWidget0->fn->setSize(PanelWidget0, 800, 480);
    PanelWidget0->fn->setScheme(PanelWidget0, &WhiteBackgroundScheme);
    root0->fn->addChild(root0, PanelWidget0);

    ImageWidget1 = leImageWidget_New();
    ImageWidget1->fn->setPosition(ImageWidget1, 591, 36);
    ImageWidget1->fn->setSize(ImageWidget1, 170, 165);
    ImageWidget1->fn->setBackgroundType(ImageWidget1, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget1->fn->setImage(ImageWidget1, &MHGSLogo);
    root0->fn->addChild(root0, (leWidget*)ImageWidget1);

    LabelWidget0 = leLabelWidget_New();
    LabelWidget0->fn->setPosition(LabelWidget0, 30, 20);
    LabelWidget0->fn->setSize(LabelWidget0, 234, 31);
    LabelWidget0->fn->setBackgroundType(LabelWidget0, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget0->fn->setString(LabelWidget0, (leString*)&tableString_String_Demonstrated);
    root0->fn->addChild(root0, (leWidget*)LabelWidget0);

    LabelWidget1 = leLabelWidget_New();
    LabelWidget1->fn->setPosition(LabelWidget1, 30, 70);
    LabelWidget1->fn->setSize(LabelWidget1, 189, 40);
    LabelWidget1->fn->setBackgroundType(LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget1->fn->setString(LabelWidget1, (leString*)&tableString_String_Device);
    root0->fn->addChild(root0, (leWidget*)LabelWidget1);

    LabelWidget2 = leLabelWidget_New();
    LabelWidget2->fn->setPosition(LabelWidget2, 30, 120);
    LabelWidget2->fn->setSize(LabelWidget2, 319, 34);
    LabelWidget2->fn->setBackgroundType(LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget2->fn->setString(LabelWidget2, (leString*)&tableString_String_GfxController);
    root0->fn->addChild(root0, (leWidget*)LabelWidget2);

    LabelWidget3 = leLabelWidget_New();
    LabelWidget3->fn->setPosition(LabelWidget3, 31, 170);
    LabelWidget3->fn->setSize(LabelWidget3, 360, 40);
    LabelWidget3->fn->setBackgroundType(LabelWidget3, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget3->fn->setString(LabelWidget3, (leString*)&tableString_String_ColorDepth);
    root0->fn->addChild(root0, (leWidget*)LabelWidget3);

    LabelWidget4 = leLabelWidget_New();
    LabelWidget4->fn->setPosition(LabelWidget4, 31, 220);
    LabelWidget4->fn->setSize(LabelWidget4, 290, 40);
    LabelWidget4->fn->setBackgroundType(LabelWidget4, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget4->fn->setString(LabelWidget4, (leString*)&tableString_String_Library);
    root0->fn->addChild(root0, (leWidget*)LabelWidget4);

    LabelWidget5 = leLabelWidget_New();
    LabelWidget5->fn->setPosition(LabelWidget5, 31, 270);
    LabelWidget5->fn->setSize(LabelWidget5, 430, 40);
    LabelWidget5->fn->setBackgroundType(LabelWidget5, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget5->fn->setString(LabelWidget5, (leString*)&tableString_String_Features);
    root0->fn->addChild(root0, (leWidget*)LabelWidget5);

    ButtonWidget0 = leButtonWidget_New();
    ButtonWidget0->fn->setPosition(ButtonWidget0, 568, 420);
    ButtonWidget0->fn->setSize(ButtonWidget0, 213, 45);
    ButtonWidget0->fn->setScheme(ButtonWidget0, &WhiteBackgroundScheme);
    ButtonWidget0->fn->setString(ButtonWidget0, (leString*)&tableString_String_PressHere);
    ButtonWidget0->fn->setReleasedEventCallback(ButtonWidget0, ButtonWidget0_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget0);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_InfoScreen()
{
}

void screenHide_InfoScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget0 = NULL;
    ImageWidget1 = NULL;
    LabelWidget0 = NULL;
    LabelWidget1 = NULL;
    LabelWidget2 = NULL;
    LabelWidget3 = NULL;
    LabelWidget4 = NULL;
    LabelWidget5 = NULL;
    ButtonWidget0 = NULL;

    tableString_String_Demonstrated.fn->destructor(&tableString_String_Demonstrated);
    tableString_String_Device.fn->destructor(&tableString_String_Device);
    tableString_String_GfxController.fn->destructor(&tableString_String_GfxController);
    tableString_String_ColorDepth.fn->destructor(&tableString_String_ColorDepth);
    tableString_String_Library.fn->destructor(&tableString_String_Library);
    tableString_String_Features.fn->destructor(&tableString_String_Features);
    tableString_String_PressHere.fn->destructor(&tableString_String_PressHere);
    showing = LE_FALSE;
}

void screenDestroy_InfoScreen()
{

}

leWidget* screenGetRoot_InfoScreen(uint32_t lyrIdx)
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

// event handlers
void ButtonWidget0_OnReleased(leButtonWidget* btn)
{
    // Show Screen (MainScreen) - ShowScreen - MainScreen
    legato_showScreen(screenID_MainScreen);

}



