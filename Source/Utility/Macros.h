#pragma once

#ifndef MACROS_H_
#define MACROS_H_

#ifdef _MSC_VER
#define DAEDALUS_FORCEINLINE __forceinline
#else
#define DAEDALUS_FORCEINLINE inline __attribute__((always_inline))
#endif

#ifdef DAEDALUS_ENABLE_ASSERTS

#define NODEFAULT		DAEDALUS_ERROR( "No default - we shouldn't be here" )

#else

#ifdef _MSC_VER
#define NODEFAULT		__assume( 0 )
#else
#define NODEFAULT		//DAEDALUS_EXPECT_LIKELY(1)?
#endif

#endif

#ifndef ARRAYSIZE
#define ARRAYSIZE(arr)   (sizeof(arr) / sizeof(arr[0]))
#endif

#define DAEDALUS_USE(...)	do { (void)sizeof(__VA_ARGS__, 0); } while(0)

#endif // MACROS_H_
