#include "gfx/legato/generated/screen/le_gen_screen_Screen3.h"

// screen member widget declarations
leWidget* root0;

leWidget* Screen3_ImageBackground;
leImageWidget* Screen3_ImageRenderArea;
leWidget* Screen3_ImageSideContainer;
leButtonWidget* Screen3_ImageUpdateValue;
leButtonWidget* Screen3_ImageTypeNextButton;
leButtonWidget* Screen3_ImageTypePrevButton;
leLabelWidget* Screen3_ImageTypeValue;
leLabelWidget* Screen3_ImageTypeLabel;
leLabelWidget* Screen3_ImageSizeValue;
leLabelWidget* Screen3_ImageSizeLabel;
leButtonWidget* Screen3_ImageSizeUpButton;
leButtonWidget* Screen3_ImageSizeDownButton;
leButtonWidget* Screen3_ImageNextButton;
leLabelWidget* Screen3_ImageContainerTitle;
leLabelWidget* Screen3_ImageRefreshValue;
leLabelWidget* Screen3_ImageRefreshLabel;
leLabelWidget* Screen3_ImageUpdateLabel;

// string list for this screen
static leTableString string_NumsLarge;
static leTableString string_NumsLittle;
static leTableString string_Size;
static leTableString string_Next;
static leTableString string_DynamicString;
static leTableString string_Plus;
static leTableString string_Minus;
static leTableString string_RefreshRate;
static leTableString string_FPS;
static leTableString string_NumsTiny;
static leTableString string_RectanglesNum;
static leTableString string_MotionUpdates;
static leTableString string_NextSymbol;
static leTableString string_Previous;
static leTableString string_ImageType;
static leTableString string_ImageRendering;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen3()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen3()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&string_NumsLarge, stringID_NumsLarge);
    leTableString_Constructor(&string_NumsLittle, stringID_NumsLittle);
    leTableString_Constructor(&string_Size, stringID_Size);
    leTableString_Constructor(&string_Next, stringID_Next);
    leTableString_Constructor(&string_DynamicString, stringID_DynamicString);
    leTableString_Constructor(&string_Plus, stringID_Plus);
    leTableString_Constructor(&string_Minus, stringID_Minus);
    leTableString_Constructor(&string_RefreshRate, stringID_RefreshRate);
    leTableString_Constructor(&string_FPS, stringID_FPS);
    leTableString_Constructor(&string_NumsTiny, stringID_NumsTiny);
    leTableString_Constructor(&string_RectanglesNum, stringID_RectanglesNum);
    leTableString_Constructor(&string_MotionUpdates, stringID_MotionUpdates);
    leTableString_Constructor(&string_NextSymbol, stringID_NextSymbol);
    leTableString_Constructor(&string_Previous, stringID_Previous);
    leTableString_Constructor(&string_ImageType, stringID_ImageType);
    leTableString_Constructor(&string_ImageRendering, stringID_ImageRendering);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen3_ImageBackground = leWidget_New();
    Screen3_ImageBackground->fn->setPosition(Screen3_ImageBackground, 0, 0);
    Screen3_ImageBackground->fn->setSize(Screen3_ImageBackground, 480, 272);
    Screen3_ImageBackground->fn->setScheme(Screen3_ImageBackground, &WhiteFillScheme);
    root0->fn->addChild(root0, (leWidget*)Screen3_ImageBackground);

    Screen3_ImageRenderArea = leImageWidget_New();
    Screen3_ImageRenderArea->fn->setPosition(Screen3_ImageRenderArea, 0, 0);
    Screen3_ImageRenderArea->fn->setSize(Screen3_ImageRenderArea, 480, 272);
    Screen3_ImageRenderArea->fn->setBackgroundType(Screen3_ImageRenderArea, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageRenderArea->fn->setBorderType(Screen3_ImageRenderArea, LE_WIDGET_BORDER_NONE);
    Screen3_ImageRenderArea->fn->setHAlignment(Screen3_ImageRenderArea, LE_HALIGN_LEFT);
    Screen3_ImageRenderArea->fn->setVAlignment(Screen3_ImageRenderArea, LE_VALIGN_TOP);
    root0->fn->addChild(root0, (leWidget*)Screen3_ImageRenderArea);

    Screen3_ImageSideContainer = leWidget_New();
    Screen3_ImageSideContainer->fn->setPosition(Screen3_ImageSideContainer, 359, 8);
    Screen3_ImageSideContainer->fn->setSize(Screen3_ImageSideContainer, 113, 260);
    Screen3_ImageSideContainer->fn->setScheme(Screen3_ImageSideContainer, &WhiteBackgroundScheme);
    Screen3_ImageSideContainer->fn->setBackgroundType(Screen3_ImageSideContainer, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageSideContainer->fn->setBorderType(Screen3_ImageSideContainer, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, (leWidget*)Screen3_ImageSideContainer);

    Screen3_ImageUpdateValue = leButtonWidget_New();
    Screen3_ImageUpdateValue->fn->setPosition(Screen3_ImageUpdateValue, 5, 39);
    Screen3_ImageUpdateValue->fn->setSize(Screen3_ImageUpdateValue, 107, 31);
    Screen3_ImageUpdateValue->fn->setBackgroundType(Screen3_ImageUpdateValue, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageUpdateValue->fn->setToggleable(Screen3_ImageUpdateValue, LE_TRUE);
    Screen3_ImageUpdateValue->fn->setString(Screen3_ImageUpdateValue, (leString*)&string_NumsLittle);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageUpdateValue);

    Screen3_ImageTypeNextButton = leButtonWidget_New();
    Screen3_ImageTypeNextButton->fn->setPosition(Screen3_ImageTypeNextButton, 57, 192);
    Screen3_ImageTypeNextButton->fn->setSize(Screen3_ImageTypeNextButton, 55, 30);
    Screen3_ImageTypeNextButton->fn->setBackgroundType(Screen3_ImageTypeNextButton, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageTypeNextButton->fn->setString(Screen3_ImageTypeNextButton, (leString*)&string_NextSymbol);
    Screen3_ImageTypeNextButton->fn->setPressedEventCallback(Screen3_ImageTypeNextButton, event_Screen3_ImageTypeNextButton_OnPressed);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageTypeNextButton);

    Screen3_ImageTypePrevButton = leButtonWidget_New();
    Screen3_ImageTypePrevButton->fn->setPosition(Screen3_ImageTypePrevButton, 1, 192);
    Screen3_ImageTypePrevButton->fn->setSize(Screen3_ImageTypePrevButton, 55, 30);
    Screen3_ImageTypePrevButton->fn->setBackgroundType(Screen3_ImageTypePrevButton, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageTypePrevButton->fn->setString(Screen3_ImageTypePrevButton, (leString*)&string_Previous);
    Screen3_ImageTypePrevButton->fn->setPressedEventCallback(Screen3_ImageTypePrevButton, event_Screen3_ImageTypePrevButton_OnPressed);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageTypePrevButton);

    Screen3_ImageTypeValue = leLabelWidget_New();
    Screen3_ImageTypeValue->fn->setPosition(Screen3_ImageTypeValue, 38, 168);
    Screen3_ImageTypeValue->fn->setSize(Screen3_ImageTypeValue, 74, 23);
    Screen3_ImageTypeValue->fn->setBackgroundType(Screen3_ImageTypeValue, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageTypeValue->fn->setString(Screen3_ImageTypeValue, (leString*)&string_NumsTiny);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageTypeValue);

    Screen3_ImageTypeLabel = leLabelWidget_New();
    Screen3_ImageTypeLabel->fn->setPosition(Screen3_ImageTypeLabel, 4, 168);
    Screen3_ImageTypeLabel->fn->setSize(Screen3_ImageTypeLabel, 39, 19);
    Screen3_ImageTypeLabel->fn->setBackgroundType(Screen3_ImageTypeLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageTypeLabel->fn->setString(Screen3_ImageTypeLabel, (leString*)&string_ImageType);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageTypeLabel);

    Screen3_ImageSizeValue = leLabelWidget_New();
    Screen3_ImageSizeValue->fn->setPosition(Screen3_ImageSizeValue, 35, 112);
    Screen3_ImageSizeValue->fn->setSize(Screen3_ImageSizeValue, 75, 23);
    Screen3_ImageSizeValue->fn->setBackgroundType(Screen3_ImageSizeValue, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageSizeValue->fn->setString(Screen3_ImageSizeValue, (leString*)&string_NumsTiny);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageSizeValue);

    Screen3_ImageSizeLabel = leLabelWidget_New();
    Screen3_ImageSizeLabel->fn->setPosition(Screen3_ImageSizeLabel, 4, 113);
    Screen3_ImageSizeLabel->fn->setSize(Screen3_ImageSizeLabel, 33, 19);
    Screen3_ImageSizeLabel->fn->setBackgroundType(Screen3_ImageSizeLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageSizeLabel->fn->setString(Screen3_ImageSizeLabel, (leString*)&string_Size);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageSizeLabel);

    Screen3_ImageSizeUpButton = leButtonWidget_New();
    Screen3_ImageSizeUpButton->fn->setPosition(Screen3_ImageSizeUpButton, 57, 136);
    Screen3_ImageSizeUpButton->fn->setSize(Screen3_ImageSizeUpButton, 55, 30);
    Screen3_ImageSizeUpButton->fn->setBackgroundType(Screen3_ImageSizeUpButton, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageSizeUpButton->fn->setString(Screen3_ImageSizeUpButton, (leString*)&string_Plus);
    Screen3_ImageSizeUpButton->fn->setPressedEventCallback(Screen3_ImageSizeUpButton, event_Screen3_ImageSizeUpButton_OnPressed);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageSizeUpButton);

    Screen3_ImageSizeDownButton = leButtonWidget_New();
    Screen3_ImageSizeDownButton->fn->setPosition(Screen3_ImageSizeDownButton, 1, 136);
    Screen3_ImageSizeDownButton->fn->setSize(Screen3_ImageSizeDownButton, 55, 30);
    Screen3_ImageSizeDownButton->fn->setBackgroundType(Screen3_ImageSizeDownButton, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageSizeDownButton->fn->setString(Screen3_ImageSizeDownButton, (leString*)&string_Minus);
    Screen3_ImageSizeDownButton->fn->setPressedEventCallback(Screen3_ImageSizeDownButton, event_Screen3_ImageSizeDownButton_OnPressed);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageSizeDownButton);

    Screen3_ImageNextButton = leButtonWidget_New();
    Screen3_ImageNextButton->fn->setPosition(Screen3_ImageNextButton, 57, 226);
    Screen3_ImageNextButton->fn->setSize(Screen3_ImageNextButton, 55, 30);
    Screen3_ImageNextButton->fn->setBackgroundType(Screen3_ImageNextButton, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageNextButton->fn->setString(Screen3_ImageNextButton, (leString*)&string_Next);
    Screen3_ImageNextButton->fn->setPressedEventCallback(Screen3_ImageNextButton, event_Screen3_ImageNextButton_OnPressed);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageNextButton);

    Screen3_ImageContainerTitle = leLabelWidget_New();
    Screen3_ImageContainerTitle->fn->setPosition(Screen3_ImageContainerTitle, 0, 2);
    Screen3_ImageContainerTitle->fn->setSize(Screen3_ImageContainerTitle, 111, 25);
    Screen3_ImageContainerTitle->fn->setBackgroundType(Screen3_ImageContainerTitle, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageContainerTitle->fn->setHAlignment(Screen3_ImageContainerTitle, LE_HALIGN_CENTER);
    Screen3_ImageContainerTitle->fn->setString(Screen3_ImageContainerTitle, (leString*)&string_ImageRendering);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageContainerTitle);

    Screen3_ImageRefreshValue = leLabelWidget_New();
    Screen3_ImageRefreshValue->fn->setPosition(Screen3_ImageRefreshValue, 7, 89);
    Screen3_ImageRefreshValue->fn->setSize(Screen3_ImageRefreshValue, 101, 24);
    Screen3_ImageRefreshValue->fn->setBackgroundType(Screen3_ImageRefreshValue, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageRefreshValue->fn->setHAlignment(Screen3_ImageRefreshValue, LE_HALIGN_CENTER);
    Screen3_ImageRefreshValue->fn->setString(Screen3_ImageRefreshValue, (leString*)&string_NumsLittle);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageRefreshValue);

    Screen3_ImageRefreshLabel = leLabelWidget_New();
    Screen3_ImageRefreshLabel->fn->setPosition(Screen3_ImageRefreshLabel, 1, 68);
    Screen3_ImageRefreshLabel->fn->setSize(Screen3_ImageRefreshLabel, 109, 18);
    Screen3_ImageRefreshLabel->fn->setBackgroundType(Screen3_ImageRefreshLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageRefreshLabel->fn->setString(Screen3_ImageRefreshLabel, (leString*)&string_RefreshRate);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageRefreshLabel);

    Screen3_ImageUpdateLabel = leLabelWidget_New();
    Screen3_ImageUpdateLabel->fn->setPosition(Screen3_ImageUpdateLabel, 1, 22);
    Screen3_ImageUpdateLabel->fn->setSize(Screen3_ImageUpdateLabel, 110, 19);
    Screen3_ImageUpdateLabel->fn->setBackgroundType(Screen3_ImageUpdateLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen3_ImageUpdateLabel->fn->setString(Screen3_ImageUpdateLabel, (leString*)&string_FPS);
    Screen3_ImageSideContainer->fn->addChild(Screen3_ImageSideContainer, (leWidget*)Screen3_ImageUpdateLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    Screen3_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen3()
{
    Screen3_OnUpdate(); // raise event
}

void screenHide_Screen3()
{
    Screen3_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen3_ImageBackground = NULL;
    Screen3_ImageRenderArea = NULL;
    Screen3_ImageSideContainer = NULL;
    Screen3_ImageUpdateValue = NULL;
    Screen3_ImageTypeNextButton = NULL;
    Screen3_ImageTypePrevButton = NULL;
    Screen3_ImageTypeValue = NULL;
    Screen3_ImageTypeLabel = NULL;
    Screen3_ImageSizeValue = NULL;
    Screen3_ImageSizeLabel = NULL;
    Screen3_ImageSizeUpButton = NULL;
    Screen3_ImageSizeDownButton = NULL;
    Screen3_ImageNextButton = NULL;
    Screen3_ImageContainerTitle = NULL;
    Screen3_ImageRefreshValue = NULL;
    Screen3_ImageRefreshLabel = NULL;
    Screen3_ImageUpdateLabel = NULL;

    string_NumsLarge.fn->destructor(&string_NumsLarge);
    string_NumsLittle.fn->destructor(&string_NumsLittle);
    string_Size.fn->destructor(&string_Size);
    string_Next.fn->destructor(&string_Next);
    string_DynamicString.fn->destructor(&string_DynamicString);
    string_Plus.fn->destructor(&string_Plus);
    string_Minus.fn->destructor(&string_Minus);
    string_RefreshRate.fn->destructor(&string_RefreshRate);
    string_FPS.fn->destructor(&string_FPS);
    string_NumsTiny.fn->destructor(&string_NumsTiny);
    string_RectanglesNum.fn->destructor(&string_RectanglesNum);
    string_MotionUpdates.fn->destructor(&string_MotionUpdates);
    string_NextSymbol.fn->destructor(&string_NextSymbol);
    string_Previous.fn->destructor(&string_Previous);
    string_ImageType.fn->destructor(&string_ImageType);
    string_ImageRendering.fn->destructor(&string_ImageRendering);


    showing = LE_FALSE;
}

void screenDestroy_Screen3()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen3(uint32_t lyrIdx)
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

