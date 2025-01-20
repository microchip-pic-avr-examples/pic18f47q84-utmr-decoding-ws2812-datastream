/**
 * TU16B Generated Driver File
 *
 * @file tu16b.c
 *  
 * @ingroup tu16b
 *
 * @brief This file contains the API definitions for the TU16B module.
 *
 * @version TU16B Driver Version 3.0.0
 *
 * @version Package Version 2.0.0
 */

 /*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include <xc.h>
#include "../tu16b.h"

static void (*TU16B_PeriodMatchCallback)(void); 
static void TU16B_PeriodMatchDefaultCallback(void);
static void (*TU16B_ZeroMatchCallback)(void);
static void TU16B_ZeroMatchDefaultCallback(void);
static void (*TU16B_CaptureEventCallback)(void); 
static void TU16B_CaptureEventDefaultCallback(void);

void TU16B_Initialize(void)
{
    TU16BCON0bits.ON = 0;        //Stop TU16B

    TU16BCON1 = (0 << _TU16BCON1_CIF_POSN)   // CIF disabled
        | (0 << _TU16BCON1_ZIF_POSN)   // ZIF disabled
        | (0 << _TU16BCON1_PRIF_POSN)   // PRIF disabled
        | (0 << _TU16BCON1_CAPT_POSN)   // CAPT disabled
        | (0 << _TU16BCON1_LIMIT_POSN)   // LIMIT disabled
        | (0 << _TU16BCON1_CLR_POSN)   // CLR disabled
        | (0 << _TU16BCON1_OSEN_POSN);  // OSEN disabled
    
    TU16BHLT = (3 << _TU16BHLT_STOP_POSN)   // STOP At PR Match
        | (2 << _TU16BHLT_RESET_POSN)   // RESET At Start and PR match
        | (2 << _TU16BHLT_START_POSN)   // START Rising ERS edge
        | (1 << _TU16BHLT_CSYNC_POSN)   // CSYNC enabled
        | (0 << _TU16BHLT_EPOL_POSN);  // EPOL non inverted
    
    TU16BCLK = (3 << _TU16BCLK_CLK_POSN);  // CLK HFINTOSC
    
    TU16BERS = (2 << _TU16BERS_ERS_POSN);  // ERS TU16A_OUT
    
    TU16BPS = (0 << _TU16BPS_PS_POSN);  // PS 0x0
    
    TU16BPRH = 0x0;
    TU16BPRL = 0x32;

    TU16BTMRH = 0x0;
    TU16BTMRL = 0x0;

    TU16B_PeriodMatchCallback = TU16B_PeriodMatchDefaultCallback;
    TU16B_ZeroMatchCallback = TU16B_ZeroMatchDefaultCallback;
    TU16B_CaptureEventCallback = TU16B_CaptureEventDefaultCallback;

    TU16BCON0 = (0 << _TU16BCON0_CIE_POSN)   // CIE disabled
        | (0 << _TU16BCON0_ZIE_POSN)   // ZIE disabled
        | (0 << _TU16BCON0_PRIE_POSN)   // PRIE disabled
        | (0 << _TU16BCON0_RDSEL_POSN)   // RDSEL read
        | (0 << _TU16BCON0_OPOL_POSN)   // OPOL low
        | (1 << _TU16BCON0_OM_POSN)   // OM level mode
        | (0 << _TU16BCON0_CPOL_POSN)   // CPOL falling edge
        | (1 << _TU16BCON0_ON_POSN);  // ON enabled  

    PIE5bits.TU16BIE = 0;     // Disable TUI Interrupt
}

void TU16B_Deinitialize(void)
{
    TU16BCON0bits.ON = 0;
    TU16BCON0 = 0x0;
    TU16BCON1 = 0x0;
    TU16BHLT = 0x40;
    TU16BCLK = 0x0;
    TU16BERS = 0x0;
    TU16BPS = 0x0;   
    TU16BPRH = 0xFF;
    TU16BPRL = 0xFF;
    TU16BTMRH = 0x0;
    TU16BTMRL = 0x0;
    PIE5bits.TU16BIE = 0;
}

void TU16B_Start(void)
{
    TU16BCON0bits.ON = 1;
}

void TU16B_Stop(void)
{
    TU16BCON0bits.ON = 0;
}

uint16_t TU16B_CaptureValueGet(void)
{
    uint16_t captureValue;

    TU16BCON0bits.RDSEL = 0;

    captureValue = ((uint16_t)TU16BCRH<< 8) 
                    | (uint16_t)TU16BCRL;

    return captureValue;
}

uint16_t TU16B_OnCommandCapture(void)
{
    TU16BCON1bits.CAPT = 1;

    while(1U == TU16BCON1bits.CAPT)
    {
        //Wait to clear CAPT bit
    }
    /* cppcheck-suppress misra-c2012-8.7 */
    return TU16B_CaptureValueGet();
}

