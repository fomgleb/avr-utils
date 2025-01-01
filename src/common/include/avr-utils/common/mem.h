#ifndef AVR_UTILS_COMMON_MEM_H_
#define AVR_UTILS_COMMON_MEM_H_

#include <inttypes.h>
#include <stdbool.h>
#include "real_inline.h"

static REAL_INLINE void
mem_set_bit(volatile uint8_t* memory_byte, uint8_t bit_index) {
    *memory_byte |= (1 << bit_index);
}

static REAL_INLINE void
mem_set_2_bits(volatile uint8_t* memory_byte, uint8_t bit1_index, uint8_t bit2_index) {
    *memory_byte |= (1 << bit1_index) | (1 << bit2_index);
}

static REAL_INLINE void
mem_set_3_bits(volatile uint8_t* memory_byte, uint8_t bit1_index, uint8_t bit2_index, uint8_t bit3_index) {
    *memory_byte |= (1 << bit1_index) | (1 << bit2_index) | (1 << bit3_index);
}

static REAL_INLINE void
mem_assign_bit(volatile uint8_t* memory_byte, uint8_t bit_index) {
    *memory_byte = 1 << bit_index;
}

static REAL_INLINE void
mem_assign_2_bits(volatile uint8_t* memory_byte, uint8_t bit1_index, uint8_t bit2_index) {
    *memory_byte = (1 << bit1_index) | (1 << bit2_index);
}

static REAL_INLINE void
mem_assign_3_bits(volatile uint8_t* memory_byte, uint8_t bit1_index, uint8_t bit2_index, uint8_t bit3_index) {
    *memory_byte = (1 << bit1_index) | (1 << bit2_index) | (1 << bit3_index);
}

static REAL_INLINE void
mem_unset_bit(volatile uint8_t* memory_byte, uint8_t bit_index) {
    *memory_byte &= ~(1 << bit_index);
}

static REAL_INLINE void
mem_unset_2_bits(volatile uint8_t* memory_byte, uint8_t bit1_index, uint8_t bit2_index) {
    *memory_byte &= ~((1 << bit1_index) | (1 << bit2_index));
}

static REAL_INLINE void
mem_unset_3_bits(volatile uint8_t* memory_byte, uint8_t bit1_index, uint8_t bit2_index, uint8_t bit3_index) {
    *memory_byte &= ~((1 << bit1_index) | (1 << bit2_index) | (1 << bit3_index));
}

static REAL_INLINE bool
mem_get_bit(const volatile uint8_t* memory_byte, uint8_t bit_index) {
    return *memory_byte & (1 << bit_index);
}

#endif /* AVR_UTILS_COMMON_MEM_H_ */
