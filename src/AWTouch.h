//
//  AWTouch.h
//  graphic
//
//  Created by Pierre Molinaro on 21/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AW_TOUCH_CLASS_DEFINED
#define AW_TOUCH_CLASS_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "Arduino.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWTouch {
//--- Constructor
  public : AWTouch (const byte inCLK,
                    const byte inCS,
                    const byte inDIN,
                    const byte inDOUT,
                    const byte inIRQ) ;

//--- Public methods
  public : bool dataAvailable (void) const ;
  public : void read (uint16_t & outX, uint16_t & outY) const ;

//--- Properties
  private : const byte mCLK ;
  private : const byte mCS ;
  private : const byte mDIN ;
  private : const byte mDOUT ;
  private : const byte mIRQ ;

//--- Private method
  private : uint16_t readRegister (const byte inRegister) const ;

//--- No Copy
  private : AWTouch (const AWTouch &) ;
  private : AWTouch & operator = (const AWTouch &) ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
