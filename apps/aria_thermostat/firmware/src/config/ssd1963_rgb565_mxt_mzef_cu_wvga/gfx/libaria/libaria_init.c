/*******************************************************************************
  MPLAB Harmony Graphics Composer Generated Implementation File

  File Name:
    libaria_init.c

  Summary:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

  Description:
    Build-time generated implementation from the MPLAB Harmony
    Graphics Composer.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#include "gfx/libaria/libaria_init.h"
#include "gfx/libaria/inc/libaria_utils.h"

laScheme defaultScheme;
laScheme whiteScheme;
laScheme mainScheme;
laImageWidget* Pic32Logo;
laImageWidget* HarmonyLogoWidget;
laImageWidget* SplashBar;
laImageWidget* SplashBarLogo;
laImageWidget* ImageWidget;


static void ScreenCreate_SplashScreen(laScreen* screen);
static void ScreenCreate_MainScreen(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&defaultScheme, GFX_COLOR_MODE_RGB_565);
    defaultScheme.base = 0xC67A;
    defaultScheme.highlight = 0xC67A;
    defaultScheme.highlightLight = 0xFFFF;
    defaultScheme.shadow = 0x8410;
    defaultScheme.shadowDark = 0x4208;
    defaultScheme.foreground = 0x0;
    defaultScheme.foregroundInactive = 0xD71C;
    defaultScheme.foregroundDisabled = 0x8410;
    defaultScheme.background = 0xFFFF;
    defaultScheme.backgroundInactive = 0xD71C;
    defaultScheme.backgroundDisabled = 0xC67A;
    defaultScheme.text = 0x0;
    defaultScheme.textHighlight = 0x1F;
    defaultScheme.textHighlightText = 0xFFFF;
    defaultScheme.textInactive = 0xD71C;
    defaultScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&whiteScheme, GFX_COLOR_MODE_RGB_565);
    whiteScheme.base = 0xFFFF;
    whiteScheme.highlight = 0xC67A;
    whiteScheme.highlightLight = 0xFFFF;
    whiteScheme.shadow = 0x8410;
    whiteScheme.shadowDark = 0x4208;
    whiteScheme.foreground = 0x0;
    whiteScheme.foregroundInactive = 0xD71C;
    whiteScheme.foregroundDisabled = 0x8410;
    whiteScheme.background = 0xFFFF;
    whiteScheme.backgroundInactive = 0xD71C;
    whiteScheme.backgroundDisabled = 0xC67A;
    whiteScheme.text = 0x0;
    whiteScheme.textHighlight = 0x1F;
    whiteScheme.textHighlightText = 0xFFFF;
    whiteScheme.textInactive = 0xD71C;
    whiteScheme.textDisabled = 0x8C92;

    laScheme_Initialize(&mainScheme, GFX_COLOR_MODE_RGB_565);
    mainScheme.base = 0x2967;
    mainScheme.highlight = 0xC67A;
    mainScheme.highlightLight = 0xFFFF;
    mainScheme.shadow = 0x8410;
    mainScheme.shadowDark = 0x4208;
    mainScheme.foreground = 0x0;
    mainScheme.foregroundInactive = 0xD71C;
    mainScheme.foregroundDisabled = 0x8410;
    mainScheme.background = 0xFFFF;
    mainScheme.backgroundInactive = 0xD71C;
    mainScheme.backgroundDisabled = 0xC67A;
    mainScheme.text = 0x0;
    mainScheme.textHighlight = 0x1F;
    mainScheme.textHighlightText = 0xFFFF;
    mainScheme.textInactive = 0xD71C;
    mainScheme.textDisabled = 0x8C92;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_SplashScreen);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_MainScreen);
    laContext_AddScreen(screen);

    laContext_SetActiveScreen(0);

	return 0;
}

static void ScreenCreate_SplashScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 800, 480);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);
    laLayer_SetVSync(layer0, LA_FALSE);

    laScreen_SetLayer(screen, 0, layer0);

    Pic32Logo = laImageWidget_New();
    laWidget_SetPosition((laWidget*)Pic32Logo, 221, 94);
    laWidget_SetSize((laWidget*)Pic32Logo, 372, 210);
    laWidget_SetOptimizationFlags((laWidget*)Pic32Logo, LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)Pic32Logo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)Pic32Logo, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(Pic32Logo, &PIC32Logo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)Pic32Logo);

    HarmonyLogoWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)HarmonyLogoWidget, 221, 94);
    laWidget_SetSize((laWidget*)HarmonyLogoWidget, 372, 210);
    laWidget_SetEnabled((laWidget*)HarmonyLogoWidget, LA_FALSE);
    laWidget_SetVisible((laWidget*)HarmonyLogoWidget, LA_FALSE);
    laWidget_SetOptimizationFlags((laWidget*)HarmonyLogoWidget, LA_WIDGET_OPT_OPAQUE);
    laWidget_SetScheme((laWidget*)HarmonyLogoWidget, &whiteScheme);
    laWidget_SetBackgroundType((laWidget*)HarmonyLogoWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)HarmonyLogoWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(HarmonyLogoWidget, &MHGSLogo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)HarmonyLogoWidget);

    SplashBar = laImageWidget_New();
    laWidget_SetPosition((laWidget*)SplashBar, 800, 391);
    laWidget_SetSize((laWidget*)SplashBar, 800, 91);
    laWidget_SetOptimizationFlags((laWidget*)SplashBar, LA_WIDGET_OPT_OPAQUE);
    laWidget_SetBackgroundType((laWidget*)SplashBar, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SplashBar, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(SplashBar, &Bar);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)SplashBar);

    SplashBarLogo = laImageWidget_New();
    laWidget_SetPosition((laWidget*)SplashBarLogo, 18, 413);
    laWidget_SetSize((laWidget*)SplashBarLogo, 202, 55);
    laWidget_SetEnabled((laWidget*)SplashBarLogo, LA_FALSE);
    laWidget_SetVisible((laWidget*)SplashBarLogo, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)SplashBarLogo, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SplashBarLogo, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(SplashBarLogo, &MicrochipLogo);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)SplashBarLogo);

}

static void ScreenCreate_MainScreen(laScreen* screen)
{
    laLayer* layer0;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 800, 480);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 1);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget = laImageWidget_New();
    laWidget_SetSize((laWidget*)ImageWidget, 800, 480);
    laWidget_SetScheme((laWidget*)ImageWidget, &mainScheme);
    laWidget_SetBackgroundType((laWidget*)ImageWidget, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)ImageWidget, LA_WIDGET_BORDER_NONE);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget);

}




