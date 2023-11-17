// UARTE example app
//
// Initialize the UARTE and send some bytes

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf_delay.h"
#include "nrfx_uarte.h"

#include "microbit_v2.h"

static const nrfx_uarte_t UARTE_INST = NRFX_UARTE_INSTANCE(1);

static void uarte_init(void) {
  nrfx_uarte_config_t uarte_config = {
    .pseltxd = EDGE_P7,
    .pselrxd = EDGE_P8,
    .pselcts = NRF_UARTE_PSEL_DISCONNECTED,
    .pselrts = NRF_UARTE_PSEL_DISCONNECTED,
    .p_context = NULL,
    .hwfc = NRF_UARTE_HWFC_DISABLED,
    .parity = NRF_UARTE_PARITY_EXCLUDED,
    .baudrate = NRF_UARTE_BAUDRATE_115200,
    .interrupt_priority = NRFX_UARTE_DEFAULT_CONFIG_IRQ_PRIORITY,
  };

  // Note: without a callback handler, transfers are blocking
  nrfx_err_t result = nrfx_uarte_init(&UARTE_INST, &uarte_config, NULL);
  APP_ERROR_CHECK(result);
}


int main(void) {
  printf("Board started!\n");
 
  // Initialize UARTE
  uarte_init();

  // loop forever
  while (1) {
    nrf_delay_ms(1000);

    // Perform a UARTE transmission
    uint8_t data[10] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a};
    nrfx_uarte_tx(&UARTE_INST, data, 10);
  }
}

