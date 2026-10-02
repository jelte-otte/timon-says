#pragma once
#include <stdint.h>

struct LEDsButtonsSoundsStruct
{
    uint8_t LEDPin;
    uint8_t ButtonPin;
    unsigned int sound;
};

// BEGIN GENERATED DECLARATIONS
extern const bool development;
extern bool oldPeopleMode;
extern bool sound;
extern unsigned int activeItem;
extern const unsigned int maxRounds;
extern const uint8_t blueLED;
extern const uint8_t redLED;
extern const uint8_t greenLED;
extern const uint8_t yellowLED;
extern const uint8_t blueButton;
extern const uint8_t redButton;
extern const uint8_t greenButton;
extern const uint8_t yellowButton;
extern const unsigned int redLEDSound;
extern const unsigned int greenLEDSound;
extern const unsigned int blueLEDSound;
extern const unsigned int yellowLEDSound;
extern const LEDsButtonsSoundsStruct LEDButtonSoundMap[];
extern uint8_t buttons[];
extern const uint8_t buzzerPin;
extern const uint8_t switchPin;

enum class Result{
    none,
    succes,
    failed
};
// END GENERATED DECLARATIONS
