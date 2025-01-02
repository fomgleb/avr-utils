#ifndef AVR_UTILS_COMMON_POINT_H_
#define AVR_UTILS_COMMON_POINT_H_

#include <inttypes.h>
#include "real_inline.h"

#define DEFINE_POINT_TYPE(TYPE, SUFFIX)                                                                                \
    typedef struct {                                                                                                   \
        TYPE x;                                                                                                        \
        TYPE y;                                                                                                        \
    } point_##SUFFIX##_t;                                                                                              \
                                                                                                                       \
    static REAL_INLINE point_##SUFFIX##_t pnt_##SUFFIX##_sum(point_##SUFFIX##_t p1, point_##SUFFIX##_t p2) {           \
        return (point_##SUFFIX##_t){.x = p1.x + p2.x, .y = p1.y + p2.y};                                               \
    }

DEFINE_POINT_TYPE(uint8_t, u8)
DEFINE_POINT_TYPE(int8_t, i8)
DEFINE_POINT_TYPE(uint16_t, u16)
DEFINE_POINT_TYPE(int16_t, i16)
DEFINE_POINT_TYPE(uint32_t, u32)
DEFINE_POINT_TYPE(int32_t, i32)

#define DEFINE_POINT_CAST(point, TYPE, SUFFIX) ((point_##SUFFIX##_t){.x = (TYPE)(point.x), .y = (TYPE)(point.y)})

#define POINT_U8(point)                        DEFINE_POINT_CAST(point, uint8_t, u8)
#define POINT_I8(point)                        DEFINE_POINT_CAST(point, int8_t, i8)
#define POINT_U16(point)                       DEFINE_POINT_CAST(point, uint16_t, u16)
#define POINT_I16(point)                       DEFINE_POINT_CAST(point, int16_t, i16)
#define POINT_U32(point)                       DEFINE_POINT_CAST(point, uint32_t, u32)
#define POINT_I32(point)                       DEFINE_POINT_CAST(point, int32_t, i32)

#define pnt_sum(point1, point2)                                                                                        \
    _Generic((point1),                                                                                                 \
        point_u8_t: pnt_u8_sum,                                                                                        \
        point_i8_t: pnt_i8_sum,                                                                                        \
        point_u16_t: pnt_u16_sum,                                                                                      \
        point_i16_t: pnt_i16_sum,                                                                                      \
        point_u32_t: pnt_u32_sum,                                                                                      \
        point_i32_t: pnt_i32_sum)((point1), (point2))

#endif /* AVR_UTILS_COMMON_POINT_H_ */
