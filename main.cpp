#include "KeyboardTsLcd.h"
#include "Keyboard_Ts.h"
#include "Led_Lcd.h"

int main()
{
    Led_Lcd Led(3);
    KeyboardTsLcd Keyboard(1);
    while(1){  
        Keyboard.eRead();
        switch (Keyboard.eRead()){
            case BUTTON_0:
                Led.On(3);
                break;

            case BUTTON_1:
                Led.On(2);
                break;

            case BUTTON_2:
                Led.On(1);
                break;

            case BUTTON_3:
                Led.On(0);
                break;
            case RELEASED:
                Led.On(4);
                break;

            default:
                break;
            }
    }
}
