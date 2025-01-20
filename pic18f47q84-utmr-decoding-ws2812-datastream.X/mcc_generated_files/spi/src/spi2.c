/**
  * SPI2 Generated Driver File
  *
  * @file spi2.c
  *
  * @ingroup spi2
  *
  * @brief This file contains the driver code for the SPI2 module.
  *
  * @version SPI2 Driver Version v3.2.0.
  * 
  * @version SPI2 Package Version v5.2.0.
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
#include "../spi_interface.h"
#include "../spi2.h"
#include "../spi_interrupt_types.h"

/**
 * @ingroup spi2
 * @struct SPI_INTERFACE SPI2
 * @brief Defines an object for SPI_INTERFACE functions.
 */ 
 
const struct SPI_INTERFACE SPI2 = {
    .Initialize = SPI2_Initialize,
    .Deinitialize = SPI2_Deinitialize,
    .Open = SPI2_Open,
    .Close = SPI2_Close,
	.Transfer = SPI2_Transfer,
    .BufferExchange = SPI2_BufferExchange,
    .BufferWrite = SPI2_BufferWrite,
    .BufferRead = SPI2_BufferRead,	
    .ByteExchange = SPI2_ByteExchange,
    .ByteWrite = SPI2_ByteWrite,
    .ByteRead = SPI2_ByteRead,
    .IsTxReady = SPI2_IsTxReady,
    .IsRxReady = SPI2_IsRxReady,
    .RxCompleteCallbackRegister = SPI2_RxCompleteCallbackRegister,
    .TxCompleteCallbackRegister = SPI2_TxCompleteCallbackRegister
};

static void (*SPI2_RxCompleteCallback)(void);
static void (*SPI2_TxCompleteCallback)(void);

static spi_descriptor_t spi2_descriptor = {
    .transmitBuffer = NULL,
    .receiveBuffer 	= NULL,
    .bytesToTransmit = 0,
    .bytesToReceive = 0,
    .status = SPI_RESET
};

// con0 == SPI2CON0, con1 == SPI2CON1, con2 == SPI2CON2, baud == SPI2BAUD, clksel == SPI2CLKSEL
static const spi_configuration_t spi2_configuration[] = {   
    { 0x0, 0x0, 0x0, 0x0, 0x0 }
};

void SPI2_Initialize(void)
{
    SPI2CON0bits.EN = 0U;

    // Disable the interrupts
    PIE5bits.SPI2IE 		= 0U;
    PIE5bits.SPI2TXIE 	= 0U;
    PIE5bits.SPI2RXIE 	= 0U;
	
    SPI2CON1 = (0 << _SPI2CON1_SDOP_POSITION)	/* SDOP active high(0) */
			|(0 << _SPI2CON1_SDIP_POSITION)	/* SDIP active high(0) */
			|(0 << _SPI2CON1_SSP_POSITION)	/* SSP active high(0) */
			|(0 << _SPI2CON1_FST_POSITION)	/* FST disabled(0) */
			|(0 << _SPI2CON1_CKP_POSITION)	/* CKP Idle:Low, Active:High(0) */
			|(0 << _SPI2CON1_CKE_POSITION)	/* CKE Idle to active(0) */
			|(0 << _SPI2CON1_SMP_POSITION);	/* SMP Middle(0) */
    SPI2CON2 = (0 << _SPI2CON2_RXR_POSITION)	/* RXR data is not stored in the FIFO(0) */
			|(0 << _SPI2CON2_TXR_POSITION)	/* TXR not required for a transfer(0) */
			|(0 << _SPI2CON2_SSET_POSITION);	/* SSET disabled(0) */
    SPI2BAUD = (0 << _SPI2BAUD_BAUD_POSITION);	/* BAUD 0x0(0) */
    SPI2CLK = (0 << _SPI2CLK_CLKSEL_POSITION);	/* CLKSEL FOSC(0) */     
	SPI2TCNTL = (0 << _SPI2TCNTL_TCNTL_POSITION);	/* TCNTL 0x0(0) */
	SPI2TCNTH = (0 << _SPI2TCNTH_TCNTH_POSITION);	/* TCNTH 0x0(0) */
	SPI2STATUS = (0 << _SPI2STATUS_CLRBF_POSITION)	/* CLRBF no action(0) */
			|(0 << _SPI2STATUS_RXRE_POSITION)	/* RXRE no error(0) */
			|(0 << _SPI2STATUS_TXWE_POSITION);	/* TXWE no error(0) */
	SPI2TWIDTH = (0 << _SPI2TWIDTH_TWIDTH_POSITION);	/* TWIDTH 0x0(0) */
	SPI2INTE = (0 << _SPI2INTE_TXUIE_POSITION)	/* TXUIE disabled(0) */
			|(0 << _SPI2INTE_RXOIE_POSITION)	/* RXOIE disabled(0) */
			|(0 << _SPI2INTE_EOSIE_POSITION)	/* EOSIE disabled(0) */
			|(0 << _SPI2INTE_SOSIE_POSITION)	/* SOSIE disabled(0) */
			|(0 << _SPI2INTE_TCZIE_POSITION)	/* TCZIE disabled(0) */
			|(0 << _SPI2INTE_SRMTIE_POSITION);	/* SRMTIE disabled(0) */
	SPI2INTF = (0 << _SPI2INTF_TXUIF_POSITION)	/* TXUIF disabled(0) */
			|(0 << _SPI2INTF_RXOIF_POSITION)	/* RXOIF disabled(0) */
			|(0 << _SPI2INTF_EOSIF_POSITION)	/* EOSIF disabled(0) */
			|(0 << _SPI2INTF_SOSIF_POSITION)	/* SOSIF disabled(0) */
			|(0 << _SPI2INTF_TCZIF_POSITION)	/* TCZIF disabled(0) */
			|(0 << _SPI2INTF_SRMTIF_POSITION);	/* SRMTIF disabled(0) */
	
	SPI2STATUSbits.CLRBF = 1U;
    
	SPI2_RxCompleteCallback = NULL;
	SPI2_TxCompleteCallback = NULL;	

	SPI2CON0 = (0 << _SPI2CON0_BMODE_POSITION)	/* BMODE last byte(0) */
			|(0 << _SPI2CON0_MST_POSITION)	/* MST bus client(0) */
			|(0 << _SPI2CON0_LSBF_POSITION)	/* LSBF MSb first(0) */
			|(0 << _SPI2CON0_EN_POSITION);	/* EN disabled(0) */

	spi2_descriptor.status = SPI_RESET;
}

