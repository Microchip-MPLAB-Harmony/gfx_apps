#include "gfx/legato/generated/screen/le_gen_screen_default.h"

// widget list for layer 0
static leWidget* root0;

leWidget* Background;
leWidget* SysValue;
leLabelWidget* SysValue1;
leLabelWidget* SysValue10;
leLabelWidget* SysValue100;
leWidget* DiaValue;
leLabelWidget* DiaValue1;
leLabelWidget* DiaValue10;
leLabelWidget* DiaValue100;
leWidget* PulseValue;
leLabelWidget* PulseValue1;
leLabelWidget* PulseValue10;
leLabelWidget* PulseValue100;
leLabelWidget* DateLabel;
leImageWidget* HeartImage;
leLineWidget* LineWidget18;
leImageWidget* ImageWidget21;
leLineWidget* LineWidget22;
leLineWidget* LineWidget23;
leLineWidget* LineWidget24;
leLineWidget* LineWidget25;
leLineWidget* LineWidget26;
leImageWidget* MicrochipLogo;
leImageWidget* SideBar;

// string list for this screen
static leTableString tableString_SysDefaultValue;
static leTableString tableString_Date;

static leBool showing = LE_FALSE;

leResult screenInit_default()
{
    return LE_SUCCESS;
}

leResult screenShow_default()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_SysDefaultValue, string_SysDefaultValue);
    leTableString_Constructor(&tableString_Date, string_Date);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 320, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    Background = leWidget_New();
    Background->fn->setPosition(Background, 0, 0);
    Background->fn->setSize(Background, 320, 480);
    Background->fn->setScheme(Background, &defaultScheme);
    root0->fn->addChild(root0, Background);

    SysValue = leWidget_New();
    SysValue->fn->setPosition(SysValue, 140, 45);
    SysValue->fn->setSize(SysValue, 160, 95);
    SysValue->fn->setBackgroundType(SysValue, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, SysValue);

    SysValue1 = leLabelWidget_New();
    SysValue1->fn->setPosition(SysValue1, 111, 9);
    SysValue1->fn->setSize(SysValue1, 45, 86);
    SysValue1->fn->setBackgroundType(SysValue1, LE_WIDGET_BACKGROUND_NONE);
    SysValue1->fn->setString(SysValue1, (leString*)&tableString_SysDefaultValue);
    SysValue->fn->addChild(SysValue, (leWidget*)SysValue1);

    SysValue10 = leLabelWidget_New();
    SysValue10->fn->setPosition(SysValue10, 61, 9);
    SysValue10->fn->setSize(SysValue10, 46, 87);
    SysValue10->fn->setBackgroundType(SysValue10, LE_WIDGET_BACKGROUND_NONE);
    SysValue10->fn->setString(SysValue10, (leString*)&tableString_SysDefaultValue);
    SysValue->fn->addChild(SysValue, (leWidget*)SysValue10);

    SysValue100 = leLabelWidget_New();
    SysValue100->fn->setPosition(SysValue100, 13, 9);
    SysValue100->fn->setSize(SysValue100, 45, 87);
    SysValue100->fn->setBackgroundType(SysValue100, LE_WIDGET_BACKGROUND_NONE);
    SysValue100->fn->setString(SysValue100, (leString*)&tableString_SysDefaultValue);
    SysValue->fn->addChild(SysValue, (leWidget*)SysValue100);

    DiaValue = leWidget_New();
    DiaValue->fn->setPosition(DiaValue, 144, 180);
    DiaValue->fn->setSize(DiaValue, 160, 95);
    DiaValue->fn->setBackgroundType(DiaValue, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, DiaValue);

    DiaValue1 = leLabelWidget_New();
    DiaValue1->fn->setPosition(DiaValue1, 111, 9);
    DiaValue1->fn->setSize(DiaValue1, 45, 86);
    DiaValue1->fn->setBackgroundType(DiaValue1, LE_WIDGET_BACKGROUND_NONE);
    DiaValue1->fn->setString(DiaValue1, (leString*)&tableString_SysDefaultValue);
    DiaValue->fn->addChild(DiaValue, (leWidget*)DiaValue1);

    DiaValue10 = leLabelWidget_New();
    DiaValue10->fn->setPosition(DiaValue10, 61, 9);
    DiaValue10->fn->setSize(DiaValue10, 46, 87);
    DiaValue10->fn->setBackgroundType(DiaValue10, LE_WIDGET_BACKGROUND_NONE);
    DiaValue10->fn->setString(DiaValue10, (leString*)&tableString_SysDefaultValue);
    DiaValue->fn->addChild(DiaValue, (leWidget*)DiaValue10);

    DiaValue100 = leLabelWidget_New();
    DiaValue100->fn->setPosition(DiaValue100, 13, 9);
    DiaValue100->fn->setSize(DiaValue100, 45, 87);
    DiaValue100->fn->setBackgroundType(DiaValue100, LE_WIDGET_BACKGROUND_NONE);
    DiaValue100->fn->setString(DiaValue100, (leString*)&tableString_SysDefaultValue);
    DiaValue->fn->addChild(DiaValue, (leWidget*)DiaValue100);

    PulseValue = leWidget_New();
    PulseValue->fn->setPosition(PulseValue, 147, 307);
    PulseValue->fn->setSize(PulseValue, 160, 95);
    PulseValue->fn->setBackgroundType(PulseValue, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, PulseValue);

    PulseValue1 = leLabelWidget_New();
    PulseValue1->fn->setPosition(PulseValue1, 111, 9);
    PulseValue1->fn->setSize(PulseValue1, 45, 86);
    PulseValue1->fn->setBackgroundType(PulseValue1, LE_WIDGET_BACKGROUND_NONE);
    PulseValue1->fn->setString(PulseValue1, (leString*)&tableString_SysDefaultValue);
    PulseValue->fn->addChild(PulseValue, (leWidget*)PulseValue1);

    PulseValue10 = leLabelWidget_New();
    PulseValue10->fn->setPosition(PulseValue10, 61, 9);
    PulseValue10->fn->setSize(PulseValue10, 46, 87);
    PulseValue10->fn->setBackgroundType(PulseValue10, LE_WIDGET_BACKGROUND_NONE);
    PulseValue10->fn->setString(PulseValue10, (leString*)&tableString_SysDefaultValue);
    PulseValue->fn->addChild(PulseValue, (leWidget*)PulseValue10);

    PulseValue100 = leLabelWidget_New();
    PulseValue100->fn->setPosition(PulseValue100, 13, 9);
    PulseValue100->fn->setSize(PulseValue100, 45, 87);
    PulseValue100->fn->setBackgroundType(PulseValue100, LE_WIDGET_BACKGROUND_NONE);
    PulseValue100->fn->setString(PulseValue100, (leString*)&tableString_SysDefaultValue);
    PulseValue->fn->addChild(PulseValue, (leWidget*)PulseValue100);

    DateLabel = leLabelWidget_New();
    DateLabel->fn->setPosition(DateLabel, 180, 8);
    DateLabel->fn->setSize(DateLabel, 132, 25);
    DateLabel->fn->setBackgroundType(DateLabel, LE_WIDGET_BACKGROUND_NONE);
    DateLabel->fn->setString(DateLabel, (leString*)&tableString_Date);
    root0->fn->addChild(root0, (leWidget*)DateLabel);

    HeartImage = leImageWidget_New();
    HeartImage->fn->setPosition(HeartImage, 279, 441);
    HeartImage->fn->setSize(HeartImage, 29, 25);
    HeartImage->fn->setBackgroundType(HeartImage, LE_WIDGET_BACKGROUND_NONE);
    HeartImage->fn->setImage(HeartImage, &_1200px_Heart_coraz_n);
    root0->fn->addChild(root0, (leWidget*)HeartImage);

    LineWidget18 = leLineWidget_New();
    LineWidget18->fn->setPosition(LineWidget18, 111, 41);
    LineWidget18->fn->setSize(LineWidget18, 10, 400);
    LineWidget18->fn->setStartPoint(LineWidget18, 5, 0);
    LineWidget18->fn->setEndPoint(LineWidget18, 5, 400);
    root0->fn->addChild(root0, (leWidget*)LineWidget18);

    ImageWidget21 = leImageWidget_New();
    ImageWidget21->fn->setPosition(ImageWidget21, 28, 445);
    ImageWidget21->fn->setSize(ImageWidget21, 63, 26);
    ImageWidget21->fn->setBackgroundType(ImageWidget21, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget21->fn->setImage(ImageWidget21, &Battery);
    root0->fn->addChild(root0, (leWidget*)ImageWidget21);

    LineWidget22 = leLineWidget_New();
    LineWidget22->fn->setPosition(LineWidget22, 50, 150);
    LineWidget22->fn->setSize(LineWidget22, 270, 10);
    LineWidget22->fn->setStartPoint(LineWidget22, 0, 5);
    LineWidget22->fn->setEndPoint(LineWidget22, 270, 5);
    root0->fn->addChild(root0, (leWidget*)LineWidget22);

    LineWidget23 = leLineWidget_New();
    LineWidget23->fn->setPosition(LineWidget23, 80, 280);
    LineWidget23->fn->setSize(LineWidget23, 240, 10);
    LineWidget23->fn->setStartPoint(LineWidget23, 0, 5);
    LineWidget23->fn->setEndPoint(LineWidget23, 240, 5);
    root0->fn->addChild(root0, (leWidget*)LineWidget23);

    LineWidget24 = leLineWidget_New();
    LineWidget24->fn->setPosition(LineWidget24, 110, 410);
    LineWidget24->fn->setSize(LineWidget24, 210, 10);
    LineWidget24->fn->setStartPoint(LineWidget24, 0, 5);
    LineWidget24->fn->setEndPoint(LineWidget24, 210, 5);
    root0->fn->addChild(root0, (leWidget*)LineWidget24);

    LineWidget25 = leLineWidget_New();
    LineWidget25->fn->setPosition(LineWidget25, 0, 36);
    LineWidget25->fn->setSize(LineWidget25, 320, 10);
    LineWidget25->fn->setStartPoint(LineWidget25, 0, 5);
    LineWidget25->fn->setEndPoint(LineWidget25, 320, 5);
    root0->fn->addChild(root0, (leWidget*)LineWidget25);

    LineWidget26 = leLineWidget_New();
    LineWidget26->fn->setPosition(LineWidget26, 0, -2);
    LineWidget26->fn->setSize(LineWidget26, 320, 10);
    LineWidget26->fn->setStartPoint(LineWidget26, 0, 5);
    LineWidget26->fn->setEndPoint(LineWidget26, 320, 5);
    root0->fn->addChild(root0, (leWidget*)LineWidget26);

    MicrochipLogo = leImageWidget_New();
    MicrochipLogo->fn->setPosition(MicrochipLogo, 10, 12);
    MicrochipLogo->fn->setSize(MicrochipLogo, 110, 24);
    MicrochipLogo->fn->setBackgroundType(MicrochipLogo, LE_WIDGET_BACKGROUND_NONE);
    MicrochipLogo->fn->setImage(MicrochipLogo, &Microchip_logo);
    root0->fn->addChild(root0, (leWidget*)MicrochipLogo);

    SideBar = leImageWidget_New();
    SideBar->fn->setPosition(SideBar, 11, 42);
    SideBar->fn->setSize(SideBar, 105, 397);
    SideBar->fn->setBackgroundType(SideBar, LE_WIDGET_BACKGROUND_NONE);
    SideBar->fn->setImage(SideBar, &BannerLeft);
    root0->fn->addChild(root0, (leWidget*)SideBar);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    default_OnShow();
    return LE_SUCCESS;
}

void screenUpdate_default()
{
    default_OnUpdate();
}

void screenHide_default()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;
    Background = NULL;
    SysValue = NULL;
    SysValue1 = NULL;
    SysValue10 = NULL;
    SysValue100 = NULL;
    DiaValue = NULL;
    DiaValue1 = NULL;
    DiaValue10 = NULL;
    DiaValue100 = NULL;
    PulseValue = NULL;
    PulseValue1 = NULL;
    PulseValue10 = NULL;
    PulseValue100 = NULL;
    DateLabel = NULL;
    HeartImage = NULL;
    LineWidget18 = NULL;
    ImageWidget21 = NULL;
    LineWidget22 = NULL;
    LineWidget23 = NULL;
    LineWidget24 = NULL;
    LineWidget25 = NULL;
    LineWidget26 = NULL;
    MicrochipLogo = NULL;
    SideBar = NULL;

    tableString_SysDefaultValue.fn->destructor(&tableString_SysDefaultValue);
    tableString_Date.fn->destructor(&tableString_Date);

    showing = LE_FALSE;

    default_OnHide();
}

void screenDestroy_default()
{

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

