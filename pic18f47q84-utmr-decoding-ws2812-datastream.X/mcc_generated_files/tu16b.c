/**
  TU16B Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tu16b.c

  @Summary
    This is the generated driver implementation file for the TU16B driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides implementations for driver APIs for TU16B.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC18F47Q84
        Driver Version    :  2.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above or later
        MPLAB             :  MPLAB X 5.40
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "tu16b.h"


void TU16B_Initialize(void)
{
    //Stop Timer if already running
    TU16BCON0bits.ON = 0;
    //OSEN disabled; CLR disabled; LIMIT disabled; CAPT disabled; PRIF disabled; ZIF disabled; CIF disabled; 
    TU16BCON1 = 0x00;
    //EPOL non inverted; CSYNC enabled; START Timer counter starts at rising egde of ERS; RESET Timer counter resets at every first clock when starting and also at PR match; STOP Timer stops counting at PR match; 
    TU16BHLT = 0x6B;
    //CLK FOSC; 
    TU16BCLK = 0x02;
    //ERS TU16A_OUT; 
    TU16BERS = 0x02;
    //PS 0; 
    TU16BPS = 0x00;
    //PRH 0; 
    TU16BPRH = 0x00;
    //PRL 40; 
    TU16BPRL = 0x28;
    //TMRH 0; 
    TU16BTMRH = 0x00;
    //TMRL 0; 
    TU16BTMRL = 0x00;
    // Disabled TUI TU16B interrupt
    PIE5bits.TU16BIE = 0;
    //ON enabled; CPOL falling edge; OM level mode; OPOL low; RDSEL read; PRIE disabled; ZIE disabled; CIE disabled; 
    TU16BCON0 = 0xA0;
}

inline void TU16B_StartTimer(void)
{
    TU16BCON0bits.ON = 1;
}

inline void TU16B_StopTimer(void)
{
    TU16BCON0bits.ON = 0;
}

uint16_t TU16B_ReadCaptureValue(void)
{
    TU16BCON0bits.RDSEL = 0;
    return (uint16_t)(((uint16_t)TU16BCRH<< 8) | TU16BCRL);
}

uint16_t TU16B_CaptureOnCommand(void)
{
    TU16BCON1bits.CAPT = 1;
    while(TU16BCON1bits.CAPT == 1);
    /* 
       The above while loop is blocking code.
       If CSYNC=1 and ON=0 (or freeze=1), this bit will not clear unless there's
       clock provided. User must be careful here.
       Also when CSYNC=1 and timer clock is very slow, it will take forever
       to clear this bit because it takes 3 timer clocks to synchronize.
    */
    return TU16B_ReadCaptureValue();
}

uint16_t TU16B_ReadTimer(void)
{
    return (uint16_t)(((uint16_t)TU16BTMRH << 8) | (TU16BTMRL));
}

void TU16B_WriteTimer(uint16_t timerVal)
{
    TU16BTMRH = (uint8_t) (timerVal >> 8);
    TU16BTMRL = (uint8_t) (timerVal & 0xFF);
}

inline void TU16B_ClearCounter(void)
{
    TU16BCON1bits.CLR = 1;
    while(TU16BCON1bits.CLR == 1);
    /* 
       The above while loop is blocking code.
       If CSYNC=1 and ON=0 (or freeze=1), this bit will not clear unless there's
       clock provided. User must be careful here.
       Also when CSYNC=1 and timer clock is very slow, it will take forever
       to clear this bit because it takes 3 timer clocks to synchronize.
    */
}

void TU16B_SetPeriodValue(uint16_t prVal)
{
    TU16BPRH = (uint8_t)((prVal >> 8) & 0xFF);
    TU16BPRL = (uint8_t)(prVal & 0xFF);
}

inline void TU16B_EnablePRMatchInterrupt(void)
{
    TU16BCON0bits.PRIE = 1;
}

inline void TU16B_DisablePRMatchInterrupt(void)
{
    TU16BCON0bits.PRIE = 0;
}

inline void TU16B_EnableZeroInterrupt(void)
{
    TU16BCON0bits.ZIE = 1;
}

inline void TU16B_DisableZeroInterrupt(void)
{
    TU16BCON0bits.ZIE = 0;
}

inline void TU16B_EnableCaptureInterrupt(void)
{
    TU16BCON0bits.CIE = 1;
}

inline void TU16B_DisableCaptureInterrupt(void)
{
    TU16BCON0bits.CIE = 0;
}

inline bool TU16B_HasPRMatchOccured(void)
{
    return TU16BCON1bits.PRIF;
}

inline bool TU16B_HasResetOccured(void)
{
    return TU16BCON1bits.ZIF;
}

inline bool TU16B_HasCaptureOccured(void)
{
    return TU16BCON1bits.CIF;
}

inline bool TU16B_IsTimerRunning(void)
{
    return TU16BCON1bits.RUN;
}

inline void TU16B_EnableInterrupt(void)
{
    PIE5bits.TU16BIE = 1;
}

inline void TU16B_DisableInterrupt(void)
{
    PIE5bits.TU16BIE = 0;
}

inline bool TU16B_IsInterruptEnabled(void)
{
    return PIE5bits.TU16BIE;
}

inline void TU16B_ClearInterruptFlag(void)
{
}
