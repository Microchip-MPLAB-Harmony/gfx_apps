#include "gfx/legato/generated/le_gen_init.h"

static uint32_t currentScreen;

void legato_initialize(void)
{
    leSetStringTable(&stringTable);

    screenInit_Intro();
    screenInit_MainMenu();
    screenInit_ColorScreen();

    currentScreen = -1;

    legato_showScreen(screenID_Intro);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

void legato_hideCurrentScreen()
{
    switch(currentScreen)
    {
        case screenID_Intro:
        {
            screenHide_Intro();
            currentScreen = 0;
            break;
        }
        case screenID_MainMenu:
        {
            screenHide_MainMenu();
            currentScreen = 0;
            break;
        }
        case screenID_ColorScreen:
        {
            screenHide_ColorScreen();
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
        case screenID_Intro:
        {
            screenShow_Intro();
            currentScreen = id;
            break;
        }
        case screenID_MainMenu:
        {
            screenShow_MainMenu();
            currentScreen = id;
            break;
        }
        case screenID_ColorScreen:
        {
            screenShow_ColorScreen();
            currentScreen = id;
            break;
        }
    }
}

void legato_updateCurrentScreen(void)
{
    switch(currentScreen)
    {
        case screenID_Intro:
        {
            screenUpdate_Intro();
            break;
        }
        case screenID_MainMenu:
        {
            screenUpdate_MainMenu();
            break;
        }
        case screenID_ColorScreen:
        {
            screenUpdate_ColorScreen();
            break;
        }
    }
}

