// Capacitive Touch app
//
// Use capacitance to detect touch on the microbit logo pad

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "app_timer.h"
#include "nrf_delay.h"
#include "nrfx_gpiote.h"

#include "microbit_v2.h"
#include "capacitive_touch.h"

int main(void) {
  printf("Board started!\n");

  // intialize drivers
  nrfx_gpiote_init();
  app_timer_init();
  
  // start capacitive touch driver
  capacitive_touch_init();

  // loop forever
  while (1) {
    // Faster than normal so that we can see the touch sensor responding
    nrf_delay_ms(100);

    // Add some stuff here to demonstrate that your driver works
  }
}

