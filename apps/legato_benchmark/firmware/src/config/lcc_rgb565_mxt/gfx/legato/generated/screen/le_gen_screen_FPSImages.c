#include "gfx/legato/generated/screen/le_gen_screen_FPSImages.h"

// widget list for layer 0
static leWidget* root0;

leWidget* ImageBackground;
leImageWidget* ImageRenderArea;
leWidget* ImageSideContainer;
leLabelWidget* ImageUpdateLabel;
leLabelWidget* ImageRefreshLabel;
leLabelWidget* ImageRefreshValue;
leLabelWidget* ImageContainerTitle;
leButtonWidget* ImageNextButton;
leButtonWidget* ImageSizeDownButton;
leButtonWidget* ImageSizeUpButton;
leLabelWidget* ImageSizeLabel;
leLabelWidget* ImageSizeValue;
leLabelWidget* ImageTypeLabel;
leLabelWidget* ImageTypeValue;
leButtonWidget* ImageTypePrevButton;
leButtonWidget* ImageTypeNextButton;
leButtonWidget* ImageUpdateValue;

// string list for this screen
static leTableString tableString_FPS;
static leTableString tableString_RefreshRate;
static leTableString tableString_NumsLittle;
static leTableString tableString_ImageRendering;
static leTableString tableString_Next;
static leTableString tableString_Minus;
static leTableString tableString_Plus;
static leTableString tableString_Size;
static leTableString tableString_NumsTiny;
static leTableString tableString_ImageType;
static leTableString tableString_Previous;
static leTableString tableString_NextSymbol;

static leBool showing = LE_FALSE;

leResult screenInit_FPSImages()
{
    return LE_SUCCESS;
}

