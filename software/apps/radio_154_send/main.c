// Radio 15.4 send app
//
// Sends wireless packets via the 802.15.4 radio

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "nrf.h"
#include "nrf_delay.h"
#include "nrf_gpio.h"

// Pin configurations
#include "microbit_v2.h"

#include "nrf_802154.h"

#define PSDU_MAX_SIZE (127) // Max length of a packet
#define FCS_LENGTH (2) // Length of the Frame Control Sequence


// callback fn when tx starts
void nrf_802154_tx_started(const uint8_t* p_frame) {
	printf("tx started\n");
}

// callback fn when tx fails
void nrf_802154_transmit_failed(const uint8_t* p_frame, nrf_802154_tx_error_t error) {
	printf("tx failed error %u!\n", error);
}

// callback fn for successful tx
void nrf_802154_transmitted_raw(const uint8_t* p_frame, uint8_t* p_ack, int8_t power, uint8_t lqi) {
	printf("frame was transmitted!\n");
}


int main(void) {
  printf("Board started!\n");

  // Initialize.
  nrf_gpio_cfg_output(LED_MIC);

  // Configure 154 radio
  printf("About to init\n");
  nrf_802154_init();
  printf("Done with init\n");
  nrf_802154_channel_set(11);
  uint8_t src_pan_id[] = {0xcd, 0xab}; 
  nrf_802154_pan_id_set(src_pan_id);
  printf("Radio configured!\n");

  // Addresses (source and destination)
  uint8_t src_extended_addr[] = {0xdc, 0xa9, 0x35, 0x7b, 0x73, 0x36, 0xce, 0xf4};
  nrf_802154_extended_address_set(src_extended_addr);
  uint8_t dst_extended_addr[] = {0x50, 0xbe, 0xca, 0xc3, 0x3c, 0x36, 0xce, 0xf4};

  // TX Packet
  uint8_t pkt[PSDU_MAX_SIZE];
  pkt[0] = 26 + FCS_LENGTH; /* Length for nrf_transmit (length of pkt + FCS) */
  pkt[1] = 0x01; /* Frame Control Field */
  pkt[2] = 0xcc; /* Frame Control Field */
  pkt[3] = 0x00; /* Sequence number */
  pkt[4] = 0xff; /* Destination PAN ID 0xffff */
  pkt[5] = 0xff; /* Destination PAN ID */
  memcpy(&pkt[6], dst_extended_addr, 8); /* Destination extended address */
  memcpy(&pkt[14], src_pan_id, 2); /* Source PAN ID */
  memcpy(&pkt[16], src_extended_addr, 8);/* Source extended address */ 
  pkt[24] = 0xAA; /* Payload */
  pkt[25] = 0xBB; /* */
  pkt[26] = 0xCC; /* */


  // Enter main loop.
  while (1) {
    // Send packet
    if (!nrf_802154_transmit_raw(pkt, true)) {
      printf("Failure to send radio packet!\n");
    } else {
      printf("Sent a radio packet!\n");
    }

    // Toggle LED
    nrf_gpio_pin_toggle(LED_MIC);

    // Sleep
    nrf_delay_ms(500);
  }
}

