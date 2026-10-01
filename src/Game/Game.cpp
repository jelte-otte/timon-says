#include "Game.h"
#include <Arduino.h>
#include "PatternLogic/PatternLogic.h"
#include "../Config/Config.h"
#include "../Services/CheckButtonState/CheckButtonState.h"

void playGame()
{
    int gameRound = 0;
    uint8_t pattern[maxRounds];
    generatePattern(pattern);
    bool hasWonGame = false;
    for (gameRound; gameRound < maxRounds; gameRound++)
    {
        showPattern(gameRound, pattern);
        if (gameRound == 0)
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
        Result result;
        for (int i = 0; i < gameRound; i++)
        {
            Serial.print("We are gaming in round ");
            Serial.println(gameRound);
            while (millis() - now < 20000)
            {            
                // Serial.print("We are now at buttonpress ");
                // Serial.println(i);
                result = checkPattern(i, pattern);
                if (result != Result::none)
                {
                    Serial.println("AMAI, we pressed a button");
                    break;
                }
            }
            if (result == Result::failed)
            {
                Serial.println("AWWW wrong button");
                break;
            }
            delay(200);
        }
        if (result == Result::failed)
        {
            Serial.println("Sorry buddy you lost.");
            hasWonGame = false;
            break;
        }
        Serial.println("Okayy, good job. You pressed the correct button. How impressive.");
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
