// PWM Tone App
//
// Use PWM to play a tone over the speaker

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf.h"
#include "nrf_delay.h"
#include "nrfx_pwm.h"

#include "microbit_v2.h"

// PWM configuration
static const nrfx_pwm_t PWM_INST = NRFX_PWM_INSTANCE(0);

// Holds duty cycle values to trigger PWM toggle
nrf_pwm_values_common_t sequence_data[1] = {0};

// Sequence structure for configuring DMA
nrf_pwm_sequence_t pwm_sequence = {
  .values.p_common = sequence_data,
  .length = 1,
  .repeats = 0,
  .end_delay = 0,
};


static void pwm_init(void) {
  // Initialize the PWM
  // SPEAKER_OUT is the output pin, mark the others as NRFX_PWM_PIN_NOT_USED
  // Set the clock to 500 kHz, count mode to Up, and load mode to Common
  // The Countertop value doesn't matter for now. We'll set it in play_tone()
  // TODO
}

static void play_tone(uint16_t frequency) {
  // Stop the PWM (and wait until its finished)
  // TODO

  // Set a countertop value based on desired tone frequency
  // You can access it as NRF_PWM0->COUNTERTOP
  // TODO

  // Modify the sequence data to be a 25% duty cycle
  // TODO

  // Start playback of the samples and loop indefinitely
  // TODO
}


int main(void) {
  printf("Board started!\n");

  // initialize PWM
  pwm_init();

  // Play the A4 tone for one second
  // TODO

  // Play the C#5 tone for one second
  // TODO

  // Play the E5 tone for one second
  // TODO

  // Play the A5 tone for one second
  // TODO

  // Stop all noises
  // TODO
}

