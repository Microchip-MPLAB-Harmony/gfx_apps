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

laScheme BlackBaseScheme;
laScheme SemiTransScheme;
laScheme ClearScheme;
laScheme RedColorScheme;
laImageWidget* ImageWidget1;
laImageWidget* ImageWidget3;
laImageWidget* ImageWidget4;
laImageWidget* BackgroundImageWidget;
laImageSequenceWidget* ImageSequenceWidget5;
laRectangleWidget* IndicatorBlockPanel;
laDrawSurfaceWidget* RPMDrawSurfaceWidget;
laDrawSurfaceWidget* SpeedDrawSurfaceWidget;
laImageWidget* MapPointImage;
laRectangleWidget* WindshieldBlockPanel;
laButtonWidget* CenterButtonWidget;
laButtonWidget* EngineOnButton;
laImageWidget* WindshieldImage;
laImageWidget* MHGCLogoImage;
laImageWidget* TurnLeftImageWidget;
laImageWidget* TurnRightImageWidget;
laImageWidget* ImageWidget;
laImageWidget* ImageWidget2;


static void ScreenCreate_Splash(laScreen* screen);
static void ScreenCreate_Main(laScreen* screen);


int32_t libaria_initialize(void)
{
    laScreen* screen;

    laScheme_Initialize(&BlackBaseScheme, GFX_COLOR_MODE_RGBA_8888);
    BlackBaseScheme.base = 0xFF;
    BlackBaseScheme.highlight = 0xC8D0D4FF;
    BlackBaseScheme.highlightLight = 0xFFFFFFFF;
    BlackBaseScheme.shadow = 0x808080FF;
    BlackBaseScheme.shadowDark = 0x404040FF;
    BlackBaseScheme.foreground = 0xFF;
    BlackBaseScheme.foregroundInactive = 0xD6E3E7FF;
    BlackBaseScheme.foregroundDisabled = 0x808080FF;
    BlackBaseScheme.background = 0xFF;
    BlackBaseScheme.backgroundInactive = 0xD6E3E7FF;
    BlackBaseScheme.backgroundDisabled = 0xC8D0D4FF;
    BlackBaseScheme.text = 0xFF;
    BlackBaseScheme.textHighlight = 0xFFFF;
    BlackBaseScheme.textHighlightText = 0xFFFFFFFF;
    BlackBaseScheme.textInactive = 0xD6E3E7FF;
    BlackBaseScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&SemiTransScheme, GFX_COLOR_MODE_RGBA_8888);
    SemiTransScheme.base = 0xAF;
    SemiTransScheme.highlight = 0xC8D0D4FF;
    SemiTransScheme.highlightLight = 0xFFFFFFFF;
    SemiTransScheme.shadow = 0x808080FF;
    SemiTransScheme.shadowDark = 0x404040FF;
    SemiTransScheme.foreground = 0xFF;
    SemiTransScheme.foregroundInactive = 0xD6E3E7FF;
    SemiTransScheme.foregroundDisabled = 0x808080FF;
    SemiTransScheme.background = 0xFFFFFFFF;
    SemiTransScheme.backgroundInactive = 0xD6E3E7FF;
    SemiTransScheme.backgroundDisabled = 0xC8D0D4FF;
    SemiTransScheme.text = 0xFF;
    SemiTransScheme.textHighlight = 0xFFFF;
    SemiTransScheme.textHighlightText = 0xFFFFFFFF;
    SemiTransScheme.textInactive = 0xD6E3E7FF;
    SemiTransScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&ClearScheme, GFX_COLOR_MODE_RGBA_8888);
    ClearScheme.base = 0xC8D0D4FF;
    ClearScheme.highlight = 0xC8D0D4FF;
    ClearScheme.highlightLight = 0xFFFFFFFF;
    ClearScheme.shadow = 0x808080FF;
    ClearScheme.shadowDark = 0x404040FF;
    ClearScheme.foreground = 0xFF;
    ClearScheme.foregroundInactive = 0xD6E3E7FF;
    ClearScheme.foregroundDisabled = 0x808080FF;
    ClearScheme.background = 0x0;
    ClearScheme.backgroundInactive = 0xD6E3E7FF;
    ClearScheme.backgroundDisabled = 0xC8D0D4FF;
    ClearScheme.text = 0xFF;
    ClearScheme.textHighlight = 0xFFFF;
    ClearScheme.textHighlightText = 0xFFFFFFFF;
    ClearScheme.textInactive = 0xD6E3E7FF;
    ClearScheme.textDisabled = 0x8C9294FF;

    laScheme_Initialize(&RedColorScheme, GFX_COLOR_MODE_RGBA_8888);
    RedColorScheme.base = 0xC8D0D4FF;
    RedColorScheme.highlight = 0xC8D0D4FF;
    RedColorScheme.highlightLight = 0xFFFFFFFF;
    RedColorScheme.shadow = 0x808080FF;
    RedColorScheme.shadowDark = 0x404040FF;
    RedColorScheme.foreground = 0xFF0000FF;
    RedColorScheme.foregroundInactive = 0xD6E3E7FF;
    RedColorScheme.foregroundDisabled = 0x808080FF;
    RedColorScheme.background = 0xFFFFFFFF;
    RedColorScheme.backgroundInactive = 0xD6E3E7FF;
    RedColorScheme.backgroundDisabled = 0xC8D0D4FF;
    RedColorScheme.text = 0xFF;
    RedColorScheme.textHighlight = 0xFFFF;
    RedColorScheme.textHighlightText = 0xFFFFFFFF;
    RedColorScheme.textInactive = 0xD6E3E7FF;
    RedColorScheme.textDisabled = 0x8C9294FF;

    GFX_Set(GFXF_DRAW_PIPELINE_MODE, GFX_PIPELINE_GCUGPU);
    laContext_SetStringTable(&stringTable);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_Splash);
    laContext_AddScreen(screen);

    screen = laScreen_New(LA_FALSE, LA_FALSE, &ScreenCreate_Main);
    laContext_AddScreen(screen);

    laContext_SetActiveScreen(0);

	return 0;
}