leResult screenShow_FPSImages()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_FPS, string_FPS);
    leTableString_Constructor(&tableString_RefreshRate, string_RefreshRate);
    leTableString_Constructor(&tableString_NumsLittle, string_NumsLittle);
    leTableString_Constructor(&tableString_ImageRendering, string_ImageRendering);
    leTableString_Constructor(&tableString_Next, string_Next);
    leTableString_Constructor(&tableString_Minus, string_Minus);
    leTableString_Constructor(&tableString_Plus, string_Plus);
    leTableString_Constructor(&tableString_Size, string_Size);
    leTableString_Constructor(&tableString_NumsTiny, string_NumsTiny);
    leTableString_Constructor(&tableString_ImageType, string_ImageType);
    leTableString_Constructor(&tableString_Previous, string_Previous);
    leTableString_Constructor(&tableString_NextSymbol, string_NextSymbol);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    ImageBackground = leWidget_New();
    ImageBackground->fn->setPosition(ImageBackground, 0, 0);
    ImageBackground->fn->setSize(ImageBackground, 480, 272);
    ImageBackground->fn->setScheme(ImageBackground, &WhiteFillScheme);
    root0->fn->addChild(root0, ImageBackground);

    ImageRenderArea = leImageWidget_New();
    ImageRenderArea->fn->setPosition(ImageRenderArea, 0, 0);
    ImageRenderArea->fn->setSize(ImageRenderArea, 480, 272);
    ImageRenderArea->fn->setBackgroundType(ImageRenderArea, LE_WIDGET_BACKGROUND_NONE);
    ImageRenderArea->fn->setHAlignment(ImageRenderArea, LE_HALIGN_LEFT);
    ImageRenderArea->fn->setVAlignment(ImageRenderArea, LE_VALIGN_TOP);
    root0->fn->addChild(root0, (leWidget*)ImageRenderArea);

    ImageSideContainer = leWidget_New();
    ImageSideContainer->fn->setPosition(ImageSideContainer, 359, 8);
    ImageSideContainer->fn->setSize(ImageSideContainer, 113, 260);
    ImageSideContainer->fn->setScheme(ImageSideContainer, &WhiteBackgroundScheme);
    ImageSideContainer->fn->setBackgroundType(ImageSideContainer, LE_WIDGET_BACKGROUND_NONE);
    ImageSideContainer->fn->setBorderType(ImageSideContainer, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, ImageSideContainer);

    ImageUpdateLabel = leLabelWidget_New();
    ImageUpdateLabel->fn->setPosition(ImageUpdateLabel, 1, 22);
    ImageUpdateLabel->fn->setSize(ImageUpdateLabel, 110, 19);
    ImageUpdateLabel->fn->setBackgroundType(ImageUpdateLabel, LE_WIDGET_BACKGROUND_NONE);
    ImageUpdateLabel->fn->setString(ImageUpdateLabel, (leString*)&tableString_FPS);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageUpdateLabel);

    ImageRefreshLabel = leLabelWidget_New();
    ImageRefreshLabel->fn->setPosition(ImageRefreshLabel, 1, 68);
    ImageRefreshLabel->fn->setSize(ImageRefreshLabel, 109, 18);
    ImageRefreshLabel->fn->setBackgroundType(ImageRefreshLabel, LE_WIDGET_BACKGROUND_NONE);
    ImageRefreshLabel->fn->setString(ImageRefreshLabel, (leString*)&tableString_RefreshRate);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageRefreshLabel);

    ImageRefreshValue = leLabelWidget_New();
    ImageRefreshValue->fn->setPosition(ImageRefreshValue, 7, 89);
    ImageRefreshValue->fn->setSize(ImageRefreshValue, 101, 24);
    ImageRefreshValue->fn->setBackgroundType(ImageRefreshValue, LE_WIDGET_BACKGROUND_NONE);
    ImageRefreshValue->fn->setHAlignment(ImageRefreshValue, LE_HALIGN_CENTER);
    ImageRefreshValue->fn->setString(ImageRefreshValue, (leString*)&tableString_NumsLittle);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageRefreshValue);

    ImageContainerTitle = leLabelWidget_New();
    ImageContainerTitle->fn->setPosition(ImageContainerTitle, 0, 2);
    ImageContainerTitle->fn->setSize(ImageContainerTitle, 111, 25);
    ImageContainerTitle->fn->setBackgroundType(ImageContainerTitle, LE_WIDGET_BACKGROUND_NONE);
    ImageContainerTitle->fn->setHAlignment(ImageContainerTitle, LE_HALIGN_CENTER);
    ImageContainerTitle->fn->setString(ImageContainerTitle, (leString*)&tableString_ImageRendering);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageContainerTitle);

    ImageNextButton = leButtonWidget_New();
    ImageNextButton->fn->setPosition(ImageNextButton, 57, 226);
    ImageNextButton->fn->setSize(ImageNextButton, 55, 30);
    ImageNextButton->fn->setBackgroundType(ImageNextButton, LE_WIDGET_BACKGROUND_NONE);
    ImageNextButton->fn->setString(ImageNextButton, (leString*)&tableString_Next);
    ImageNextButton->fn->setPressedEventCallback(ImageNextButton, ImageNextButton_OnPressed);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageNextButton);

    ImageSizeDownButton = leButtonWidget_New();
    ImageSizeDownButton->fn->setPosition(ImageSizeDownButton, 1, 136);
    ImageSizeDownButton->fn->setSize(ImageSizeDownButton, 55, 30);
    ImageSizeDownButton->fn->setBackgroundType(ImageSizeDownButton, LE_WIDGET_BACKGROUND_NONE);
    ImageSizeDownButton->fn->setString(ImageSizeDownButton, (leString*)&tableString_Minus);
    ImageSizeDownButton->fn->setPressedEventCallback(ImageSizeDownButton, ImageSizeDownButton_OnPressed);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageSizeDownButton);

    ImageSizeUpButton = leButtonWidget_New();
    ImageSizeUpButton->fn->setPosition(ImageSizeUpButton, 57, 136);
    ImageSizeUpButton->fn->setSize(ImageSizeUpButton, 55, 30);
    ImageSizeUpButton->fn->setBackgroundType(ImageSizeUpButton, LE_WIDGET_BACKGROUND_NONE);
    ImageSizeUpButton->fn->setString(ImageSizeUpButton, (leString*)&tableString_Plus);
    ImageSizeUpButton->fn->setPressedEventCallback(ImageSizeUpButton, ImageSizeUpButton_OnPressed);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageSizeUpButton);

    ImageSizeLabel = leLabelWidget_New();
    ImageSizeLabel->fn->setPosition(ImageSizeLabel, 4, 113);
    ImageSizeLabel->fn->setSize(ImageSizeLabel, 33, 19);
    ImageSizeLabel->fn->setBackgroundType(ImageSizeLabel, LE_WIDGET_BACKGROUND_NONE);
    ImageSizeLabel->fn->setString(ImageSizeLabel, (leString*)&tableString_Size);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageSizeLabel);

    ImageSizeValue = leLabelWidget_New();
    ImageSizeValue->fn->setPosition(ImageSizeValue, 35, 112);
    ImageSizeValue->fn->setSize(ImageSizeValue, 75, 23);
    ImageSizeValue->fn->setBackgroundType(ImageSizeValue, LE_WIDGET_BACKGROUND_NONE);
    ImageSizeValue->fn->setString(ImageSizeValue, (leString*)&tableString_NumsTiny);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageSizeValue);

    ImageTypeLabel = leLabelWidget_New();
    ImageTypeLabel->fn->setPosition(ImageTypeLabel, 4, 168);
    ImageTypeLabel->fn->setSize(ImageTypeLabel, 39, 19);
    ImageTypeLabel->fn->setBackgroundType(ImageTypeLabel, LE_WIDGET_BACKGROUND_NONE);
    ImageTypeLabel->fn->setString(ImageTypeLabel, (leString*)&tableString_ImageType);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageTypeLabel);

    ImageTypeValue = leLabelWidget_New();
    ImageTypeValue->fn->setPosition(ImageTypeValue, 38, 168);
    ImageTypeValue->fn->setSize(ImageTypeValue, 74, 23);
    ImageTypeValue->fn->setBackgroundType(ImageTypeValue, LE_WIDGET_BACKGROUND_NONE);
    ImageTypeValue->fn->setString(ImageTypeValue, (leString*)&tableString_NumsTiny);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageTypeValue);

    ImageTypePrevButton = leButtonWidget_New();
    ImageTypePrevButton->fn->setPosition(ImageTypePrevButton, 1, 192);
    ImageTypePrevButton->fn->setSize(ImageTypePrevButton, 55, 30);
    ImageTypePrevButton->fn->setBackgroundType(ImageTypePrevButton, LE_WIDGET_BACKGROUND_NONE);
    ImageTypePrevButton->fn->setString(ImageTypePrevButton, (leString*)&tableString_Previous);
    ImageTypePrevButton->fn->setPressedEventCallback(ImageTypePrevButton, ImageTypePrevButton_OnPressed);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageTypePrevButton);

    ImageTypeNextButton = leButtonWidget_New();
    ImageTypeNextButton->fn->setPosition(ImageTypeNextButton, 57, 192);
    ImageTypeNextButton->fn->setSize(ImageTypeNextButton, 55, 30);
    ImageTypeNextButton->fn->setBackgroundType(ImageTypeNextButton, LE_WIDGET_BACKGROUND_NONE);
    ImageTypeNextButton->fn->setString(ImageTypeNextButton, (leString*)&tableString_NextSymbol);
    ImageTypeNextButton->fn->setPressedEventCallback(ImageTypeNextButton, ImageTypeNextButton_OnPressed);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageTypeNextButton);

    ImageUpdateValue = leButtonWidget_New();
    ImageUpdateValue->fn->setPosition(ImageUpdateValue, 5, 39);
    ImageUpdateValue->fn->setSize(ImageUpdateValue, 107, 31);
    ImageUpdateValue->fn->setBackgroundType(ImageUpdateValue, LE_WIDGET_BACKGROUND_NONE);
    ImageUpdateValue->fn->setToggleable(ImageUpdateValue, LE_TRUE);
    ImageUpdateValue->fn->setString(ImageUpdateValue, (leString*)&tableString_NumsLittle);
    ImageSideContainer->fn->addChild(ImageSideContainer, (leWidget*)ImageUpdateValue);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    FPSImages_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_FPSImages()
{
    FPSImages_OnUpdate();
}

