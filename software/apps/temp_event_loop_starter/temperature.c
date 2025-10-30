// Temperature driver
//
// Accesses the internal temperature sensor peripheral

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf.h"

#include "temperature.h"


// Interrupt handler for Temperature sensor
void TEMP_IRQHandler(void) {
  // Clear interrupt
  NRF_TEMP->EVENTS_DATARDY = 0;

  // Save value for later access

  // Signal readiness

}

void start_temperature_sample(void) {
  // Not ready anymore

  // Enable lowest-priority interrupts (NRF_TEMP and TEMP_IRQn)

  // Start temperature sensor

}

bool is_temperature_ready(void) {
  return false;
}

float get_temperature_sample(void) {
  return 0.0;
}

