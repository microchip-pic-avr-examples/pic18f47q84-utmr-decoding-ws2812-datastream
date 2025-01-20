/**
 * CLC4 Generated Driver File.
 * 
 * @file clc4.c
 * 
 * @ingroup  clc4
 * 
 * @brief This file contains the API implementations for the CLC4 driver.
 *
 * @version CLC4 Driver Version 1.2.0
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
#include "../clc4.h"


static void (*CLC4_Callback)(void);
static void CLC4_DefaultCallback(void);

void CLC4_Initialize(void) 
{
    
    // SLCT 0x3; 
    CLCSELECT = 0x3;
    // LCG1POL not_inverted; LCG2POL inverted; LCG3POL not_inverted; LCG4POL not_inverted; LCPOL not_inverted; 
    CLCnPOL = 0x2;
    // LCD1S TMR4; 
    CLCnSEL0 = 0x16;
    // LCD2S CLCIN0 (CLCIN0PPS); 
    CLCnSEL1 = 0x0;
    // LCD3S CLCIN0 (CLCIN0PPS); 
    CLCnSEL2 = 0x0;
    // LCD4S CLCIN0 (CLCIN0PPS); 
    CLCnSEL3 = 0x0;
    // LCG1D1N disabled; LCG1D1T enabled; LCG1D2N disabled; LCG1D2T disabled; LCG1D3N disabled; LCG1D3T disabled; LCG1D4N disabled; LCG1D4T disabled; 
    CLCnGLS0 = 0x2;
    // LCG2D1N disabled; LCG2D1T disabled; LCG2D2N disabled; LCG2D2T disabled; LCG2D3N disabled; LCG2D3T disabled; LCG2D4N disabled; LCG2D4T disabled; 
    CLCnGLS1 = 0x0;
    // LCG3D1N disabled; LCG3D1T disabled; LCG3D2N disabled; LCG3D2T disabled; LCG3D3N disabled; LCG3D3T disabled; LCG3D4N disabled; LCG3D4T disabled; 
    CLCnGLS2 = 0x0;
    // LCG4D1N disabled; LCG4D1T disabled; LCG4D2N disabled; LCG4D2T disabled; LCG4D3N disabled; LCG4D3T disabled; LCG4D4N disabled; LCG4D4T disabled; 
    CLCnGLS3 = 0x0;
    // LCOUT 0x00; 
    CLCDATA = 0x0;
    // LCMODE AND-OR; LCINTN disabled; LCINTP disabled; LCEN enabled; 
    CLCnCON = 0x80;

    //Set default callback for CLC4 interrupt Overflow.
    CLC4_CallbackRegister(CLC4_DefaultCallback);

    // Clear the CLC interrupt flag
    PIR9bits.CLC4IF = 0;
}

void CLC4_Enable(void) 
{
    CLCSELECTbits.SLCT = 3;
    CLCnCONbits.EN = 1;
}

void CLC4_Disable(void) 
{
    CLCSELECTbits.SLCT = 3;
    CLCnCONbits.EN = 0;
}

void CLC4_RisingEdgeDetectionEnable(void) 
{
    CLCSELECTbits.SLCT = 3;
    CLCnCONbits.INTP = 1;
}

void CLC4_RisingEdgeDetectionDisable(void) 
{
    CLCSELECTbits.SLCT = 3;
    CLCnCONbits.INTP = 0;
}

void CLC4_FallingEdgeDetectionEnable(void) 
{
    CLCSELECTbits.SLCT = 3;
    CLCnCONbits.INTN = 1;
}

void CLC4_FallingEdgeDetectionDisable(void) 
{
    CLCSELECTbits.SLCT = 3;
    CLCnCONbits.INTN = 0;
}

void CLC4_CallbackRegister(void (* CallbackHandler)(void))
{
    CLC4_Callback = CallbackHandler;
}

static void CLC4_DefaultCallback(void)
{
    //Add your interrupt code here or
    //Use CLC4_CallbackRegister function to use Custom ISR
}

void CLC4_Tasks(void)
{
    if(PIR9bits.CLC4IF == 1)
    {
        if(CLC4_Callback != NULL)
        {
            CLC4_Callback();
        }
        PIR9bits.CLC4IF = 0;
    }
}


bool CLC4_OutputStatusGet(void) 
{
    return(CLCDATAbits.CLC4OUT);
}
/**
 End of File
*/
