// Copyright (c) 2021 Tencent. All rights reserved.

#ifndef SRC_PLATFORM_CROSS_PLATFORM_INCLUDE_TIM_CLOUD_COMM_H_
#define SRC_PLATFORM_CROSS_PLATFORM_INCLUDE_TIM_CLOUD_COMM_H_

#include <sys/types.h>

#ifndef _MSC_VER
// stdint.h is part of C99 but MSVC doesn't have it.
#include <stdint.h>         // For intptr_t.
#endif

/* define int types*/
#if defined(__GNUC__)

#ifndef    _STDINT_H

#if defined(__PROSPERO__) || defined(__ORBIS__)
typedef     u_int8_t            uint8_t;
typedef     u_int16_t           uint16_t;
typedef     u_int32_t           uint32_t;
typedef     u_int64_t           uint64_t;
#elif !defined(_SYS_TYPES_H)
typedef     signed char         int8_t;
typedef     signed short        int16_t;
typedef     signed int          int32_t;
typedef     signed long long    int64_t;
typedef     unsigned char       uint8_t;
typedef     unsigned short      uint16_t;
typedef     unsigned int        uint32_t;
typedef     unsigned long long  uint64_t;
#else
/* FreeBSD has these C99 int types defined in /sys/inttypes.h already */
typedef     u_int8_t            uint8_t;
typedef     u_int16_t           uint16_t;
typedef     u_int32_t           uint32_t;
typedef     u_int64_t           uint64_t;
#endif  // defined(__PROSPERO__) || defined(__ORBIS__)

#endif  // _STDINT_H

#elif defined(_MSC_VER)
typedef     signed char         int8_t;
typedef     signed short        int16_t;
typedef     signed int          int32_t;
typedef     signed __int64      int64_t;
typedef     unsigned char       uint8_t;
typedef     unsigned short      uint16_t;
typedef     unsigned int        uint32_t;
typedef     unsigned __int64    uint64_t;

/* the following definitions are from VS2010's stdint.h */
#ifndef _INTPTR_T_DEFINED
#define _INTPTR_T_DEFINED
#ifdef _WIN64
typedef __int64 intptr_t;
#else /* _WIN64 */
typedef  int intptr_t;
#endif /* _WIN64 */
#endif /* _INTPTR_T_DEFINED */

#ifndef _UINTPTR_T_DEFINED
#define _UINTPTR_T_DEFINED
#ifdef _WIN64
typedef unsigned __int64 uintptr_t;
#else /* _WIN64 */
typedef  unsigned int uintptr_t;
#endif /* _WIN64 */
#endif /* _UINTPTR_T_DEFINED */

#endif // COMPILER_GCC/COMPILER_MSVC


#ifndef __cplusplus

/* Even in pure C, we still need a standard boolean typedef */
#ifndef bool
typedef unsigned char bool;
#endif
#ifndef true
#define true (1)
#endif
#ifndef false
#define false (0)
#endif

#endif /* !__cplusplus */

#if defined(_WIN32) || defined(__PROSPERO__) || defined(__ORBIS__)
#if defined(ENABLE_STATIC_LIB)
#define TIM_API
#else
#if defined(TIM_EXPORTS) 
#define TIM_API __declspec(dllexport)
#else
#define TIM_API __declspec(dllimport)
#endif
#endif

#else 

#define TIM_API __attribute__ ((visibility ("default")))

#endif

#define TIM_DECL TIM_API

#endif  // SRC_PLATFORM_CROSS_PLATFORM_INCLUDE_TIM_CLOUD_COMM_H_
