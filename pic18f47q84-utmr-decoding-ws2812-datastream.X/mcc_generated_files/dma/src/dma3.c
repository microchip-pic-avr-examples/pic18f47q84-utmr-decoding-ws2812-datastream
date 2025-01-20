/**
 * DMA3 Generated Driver File.
 * 
 * @file dma3.c
 * 
 * @ingroup  dma3
 * 
 * @brief This file contains the API implementations for the DMA3 driver.
 *
 * @version DMA3 Driver Version 2.12.1
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
#include "../dma3.h"

/**
  Section: DMA3 APIs
*/

void DMA3_Initialize(void)
{   
    
    //DMA Instance Selection : 0x2
    DMASELECT = 0x2;
    //Source Address : 0
    DMAnSSA = 0;
    //Destination Address : (uint16_t) &SPI1TXB
    DMAnDSA = (uint16_t) &SPI1TXB;
    //SSTP cleared; SMODE incremented; SMR Program Flash; DSTP not cleared; DMODE unchanged; 
    DMAnCON1 = 0xB;
    //Source Message Size : 15
    DMAnSSZ = 15;
    //Destination Message Size : 1
    DMAnDSZ = 1;
    //Start Trigger : SIRQ SPI1TX; 
    DMAnSIRQ = 0x19;
    //Abort Trigger : AIRQ None; 
    DMAnAIRQ = 0x0;
	
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
	
    //AIRQEN disabled; DGO not in progress; SIRQEN disabled; EN enabled; 
    DMAnCON0 = 0x80;
	 
}

void DMA3_Enable(void)
{
    DMASELECT = 0x2;
    DMAnCON0bits.EN = 0x1;
}

void DMA3_Disable(void)
{
    DMASELECT = 0x2;
    DMAnCON0bits.EN = 0x0;
}

void DMA3_SourceRegionSelect(uint8_t region)
{
    DMASELECT = 0x2;
	DMAnCON1bits.SMR  = region;
}

void DMA3_SourceAddressSet(uint24_t address)
{
    DMASELECT = 0x2;
	DMAnSSA = address;
}

uint24_t DMA3_SourceAddressGet(void)
{
    DMASELECT = 0x2;
    return DMAnSSA;
}

void DMA3_DestinationAddressSet(uint16_t address)
{
    DMASELECT = 0x2;
	DMAnDSA = address;
}

uint16_t DMA3_DestinationAddressGet(void)
{
    DMASELECT = 0x2;
    return DMAnDSA;
}

void DMA3_SourceSizeSet(uint16_t size)
{
    DMASELECT = 0x2;
	DMAnSSZ= size;
}

uint16_t DMA3_SourceSizeGet(void)
{
    DMASELECT = 0x2;
    return DMAnSSZ;
}

void DMA3_DestinationSizeSet(uint16_t size)
{                     
    DMASELECT = 0x2;
	DMAnDSZ= size;
}

uint16_t DMA3_DestinationSizeGet(void)
{                     
    DMASELECT = 0x2;
    return DMAnDSZ;
}

uint24_t DMA3_SourcePointerGet(void)
{
    DMASELECT = 0x2;
	return DMAnSPTR;
}

uint16_t DMA3_DestinationPointerGet(void)
{
    DMASELECT = 0x2;
	return DMAnDPTR;
}

uint16_t DMA3_SourceCountGet(void)
{
    DMASELECT = 0x2;
    return DMAnSCNT;
}

uint16_t DMA3_DestinationCountGet(void)
{                     
    DMASELECT = 0x2;
    return DMAnDCNT;
}

void DMA3_StartTriggerSet(uint8_t sirq)
{
    DMASELECT = 0x2;
	DMAnSIRQ = sirq;
}

void DMA3_AbortTriggerSet(uint8_t airq)
{
    DMASELECT = 0x2;
	DMAnAIRQ = airq;
}

void DMA3_TransferStart(void)
{
    DMASELECT = 0x2;
	DMAnCON0bits.DGO = 1;
}

void DMA3_TransferWithTriggerStart(void)
{
    DMASELECT = 0x2;
	DMAnCON0bits.SIRQEN = 1;
}

void DMA3_TransferStop(void)
{
    DMASELECT = 0x2;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
}

void DMA3_DMAPrioritySet(uint8_t priority)
{
    uint8_t GIESaveState = INTCON0bits.GIE;
    INTCON0bits.GIE = 0;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 0;
	DMA3PR = priority;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 1;
    INTCON0bits.GIE = GIESaveState;
}

/**
 End of File
*/
