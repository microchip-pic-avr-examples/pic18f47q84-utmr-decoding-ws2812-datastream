/**
  CCP1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    ccp1.c

  @Summary
    This is the generated driver implementation file for the CCP1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides implementations for driver APIs for CCP1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC18F47Q84
        Driver Version    :  2.1.3
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
         MPLAB 	          :  MPLAB X 5.40
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
#include "ccp1.h"
#include "interrupt_manager.h"
#include "tmr1.h"
#include "pin_manager.h"

static void (*CCP1_CallBack)(uint16_t);

/**
  Section: Capture Module APIs:
*/

static void CCP1_DefaultCallBack(uint16_t capturedValue)
{
    // Add your code here
}

void CCP1_Initialize(void)
{
    // Set the CCP1 to the options selected in the User Interface
	
	// MODE Rising edge; EN enabled; FMT right_aligned; 
	CCP1CON = 0x85;    
	
	// CCP1CTS CCP1 pin; 
	CCP1CAP = 0x00;    
	
	// RH 0; 
	CCPR1H = 0x00;    
	
	// RL 0; 
	CCPR1L = 0x00;    
    
    // Set the default call back function for CCP1
    CCP1_SetCallBack(CCP1_DefaultCallBack);

	// Selecting Timer 1
	CCPTMRS0bits.C1TSEL = 0x1;
    
    // Clear the CCP1 interrupt flag
    PIR3bits.CCP1IF = 0;

    // Enable the CCP1 interrupt
    PIE3bits.CCP1IE = 1;
}

void __interrupt(irq(CCP1),base(8)) CCP1_CaptureISR()
{
    uint16_t resetTime = 0;

    // Clear the CCP1 interrupt flag
    PIR3bits.CCP1IF = 0;
    
    // Clear timer
    CCP1CONbits.EN = 0;
    TMR1H = 0;
    TMR1L = 0;
    
    DBG0_SetHigh();
    DBG0_SetLow();
    
    // If TMR1 has overflowed, set reset time to maximum
    // otherwise CCPR1 register captures actual reset time
    if(PIR3bits.TMR1IF == 1) {
        PIR3bits.TMR1IF = 0;
        resetTime = 0xFFFF;
    }
    else {
        resetTime = CCPR1;
    }
    
//    if(resetTime < DELAY_50us) {
//        if(seqID < MAX_SEQID) {
//            sequenceTiming[seqID][ID_NUMLED]++;
//        }
//    }
//    else {
//        if(seqID < MAX_SEQID) {
//            sequenceTiming[seqID][ID_RSTTIME] = resetTime;
//        }
//        seqID++;
//        sequenceTiming[seqID][ID_NUMLED] = 0;   // Initialize to zero at runtime
//    }
    
    if(resetTime >= DELAY_50us) {
        if(seqID < MAX_SEQID) {
            sequenceTiming[seqID][ID_RSTTIME] = resetTime;
        }
        seqID++;                    // First seqID++ will make seqID=0
        sequenceTiming[seqID][ID_NUMLED] = 0;   // Initialize to zero at runtime
        sequenceTiming[seqID][ID_RSTTIME] = 0;
    }
    
    if(seqID < MAX_SEQID) {
        sequenceTiming[seqID][ID_NUMLED]++;
    }
}

void CCP1_SetCallBack(void (*customCallBack)(uint16_t)){
    CCP1_CallBack = customCallBack;
}
/**
 End of File
*/