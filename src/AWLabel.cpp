//
//  AWLabel.cpp
//  graphic
//
//  Created by Pierre Molinaro on 09/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWLabel.h"
#include "AWContext.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static AWRect computeLabelRelativeRect (const AWPoint & inRelativeOrigin,
                                        const AWInt inWidth,
                                        const AWFont & inFont) {
  AWRect r (inRelativeOrigin, AWSize (inWidth, inFont.lineHeight ())) ;
  r.origin.y += inFont.descent () ;
  return r ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWLabel::AWLabel (const AWPoint & inRelativeOrigin,
                  const AWInt inWidth,
                  const AWAlignment inAlignment,
                  const String & inTitle,
                  const AWFont & inFont) :
AWView (computeLabelRelativeRect (inRelativeOrigin, inWidth, inFont), AWColor ()),
mTitle (inTitle),
mTextColor (awkTextColor),
mFont (inFont),
mStringDisplayLength (inFont.stringLength (inTitle)),
mAlignment (inAlignment) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWLabel::setTextColor (const AWColor & inColor) {
  if (mTextColor != inColor) {
    mTextColor = inColor ;
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWLabel::drawInRegion (const AWRegion & inDrawRegion) const {
  super::drawInRegion (inDrawRegion) ;
  const AWRect r = absoluteFrame () ;
  AWContext::setColor (mTextColor) ;
  const AWInt y = r.origin.y - mFont.descent () ;
  AWInt x = r.origin.x ;
  switch (mAlignment) {
  case kAWAlignmentLeft :
    break ;
  case kAWAlignmentCenter :
    x += (r.size.width - mStringDisplayLength) / 2 ;
    break ;
  case kAWAlignmentRight :
    x += r.size.width - mStringDisplayLength ;
    break ;
  }
  mFont.drawStringInRegion (x, y, mTitle, inDrawRegion) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWLabel::setTitle (const String & inTitle) {
  if (mTitle != inTitle) {
    mTitle = inTitle ;
    mStringDisplayLength = mFont.stringLength (mTitle) ;
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWLabel::setAlignment (const AWAlignment inAlignment) {
  if (mAlignment != inAlignment) {
    mAlignment = inAlignment ;
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
