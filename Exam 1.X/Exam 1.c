// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
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

#define _XTAL_FREQ 1000000
#include <xc.h>

void clk_pulse (unsigned int n){
    unsigned int i=0;
    for (i=0 ; i<n ; i++){
        LATCbits.LATC0 = 1;
        LATCbits.LATC0 = 0;
    }
}

void latch_pulse (unsigned int n){
    unsigned int i=0;
    for (i=0 ; i<n ; i++){
        LATCbits.LATC2 = 1;
        LATCbits.LATC2 = 0;
    }
}

void Data_pulse_with_1(unsigned int n){
    LATCbits.LATC1 = 1;
    clk_pulse(n);
}

void Data_pulse_with_0(unsigned int n){
    LATCbits.LATC1 = 0;
    clk_pulse(n);
}

void display_7segment(unsigned int n){
    if (n==0){
        Data_pulse_with_1(1);
        Data_pulse_with_0(6);
    }
    else if (n==1){
        Data_pulse_with_1(4);
        Data_pulse_with_0(2);
        Data_pulse_with_1(1);
    }
    else if (n==2){
        Data_pulse_with_0(1);
        Data_pulse_with_1(1);
        Data_pulse_with_0(2);
        Data_pulse_with_1(1);
        Data_pulse_with_0(2);
    }
    else if (n==3){ 
        Data_pulse_with_0(1);
        Data_pulse_with_1(2);
        Data_pulse_with_0(4);
    }
    else if (n==4){
        Data_pulse_with_0(2);
        Data_pulse_with_1(2);
        Data_pulse_with_0(2);
        Data_pulse_with_1(1);
    }
    else if (n==5){
        Data_pulse_with_0(2);
        Data_pulse_with_1(1);
        Data_pulse_with_0(2);
        Data_pulse_with_1(1);
        Data_pulse_with_0(1);
    }
    else if (n==6){
        Data_pulse_with_0(5);
        Data_pulse_with_1(1);
        Data_pulse_with_0(1);
    }
    else if (n==7){
        Data_pulse_with_1(4);
        Data_pulse_with_0(3);
    }
    else if (n==8){
        Data_pulse_with_0(7);
    }
    else if (n==9){
        Data_pulse_with_0(2);
        Data_pulse_with_1(1);
        Data_pulse_with_0(4);
    }
}

void enter_number_added(unsigned int n){  
    display_7segment(n);
    clk_pulse(1); //Q7 pulse
}

void enter_number_finish(unsigned int n){ 
    display_7segment(n);
    latch_pulse(1);
    __delay_ms(70);
}

void enter_total_number(unsigned int n){
    int a = n/100;
    int b = (n%100)/10;
    int c = (n%100)%10;

    enter_number_added((unsigned int)(c%10));
    enter_number_added((unsigned int)(b%10));
    enter_number_finish((unsigned int)(a%10));
}

void main(void) {
    TRISCbits.TRISC0 = 0; //CLOCK - output
    TRISCbits.TRISC1 = 0; // DATA
    TRISCbits.TRISC2 = 0; // LATCH 
    TRISAbits.TRISA0 = 1;
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA2 = 1;
    TRISAbits.TRISA4 = 0;
    TRISBbits.TRISB4 = 1;
    TRISCbits.TRISC3 = 1;
    
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    
    LATCbits.LATC0 = 0;
    LATCbits.LATC1 = 0;
    LATCbits.LATC2 = 0;
    
    unsigned char S1_state = 0;
    unsigned char S2_state = 0;
    unsigned int dem = 0;
    unsigned int dem1 = 0;
    while(1){
        if (PORTAbits.RA0 == 1){
            if (PORTAbits.RA1 == 1){
                if ((PORTCbits.RC3 == 0) && (S1_state == 0)) S1_state = 1;
                if ((PORTCbits.RC3 == 1) && (S1_state == 1)) S1_state = 2;
                if ((PORTCbits.RC3 == 0) && (S1_state == 2)) S1_state = 3;

                if (S1_state == 3){
                    dem = dem + 1;
                    S1_state = 0;
                    if (dem > 999){
                        dem = 0;
                    }
                }
                LATAbits.LATA4 = 1;
                enter_total_number(dem);

                if (PORTBbits.RB4 == 1){
                    dem = 0;
                    S1_state=0;
                    enter_total_number(dem);
                }
            }
            if (PORTAbits.RA2 == 1){
                if ((PORTCbits.RC3 == 0) && (S2_state == 0)) S2_state = 1;
                if ((PORTCbits.RC3 == 1) && (S2_state == 1)) S2_state = 2;
                if ((PORTCbits.RC3 == 0) && (S2_state == 2)) S2_state = 3;

                if (S2_state == 3){
                    dem1 = dem1 + 1;
                    S2_state = 0;
                }
                if (dem1 < 10){
                    LATAbits.LATA4 = 1; 
                }
                else{
                    dem1 = 10;   
                    LATAbits.LATA4 = 0;   
                }
                enter_total_number(dem1);

                if (PORTBbits.RB4 == 1){
                    dem1 = 0;
                    S2_state=0;
                    enter_total_number(dem1);
                }
            }
        }
        if (PORTAbits.RA0 == 0){
            if (PORTAbits.RA2 == 1){    
                LATAbits.LATA4 = 0;
                Data_pulse_with_1(7);
                latch_pulse(1);
            }
        }
    }
    return;
}
