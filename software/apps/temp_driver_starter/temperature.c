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
  NRF_TEMP->EVENTS_DATARDY = 0;

}

void get_temperature_nonblocking(void (*callback)(float, void*), void* context) {
  // Save callback

  // Enable lowest-priority interrupts

  // Start temperature sensor

}



float get_temperature_blocking(void) {

  return 0.0;
}

