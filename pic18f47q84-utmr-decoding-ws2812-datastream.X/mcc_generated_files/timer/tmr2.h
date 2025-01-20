/**
 * TMR2 Generated Driver API Header File
 *
 * @file tmr2.h
 *  
 * @defgroup tmr2 TMR2
 *
 * @brief This file contains API prototypes and other data types for the TMR2 driver.
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

#ifndef TMR2_H
#define TMR2_H

#include <stdint.h>
#include <stdbool.h>
#include "tmr2_deprecated.h"

/**
 * @misradeviation{@advisory,2.5}
 * MCC Melody drivers provide macros that can be added to an application. 
 * It depends on the application whether a macro is used or not. 
 */
 
/**
 * @ingroup tmr2
 * @brief Defines the TMR2 maximum count value.
 */
#define TMR2_MAX_COUNT (255U)
/**
 * @ingroup tmr2
 * @brief Defines the TMR2 prescaled clock frequency in hertz.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TMR2_CLOCK_FREQ (1000UL)
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_MAX_COUNT.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TIMER2_MAX_COUNT TMR2_MAX_COUNT
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_CLOCK_FREQ.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define TIMER2_CLOCK_FREQ TMR2_CLOCK_FREQ
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_Initialize API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_Initialize TMR2_Initialize
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_Deinitialize API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_Deinitialize TMR2_Deinitialize
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_Start API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_Start TMR2_Start
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_Stop API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_Stop TMR2_Stop
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_CounterGet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_CounterGet TMR2_CounterGet
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_CounterSet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_CounterSet TMR2_CounterSet
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_PeriodSet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_PeriodSet TMR2_PeriodSet
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_MaxCountGet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_MaxCountGet TMR2_MaxCountGet
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_ModeSet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_ModeSet TMR2_ModeSet
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_ExtResetSourceSet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_ExtResetSourceSet TMR2_ExtResetSourceSet
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_PeriodMatchCallbackRegister API.
 */
 /* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_PeriodMatchCallbackRegister TMR2_PeriodMatchCallbackRegister
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_PeriodMatchStatusGet API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_PeriodMatchStatusGet TMR2_PeriodMatchStatusGet
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_PeriodMatchStatusClear API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_PeriodMatchStatusClear TMR2_PeriodMatchStatusClear
/**
 * @ingroup tmr2
 * @brief Defines the Custom Name for the \ref TMR2_Tasks API.
 */
/* cppcheck-suppress misra-c2012-2.5 */
#define Timer2_Tasks TMR2_Tasks

/**
 * @ingroup tmr2
 * @enum TMR2_HLT_EXT_RESET_SOURCE
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
   TMR2_ROP_STARTS_TMRON,

   /* Roll-over Pulse mode indicates that the Timer starts
       when ON = 1 and TMRx_ers = 1. Stops when TMRx_ers = 0
     */
   TMR2_ROP_STARTS_TMRON_ERSHIGH,

   /* Roll-over Pulse mode indicates that the Timer starts
      when ON = 1 and TMRx_ers = 0. Stops when TMRx_ers = 1
     */
   TMR2_ROP_STARTS_TMRON_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon rising or falling edge of TMRx_ers
     */
   TMR2_ROP_RESETS_ERSBOTHEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
    upon rising edge of TMRx_ers
     */
   TMR2_ROP_RESETS_ERSRISINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon falling edge of TMRx_ers
     */
   TMR2_ROP_RESETS_ERSFALLINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 0
     */
   TMR2_ROP_RESETS_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 1
     */
   TMR2_ROP_RESETS_ERSHIGH,

    /*In all One-Shot mode the timer resets and the ON bit is
	cleared when the timer value matches the PRx period
	value. The ON bit must be set by software to start
	another timer cycle.
	*/

   /* One shot mode indicates that the Timer starts
    immediately upon ON = 1 (Software Control)
     */
   TMR2_OS_STARTS_TMRON,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers
     */
   TMR2_OS_STARTS_ERSRISINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers
     */
   TMR2_OS_STARTS_ERSFALLINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when either a rising or falling edge is detected on TMRx_ers
     */
   TMR2_OS_STARTS_ERSBOTHEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers rising edge and resets on all
	subsequent TMRx_ers rising edges
     */
   TMR2_OS_STARTS_ERSFIRSTRISINGEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers falling edge and restarts on all
	subsequent TMRx_ers falling edges
     */
   TMR2_OS_STARTS_ERSFIRSTFALLINGEDGE,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 0
     */
   TMR2_OS_STARTS_ERSRISINGEDGEDETECT,
     /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 1
     */
   TMR2_OS_STARTS_ERSFALLINGEDGEDETECT,
   
   /* One shot mode indicates that the Timer starts
    when a TMRx_ers = 1,ON =1 and resets upon TMRx_ers =0
    */
   TMR2_OS_STARTS_TMRON_ERSHIGH = 0x16,
           
   /* One shot mode indicates that the Timer starts
     when a TMRx_ers = 0,ON = 1 and resets upon TMRx_ers =1 
    */
   TMR2_OS_STARTS_TMRON_ERSLOW = 0x17,
        
   /*In all Mono-Stable mode the ON bit must be initially set,but
     not cleared upon the TMRx = PRx, and the timer will start upon
     an TMRx_ers start event following TMRx = PRx.*/
               
   /* Mono Stable mode indicates that the Timer starts
      when a rising edge is detected on the TMRx_ers and ON = 1
    */
   TMR2_MS_STARTS_TMRON_ERSRISINGEDGEDETECT = 0x11,
           
   /* Mono Stable mode indicates that the Timer starts
      when a falling edge is detected on the TMRx_ers and ON = 1
    */
   TMR2_MS_STARTS_TMRON_ERSFALLINGEDGEDETECT = 0x12,
           
   /* Mono Stable mode indicates that the Timer starts
      when  either a rising or falling edge is detected on TMRx_ers 
      and ON = 1
    */
   TMR2_MS_STARTS_TMRON_ERSBOTHEDGE = 0x13
           
} TMR2_HLT_MODE;

