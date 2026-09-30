#include "Startup.h"
#include <Arduino.h>
#include "PlayWelcomeSoundAndAnimation.h"
#include "SetupPins.h"

void startup()
{
    Serial.begin(9600);
    setupPins();
    randomSeed(A0);
    playWelcomeSoundAndAnimation();
}