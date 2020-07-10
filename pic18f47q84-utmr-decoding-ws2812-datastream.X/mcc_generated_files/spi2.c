/**
  SPI2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    spi2.c

  @Summary
    This is the generated driver implementation file for the SPI2 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides implementations for driver APIs for SPI2.
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

#include "spi2.h"
#include "pin_manager.h"
#include "tmr1.h"
#include <xc.h>

typedef struct { 
    uint8_t con0; 
    uint8_t con1; 
    uint8_t con2; 
    uint8_t baud; 
    uint8_t operation;
} spi2_configuration_t;

//con0 == SPIxCON0, con1 == SPIxCON1, con2 == SPIxCON2, baud == SPIxBAUD, operation == Master/Slave
static const spi2_configuration_t spi2_configuration[] = {   
    { 0x82, 0x0, 0x5, 0x0, 1 }
};

void SPI2_Initialize(void)
{
    //SMP Middle; CKE Idle to active; CKP Idle:Low, Active:High; FST disabled; SSP active high; SDIP active high; SDOP active high; 
    SPI2CON1 = 0x00;
    //SSET enabled; TXR not required for a transfer; RXR suspended if the RxFIFO is full; 
    SPI2CON2 = 0x05;
    //CLKSEL CLC5; 
    SPI2CLK = 0x13;
    //BAUD 0; 
    SPI2BAUD = 0x00;
    TRISBbits.TRISB3 = 1;
    PIE5bits.SPI2RXIE = 1;
    SPI2_SetInterruptHandler(NULL);
    
    //EN enabled; LSBF MSb first; MST bus slave; BMODE last byte; 
    SPI2CON0 = 0x80;
}

bool SPI2_Open(spi2_modes_t spi2UniqueConfiguration)
{
    if(!SPI1CON0bits.EN)
    {
        SPI2CON0 = spi2_configuration[spi2UniqueConfiguration].con0;
        SPI2CON1 = spi2_configuration[spi2UniqueConfiguration].con1;
        SPI2CON2 = spi2_configuration[spi2UniqueConfiguration].con2 | (_SPI1CON2_SPI1RXR_MASK | _SPI1CON2_SPI1TXR_MASK);
        SPI2CLK  = 0x00;
        SPI2BAUD = spi2_configuration[spi2UniqueConfiguration].baud;        
        TRISBbits.TRISB3 = spi2_configuration[spi2UniqueConfiguration].operation;
        SPI2CON0bits.EN = 1;
        return true;
    }
    return false;
}

void SPI2_Close(void)
{
    SPI2CON0bits.EN = 0;
}

uint8_t SPI2_ExchangeByte(uint8_t data)
{
    SPI2TCNTL = 1;
    SPI2TXB = data;
    while(!PIR5bits.SPI2RXIF);
    return SPI2RXB;
}

void SPI2_ExchangeBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        SPI2TCNTL = 1;
        SPI2TXB = *data;
        while(!PIR5bits.SPI2RXIF);
        *data++ = SPI2RXB;
    }
}

// Half Duplex SPI Functions
void SPI2_WriteBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        SPI2_ExchangeByte(*data++);
    }
}

void SPI2_ReadBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        *data++ = SPI2_ExchangeByte(0);
    }
}

void SPI2_WriteByte(uint8_t byte)
{
    SPI2TXB = byte;
}

uint8_t SPI2_ReadByte(void)
{
    return SPI2RXB;
}

void SPI2_SetInterruptHandler(spi2InterruptHandler_t handler)
{
    SPI2_InterruptHandler = handler;
}

void __interrupt(irq(SPI2RX),base(8)) SPI2_Isr()
{
    static uint8_t byteCounter = 0;
    if(++byteCounter == 3) {
        DBG0_SetHigh();
        DBG0_SetLow();
        DBG0_SetHigh();
        DBG0_SetLow();
        byteCounter = 0;
        TMR1H = 0;          // Clear timer
        TMR1L = 0;
        CCP1CONbits.EN = 1;   // Start CCP for reset-time measurement
    }
}
