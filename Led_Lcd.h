#ifndef LED_LCD
#define LED_LCD
#include "LCD_DISCO_F429ZI.h"

class Led_Lcd: public LCD_DISCO_F429ZI{
    private:
        uint8_t ui8ColumnOffsetLed;
        void Draw(uint8_t, uint32_t);
    public:
        Led_Lcd(uint8_t = 1);
        void On(uint8_t);
};
#endif
