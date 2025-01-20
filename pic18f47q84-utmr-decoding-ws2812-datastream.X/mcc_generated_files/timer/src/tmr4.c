/**
 * TMR4 Generated Driver File
 *
 * @file tmr4.c
 * 
 * @ingroup  tmr4
 * 
 * @brief Driver implementation for the TMR4 module.
 *
 * @version Driver Version 4.0.0
 *
 * @version Package Version 5.0.0
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "../tmr4.h"

static void (*TMR4_PeriodMatchCallback)(void);
static void TMR4_DefaultPeriodMatchCallback(void);

/**
  Section: TMR4 APIs
*/

void TMR4_Initialize(void)
{
    T4CLKCON = (0 << _T4CLKCON_T4CS_POSN);  // T4CS T4CKIPPS pin

    T4HLT = (0 << _T4HLT_T4MODE_POSN)   // T4MODE Software control
        | (0 << _T4HLT_T4CKSYNC_POSN)   // T4CKSYNC Not Synchronized
        | (0 << _T4HLT_T4CKPOL_POSN)   // T4CKPOL Rising Edge
        | (0 << _T4HLT_T4PSYNC_POSN);  // T4PSYNC Not Synchronized

    T4RST = (0 << _T4RST_T4RSEL_POSN);  // T4RSEL T4CKIPPS pin

    T4PR = 0x17;    // Period 0.024s; Frequency 1000Hz; Count 23

    T4TMR = 0x0;

    TMR4_PeriodMatchCallback = TMR4_DefaultPeriodMatchCallback;
    
    PIR11bits.TMR4IF = 0;

    T4CON = (0 << _T4CON_T4CKPS_POSN)   // T4CKPS 1:1
        | (1 << _T4CON_TMR4ON_POSN)   // TMR4ON on
        | (0 << _T4CON_T4OUTPS_POSN);  // T4OUTPS 1:1
}

void TMR4_Deinitialize(void)
{
    T4CONbits.TMR4ON = 0;
    
    PIR11bits.TMR4IF = 0;	   
    PIE11bits.TMR4IE = 0;		
    
    T4CON = 0x0;
    T4CLKCON = 0x0;
    T4HLT = 0x0;
    T4RST = 0x0;
    T4PR = 0xFF;
    T4TMR =0x0;
}

void TMR4_Start(void)
{   
    T4CONbits.TMR4ON = 1;
}

void TMR4_Stop(void)
{   
    T4CONbits.TMR4ON = 0;
}

void TMR4_ModeSet(TMR4_HLT_MODE mode)
{  
    T4HLTbits.T4MODE = mode;
}

void TMR4_ExtResetSourceSet(TMR4_HLT_EXT_RESET_SOURCE reset)
{   
    T4RSTbits.T4RSEL = reset;
}

uint8_t TMR4_CounterGet(void)
{
    return T4TMR;
}

void TMR4_CounterSet(uint8_t count)
{  
    T4TMR = count;
}

void TMR4_PeriodSet(uint8_t periodVal)
{
    T4PR = periodVal;
}

uint8_t TMR4_PeriodGet(void)
{
    return T4PR;
}

uint8_t TMR4_MaxCountGet(void)
{
    return TMR4_MAX_COUNT;
}

bool TMR4_PeriodMatchStatusGet(void)
{
    return PIR11bits.TMR4IF;
}

void TMR4_PeriodMatchStatusClear(void)
{
    PIR11bits.TMR4IF = 0;
}

void TMR4_Tasks(void)
{
    if(1U == PIR11bits.TMR4IF)
    {
        if(NULL != TMR4_PeriodMatchCallback)
        {
            TMR4_PeriodMatchCallback();
        }
        PIR11bits.TMR4IF = 0;
    }
}

void TMR4_PeriodMatchCallbackRegister(void (* callbackHandler)(void))
{
   TMR4_PeriodMatchCallback = callbackHandler;
}

static void TMR4_DefaultPeriodMatchCallback(void)
{
    // Default callback function
}


