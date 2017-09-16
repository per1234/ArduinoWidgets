//
//  AWColor.cpp
//  graphic
//
//  Created by Pierre Molinaro on 07/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWColor.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWColor::operator == (const AWColor & inOtherColor) const {
  return (mRed == inOtherColor.mRed)
      && (mGreen == inOtherColor.mGreen)
      && (mBlue == inOtherColor.mBlue)
      && (mIsOpaque == inOtherColor.mIsOpaque) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

