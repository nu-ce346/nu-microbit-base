// Temperature driver
//
// Accesses the internal temperature sensor peripheral

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf.h"

#include "temperature.h"

static void (*callback_fn)(float, void*) = NULL;
static void* callback_context = NULL;

// Interrupt handler for Temperature sensor
void TEMP_IRQHandler(void) {
  NRF_TEMP->EVENTS_DATARDY = 0;

  // Be sure to only call function if non-null
  if (callback_fn) {
    float temperature = ((float)NRF_TEMP->TEMP)/4.0;
    callback_fn(temperature, callback_context);
  }
}

void get_temperature_nonblocking(void (*callback)(float, void*), void* context) {
  // Save callback
  callback_fn = callback;
  callback_context = context;

  // Enable lowest-priority interrupts
  NRF_TEMP->INTENSET = 1;
  NVIC_EnableIRQ(TEMP_IRQn);
  NVIC_SetPriority(TEMP_IRQn, 7);

  // Start temperature sensor
  NRF_TEMP->TASKS_START = 1;

  return;
}

typedef struct {
  float temp;
  bool flag;
} handler_info_t;

static void temp_handler(float temp, void* context) {
  ((handler_info_t*)context)->temp = temp;
  ((handler_info_t*)context)->flag = true;
}

float get_temperature_blocking(void) {

  volatile handler_info_t handler_info = {.temp = 0.0, .flag = false};
  get_temperature_nonblocking(temp_handler, (void*)&handler_info);
  while (!handler_info.flag);

  return handler_info.temp;
}

