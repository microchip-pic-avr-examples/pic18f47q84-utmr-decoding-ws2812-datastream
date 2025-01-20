/**
 * DMA3 Generated Driver API Header File.
 * 
 * @file dma3.h
 * 
 * @defgroup  dma3 DMA3
 * 
 * @brief This file contains the API prototypes for the Direct Memory Access (DMA) driver.
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

#ifndef DMA3_H
#define DMA3_H

/**
  Section: Included Files
*/
#include <stdint.h>

/**
 * @ingroup dma3
 * @name Classic API Name Macros
 * Macros used to map the APIs to the deprecated API names:
 */
///@{
#define DMA3_SelectSourceRegion            DMA3_SourceRegionSelect
#define DMA3_SetSourceAddress              DMA3_SourceAddressSet
#define DMA3_SetDestinationAddress         DMA3_DestinationAddressSet
#define DMA3_SetSourceSize                 DMA3_SourceSizeSet
#define DMA3_SetDestinationSize            DMA3_DestinationSizeSet
#define DMA3_GetSourcePointer              DMA3_SourcePointerGet
#define DMA3_GetDestinationPointer         DMA3_DestinationPointerGet
#define DMA3_SetStartTrigger               DMA3_StartTriggerSet
#define DMA3_SetAbortTrigger               DMA3_AbortTriggerSet
#define DMA3_StartTransfer                 DMA3_TransferStart
#define DMA3_StartTransferWithTrigger      DMA3_TransferWithTriggerStart
#define DMA3_StopTransfer                  DMA3_TransferStop
#define DMA3_SetDMAPriority                DMA3_DMAPrioritySet
///@}

/**
 * @ingroup dma3
 * @brief Initializes the DMA3 module. This is called only once before calling other DMA3 APIs.
 * @param None.
 * @return None. 
 */
void DMA3_Initialize(void);

/**
 * @ingroup dma3
 * @brief Enables the DMA3.
 * @param None.
 * @return None. 
 */
void DMA3_Enable(void);

/**
 * @ingroup dma3
 * @brief Disables the DMA3.
 * @param None.
 * @return None. 
 */
void DMA3_Disable(void);

/**
 * @ingroup dma3
 * @brief Sets the source region.
 * @param [in] region - Desired source region.
 * @return None.
 */
void DMA3_SourceRegionSelect(uint8_t region);

/**
 * @ingroup dma3
 * @brief Sets the source address for the DMA packet.
 * @param [in] address - Desired source address.
 * @return None.
 */
void DMA3_SourceAddressSet(uint24_t address);

/**
 * @ingroup dma3
 * @brief Returns the DMA Source Address.
 * @param None.
 * @return 24-bit DMA Source address.
 */
uint24_t DMA3_SourceAddressGet(void);

/**
 * @ingroup dma3
 * @brief Sets the destination address for the DMA packet.
 * @param [in] address - Desired destination address.
 * @return None.
 */
void DMA3_DestinationAddressSet(uint16_t address);

/**
 * @ingroup dma3
 * @brief Returns the DMA Destination Address.
 * @param None.
 * @return 16-bit DMA Destination address.
 */
uint16_t DMA3_DestinationAddressGet(void);

/**
 * @ingroup dma3
 * @brief Sets the size of the source array.
 * @param [in] size - Size of the source array in bytes.
 * @return None.
 */
void DMA3_SourceSizeSet(uint16_t size);

/**
 * @ingroup dma3
 * @brief Returns the DMA Source Message Size.
 * @param None.
 * @return 16-bit DMA Source message size value.
 */
uint16_t DMA3_SourceSizeGet(void);

/**
 * @ingroup dma3
 * @brief Sets the size of the destination array.
 * @param [in] size - Size of the destination array in bytes.
 * @return None.
 */
void DMA3_DestinationSizeSet(uint16_t size);

/**
 * @ingroup dma3
 * @brief Returns the DMA Destination Message Size.
 * @param None.
 * @return 16-bit DMA Destination message size value.
 */
uint16_t DMA3_DestinationSizeGet(void);

/**
 * @ingroup dma3
 * @brief Returns the current location read by the DMA.
 * @param None.
 * @return Current address pointer to the source.
 */
uint24_t DMA3_SourcePointerGet(void);

/**
 * @ingroup dma3
 * @brief Returns the current location written by the DMA.
 * @param None.
 * @return Current address pointer to the destination.
 */
uint16_t DMA3_DestinationPointerGet(void);

/**
 * @ingroup dma3
 * @brief Returns the DMA Source Count value.
 * @param None.
 * @return Current 16-bit source counter value.
 */
uint16_t DMA3_SourceCountGet(void);

/**
 * @ingroup dma3
 * @brief Returns the DMA Destination Count value.
 * @param None.
 * @return Current 16-bit destination counter value.
 */
uint16_t DMA3_DestinationCountGet(void);

/**
 * @ingroup dma3
 * @brief Sets the Start Trigger for the DMA. Note that this function does not start the transfer.
 * @param [in] sirq - Start trigger source.
 * @return None.
 */
void DMA3_StartTriggerSet(uint8_t sirq);

/**
 * @ingroup dma3
 * @brief Sets the Abort Trigger for the DMA. Note that this function does not start the transfer.
 * @param [in] airq - Abort trigger source.
 * @return None.
 */
void DMA3_AbortTriggerSet(uint8_t airq);

/**
 * @ingroup dma3
 * @brief Starts the DMA Transfer.
 * @param None.
 * @return None.
 */
void DMA3_TransferStart(void);

/**
 * @ingroup dma3
 * @brief Starts the DMA transfer based on the requested interrupt source.
 * @param None.
 * @return None.
 */
void DMA3_TransferWithTriggerStart(void);	

/**
 * @ingroup dma3
 * @brief Stops the DMA transfer.
 * @param None.
 * @return None.
 */
void DMA3_TransferStop(void);

/**
 * @ingroup dma3
 * @brief Sets the priority of the arbiter.
 * @param [in] priority - Priority of the DMA.
 * @return None.
 * NOTE: This function is dependent on the PR1WAY CONFIG bit.
 */
void DMA3_DMAPrioritySet(uint8_t priority);

#endif //DMA3_H