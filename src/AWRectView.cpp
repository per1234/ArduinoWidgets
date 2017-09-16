//
//  AWRectView.cpp
//  graphic
//
//  Created by Pierre Molinaro on 22/07/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWRectView.h"
#include "AWContext.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRectView::AWRectView (const AWRect & inRelativeRect,
                        const AWColor & inBackColor,
                        const AWColor & inFrameColor,
                        const AWInt inMargin,
                        const AWInt inFrameThickness) :

AWView (inRelativeRect, inBackColor),
mFrameColor (inFrameColor),
mMargin(inMargin),
mFrameThickness(inFrameThickness)
{
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRectView::drawInRegion (const AWRegion & inDrawRegion) const
{
  AWRect r = absoluteFrame () ;
  //--- Frame
  AWContext::setColor (mFrameColor) ;
  r.frameRectInRegion (inDrawRegion) ;
  //--- Fill
  AWContext::setColor (backColor ()) ;
  r.inset (1, 1) ;
  r.fillRectInRegion (inDrawRegion) ;
  //--- Adorn
  if (mFrameThickness > 0) {
    AWContext::setColor (mFrameColor) ;
    r.inset (mMargin, mMargin) ;
    for (int i = 0; i < mFrameThickness; i++) {
      r.frameRectInRegion (inDrawRegion) ;
      r.inset (1, 1) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRectView::setFrameColor (const AWColor & inFrameColor) {
  if (mFrameColor != inFrameColor) {
    mFrameColor = inFrameColor ;
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

