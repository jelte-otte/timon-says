#include "SwitchState.h"
#include <Arduino.h>
#include "../../Config/Config.h"

bool isSwitchOn()
{
    return digitalRead(switchPin);
}

void switchSettingsOnOff(uint8_t LEDState, bool shouldBeOn)
{
    uint8_t originalLEDStateGreenLED = shouldMakeSound ? HIGH : LOW;
    uint8_t originalLEDStateYellowLED = oldPeopleMode ? HIGH : LOW;
    switch (activeItem)
    {
    case 0:
        digitalWrite(greenLED, LEDState);
        digitalWrite(yellowLED, originalLEDStateYellowLED);
        shouldMakeSound = shouldBeOn;
        break;
    case 1:
        digitalWrite(yellowLED, LEDState);
        digitalWrite(greenLED, originalLEDStateGreenLED);
        oldPeopleMode = shouldBeOn;
        break;
    default:
        activeItem = 0;
        digitalWrite(greenLED, LEDState);
        digitalWrite(yellowLED, originalLEDStateYellowLED);
        shouldMakeSound = shouldBeOn;
        break;
    }
}

void switchLEDStateBasedOnActiveItem()
{
    switch (activeItem)
    {
    case 0:
        digitalWrite(greenLED, LOW);
        delay(100);
        digitalWrite(greenLED, HIGH);
        delay(100);
        digitalWrite(greenLED, LOW);
        delay(100);
        digitalWrite(greenLED, HIGH);
        delay(100);
        break;
    case 1:
        digitalWrite(yellowLED, LOW);
        delay(100);
        digitalWrite(yellowLED, HIGH);
        delay(100);
        digitalWrite(yellowLED, LOW);
        delay(100);
        digitalWrite(yellowLED, HIGH);
        delay(100);
        break;
    default:
        activeItem = 0;
        digitalWrite(greenLED, LOW);
        delay(100);
        digitalWrite(greenLED, HIGH);
        delay(100);
        digitalWrite(greenLED, LOW);
        delay(100);
        digitalWrite(greenLED, HIGH);
        delay(100);
        break;
    }
}