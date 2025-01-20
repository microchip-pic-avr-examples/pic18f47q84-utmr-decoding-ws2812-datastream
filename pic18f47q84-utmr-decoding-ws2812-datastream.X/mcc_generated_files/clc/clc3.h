/**
 * CLC3 Generated Driver API Header File.
 * 
 * @file clc3.h
 * 
 * @defgroup  clc3 CLC3
 * 
 * @brief This file contains the API prototypes for the CLC3 driver.
 *
 * @version CLC3 Driver Version 1.2.0
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

#ifndef CLC3_H
 #define CLC3_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>



/**
 * @ingroup clc3
 * @brief  Initializes the CLC3 module. This routine configures the CLC3 specific control registers.
 * @param None.
 * @return None.
 */
void CLC3_Initialize(void);

/**
 * @ingroup clc3
 * @brief Enables the CLC3 module.     
 * @param None.
 * @return None.
 */
void CLC3_Enable(void);

/**
 * @ingroup clc3
 * @brief Disables the CLC3 module.     
 * @param None.
 * @return None.
 */
void CLC3_Disable(void);

/**
 * @ingroup clc3
 * @brief Enabes Rising Edge Detection  on CLC3 output for the CLC3 module.     
 * @param None.
 * @return None.
 */
void CLC3_RisingEdgeDetectionEnable(void);

/**
 * @ingroup clc3
 * @brief Disables Rising Edge Detection  on CLC3 output for the CLC3 module.     
 * @param None.
 * @return None.
 */
void CLC3_RisingEdgeDetectionDisable(void);

/**
 * @ingroup clc3
 * @brief Enables Falling Edge Detection  on CLC3 output for the CLC3 module.     
 * @param None.
 * @return None.
 */
void CLC3_FallingEdgeDetectionEnable(void);

/**
 * @ingroup clc3
 * @brief Disables Falling Edge Detection on CLC3 output for the CLC3 module.     
 * @param None.
 * @return None.
 */
void CLC3_FallingEdgeDetectionDisable(void);


/**
 * @ingroup clc3
 * @brief Returns the output pin status of the CLC3 module.
 * @param  None.
 * @retval True - Output is 1
 * @retval False - Output is 0
 */
bool CLC3_OutputStatusGet(void); 

/**
 * @ingroup clc3
 * @brief Setter function for the CLC3 callback.
 * @param CallbackHandler - Pointer to the custom callback
 * @return None.
 */
 void CLC3_CallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup clc3
 * @brief Performs tasks to be executed on rising edge or falling edge event in Polling mode.
 * @param None.
 * @return None.
 */
void CLC3_Tasks(void);


#endif  // CLC3_H
/**
 End of File
*/