void SPI2_Deinitialize(void)
{
    SPI2CON0 = 0x0;
    SPI2CON1 = 0x4;
    SPI2CON2 = 0x0;
    SPI2BAUD = 0x0;
    SPI2CLK = 0x0; 
	SPI2TXB = 0x0;
	SPI2TCNTL = 0x0;
	SPI2TCNTH = 0x0;
	SPI2STATUS = 0x20;
	SPI2TWIDTH = 0x0;
	SPI2INTE = 0x0;
	SPI2INTF = 0x0;
	spi2_descriptor.status = SPI_RESET;
}

bool SPI2_Open(uint8_t spiConfigIndex)
{
	bool returnValue = false; 
	if(false == SPI2CON0bits.EN)
	{
        SPI2CON0 = spi2_configuration[spiConfigIndex].con0;
        SPI2CON1 = spi2_configuration[spiConfigIndex].con1;
	    SPI2CON2 = spi2_configuration[spiConfigIndex].con2 & ~(_SPI2CON2_SPI2RXR_MASK) & ~(_SPI2CON2_SPI2TXR_MASK);
        SPI2BAUD = spi2_configuration[spiConfigIndex].baud;        
        SPI2CLK = spi2_configuration[spiConfigIndex].clksel;        
		TRISBbits.TRISB3 = 1;
		PIE5bits.SPI2IE 	= 1U;
        SPI2CON0bits.EN = 1U;
		spi2_descriptor.status = SPI_IDLE;
		returnValue = true;
	}
	else
	{
		returnValue = false;
	}
	return returnValue;
}

void SPI2_Close(void)
{
	SPI2CON0bits.EN = 0U;
	PIE5bits.SPI2IE 		= 0U;
    PIE5bits.SPI2TXIE 	= 0U;
    PIE5bits.SPI2RXIE 	= 0U;
	spi2_descriptor.status = SPI_RESET;
}

void SPI2_Transfer(const void *txBuffer, void *rxBuffer, size_t bufferSize)
{
	if (SPI_IDLE == spi2_descriptor.status)
    {
        SPI2STATUSbits.CLRBF = 1U;

		// Set as full duplex mode for buffer exchange operation
        SPI2CON2 = (SPI2CON2 | _SPI2CON2_SPI2RXR_MASK) | _SPI2CON2_SPI2TXR_MASK;

		// Load the spi2_descriptor
		spi2_descriptor.transmitBuffer 	= (const uint8_t*)txBuffer;
		spi2_descriptor.receiveBuffer 	= (uint8_t*)rxBuffer;
        spi2_descriptor.bytesToTransmit 	= bufferSize;
        spi2_descriptor.bytesToReceive 	= bufferSize;
        spi2_descriptor.status 			= SPI_BUSY;

        // Load the transfer count registers
		SPI2TCNTH = (uint8_t)(bufferSize>>8);
		SPI2TCNTL = (uint8_t)(bufferSize);
		
		PIE5bits.SPI2RXIE 	= 1U;
		PIE5bits.SPI2TXIE 	= 1U;
	}
	else
	{
		// No operation when module is already in use
	}
}

