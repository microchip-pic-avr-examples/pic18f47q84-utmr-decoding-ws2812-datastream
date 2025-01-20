/**
 * CLC3 Generated Driver File.
 * 
 * @file clc3.c
 * 
 * @ingroup  clc3
 * 
 * @brief This file contains the API implementations for the CLC3 driver.
 *
 * @version CLC3 Driver Version 1.2.0
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
#include "../clc3.h"


static void (*CLC3_Callback)(void);
static void CLC3_DefaultCallback(void);

void CLC3_Initialize(void) 
{
    
    // SLCT 0x2; 
    CLCSELECT = 0x2;
    // LCG1POL inverted; LCG2POL not_inverted; LCG3POL not_inverted; LCG4POL not_inverted; LCPOL not_inverted; 
    CLCnPOL = 0x1;
    // LCD1S PWM1_OUT1; 
    CLCnSEL0 = 0x22;
    // LCD2S SPI1 SCK OUT; 
    CLCnSEL1 = 0x41;
    // LCD3S SPI1 SDO OUT; 
    CLCnSEL2 = 0x40;
    // LCD4S CLCIN0 (CLCIN0PPS); 
    CLCnSEL3 = 0x0;
    // LCG1D1N enabled; LCG1D1T disabled; LCG1D2N enabled; LCG1D2T disabled; LCG1D3N disabled; LCG1D3T disabled; LCG1D4N disabled; LCG1D4T disabled; 
    CLCnGLS0 = 0x5;
    // LCG2D1N disabled; LCG2D1T disabled; LCG2D2N disabled; LCG2D2T disabled; LCG2D3N enabled; LCG2D3T disabled; LCG2D4N disabled; LCG2D4T disabled; 
    CLCnGLS1 = 0x10;
    // LCG3D1N disabled; LCG3D1T disabled; LCG3D2N disabled; LCG3D2T enabled; LCG3D3N disabled; LCG3D3T disabled; LCG3D4N disabled; LCG3D4T disabled; 
    CLCnGLS2 = 0x8;
    // LCG4D1N disabled; LCG4D1T disabled; LCG4D2N disabled; LCG4D2T disabled; LCG4D3N disabled; LCG4D3T enabled; LCG4D4N disabled; LCG4D4T disabled; 
    CLCnGLS3 = 0x20;
    // LCOUT 0x00; 
    CLCDATA = 0x0;
    // LCMODE AND-OR; LCINTN disabled; LCINTP disabled; LCEN enabled; 
    CLCnCON = 0x80;

    //Set default callback for CLC3 interrupt Overflow.
    CLC3_CallbackRegister(CLC3_DefaultCallback);

    // Clear the CLC interrupt flag
    PIR7bits.CLC3IF = 0;
}

void CLC3_Enable(void) 
{
    CLCSELECTbits.SLCT = 2;
    CLCnCONbits.EN = 1;
}

void CLC3_Disable(void) 
{
    CLCSELECTbits.SLCT = 2;
    CLCnCONbits.EN = 0;
}

void CLC3_RisingEdgeDetectionEnable(void) 
{
    CLCSELECTbits.SLCT = 2;
    CLCnCONbits.INTP = 1;
}

void CLC3_RisingEdgeDetectionDisable(void) 
{
    CLCSELECTbits.SLCT = 2;
    CLCnCONbits.INTP = 0;
}

void CLC3_FallingEdgeDetectionEnable(void) 
{
    CLCSELECTbits.SLCT = 2;
    CLCnCONbits.INTN = 1;
}

void CLC3_FallingEdgeDetectionDisable(void) 
{
    CLCSELECTbits.SLCT = 2;
    CLCnCONbits.INTN = 0;
}

void CLC3_CallbackRegister(void (* CallbackHandler)(void))
{
    CLC3_Callback = CallbackHandler;
}

static void CLC3_DefaultCallback(void)
{
    //Add your interrupt code here or
    //Use CLC3_CallbackRegister function to use Custom ISR
}

void CLC3_Tasks(void)
{
    if(PIR7bits.CLC3IF == 1)
    {
        if(CLC3_Callback != NULL)
        {
            CLC3_Callback();
        }
        PIR7bits.CLC3IF = 0;
    }
}


bool CLC3_OutputStatusGet(void) 
{
    return(CLCDATAbits.CLC3OUT);
}
/**
 End of File
*/
