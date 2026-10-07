#include "CheckButtonState.h"
#include <Arduino.h>

bool isButtonPressed(uint8_t buttonPin){
    bool isPressed = digitalRead(buttonPin);
    if (isPressed){
        delay(100);
        bool IsStillPressed = !digitalRead(buttonPin);
        if (IsStillPressed){
            return true;
        }
    }
    return false;
}

int whichButtonisPressed(const uint8_t *buttonPins, unsigned int buttonCount){
    if (buttonCount == 0 || buttonPins == nullptr){
        return -1;
    }

    for (unsigned int i = 0; i < buttonCount; i++){
        if (digitalRead(buttonPins[i]) == LOW){
            return buttonPins[i];
        }
    }

    for (unsigned int i = 0; i < buttonCount; i++){
        if (digitalRead(buttonPins[i]) == LOW){
            return buttonPins[i];
        }
    }

    return -1;
}
