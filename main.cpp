#include "KeyboardTsLcd.h"

int main()
{
    KeyboardTsLcd Keyboard_1(1), Keyboard_2(3);
    while(1){
        uint32_t Invert;
        Keyboard_1.eRead();
        Invert = Keyboard_1.pKeyboard->eRead();
        if(Invert == RELEASED){
            Keyboard_2.pLed->On(Invert);
        }else{
            Keyboard_2.pLed->On(3-Invert);
        }
        wait(0.1);
    }
}
