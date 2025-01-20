/**
 * TMR2 Generated Driver API Header File
 *
 * @file tmr2.h
 *  
 * @defgroup tmr2 TMR2
 *
 * @brief This file contains deprecated macros or functions for the TMR2 driver.
 *
 * @version Driver Version 4.0.0
 *
 * @version Package Version 5.0.0
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

#ifndef TMR2_DEPRECATED_H
#define TMR2_DEPRECATED_H

#warning "The tmr2_deprecated.h file contains the deprecated macros or functions. Replace the deprecated macro or functions with the recommended alternative."

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application. 
 * It depends on the application whether a macro is used or not. 
 */

/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_CounterGet API.
 *        The TMR2_Read will be deprecated in the future release. Use TMR2_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR2_Read TMR2_CounterGet
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_CounterGet API.
 *        The Timer2_Read will be deprecated in the future release. Use Timer2_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_Read TMR2_CounterGet
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_CounterSet API.
 *        The TMR2_Write will be deprecated in the future release. Use TMR2_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR2_Write TMR2_CounterSet
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_CounterSet API.
 *        The Timer2_Write will be deprecated in the future release. Use Timer2_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_Write TMR2_CounterSet
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_PeriodSet API.
 *        The TMR2_PeriodCountSet will be deprecated in the future release. Use TMR2_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR2_PeriodCountSet TMR2_PeriodSet
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_PeriodSet API.
 *        The Timer2_PeriodCountSet will be deprecated in the future release. Use Timer2_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_PeriodCountSet TMR2_PeriodSet
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_PeriodMatchCallbackRegister API.
 *        The TMR2_OverflowCallbackRegister will be deprecated in the future release. Use TMR2_PeriodMatchCallbackRegister instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR2_OverflowCallbackRegister TMR2_PeriodMatchCallbackRegister
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_PeriodMatchCallbackRegister API.
 *        The Timer2_OverflowCallbackRegister will be deprecated in the future release. Use Timer2_PeriodMatchCallbackRegister instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_OverflowCallbackRegister TMR2_PeriodMatchCallbackRegister

#endif // TMR2_DEPRECATED_H
/**
 End of File
*/
