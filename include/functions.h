#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

#include "tools.h"

typedef uint8_t byte;

byte set_sws(byte toggled_sws);
void set_mock_digitalRead_values(byte values[3]);
byte digitalRead(byte pin);
void sws_sw_callback(byte toggled_sws);
int bitwise_toggle_test();

#endif

