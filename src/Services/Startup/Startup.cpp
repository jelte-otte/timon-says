#include "Startup.h"
#include <Arduino.h>
#include "PlayWelcomeSoundAndAnimation.h"
#include "SetupPins.h"

void startup()
{
    setupPins();
    randomSeed(A0);
    playWelcomeSoundAndAnimation();
}