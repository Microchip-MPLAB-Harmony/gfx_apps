#include "gfx/legato/generated/screen/le_gen_screen_SlideshowHelpScreen.h"

// screen member widget declarations
leWidget* root0;

leWidget* SlideshowHelpScreen_PanelWidget8;
leButtonWidget* SlideshowHelpScreen_SlideShowHelpCloseButton;
leImageWidget* SlideshowHelpScreen_ImageWidget18;
leLabelWidget* SlideshowHelpScreen_LabelWidget27;
leLabelWidget* SlideshowHelpScreen_LabelWidget31;
leLabelWidget* SlideshowHelpScreen_LabelWidget36;
leLabelWidget* SlideshowHelpScreen_LabelWidget37;
leLabelWidget* SlideshowHelpScreen_LabelWidget38;
leLabelWidget* SlideshowHelpScreen_LabelWidget39;
leImageWidget* SlideshowHelpScreen_ImageWidget21;
leImageWidget* SlideshowHelpScreen_ImageWidget24;
leImageWidget* SlideshowHelpScreen_ImageWidget25;
leImageWidget* SlideshowHelpScreen_ImageWidget26;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_SlideshowHelpScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_SlideshowHelpScreen()
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

    SlideshowHelpScreen_PanelWidget8 = leWidget_New();
    SlideshowHelpScreen_PanelWidget8->fn->setPosition(SlideshowHelpScreen_PanelWidget8, 0, 0);
    SlideshowHelpScreen_PanelWidget8->fn->setSize(SlideshowHelpScreen_PanelWidget8, 480, 320);
    SlideshowHelpScreen_PanelWidget8->fn->setScheme(SlideshowHelpScreen_PanelWidget8, &whiteScheme);
    root0->fn->addChild(root0, (leWidget*)SlideshowHelpScreen_PanelWidget8);

    SlideshowHelpScreen_SlideShowHelpCloseButton = leButtonWidget_New();
    SlideshowHelpScreen_SlideShowHelpCloseButton->fn->setPosition(SlideshowHelpScreen_SlideShowHelpCloseButton, 440, 0);
    SlideshowHelpScreen_SlideShowHelpCloseButton->fn->setSize(SlideshowHelpScreen_SlideShowHelpCloseButton, 40, 40);
    SlideshowHelpScreen_SlideShowHelpCloseButton->fn->setBackgroundType(SlideshowHelpScreen_SlideShowHelpCloseButton, LE_WIDGET_BACKGROUND_NONE);
    SlideshowHelpScreen_SlideShowHelpCloseButton->fn->setPressedImage(SlideshowHelpScreen_SlideShowHelpCloseButton, (leImage*)&GFX_CloseX_40x40);
    SlideshowHelpScreen_SlideShowHelpCloseButton->fn->setReleasedImage(SlideshowHelpScreen_SlideShowHelpCloseButton, (leImage*)&GFX_CloseX_40x40);
    SlideshowHelpScreen_SlideShowHelpCloseButton->fn->setReleasedEventCallback(SlideshowHelpScreen_SlideShowHelpCloseButton, event_SlideshowHelpScreen_SlideShowHelpCloseButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SlideshowHelpScreen_SlideShowHelpCloseButton);

    SlideshowHelpScreen_ImageWidget18 = leImageWidget_New();
    SlideshowHelpScreen_ImageWidget18->fn->setPosition(SlideshowHelpScreen_ImageWidget18, 0, 0);
    SlideshowHelpScreen_ImageWidget18->fn->setSize(SlideshowHelpScreen_ImageWidget18, 40, 40);
    SlideshowHelpScreen_ImageWidget18->fn->setBackgroundType(SlideshowHelpScreen_ImageWidget18, LE_WIDGET_BACKGROUND_NONE);
    SlideshowHelpScreen_ImageWidget18->fn->setBorderType(SlideshowHelpScreen_ImageWidget18, LE_WIDGET_BORDER_NONE);
    SlideshowHelpScreen_ImageWidget18->fn->setImage(SlideshowHelpScreen_ImageWidget18, (leImage*)&GFX_Help_40x40);
    root0->fn->addChild(root0, (leWidget*)SlideshowHelpScreen_ImageWidget18);

    SlideshowHelpScreen_LabelWidget27 = leLabelWidget_New();
    SlideshowHelpScreen_LabelWidget27->fn->setPosition(SlideshowHelpScreen_LabelWidget27, 48, 6);
    SlideshowHelpScreen_LabelWidget27->fn->setBackgroundType(SlideshowHelpScreen_LabelWidget27, LE_WIDGET_BACKGROUND_NONE);
    SlideshowHelpScreen_LabelWidget27->fn->setString(SlideshowHelpScreen_LabelWidget27, (leString*)&string_Help);
    root0->fn->addChild(root0, (leWidget*)SlideshowHelpScreen_LabelWidget27);

    SlideshowHelpScreen_LabelWidget31 = leLabelWidget_New();
    SlideshowHelpScreen_LabelWidget31->fn->setPosition(SlideshowHelpScreen_LabelWidget31, 29, 47);
    SlideshowHelpScreen_LabelWidget31->fn->setSize(SlideshowHelpScreen_LabelWidget31, 356, 25);
    SlideshowHelpScreen_LabelWidget31->fn->setBackgroundType(SlideshowHelpScreen_LabelWidget31, LE_WIDGET_BACKGROUND_NONE);
    SlideshowHelpScreen_LabelWidget31->fn->setString(SlideshowHelpScreen_LabelWidget31, (leString*)&string_SlideShowNavHelpInfo);
    root0->fn->addChild(root0, (leWidget*)SlideshowHelpScreen_LabelWidget31);

    SlideshowHelpScreen_LabelWidget36 = leLabelWidget_New();
    SlideshowHelpScreen_LabelWidget36->fn->setPosition(SlideshowHelpScreen_LabelWidget36, 63, 71);
    SlideshowHelpScreen_LabelWidget36->fn->setSize(SlideshowHelpScreen_LabelWidget36, 355, 25);
    SlideshowHelpScreen_LabelWidget36->fn->setBackgroundType(SlideshowHelpScreen_LabelWidget36, LE_WIDGET_BACKGROUND_NONE);
    SlideshowHelpScreen_LabelWidget36->fn->setString(SlideshowHelpScreen_LabelWidget36, (leString*)&string_TouchPlayHelpInfo);
    root0->fn->addChild(root0, (leWidget*)SlideshowHelpScreen_LabelWidget36);

    SlideshowHelpScreen_LabelWidget37 = leLabelWidget_New();
    SlideshowHelpScreen_LabelWidget37->fn->setPosition(SlideshowHelpScreen_LabelWidget37, 63, 95);
    SlideshowHelpScreen_LabelWidget37->fn->setSize(SlideshowHelpScreen_LabelWidget37, 416, 25);
    SlideshowHelpScreen_LabelWidget37->fn->setBackgroundType(SlideshowHelpScreen_LabelWidget37, LE_WIDGET_BACKGROUND_NONE);
    SlideshowHelpScreen_LabelWidget37->fn->setString(SlideshowHelpScreen_LabelWidget37, (leString*)&string_TouchFFHelpInfo);
    root0->fn->addChild(root0, (leWidget*)SlideshowHelpScreen_LabelWidget37);

    SlideshowHelpScreen_LabelWidget38 = leLabelWidget_New();
    SlideshowHelpScreen_LabelWidget38->fn->setPosition(SlideshowHelpScreen_LabelWidget38, 63, 145);
    SlideshowHelpScreen_LabelWidget38->fn->setSize(SlideshowHelpScreen_LabelWidget38, 408, 25);
    SlideshowHelpScreen_LabelWidget38->fn->setBackgroundType(SlideshowHelpScreen_LabelWidget38, LE_WIDGET_BACKGROUND_NONE);
    SlideshowHelpScreen_LabelWidget38->fn->setString(SlideshowHelpScreen_LabelWidget38, (leString*)&string_HomeHelpText);
    root0->fn->addChild(root0, (leWidget*)SlideshowHelpScreen_LabelWidget38);

    SlideshowHelpScreen_LabelWidget39 = leLabelWidget_New();
    SlideshowHelpScreen_LabelWidget39->fn->setPosition(SlideshowHelpScreen_LabelWidget39, 63, 121);
    SlideshowHelpScreen_LabelWidget39->fn->setSize(SlideshowHelpScreen_LabelWidget39, 372, 25);
    SlideshowHelpScreen_LabelWidget39->fn->setBackgroundType(SlideshowHelpScreen_LabelWidget39, LE_WIDGET_BACKGROUND_NONE);
    SlideshowHelpScreen_LabelWidget39->fn->setString(SlideshowHelpScreen_LabelWidget39, (leString*)&string_TouchStopHelpInfo);
    root0->fn->addChild(root0, (leWidget*)SlideshowHelpScreen_LabelWidget39);

    SlideshowHelpScreen_ImageWidget21 = leImageWidget_New();
    SlideshowHelpScreen_ImageWidget21->fn->setPosition(SlideshowHelpScreen_ImageWidget21, 36, 75);
    SlideshowHelpScreen_ImageWidget21->fn->setSize(SlideshowHelpScreen_ImageWidget21, 20, 20);
    SlideshowHelpScreen_ImageWidget21->fn->setBackgroundType(SlideshowHelpScreen_ImageWidget21, LE_WIDGET_BACKGROUND_NONE);
    SlideshowHelpScreen_ImageWidget21->fn->setBorderType(SlideshowHelpScreen_ImageWidget21, LE_WIDGET_BORDER_NONE);
    SlideshowHelpScreen_ImageWidget21->fn->setImage(SlideshowHelpScreen_ImageWidget21, (leImage*)&GFX_Play_20x20);
    root0->fn->addChild(root0, (leWidget*)SlideshowHelpScreen_ImageWidget21);

    SlideshowHelpScreen_ImageWidget24 = leImageWidget_New();
    SlideshowHelpScreen_ImageWidget24->fn->setPosition(SlideshowHelpScreen_ImageWidget24, 36, 100);
    SlideshowHelpScreen_ImageWidget24->fn->setSize(SlideshowHelpScreen_ImageWidget24, 20, 20);
    SlideshowHelpScreen_ImageWidget24->fn->setBackgroundType(SlideshowHelpScreen_ImageWidget24, LE_WIDGET_BACKGROUND_NONE);
    SlideshowHelpScreen_ImageWidget24->fn->setBorderType(SlideshowHelpScreen_ImageWidget24, LE_WIDGET_BORDER_NONE);
    SlideshowHelpScreen_ImageWidget24->fn->setImage(SlideshowHelpScreen_ImageWidget24, (leImage*)&GFX_FF_20x20);
    root0->fn->addChild(root0, (leWidget*)SlideshowHelpScreen_ImageWidget24);

    SlideshowHelpScreen_ImageWidget25 = leImageWidget_New();
    SlideshowHelpScreen_ImageWidget25->fn->setPosition(SlideshowHelpScreen_ImageWidget25, 36, 149);
    SlideshowHelpScreen_ImageWidget25->fn->setSize(SlideshowHelpScreen_ImageWidget25, 20, 20);
    SlideshowHelpScreen_ImageWidget25->fn->setBackgroundType(SlideshowHelpScreen_ImageWidget25, LE_WIDGET_BACKGROUND_NONE);
    SlideshowHelpScreen_ImageWidget25->fn->setBorderType(SlideshowHelpScreen_ImageWidget25, LE_WIDGET_BORDER_NONE);
    SlideshowHelpScreen_ImageWidget25->fn->setImage(SlideshowHelpScreen_ImageWidget25, (leImage*)&GFX_Home_20x20);
    root0->fn->addChild(root0, (leWidget*)SlideshowHelpScreen_ImageWidget25);

    SlideshowHelpScreen_ImageWidget26 = leImageWidget_New();
    SlideshowHelpScreen_ImageWidget26->fn->setPosition(SlideshowHelpScreen_ImageWidget26, 36, 125);
    SlideshowHelpScreen_ImageWidget26->fn->setSize(SlideshowHelpScreen_ImageWidget26, 20, 20);
    SlideshowHelpScreen_ImageWidget26->fn->setBackgroundType(SlideshowHelpScreen_ImageWidget26, LE_WIDGET_BACKGROUND_NONE);
    SlideshowHelpScreen_ImageWidget26->fn->setBorderType(SlideshowHelpScreen_ImageWidget26, LE_WIDGET_BORDER_NONE);
    SlideshowHelpScreen_ImageWidget26->fn->setImage(SlideshowHelpScreen_ImageWidget26, (leImage*)&GFX_Stop_20x20);
    root0->fn->addChild(root0, (leWidget*)SlideshowHelpScreen_ImageWidget26);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    SlideshowHelpScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_SlideshowHelpScreen()
{
    SlideshowHelpScreen_OnUpdate(); // raise event
}

void screenHide_SlideshowHelpScreen()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    SlideshowHelpScreen_PanelWidget8 = NULL;
    SlideshowHelpScreen_SlideShowHelpCloseButton = NULL;
    SlideshowHelpScreen_ImageWidget18 = NULL;
    SlideshowHelpScreen_LabelWidget27 = NULL;
    SlideshowHelpScreen_LabelWidget31 = NULL;
    SlideshowHelpScreen_LabelWidget36 = NULL;
    SlideshowHelpScreen_LabelWidget37 = NULL;
    SlideshowHelpScreen_LabelWidget38 = NULL;
    SlideshowHelpScreen_LabelWidget39 = NULL;
    SlideshowHelpScreen_ImageWidget21 = NULL;
    SlideshowHelpScreen_ImageWidget24 = NULL;
    SlideshowHelpScreen_ImageWidget25 = NULL;
    SlideshowHelpScreen_ImageWidget26 = NULL;


    showing = LE_FALSE;
}

void screenDestroy_SlideshowHelpScreen()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_SlideshowHelpScreen(uint32_t lyrIdx)
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

