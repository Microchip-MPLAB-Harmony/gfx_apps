#include "gfx/legato/generated/screen/le_gen_screen_Splash.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget0;
leImageWidget* MHGCImageWidget;
leImageWidget* BarImageWidget;
leImageWidget* MicrochipLogoImageWidget;


static leBool showing = LE_FALSE;

leResult screenInit_Splash()
{
    return LE_SUCCESS;
}

leResult screenShow_Splash()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 320, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget0 = leWidget_New();
    PanelWidget0->fn->setPosition(PanelWidget0, 0, 0);
    PanelWidget0->fn->setSize(PanelWidget0, 320, 480);
    PanelWidget0->fn->setScheme(PanelWidget0, &defaultScheme);
    root0->fn->addChild(root0, PanelWidget0);

    MHGCImageWidget = leImageWidget_New();
    MHGCImageWidget->fn->setPosition(MHGCImageWidget, 76, 90);
    MHGCImageWidget->fn->setSize(MHGCImageWidget, 176, 170);
    MHGCImageWidget->fn->setScheme(MHGCImageWidget, &defaultScheme);
    MHGCImageWidget->fn->setImage(MHGCImageWidget, &MHGC_170x170);
    root0->fn->addChild(root0, (leWidget*)MHGCImageWidget);

    BarImageWidget = leImageWidget_New();
    BarImageWidget->fn->setPosition(BarImageWidget, 320, 416);
    BarImageWidget->fn->setSize(BarImageWidget, 320, 65);
    BarImageWidget->fn->setBackgroundType(BarImageWidget, LE_WIDGET_BACKGROUND_NONE);
    BarImageWidget->fn->setImage(BarImageWidget, &Bar_320);
    root0->fn->addChild(root0, (leWidget*)BarImageWidget);

    MicrochipLogoImageWidget = leImageWidget_New();
    MicrochipLogoImageWidget->fn->setPosition(MicrochipLogoImageWidget, 9, 430);
    MicrochipLogoImageWidget->fn->setSize(MicrochipLogoImageWidget, 145, 40);
    MicrochipLogoImageWidget->fn->setVisible(MicrochipLogoImageWidget, LE_FALSE);
    MicrochipLogoImageWidget->fn->setBackgroundType(MicrochipLogoImageWidget, LE_WIDGET_BACKGROUND_NONE);
    MicrochipLogoImageWidget->fn->setImage(MicrochipLogoImageWidget, &MicrochipLogo);
    root0->fn->addChild(root0, (leWidget*)MicrochipLogoImageWidget);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    Splash_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_Splash()
{
    Splash_OnUpdate();
}

void screenHide_Splash()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget0 = NULL;
    MHGCImageWidget = NULL;
    BarImageWidget = NULL;
    MicrochipLogoImageWidget = NULL;
    showing = LE_FALSE;

    Splash_OnHide();
}

void screenDestroy_Splash()
{

}

leWidget* screenGetRoot_Splash(uint32_t lyrIdx)
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

