#include "16F1509 config.h"
#include <xc.h>
#define _XTAL_FREQ 1000000

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
    clk_pulse(1);
}

void enter_number_finish(unsigned int n){ 
    display_7segment(n);
    latch_pulse(1);
    __delay_ms(70);
}

void enter_total_number(unsigned int n){
    int a = n/1000;
    int b = (n/100)%10;
    int c = (n%100)/10;
    int d = (n%100)%10;

    enter_number_added((unsigned int)(d%10));
    enter_number_added((unsigned int)(c%10));
    enter_number_added((unsigned int)(b%10));
    enter_number_finish((unsigned int)(a%10));
}

void enter_digit_total(unsigned int seconds,unsigned int minutes){
    enter_number_added((unsigned int)(seconds%10));
    enter_number_added((unsigned int)(seconds/10));
    enter_number_added((unsigned int)(minutes%10));
    enter_number_finish((unsigned int)(minutes/10));
}

void main(void) {
    TRISCbits.TRISC0 = 0; //CLOCK - output
    TRISCbits.TRISC1 = 0; // DATA
    TRISCbits.TRISC2 = 0; // LATCH 
    
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA2 = 1;
    
    LATCbits.LATC0 = 0;
    LATCbits.LATC1 = 0;
    LATCbits.LATC2 = 0;
    
    ANSELAbits.ANSA1 = 0;
    ANSELAbits.ANSA2 = 0;
    ANSELC = 0;
    
    unsigned int ADC0_result_var=0; // variable to save the result
    TRISAbits.TRISA0 = 1; // Set PIN as input
    ANSELAbits.ANSA0 = 1; // Set PIN as ADC function
    OPTION_REGbits.nWPUEN = 1; // Disable pull up resistor
    ADCON1 = 0b11010000; // Select conversion clock
    // Select voltage reference
    ADCON2 = 0b00000000; // Select auto-trigger source
    ADCON0 = 0b00000001; // Select Analog channel
    ADCON0bits.ADON = 1; // Enable Analog function
    __delay_ms(1); // Delay for T_ACQ
         
    
    unsigned char S1_state = 0;
    unsigned char h  ; // conversion ADC for seconds
    unsigned char m ;  // conversion ADC for minutes 
    unsigned int minutes = 0;  //2 digits minutes
    unsigned int seconds = 0;  //2 digits seconds
    while(1){
        ADCON0bits. GO_nDONE = 1; // Start conversion
        while(ADCON0bits. GO_nDONE == 1) ; //conversion complete wait
        ADC0_result_var = ADRESH; // High byte of the result
        ADC0_result_var = (ADC0_result_var<<8) | ADRESL ;

        if ((PORTAbits.RA1 == 0) && (S1_state == 0)) S1_state = 1;
        if ((PORTAbits.RA1 == 1) && (S1_state == 1)) S1_state = 2;
        if ((PORTAbits.RA1 == 0) && (S1_state == 2)) S1_state = 3;
        if ((PORTAbits.RA1 == 1) && (S1_state == 3)) S1_state = 4;
        if ((PORTAbits.RA1 == 0) && (S1_state == 4)) S1_state = 5;
        if ((PORTAbits.RA1 == 1) && (S1_state == 5)) S1_state = 6;
        if ((PORTAbits.RA1 == 0) && (S1_state == 6)) S1_state = 7;
        if ((PORTAbits.RA1 == 1) && (S1_state == 7)) S1_state = 8;
        if ((PORTAbits.RA1 == 0) && (S1_state == 8)) S1_state = 2;

        if (S1_state == 1){
            seconds = seconds + 1; 
            enter_digit_total(seconds,minutes);
            if (seconds > 58){  
                seconds = 0;
                minutes = minutes + 1;
                if (minutes <= 59){
                    enter_digit_total(seconds,minutes);
                }
                if (minutes > 59 ){
                    minutes = 0;
                    seconds = 0;
                    enter_digit_total(seconds,minutes);
                }
            }
        }
        if (S1_state == 2){
            enter_total_number(0);
        }
        if (S1_state == 3){
            __delay_ms(25);
            m = ((int)(ADC0_result_var/17.33)%100);
            enter_digit_total(0,m); 
            // set up for minutes ex : 100% --> 59p , 10% --> 5p , v.v
        }
        if (S1_state == 5){
            h = ((int)(ADC0_result_var/17.33)%100);
            enter_digit_total(h,m); 
            // set up for seconds ex : 100% --> 59s , 10% --> 5s , v.v
        }
        if (S1_state == 7){
            h = h + 1; 
            enter_digit_total(h,m);
            if (h > 58){  
                h = 0;
                m = m + 1;
                if (m <= 59){
                    enter_digit_total(h,m);
                }
                if (m > 59 ){
                    m = 0;
                    h = 0;
                    enter_digit_total(h,m);
                }
            }
        }
        if (PORTAbits.RA2 == 1){
            seconds = 0;
            minutes = 0;
            h = 0 ;
            m = 0 ;
        }
    }
    return;
}
