#include "KeyboardTsLcd.h"
#include "Keyboard_Ts.h"

KeyboardTsLcd::KeyboardTsLcd(unsigned char _ucColumn)
{
    pKeyboard = new Keyboard_Ts(_ucColumn);
    pLed = new Led_Lcd(_ucColumn);
}

void KeyboardTsLcd::eRead(){
    uint8_t ui8LedInvert;
    switch (pKeyboard->eRead()){
        case BUTTON_0:
            ui8LedInvert = 0;
            break;

        case BUTTON_1:
            ui8LedInvert = 1;
            break;

        case BUTTON_2:
            ui8LedInvert = 2;
            break;

        case BUTTON_3:
            ui8LedInvert = 3;
            break;
        case RELEASED:
            ui8LedInvert = 4;
            break;

        default:
            ui8LedInvert = 4;
            break;
        }
        pLed->On(ui8LedInvert);
}
