/*******************************************************************************
  LCDC PLIB Implementation

  Company:
    Microchip Technology Inc.

  File Name:
    plib_lcdc.c

  Summary:
    Function implementations for the LCDC (LCD Controller) PLIB.

  Description:
    This PLIB provides the interfaces to configure the LCD Controller (LCDC).
    This peripheral library implements a SUBSET of the register configurations
    for the LCDC. 

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2018 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
//DOM-IGNORE-END

#include "definitions.h"

void LCDC_SetPixelClockPolarity(LCDC_SIGNAL_POLARITY polarity)
{
    LCDC_REGS->LCDC_LCDCFG0 = (LCDC_REGS->LCDC_LCDCFG0 & ~LCDC_LCDCFG0_CLKPOL_Msk) | 
                                LCDC_LCDCFG0_CLKPOL(polarity == LCDC_POLARITY_NEGATIVE);
}

void LCDC_SetClockSourceSelection(LCDC_CLOCK_SOURCE source)
{
    LCDC_REGS->LCDC_LCDCFG0 = (LCDC_REGS->LCDC_LCDCFG0 & ~LCDC_LCDCFG0_CLKSEL_Msk) | 
                                LCDC_LCDCFG0_CLKSEL(source == LCDC_CLOCK_SOURCE_SYSTEM_2X);
}

void LCDC_SetPWMClockSourceSelection(LCDC_PWM_CLOCK_SOURCE source)
{
    LCDC_REGS->LCDC_LCDCFG0 = (LCDC_REGS->LCDC_LCDCFG0 & ~LCDC_LCDCFG0_CLKPWMSEL_Msk) | 
                                LCDC_LCDCFG0_CLKPWMSEL(source == LCDC_PWM_SOURCE_SYSTEM);
}

void LCDC_SetLayerClockGatingDisable(LCDC_LAYER_ID layer, bool disable)
{
    switch(layer)
    {
        case LCDC_LAYER_BASE:
            LCDC_REGS->LCDC_LCDCFG0 = (LCDC_REGS->LCDC_LCDCFG0 & ~LCDC_LCDCFG0_CGDISBASE_Msk) | 
                                LCDC_LCDCFG0_CGDISBASE(disable == false);
            break;
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_LCDCFG0 = (LCDC_REGS->LCDC_LCDCFG0 & ~LCDC_LCDCFG0_CGDISOVR1_Msk) | 
                                LCDC_LCDCFG0_CGDISOVR1(disable == false);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_LCDCFG0 = (LCDC_REGS->LCDC_LCDCFG0 & ~LCDC_LCDCFG0_CGDISOVR2_Msk) | 
                                LCDC_LCDCFG0_CGDISOVR2(disable == false);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_LCDCFG0 = (LCDC_REGS->LCDC_LCDCFG0 & ~LCDC_LCDCFG0_CGDISHEO_Msk) | 
                                LCDC_LCDCFG0_CGDISHEO(disable == false);
            break;
        case LCDC_LAYER_PP:
            LCDC_REGS->LCDC_LCDCFG0 = (LCDC_REGS->LCDC_LCDCFG0 & ~LCDC_LCDCFG0_CGDISPP_Msk) | 
                                LCDC_LCDCFG0_CGDISPP(disable == false);
            break;
        default:
            break;
    }
}

void LCDC_SetClockDivider(uint8_t value)
{
    LCDC_REGS->LCDC_LCDCFG0 = (LCDC_REGS->LCDC_LCDCFG0 & ~LCDC_LCDCFG0_CLKDIV_Msk) | 
                                  LCDC_LCDCFG0_CLKDIV(value - 2);
}

void LCDC_SetHSYNCPulseWidth(uint16_t value)
{
    LCDC_REGS->LCDC_LCDCFG1 = (LCDC_REGS->LCDC_LCDCFG1 & ~LCDC_LCDCFG1_HSPW_Msk) | 
                                  LCDC_LCDCFG1_HSPW(value);
}

void LCDC_SetVSYNCPulseWidth(uint16_t value)
{
    LCDC_REGS->LCDC_LCDCFG1 = (LCDC_REGS->LCDC_LCDCFG1 & ~LCDC_LCDCFG1_VSPW_Msk) | 
                                  LCDC_LCDCFG1_VSPW(value);
}

void LCDC_SetVerticalFrontPorchWidth(uint16_t value)
{
    LCDC_REGS->LCDC_LCDCFG2 = (LCDC_REGS->LCDC_LCDCFG2 & ~LCDC_LCDCFG2_VFPW_Msk) | 
                                  LCDC_LCDCFG2_VFPW(value - 1);
}

void LCDC_SetVerticalBackPorchWidth(uint16_t value)
{
    LCDC_REGS->LCDC_LCDCFG2 = (LCDC_REGS->LCDC_LCDCFG2 & ~LCDC_LCDCFG2_VBPW_Msk) | 
                                  LCDC_LCDCFG2_VBPW(value - 1);
}

void LCDC_SetHorizontalFrontPorchWidth(uint16_t value)
{
    LCDC_REGS->LCDC_LCDCFG3 = (LCDC_REGS->LCDC_LCDCFG3 & ~LCDC_LCDCFG3_HFPW_Msk) | 
                                  LCDC_LCDCFG3_HFPW(value - 1);
}

void LCDC_SetHorizontalBackPorchWidth(uint16_t value)
{
    LCDC_REGS->LCDC_LCDCFG4 = (LCDC_REGS->LCDC_LCDCFG4 & ~LCDC_LCDCFG3_HBPW_Msk) | 
                                  LCDC_LCDCFG3_HBPW(value - 1);
}

void LCDC_SetNumActiveRows(uint16_t value)
{
    LCDC_REGS->LCDC_LCDCFG4 = (LCDC_REGS->LCDC_LCDCFG4 & ~LCDC_LCDCFG4_RPF_Msk) | 
                                  LCDC_LCDCFG4_RPF(value - 1);
}

void LCDC_SetNumPixelsPerLine(uint16_t value)
{
    LCDC_REGS->LCDC_LCDCFG4 = (LCDC_REGS->LCDC_LCDCFG4 & ~LCDC_LCDCFG4_PPL_Msk) | 
                                  LCDC_LCDCFG4_PPL(value - 1);
}

void LCDC_SetHSYNCPolarity(LCDC_SIGNAL_POLARITY polarity)
{
    LCDC_REGS->LCDC_LCDCFG5 = (LCDC_REGS->LCDC_LCDCFG5 & ~LCDC_LCDCFG5_HSPOL_Msk) | 
                                  LCDC_LCDCFG5_HSPOL(polarity == LCDC_POLARITY_NEGATIVE);
}

void LCDC_SetVSYNCPolarity(LCDC_SIGNAL_POLARITY polarity)
{
    LCDC_REGS->LCDC_LCDCFG5 = (LCDC_REGS->LCDC_LCDCFG5 & ~LCDC_LCDCFG5_VSPOL_Msk) | 
                                  LCDC_LCDCFG5_VSPOL(polarity == LCDC_POLARITY_NEGATIVE);
}

void LCDC_SetVSYNCPulseStart(LCDC_VSYNC_SYNC_EDGE edge)
{
    LCDC_REGS->LCDC_LCDCFG5 = (LCDC_REGS->LCDC_LCDCFG5 & ~LCDC_LCDCFG5_VSPDLYS_Msk) | 
                                  LCDC_LCDCFG5_VSPDLYS(edge == LCDC_SYNC_EDGE_FIRST);
}

void LCDC_SetVSYNCPulseEnd(LCDC_VSYNC_SYNC_EDGE edge)
{
    LCDC_REGS->LCDC_LCDCFG5 = (LCDC_REGS->LCDC_LCDCFG5 & ~LCDC_LCDCFG5_VSPDLYE_Msk) | 
                                  LCDC_LCDCFG5_VSPDLYE(edge == LCDC_SYNC_EDGE_FIRST);
}

void LCDC_SetDisplaySignalPolarity(LCDC_SIGNAL_POLARITY polarity)
{
    LCDC_REGS->LCDC_LCDCFG5 = (LCDC_REGS->LCDC_LCDCFG5 & ~LCDC_LCDCFG5_DISPPOL_Msk) | 
                                  LCDC_LCDCFG5_DISPPOL(polarity == LCDC_POLARITY_NEGATIVE);
}

void LCDC_SetDitheringEnable(bool enable)
{
    LCDC_REGS->LCDC_LCDCFG5 = (LCDC_REGS->LCDC_LCDCFG5 & ~LCDC_LCDCFG5_DITHER_Msk) | 
                                  LCDC_LCDCFG5_DITHER(enable == true);
}

void LCDC_SetDisplaySignalSynchronization(bool synchronous)
{
    LCDC_REGS->LCDC_LCDCFG5 = (LCDC_REGS->LCDC_LCDCFG5 & ~LCDC_LCDCFG5_DISPDLY_Msk) | 
                                  LCDC_LCDCFG5_DISPDLY(synchronous == false);
}

void LCDC_SetOutputMode(LCDC_OUTPUT_COLOR_MODE mode)
{
    LCDC_REGS->LCDC_LCDCFG5 = (LCDC_REGS->LCDC_LCDCFG5 & ~LCDC_LCDCFG5_MODE_Msk) | 
                                  LCDC_LCDCFG5_MODE(mode);
}

void LCDC_SetPostPocessingEnable(bool enable)
{
    LCDC_REGS->LCDC_LCDCFG5 = (LCDC_REGS->LCDC_LCDCFG5 & ~LCDC_LCDCFG5_PP_Msk) | 
                                  LCDC_LCDCFG5_PP(enable == true);
}

void LCDC_SetVSYNCPulseSetupConfig(bool synchronous)
{
    LCDC_REGS->LCDC_LCDCFG5 = (LCDC_REGS->LCDC_LCDCFG5 & ~LCDC_LCDCFG5_VSPSU_Msk) | 
                                  LCDC_LCDCFG5_VSPSU(synchronous == false);
}

void LCDC_SetVSYNCPulseHoldConfig(bool synchronous)
{
    LCDC_REGS->LCDC_LCDCFG5 = (LCDC_REGS->LCDC_LCDCFG5 & ~LCDC_LCDCFG5_VSPHO_Msk) | 
                                  LCDC_LCDCFG5_VSPHO(synchronous == false);
}

void LCDC_SetDisplayGuardTime(uint16_t frames)
{
    LCDC_REGS->LCDC_LCDCFG5 = (LCDC_REGS->LCDC_LCDCFG5 & ~LCDC_LCDCFG5_GUARDTIME_Msk) | 
                                  LCDC_LCDCFG5_GUARDTIME(frames);
}

void LCDC_SetPWMPrescaler(uint8_t div)
{
    LCDC_REGS->LCDC_LCDCFG6 = (LCDC_REGS->LCDC_LCDCFG6 & ~LCDC_LCDCFG6_PWMPS_Msk) | 
                                  LCDC_LCDCFG6_PWMPS(div);
}

void LCDC_SetPWMSignalPolarity(LCDC_SIGNAL_POLARITY polarity)
{
    LCDC_REGS->LCDC_LCDCFG6 = (LCDC_REGS->LCDC_LCDCFG6 & ~LCDC_LCDCFG6_PWMPOL_Msk) | 
                                  LCDC_LCDCFG6_PWMPOL(polarity == LCDC_POLARITY_POSITIVE);
}

void LCDC_SetPWMCompareValue(uint32_t value)
{
    LCDC_REGS->LCDC_LCDCFG6 = (LCDC_REGS->LCDC_LCDCFG6 & ~LCDC_LCDCFG6_PWMCVAL_Msk) | 
                                  LCDC_LCDCFG6_PWMCVAL(value);
}

void LCDC_SetPixelClockEnable(bool enable)
{
    if (enable == true)
        LCDC_REGS->LCDC_LCDEN = (LCDC_REGS->LCDC_LCDEN & ~LCDC_LCDEN_CLKEN_Msk) | 
                                      LCDC_LCDEN_CLKEN(1);
    else
        LCDC_REGS->LCDC_LCDDIS = (LCDC_REGS->LCDC_LCDDIS & ~LCDC_LCDDIS_CLKDIS_Msk) | 
                                      LCDC_LCDDIS_CLKDIS(1);
}

void LCDC_SetSYNCEnable(bool enable)
{
    if (enable == true)
        LCDC_REGS->LCDC_LCDEN = (LCDC_REGS->LCDC_LCDEN & ~LCDC_LCDEN_SYNCEN_Msk) | 
                                  LCDC_LCDEN_SYNCEN(1);
    else
        LCDC_REGS->LCDC_LCDDIS = (LCDC_REGS->LCDC_LCDDIS & ~LCDC_LCDDIS_SYNCDIS_Msk) | 
                                      LCDC_LCDDIS_SYNCDIS(1);
}

void LCDC_SetDISPSignalEnable(bool enable)
{
    if (enable == true)
        LCDC_REGS->LCDC_LCDEN = (LCDC_REGS->LCDC_LCDEN & ~LCDC_LCDEN_DISPEN_Msk) | 
                                  LCDC_LCDEN_DISPEN(1);
    else
        LCDC_REGS->LCDC_LCDDIS = (LCDC_REGS->LCDC_LCDDIS & ~LCDC_LCDDIS_DISPDIS_Msk) | 
                                      LCDC_LCDDIS_DISPDIS(1);  
}

void LCDC_SetPWMEnable(bool enable)
{
    if (enable == true)
        LCDC_REGS->LCDC_LCDEN = (LCDC_REGS->LCDC_LCDEN & ~LCDC_LCDEN_PWMEN_Msk) | 
                                 LCDC_LCDEN_PWMEN(1);
    else
        LCDC_REGS->LCDC_LCDDIS = (LCDC_REGS->LCDC_LCDDIS & ~LCDC_LCDDIS_PWMDIS_Msk) | 
                                      LCDC_LCDDIS_PWMDIS(1);    
}

void LCDC_ClockReset( void )
{
    LCDC_REGS->LCDC_LCDDIS = (LCDC_REGS->LCDC_LCDDIS & ~LCDC_LCDDIS_CLKRST_Msk) | 
                              LCDC_LCDDIS_CLKRST(1);    
}

void LCDC_SYNCReset( void )
{
    LCDC_REGS->LCDC_LCDDIS = (LCDC_REGS->LCDC_LCDDIS & ~LCDC_LCDDIS_SYNCRST_Msk) | 
                              LCDC_LCDDIS_SYNCRST(1);    
}

void LCDC_DISPSignalReset( void )
{
    LCDC_REGS->LCDC_LCDDIS = (LCDC_REGS->LCDC_LCDDIS & ~LCDC_LCDDIS_DISPRST_Msk) | 
                              LCDC_LCDDIS_DISPRST(1);    
}

void LCDC_PWMReset( void )
{
    LCDC_REGS->LCDC_LCDDIS = (LCDC_REGS->LCDC_LCDDIS & ~LCDC_LCDDIS_PWMRST_Msk) | 
                              LCDC_LCDDIS_PWMRST(1); 
}

bool LCDC_GetPixelClockStatusRunning( void )
{
    return ((LCDC_REGS->LCDC_LCDSR & LCDC_LCDSR_CLKSTS_Msk) == LCDC_LCDSR_CLKSTS_Msk);
}

bool LCDC_GetTimingEngineStatusRunning( void )
{
    return ((LCDC_REGS->LCDC_LCDSR & LCDC_LCDSR_LCDSTS_Msk) == LCDC_LCDSR_LCDSTS_Msk);
}

bool LCDC_GetDisplaySignalStatusActivated( void )
{
    return ((LCDC_REGS->LCDC_LCDSR & LCDC_LCDSR_DISPSTS_Msk) == LCDC_LCDSR_DISPSTS_Msk);
}

bool LCDC_GetPWMSignalStatusActivated( void )
{
    return ((LCDC_REGS->LCDC_LCDSR & LCDC_LCDSR_PWMSTS_Msk) == LCDC_LCDSR_PWMSTS_Msk);
}

bool LCDC_GetSynchronizationStatusInProgress( void )
{
    return ((LCDC_REGS->LCDC_LCDSR & LCDC_LCDSR_SIPSTS_Msk) == LCDC_LCDSR_SIPSTS_Msk);
}

void LCDC_SetSOFInterruptEnable(bool enable)
{
    if (enable == true)
        LCDC_REGS->LCDC_LCDIER = (LCDC_REGS->LCDC_LCDIER & ~LCDC_LCDIER_SOFIE_Msk) | 
                                  LCDC_LCDIER_SOFIE(1);
    else
        LCDC_REGS->LCDC_LCDIDR = (LCDC_REGS->LCDC_LCDIDR & ~LCDC_LCDIDR_SOFID_Msk) | 
                                  LCDC_LCDIDR_SOFID(1);    
}

void LCDC_SetLCDDisableInterruptEnable(bool enable)
{
    if (enable == true)
        LCDC_REGS->LCDC_LCDIER = (LCDC_REGS->LCDC_LCDIER & ~LCDC_LCDIER_DISIE_Msk) | 
                                  LCDC_LCDIER_DISIE(1);
    else
        LCDC_REGS->LCDC_LCDIDR = (LCDC_REGS->LCDC_LCDIDR & ~LCDC_LCDIDR_DISID_Msk) | 
                                  LCDC_LCDIDR_DISID(1);    
}

void LCDC_WaitForSyncInProgress( void )
{
    while ((LCDC_REGS->LCDC_LCDSR & LCDC_LCDSR_SIPSTS_Msk));
}

void LCDC_WaitForClockRunning( void )
{
    while (!(LCDC_REGS->LCDC_LCDSR & LCDC_LCDSR_CLKSTS_Msk));
}

void LCDC_WaitForSynchronization( void )
{
    while (!(LCDC_REGS->LCDC_LCDSR & LCDC_LCDSR_LCDSTS_Msk));
}

void LCDC_WaitForDISPSignal( void )
{
    while (!(LCDC_REGS->LCDC_LCDSR & LCDC_LCDSR_DISPSTS_Msk));
}


static void _wait_for_clock_domain_sync(void)
{
	while ((LCDC_REGS->LCDC_LCDSR & LCDC_LCDSR_SIPSTS_Msk));
}

void LCDC_SetRGBModeInput(LCDC_LAYER_ID layer, LCDC_INPUT_COLOR_MODE mode)
{
    switch(layer)
    {
        case LCDC_LAYER_BASE:
            LCDC_REGS->LCDC_BASECFG1 = (LCDC_REGS->LCDC_BASECFG1 & ~LCDC_BASECFG1_RGBMODE_Msk) | 
                                        LCDC_BASECFG1_RGBMODE(mode);
          break;
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CFG1 = (LCDC_REGS->LCDC_OVR1CFG1 & ~LCDC_OVR1CFG1_RGBMODE_Msk) | 
                                        LCDC_OVR1CFG1_RGBMODE(mode);
          break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CFG1 = (LCDC_REGS->LCDC_OVR2CFG1 & ~LCDC_OVR2CFG1_RGBMODE_Msk) | 
                                        LCDC_OVR2CFG1_RGBMODE(mode);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCFG1 = (LCDC_REGS->LCDC_HEOCFG1 & ~LCDC_HEOCFG1_RGBMODE_Msk) | 
                                       LCDC_HEOCFG1_RGBMODE(mode);
            break;            
        case LCDC_LAYER_PP:
        default:
          break;
    }
}

void LCDC_SetDMAHeadPointer(LCDC_LAYER_ID layer, uint32_t head)
{
    switch(layer)
    {
        case LCDC_LAYER_BASE:
            LCDC_REGS->LCDC_BASEHEAD = (LCDC_REGS->LCDC_BASEHEAD & ~LCDC_BASEHEAD_HEAD_Msk) | 
                                        LCDC_BASEHEAD_HEAD(head);
          break;
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1HEAD = (LCDC_REGS->LCDC_OVR1HEAD & ~LCDC_OVR1HEAD_HEAD_Msk) | 
                                        LCDC_OVR1HEAD_HEAD(head);
          break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2HEAD = (LCDC_REGS->LCDC_OVR2HEAD & ~LCDC_OVR2HEAD_HEAD_Msk) | 
                                        LCDC_OVR2HEAD_HEAD(head);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOHEAD = (LCDC_REGS->LCDC_HEOHEAD & ~LCDC_OVR2HEAD_HEAD_Msk) | 
                                       LCDC_OVR2HEAD_HEAD(head);
            break;
        case LCDC_LAYER_PP:
        default:
          break;
    }
}

void LCDC_UpdateAddToQueue(LCDC_LAYER_ID layer)
{
    switch(layer)
    {
        case LCDC_LAYER_BASE:
            LCDC_REGS->LCDC_ATTR = (LCDC_REGS->LCDC_ATTR & ~LCDC_ATTR_BASEA2Q_Msk) | 
                                    LCDC_ATTR_BASEA2Q(1); 
            break;
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_ATTR = (LCDC_REGS->LCDC_ATTR & ~LCDC_ATTR_OVR1A2Q_Msk) | 
                                    LCDC_ATTR_OVR1A2Q(1); 
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_ATTR = (LCDC_REGS->LCDC_ATTR & ~LCDC_ATTR_OVR2A2Q_Msk) | 
                                    LCDC_ATTR_OVR2A2Q(1);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_ATTR = (LCDC_REGS->LCDC_ATTR & ~LCDC_ATTR_HEOA2Q_Msk) | 
                              LCDC_ATTR_HEOA2Q(1);
            break;
        case LCDC_LAYER_PP:
            LCDC_REGS->LCDC_ATTR = (LCDC_REGS->LCDC_ATTR & ~LCDC_ATTR_PPA2Q_Msk) | 
                              LCDC_ATTR_PPA2Q(1);
            break;
        default:
          break;
    }
}

void LCDC_SetWindowPosition(LCDC_LAYER_ID layer, uint16_t xpos, uint16_t ypos)
{
    switch(layer)
    {
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CFG2 = LCDC_OVR1CFG2_YPOS(ypos) | LCDC_OVR1CFG2_XPOS(xpos); 
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CFG2 = LCDC_OVR1CFG2_YPOS(ypos) | LCDC_OVR1CFG2_XPOS(xpos); 
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCFG2 = LCDC_HEOCFG2_YPOS(ypos) | LCDC_HEOCFG2_XPOS(xpos); 
            break;
        case LCDC_LAYER_PP:
        case LCDC_LAYER_BASE:
            //unsupported
        default:
          break;
    }
}

void LCDC_SetWindowSize(LCDC_LAYER_ID layer, uint16_t width, uint16_t height)
{
    switch(layer)
    {
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CFG3 = LCDC_OVR1CFG3_YSIZE(height - 1) | LCDC_OVR1CFG3_XSIZE(width - 1); 
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CFG3 = LCDC_OVR2CFG3_YSIZE(height - 1) | LCDC_OVR2CFG3_XSIZE(width - 1); 
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCFG3 = LCDC_HEOCFG3_YSIZE(height - 1) | LCDC_HEOCFG3_XSIZE(width - 1); 
            break;
        case LCDC_LAYER_PP:
        case LCDC_LAYER_BASE:
            //unsupported
        default:
          break;
    }
}

void LCDC_SetUseDMAPathEnable(LCDC_LAYER_ID layer, bool enable)
{
    switch(layer)
    {
        case LCDC_LAYER_BASE:
            LCDC_REGS->LCDC_BASECFG4 = (LCDC_REGS->LCDC_BASECFG4 & ~LCDC_BASECFG4_DMA_Msk) | 
                                LCDC_BASECFG4_DMA(enable == true);
            break;
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CFG9 = (LCDC_REGS->LCDC_OVR1CFG9 & ~LCDC_OVR1CFG9_DMA_Msk) | 
                                LCDC_OVR1CFG9_DMA(enable == true);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CFG9 = (LCDC_REGS->LCDC_OVR2CFG9 & ~LCDC_OVR2CFG9_DMA_Msk) | 
                                LCDC_OVR2CFG9_DMA(enable == true);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCFG12 = (LCDC_REGS->LCDC_HEOCFG12 & ~LCDC_HEOCFG12_DMA_Msk) | 
                                LCDC_HEOCFG12_DMA(enable == true);
            break;
        case LCDC_LAYER_PP:
        default:
          break;
    }
}

void LCDC_SetDMAAddressRegister(LCDC_LAYER_ID layer, uint32_t addr)
{
    switch(layer)
    {
        case LCDC_LAYER_BASE:
            LCDC_REGS->LCDC_BASEADDR = LCDC_BASEADDR_ADDR(addr);
            break;
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1ADDR = LCDC_OVR1ADDR_ADDR(addr);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2ADDR = LCDC_OVR2ADDR_ADDR(addr);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOADDR = LCDC_HEOADDR_ADDR(addr);
            break;
        case LCDC_LAYER_PP:
            LCDC_REGS->LCDC_PPADDR = LCDC_PPADDR_ADDR(addr);
            break;
        default:
          break;
    }
}

void LCDC_SetDMADescriptorNextAddress(LCDC_LAYER_ID layer, uint32_t next)
{
    switch(layer)
    {
        case LCDC_LAYER_BASE:
            LCDC_REGS->LCDC_BASENEXT = LCDC_BASENEXT_NEXT(next);  
            break;
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1NEXT = LCDC_OVR1NEXT_NEXT(next);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2NEXT = LCDC_OVR2NEXT_NEXT(next);  
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEONEXT = LCDC_HEONEXT_NEXT(next);  
            break;
        case LCDC_LAYER_PP:
            LCDC_REGS->LCDC_PPNEXT = LCDC_PPNEXT_NEXT(next);  
            break;
        default:
          break;
    }  
}

void LCDC_SetTransferDescriptorFetchEnable(LCDC_LAYER_ID layer, bool enable)
{
    switch(layer)
    {
        case LCDC_LAYER_BASE:
            LCDC_REGS->LCDC_BASECTRL = (LCDC_REGS->LCDC_BASECTRL & ~LCDC_BASECTRL_DFETCH_Msk) | 
                                        LCDC_BASECTRL_DFETCH(enable == true);
            break;
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CTRL = (LCDC_REGS->LCDC_OVR1CTRL & ~LCDC_OVR1CTRL_DFETCH_Msk) | 
                                        LCDC_OVR1CTRL_DFETCH(enable == true);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CTRL = (LCDC_REGS->LCDC_OVR2CTRL & ~LCDC_OVR2CTRL_DFETCH_Msk) | 
                                        LCDC_OVR2CTRL_DFETCH(enable == true);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCTRL = (LCDC_REGS->LCDC_HEOCTRL & ~LCDC_HEOCTRL_DFETCH_Msk) | 
                                        LCDC_HEOCTRL_DFETCH(enable == true);
            break;
        case LCDC_LAYER_PP:
            LCDC_REGS->LCDC_PPCTRL = (LCDC_REGS->LCDC_PPCTRL & ~LCDC_PPCTRL_DFETCH_Msk) | 
                                        LCDC_PPCTRL_DFETCH(enable == true);
            break;
        default:
          break;
    }
}

void LCDC_UpdateOverlayAttributesEnable(LCDC_LAYER_ID layer)
{
    switch(layer)
    {
        case LCDC_LAYER_BASE:
            LCDC_REGS->LCDC_BASECHER = (LCDC_REGS->LCDC_BASECHER & ~LCDC_BASECHER_UPDATEEN_Msk) | 
                                        LCDC_BASECHER_UPDATEEN(1);
            break;
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CHER = (LCDC_REGS->LCDC_OVR1CHER & ~LCDC_OVR1CHER_UPDATEEN_Msk) | 
                                        LCDC_OVR1CHER_UPDATEEN(1);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CHER = (LCDC_REGS->LCDC_OVR2CHER & ~LCDC_OVR2CHER_UPDATEEN_Msk) | 
                                        LCDC_OVR2CHER_UPDATEEN(1);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCHER = (LCDC_REGS->LCDC_HEOCHER & ~LCDC_HEOCHER_UPDATEEN_Msk) | 
                                        LCDC_HEOCHER_UPDATEEN(1);
            break;
        case LCDC_LAYER_PP:
            LCDC_REGS->LCDC_PPCHER = (LCDC_REGS->LCDC_PPCHER & ~LCDC_PPCHER_UPDATEEN_Msk) | 
                                        LCDC_PPCHER_UPDATEEN(1);
            break;
        default:
          break;
    }  
}

void LCDC_SetChannelEnable(LCDC_LAYER_ID layer, bool enable)
{
    switch(layer)
    {
        case LCDC_LAYER_BASE:
            if (enable == true)
                LCDC_REGS->LCDC_BASECHER = (LCDC_REGS->LCDC_BASECHER & ~LCDC_BASECHER_CHEN_Msk) | 
                                            LCDC_BASECHER_CHEN(1);
            else
                LCDC_REGS->LCDC_BASECHDR = (LCDC_REGS->LCDC_BASECHDR & ~LCDC_BASECHDR_CHDIS_Msk) | 
                                            LCDC_BASECHDR_CHDIS(1);    
            break;
        case LCDC_LAYER_OVR1:
            if (enable == true)
                LCDC_REGS->LCDC_OVR1CHER = (LCDC_REGS->LCDC_OVR1CHER & ~LCDC_OVR1CHER_CHEN_Msk) | 
                                            LCDC_OVR1CHER_CHEN(1);
            else
                LCDC_REGS->LCDC_OVR1CHDR = (LCDC_REGS->LCDC_BASECHDR & ~LCDC_OVR1CHDR_CHDIS_Msk) | 
                                            LCDC_OVR1CHDR_CHDIS(1);    
            break;
        case LCDC_LAYER_OVR2:
            if (enable == true)
                LCDC_REGS->LCDC_OVR2CHER = (LCDC_REGS->LCDC_OVR2CHER & ~LCDC_OVR2CHER_CHEN_Msk) | 
                                            LCDC_OVR2CHER_CHEN(1);
            else
                LCDC_REGS->LCDC_OVR2CHDR = (LCDC_REGS->LCDC_OVR2CHDR & ~LCDC_OVR2CHDR_CHDIS_Msk) | 
                                            LCDC_OVR2CHDR_CHDIS(1);    
            break;
        case LCDC_LAYER_HEO:
            if (enable == true)
                LCDC_REGS->LCDC_HEOCHER = (LCDC_REGS->LCDC_HEOCHER & ~LCDC_HEOCHER_CHEN_Msk) | 
                                            LCDC_HEOCHER_CHEN(1);
            else
                LCDC_REGS->LCDC_HEOCHDR = (LCDC_REGS->LCDC_HEOCHDR & ~LCDC_HEOCHDR_CHDIS_Msk) | 
                                            LCDC_HEOCHDR_CHDIS(1);    
            break;
        case LCDC_LAYER_PP:
            if (enable == true)
                LCDC_REGS->LCDC_PPCHER = (LCDC_REGS->LCDC_PPCHER & ~LCDC_PPCHER_CHEN_Msk) | 
                                            LCDC_PPCHER_CHEN(1);
            else
                LCDC_REGS->LCDC_PPCHDR = (LCDC_REGS->LCDC_PPCHDR & ~LCDC_PPCHDR_CHDIS_Msk) | 
                                            LCDC_PPCHDR_CHDIS(1);    
            break;
        default:
          break;
    }  
}

void LCDC_AddToQueueEnable(LCDC_LAYER_ID layer)
{
    switch(layer)
    {
        case LCDC_LAYER_BASE:
            LCDC_REGS->LCDC_BASECHER = (LCDC_REGS->LCDC_BASECHER & ~LCDC_BASECHSR_A2QSR_Msk) | 
                                        LCDC_BASECHER_A2QEN(1);
            break;
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CHER = (LCDC_REGS->LCDC_OVR1CHER & ~LCDC_OVR1CHSR_A2QSR_Msk) | 
                                        LCDC_OVR1CHER_A2QEN(1);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CHER = (LCDC_REGS->LCDC_OVR2CHER & ~LCDC_OVR2CHSR_A2QSR_Msk) | 
                                        LCDC_OVR2CHER_A2QEN(1);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCHER = (LCDC_REGS->LCDC_HEOCHER & ~LCDC_HEOCHSR_A2QSR_Msk) | 
                                        LCDC_HEOCHER_A2QEN(1);
            break;
        case LCDC_LAYER_PP:
            LCDC_REGS->LCDC_PPCHER = (LCDC_REGS->LCDC_PPCHER & ~LCDC_PPCHSR_A2QSR_Msk) | 
                                        LCDC_PPCHER_A2QEN(1);
            break;
        default:
          break;
    }  
}

void LCDC_SetBlenderOverlayLayerEnable(LCDC_LAYER_ID layer, bool enable)
{
    switch(layer)
    {
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CFG9 = (LCDC_REGS->LCDC_OVR1CFG9 & ~LCDC_OVR1CFG9_OVR_Msk) | 
                                        LCDC_OVR1CFG9_OVR(enable == true);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CFG9 = (LCDC_REGS->LCDC_OVR2CFG9 & ~LCDC_OVR2CFG9_OVR_Msk) | 
                                        LCDC_OVR2CFG9_OVR(enable == true);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCFG12 = (LCDC_REGS->LCDC_HEOCFG12 & ~LCDC_HEOCFG12_OVR_Msk) | 
                                        LCDC_HEOCFG12_OVR(enable == true);
            break;
        //Not supported            
        case LCDC_LAYER_BASE: 
        case LCDC_LAYER_PP:
        default:
          break;
    }  
}

void LCDC_SetBlenderDMALayerEnable(LCDC_LAYER_ID layer, bool enable)
{
    switch(layer)
    {
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CFG9 = (LCDC_REGS->LCDC_OVR1CFG9 & ~LCDC_OVR1CFG9_DMA_Msk) | 
                                        LCDC_OVR1CFG9_DMA(enable == true);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CFG9 = (LCDC_REGS->LCDC_OVR2CFG9 & ~LCDC_OVR2CFG9_DMA_Msk) | 
                                        LCDC_OVR2CFG9_DMA(enable == true);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCFG12 = (LCDC_REGS->LCDC_HEOCFG12 & ~LCDC_HEOCFG12_DMA_Msk) | 
                                        LCDC_HEOCFG12_DMA(enable == true);
            break;
        //Not supported            
        case LCDC_LAYER_BASE: 
        case LCDC_LAYER_PP:
        default:
          break;
    }  
}

void LCDC_SetBlenderLocalAlphaEnable(LCDC_LAYER_ID layer, bool enable)
{
    switch(layer)
    {
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CFG9 = (LCDC_REGS->LCDC_OVR1CFG9 & ~LCDC_OVR1CFG9_LAEN_Msk) | 
                                        LCDC_OVR1CFG9_LAEN(enable == true);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CFG9 = (LCDC_REGS->LCDC_OVR2CFG9 & ~LCDC_OVR2CFG9_LAEN_Msk) | 
                                        LCDC_OVR2CFG9_LAEN(enable == true);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCFG12 = (LCDC_REGS->LCDC_HEOCFG12 & ~LCDC_HEOCFG12_LAEN_Msk) | 
                                        LCDC_HEOCFG12_LAEN(enable == true);
            break;
        //Not supported            
        case LCDC_LAYER_BASE: 
        case LCDC_LAYER_PP:
        default:
          break;
    }  
}

void LCDC_SetBlenderIteratedColorEnable(LCDC_LAYER_ID layer, bool enable)
{
    switch(layer)
    {
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CFG9 = (LCDC_REGS->LCDC_OVR1CFG9 & ~LCDC_OVR1CFG9_ITER2BL_Msk) | 
                                        LCDC_OVR1CFG9_ITER2BL(enable == true);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CFG9 = (LCDC_REGS->LCDC_OVR2CFG9 & ~LCDC_OVR2CFG9_ITER2BL_Msk) | 
                                        LCDC_OVR2CFG9_ITER2BL(enable == true);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCFG12 = (LCDC_REGS->LCDC_HEOCFG12 & ~LCDC_HEOCFG12_ITER2BL_Msk) | 
                                        LCDC_HEOCFG12_ITER2BL(enable == true);
            break;
        //Not supported            
        case LCDC_LAYER_BASE: 
        case LCDC_LAYER_PP:
        default:
          break;
    }  
}

void LCDC_SetBlenderUseIteratedColor(LCDC_LAYER_ID layer, bool use)
{
    switch(layer)
    {
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CFG9 = (LCDC_REGS->LCDC_OVR1CFG9 & ~LCDC_OVR1CFG9_ITER_Msk) | 
                                        LCDC_OVR1CFG9_ITER(use == true);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CFG9 = (LCDC_REGS->LCDC_OVR2CFG9 & ~LCDC_OVR2CFG9_ITER_Msk) | 
                                        LCDC_OVR2CFG9_ITER(use == true);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCFG12 = (LCDC_REGS->LCDC_HEOCFG12 & ~LCDC_HEOCFG12_ITER_Msk) | 
                                        LCDC_HEOCFG12_ITER(use == true);
            break;
        //Not supported            
        case LCDC_LAYER_BASE: 
        case LCDC_LAYER_PP:
        default:
          break;
    }  
}

void LCDC_SetBlenderGlobalAlphaEnable(LCDC_LAYER_ID layer, bool enable)
{
    switch(layer)
    {
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CFG9 = (LCDC_REGS->LCDC_OVR1CFG9 & ~LCDC_OVR1CFG9_GAEN_Msk) | 
                                        LCDC_OVR1CFG9_GAEN(enable == true);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CFG9 = (LCDC_REGS->LCDC_OVR2CFG9 & ~LCDC_OVR2CFG9_GAEN_Msk) | 
                                        LCDC_OVR2CFG9_GAEN(enable == true);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCFG12 = (LCDC_REGS->LCDC_HEOCFG12 & ~LCDC_HEOCFG12_GAEN_Msk) | 
                                        LCDC_HEOCFG12_GAEN(enable == true);
            break;
        //Not supported            
        case LCDC_LAYER_BASE: 
        case LCDC_LAYER_PP:
        default:
          break;
    }  
}

void LCDC_SetBlenderGlobalAlpha(LCDC_LAYER_ID layer, uint8_t alpha)
{
    switch(layer)
    {
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_OVR1CFG9 = (LCDC_REGS->LCDC_OVR1CFG9 & ~LCDC_OVR1CFG9_GA_Msk) | 
                                        LCDC_OVR1CFG9_GA(alpha);
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_OVR2CFG9 = (LCDC_REGS->LCDC_OVR2CFG9 & ~LCDC_OVR2CFG9_GA_Msk) | 
                                        LCDC_OVR2CFG9_GA(alpha);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_HEOCFG12 = (LCDC_REGS->LCDC_HEOCFG12 & ~LCDC_HEOCFG12_GA_Msk) | 
                                        LCDC_HEOCFG12_GA(alpha);
            break;
        //Not supported            
        case LCDC_LAYER_BASE: 
        case LCDC_LAYER_PP:
        default:
          break;
    }  
}


void LCDC_UpdateAttribute(LCDC_LAYER_ID layer)
{
    switch(layer)
    {
        case LCDC_LAYER_OVR1:
            LCDC_REGS->LCDC_ATTR = (LCDC_REGS->LCDC_ATTR & ~LCDC_ATTR_OVR1_Msk) | 
                                    LCDC_ATTR_OVR1(1);             
            break;
        case LCDC_LAYER_OVR2:
            LCDC_REGS->LCDC_ATTR = (LCDC_REGS->LCDC_ATTR & ~LCDC_ATTR_OVR2_Msk) | 
                                    LCDC_ATTR_OVR2(1);
            break;
        case LCDC_LAYER_HEO:
            LCDC_REGS->LCDC_ATTR = (LCDC_REGS->LCDC_ATTR & ~LCDC_ATTR_HEO_Msk) | 
                                    LCDC_ATTR_HEO(1);
            break;
        case LCDC_LAYER_BASE:
            LCDC_REGS->LCDC_ATTR = (LCDC_REGS->LCDC_ATTR & ~LCDC_ATTR_BASE_Msk) | 
                                    LCDC_ATTR_BASE(1);
            break;          
        case LCDC_LAYER_PP:
            LCDC_REGS->LCDC_ATTR = (LCDC_REGS->LCDC_ATTR & ~LCDC_ATTR_PP_Msk) | 
                                    LCDC_ATTR_PP(1);
            break;
        default:
          break;
    }   

}