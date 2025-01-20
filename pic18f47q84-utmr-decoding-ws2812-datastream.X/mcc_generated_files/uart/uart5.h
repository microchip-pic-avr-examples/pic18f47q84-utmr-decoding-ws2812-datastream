/**
 * UART5 Generated Driver API Header File
 * 
 * @file uart5.h
 * 
 * @defgroup uart5 UART5
 * 
 * @brief This file contains API prototypes and other data types for the the Universal Asynchronous Receiver and Transmitter (UART) module.
 *
 * @version UART5 Driver Version 3.0.8
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

#ifndef UART5_H
#define UART5_H


#include <stdbool.h>
#include <stdint.h>
/**
    @ingroup uart5 
    @def Standard Input Output functions
    @misradeviation{@required, 21.6} This inclusion is essential for UART module to use Printf function for print the character.
*/
/* cppcheck-suppress misra-c2012-21.6 */
#include <stdio.h>
#include "../system/system.h"
#include "uart_drv_interface.h"

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

#define UART5_interface UART5

/**
 @ingroup uart5
 @struct uart5_status_t
 @brief This is a structure defined for errors in reception of data.
 */
 /**
 * @misradeviation{@advisory,19.2}
 * The UART error status necessitates checking the bitfield and accessing the status within the group byte therefore the use of a union is essential.
 */
 /* cppcheck-suppress misra-c2012-19.2 */
typedef union {
    struct {
        uint8_t perr : 1;     /**<This is a bit field for Parity Error status*/
        uint8_t ferr : 1;     /**<This is a bit field for Framing Error status*/
        uint8_t oerr : 1;     /**<This is a bit field for Overfrun Error status*/
        uint8_t reserved : 5; /**<Reserved*/
    };
    size_t status;            /**<Group byte for status errors*/
}uart5_status_t;


/**
 * @ingroup uart5
 * @brief External object for uart_drv_interface.
 */
extern const uart_drv_interface_t UART5;

/**
 * @ingroup uart5
 * @brief Initializes the UART5 module. This routine is called
 *        only once during system initialization, before calling other APIs.
 * @param None.
 * @return None.
 */
void UART5_Initialize(void);

/**
 * @ingroup uart5
 * @brief Deinitializes and disables the UART5 module.

 * @param None.
 * @return None.
 */
void UART5_Deinitialize(void);

/**
 * @ingroup uart5
 * @brief Enables the UART5 module.     
 * @param None.
 * @return None.
 */
void UART5_Enable(void);

/**
 * @ingroup uart5
 * @brief Disables the UART5 module.
 * @param None.
 * @return None.
 */
void UART5_Disable(void);

/**
 * @ingroup uart5
 * @brief Enables the UART5 transmitter. 
 *        The UART5 must be enabled to send the bytes over to the TX pin.
 * @param None.
 * @return None.
 */
void UART5_TransmitEnable(void);

/**
 * @ingroup uart5
 * @brief Disables the UART5 transmitter.
 * @param None.
 * @return None.
 */
void UART5_TransmitDisable(void);

/**
 * @ingroup uart5
 * @brief Enables the UART5 to send a break control.
 * @param None.
 * @return None.
 */
void UART5_SendBreakControlEnable(void);

/**
 * @ingroup uart5
 * @brief Disables the UART5 Send Break Control bit.
 * @param None.
 * @return None.
 */
void UART5_SendBreakControlDisable(void);

/**
 * @ingroup uart5
 * @brief Enables the UART5 Auto-Baud Detection (ABR).
 * @param bool enable
 * @return None.
 */
void UART5_AutoBaudSet(bool enable);


/**
 * @ingroup uart5
 * @brief Reads the UART5 Auto-Baud Detection Complete bit.
 * @param None.
 * @return None.
 */
bool UART5_AutoBaudQuery(void);

/**
 * @ingroup uart5
 * @brief Resets the UART5 Auto-Baud Detection Complete bit.
 * @param None.
 * @return None.
 */
