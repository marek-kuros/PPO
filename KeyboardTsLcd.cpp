#include "KeyboardTsLcd.h"
#include "Keyboard_Ts.h"

KeyboardTsLcd::KeyboardTsLcd(unsigned char _ucColumn)
{
    pKeyboard = new Keyboard_Ts(_ucColumn);
    pLed = new Led_Lcd(_ucColumn);
}

enum eButton KeyboardTsLcd::eRead(){
    switch (pKeyboard->eRead()){
        case BUTTON_0:
            pLed->On(0);
            return BUTTON_0;
            break;

        case BUTTON_1:
            pLed->On(1);
            return BUTTON_1;
            break;

        case BUTTON_2:
            pLed->On(2);
            return BUTTON_2;
            break;

        case BUTTON_3:
            pLed->On(3);
            return BUTTON_3;
            break;
        case RELEASED:
            pLed->On(4);
            return RELEASED;
            break;

        default:
            break;
        }
}
