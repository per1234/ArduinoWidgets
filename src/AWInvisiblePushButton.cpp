//
//  AWInvisiblePushButton.cpp
//  graphic
//
//  Created by Pierre Molinaro on 08/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWInvisiblePushButton.h"
#include "AWContext.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInvisiblePushButton::AWInvisiblePushButton (const AWRect & inRelativeFrame) :
AWView (inRelativeFrame, AWColor ()) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWInvisiblePushButton::drawInRegion (const AWRegion & inDrawRegion) const {
// Transparent: draw nothing
}


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWInvisiblePushButton::touchUp (const AWPoint & inPoint) {
  const bool within = absoluteFrame ().containsPoint (inPoint) ;
  if (within) {
    sendAction () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
