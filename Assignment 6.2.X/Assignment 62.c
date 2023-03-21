#include "16F1509 config.h"
#include <xc.h>
#include "lcd.h"
#include <string.h>
#define _XTAL_FREQ 1000000
void main(void) {
    LCD_Initialize();
    LCDPutStr2("PIC16F1509 MCU",1,0);
    LCDPutStr3("23:59:00",1);
    
    while(1);
    return;
}
