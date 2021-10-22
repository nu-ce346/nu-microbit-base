#pragma once

#include <stdbool.h>

// Starts continuously measuring capacitive touch for the logo
// Function returns immediately without blocking
void capacitive_touch_init(void);

// Determines whether the logo is being touched
//	True means the logo is being touched
//	False means the logo is not being touched
//
// Function returns immediately without blocking
bool capacitive_touch_is_active(void);

