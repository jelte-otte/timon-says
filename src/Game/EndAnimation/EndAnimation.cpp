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
        PlayToneForLED(melody[i], 300);
        delay(300);
        digitalWrite(melody[i], LOW);
        delay(120);
    }

    for (uint8_t i = 0; i < 3; i++)
    {
        setAllLEDs(HIGH);
        PlayToneForLED(yellowLED, 350);
        delay(350);
        setAllLEDs(LOW);
        delay(250);
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
