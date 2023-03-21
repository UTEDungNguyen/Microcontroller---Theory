/*
 * File:   Test week 2 VXL.c
 * Author: DELL
 *
 * Created on March 2, 2022, 11:07 PM
 */
#define _XTAL_FREQ 1000000
// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
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

void main(void) {
    TRISC = 0b00000000; // 0b<RC7><RC6><RC5><RC4><RC3><RC2><RC1><RC0>
    TRISA = 0b00000000;     // 0 = output ; 1 = input
    TRISB = 0b00000000;
    
    int c[10] = {0x3F,0x6,0x5B,0x4F,0x66,0x6D,0x7D,0x7,0x7F,0x6F}; // LATC
    int a[10] = {0x34,0x30,0x14,0x34,0x30,0x24,0x24,0x34,0x34,0x34};
    int b[10] = {0x70,0x0,0xB0,0x90,0xC0,0xD0,0xF0,0x0,0xF0,0xD0};
    
    for (int i=0 ; i<10 ; i++){
        LATC = c[i];
        for (int m=0 ; m<10 ; m++){
            LATA = a[m];
            LATB = b[m];
            __delay_ms(90);
        }
    }
    return;
}
