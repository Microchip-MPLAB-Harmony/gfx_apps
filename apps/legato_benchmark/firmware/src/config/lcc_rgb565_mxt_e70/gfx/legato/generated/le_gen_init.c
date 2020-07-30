#include "gfx/legato/generated/le_gen_init.h"

static uint32_t currentScreen;

void legato_initialize(void)
{
    leSetStringTable(&stringTable);

    initializeStrings();

    screenInit_Screen0();
    screenInit_Screen1();
    screenInit_Screen2();
    screenInit_Screen3();

    currentScreen = -1;

    legato_showScreen(screenID_Screen0);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

void legato_hideCurrentScreen()
{
    switch(currentScreen)
    {
        case screenID_Screen0:
        {
            screenHide_Screen0();
            currentScreen = 0;
            break;
        }
        case screenID_Screen1:
        {
            screenHide_Screen1();
            currentScreen = 0;
            break;
        }
        case screenID_Screen2:
        {
            screenHide_Screen2();
            currentScreen = 0;
            break;
        }
        case screenID_Screen3:
        {
            screenHide_Screen3();
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
        case screenID_Screen0:
        {
            screenShow_Screen0();
            currentScreen = id;
            break;
        }
        case screenID_Screen1:
        {
            screenShow_Screen1();
            currentScreen = id;
            break;
        }
        case screenID_Screen2:
        {
            screenShow_Screen2();
            currentScreen = id;
            break;
        }
        case screenID_Screen3:
        {
            screenShow_Screen3();
            currentScreen = id;
            break;
        }
    }
}

void legato_updateCurrentScreen(void)
{
    switch(currentScreen)
    {
        case screenID_Screen0:
        {
            screenUpdate_Screen0();
            break;
        }
        case screenID_Screen1:
        {
            screenUpdate_Screen1();
            break;
        }
        case screenID_Screen2:
        {
            screenUpdate_Screen2();
            break;
        }
        case screenID_Screen3:
        {
            screenUpdate_Screen3();
            break;
        }
    }
}

