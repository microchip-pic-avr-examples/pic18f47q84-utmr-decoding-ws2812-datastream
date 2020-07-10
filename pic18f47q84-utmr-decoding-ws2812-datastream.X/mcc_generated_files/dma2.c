/**
  DMA2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    dma2.c

  @Summary
    This is the generated driver implementation file for the DMA2 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for DMA2.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC18F47Q84
        Driver Version    :  1.0.0
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
#include "dma2.h"


/**
  Section: DMA2 APIs
*/

void DMA2_Initialize(void)
{
    //DMA Instance Selection : 0x01
    DMASELECT = 0x01;
    //Source Address : &SPI2RXB
    DMAnSSA = &SPI2RXB;
    //Destination Address : &decodedColor
    DMAnDSA= &decodedColor;
    //DMODE incremented; DSTP cleared; SMR SFR; SMODE unchanged; SSTP not cleared; 
    DMAnCON1 = 0x60;
    //Source Message Size : 1
    DMAnSSZ = 1;
    //Destination Message Size : 4095
    DMAnDSZ = 4095;
    //Start Trigger : SIRQ SPI2RX; 
    DMAnSIRQ = 0x28;
    //Abort Trigger : AIRQ None; 
    DMAnAIRQ = 0x00;
	
    // Clear Destination Count Interrupt Flag bit
    PIR6bits.DMA2DCNTIF = 0; 
    // Clear Source Count Interrupt Flag bit
    PIR6bits.DMA2SCNTIF = 0; 
    // Clear Abort Interrupt Flag bit
    PIR6bits.DMA2AIF = 0; 
    // Clear Overrun Interrupt Flag bit
    PIR6bits.DMA2ORIF =0; 
    
    PIE6bits.DMA2DCNTIE = 0;
    PIE6bits.DMA2SCNTIE = 0;
    PIE6bits.DMA2AIE = 0;
    PIE6bits.DMA2ORIE = 0;
	
    //EN enabled; SIRQEN enabled; DGO not in progress; AIRQEN disabled; 
    DMAnCON0 = 0xC0;
	
}

void DMA2_SelectSourceRegion(uint8_t region)
{
    DMASELECT = 0x01;
	DMAnCON1bits.SMR  = region;
}

void DMA2_SetSourceAddress(uint24_t address)
{
    DMASELECT = 0x01;
	DMAnSSA = address;
}

void DMA2_SetDestinationAddress(uint16_t address)
{
    DMASELECT = 0x01;
	DMAnDSA = address;
}

void DMA2_SetSourceSize(uint16_t size)
{
    DMASELECT = 0x01;
	DMAnSSZ= size;
}

void DMA2_SetDestinationSize(uint16_t size)
{                     
    DMASELECT = 0x01;
	DMAnDSZ= size;
}

uint24_t DMA2_GetSourcePointer(void)
{
    DMASELECT = 0x01;
	return DMAnSPTR;
}

uint16_t DMA2_GetDestinationPointer(void)
{
    DMASELECT = 0x01;
	return DMAnDPTR;
}

void DMA2_SetStartTrigger(uint8_t sirq)
{
    DMASELECT = 0x01;
	DMAnSIRQ = sirq;
}

void DMA2_SetAbortTrigger(uint8_t airq)
{
    DMASELECT = 0x01;
	DMAnAIRQ = airq;
}

void DMA2_StartTransfer(void)
{
    DMASELECT = 0x01;
	DMAnCON0bits.DGO = 1;
}

void DMA2_StartTransferWithTrigger(void)
{
    DMASELECT = 0x01;
	DMAnCON0bits.SIRQEN = 1;
}

void DMA2_StopTransfer(void)
{
    DMASELECT = 0x01;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
}

void DMA2_SetDMAPriority(uint8_t priority)
{
    // This function is dependant on the PR1WAY CONFIG bit
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 0;
	DMA2PR = priority;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 1;
}

/**
 End of File
*/
