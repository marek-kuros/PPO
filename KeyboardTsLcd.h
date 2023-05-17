#ifndef KEYBOARDTSLCD
#define KEYBOARDTSLCD

#include "Keyboard_Ts.h"
#include "Led_Lcd.h"

class KeyboardTsLcd{
    public:
        Keyboard_Ts *pKeyboard;
        Led_Lcd *pLed;
        KeyboardTsLcd(unsigned char);
        void eRead();
};

#endif
