//
//  AWView.cpp
//  graphic
//
//  Created by Pierre Molinaro on 08/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWView.h"
#include "AWContext.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWView::AWView (const AWRect & inRelativeFrame, const AWColor & inBackColor) :
mRelativeFrame (inRelativeFrame),
mAbsoluteFrame (inRelativeFrame),
mBackColor (inBackColor),
mSuperView (NULL),
mSubviews (),
mTag (-1),
mAction (NULL),
mIsVisible (true),
mIsOnScreen (false) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWView:: ~ AWView (void) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   BACK COLOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::setBackColor (const AWColor & inBackColor) {
  if (mBackColor != inBackColor) {
    mBackColor = inBackColor ;
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   NEEDS DISPLAY
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static AWRegion gInvalidRegion ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWView::viewsNeedDisplay (void) {
  return !gInvalidRegion.isEmpty () ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::setNeedsDisplay (void) {
  if (mIsVisible && mIsOnScreen) {
    gInvalidRegion += mAbsoluteFrame ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::setNeedsDisplayInRect (const AWRect & inRect) {
  if (mIsVisible && mIsOnScreen) {
    gInvalidRegion += inRect & mAbsoluteFrame ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   DRAWING VIEW
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::drawInRegion (const AWRegion & inDrawRegion) const {
  AWContext::setColor (mBackColor) ;
  mAbsoluteFrame.fillRectInRegion (inDrawRegion) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   OPACITY
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWView::isOpaque (void) const {
  return mBackColor.isOpaque () ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   VIEW TRANSLATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::translateBy (const AWInt inDx, const AWInt inDy) {
  if ((inDx != 0) || (inDy != 0)) {
  //--- Mark old view rect as super view invalid rect
    setNeedsDisplay () ;
  //--- Perfom translation
    mRelativeFrame.translateBy (inDx, inDy) ;
    if (NULL != mSuperView) {
      const AWPoint p = mSuperView->absoluteFrame ().origin ;
      setAbsoluteFrameFromOrigin (p.x, p.y) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   ON SCREEN STATE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::setOnScreen (const bool inOnScreen) {
  mIsOnScreen = inOnScreen ;
  for (AWInt i=0 ; i<mSubviews.count () ; i++) {
    AWView * subview = mSubviews (i COMMA_HERE) ;
    subview->setOnScreen (inOnScreen) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   MANAGING VIEW HIERARCHY
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::removeFromSuperView (void) {
  setNeedsDisplay () ;
  if (NULL != mSuperView) {
    mSuperView->mSubviews.remove (this) ;
    mSuperView = NULL ;
    setOnScreen (false) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::addSubView (AWView * inView) {
  if (NULL != inView) {
    inView->removeFromSuperView () ;
    mSubviews.append (inView) ;
    inView->mSuperView = this ;
    setOnScreen (true) ;
    inView->setAbsoluteFrameFromOrigin (mAbsoluteFrame.origin.x, mAbsoluteFrame.origin.y) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::addCenteredSubView (AWView * inView) {
  if (NULL != inView) {
    inView->removeFromSuperView () ;
    mSubviews.append (inView) ;
    inView->mSuperView = this ;
    inView->translateBy(-inView->absoluteFrame().origin.x, -inView->absoluteFrame().origin.y) ;
    inView->translateBy((absoluteFrame ().size.width - inView->absoluteFrame ().size.width) / 2,
                        (absoluteFrame ().size.height - inView->absoluteFrame ().size.height) / 2) ;
    setOnScreen (true) ;
    inView->setAbsoluteFrameFromOrigin (mAbsoluteFrame.origin.x, mAbsoluteFrame.origin.y) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   CHANGING FRAME
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::setAbsoluteFrameFromOrigin (const AWInt inX, const AWInt inY) {
  mAbsoluteFrame = mRelativeFrame ;
  mAbsoluteFrame.translateBy (inX, inY) ;
  setNeedsDisplay () ;
  for (AWInt i=0 ; i<mSubviews.count () ; i++) {
    AWView * sbv = mSubviews (i COMMA_HERE) ;
    sbv->setAbsoluteFrameFromOrigin (mAbsoluteFrame.origin.x, mAbsoluteFrame.origin.y) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::setSize (const AWSize & inNewSize) {
  setNeedsDisplay () ;
  mRelativeFrame.size = inNewSize ;
  mAbsoluteFrame.size = inNewSize ;
  setNeedsDisplay () ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    VISIBILITY
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::setVisibility (const bool inIsVisible) {
  if (mIsVisible != inIsVisible) {
  //--- Temporary make the view visible for marking its rect as invalid
    mIsVisible = true ;
    setNeedsDisplay () ;
  //---
    mIsVisible = inIsVisible ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   TOUCH
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::touchDown (const AWPoint & /* inPoint */) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::touchMove (const AWPoint & /* inPoint */) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::touchUp (const AWPoint & /* inPoint */) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    ACTION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::sendAction (void) {
  if (NULL != mAction) {
    mAction (this) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   VIEW UTILITY
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWView * AWView::viewAtPoint (const AWPoint & inPoint) {
  AWView * result = NULL ;
  if (isVisible ()) {
    for (AWInt i=mSubviews.count () ; (i>0) && (NULL == result) ; i--) {
      AWView * subview = mSubviews (i-1 COMMA_HERE) ;
      AWView * view = subview->viewAtPoint (inPoint) ;
      if (NULL != view) {
        result = view ;
      }
    }
    if ((NULL == result) && mAbsoluteFrame.containsPoint (inPoint)) {
      result = this ;
    }
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   DRAWING
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::drawAllViews (const bool inFlashUpdate) const {
  AWRegion drawRegion = gInvalidRegion & AWContext::screenRect () ;
  drawViews (drawRegion, inFlashUpdate) ;
  if (!inFlashUpdate) {
    gInvalidRegion.release () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//#include "Simulator.h"

void AWView::drawViews (const AWRegion & inDrawRegion, const bool inFlashUpdate) const {
  if (isVisible () && !inDrawRegion.isEmpty ()) {
  //--- Draw view
    AWRegion currentDrawRegion = inDrawRegion ;
    for (AWInt i=0 ; (i<mSubviews.count ()) && !currentDrawRegion.isEmpty () ; i++) {
      AWView * subview = mSubviews (i COMMA_HERE) ;
      subview->removeOpaqueRegion (currentDrawRegion) ;
    }
    if (!currentDrawRegion.isEmpty ()) {
      if (inFlashUpdate) {
        mAbsoluteFrame.fillRectInRegion (currentDrawRegion) ;
      }else{
        drawInRegion (currentDrawRegion) ;
        // display () ;
      }
    }
  //--- Draw subviews
    for (AWInt i=0 ; i<mSubviews.count () ; i++) {
      AWView * subview = mSubviews (i COMMA_HERE) ;
      if (subview->isVisible ()) {
        AWRegion subviewDrawingRegion = inDrawRegion & subview->absoluteFrame () ;
        for (AWInt j=i+1 ; (j<mSubviews.count ()) && !subviewDrawingRegion.isEmpty () ; j++) {
          AWView * subviewAbove = mSubviews (j COMMA_HERE) ;
          subviewAbove->removeOpaqueRegion (subviewDrawingRegion) ;
        }
        if (!subviewDrawingRegion.isEmpty ()) {
          subview->drawViews (subviewDrawingRegion, inFlashUpdate) ;
        }
      }
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWView::removeOpaqueRegion (AWRegion & ioRegion) const {
  if (isVisible ()) {
    if (isOpaque ()) {
      ioRegion -= absoluteFrame () ;
    }else{
      for (AWInt i=0 ; (i<mSubviews.count ()) && !ioRegion.isEmpty () ; i++) {
        AWView * subview = mSubviews (i COMMA_HERE) ;
        subview->removeOpaqueRegion (ioRegion) ;
      }
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
