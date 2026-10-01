#include "PatternLogic.h"
#include <Arduino.h>
#include "../../Config/Config.h"
#include "../../Services/CheckButtonState/CheckButtonState.h"
#include "../../Services/TurnOnLED/TurnOnLED.h"

Result checkPattern(size_t previousPresses, uint8_t *pattern)
{

    int pressedButtonPin = whichButtonisPressed(buttons, 4);
    if (pressedButtonPin < 0)
    {
        return Result::none;
    }
    else
    {
        uint8_t LEDPin;
        for (int i = 0; i < 4; i++)
        {
            if (pressedButtonPin == LEDButtonSoundMap[i].ButtonPin)
            {
                LEDPin = LEDButtonSoundMap[i].LEDPin;
            }
        }
        Serial.print("We are checking the pressed button LED (");
        Serial.print(LEDPin);
        Serial.print(") against ");
        Serial.println(pattern[previousPresses]);
        if (LEDPin != pattern[previousPresses])
        {
            return Result::failed;
        }
        else
        {
            return Result::succes;
        }
    }
}

// Below this point are the small helper functions.
// These are not in seperate files due to their small size.

void showPattern(int round, uint8_t *pattern)
{
    for (int i = 0; i < round; i++)
    {
        turnOnLED(pattern[i], 500);
    }
}

void generatePattern(uint8_t *pattern)
{
    Serial.print("Pattern is: [");
    for (int i = 0; i < maxRounds; i++)
    {
        pattern[i] = random(8, 12);
        Serial.print(pattern[i]);
        Serial.print(",");
    }
    Serial.println("]");
}