void SPI2_BufferExchange(void *bufferData, size_t bufferSize)
{
	if (SPI_IDLE == spi2_descriptor.status)
    {
        SPI2STATUSbits.CLRBF = 1U;

		// Set as full duplex mode for buffer exchange operation
        SPI2CON2 = (SPI2CON2 | _SPI2CON2_SPI2RXR_MASK) | _SPI2CON2_SPI2TXR_MASK;

		// Load the spi2_descriptor
		spi2_descriptor.transmitBuffer 	= (const uint8_t*)bufferData;
		spi2_descriptor.receiveBuffer 	= (uint8_t*)bufferData;
        spi2_descriptor.bytesToTransmit 	= bufferSize;
        spi2_descriptor.bytesToReceive 	= bufferSize;
        spi2_descriptor.status 			= SPI_BUSY;

        // Load the transfer count registers
		SPI2TCNTH = (uint8_t)(bufferSize>>8);
		SPI2TCNTL = (uint8_t)(bufferSize);
		
		PIE5bits.SPI2RXIE 	= 1U;
		PIE5bits.SPI2TXIE 	= 1U;
	}
	else
	{
		// No operation when module is already in use
	}
}

void SPI2_BufferWrite(void *bufferData, size_t bufferSize)
{
	if (SPI_IDLE == spi2_descriptor.status)
    {
		SPI2STATUSbits.CLRBF = 1U;

		// Set as transmit only mode for buffer write operation
        SPI2CON2 = (SPI2CON2 & ~_SPI2CON2_SPI2RXR_MASK) | _SPI2CON2_SPI2TXR_MASK;
		
		// Load the spi2_descriptor
		spi2_descriptor.transmitBuffer 	= (const uint8_t*)bufferData;
		spi2_descriptor.receiveBuffer 	= NULL;
        spi2_descriptor.bytesToTransmit 	= bufferSize;
	    spi2_descriptor.bytesToReceive 	= 0U;
        spi2_descriptor.status 			= SPI_BUSY;

        // Load the transfer count registers
		SPI2TCNTH = (uint8_t)(bufferSize>>8);
		SPI2TCNTL = (uint8_t)(bufferSize);

		PIE5bits.SPI2TXIE 	= 1U;
	}
	else
	{
		// No operation when module is already in use
	}
}

void SPI2_BufferRead(void *bufferData, size_t bufferSize)
{
	if (SPI_IDLE == spi2_descriptor.status)
    {
		SPI2STATUSbits.CLRBF = 1U;	

		// Set as receive only mode for buffer read operation
        SPI2CON2 = (SPI2CON2 & ~_SPI2CON2_SPI2TXR_MASK) | _SPI2CON2_SPI2RXR_MASK;
		
		// Load the spi2_descriptor
		spi2_descriptor.transmitBuffer 	= NULL;
		spi2_descriptor.receiveBuffer 	= (uint8_t*)bufferData;
	    spi2_descriptor.bytesToTransmit 	= 0U;
        spi2_descriptor.bytesToReceive 	= bufferSize;
	    spi2_descriptor.status 			= SPI_BUSY;

		// Load the transfer count registers
		SPI2TCNTH = (uint8_t)(bufferSize>>8);
		SPI2TCNTL = (uint8_t)(bufferSize);

		PIE5bits.SPI2RXIE 	= 1U;
	}
	else
	{
		// No operation when module is already in use
	}
}

uint8_t SPI2_ByteExchange(uint8_t byteData)
{
	uint8_t returnValue = 0U;
	while(SPI_IDLE != spi2_descriptor.status)
    {
        // Waiting for the current operation to finish
    }

	SPI2STATUSbits.CLRBF = 1U;
	
	// Set as full duplex mode
	SPI2CON2 = SPI2CON2 | _SPI2CON2_SPI2RXR_MASK | _SPI2CON2_SPI2TXR_MASK;	
	
	// Load the spi2_descriptor
	spi2_descriptor.transmitBuffer 		= (const uint8_t*)&byteData;
	spi2_descriptor.receiveBuffer 		= (uint8_t*)&byteData;
    spi2_descriptor.bytesToTransmit 		= 1;
	spi2_descriptor.bytesToReceive 		= 1;
	spi2_descriptor.status 				= SPI_BUSY;

    // Load the transfer count registers
	SPI2TCNTH = 0U;
	SPI2TCNTL = 1U;

	PIE5bits.SPI2RXIE 	= 1U;
	PIE5bits.SPI2TXIE 	= 1U;
	
	// Wait on transmit complete
	while(SPI_BUSY == spi2_descriptor.status){
	};
	
	return byteData;
}