void UART5_AutoBaudDetectCompleteReset(void);

/**
 * @ingroup uart5
 * @brief Reads the UART5 Auto-Baud Detection Overflow bit.
 * @param None.
 * @return None.
 */
bool UART5_IsAutoBaudDetectOverflow(void);

/**
 * @ingroup uart5
 * @brief Resets the UART5 Auto-Baud Detection Overflow bit.
 * @param None.
 * @return None.
 */
void UART5_AutoBaudDetectOverflowReset(void);

/**
 * @ingroup uart5
 * @brief Checks if the UART5 receiver has received data and is ready to be read.
 * @param None.
 * @retval True - UART5 receiver FIFO has data
 * @retval False - UART5 receiver FIFO is empty
 */
bool UART5_IsRxReady(void);

/**
 * @ingroup uart5
 * @brief Checks if the UART5 transmitter is ready to accept a data byte.
 * @param None.
 * @retval True -  The UART5 transmitter FIFO has at least a one byte space
 * @retval False - The UART5 transmitter FIFO is full
 */
bool UART5_IsTxReady(void);

/**
 * @ingroup uart5
 * @brief Returns the status of the Transmit Shift Register (TSR).
 * @param None.
 * @retval True - Data completely shifted out from the TSR
 * @retval False - Data is present in Transmit FIFO and/or in TSR
 */
bool UART5_IsTxDone(void);

/**
 * @ingroup uart5
 * @brief Gets the error status of the last read byte. Call 
 *        this function before calling UART5_Read().
 * @pre Call UART5_RxEnable() to enable RX before calling this API.
 * @param None.
 * @return Status of the last read byte. See the uart5_status_t struct for more details.
 */
size_t UART5_ErrorGet(void);

/**
 * @ingroup uart5
 * @brief Reads the eight bits from the Receiver FIFO register.
 * @pre Check the transfer status to see if the receiver is not empty before calling this function. Check 
 *      UART5_IsRxReady() in if () before calling this API.
 * @param None.
 * @return 8-bit data from the RX FIFO register
 */
uint8_t UART5_Read(void);

/**
 * @ingroup uart5
 * @brief Writes a byte of data to the Transmitter FIFO register.
 * @pre Check the transfer status to see if the transmitter is not empty before calling this function. Check
 *      UART5_IsTxReady() in if () before calling this API.
 * @param txData  - Data byte to write to the TX FIFO
 * @return None.
 */
void UART5_Write(uint8_t txData);

/**
 * @ingroup uart5
 * @brief Calls the function upon UART5 framing error.
 * @param callbackHandler - Function pointer called when the framing error condition occurs
 * @return None.
 */
void UART5_FramingErrorCallbackRegister(void (* callbackHandler)(void));

/**
 * @ingroup uart5
 * @brief Calls the function upon UART5 overrun error.
 * @param callbackHandler - Function pointer called when the overrun error condition occurs
 * @return None.
 */
void UART5_OverrunErrorCallbackRegister(void (* callbackHandler)(void));

/**
 * @ingroup uart5
 * @brief Calls the function upon UART5 parity error.
 * @param callbackHandler - Function pointer called when the parity error condition occurs
 * @return None.
 */
void UART5_ParityErrorCallbackRegister(void (* callbackHandler)(void));

/**
 * @ingroup uart5
 * @brief This function used to printf support for reads the 8 bits from the FIFO register receiver.
 * @param None.
 * @return 8-bit data from RX FIFO register.
 */
int getch(void);

/**
 * @ingroup uart5
 * @brief This function used to printf support for writes a byte of data to the transmitter FIFO register.
 * @param txData  - Data byte to write to the TX FIFO.
 * @return None.
 */
void putch(char txData);


#ifdef __cplusplus  // Provide C++ Compatibility


    }

#endif

#endif  // UART5_H
