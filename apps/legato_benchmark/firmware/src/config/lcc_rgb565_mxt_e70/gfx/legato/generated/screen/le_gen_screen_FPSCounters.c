#include "gfx/legato/generated/screen/le_gen_screen_FPSCounters.h"

// widget list for layer 0
static leWidget* root0;

leWidget* FPSBackground;
leLabelWidget* FPSCounterValue;
leWidget* FPSSideContainer;
leLabelWidget* FPSUpdateLabel;
leLabelWidget* FPSRefreshLabel;
leLabelWidget* FPSRefreshValue;
leButtonWidget* FPSCounterSizeDown;
leButtonWidget* FPSCounterSizeUp;
leLabelWidget* FPSContainerTitle;
leButtonWidget* FPSNextButton;
leLabelWidget* FPSStringSize;
leLabelWidget* FPSSizeLabel;
leButtonWidget* FPSUpdateValue;

// string list for this screen
static leTableString tableString_NumsLarge;
static leTableString tableString_FPS;
static leTableString tableString_RefreshRate;
static leTableString tableString_NumsLittle;
static leTableString tableString_Minus;
static leTableString tableString_Plus;
static leTableString tableString_DynamicString;
static leTableString tableString_Next;
static leTableString tableString_Size;

static leBool showing = LE_FALSE;

leResult screenInit_FPSCounters()
{
    return LE_SUCCESS;
}

