#include "PlayWelcomeSoundAndAnimation.h"
#include <Arduino.h>
#include "../../Config/Config.h"
#include "../PlayToneForLED/PlayToneForLED.h"

void playWelcomeSoundAndAnimation()
{
    playBootSound();
    welcomeAnimation();
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

void welcomeAnimation()
{
    for (int i = 0; i < 19; i++)
    {
        unsigned long LED = random(8, 11);
        Serial.println(LED);
        digitalWrite(LED, HIGH);
        PlayToneForLED(LED);
        digitalWrite(LED, LOW);
        delay(250);
    }
}