#pragma once

#include "nrf.h"
#include "stdbool.h"

typedef enum {
  GPIO_INPUT = 0,
  GPIO_OUTPUT,
} gpio_direction_t;

// Inputs: 
//  gpio_num - gpio number 0-31 OR (32 + gpio number)
//  dir - gpio direction (INPUT, OUTPUT)
void gpio_config(uint8_t gpio_num, gpio_direction_t dir);

// Inputs: 
//  gpio_num - gpio number 0-31 OR (32 + gpio number)
void gpio_set(uint8_t gpio_num);

// Inputs: 
//  gpio_num - gpio number 0-31 OR (32 + gpio number)
void gpio_clear(uint8_t gpio_num);

// Inputs: 
//  gpio_num - gpio number 0-31 OR (32 + gpio number)
// Returns:
//  current state of the specified gpio pin (true == high)
bool gpio_read(uint8_t gpio_num);