void screenHide_FPSImages()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    ImageBackground = NULL;
    ImageRenderArea = NULL;
    ImageSideContainer = NULL;
    ImageUpdateLabel = NULL;
    ImageRefreshLabel = NULL;
    ImageRefreshValue = NULL;
    ImageContainerTitle = NULL;
    ImageNextButton = NULL;
    ImageSizeDownButton = NULL;
    ImageSizeUpButton = NULL;
    ImageSizeLabel = NULL;
    ImageSizeValue = NULL;
    ImageTypeLabel = NULL;
    ImageTypeValue = NULL;
    ImageTypePrevButton = NULL;
    ImageTypeNextButton = NULL;
    ImageUpdateValue = NULL;

    tableString_FPS.fn->destructor(&tableString_FPS);
    tableString_RefreshRate.fn->destructor(&tableString_RefreshRate);
    tableString_NumsLittle.fn->destructor(&tableString_NumsLittle);
    tableString_ImageRendering.fn->destructor(&tableString_ImageRendering);
    tableString_Next.fn->destructor(&tableString_Next);
    tableString_Minus.fn->destructor(&tableString_Minus);
    tableString_Plus.fn->destructor(&tableString_Plus);
    tableString_Size.fn->destructor(&tableString_Size);
    tableString_NumsTiny.fn->destructor(&tableString_NumsTiny);
    tableString_ImageType.fn->destructor(&tableString_ImageType);
    tableString_Previous.fn->destructor(&tableString_Previous);
    tableString_NextSymbol.fn->destructor(&tableString_NextSymbol);
    showing = LE_FALSE;

    FPSImages_OnHide();
}

void screenDestroy_FPSImages()
{

}

leWidget* screenGetRoot_FPSImages(uint32_t lyrIdx)
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

