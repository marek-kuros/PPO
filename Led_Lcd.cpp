#include "Led_Lcd.h"

#define X_SIZE_OF_BUTTON 80
#define Y_SIZE_OF_BUTTON 80
#define SIZE_OF_FRAME 1
#define STARTING_POINT 0
#define BUTTON_MULTIPY  80

Led_Lcd::Led_Lcd(uint8_t ui8ColumnIndexLed){
    ui8ColumnOffsetLed = ui8ColumnIndexLed;
    Init();
    Clear(LCD_COLOR_BLACK);
    SetFont(&Font24);
}

void Led_Lcd::On(uint8_t uIndexOfLed){
    for(uint8_t uButtonIndex = 0; uButtonIndex < 4; uButtonIndex++){           
        SetTextColor(uButtonIndex == uIndexOfLed ? LCD_COLOR_GREEN : LCD_COLOR_BLUE);
        FillRect(STARTING_POINT + (ui8ColumnOffsetLed - 1)*X_SIZE_OF_BUTTON, SIZE_OF_FRAME + uButtonIndex*BUTTON_MULTIPY, X_SIZE_OF_BUTTON, Y_SIZE_OF_BUTTON);
        SetTextColor(LCD_COLOR_GREEN);
        DrawRect(STARTING_POINT + (ui8ColumnOffsetLed - 1)*X_SIZE_OF_BUTTON, uButtonIndex*BUTTON_MULTIPY, X_SIZE_OF_BUTTON, Y_SIZE_OF_BUTTON);
        SetTextColor(LCD_COLOR_WHITE);
        SetBackColor(LCD_COLOR_RED);
        DisplayChar(STARTING_POINT + (ui8ColumnOffsetLed - 1)*X_SIZE_OF_BUTTON, SIZE_OF_FRAME + uButtonIndex*BUTTON_MULTIPY, '0' + uButtonIndex+1);
    }
}
