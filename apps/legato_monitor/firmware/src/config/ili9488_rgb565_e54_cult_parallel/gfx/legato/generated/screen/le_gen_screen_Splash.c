#include "gfx/legato/generated/screen/le_gen_screen_Splash.h"

// screen member widget declarations
leWidget* root0;

leWidget* Splash_PanelWidget0;
leImageWidget* Splash_MHGCImageWidget;
leImageWidget* Splash_BarImageWidget;
leImageWidget* Splash_MicrochipLogoImageWidget;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Splash()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Splash()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 320, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Splash_PanelWidget0 = leWidget_New();
    Splash_PanelWidget0->fn->setPosition(Splash_PanelWidget0, 0, 0);
    Splash_PanelWidget0->fn->setSize(Splash_PanelWidget0, 320, 480);
    Splash_PanelWidget0->fn->setScheme(Splash_PanelWidget0, &defaultScheme);
    root0->fn->addChild(root0, (leWidget*)Splash_PanelWidget0);

    Splash_MHGCImageWidget = leImageWidget_New();
    Splash_MHGCImageWidget->fn->setPosition(Splash_MHGCImageWidget, 76, 90);
    Splash_MHGCImageWidget->fn->setSize(Splash_MHGCImageWidget, 176, 170);
    Splash_MHGCImageWidget->fn->setScheme(Splash_MHGCImageWidget, &defaultScheme);
    Splash_MHGCImageWidget->fn->setBorderType(Splash_MHGCImageWidget, LE_WIDGET_BORDER_NONE);
    Splash_MHGCImageWidget->fn->setImage(Splash_MHGCImageWidget, (leImage*)&MHGC_170x170);
    root0->fn->addChild(root0, (leWidget*)Splash_MHGCImageWidget);

    Splash_BarImageWidget = leImageWidget_New();
    Splash_BarImageWidget->fn->setPosition(Splash_BarImageWidget, 320, 416);
    Splash_BarImageWidget->fn->setSize(Splash_BarImageWidget, 320, 65);
    Splash_BarImageWidget->fn->setBackgroundType(Splash_BarImageWidget, LE_WIDGET_BACKGROUND_NONE);
    Splash_BarImageWidget->fn->setBorderType(Splash_BarImageWidget, LE_WIDGET_BORDER_NONE);
    Splash_BarImageWidget->fn->setImage(Splash_BarImageWidget, (leImage*)&Bar_320);
    root0->fn->addChild(root0, (leWidget*)Splash_BarImageWidget);

    Splash_MicrochipLogoImageWidget = leImageWidget_New();
    Splash_MicrochipLogoImageWidget->fn->setPosition(Splash_MicrochipLogoImageWidget, 9, 430);
    Splash_MicrochipLogoImageWidget->fn->setSize(Splash_MicrochipLogoImageWidget, 145, 40);
    Splash_MicrochipLogoImageWidget->fn->setVisible(Splash_MicrochipLogoImageWidget, LE_FALSE);
    Splash_MicrochipLogoImageWidget->fn->setBackgroundType(Splash_MicrochipLogoImageWidget, LE_WIDGET_BACKGROUND_NONE);
    Splash_MicrochipLogoImageWidget->fn->setBorderType(Splash_MicrochipLogoImageWidget, LE_WIDGET_BORDER_NONE);
    Splash_MicrochipLogoImageWidget->fn->setImage(Splash_MicrochipLogoImageWidget, (leImage*)&MicrochipLogo);
    root0->fn->addChild(root0, (leWidget*)Splash_MicrochipLogoImageWidget);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    Splash_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Splash()
{
    Splash_OnUpdate(); // raise event
}

void screenHide_Splash()
{
    Splash_OnHide(); // raise event


    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Splash_PanelWidget0 = NULL;
    Splash_MHGCImageWidget = NULL;
    Splash_BarImageWidget = NULL;
    Splash_MicrochipLogoImageWidget = NULL;


    showing = LE_FALSE;
}

void screenDestroy_Splash()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
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

