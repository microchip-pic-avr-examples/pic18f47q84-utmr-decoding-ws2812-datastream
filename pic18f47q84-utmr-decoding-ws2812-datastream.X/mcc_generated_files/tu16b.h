/**
  TU16B Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    tu16b.h

  @Summary
    This is the generated header file for the TU16B driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for TU16B.
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

#ifndef TU16B_H
#define TU16B_H

/**
  Section: Included Files
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/**
  Section: TU16B APIs
*/

/**
  @Summary
    Initializes the TU16B.

  @Description
    This function initializes the TU16B Registers.
    This function must be called before any other TU16B function is called.

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
        // Initialize TU16B module
        TU16B_Initialize();

        // Do something else...
    }
    </code>
*/
void TU16B_Initialize(void);

/**
  @Summary
    This function starts the TU16B.

  @Description
    This function starts the TU16B operation.
    This function must be called after the initialization of TU16B.

  @Preconditions
    Initialize  the TU16B before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TU16B module

    // Start TU16B
    TU16B_StartTimer();

    // Do something else...
    </code>
*/
inline void TU16B_StartTimer(void);

/**
  @Summary
    This function stops the TU16B.

  @Description
    This function stops the TU16B operation.
    This function must be called after the start of TU16B.

  @Preconditions
    Initialize  the TU16B before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TU16B module

    // Start TU16B
    TU16B_StartTimer();

    // Do something else...

    // Stop TU16B;
    TU16B_StopTimer();
    </code>
*/
inline void TU16B_StopTimer(void);

/**
  @Summary
    Reads the 16-bit value of Capture register.

  @Description
    This function reads the 16-bit value of Capture register and return it.

  @Preconditions
    Initialize  the TU16B before calling this function.

  @Param
    None

  @Returns
    This function returns the 16-bit value of Capture Register.

  @Example
    <code>
    // Initialize TU16B module

    // Start TU16B
    TU16B_StartTimer();

    // Read the current value of TU16B
    uint16_t capvalue= TU16B_ReadCaptureValue())
    // Do something else...
    // Stop TU16B;
     TU16B_StopTimer();
    </code>
*/
uint16_t TU16B_ReadCaptureValue(void);

/**
  @Summary
    Reads the 16-bit value of Capture register.

  @Description
    This function captures the current timer value, stores it in the capture register,
    and returns the captured value.
    This function is blocking code.

  @Preconditions
    Initialize  the TU16B before calling this function.

  @Param
    None

  @Returns
    This function returns the 16-bit value of Capture Register.

  @Example
    <code>
    // Initialize TU16B module

    // Start TU16B
    TU16B_StartTimer();

    // Read the current value of TU16B
    uint16_t capvalue= TU16B_CaptureOnCommand())
    // Do something else...
    // Stop TU16B;
     TU16B_StopTimer();
    </code>
*/
uint16_t TU16B_CaptureOnCommand(void);

/**
  @Summary
    Reads the TU16B register.

  @Description
    This function reads the TU16B TMR register value and return it.

  @Preconditions
    Initialize  the TU16B before calling this function.

  @Param
    None

  @Returns
    This function returns the current value of TMR register.

  @Example
    <code>
    // Initialize TU16B module

    // Start TU16B
    TU16B_StartTimer();

    // Read the current value of TU16B
    if(0 == TU16B_ReadTimer())
    {
        // Do something else...

        // Reload the TMR value
        TU16B_SetPeriodValue(0xFFFF);
    }
    </code>
*/
uint16_t TU16B_ReadTimer(void);

/**
  @Summary
    Writes the TU16B register.

  @Description
    This function writes the TU16B register.
    This function must be called after the initialization of TU16B.

  @Preconditions
    Initialize  the TU16B before calling this function.

  @Param
    timerVal - Value to write into TU16B register.

  @Returns
    None

  @Example
    <code>
    #define PERIOD 0x80
    #define ZERO   0x00

    while(1)
    {
        // Read the TU16B register
        if(ZERO == TU16B_ReadTimer())
        {
            // Do something else...

            // Write the TU16B register
            TU16B_WriteTimer(PERIOD);
        }

        // Do something else...
    }
    </code>
*/
void TU16B_WriteTimer(uint16_t timerVal);

/**
  @Summary
    Clear the Counter to zero.

  @Description
    Clear the Counter to zero. it helps to reload new PR value.
    This function is blocking code.

  @Preconditions
    Initialize  the TU16B before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize TU16B module

    // Start TU16B
    TU16B_StartTimer();

    // Read the current value of TU16B
    TU16B_SetPeriodValue(0xFFFF);
    TU16B_ClearCounter();
    // Do something else...
    // Stop TU16B;
     TU16B_StopTimer();
    </code>
*/
inline void TU16B_ClearCounter(void);

/**
  @Summary
    Load value to Period Register.

  @Description
    This function writes the value to Period registers.
    This function must be called after the initialization of TU16B.

  @Note
    It is important to note that the Period register is double-buffered.
    SetPeriodValue() loads and arms the buffer. For the new period to kick in,
    a second qualifying event is required (like an ERS reset or CLR command)

  @Preconditions
    Initialize  the TU16B before calling this function.

  @Param
    prVal - Value to load into TU16B register.

  @Returns
    None


  @Example
    <code>
    // Initialize TU16B module

    // Start TU16B
    TU16B_StartTimer();

    // Writes the new PR value to Period registers
    TU16B_SetPeriodValue(0xFFFF);
    // Do something else...
    // Stop TU16B;
     TU16B_StopTimer();
    </code>
*/
void TU16B_SetPeriodValue(uint16_t prVal);

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
inline void TU16B_EnablePRMatchInterrupt(void);

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
inline void TU16B_DisablePRMatchInterrupt(void);

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
inline void TU16B_EnableZeroInterrupt(void);

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
inline void TU16B_DisableZeroInterrupt(void);

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
inline void TU16B_EnableCaptureInterrupt(void);

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
inline void TU16B_DisableCaptureInterrupt(void);

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
inline bool TU16B_HasPRMatchOccured(void);

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
inline bool TU16B_HasResetOccured(void);

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
inline bool TU16B_HasCaptureOccured(void);

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
inline bool TU16B_IsTimerRunning(void);

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
inline void TU16B_EnableInterrupt(void);

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
inline void TU16B_DisableInterrupt(void);

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
inline bool TU16B_IsInterruptEnabled(void);

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
inline void TU16B_ClearInterruptFlag(void);

#endif //TU16B_H