#include "rng.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
  // TODO: add stuff here
} rng_reg_t;

static volatile rng_reg_t* RNG; // TODO: set this to something

// Initializes the RNG
// Enable bias correction
// Stops itself after generating a value
void rng_init(void) {
  // TODO: implement me
}

// Get a random 8-bit value
// Waits until a value is ready
uint8_t rng_get8(void) {
  // TODO: implement me
  // HINT: be sure to clear EVENTS_VALRDY before starting the RNG

  return 0;
}

