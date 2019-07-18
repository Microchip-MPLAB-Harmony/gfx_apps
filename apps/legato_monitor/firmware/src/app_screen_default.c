/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app_screen_default.c

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

#define PERIOD_ms 500
#define MAX_SYSTOLIC_PRESSURE 250
#define MIN_SYSTOLIC_PRESSURE 90
#define MAX_DIASTOLIC_PRESSURE 140
#define MIN_DIASTOLIC_PRESSURE 60
#define MAX_PULSE_RATE 220
#define MIN_PULSE_RATE 75

#define ELEVATED_SYSTOLIC_PRESSURE 120
#define HIGH1_SYSTOLIC_PRESSURE 130
#define HIGH2_SYSTOLIC_PRESSURE 140
#define HYPER_SYSTOLIC_PRESSURE 180

#define HIGH1_DIASTOLIC_PRESSURE 80
#define HIGH2_DIASTOLIC_PRESSURE 90
#define HYPER_DIASTOLIC_PRESSURE 120

static SYS_TIME_HANDLE updateTimer1000ms;

static leBool updateHeartFlag;
static leBool updateClockFlag;
static leBool touchDownFlag;
static leBool updateValuesFlag;
static leBool resetValuesFlag;
static leBool startMonitorFlag;

static char charBuff[16]; //char buffer
static leChar clockStrBuff[16] = {0};
static leChar sysStrBuff[8] = {0};
static leChar diaStrBuff[8] = {0};
static leChar pulseStrBuff[8] = {0};
static leChar clearStrBuff[8] = {0};

static leFixedString clockStr;
static leFixedString sysStr;
static leFixedString diaStr;
static leFixedString pulseStr;
static leFixedString clearStr;

static void updateClock(void)
{
    static unsigned int sec = 0;
    static unsigned int min = 0;
    static unsigned int hr = 12;

    sec++;
    if (sec == 60)
    {
        {
            sec = 0;
            min++;
            if (min == 60)
            {
                min = 0;
                hr++;
                if (hr == 24)
                {
                    hr = 0;
                }
            }
        }
    }    

    //create the time character string from hr, min, sec variables
    sprintf(charBuff, "%02u:%02u:%02u", hr, min, sec); 

    //convert the character string to leFixedString object
    clockStr.fn->setFromCStr(&clockStr, charBuff);    

    //Set ClockLabel text to object
    ClockLabel->fn->setString(ClockLabel, (leString*)&clockStr);   
}

static void updateHeartIcon(void)
{
    static unsigned int showHeart = 1;
        
    if (showHeart == 1)
    {
        HeartImage->fn->setVisible(HeartImage, LE_TRUE);
        showHeart = 0;
    }
    else
    {
        HeartImage->fn->setVisible(HeartImage, LE_FALSE);
        showHeart = 1;
    }
}

static void updateBloodPressure(void)
{   
    static int sys = MIN_SYSTOLIC_PRESSURE;
    static int sys_dec = 1;
    static int dia = MIN_DIASTOLIC_PRESSURE;
    static int dia_dec = 1;
    
    sys += sys_dec;
    
    if (sys == MAX_SYSTOLIC_PRESSURE)
        sys_dec = -1;
    else if (sys == MIN_SYSTOLIC_PRESSURE)
        sys_dec = 1;
    
    dia += dia_dec;
    
    if (dia == MAX_DIASTOLIC_PRESSURE)
        dia_dec = -1;
    else if (dia == MIN_DIASTOLIC_PRESSURE)
        dia_dec = 1;
    
    if (sys > HYPER_SYSTOLIC_PRESSURE || dia > HYPER_DIASTOLIC_PRESSURE)
    {
        SysLabel->fn->setScheme(SysLabel, &HypertensiveScheme);
        DiaLabel->fn->setScheme(DiaLabel, &HypertensiveScheme);
    }
    else if (sys > HIGH2_SYSTOLIC_PRESSURE || dia > HIGH2_DIASTOLIC_PRESSURE)
    {
        SysLabel->fn->setScheme(SysLabel, &HighStage2Scheme);
        DiaLabel->fn->setScheme(DiaLabel, &HighStage2Scheme);
    }
    else if (sys > HIGH1_SYSTOLIC_PRESSURE || dia > HIGH1_DIASTOLIC_PRESSURE)
    {
        SysLabel->fn->setScheme(SysLabel, &HighStage1Scheme);
        DiaLabel->fn->setScheme(DiaLabel, &HighStage1Scheme);        
    }
    else if (sys > ELEVATED_SYSTOLIC_PRESSURE && dia < HIGH1_DIASTOLIC_PRESSURE)
    {
        SysLabel->fn->setScheme(SysLabel, &ElevatedScheme);
        DiaLabel->fn->setScheme(DiaLabel, &ElevatedScheme);        
    }
    else
    {
        SysLabel->fn->setScheme(SysLabel, &NormalScheme);
        DiaLabel->fn->setScheme(DiaLabel, &NormalScheme);          
    }
   
    //create the time character string from hr, min, sec variables
    sprintf(charBuff, "%3d", sys); 

    //convert the character string to leFixedString object
    sysStr.fn->setFromCStr(&sysStr, charBuff);    

    //Set SysLabel text to object
    SysLabel->fn->setString(SysLabel, (leString*)&sysStr);      
    
    //create the time character string from hr, min, sec variables
    sprintf(charBuff, "%3d", dia); 
    
    //convert the character string to leFixedString object
    diaStr.fn->setFromCStr(&diaStr, charBuff);    

    //Set SysLabel text to object
    DiaLabel->fn->setString(DiaLabel, (leString*)&diaStr);       
}

