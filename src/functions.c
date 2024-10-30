#include "functions.h"

const byte CABIN_LTS_PIN = 10;
const byte COCKPIT_LTS_PIN = 11;
const byte STORAGE_LTS_PIN = 12;
const byte LTS_PIN_ARRAY[3] = {CABIN_LTS_PIN, COCKPIT_LTS_PIN, STORAGE_LTS_PIN};

const byte CABIN_LTS_SW_PIN = 2;
const byte COCKPIT_LTS_SW_PIN = 3;
const byte STORAGE_LTS_SW_PIN = 4;
const byte LTS_SW_PIN_ARRAY[3] = {CABIN_LTS_SW_PIN, COCKPIT_LTS_SW_PIN, STORAGE_LTS_SW_PIN};

byte mock_digitalRead_values[3] = {0};

byte set_sws(byte toggled_sws) {
  // With bitwise operations, use the previous toggled_sws and check if any had changed.
    for (byte i = 0; i < 3; i++) {
        byte dig_read = digitalRead(LTS_SW_PIN_ARRAY[i]);
        if (toggled_sws & (dig_read << (i+1))) {
            toggled_sws ^= (1 << (i+1));
        }
    }
    return toggled_sws;
}

void set_mock_digitalRead_values(byte values[3]) {
    for (int i = 0; i < 3; i++) {
        mock_digitalRead_values[i] = values[i];
    }
}

byte digitalRead(byte pin) {
    // Return the mock value based on the pin index
    for (int i = 0; i < 3; i++) {
        if (LTS_SW_PIN_ARRAY[i] == pin) {
            return mock_digitalRead_values[i];
        }
    }
    return 0;
}

void sws_sw_callback(byte toggled_sws) {
    printf("Callback called with toggled_sws: ");
    print_binary(toggled_sws);
    printf("\n");
}

int bitwise_toggle_test() {
    byte toggled_sws = 0b0000;
    byte mock_values[3] = {1,0,1};

    set_mock_digitalRead_values(mock_values);

    // Call set_sws with the mock values
    toggled_sws = set_sws(toggled_sws);
    sws_sw_callback(toggled_sws);

    print_binary(toggled_sws);

    return 0;   
}