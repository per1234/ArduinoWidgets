//
//  AWPushButton.cpp
//  graphic
//
//  Created by Pierre Molinaro on 08/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWPushButton.h"
#include "AWContext.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static AWRect computePushButtonRelativeRect (const AWPoint & inRelativeOrigin,
                                             const AWInt inWidth,
                                             const AWFont & inFont) {
  AWRect r (inRelativeOrigin, AWSize ()) ;
  r.size.height = inFont.lineHeight () ;
  r.origin.y += inFont.descent () ;
  r.size.width = inWidth ;
  r.size.height += 2 * awkButtonVerticalMargin ;
  r.origin.y -= awkButtonVerticalMargin ;
  return r ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static AWInt computeVerticalMargin(const AWRect & inFrame, const AWFont & inFont)
{
  return (inFrame.size.height - inFont.lineHeight()) / 2 ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWPushButton::AWPushButton (const AWPoint & inRelativeBaselineOrigin,
                            const AWInt inWidth,
                            const String & inTitle,
                            const AWFont & inFont) :
AWView (computePushButtonRelativeRect (inRelativeBaselineOrigin, inWidth, inFont), awkResponderBackColor),
mTitle (inTitle),
mFont (inFont),
mTextColor (awkTextColor),
mStringDisplayLength (inFont.stringLength (inTitle)),
mVerticalMargin(awkButtonVerticalMargin),
mIsEnabled (true),
mHiliteState (false)
{
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
AWPushButton::AWPushButton (const AWRect & inFrame,
                            const String & inTitle,
                            const AWFont & inFont) :
AWView (inFrame, awkResponderBackColor),
mTitle(inTitle),
mFont(inFont),
mTextColor(awkTextColor),
mStringDisplayLength(inFont.stringLength(inTitle)),
mVerticalMargin(computeVerticalMargin(inFrame, inFont)),
mIsEnabled(true),
mHiliteState(false)
{
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWPushButton::setTitle (const String & inTitle) {
  if (mTitle != inTitle) {
    mTitle = inTitle ;
    mStringDisplayLength = font ().stringLength (mTitle) ;
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWPushButton::drawInRegion (const AWRegion & inDrawRegion) const {
//--- Fill button
  const AWRect af = absoluteFrame () ;
  AWContext::setColor (mHiliteState ? awkHiliteBackColor : (mIsEnabled ? backColor () : awkBackColor)) ;
  af.fillRoundRectInRegion (awkPushButtonRoundRadius, inDrawRegion) ;
//--- Frame button
  AWContext::setColor (mIsEnabled ? mTextColor : awkDisabledTextColor) ;
  af.frameRoundRectInRegion (awkPushButtonRoundRadius, inDrawRegion) ;
//--- Draw title
  const AWRect r = absoluteFrame () ;
  const AWInt x = r.origin.x + (r.size.width - mStringDisplayLength) / 2 ;
  const AWInt y = r.origin.y - font ().descent () + mVerticalMargin ;
  AWContext::setColor (mIsEnabled ? (mHiliteState ? awkHiliteTextColor : mTextColor) : awkDisabledTextColor) ;
  font ().drawStringInRegion (x, y, mTitle, inDrawRegion) ;
}


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWPushButton::isOpaque (void) const {
  return false ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWPushButton::setEnabled (const bool inState) {
  if (mIsEnabled != inState) {
    mIsEnabled = inState ;
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWPushButton::touchDown (const AWPoint & inPoint) {
  if (mIsEnabled) {
    mHiliteState = true ;
    setNeedsDisplay () ;
    super::touchDown (inPoint) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWPushButton::touchMove (const AWPoint & inPoint) {
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

void AWPushButton::touchUp (const AWPoint & inPoint) {
  if (mIsEnabled) {
    if (mHiliteState) {
      mHiliteState = false ;
      setNeedsDisplay () ;
    }
    const bool within = absoluteFrame ().containsPoint (inPoint) ;
    if (within) {
      sendAction () ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
