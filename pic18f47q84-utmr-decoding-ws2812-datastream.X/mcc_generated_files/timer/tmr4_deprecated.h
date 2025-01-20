/**
 * TMR4 Generated Driver API Header File
 *
 * @file tmr4.h
 *  
 * @defgroup tmr4 TMR4
 *
 * @brief This file contains deprecated macros or functions for the TMR4 driver.
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

#ifndef TMR4_DEPRECATED_H
#define TMR4_DEPRECATED_H

#warning "The tmr4_deprecated.h file contains the deprecated macros or functions. Replace the deprecated macro or functions with the recommended alternative."

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application. 
 * It depends on the application whether a macro is used or not. 
 */

/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_CounterGet API.
 *        The TMR4_Read will be deprecated in the future release. Use TMR4_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR4_Read TMR4_CounterGet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_CounterGet API.
 *        The Timer4_Read will be deprecated in the future release. Use Timer4_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_Read TMR4_CounterGet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_CounterSet API.
 *        The TMR4_Write will be deprecated in the future release. Use TMR4_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR4_Write TMR4_CounterSet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_CounterSet API.
 *        The Timer4_Write will be deprecated in the future release. Use Timer4_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_Write TMR4_CounterSet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_PeriodSet API.
 *        The TMR4_PeriodCountSet will be deprecated in the future release. Use TMR4_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR4_PeriodCountSet TMR4_PeriodSet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_PeriodSet API.
 *        The Timer4_PeriodCountSet will be deprecated in the future release. Use Timer4_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_PeriodCountSet TMR4_PeriodSet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_PeriodMatchCallbackRegister API.
 *        The TMR4_OverflowCallbackRegister will be deprecated in the future release. Use TMR4_PeriodMatchCallbackRegister instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR4_OverflowCallbackRegister TMR4_PeriodMatchCallbackRegister
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_PeriodMatchCallbackRegister API.
 *        The Timer4_OverflowCallbackRegister will be deprecated in the future release. Use Timer4_PeriodMatchCallbackRegister instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_OverflowCallbackRegister TMR4_PeriodMatchCallbackRegister

#endif // TMR4_DEPRECATED_H
/**
 End of File
*/
