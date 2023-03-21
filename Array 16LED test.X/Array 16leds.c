
/*
 * File:   main.c
 * Author: 7570
 *
 * Created on March 10, 2022, 8:34 PM
 */

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
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
#include<string.h>
#define _XTAL_FREQ 4000000



void main(void){
    TRISC=0;
    TRISD=0;
    TRISB=TRISA=1;
    ANSEL=ANSELH=0;
    PORTC=PORTD=0;
    while(1){        
        if(RA0==0){
            PORTC=PORTD=0;
            unsigned char var=0x80 ;    
            unsigned char var1=0b00000010;
            for(var1;var1!=0b00000000;var1>>=1){
                PORTD=var1;
                __delay_ms(50);
            }
            PORTD=0;
            for(var;var!=0x00;var>>=1){
                PORTC=var;
                __delay_ms(50);
            }
            PORTC=0;
        }
        if(RB0==0){
            PORTC=PORTD=0;
            __delay_ms(50);
            unsigned char var2=0b10000000;
            unsigned char var3=0b00000010;
            unsigned char x=0b00000010;
            for(x;x!=0x00;x>>=1){
                var3|=x;
                PORTD=var3;
                __delay_ms(50);
            }
            x=0b10000000;
            for(x;x!=0x00;x>>=1){
                var2|=x;
                PORTC=var2;
                __delay_ms(50);
            }
        }
    }
    return ;
}