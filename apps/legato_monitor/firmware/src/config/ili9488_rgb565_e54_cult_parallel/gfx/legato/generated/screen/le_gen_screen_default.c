#include "gfx/legato/generated/screen/le_gen_screen_default.h"

// screen member widget declarations
leWidget* root0;

leImageWidget* default_BackgroundImage;
leLabelWidget* default_PulseLabel;
leLabelWidget* default_DiaLabel;
leLabelWidget* default_SysLabel;
leLabelWidget* default_ClockLabel;
leImageWidget* default_HeartImage;
leImageWidget* default_ImageWidget6;
leButtonWidget* default_ButtonWidget0;

// string list for this screen
static leTableString string_ClearVal;
static leTableString string_DefaultTime;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_default()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_default()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&string_ClearVal, stringID_ClearVal);
    leTableString_Constructor(&string_DefaultTime, stringID_DefaultTime);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 320, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    default_BackgroundImage = leImageWidget_New();
    default_BackgroundImage->fn->setPosition(default_BackgroundImage, 0, 0);
    default_BackgroundImage->fn->setSize(default_BackgroundImage, 320, 480);
    default_BackgroundImage->fn->setBackgroundType(default_BackgroundImage, LE_WIDGET_BACKGROUND_NONE);
    default_BackgroundImage->fn->setBorderType(default_BackgroundImage, LE_WIDGET_BORDER_NONE);
    default_BackgroundImage->fn->setImage(default_BackgroundImage, (leImage*)&Background);
    root0->fn->addChild(root0, (leWidget*)default_BackgroundImage);

    default_PulseLabel = leLabelWidget_New();
    default_PulseLabel->fn->setPosition(default_PulseLabel, 120, 355);
    default_PulseLabel->fn->setSize(default_PulseLabel, 155, 75);
    default_PulseLabel->fn->setBackgroundType(default_PulseLabel, LE_WIDGET_BACKGROUND_NONE);
    default_PulseLabel->fn->setHAlignment(default_PulseLabel, LE_HALIGN_RIGHT);
    default_PulseLabel->fn->setString(default_PulseLabel, (leString*)&string_ClearVal);
    root0->fn->addChild(root0, (leWidget*)default_PulseLabel);

    default_DiaLabel = leLabelWidget_New();
    default_DiaLabel->fn->setPosition(default_DiaLabel, 121, 225);
    default_DiaLabel->fn->setSize(default_DiaLabel, 155, 75);
    default_DiaLabel->fn->setScheme(default_DiaLabel, &HighStage2Scheme);
    default_DiaLabel->fn->setBackgroundType(default_DiaLabel, LE_WIDGET_BACKGROUND_NONE);
    default_DiaLabel->fn->setHAlignment(default_DiaLabel, LE_HALIGN_RIGHT);
    default_DiaLabel->fn->setString(default_DiaLabel, (leString*)&string_ClearVal);
    root0->fn->addChild(root0, (leWidget*)default_DiaLabel);

    default_SysLabel = leLabelWidget_New();
    default_SysLabel->fn->setPosition(default_SysLabel, 120, 96);
    default_SysLabel->fn->setSize(default_SysLabel, 155, 75);
    default_SysLabel->fn->setScheme(default_SysLabel, &HighStage2Scheme);
    default_SysLabel->fn->setBackgroundType(default_SysLabel, LE_WIDGET_BACKGROUND_NONE);
    default_SysLabel->fn->setHAlignment(default_SysLabel, LE_HALIGN_RIGHT);
    default_SysLabel->fn->setString(default_SysLabel, (leString*)&string_ClearVal);
    root0->fn->addChild(root0, (leWidget*)default_SysLabel);

    default_ClockLabel = leLabelWidget_New();
    default_ClockLabel->fn->setPosition(default_ClockLabel, 140, 30);
    default_ClockLabel->fn->setSize(default_ClockLabel, 91, 30);
    default_ClockLabel->fn->setBackgroundType(default_ClockLabel, LE_WIDGET_BACKGROUND_NONE);
    default_ClockLabel->fn->setHAlignment(default_ClockLabel, LE_HALIGN_RIGHT);
    default_ClockLabel->fn->setString(default_ClockLabel, (leString*)&string_DefaultTime);
    root0->fn->addChild(root0, (leWidget*)default_ClockLabel);

    default_HeartImage = leImageWidget_New();
    default_HeartImage->fn->setPosition(default_HeartImage, 31, 31);
    default_HeartImage->fn->setSize(default_HeartImage, 30, 30);
    default_HeartImage->fn->setBackgroundType(default_HeartImage, LE_WIDGET_BACKGROUND_NONE);
    default_HeartImage->fn->setBorderType(default_HeartImage, LE_WIDGET_BORDER_NONE);
    default_HeartImage->fn->setImage(default_HeartImage, (leImage*)&heart);
    root0->fn->addChild(root0, (leWidget*)default_HeartImage);

    default_ImageWidget6 = leImageWidget_New();
    default_ImageWidget6->fn->setPosition(default_ImageWidget6, 241, 30);
    default_ImageWidget6->fn->setSize(default_ImageWidget6, 40, 30);
    default_ImageWidget6->fn->setBackgroundType(default_ImageWidget6, LE_WIDGET_BACKGROUND_NONE);
    default_ImageWidget6->fn->setBorderType(default_ImageWidget6, LE_WIDGET_BORDER_NONE);
    default_ImageWidget6->fn->setHAlignment(default_ImageWidget6, LE_HALIGN_LEFT);
    default_ImageWidget6->fn->setMargins(default_ImageWidget6, 0, 4, 4, 4);
    default_ImageWidget6->fn->setImage(default_ImageWidget6, (leImage*)&Microchip_meatball);
    root0->fn->addChild(root0, (leWidget*)default_ImageWidget6);

    default_ButtonWidget0 = leButtonWidget_New();
    default_ButtonWidget0->fn->setPosition(default_ButtonWidget0, 0, 0);
    default_ButtonWidget0->fn->setSize(default_ButtonWidget0, 320, 480);
    default_ButtonWidget0->fn->setBackgroundType(default_ButtonWidget0, LE_WIDGET_BACKGROUND_NONE);
    default_ButtonWidget0->fn->setBorderType(default_ButtonWidget0, LE_WIDGET_BORDER_NONE);
    default_ButtonWidget0->fn->setPressedEventCallback(default_ButtonWidget0, event_default_ButtonWidget0_OnPressed);
    default_ButtonWidget0->fn->setReleasedEventCallback(default_ButtonWidget0, event_default_ButtonWidget0_OnReleased);
    root0->fn->addChild(root0, (leWidget*)default_ButtonWidget0);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    default_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_default()
{
    default_OnUpdate(); // raise event
}

void screenHide_default()
{
    default_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    default_BackgroundImage = NULL;
    default_PulseLabel = NULL;
    default_DiaLabel = NULL;
    default_SysLabel = NULL;
    default_ClockLabel = NULL;
    default_HeartImage = NULL;
    default_ImageWidget6 = NULL;
    default_ButtonWidget0 = NULL;

    string_ClearVal.fn->destructor(&string_ClearVal);
    string_DefaultTime.fn->destructor(&string_DefaultTime);


    showing = LE_FALSE;
}

void screenDestroy_default()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_default(uint32_t lyrIdx)
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

