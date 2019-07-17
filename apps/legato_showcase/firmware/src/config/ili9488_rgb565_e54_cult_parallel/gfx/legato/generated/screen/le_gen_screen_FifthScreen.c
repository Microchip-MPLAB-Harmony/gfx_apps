#include "gfx/legato/generated/screen/le_gen_screen_FifthScreen.h"

// widget list for layer 0
static leWidget* root0;

leGradientWidget* GradientWidget6;
leImageSequenceWidget* ImageSequenceWidget1;
leButtonWidget* ButtonWidget9;
leButtonWidget* ButtonWidget11;
leLabelWidget* LabelWidget10;
leButtonWidget* ButtonWidget10;
leButtonWidget* ButtonWidget20;
leButtonWidget* ButtonWidget21;
leButtonWidget* ButtonWidget22;
leImageWidget* SSStatusImageWidget;

// string list for this screen
static leTableString tableString_SlideShowDemo;
static leTableString tableString_msecs500;
static leTableString tableString_secs2;

// event handlers
static void ButtonWidget9_OnReleased(leButtonWidget* btn);
static void ButtonWidget11_OnReleased(leButtonWidget* btn);
static void ButtonWidget10_OnReleased(leButtonWidget* btn);
static void ButtonWidget20_OnReleased(leButtonWidget* btn);
static void ButtonWidget21_OnPressed(leButtonWidget* btn);
static void ButtonWidget21_OnReleased(leButtonWidget* btn);
static void ButtonWidget22_OnPressed(leButtonWidget* btn);
static void ButtonWidget22_OnReleased(leButtonWidget* btn);

static leBool showing = LE_FALSE;

