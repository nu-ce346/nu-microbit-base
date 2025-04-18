// Clock time implementation

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nrf.h"
#include "nrf_delay.h"

#include "clock_time.h"
#include "virtual_timer.h"

// Get the timestamp when compiling. Ignore the warning about this
#pragma GCC diagnostic ignored "-Wdate-time"
static const char* initial_timestr = __TIME__;

// Current sense of time, automatically updated
static clock_time_t current_time = {0};

// WARNING: MUST be initialized after the virtual timer library
void clock_time_init(void) {
  printf("Initial timestr is: %s\n", initial_timestr); // debugging, you can remove this

  // TODO: implement me
}

clock_time_t clock_time_get(void) {
  return current_time;
}

