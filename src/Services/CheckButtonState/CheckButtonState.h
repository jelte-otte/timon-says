#pragma once
#include <stddef.h>
#include <stdint.h>

// BEGIN GENERATED DECLARATIONS
bool isButtonPressed(uint8_t buttonPin);
bool areButtonsPressed(const uint8_t *buttonPins, unsigned int buttonCount);
int whichButtonisPressed(const uint8_t *buttonPins, unsigned int buttonCount);
// END GENERATED DECLARATIONS
