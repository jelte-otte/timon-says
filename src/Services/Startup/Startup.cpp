#include "Startup.h"
#include <Arduino.h>
#include "PlayWelcomeSoundAndAnimation/PlayWelcomeSoundAndAnimation.h"
#include "SetupPins/SetupPins.h"

void startup()
{
    Serial.begin(9600);
    setupPins();
    randomSeed(A0);
    playWelcomeSoundAndAnimation();
}