#include "Config.h"

// Game settings
// Jonathan mode is the easier mode
const bool development = true;
const bool jonathanMode = false;
const bool sound = true;
unsigned int activemode = 0;

// LEDs
const uint8_t blueLED = 10;
const uint8_t redLED = 11;
const uint8_t greenLED = 9;
const uint8_t yellowLED = 8;

// Buttons
const uint8_t blueButton = 12;
const uint8_t redButton = 13;
const uint8_t greenButton = 7;
const uint8_t yellowButton = 6;

// LED sounds
// Made by chatgpt
const unsigned int redLEDSound = 440;
const unsigned int greenLEDSound = 554;
const unsigned int blueLEDSound = 659;
const unsigned int yellowLEDSound = 880;
// until here

const LEDsButtonsSoundsStruct LEDButtonSoundMap[] = {
    {blueLED, blueButton, blueLEDSound},
    {redLED, redButton, redLEDSound},
    {greenLED, greenButton, greenLEDSound},
    {yellowLED, yellowButton, yellowLEDSound},
};

// Buzzer
const uint8_t buzzerPin = 5;

// Switch
const uint8_t switchPin = 4;
