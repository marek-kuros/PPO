#ifndef KEYBOARD_TS
#define KEYBOARD_TS
#include "TS_DISCO_F429ZI.h"


enum eButton{
    BUTTON_0,
    BUTTON_1,
    BUTTON_2,
    BUTTON_3,
    RELEASED
};

class Keyboard_Ts: public TS_DISCO_F429ZI{
    private:
        uint8_t ui8ColumnOffsetKeyboard;
        TS_StateTypeDef tTS_TouchPoint;
    public:
        Keyboard_Ts(uint8_t = 1);
        eButton eRead(void);      
};
#endif
