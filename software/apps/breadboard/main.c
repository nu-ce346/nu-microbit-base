// Breadboard example app
//
// Read from multiple analog sensors and control an RGB LED

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include "app_timer.h"
#include "nrf_delay.h"
#include "nrfx_saadc.h"

#include "microbit_v2.h"

// Digital outputs
// Breakout pins 13, 14, and 15
// These are GPIO pin numbers that can be used in nrf_gpio_* calls
#define LED_RED   EDGE_P13
#define LED_GREEN EDGE_P14
#define LED_BLUE  EDGE_P15

// Digital inputs
// Breakout pin 16
// These are GPIO pin numbers that can be used in nrf_gpio_* calls
#define SWITCH_IN EDGE_P16

// Analog inputs
// Breakout pins 1 and 2
// These are GPIO pin numbers that can be used in ADC configurations
// AIN1 is breakout pin 1. AIN2 is breakout pin 2.
#define ANALOG_TEMP_IN  NRF_SAADC_INPUT_AIN1
#define ANALOG_LIGHT_IN NRF_SAADC_INPUT_AIN2

// ADC channel configurations
// These are ADC channel numbers that can be used in ADC calls
#define ADC_TEMP_CHANNEL  0
#define ADC_LIGHT_CHANNEL 1

// Global variables
APP_TIMER_DEF(sample_timer);

// Function prototypes
static void gpio_init(void);
static void adc_init(void);
static float adc_sample_blocking(uint8_t channel);

static void sample_timer_callback(void* _unused) {
  // Do things periodically here
  // TODO
}

static void saadc_event_callback(nrfx_saadc_evt_t const* _unused) {
  // don't care about saadc events
  // ignore this function
}

static void gpio_init(void) {
  // Initialize output pins
  // TODO

  // Set LEDs off initially
  // TODO

  // Initialize input pin
  // TODO
}

static void adc_init(void) {
  // Initialize the SAADC
  nrfx_saadc_config_t saadc_config = {
    .resolution = NRF_SAADC_RESOLUTION_12BIT,
    .oversample = NRF_SAADC_OVERSAMPLE_DISABLED,
    .interrupt_priority = 4,
    .low_power_mode = false,
  };
  ret_code_t error_code = nrfx_saadc_init(&saadc_config, saadc_event_callback);
  APP_ERROR_CHECK(error_code);

  // Initialize temperature sensor channel
  nrf_saadc_channel_config_t temp_channel_config = NRFX_SAADC_DEFAULT_CHANNEL_CONFIG_SE(ANALOG_TEMP_IN);
  error_code = nrfx_saadc_channel_init(ADC_TEMP_CHANNEL, &temp_channel_config);
  APP_ERROR_CHECK(error_code);

  // Initialize light sensor channel
  nrf_saadc_channel_config_t light_channel_config = NRFX_SAADC_DEFAULT_CHANNEL_CONFIG_SE(ANALOG_LIGHT_IN);
  error_code = nrfx_saadc_channel_init(ADC_LIGHT_CHANNEL, &light_channel_config);
  APP_ERROR_CHECK(error_code);
}

static float adc_sample_blocking(uint8_t channel) {
  // read ADC counts (0-4095)
  // this function blocks until the sample is ready
  int16_t adc_counts = 0;
  ret_code_t error_code = nrfx_saadc_sample_convert(channel, &adc_counts);
  APP_ERROR_CHECK(error_code);

  // convert ADC counts to volts
  // 12-bit ADC with range from 0 to 3.6 Volts
  // TODO

  // return voltage measurement
  return 0.0;
}


int main(void) {
  printf("Board started!\n");
  
  // initialize GPIO
  gpio_init();

  // initialize ADC
  adc_init();

  // initialize app timers
  app_timer_init();
  app_timer_create(&sample_timer, APP_TIMER_MODE_REPEATED, sample_timer_callback);

  // start timer
  // change the rate to whatever you want
  app_timer_start(sample_timer, 32768, NULL);

  // loop forever
  while (1) {
    // Don't put any code in here. Instead put periodic code in `sample_timer_callback()`
    nrf_delay_ms(1000);
  }
}

