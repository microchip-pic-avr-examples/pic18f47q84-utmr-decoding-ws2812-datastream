/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.1.1
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

#include "../pins.h"

void (*SW2_InterruptHandler)(void);

void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATB = 0x0;
    LATC = 0x0;
    LATD = 0x0;
    LATE = 0x0;
    /**
    ODx registers
    */
    ODCONA = 0x0;
    ODCONB = 0x0;
    ODCONC = 0x0;
    ODCOND = 0x0;
    ODCONE = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0xEF;
    TRISB = 0xFE;
    TRISC = 0x37;
    TRISD = 0xFA;
    TRISE = 0x7;

    /**
    ANSELx registers
    */
    ANSELA = 0xEF;
    ANSELB = 0xC6;
    ANSELC = 0x5;
    ANSELD = 0xFA;
    ANSELE = 0x7;

    /**
    WPUx registers
    */
    WPUA = 0x0;
    WPUB = 0x0;
    WPUC = 0x0;
    WPUD = 0x0;
    WPUE = 0x0;


    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x7;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0xF;

   /**
    RxyI2C | RxyFEAT registers   
    */
    RB1I2C = 0x0;
    RB2I2C = 0x0;
    RC3I2C = 0x0;
    RC4I2C = 0x0;
    /**
    PPS registers
    */
    T4INPPS = 0xC; //RB4->TMR4:T4IN;
    TUIN1PPS = 0xC; //RB4->TU16A:TUIN1;
    CLCIN2PPS = 0xC; //RB4->CLC2:CLCIN2;
    SPI2SDIPPS = 0xD; //RB5->SPI2:SDI2;
    SPI1SDIPPS = 0x11; //RC1->SPI1:SDI1;
    RC3PPS = 0x2C;  //RC3->UART5:TX5;
    RB0PPS = 0x3B;  //RB0->TU16B:TU16B;
    RD2PPS = 0x04;  //RD2->CLC4:CLC4;
    RD0PPS = 0x03;  //RD0->CLC3:CLC3;
    RC7PPS = 0x02;  //RC7->CLC2:CLC2;
    RC6PPS = 0x32;  //RC6->SPI1:SDO1;
    CCP1PPS = 0xC;  //RB4->CCP1:CCP1;
    SPI2SCKPPS = 0xB;  //RB3->SPI2:SCK2;
    RB3PPS = 0x34;  //RB3->SPI2:SCK2;
    SPI1SCKPPS = 0x14;  //RC4->SPI1:SCK1;
    RC4PPS = 0x31;  //RC4->SPI1:SCK1;

   /**
    IOCx registers 
    */
    IOCAP = 0x0;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCBP = 0x0;
    IOCBN = 0x0;
    IOCBF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x20;
    IOCCF = 0x0;
    IOCEP = 0x0;
    IOCEN = 0x0;
    IOCEF = 0x0;

    SW2_SetInterruptHandler(SW2_DefaultInterruptHandler);

    // Enable PIE0bits.IOCIE interrupt 
    PIE0bits.IOCIE = 1; 
}
  
void PIN_MANAGER_IOC(void)
{
    // interrupt on change for pin SW2
    if(IOCCFbits.IOCCF5 == 1)
    {
        SW2_ISR();  
    }
}
   
/**
   SW2 Interrupt Service Routine
*/
void SW2_ISR(void) {

    // Add custom SW2 code

    // Call the interrupt handler for the callback registered at runtime
    if(SW2_InterruptHandler)
    {
        SW2_InterruptHandler();
    }
    IOCCFbits.IOCCF5 = 0;
}

/**
  Allows selecting an interrupt handler for SW2 at application runtime
*/
void SW2_SetInterruptHandler(void (* InterruptHandler)(void)){
    SW2_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for SW2
*/
void SW2_DefaultInterruptHandler(void){
    // add your SW2 interrupt custom code
    // or set custom function using SW2_SetInterruptHandler()
}
/**
 End of File
*/