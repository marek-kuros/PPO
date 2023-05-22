#include "Keyboard_Ts.h"
#include <cmath>

#define X_SIZE_OF_BUTTON 80
#define Y_SIZE_OF_BUTTON 80
#define SIZE_OF_FRAME 1
#define STARTING_POINT 0
#define BUTTON_MULTIPY 80

Keyboard_Ts::Keyboard_Ts(uint8_t ui8ColumnIndexKeyboard){
    ui8ColumnOffsetKeyboard = ui8ColumnIndexKeyboard;
    Init(240, 320);
}

enum eButton Keyboard_Ts::eRead(){
    uint16_t X, Y, TouchDetected;
    eButton State, eSTATE[5] = {BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3, RELEASED};
    GetState(&tTS_TouchPoint);
    
    X = tTS_TouchPoint.X;
    Y = tTS_TouchPoint.Y;
    TouchDetected = tTS_TouchPoint.TouchDetected;

    if((TouchDetected) && (X >= X_SIZE_OF_BUTTON * (ui8ColumnOffsetKeyboard-1)) && (X < X_SIZE_OF_BUTTON * ui8ColumnOffsetKeyboard)){
        State = eSTATE[Y/Y_SIZE_OF_BUTTON];
    }else{
        State = RELEASED;
    }
    return State;
}
