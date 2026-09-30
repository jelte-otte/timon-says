#include "Startup.h"
#include <Arduino.h>
#include "PlayWelcomeSoundAndAnimation.h"

void startup()
{
    randomSeed(A0);
    playWelcomeSoundAndAnimation();
}