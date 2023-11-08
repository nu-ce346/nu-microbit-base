# Board-specific configurations for the microbit v2 (uses nrf52833 like pca10100)

# Ensure that this file is only included once
ifndef BOARD_MAKEFILE
BOARD_MAKEFILE = 1

# Get directory of this makefile
BOARD_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
KEY_DIR := $(BOARD_DIR)/../keys/

# Include any files in this directory in the build process
# Mostly point to files from the original microbit_v2 board
BOARD_HEADER_PATHS = $(BOARD_DIR)/.
BOARD_SOURCE_PATHS = $(BOARD_DIR)/../microbit_v2/.
BOARD_LINKER_PATHS = $(BOARD_DIR)/../microbit_v2/.
BOARD_SOURCES = $(notdir $(wildcard $(BOARD_DIR)/../microbit_v2/*.c))
BOARD_AS = $(notdir $(wildcard $(BOARD_DIR)/../microbit_v2/*.s))

# Board-specific configurations
BOARD = PCA10100
USE_BLE = 0
USE_THREAD = 0

# Add 15.4 stuff
SDK_SOURCE_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src
SDK_SOURCE_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/fal
SDK_SOURCE_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/mac_features
SDK_SOURCE_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/mac_features/ack_generator
SDK_SOURCE_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/platform/clock
SDK_SOURCE_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/platform/coex
SDK_SOURCE_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/platform/hp_timer
SDK_SOURCE_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/platform/lp_timer
SDK_SOURCE_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/platform/random
SDK_SOURCE_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/platform/temperature
SDK_SOURCE_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/rsch
SDK_SOURCE_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/rsch/raal/single_phy
SDK_SOURCE_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/timer_scheduler
SDK_HEADER_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src
SDK_HEADER_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/fal
SDK_HEADER_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/fem
SDK_HEADER_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/mac_features
SDK_HEADER_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/mac_features/ack_generator
SDK_HEADER_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/platform/clock
SDK_HEADER_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/platform/coex
SDK_HEADER_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/platform/hp_timer
SDK_HEADER_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/platform/lp_timer
SDK_HEADER_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/platform/temperature
SDK_HEADER_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/rsch
SDK_HEADER_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/rsch/raal
SDK_HEADER_PATHS += $(NRF_BASE_DIR)/sdk/nrf5_sdk_16.0.0_thread/external/nRF-IEEE-802.15.4-radio-driver/src/timer_scheduler

# Additional #define's to be added to code by the compiler
BOARD_VARS = \
	BOARD_$(BOARD)\
	USE_APP_CONFIG\
	DEBUG\
	DEBUG_NRF\
	RAAL_SINGLE_PHY\

# Default SDK source files to be included
BOARD_SOURCES += \
	app_error_handler_gcc.c\
	app_fifo.c\
	app_scheduler.c\
	app_timer.c\
	app_uart_fifo.c\
	app_util_platform.c\
	hardfault_handler_gcc.c\
	nrf_assert.c\
	nrf_atomic.c\
	nrf_balloc.c\
	nrf_drv_clock.c\
	nrf_drv_twi.c\
	nrf_drv_uart.c\
	nrf_fprintf.c\
	nrf_fprintf_format.c\
	nrf_log_backend_rtt.c\
	nrf_log_backend_serial.c\
	nrf_log_default_backends.c\
	nrf_log_frontend.c\
	nrf_log_str_formatter.c\
	nrf_memobj.c\
	nrf_nvmc.c\
	nrf_pwr_mgmt.c\
	nrf_queue.c\
	nrf_ringbuf.c\
	nrf_sdh.c\
	nrf_section_iter.c\
	nrf_serial.c\
	nrf_strerror.c\
	nrf_twi_mngr.c\
	nrfx_gpiote.c\
	nrfx_ppi.c\
	nrfx_prs.c\
	nrfx_pwm.c\
	nrfx_saadc.c\
	nrfx_spim.c\
	nrfx_timer.c\
	nrfx_twi.c\
	nrfx_twim.c\
	nrfx_uart.c\
	nrfx_uarte.c\

## 15.4 stuff
BOARD_SOURCES += \
	nrf_802154.c\
	nrf_802154_core.c\
	nrf_802154_core_hooks.c\
	nrf_802154_critical_section.c\
	nrf_802154_debug.c\
	nrf_802154_pib.c\
	nrf_802154_rssi.c\
	nrf_802154_rx_buffer.c\
	nrf_802154_timer_coord.c\
	nrf_802154_fal.c\
	nrf_802154_csma_ca.c\
	nrf_802154_delayed_trx.c\
	nrf_802154_filter.c\
	nrf_802154_frame_parser.c\
	nrf_802154_precise_ack_timeout.c\
	nrf_802154_ack_data.c\
	nrf_802154_ack_generator.c\
	nrf_802154_enh_ack_generator.c\
	nrf_802154_imm_ack_generator.c\
	nrf_802154_rsch.c\
	nrf_802154_rsch_crit_sect.c\
	nrf_802154_timer_sched.c\
	nrf_802154_notification_direct.c\
	nrf_802154_priority_drop_direct.c\
	nrf_802154_request_direct.c\
	single_phy.c\
	nrf_802154_clock_nodrv.c\
	nrf_802154_wifi_coex_none.c\
	nrf_802154_hp_timer.c\
	nrf_802154_lp_timer_nodrv.c\
	nrf_802154_random_stdlib.c\
	nrf_802154_temperature_none.c\

# Include the OpenOCD programming makefile
# Replace the default JLink programming makefile from the nrf52x-base repo
include $(BOARD_DIR)/../../tools/openocd/Program_OpenOCD.mk

endif

