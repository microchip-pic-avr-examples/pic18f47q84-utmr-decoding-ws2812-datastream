/**
  TU16A Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    tu16a.h

  @Summary
    This is the generated header file for the TU16A driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for TU16A.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC18F47Q84
        Driver Version    :  2.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above or later
        MPLAB             :  MPLAB X 5.40
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef TU16A_H
#define TU16A_H

/**
  Section: Included Files
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/**
  Section: TU16A APIs
*/

/**
  @Summary
    Initializes the TU16A.

  @Description
    This function initializes the TU16A Registers.
    This function must be called before any other TU16A function is called.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
   
   
  @Example
    <code>
    main()
    {
        // Initialize TU16A module
        TU16A_Initialize();

        // Do something else...
    }
    </code>
*/
void TU16A_Initialize(void);

/**
  @Summary
    This function starts the TU16A.

  @Description
    This function starts the TU16A operation.
    This function must be called after the initialization of TU16A.

  @Preconditions
    Initialize  the TU16A before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TU16A module

    // Start TU16A
    TU16A_StartTimer();

    // Do something else...
    </code>
*/
inline void TU16A_StartTimer(void);

/**
  @Summary
    This function stops the TU16A.

  @Description
    This function stops the TU16A operation.
    This function must be called after the start of TU16A.

  @Preconditions
    Initialize  the TU16A before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TU16A module

    // Start TU16A
    TU16A_StartTimer();

    // Do something else...

    // Stop TU16A;
    TU16A_StopTimer();
    </code>
*/
inline void TU16A_StopTimer(void);

/**
  @Summary
    Reads the 16-bit value of Capture register.

  @Description
    This function reads the 16-bit value of Capture register and return it.

  @Preconditions
    Initialize  the TU16A before calling this function.

  @Param
    None

  @Returns
    This function returns the 16-bit value of Capture Register.

  @Example
    <code>
    // Initialize TU16A module

    // Start TU16A
    TU16A_StartTimer();

    // Read the current value of TU16A
    uint16_t capvalue= TU16A_ReadCaptureValue())
    // Do something else...
    // Stop TU16A;
     TU16A_StopTimer();
    </code>
*/
uint16_t TU16A_ReadCaptureValue(void);

/**
  @Summary
    Reads the 16-bit value of Capture register.

  @Description
    This function captures the current timer value, stores it in the capture register,
    and returns the captured value.
    This function is blocking code.

  @Preconditions
    Initialize  the TU16A before calling this function.

  @Param
    None

  @Returns
    This function returns the 16-bit value of Capture Register.

  @Example
    <code>
    // Initialize TU16A module

    // Start TU16A
    TU16A_StartTimer();

    // Read the current value of TU16A
    uint16_t capvalue= TU16A_CaptureOnCommand())
    // Do something else...
    // Stop TU16A;
     TU16A_StopTimer();
    </code>
*/
uint16_t TU16A_CaptureOnCommand(void);

/**
  @Summary
    Reads the TU16A register.

  @Description
    This function reads the TU16A TMR register value and return it.

  @Preconditions
    Initialize  the TU16A before calling this function.

  @Param
    None

  @Returns
    This function returns the current value of TMR register.

  @Example
    <code>
    // Initialize TU16A module

    // Start TU16A
    TU16A_StartTimer();

    // Read the current value of TU16A
    if(0 == TU16A_ReadTimer())
    {
        // Do something else...

        // Reload the TMR value
        TU16A_SetPeriodValue(0xFFFF);
    }
    </code>
*/
uint16_t TU16A_ReadTimer(void);

/**
  @Summary
    Writes the TU16A register.

  @Description
    This function writes the TU16A register.
    This function must be called after the initialization of TU16A.

  @Preconditions
    Initialize  the TU16A before calling this function.

  @Param
    timerVal - Value to write into TU16A register.

  @Returns
    None

  @Example
    <code>
    #define PERIOD 0x80
    #define ZERO   0x00

    while(1)
    {
        // Read the TU16A register
        if(ZERO == TU16A_ReadTimer())
        {
            // Do something else...

            // Write the TU16A register
            TU16A_WriteTimer(PERIOD);
        }

        // Do something else...
    }
    </code>
*/
void TU16A_WriteTimer(uint16_t timerVal);

/**
  @Summary
    Clear the Counter to zero.

  @Description
    Clear the Counter to zero. it helps to reload new PR value.
    This function is blocking code.

  @Preconditions
    Initialize  the TU16A before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TU16A module

    // Start TU16A
    TU16A_StartTimer();

    // Read the current value of TU16A
    TU16A_SetPeriodValue(0xFFFF);
    TU16A_ClearCounter();
    // Do something else...
    // Stop TU16A;
     TU16A_StopTimer();
    </code>
*/
inline void TU16A_ClearCounter(void);

/**
  @Summary
    Load value to Period Register.

  @Description
    This function writes the value to Period registers.
    This function must be called after the initialization of TU16A.

  @Note
    It is important to note that the Period register is double-buffered.
    SetPeriodValue() loads and arms the buffer. For the new period to kick in,
    a second qualifying event is required (like an ERS reset or CLR command)

  @Preconditions
    Initialize  the TU16A before calling this function.

  @Param
    prVal - Value to load into TU16A register.

  @Returns
    None


  @Example
    <code>
    // Initialize TU16A module

    // Start TU16A
    TU16A_StartTimer();

    // Writes the new PR value to Period registers
    TU16A_SetPeriodValue(0xFFFF);
    // Do something else...
    // Stop TU16A;
     TU16A_StopTimer();
    </code>
*/
void TU16A_SetPeriodValue(uint16_t prVal);

/**
  @Summary
    Enables Period register match interrupt.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    None
*/
inline void TU16A_EnablePRMatchInterrupt(void);

/**
  @Summary
    Disables Period register match interrupt.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    None
*/
inline void TU16A_DisablePRMatchInterrupt(void);

/**
  @Summary
    Enables Zero condition match interrupt.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    None
*/
inline void TU16A_EnableZeroInterrupt(void);

/**
  @Summary
    Disables Zero condition match interrupt.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    None
*/
inline void TU16A_DisableZeroInterrupt(void);

/**
  @Summary
    Enables Capture interrupt.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    None
*/
inline void TU16A_EnableCaptureInterrupt(void);

/**
  @Summary
    Disables Capture interrupt.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    None
*/
inline void TU16A_DisableCaptureInterrupt(void);

/**
  @Summary
    This function get the PR Match interrupt flag status.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    bool
*/
inline bool TU16A_HasPRMatchOccured(void);

/**
  @Summary
    This function get the Zero condition Match interrupt flag status.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    bool
*/
inline bool TU16A_HasResetOccured(void);

/**
  @Summary
    This function get the Capture interrupt flag status.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    bool
*/
inline bool TU16A_HasCaptureOccured(void);

/**
  @Summary
    This function get the timer running flag status.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    bool
*/
inline bool TU16A_IsTimerRunning(void);

/**
  @Summary
    Enables TU main interrupt.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    None
*/
inline void TU16A_EnableInterrupt(void);

/**
  @Summary
    Disables TU main interrupt.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    None
*/
inline void TU16A_DisableInterrupt(void);

/**
  @Summary
    This function get the status of main TU interrupt flag.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    bool
*/
inline bool TU16A_IsInterruptEnabled(void);

/**
  @Summary
    This function clear the status bits of TU module interrupt flag.

  @Preconditions
    None
    
  @Param
    None

  @Returns
    bool
*/
inline void TU16A_ClearInterruptFlag(void);

#endif //TU16A_H