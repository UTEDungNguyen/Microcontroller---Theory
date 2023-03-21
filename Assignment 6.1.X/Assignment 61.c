#include "16F1509_config.h"
#include <xc.h>
#include "lcd.h"
#define _XTAL_FREQ 1000000
void main(void) {
    LCD_Initialize();
    LCDGoto(1,0);
    LCDPutStr("PIC16F1509 MCU");
    LCDGoto(4,1);
    LCDPutStr("23:59:00");
    while(1);
    return;
}
