#include "gfx/legato/generated/screen/le_gen_screen_Screen1.h"

// screen member widget declarations
leWidget* root0;

leWidget* Screen1_PanelBackground;
leImageWidget* Screen1_ImageWidget0;
leWidget* Screen1_PositionWidget;
leButtonWidget* Screen1_ButtonWidget_RunLeft;
leButtonWidget* Screen1_ButtonWidget_RunRight;
leButtonWidget* Screen1_ButtonWidget_Jump;
leButtonWidget* Screen1_ButtonWidget_ScreenChange;
leImageSequenceWidget* Screen1_ImageSequenceWidget_DizzieLeft;
leImageSequenceWidget* Screen1_ImageSequenceWidget_DizzieRight;
leImageSequenceWidget* Screen1_ImageSequenceWidget_HurtLeft;
leImageSequenceWidget* Screen1_ImageSequenceWidget_IdleLeft;
leImageSequenceWidget* Screen1_ImageSequenceWidget_IdleRight;
leImageSequenceWidget* Screen1_ImageSequenceWidget_HurtRight;
leImageSequenceWidget* Screen1_ImageSequenceWidget_RunLeft;
leImageSequenceWidget* Screen1_ImageSequenceWidget_RunRight;
leImageSequenceWidget* Screen1_ImageSequenceWidget_JumpLeft;
leImageSequenceWidget* Screen1_ImageSequenceWidget_JumpRight;

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

    Screen1_PanelBackground = leWidget_New();
    Screen1_PanelBackground->fn->setPosition(Screen1_PanelBackground, 0, 0);
    Screen1_PanelBackground->fn->setSize(Screen1_PanelBackground, 480, 272);
    Screen1_PanelBackground->fn->setScheme(Screen1_PanelBackground, &WhiteBackgroundScheme);
    root0->fn->addChild(root0, (leWidget*)Screen1_PanelBackground);

    Screen1_ImageWidget0 = leImageWidget_New();
    Screen1_ImageWidget0->fn->setPosition(Screen1_ImageWidget0, 141, 42);
    Screen1_ImageWidget0->fn->setSize(Screen1_ImageWidget0, 180, 169);
    Screen1_ImageWidget0->fn->setScheme(Screen1_ImageWidget0, &WhiteBackgroundScheme);
    Screen1_ImageWidget0->fn->setBackgroundType(Screen1_ImageWidget0, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ImageWidget0->fn->setBorderType(Screen1_ImageWidget0, LE_WIDGET_BORDER_NONE);
    Screen1_ImageWidget0->fn->setImage(Screen1_ImageWidget0, (leImage*)&MHGSLogo);
    root0->fn->addChild(root0, (leWidget*)Screen1_ImageWidget0);

    Screen1_PositionWidget = leWidget_New();
    Screen1_PositionWidget->fn->setPosition(Screen1_PositionWidget, 171, 79);
    Screen1_PositionWidget->fn->setSize(Screen1_PositionWidget, 120, 192);
    Screen1_PositionWidget->fn->setBackgroundType(Screen1_PositionWidget, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)Screen1_PositionWidget);

    Screen1_ImageSequenceWidget_DizzieLeft = leImageSequenceWidget_New();
    Screen1_ImageSequenceWidget_DizzieLeft->fn->setPosition(Screen1_ImageSequenceWidget_DizzieLeft, 0, 94);
    Screen1_ImageSequenceWidget_DizzieLeft->fn->setSize(Screen1_ImageSequenceWidget_DizzieLeft, 120, 96);
    Screen1_ImageSequenceWidget_DizzieLeft->fn->setVisible(Screen1_ImageSequenceWidget_DizzieLeft, LE_FALSE);
    Screen1_ImageSequenceWidget_DizzieLeft->fn->setBackgroundType(Screen1_ImageSequenceWidget_DizzieLeft, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ImageSequenceWidget_DizzieLeft->fn->setRepeat(Screen1_ImageSequenceWidget_DizzieLeft, LE_TRUE);
    Screen1_ImageSequenceWidget_DizzieLeft->fn->setImageCount(Screen1_ImageSequenceWidget_DizzieLeft, 3);
    Screen1_ImageSequenceWidget_DizzieLeft->fn->setImage(Screen1_ImageSequenceWidget_DizzieLeft, 0, &DizzyLeft0);
    Screen1_ImageSequenceWidget_DizzieLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_DizzieLeft, 0, 1000);
    Screen1_ImageSequenceWidget_DizzieLeft->fn->setImage(Screen1_ImageSequenceWidget_DizzieLeft, 1, &DizzyLeft1);
    Screen1_ImageSequenceWidget_DizzieLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_DizzieLeft, 1, 1000);
    Screen1_ImageSequenceWidget_DizzieLeft->fn->setImage(Screen1_ImageSequenceWidget_DizzieLeft, 2, &DizzyLeft2);
    Screen1_ImageSequenceWidget_DizzieLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_DizzieLeft, 2, 1000);
    Screen1_PositionWidget->fn->addChild(Screen1_PositionWidget, (leWidget*)Screen1_ImageSequenceWidget_DizzieLeft);

    Screen1_ImageSequenceWidget_DizzieRight = leImageSequenceWidget_New();
    Screen1_ImageSequenceWidget_DizzieRight->fn->setPosition(Screen1_ImageSequenceWidget_DizzieRight, 0, 94);
    Screen1_ImageSequenceWidget_DizzieRight->fn->setSize(Screen1_ImageSequenceWidget_DizzieRight, 120, 96);
    Screen1_ImageSequenceWidget_DizzieRight->fn->setVisible(Screen1_ImageSequenceWidget_DizzieRight, LE_FALSE);
    Screen1_ImageSequenceWidget_DizzieRight->fn->setBackgroundType(Screen1_ImageSequenceWidget_DizzieRight, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ImageSequenceWidget_DizzieRight->fn->setRepeat(Screen1_ImageSequenceWidget_DizzieRight, LE_TRUE);
    Screen1_ImageSequenceWidget_DizzieRight->fn->setImageCount(Screen1_ImageSequenceWidget_DizzieRight, 3);
    Screen1_ImageSequenceWidget_DizzieRight->fn->setImage(Screen1_ImageSequenceWidget_DizzieRight, 0, &Dizzy0);
    Screen1_ImageSequenceWidget_DizzieRight->fn->setImageDelay(Screen1_ImageSequenceWidget_DizzieRight, 0, 1000);
    Screen1_ImageSequenceWidget_DizzieRight->fn->setImage(Screen1_ImageSequenceWidget_DizzieRight, 1, &Dizzy1);
    Screen1_ImageSequenceWidget_DizzieRight->fn->setImageDelay(Screen1_ImageSequenceWidget_DizzieRight, 1, 1000);
    Screen1_ImageSequenceWidget_DizzieRight->fn->setImage(Screen1_ImageSequenceWidget_DizzieRight, 2, &Dizzy2);
    Screen1_ImageSequenceWidget_DizzieRight->fn->setImageDelay(Screen1_ImageSequenceWidget_DizzieRight, 2, 1000);
    Screen1_PositionWidget->fn->addChild(Screen1_PositionWidget, (leWidget*)Screen1_ImageSequenceWidget_DizzieRight);

    Screen1_ImageSequenceWidget_HurtLeft = leImageSequenceWidget_New();
    Screen1_ImageSequenceWidget_HurtLeft->fn->setPosition(Screen1_ImageSequenceWidget_HurtLeft, 0, 94);
    Screen1_ImageSequenceWidget_HurtLeft->fn->setSize(Screen1_ImageSequenceWidget_HurtLeft, 120, 96);
    Screen1_ImageSequenceWidget_HurtLeft->fn->setVisible(Screen1_ImageSequenceWidget_HurtLeft, LE_FALSE);
    Screen1_ImageSequenceWidget_HurtLeft->fn->setBackgroundType(Screen1_ImageSequenceWidget_HurtLeft, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ImageSequenceWidget_HurtLeft->fn->setRepeat(Screen1_ImageSequenceWidget_HurtLeft, LE_TRUE);
    Screen1_ImageSequenceWidget_HurtLeft->fn->setImageCount(Screen1_ImageSequenceWidget_HurtLeft, 4);
    Screen1_ImageSequenceWidget_HurtLeft->fn->setImage(Screen1_ImageSequenceWidget_HurtLeft, 0, &HurtLeft0);
    Screen1_ImageSequenceWidget_HurtLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_HurtLeft, 0, 1000);
    Screen1_ImageSequenceWidget_HurtLeft->fn->setImage(Screen1_ImageSequenceWidget_HurtLeft, 1, &HurtLeft1);
    Screen1_ImageSequenceWidget_HurtLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_HurtLeft, 1, 1000);
    Screen1_ImageSequenceWidget_HurtLeft->fn->setImage(Screen1_ImageSequenceWidget_HurtLeft, 2, &HurtLeft2);
    Screen1_ImageSequenceWidget_HurtLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_HurtLeft, 2, 1000);
    Screen1_ImageSequenceWidget_HurtLeft->fn->setImage(Screen1_ImageSequenceWidget_HurtLeft, 3, &HurtLeft3);
    Screen1_ImageSequenceWidget_HurtLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_HurtLeft, 3, 1000);
    Screen1_PositionWidget->fn->addChild(Screen1_PositionWidget, (leWidget*)Screen1_ImageSequenceWidget_HurtLeft);

    Screen1_ImageSequenceWidget_IdleLeft = leImageSequenceWidget_New();
    Screen1_ImageSequenceWidget_IdleLeft->fn->setPosition(Screen1_ImageSequenceWidget_IdleLeft, 0, 94);
    Screen1_ImageSequenceWidget_IdleLeft->fn->setSize(Screen1_ImageSequenceWidget_IdleLeft, 120, 96);
    Screen1_ImageSequenceWidget_IdleLeft->fn->setVisible(Screen1_ImageSequenceWidget_IdleLeft, LE_FALSE);
    Screen1_ImageSequenceWidget_IdleLeft->fn->setBackgroundType(Screen1_ImageSequenceWidget_IdleLeft, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ImageSequenceWidget_IdleLeft->fn->setRepeat(Screen1_ImageSequenceWidget_IdleLeft, LE_TRUE);
    Screen1_ImageSequenceWidget_IdleLeft->fn->setImageCount(Screen1_ImageSequenceWidget_IdleLeft, 4);
    Screen1_ImageSequenceWidget_IdleLeft->fn->setImage(Screen1_ImageSequenceWidget_IdleLeft, 0, &IdleLeft0);
    Screen1_ImageSequenceWidget_IdleLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_IdleLeft, 0, 1000);
    Screen1_ImageSequenceWidget_IdleLeft->fn->setImage(Screen1_ImageSequenceWidget_IdleLeft, 1, &IdleLeft1);
    Screen1_ImageSequenceWidget_IdleLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_IdleLeft, 1, 1000);
    Screen1_ImageSequenceWidget_IdleLeft->fn->setImage(Screen1_ImageSequenceWidget_IdleLeft, 2, &IdleLeft2);
    Screen1_ImageSequenceWidget_IdleLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_IdleLeft, 2, 1000);
    Screen1_ImageSequenceWidget_IdleLeft->fn->setImage(Screen1_ImageSequenceWidget_IdleLeft, 3, &IdleLeft3);
    Screen1_ImageSequenceWidget_IdleLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_IdleLeft, 3, 1000);
    Screen1_PositionWidget->fn->addChild(Screen1_PositionWidget, (leWidget*)Screen1_ImageSequenceWidget_IdleLeft);

    Screen1_ImageSequenceWidget_IdleRight = leImageSequenceWidget_New();
    Screen1_ImageSequenceWidget_IdleRight->fn->setPosition(Screen1_ImageSequenceWidget_IdleRight, 0, 94);
    Screen1_ImageSequenceWidget_IdleRight->fn->setSize(Screen1_ImageSequenceWidget_IdleRight, 120, 96);
    Screen1_ImageSequenceWidget_IdleRight->fn->setBackgroundType(Screen1_ImageSequenceWidget_IdleRight, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ImageSequenceWidget_IdleRight->fn->setRepeat(Screen1_ImageSequenceWidget_IdleRight, LE_TRUE);
    Screen1_ImageSequenceWidget_IdleRight->fn->setImageCount(Screen1_ImageSequenceWidget_IdleRight, 4);
    Screen1_ImageSequenceWidget_IdleRight->fn->setImage(Screen1_ImageSequenceWidget_IdleRight, 0, &Idle0);
    Screen1_ImageSequenceWidget_IdleRight->fn->setImageDelay(Screen1_ImageSequenceWidget_IdleRight, 0, 1000);
    Screen1_ImageSequenceWidget_IdleRight->fn->setImage(Screen1_ImageSequenceWidget_IdleRight, 1, &Idle1);
    Screen1_ImageSequenceWidget_IdleRight->fn->setImageDelay(Screen1_ImageSequenceWidget_IdleRight, 1, 1000);
    Screen1_ImageSequenceWidget_IdleRight->fn->setImage(Screen1_ImageSequenceWidget_IdleRight, 2, &Idle2);
    Screen1_ImageSequenceWidget_IdleRight->fn->setImageDelay(Screen1_ImageSequenceWidget_IdleRight, 2, 1000);
    Screen1_ImageSequenceWidget_IdleRight->fn->setImage(Screen1_ImageSequenceWidget_IdleRight, 3, &Idle3);
    Screen1_ImageSequenceWidget_IdleRight->fn->setImageDelay(Screen1_ImageSequenceWidget_IdleRight, 3, 1000);
    Screen1_PositionWidget->fn->addChild(Screen1_PositionWidget, (leWidget*)Screen1_ImageSequenceWidget_IdleRight);

    Screen1_ImageSequenceWidget_HurtRight = leImageSequenceWidget_New();
    Screen1_ImageSequenceWidget_HurtRight->fn->setPosition(Screen1_ImageSequenceWidget_HurtRight, 0, 94);
    Screen1_ImageSequenceWidget_HurtRight->fn->setSize(Screen1_ImageSequenceWidget_HurtRight, 120, 96);
    Screen1_ImageSequenceWidget_HurtRight->fn->setVisible(Screen1_ImageSequenceWidget_HurtRight, LE_FALSE);
    Screen1_ImageSequenceWidget_HurtRight->fn->setBackgroundType(Screen1_ImageSequenceWidget_HurtRight, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ImageSequenceWidget_HurtRight->fn->setRepeat(Screen1_ImageSequenceWidget_HurtRight, LE_TRUE);
    Screen1_ImageSequenceWidget_HurtRight->fn->setImageCount(Screen1_ImageSequenceWidget_HurtRight, 4);
    Screen1_ImageSequenceWidget_HurtRight->fn->setImage(Screen1_ImageSequenceWidget_HurtRight, 0, &Hurt0);
    Screen1_ImageSequenceWidget_HurtRight->fn->setImageDelay(Screen1_ImageSequenceWidget_HurtRight, 0, 1000);
    Screen1_ImageSequenceWidget_HurtRight->fn->setImage(Screen1_ImageSequenceWidget_HurtRight, 1, &Hurt1);
    Screen1_ImageSequenceWidget_HurtRight->fn->setImageDelay(Screen1_ImageSequenceWidget_HurtRight, 1, 1000);
    Screen1_ImageSequenceWidget_HurtRight->fn->setImage(Screen1_ImageSequenceWidget_HurtRight, 2, &Hurt2);
    Screen1_ImageSequenceWidget_HurtRight->fn->setImageDelay(Screen1_ImageSequenceWidget_HurtRight, 2, 1000);
    Screen1_ImageSequenceWidget_HurtRight->fn->setImage(Screen1_ImageSequenceWidget_HurtRight, 3, &Hurt3);
    Screen1_ImageSequenceWidget_HurtRight->fn->setImageDelay(Screen1_ImageSequenceWidget_HurtRight, 3, 1000);
    Screen1_PositionWidget->fn->addChild(Screen1_PositionWidget, (leWidget*)Screen1_ImageSequenceWidget_HurtRight);

    Screen1_ImageSequenceWidget_RunLeft = leImageSequenceWidget_New();
    Screen1_ImageSequenceWidget_RunLeft->fn->setPosition(Screen1_ImageSequenceWidget_RunLeft, 0, 94);
    Screen1_ImageSequenceWidget_RunLeft->fn->setSize(Screen1_ImageSequenceWidget_RunLeft, 120, 96);
    Screen1_ImageSequenceWidget_RunLeft->fn->setVisible(Screen1_ImageSequenceWidget_RunLeft, LE_FALSE);
    Screen1_ImageSequenceWidget_RunLeft->fn->setBackgroundType(Screen1_ImageSequenceWidget_RunLeft, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ImageSequenceWidget_RunLeft->fn->setRepeat(Screen1_ImageSequenceWidget_RunLeft, LE_TRUE);
    Screen1_ImageSequenceWidget_RunLeft->fn->setImageCount(Screen1_ImageSequenceWidget_RunLeft, 3);
    Screen1_ImageSequenceWidget_RunLeft->fn->setImage(Screen1_ImageSequenceWidget_RunLeft, 0, &RunToLeft0);
    Screen1_ImageSequenceWidget_RunLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_RunLeft, 0, 1000);
    Screen1_ImageSequenceWidget_RunLeft->fn->setImage(Screen1_ImageSequenceWidget_RunLeft, 1, &RunToLeft1);
    Screen1_ImageSequenceWidget_RunLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_RunLeft, 1, 1000);
    Screen1_ImageSequenceWidget_RunLeft->fn->setImage(Screen1_ImageSequenceWidget_RunLeft, 2, &RunToLeft2);
    Screen1_ImageSequenceWidget_RunLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_RunLeft, 2, 1000);
    Screen1_PositionWidget->fn->addChild(Screen1_PositionWidget, (leWidget*)Screen1_ImageSequenceWidget_RunLeft);

    Screen1_ImageSequenceWidget_RunRight = leImageSequenceWidget_New();
    Screen1_ImageSequenceWidget_RunRight->fn->setPosition(Screen1_ImageSequenceWidget_RunRight, 0, 94);
    Screen1_ImageSequenceWidget_RunRight->fn->setSize(Screen1_ImageSequenceWidget_RunRight, 120, 96);
    Screen1_ImageSequenceWidget_RunRight->fn->setVisible(Screen1_ImageSequenceWidget_RunRight, LE_FALSE);
    Screen1_ImageSequenceWidget_RunRight->fn->setBackgroundType(Screen1_ImageSequenceWidget_RunRight, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ImageSequenceWidget_RunRight->fn->setRepeat(Screen1_ImageSequenceWidget_RunRight, LE_TRUE);
    Screen1_ImageSequenceWidget_RunRight->fn->setImageCount(Screen1_ImageSequenceWidget_RunRight, 3);
    Screen1_ImageSequenceWidget_RunRight->fn->setImage(Screen1_ImageSequenceWidget_RunRight, 0, &Run0);
    Screen1_ImageSequenceWidget_RunRight->fn->setImageDelay(Screen1_ImageSequenceWidget_RunRight, 0, 1000);
    Screen1_ImageSequenceWidget_RunRight->fn->setImage(Screen1_ImageSequenceWidget_RunRight, 1, &Run1);
    Screen1_ImageSequenceWidget_RunRight->fn->setImageDelay(Screen1_ImageSequenceWidget_RunRight, 1, 1000);
    Screen1_ImageSequenceWidget_RunRight->fn->setImage(Screen1_ImageSequenceWidget_RunRight, 2, &Run2);
    Screen1_ImageSequenceWidget_RunRight->fn->setImageDelay(Screen1_ImageSequenceWidget_RunRight, 2, 1000);
    Screen1_PositionWidget->fn->addChild(Screen1_PositionWidget, (leWidget*)Screen1_ImageSequenceWidget_RunRight);

    Screen1_ImageSequenceWidget_JumpLeft = leImageSequenceWidget_New();
    Screen1_ImageSequenceWidget_JumpLeft->fn->setPosition(Screen1_ImageSequenceWidget_JumpLeft, 0, 0);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setSize(Screen1_ImageSequenceWidget_JumpLeft, 120, 192);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setVisible(Screen1_ImageSequenceWidget_JumpLeft, LE_FALSE);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setBackgroundType(Screen1_ImageSequenceWidget_JumpLeft, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setRepeat(Screen1_ImageSequenceWidget_JumpLeft, LE_TRUE);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImageCount(Screen1_ImageSequenceWidget_JumpLeft, 8);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImage(Screen1_ImageSequenceWidget_JumpLeft, 0, &JumpLeft0);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpLeft, 0, 1000);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImage(Screen1_ImageSequenceWidget_JumpLeft, 1, &JumpLeft1);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpLeft, 1, 1000);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImage(Screen1_ImageSequenceWidget_JumpLeft, 2, &JumpLeft2);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpLeft, 2, 1000);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImage(Screen1_ImageSequenceWidget_JumpLeft, 3, &JumpLeft3);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpLeft, 3, 1000);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImage(Screen1_ImageSequenceWidget_JumpLeft, 4, &JumpLeft4);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpLeft, 4, 1000);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImage(Screen1_ImageSequenceWidget_JumpLeft, 5, &JumpLeft5);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpLeft, 5, 1000);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImage(Screen1_ImageSequenceWidget_JumpLeft, 6, &JumpLeft6);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpLeft, 6, 1000);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImage(Screen1_ImageSequenceWidget_JumpLeft, 7, &JumpLeft7);
    Screen1_ImageSequenceWidget_JumpLeft->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpLeft, 7, 1000);
    Screen1_PositionWidget->fn->addChild(Screen1_PositionWidget, (leWidget*)Screen1_ImageSequenceWidget_JumpLeft);

    Screen1_ImageSequenceWidget_JumpRight = leImageSequenceWidget_New();
    Screen1_ImageSequenceWidget_JumpRight->fn->setPosition(Screen1_ImageSequenceWidget_JumpRight, 0, 0);
    Screen1_ImageSequenceWidget_JumpRight->fn->setSize(Screen1_ImageSequenceWidget_JumpRight, 120, 192);
    Screen1_ImageSequenceWidget_JumpRight->fn->setVisible(Screen1_ImageSequenceWidget_JumpRight, LE_FALSE);
    Screen1_ImageSequenceWidget_JumpRight->fn->setBackgroundType(Screen1_ImageSequenceWidget_JumpRight, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ImageSequenceWidget_JumpRight->fn->setRepeat(Screen1_ImageSequenceWidget_JumpRight, LE_TRUE);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImageCount(Screen1_ImageSequenceWidget_JumpRight, 8);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImage(Screen1_ImageSequenceWidget_JumpRight, 0, &Jump0);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpRight, 0, 1000);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImage(Screen1_ImageSequenceWidget_JumpRight, 1, &Jump1);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpRight, 1, 1000);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImage(Screen1_ImageSequenceWidget_JumpRight, 2, &Jump2);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpRight, 2, 1000);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImage(Screen1_ImageSequenceWidget_JumpRight, 3, &Jump3);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpRight, 3, 1000);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImage(Screen1_ImageSequenceWidget_JumpRight, 4, &Jump4);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpRight, 4, 1000);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImage(Screen1_ImageSequenceWidget_JumpRight, 5, &Jump5);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpRight, 5, 1000);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImage(Screen1_ImageSequenceWidget_JumpRight, 6, &Jump6);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpRight, 6, 1000);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImage(Screen1_ImageSequenceWidget_JumpRight, 7, &Jump7);
    Screen1_ImageSequenceWidget_JumpRight->fn->setImageDelay(Screen1_ImageSequenceWidget_JumpRight, 7, 1000);
    Screen1_PositionWidget->fn->addChild(Screen1_PositionWidget, (leWidget*)Screen1_ImageSequenceWidget_JumpRight);

    Screen1_ButtonWidget_RunLeft = leButtonWidget_New();
    Screen1_ButtonWidget_RunLeft->fn->setPosition(Screen1_ButtonWidget_RunLeft, -240, 172);
    Screen1_ButtonWidget_RunLeft->fn->setSize(Screen1_ButtonWidget_RunLeft, 480, 100);
    Screen1_ButtonWidget_RunLeft->fn->setBackgroundType(Screen1_ButtonWidget_RunLeft, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ButtonWidget_RunLeft->fn->setBorderType(Screen1_ButtonWidget_RunLeft, LE_WIDGET_BORDER_NONE);
    Screen1_ButtonWidget_RunLeft->fn->setPressedEventCallback(Screen1_ButtonWidget_RunLeft, event_Screen1_ButtonWidget_RunLeft_OnPressed);
    Screen1_ButtonWidget_RunLeft->fn->setReleasedEventCallback(Screen1_ButtonWidget_RunLeft, event_Screen1_ButtonWidget_RunLeft_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Screen1_ButtonWidget_RunLeft);

    Screen1_ButtonWidget_RunRight = leButtonWidget_New();
    Screen1_ButtonWidget_RunRight->fn->setPosition(Screen1_ButtonWidget_RunRight, 240, 172);
    Screen1_ButtonWidget_RunRight->fn->setSize(Screen1_ButtonWidget_RunRight, 480, 100);
    Screen1_ButtonWidget_RunRight->fn->setBackgroundType(Screen1_ButtonWidget_RunRight, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ButtonWidget_RunRight->fn->setBorderType(Screen1_ButtonWidget_RunRight, LE_WIDGET_BORDER_NONE);
    Screen1_ButtonWidget_RunRight->fn->setPressedEventCallback(Screen1_ButtonWidget_RunRight, event_Screen1_ButtonWidget_RunRight_OnPressed);
    Screen1_ButtonWidget_RunRight->fn->setReleasedEventCallback(Screen1_ButtonWidget_RunRight, event_Screen1_ButtonWidget_RunRight_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Screen1_ButtonWidget_RunRight);

    Screen1_ButtonWidget_Jump = leButtonWidget_New();
    Screen1_ButtonWidget_Jump->fn->setPosition(Screen1_ButtonWidget_Jump, 0, 0);
    Screen1_ButtonWidget_Jump->fn->setSize(Screen1_ButtonWidget_Jump, 480, 172);
    Screen1_ButtonWidget_Jump->fn->setBackgroundType(Screen1_ButtonWidget_Jump, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ButtonWidget_Jump->fn->setBorderType(Screen1_ButtonWidget_Jump, LE_WIDGET_BORDER_NONE);
    Screen1_ButtonWidget_Jump->fn->setPressedEventCallback(Screen1_ButtonWidget_Jump, event_Screen1_ButtonWidget_Jump_OnPressed);
    Screen1_ButtonWidget_Jump->fn->setReleasedEventCallback(Screen1_ButtonWidget_Jump, event_Screen1_ButtonWidget_Jump_OnReleased);
    root0->fn->addChild(root0, (leWidget*)Screen1_ButtonWidget_Jump);

    Screen1_ButtonWidget_ScreenChange = leButtonWidget_New();
    Screen1_ButtonWidget_ScreenChange->fn->setPosition(Screen1_ButtonWidget_ScreenChange, 352, 0);
    Screen1_ButtonWidget_ScreenChange->fn->setSize(Screen1_ButtonWidget_ScreenChange, 129, 42);
    Screen1_ButtonWidget_ScreenChange->fn->setScheme(Screen1_ButtonWidget_ScreenChange, &WhiteFillScheme);
    Screen1_ButtonWidget_ScreenChange->fn->setBackgroundType(Screen1_ButtonWidget_ScreenChange, LE_WIDGET_BACKGROUND_NONE);
    Screen1_ButtonWidget_ScreenChange->fn->setBorderType(Screen1_ButtonWidget_ScreenChange, LE_WIDGET_BORDER_NONE);
    Screen1_ButtonWidget_ScreenChange->fn->setReleasedImage(Screen1_ButtonWidget_ScreenChange, (leImage*)&mchp_logo);
    root0->fn->addChild(root0, (leWidget*)Screen1_ButtonWidget_ScreenChange);

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

    Screen1_PanelBackground = NULL;
    Screen1_ImageWidget0 = NULL;
    Screen1_PositionWidget = NULL;
    Screen1_ButtonWidget_RunLeft = NULL;
    Screen1_ButtonWidget_RunRight = NULL;
    Screen1_ButtonWidget_Jump = NULL;
    Screen1_ButtonWidget_ScreenChange = NULL;
    Screen1_ImageSequenceWidget_DizzieLeft = NULL;
    Screen1_ImageSequenceWidget_DizzieRight = NULL;
    Screen1_ImageSequenceWidget_HurtLeft = NULL;
    Screen1_ImageSequenceWidget_IdleLeft = NULL;
    Screen1_ImageSequenceWidget_IdleRight = NULL;
    Screen1_ImageSequenceWidget_HurtRight = NULL;
    Screen1_ImageSequenceWidget_RunLeft = NULL;
    Screen1_ImageSequenceWidget_RunRight = NULL;
    Screen1_ImageSequenceWidget_JumpLeft = NULL;
    Screen1_ImageSequenceWidget_JumpRight = NULL;


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

