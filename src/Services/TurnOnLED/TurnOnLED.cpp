#include "TurnOnLED.h"
#include <Arduino.h>
#include "../PlayToneForLED/PlayToneForLED.h"
#include "../../Config/Config.h"

void turnOnLED(uint8_t LEDPin, unsigned int timeout = 250)
{
    digitalWrite(LEDPin, HIGH);
    PlayToneForLED(LEDPin);
    delay(timeout);
    digitalWrite(LEDPin, LOW);
    delay(timeout);
}

void turnOnLEDForButton(uint8_t buttonPin)
{
    uint8_t LEDPin;
    for (int i = 0; i < 4; i++)
    {
        if (buttonPin == LEDButtonSoundMap[i].ButtonPin)
        {
            LEDPin = LEDButtonSoundMap[i].LEDPin;
        }
    }
    turnOnLED(LEDPin);
}