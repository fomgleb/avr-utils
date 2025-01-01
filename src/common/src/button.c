#include "avr-utils/common/button.h"

button_t
btn_create(volatile uint8_t* ddr, volatile uint8_t* port, const volatile uint8_t* pin, volatile uint8_t leg_index) {
    input_leg_t new_input_leg = leg_create_input_leg(ddr, port, pin, leg_index);
    return new_input_leg;
}
