#include "SwitchState.h"
#include <Arduino.h>
#include <EEPROM.h>
#include "../../Config/Config.h"

bool isSwitchOn()
{
    return digitalRead(switchPin);
}

void switchSettingsOnOff(uint8_t LEDState, bool shouldBeOn)
{
    uint8_t originalLEDStateGreenLED = shouldMakeSound ? HIGH : LOW;
    uint8_t originalLEDStateYellowLED = oldPeopleMode ? HIGH : LOW;
    activeItem = EEPROM.read(activeItemAddress);
    switch (activeItem)
    {
    case 0:
        digitalWrite(greenLED, LEDState);
        digitalWrite(yellowLED, originalLEDStateYellowLED);
        shouldMakeSound = shouldBeOn;
        EEPROM.update(shouldMakeSoundAddress, shouldMakeSound);
        break;
    case 1:
        digitalWrite(yellowLED, LEDState);
        digitalWrite(greenLED, originalLEDStateGreenLED);
        oldPeopleMode = shouldBeOn;
        EEPROM.update(oldPeopleModeAddress, oldPeopleMode);
        break;
    default:
        activeItem = 0;
        EEPROM.update(activeItemAddress, activeItem);
        digitalWrite(greenLED, LEDState);
        digitalWrite(yellowLED, originalLEDStateYellowLED);
        shouldMakeSound = shouldBeOn;
        EEPROM.update(shouldMakeSoundAddress, shouldMakeSound);
        break;
    }
}

void switchLEDStateBasedOnActiveItem()
{
    activeItem = EEPROM.read(activeItemAddress);
    switch (activeItem)
    {
    case 0:
        for (int i = 0; i < 2; i++)
        {
            digitalWrite(greenLED, LOW);
            delay(100);
            digitalWrite(greenLED, HIGH);
            delay(100);
        }
        break;
    case 1:
        for (int i = 0; i < 2; i++)
        {
            digitalWrite(yellowLED, LOW);
            delay(100);
            digitalWrite(yellowLED, HIGH);
            delay(100);
        }
        break;
    default:
        activeItem = 0;
        EEPROM.update(activeItemAddress, activeItem);
        for (int i = 0; i < 2; i++)
        {
            digitalWrite(greenLED, LOW);
            delay(100);
            digitalWrite(greenLED, HIGH);
            delay(100);
        }
        break;
    }
}