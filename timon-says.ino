#include "src/Services/Startup/Startup.h"
#include "src/Tests/LEDs/TurnOnAllLEDs.h"
#include "src/Game/Game.h"
#include "src/RestingState/RestingState.h"

void setup()
{
    startup();
}

void loop()
{
    // playGame();
    restingState();
    Serial.println("playing game");
}   