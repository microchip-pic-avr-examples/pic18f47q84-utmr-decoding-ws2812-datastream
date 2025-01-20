/**
 * SPI Driver API Interface File
 *
 * @file spi_interface.h
 *
 * @defgroup spi SPI
 *
 * @brief This header file provides API prototypes for the SPI module in Polling and Interrupt mode.
 *
 * @version SPI Interface Version v3.1.0
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

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
        
/**
 * @ingroup spi
 * @struct SPI_INTERFACE SPI
 * @brief SPI Driver prototypes struct.
 */ 
struct SPI_INTERFACE
{   
    void (*Initialize)(void);
    void (*Deinitialize)(void);
    bool (*Open)(uint8_t spiConfigIndex);
    void (*Close)(void);
    void (*Transfer)(const void *txBuffer, void *rxBuffer, size_t bufferSize);
    void (*BufferExchange)(void *bufferData, size_t bufferSize);
    void (*BufferRead)(void *bufferData, size_t bufferSize);
    void (*BufferWrite)(void *bufferData, size_t bufferSize); 
    uint8_t (*ByteExchange)(uint8_t byteData);    
    uint8_t (*ByteRead)(void);
    void (*ByteWrite)(uint8_t byteData);
    bool (*IsRxReady)(void);
    bool (*IsTxReady)(void);
    void (*RxCompleteCallbackRegister)(void (*callbackHandler)(void));
    void (*TxCompleteCallbackRegister)(void (*callbackHandler)(void));
};

#endif /* SPI_INTERFACE_H */
