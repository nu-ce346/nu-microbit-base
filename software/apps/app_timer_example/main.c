// App Timer example app
//
// Use the App Timer to blink LEDs

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "app_timer.h"
#include "nrf_delay.h"

#include "microbit_v2.h"

APP_TIMER_DEF(my_timer_1);
APP_TIMER_DEF(my_timer_2);

static void led0_toggle(void* _unused) {
    nrf_gpio_pin_toggle(LED_ROW1);
}

static void led1_toggle(void* _unused) {
    nrf_gpio_pin_toggle(LED_ROW2);
}

int main(void) {
  printf("Board started!\n");
  
  // initialize LED pins
  nrf_gpio_pin_dir_set(LED_COL1, NRF_GPIO_PIN_DIR_OUTPUT);
  nrf_gpio_pin_dir_set(LED_ROW1, NRF_GPIO_PIN_DIR_OUTPUT);
  nrf_gpio_pin_dir_set(LED_ROW2, NRF_GPIO_PIN_DIR_OUTPUT);
  nrf_gpio_pin_dir_set(LED_ROW3, NRF_GPIO_PIN_DIR_OUTPUT);
  nrf_gpio_pin_clear(LED_COL1);
  nrf_gpio_pin_clear(LED_ROW1);
  nrf_gpio_pin_clear(LED_ROW2);
  nrf_gpio_pin_clear(LED_ROW3);

  // initialize app timers
  //    First argument is a pointer to the app timer
  //    Second argument is mode SINGLE_SHOT or REPEATED
  //    Third argument is a callback function
  app_timer_init();
  app_timer_create(&my_timer_1, APP_TIMER_MODE_REPEATED, led0_toggle);
  app_timer_create(&my_timer_2, APP_TIMER_MODE_REPEATED, led1_toggle);

  // start app timers
  //    First argument is the app timer
  //    Second argument is duration in Ticks (Ticks/32768 = Seconds)
  //    Third argument is a pointer to pass to the callback (usually NULL)
  app_timer_start(my_timer_1, 32768, NULL);
  app_timer_start(my_timer_2, 2*32768, NULL);

  // loop forever
  while (1) {
    nrf_delay_ms(1000);
  }
}

