//
//  AWSwitch.cpp
//  graphic
//
//  Created by Pierre Molinaro on 20/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWSwitch.h"
#include "AWContext.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const AWInt MARGIN_BETWEEN_BOX_AND_TITLE = 3 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static AWRect computeSwitchRelativeRect (const AWPoint & inBaseLineRelativeOrigin,
                                         const String & inTitle,
                                         const AWFont & inFont) {
  AWRect r (inBaseLineRelativeOrigin, AWSize (inFont.stringLength (inTitle), inFont.lineHeight ())) ;
  r.origin.y += inFont.descent () ;
  r.origin.y -= awkButtonVerticalMargin ;
  r.size.height += 2 * awkButtonVerticalMargin ;
  const int boxWidth = inFont.lineHeight () ;
  r.size.width += boxWidth ;
  r.size.width += MARGIN_BETWEEN_BOX_AND_TITLE ;
  return r ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWSwitch::AWSwitch (const AWPoint & inBaseLineRelativeOrigin,
                    const String & inTitle,
                    const AWFont & inFont) :
AWView (computeSwitchRelativeRect (inBaseLineRelativeOrigin, inTitle, inFont), awkBackColor),
mTitle (inTitle),
mTextColor (awkTextColor),
mFont (inFont),
mChecked (false),
mHiliteState (false),
mIsEnabled (true) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSwitch::drawInRegion (const AWRegion & inDrawRegion) const {
  super::drawInRegion (inDrawRegion) ;
  AWRect r = absoluteFrame () ;
  AWContext::setColor (backColor()) ;
  r.fillRectInRegion (inDrawRegion) ;
//--- Draw box
  r = boxRect () ;
  const AWInt boxWidth = r.size.width ;
  AWContext::setColor (mHiliteState ? awkHiliteBackColor : awkResponderBackColor) ;
  r.fillRectInRegion (inDrawRegion) ;
  AWContext::setColor (mIsEnabled ? mTextColor : awkDisabledTextColor) ;
  r.frameRectInRegion (inDrawRegion) ;
  if (mChecked) {
    r.bottomLeft ().strokeLineInRegion (r.topRight (), inDrawRegion) ;
    r.topLeft ().strokeLineInRegion (r.bottomRight (), inDrawRegion) ;
  }
//--- Draw title
  r = absoluteFrame () ;
  const AWInt x = r.origin.x + boxWidth + MARGIN_BETWEEN_BOX_AND_TITLE ;
  const AWInt y = r.origin.y + awkButtonVerticalMargin - mFont.descent () ;
  mFont.drawStringInRegion (x, y, mTitle, inDrawRegion) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSwitch::setTitle (const String & inTitle) {
  if (mTitle != inTitle) {
    const int previousStringLength = mFont.stringLength (mTitle) ;
    const int newStringLength = mFont.stringLength (inTitle) ;
    if (previousStringLength != newStringLength) {
      AWSize size = absoluteFrame ().size ;
      size.width += newStringLength - previousStringLength ;
      setSize (size) ;
    }else{
      setNeedsDisplay () ;
    }
    mTitle = inTitle ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWSwitch::boxRect (void) const {
  const AWRect f = absoluteFrame () ;
  const AWInt boxWidth = mFont.lineHeight () ;
  return AWRect (f.origin.x, f.origin.y + awkButtonVerticalMargin, boxWidth, boxWidth) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSwitch::setChecked (const bool inChecked) {
  if (mChecked != inChecked) {
    mChecked = inChecked ;
    setNeedsDisplay () ;
    sendAction () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSwitch::setEnabled (const bool inState) {
  if (mIsEnabled != inState) {
    mIsEnabled = inState ;
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    TOUCH
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSwitch::touchDown (const AWPoint & inPoint) {
  if (mIsEnabled) {
    mHiliteState = true ;
    setNeedsDisplay () ;
    super::touchDown (inPoint) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSwitch::touchMove (const AWPoint & inPoint) {
  if (mIsEnabled) {
    const bool within = absoluteFrame ().containsPoint (inPoint) ;
    if (within != mHiliteState) {
      mHiliteState = within ;
      setNeedsDisplay () ;
    }
    super::touchMove (inPoint) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSwitch::touchUp (const AWPoint & inPoint) {
  if (mIsEnabled) {
    if (mHiliteState) {
      mHiliteState = false ;
      setNeedsDisplay () ;
    }
    const bool within = absoluteFrame ().containsPoint (inPoint) ;
    if (within) {
      setChecked (!mChecked) ;
      sendAction () ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
