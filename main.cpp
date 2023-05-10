#include "mbed.h"
#include "KeyboardTsLcd.h"

#define INVERSION 3

int main()
{
    KeyboardTsLcd Keyboard(1), Keyboard_3(3);
    while(1){
        Keyboard.pLed->On(4);
        Keyboard_3.pLed->On(INVERSION - (Keyboard.pKeyboard->eRead()));
        wait(0.1);
    }
}