void SPI2_ByteWrite(uint8_t byteData)
{
	if(SPI_IDLE == spi2_descriptor.status)
	{
		// Set as full duplex mode
		SPI2CON2 = SPI2CON2 | _SPI2CON2_SPI2RXR_MASK | _SPI2CON2_SPI2TXR_MASK;
        
		// Load the transfer count registers
		SPI2TCNTH = 0;
		SPI2TCNTL = 1;

		SPI2TXB = byteData;
	}
	else
	{
		// Do nothing
	}
}

uint8_t SPI2_ByteRead(void)
{
	uint8_t returnValue = 0x00U;
	if(SPI_IDLE == spi2_descriptor.status)
	{		
		// Set as full duplex mode
		SPI2CON2 = SPI2CON2 | _SPI2CON2_SPI2RXR_MASK | _SPI2CON2_SPI2TXR_MASK;
		
		// Store received data from receive buffer register 
		returnValue = SPI2RXB;
	}
	else
	{
		returnValue = 0x00U;
	}
	return returnValue;
}

bool SPI2_IsTxReady(void)
{
	bool returnValue = false;
    if (SPI_IDLE == spi2_descriptor.status)
    {
        returnValue = true;
    }
    else 
    {
        returnValue = false;
    }
    return returnValue;
}

bool SPI2_IsRxReady(void)
{
	bool returnValue = false;
    if((spi2_descriptor.status == SPI_IDLE) && (1U == PIR5bits.SPI2RXIF))
    {
        returnValue = true;
    }
    else 
    {
        returnValue = false;
    }
    return returnValue;
}

void SPI2_RxCompleteCallbackRegister(void (*rxCompleteCallbackHandler)(void))
{
	SPI2_RxCompleteCallback = rxCompleteCallbackHandler;
}

void SPI2_TxCompleteCallbackRegister(void (*txCompleteCallbackHandler)(void))
{
	SPI2_TxCompleteCallback = txCompleteCallbackHandler;
}

void __interrupt(irq(SPI2RX),base(8)) SPI2_Receive_ISR(void)
{
	if(spi2_descriptor.bytesToReceive > (size_t)0)
	{
		// Read the receive buffer register
		*spi2_descriptor.receiveBuffer = SPI2RXB;
		spi2_descriptor.receiveBuffer++;
		spi2_descriptor.bytesToReceive = spi2_descriptor.bytesToReceive - 1U;
	}
	else
    {
        // In case of operation for Byte Write
        // To clear the interrupt flag, perform a dummy read
        (void)SPI2RXB;
    }

	if((size_t)0 == spi2_descriptor.bytesToReceive)
	{
        // If no more bytes to receive disable the interrupts
		PIE5bits.SPI2RXIE 	= 0U;
        /* Check to see if more bytes are there to transmit.
         * In case of Buffer Read there wont be any bytes to transmit.
         * It should set it the status to SPI_IDLE.
		 */
        if((size_t)0 == spi2_descriptor.bytesToTransmit)
        {
	    	spi2_descriptor.status = SPI_IDLE;	
    	}
		else
		{
			// Do nothing
		}
		if (SPI2_RxCompleteCallback != NULL)
        {
        	SPI2_RxCompleteCallback();
        }
        else
        {
        	// No callback exists
        }
	}
	else
	{
		//Do nothing
	}
}

void __interrupt(irq(SPI2TX),base(8)) SPI2_Transmit_ISR(void)
{
	if(spi2_descriptor.bytesToTransmit > (size_t)0)
	{
        // Transmit the data on transmit buffer register
		SPI2TXB = *spi2_descriptor.transmitBuffer;
		spi2_descriptor.transmitBuffer++;
		spi2_descriptor.bytesToTransmit = spi2_descriptor.bytesToTransmit - 1U;
	}
	else
	{
		// Do nothing
	}
	
	/* The execution comes here to check if there is no more bytes to transmit.
	 *  This condition is true in case of last byte to be transmitted.
 	 */
	if((size_t)0 == spi2_descriptor.bytesToTransmit)
	{
		PIE5bits.SPI2TXIE 	= 0U;
        /* Check to see if more bytes are there to receive.
         * In case of Buffer Write there wont be any bytes to receive.
         * It should set it the status to SPI_IDLE.
		*/
        if((size_t)0 == spi2_descriptor.bytesToReceive)
		{
			spi2_descriptor.status = SPI_IDLE;
		}
		else
		{
			// Do nothing
		}
		if (SPI2_TxCompleteCallback != NULL)
    	{
        	SPI2_TxCompleteCallback();
    	}
    	else
    	{
        	// No callback exists
    	}
	}
}
void __interrupt(irq(SPI2),base(8)) SPI2_ISR(void)
{
	// This ISR will be for reporting errors
}