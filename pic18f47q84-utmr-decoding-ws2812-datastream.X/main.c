/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC18F47Q84
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

#define LED_LENGTH          16
#define MAX_BRIGHTNESS      20      //255 max

// Position of GRB in WS2812
#define RED                 1
#define GREEN               0
#define BLUE                2

extern uint16_t captureData[256];
extern uint8_t decodedColor[MAX_COLORPOS][3];
extern uint16_t sequenceTiming[MAX_SEQID][2];
extern uint16_t seqID;

#define ACQ_TIME            2000    // ms
bool acquisitionInProgress = false;
bool buttonPressed = false;

void printDatastream() {
    // Prints captured datastream
    
    uint16_t _seqID = 0;            // row indicator for sequenceTiming[][]
    uint16_t colorPos = 0;          // row indicator for decodedColor[][]
    
    // Print number of sequences in the capture
    printf("Total sequences = %d\r\n\n", seqID+1);
    
    // Print all sequences one by one
    for(_seqID = 0; _seqID <= seqID; _seqID++) {
        // Print sequence number
        printf("Sequence #%d\r\n", _seqID+1);
        
        // G-R-B header for each sequence
        printf("\tG\tR\tB\r\n");
        
        // Print all LEDs in this sequence
        for(uint16_t i = 0; i < sequenceTiming[_seqID][ID_NUMLED] && colorPos <= MAX_COLORPOS; i++, colorPos++) {
            printf("%d:\t%d\t%d\t%d\r\n", i+1, decodedColor[colorPos][GREEN], decodedColor[colorPos][RED], decodedColor[colorPos][BLUE]);
        }
        
        // Print reset time
        printf("\r\nReset Time = %d us ", sequenceTiming[_seqID][ID_RSTTIME] >> 1);
        if(sequenceTiming[_seqID][ID_RSTTIME] == 0xFFFF) {
            printf("or greater\r\n\n");
        }
        else {
            printf("\r\n\n");
        }
    }
    
}

void startAcquisition()
{
    // Start acquisition of WS2812 datastream for decoding
    
    // Reset sequence ID
    seqID = -1;
    
    // Start DMA
    DMASELECT = 0x01;
	DMAnCON0bits.SIRQEN = 1;
    DMAnCON0bits.EN = 1;
    
    // Turn on timers and CCP
    TU16ACON0bits.ON = 1;       // begins populating decodedColor array
    CCP1CONbits.EN = 1;         // begins populating sequenceTiming array
    PIR3bits.TMR1IF = 0;        // clear TMR1IF
    TMR1H = 0;                  // reset and start CCP base timer
    TMR1L = 0;
    TMR1CONbits.ON = 1;
    
    // Set status in software and hardware
    acquisitionInProgress = true;
    LED2_SetHigh();
}

void stopAcquisition()
{
    // Stop acquisition of WS2812 datastream for decoding
    
    // Turn off timers and CCP
    TU16ACON0bits.ON = 0;       // stops populating decodedColor array
    CCP1CONbits.EN = 0;         // stops populating sequenceTiming array
    TMR1CONbits.ON = 0;         // stops CCP base timer to save power

    // Stop DMA
    DMASELECT = 0x01;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
    DMAnCON0bits.EN = 0;        // resets DMA pointers and counters when re-enabled
    
    // Clear status in software and hardware
    acquisitionInProgress = false;
    LED2_SetLow();
}

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();
    
    // Stop any existing running timers, CCPs, or DMAs
    stopAcquisition();

    while (1)
    {
        if(buttonPressed) {
            if(!acquisitionInProgress) {
                startAcquisition();
                __delay_ms(ACQ_TIME);   // if memory becomes full, data will be discarded
                stopAcquisition();
                printDatastream();
            }
            buttonPressed = false;
        }
        
        __delay_ms(500);
        
    }
}
/**
 End of File
*/