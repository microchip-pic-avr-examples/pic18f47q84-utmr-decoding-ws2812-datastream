/**
 * DMA2 Generated Driver API Header File.
 * 
 * @file dma2.h
 * 
 * @defgroup  dma2 DMA2
 * 
 * @brief This file contains the API prototypes for the Direct Memory Access (DMA) driver.
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

#ifndef DMA2_H
#define DMA2_H

/**
  Section: Included Files
*/
#include <stdint.h>

/**
 * @ingroup dma2
 * @name Classic API Name Macros
 * Macros used to map the APIs to the deprecated API names:
 */
///@{
#define DMA2_SelectSourceRegion            DMA2_SourceRegionSelect
#define DMA2_SetSourceAddress              DMA2_SourceAddressSet
#define DMA2_SetDestinationAddress         DMA2_DestinationAddressSet
#define DMA2_SetSourceSize                 DMA2_SourceSizeSet
#define DMA2_SetDestinationSize            DMA2_DestinationSizeSet
#define DMA2_GetSourcePointer              DMA2_SourcePointerGet
#define DMA2_GetDestinationPointer         DMA2_DestinationPointerGet
#define DMA2_SetStartTrigger               DMA2_StartTriggerSet
#define DMA2_SetAbortTrigger               DMA2_AbortTriggerSet
#define DMA2_StartTransfer                 DMA2_TransferStart
#define DMA2_StartTransferWithTrigger      DMA2_TransferWithTriggerStart
#define DMA2_StopTransfer                  DMA2_TransferStop
#define DMA2_SetDMAPriority                DMA2_DMAPrioritySet
///@}

/**
 * @ingroup dma2
 * @var uint8_t decodedColor
 * @brief Destination address.
 */
extern uint8_t decodedColor[4095];

/**
 * @ingroup dma2
 * @brief Initializes the DMA2 module. This is called only once before calling other DMA2 APIs.
 * @param None.
 * @return None. 
 */
void DMA2_Initialize(void);

/**
 * @ingroup dma2
 * @brief Enables the DMA2.
 * @param None.
 * @return None. 
 */
void DMA2_Enable(void);

/**
 * @ingroup dma2
 * @brief Disables the DMA2.
 * @param None.
 * @return None. 
 */
void DMA2_Disable(void);

/**
 * @ingroup dma2
 * @brief Sets the source region.
 * @param [in] region - Desired source region.
 * @return None.
 */
void DMA2_SourceRegionSelect(uint8_t region);

/**
 * @ingroup dma2
 * @brief Sets the source address for the DMA packet.
 * @param [in] address - Desired source address.
 * @return None.
 */
void DMA2_SourceAddressSet(uint24_t address);

/**
 * @ingroup dma2
 * @brief Returns the DMA Source Address.
 * @param None.
 * @return 24-bit DMA Source address.
 */
uint24_t DMA2_SourceAddressGet(void);

/**
 * @ingroup dma2
 * @brief Sets the destination address for the DMA packet.
 * @param [in] address - Desired destination address.
 * @return None.
 */
void DMA2_DestinationAddressSet(uint16_t address);

/**
 * @ingroup dma2
 * @brief Returns the DMA Destination Address.
 * @param None.
 * @return 16-bit DMA Destination address.
 */
uint16_t DMA2_DestinationAddressGet(void);

/**
 * @ingroup dma2
 * @brief Sets the size of the source array.
 * @param [in] size - Size of the source array in bytes.
 * @return None.
 */
void DMA2_SourceSizeSet(uint16_t size);

/**
 * @ingroup dma2
 * @brief Returns the DMA Source Message Size.
 * @param None.
 * @return 16-bit DMA Source message size value.
 */
uint16_t DMA2_SourceSizeGet(void);

/**
 * @ingroup dma2
 * @brief Sets the size of the destination array.
 * @param [in] size - Size of the destination array in bytes.
 * @return None.
 */
void DMA2_DestinationSizeSet(uint16_t size);

/**
 * @ingroup dma2
 * @brief Returns the DMA Destination Message Size.
 * @param None.
 * @return 16-bit DMA Destination message size value.
 */
uint16_t DMA2_DestinationSizeGet(void);

/**
 * @ingroup dma2
 * @brief Returns the current location read by the DMA.
 * @param None.
 * @return Current address pointer to the source.
 */
uint24_t DMA2_SourcePointerGet(void);

/**
 * @ingroup dma2
 * @brief Returns the current location written by the DMA.
 * @param None.
 * @return Current address pointer to the destination.
 */
uint16_t DMA2_DestinationPointerGet(void);

/**
 * @ingroup dma2
 * @brief Returns the DMA Source Count value.
 * @param None.
 * @return Current 16-bit source counter value.
 */
uint16_t DMA2_SourceCountGet(void);

/**
 * @ingroup dma2
 * @brief Returns the DMA Destination Count value.
 * @param None.
 * @return Current 16-bit destination counter value.
 */
uint16_t DMA2_DestinationCountGet(void);

/**
 * @ingroup dma2
 * @brief Sets the Start Trigger for the DMA. Note that this function does not start the transfer.
 * @param [in] sirq - Start trigger source.
 * @return None.
 */
void DMA2_StartTriggerSet(uint8_t sirq);

/**
 * @ingroup dma2
 * @brief Sets the Abort Trigger for the DMA. Note that this function does not start the transfer.
 * @param [in] airq - Abort trigger source.
 * @return None.
 */
void DMA2_AbortTriggerSet(uint8_t airq);

/**
 * @ingroup dma2
 * @brief Starts the DMA Transfer.
 * @param None.
 * @return None.
 */
void DMA2_TransferStart(void);

/**
 * @ingroup dma2
 * @brief Starts the DMA transfer based on the requested interrupt source.
 * @param None.
 * @return None.
 */
void DMA2_TransferWithTriggerStart(void);	

/**
 * @ingroup dma2
 * @brief Stops the DMA transfer.
 * @param None.
 * @return None.
 */
void DMA2_TransferStop(void);

/**
 * @ingroup dma2
 * @brief Sets the priority of the arbiter.
 * @param [in] priority - Priority of the DMA.
 * @return None.
 * NOTE: This function is dependent on the PR1WAY CONFIG bit.
 */
void DMA2_DMAPrioritySet(uint8_t priority);

#endif //DMA2_H