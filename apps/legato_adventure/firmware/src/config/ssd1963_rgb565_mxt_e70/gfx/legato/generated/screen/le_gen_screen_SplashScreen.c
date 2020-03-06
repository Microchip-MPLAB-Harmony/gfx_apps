// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include "gfx/legato/generated/screen/le_gen_screen_SplashScreen.h"

// widget list for layer 0
static leWidget* root0;

leWidget* SplashBackground;
leImageWidget* SplashPIC32Logo;
leImageWidget* SplashHarmonyLogo;
leImageWidget* SplashBar;
leImageWidget* SplashMicrochipLogo;


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
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    SplashBackground = leWidget_New();
    SplashBackground->fn->setPosition(SplashBackground, 0, 0);
    SplashBackground->fn->setSize(SplashBackground, 480, 272);
    SplashBackground->fn->setScheme(SplashBackground, &WhiteFillScheme);
    root0->fn->addChild(root0, SplashBackground);

    SplashPIC32Logo = leImageWidget_New();
    SplashPIC32Logo->fn->setPosition(SplashPIC32Logo, 120, 40);
    SplashPIC32Logo->fn->setSize(SplashPIC32Logo, 240, 139);
    SplashPIC32Logo->fn->setBackgroundType(SplashPIC32Logo, LE_WIDGET_BACKGROUND_NONE);
    SplashPIC32Logo->fn->setImage(SplashPIC32Logo, &PIC32Logo);
    root0->fn->addChild(root0, (leWidget*)SplashPIC32Logo);

    SplashHarmonyLogo = leImageWidget_New();
    SplashHarmonyLogo->fn->setPosition(SplashHarmonyLogo, 120, 40);
    SplashHarmonyLogo->fn->setSize(SplashHarmonyLogo, 240, 139);
    SplashHarmonyLogo->fn->setVisible(SplashHarmonyLogo, LE_FALSE);
    SplashHarmonyLogo->fn->setScheme(SplashHarmonyLogo, &WhiteBackgroundScheme);
    SplashHarmonyLogo->fn->setImage(SplashHarmonyLogo, &HarmonyLogo);
    root0->fn->addChild(root0, (leWidget*)SplashHarmonyLogo);

    SplashBar = leImageWidget_New();
    SplashBar->fn->setPosition(SplashBar, 480, 207);
    SplashBar->fn->setSize(SplashBar, 480, 65);
    SplashBar->fn->setBackgroundType(SplashBar, LE_WIDGET_BACKGROUND_NONE);
    SplashBar->fn->setImage(SplashBar, &Bar);
    root0->fn->addChild(root0, (leWidget*)SplashBar);

    SplashMicrochipLogo = leImageWidget_New();
    SplashMicrochipLogo->fn->setPosition(SplashMicrochipLogo, 17, 224);
    SplashMicrochipLogo->fn->setSize(SplashMicrochipLogo, 144, 39);
    SplashMicrochipLogo->fn->setVisible(SplashMicrochipLogo, LE_FALSE);
    SplashMicrochipLogo->fn->setBackgroundType(SplashMicrochipLogo, LE_WIDGET_BACKGROUND_NONE);
    SplashMicrochipLogo->fn->setImage(SplashMicrochipLogo, &MicrochipLogo);
    root0->fn->addChild(root0, (leWidget*)SplashMicrochipLogo);

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

    SplashBackground = NULL;
    SplashPIC32Logo = NULL;
    SplashHarmonyLogo = NULL;
    SplashBar = NULL;
    SplashMicrochipLogo = NULL;
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

