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

/*
                         Main application
 */

#define in1 LATCbits.LATC0
#define in2 LATCbits.LATC1
#define in3 LATCbits.LATC2
#define in4 LATAbits.LATA4
#define LinePhai PORTCbits.RC4
#define LineGiua PORTCbits.RC7
#define LineTrai PORTBbits.RB6

#define VatCan PORTBbits.RB4

unsigned char cmd, state = 1;
unsigned int time;
float distance;

/*void DoKhoangCach() {
    trigger = 1;
    __delay_us(10);
    trigger = 0;
    while (echo == 0);
    TMR0 = 0;
    while (echo == 1);
    time = TMR0 * 4 * 4;
    distance = (float) time / 58;
    //__delay_ms(100);
}*/

void Forward() {
    in1 = 1;
    in2 = 0;
    in3 = 1;
    in4 = 0;
}

void turnRight() {
    in1 = 0;
    in2 = 1;
    in3 = 1;
    in4 = 0;
}

void turnLeft() {
    in1 = 1;
    in2 = 0;
    in3 = 0;
    in4 = 1;
}

void Stop() {
    in1 = 0;
    in2 = 0;
    in3 = 0;
    in4 = 0;
}

void Backward() {
    in1 = 0;
    in2 = 1;
    in3 = 0;
    in4 = 1;
}

void main(void) {
    SYSTEM_Initialize();
    PWM3_LoadDutyValue(400);
    PWM4_LoadDutyValue(450);
    EPWM1_LoadDutyValue(15);
    EPWM2_LoadDutyValue(30);

    while (1) {

        if (state == 1) {
            while (EUSART_is_rx_ready() == 0);
            cmd = EUSART_Read();
            if (cmd == 'S') {
                Stop();
            }
            if (cmd == 'F') {
                Forward();
            }
            if (cmd == 'G') {
                Backward();
            }
            if (cmd == 'R') {
                turnLeft();
            }
            if (cmd == 'L') {
                turnRight();
            }
            if (cmd == 'X') {
                state = 0;
            }
            if (cmd == 'D') {
                EPWM1_LoadDutyValue(14);
                EPWM2_LoadDutyValue(30);
            }
        }

        if (state == 0) {
            //DoKhoangCach();
            if (VatCan == 1) {
                if (LineGiua == 1) {
                    Forward();
                }
                if ((LineTrai == 1) || ((LineTrai == 1)&&(LineGiua == 1))) {
                    turnRight();
                }
                if ((LinePhai == 1) || ((LinePhai == 1)&&(LineGiua == 1))) {
                    turnLeft();
                }
            } else {
                Stop();
                EPWM1_LoadDutyValue(30);
                EPWM2_LoadDutyValue(14);

                state = 1;
            }
        }
    }
}
