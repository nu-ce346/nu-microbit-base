// Temperature driver app
//
// Use a driver to read from the Temperature peripheral
// in a non-blocking or blocking way

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf_delay.h"

#include "microbit_v2.h"
#include "temperature.h"

void temp_callback(float temp, void* _unused) {
  printf("Temperature: %f degrees C\n", temp);
}

int main(void) {
  printf("Board started!\n");

  // Get temperature without blocking
  get_temperature_nonblocking(temp_callback, NULL);

  // loop forever
  while (1) {
    nrf_delay_ms(1000);
    printf("Looping\n");
    printf("New temp: %f degrees C\n", get_temperature_blocking());
  }
}

