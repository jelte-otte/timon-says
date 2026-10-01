#include "Startup.h"
#include <Arduino.h>
#include "../../Config/Config.h"
#include "PlayWelcomeSoundAndAnimation/PlayWelcomeSoundAndAnimation.h"
#include "SetupPins/SetupPins.h"

void startup()
{
    Serial.begin(9600);
    setupPins();
    randomSeed(analogRead(A0));
    if (!development)
    {
        playWelcomeSoundAndAnimation();
    }
}