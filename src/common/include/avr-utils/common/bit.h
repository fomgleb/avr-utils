#ifndef AVR_UTILS_COMMON_BIT_H_
#define AVR_UTILS_COMMON_BIT_H_

#include <inttypes.h>
#include <stdbool.h>
#include "real_inline.h"

#define DEFINE_BIT_TYPE(TYPE, SUFFIX)                                                                                  \
    static REAL_INLINE void bit_##SUFFIX##_set(TYPE* var, uint8_t bit_index) { *var |= ((TYPE)1 << bit_index); }       \
    static REAL_INLINE void bit_##SUFFIX##_set2(TYPE* var, uint8_t bit1_index, uint8_t bit2_index) {                   \
        *var |= ((TYPE)1 << bit1_index) | ((TYPE)1 << bit2_index);                                                     \
    }                                                                                                                  \
    static REAL_INLINE void bit_##SUFFIX##_set3(TYPE* var, uint8_t bit1_index, uint8_t bit2_index,                     \
                                                uint8_t bit3_index) {                                                  \
        *var |= ((TYPE)1 << bit1_index) | ((TYPE)1 << bit2_index) | ((TYPE)1 << bit3_index);                           \
    }                                                                                                                  \
    static REAL_INLINE void bit_##SUFFIX##_assign(TYPE* var, uint8_t bit_index) { *var = ((TYPE)1 << bit_index); }     \
    static REAL_INLINE void bit_##SUFFIX##_assign2(TYPE* var, uint8_t bit1_index, uint8_t bit2_index) {                \
        *var = ((TYPE)1 << bit1_index) | ((TYPE)1 << bit2_index);                                                      \
    }                                                                                                                  \
    static REAL_INLINE void bit_##SUFFIX##_assign3(TYPE* var, uint8_t bit1_index, uint8_t bit2_index,                  \
                                                   uint8_t bit3_index) {                                               \
        *var = ((TYPE)1 << bit1_index) | ((TYPE)1 << bit2_index) | ((TYPE)1 << bit3_index);                            \
    }                                                                                                                  \
    static REAL_INLINE void bit_##SUFFIX##_unset(TYPE* var, uint8_t bit_index) { *var &= ~((TYPE)1 << bit_index); }    \
    static REAL_INLINE void bit_##SUFFIX##_unset2(TYPE* var, uint8_t bit1_index, uint8_t bit2_index) {                 \
        *var &= ~(((TYPE)1 << bit1_index) | ((TYPE)1 << bit2_index));                                                  \
    }                                                                                                                  \
    static REAL_INLINE void bit_##SUFFIX##_unset3(TYPE* var, uint8_t bit1_index, uint8_t bit2_index,                   \
                                                  uint8_t bit3_index) {                                                \
        *var &= ~(((TYPE)1 << bit1_index) | ((TYPE)1 << bit2_index) | ((TYPE)1 << bit3_index));                        \
    }                                                                                                                  \
    static REAL_INLINE bool bit_##SUFFIX##_get(const TYPE* var, uint8_t bit_index) {                                   \
        return (*var & ((TYPE)1 << bit_index)) != 0;                                                                   \
    }

DEFINE_BIT_TYPE(uint8_t, u8)
DEFINE_BIT_TYPE(int8_t, i8)
DEFINE_BIT_TYPE(uint16_t, u16)
DEFINE_BIT_TYPE(int16_t, i16)
DEFINE_BIT_TYPE(uint32_t, u32)
DEFINE_BIT_TYPE(int32_t, i32)

#define DEFINE_GENERIC_BIT_OP(OPERATION)                                                                               \
    _Generic((var),                                                                                                    \
        uint8_t*: bit_u8_##OPERATION,                                                                                  \
        int8_t*: bit_i8_##OPERATION,                                                                                   \
        uint16_t*: bit_u16_##OPERATION,                                                                                \
        int16_t*: bit_i16_##OPERATION,                                                                                 \
        uint32_t*: bit_u32_##OPERATION,                                                                                \
        int32_t*: bit_i32_##OPERATION)

#define DEFINE_GENERIC_CONST_BIT_OP(OPERATION)                                                                         \
    _Generic((var),                                                                                                    \
        const uint8_t*: bit_u8_##OPERATION,                                                                            \
        const int8_t*: bit_i8_##OPERATION,                                                                             \
        const uint16_t*: bit_u16_##OPERATION,                                                                          \
        const int16_t*: bit_i16_##OPERATION,                                                                           \
        const uint32_t*: bit_u32_##OPERATION,                                                                          \
        const int32_t*: bit_i32_##OPERATION)

#define bit_set(var, bit_index)            DEFINE_GENERIC_BIT_OP(set)(var, bit_index)
#define bit_set2(var, bit1, bit2)          DEFINE_GENERIC_BIT_OP(set2)(var, bit1, bit2)
#define bit_set3(var, bit1, bit2, bit3)    DEFINE_GENERIC_BIT_OP(set3)(var, bit1, bit2, bit3)

#define bit_assign(var, bit_index)         DEFINE_GENERIC_BIT_OP(assign)(var, bit_index)
#define bit_assign2(var, bit1, bit2)       DEFINE_GENERIC_BIT_OP(assign2)(var, bit1, bit2)
#define bit_assign3(var, bit1, bit2, bit3) DEFINE_GENERIC_BIT_OP(assign3)(var, bit1, bit2, bit3)

#define bit_unset(var, bit_index)          DEFINE_GENERIC_BIT_OP(unset)(var, bit_index)
#define bit_unset2(var, bit1, bit2)        DEFINE_GENERIC_BIT_OP(unset2)(var, bit1, bit2)
#define bit_unset3(var, bit1, bit2, bit3)  DEFINE_GENERIC_BIT_OP(unset3)(var, bit1, bit2, bit3)

#define bit_get(var, bit_index)            DEFINE_GENERIC_CONST_BIT_OP(get)(var, bit_index)

#endif /* AVR_UTILS_COMMON_BIT_H_ */
