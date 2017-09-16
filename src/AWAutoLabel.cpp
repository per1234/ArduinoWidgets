//
//  AWAutoLabel.cpp
//  graphic
//
//  Created by Pierre Molinaro on 24/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWAutoLabel.h"
#include "AWContext.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static AWRect computeAutoLabelRelativeRect (const AWPoint & inRelativeOrigin,
                                            const String & inTitle,
                                            const AWFont & inFont) {
  AWRect r (inRelativeOrigin, AWSize ()) ;
  r.size.height = inFont.lineHeight () ;
  r.origin.y += inFont.descent () ;
  r.size.width = inFont.stringLength (inTitle) ;
  return r ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWAutoLabel::AWAutoLabel (const AWPoint & inRelativeOrigin,
                          const String & inTitle,
                          const AWFont & inFont) :
AWView (computeAutoLabelRelativeRect (inRelativeOrigin, inTitle, inFont), AWColor ()),
mTitle (inTitle),
mTextColor (awkTextColor),
mTextFont (inFont) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWAutoLabel::setTextColor (const AWColor & inColor) {
  if (mTextColor != inColor) {
    mTextColor = inColor ;
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWAutoLabel::drawInRegion (const AWRegion & inDrawRegion) const {
//--- Draw background
  super::drawInRegion (inDrawRegion) ;
//--- Draw Label
  const AWPoint p = absoluteFrame ().origin ;
  AWContext::setColor (mTextColor) ;
  font ().drawStringInRegion (p.x, p.y - font ().descent(), mTitle, inDrawRegion) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWAutoLabel::setTitle (const String & inTitle) {
  if (mTitle != inTitle) {
    mTitle = inTitle ;
    const AWInt newDisplayLength = font ().stringLength (mTitle) ;
    setSize (AWSize (newDisplayLength, absoluteFrame ().size.height)) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
