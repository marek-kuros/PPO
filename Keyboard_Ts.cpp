#include "Keyboard_Ts.h"
#include "stm32f429i_discovery_lcd.h"

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
    eButton STATE;
    GetState(&tTS_TouchPoint);
    for(uint8_t ui8ButtonIndex = BUTTON_0; ui8ButtonIndex != RELEASED; ui8ButtonIndex++){
        if(tTS_TouchPoint.Y < Y_SIZE_OF_BUTTON + ui8ButtonIndex*Y_SIZE_OF_BUTTON && 
        tTS_TouchPoint.Y > ui8ButtonIndex*Y_SIZE_OF_BUTTON && 
        tTS_TouchPoint.X < ui8ColumnOffsetKeyboard*X_SIZE_OF_BUTTON && 
        tTS_TouchPoint.X >= ui8ColumnOffsetKeyboard*X_SIZE_OF_BUTTON - X_SIZE_OF_BUTTON){
            STATE = static_cast<eButton>(ui8ButtonIndex);
            break;
        }else{
            STATE = RELEASED;
        }
    }
    tTS_TouchPoint.Y = 400;
    return STATE;
}

// enum eButton Keyboard_Ts::eRead(){
//     GetState(&tTS_TouchPoint);
//     if(tTS_TouchPoint.Y < Y_SIZE_OF_BUTTON + 0*Y_SIZE_OF_BUTTON && 
//     tTS_TouchPoint.Y > 0*Y_SIZE_OF_BUTTON && tTS_TouchPoint.X < X_SIZE_OF_BUTTON){
//         return BUTTON_0;
//     }
//     else if(tTS_TouchPoint.Y < Y_SIZE_OF_BUTTON + 1*Y_SIZE_OF_BUTTON && 
//     tTS_TouchPoint.Y > 1*Y_SIZE_OF_BUTTON && tTS_TouchPoint.X < X_SIZE_OF_BUTTON){
//         return BUTTON_1;
//     }
//     else if(tTS_TouchPoint.Y < Y_SIZE_OF_BUTTON + 2*Y_SIZE_OF_BUTTON && 
//     tTS_TouchPoint.Y > 2*Y_SIZE_OF_BUTTON && tTS_TouchPoint.X < X_SIZE_OF_BUTTON){
//         return BUTTON_2;
//     }
//     else if(tTS_TouchPoint.Y < Y_SIZE_OF_BUTTON + 3*Y_SIZE_OF_BUTTON && 
//     tTS_TouchPoint.Y > 3*Y_SIZE_OF_BUTTON && tTS_TouchPoint.X < X_SIZE_OF_BUTTON){
//         return BUTTON_3;
//     }
//     else{
//         return RELEASED;
//     }
// }
