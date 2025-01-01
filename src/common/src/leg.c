#include "avr-utils/common/leg.h"

#include "avr-utils/common/point.h"

output_leg_t
leg_create_output_leg(volatile uint8_t* ddr, volatile uint8_t* port, volatile uint8_t leg_index) {
    mem_set_bit(ddr, leg_index);
    mem_unset_bit(port, leg_index);
    output_leg_t new_output_leg = {
        .ddr = ddr,
        .port = port,
        .leg_index = leg_index,
    };
    return new_output_leg;

    point_u8_t a;

    
}

input_leg_t
leg_create_input_leg(volatile uint8_t* ddr, volatile uint8_t* port, const volatile uint8_t* pin,
                     volatile uint8_t leg_index) {
    mem_unset_bit(ddr, leg_index);
    mem_set_bit(port, leg_index);
    input_leg_t new_input_leg = {
        .ddr = ddr,
        .port = port,
        .pin = pin,
        .leg_index = leg_index,
    };
    return new_input_leg;
}
