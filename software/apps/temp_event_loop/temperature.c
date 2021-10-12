// Temperature driver
//
// Accesses the internal temperature sensor peripheral

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf.h"

#include "temperature.h"

static bool sample_ready = false;
static float temp_value = 0.0;

// Interrupt handler for Temperature sensor
void TEMP_IRQHandler(void) {
  // Clear interrupt
  NRF_TEMP->EVENTS_DATARDY = 0;

  // Save value for later access
  temp_value = ((float)NRF_TEMP->TEMP)/4.0;

  // Signal readiness
  sample_ready = true;

}

void start_temperature_sample(void) {
  // not ready anymore
  sample_ready = false;

  // Enable lowest-priority interrupts (NRF_TEMP and TEMP_IRQn)
  NRF_TEMP->INTENSET = 1;
  NVIC_EnableIRQ(TEMP_IRQn);
  NVIC_SetPriority(TEMP_IRQn, 7);

  // Start temperature sensor
  NRF_TEMP->TASKS_START = 1;

  return;
}

bool is_temperature_ready(void) {
  // determine if measurement is ready
  return sample_ready;
}

float get_temperature_sample(void) {
  // return temperature reading
  return temp_value;
}

