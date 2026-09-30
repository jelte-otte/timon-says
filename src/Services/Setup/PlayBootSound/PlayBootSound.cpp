#include "PlayBootSound.h"
#include <Arduino.h>
#include "../../../Config/Config.h"

// Made by Chatgpt
// Checked by Dhr. I.J.C. Otte
void playBootSound() {
  const unsigned int notes[] = {523, 659, 784, 1047};
  const unsigned int lengths[] = {100, 100, 100, 220};

  for (uint8_t i = 0; i < 4; i++) {
    tone(buzzerPin, notes[i], lengths[i]);
    delay(lengths[i] + 35);
  }

  noTone(buzzerPin);
}
