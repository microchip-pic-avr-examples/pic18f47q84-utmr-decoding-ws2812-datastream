/**
 * TU16B Generated Driver API Header File
 * 
 * @file tu16b.h
 * 
 * @ingroup tu16b""
 * 
 * @brief This file contains the deprecated macros or APIs for the TU16B driver.
 *
 * @version TU16B Driver Version 3.0.0
 *
 * @version Package Version 2.0.0
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

#ifndef TU16B_DEPRECATED_H
#define TU16B_DEPRECATED_H

#warning "The tu16b_deprecated.h file contains the deprecated macros or functions. Replace the deprecated macro or functions with the recommended alternative."

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application.
 * It depends on the application whether a macro is used or not. 
 */
 
/**
 * @ingroup tu16b
 * @brief Defines the Custom Name for the \ref TU16B_CounterSet API. 
 *        The TU16B_Write will be deprecated in the future release. Use TU16B_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */  
#define TU16B_Write TU16B_CounterSet
/**
 * @ingroup tu16b
 * @brief Defines the Custom Name for the \ref TU16B_CounterGet API. 
 *        The TU16B_Read will be deprecated in the future release. Use TU16B_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */  
#define TU16B_Read TU16B_CounterGet
/**
 * @ingroup tu16b
 * @brief Defines the Custom Name for the \ref TU16B_CaptureValueGet API. 
 *        The TU16B_CaptureValueRead will be deprecated in the future release. Use TU16B_CaptureValueGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */  
#define TU16B_CaptureValueRead  TU16B_CaptureValueGet
/**
 * @ingroup tu16b
 * @brief Defines the Custom Name for the \ref TU16B_PeriodSet API. 
 *        The TU16B_PeriodValueSet will be deprecated in the future release. Use TU16B_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16B_PeriodValueSet TU16B_PeriodSet
/**
 * @ingroup tu16b
 * @brief Defines the Custom Name for the \ref TU16B_RunningStatusGet API. 
 *        The TU16B_IsTimerRunning will be deprecated in the future release. Use TU16B_RunningStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16B_IsTimerRunning TU16B_RunningStatusGet
/**
 * @ingroup tu16b
 * @brief Defines the Custom Name for the \ref TU16B_PeriodMatchStatusGet API. 
 *        The TU16B_HasPRMatchOccured will be deprecated in the future release. Use TU16B_PeriodMatchStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16B_HasPRMatchOccured  TU16B_PeriodMatchStatusGet
/**
 * @ingroup tu16b
 * @brief Defines the Custom Name for the \ref TU16B_PeriodMatchStatusGet API. 
 *        The TU16B_HasResetOccured will be deprecated in the future release. Use TU16B_ResetStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16B_HasResetOccured TU16B_ResetStatusGet
/**
 * @ingroup tu16b
 * @brief Defines the Custom Name for the \ref TU16B_CaptureStatusGet API. 
 *        The TU16B_HasCaptureOccured will be deprecated in the future release. Use TU16B_CaptureStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16B_HasCaptureOccured TU16B_CaptureStatusGet
/**
 * @ingroup tu16b
 * @brief Defines the Custom Name for the \ref TU16B_PeriodMatchCallbackRegister API. 
 *        The TU16B_PRMatchInterruptHandlerSet will be deprecated in the future release. Use TU16B_PeriodMatchCallbackRegister instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16B_PRMatchInterruptHandlerSet TU16B_PeriodMatchCallbackRegister
/**
 * @ingroup tu16b
 * @brief Defines the Custom Name for the \ref TU16B_ZeroMatchCallbackRegister API. 
 *        The TU16B_ZeroMatchInterruptHandlerSet will be deprecated in the future release. Use TU16B_ZeroMatchCallbackRegister instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16B_ZeroMatchInterruptHandlerSet TU16B_ZeroMatchCallbackRegister
/**
 * @ingroup tu16b
 * @brief Defines the Custom Name for the \ref TU16B_CaptureEventCallbackRegister API. 
 *        The TU16B_CaptureMatchInterruptHandlerSet will be deprecated in the future release. Use TU16B_CaptureEventCallbackRegister instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16B_CaptureMatchInterruptHandlerSet TU16B_CaptureEventCallbackRegister
#endif //TU16B_DEPRECATED_H