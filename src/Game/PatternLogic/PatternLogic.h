#pragma once
#include <stddef.h>
#include <stdint.h>
#include "../../Config/Config.h"

// BEGIN GENERATED DECLARATIONS
Result checkPattern(size_t previousPresses, uint8_t *pattern);
void showPattern(int round, uint8_t *pattern);
void generatePattern(uint8_t *pattern);
// END GENERATED DECLARATIONS
