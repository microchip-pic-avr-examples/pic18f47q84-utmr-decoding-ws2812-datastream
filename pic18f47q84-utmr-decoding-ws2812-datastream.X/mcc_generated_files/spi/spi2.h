/**
 * SPI2 Generated Driver API Header File
 *
 * @file  spi2.h
 *
 * @defgroup  spi2 SPI2
 *
 * @brief This header file provides API prototypes for the SPI2 driver.
 *
 * @version SPI2 Driver Version v3.2.0.
 * 
 * @version SPI2 Package Version v5.2.0.
 *
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

#ifndef SPI2_H
#define SPI2_H

/**
 * Section: Included Files
 */ 
 
#include <stdint.h>
#include <stdbool.h>
#include "spi_interface.h"

/**
 * @ingroup spi2
 * @struct SPI_INTERFACE SPI2
 * @brief SPI driver interface object.
 */
extern const struct SPI_INTERFACE SPI2;


/**
 @ingroup spi2
 @typedef enum spi2_configuration_name_t
 @brief Enumeration of the different configurations supported by the driver. A configuration is specified as parameter to Open()
        and is used by the function to set SPI parameters as specified by the configuration.
 */
typedef enum 
{
    SPI2_DEFAULT
} spi2_configuration_name_t;

/**
 * @ingroup spi2
 * @brief Initializes the SPI2 module based on the configurable options in the MPLABÂ® Code Configurator (MCC) Melody UI.
 * @param None.
 * @return None.
 */
void SPI2_Initialize(void);

/**
 * @ingroup spi2
 * @brief Sets the registers to Power-on Reset values.
 * @param None.
 * @return None.
 */
void SPI2_Deinitialize(void);

/**
 * @ingroup spi2
 * @brief Enables the SPI2 module with the configurations passed as the parameter.
 * See spi2_config_names_t for the available configurations.
 * @param spiConfigIndex Configuration index 
 * @retval True  SPI2 module is enabled successfully with the chosen configuration
 * @retval False SPI2 module is already open with another configuration
 */
bool SPI2_Open(uint8_t spiConfigIndex);

/**
 * @ingroup spi2
 * @brief Closes the active configuration of the SPI2 module.
 * @param None.
 * @return None.
 */
void SPI2_Close(void);

/**
 * @ingroup spi2
 * @brief Exchanges the buffer using the SPI protocol with separate transmit and receive buffer locations. This function is blocking in Polling mode.
 * @param [in] *txBuffer Buffer address of the data to be transmitted during exchange
 * @param [in] *rxBuffer Buffer address of the data to be received during exchange
 * @param [in] bufferSize Size of the data in bytes
 * @return None.
 */
void SPI2_Transfer(const void * txBuffer, void * rxBuffer, size_t bufferSize);

/**
 * @ingroup spi2
 * @brief Exchanges the buffer using the SPI protocol. This function is blocking in Polling mode.
 * @param [in,out] *bufferData Buffer address of the data to be exchanged
 * @param [in] bufferSize Size of the data in bytes
 * @return None.
 */
void SPI2_BufferExchange(void * bufferData, size_t bufferSize);

/**
 * @ingroup spi2
 * @brief Writes a buffer using the SPI protocol. This function is blocking in Polling mode.
 * @param [in] *bufferData Buffer address of the data to be written
 * @param [in] bufferSize Size of the data in bytes
 * @return None.
 */
void SPI2_BufferWrite(void * bufferData, size_t bufferSize);

/**
 * @ingroup spi2
 * @brief Reads a buffer using the SPI protocol. This function is blocking in Polling mode.
 * @param [out] *bufferData Buffer address of the data to be read
 * @param [in] bufferSize Size of the data in bytes
 * @return None.
 */
void SPI2_BufferRead(void * bufferData, size_t bufferSize);

/**
 * @ingroup spi2
 * @brief Exchanges one byte using the SPI protocol. This function is blocking.
 * @param byteData Byte to be written
 * @return Received data byte
 */
uint8_t SPI2_ByteExchange(uint8_t byteData);

/**
 * @ingroup spi2
 * @brief Writes one byte using the SPI protocol.
 * @param byteData Byte to be written
 * @return None.
 */
void SPI2_ByteWrite(uint8_t byteData);

/**
 * @ingroup spi2
 * @brief Receives one byte using the SPI protocol.
 * @param None.
 * @return Received data byte
 */
uint8_t SPI2_ByteRead(void);

/**
 * @ingroup spi2
 * @brief Checks if the SPI2 module is ready to read data.
 * @param None.
 * @retval True SPI2 module is ready to read data
 * @retval False SPI2 module is not ready to read data
 */
bool SPI2_IsRxReady(void);

/**
 * @ingroup spi2
 * @brief  Checks if the SPI2 is ready to write data.
 * @param None.
 * @retval True SPI2 module is ready to write data
 * @retval False SPI2 module is not ready to write data
 */
bool SPI2_IsTxReady(void);

/**
 * @ingroup spi2
 * @brief Sets the callback function to be executed at the completion of data transfer receive in Interrupt mode.
 * @param Pointer to the function to be executed
 * @return None.
 */
void SPI2_RxCompleteCallbackRegister(void (*rxCompleteCallbackHandler)(void));

/**
 * @ingroup spi2
 * @brief Sets the callback function to be executed at the completion of data transfer transmit in Interrupt mode.
 * @param Pointer to the function to be executed
 * @return None.
 */
void SPI2_TxCompleteCallbackRegister(void (*txCompleteCallbackHandler)(void));

/**
 * @ingroup spi2
 * @brief Interrupt Service Routine (ISR) with receive interrupt RXIF for the SPI2 module.
 * @param None.
 * @return None.
 */
void SPI2_Receive_ISR(void);

/**
 * @ingroup spi2
 * @brief ISR with transmit interrupt TXIF for the SPI2 module.
 * @param None.
 * @return None.
 */
void SPI2_Transmit_ISR(void);

/**
 * @ingroup spi2
 * @brief ISR for the SPI2 module.
 * @param None.
 * @return None.
 */
void SPI2_ISR(void);
#endif // SPI2_H