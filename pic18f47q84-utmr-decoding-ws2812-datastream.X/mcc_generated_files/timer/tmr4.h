/**
 * TMR4 Generated Driver API Header File
 *
 * @file tmr4.h
 *  
 * @defgroup tmr4 TMR4
 *
 * @brief This file contains API prototypes and other data types for the TMR4 driver.
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

#ifndef TMR4_H
#define TMR4_H

#include <stdint.h>
#include <stdbool.h>
#include "tmr4_deprecated.h"

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application. 
 * It depends on the application whether a macro is used or not. 
 */
 
/**
 * @ingroup tmr4
 * @brief Defines the TMR4 maximum count value.
 */
#define TMR4_MAX_COUNT (255U)
/**
 * @ingroup tmr4
 * @brief Defines the TMR4 prescaled clock frequency in hertz.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR4_CLOCK_FREQ (1000UL)
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_MAX_COUNT.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TIMER4_MAX_COUNT TMR4_MAX_COUNT
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_CLOCK_FREQ.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TIMER4_CLOCK_FREQ TMR4_CLOCK_FREQ
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_Initialize API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_Initialize TMR4_Initialize
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_Deinitialize API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_Deinitialize TMR4_Deinitialize
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_Start API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_Start TMR4_Start
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_Stop API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_Stop TMR4_Stop
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_CounterGet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_CounterGet TMR4_CounterGet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_CounterSet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_CounterSet TMR4_CounterSet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_PeriodSet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_PeriodSet TMR4_PeriodSet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_MaxCountGet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_MaxCountGet TMR4_MaxCountGet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_ModeSet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_ModeSet TMR4_ModeSet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_ExtResetSourceSet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_ExtResetSourceSet TMR4_ExtResetSourceSet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_PeriodMatchCallbackRegister API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_PeriodMatchCallbackRegister TMR4_PeriodMatchCallbackRegister
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_PeriodMatchStatusGet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_PeriodMatchStatusGet TMR4_PeriodMatchStatusGet
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_PeriodMatchStatusClear API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_PeriodMatchStatusClear TMR4_PeriodMatchStatusClear
/**
 * @ingroup tmr4
 * @brief Defines the Custom Name for the \ref TMR4_Tasks API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer4_Tasks TMR4_Tasks

/**
 * @ingroup tmr4
 * @enum TMR4_HLT_EXT_RESET_SOURCE
 * @brief Defines the several modes of timer's operation of the timer with the Hardware Limit Timer (HLT) extension.
 */
typedef enum
{
	/* Roll-over Pulse mode clears the TMRx upon TMRx = PRx, then continue running.
	ON bit must be set and is not affected by Resets
	*/

   /* Roll-over Pulse mode indicates that Timer starts
   immediately upon ON = 1 (Software Control)
   */
   TMR4_ROP_STARTS_TMRON,

   /* Roll-over Pulse mode indicates that the Timer starts
       when ON = 1 and TMRx_ers = 1. Stops when TMRx_ers = 0
     */
   TMR4_ROP_STARTS_TMRON_ERSHIGH,

   /* Roll-over Pulse mode indicates that the Timer starts
      when ON = 1 and TMRx_ers = 0. Stops when TMRx_ers = 1
     */
   TMR4_ROP_STARTS_TMRON_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon rising or falling edge of TMRx_ers
     */
   TMR4_ROP_RESETS_ERSBOTHEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
    upon rising edge of TMRx_ers
     */
   TMR4_ROP_RESETS_ERSRISINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon falling edge of TMRx_ers
     */
   TMR4_ROP_RESETS_ERSFALLINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 0
     */
   TMR4_ROP_RESETS_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 1
     */
   TMR4_ROP_RESETS_ERSHIGH,

    /*In all One-Shot mode the timer resets and the ON bit is
	cleared when the timer value matches the PRx period
	value. The ON bit must be set by software to start
	another timer cycle.
	*/

   /* One shot mode indicates that the Timer starts
    immediately upon ON = 1 (Software Control)
     */
   TMR4_OS_STARTS_TMRON,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers
     */
   TMR4_OS_STARTS_ERSRISINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers
     */
   TMR4_OS_STARTS_ERSFALLINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when either a rising or falling edge is detected on TMRx_ers
     */
   TMR4_OS_STARTS_ERSBOTHEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers rising edge and resets on all
	subsequent TMRx_ers rising edges
     */
   TMR4_OS_STARTS_ERSFIRSTRISINGEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers falling edge and restarts on all
	subsequent TMRx_ers falling edges
     */
   TMR4_OS_STARTS_ERSFIRSTFALLINGEDGE,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 0
     */
   TMR4_OS_STARTS_ERSRISINGEDGEDETECT,
     /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 1
     */
   TMR4_OS_STARTS_ERSFALLINGEDGEDETECT,
   
   /* One shot mode indicates that the Timer starts
    when a TMRx_ers = 1,ON =1 and resets upon TMRx_ers =0
    */
   TMR4_OS_STARTS_TMRON_ERSHIGH = 0x16,
           
   /* One shot mode indicates that the Timer starts
     when a TMRx_ers = 0,ON = 1 and resets upon TMRx_ers =1 
    */
   TMR4_OS_STARTS_TMRON_ERSLOW = 0x17,
        
   /*In all Mono-Stable mode the ON bit must be initially set,but
     not cleared upon the TMRx = PRx, and the timer will start upon
     an TMRx_ers start event following TMRx = PRx.*/
               
   /* Mono Stable mode indicates that the Timer starts
      when a rising edge is detected on the TMRx_ers and ON = 1
    */
   TMR4_MS_STARTS_TMRON_ERSRISINGEDGEDETECT = 0x11,
           
   /* Mono Stable mode indicates that the Timer starts
      when a falling edge is detected on the TMRx_ers and ON = 1
    */
   TMR4_MS_STARTS_TMRON_ERSFALLINGEDGEDETECT = 0x12,
           
   /* Mono Stable mode indicates that the Timer starts
      when  either a rising or falling edge is detected on TMRx_ers 
      and ON = 1
    */
   TMR4_MS_STARTS_TMRON_ERSBOTHEDGE = 0x13
           
} TMR4_HLT_MODE;

