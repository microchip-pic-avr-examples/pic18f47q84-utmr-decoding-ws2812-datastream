/**
  @Generated Not generated by MCC. This is a custom file.

  @Company:
    Microchip Technology Inc.

  @File Name:
    ws2812_seed.h

  @Summary:
    Not generated by MCC. This is a custom file.

  @Description:
    Not generated by MCC. This is a custom file.
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. 
    
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

#ifndef WS2812_SEED_H
#define	WS2812_SEED_H

#define WS2812_SEED_SIZE                1800
#define WS2812_SEED_NUMLED              5
#define WS2812_SEED_NUMLED_BYTELEN      15      // =3*NUMLED
#define WS2812_SEED_NUMPACKETS          120     // =SIZE/BYTELEN

const uint8_t ws2812_seed[WS2812_SEED_SIZE] = 
{
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	0,0,0,
	1,0,0,
	1,0,0,
	1,0,0,
	1,0,0,
	1,0,0,
	2,0,0,
	2,0,0,
	2,0,0,
	2,0,0,
	2,0,0,
	3,0,0,
	3,0,0,
	3,0,0,
	3,0,0,
	3,0,0,
	4,0,0,
	4,0,0,
	4,0,0,
	4,0,0,
	4,0,0,
	5,0,0,
	5,0,0,
	5,0,0,
	5,0,0,
	5,0,0,
	6,0,0,
	6,0,0,
	6,0,0,
	6,0,0,
	6,0,0,
	7,0,0,
	7,0,0,
	7,0,0,
	7,0,0,
	7,0,0,
	8,0,0,
	8,0,0,
	8,0,0,
	8,0,0,
	8,0,0,
	9,0,0,
	9,0,0,
	9,0,0,
	9,0,0,
	9,0,0,
	10,0,0,
	10,0,0,
	10,0,0,
	10,0,0,
	10,0,0,
	11,0,0,
	11,0,0,
	11,0,0,
	11,0,0,
	11,0,0,
	12,0,0,
	12,0,0,
	12,0,0,
	12,0,0,
	12,0,0,
	13,0,0,
	13,0,0,
	13,0,0,
	13,0,0,
	13,0,0,
	14,0,0,
	14,0,0,
	14,0,0,
	14,0,0,
	14,0,0,
	15,0,0,
	15,0,0,
	15,0,0,
	15,0,0,
	15,0,0,
	16,0,0,
	16,0,0,
	16,0,0,
	16,0,0,
	16,0,0,
	17,0,0,
	17,0,0,
	17,0,0,
	17,0,0,
	17,0,0,
	18,0,0,
	18,0,0,
	18,0,0,
	18,0,0,
	18,0,0,
	19,0,0,
	19,0,0,
	19,0,0,
	19,0,0,
	19,0,0,
	20,0,0,
	20,0,0,
	20,0,0,
	20,0,0,
	20,0,0,
	20,1,0,
	20,1,0,
	20,1,0,
	20,1,0,
	20,1,0,
	20,2,0,
	20,2,0,
	20,2,0,
	20,2,0,
	20,2,0,
	20,3,0,
	20,3,0,
	20,3,0,
	20,3,0,
	20,3,0,
	20,4,0,
	20,4,0,
	20,4,0,
	20,4,0,
	20,4,0,
	20,5,0,
	20,5,0,
	20,5,0,
	20,5,0, 
	20,5,0,
	20,6,0,
	20,6,0,
	20,6,0,
	20,6,0,
	20,6,0,
	20,7,0,
	20,7,0,
	20,7,0,
	20,7,0,
	20,7,0,
	20,8,0,
	20,8,0,
	20,8,0,
	20,8,0,
	20,8,0,
	20,9,0,
	20,9,0,
	20,9,0,
	20,9,0,
	20,9,0,
	20,10,0,
	20,10,0,
	20,10,0,
	20,10,0,
	20,10,0,
	20,11,0,
	20,11,0,
	20,11,0,
	20,11,0,
	20,11,0,
	20,12,0,
	20,12,0,
	20,12,0,
	20,12,0,
	20,12,0,
	20,13,0,
	20,13,0,
	20,13,0,
	20,13,0,
	20,13,0,
	20,14,0,
	20,14,0,
	20,14,0,
	20,14,0,
	20,14,0,
	20,15,0,
	20,15,0,
	20,15,0,
	20,15,0,
	20,15,0,
	20,16,0,
	20,16,0,
	20,16,0,
	20,16,0,
	20,16,0,
	20,17,0,
	20,17,0,
	20,17,0,
	20,17,0,
	20,17,0,
	20,18,0,
	20,18,0,
	20,18,0,
	20,18,0,
	20,18,0,
	20,19,0,
	20,19,0,
	20,19,0,
	20,19,0,
	20,19,0,
	20,20,0,
	20,20,0,
	20,20,0,
	20,20,0,
	20,20,0,
	20,20,1,
	20,20,1,
	20,20,1,
	20,20,1,
	20,20,1,
	20,20,2,
	20,20,2,
	20,20,2,
	20,20,2,
	20,20,2,
	20,20,3,
	20,20,3,
	20,20,3,
	20,20,3,
	20,20,3,
	20,20,4,
	20,20,4,
	20,20,4,
	20,20,4,
	20,20,4,
	20,20,5,
	20,20,5,
	20,20,5,
	20,20,5,
	20,20,5,
	20,20,6,
	20,20,6,
	20,20,6,
	20,20,6,
	20,20,6,
	20,20,7,
	20,20,7,
	20,20,7,
	20,20,7,
	20,20,7,
	20,20,8,
	20,20,8,
	20,20,8,
	20,20,8,
	20,20,8,
	20,20,9,
	20,20,9,
	20,20,9,
	20,20,9,
	20,20,9,
	20,20,10,
	20,20,10,
	20,20,10,
	20,20,10,
	20,20,10,
	20,20,11,
	20,20,11,
	20,20,11,
	20,20,11,
	20,20,11,
	20,20,12,
	20,20,12,
	20,20,12,
	20,20,12,
	20,20,12,
	20,20,13,
	20,20,13,
	20,20,13,
	20,20,13,
	20,20,13,
	20,20,14,
	20,20,14,
	20,20,14,
	20,20,14,
	20,20,14,
	20,20,15,
	20,20,15,
	20,20,15,
	20,20,15,
	20,20,15,
	20,20,16,
	20,20,16,
	20,20,16,
	20,20,16,
	20,20,16,
	20,20,17,
	20,20,17,
	20,20,17,
	20,20,17,
	20,20,17,
	20,20,18,
	20,20,18,
	20,20,18,
	20,20,18,
	20,20,18,
	20,20,19,
	20,20,19,
	20,20,19,
	20,20,19,
	20,20,19,
	20,20,20,
	20,20,20,
	20,20,20,
	20,20,20,
	20,20,20,
	19,20,20,
	19,20,20,
	19,20,20,
	19,20,20,
	19,20,20,
	18,20,20,
	18,20,20,
	18,20,20,
	18,20,20,
	18,20,20,
	17,20,20,
	17,20,20,
	17,20,20,
	17,20,20,
	17,20,20,
	16,20,20,
	16,20,20,
	16,20,20,
	16,20,20,
	16,20,20,
	15,20,20,
	15,20,20,
	15,20,20,
	15,20,20,
	15,20,20,
	14,20,20,
	14,20,20,
	14,20,20,
	14,20,20,
	14,20,20,
	13,20,20,
	13,20,20,
	13,20,20,
	13,20,20,
	13,20,20,
	12,20,20,
	12,20,20,
	12,20,20,
	12,20,20,
	12,20,20,
	11,20,20,
	11,20,20,
	11,20,20,
	11,20,20,
	11,20,20,
	10,20,20,
	10,20,20,
	10,20,20,
	10,20,20,
	10,20,20,
	9,20,20,
	9,20,20,
	9,20,20,
	9,20,20,
	9,20,20,
	8,20,20,
	8,20,20,
	8,20,20,
	8,20,20,
	8,20,20,
	7,20,20,
	7,20,20,
	7,20,20,
	7,20,20,
	7,20,20,
	6,20,20,
	6,20,20,
	6,20,20,
	6,20,20,
	6,20,20,
	5,20,20,
	5,20,20,
	5,20,20,
	5,20,20,
	5,20,20,
	4,20,20,
	4,20,20,
	4,20,20,
	4,20,20,
	4,20,20,
	3,20,20,
	3,20,20,
	3,20,20,
	3,20,20,
	3,20,20,
	2,20,20,
	2,20,20,
	2,20,20,
	2,20,20,
	2,20,20,
	1,20,20,
	1,20,20,
	1,20,20,
	1,20,20,
	1,20,20,
	0,20,20,
	0,20,20,
	0,20,20,
	0,20,20,
	0,20,20,
	0,19,20,
	0,19,20,
	0,19,20,
	0,19,20,
	0,19,20,
	0,18,20,
	0,18,20,
	0,18,20,
	0,18,20,
	0,18,20,
	0,17,20,
	0,17,20,
	0,17,20,
	0,17,20,
	0,17,20,
	0,16,20,
	0,16,20,
	0,16,20,
	0,16,20,
	0,16,20,
	0,15,20,
	0,15,20,
	0,15,20,
	0,15,20,
	0,15,20,
	0,14,20,
	0,14,20,
	0,14,20,
	0,14,20,
	0,14,20,
	0,13,20,
	0,13,20,
	0,13,20,
	0,13,20,
	0,13,20,
	0,12,20,
	0,12,20,
	0,12,20,
	0,12,20,
	0,12,20,
	0,11,20,
	0,11,20,
	0,11,20,
	0,11,20,
	0,11,20,
	0,10,20,
	0,10,20,
	0,10,20,
	0,10,20,
	0,10,20,
	0,9,20,
	0,9,20,
	0,9,20,
	0,9,20,
	0,9,20,
	0,8,20,
	0,8,20,
	0,8,20,
	0,8,20,
	0,8,20,
	0,7,20,
	0,7,20,
	0,7,20,
	0,7,20,
	0,7,20,
	0,6,20,
	0,6,20,
	0,6,20,
	0,6,20,
	0,6,20,
	0,5,20,
	0,5,20,
	0,5,20,
	0,5,20,
	0,5,20,
	0,4,20,
	0,4,20,
	0,4,20,
	0,4,20,
	0,4,20,
	0,3,20,
	0,3,20,
	0,3,20,
	0,3,20,
	0,3,20,
	0,2,20,
	0,2,20,
	0,2,20,
	0,2,20,
	0,2,20,
	0,1,20,
	0,1,20,
	0,1,20,
	0,1,20,
	0,1,20,
	0,0,20,
	0,0,20,
	0,0,20,
	0,0,20,
	0,0,20,
	0,0,19,
	0,0,19,
	0,0,19,
	0,0,19,
	0,0,19,
	0,0,18,
	0,0,18,
	0,0,18,
	0,0,18,
	0,0,18,
	0,0,17,
	0,0,17,
	0,0,17,
	0,0,17,
	0,0,17,
	0,0,16,
	0,0,16,
	0,0,16,
	0,0,16,
	0,0,16,
	0,0,15,
	0,0,15,
	0,0,15,
	0,0,15,
	0,0,15,
	0,0,14,
	0,0,14,
	0,0,14,
	0,0,14,
	0,0,14,
	0,0,13,
	0,0,13,
	0,0,13,
	0,0,13,
	0,0,13,
	0,0,12,
	0,0,12,
	0,0,12,
	0,0,12,
	0,0,12,
	0,0,11,
	0,0,11,
	0,0,11,
	0,0,11,
	0,0,11,
	0,0,10,
	0,0,10,
	0,0,10,
	0,0,10,
	0,0,10,
	0,0,9,
	0,0,9,
	0,0,9,
	0,0,9,
	0,0,9,
	0,0,8,
	0,0,8,
	0,0,8,
	0,0,8,
	0,0,8,
	0,0,7,
	0,0,7,
	0,0,7,
	0,0,7,
	0,0,7,
	0,0,6,
	0,0,6,
	0,0,6,
	0,0,6,
	0,0,6,
	0,0,5,
	0,0,5,
	0,0,5,
	0,0,5,
	0,0,5,
	0,0,4,
	0,0,4,
	0,0,4,
	0,0,4,
	0,0,4,
	0,0,3,
	0,0,3,
	0,0,3,
	0,0,3,
	0,0,3,
	0,0,2,
	0,0,2,
	0,0,2,
	0,0,2,
	0,0,2,
	0,0,1,
	0,0,1,
	0,0,1,
	0,0,1,
	0,0,1
};


#endif	/* WS2812_SEED_H */
/**
 End of File
*/