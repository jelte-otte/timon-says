#include "SetupPins.h"
#include "../../Config/Config.h"

void setupPins()
{
    // Setup LEDs first
    for (int i = 0; i < 4; i++)
    {
        pinMode(LEDButtonSoundMap[i].LEDPin, OUTPUT);
    }

    // Then the buttons
    for (int i = 0; i < 4; i++)
    {
        pinMode(LEDButtonSoundMap[i].ButtonPin, INPUT_PULLUP);
    }

    // Then the buzzer
    pinMode(buzzerPin, OUTPUT);

    // And at last the switch
    pinMode(switchPin, INPUT_PULLUP);
}