/**
 * TU16A Generated Driver API Header File
 *
 * @file tu16a.h
 *  
 * @defgroup tu16a TU16A
 *
 * @brief This file contains API prototypes and other data types for the TU16A module.
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

#ifndef TU16A_H
#define TU16A_H

/**
  Section: Included Files
*/

#include <stdint.h>
#include <stdbool.h>

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application.
 * It depends on the application whether a macro is used or not. 
 */

/**
 * @ingroup tu16a
 * @brief Defines the maximum count of the timer.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16A_MAX_COUNT (0xFFFFU)
/**
 * @ingroup tu16a
 * @brief Defines the timer prescaled clock frequency in hertz.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TU16A_CLOCK_FREQ (64000000UL)

/**
 * @ingroup tu16a
 * @brief Initializes the TU16A module.
 * @param None.
 * @return None.
 */
void TU16A_Initialize(void);

/**
 * @ingroup tu16a
 * @brief Deinitializes the TU16A module.
 * @param None.
 * @return None.
 */
void TU16A_Deinitialize(void);

/**
 * @ingroup tu16a
 * @brief Starts the TU16A.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TU16A_Start(void);

/**
 * @ingroup tu16a
 * @brief Stops the TU16A.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TU16A_Stop(void);

/**
 * @ingroup tu16a
 * @brief Returns the captured counter value from the Timer Capture register.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param None.
 * @return Captured counter value
 */
uint16_t TU16A_CaptureValueGet(void);

/**
 * @ingroup tu16a
 * @brief Executes the capture command and returns the captured count value from the Timer Capture register.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param None.
 * @return Captured counter value
 * @note When the UTMR Enable and Clock Synchronization (CSYNC) bits are set, it takes three timer clock cycles to synchronize the clocks.
 *      Clearing the UTMR Enable bit would require the selected clock source, especially the External Cock Sources (ERS), to supply at least three additional
 *      clock cycles to resolve the internal state. The user must be careful because if the timer is already running, any Stop/Reset-related ERS events that get
 *      processed will continue to affect the Run state of the timer.
 */
uint16_t TU16A_OnCommandCapture(void);

/**
 * @ingroup tu16a
 * @brief Returns the current counter value.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param None.
 * @return Counter value from the Timer Counter register
 * @note The Timer Counter register is not double-buffered, thus the timer must be
 *      stopped before writing to it. If the desired action is to clear the counter
 *      while the timer is running, consider using the CounterClear() API. If the
 *      desired action is to change the overall period of the timer (running or not),
 *      consider changing the Timer Period register (which is double-buffered) through the
 *      PeriodSet() API.
 */
uint16_t TU16A_CounterGet(void);

/**
 * @ingroup tu16a
 * @brief Sets the counter value.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param timerVal - Counter value to be written to the Timer Counter register
 * @return None.
 * @note The Timer Counter register is not double-buffered, thus the timer must be
 *      stopped before writing to it. If the desired action is to clear the counter
 *      while the timer is running, consider using the CounterClear() API. If the
 *      desired action is to change the overall period of the timer (running or not),
 *      consider changing the Timer Period register (which is double-buffered) through the
 *      PeriodSet() API.
 */
void TU16A_CounterSet(uint16_t timerVal);

/**
 * @ingroup tu16a
 * @brief Clears the Timer Counter and the internal prescaler counter to zero.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param None.
 * @return None.
 * @note When the UTMR Enable and Clock Synchronization (CSYNC) bits are set, it takes three timer clock cycles to synchronize the clocks.
 *      Clearing the UTMR Enable bit would require the selected clock source, especially the External Cock Sources (ERS), to supply at least three additional
 *      clock cycles to resolve the internal state. The user must be careful because if the timer is already running, any Stop/Reset-related ERS events that get
 *      processed will continue to affect the Run state of the timer.
 */
void TU16A_CounterClear(void);

/**
 * @ingroup tu16a
 * @brief Sets the period value to the Timer Period register.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param prVal - Period value to be written to the Timer Period register
 * @return None.
 * @note Writing to the Timer Period register is double-buffered,
 *      thus stopping the UTMR is not required. This must be followed
 *      by a Reset event for the new period value to become effective.
 */
void TU16A_PeriodSet(uint16_t periodVal);

/**
 * @ingroup tu16a
 * @brief Returns the current period value.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param None.
 * @return Current period count value
 */
uint16_t TU16A_PeriodGet(void);

/**
 * @ingroup tu16a
 * @brief Returns the maximum count value.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param None.
 * @return Maximum count value
 */
uint16_t TU16A_MaxCountGet(void);

/**
 * @ingroup tu16a
 * @brief Returns the Period Match Interrupt flag status.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param None.
 * @retval True - The counter has incremented from PR-1 to PR
 * @retval False - The counter has not incremented from PR-1 to PR since this bit was last cleared
 */
bool TU16A_PeriodMatchStatusGet(void);

/**
 * @ingroup tu16a
 * @brief Returns the Zero Interrupt flag status.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param None.
 * @retval True - The counter has reset or rolled over to zero
 * @retval False - The counter has not reset or rolled over since this bit was last cleared
 */
bool TU16A_ResetStatusGet(void);

/**
 * @ingroup tu16a
 * @brief Returns the Capture Interrupt flag status.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param None.
 * @retval True - A capture event has occurred
 * @retval False - A capture event has not occurred since this bit was last cleared
 */
bool TU16A_CaptureStatusGet(void);

/**
 * @ingroup tu16a
 * @brief Returns the UTMR Running flag status.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param None.
 * @retval True - UTMR is running and not being held in Reset by the External Reset Source (ERS)
 * @retval False - UTMR is not running or is held in Reset by the ERS
 */
bool TU16A_RunningStatusGet(void);

/**
 * @ingroup tu16a
 * @brief Clears the UTMR module interrupt flags.
 * @pre Initialize TU16A with TU16A_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TU16A_InterruptFlagsClear(void);

/**
 * @ingroup tu16a
 * @brief Performs tasks to be executed during the UTMR interrupt events.
 * @param None.
 * @return None.
 */
void TU16A_Tasks(void);

/**
 * @ingroup tu16a
 * @brief Registers a callback function for the TU16A Period Match interrupt event.
 * @param CallbackHandler - Address to the custom callback function
 * @return None.
 */
void TU16A_PeriodMatchCallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup tu16a
 * @brief Registers a callback function for the TU16A zero match or Reset interrupt event.
 * @param CallbackHandler - Address to the custom callback function
 * @return None.
 */
void TU16A_ZeroMatchCallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup tu16a
 * @brief Registers a callback function for the TU16A capture event.
 * @param CallbackHandler - Address to the custom callback function
 * @return None.
 */
void TU16A_CaptureEventCallbackRegister(void (* CallbackHandler)(void));

#endif //TU16A_H
