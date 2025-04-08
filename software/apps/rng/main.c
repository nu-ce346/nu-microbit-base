// RNG app
//
// Uses MMIO to read RNG values

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf.h"
#include "nrf_delay.h"

#include "microbit_v2.h"
#include "rng.h"

int main(void) {
  printf("Board started!\n");

  // Initialize the RNG
  rng_init();

  // Print 10,000 randomly generated values
  // TODO: write code here!

}

