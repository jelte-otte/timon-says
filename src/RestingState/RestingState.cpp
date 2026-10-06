#include "RestingState.h"
#include <Arduino.h>
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
        if (pressedButton == 7)
        {
            activeItem = 0;
            switchLEDStateBasedOnActiveItem();
        }
        else if (pressedButton == 6)
        {
            activeItem = 1;
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
                delay(200);
                switchSettingsOnOff(LOW, false);
            }
        }
    }
    setAllLEDs(LOW);
    delay(400);
}

