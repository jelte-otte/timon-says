#include "SwitchStatus.h"
#include <Arduino.h>
#include "../../Config/Config.h"

bool switchStatus()
{
    return digitalRead(switchPin);
}
