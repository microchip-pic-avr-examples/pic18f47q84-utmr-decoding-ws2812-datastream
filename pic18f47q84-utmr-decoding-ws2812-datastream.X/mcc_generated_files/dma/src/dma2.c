/**
 * DMA2 Generated Driver File.
 * 
 * @file dma2.c
 * 
 * @ingroup  dma2
 * 
 * @brief This file contains the API implementations for the DMA2 driver.
 *
 * @version DMA2 Driver Version 2.12.1
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
#include "../dma2.h"

uint8_t decodedColor[4095];

/**
  Section: DMA2 APIs
*/

void DMA2_Initialize(void)
{   
    
    //DMA Instance Selection : 0x1
    DMASELECT = 0x1;
    //Source Address : (uint24_t) &SPI2RXB
    DMAnSSA = (uint24_t) &SPI2RXB;
    //Destination Address : (uint16_t) &decodedColor
    DMAnDSA = (uint16_t) &decodedColor;
    //SSTP not cleared; SMODE unchanged; SMR SFR; DSTP cleared; DMODE incremented; 
    DMAnCON1 = 0x60;
    //Source Message Size : 1
    DMAnSSZ = 1;
    //Destination Message Size : 4095
    DMAnDSZ = 4095;
    //Start Trigger : SIRQ SPI2RX; 
    DMAnSIRQ = 0x28;
    //Abort Trigger : AIRQ None; 
    DMAnAIRQ = 0x0;
	
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
	
    //AIRQEN disabled; DGO not in progress; SIRQEN enabled; EN enabled; 
    DMAnCON0 = 0xC0;
	 
}

void DMA2_Enable(void)
{
    DMASELECT = 0x1;
    DMAnCON0bits.EN = 0x1;
}

void DMA2_Disable(void)
{
    DMASELECT = 0x1;
    DMAnCON0bits.EN = 0x0;
}

void DMA2_SourceRegionSelect(uint8_t region)
{
    DMASELECT = 0x1;
	DMAnCON1bits.SMR  = region;
}

void DMA2_SourceAddressSet(uint24_t address)
{
    DMASELECT = 0x1;
	DMAnSSA = address;
}

uint24_t DMA2_SourceAddressGet(void)
{
    DMASELECT = 0x1;
    return DMAnSSA;
}

void DMA2_DestinationAddressSet(uint16_t address)
{
    DMASELECT = 0x1;
	DMAnDSA = address;
}

uint16_t DMA2_DestinationAddressGet(void)
{
    DMASELECT = 0x1;
    return DMAnDSA;
}

void DMA2_SourceSizeSet(uint16_t size)
{
    DMASELECT = 0x1;
	DMAnSSZ= size;
}

uint16_t DMA2_SourceSizeGet(void)
{
    DMASELECT = 0x1;
    return DMAnSSZ;
}

void DMA2_DestinationSizeSet(uint16_t size)
{                     
    DMASELECT = 0x1;
	DMAnDSZ= size;
}

uint16_t DMA2_DestinationSizeGet(void)
{                     
    DMASELECT = 0x1;
    return DMAnDSZ;
}

uint24_t DMA2_SourcePointerGet(void)
{
    DMASELECT = 0x1;
	return DMAnSPTR;
}

uint16_t DMA2_DestinationPointerGet(void)
{
    DMASELECT = 0x1;
	return DMAnDPTR;
}

uint16_t DMA2_SourceCountGet(void)
{
    DMASELECT = 0x1;
    return DMAnSCNT;
}

uint16_t DMA2_DestinationCountGet(void)
{                     
    DMASELECT = 0x1;
    return DMAnDCNT;
}

void DMA2_StartTriggerSet(uint8_t sirq)
{
    DMASELECT = 0x1;
	DMAnSIRQ = sirq;
}

void DMA2_AbortTriggerSet(uint8_t airq)
{
    DMASELECT = 0x1;
	DMAnAIRQ = airq;
}

void DMA2_TransferStart(void)
{
    DMASELECT = 0x1;
	DMAnCON0bits.DGO = 1;
}

void DMA2_TransferWithTriggerStart(void)
{
    DMASELECT = 0x1;
	DMAnCON0bits.SIRQEN = 1;
}

void DMA2_TransferStop(void)
{
    DMASELECT = 0x1;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
}

void DMA2_DMAPrioritySet(uint8_t priority)
{
    uint8_t GIESaveState = INTCON0bits.GIE;
    INTCON0bits.GIE = 0;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 0;
	DMA2PR = priority;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 1;
    INTCON0bits.GIE = GIESaveState;
}

/**
 End of File
*/
