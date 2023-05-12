#include "KeyboardTsLcd.h"
#include "Keyboard_Ts.h"

#define INVERSION 3

KeyboardTsLcd::KeyboardTsLcd(unsigned char _ucColumn)
{
    pKeyboard = new Keyboard_Ts(_ucColumn);
    pLed = new Led_Lcd(_ucColumn);
    pKeyboardTsLcd = new Led_Lcd(3);
}

void KeyboardTsLcd::eRead(){
    uint8_t ui8LedInvert;
    switch (pKeyboard->eRead()) {
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

        if(ui8LedInvert != 4){
            pKeyboardTsLcd->On(INVERSION-ui8LedInvert);
            pLed->On(ui8LedInvert);
        }else{
            pKeyboardTsLcd->On(ui8LedInvert);
            pLed->On(ui8LedInvert);
        }
}
