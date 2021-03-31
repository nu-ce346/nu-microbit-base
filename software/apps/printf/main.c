// printf app
//
// Use serial to print messages via printf

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf_delay.h"

#include "microbit_v2.h"

int main(void) {
  printf("Board started!\n");
  
  // initialize LED
  nrf_gpio_cfg_output(LED_MIC);

  // loop forever
  uint32_t i = 0;
  while (1) {
    nrf_delay_ms(1000);
    printf("Iteration: %lu\n", i++);
    nrf_gpio_pin_toggle(LED_MIC);
  }
}

