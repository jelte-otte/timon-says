#include "SetupGame.h"
#include <Arduino.h>
#include "SetupPins/SetupPins.h"
#include "PlayBootSound/PlayBootSound.h"
#include "../SwitchLightState/SwitchLightState.h"
#include "../../Config/Config.h"

void setupGame(){
    setupPins();
    if (!development)
    {
        playBootSound();
    }
    randomSeed(A0);
    Serial.begin(9600);
}
