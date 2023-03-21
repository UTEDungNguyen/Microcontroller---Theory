/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1829
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#define IN1 LATCbits.LATC0
#define IN2 LATCbits.LATC1
#define IN3 LATCbits.LATC2
#define IN4 LATCbits.LATC3
#define SENSOR       PORTCbits.RC4 //6
#define SENSOR_RIGHT PORTBbits.RB6 //11
#define SENSOR_LEFT  PORTCbits.RC7 //9
#define hongngoai    PORTBbits.RB4//13 
int a = 0 ;
int b = 0 ;
int state = 0 ;
unsigned char value =0  ;
int Dis_cm = 20;
uint16_t map(int value , int inputMin , int inMax , int outMin , int outMax); 
#include <stdio.h>
/*
                         Main application
 */
void putch(char data) {
    while(!EUSART_is_tx_ready());
    EUSART_Write(data);
}

void di_thang() {
    IN2 =0;
    IN3 = 0 ;
    IN1 = 1 ; 
    IN4 =1;
    PWM3_LoadDutyValue(600);
    PWM4_LoadDutyValue(600);
}
void di_thang_nhanh() {
    IN2 =0;
    IN4 = 0 ;
    IN1 = 1 ; 
    IN4 =1;
    PWM3_LoadDutyValue(700);
    PWM4_LoadDutyValue(700);
}
void dung_lai(){
    IN2 =0;
    IN3 = 0 ;
    IN1 = 0 ;
    IN4 =0;
    PWM3_LoadDutyValue(0);
    PWM4_LoadDutyValue(0);
}
void rephai(){
    IN2 =1;
    IN3 = 0 ;
    IN1 = 0 ;
    IN4 =1;
    PWM3_LoadDutyValue(0);
    PWM4_LoadDutyValue(900);
           }
void retrai(){
    IN2 =0;
    IN3 = 1 ;
    IN1 = 1 ;
    IN4 =0;
    PWM3_LoadDutyValue(900);
    PWM4_LoadDutyValue(0);
}
void retrai2(){
    IN2 =0;
    IN3 = 0 ;
    IN1 = 1 ;
    IN4 =0;
    PWM3_LoadDutyValue(900);
    PWM4_LoadDutyValue(0);
}
void rephai2(){
    IN2 =0;
    IN3 = 0 ;
    IN1 = 0 ;
    IN4 =1;
    PWM3_LoadDutyValue(0);
    PWM4_LoadDutyValue(900);
}
void retrai3(){
    IN2 =0;
    IN3 = 1 ;
    IN1 = 1 ;
    IN4 =0;
    PWM3_LoadDutyValue(900);
    PWM4_LoadDutyValue(300);
}
void retrainhanh(){
    IN2 =0;
    IN3 = 0 ;
    IN1 = 1 ;
    IN4 =0;
    PWM3_LoadDutyValue(900);
    PWM4_LoadDutyValue(600);
}
void rephainhanh(){
    IN2 =0;
    IN3 = 0 ;
    IN1 = 0 ;
    IN4 =1;
    PWM3_LoadDutyValue(600);
    PWM4_LoadDutyValue(900);
}
void lui(){
    IN2 =1;
    IN3 = 1 ;
    IN1 = 0 ;
    IN4 =0;
    PWM3_LoadDutyValue(600);
    PWM4_LoadDutyValue(600);
}
void lui_nhanh(){
    IN2 =1;
    IN3 = 1 ;
    IN1 = 0 ;
    IN4 =0;
    PWM3_LoadDutyValue(700);
    PWM4_LoadDutyValue(700);
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    uint16_t mappedValue = map(9515,0,1023,61,30) ;// 9515 = 170 ?? // 9514 = 176 ??  // 89,3 ?? 
    uint16_t mappedValue2 = map(20000,0,1023,61,30) ;
    while (1)
    { 
        if ((EUSART_is_rx_ready()!=0)){
        if (EUSART_Read() == 'W') {b=1;}}
        while (b == 1){
            di_thang_nhanh() ;
            __delay_ms(300);
            while (1){       
                if ((hongngoai==1)&&(a!=3)) {
                    EPWM1_LoadDutyValue(mappedValue);
                    if((SENSOR_LEFT==0) && (SENSOR_RIGHT==0)&&(SENSOR == 1)){
                        di_thang();
                    }
                    else if(SENSOR_LEFT!=0 && SENSOR_RIGHT==0 ){
                        retrai();
                    }
                    else if(SENSOR_LEFT==0 && SENSOR_RIGHT!=0 ){
                        rephai();
                    }
                    else if(SENSOR_LEFT==0 && SENSOR_RIGHT==0 &&(SENSOR == 0)){
                        lui();
                    } 
                    else if(SENSOR_LEFT==1 && SENSOR_RIGHT==1 &&(SENSOR == 1)){
                        retrai3();
                    } 
                    else {dung_lai();}
                }

                else if((hongngoai==0)||(a==3)) {
                    if (state != 4) {EPWM1_LoadDutyValue( mappedValue2);}
                    if ((EUSART_is_rx_ready()!=0)){
                        value = EUSART_Read();
                        if (value == 'F') {di_thang_nhanh();}
                        if (value == 'B') {lui_nhanh();}
                        if (value == 'L') {rephai2();}
                        if (value == 'R') {retrai2();}
                        if (value == 'X') {a=3 ;}
                        if (value == 'S') {dung_lai();}
                        if (value == 'V') {state = 4;}
                        if (value == 'v') {state = 5;}
                        if (value == 'G') {rephainhanh();}
                        if (value == 'I') {retrainhanh();}
                    }      
                }
                if (state == 4){EPWM1_LoadDutyValue(mappedValue);}
                if (state == 5){EPWM1_LoadDutyValue(mappedValue2);}
            }
        }
    }
}
uint16_t map(int value , int inputMin , int inMax , int outMin , int outMax){
return (value - inputMin)*(outMax - outMin)/(inMax- inputMin)+outMin;} 
/**
 End of File
*/
