#ifndef KEYBOARDTSLCD
#define KEYBOARDTSLCD

#include "Keyboard_Ts.h"
#include "Led_Lcd.h"

class KeyboardTsLcd: public Keyboard_Ts, public Led_Lcd{
    private:
        Keyboard_Ts *pKeyboard;
        Led_Lcd *pLed;
        Led_Lcd *pKeyboardTsLcd;
    public:
        KeyboardTsLcd(unsigned char);
        void eRead();
};

#endif
