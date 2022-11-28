// Computer Bidirectional app
//
// Use serial to echo data typed by the user

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
  while (1) {

    // read a single character
    nrf_gpio_pin_clear(LED_MIC);
    int c = getchar();
    if (c == EOF) {
      continue;
    }

    // print back out that character
    nrf_gpio_pin_set(LED_MIC);
    putchar(c);
  }
}

