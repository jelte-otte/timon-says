#include "ButtonState.h"
#include <Arduino.h>

bool buttonPressed(uint8_t button)
{
    bool isPressed = !digitalRead(button);
    if (isPressed){
        delay(100);
        bool isPressed = !digitalRead(button);
        if (isPressed){
            return true;
        }
    }
    return false;
}