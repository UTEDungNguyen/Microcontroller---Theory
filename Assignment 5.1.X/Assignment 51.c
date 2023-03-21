// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
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

#define _XTAL_FREQ 1000000
#include <xc.h>

void one_LED_move(){
    unsigned char i,h=0;
    i = 0b10000000;
    h = 0b00100000;
    for (char m=0;m<2;m++){
        LATB = h;
        h=h>>1;
        __delay_ms(50);
        LATB=h;
    }
    for (char n=0;n<8;n++){
        LATC = i;   
        i=i>>1;
        __delay_ms(50);
        LATC = i;
    }
}

void LED_one_by_one(){
    unsigned char i,h=0;
    i = 0b10000000;
    h = 0b00100000;
    for (char m=0;m<2;m++){
        LATB = h;
        h=h>>1|h;
        __delay_ms(50);
    }
    for (char n=0;n<8;n++){
        LATC = i;   
        i=i>>1|i;
        __delay_ms(50);
    }
    LATB = 0;
    LATC = 0;
    __delay_ms(40);
}

void main(void) {
    TRISC = 0;
    TRISB = 0;
    LATB = 0;
    LATC = 0;
    ANSELA = 0;
    TRISAbits.TRISA0 = 1;  // S1 button as input
    TRISAbits.TRISA1 = 1;  // S2 button as input
    TRISAbits.TRISA2 = 1;  // S3 button as input
    unsigned char S1_state=0 ;
    unsigned char S2_state=0 ;
    while(1){
        if ((S1_state == 0) && (PORTAbits.RA0 == 0)) S1_state =1;
        if ((S1_state == 1) && (PORTAbits.RA0 == 1)) S1_state =2;
        if ((S1_state == 2) && (PORTAbits.RA0 == 0)) S1_state =3;
        
        if ((S2_state == 0) && (PORTAbits.RA1 == 0)) S2_state =1;
        if ((S2_state == 1) && (PORTAbits.RA1 == 1)) S2_state =2;
        if ((S2_state == 2) && (PORTAbits.RA1 == 0)) S2_state =3;
            
        if (S1_state == 2){
            LATB = 0;
            LATC = 0;
        }
        if (S1_state == 3){
            one_LED_move();
        }
        
        if (S2_state == 2){
            LATB = 0;
            LATC = 0;
        }
        
        if (S2_state == 3){
            LED_one_by_one();
        }
        
        if (PORTAbits.RA2 == 1){
            LATB = 0;
            LATC = 0;
            S1_state = 0;
            S2_state = 0;
        }
    }     
    return;
}
