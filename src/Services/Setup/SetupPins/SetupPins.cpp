#include "SetupPins.h"
#include <Arduino.h>
#include "../../../Config/Config.h"

void setupPins(){
    // Setup LEDs
    for(int i = 0; i < 4; i++){
        pinMode(LEDs[i],OUTPUT);
    }

    // Setup Buttons
    for(int i = 0; i < 4; i++){
        pinMode(Buttons[i],INPUT_PULLUP);
    }

    // Setup switch
    pinMode(switchPin, INPUT_PULLUP);
}
