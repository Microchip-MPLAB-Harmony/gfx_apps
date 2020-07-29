#include "gfx/legato/generated/screen/le_gen_screen_SlideShowDemoScreen.h"

// screen member widget declarations
leWidget* root0;

leGradientWidget* SlideShowDemoScreen_GradientWidget6;
leImageSequenceWidget* SlideShowDemoScreen_ImageSequenceWidget1;
leButtonWidget* SlideShowDemoScreen_SlideshowHelpButton;
leButtonWidget* SlideShowDemoScreen_SlideShowHomeButton;
leLabelWidget* SlideShowDemoScreen_LabelWidget10;
leButtonWidget* SlideShowDemoScreen_SlideShowPrevButton;
leButtonWidget* SlideShowDemoScreen_SlideshowNextButton;
leButtonWidget* SlideShowDemoScreen_SlideShowFFButton;
leButtonWidget* SlideShowDemoScreen_SlideShowPlayButton;
leImageWidget* SlideShowDemoScreen_SSStatusImageWidget;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_SlideShowDemoScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_SlideShowDemoScreen()
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

    SlideShowDemoScreen_GradientWidget6 = leGradientWidget_New();
    SlideShowDemoScreen_GradientWidget6->fn->setPosition(SlideShowDemoScreen_GradientWidget6, 0, 0);
    SlideShowDemoScreen_GradientWidget6->fn->setSize(SlideShowDemoScreen_GradientWidget6, 480, 320);
    SlideShowDemoScreen_GradientWidget6->fn->setScheme(SlideShowDemoScreen_GradientWidget6, &BackgroundGradientScheme);
    SlideShowDemoScreen_GradientWidget6->fn->setDirection(SlideShowDemoScreen_GradientWidget6, LE_DIRECTION_DOWN);
    root0->fn->addChild(root0, (leWidget*)SlideShowDemoScreen_GradientWidget6);

    SlideShowDemoScreen_ImageSequenceWidget1 = leImageSequenceWidget_New();
    SlideShowDemoScreen_ImageSequenceWidget1->fn->setPosition(SlideShowDemoScreen_ImageSequenceWidget1, 107, 41);
    SlideShowDemoScreen_ImageSequenceWidget1->fn->setSize(SlideShowDemoScreen_ImageSequenceWidget1, 279, 161);
    SlideShowDemoScreen_ImageSequenceWidget1->fn->setBackgroundType(SlideShowDemoScreen_ImageSequenceWidget1, LE_WIDGET_BACKGROUND_NONE);
    SlideShowDemoScreen_ImageSequenceWidget1->fn->play(SlideShowDemoScreen_ImageSequenceWidget1);
    SlideShowDemoScreen_ImageSequenceWidget1->fn->setRepeat(SlideShowDemoScreen_ImageSequenceWidget1, LE_TRUE);
    SlideShowDemoScreen_ImageSequenceWidget1->fn->setImageCount(SlideShowDemoScreen_ImageSequenceWidget1, 3);
    SlideShowDemoScreen_ImageSequenceWidget1->fn->setImage(SlideShowDemoScreen_ImageSequenceWidget1, 0, &USA);
    SlideShowDemoScreen_ImageSequenceWidget1->fn->setImageDelay(SlideShowDemoScreen_ImageSequenceWidget1, 0, 1000);
    SlideShowDemoScreen_ImageSequenceWidget1->fn->setImage(SlideShowDemoScreen_ImageSequenceWidget1, 1, &MicrochipLogo);
    SlideShowDemoScreen_ImageSequenceWidget1->fn->setImageDelay(SlideShowDemoScreen_ImageSequenceWidget1, 1, 1000);
    SlideShowDemoScreen_ImageSequenceWidget1->fn->setImage(SlideShowDemoScreen_ImageSequenceWidget1, 2, &NewHarmonyLogo);
    SlideShowDemoScreen_ImageSequenceWidget1->fn->setImageDelay(SlideShowDemoScreen_ImageSequenceWidget1, 2, 1000);
    root0->fn->addChild(root0, (leWidget*)SlideShowDemoScreen_ImageSequenceWidget1);

    SlideShowDemoScreen_SlideshowHelpButton = leButtonWidget_New();
    SlideShowDemoScreen_SlideshowHelpButton->fn->setPosition(SlideShowDemoScreen_SlideshowHelpButton, 0, 260);
    SlideShowDemoScreen_SlideshowHelpButton->fn->setSize(SlideShowDemoScreen_SlideshowHelpButton, 60, 60);
    SlideShowDemoScreen_SlideshowHelpButton->fn->setBackgroundType(SlideShowDemoScreen_SlideshowHelpButton, LE_WIDGET_BACKGROUND_NONE);
    SlideShowDemoScreen_SlideshowHelpButton->fn->setBorderType(SlideShowDemoScreen_SlideshowHelpButton, LE_WIDGET_BORDER_NONE);
    SlideShowDemoScreen_SlideshowHelpButton->fn->setPressedImage(SlideShowDemoScreen_SlideshowHelpButton, (leImage*)&GFX_Help_60);
    SlideShowDemoScreen_SlideshowHelpButton->fn->setReleasedImage(SlideShowDemoScreen_SlideshowHelpButton, (leImage*)&GFX_Help_60);
    SlideShowDemoScreen_SlideshowHelpButton->fn->setReleasedEventCallback(SlideShowDemoScreen_SlideshowHelpButton, event_SlideShowDemoScreen_SlideshowHelpButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SlideShowDemoScreen_SlideshowHelpButton);

    SlideShowDemoScreen_SlideShowHomeButton = leButtonWidget_New();
    SlideShowDemoScreen_SlideShowHomeButton->fn->setPosition(SlideShowDemoScreen_SlideShowHomeButton, 421, 260);
    SlideShowDemoScreen_SlideShowHomeButton->fn->setSize(SlideShowDemoScreen_SlideShowHomeButton, 60, 60);
    SlideShowDemoScreen_SlideShowHomeButton->fn->setBackgroundType(SlideShowDemoScreen_SlideShowHomeButton, LE_WIDGET_BACKGROUND_NONE);
    SlideShowDemoScreen_SlideShowHomeButton->fn->setBorderType(SlideShowDemoScreen_SlideShowHomeButton, LE_WIDGET_BORDER_NONE);
    SlideShowDemoScreen_SlideShowHomeButton->fn->setPressedImage(SlideShowDemoScreen_SlideShowHomeButton, (leImage*)&GFX_Home_60x60);
    SlideShowDemoScreen_SlideShowHomeButton->fn->setReleasedImage(SlideShowDemoScreen_SlideShowHomeButton, (leImage*)&GFX_Home_60x60);
    SlideShowDemoScreen_SlideShowHomeButton->fn->setReleasedEventCallback(SlideShowDemoScreen_SlideShowHomeButton, event_SlideShowDemoScreen_SlideShowHomeButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SlideShowDemoScreen_SlideShowHomeButton);

    SlideShowDemoScreen_LabelWidget10 = leLabelWidget_New();
    SlideShowDemoScreen_LabelWidget10->fn->setPosition(SlideShowDemoScreen_LabelWidget10, 10, 6);
    SlideShowDemoScreen_LabelWidget10->fn->setSize(SlideShowDemoScreen_LabelWidget10, 251, 25);
    SlideShowDemoScreen_LabelWidget10->fn->setScheme(SlideShowDemoScreen_LabelWidget10, &whiteScheme);
    SlideShowDemoScreen_LabelWidget10->fn->setBackgroundType(SlideShowDemoScreen_LabelWidget10, LE_WIDGET_BACKGROUND_NONE);
    SlideShowDemoScreen_LabelWidget10->fn->setString(SlideShowDemoScreen_LabelWidget10, (leString*)&string_SlideShowDemo);
    root0->fn->addChild(root0, (leWidget*)SlideShowDemoScreen_LabelWidget10);

    SlideShowDemoScreen_SlideShowPrevButton = leButtonWidget_New();
    SlideShowDemoScreen_SlideShowPrevButton->fn->setPosition(SlideShowDemoScreen_SlideShowPrevButton, 0, 90);
    SlideShowDemoScreen_SlideShowPrevButton->fn->setSize(SlideShowDemoScreen_SlideShowPrevButton, 50, 74);
    SlideShowDemoScreen_SlideShowPrevButton->fn->setBackgroundType(SlideShowDemoScreen_SlideShowPrevButton, LE_WIDGET_BACKGROUND_NONE);
    SlideShowDemoScreen_SlideShowPrevButton->fn->setBorderType(SlideShowDemoScreen_SlideShowPrevButton, LE_WIDGET_BORDER_NONE);
    SlideShowDemoScreen_SlideShowPrevButton->fn->setPressedImage(SlideShowDemoScreen_SlideShowPrevButton, (leImage*)&GFX_ArrowLeft_20x60);
    SlideShowDemoScreen_SlideShowPrevButton->fn->setReleasedImage(SlideShowDemoScreen_SlideShowPrevButton, (leImage*)&GFX_ArrowLeft_20x60);
    SlideShowDemoScreen_SlideShowPrevButton->fn->setReleasedEventCallback(SlideShowDemoScreen_SlideShowPrevButton, event_SlideShowDemoScreen_SlideShowPrevButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SlideShowDemoScreen_SlideShowPrevButton);

    SlideShowDemoScreen_SlideshowNextButton = leButtonWidget_New();
    SlideShowDemoScreen_SlideshowNextButton->fn->setPosition(SlideShowDemoScreen_SlideshowNextButton, 430, 90);
    SlideShowDemoScreen_SlideshowNextButton->fn->setSize(SlideShowDemoScreen_SlideshowNextButton, 49, 65);
    SlideShowDemoScreen_SlideshowNextButton->fn->setBackgroundType(SlideShowDemoScreen_SlideshowNextButton, LE_WIDGET_BACKGROUND_NONE);
    SlideShowDemoScreen_SlideshowNextButton->fn->setBorderType(SlideShowDemoScreen_SlideshowNextButton, LE_WIDGET_BORDER_NONE);
    SlideShowDemoScreen_SlideshowNextButton->fn->setPressedImage(SlideShowDemoScreen_SlideshowNextButton, (leImage*)&GFX_ArrowRight_20x60);
    SlideShowDemoScreen_SlideshowNextButton->fn->setReleasedImage(SlideShowDemoScreen_SlideshowNextButton, (leImage*)&GFX_ArrowRight_20x60);
    SlideShowDemoScreen_SlideshowNextButton->fn->setReleasedEventCallback(SlideShowDemoScreen_SlideshowNextButton, event_SlideShowDemoScreen_SlideshowNextButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SlideShowDemoScreen_SlideshowNextButton);

    SlideShowDemoScreen_SlideShowFFButton = leButtonWidget_New();
    SlideShowDemoScreen_SlideShowFFButton->fn->setPosition(SlideShowDemoScreen_SlideShowFFButton, 261, 220);
    SlideShowDemoScreen_SlideShowFFButton->fn->setSize(SlideShowDemoScreen_SlideShowFFButton, 99, 38);
    SlideShowDemoScreen_SlideShowFFButton->fn->setToggleable(SlideShowDemoScreen_SlideShowFFButton, LE_TRUE);
    SlideShowDemoScreen_SlideShowFFButton->fn->setString(SlideShowDemoScreen_SlideShowFFButton, (leString*)&string_msecs500);
    SlideShowDemoScreen_SlideShowFFButton->fn->setPressedImage(SlideShowDemoScreen_SlideShowFFButton, (leImage*)&GFX_Stop_30x30);
    SlideShowDemoScreen_SlideShowFFButton->fn->setReleasedImage(SlideShowDemoScreen_SlideShowFFButton, (leImage*)&GFX_FF_30x30);
    SlideShowDemoScreen_SlideShowFFButton->fn->setPressedEventCallback(SlideShowDemoScreen_SlideShowFFButton, event_SlideShowDemoScreen_SlideShowFFButton_OnPressed);
    SlideShowDemoScreen_SlideShowFFButton->fn->setReleasedEventCallback(SlideShowDemoScreen_SlideShowFFButton, event_SlideShowDemoScreen_SlideShowFFButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SlideShowDemoScreen_SlideShowFFButton);

    SlideShowDemoScreen_SlideShowPlayButton = leButtonWidget_New();
    SlideShowDemoScreen_SlideShowPlayButton->fn->setPosition(SlideShowDemoScreen_SlideShowPlayButton, 138, 220);
    SlideShowDemoScreen_SlideShowPlayButton->fn->setSize(SlideShowDemoScreen_SlideShowPlayButton, 92, 37);
    SlideShowDemoScreen_SlideShowPlayButton->fn->setToggleable(SlideShowDemoScreen_SlideShowPlayButton, LE_TRUE);
    SlideShowDemoScreen_SlideShowPlayButton->fn->setString(SlideShowDemoScreen_SlideShowPlayButton, (leString*)&string_secs2);
    SlideShowDemoScreen_SlideShowPlayButton->fn->setPressedImage(SlideShowDemoScreen_SlideShowPlayButton, (leImage*)&GFX_Stop_30x30);
    SlideShowDemoScreen_SlideShowPlayButton->fn->setReleasedImage(SlideShowDemoScreen_SlideShowPlayButton, (leImage*)&GFX_Play_30x30);
    SlideShowDemoScreen_SlideShowPlayButton->fn->setPressedEventCallback(SlideShowDemoScreen_SlideShowPlayButton, event_SlideShowDemoScreen_SlideShowPlayButton_OnPressed);
    SlideShowDemoScreen_SlideShowPlayButton->fn->setReleasedEventCallback(SlideShowDemoScreen_SlideShowPlayButton, event_SlideShowDemoScreen_SlideShowPlayButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SlideShowDemoScreen_SlideShowPlayButton);

    SlideShowDemoScreen_SSStatusImageWidget = leImageWidget_New();
    SlideShowDemoScreen_SSStatusImageWidget->fn->setPosition(SlideShowDemoScreen_SSStatusImageWidget, 349, 10);
    SlideShowDemoScreen_SSStatusImageWidget->fn->setSize(SlideShowDemoScreen_SSStatusImageWidget, 20, 20);
    SlideShowDemoScreen_SSStatusImageWidget->fn->setBackgroundType(SlideShowDemoScreen_SSStatusImageWidget, LE_WIDGET_BACKGROUND_NONE);
    SlideShowDemoScreen_SSStatusImageWidget->fn->setBorderType(SlideShowDemoScreen_SSStatusImageWidget, LE_WIDGET_BORDER_NONE);
    SlideShowDemoScreen_SSStatusImageWidget->fn->setImage(SlideShowDemoScreen_SSStatusImageWidget, (leImage*)&GFX_Pause_Pink_20x20);
    root0->fn->addChild(root0, (leWidget*)SlideShowDemoScreen_SSStatusImageWidget);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    SlideShowDemoScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_SlideShowDemoScreen()
{
    SlideShowDemoScreen_OnUpdate(); // raise event
}

void screenHide_SlideShowDemoScreen()
{
    SlideShowDemoScreen_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    SlideShowDemoScreen_GradientWidget6 = NULL;
    SlideShowDemoScreen_ImageSequenceWidget1 = NULL;
    SlideShowDemoScreen_SlideshowHelpButton = NULL;
    SlideShowDemoScreen_SlideShowHomeButton = NULL;
    SlideShowDemoScreen_LabelWidget10 = NULL;
    SlideShowDemoScreen_SlideShowPrevButton = NULL;
    SlideShowDemoScreen_SlideshowNextButton = NULL;
    SlideShowDemoScreen_SlideShowFFButton = NULL;
    SlideShowDemoScreen_SlideShowPlayButton = NULL;
    SlideShowDemoScreen_SSStatusImageWidget = NULL;


    showing = LE_FALSE;
}

void screenDestroy_SlideShowDemoScreen()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_SlideShowDemoScreen(uint32_t lyrIdx)
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