static void updateHeartRate(void)
{   
    static int sys = MIN_PULSE_RATE;
    static int sys_dec = 1;
    
    sys += sys_dec;
    
    if (sys == MAX_PULSE_RATE)
        sys_dec = -1;
    else if (sys == MIN_PULSE_RATE)
        sys_dec = 1;
   
    //create the time character string from hr, min, sec variables
    sprintf(charBuff, "%d", sys); 

    //convert the character string to leFixedString object
    pulseStr.fn->setFromCStr(&pulseStr, charBuff);    

    //Set SysLabel text to object
    PulseLabel->fn->setString(PulseLabel, (leString*)&pulseStr);   
}

static void resetValues(void)
{
    //create the time character string from hr, min, sec variables
    sprintf(charBuff, "---"); 

    //convert the character string to leFixedString object
    pulseStr.fn->setFromCStr(&clearStr, charBuff);    

    //Update text
    PulseLabel->fn->setString(PulseLabel, (leString*)&clearStr); 
    DiaLabel->fn->setString(DiaLabel, (leString*)&clearStr);
    SysLabel->fn->setString(SysLabel, (leString*)&clearStr); 
    HeartImage->fn->setVisible(HeartImage, LE_FALSE);
}

static void updateTimer_Callback ( uintptr_t context )
{
    static uint32_t secondCounter = 0;
    static uint32_t updateCounter = 0;
    
    updateHeartFlag = LE_TRUE;
    
    secondCounter++;
    updateCounter++;
    
    //1s
    if (secondCounter == 2)
    {
        updateClockFlag = LE_TRUE;
        secondCounter = 0;
    }
    
    //2s
    if (updateCounter == 4)
    {
        updateValuesFlag = LE_TRUE;
        updateCounter = 0;
    }
}

void default_OnShow()
{
    updateHeartFlag = LE_FALSE;
    updateClockFlag = LE_FALSE;
    touchDownFlag = LE_FALSE;
    updateValuesFlag = LE_FALSE;
    resetValuesFlag = LE_FALSE;
    startMonitorFlag = LE_FALSE;
    
    leFixedString_Constructor(&clockStr, clockStrBuff, 16);
    clockStr.fn->setFont(&clockStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              string_ClockNums,
                                                              0));
    
    leFixedString_Constructor(&sysStr, sysStrBuff, 16);
    sysStr.fn->setFont(&sysStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              string_Nums,
                                                              0));
    
    leFixedString_Constructor(&diaStr, diaStrBuff, 16);
    diaStr.fn->setFont(&diaStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              string_Nums,
                                                              0));  
    
    leFixedString_Constructor(&pulseStr, pulseStrBuff, 16);
    pulseStr.fn->setFont(&pulseStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              string_Nums,
                                                              0));    
    
    leFixedString_Constructor(&clearStr, clearStrBuff, 8);
    clearStr.fn->setFont(&clearStr, leStringTable_GetStringFont(leGetState()->stringTable,
                                                              string_ClearVal,
                                                              0));  
    
    updateTimer1000ms = SYS_TIME_CallbackRegisterMS(updateTimer_Callback, 
                                        1,
                                        PERIOD_ms,
                                        SYS_TIME_PERIODIC);
}

void default_OnHide()
{
    SYS_TIME_TimerStop(updateTimer1000ms);
    SYS_TIME_TimerDestroy(updateTimer1000ms);
        
    clockStr.fn->destructor(&clockStr);
    sysStr.fn->destructor(&sysStr);
    diaStr.fn->destructor(&diaStr);
    pulseStr.fn->destructor(&pulseStr);   
    clearStr.fn->destructor(&clearStr);   
}

void default_OnUpdate()
{
    //Update clock
    if (updateClockFlag == LE_TRUE)
    {
        updateClockFlag = LE_FALSE;
        updateClock();
    }
    
    if (startMonitorFlag == LE_TRUE)
    {
        HeartImage->fn->setVisible(HeartImage, LE_TRUE);
        startMonitorFlag = LE_FALSE;
    }
    
    if (resetValuesFlag == LE_TRUE)
    {
        resetValues();
        resetValuesFlag = LE_FALSE;
    }
    
    //Update Heart and Values only when touched
    if (touchDownFlag == LE_TRUE)
    {
        if (updateHeartFlag == LE_TRUE)
        {
            updateHeartFlag = LE_FALSE;
            updateHeartIcon();
        }
        
        if (updateValuesFlag == LE_TRUE)
        {
            updateValuesFlag = LE_FALSE;
            updateBloodPressure();  
            updateHeartRate();
        }
    }
}

void ButtonWidget0_OnPressed(leButtonWidget* btn)
{
    touchDownFlag = LE_TRUE;
    startMonitorFlag = LE_TRUE;
}

void ButtonWidget0_OnReleased(leButtonWidget* btn)
{
    touchDownFlag = LE_FALSE;
    resetValuesFlag = LE_TRUE;
}