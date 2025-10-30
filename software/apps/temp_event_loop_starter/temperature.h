#pragma once

#include <stdbool.h>

// Start a temperature transaction
// Non-blocking function
void start_temperature_sample(void);

// Checks if an on-going temperature transaction is complete
// Non-blocking function
bool is_temperature_ready(void);

// Gets a temperature measurement. Must only be called when a measurement is ready
// Non-blocking function
float get_temperature_sample(void);

