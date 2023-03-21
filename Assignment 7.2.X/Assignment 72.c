#include "16F1509 config.h"
#include <xc.h>
#include "lcd.h"
#include <stdio.h>
#include <string.h>
#define _XTAL_FREQ 1000000

void main(void) {
    LCD_Initialize();
    LCDPutStr3("DUNG 20146486",0); 
    LCDPutStr2("Temp =",0,1); 
    
    unsigned int ADC0_result_var; // variable to save the result
    TRISAbits.TRISA0 = 1; // Set PIN as input
    ANSELAbits.ANSA0 = 1; // Set PIN as ADC function
    OPTION_REGbits.nWPUEN = 1; // Disable pull up resistor
    ADCON1 = 0b11010000; // Select conversion clock
    // Select voltage reference
    ADCON2 = 0b00000000; // Select auto-trigger source
    ADCON0 = 0b00000001; // Select Analog channel
    ADCON0bits.ADON = 1; // Enable Analog function
    __delay_ms(1); // Delay for T_ACQ
    
    // Create array added CGRAM
    LCDPutCmd(0x40);
    uint8_t cus[] = 
        {0x0E,0x0A,0x0E,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    for (int i=0;i<16;i++){
        LCDPutChar(cus[i]); //added in CGRAM
    } 
    
    float temp_calculate, voltage ;
    unsigned char temp_result[15];
    while(1){
        ADCON0bits. GO_nDONE = 1; // Start conversion
        while(ADCON0bits. GO_nDONE == 1) ; //conversion complete wait
        ADC0_result_var = ADRESH; // High byte of the result
        ADC0_result_var = (ADC0_result_var<<8) | ADRESL ;
        voltage = ((float)(ADC0_result_var)*5)/1023;
        temp_calculate = voltage*100;
        sprintf(temp_result,"%0.1f",temp_calculate); 
        // Convert float into String
        LCDPutStr2(temp_result,7,1); 
        LCDGoto(12,1);
        LCDPutChar(0);  // Call array CGRAM and display LCD
        LCDPutStr2("C",13,1); 
        if (temp_calculate < 100){
            LCDGoto(11,1);
            LCDPutChar(1);  
        }
        if (temp_calculate < 10){
            LCDGoto(10,1);
            LCDPutChar(1);  
        }
    }
    return;
}
