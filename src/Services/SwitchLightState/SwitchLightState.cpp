#include "SwitchLightState.h"
#include "../../Config/Config.h"
#include <Arduino.h>

void switchLightState(uint8_t lightPin, uint8_t state)
{
    digitalWrite(lightPin, state);
}