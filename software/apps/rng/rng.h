#pragma once

#include "nrf.h"
#include <stdint.h>

// Initializes the RNG
// Enable bias correction
// Stops itself after generating a value
void rng_init(void);

// Get a random 8-bit value
// Waits until a value is ready
uint8_t rng_get8(void);

