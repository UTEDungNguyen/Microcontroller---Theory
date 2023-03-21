/*
 * File:   newmain.c
 * Author: DELL
 *
 * Created on October 21, 2022, 4:19 PM
 */
// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 20000000

void Led_200ms(){
    unsigned char i,h = 0;
    h = 0b00001000;
    for (char m=0;m<4;m++){
        PORTC = h;
        h=h>>1;
        __delay_ms(200);
        PORTC=h;
    }
}

void Led_1s(){
    unsigned char i,h = 0;
    h = 0b00001000;
    for (char m=0;m<4;m++){
        PORTC = h;
        h=h>>1;
        __delay_ms(1000);
        PORTC=h;
    }
}

void main(void) {
    TRISC = 0;
	ANSEL = ANSELH = 0; // disable analog all I/O
	TRISA0 = 1; //INPUT
	TRISA1 = 1;
	TRISA2 = 1;
    PORTC = 0;
    
    GIE = 1;
    RBIE = 1;
    RBIF = 0;
    IOCB = 0b11100000;

    while(1){
        Led_200ms();
    }
    return; 
}

void interrupt button(void){
    if (RB5 == 1){
        while(RB5==1){
        }
        if (RB5 == 0){
            Led_1s();
        }
    }  
}
