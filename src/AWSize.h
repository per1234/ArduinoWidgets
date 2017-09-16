//
//  AWSize.hpp
//  graphic
//
//  Created by Pierre Molinaro on 06/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWSize_DEFINED
#define AWSize_DEFINED

#include "AWInt.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWSize {
//--- Default constructor (null size)
  public : inline AWSize (void) : width ((AWInt)0), height ((AWInt)0) {}

//--- Constructor
  public : inline AWSize (const AWInt inWidth, const AWInt inHeight) : width (inWidth), height (inHeight) {}

//--- Equatable
  public : inline bool operator == (const AWSize & inSize) const { return (width == inSize.width) && (height == inSize.height) ; }
  public : inline bool operator != (const AWSize & inSize) const { return !(*this == inSize) ; }


//--- Properties
  public : AWInt width ;
  public : AWInt height ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
