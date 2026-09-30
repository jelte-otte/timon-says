#include "src/Services/Startup/Startup.h"
#include "src/Tests/LEDs/TurnOnAllLEDs.h"

void setup() {
    startup();
    Serial.begin(9600);
}

void loop() {
    // Add your main code here, to run repeatedly
}