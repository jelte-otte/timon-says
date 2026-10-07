#include "RestingState.h"
#include <Arduino.h>
#include <EEPROM.h>
#include "SwitchState/SwitchState.h"
#include "../Config/Config.h"
#include "../Services/CheckButtonState/CheckButtonState.h"
#include "../Services/TurnOnLED/TurnOnLED.h"

void restingState()
{

    int pressedButton = -1;
    while (pressedButton != 12)
    {
        pressedButton = whichButtonisPressed(buttons, 4);
        if (pressedButton == 7 && activeItem != 0)
        {
            activeItem = 0;
            EEPROM.update(activeItemAddress, activeItem);
            switchLEDStateBasedOnActiveItem();
        }
        else if (pressedButton == 6 && activeItem != 1)
        {
            activeItem = 1;
            EEPROM.update(activeItemAddress, activeItem);
            switchLEDStateBasedOnActiveItem();
        }
        pressedButton = whichButtonisPressed(buttons, 4);
        if (pressedButton < 0)
        {
            if (isSwitchOn())
            {
                switchSettingsOnOff(HIGH, true);
            }
            else
            {
                switchSettingsOnOff(LOW, false);
            }
        }
    }
    setAllLEDs(LOW);
    delay(400);
}
