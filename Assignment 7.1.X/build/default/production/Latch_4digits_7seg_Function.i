# 1 "Latch_4digits_7seg_Function.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC12-16F1xxx_DFP/1.3.90/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "Latch_4digits_7seg_Function.c" 2
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
