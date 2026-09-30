#include "CheckForButtonPress.h"
#include <Arduino.h>

void checkForButtonPress(uint8_t button)
{

    bool isPressed = digitalRead(button);
    if (!isPressed)
    {
        delay(100);
        bool isStillPressed = digitalRead(button);
        if (!isStillPressed)
        {
            Serial.print("Button ");
            Serial.print(button);
            Serial.println(" is Pressed");
        }
    }
}