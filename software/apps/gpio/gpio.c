#include "gpio.h"

typedef struct{
  // Step 3:
  // Add register definitions here
} gpio_reg_t;

// Inputs: 
//  gpio_num - gpio number 0-31 OR (32 + gpio number)
//  dir - gpio direction (INPUT, OUTPUT)
void gpio_config(uint8_t gpio_num, gpio_direction_t dir) {
  // Implement me
  // Hint: Use proper PIN_CNF instead of DIR
}

// Inputs: 
//  gpio_num - gpio number 0-31 OR (32 + gpio number)
void gpio_set(uint8_t gpio_num) {
  // Implement me
}

// Inputs: 
//  gpio_num - gpio number 0-31 OR (32 + gpio number)
void gpio_clear(uint8_t gpio_num) {
  // Implement me
}

// Inputs: 
//  gpio_num - gpio number 0-31 OR (32 + gpio number)
// Output:
//  bool - pin state (true == high)
bool gpio_read(uint8_t gpio_num) {
  // Implement me

  return true;
}

// prints out some information about the GPIO driver. Can be called from main()
void gpio_print(void) {
  // use this function for debugging purposes
  // you don't otherwise have to write anything here
}

