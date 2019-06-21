/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    screen_default.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

#include "gfx/legato/generated/screen/le_gen_screen_default.h"

#include <stdio.h>
#include <string.h>

#include "system/time/sys_time.h"

#define MAX_SYSTOLE 150
#define MAX_DIASTOLE 100
#define MAX_PULSE 150

SYS_TIME_HANDLE updateTimer500ms;

static uint32_t counter500ms = 0;

static leFont* sysDiaFont;

static leChar sysValue1Buff[16] = {0};
static leFixedString sysValue1Str;

static leChar sysValue10Buff[16] = {0};
static leFixedString sysValue10Str;

static leChar sysValue100Buff[16] = {0};
static leFixedString sysValue100Str;

static leChar diaValue1Buff[16] = {0};
static leFixedString diaValue1Str;

static leChar diaValue10Buff[16] = {0};
static leFixedString diaValue10Str;

static leChar diaValue100Buff[16] = {0};
static leFixedString diaValue100Str;

static leChar pulseValue1Buff[16] = {0};
static leFixedString pulseValue1Str;

static leChar pulseValue10Buff[16] = {0};
static leFixedString pulseValue10Str;

static leChar pulseValue100Buff[16] = {0};
static leFixedString pulseValue100Str;

static leBool shouldUpdateHeartBeat;
static leBool shouldUpdateNumbers;

static uint32_t systole = 888;
static uint32_t diastole = 888;
static uint32_t pulse = 888;

static int32_t systoleinc = 1;
static int32_t diastoleinc = 2;
static int32_t pulseinc = 3;

static char charBuff[16] = {0};

static uint32_t digit1;
static uint32_t digit10;
static uint32_t digit100;

static uint32_t olddigit1;
static uint32_t olddigit10;
static uint32_t olddigit100;

static void updateTimer_Callback500ms(uintptr_t context)
{    
    shouldUpdateHeartBeat = LE_TRUE;
    
    if(counter500ms > 6)
    {
        counter500ms = 0;
        
        shouldUpdateNumbers = LE_TRUE;
    }
    
    counter500ms++;
}

static void updateHeartBeat()
{
    leBool showing = HeartImage->fn->getVisible(HeartImage);
    
    showing = !showing;
    
    HeartImage->fn->setVisible(HeartImage, showing);
}

static void updateSystole()
{
    uint32_t oldvalue = systole;

    if (systole > 800)
        systole = 120;

    if (systole >= MAX_SYSTOLE)
        systoleinc = -1;
    else if (systole <= 60)
        systoleinc = 1;

    systole += systoleinc;   

    digit1 = systole%10;
    digit10 = (systole/10)%10;
    digit100 = (systole/100)%10;

    olddigit1 = oldvalue%10;
    olddigit10 = (oldvalue/10)%10;
    olddigit100 = (oldvalue/100)%10;    

    if (olddigit1 != digit1)
    {
        if (digit1 == 0 && digit10 == 0 && digit100 == 0)
            sprintf(charBuff, " ");
        else
            sprintf(charBuff, "%u", (unsigned int)digit1);

        sysValue1Str.fn->setFromCStr(&sysValue1Str, charBuff);
        SysValue1->fn->setString(SysValue1, (leString*)&sysValue1Str);      
    }

    if (olddigit10 != digit10)
    {
        if (digit100 == 0 && digit10 == 0)
            sprintf(charBuff, " ");
        else
            sprintf(charBuff, "%u", (unsigned int)digit10);

        sysValue10Str.fn->setFromCStr(&sysValue10Str, charBuff);
        SysValue10->fn->setString(SysValue10, (leString*)&sysValue10Str);       
    }

    if (olddigit100 != digit100)
    {
        if (digit100 == 0)
            sprintf(charBuff, " ");
        else
            sprintf(charBuff, "%u", (unsigned int)digit100);

        sysValue100Str.fn->setFromCStr(&sysValue100Str, charBuff);
        SysValue100->fn->setString(SysValue100, (leString*)&sysValue100Str);      
    }
}

static void updateDiastole()
{
    uint32_t oldvalue = diastole;

    if (diastole > 800)
        diastole = 85;

    if (diastole >= MAX_DIASTOLE)
        diastoleinc = -2;
    else if (diastole <= 40)
        diastoleinc = 2;

    diastole += diastoleinc;   

    digit1 = diastole%10;
    digit10 = (diastole/10)%10;
    digit100 = (diastole/100)%10;

    olddigit1 = oldvalue%10;
    olddigit10 = (oldvalue/10)%10;
    olddigit100 = (oldvalue/100)%10;    

    if (olddigit1 != digit1)
    {
        if (digit1 == 0 && digit10 == 0 && digit100 == 0)
            sprintf(charBuff, " ");
        else
            sprintf(charBuff, "%u", (unsigned int)digit1);

        diaValue1Str.fn->setFromCStr(&diaValue1Str, charBuff);
        DiaValue1->fn->setString(DiaValue1, (leString*)&diaValue1Str); 
    }

    if (olddigit10 != digit10)
    {
        if (digit100 == 0 && digit10 == 0)
            sprintf(charBuff, " ");
        else
            sprintf(charBuff, "%u", (unsigned int)digit10);

        diaValue10Str.fn->setFromCStr(&diaValue10Str, charBuff);
        DiaValue10->fn->setString(DiaValue10, (leString*)&diaValue10Str); 
    }

    if (olddigit100 != digit100)
    {
        if (digit100 == 0)
            sprintf(charBuff, " ");
        else
            sprintf(charBuff, "%u", (unsigned int)digit100);

        diaValue100Str.fn->setFromCStr(&diaValue100Str, charBuff);
        DiaValue100->fn->setString(DiaValue100, (leString*)&diaValue100Str);    
    }
}