/**
 * @ingroup tmr2
 * @enum TMR2_HLT_EXT_RESET_SOURCE
 * @brief Defines the different Reset sources of the HLT.
 */
typedef enum
{
    /*
     * T2CKIPPS_PIN as the Timer external reset source
     */
    TMR2_T2CKIPPS_PIN =  0x0,   
    /*
     * TMR4_POSTSCALED as the Timer external reset source
     */
    TMR2_TMR4_POSTSCALED =  0x2,   
    /*
     * TMR6_POSTSCALED as the Timer external reset source
     */
    TMR2_TMR6_POSTSCALED =  0x3,   
    /*
     * CCP1OUT as the Timer external reset source
     */
    TMR2_CCP1OUT =  0x4,   
    /*
     * CCP2OUT as the Timer external reset source
     */
    TMR2_CCP2OUT =  0x5,   
    /*
     * CCP3OUT as the Timer external reset source
     */
    TMR2_CCP3OUT =  0x6,   
    /*
     * PWM1_OUT1 as the Timer external reset source
     */
    TMR2_PWM1_OUT1 =  0x7,   
    /*
     * PWM1_OUT2 as the Timer external reset source
     */
    TMR2_PWM1_OUT2 =  0x8,   
    /*
     * PWM2_OUT1 as the Timer external reset source
     */
    TMR2_PWM2_OUT1 =  0x9,   
    /*
     * PWM2_OUT2 as the Timer external reset source
     */
    TMR2_PWM2_OUT2 =  0xa,   
    /*
     * PWM3_OUT1 as the Timer external reset source
     */
    TMR2_PWM3_OUT1 =  0xb,   
    /*
     * PWM3_OUT2 as the Timer external reset source
     */
    TMR2_PWM3_OUT2 =  0xc,   
    /*
     * PWM4_OUT1 as the Timer external reset source
     */
    TMR2_PWM4_OUT1 =  0xd,   
    /*
     * PWM4_OUT2 as the Timer external reset source
     */
    TMR2_PWM4_OUT2 =  0xe,   
    /*
     * CMP1OUT as the Timer external reset source
     */
    TMR2_CMP1OUT =  0xf,   
    /*
     * CMP2OUT as the Timer external reset source
     */
    TMR2_CMP2OUT =  0x10,   
    /*
     * ZCDOUT as the Timer external reset source
     */
    TMR2_ZCDOUT =  0x11,   
    /*
     * CLC1_OUT as the Timer external reset source
     */
    TMR2_CLC1_OUT =  0x12,   
    /*
     * CLC2_OUT as the Timer external reset source
     */
    TMR2_CLC2_OUT =  0x13,   
    /*
     * CLC3_OUT as the Timer external reset source
     */
    TMR2_CLC3_OUT =  0x14,   
    /*
     * CLC4_OUT as the Timer external reset source
     */
    TMR2_CLC4_OUT =  0x15,   
    /*
     * CLC5_OUT as the Timer external reset source
     */
    TMR2_CLC5_OUT =  0x16,   
    /*
     * CLC6_OUT as the Timer external reset source
     */
    TMR2_CLC6_OUT =  0x17,   
    /*
     * CLC7_OUT as the Timer external reset source
     */
    TMR2_CLC7_OUT =  0x18,   
    /*
     * CLC8_OUT as the Timer external reset source
     */
    TMR2_CLC8_OUT =  0x19,   
    /*
     * UART1_RX_EDGE as the Timer external reset source
     */
    TMR2_UART1_RX_EDGE =  0x1a,   
    /*
     * UART1_TX_EDGE as the Timer external reset source
     */
    TMR2_UART1_TX_EDGE =  0x1b,   
    /*
     * UART2_RX_EDGE as the Timer external reset source
     */
    TMR2_UART2_RX_EDGE =  0x1c,   
    /*
     * UART2_TX_EDGE as the Timer external reset source
     */
    TMR2_UART2_TX_EDGE =  0x1d,   
    /*
     * UART3_RX_EDGE as the Timer external reset source
     */
    TMR2_UART3_RX_EDGE =  0x1e,   
    /*
     * UART3_TX_EDGE as the Timer external reset source
     */
    TMR2_UART3_TX_EDGE =  0x1f,   
    /*
     * UART4_RX_EDGE as the Timer external reset source
     */
    TMR2_UART4_RX_EDGE =  0x20,   
    /*
     * UART4_TX_EDGE as the Timer external reset source
     */
    TMR2_UART4_TX_EDGE =  0x21,   
    /*
     * UART5_RX_EDGE as the Timer external reset source
     */
    TMR2_UART5_RX_EDGE =  0x22,   
    /*
     * UART5_TX_EDGE as the Timer external reset source
     */
    TMR2_UART5_TX_EDGE =  0x23   
} TMR2_HLT_EXT_RESET_SOURCE;

