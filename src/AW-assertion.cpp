//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//                    Exit on assert failure
//
//  Copyright (C) 2014, ..., 2017 Pierre Molinaro.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AW-assertion.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    assertionFailure
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// assertionFailure function is implementation dependant
// In Cocoa simulator, it is implemented in AppDelegate.mm and shows an alert.

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    assertionTest
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if ASSERTION_GENERATION == 1
  void assertionTest (const bool inCondition,
                      const char * inMessage,
                      const char * inSourceFile,
                      const int inSourceLine) {
    if (!inCondition) {
      assertionFailure (inMessage, 0, inSourceFile, inSourceLine) ;
    }
  }
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    macroCheckValidPointer
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if ASSERTION_GENERATION == 1
  void macroCheckValidPointer (const void * inPointer,
                               const char * inSourceFile,
                               const int inSourceLine) {
    if (NULL == inPointer) {
      assertionFailure ("NULL pointer", 0, inSourceFile, inSourceLine) ;
    }
  }
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