static void updatePulse()
{
    uint32_t oldvalue = pulse;

    if (pulse > 800)
        pulse = 65;

    if (pulse >= MAX_PULSE)
        pulseinc = -3;
    else if (pulse <= 40)
        pulseinc = 3;

    pulse += pulseinc;   

    digit1 = pulse%10;
    digit10 = (pulse/10)%10;
    digit100 = (pulse/100)%10;

    olddigit1 = oldvalue%10;
    olddigit10 = (oldvalue/10)%10;
    olddigit100 = (oldvalue/100)%10;    

    if (olddigit1 != digit1)
    {
        if (digit1 == 0 && digit10 == 0 && digit100 == 0)
            sprintf(charBuff, " ");
        else
            sprintf(charBuff, "%u", (unsigned int)digit1);

        pulseValue1Str.fn->setFromCStr(&pulseValue1Str, charBuff);
        PulseValue1->fn->setString(PulseValue1, (leString*)&pulseValue1Str); 
    }

    if (olddigit10 != digit10)
    {
        if (digit100 == 0 && digit10 == 0)
            sprintf(charBuff, " ");
        else
            sprintf(charBuff, "%u", (unsigned int)digit10);

        pulseValue10Str.fn->setFromCStr(&pulseValue10Str, charBuff);
        PulseValue10->fn->setString(PulseValue10, (leString*)&pulseValue10Str);      
    }

    if (olddigit100 != digit100)
    {
        if (digit100 == 0)
            sprintf(charBuff, " ");
        else
            sprintf(charBuff, "%u", (unsigned int)digit100);

        pulseValue100Str.fn->setFromCStr(&pulseValue100Str, charBuff);
        PulseValue100->fn->setString(PulseValue100, (leString*)&pulseValue100Str);   
    } 
}

static void updateNumbers()
{
    updateSystole();
    updateDiastole();
    updatePulse();
}

void default_OnShow()
{
    sysDiaFont = leStringTable_FontIndexLookup(leGetState()->stringTable,
                                               string_SysDiaValueNums,
                                               0);

    leFixedString_Constructor(&sysValue1Str, sysValue1Buff, 16);
    sysValue1Str.fn->setFont(&sysValue1Str, sysDiaFont);

    leFixedString_Constructor(&sysValue10Str, sysValue10Buff, 16);
    sysValue10Str.fn->setFont(&sysValue10Str, sysDiaFont);

    leFixedString_Constructor(&sysValue100Str, sysValue100Buff, 16);
    sysValue100Str.fn->setFont(&sysValue100Str, sysDiaFont);

    leFixedString_Constructor(&diaValue1Str, diaValue1Buff, 16);
    diaValue1Str.fn->setFont(&diaValue1Str, sysDiaFont);

    leFixedString_Constructor(&diaValue10Str, diaValue10Buff, 16);
    diaValue10Str.fn->setFont(&diaValue10Str, sysDiaFont);

    leFixedString_Constructor(&diaValue100Str, diaValue100Buff, 16);
    diaValue100Str.fn->setFont(&diaValue100Str, sysDiaFont);

    leFixedString_Constructor(&pulseValue1Str, pulseValue1Buff, 16);
    pulseValue1Str.fn->setFont(&pulseValue1Str, sysDiaFont);

    leFixedString_Constructor(&pulseValue10Str, pulseValue10Buff, 16);
    pulseValue10Str.fn->setFont(&pulseValue10Str, sysDiaFont);

    leFixedString_Constructor(&pulseValue100Str, pulseValue100Buff, 16);
    pulseValue100Str.fn->setFont(&pulseValue100Str, sysDiaFont);

    updateTimer500ms = SYS_TIME_CallbackRegisterMS(updateTimer_Callback500ms, 
                                                  1,
                                                  300,
                                                  SYS_TIME_PERIODIC);
}

void default_OnHide()
{
    sysValue1Str.fn->destructor(&sysValue1Str);
    sysValue10Str.fn->destructor(&sysValue10Str);
    sysValue100Str.fn->destructor(&sysValue100Str);
    diaValue1Str.fn->destructor(&diaValue1Str);
    diaValue10Str.fn->destructor(&diaValue10Str);
    diaValue100Str.fn->destructor(&diaValue100Str);
    pulseValue1Str.fn->destructor(&pulseValue1Str);
    pulseValue10Str.fn->destructor(&pulseValue10Str);
    pulseValue100Str.fn->destructor(&pulseValue100Str);
}

void default_OnUpdate()
{
    if(shouldUpdateHeartBeat == LE_TRUE)
    {
        updateHeartBeat();
        
        shouldUpdateHeartBeat = LE_FALSE;
    }
    
    if(shouldUpdateNumbers == LE_TRUE)
    {
        updateNumbers();
        
        shouldUpdateNumbers = LE_FALSE;
    }
}