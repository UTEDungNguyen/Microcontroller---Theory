/*
 * File:   newmain.c
 * Author: hp
 *
 * Created on April 1, 2022, 7:52 PM
 */


// PIC16F1509 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSH       // Oscillator Selection Bits (ECH, External Clock, High Power Mode (4-20 MHz): device clock supplied to CLKIN pins)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#include <xc.h>
unsigned char j=0 ;
unsigned char dem=0 ;
unsigned char mang[20] ={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0b01111000,0x80,0x90};
#define _XTAL_FREQ 1000000
void Nhan_so(unsigned int i){
  unsigned char a = 0x80 ;
  int hang_don_vi = i%10;
  int hang_chuc = (i/10)%10 ;
  int hang_tram = i/100 ;
  int b = mang[hang_don_vi] ;
  int c = mang[hang_chuc] ;
  int d = mang[hang_tram] ;
    for (j=0;j<8;j++){
 if ((b&a)  == a)  LATCbits.LATC1 = 1 ;
 else LATCbits.LATC1 = 0 ;
 LATCbits.LATC0 = 1;
 LATCbits.LATC0 = 0;
 b= b<<1 ;
 }
  for (j=0;j<8;j++){
 if ((c&a)  == a)  LATCbits.LATC1 = 1 ;
 else LATCbits.LATC1 = 0 ;
 LATCbits.LATC0 = 1;
 LATCbits.LATC0 = 0;
 c= c<<1 ;
 }
 for (j=0;j<8;j++){
 if ((d&a)  == a)  LATCbits.LATC1 = 1 ;
 else LATCbits.LATC1 = 0 ;
 LATCbits.LATC0 = 1;
 LATCbits.LATC0 = 0;
 d= d<<1 ;
 }
 LATCbits.LATC2 = 1;
LATCbits.LATC2 = 0;
}
void main(void) {
    int S1_state =0  ;
    int a = 0 ;
    TRISCbits.TRISC3 =1;
    TRISCbits.TRISC0 =0;
    TRISCbits.TRISC1 =0;
    TRISCbits.TRISC2 =0;
    TRISCbits.TRISC4 =0;
    TRISCbits.TRISC5 =1;
    TRISCbits.TRISC6 =1;
    Nhan_so(20);
    while(1){
    if (PORTCbits.RC5 == 1){    
    if (PORTCbits.RC3 == 0 && S1_state == 0) S1_state = 1,a=1; 
    if (PORTCbits.RC3 == 1 && S1_state == 1) S1_state = 2,a=2; 
    if (PORTCbits.RC3 == 0 && S1_state == 2) S1_state = 3,a=3;
    if (S1_state == 3){
    dem = dem+1 ;
    LATCbits.LATC4 = 1;
     __delay_ms(100) ;
    S1_state =0;
    LATCbits.LATC4 = 0;
    }
    
     __delay_ms(10) ;
    Nhan_so(dem);
    if (PORTCbits.RC6 == 1){
    dem = 0 ;
    S1_state =0;
    Nhan_so(dem);}
    }
    }
    
    return;
}
