/**
 * UART5 Generated Driver API Header File
 * 
 * @file uart5.c
 * 
 * @ingroup uart5
 * 
 * @brief This is the generated driver implementation file for the UART5 driver using the Universal Asynchronous Receiver and Transmitter (UART) module.
 *
 * @version UART5 Driver Version 3.0.8
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

/**
  Section: Included Files
*/
#include "../uart5.h"

/**
  Section: Macro Declarations
*/

/**
  Section: Driver Interface
 */

const uart_drv_interface_t UART5 = {
    .Initialize = &UART5_Initialize,
    .Deinitialize = &UART5_Deinitialize,
    .Read = &UART5_Read,
    .Write = &UART5_Write,
    .IsRxReady = &UART5_IsRxReady,
    .IsTxReady = &UART5_IsTxReady,
    .IsTxDone = &UART5_IsTxDone,
    .TransmitEnable = &UART5_TransmitEnable,
    .TransmitDisable = &UART5_TransmitDisable,
    .AutoBaudSet = &UART5_AutoBaudSet,
    .AutoBaudQuery = &UART5_AutoBaudQuery,
    .BRGCountSet = NULL,
    .BRGCountGet = NULL,
    .BaudRateSet = NULL,
    .BaudRateGet = NULL,
    .AutoBaudEventEnableGet = NULL,
    .ErrorGet = &UART5_ErrorGet,
    .TxCompleteCallbackRegister = NULL,
    .RxCompleteCallbackRegister = NULL,
    .TxCollisionCallbackRegister = NULL,
    .FramingErrorCallbackRegister = &UART5_FramingErrorCallbackRegister,
    .OverrunErrorCallbackRegister = &UART5_OverrunErrorCallbackRegister,
    .ParityErrorCallbackRegister = &UART5_ParityErrorCallbackRegister,
    .EventCallbackRegister = NULL,
};

/**
  Section: UART5 variables
*/
 /**
 * @misradeviation{@advisory,19.2}
 * The UART error status necessitates checking the bitfield and accessing the status within the group byte therefore the use of a union is essential.
 */
 /* cppcheck-suppress misra-c2012-19.2 */
static volatile uart5_status_t uart5RxLastError;

/**
  Section: UART5 APIs
*/

static void (*UART5_FramingErrorHandler)(void);
static void (*UART5_OverrunErrorHandler)(void);
static void (*UART5_ParityErrorHandler)(void);

static void UART5_DefaultFramingErrorCallback(void);
static void UART5_DefaultOverrunErrorCallback(void);
static void UART5_DefaultParityErrorCallback(void);

/**
  Section: UART5  APIs
*/

void UART5_Initialize(void)
{

    // Set the UART5 module to the options selected in the user interface.

    //P1L 0x0; 
    U5P1L = 0x0;
    //P2L 0x0; 
    U5P2L = 0x0;
    //P3L 0x0; 
    U5P3L = 0x0;
    //MODE Asynchronous 8-bit mode; RXEN disabled; TXEN enabled; ABDEN disabled; BRGS high speed; 
    U5CON0 = 0xA0;
    //SENDB disabled; BRKOVR disabled; RXBIMD Set RXBKIF on rising RX input; WUE disabled; ON enabled; 
    U5CON1 = 0x80;
    //FLO off; TXPOL not inverted; STP Transmit 1Stop bit, receiver verifies first Stop bit; RXPOL not inverted; RUNOVF RX input shifter stops all activity; 
    U5CON2 = 0x0;
    //BRGL 138; 
    U5BRGL = 0x8A;
    //BRGH 0; 
    U5BRGH = 0x0;
    //TXBE empty; STPMD in middle of first Stop bit; TXWRE No error; 
    U5FIFO = 0x2E;
    //ABDIE disabled; ABDIF Auto-baud not enabled or not complete; WUIF WUE not enabled by software; 
    U5UIR = 0x0;
    //TXCIF equal; RXFOIF not overflowed; RXBKIF No Break detected; FERIF no error; CERIF No Checksum error; ABDOVF Not overflowed; PERIF no parity error; TXMTIF empty; 
    U5ERRIR = 0x80;
    //TXCIE disabled; RXFOIE disabled; RXBKIE disabled; FERIE disabled; CERIE disabled; ABDOVE disabled; PERIE disabled; TXMTIE disabled; 
    U5ERRIE = 0x0;

    UART5_FramingErrorCallbackRegister(UART5_DefaultFramingErrorCallback);
    UART5_OverrunErrorCallbackRegister(UART5_DefaultOverrunErrorCallback);
    UART5_ParityErrorCallbackRegister(UART5_DefaultParityErrorCallback);

    uart5RxLastError.status = 0;  
}

