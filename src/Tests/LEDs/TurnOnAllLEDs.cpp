#include "TurnOnAllLEDs.h"
#include <Arduino.h>

void turnOnAllLEDs(){
    uint8_t LEDs[] = {8,9,10,11};

    for(int i = 0; i < 4; i++){
        pinMode(LEDs[i],OUTPUT);
        digitalWrite(LEDs[i],HIGH);
    } 
}