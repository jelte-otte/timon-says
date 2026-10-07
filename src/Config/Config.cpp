#include "Config.h"

// Game settings
// oldPeopleMode is the easier mode
// development turns off the intro animation and sound (that last one still has to be implemented (01-10-2026))
// activeItem is the active menu item, where 0 is the sound setting and 1 is the mode setting.
const bool development = false;
bool oldPeopleMode = false;
bool shouldMakeSound = true;
unsigned int activeItem = 0;
const unsigned int maxRounds = 10;

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

// Seperate button array for easier acces
uint8_t buttons[] = {blueButton, redButton, greenButton, yellowButton};


// Buzzer
const uint8_t buzzerPin = 5;

// Switch
const uint8_t switchPin = 4;
