/**
  @Generated PIC10 / PIC12 / PIC16 / PIC18 MCUs Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    mcc.c

  @Summary:
    This is the mcc.c file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1509
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above or later
        MPLAB             :  MPLAB X 6.00
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

#include "mcc.h"

void SYSTEM_Initialize(void)
{

    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    WDT_Initialize();
    EUSART_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // SCS FOSC; IRCF 1MHz_HF; 
    OSCCON = 0x58;
    // SBOREN disabled; BORFS disabled; 
    BORCON = 0x00;
}

void WDT_Initialize(void)
{
    // WDTPS 1:65536; SWDTEN OFF; 
    WDTCON = 0x16;
}

void LED_1_Blynk(){
    if (state_1 == 1){
        LATCbits.LATC0 = 0;
        __delay_ms(50);
        LATCbits.LATC0 = 1;
    }
    if (state_1 == 2) LATCbits.LATC0 = 0;
}
void LED_2_Blynk(){
    if (state_2 == 1){
        LATCbits.LATC1 = 0;
        __delay_ms(50);
        LATCbits.LATC1 = 1;
    }
    if (state_2 == 2) LATCbits.LATC1 = 0;
}
void LED_3_Blynk(){
    if (state_3 == 1){
        LATCbits.LATC2 = 0;
        __delay_ms(50);
        LATCbits.LATC2 = 1;
    }
    if (state_3 == 2) LATCbits.LATC2 = 0;
}
void LED_4_Blynk(){
    if (state_4 == 1){
        LATCbits.LATC3 = 0;
        __delay_ms(50);
        LATCbits.LATC3 = 1;
    }
    if (state_4 == 2) LATCbits.LATC3 = 0;
}
void LED_5_Blynk(){
    if (state_5 == 1){
        LATCbits.LATC4 = 0;
        __delay_ms(50);
        LATCbits.LATC4 = 1;
    }
    if (state_5 == 2) LATCbits.LATC4 = 0;
}
void LED_6_Blynk(){
    if (state_6 == 1){
        LATCbits.LATC5 = 0;
        __delay_ms(50);
        LATCbits.LATC5 = 1;
    }
    if (state_6 == 2) LATCbits.LATC5 = 0;
}
void LED_7_Blynk(){
    if (state_7 == 1){
        LATCbits.LATC6 = 0;
        __delay_ms(50);
        LATCbits.LATC6 = 1;
    }
    if (state_7 == 2) LATCbits.LATC6 = 0;
}
void LED_8_Blynk(){
    if (state_8 == 1){
        LATCbits.LATC7 = 0;
        __delay_ms(50);
        LATCbits.LATC7 = 1;
    }
    if (state_8 == 2) LATCbits.LATC7 = 0;
}
void Check_Blynk(){
    LED_1_Blynk();
    LED_2_Blynk();
    LED_3_Blynk();
    LED_4_Blynk();
    LED_5_Blynk();
    LED_6_Blynk();
    LED_7_Blynk();
    LED_8_Blynk();        
}


/**
 End of File
*/
