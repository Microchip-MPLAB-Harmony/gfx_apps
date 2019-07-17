#include "gfx/legato/generated/screen/le_gen_screen_SplashScreen.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget;
leImageWidget* SplashBar;
leImageWidget* SplashMicrochipLogo;
leImageWidget* SplashPic32Logo;
leImageWidget* SplashHarmonyLogo;


static leBool showing = LE_FALSE;

leResult screenInit_SplashScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_SplashScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget = leWidget_New();
    PanelWidget->fn->setPosition(PanelWidget, 0, 0);
    PanelWidget->fn->setSize(PanelWidget, 480, 321);
    PanelWidget->fn->setScheme(PanelWidget, &whiteScheme);
    root0->fn->addChild(root0, PanelWidget);

    SplashBar = leImageWidget_New();
    SplashBar->fn->setPosition(SplashBar, 481, 255);
    SplashBar->fn->setSize(SplashBar, 480, 65);
    SplashBar->fn->setBackgroundType(SplashBar, LE_WIDGET_BACKGROUND_NONE);
    SplashBar->fn->setImage(SplashBar, &Bar);
    PanelWidget->fn->addChild(PanelWidget, (leWidget*)SplashBar);

    SplashMicrochipLogo = leImageWidget_New();
    SplashMicrochipLogo->fn->setPosition(SplashMicrochipLogo, 17, 273);
    SplashMicrochipLogo->fn->setSize(SplashMicrochipLogo, 144, 39);
    SplashMicrochipLogo->fn->setVisible(SplashMicrochipLogo, LE_FALSE);
    SplashMicrochipLogo->fn->setBackgroundType(SplashMicrochipLogo, LE_WIDGET_BACKGROUND_NONE);
    SplashMicrochipLogo->fn->setImage(SplashMicrochipLogo, &MicrochipLogo_1);
    PanelWidget->fn->addChild(PanelWidget, (leWidget*)SplashMicrochipLogo);

    SplashPic32Logo = leImageWidget_New();
    SplashPic32Logo->fn->setPosition(SplashPic32Logo, 120, 40);
    SplashPic32Logo->fn->setSize(SplashPic32Logo, 240, 139);
    SplashPic32Logo->fn->setBackgroundType(SplashPic32Logo, LE_WIDGET_BACKGROUND_NONE);
    SplashPic32Logo->fn->setImage(SplashPic32Logo, &PIC32Logo);
    root0->fn->addChild(root0, (leWidget*)SplashPic32Logo);

    SplashHarmonyLogo = leImageWidget_New();
    SplashHarmonyLogo->fn->setPosition(SplashHarmonyLogo, 120, 40);
    SplashHarmonyLogo->fn->setSize(SplashHarmonyLogo, 240, 139);
    SplashHarmonyLogo->fn->setVisible(SplashHarmonyLogo, LE_FALSE);
    SplashHarmonyLogo->fn->setScheme(SplashHarmonyLogo, &whiteScheme);
    SplashHarmonyLogo->fn->setImage(SplashHarmonyLogo, &HarmonyLogo);
    root0->fn->addChild(root0, (leWidget*)SplashHarmonyLogo);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    SplashScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_SplashScreen()
{
    SplashScreen_OnUpdate();
}

void screenHide_SplashScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget = NULL;
    SplashBar = NULL;
    SplashMicrochipLogo = NULL;
    SplashPic32Logo = NULL;
    SplashHarmonyLogo = NULL;
    showing = LE_FALSE;

    SplashScreen_OnHide();
}

void screenDestroy_SplashScreen()
{

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

