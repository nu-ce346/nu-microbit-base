// LSM303AGR accelerometer and magnetometer

#pragma once

#include "nrf_twi_mngr.h"

// Chip addresses for accelerometer and magnetometer
static const uint8_t LSM303AGR_ACC_ADDRESS = 0x19;
static const uint8_t LSM303AGR_MAG_ADDRESS = 0x1E;

// Measurement data type
typedef struct {
  float x_axis;
  float y_axis;
  float z_axis;
} lsm303agr_measurement_t;

// Register definitions for accelerometer
typedef enum {
  STATUS_REG_AUX_A = 0x07,
  OUT_TEMP_L_A = 0x0C,
  OUT_TEMP_H_A = 0x0D,
  INT_COUNTER_REG_A = 0x0E,
  WHO_AM_I_A = 0x0F,
  TEMP_CFG_REG_A = 0x1F,
  CTRL_REG1_A = 0x20,
  CTRL_REG2_A = 0x21,
  CTRL_REG3_A = 0x22,
  CTRL_REG4_A = 0x23,
  CTRL_REG5_A = 0x24,
  CTRL_REG6_A = 0x25,
  REFERENCE_DATACAPTURE_A = 0x26,
  STATUS_REG_A = 0x27,
  OUT_X_L_A = 0x28,
  OUT_X_H_A = 0x29,
  OUT_Y_L_A = 0x2A,
  OUT_Y_H_A = 0x2B,
  OUT_Z_L_A = 0x2C,
  OUT_Z_H_A = 0x2D,
  FIFO_CTRL_REG_A = 0x2E,
  FIFO_SRC_REG_A = 0x2F,
  INT1_CFG_A = 0x30,
  INT1_SRC_A = 0x31,
  INT1_THS_A = 0x32,
  INT1_DURATION_A = 0x33,
  INT2_CFG_A = 0x34,
  INT2_SRC_A = 0x35,
  INT2_THS_A = 0x36,
  INT2_DURATION_A = 0x37,
  CLICK_CFG_A = 0x38,
  CLICK_SRC_A = 0x39,
  CLICK_THS_A = 0x3A,
  TIME_LIMIT_A = 0x3B,
  TIME_LATENCY_A = 0x3C,
  TIME_WINDOW_A = 0x3D,
  ACT_THS_A = 0x3E,
  ACT_DUR_A = 0x3F,
} lsm303agr_acc_reg_t;

// Register definitions for magnetometer
typedef enum {
  OFFSET_X_REG_L_M = 0x45,
  OFFSET_X_REG_H_M = 0x46,
  OFFSET_Y_REG_L_M = 0x47,
  OFFSET_Y_REG_H_M = 0x48,
  OFFSET_Z_REG_L_M = 0x49,
  OFFSET_Z_REG_H_M = 0x4A,
  WHO_AM_I_M = 0x4F,
  CFG_REG_A_M = 0x60,
  CFG_REG_B_M = 0x61,
  CFG_REG_C_M = 0x62,
  INT_CTRL_REG_M = 0x63,
  INT_SOURCE_REG_M = 0x64,
  INT_THS_L_REG_M = 0x65,
  INT_THS_H_REG_M = 0x66,
  STATUS_REG_M = 0x67,
  OUTX_L_REG_M = 0x68,
  OUTX_H_REG_M = 0x69,
  OUTY_L_REG_M = 0x6A,
  OUTY_H_REG_M = 0x6B,
  OUTZ_L_REG_M = 0x6C,
  OUTZ_H_REG_M = 0x6D,
} lsm303agr_mag_reg_t;

// Function prototypes

// Initialize and configure the LSM303AGR accelerometer/magnetometer
//
// i2c - pointer to already initialized and enabled twim instance
void lsm303agr_init(const nrf_twi_mngr_t* i2c);

// Read the internal temperature sensor
//
// Return measurement as floating point value in degrees C
float lsm303agr_read_temperature(void);

// Read all three axes on the accelerometer
//
// Return measurements as floating point values in g's
lsm303agr_measurement_t lsm303agr_read_accelerometer(void);

// Read all three axes on the magnetometer
//
// Return measurements as floating point values in uT
lsm303agr_measurement_t lsm303agr_read_magnetometer(void);

