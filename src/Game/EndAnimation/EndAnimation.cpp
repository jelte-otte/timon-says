#include "EndAnimation.h"
#include <Arduino.h>
#include "../../Config/Config.h"
#include "../../Services/TurnOnLED/TurnOnLED.h"
#include "../../Services/PlayToneForLED/PlayToneForLED.h"

void playWinAnimation()
{
    const uint8_t melody[] = {
        redLED, greenLED, blueLED, yellowLED,
        blueLED, yellowLED, blueLED, yellowLED
    };
    setAllLEDs(LOW);
    noTone(buzzerPin);

    for (uint8_t i = 0; i < sizeof(melody) / sizeof(melody[0]); i++)
    {
        digitalWrite(melody[i], HIGH);
        PlayToneForLED(melody[i], 120);
        digitalWrite(melody[i], LOW);
        delay(35);
    }

    for (uint8_t i = 0; i < 3; i++)
    {
        setAllLEDs(HIGH);
        PlayToneForLED(yellowLED, 150);
        setAllLEDs(LOW);
        delay(100);
    }
}

void playLoseAnimation()
{
    const uint8_t melody[] = {yellowLED, blueLED, greenLED, redLED};
    setAllLEDs(HIGH);
    noTone(buzzerPin);

    for (uint8_t i = 0; i < sizeof(melody) / sizeof(melody[0]); i++)
    {
        PlayToneForLED(melody[i], 300);
        digitalWrite(melody[i], LOW);
        delay(80);
    }
}
