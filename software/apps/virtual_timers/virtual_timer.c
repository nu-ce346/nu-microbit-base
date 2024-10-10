// Virtual timer implementation

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "nrf.h"

#include "virtual_timer.h"
#include "virtual_timer_linked_list.h"

// This is the interrupt handler that fires on a compare event
void TIMER4_IRQHandler(void) {
  // This should always be the first line of the interrupt handler!
  // It clears the event so that it doesn't happen again
  NRF_TIMER4->EVENTS_COMPARE[0] = 0;

  // You will place your interrupt handler code here

}

// Read the current value of the timer counter
uint32_t read_timer(void) {

  // Should return the value of the internal counter for TIMER4
  return 0;
}

// Initialize the timers
void virtual_timer_init(void) {
  // Place your timer initialization code here
}

// This is a private helper function called from multiple public functions with different arguments.
// Starts a timer. This function is called for both one-shot and repeated timers
static uint32_t timer_start(uint32_t microseconds, virtual_timer_callback_t cb, bool repeated) {

  // Return a unique timer ID. (hint: What is guaranteed unique about the timer you have created?)
  return 0;
}

// You do not need to modify this function
// Instead, implement timer_start
uint32_t virtual_timer_start(uint32_t microseconds, virtual_timer_callback_t cb) {
  return timer_start(microseconds, cb, false);
}

// You do not need to modify this function
// Instead, implement timer_start
uint32_t virtual_timer_start_repeated(uint32_t microseconds, virtual_timer_callback_t cb) {
  return timer_start(microseconds, cb, true);
}

// Remove a timer by ID.
// Make sure you don't cause linked list consistency issues!
// Do not forget to free removed timers.
void virtual_timer_cancel(uint32_t timer_id) {
}