void UART5_Deinitialize(void)
{
    U5RXB = 0x00;
    U5TXB = 0x00;
    U5P1L = 0x00;
    U5P2L = 0x00;
    U5P3L = 0x00;
    U5CON0 = 0x00;
    U5CON1 = 0x00;
    U5CON2 = 0x00;
    U5BRGL = 0x00;
    U5BRGH = 0x00;
    U5FIFO = 0x00;
    U5UIR = 0x00;
    U5ERRIR = 0x00;
    U5ERRIE = 0x00;
}

void UART5_Enable(void)
{
    U5CON1bits.ON = 1; 
}

void UART5_Disable(void)
{
    U5CON1bits.ON = 0; 
}

void UART5_TransmitEnable(void)
{
    U5CON0bits.TXEN = 1;
}

void UART5_TransmitDisable(void)
{
    U5CON0bits.TXEN = 0;
}

void UART5_SendBreakControlEnable(void)
{
    U5CON1bits.SENDB = 1;
}

void UART5_SendBreakControlDisable(void)
{
    U5CON1bits.SENDB = 0;
}

void UART5_AutoBaudSet(bool enable)
{
    if(enable)
    {
        U5CON0bits.ABDEN = 1; 
    }
    else
    {
      U5CON0bits.ABDEN = 0;  
    }
}


bool UART5_AutoBaudQuery(void)
{
    return (bool)U5UIRbits.ABDIF; 
}

void UART5_AutoBaudDetectCompleteReset(void)
{
    U5UIRbits.ABDIF = 0; 
}

bool UART5_IsAutoBaudDetectOverflow(void)
{
    return (bool)U5ERRIRbits.ABDOVF; 
}

void UART5_AutoBaudDetectOverflowReset(void)
{
    U5ERRIRbits.ABDOVF = 0; 
}

bool UART5_IsRxReady(void)
{
    return (bool)(!U5FIFObits.RXBE);
}

bool UART5_IsTxReady(void)
{
    return (bool)(U5FIFObits.TXBE && U5CON0bits.TXEN);
}

bool UART5_IsTxDone(void)
{
    return U5ERRIRbits.TXMTIF;
}

size_t UART5_ErrorGet(void)
{
    uart5RxLastError.status = 0;
    
    if(true == U5ERRIRbits.FERIF)
    {
        uart5RxLastError.ferr = 1;
        if(NULL != UART5_FramingErrorHandler)
        {
            UART5_FramingErrorHandler();
        }  
    }
    if(true == U5ERRIRbits.RXFOIF)
    {
        uart5RxLastError.oerr = 1;
        if(NULL != UART5_OverrunErrorHandler)
        {
            UART5_OverrunErrorHandler();
        }   
    }
    if(true == U5ERRIRbits.PERIF)
    {
        uart5RxLastError.perr = 1;
        if(NULL != UART5_ParityErrorHandler)
        {
            UART5_ParityErrorHandler();
        }   
    }

    return uart5RxLastError.status;
}

uint8_t UART5_Read(void)
{
    return U5RXB;
}


void UART5_Write(uint8_t txData)
{
    U5TXB = txData; 
}


int getch(void)
{
    while(!(UART5_IsRxReady()))
    {

    }
    return UART5_Read();
}

void putch(char txData)
{
    while(!(UART5_IsTxReady()))
    {

    }
    return UART5_Write(txData);   
}





static void UART5_DefaultFramingErrorCallback(void)
{
    
}

static void UART5_DefaultOverrunErrorCallback(void)
{
    
}

static void UART5_DefaultParityErrorCallback(void)
{
    
}

void UART5_FramingErrorCallbackRegister(void (* callbackHandler)(void))
{
    if(NULL != callbackHandler)
    {
        UART5_FramingErrorHandler = callbackHandler;
    }
}

void UART5_OverrunErrorCallbackRegister(void (* callbackHandler)(void))
{
    if(NULL != callbackHandler)
    {
        UART5_OverrunErrorHandler = callbackHandler;
    }    
}

void UART5_ParityErrorCallbackRegister(void (* callbackHandler)(void))
{
    if(NULL != callbackHandler)
    {
        UART5_ParityErrorHandler = callbackHandler;
    } 
}
