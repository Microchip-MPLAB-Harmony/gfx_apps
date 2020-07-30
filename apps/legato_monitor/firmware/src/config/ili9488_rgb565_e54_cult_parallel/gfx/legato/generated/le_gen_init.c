#include "gfx/legato/generated/le_gen_init.h"

static uint32_t currentScreen;

void legato_initialize(void)
{
    leSetStringTable(&stringTable);

    initializeStrings();

    screenInit_Splash();
    screenInit_default();

    currentScreen = -1;

    legato_showScreen(screenID_Splash);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

void legato_hideCurrentScreen()
{
    switch(currentScreen)
    {
        case screenID_Splash:
        {
            screenHide_Splash();
            currentScreen = 0;
            break;
        }
        case screenID_default:
        {
            screenHide_default();
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
        case screenID_Splash:
        {
            screenShow_Splash();
            currentScreen = id;
            break;
        }
        case screenID_default:
        {
            screenShow_default();
            currentScreen = id;
            break;
        }
    }
}

void legato_updateCurrentScreen(void)
{
    switch(currentScreen)
    {
        case screenID_Splash:
        {
            screenUpdate_Splash();
            break;
        }
        case screenID_default:
        {
            screenUpdate_default();
            break;
        }
    }
}

