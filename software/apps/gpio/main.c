// GPIO app
//
// Uses MMIO to control GPIO pins

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf.h"
#include "nrf_delay.h"

#include "microbit_v2.h"
#include "gpio.h"

int main(void) {
  printf("Board started!\n");

  // Step 2:
  // Control LED with raw MMIO
  // Microphone LED is P0.20 and active high
  // Add code here

  // loop forever
  printf("Looping\n");
  while (1) {

    // Step 4:
    // Control LED with buttons
    // Button A is P0.14 and active low
    // Button B is P0.23 and active low
    // Add code here

    nrf_delay_ms(100);
  }
}

