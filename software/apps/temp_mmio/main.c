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
    *(uint32_t*)(0x4000C000) = 1;

    // wait until ready
    volatile uint32_t ready = *(uint32_t*)(0x4000C100);
    while (!ready) {
      ready = *(uint32_t*)(0x4000C100);
    }

    /* WARNING: we can't write the code this way!
     *  Without `volatile`, the compiler optimizes out the memory access
    while (!*(uint32_t*)(0x4000C100));
    */

    // read data and print it
    volatile int32_t value = *(int32_t*)(0x4000C508);
    float temperature = ((float)value)/4.0;
    printf("Temperature=%f degrees C\n", temperature);

    nrf_delay_ms(1000);
  }
}