uint16_t TU16B_CounterGet(void)
{
    uint16_t timerVal;
    bool onValue = TU16BCON0bits.ON;

    TU16BCON0bits.ON = 0;
    TU16BCON0bits.RDSEL = 1;

    timerVal = ((uint16_t)TU16BTMRH << 8) 
            | (uint16_t)TU16BTMRL;

    TU16BCON0bits.ON = onValue;

    return timerVal;
}

void TU16B_CounterSet(uint16_t timerVal)
{
    bool onValue = TU16BCON0bits.ON;
    TU16BCON0bits.ON = 0;

    TU16BTMRH = (uint8_t)((timerVal >> 8) & 0xFFU);
    TU16BTMRL = (uint8_t)(timerVal & 0xFFU);

    TU16BCON0bits.ON = onValue;
}

void TU16B_CounterClear(void)
{
    TU16BCON1bits.CLR = 1;
    while(1U == TU16BCON1bits.CLR)
    {
        // wait to clear CLR bit
    }
}

void TU16B_PeriodSet(uint16_t periodVal)
{
    TU16BPRH = (uint8_t)((periodVal >> 8) & 0xFFU);
    TU16BPRL = (uint8_t)(periodVal & 0xFFU);
}

uint16_t TU16B_PeriodGet(void)
{
    uint16_t periodVal;

    periodVal = ((uint16_t)TU16BPRH << 8)
                 | (uint16_t)TU16BPRL;

    return periodVal;
}

uint16_t TU16B_MaxCountGet(void)
{
    return TU16B_MAX_COUNT;
}

bool TU16B_PeriodMatchStatusGet(void)
{
    return TU16BCON1bits.PRIF;
}

bool TU16B_ResetStatusGet(void)
{
    return TU16BCON1bits.ZIF;
}

bool TU16B_CaptureStatusGet(void)
{
    return TU16BCON1bits.CIF;
}

bool TU16B_RunningStatusGet(void)
{
    return TU16BCON1bits.RUN;
}

void TU16B_InterruptFlagsClear(void)
{
    TU16BCON1bits.PRIF = 0;
    TU16BCON1bits.ZIF = 0;
    TU16BCON1bits.CIF = 0;
}

void TU16B_Tasks(void)
{
    if(1U == TU16BCON1bits.PRIF)
    {      
        if(NULL != TU16B_PeriodMatchCallback)
        {
            TU16B_PeriodMatchCallback();
        }
        TU16BCON1bits.PRIF = 0;
    }
    if(1U == TU16BCON1bits.ZIF)
    {      
        if(NULL != TU16B_ZeroMatchCallback)
        {
            TU16B_ZeroMatchCallback();
        }
        TU16BCON1bits.ZIF = 0;
    }
    if(1U == TU16BCON1bits.CIF)
    {
        if(NULL != TU16B_CaptureEventCallback)
        {
            TU16B_CaptureEventCallback();
        }
        TU16BCON1bits.CIF = 0;
    }
}

void TU16B_PeriodMatchCallbackRegister(void (* CallbackHandler)(void))
{
    TU16B_PeriodMatchCallback = CallbackHandler;
}

void TU16B_ZeroMatchCallbackRegister(void (* CallbackHandler)(void))
{
    TU16B_ZeroMatchCallback = CallbackHandler;
}

void TU16B_CaptureEventCallbackRegister(void (* CallbackHandler)(void))
{
    TU16B_CaptureEventCallback = CallbackHandler;
}

static void TU16B_CaptureEventDefaultCallback(void)
{
    //Default callback handler to avoid compiler warning
}

static void TU16B_ZeroMatchDefaultCallback(void)
{
    //Default callback handler to avoid compiler warning
}

static void TU16B_PeriodMatchDefaultCallback(void)
{
    //Default callback handler to avoid compiler warning
}


