#include "KeyboardTsLcd.h"

KeyboardTsLcd::KeyboardTsLcd(unsigned char _ucColumn)
{
    pKeyboard = new Keyboard_Ts(_ucColumn);
    pLed = new Led_Lcd(_ucColumn);
}

void KeyboardTsLcd::eRead(){
    switch(pKeyboard->eRead()){
        case BUTTON_0:
            pLed->On(0);
            break;

        case BUTTON_1:
            pLed->On(1);
            break;

        case BUTTON_2:
            pLed->On(2);
            break;

        case BUTTON_3:
            pLed->On(3);
            break;
        default:
            pLed->On(4);
            break;
        }
}
