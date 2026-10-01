#include "PlayWelcomeSoundAndAnimation.h"
#include <Arduino.h>
#include "../../../Config/Config.h"
#include "../../PlayToneForLED/PlayToneForLED.h"

void playWelcomeSoundAndAnimation()
{
    playBootSound();
    playWelcomeAnimation();
}

// Made by chatgpt
void playBootSound()
{
    const unsigned int notes[] = {523, 659, 784, 1047};
    const unsigned int lengths[] = {100, 100, 100, 220};

    for (uint8_t i = 0; i < 4; i++)
    {
        tone(buzzerPin, notes[i], lengths[i]);
        delay(lengths[i] + 35);
    }

    noTone(buzzerPin);
}
// until here

// Also made by chatgpt
void playWelcomeAnimation()
{
    // Rise, fall, then build up to a cheerful finish.
    const uint8_t melody[] = {
        redLED, greenLED, blueLED, yellowLED,
        blueLED, greenLED, redLED,
        greenLED, blueLED, greenLED, blueLED,
        yellowLED, blueLED, yellowLED,
    };
    const unsigned int lengths[] = {
        120, 120, 120, 240,
        120, 120, 240,
        120, 120, 120, 120,
        240, 120, 240,
    };

    for (uint8_t i = 0; i < 4; i++)
    {
        digitalWrite(LEDButtonSoundMap[i].LEDPin, LOW);
    }

    for (uint8_t i = 0; i < sizeof(melody) / sizeof(melody[0]); i++)
    {
        digitalWrite(melody[i], HIGH);
        PlayToneForLED(melody[i]);
        delay(lengths[i]);
        noTone(buzzerPin);
        digitalWrite(melody[i], LOW);
        delay(35);
    }

    // Light every LED together on the final high note.
    for (uint8_t i = 0; i < 4; i++)
    {
        digitalWrite(LEDButtonSoundMap[i].LEDPin, HIGH);
    }
    PlayToneForLED(yellowLED);
    delay(240);
    noTone(buzzerPin);

    for (uint8_t i = 0; i < 4; i++)
    {
        digitalWrite(LEDButtonSoundMap[i].LEDPin, LOW);
    }
}
// until here