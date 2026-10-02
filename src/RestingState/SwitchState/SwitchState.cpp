#include "SwitchState.h"
#include  <Arduino.h>
#include "../../Config/Config.h"

bool isSwitchOn()
{
    return digitalRead(switchPin);
}

void switchSettingsOnOff(uint8_t LEDState, bool shouldBeOn)
{
    switch (activeItem)
    {
    case 0:
        digitalWrite(greenLED, LEDState);
        digitalWrite(yellowLED, LOW);
        sound = shouldBeOn;
        break;
    case 1:
        digitalWrite(yellowLED, LEDState);
        digitalWrite(greenLED, LOW);
        oldPeopleMode = shouldBeOn;
        break;
    default:
        activeItem = 0;
        digitalWrite(greenLED, LEDState);
        digitalWrite(yellowLED, LOW);
        sound = shouldBeOn;
        break;
    }
}

void switchLEDStateBasedOnActiveItem()
{
    switch (activeItem)
    {
    case 0:
        digitalWrite(greenLED, HIGH);
        digitalWrite(yellowLED, LOW);
        break;
    case 1:
        digitalWrite(yellowLED, HIGH);
        digitalWrite(greenLED, LOW);
        break;
    default:
        activeItem = 0;
        digitalWrite(greenLED, HIGH);
        digitalWrite(yellowLED, LOW);
        break;
    }
}