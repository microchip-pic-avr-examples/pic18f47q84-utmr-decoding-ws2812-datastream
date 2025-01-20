 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
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
#include "mcc_generated_files/system/system.h"
#include "ws2812_seed.h"

#define ACQ_TIME            2000    // ms

#define DELAY_50us  100             // T1 Clock @0.5us
#define ID_NUMLED   0
#define ID_RSTTIME  1
#define MAX_SEQID   MAX_COLORPOS    // Do not exceed 0xFFFE because seqID is initialized to -1 (0xFFFF)

#define LED_LENGTH          16
#define MAX_BRIGHTNESS      20      //255 max

// Position of GRB in WS2812
#define RED                 1
#define GREEN               0
#define BLUE                2

#define MAX_COLORPOS    1365         // =DMAnSSZ/3

typedef struct WS2812_Packet 
{
    uint16_t resetTime;
    uint16_t numLeds;
} ws2812_packet;

typedef struct RGBVAL 
{
    
    uint8_t green;
    uint8_t red;
    uint8_t blue;
} rgbVal;

ws2812_packet sequenceTiming[MAX_SEQID] = { 0 };
uint16_t seqID = 0xffff;            // Initializes to maximum unsigned value

bool acquisitionInProgress = false;
bool buttonPressed = false;

void printDatastream(void);
void startAcquisition(void);
void stopAcquisition(void);
void capture_ISR(uint16_t ccp_val);
void ws2812_transmit(void);
void buttonPressed_ISR(void);
void SPI1_initialize(void);
void SPI2_initialize(void);

/*
                         Main application
 */
void main(void)
{
    SYSTEM_Initialize();
    
    SW2_SetInterruptHandler(buttonPressed_ISR);
    DMA3_SetSourceAddress( (uint24_t)(&ws2812_seed) );
    TMR0_PeriodMatchCallbackRegister(ws2812_transmit);
    CCP1_SetCallBack(capture_ISR);
    SPI1_initialize();
    SPI2_initialize();
        
    INTERRUPT_GlobalInterruptHighEnable();
   
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

void printDatastream(void) 
{
    // Prints captured datastream
    uint16_t _seqID = 0;    
    rgbVal * colorData = ( rgbVal *)(decodedColor);    
    
    // Print number of sequences in the capture
    printf("Total sequences = %d\r\n\n", seqID+1);
    
    // Print all sequences one by one
    for(_seqID = 0; _seqID <= seqID-1; _seqID++) {
        // Print sequence number
        printf("Sequence #%d\r\n", _seqID+1);
        
        // G-R-B header for each sequence
        printf("\tG\tR\tB\r\n");
        
        
        // Print all LEDs in this sequence
        uint16_t numLeds = sequenceTiming[_seqID].numLeds;
        for(uint8_t i = 0; i < numLeds; i++) {
            printf("%d:\t%d\t%d\t%d\r\n", i+1, colorData[i].green, colorData[i].red, colorData[i].blue);
        }
        colorData += numLeds;
        
        // Print reset time
        printf("\r\nReset Time = %d us ", sequenceTiming[_seqID].resetTime >> 1);
        if(sequenceTiming[_seqID].resetTime == 0xFFFF) {
            printf("or greater\r\n\n");
        }
        else {
            printf("\r\n\n");
        }
    }    
}


void startAcquisition(void)
{
    // Start acquisition of WS2812 datastream for decoding
    
    // Reset sequence ID
    seqID = 0xffff;
    
    // Start DMA
    DMA2_TransferWithTriggerStart();
    DMA2_Enable();
    
    // Turn on timers and CCP
    TU16A_Start();              // begins populating decodedColor array
    CCP1CONbits.EN = 1;         // begins populating sequenceTiming array
    TMR1_OverflowStatusClear(); // clear TMR1IF
    Timer1_Reload();
    Timer1_Start();
    Timer2_Start();
    Timer4_Start();
    
    // Set status in software and hardware
    acquisitionInProgress = true;
    LED2_SetHigh();
}

void stopAcquisition(void)
{
    // Stop acquisition of WS2812 datastream for decoding
    
    // Turn off timers and CCP
    TU16A_Stop();       // stops populating decodedColor array
    CCP1CONbits.EN = 0;         // stops populating sequenceTiming array
    Timer1_Stop();         // stops CCP base timer to save power
    Timer2_Stop();
    Timer2_Write(0);
    Timer4_Stop();
    Timer4_Write(0);

    // Stop DMA
    DMA2_TransferStop();
    DMA2_Disable();        // resets DMA pointers and counters when re-enabled
    
    // Clear status in software and hardware
    acquisitionInProgress = false;
    LED2_SetLow();
}

void capture_ISR(uint16_t ccp_val)
{
     uint16_t resetTime = 0;     
     Timer1_Reload();
    
    // If TMR1 has overflowed, set reset time to maximum
    // otherwise CCPR1 register captures actual reset time
    if( Timer1_HasOverflowOccured() ) {
        Timer1_OverflowStatusClear();
        resetTime = 0xFFFF;
    }
    else {
        resetTime = ccp_val;
    }
    
    if(resetTime >= DELAY_50us) {
        if(seqID < MAX_SEQID) {
            sequenceTiming[seqID].resetTime = resetTime;
            sequenceTiming[seqID].numLeds = Timer2_Read();
            Timer2_Write(0);
        }
        seqID++;                             // First seqID++ will make seqID=0
        sequenceTiming[seqID].numLeds = 0;   // Initialize to zero at runtime
        sequenceTiming[seqID].resetTime = 0;
    }
}


void ws2812_transmit(void)
{
    uint24_t ws2812_seed_addr = (uint24_t)&ws2812_seed;

    // start DMA transfer (transfer GRB data to SPI for WS2812)
    DMA3_TransferWithTriggerStart();
    DMAnSSA += DMAnSSZ;     // move source start addr ahead
    if(DMAnSSA >= (ws2812_seed_addr + WS2812_SEED_SIZE))    // rollover
        DMAnSSA = ws2812_seed_addr;
}

void buttonPressed_ISR(void)
{
    buttonPressed = true;
}

void SPI1_initialize(void)
{
    //SMP Middle; CKE Idle to active; CKP Idle:Low, Active:High; FST disabled; SSP active high; SDIP active high; SDOP active high; 
    SPI1CON1 = 0x00;
    //SSET disabled; TXR required for a transfer; RXR data is not stored in the FIFO; 
    SPI1CON2 = 0x02;
    //CLKSEL CLC1; 
    SPI1CLK = 0x0F;
    //BAUD 0; 
    SPI1BAUD = 0x00;
    TRISCbits.TRISC4 = 0;
    //EN enabled; LSBF MSb first; MST bus master; BMODE every byte; 
    SPI1CON0 = 0x83;
}

void SPI2_initialize(void)
{
    //SMP Middle; CKE Idle to active; CKP Idle:Low, Active:High; FST disabled; SSP active high; SDIP active high; SDOP active high; 
    SPI2CON1 = 0x00;
    //SSET enabled; TXR not required for a transfer; RXR suspended if the RxFIFO is full; 
    SPI2CON2 = 0x05;
    //CLKSEL CLC5; 
    SPI2CLK = 0x13;
    //BAUD 0; 
    SPI2BAUD = 0x00;
    TRISBbits.TRISB3 = 1;    
    //EN enabled; LSBF MSb first; MST bus slave; BMODE last byte; 
    SPI2CON0 = 0x80;
}

