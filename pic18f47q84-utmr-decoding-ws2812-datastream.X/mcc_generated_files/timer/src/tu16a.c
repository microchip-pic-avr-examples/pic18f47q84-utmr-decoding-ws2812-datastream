/**
 * TU16A Generated Driver File
 *
 * @file tu16a.c
 *  
 * @ingroup tu16a
 *
 * @brief This file contains the API definitions for the TU16A module.
 *
 * @version TU16A Driver Version 3.0.0
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
#include "../tu16a.h"

static void (*TU16A_PeriodMatchCallback)(void); 
static void TU16A_PeriodMatchDefaultCallback(void);
static void (*TU16A_ZeroMatchCallback)(void);
static void TU16A_ZeroMatchDefaultCallback(void);
static void (*TU16A_CaptureEventCallback)(void); 
static void TU16A_CaptureEventDefaultCallback(void);

void TU16A_Initialize(void)
{
    TU16ACON0bits.ON = 0;        //Stop TU16A

    TU16ACON1 = (0 << _TU16ACON1_CIF_POSN)   // CIF disabled
        | (0 << _TU16ACON1_ZIF_POSN)   // ZIF disabled
        | (0 << _TU16ACON1_PRIF_POSN)   // PRIF disabled
        | (0 << _TU16ACON1_CAPT_POSN)   // CAPT disabled
        | (0 << _TU16ACON1_LIMIT_POSN)   // LIMIT disabled
        | (0 << _TU16ACON1_CLR_POSN)   // CLR disabled
        | (0 << _TU16ACON1_OSEN_POSN);  // OSEN disabled
    
    TU16AHLT = (3 << _TU16AHLT_STOP_POSN)   // STOP At PR Match
        | (2 << _TU16AHLT_RESET_POSN)   // RESET At Start and PR match
        | (2 << _TU16AHLT_START_POSN)   // START Rising ERS edge
        | (1 << _TU16AHLT_CSYNC_POSN)   // CSYNC enabled
        | (0 << _TU16AHLT_EPOL_POSN);  // EPOL non inverted
    
    TU16ACLK = (2 << _TU16ACLK_CLK_POSN);  // CLK FOSC
    
    TU16AERS = (1 << _TU16AERS_ERS_POSN);  // ERS TUIN1PPS
    
    TU16APS = (0 << _TU16APS_PS_POSN);  // PS 0x0
    
    TU16APRH = 0x0;
    TU16APRL = 0x1E;

    TU16ATMRH = 0x0;
    TU16ATMRL = 0x0;

    TU16A_PeriodMatchCallback = TU16A_PeriodMatchDefaultCallback;
    TU16A_ZeroMatchCallback = TU16A_ZeroMatchDefaultCallback;
    TU16A_CaptureEventCallback = TU16A_CaptureEventDefaultCallback;

    TU16ACON0 = (0 << _TU16ACON0_CIE_POSN)   // CIE disabled
        | (0 << _TU16ACON0_ZIE_POSN)   // ZIE disabled
        | (0 << _TU16ACON0_PRIE_POSN)   // PRIE disabled
        | (0 << _TU16ACON0_RDSEL_POSN)   // RDSEL read
        | (0 << _TU16ACON0_OPOL_POSN)   // OPOL low
        | (0 << _TU16ACON0_OM_POSN)   // OM pulse mode
        | (0 << _TU16ACON0_CPOL_POSN)   // CPOL falling edge
        | (1 << _TU16ACON0_ON_POSN);  // ON enabled  

    PIE0bits.TU16AIE = 0;     // Disable TUI Interrupt
}

void TU16A_Deinitialize(void)
{
    TU16ACON0bits.ON = 0;
    TU16ACON0 = 0x0;
    TU16ACON1 = 0x0;
    TU16AHLT = 0x40;
    TU16ACLK = 0x0;
    TU16AERS = 0x0;
    TU16APS = 0x0;   
    TUCHAIN = 0x0;
    TU16APRH = 0xFF;
    TU16APRL = 0xFF;
    TU16ATMRH = 0x0;
    TU16ATMRL = 0x0;
    PIE0bits.TU16AIE = 0;
}

void TU16A_Start(void)
{
    TU16ACON0bits.ON = 1;
}

void TU16A_Stop(void)
{
    TU16ACON0bits.ON = 0;
}

uint16_t TU16A_CaptureValueGet(void)
{
    uint16_t captureValue;

    TU16ACON0bits.RDSEL = 0;

    captureValue = ((uint16_t)TU16ACRH<< 8) 
                    | (uint16_t)TU16ACRL;

    return captureValue;
}

uint16_t TU16A_OnCommandCapture(void)
{
    TU16ACON1bits.CAPT = 1;

    while(1U == TU16ACON1bits.CAPT)
    {
        //Wait to clear CAPT bit
    }
    /* cppcheck-suppress misra-c2012-8.7 */
    return TU16A_CaptureValueGet();
}

