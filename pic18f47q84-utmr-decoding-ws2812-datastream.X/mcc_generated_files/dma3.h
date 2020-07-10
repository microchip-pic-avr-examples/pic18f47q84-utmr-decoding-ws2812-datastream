/**
  DMA3 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    dma3.h

  @Summary
    This is the generated header file for the DMA3 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for DMA3.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC18F47Q84
        Driver Version    :  1.0.0
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

#ifndef DMA3_H
#define DMA3_H

/**
  Section: Included Files
*/
#include <stdint.h>
#include "../ws2812_seed.h"

extern const uint8_t ws2812_seed[];

/**
 * @brief Initializes the DMA3 module
 *        This routine must be called before any other DMA3 routine
 * @return None.
 * @param None.
 */
void DMA3_Initialize(void);

/**
 * @brief Sets the source region as per user selection
 * @return None.
 * @param [in] Desired source region
 */
void DMA3_SelectSourceRegion(uint8_t region);

/**
 * @brief Sets the Source Address for the DMA packet
 * @return None.
 * @param [in] Desired Source Address
 */
void DMA3_SetSourceAddress(uint24_t address);

/**
 * @brief Sets the destination address for the DMA packet
 * @return None.
 * @param [in] Desired Destination Address
 */
void DMA3_SetDestinationAddress(uint16_t address);

/**
 * @brief Sets the size of the Source array
 * @return None.
 * @param [in] Size of Source Array
 */
void DMA3_SetSourceSize(uint16_t size);

/**
 * @brief Sets the size of the destination array
 * @return None.
 * @param [in] Size of Destination array
 */
void DMA3_SetDestinationSize(uint16_t size);

/**
 * @brief Returns the current location from which the DMA has read
 * @return Current Source pointer
 * @param None
 */
uint24_t DMA3_GetSourcePointer(void);

/**
 * @brief Returns the current location where the DMA last wrote
 * @return Current Destination pointer
 * @param None
 */
uint16_t DMA3_GetDestinationPointer(void);

/**
 * @brief Sets the Start Trigger for DMA, doesn't start the transfer
 * @return None.
 * @param [in] Start Trigger Source
 */
void DMA3_SetStartTrigger(uint8_t sirq);

/**
 * @brief Sets the Abort Trigger for DMA, doesn't abort the transfer
 * @return None.
 * @param [in] Abort Trigger Source
 */
void DMA3_SetAbortTrigger(uint8_t airq);

/**
 * @brief Starts the DMA Transfer by setting GO bit
 * @return None.
 * @param None.
 */
void DMA3_StartTransfer(void);

/**
 * @brief Starts the DMA transfer by enabling the trigger
 * @return None.
 * @param None.
 */
void DMA3_StartTransferWithTrigger(void);	

/**
 * @brief Stops all the possible triggers and also clears the GO bit
 * @return None.
 * @param None.
 */
void DMA3_StopTransfer(void);

/**
 * @brief Unlocks Arbiter - changes priority - locks Arbiter
 * @return None.
 * @param [in] Priority of DMA
 */
void DMA3_SetDMAPriority(uint8_t priority);




#endif //DMA3_H
