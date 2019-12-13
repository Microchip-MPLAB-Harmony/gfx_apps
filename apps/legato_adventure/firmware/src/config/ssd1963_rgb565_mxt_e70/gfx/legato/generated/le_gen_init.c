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
        case screenID_MainScreen:
        {
            screenHide_MainScreen();
            currentScreen = 0;
            break;
        }
        case screenID_InfoScreen:
        {
            screenHide_InfoScreen();
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
        case screenID_MainScreen:
        {
            screenShow_MainScreen();
            currentScreen = id;
            break;
        }
        case screenID_InfoScreen:
        {
            screenShow_InfoScreen();
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
        case screenID_MainScreen:
        {
            screenUpdate_MainScreen();
            break;
        }
    }
}

