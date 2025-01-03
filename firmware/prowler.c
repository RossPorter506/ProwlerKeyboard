#include "quantum.h"

void keyboard_pre_init_kb(void) {
  gpio_set_pin_input_high(GP3); // Handedness pin. Has pulldown resistor on slave side.
  keyboard_pre_init_user();
}
