#include "gfx/legato/generated/screen/le_gen_screen_MainScreen.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelBackground;
leImageWidget* ImageWidget0;
leWidget* PositionWidget;
leImageSequenceWidget* ImageSequenceWidget_JumpRight;
leImageSequenceWidget* ImageSequenceWidget_RunRight;
leImageSequenceWidget* ImageSequenceWidget_RunLeft;
leImageSequenceWidget* ImageSequenceWidget_IdleRight;
leImageSequenceWidget* ImageSequenceWidget_IdleLeft;
leImageSequenceWidget* ImageSequenceWidget_DizzieRight;
leImageSequenceWidget* ImageSequenceWidget_DizzieLeft;
leButtonWidget* ButtonWidget_RunLeft;
leButtonWidget* ButtonWidget_RunRight;
leButtonWidget* ButtonWidget_Jump;
leButtonWidget* ButtonWidget_ScreenChange;


// event handlers
static void ButtonWidget_ScreenChange_OnReleased(leButtonWidget* btn)
;


static leBool showing = LE_FALSE;

leResult screenInit_MainScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_MainScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelBackground = leWidget_New();
    PanelBackground->fn->setPosition(PanelBackground, 0, 0);
    PanelBackground->fn->setSize(PanelBackground, 480, 320);
    PanelBackground->fn->setScheme(PanelBackground, &WhiteBackgroundScheme);
    root0->fn->addChild(root0, PanelBackground);

    ImageWidget0 = leImageWidget_New();
    ImageWidget0->fn->setPosition(ImageWidget0, 141, 42);
    ImageWidget0->fn->setSize(ImageWidget0, 180, 169);
    ImageWidget0->fn->setScheme(ImageWidget0, &WhiteBackgroundScheme);
    ImageWidget0->fn->setBackgroundType(ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    ImageWidget0->fn->setImage(ImageWidget0, &MHGSLogo);
    root0->fn->addChild(root0, (leWidget*)ImageWidget0);

    PositionWidget = leWidget_New();
    PositionWidget->fn->setPosition(PositionWidget, 171, 130);
    PositionWidget->fn->setSize(PositionWidget, 120, 192);
    PositionWidget->fn->setBackgroundType(PositionWidget, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, PositionWidget);

    ImageSequenceWidget_JumpRight = leImageSequenceWidget_New();
    ImageSequenceWidget_JumpRight->fn->setPosition(ImageSequenceWidget_JumpRight, 0, 0);
    ImageSequenceWidget_JumpRight->fn->setSize(ImageSequenceWidget_JumpRight, 120, 192);
    ImageSequenceWidget_JumpRight->fn->setVisible(ImageSequenceWidget_JumpRight, LE_FALSE);
    ImageSequenceWidget_JumpRight->fn->setBackgroundType(ImageSequenceWidget_JumpRight, LE_WIDGET_BACKGROUND_NONE);
    ImageSequenceWidget_JumpRight->fn->setImageCount(ImageSequenceWidget_JumpRight, 8);
    ImageSequenceWidget_JumpRight->fn->setImage(ImageSequenceWidget_JumpRight, 0, &Jump0);
    ImageSequenceWidget_JumpRight->fn->setImage(ImageSequenceWidget_JumpRight, 1, &Jump1);
    ImageSequenceWidget_JumpRight->fn->setImage(ImageSequenceWidget_JumpRight, 2, &Jump2);
    ImageSequenceWidget_JumpRight->fn->setImage(ImageSequenceWidget_JumpRight, 3, &Jump3);
    ImageSequenceWidget_JumpRight->fn->setImage(ImageSequenceWidget_JumpRight, 4, &Jump4);
    ImageSequenceWidget_JumpRight->fn->setImage(ImageSequenceWidget_JumpRight, 5, &Jump5);
    ImageSequenceWidget_JumpRight->fn->setImage(ImageSequenceWidget_JumpRight, 6, &Jump6);
    ImageSequenceWidget_JumpRight->fn->setImage(ImageSequenceWidget_JumpRight, 7, &Jump7);
    ImageSequenceWidget_JumpRight->fn->setRepeat(ImageSequenceWidget_JumpRight, LE_TRUE);
    PositionWidget->fn->addChild(PositionWidget, (leWidget*)ImageSequenceWidget_JumpRight);

    ImageSequenceWidget_RunRight = leImageSequenceWidget_New();
    ImageSequenceWidget_RunRight->fn->setPosition(ImageSequenceWidget_RunRight, 0, 94);
    ImageSequenceWidget_RunRight->fn->setSize(ImageSequenceWidget_RunRight, 120, 96);
    ImageSequenceWidget_RunRight->fn->setVisible(ImageSequenceWidget_RunRight, LE_FALSE);
    ImageSequenceWidget_RunRight->fn->setBackgroundType(ImageSequenceWidget_RunRight, LE_WIDGET_BACKGROUND_NONE);
    ImageSequenceWidget_RunRight->fn->setImageCount(ImageSequenceWidget_RunRight, 3);
    ImageSequenceWidget_RunRight->fn->setImage(ImageSequenceWidget_RunRight, 0, &Run0);
    ImageSequenceWidget_RunRight->fn->setImage(ImageSequenceWidget_RunRight, 1, &Run1);
    ImageSequenceWidget_RunRight->fn->setImage(ImageSequenceWidget_RunRight, 2, &Run2);
    ImageSequenceWidget_RunRight->fn->setRepeat(ImageSequenceWidget_RunRight, LE_TRUE);
    PositionWidget->fn->addChild(PositionWidget, (leWidget*)ImageSequenceWidget_RunRight);

    ImageSequenceWidget_RunLeft = leImageSequenceWidget_New();
    ImageSequenceWidget_RunLeft->fn->setPosition(ImageSequenceWidget_RunLeft, 0, 94);
    ImageSequenceWidget_RunLeft->fn->setSize(ImageSequenceWidget_RunLeft, 120, 96);
    ImageSequenceWidget_RunLeft->fn->setVisible(ImageSequenceWidget_RunLeft, LE_FALSE);
    ImageSequenceWidget_RunLeft->fn->setBackgroundType(ImageSequenceWidget_RunLeft, LE_WIDGET_BACKGROUND_NONE);
    ImageSequenceWidget_RunLeft->fn->setImageCount(ImageSequenceWidget_RunLeft, 3);
    ImageSequenceWidget_RunLeft->fn->setImage(ImageSequenceWidget_RunLeft, 0, &RunToLeft0);
    ImageSequenceWidget_RunLeft->fn->setImage(ImageSequenceWidget_RunLeft, 1, &RunToLeft1);
    ImageSequenceWidget_RunLeft->fn->setImage(ImageSequenceWidget_RunLeft, 2, &RunToLeft2);
    ImageSequenceWidget_RunLeft->fn->setRepeat(ImageSequenceWidget_RunLeft, LE_TRUE);
    PositionWidget->fn->addChild(PositionWidget, (leWidget*)ImageSequenceWidget_RunLeft);

    ImageSequenceWidget_IdleRight = leImageSequenceWidget_New();
    ImageSequenceWidget_IdleRight->fn->setPosition(ImageSequenceWidget_IdleRight, 0, 94);
    ImageSequenceWidget_IdleRight->fn->setSize(ImageSequenceWidget_IdleRight, 120, 96);
    ImageSequenceWidget_IdleRight->fn->setBackgroundType(ImageSequenceWidget_IdleRight, LE_WIDGET_BACKGROUND_NONE);
    ImageSequenceWidget_IdleRight->fn->setImageCount(ImageSequenceWidget_IdleRight, 4);
    ImageSequenceWidget_IdleRight->fn->setImage(ImageSequenceWidget_IdleRight, 0, &Idle0);
    ImageSequenceWidget_IdleRight->fn->setImage(ImageSequenceWidget_IdleRight, 1, &Idle1);
    ImageSequenceWidget_IdleRight->fn->setImage(ImageSequenceWidget_IdleRight, 2, &Idle2);
    ImageSequenceWidget_IdleRight->fn->setImage(ImageSequenceWidget_IdleRight, 3, &Idle3);
    ImageSequenceWidget_IdleRight->fn->setRepeat(ImageSequenceWidget_IdleRight, LE_TRUE);
    PositionWidget->fn->addChild(PositionWidget, (leWidget*)ImageSequenceWidget_IdleRight);

    ImageSequenceWidget_IdleLeft = leImageSequenceWidget_New();
    ImageSequenceWidget_IdleLeft->fn->setPosition(ImageSequenceWidget_IdleLeft, 0, 94);
    ImageSequenceWidget_IdleLeft->fn->setSize(ImageSequenceWidget_IdleLeft, 120, 96);
    ImageSequenceWidget_IdleLeft->fn->setVisible(ImageSequenceWidget_IdleLeft, LE_FALSE);
    ImageSequenceWidget_IdleLeft->fn->setBackgroundType(ImageSequenceWidget_IdleLeft, LE_WIDGET_BACKGROUND_NONE);
    ImageSequenceWidget_IdleLeft->fn->setImageCount(ImageSequenceWidget_IdleLeft, 4);
    ImageSequenceWidget_IdleLeft->fn->setImage(ImageSequenceWidget_IdleLeft, 0, &IdleLeft0);
    ImageSequenceWidget_IdleLeft->fn->setImage(ImageSequenceWidget_IdleLeft, 1, &IdleLeft1);
    ImageSequenceWidget_IdleLeft->fn->setImage(ImageSequenceWidget_IdleLeft, 2, &IdleLeft2);
    ImageSequenceWidget_IdleLeft->fn->setImage(ImageSequenceWidget_IdleLeft, 3, &IdleLeft3);
    ImageSequenceWidget_IdleLeft->fn->setRepeat(ImageSequenceWidget_IdleLeft, LE_TRUE);
    PositionWidget->fn->addChild(PositionWidget, (leWidget*)ImageSequenceWidget_IdleLeft);

    ImageSequenceWidget_DizzieRight = leImageSequenceWidget_New();
    ImageSequenceWidget_DizzieRight->fn->setPosition(ImageSequenceWidget_DizzieRight, 0, 94);
    ImageSequenceWidget_DizzieRight->fn->setSize(ImageSequenceWidget_DizzieRight, 120, 96);
    ImageSequenceWidget_DizzieRight->fn->setVisible(ImageSequenceWidget_DizzieRight, LE_FALSE);
    ImageSequenceWidget_DizzieRight->fn->setBackgroundType(ImageSequenceWidget_DizzieRight, LE_WIDGET_BACKGROUND_NONE);
    ImageSequenceWidget_DizzieRight->fn->setImageCount(ImageSequenceWidget_DizzieRight, 3);
    ImageSequenceWidget_DizzieRight->fn->setImage(ImageSequenceWidget_DizzieRight, 0, &Dizzy0);
    ImageSequenceWidget_DizzieRight->fn->setImage(ImageSequenceWidget_DizzieRight, 1, &Dizzy1);
    ImageSequenceWidget_DizzieRight->fn->setImage(ImageSequenceWidget_DizzieRight, 2, &Dizzy2);
    ImageSequenceWidget_DizzieRight->fn->setRepeat(ImageSequenceWidget_DizzieRight, LE_TRUE);
    PositionWidget->fn->addChild(PositionWidget, (leWidget*)ImageSequenceWidget_DizzieRight);

    ImageSequenceWidget_DizzieLeft = leImageSequenceWidget_New();
    ImageSequenceWidget_DizzieLeft->fn->setPosition(ImageSequenceWidget_DizzieLeft, 0, 94);
    ImageSequenceWidget_DizzieLeft->fn->setSize(ImageSequenceWidget_DizzieLeft, 120, 96);
    ImageSequenceWidget_DizzieLeft->fn->setVisible(ImageSequenceWidget_DizzieLeft, LE_FALSE);
    ImageSequenceWidget_DizzieLeft->fn->setBackgroundType(ImageSequenceWidget_DizzieLeft, LE_WIDGET_BACKGROUND_NONE);
    ImageSequenceWidget_DizzieLeft->fn->setImageCount(ImageSequenceWidget_DizzieLeft, 3);
    ImageSequenceWidget_DizzieLeft->fn->setImage(ImageSequenceWidget_DizzieLeft, 0, &DizzyLeft0);
    ImageSequenceWidget_DizzieLeft->fn->setImage(ImageSequenceWidget_DizzieLeft, 1, &DizzyLeft1);
    ImageSequenceWidget_DizzieLeft->fn->setImage(ImageSequenceWidget_DizzieLeft, 2, &DizzyLeft2);
    ImageSequenceWidget_DizzieLeft->fn->setRepeat(ImageSequenceWidget_DizzieLeft, LE_TRUE);
    PositionWidget->fn->addChild(PositionWidget, (leWidget*)ImageSequenceWidget_DizzieLeft);

    ButtonWidget_RunLeft = leButtonWidget_New();
    ButtonWidget_RunLeft->fn->setPosition(ButtonWidget_RunLeft, -240, 220);
    ButtonWidget_RunLeft->fn->setSize(ButtonWidget_RunLeft, 480, 100);
    ButtonWidget_RunLeft->fn->setBackgroundType(ButtonWidget_RunLeft, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget_RunLeft->fn->setBorderType(ButtonWidget_RunLeft, LE_WIDGET_BORDER_NONE);
    ButtonWidget_RunLeft->fn->setPressedEventCallback(ButtonWidget_RunLeft, ButtonWidget_RunLeft_OnPressed);
    ButtonWidget_RunLeft->fn->setReleasedEventCallback(ButtonWidget_RunLeft, ButtonWidget_RunLeft_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget_RunLeft);

    ButtonWidget_RunRight = leButtonWidget_New();
    ButtonWidget_RunRight->fn->setPosition(ButtonWidget_RunRight, 240, 220);
    ButtonWidget_RunRight->fn->setSize(ButtonWidget_RunRight, 480, 100);
    ButtonWidget_RunRight->fn->setBackgroundType(ButtonWidget_RunRight, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget_RunRight->fn->setBorderType(ButtonWidget_RunRight, LE_WIDGET_BORDER_NONE);
    ButtonWidget_RunRight->fn->setPressedEventCallback(ButtonWidget_RunRight, ButtonWidget_RunRight_OnPressed);
    ButtonWidget_RunRight->fn->setReleasedEventCallback(ButtonWidget_RunRight, ButtonWidget_RunRight_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget_RunRight);

    ButtonWidget_Jump = leButtonWidget_New();
    ButtonWidget_Jump->fn->setPosition(ButtonWidget_Jump, 0, 0);
    ButtonWidget_Jump->fn->setSize(ButtonWidget_Jump, 480, 160);
    ButtonWidget_Jump->fn->setBackgroundType(ButtonWidget_Jump, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget_Jump->fn->setBorderType(ButtonWidget_Jump, LE_WIDGET_BORDER_NONE);
    ButtonWidget_Jump->fn->setPressedEventCallback(ButtonWidget_Jump, ButtonWidget_Jump_OnPressed);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget_Jump);

    ButtonWidget_ScreenChange = leButtonWidget_New();
    ButtonWidget_ScreenChange->fn->setPosition(ButtonWidget_ScreenChange, 352, 0);
    ButtonWidget_ScreenChange->fn->setSize(ButtonWidget_ScreenChange, 129, 42);
    ButtonWidget_ScreenChange->fn->setScheme(ButtonWidget_ScreenChange, &WhiteFillScheme);
    ButtonWidget_ScreenChange->fn->setBackgroundType(ButtonWidget_ScreenChange, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget_ScreenChange->fn->setBorderType(ButtonWidget_ScreenChange, LE_WIDGET_BORDER_NONE);
    ButtonWidget_ScreenChange->fn->setReleasedImage(ButtonWidget_ScreenChange, &mchp_logo);
    ButtonWidget_ScreenChange->fn->setReleasedEventCallback(ButtonWidget_ScreenChange, ButtonWidget_ScreenChange_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget_ScreenChange);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    MainScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_MainScreen()
{
    MainScreen_OnUpdate();
}

void screenHide_MainScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelBackground = NULL;
    ImageWidget0 = NULL;
    PositionWidget = NULL;
    ImageSequenceWidget_JumpRight = NULL;
    ImageSequenceWidget_RunRight = NULL;
    ImageSequenceWidget_RunLeft = NULL;
    ImageSequenceWidget_IdleRight = NULL;
    ImageSequenceWidget_IdleLeft = NULL;
    ImageSequenceWidget_DizzieRight = NULL;
    ImageSequenceWidget_DizzieLeft = NULL;
    ButtonWidget_RunLeft = NULL;
    ButtonWidget_RunRight = NULL;
    ButtonWidget_Jump = NULL;
    ButtonWidget_ScreenChange = NULL;
    showing = LE_FALSE;

    MainScreen_OnHide();
}

void screenDestroy_MainScreen()
{

}

leWidget* screenGetRoot_MainScreen(uint32_t lyrIdx)
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

// event handlers
void ButtonWidget_ScreenChange_OnReleased(leButtonWidget* btn)
{
    // Show Screen (InfoScreen) - ShowScreen - InfoScreen
    legato_showScreen(screenID_InfoScreen);

}



