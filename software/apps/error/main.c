// error app
//
// Cause an error that then gets printed

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf_delay.h"

#include "microbit_v2.h"

int main(void) {
  printf("Board started! Erroring in a second.\n");
  nrf_delay_ms(1000);

  // dereference a NULL pointer
  volatile int invalid = *(int*)0x00000000;

  printf("You should never see this print %d\n", invalid);
  while (1);
}

