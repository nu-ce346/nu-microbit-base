#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "nrf.h"
#include "nrf_delay.h"
#include "microbit_v2.h"

// buffer size for incoming messages
#define BUFFER_SIZE 64

int main(void) {

  printf("Board started! Waiting for input (e.g., 42 3.14).\n");

  char buffer[BUFFER_SIZE] = {0};
  while (true) {

    // read input into buffer
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
      continue;
    }

    // attempt to match arguments
    int integer_value = 0;
    float float_value = 0.0;
    int matched = sscanf(buffer, "%d %f", &integer_value, &float_value);

    // check for errors
    if (matched != 2) {
      printf("Error: Expected an integer and a float.\n");
      nrf_delay_ms(10);
      continue;
    }

    // print results
    printf("GOT: Integer = %d, Float = %f\n", integer_value, float_value);
    nrf_delay_ms(10);
  }
}