/**
 * @ingroup tmr4
 * @enum TMR4_HLT_EXT_RESET_SOURCE
 * @brief Defines the different Reset sources of the HLT.
 */
typedef enum
{
    /*
     * T4CKIPPS_PIN as the Timer external reset source
     */
    TMR4_T4CKIPPS_PIN =  0x0,   
    /*
     * TMR2_POSTSCALED as the Timer external reset source
     */
    TMR4_TMR2_POSTSCALED =  0x1,   
    /*
     * TMR6_POSTSCALED as the Timer external reset source
     */
    TMR4_TMR6_POSTSCALED =  0x3,   
    /*
     * CCP1OUT as the Timer external reset source
     */
    TMR4_CCP1OUT =  0x4,   
    /*
     * CCP2OUT as the Timer external reset source
     */
    TMR4_CCP2OUT =  0x5,   
    /*
     * CCP3OUT as the Timer external reset source
     */
    TMR4_CCP3OUT =  0x6,   
    /*
     * PWM1_OUT1 as the Timer external reset source
     */
    TMR4_PWM1_OUT1 =  0x7,   
    /*
     * PWM1_OUT2 as the Timer external reset source
     */
    TMR4_PWM1_OUT2 =  0x8,   
    /*
     * PWM2_OUT1 as the Timer external reset source
     */
    TMR4_PWM2_OUT1 =  0x9,   
    /*
     * PWM2_OUT2 as the Timer external reset source
     */
    TMR4_PWM2_OUT2 =  0xa,   
    /*
     * PWM3_OUT1 as the Timer external reset source
     */
    TMR4_PWM3_OUT1 =  0xb,   
    /*
     * PWM3_OUT2 as the Timer external reset source
     */
    TMR4_PWM3_OUT2 =  0xc,   
    /*
     * PWM4_OUT1 as the Timer external reset source
     */
    TMR4_PWM4_OUT1 =  0xd,   
    /*
     * PWM4_OUT2 as the Timer external reset source
     */
    TMR4_PWM4_OUT2 =  0xe,   
    /*
     * CMP1OUT as the Timer external reset source
     */
    TMR4_CMP1OUT =  0xf,   
    /*
     * CMP2OUT as the Timer external reset source
     */
    TMR4_CMP2OUT =  0x10,   
    /*
     * ZCDOUT as the Timer external reset source
     */
    TMR4_ZCDOUT =  0x11,   
    /*
     * CLC1_OUT as the Timer external reset source
     */
    TMR4_CLC1_OUT =  0x12,   
    /*
     * CLC2_OUT as the Timer external reset source
     */
    TMR4_CLC2_OUT =  0x13,   
    /*
     * CLC3_OUT as the Timer external reset source
     */
    TMR4_CLC3_OUT =  0x14,   
    /*
     * CLC4_OUT as the Timer external reset source
     */
    TMR4_CLC4_OUT =  0x15,   
    /*
     * CLC5_OUT as the Timer external reset source
     */
    TMR4_CLC5_OUT =  0x16,   
    /*
     * CLC6_OUT as the Timer external reset source
     */
    TMR4_CLC6_OUT =  0x17,   
    /*
     * CLC7_OUT as the Timer external reset source
     */
    TMR4_CLC7_OUT =  0x18,   
    /*
     * CLC8_OUT as the Timer external reset source
     */
    TMR4_CLC8_OUT =  0x19,   
    /*
     * UART1_RX_EDGE as the Timer external reset source
     */
    TMR4_UART1_RX_EDGE =  0x1a,   
    /*
     * UART1_TX_EDGE as the Timer external reset source
     */
    TMR4_UART1_TX_EDGE =  0x1b,   
    /*
     * UART2_RX_EDGE as the Timer external reset source
     */
    TMR4_UART2_RX_EDGE =  0x1c,   
    /*
     * UART2_TX_EDGE as the Timer external reset source
     */
    TMR4_UART2_TX_EDGE =  0x1d,   
    /*
     * UART3_RX_EDGE as the Timer external reset source
     */
    TMR4_UART3_RX_EDGE =  0x1e,   
    /*
     * UART3_TX_EDGE as the Timer external reset source
     */
    TMR4_UART3_TX_EDGE =  0x1f,   
    /*
     * UART4_RX_EDGE as the Timer external reset source
     */
    TMR4_UART4_RX_EDGE =  0x20,   
    /*
     * UART4_TX_EDGE as the Timer external reset source
     */
    TMR4_UART4_TX_EDGE =  0x21,   
    /*
     * UART5_RX_EDGE as the Timer external reset source
     */
    TMR4_UART5_RX_EDGE =  0x22,   
    /*
     * UART5_TX_EDGE as the Timer external reset source
     */
    TMR4_UART5_TX_EDGE =  0x23   
} TMR4_HLT_EXT_RESET_SOURCE;

