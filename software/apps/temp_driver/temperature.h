#pragma once

// Get temperature value
// Non-blocking function. Calls callback with context when temperature is ready
void get_temperature_nonblocking(void (*callback)(float, void*), void* context);

// Get temperature value
// Blocking function. Returns temperature value when ready
float get_temperature_blocking(void);

