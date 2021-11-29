// SPIM example app
//
// Initialize the SPIM and send some bytes

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf_delay.h"
#include "nrfx_spim.h"

#include "microbit_v2.h"

static const nrfx_spim_t SPIM_INST = NRFX_SPIM_INSTANCE(2);

static void spim_init(void) {
  // Note: doesn't specify a chip-select pin
  // That should probably be manually controlled via the GPIO library
  nrfx_spim_config_t spim_config = NRFX_SPIM_DEFAULT_CONFIG;
  spim_config.sck_pin = EDGE_P13;
  spim_config.mosi_pin = EDGE_P15;
  spim_config.miso_pin = EDGE_P14;
  spim_config.irq_priority = 0;
  spim_config.frequency = NRF_SPIM_FREQ_8M;
  spim_config.mode = NRF_SPIM_MODE_0;

  // Note: without a callback handler, transfers are blocking
  nrfx_spim_init(&SPIM_INST, &spim_config, NULL, NULL);
}


int main(void) {
  printf("Board started!\n");
 
  // Initialize SPI controller
  spim_init();

  // Perform a SPI transmission (COPI)
  uint8_t data[4] = {0x00, 0x0F, 0xF0, 0xFF};
  nrfx_spim_xfer_desc_t data_xfer = NRFX_SPIM_XFER_TX(&data, 4);
  nrfx_spim_xfer(&SPIM_INST, &data_xfer, 0);

  // loop forever
  while (1) {
    nrf_delay_ms(1000);
  }
}

