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
        Device            :  PIC16F1509
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
#include <stdio.h>
char str[50]; 
int i;
int count = 0 ;
/*
                         Main application
 */

void putch(char data)
{while(!EUSART_is_tx_ready());
EUSART_Write(data);
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

    while (1)
    {   
        if (count==0){
        for (i=0;i<10;i++){ 
        while ((EUSART_is_rx_ready()==0)) test();
        str[i]=EUSART_Read();
        if (str[i]=='#') i=11;}}
        if ((str[0]=='O')&&(str[1]=='N')&&(str[2]=='0')&&(str[3]=='1')&&(str[4]=='#')){
        LATCbits.LATC0 =1 ;
        st_1=0 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='N')&&(str[2]=='0')&&(str[3]=='2')&&(str[4]=='#')){
        LATCbits.LATC1 =1 ;
        st_2=0 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='N')&&(str[2]=='0')&&(str[3]=='3')&&(str[4]=='#')){
        LATCbits.LATC2 =1 ;
        st_3=0 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='N')&&(str[2]=='0')&&(str[3]=='4')&&(str[4]=='#')){
        LATCbits.LATC3 =1 ;
        st_4=0 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='N')&&(str[2]=='0')&&(str[3]=='5')&&(str[4]=='#')){
        LATCbits.LATC4 =1 ;
        st_5=0 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='N')&&(str[2]=='0')&&(str[3]=='6')&&(str[4]=='#')){
        LATCbits.LATC5 =1 ;
        st_6=0 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='N')&&(str[2]=='0')&&(str[3]=='7')&&(str[4]=='#')){
        LATCbits.LATC6 =1 ;
        st_7=0 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='N')&&(str[2]=='0')&&(str[3]=='8')&&(str[4]=='#')){
        LATCbits.LATC7 =1 ;
        st_8=0 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='N')&&(str[2]=='*')&&(str[3]=='#')){
        LATCbits.LATC0 =1 ;
        LATCbits.LATC1 =1 ;
        LATCbits.LATC2 =1 ;
        LATCbits.LATC3 =1 ;
        LATCbits.LATC4 =1 ;
        LATCbits.LATC5 =1 ;
        LATCbits.LATC6 =1 ;
        LATCbits.LATC7 =1 ;
        st_8=0 ;
        st_1=0 ;
        st_2=0 ;
        st_3=0 ;
        st_4=0 ;
        st_5=0 ;
        st_6=0 ;
        st_7=0 ;
        count=0;}
   ////////////////////////////////////////////////////////////////////////////////////////////////////
                                        //OFF//
    
        if ((str[0]=='O')&&(str[1]=='F')&&(str[2]=='F')&&(str[3]=='0')&&(str[4]=='1')&&(str[5]=='#')){
        LATCbits.LATC0 =0 ;
        st_1=2 ;
        count=0;
        }
        if ((str[0]=='O')&&(str[1]=='F')&&(str[2]=='F')&&(str[3]=='0')&&(str[4]=='2')&&(str[5]=='#')){
        LATCbits.LATC1 =0 ;
        st_2=2 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='F')&&(str[2]=='F')&&(str[3]=='0')&&(str[4]=='3')&&(str[5]=='#')){
        LATCbits.LATC2 =0 ;
        st_3=2 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='F')&&(str[2]=='F')&&(str[3]=='0')&&(str[4]=='4')&&(str[5]=='#')){
        LATCbits.LATC3 =0 ;
        st_4=2 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='F')&&(str[2]=='F')&&(str[3]=='0')&&(str[4]=='5')&&(str[5]=='#')){
        LATCbits.LATC4 =0 ;
        st_5=2 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='F')&&(str[2]=='F')&&(str[3]=='0')&&(str[4]=='6')&&(str[5]=='#')){
        LATCbits.LATC5 =0 ;
        st_6=2 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='F')&&(str[2]=='F')&&(str[3]=='0')&&(str[4]=='7')&&(str[5]=='#')){
        LATCbits.LATC6 =0 ;
        st_7=2 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='F')&&(str[2]=='F')&&(str[3]=='0')&&(str[4]=='8')&&(str[5]=='#')){
        LATCbits.LATC7 =0 ;
        st_8=2 ;
        count=0;}
        if ((str[0]=='O')&&(str[1]=='F')&&(str[2]=='F')&&(str[3]=='*')&&(str[4]=='#')){
        st_1=2 ;
        st_2=2 ;
        st_3=2 ;
        st_4=2 ;
        st_5=2 ;
        st_6=2 ;
        st_7=2 ;
        st_8=2 ;
        LATC =0 ;
        count=0;}
 ////////////////////////////////////////////////////////////////////////////////////////////////////////
                                             /////BLINK///////
    while ((str[0]=='B')&&(str[1]=='L')&&(str[2]=='I')&&(str[3]=='N')&&(str[4]=='K')&&(str[5]=='0')&&(str[6]=='1')&&(str[7]=='#')){
        st_1=1 ;
        count=1;
        for (i=0;i<10;i++){ 
        while ((EUSART_is_rx_ready()==0)){
        test();}
        str[i]=EUSART_Read();
        if (str[i]=='#') i=11;}
        }
    while ((str[0]=='B')&&(str[1]=='L')&&(str[2]=='I')&&(str[3]=='N')&&(str[4]=='K')&&(str[5]=='0')&&(str[6]=='2')&&(str[7]=='#')){
        count=1;
        st_2=1 ;
        for (i=0;i<10;i++){ 
        while ((EUSART_is_rx_ready()==0)){
        test();}
        str[i]=EUSART_Read();
        if (str[i]=='#') i=11;}
        }
    while ((str[0]=='B')&&(str[1]=='L')&&(str[2]=='I')&&(str[3]=='N')&&(str[4]=='K')&&(str[5]=='0')&&(str[6]=='3')&&(str[7]=='#')){
        count=1;
        st_3=1 ;
        for (i=0;i<10;i++){ 
        while ((EUSART_is_rx_ready()==0)){
        test();}
        str[i]=EUSART_Read();
        if (str[i]=='#') i=11;}
        }
    while ((str[0]=='B')&&(str[1]=='L')&&(str[2]=='I')&&(str[3]=='N')&&(str[4]=='K')&&(str[5]=='0')&&(str[6]=='4')&&(str[7]=='#')){
        count=1;
        st_4=1 ;
        for (i=0;i<10;i++){ 
        while ((EUSART_is_rx_ready()==0)){
        test();}
        str[i]=EUSART_Read();
        if (str[i]=='#') i=11;}}
    while ((str[0]=='B')&&(str[1]=='L')&&(str[2]=='I')&&(str[3]=='N')&&(str[4]=='K')&&(str[5]=='0')&&(str[6]=='5')&&(str[7]=='#')){
        count=1;
        st_5=1 ;
        for (i=0;i<10;i++){ 
        while ((EUSART_is_rx_ready()==0)){
        test();}
        str[i]=EUSART_Read();
        if (str[i]=='#') i=11;}}
    while ((str[0]=='B')&&(str[1]=='L')&&(str[2]=='I')&&(str[3]=='N')&&(str[4]=='K')&&(str[5]=='0')&&(str[6]=='6')&&(str[7]=='#')){
        count=1;
        st_6=1 ;
        for (i=0;i<10;i++){ 
        while ((EUSART_is_rx_ready()==0)){
        test();}
        str[i]=EUSART_Read();
        if (str[i]=='#') i=11;};}
    while ((str[0]=='B')&&(str[1]=='L')&&(str[2]=='I')&&(str[3]=='N')&&(str[4]=='K')&&(str[5]=='0')&&(str[6]=='7')&&(str[7]=='#')){
        count=1;
        st_7=1 ;
        for (i=0;i<10;i++){ 
        while ((EUSART_is_rx_ready()==0)){
        test();}
        str[i]=EUSART_Read();
        if (str[i]=='#') i=11;}}
    while ((str[0]=='B')&&(str[1]=='L')&&(str[2]=='I')&&(str[3]=='N')&&(str[4]=='K')&&(str[5]=='0')&&(str[6]=='8')&&(str[7]=='#')){
        count=1;
        st_8=1 ;
        for (i=0;i<10;i++){ 
        while ((EUSART_is_rx_ready()==0)){
        test();}
        str[i]=EUSART_Read();
        if (str[i]=='#') i=11;}}
    while ((str[0]=='B')&&(str[1]=='L')&&(str[2]=='I')&&(str[3]=='N')&&(str[4]=='K')&&(str[5]=='*')&&(str[6]=='#')){
        count=1;
        st_1=1 ;
        st_2=1 ;
        st_3=1 ;
        st_4=1 ;
        st_5=1 ;
        st_6=1 ;
        st_7=1 ;
        st_8=1 ;
        for (i=0;i<10;i++){ 
        while ((EUSART_is_rx_ready()==0)){
        test();}
        str[i]=EUSART_Read();
        if (str[i]=='#') i=11;}}
    
        // Add your application code
    }
}
/**
 End of File
*/