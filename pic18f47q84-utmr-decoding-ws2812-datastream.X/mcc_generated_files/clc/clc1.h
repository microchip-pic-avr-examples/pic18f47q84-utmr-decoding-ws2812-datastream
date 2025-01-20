/**
 * CLC1 Generated Driver API Header File.
 * 
 * @file clc1.h
 * 
 * @defgroup  clc1 CLC1
 * 
 * @brief This file contains the API prototypes for the CLC1 driver.
 *
 * @version CLC1 Driver Version 1.2.0
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

#ifndef CLC1_H
 #define CLC1_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>



/**
 * @ingroup clc1
 * @brief  Initializes the CLC1 module. This routine configures the CLC1 specific control registers.
 * @param None.
 * @return None.
 */
void CLC1_Initialize(void);

/**
 * @ingroup clc1
 * @brief Enables the CLC1 module.     
 * @param None.
 * @return None.
 */
void CLC1_Enable(void);

/**
 * @ingroup clc1
 * @brief Disables the CLC1 module.     
 * @param None.
 * @return None.
 */
void CLC1_Disable(void);

/**
 * @ingroup clc1
 * @brief Enabes Rising Edge Detection  on CLC1 output for the CLC1 module.     
 * @param None.
 * @return None.
 */
void CLC1_RisingEdgeDetectionEnable(void);

/**
 * @ingroup clc1
 * @brief Disables Rising Edge Detection  on CLC1 output for the CLC1 module.     
 * @param None.
 * @return None.
 */
void CLC1_RisingEdgeDetectionDisable(void);

/**
 * @ingroup clc1
 * @brief Enables Falling Edge Detection  on CLC1 output for the CLC1 module.     
 * @param None.
 * @return None.
 */
void CLC1_FallingEdgeDetectionEnable(void);

/**
 * @ingroup clc1
 * @brief Disables Falling Edge Detection on CLC1 output for the CLC1 module.     
 * @param None.
 * @return None.
 */
void CLC1_FallingEdgeDetectionDisable(void);


/**
 * @ingroup clc1
 * @brief Returns the output pin status of the CLC1 module.
 * @param  None.
 * @retval True - Output is 1
 * @retval False - Output is 0
 */
bool CLC1_OutputStatusGet(void); 

/**
 * @ingroup clc1
 * @brief Setter function for the CLC1 callback.
 * @param CallbackHandler - Pointer to the custom callback
 * @return None.
 */
 void CLC1_CallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup clc1
 * @brief Performs tasks to be executed on rising edge or falling edge event in Polling mode.
 * @param None.
 * @return None.
 */
void CLC1_Tasks(void);


#endif  // CLC1_H
/**
 End of File
*/

