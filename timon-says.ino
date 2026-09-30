#include "src/Services/Startup/Startup.h"
#include "src/Tests/LEDs/TurnOnAllLEDs.h"
#include "src/Game/Game.h"

void setup()
{
    startup();
}

void loop()
{
    playGame();
    Serial.println("Done");
    delay(1000000);
}   