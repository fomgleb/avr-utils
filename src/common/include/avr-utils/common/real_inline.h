#ifndef AVR_UTILS_COMMON_REAL_INLINE_H_
#define AVR_UTILS_COMMON_REAL_INLINE_H_

#if defined(__OPTIMIZE__)
#define REAL_INLINE __attribute__((always_inline)) inline
#else /* defined(__OPTIMIZE__) */
#define REAL_INLINE inline
#endif /* !defined(__OPTIMIZE__) */

#endif /* AVR_UTILS_COMMON_REAL_INLINE_H_ */
