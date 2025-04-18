#pragma once

#include <stdint.h>

#include "nrf.h"

// type for timestamps
typedef struct {
  uint8_t hours;
  uint8_t minutes;
  uint8_t seconds;
} clock_time_t;

// Initialize the clock time library
// Automatically tracks time starting from compilation
// MUST be called after `virtual_timer_init` has already been called
void clock_time_init(void);

// Get the current clock time
clock_time_t clock_time_get(void);

