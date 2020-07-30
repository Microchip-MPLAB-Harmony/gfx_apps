#include "gfx/legato/generated/screen/le_gen_screen_Screen1.h"

// screen member widget declarations
leWidget* root0;

leWidget* Screen1_FPSBackground;
leLabelWidget* Screen1_FPSCounterValue;
leWidget* Screen1_FPSSideContainer;
leButtonWidget* Screen1_FPSUpdateValue;
leLabelWidget* Screen1_FPSUpdateLabel;
leLabelWidget* Screen1_FPSRefreshLabel;
leLabelWidget* Screen1_FPSRefreshValue;
leButtonWidget* Screen1_FPSCounterSizeDown;
leButtonWidget* Screen1_FPSCounterSizeUp;
leLabelWidget* Screen1_FPSContainerTitle;
leButtonWidget* Screen1_FPSNextButton;
leLabelWidget* Screen1_FPSStringSize;
leLabelWidget* Screen1_FPSSizeLabel;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen1()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen1()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen1_FPSBackground = leWidget_New();
    Screen1_FPSBackground->fn->setPosition(Screen1_FPSBackground, 0, 0);
    Screen1_FPSBackground->fn->setSize(Screen1_FPSBackground, 480, 272);
    Screen1_FPSBackground->fn->setScheme(Screen1_FPSBackground, &LightRedBackgroundScheme);
    root0->fn->addChild(root0, (leWidget*)Screen1_FPSBackground);

    Screen1_FPSCounterValue = leLabelWidget_New();
    Screen1_FPSCounterValue->fn->setPosition(Screen1_FPSCounterValue, 0, 70);
    Screen1_FPSCounterValue->fn->setSize(Screen1_FPSCounterValue, 353, 134);
    Screen1_FPSCounterValue->fn->setBackgroundType(Screen1_FPSCounterValue, LE_WIDGET_BACKGROUND_NONE);
    Screen1_FPSCounterValue->fn->setHAlignment(Screen1_FPSCounterValue, LE_HALIGN_CENTER);
    Screen1_FPSCounterValue->fn->setString(Screen1_FPSCounterValue, (leString*)&string_NumsLarge);
    root0->fn->addChild(root0, (leWidget*)Screen1_FPSCounterValue);

    Screen1_FPSSideContainer = leWidget_New();
    Screen1_FPSSideContainer->fn->setPosition(Screen1_FPSSideContainer, 359, 8);
    Screen1_FPSSideContainer->fn->setSize(Screen1_FPSSideContainer, 113, 260);
    Screen1_FPSSideContainer->fn->setScheme(Screen1_FPSSideContainer, &WhiteBackgroundScheme);
    Screen1_FPSSideContainer->fn->setBackgroundType(Screen1_FPSSideContainer, LE_WIDGET_BACKGROUND_NONE);
    Screen1_FPSSideContainer->fn->setBorderType(Screen1_FPSSideContainer, LE_WIDGET_BORDER_LINE);
    root0->fn->addChild(root0, (leWidget*)Screen1_FPSSideContainer);

    Screen1_FPSUpdateLabel = leLabelWidget_New();
    Screen1_FPSUpdateLabel->fn->setPosition(Screen1_FPSUpdateLabel, 1, 22);
    Screen1_FPSUpdateLabel->fn->setSize(Screen1_FPSUpdateLabel, 106, 25);
    Screen1_FPSUpdateLabel->fn->setBackgroundType(Screen1_FPSUpdateLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen1_FPSUpdateLabel->fn->setString(Screen1_FPSUpdateLabel, (leString*)&string_FPS);
    Screen1_FPSSideContainer->fn->addChild(Screen1_FPSSideContainer, (leWidget*)Screen1_FPSUpdateLabel);

    Screen1_FPSRefreshLabel = leLabelWidget_New();
    Screen1_FPSRefreshLabel->fn->setPosition(Screen1_FPSRefreshLabel, 1, 72);
    Screen1_FPSRefreshLabel->fn->setSize(Screen1_FPSRefreshLabel, 109, 23);
    Screen1_FPSRefreshLabel->fn->setBackgroundType(Screen1_FPSRefreshLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen1_FPSRefreshLabel->fn->setString(Screen1_FPSRefreshLabel, (leString*)&string_RefreshRate);
    Screen1_FPSSideContainer->fn->addChild(Screen1_FPSSideContainer, (leWidget*)Screen1_FPSRefreshLabel);

    Screen1_FPSRefreshValue = leLabelWidget_New();
    Screen1_FPSRefreshValue->fn->setPosition(Screen1_FPSRefreshValue, 4, 94);
    Screen1_FPSRefreshValue->fn->setSize(Screen1_FPSRefreshValue, 101, 28);
    Screen1_FPSRefreshValue->fn->setBackgroundType(Screen1_FPSRefreshValue, LE_WIDGET_BACKGROUND_NONE);
    Screen1_FPSRefreshValue->fn->setHAlignment(Screen1_FPSRefreshValue, LE_HALIGN_CENTER);
    Screen1_FPSRefreshValue->fn->setString(Screen1_FPSRefreshValue, (leString*)&string_NumsLittle);
    Screen1_FPSSideContainer->fn->addChild(Screen1_FPSSideContainer, (leWidget*)Screen1_FPSRefreshValue);

    Screen1_FPSCounterSizeDown = leButtonWidget_New();
    Screen1_FPSCounterSizeDown->fn->setPosition(Screen1_FPSCounterSizeDown, 1, 148);
    Screen1_FPSCounterSizeDown->fn->setSize(Screen1_FPSCounterSizeDown, 55, 30);
    Screen1_FPSCounterSizeDown->fn->setBackgroundType(Screen1_FPSCounterSizeDown, LE_WIDGET_BACKGROUND_NONE);
    Screen1_FPSCounterSizeDown->fn->setString(Screen1_FPSCounterSizeDown, (leString*)&string_Minus);
    Screen1_FPSCounterSizeDown->fn->setPressedEventCallback(Screen1_FPSCounterSizeDown, event_Screen1_FPSCounterSizeDown_OnPressed);
    Screen1_FPSSideContainer->fn->addChild(Screen1_FPSSideContainer, (leWidget*)Screen1_FPSCounterSizeDown);

    Screen1_FPSCounterSizeUp = leButtonWidget_New();
    Screen1_FPSCounterSizeUp->fn->setPosition(Screen1_FPSCounterSizeUp, 57, 148);
    Screen1_FPSCounterSizeUp->fn->setSize(Screen1_FPSCounterSizeUp, 55, 30);
    Screen1_FPSCounterSizeUp->fn->setBackgroundType(Screen1_FPSCounterSizeUp, LE_WIDGET_BACKGROUND_NONE);
    Screen1_FPSCounterSizeUp->fn->setString(Screen1_FPSCounterSizeUp, (leString*)&string_Plus);
    Screen1_FPSCounterSizeUp->fn->setPressedEventCallback(Screen1_FPSCounterSizeUp, event_Screen1_FPSCounterSizeUp_OnPressed);
    Screen1_FPSSideContainer->fn->addChild(Screen1_FPSSideContainer, (leWidget*)Screen1_FPSCounterSizeUp);

    Screen1_FPSContainerTitle = leLabelWidget_New();
    Screen1_FPSContainerTitle->fn->setPosition(Screen1_FPSContainerTitle, 2, 2);
    Screen1_FPSContainerTitle->fn->setSize(Screen1_FPSContainerTitle, 109, 25);
    Screen1_FPSContainerTitle->fn->setBackgroundType(Screen1_FPSContainerTitle, LE_WIDGET_BACKGROUND_NONE);
    Screen1_FPSContainerTitle->fn->setHAlignment(Screen1_FPSContainerTitle, LE_HALIGN_CENTER);
    Screen1_FPSContainerTitle->fn->setString(Screen1_FPSContainerTitle, (leString*)&string_DynamicString);
    Screen1_FPSSideContainer->fn->addChild(Screen1_FPSSideContainer, (leWidget*)Screen1_FPSContainerTitle);

    Screen1_FPSNextButton = leButtonWidget_New();
    Screen1_FPSNextButton->fn->setPosition(Screen1_FPSNextButton, 57, 229);
    Screen1_FPSNextButton->fn->setSize(Screen1_FPSNextButton, 55, 30);
    Screen1_FPSNextButton->fn->setBackgroundType(Screen1_FPSNextButton, LE_WIDGET_BACKGROUND_NONE);
    Screen1_FPSNextButton->fn->setString(Screen1_FPSNextButton, (leString*)&string_Next);
    Screen1_FPSNextButton->fn->setPressedEventCallback(Screen1_FPSNextButton, event_Screen1_FPSNextButton_OnPressed);
    Screen1_FPSSideContainer->fn->addChild(Screen1_FPSSideContainer, (leWidget*)Screen1_FPSNextButton);

    Screen1_FPSStringSize = leLabelWidget_New();
    Screen1_FPSStringSize->fn->setPosition(Screen1_FPSStringSize, 68, 123);
    Screen1_FPSStringSize->fn->setSize(Screen1_FPSStringSize, 24, 25);
    Screen1_FPSStringSize->fn->setBackgroundType(Screen1_FPSStringSize, LE_WIDGET_BACKGROUND_NONE);
    Screen1_FPSStringSize->fn->setHAlignment(Screen1_FPSStringSize, LE_HALIGN_CENTER);
    Screen1_FPSStringSize->fn->setString(Screen1_FPSStringSize, (leString*)&string_NumsLittle);
    Screen1_FPSSideContainer->fn->addChild(Screen1_FPSSideContainer, (leWidget*)Screen1_FPSStringSize);

    Screen1_FPSSizeLabel = leLabelWidget_New();
    Screen1_FPSSizeLabel->fn->setPosition(Screen1_FPSSizeLabel, 2, 121);
    Screen1_FPSSizeLabel->fn->setSize(Screen1_FPSSizeLabel, 64, 25);
    Screen1_FPSSizeLabel->fn->setBackgroundType(Screen1_FPSSizeLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen1_FPSSizeLabel->fn->setString(Screen1_FPSSizeLabel, (leString*)&string_Size);
    Screen1_FPSSideContainer->fn->addChild(Screen1_FPSSideContainer, (leWidget*)Screen1_FPSSizeLabel);

    Screen1_FPSUpdateValue = leButtonWidget_New();
    Screen1_FPSUpdateValue->fn->setPosition(Screen1_FPSUpdateValue, 362, 50);
    Screen1_FPSUpdateValue->fn->setSize(Screen1_FPSUpdateValue, 107, 30);
    Screen1_FPSUpdateValue->fn->setBackgroundType(Screen1_FPSUpdateValue, LE_WIDGET_BACKGROUND_NONE);
    Screen1_FPSUpdateValue->fn->setToggleable(Screen1_FPSUpdateValue, LE_TRUE);
    Screen1_FPSUpdateValue->fn->setString(Screen1_FPSUpdateValue, (leString*)&string_NumsLittle);
    root0->fn->addChild(root0, (leWidget*)Screen1_FPSUpdateValue);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    Screen1_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen1()
{
    Screen1_OnUpdate(); // raise event
}

void screenHide_Screen1()
{
    Screen1_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen1_FPSBackground = NULL;
    Screen1_FPSCounterValue = NULL;
    Screen1_FPSSideContainer = NULL;
    Screen1_FPSUpdateValue = NULL;
    Screen1_FPSUpdateLabel = NULL;
    Screen1_FPSRefreshLabel = NULL;
    Screen1_FPSRefreshValue = NULL;
    Screen1_FPSCounterSizeDown = NULL;
    Screen1_FPSCounterSizeUp = NULL;
    Screen1_FPSContainerTitle = NULL;
    Screen1_FPSNextButton = NULL;
    Screen1_FPSStringSize = NULL;
    Screen1_FPSSizeLabel = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Screen1()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen1(uint32_t lyrIdx)
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

