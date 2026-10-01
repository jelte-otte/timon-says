#include "TurnOnLED.h"
#include <Arduino.h>
#include "../PlayToneForLED/PlayToneForLED.h"

void turnOnLED(uint8_t LEDPin, unsigned int timeout = 250)
{
    digitalWrite(LEDPin, HIGH);
    PlayToneForLED(LEDPin);
    delay(timeout - 250);
    digitalWrite(LEDPin, LOW);
    delay(timeout);
}