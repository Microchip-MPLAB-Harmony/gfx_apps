#include "gfx/legato/generated/le_gen_init.h"

static uint32_t currentScreen;

void legato_initialize(void)
{
    legato_initialize_schemes();

    leSetStringTable(&stringTable);

    currentScreen = -1;

    legato_showScreen(screenID_SplashScreen);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

void legato_hideCurrentScreen()
{
    switch(currentScreen)
    {
        case screenID_SplashScreen:
        {
            screenHide_SplashScreen();
            currentScreen = 0;
            break;
        }
        case screenID_MainMenu:
        {
            screenHide_MainMenu();
            currentScreen = 0;
            break;
        }
        case screenID_ListWheelDemoScreen:
        {
            screenHide_ListWheelDemoScreen();
            currentScreen = 0;
            break;
        }
        case screenID_TouchTestDemoScreen:
        {
            screenHide_TouchTestDemoScreen();
            currentScreen = 0;
            break;
        }
        case screenID_KeypadDemoScreen:
        {
            screenHide_KeypadDemoScreen();
            currentScreen = 0;
            break;
        }
        case screenID_AlphaBlendingDemoScreen:
        {
            screenHide_AlphaBlendingDemoScreen();
            currentScreen = 0;
            break;
        }
        case screenID_SlideShowDemoScreen:
        {
            screenHide_SlideShowDemoScreen();
            currentScreen = 0;
            break;
        }
        case screenID_SettingsScreen:
        {
            screenHide_SettingsScreen();
            currentScreen = 0;
            break;
        }
        case screenID_MainMenuHelp:
        {
            screenHide_MainMenuHelp();
            currentScreen = 0;
            break;
        }
        case screenID_ListWheelHelpScreen:
        {
            screenHide_ListWheelHelpScreen();
            currentScreen = 0;
            break;
        }
        case screenID_TouchTestHelpScreen:
        {
            screenHide_TouchTestHelpScreen();
            currentScreen = 0;
            break;
        }
        case screenID_KeypadHelpScreen:
        {
            screenHide_KeypadHelpScreen();
            currentScreen = 0;
            break;
        }
        case screenID_AlphaBlendingHelpScreen:
        {
            screenHide_AlphaBlendingHelpScreen();
            currentScreen = 0;
            break;
        }
        case screenID_SlideshowHelpScreen:
        {
            screenHide_SlideshowHelpScreen();
            currentScreen = 0;
            break;
        }
    }
}

void legato_showScreen(uint32_t id)
{
    legato_hideCurrentScreen(currentScreen);

    switch(id)
    {
        case screenID_SplashScreen:
        {
            screenShow_SplashScreen();
            currentScreen = id;
            break;
        }
        case screenID_MainMenu:
        {
            screenShow_MainMenu();
            currentScreen = id;
            break;
        }
        case screenID_ListWheelDemoScreen:
        {
            screenShow_ListWheelDemoScreen();
            currentScreen = id;
            break;
        }
        case screenID_TouchTestDemoScreen:
        {
            screenShow_TouchTestDemoScreen();
            currentScreen = id;
            break;
        }
        case screenID_KeypadDemoScreen:
        {
            screenShow_KeypadDemoScreen();
            currentScreen = id;
            break;
        }
        case screenID_AlphaBlendingDemoScreen:
        {
            screenShow_AlphaBlendingDemoScreen();
            currentScreen = id;
            break;
        }
        case screenID_SlideShowDemoScreen:
        {
            screenShow_SlideShowDemoScreen();
            currentScreen = id;
            break;
        }
        case screenID_SettingsScreen:
        {
            screenShow_SettingsScreen();
            currentScreen = id;
            break;
        }
        case screenID_MainMenuHelp:
        {
            screenShow_MainMenuHelp();
            currentScreen = id;
            break;
        }
        case screenID_ListWheelHelpScreen:
        {
            screenShow_ListWheelHelpScreen();
            currentScreen = id;
            break;
        }
        case screenID_TouchTestHelpScreen:
        {
            screenShow_TouchTestHelpScreen();
            currentScreen = id;
            break;
        }
        case screenID_KeypadHelpScreen:
        {
            screenShow_KeypadHelpScreen();
            currentScreen = id;
            break;
        }
        case screenID_AlphaBlendingHelpScreen:
        {
            screenShow_AlphaBlendingHelpScreen();
            currentScreen = id;
            break;
        }
        case screenID_SlideshowHelpScreen:
        {
            screenShow_SlideshowHelpScreen();
            currentScreen = id;
            break;
        }
    }
}

void legato_updateCurrentScreen(void)
{
    switch(currentScreen)
    {
        case screenID_SplashScreen:
        {
            screenUpdate_SplashScreen();
            break;
        }
        case screenID_MainMenu:
        {
            screenUpdate_MainMenu();
            break;
        }
        case screenID_ListWheelDemoScreen:
        {
            screenUpdate_ListWheelDemoScreen();
            break;
        }
        case screenID_TouchTestDemoScreen:
        {
            screenUpdate_TouchTestDemoScreen();
            break;
        }
        case screenID_KeypadDemoScreen:
        {
            screenUpdate_KeypadDemoScreen();
            break;
        }
        case screenID_AlphaBlendingDemoScreen:
        {
            screenUpdate_AlphaBlendingDemoScreen();
            break;
        }
        case screenID_SlideShowDemoScreen:
        {
            screenUpdate_SlideShowDemoScreen();
            break;
        }
        case screenID_SettingsScreen:
        {
            screenUpdate_SettingsScreen();
            break;
        }
        case screenID_MainMenuHelp:
        {
            screenUpdate_MainMenuHelp();
            break;
        }
        case screenID_ListWheelHelpScreen:
        {
            screenUpdate_ListWheelHelpScreen();
            break;
        }
        case screenID_TouchTestHelpScreen:
        {
            screenUpdate_TouchTestHelpScreen();
            break;
        }
        case screenID_KeypadHelpScreen:
        {
            screenUpdate_KeypadHelpScreen();
            break;
        }
        case screenID_AlphaBlendingHelpScreen:
        {
            screenUpdate_AlphaBlendingHelpScreen();
            break;
        }
        case screenID_SlideshowHelpScreen:
        {
            screenUpdate_SlideshowHelpScreen();
            break;
        }
    }
}

