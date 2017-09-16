//
//  AWArrowPushButton.cpp
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 04/08/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#include "AWArrowPushButton.h"
#include "AWContext.h"
#include "AW-settings.h"

//-----------------------------------------------------------------------------

AWArrowPushButton::AWArrowPushButton(const AWRect & inRelativeFrame,
                                     const uint32_t inArrowDirection,
                                     const AWColor & inArrowColor) :
AWView(inRelativeFrame, awkResponderBackColor),
mArrowDirection(inArrowDirection),
mArrowColor(inArrowColor),
mIsEnabled (true),
mIsOn(false),
mOnOffState(false),
mHiliteState(false)
{
}

//-----------------------------------------------------------------------------

void AWArrowPushButton::drawInRegion (const AWRegion & inDrawRegion) const
{
  //--- Fill button
  AWRect af = absoluteFrame () ;
  AWContext::setColor (mHiliteState ? awkHiliteBackColor : (mIsEnabled ? ( mOnOffState ? awkHiliteBackColor : backColor ()) : awkBackColor)) ;
  af.fillRoundRectInRegion (awkPushButtonRoundRadius, inDrawRegion) ;
  //--- Frame button
  AWContext::setColor (mIsEnabled ? AWColor::black() : awkDisabledTextColor) ;
  af.frameRoundRectInRegion (awkPushButtonRoundRadius, inDrawRegion) ;
  //--- Arrow
  AWSize buttonSize = af.size ;
  AWRect arrow = af ;
  AWContext::setColor ( mHiliteState ? AWColor::lightGray() : mArrowColor ) ;
  switch (mArrowDirection)
  {
    case kUpArrow:
      af.inset ( 3 * buttonSize.width / 8, 3 * buttonSize.width / 8 ) ;
      af.size.height -= buttonSize.width / 3 ;
      arrow.inset ( buttonSize.width / 6, 3 * buttonSize.width / 8 ) ;
      arrow.size.height = 1 ;
      arrow.origin.y += buttonSize.height - 3 * buttonSize.width / 4 - buttonSize.width / 3 ;
      while (arrow.size.width > 0) {
        arrow.fillRectInRegion ( inDrawRegion ) ;
        arrow.inset (1, 0) ;
        arrow.origin.y++ ;
      }
      break ;
    case kDownArrow:
      af.inset ( 3 * buttonSize.width / 8, 3 * buttonSize.width / 8 ) ;
      af.size.height -= buttonSize.width / 3 ;
      af.origin.y += buttonSize.width / 3 ;
      arrow.inset ( buttonSize.width / 6, 3 * buttonSize.width / 8 ) ;
      arrow.size.height = 1 ;
      arrow.origin.y += buttonSize.width / 3 ;
      while (arrow.size.width > 0) {
        arrow.fillRectInRegion ( inDrawRegion ) ;
        arrow.inset (1, 0) ;
        arrow.origin.y-- ;
      }
      break ;
    case kRightArrow:
      af.inset ( 3 * buttonSize.height / 8, 3 * buttonSize.height / 8 ) ;
      af.size.width -= buttonSize.height / 3 ;
      arrow.inset ( 3 * buttonSize.height / 8 , buttonSize.height / 6 ) ;
      arrow.size.width = 1 ;
      arrow.origin.x += buttonSize.width - 3 * buttonSize.height / 4 - buttonSize.height / 3 ;
      while (arrow.size.height > 0) {
        arrow.fillRectInRegion ( inDrawRegion ) ;
        arrow.inset (0, 1) ;
        arrow.origin.x++ ;
      }
      break ;
    case kLeftArrow:
      af.inset ( 3 * buttonSize.height / 8, 3 * buttonSize.height / 8 ) ;
      af.size.width -= buttonSize.height / 3 ;
      af.origin.x += buttonSize.height / 3 ;
      arrow.inset ( 3 * buttonSize.height / 8, buttonSize.height / 6 ) ;
      arrow.size.width = 1 ;
      arrow.origin.x += buttonSize.height / 3 ;
      while (arrow.size.height > 0) {
        arrow.fillRectInRegion ( inDrawRegion ) ;
        arrow.inset (0, 1) ;
        arrow.origin.x-- ;
      }
      break ;
  }
  af.fillRectInRegion ( inDrawRegion ) ;
}

//————————————————————————————————————————————————————————————————————————————-

bool AWArrowPushButton::isOpaque (void) const {
  return false ;
}

//—————————————————————————————————————————————————————————————————————————————

void AWArrowPushButton::setEnabled (const bool inState) {
  if (mIsEnabled != inState) {
    mIsEnabled = inState ;
    setNeedsDisplay () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————

void AWArrowPushButton::touchDown (const AWPoint & inPoint) {
  if (mIsEnabled) {
    mHiliteState = true ;
    setNeedsDisplay () ;
    super::touchDown (inPoint) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————

void AWArrowPushButton::touchMove (const AWPoint & inPoint) {
  if (mIsEnabled) {
    const bool within = absoluteFrame ().containsPoint (inPoint) ;
    if (within != mHiliteState) {
      mHiliteState = within ;
      setNeedsDisplay () ;
    }
    super::touchMove (inPoint) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————

void AWArrowPushButton::touchUp (const AWPoint & inPoint) {
  if (mIsEnabled) {
    if (mHiliteState) {
      mHiliteState = false ;
      setNeedsDisplay () ;
    }
    const bool within = absoluteFrame ().containsPoint (inPoint) ;
    if (within) {
      if (mIsOn) mOnOffState = ! mOnOffState ;
      sendAction () ;
    }
  }
}