leResult screenShow_FPSCounters()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_NumsLarge, string_NumsLarge);
    leTableString_Constructor(&tableString_FPS, string_FPS);
    leTableString_Constructor(&tableString_RefreshRate, string_RefreshRate);
    leTableString_Constructor(&tableString_NumsLittle, string_NumsLittle);
    leTableString_Constructor(&tableString_Minus, string_Minus);
    leTableString_Constructor(&tableString_Plus, string_Plus);
    leTableString_Constructor(&tableString_DynamicString, string_DynamicString);
    leTableString_Constructor(&tableString_Next, string_Next);
    leTableString_Constructor(&tableString_Size, string_Size);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    FPSBackground = leWidget_New();
    FPSBackground->fn->setPosition(FPSBackground, 0, 0);
    FPSBackground->fn->setSize(FPSBackground, 480, 272);
    FPSBackground->fn->setScheme(FPSBackground, &LightRedBackgroundScheme);
    root0->fn->addChild(root0, FPSBackground);

    FPSCounterValue = leLabelWidget_New();
    FPSCounterValue->fn->setPosition(FPSCounterValue, 0, 70);
    FPSCounterValue->fn->setSize(FPSCounterValue, 353, 134);
    FPSCounterValue->fn->setBackgroundType(FPSCounterValue, LE_WIDGET_BACKGROUND_NONE);
    FPSCounterValue->fn->setHAlignment(FPSCounterValue, LE_HALIGN_CENTER);
    FPSCounterValue->fn->setString(FPSCounterValue, (leString*)&tableString_NumsLarge);
    root0->fn->addChild(root0, (leWidget*)FPSCounterValue);

    FPSSideContainer = leWidget_New();
    FPSSideContainer->fn->setPosition(FPSSideContainer, 359, 8);
    FPSSideContainer->fn->setSize(FPSSideContainer, 113, 260);
    FPSSideContainer->fn->setScheme(FPSSideContainer, &WhiteBackgroundScheme);
    FPSSideContainer->fn->setBackgroundType(FPSSideContainer, LE_WIDGET_BACKGROUND_NONE);
    FPSSideContainer->fn->setBorderType(FPSSideContainer, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, FPSSideContainer);

    FPSUpdateLabel = leLabelWidget_New();
    FPSUpdateLabel->fn->setPosition(FPSUpdateLabel, 1, 22);
    FPSUpdateLabel->fn->setSize(FPSUpdateLabel, 106, 25);
    FPSUpdateLabel->fn->setBackgroundType(FPSUpdateLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSUpdateLabel->fn->setString(FPSUpdateLabel, (leString*)&tableString_FPS);
    FPSSideContainer->fn->addChild(FPSSideContainer, (leWidget*)FPSUpdateLabel);

    FPSRefreshLabel = leLabelWidget_New();
    FPSRefreshLabel->fn->setPosition(FPSRefreshLabel, 1, 72);
    FPSRefreshLabel->fn->setSize(FPSRefreshLabel, 109, 23);
    FPSRefreshLabel->fn->setBackgroundType(FPSRefreshLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSRefreshLabel->fn->setString(FPSRefreshLabel, (leString*)&tableString_RefreshRate);
    FPSSideContainer->fn->addChild(FPSSideContainer, (leWidget*)FPSRefreshLabel);

    FPSRefreshValue = leLabelWidget_New();
    FPSRefreshValue->fn->setPosition(FPSRefreshValue, 4, 94);
    FPSRefreshValue->fn->setSize(FPSRefreshValue, 101, 28);
    FPSRefreshValue->fn->setBackgroundType(FPSRefreshValue, LE_WIDGET_BACKGROUND_NONE);
    FPSRefreshValue->fn->setHAlignment(FPSRefreshValue, LE_HALIGN_CENTER);
    FPSRefreshValue->fn->setString(FPSRefreshValue, (leString*)&tableString_NumsLittle);
    FPSSideContainer->fn->addChild(FPSSideContainer, (leWidget*)FPSRefreshValue);

    FPSCounterSizeDown = leButtonWidget_New();
    FPSCounterSizeDown->fn->setPosition(FPSCounterSizeDown, 1, 148);
    FPSCounterSizeDown->fn->setSize(FPSCounterSizeDown, 55, 30);
    FPSCounterSizeDown->fn->setBackgroundType(FPSCounterSizeDown, LE_WIDGET_BACKGROUND_NONE);
    FPSCounterSizeDown->fn->setString(FPSCounterSizeDown, (leString*)&tableString_Minus);
    FPSCounterSizeDown->fn->setPressedEventCallback(FPSCounterSizeDown, FPSCounterSizeDown_OnPressed);
    FPSSideContainer->fn->addChild(FPSSideContainer, (leWidget*)FPSCounterSizeDown);

    FPSCounterSizeUp = leButtonWidget_New();
    FPSCounterSizeUp->fn->setPosition(FPSCounterSizeUp, 57, 148);
    FPSCounterSizeUp->fn->setSize(FPSCounterSizeUp, 55, 30);
    FPSCounterSizeUp->fn->setBackgroundType(FPSCounterSizeUp, LE_WIDGET_BACKGROUND_NONE);
    FPSCounterSizeUp->fn->setString(FPSCounterSizeUp, (leString*)&tableString_Plus);
    FPSCounterSizeUp->fn->setPressedEventCallback(FPSCounterSizeUp, FPSCounterSizeUp_OnPressed);
    FPSSideContainer->fn->addChild(FPSSideContainer, (leWidget*)FPSCounterSizeUp);

    FPSContainerTitle = leLabelWidget_New();
    FPSContainerTitle->fn->setPosition(FPSContainerTitle, 2, 2);
    FPSContainerTitle->fn->setSize(FPSContainerTitle, 109, 25);
    FPSContainerTitle->fn->setBackgroundType(FPSContainerTitle, LE_WIDGET_BACKGROUND_NONE);
    FPSContainerTitle->fn->setHAlignment(FPSContainerTitle, LE_HALIGN_CENTER);
    FPSContainerTitle->fn->setString(FPSContainerTitle, (leString*)&tableString_DynamicString);
    FPSSideContainer->fn->addChild(FPSSideContainer, (leWidget*)FPSContainerTitle);

    FPSNextButton = leButtonWidget_New();
    FPSNextButton->fn->setPosition(FPSNextButton, 57, 229);
    FPSNextButton->fn->setSize(FPSNextButton, 55, 30);
    FPSNextButton->fn->setBackgroundType(FPSNextButton, LE_WIDGET_BACKGROUND_NONE);
    FPSNextButton->fn->setString(FPSNextButton, (leString*)&tableString_Next);
    FPSNextButton->fn->setPressedEventCallback(FPSNextButton, FPSNextButton_OnPressed);
    FPSSideContainer->fn->addChild(FPSSideContainer, (leWidget*)FPSNextButton);

    FPSStringSize = leLabelWidget_New();
    FPSStringSize->fn->setPosition(FPSStringSize, 68, 123);
    FPSStringSize->fn->setSize(FPSStringSize, 24, 25);
    FPSStringSize->fn->setBackgroundType(FPSStringSize, LE_WIDGET_BACKGROUND_NONE);
    FPSStringSize->fn->setHAlignment(FPSStringSize, LE_HALIGN_CENTER);
    FPSStringSize->fn->setString(FPSStringSize, (leString*)&tableString_NumsLittle);
    FPSSideContainer->fn->addChild(FPSSideContainer, (leWidget*)FPSStringSize);

    FPSSizeLabel = leLabelWidget_New();
    FPSSizeLabel->fn->setPosition(FPSSizeLabel, 2, 121);
    FPSSizeLabel->fn->setSize(FPSSizeLabel, 64, 25);
    FPSSizeLabel->fn->setBackgroundType(FPSSizeLabel, LE_WIDGET_BACKGROUND_NONE);
    FPSSizeLabel->fn->setString(FPSSizeLabel, (leString*)&tableString_Size);
    FPSSideContainer->fn->addChild(FPSSideContainer, (leWidget*)FPSSizeLabel);

    FPSUpdateValue = leButtonWidget_New();
    FPSUpdateValue->fn->setPosition(FPSUpdateValue, 362, 50);
    FPSUpdateValue->fn->setSize(FPSUpdateValue, 107, 30);
    FPSUpdateValue->fn->setBackgroundType(FPSUpdateValue, LE_WIDGET_BACKGROUND_NONE);
    FPSUpdateValue->fn->setToggleable(FPSUpdateValue, LE_TRUE);
    FPSUpdateValue->fn->setString(FPSUpdateValue, (leString*)&tableString_NumsLittle);
    root0->fn->addChild(root0, (leWidget*)FPSUpdateValue);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    FPSCounters_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_FPSCounters()
{
    FPSCounters_OnUpdate();
}

void screenHide_FPSCounters()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    FPSBackground = NULL;
    FPSCounterValue = NULL;
    FPSSideContainer = NULL;
    FPSUpdateLabel = NULL;
    FPSRefreshLabel = NULL;
    FPSRefreshValue = NULL;
    FPSCounterSizeDown = NULL;
    FPSCounterSizeUp = NULL;
    FPSContainerTitle = NULL;
    FPSNextButton = NULL;
    FPSStringSize = NULL;
    FPSSizeLabel = NULL;
    FPSUpdateValue = NULL;

    tableString_NumsLarge.fn->destructor(&tableString_NumsLarge);
    tableString_FPS.fn->destructor(&tableString_FPS);
    tableString_RefreshRate.fn->destructor(&tableString_RefreshRate);
    tableString_NumsLittle.fn->destructor(&tableString_NumsLittle);
    tableString_Minus.fn->destructor(&tableString_Minus);
    tableString_Plus.fn->destructor(&tableString_Plus);
    tableString_DynamicString.fn->destructor(&tableString_DynamicString);
    tableString_Next.fn->destructor(&tableString_Next);
    tableString_Size.fn->destructor(&tableString_Size);
    showing = LE_FALSE;

    FPSCounters_OnHide();
}

void screenDestroy_FPSCounters()
{

}

leWidget* screenGetRoot_FPSCounters(uint32_t lyrIdx)
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