leResult screenInit_FifthScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_FifthScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_SlideShowDemo, string_SlideShowDemo);
    leTableString_Constructor(&tableString_msecs500, string_msecs500);
    leTableString_Constructor(&tableString_secs2, string_secs2);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    GradientWidget6 = leGradientWidget_New();
    GradientWidget6->fn->setPosition(GradientWidget6, 0, 0);
    GradientWidget6->fn->setSize(GradientWidget6, 480, 320);
    GradientWidget6->fn->setScheme(GradientWidget6, &BackgroundGradientScheme);
    GradientWidget6->fn->setDirection(GradientWidget6, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)GradientWidget6);

    ImageSequenceWidget1 = leImageSequenceWidget_New();
    ImageSequenceWidget1->fn->setPosition(ImageSequenceWidget1, 107, 41);
    ImageSequenceWidget1->fn->setSize(ImageSequenceWidget1, 279, 161);
    ImageSequenceWidget1->fn->setBackgroundType(ImageSequenceWidget1, LE_WIDGET_BACKGROUND_NONE);
    ImageSequenceWidget1->fn->setImageCount(ImageSequenceWidget1, 3);
    ImageSequenceWidget1->fn->setImage(ImageSequenceWidget1, 0, &USA);
    ImageSequenceWidget1->fn->setImage(ImageSequenceWidget1, 1, &MicrochipLogo);
    ImageSequenceWidget1->fn->setImage(ImageSequenceWidget1, 2, &NewHarmonyLogo);
    ImageSequenceWidget1->fn->play(ImageSequenceWidget1);
    ImageSequenceWidget1->fn->setRepeat(ImageSequenceWidget1, LE_TRUE);
    root0->fn->addChild(root0, (leWidget*)ImageSequenceWidget1);

    ButtonWidget9 = leButtonWidget_New();
    ButtonWidget9->fn->setPosition(ButtonWidget9, 0, 260);
    ButtonWidget9->fn->setSize(ButtonWidget9, 60, 60);
    ButtonWidget9->fn->setBackgroundType(ButtonWidget9, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget9->fn->setBorderType(ButtonWidget9, LE_WIDGET_BORDER_NONE);
    ButtonWidget9->fn->setPressedImage(ButtonWidget9, &GFX_Help_60);
    ButtonWidget9->fn->setReleasedImage(ButtonWidget9, &GFX_Help_60);
    ButtonWidget9->fn->setReleasedEventCallback(ButtonWidget9, ButtonWidget9_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget9);

    ButtonWidget11 = leButtonWidget_New();
    ButtonWidget11->fn->setPosition(ButtonWidget11, 421, 260);
    ButtonWidget11->fn->setSize(ButtonWidget11, 60, 60);
    ButtonWidget11->fn->setBackgroundType(ButtonWidget11, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget11->fn->setBorderType(ButtonWidget11, LE_WIDGET_BORDER_NONE);
    ButtonWidget11->fn->setPressedImage(ButtonWidget11, &GFX_Home_60x60);
    ButtonWidget11->fn->setReleasedImage(ButtonWidget11, &GFX_Home_60x60);
    ButtonWidget11->fn->setReleasedEventCallback(ButtonWidget11, ButtonWidget11_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget11);

    LabelWidget10 = leLabelWidget_New();
    LabelWidget10->fn->setPosition(LabelWidget10, 10, 6);
    LabelWidget10->fn->setSize(LabelWidget10, 251, 25);
    LabelWidget10->fn->setScheme(LabelWidget10, &BlackBackground);
    LabelWidget10->fn->setBackgroundType(LabelWidget10, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget10->fn->setString(LabelWidget10, (leString*)&tableString_SlideShowDemo);
    root0->fn->addChild(root0, (leWidget*)LabelWidget10);

    ButtonWidget10 = leButtonWidget_New();
    ButtonWidget10->fn->setPosition(ButtonWidget10, 0, 90);
    ButtonWidget10->fn->setSize(ButtonWidget10, 50, 74);
    ButtonWidget10->fn->setBackgroundType(ButtonWidget10, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget10->fn->setBorderType(ButtonWidget10, LE_WIDGET_BORDER_NONE);
    ButtonWidget10->fn->setPressedImage(ButtonWidget10, &GFX_ArrowLeft_20x60);
    ButtonWidget10->fn->setReleasedImage(ButtonWidget10, &GFX_ArrowLeft_20x60);
    ButtonWidget10->fn->setReleasedEventCallback(ButtonWidget10, ButtonWidget10_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget10);

    ButtonWidget20 = leButtonWidget_New();
    ButtonWidget20->fn->setPosition(ButtonWidget20, 430, 90);
    ButtonWidget20->fn->setSize(ButtonWidget20, 49, 65);
    ButtonWidget20->fn->setBackgroundType(ButtonWidget20, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget20->fn->setBorderType(ButtonWidget20, LE_WIDGET_BORDER_NONE);
    ButtonWidget20->fn->setPressedImage(ButtonWidget20, &GFX_ArrowRight_20x60);
    ButtonWidget20->fn->setReleasedImage(ButtonWidget20, &GFX_ArrowRight_20x60);
    ButtonWidget20->fn->setReleasedEventCallback(ButtonWidget20, ButtonWidget20_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget20);

    ButtonWidget21 = leButtonWidget_New();
    ButtonWidget21->fn->setPosition(ButtonWidget21, 261, 220);
    ButtonWidget21->fn->setSize(ButtonWidget21, 99, 38);
    ButtonWidget21->fn->setToggleable(ButtonWidget21, LE_TRUE);
    ButtonWidget21->fn->setString(ButtonWidget21, (leString*)&tableString_msecs500);
    ButtonWidget21->fn->setPressedImage(ButtonWidget21, &GFX_Stop_30x30);
    ButtonWidget21->fn->setReleasedImage(ButtonWidget21, &GFX_FF_30x30);
    ButtonWidget21->fn->setPressedEventCallback(ButtonWidget21, ButtonWidget21_OnPressed);
    ButtonWidget21->fn->setReleasedEventCallback(ButtonWidget21, ButtonWidget21_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget21);

    ButtonWidget22 = leButtonWidget_New();
    ButtonWidget22->fn->setPosition(ButtonWidget22, 138, 220);
    ButtonWidget22->fn->setSize(ButtonWidget22, 92, 37);
    ButtonWidget22->fn->setToggleable(ButtonWidget22, LE_TRUE);
    ButtonWidget22->fn->setString(ButtonWidget22, (leString*)&tableString_secs2);
    ButtonWidget22->fn->setPressedImage(ButtonWidget22, &GFX_Stop_30x30);
    ButtonWidget22->fn->setReleasedImage(ButtonWidget22, &GFX_Play_30x30);
    ButtonWidget22->fn->setPressedEventCallback(ButtonWidget22, ButtonWidget22_OnPressed);
    ButtonWidget22->fn->setReleasedEventCallback(ButtonWidget22, ButtonWidget22_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget22);

    SSStatusImageWidget = leImageWidget_New();
    SSStatusImageWidget->fn->setPosition(SSStatusImageWidget, 349, 10);
    SSStatusImageWidget->fn->setSize(SSStatusImageWidget, 20, 20);
    SSStatusImageWidget->fn->setBackgroundType(SSStatusImageWidget, LE_WIDGET_BACKGROUND_NONE);
    SSStatusImageWidget->fn->setImage(SSStatusImageWidget, &GFX_Pause_Pink_20x20);
    root0->fn->addChild(root0, (leWidget*)SSStatusImageWidget);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_FifthScreen()
{
}

void screenHide_FifthScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    GradientWidget6 = NULL;
    ImageSequenceWidget1 = NULL;
    ButtonWidget9 = NULL;
    ButtonWidget11 = NULL;
    LabelWidget10 = NULL;
    ButtonWidget10 = NULL;
    ButtonWidget20 = NULL;
    ButtonWidget21 = NULL;
    ButtonWidget22 = NULL;
    SSStatusImageWidget = NULL;

    tableString_SlideShowDemo.fn->destructor(&tableString_SlideShowDemo);
    tableString_msecs500.fn->destructor(&tableString_msecs500);
    tableString_secs2.fn->destructor(&tableString_secs2);
    showing = LE_FALSE;
}

void screenDestroy_FifthScreen()
{

}

leWidget* screenGetRoot_FifthScreen(uint32_t lyrIdx)
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
void ButtonWidget9_OnReleased(leButtonWidget* btn)
{
}

void ButtonWidget11_OnReleased(leButtonWidget* btn)
{
}

void ButtonWidget10_OnReleased(leButtonWidget* btn)
{
}

void ButtonWidget20_OnReleased(leButtonWidget* btn)
{
}

void ButtonWidget21_OnPressed(leButtonWidget* btn)
{
}

void ButtonWidget21_OnReleased(leButtonWidget* btn)
{
}

void ButtonWidget22_OnPressed(leButtonWidget* btn)
{
}

void ButtonWidget22_OnReleased(leButtonWidget* btn)
{
}


