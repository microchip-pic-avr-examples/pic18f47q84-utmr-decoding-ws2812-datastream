/**
  DMA3 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    dma3.c

  @Summary
    This is the generated driver implementation file for the DMA3 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for DMA3.
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
#include "dma3.h"


/**
  Section: DMA3 APIs
*/

void DMA3_Initialize(void)
{
    //DMA Instance Selection : 0x02
    DMASELECT = 0x02;
    //Source Address : &ws2812_seed
    DMAnSSA = &ws2812_seed;
    //Destination Address : &SPI1TXB
    DMAnDSA = &SPI1TXB;
    //DMODE unchanged; DSTP not cleared; SMR Program Flash; SMODE incremented; SSTP cleared; 
    DMAnCON1 = 0x0B;
    //Source Message Size : 15
    DMAnSSZ = 15;
    //Destination Message Size : 1
    DMAnDSZ = 1;
    //Start Trigger : SIRQ SPI1TX; 
    DMAnSIRQ = 0x19;
    //Abort Trigger : AIRQ None; 
    DMAnAIRQ = 0x00;
	
    // Clear Destination Count Interrupt Flag bit
    PIR10bits.DMA3DCNTIF = 0; 
    // Clear Source Count Interrupt Flag bit
    PIR10bits.DMA3SCNTIF = 0; 
    // Clear Abort Interrupt Flag bit
    PIR10bits.DMA3AIF = 0; 
    // Clear Overrun Interrupt Flag bit
    PIR10bits.DMA3ORIF =0; 
    
    PIE10bits.DMA3DCNTIE = 0;
    PIE10bits.DMA3SCNTIE = 0;
    PIE10bits.DMA3AIE = 0;
    PIE10bits.DMA3ORIE = 0;
	
    //EN enabled; SIRQEN enabled; DGO not in progress; AIRQEN disabled; 
    DMAnCON0 = 0xC0;
	
}

void DMA3_SelectSourceRegion(uint8_t region)
{
    DMASELECT = 0x02;
	DMAnCON1bits.SMR  = region;
}

void DMA3_SetSourceAddress(uint24_t address)
{
    DMASELECT = 0x02;
	DMAnSSA = address;
}

void DMA3_SetDestinationAddress(uint16_t address)
{
    DMASELECT = 0x02;
	DMAnDSA = address;
}

void DMA3_SetSourceSize(uint16_t size)
{
    DMASELECT = 0x02;
	DMAnSSZ= size;
}

void DMA3_SetDestinationSize(uint16_t size)
{                     
    DMASELECT = 0x02;
	DMAnDSZ= size;
}

uint24_t DMA3_GetSourcePointer(void)
{
    DMASELECT = 0x02;
	return DMAnSPTR;
}

uint16_t DMA3_GetDestinationPointer(void)
{
    DMASELECT = 0x02;
	return DMAnDPTR;
}

void DMA3_SetStartTrigger(uint8_t sirq)
{
    DMASELECT = 0x02;
	DMAnSIRQ = sirq;
}

void DMA3_SetAbortTrigger(uint8_t airq)
{
    DMASELECT = 0x02;
	DMAnAIRQ = airq;
}

void DMA3_StartTransfer(void)
{
    DMASELECT = 0x02;
	DMAnCON0bits.DGO = 1;
}

void DMA3_StartTransferWithTrigger(void)
{
    DMASELECT = 0x02;
	DMAnCON0bits.SIRQEN = 1;
}

void DMA3_StopTransfer(void)
{
    DMASELECT = 0x02;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
}

void DMA3_SetDMAPriority(uint8_t priority)
{
    // This function is dependant on the PR1WAY CONFIG bit
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 0;
	DMA3PR = priority;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 1;
}

/**
 End of File
*/
