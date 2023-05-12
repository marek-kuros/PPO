#include "mbed.h"
#include "KeyboardTsLcd.h"
#include "Led_Lcd.h"
#include "Keyboard_Ts.h"
#include "stm32f429i_discovery_lcd.h"

int main()
{
    KeyboardTsLcd Keyboard(1);
    while(1){
        Keyboard.eRead();
        wait(0.1);
    }
}