uint16_t TU16A_CounterGet(void)
{
    uint16_t timerVal;
    bool onValue = TU16ACON0bits.ON;

    TU16ACON0bits.ON = 0;
    TU16ACON0bits.RDSEL = 1;

    timerVal = ((uint16_t)TU16ATMRH << 8) 
            | (uint16_t)TU16ATMRL;

    TU16ACON0bits.ON = onValue;

    return timerVal;
}

void TU16A_CounterSet(uint16_t timerVal)
{
    bool onValue = TU16ACON0bits.ON;
    TU16ACON0bits.ON = 0;

    TU16ATMRH = (uint8_t)((timerVal >> 8) & 0xFFU);
    TU16ATMRL = (uint8_t)(timerVal & 0xFFU);

    TU16ACON0bits.ON = onValue;
}

void TU16A_CounterClear(void)
{
    TU16ACON1bits.CLR = 1;
    while(1U == TU16ACON1bits.CLR)
    {
        // wait to clear CLR bit
    }
}

void TU16A_PeriodSet(uint16_t periodVal)
{
    TU16APRH = (uint8_t)((periodVal >> 8) & 0xFFU);
    TU16APRL = (uint8_t)(periodVal & 0xFFU);
}

uint16_t TU16A_PeriodGet(void)
{
    uint16_t periodVal;

    periodVal = ((uint16_t)TU16APRH << 8)
                 | (uint16_t)TU16APRL;

    return periodVal;
}

uint16_t TU16A_MaxCountGet(void)
{
    return TU16A_MAX_COUNT;
}

bool TU16A_PeriodMatchStatusGet(void)
{
    return TU16ACON1bits.PRIF;
}

bool TU16A_ResetStatusGet(void)
{
    return TU16ACON1bits.ZIF;
}

bool TU16A_CaptureStatusGet(void)
{
    return TU16ACON1bits.CIF;
}

bool TU16A_RunningStatusGet(void)
{
    return TU16ACON1bits.RUN;
}

void TU16A_InterruptFlagsClear(void)
{
    TU16ACON1bits.PRIF = 0;
    TU16ACON1bits.ZIF = 0;
    TU16ACON1bits.CIF = 0;
}

void TU16A_Tasks(void)
{
    if(1U == TU16ACON1bits.PRIF)
    {      
        if(NULL != TU16A_PeriodMatchCallback)
        {
            TU16A_PeriodMatchCallback();
        }
        TU16ACON1bits.PRIF = 0;
    }
    if(1U == TU16ACON1bits.ZIF)
    {      
        if(NULL != TU16A_ZeroMatchCallback)
        {
            TU16A_ZeroMatchCallback();
        }
        TU16ACON1bits.ZIF = 0;
    }
    if(1U == TU16ACON1bits.CIF)
    {
        if(NULL != TU16A_CaptureEventCallback)
        {
            TU16A_CaptureEventCallback();
        }
        TU16ACON1bits.CIF = 0;
    }
}

void TU16A_PeriodMatchCallbackRegister(void (* CallbackHandler)(void))
{
    TU16A_PeriodMatchCallback = CallbackHandler;
}

void TU16A_ZeroMatchCallbackRegister(void (* CallbackHandler)(void))
{
    TU16A_ZeroMatchCallback = CallbackHandler;
}

void TU16A_CaptureEventCallbackRegister(void (* CallbackHandler)(void))
{
    TU16A_CaptureEventCallback = CallbackHandler;
}

static void TU16A_CaptureEventDefaultCallback(void)
{
    //Default callback handler to avoid compiler warning
}

static void TU16A_ZeroMatchDefaultCallback(void)
{
    //Default callback handler to avoid compiler warning
}

static void TU16A_PeriodMatchDefaultCallback(void)
{
    //Default callback handler to avoid compiler warning
}


