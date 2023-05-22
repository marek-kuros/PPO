#ifndef KEYBOARDTSLCD
#define KEYBOARDTSLCD

#include "Keyboard_Ts.h"
#include "Led_Lcd.h"

class KeyboardTsLcd{
    private:
        Keyboard_Ts *pKeyboard;
        Led_Lcd *pLed;
    public:
        KeyboardTsLcd(unsigned char);
        eButton eRead();
};

#endif
