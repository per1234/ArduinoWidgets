//
//  AWLine.cpp
//  graphic
//
//  Created by Pierre Molinaro on 23/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWLine.h"
#include "AWContext.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWLine::AWLine (const AWPoint & inRelativePoint1,
                const AWPoint & inRelativePoint2) :

AWView (AWRect (inRelativePoint1, inRelativePoint2), awkTextColor),
mRelativePoint1 (inRelativePoint1),
mRelativePoint2 (inRelativePoint2),
mAbsolutePoint1 (),
mAbsolutePoint2 () {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWLine::setAbsoluteFrameFromOrigin (const AWInt inX, const AWInt inY) {
  super::setAbsoluteFrameFromOrigin (inX, inY) ;
  mAbsolutePoint1 = mRelativePoint1 ;
  mAbsolutePoint1.translateBy (inX, inY) ;
  mAbsolutePoint2 = mRelativePoint2 ;
  mAbsolutePoint2.translateBy (inX, inY) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWLine::drawInRegion (const AWRegion & inDrawRegion) const {
//  AWContext::setColor (AWColor::yellow ()) ;
//  absoluteFrame().fill (inDrawRegion) ;
  AWContext::setColor (backColor ()) ;
  mAbsolutePoint1.strokeLineInRegion(mAbsolutePoint2, inDrawRegion) ;
//  AWContext::setColor (AWColor::red ()) ;
//  AWRect::horizontalLine (mAbsoluteP1.x, mAbsoluteP1.y, 1).fill (inDrawRegion) ;
//  AWRect::horizontalLine (mAbsoluteP2.x, mAbsoluteP2.y, 1).fill (inDrawRegion) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