static void ScreenCreate_Splash(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_FILL);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    ImageWidget1 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget1, 120, 60);
    laWidget_SetSize((laWidget*)ImageWidget1, 241, 140);
    laWidget_SetBackgroundType((laWidget*)ImageWidget1, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget1, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget1, &PIC100MPLAB0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageWidget1);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);

    laScreen_SetLayer(screen, 1, layer1);

    ImageWidget3 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget3, 480, 217);
    laWidget_SetSize((laWidget*)ImageWidget3, 480, 55);
    laWidget_SetBackgroundType((laWidget*)ImageWidget3, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget3, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget3, &Bar);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)ImageWidget3);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);

    laScreen_SetLayer(screen, 2, layer2);

    ImageWidget4 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget4, 17, 231);
    laWidget_SetSize((laWidget*)ImageWidget4, 121, 33);
    laWidget_SetVisible((laWidget*)ImageWidget4, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)ImageWidget4, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget4, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget4, &MicrochipLogo);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)ImageWidget4);

}

static void ScreenCreate_Main(laScreen* screen)
{
    laLayer* layer0;
    laLayer* layer1;
    laLayer* layer2;

    layer0 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer0, 0, 0);
    laWidget_SetSize((laWidget*)layer0, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer0, LA_WIDGET_BACKGROUND_NONE);
    laLayer_SetBufferCount(layer0, 2);

    laScreen_SetLayer(screen, 0, layer0);

    BackgroundImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)BackgroundImageWidget, 0, 102);
    laWidget_SetSize((laWidget*)BackgroundImageWidget, 480, 173);
    laWidget_SetBackgroundType((laWidget*)BackgroundImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)BackgroundImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(BackgroundImageWidget, &Background_Image_Dashboard2);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)BackgroundImageWidget);

    ImageSequenceWidget5 = laImageSequenceWidget_New();
    laWidget_SetSize((laWidget*)ImageSequenceWidget5, 480, 102);
    laWidget_SetBackgroundType((laWidget*)ImageSequenceWidget5, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageSequenceWidget5, LA_WIDGET_BORDER_NONE);
    laImageSequenceWidget_SetImageCount(ImageSequenceWidget5, 4);
    laImageSequenceWidget_SetImage(ImageSequenceWidget5, 0, &view);
    laImageSequenceWidget_SetImage(ImageSequenceWidget5, 1, &view1);
    laImageSequenceWidget_SetImage(ImageSequenceWidget5, 2, &view2);
    laImageSequenceWidget_SetImage(ImageSequenceWidget5, 3, &view3);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)ImageSequenceWidget5);

    IndicatorBlockPanel = laRectangleWidget_New();
    laWidget_SetPosition((laWidget*)IndicatorBlockPanel, 175, 140);
    laWidget_SetSize((laWidget*)IndicatorBlockPanel, 130, 99);
    laWidget_SetScheme((laWidget*)IndicatorBlockPanel, &BlackBaseScheme);
    laWidget_SetBackgroundType((laWidget*)IndicatorBlockPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)IndicatorBlockPanel, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(IndicatorBlockPanel, 0);
    laWidget_AddChild((laWidget*)layer0, (laWidget*)IndicatorBlockPanel);

    layer1 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer1, 0, 0);
    laWidget_SetSize((laWidget*)layer1, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer1, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer1, &ClearScheme);
    laLayer_SetBufferCount(layer1, 2);

    laScreen_SetLayer(screen, 1, layer1);

    RPMDrawSurfaceWidget = laDrawSurfaceWidget_New();
    laWidget_SetPosition((laWidget*)RPMDrawSurfaceWidget, 12, 112);
    laWidget_SetSize((laWidget*)RPMDrawSurfaceWidget, 150, 150);
    laWidget_SetBackgroundType((laWidget*)RPMDrawSurfaceWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)RPMDrawSurfaceWidget, LA_WIDGET_BORDER_NONE);
    laDrawSurfaceWidget_SetDrawCallback(RPMDrawSurfaceWidget, &RPMDrawSurfaceWidget_DrawNotificationEvent);

    laWidget_AddChild((laWidget*)layer1, (laWidget*)RPMDrawSurfaceWidget);

    SpeedDrawSurfaceWidget = laDrawSurfaceWidget_New();
    laWidget_SetPosition((laWidget*)SpeedDrawSurfaceWidget, 319, 112);
    laWidget_SetSize((laWidget*)SpeedDrawSurfaceWidget, 150, 150);
    laWidget_SetBackgroundType((laWidget*)SpeedDrawSurfaceWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)SpeedDrawSurfaceWidget, LA_WIDGET_BORDER_NONE);
    laDrawSurfaceWidget_SetDrawCallback(SpeedDrawSurfaceWidget, &SpeedDrawSurfaceWidget_DrawNotificationEvent);

    laWidget_AddChild((laWidget*)layer1, (laWidget*)SpeedDrawSurfaceWidget);

    MapPointImage = laImageWidget_New();
    laWidget_SetPosition((laWidget*)MapPointImage, 276, 150);
    laWidget_SetSize((laWidget*)MapPointImage, 6, 6);
    laWidget_SetVisible((laWidget*)MapPointImage, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)MapPointImage, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)MapPointImage, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(MapPointImage, &mapPoint);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)MapPointImage);

    WindshieldBlockPanel = laRectangleWidget_New();
    laWidget_SetSize((laWidget*)WindshieldBlockPanel, 480, 102);
    laWidget_SetScheme((laWidget*)WindshieldBlockPanel, &SemiTransScheme);
    laWidget_SetBackgroundType((laWidget*)WindshieldBlockPanel, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetBorderType((laWidget*)WindshieldBlockPanel, LA_WIDGET_BORDER_NONE);
    laRectangleWidget_SetThickness(WindshieldBlockPanel, 0);
    laWidget_AddChild((laWidget*)layer1, (laWidget*)WindshieldBlockPanel);

    layer2 = laLayer_New();
    laWidget_SetPosition((laWidget*)layer2, 0, 0);
    laWidget_SetSize((laWidget*)layer2, 480, 272);
    laWidget_SetBackgroundType((laWidget*)layer2, LA_WIDGET_BACKGROUND_FILL);
    laWidget_SetScheme((laWidget*)layer2, &ClearScheme);
    laLayer_SetBufferCount(layer2, 2);

    laScreen_SetLayer(screen, 2, layer2);

    CenterButtonWidget = laButtonWidget_New();
    laWidget_SetSize((laWidget*)CenterButtonWidget, 480, 272);
    laWidget_SetBackgroundType((laWidget*)CenterButtonWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)CenterButtonWidget, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetPressedEventCallback(CenterButtonWidget, &CenterButtonWidget_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(CenterButtonWidget, &CenterButtonWidget_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)CenterButtonWidget);

    EngineOnButton = laButtonWidget_New();
    laWidget_SetPosition((laWidget*)EngineOnButton, 426, 218);
    laWidget_SetSize((laWidget*)EngineOnButton, 54, 54);
    laWidget_SetBackgroundType((laWidget*)EngineOnButton, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)EngineOnButton, LA_WIDGET_BORDER_NONE);
    laButtonWidget_SetToggleable(EngineOnButton, LA_TRUE);
    laButtonWidget_SetPressedImage(EngineOnButton, &enginestartstop120on);
    laButtonWidget_SetReleasedImage(EngineOnButton, &enginestartstop120);
    laButtonWidget_SetPressedOffset(EngineOnButton, 0);
    laButtonWidget_SetPressedEventCallback(EngineOnButton, &EngineOnButton_PressedEvent);
    laButtonWidget_SetReleasedEventCallback(EngineOnButton, &EngineOnButton_ReleasedEvent);

    laWidget_AddChild((laWidget*)layer2, (laWidget*)EngineOnButton);

    WindshieldImage = laImageWidget_New();
    laWidget_SetSize((laWidget*)WindshieldImage, 480, 102);
    laWidget_SetBackgroundType((laWidget*)WindshieldImage, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)WindshieldImage, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(WindshieldImage, &TopWindShieldBars);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)WindshieldImage);

    MHGCLogoImage = laImageWidget_New();
    laWidget_SetPosition((laWidget*)MHGCLogoImage, 210, 85);
    laWidget_SetSize((laWidget*)MHGCLogoImage, 60, 56);
    laWidget_SetBackgroundType((laWidget*)MHGCLogoImage, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)MHGCLogoImage, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(MHGCLogoImage, &MPLABGraphics100);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)MHGCLogoImage);

    TurnLeftImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)TurnLeftImageWidget, 76, 77);
    laWidget_SetSize((laWidget*)TurnLeftImageWidget, 20, 20);
    laWidget_SetVisible((laWidget*)TurnLeftImageWidget, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)TurnLeftImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TurnLeftImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(TurnLeftImageWidget, &TurnLeft);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)TurnLeftImageWidget);

    TurnRightImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)TurnRightImageWidget, 387, 77);
    laWidget_SetSize((laWidget*)TurnRightImageWidget, 20, 20);
    laWidget_SetVisible((laWidget*)TurnRightImageWidget, LA_FALSE);
    laWidget_SetBackgroundType((laWidget*)TurnRightImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)TurnRightImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(TurnRightImageWidget, &TurnRight);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)TurnRightImageWidget);

    ImageWidget = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget, 72, 173);
    laWidget_SetSize((laWidget*)ImageWidget, 30, 30);
    laWidget_SetBackgroundType((laWidget*)ImageWidget, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget, &centercircle2);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)ImageWidget);

    ImageWidget2 = laImageWidget_New();
    laWidget_SetPosition((laWidget*)ImageWidget2, 379, 173);
    laWidget_SetSize((laWidget*)ImageWidget2, 30, 30);
    laWidget_SetBackgroundType((laWidget*)ImageWidget2, LA_WIDGET_BACKGROUND_NONE);
    laWidget_SetBorderType((laWidget*)ImageWidget2, LA_WIDGET_BORDER_NONE);
    laImageWidget_SetImage(ImageWidget2, &centercircle2);
    laWidget_AddChild((laWidget*)layer2, (laWidget*)ImageWidget2);

}



int32_t libaria_preprocess_assets(void)
{

    // process images configured for preprocessing
    laUtils_PreprocessImage(&Bar,0xA83FD000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&view,0xA82FD000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&view1,0xA833D000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&view2,0xA837D000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&view3,0xA83BD000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&TurnLeft,0xA841D000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);
    laUtils_PreprocessImage(&TurnRight,0xA841E000,GFX_COLOR_MODE_RGBA_8888,GFX_TRUE,&laContext_GetActive()->memIntf);

    return 0;
}

