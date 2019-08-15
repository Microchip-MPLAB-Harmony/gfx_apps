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
        case screenID_FPSCounters:
        {
            screenHide_FPSCounters();
            currentScreen = 0;
            break;
        }
        case screenID_FPSMotion:
        {
            screenHide_FPSMotion();
            currentScreen = 0;
            break;
        }
        case screenID_FPSImages:
        {
            screenHide_FPSImages();
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
        case screenID_FPSCounters:
        {
            screenShow_FPSCounters();
            currentScreen = id;
            break;
        }
        case screenID_FPSMotion:
        {
            screenShow_FPSMotion();
            currentScreen = id;
            break;
        }
        case screenID_FPSImages:
        {
            screenShow_FPSImages();
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
        case screenID_FPSCounters:
        {
            screenUpdate_FPSCounters();
            break;
        }
        case screenID_FPSMotion:
        {
            screenUpdate_FPSMotion();
            break;
        }
        case screenID_FPSImages:
        {
            screenUpdate_FPSImages();
            break;
        }
    }
}

