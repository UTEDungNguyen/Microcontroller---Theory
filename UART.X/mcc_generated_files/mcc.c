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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1509
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above or later
        MPLAB             :  MPLAB X 5.45
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
    // SCS INTOSC; IRCF 1MHz_HF; 
    OSCCON = 0x5A;
    // SBOREN disabled; BORFS disabled; 
    BORCON = 0x00;
}

void WDT_Initialize(void)
{
    // WDTPS 1:65536; SWDTEN OFF; 
    WDTCON = 0x16;
}
void statement1 (){
if (st_1==1) {
    LATCbits.LATC0 =0 ;
    __delay_ms(1);
    LATCbits.LATC0 =1;
}
if (st_1==2) LATCbits.LATC0 =0 ;}
void statement2 (){
if (st_2==1) {
    LATCbits.LATC1 =0 ;
    __delay_ms(1);
    LATCbits.LATC1 =1;
}
if (st_2==2) LATCbits.LATC1 =0 ;}
void statement3 (){
if (st_3==1) {
    LATCbits.LATC2 =0 ;
    __delay_ms(1);
    LATCbits.LATC2 =1;
}
if (st_3==2) LATCbits.LATC2 =0 ;}
void statement4 (){
if (st_4==1) {
    LATCbits.LATC3 =0 ;
    __delay_ms(1);
    LATCbits.LATC3 =1;
}
if (st_4==2) LATCbits.LATC3 =0 ;}
void statement5 (){
if (st_5==1) {
    LATCbits.LATC4 =0 ;
    __delay_ms(1);
    LATCbits.LATC4 =1;
}
if (st_5==2) LATCbits.LATC4 =0 ;}
void statement6 (){
if (st_6==1) {
    LATCbits.LATC5 =0 ;
    __delay_ms(1);
    LATCbits.LATC5 =1;
}
if (st_6==2) LATCbits.LATC5 =0 ;}
void statement7 (){
if (st_7==1) {
    LATCbits.LATC6 =0 ;
    __delay_ms(1);
    LATCbits.LATC6 =1;
}
if (st_7==2) LATCbits.LATC6 =0 ;}
void statement8 (){
if (st_8==1) {
    LATCbits.LATC7 =1 ;
    __delay_ms(1);
    LATCbits.LATC7 =0;
}
if (st_8==2) LATCbits.LATC7 =0 ;}
void test(){
statement1();
statement2();
statement3();
statement4();
statement5();
statement6();
statement7();
statement8();}
/**
 End of File
*/
