#include "gfx/legato/generated/screen/le_gen_screen_SlideshowHelpScreen.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget8;
leButtonWidget* SlideShowHelpCloseButton;
leImageWidget* ImageWidget18;
leLabelWidget* LabelWidget27;
leLabelWidget* LabelWidget31;
leLabelWidget* LabelWidget36;
leLabelWidget* LabelWidget37;
leLabelWidget* LabelWidget38;
leLabelWidget* LabelWidget39;
leImageWidget* ImageWidget21;
leImageWidget* ImageWidget24;
leImageWidget* ImageWidget25;
leImageWidget* ImageWidget26;

// string list for this screen
static leTableString tableString_Help;
static leTableString tableString_SlideShowNavHelpInfo;
static leTableString tableString_TouchPlayHelpInfo;
static leTableString tableString_TouchFFHelpInfo;
static leTableString tableString_HomeHelpText;
static leTableString tableString_TouchStopHelpInfo;

static leBool showing = LE_FALSE;

leResult screenInit_SlideshowHelpScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_SlideshowHelpScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_Help, string_Help);
    leTableString_Constructor(&tableString_SlideShowNavHelpInfo, string_SlideShowNavHelpInfo);
    leTableString_Constructor(&tableString_TouchPlayHelpInfo, string_TouchPlayHelpInfo);
    leTableString_Constructor(&tableString_TouchFFHelpInfo, string_TouchFFHelpInfo);
    leTableString_Constructor(&tableString_HomeHelpText, string_HomeHelpText);
    leTableString_Constructor(&tableString_TouchStopHelpInfo, string_TouchStopHelpInfo);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget8 = leWidget_New();
    PanelWidget8->fn->setPosition(PanelWidget8, 0, 0);
    PanelWidget8->fn->setSize(PanelWidget8, 480, 320);
    PanelWidget8->fn->setScheme(PanelWidget8, &whiteScheme);
    root0->fn->addChild(root0, PanelWidget8);

    SlideShowHelpCloseButton = leButtonWidget_New();
    SlideShowHelpCloseButton->fn->setPosition(SlideShowHelpCloseButton, 440, 0);
    SlideShowHelpCloseButton->fn->setSize(SlideShowHelpCloseButton, 40, 40);
    SlideShowHelpCloseButton->fn->setBackgroundType(SlideShowHelpCloseButton, LE_WIDGET_BACKGROUND_NONE);
    SlideShowHelpCloseButton->fn->setPressedImage(SlideShowHelpCloseButton, &GFX_CloseX_40x40);
    SlideShowHelpCloseButton->fn->setReleasedImage(SlideShowHelpCloseButton, &GFX_CloseX_40x40);
    SlideShowHelpCloseButton->fn->setReleasedEventCallback(SlideShowHelpCloseButton, SlideShowHelpCloseButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SlideShowHelpCloseButton);

    ImageWidget18 = leImageWidget_New();
    ImageWidget18->fn->setPosition(ImageWidget18, 0, 0);
    ImageWidget18->fn->setSize(ImageWidget18, 40, 40);
    ImageWidget18->fn->setBackgroundType(ImageWidget18, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget18->fn->setImage(ImageWidget18, &GFX_Help_40x40);
    root0->fn->addChild(root0, (leWidget*)ImageWidget18);

    LabelWidget27 = leLabelWidget_New();
    LabelWidget27->fn->setPosition(LabelWidget27, 48, 6);
    LabelWidget27->fn->setBackgroundType(LabelWidget27, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget27->fn->setString(LabelWidget27, (leString*)&tableString_Help);
    root0->fn->addChild(root0, (leWidget*)LabelWidget27);

    LabelWidget31 = leLabelWidget_New();
    LabelWidget31->fn->setPosition(LabelWidget31, 29, 47);
    LabelWidget31->fn->setSize(LabelWidget31, 356, 25);
    LabelWidget31->fn->setBackgroundType(LabelWidget31, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget31->fn->setString(LabelWidget31, (leString*)&tableString_SlideShowNavHelpInfo);
    root0->fn->addChild(root0, (leWidget*)LabelWidget31);

    LabelWidget36 = leLabelWidget_New();
    LabelWidget36->fn->setPosition(LabelWidget36, 63, 71);
    LabelWidget36->fn->setSize(LabelWidget36, 355, 25);
    LabelWidget36->fn->setBackgroundType(LabelWidget36, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget36->fn->setString(LabelWidget36, (leString*)&tableString_TouchPlayHelpInfo);
    root0->fn->addChild(root0, (leWidget*)LabelWidget36);

    LabelWidget37 = leLabelWidget_New();
    LabelWidget37->fn->setPosition(LabelWidget37, 63, 95);
    LabelWidget37->fn->setSize(LabelWidget37, 373, 25);
    LabelWidget37->fn->setBackgroundType(LabelWidget37, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget37->fn->setString(LabelWidget37, (leString*)&tableString_TouchFFHelpInfo);
    root0->fn->addChild(root0, (leWidget*)LabelWidget37);

    LabelWidget38 = leLabelWidget_New();
    LabelWidget38->fn->setPosition(LabelWidget38, 63, 145);
    LabelWidget38->fn->setSize(LabelWidget38, 408, 25);
    LabelWidget38->fn->setBackgroundType(LabelWidget38, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget38->fn->setString(LabelWidget38, (leString*)&tableString_HomeHelpText);
    root0->fn->addChild(root0, (leWidget*)LabelWidget38);

    LabelWidget39 = leLabelWidget_New();
    LabelWidget39->fn->setPosition(LabelWidget39, 63, 121);
    LabelWidget39->fn->setSize(LabelWidget39, 372, 25);
    LabelWidget39->fn->setBackgroundType(LabelWidget39, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget39->fn->setString(LabelWidget39, (leString*)&tableString_TouchStopHelpInfo);
    root0->fn->addChild(root0, (leWidget*)LabelWidget39);

    ImageWidget21 = leImageWidget_New();
    ImageWidget21->fn->setPosition(ImageWidget21, 36, 75);
    ImageWidget21->fn->setSize(ImageWidget21, 20, 20);
    ImageWidget21->fn->setBackgroundType(ImageWidget21, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget21->fn->setImage(ImageWidget21, &GFX_Play_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget21);

    ImageWidget24 = leImageWidget_New();
    ImageWidget24->fn->setPosition(ImageWidget24, 36, 100);
    ImageWidget24->fn->setSize(ImageWidget24, 20, 20);
    ImageWidget24->fn->setBackgroundType(ImageWidget24, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget24->fn->setImage(ImageWidget24, &GFX_FF_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget24);

    ImageWidget25 = leImageWidget_New();
    ImageWidget25->fn->setPosition(ImageWidget25, 36, 149);
    ImageWidget25->fn->setSize(ImageWidget25, 20, 20);
    ImageWidget25->fn->setBackgroundType(ImageWidget25, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget25->fn->setImage(ImageWidget25, &GFX_Home_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget25);

    ImageWidget26 = leImageWidget_New();
    ImageWidget26->fn->setPosition(ImageWidget26, 36, 125);
    ImageWidget26->fn->setSize(ImageWidget26, 20, 20);
    ImageWidget26->fn->setBackgroundType(ImageWidget26, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget26->fn->setImage(ImageWidget26, &GFX_Stop_20x20);
    root0->fn->addChild(root0, (leWidget*)ImageWidget26);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    SlideshowHelpScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_SlideshowHelpScreen()
{
    SlideshowHelpScreen_OnUpdate();
}

void screenHide_SlideshowHelpScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget8 = NULL;
    SlideShowHelpCloseButton = NULL;
    ImageWidget18 = NULL;
    LabelWidget27 = NULL;
    LabelWidget31 = NULL;
    LabelWidget36 = NULL;
    LabelWidget37 = NULL;
    LabelWidget38 = NULL;
    LabelWidget39 = NULL;
    ImageWidget21 = NULL;
    ImageWidget24 = NULL;
    ImageWidget25 = NULL;
    ImageWidget26 = NULL;

    tableString_Help.fn->destructor(&tableString_Help);
    tableString_SlideShowNavHelpInfo.fn->destructor(&tableString_SlideShowNavHelpInfo);
    tableString_TouchPlayHelpInfo.fn->destructor(&tableString_TouchPlayHelpInfo);
    tableString_TouchFFHelpInfo.fn->destructor(&tableString_TouchFFHelpInfo);
    tableString_HomeHelpText.fn->destructor(&tableString_HomeHelpText);
    tableString_TouchStopHelpInfo.fn->destructor(&tableString_TouchStopHelpInfo);
    showing = LE_FALSE;
}

void screenDestroy_SlideshowHelpScreen()
{

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

