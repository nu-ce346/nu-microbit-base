// Temperature MMIO app
//
// Use memory-mapped I/O to read from the Temperature peripheral

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf_delay.h"

#include "microbit_v2.h"

int main(void) {
  printf("Board started!\n");

  // loop forever
  while (1) {

    // start a measurement

    // wait until ready

    // read data and print it

    nrf_delay_ms(1000);
  }
}

