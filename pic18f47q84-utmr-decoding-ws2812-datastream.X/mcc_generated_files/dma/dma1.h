/**
 * DMA1 Generated Driver API Header File.
 * 
 * @file dma1.h
 * 
 * @defgroup  dma1 DMA1
 * 
 * @brief This file contains the API prototypes for the Direct Memory Access (DMA) driver.
 *
 * @version DMA1 Driver Version 2.12.1
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

#ifndef DMA1_H
#define DMA1_H

/**
  Section: Included Files
*/
#include <stdint.h>

/**
 * @ingroup dma1
 * @name Classic API Name Macros
 * Macros used to map the APIs to the deprecated API names:
 */
///@{
#define DMA1_SelectSourceRegion            DMA1_SourceRegionSelect
#define DMA1_SetSourceAddress              DMA1_SourceAddressSet
#define DMA1_SetDestinationAddress         DMA1_DestinationAddressSet
#define DMA1_SetSourceSize                 DMA1_SourceSizeSet
#define DMA1_SetDestinationSize            DMA1_DestinationSizeSet
#define DMA1_GetSourcePointer              DMA1_SourcePointerGet
#define DMA1_GetDestinationPointer         DMA1_DestinationPointerGet
#define DMA1_SetStartTrigger               DMA1_StartTriggerSet
#define DMA1_SetAbortTrigger               DMA1_AbortTriggerSet
#define DMA1_StartTransfer                 DMA1_TransferStart
#define DMA1_StartTransferWithTrigger      DMA1_TransferWithTriggerStart
#define DMA1_StopTransfer                  DMA1_TransferStop
#define DMA1_SetDMAPriority                DMA1_DMAPrioritySet
///@}

/**
 * @ingroup dma1
 * @var uint8_t captureData
 * @brief Destination address.
 */
extern uint8_t captureData[480];

/**
 * @ingroup dma1
 * @brief Initializes the DMA1 module. This is called only once before calling other DMA1 APIs.
 * @param None.
 * @return None. 
 */
void DMA1_Initialize(void);

/**
 * @ingroup dma1
 * @brief Enables the DMA1.
 * @param None.
 * @return None. 
 */
void DMA1_Enable(void);

/**
 * @ingroup dma1
 * @brief Disables the DMA1.
 * @param None.
 * @return None. 
 */
void DMA1_Disable(void);

/**
 * @ingroup dma1
 * @brief Sets the source region.
 * @param [in] region - Desired source region.
 * @return None.
 */
void DMA1_SourceRegionSelect(uint8_t region);

/**
 * @ingroup dma1
 * @brief Sets the source address for the DMA packet.
 * @param [in] address - Desired source address.
 * @return None.
 */
void DMA1_SourceAddressSet(uint24_t address);

/**
 * @ingroup dma1
 * @brief Returns the DMA Source Address.
 * @param None.
 * @return 24-bit DMA Source address.
 */
uint24_t DMA1_SourceAddressGet(void);

/**
 * @ingroup dma1
 * @brief Sets the destination address for the DMA packet.
 * @param [in] address - Desired destination address.
 * @return None.
 */
void DMA1_DestinationAddressSet(uint16_t address);

/**
 * @ingroup dma1
 * @brief Returns the DMA Destination Address.
 * @param None.
 * @return 16-bit DMA Destination address.
 */
uint16_t DMA1_DestinationAddressGet(void);

/**
 * @ingroup dma1
 * @brief Sets the size of the source array.
 * @param [in] size - Size of the source array in bytes.
 * @return None.
 */
void DMA1_SourceSizeSet(uint16_t size);

/**
 * @ingroup dma1
 * @brief Returns the DMA Source Message Size.
 * @param None.
 * @return 16-bit DMA Source message size value.
 */
uint16_t DMA1_SourceSizeGet(void);

/**
 * @ingroup dma1
 * @brief Sets the size of the destination array.
 * @param [in] size - Size of the destination array in bytes.
 * @return None.
 */
void DMA1_DestinationSizeSet(uint16_t size);

/**
 * @ingroup dma1
 * @brief Returns the DMA Destination Message Size.
 * @param None.
 * @return 16-bit DMA Destination message size value.
 */
uint16_t DMA1_DestinationSizeGet(void);

/**
 * @ingroup dma1
 * @brief Returns the current location read by the DMA.
 * @param None.
 * @return Current address pointer to the source.
 */
uint24_t DMA1_SourcePointerGet(void);

/**
 * @ingroup dma1
 * @brief Returns the current location written by the DMA.
 * @param None.
 * @return Current address pointer to the destination.
 */
uint16_t DMA1_DestinationPointerGet(void);

/**
 * @ingroup dma1
 * @brief Returns the DMA Source Count value.
 * @param None.
 * @return Current 16-bit source counter value.
 */
uint16_t DMA1_SourceCountGet(void);

/**
 * @ingroup dma1
 * @brief Returns the DMA Destination Count value.
 * @param None.
 * @return Current 16-bit destination counter value.
 */
uint16_t DMA1_DestinationCountGet(void);

/**
 * @ingroup dma1
 * @brief Sets the Start Trigger for the DMA. Note that this function does not start the transfer.
 * @param [in] sirq - Start trigger source.
 * @return None.
 */
void DMA1_StartTriggerSet(uint8_t sirq);

/**
 * @ingroup dma1
 * @brief Sets the Abort Trigger for the DMA. Note that this function does not start the transfer.
 * @param [in] airq - Abort trigger source.
 * @return None.
 */
void DMA1_AbortTriggerSet(uint8_t airq);

/**
 * @ingroup dma1
 * @brief Starts the DMA Transfer.
 * @param None.
 * @return None.
 */
void DMA1_TransferStart(void);

/**
 * @ingroup dma1
 * @brief Starts the DMA transfer based on the requested interrupt source.
 * @param None.
 * @return None.
 */
void DMA1_TransferWithTriggerStart(void);	

/**
 * @ingroup dma1
 * @brief Stops the DMA transfer.
 * @param None.
 * @return None.
 */
void DMA1_TransferStop(void);

/**
 * @ingroup dma1
 * @brief Sets the priority of the arbiter.
 * @param [in] priority - Priority of the DMA.
 * @return None.
 * NOTE: This function is dependent on the PR1WAY CONFIG bit.
 */
void DMA1_DMAPrioritySet(uint8_t priority);

#endif //DMA1_H