/**
 * CLC4 Generated Driver API Header File.
 * 
 * @file clc4.h
 * 
 * @defgroup  clc4 CLC4
 * 
 * @brief This file contains the API prototypes for the CLC4 driver.
 *
 * @version CLC4 Driver Version 1.2.0
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

#ifndef CLC4_H
 #define CLC4_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>



/**
 * @ingroup clc4
 * @brief  Initializes the CLC4 module. This routine configures the CLC4 specific control registers.
 * @param None.
 * @return None.
 */
void CLC4_Initialize(void);

/**
 * @ingroup clc4
 * @brief Enables the CLC4 module.     
 * @param None.
 * @return None.
 */
void CLC4_Enable(void);

/**
 * @ingroup clc4
 * @brief Disables the CLC4 module.     
 * @param None.
 * @return None.
 */
void CLC4_Disable(void);

/**
 * @ingroup clc4
 * @brief Enabes Rising Edge Detection  on CLC4 output for the CLC4 module.     
 * @param None.
 * @return None.
 */
void CLC4_RisingEdgeDetectionEnable(void);

/**
 * @ingroup clc4
 * @brief Disables Rising Edge Detection  on CLC4 output for the CLC4 module.     
 * @param None.
 * @return None.
 */
void CLC4_RisingEdgeDetectionDisable(void);

/**
 * @ingroup clc4
 * @brief Enables Falling Edge Detection  on CLC4 output for the CLC4 module.     
 * @param None.
 * @return None.
 */
void CLC4_FallingEdgeDetectionEnable(void);

/**
 * @ingroup clc4
 * @brief Disables Falling Edge Detection on CLC4 output for the CLC4 module.     
 * @param None.
 * @return None.
 */
void CLC4_FallingEdgeDetectionDisable(void);


/**
 * @ingroup clc4
 * @brief Returns the output pin status of the CLC4 module.
 * @param  None.
 * @retval True - Output is 1
 * @retval False - Output is 0
 */
bool CLC4_OutputStatusGet(void); 

/**
 * @ingroup clc4
 * @brief Setter function for the CLC4 callback.
 * @param CallbackHandler - Pointer to the custom callback
 * @return None.
 */
 void CLC4_CallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup clc4
 * @brief Performs tasks to be executed on rising edge or falling edge event in Polling mode.
 * @param None.
 * @return None.
 */
void CLC4_Tasks(void);


#endif  // CLC4_H
/**
 End of File
*/

