//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//                    Exit on assert failure
//
//  Copyright (C) 2014, ..., 2014 Pierre Molinaro.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef ASSERTION_FAILURE_ROUTINE_DEFINED
#define ASSERTION_FAILURE_ROUTINE_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <stddef.h>
#include <stdint.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   For disabling debugging:
// #define ASSERTION_GENERATION 0
//   For enabling debugging:
// #define ASSERTION_GENERATION 1
//
// Debugging should be disabled on Arduino, unless you provide a assertionFailure function.
// On Mac OS simulator, assertion generation can be enabled or disabled. The assertionFailure function is
// implemented in AppDelegate.mm; assertion violation presents an alert.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// The following definition enables debugging on OS X, and disables it on Arduino.

#ifdef __APPLE__
  #define ASSERTION_GENERATION 1
#else
  #define ASSERTION_GENERATION 0
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if ASSERTION_GENERATION == 1
  #define HERE __FILE__, __LINE__
  #define COMMA_HERE , HERE
  #define THERE IN_SOURCE_FILE, IN_SOURCE_LINE
  #define COMMA_THERE , THERE
  #define LOCATION_ARGS const char * IN_SOURCE_FILE, const int32_t IN_SOURCE_LINE
  #define UNUSED_LOCATION_ARGS const char *, const int32_t
  #define COMMA_LOCATION_ARGS , LOCATION_ARGS
  #define COMMA_UNUSED_LOCATION_ARGS , UNUSED_LOCATION_ARGS
#else
  #define HERE
  #define COMMA_HERE
  #define THERE
  #define COMMA_THERE
  #define LOCATION_ARGS void
  #define UNUSED_LOCATION_ARGS void
  #define COMMA_LOCATION_ARGS
  #define COMMA_UNUSED_LOCATION_ARGS
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if ASSERTION_GENERATION == 1
  void assertionFailure (const char * inMessage,
                         const uint32_t inValue,
                         const char * inSourceFile,
                         const int inSourceLine) ;
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if ASSERTION_GENERATION == 1
  void assertionTest (const bool inCondition,
                      const char * inMessage,
                      const char * inSourceFile,
                      const int inSourceLine) ;
  #define macroAssertHere(CONDITION,MESSAGE) assertionTest (CONDITION, MESSAGE COMMA_HERE) ;
  #define macroAssertThere(CONDITION,MESSAGE) assertionTest (CONDITION, MESSAGE COMMA_THERE) ;
#else
  #define macroAssertHere(CONDITION,MESSAGE)
  #define macroAssertThere(CONDITION,MESSAGE)
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if ASSERTION_GENERATION == 1
  void macroCheckValidPointer (const void * inPointer,
                               const char * inSourceFile,
                               const int inSourceLine) ;
  #define macroValidPointerHere(PTR) macroCheckValidPointer (PTR COMMA_HERE)
  #define macroValidPointerThere(PTR) macroCheckValidPointer (PTR COMMA_THERE)
#else
  #define macroValidPointerHere(PTR)
  #define macroValidPointerThere(PTR)
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
