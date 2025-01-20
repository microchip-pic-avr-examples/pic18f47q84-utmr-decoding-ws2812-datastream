/**
 * TU16A Generated Driver API Header File
 * 
 * @file tu16a.h
 * 
 * @ingroup tu16a""
 * 
 * @brief This file contains the deprecated macros or APIs for the TU16A driver.
 *
 * @version TU16A Driver Version 3.0.0
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

#ifndef TU16A_DEPRECATED_H
#define TU16A_DEPRECATED_H

#warning "The tu16a_deprecated.h file contains the deprecated macros or functions. Replace the deprecated macro or functions with the recommended alternative."

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application.
 * It depends on the application whether a macro is used or not. 
 */
 
/**
 * @ingroup tu16a
 * @brief Defines the Custom Name for the \ref TU16A_CounterSet API. 
 *        The TU16A_Write will be deprecated in the future release. Use TU16A_CounterSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */  
#define TU16A_Write TU16A_CounterSet
/**
 * @ingroup tu16a
 * @brief Defines the Custom Name for the \ref TU16A_CounterGet API. 
 *        The TU16A_Read will be deprecated in the future release. Use TU16A_CounterGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */  
#define TU16A_Read TU16A_CounterGet
/**
 * @ingroup tu16a
 * @brief Defines the Custom Name for the \ref TU16A_CaptureValueGet API. 
 *        The TU16A_CaptureValueRead will be deprecated in the future release. Use TU16A_CaptureValueGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */  
#define TU16A_CaptureValueRead  TU16A_CaptureValueGet
/**
 * @ingroup tu16a
 * @brief Defines the Custom Name for the \ref TU16A_PeriodSet API. 
 *        The TU16A_PeriodValueSet will be deprecated in the future release. Use TU16A_PeriodSet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16A_PeriodValueSet TU16A_PeriodSet
/**
 * @ingroup tu16a
 * @brief Defines the Custom Name for the \ref TU16A_RunningStatusGet API. 
 *        The TU16A_IsTimerRunning will be deprecated in the future release. Use TU16A_RunningStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16A_IsTimerRunning TU16A_RunningStatusGet
/**
 * @ingroup tu16a
 * @brief Defines the Custom Name for the \ref TU16A_PeriodMatchStatusGet API. 
 *        The TU16A_HasPRMatchOccured will be deprecated in the future release. Use TU16A_PeriodMatchStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16A_HasPRMatchOccured  TU16A_PeriodMatchStatusGet
/**
 * @ingroup tu16a
 * @brief Defines the Custom Name for the \ref TU16A_PeriodMatchStatusGet API. 
 *        The TU16A_HasResetOccured will be deprecated in the future release. Use TU16A_ResetStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16A_HasResetOccured TU16A_ResetStatusGet
/**
 * @ingroup tu16a
 * @brief Defines the Custom Name for the \ref TU16A_CaptureStatusGet API. 
 *        The TU16A_HasCaptureOccured will be deprecated in the future release. Use TU16A_CaptureStatusGet instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16A_HasCaptureOccured TU16A_CaptureStatusGet
/**
 * @ingroup tu16a
 * @brief Defines the Custom Name for the \ref TU16A_PeriodMatchCallbackRegister API. 
 *        The TU16A_PRMatchInterruptHandlerSet will be deprecated in the future release. Use TU16A_PeriodMatchCallbackRegister instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16A_PRMatchInterruptHandlerSet TU16A_PeriodMatchCallbackRegister
/**
 * @ingroup tu16a
 * @brief Defines the Custom Name for the \ref TU16A_ZeroMatchCallbackRegister API. 
 *        The TU16A_ZeroMatchInterruptHandlerSet will be deprecated in the future release. Use TU16A_ZeroMatchCallbackRegister instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16A_ZeroMatchInterruptHandlerSet TU16A_ZeroMatchCallbackRegister
/**
 * @ingroup tu16a
 * @brief Defines the Custom Name for the \ref TU16A_CaptureEventCallbackRegister API. 
 *        The TU16A_CaptureMatchInterruptHandlerSet will be deprecated in the future release. Use TU16A_CaptureEventCallbackRegister instead.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16A_CaptureMatchInterruptHandlerSet TU16A_CaptureEventCallbackRegister
#endif //TU16A_DEPRECATED_H