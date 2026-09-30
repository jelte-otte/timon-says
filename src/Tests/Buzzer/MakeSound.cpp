#include "MakeSound.h"
#include <Arduino.h>

void makeSound(){
    uint8_t buzzerPin = 5;
    tone(buzzerPin, 1000); // Send 1KHz sound signal...
    delay(1000);         // ...for 1 sec
    noTone(buzzerPin);     // Stop sound...
    delay(1000);         // ...for 1sec
}