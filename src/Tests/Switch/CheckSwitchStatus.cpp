#include "CheckSwitchStatus.h"
#include <Arduino.h>
#include "../../Config/Config.h"

void checkSwitchStatus()
{
    uint8_t switchPin = 4;
    bool isStillPressed = digitalRead(switchPin);
    if (!isStillPressed)
    {
        Serial.println("Switch is turned on");
    }
}
