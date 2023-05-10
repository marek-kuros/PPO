#ifndef LED_LCD
#define LED_LCD
#include "LCD_DISCO_F429ZI.h"
#include <cstdint>

class Led_Lcd: public LCD_DISCO_F429ZI{
    private:
        uint8_t ui8ColumnOffsetLed;
    public:
        Led_Lcd(uint8_t = 1);
        void On(uint8_t);
};
#endif
