/**
  UART5 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    uart5.h

  @Summary
    This is the generated header file for the UART5 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for UART5.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC18F47Q84
        Driver Version    :  2.4.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
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

#ifndef UART5_H
#define UART5_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Macro Declarations
*/

#define UART5_DataReady  (UART5_is_rx_ready())

/**
  Section: Data Type Definitions
*/

typedef union {
    struct {
        unsigned perr : 1;
        unsigned ferr : 1;
        unsigned oerr : 1;
        unsigned reserved : 5;
    };
    uint8_t status;
}uart5_status_t;


/**
  Section: UART5 APIs
*/

/**
  @Summary
    Initialization routine that takes inputs from the UART5 GUI.

  @Description
    This routine initializes the UART5 driver.
    This routine must be called before any other UART5 routine is called.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment

  @Example
*/
void UART5_Initialize(void);

/**
  @Summary
    Checks if the UART5 receiver ready for reading

  @Description
    This routine checks if UART5 receiver has received data 
    and ready to be read

  @Preconditions
    UART5_Initialize() function should be called
    before calling this function
    UART5 receiver should be enabled before calling this 
    function

  @Param
    None

  @Returns
    Status of UART5 receiver
    TRUE: UART5 receiver is ready for reading
    FALSE: UART5 receiver is not ready for reading
    
  @Example
    <code>
    void main(void)
    {
        volatile uint8_t rxData;
        
        // Initialize the device
        SYSTEM_Initialize();
        
        while(1)
        {
            // Logic to echo received data
            if(UART5_is_rx_ready())
            {
                rxData = UART5_Read();
                if(UART5_is_tx_ready())
                {
                    UART5_Write(rxData);
                }
            }
        }
    }
    </code>
*/
bool UART5_is_rx_ready(void);

/**
  @Summary
    Checks if the UART5 transmitter is ready to transmit data

  @Description
    This routine checks if UART5 transmitter is ready 
    to accept and transmit data byte

  @Preconditions
    UART5_Initialize() function should have been called
    before calling this function.
    UART5 transmitter should be enabled before calling 
    this function

  @Param
    None

  @Returns
    Status of UART5 transmitter
    TRUE: UART5 transmitter is ready
    FALSE: UART5 transmitter is not ready
    
  @Example
    <code>
    void main(void)
    {
        volatile uint8_t rxData;
        
        // Initialize the device
        SYSTEM_Initialize();
        
        while(1)
        {
            // Logic to echo received data
            if(UART5_is_rx_ready())
            {
                rxData = UART5_Read();
                if(UART5_is_tx_ready())
                {
                    UART5_Write(rxData);
                }
            }
        }
    }
    </code>
*/
bool UART5_is_tx_ready(void);

/**
  @Summary
    Checks if UART5 data is transmitted

  @Description
    This function return the status of transmit shift register

  @Preconditions
    UART5_Initialize() function should be called
    before calling this function
    UART5 transmitter should be enabled and UART5_Write
    should be called before calling this function

  @Param
    None

  @Returns
    Status of UART5 transmit shift register
    TRUE: Data completely shifted out if the UART shift register
    FALSE: Data is not completely shifted out of the shift register
    
  @Example
    <code>
    void main(void)
    {
        volatile uint8_t rxData;
        
        // Initialize the device
        SYSTEM_Initialize();
        
        while(1)
        {
            if(UART5_is_tx_ready())
            {
                LED_0_SetHigh();
                UART5Write(rxData);
            }
            if(UART5_is_tx_done()
            {
                LED_0_SetLow();
            }
        }
    }
    </code>
*/
bool UART5_is_tx_done(void);

/**
  @Summary
    Gets the error status of the last read byte.

  @Description
    This routine gets the error status of the last read byte.

  @Preconditions
    UART5_Initialize() function should have been called
    before calling this function. The returned value is only
    updated after a read is called.

  @Param
    None

  @Returns
    the status of the last read byte

  @Example
	<code>
    void main(void)
    {
        volatile uint8_t rxData;
        volatile uart5_status_t rxStatus;
        
        // Initialize the device
        SYSTEM_Initialize();
        
        // Enable the Global Interrupts
        INTERRUPT_GlobalInterruptEnable();
        
        while(1)
        {
            // Logic to echo received data
            if(UART5_is_rx_ready())
            {
                rxData = UART5_Read();
                rxStatus = UART5_get_last_status();
                if(rxStatus.ferr){
                    LED_0_SetHigh();
                }
            }
        }
    }
    </code>
 */
uart5_status_t UART5_get_last_status(void);

/**
  @Summary
    Read a byte of data from the UART5.

  @Description
    This routine reads a byte of data from the UART5.

  @Preconditions
    UART5_Initialize() function should have been called
    before calling this function. The transfer status should be checked to see
    if the receiver is not empty before calling this function.
	
	UART5_DataReady is a macro which checks if any byte is received.
	Call this macro before using this function.

  @Param
    None

  @Returns
    A data byte received by the driver.
	
  @Example
	<code>
            void main(void) {
                            // initialize the device
                            SYSTEM_Initialize();
                            uint8_t data;

                            // Enable the Global Interrupts
                            INTERRUPT_GlobalInterruptEnable();

                            // Enable the Peripheral Interrupts
                            INTERRUPT_PeripheralInterruptEnable();

                            printf("\t\tTEST CODE\n\r");		//Enable redirect STDIO to USART before using printf statements
                            printf("\t\t---- ----\n\r");
                            printf("\t\tECHO TEST\n\r");
                            printf("\t\t---- ----\n\n\r");
                            printf("Enter any string: ");
                            do{
                            data = UART5_Read();		// Read data received
                            UART5_Write(data);			// Echo back the data received
                            }while(!UART5_DataReady);		//check if any data is received

                    }
    </code>
*/
uint8_t UART5_Read(void);

 /**
  @Summary
    Writes a byte of data to the UART5.

  @Description
    This routine writes a byte of data to the UART5.

  @Preconditions
    UART5_Initialize() function should have been called
    before calling this function. The transfer status should be checked to see
    if transmitter is not busy before calling this function.

  @Param
    txData  - Data byte to write to the UART5

  @Returns
    None
  
  @Example
      <code>
          Refer to UART5_Read() for an example	
      </code>
*/
void UART5_Write(uint8_t txData);



/**
  @Summary
    Set UART5 Framing Error Handler

  @Description
    This API sets the function to be called upon UART5 framing error

  @Preconditions
    Initialize  the UART5 before calling this API

  @Param
    Address of function to be set as framing error handler

  @Returns
    None
*/
void UART5_SetFramingErrorHandler(void (* interruptHandler)(void));

/**
  @Summary
    Set UART5 Overrun Error Handler

  @Description
    This API sets the function to be called upon UART5 overrun error

  @Preconditions
    Initialize  the UART5 module before calling this API

  @Param
    Address of function to be set as overrun error handler

  @Returns
    None
*/
void UART5_SetOverrunErrorHandler(void (* interruptHandler)(void));

/**
  @Summary
    Set UART5 Error Handler

  @Description
    This API sets the function to be called upon UART5 error

  @Preconditions
    Initialize  the UART5 module before calling this API

  @Param
    Address of function to be set as error handler

  @Returns
    None
*/
void UART5_SetErrorHandler(void (* interruptHandler)(void));











#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  // UART5_H
/**
 End of File
*/
