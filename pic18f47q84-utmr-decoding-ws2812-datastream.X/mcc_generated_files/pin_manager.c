/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC18F47Q84
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB             :  MPLAB X 5.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
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

#include "pin_manager.h"
#include "interrupt_manager.h"
#include <stdbool.h>

extern bool buttonPressed;


void (*IOCCF5_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x07;
    TRISA = 0xEF;
    TRISB = 0xF4;
    TRISC = 0x26;
    TRISD = 0xFC;

    /**
    ANSELx registers
    */
    ANSELD = 0xD8;
    ANSELC = 0x08;
    ANSELB = 0xC4;
    ANSELE = 0x07;
    ANSELA = 0xEA;

    /**
    WPUx registers
    */
    WPUD = 0x00;
    WPUE = 0x00;
    WPUB = 0x00;
    WPUA = 0x08;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONE = 0x00;
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    ODCOND = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFE;
    SLRCOND = 0xFF;
    SLRCONE = 0x07;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0x0F;


    /**
    IOCx registers 
    */
    //interrupt on change for group IOCCF - flag
    IOCCFbits.IOCCF5 = 0;
    //interrupt on change for group IOCCN - negative
    IOCCNbits.IOCCN5 = 1;
    //interrupt on change for group IOCCP - positive
    IOCCPbits.IOCCP5 = 0;



    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCCF5_SetInterruptHandler(IOCCF5_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    PIE0bits.IOCIE = 1; 
    
	
    TUIN1PPS = 0x0C;   //RB4->TU16A:TUIN1;    
    RC0PPS = 0x3A;   //RC0->TU16A:TU1;    
    SPI2SDIPPS = 0x0D;   //RB5->SPI2:SDI2;    
    RC3PPS = 0x2C;   //RC3->UART5:TX5;    
    RC4PPS = 0x31;   //RC4->SPI1:SCK1;    
    CCP1PPS = 0x0C;   //RB4->CCP1:CCP1;    
    SPI2SCKPPS = 0x0B;   //RB3->SPI2:SCK2;    
    SPI1SCKPPS = 0x14;   //RC4->SPI1:SCK1;    
    CLCIN0PPS = 0x00;   //RA0->CLC3:CLCIN0;    
    RB0PPS = 0x3B;   //RB0->TU16B:TU2;    
    RD0PPS = 0x03;   //RD0->CLC3:CLC3;    
    RD1PPS = 0x03;   //RD1->CLC3:CLC3;    
    CLCIN2PPS = 0x0C;   //RB4->CLC3:CLCIN2;    
    RC6PPS = 0x32;   //RC6->SPI1:SDO1;    
    RC7PPS = 0x02;   //RC7->CLC2:CLC2;    
    SPI1SDIPPS = 0x11;   //RC1->SPI1:SDI1;    
}
  
void __interrupt(irq(IOC),base(8)) PIN_MANAGER_IOC()
{   
	// interrupt on change for pin IOCCF5
    if(IOCCFbits.IOCCF5 == 1)
    {
        IOCCF5_ISR();  
    }	
}

/**
   IOCCF5 Interrupt Service Routine
*/
void IOCCF5_ISR(void) {

    // Add custom IOCCF5 code
    IOCCFbits.IOCCF5 = 0;
    buttonPressed = true;
}
    
/**
  Allows selecting an interrupt handler for IOCCF5 at application runtime
*/
void IOCCF5_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCCF5_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCCF5
*/
void IOCCF5_DefaultInterruptHandler(void){
    // add your IOCCF5 interrupt custom code
    // or set custom function using IOCCF5_SetInterruptHandler()
}

/**
 End of File
*/