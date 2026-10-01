#include <Arduino.h>
#include "../../Config/Config.h"

void PlayToneForLED(int LED, int duration = 250)
{
    int sound;
    for (int i = 0; i < 4; i++)
    {
        if (LED == LEDButtonSoundMap[i].LEDPin)
        {
            sound = LEDButtonSoundMap[i].sound;
        }
    }
    tone(buzzerPin, sound, duration);
}