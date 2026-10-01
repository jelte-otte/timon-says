#include "Game.h"
#include <Arduino.h>
#include "PatternLogic/PatternLogic.h"
#include "../Config/Config.h"
#include "../Services/CheckButtonState/CheckButtonState.h"
#include "../Services/TurnOnLED/TurnOnLED.h"

void playGame()
{
    int gameRound = 1;
    uint8_t pattern[maxRounds];
    generatePattern(pattern);
    bool hasWonGame = false;
    for (gameRound; gameRound < maxRounds; gameRound++)
    {
        showPattern(gameRound, pattern);
        if (gameRound == 1)
        {
            bool allPressed = areButtonsPressed(buttons, 4);
            if (allPressed)
            {
                // Print that they are all pressed, implement further logic later.
                Serial.println("This should start resting state, but that is not implemented yet");
            }
            Serial.println("gameRound = 0");
        }
        unsigned long now = millis();
        bool success = false;
        for (int i = 0; i < gameRound; i++)
        {
            Serial.print("We are gaming in round ");
            Serial.println(gameRound);
            while (millis() - now < 20000)
            {
                success = false;
                int pressedButtonPin = whichButtonisPressed(buttons, 4);
                if (pressedButtonPin >= 0)
                {
                    turnOnLEDForButton(pressedButtonPin);
                    success = checkPattern(pressedButtonPin, i, pattern);
                        Serial.println("AMAI, we pressed a button");
                        break;
                }
            }
            if (!success)
            {
                Serial.println("AWWW wrong button");
                break;
            }
        }
        if (!success)
        {
            Serial.println("Sorry buddy you lost.");
            hasWonGame = false;
            break;
        }
        Serial.println("Okayy, good job. You pressed the correct buttons. How impressive...");
        hasWonGame = true;
    }
    if (hasWonGame)
    {
        Serial.println("hurray!");
    }
    else
    {
        Serial.println(":sad:");
    }
}