/**
  Section: TMR4 APIs
*/

/**
 * @ingroup tmr4
 * @brief Initializes the Timer4 (TMR4) module.
 *        This routine must be called before any other TMR4 routines.
 * @param None.
 * @return None.
 */
void TMR4_Initialize(void);

/**
 * @ingroup tmr4
 * @brief Deinitializes the TMR4 to Power-on Reset (POR) values.
 * @param None.
 * @return None.
 */
void TMR4_Deinitialize(void);

/**
 * @ingroup tmr4
 * @brief Starts the TMR4 timer.
 * @pre Initialize TMR4 with TMR4_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR4_Start(void);

/**
 * @ingroup tmr4
 * @brief Stops the TMR4 timer.
 * @pre Initialize TMR4 with TMR4_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR4_Stop(void);

/**
 * @ingroup tmr4
 * @brief Returns the current counter value.
 * @pre Initialize TMR4 with TMR4_Initialize() before calling this API.
 * @param None.
 * @return Current counter value
 */
uint8_t TMR4_CounterGet(void);

/**
 * @ingroup tmr4
 * @brief Sets the counter value for the TMR4 timer.
 * @pre Initialize TMR4 with TMR4_Initialize() before calling this API.
 * @param count - Counter value to be written to the T4TMR register
 * @return None.
 */
void TMR4_CounterSet(uint8_t count);

/**
 * @ingroup tmr4
 * @brief Sets the period count value.
 * @pre Initialize TMR4 with TMR4_Initialize() before calling this API.
 * @param periodVal - Period count value to be written to the T4PR register
 * @return None.
 */
void TMR4_PeriodSet(uint8_t periodVal);

/**
 * @ingroup tmr4
 * @brief Returns the current period count value.
 * @pre Initialize TMR4 with TMR4_Initialize() before calling this API.
 * @param None.
 * @return Period count value from the T4PR register
 */
uint8_t TMR4_PeriodGet(void);

/**
 * @ingroup tmr4
 * @brief Returns the TMR4 maximum count value.
 * @param None.
 * @return Maximum count value of the timer
 */
uint8_t TMR4_MaxCountGet(void);

/**
 * @ingroup tmr4
 * @brief Sets the HLT mode.
 * @pre Initialize TMR4 with TMR4_Initialize() after calling this API.
 * @param mode - Value to be written to the T4HLTbits.MODE bits
 * @return None.
 */
void TMR4_ModeSet(TMR4_HLT_MODE mode);

/**
 * @ingroup tmr4
 * @brief Sets the HLT External Reset source.
 * @pre Initialize TMR4 with TMR4_Initialize() before calling this API.
 * @param reset - Value to be written to the T4RSTbits.RSEL bits
 * @return None.
 */
void TMR4_ExtResetSourceSet(TMR4_HLT_EXT_RESET_SOURCE reset);

/**
 * @ingroup tmr4
 * @brief Returns the status of the TMR4 Period Match Interrupt flag.
 * @param None.
 * @return Interrupt flag status
 */
bool TMR4_PeriodMatchStatusGet(void);

/**
 * @ingroup tmr4
 * @brief Clears the TMR4 Period Match Interrupt flag.
 * @param None.
 * @return None.
 */
void TMR4_PeriodMatchStatusClear(void);

/**
 * @ingroup tmr4
 * @brief Performs tasks to be executed during the TMR4 period match event.
 * @param None.
 * @return None.
 */
void TMR4_Tasks(void);
/**
 * @ingroup tmr4
 * @brief Registers a callback function for the TMR4 period match event.
 * @param CallbackHandler - Address of the custom callback function
 * @return None.
 */
void TMR4_PeriodMatchCallbackRegister(void (* callbackHandler)(void));

#endif // TMR4_H
/**
 End of File
*/
