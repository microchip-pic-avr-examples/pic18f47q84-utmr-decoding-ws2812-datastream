/**
 * CCP1 Generated Driver File.
 * 
 * @file ccp1.c
 * 
 * @ingroup capture1
 * 
 * @brief This file contains the API implementation for the CCP1 driver.
 *
 * @version CCP1 Driver Version 2.0.2
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
#include "../ccp1.h"
#include "../../system/interrupt.h"

static void (*CCP1_CallBack)(uint16_t);

/**
  Section: Capture Module APIs
*/

/**
 * @ingroup capture1
 * @brief Default callback function for the capture interrupt events.
 * @param capturedValue - 16-bit captured value.
 * @return None.
 */
static void CCP1_DefaultCallBack(uint16_t capturedValue) {
    // Add your code here
}

void CCP1_Initialize(void)
{
    // Set the CCP1 to the options selected in the User Interface

    // CCPM Rising edge; EN disabled; FMT right_aligned; 
    CCP1CON = 0x5;

    // CTS CCP1 pin; 
    CCP1CAP = 0x0;

    // CCPRH 0; 
    CCPR1H = 0x0;

    // CCPRL 0; 
    CCPR1L = 0x0;

    // Set the default call back function for CCP1
    CCP1_SetCallBack(CCP1_DefaultCallBack);

    // Selecting Timer 1
    CCPTMRS0bits.C1TSEL = 0x1;

    // Clear the CCP1 interrupt flag    
    PIR3bits.CCP1IF = 0;    

    // Enable the CCP1 interrupt
    PIE3bits.CCP1IE = 1;
}

/**
 * @ingroup capture1
 * @brief Implements the ISR for capture interrupt when vectored interrupt is enabled.
 * @param None.
 * @return None.
 */
void __interrupt(irq(CCP1),base(8)) CCP1_CaptureISR()
{
    CCPR1_PERIOD_REG_T module;

    // Clear the CCP1 interrupt flag
    PIR3bits.CCP1IF = 0;
    
    // Copy captured value.
    module.ccpr1l = CCPR1L;
    module.ccpr1h = CCPR1H;
    
    // Return 16-bit captured value
    CCP1_CallBack(module.ccpr1_16Bit);
}

void CCP1_SetCallBack(void (*customCallBack)(uint16_t)){
    CCP1_CallBack = customCallBack;
}
/**
 End of File
*/