/**
  Section: TMR2 APIs
*/

/**
 * @ingroup tmr2
 * @brief Initializes the Timer2 (TMR2) module.
 *        This routine must be called before any other TMR2 routines.
 * @param None.
 * @return None.
 */
void TMR2_Initialize(void);

/**
 * @ingroup tmr2
 * @brief Deinitializes the TMR2 to Power-on Reset (POR) values.
 * @param None.
 * @return None.
 */
void TMR2_Deinitialize(void);

/**
 * @ingroup tmr2
 * @brief Starts the TMR2 timer.
 * @pre Initialize TMR2 with TMR2_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR2_Start(void);

/**
 * @ingroup tmr2
 * @brief Stops the TMR2 timer.
 * @pre Initialize TMR2 with TMR2_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR2_Stop(void);

/**
 * @ingroup tmr2
 * @brief Returns the current counter value.
 * @pre Initialize TMR2 with TMR2_Initialize() before calling this API.
 * @param None.
 * @return Current counter value
 */
uint8_t TMR2_CounterGet(void);

/**
 * @ingroup tmr2
 * @brief Sets the counter value for the TMR2 timer.
 * @pre Initialize TMR2 with TMR2_Initialize() before calling this API.
 * @param count - Counter value to be written to the T2TMR register
 * @return None.
 */
void TMR2_CounterSet(uint8_t count);

/**
 * @ingroup tmr2
 * @brief Sets the period count value.
 * @pre Initialize TMR2 with TMR2_Initialize() before calling this API.
 * @param periodVal - Period count value to be written to the T2PR register
 * @return None.
 */
void TMR2_PeriodSet(uint8_t periodVal);

/**
 * @ingroup tmr2
 * @brief Returns the current period count value.
 * @pre Initialize TMR2 with TMR2_Initialize() before calling this API.
 * @param None.
 * @return Period count value from the T2PR register
 */
uint8_t TMR2_PeriodGet(void);

/**
 * @ingroup tmr2
 * @brief Returns the TMR2 maximum count value.
 * @param None.
 * @return Maximum count value of the timer
 */
uint8_t TMR2_MaxCountGet(void);

/**
 * @ingroup tmr2
 * @brief Sets the HLT mode.
 * @pre Initialize TMR2 with TMR2_Initialize() after calling this API.
 * @param mode - Value to be written to the T2HLTbits.MODE bits
 * @return None.
 */
void TMR2_ModeSet(TMR2_HLT_MODE mode);

/**
 * @ingroup tmr2
 * @brief Sets the HLT External Reset source.
 * @pre Initialize TMR2 with TMR2_Initialize() before calling this API.
 * @param reset - Value to be written to the T2RSTbits.RSEL bits
 * @return None.
 */
void TMR2_ExtResetSourceSet(TMR2_HLT_EXT_RESET_SOURCE reset);

/**
 * @ingroup tmr2
 * @brief Returns the status of the TMR2 Period Match Interrupt flag.
 * @param None.
 * @return Interrupt flag status
 */
bool TMR2_PeriodMatchStatusGet(void);

/**
 * @ingroup tmr2
 * @brief Clears the TMR2 Period Match Interrupt flag.
 * @param None.
 * @return None.
 */
void TMR2_PeriodMatchStatusClear(void);

/**
 * @ingroup tmr2
 * @brief Performs tasks to be executed during the TMR2 period match event.
 * @param None.
 * @return None.
 */
void TMR2_Tasks(void);
/**
 * @ingroup tmr2
 * @brief Registers a callback function for the TMR2 period match event.
 * @param CallbackHandler - Address of the custom callback function
 * @return None.
 */
void TMR2_PeriodMatchCallbackRegister(void (* callbackHandler)(void));

#endif // TMR2_H
/**
 End of File
*/
