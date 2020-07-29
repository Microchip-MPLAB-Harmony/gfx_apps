#include "gfx/legato/generated/screen/le_gen_screen_SplashScreen.h"

// screen member widget declarations
leWidget* root0;

leWidget* SplashScreen_PanelWidget;
leImageWidget* SplashScreen_SplashPic32Logo;
leImageWidget* SplashScreen_SplashHarmonyLogo;
leImageWidget* SplashScreen_SplashBar;
leImageWidget* SplashScreen_SplashMicrochipLogo;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_SplashScreen()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_SplashScreen()
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

    SplashScreen_PanelWidget = leWidget_New();
    SplashScreen_PanelWidget->fn->setPosition(SplashScreen_PanelWidget, 0, 0);
    SplashScreen_PanelWidget->fn->setSize(SplashScreen_PanelWidget, 480, 321);
    SplashScreen_PanelWidget->fn->setScheme(SplashScreen_PanelWidget, &whiteScheme);
    root0->fn->addChild(root0, (leWidget*)SplashScreen_PanelWidget);

    SplashScreen_SplashBar = leImageWidget_New();
    SplashScreen_SplashBar->fn->setPosition(SplashScreen_SplashBar, 481, 255);
    SplashScreen_SplashBar->fn->setSize(SplashScreen_SplashBar, 480, 65);
    SplashScreen_SplashBar->fn->setBackgroundType(SplashScreen_SplashBar, LE_WIDGET_BACKGROUND_NONE);
    SplashScreen_SplashBar->fn->setBorderType(SplashScreen_SplashBar, LE_WIDGET_BORDER_NONE);
    SplashScreen_SplashBar->fn->setImage(SplashScreen_SplashBar, (leImage*)&Bar);
    SplashScreen_PanelWidget->fn->addChild(SplashScreen_PanelWidget, (leWidget*)SplashScreen_SplashBar);

    SplashScreen_SplashMicrochipLogo = leImageWidget_New();
    SplashScreen_SplashMicrochipLogo->fn->setPosition(SplashScreen_SplashMicrochipLogo, 17, 273);
    SplashScreen_SplashMicrochipLogo->fn->setSize(SplashScreen_SplashMicrochipLogo, 144, 39);
    SplashScreen_SplashMicrochipLogo->fn->setVisible(SplashScreen_SplashMicrochipLogo, LE_FALSE);
    SplashScreen_SplashMicrochipLogo->fn->setBackgroundType(SplashScreen_SplashMicrochipLogo, LE_WIDGET_BACKGROUND_NONE);
    SplashScreen_SplashMicrochipLogo->fn->setBorderType(SplashScreen_SplashMicrochipLogo, LE_WIDGET_BORDER_NONE);
    SplashScreen_SplashMicrochipLogo->fn->setImage(SplashScreen_SplashMicrochipLogo, (leImage*)&MicrochipLogo_1);
    SplashScreen_PanelWidget->fn->addChild(SplashScreen_PanelWidget, (leWidget*)SplashScreen_SplashMicrochipLogo);

    SplashScreen_SplashPic32Logo = leImageWidget_New();
    SplashScreen_SplashPic32Logo->fn->setPosition(SplashScreen_SplashPic32Logo, 120, 40);
    SplashScreen_SplashPic32Logo->fn->setSize(SplashScreen_SplashPic32Logo, 240, 139);
    SplashScreen_SplashPic32Logo->fn->setBackgroundType(SplashScreen_SplashPic32Logo, LE_WIDGET_BACKGROUND_NONE);
    SplashScreen_SplashPic32Logo->fn->setBorderType(SplashScreen_SplashPic32Logo, LE_WIDGET_BORDER_NONE);
    SplashScreen_SplashPic32Logo->fn->setImage(SplashScreen_SplashPic32Logo, (leImage*)&PIC32Logo);
    root0->fn->addChild(root0, (leWidget*)SplashScreen_SplashPic32Logo);

    SplashScreen_SplashHarmonyLogo = leImageWidget_New();
    SplashScreen_SplashHarmonyLogo->fn->setPosition(SplashScreen_SplashHarmonyLogo, 120, 40);
    SplashScreen_SplashHarmonyLogo->fn->setSize(SplashScreen_SplashHarmonyLogo, 240, 139);
    SplashScreen_SplashHarmonyLogo->fn->setVisible(SplashScreen_SplashHarmonyLogo, LE_FALSE);
    SplashScreen_SplashHarmonyLogo->fn->setScheme(SplashScreen_SplashHarmonyLogo, &whiteScheme);
    SplashScreen_SplashHarmonyLogo->fn->setBorderType(SplashScreen_SplashHarmonyLogo, LE_WIDGET_BORDER_NONE);
    SplashScreen_SplashHarmonyLogo->fn->setImage(SplashScreen_SplashHarmonyLogo, (leImage*)&HarmonyLogo);
    root0->fn->addChild(root0, (leWidget*)SplashScreen_SplashHarmonyLogo);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    SplashScreen_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_SplashScreen()
{
    SplashScreen_OnUpdate(); // raise event
}

void screenHide_SplashScreen()
{
    SplashScreen_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    SplashScreen_PanelWidget = NULL;
    SplashScreen_SplashPic32Logo = NULL;
    SplashScreen_SplashHarmonyLogo = NULL;
    SplashScreen_SplashBar = NULL;
    SplashScreen_SplashMicrochipLogo = NULL;


    showing = LE_FALSE;
}

void screenDestroy_SplashScreen()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_SplashScreen(uint32_t lyrIdx)
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

