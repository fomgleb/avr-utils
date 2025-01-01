#ifndef AVR_UTILS_COMMON_MATRIX_H_
#define AVR_UTILS_COMMON_MATRIX_H_

#include <limits.h>
#include <stdlib.h>
#include <inttypes.h>
#include "real_inline.h"

#define DEFINE_MATRIX_TYPE(TYPE, SUFFIX)                                                                               \
    typedef struct {                                                                                                   \
        TYPE* const _arr;                                                                                              \
        const uint8_t width;                                                                                           \
        const uint8_t height;                                                                                          \
    } matrix_##SUFFIX##_t;                                                                                             \
                                                                                                                       \
    static REAL_INLINE matrix_##SUFFIX##_t mx_##SUFFIX##_create(uint8_t w, uint8_t h) {                                \
        TYPE* arr = (TYPE*)malloc(w * (size_t)h * sizeof(TYPE));                                                       \
        if (!arr) {                                                                                                    \
            matrix_##SUFFIX##_t matrix = {._arr = NULL, .width = 0, .height = 0};                                      \
            return matrix;                                                                                             \
        }                                                                                                              \
        matrix_##SUFFIX##_t matrix = {                                                                                 \
            ._arr = arr,                                                                                               \
            .width = w,                                                                                                \
            .height = h,                                                                                               \
        };                                                                                                             \
        memset(arr, 0, w* h * sizeof(TYPE));                                                                           \
        return matrix;                                                                                                 \
    }                                                                                                                  \
                                                                                                                       \
    static REAL_INLINE void mx_##SUFFIX##_delete(const matrix_##SUFFIX##_t* m) {                                       \
        if (m && m->_arr) {                                                                                            \
            free(m->_arr);                                                                                             \
        }                                                                                                              \
    }                                                                                                                  \
                                                                                                                       \
    static REAL_INLINE void mx_##SUFFIX##_set(const matrix_##SUFFIX##_t* m, uint8_t x, uint8_t y, TYPE value) {        \
        m->_arr[y * m->width + x] = value;                                                                             \
    }                                                                                                                  \
                                                                                                                       \
    static REAL_INLINE TYPE mx_##SUFFIX##_get(const matrix_##SUFFIX##_t* m, uint8_t x, uint8_t y) {                    \
        return m->_arr[y * m->width + x];                                                                              \
    }

DEFINE_MATRIX_TYPE(int8_t, i8)
DEFINE_MATRIX_TYPE(uint8_t, u8)
DEFINE_MATRIX_TYPE(int16_t, i16)
DEFINE_MATRIX_TYPE(uint16_t, u16)
DEFINE_MATRIX_TYPE(int32_t, i32)
DEFINE_MATRIX_TYPE(uint32_t, u32)

#define mx_create(type, width, height)                                                                                 \
    _Generic(((type)0),                                                                                                \
        int8_t: mx_i8_create,                                                                                          \
        uint8_t: mx_u8_create,                                                                                         \
        int16_t: mx_i16_create,                                                                                        \
        uint16_t: mx_u16_create,                                                                                       \
        int32_t: mx_i32_create,                                                                                        \
        uint32_t: mx_u32_create)(width, height)

#define mx_delete(matrix_ptr)                                                                                          \
    _Generic((matrix_ptr),                                                                                             \
        matrix_i8_t *: mx_i8_delete,                                                                                   \
        matrix_u8_t *: mx_u8_delete,                                                                                   \
        matrix_i16_t *: mx_i16_delete,                                                                                 \
        matrix_u16_t *: mx_u16_delete,                                                                                 \
        matrix_i32_t *: mx_i32_delete,                                                                                 \
        matrix_u32_t *: mx_u32_delete)(matrix_ptr)

#define mx_set(matrix_ptr, x, y, value)                                                                                \
    _Generic((matrix_ptr),                                                                                             \
        matrix_i8_t *: mx_i8_set,                                                                                      \
        matrix_u8_t *: mx_u8_set,                                                                                      \
        matrix_i16_t *: mx_i16_set,                                                                                    \
        matrix_u16_t *: mx_u16_set,                                                                                    \
        matrix_i32_t *: mx_i32_set,                                                                                    \
        matrix_u32_t *: mx_u32_set)(matrix_ptr, x, y, value)

#define mx_get(matrix_ptr, x, y)                                                                                       \
    _Generic((matrix_ptr),                                                                                             \
        matrix_i8_t *: mx_i8_get,                                                                                      \
        matrix_u8_t *: mx_u8_get,                                                                                      \
        matrix_i16_t *: mx_i16_get,                                                                                    \
        matrix_u16_t *: mx_u16_get,                                                                                    \
        matrix_i32_t *: mx_i32_get,                                                                                    \
        matrix_u32_t *: mx_u32_get,                                                                                    \
        const matrix_i8_t*: mx_i8_get,                                                                                 \
        const matrix_u8_t*: mx_u8_get,                                                                                 \
        const matrix_i16_t*: mx_i16_get,                                                                               \
        const matrix_u16_t*: mx_u16_get,                                                                               \
        const matrix_i32_t*: mx_i32_get,                                                                               \
        const matrix_u32_t*: mx_u32_get)(matrix_ptr, x, y)

#endif /* AVR_UTILS_COMMON_MATRIX_H_ */
