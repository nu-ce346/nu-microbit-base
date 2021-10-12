// Temperature event-loop example
//
// Use a driver to read from the Temperature peripheral
// as part of an event loop

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf_delay.h"

#include "microbit_v2.h"
#include "temperature.h"


int main(void) {
  printf("Board started!\n");

  // Start temperature transaction
  start_temperature_sample();

  // loop forever
  while (1) {
    // Poll for temperature events
    if (is_temperature_ready()) {
      printf("New temp: %f degrees C\n", get_temperature_sample());
      start_temperature_sample();
    }

    // Wait until events (usually replaced with a call to sleep)
    printf("Looping\n");
    nrf_delay_ms(1000);
  }
}

