#include "src/Config/Config.h"
#include "src/Services/Setup/SetupGame.h"
#include "src/Services/ButtonState/ButtonState.h"
#include "src/Services/SwitchStatus/SwitchStatus.h"
#include "src/Services/SwitchLightState/SwitchLightState.h"
#include "src/Tests/LEDs/TurnOnAllLEDs.h"
#include "src/Tests/Buttons/CheckForButtonPress.h"
#include "src/Tests/Buzzer/MakeSound.h"
#include "src/Tests/Switch/CheckSwitchStatus.h"

bool sound = true;
bool insaneMode = false;
int activeItem = 0;

void setup()
{
    setupGame();
}

void loop()
{
    tests();
}

void menu()
{
    bool switchOn = switchStatus();
    if (buttonPressed(greenButton))
    {
        activeItem = 0;
        switchLightState(yellowLED, LOW);
        switchLightState(greenLED, HIGH);
        if (!switchOn && activeItem == 0)
        {
            sound = false;
            delay(200);
            switchLightState(greenLED, LOW);
        }
        else if (switchOn && activeItem == 0)
        {
            sound = true;
            delay(200);
            switchLightState(greenLED, HIGH);
        }
    }
    else if (buttonPressed(yellowButton))
    {
        activeItem = 1;
        switchLightState(yellowLED, HIGH);
        switchLightState(greenLED, LOW);
        if (!switchOn && activeItem == 1)
        {
            insaneMode = false;
            delay(200);
            switchLightState(yellowLED, LOW);
        }
        else if (switchOn && activeItem == 1)
        {
            insaneMode = true;
            delay(400);
            switchLightState(yellowLED, HIGH);
        }
    }
}

void tests()
{
    turnOnAllLEDs();
    // checkForButtonPress(greenButton);
    // checkForButtonPress(yellowButton);
    // checkForButtonPress(blueButton);
    // checkForButtonPress(redButton);
    // makeSound();
    // checkSwitchStatus();
}
