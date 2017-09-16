//
//  AWSegmentedControl.cpp
//  graphic
//
//  Created by Pierre Molinaro on 24/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWSegmentedControl.h"
#include "AWContext.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static AWRect computSegmentedControlRelativeRect (const AWPoint & inRelativeOrigin,
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

AWSegmentedControl::AWSegmentedControl (const AWPoint & inRelativeBaselineOrigin,
                                        const AWInt inWidth,
                                        const AWFont & inFont) :
AWView (computSegmentedControlRelativeRect (inRelativeBaselineOrigin, inWidth, inFont), awkBackColor),
mFont (inFont),
mTabTitles (),
mHilitedTabIndexOnTouchDown (-1),
mHilitedTabIndex (-1),
mSelectedTabIndex (-1),
mSegmentedControlAction (NULL),
mIsEnabled (true) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSegmentedControl::drawInRegion (const AWRegion & inDrawRegion) const {
  const AWInt nt = mTabTitles.count () ;
//--- Frame segmented control
  AWContext::setColor ((!mIsEnabled || (nt == 0)) ? awkDisabledTextColor : awkTextColor) ;
  absoluteFrame ().frameRectInRegion (inDrawRegion) ;
//--- Draw titles
  if (nt == 0) { // Empty tab
    AWContext::setColor (awkBackColor) ;
    AWRect r = absoluteFrame () ;
    r.inset (1, 1) ;
    r.fillRectInRegion (inDrawRegion) ;
  }else{
  //--- Draw separators
    if (nt > 1) {
      const AWInt y = absoluteFrame().origin.y + 1 ;
      const AWInt height = absoluteFrame().size.height - 2 ;
      AWContext::setColor (mIsEnabled ? awkTextColor : awkDisabledTextColor) ;
      for (AWInt i=1 ; i<nt ; i++) {
        const AWRect r (xTitleOriginForIndex (i) - 1, y, 1, height) ;
        r.fillRectInRegion (inDrawRegion) ;
      }
    }
  //--- Draw titles
    const AWInt y = absoluteFrame().origin.y - font ().descent () + awkButtonVerticalMargin ;
    for (AWInt i=0 ; i<nt ; i++) {
      AWColor backgroundColor = mIsEnabled ? awkResponderBackColor : awkBackColor ;
      AWColor textColor = mIsEnabled ? awkTextColor : awkDisabledTextColor ;
      if (mHilitedTabIndex == (int) i) {
        backgroundColor = awkHiliteBackColor ;
        textColor = awkHiliteTextColor ;
      }else if (mSelectedTabIndex == (int) i) {
        backgroundColor = mIsEnabled ? awkSelectedBackColor : awkSelectedDisabledBackColor ;
        textColor = mIsEnabled ? awkSelectedTextColor : awkDisabledTextColor ;
      }
      AWRect tabTitleRect = tabTitleRectForIndex (i) ;
    //--- Draw background
      AWContext::setColor (backgroundColor) ;
      tabTitleRect.fillRectInRegion (inDrawRegion) ;
    //--- Draw title
      const String title = mTabTitles (i COMMA_HERE) ;
      const AWInt s = font ().stringLength (title) ;
      const AWInt x = xTitleOriginForIndex (i) ;
      const AWInt width = xTitleOriginForIndex (i+1) - x - 1 ;
      AWContext::setColor (textColor) ;
      font ().drawStringInRegion (x + (width - s) / 2, y, title, inDrawRegion & tabTitleRect) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   Touch
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSegmentedControl::selectTabAtIndex (const AWInt inIndex) {
  if ((mSelectedTabIndex != inIndex) && (inIndex >= -1) && (inIndex <= mTabTitles.count ())) {
  //--- Unselect previous tab
    if (mSelectedTabIndex >= 0) {
      const AWRect r = tabTitleRectForIndex (mSelectedTabIndex) ;
      setNeedsDisplayInRect (r) ;
    }
  //--- Select new tab
    mSelectedTabIndex = inIndex ;
  //--- Display newly selected tab
    if (mSelectedTabIndex >= 0) {
      const AWRect r = tabTitleRectForIndex (mSelectedTabIndex) ;
      setNeedsDisplayInRect (r) ;
    }
  //--- Run action
    sendAction () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   Touch
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSegmentedControl::touchDown (const AWPoint & inPoint) {
//--- Find tab under touch
  if (mIsEnabled) {
    bool found = false ;
    for (AWInt i=0 ; (i < mTabTitles.count ()) && !found ; i++) {
      const AWRect r = tabTitleRectForIndex (i) ;
      found = r.containsPoint (inPoint) ;
      if (found) {
        mHilitedTabIndex = i ;
        mHilitedTabIndexOnTouchDown = i ;
        setNeedsDisplayInRect (r) ;
      }
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSegmentedControl::touchMove (const AWPoint & inPoint) {
  if (mIsEnabled && (mHilitedTabIndexOnTouchDown >= 0)) {
    const AWRect r = tabTitleRectForIndex (mHilitedTabIndexOnTouchDown) ;
    const bool within = r.containsPoint (inPoint) ;
    if (within) {
      if (mHilitedTabIndex < 0) { ;
        mHilitedTabIndex = mHilitedTabIndexOnTouchDown ;
        setNeedsDisplayInRect (r) ;
      }
    }else if (mHilitedTabIndex >= 0) {
      mHilitedTabIndex = -1 ;
      setNeedsDisplayInRect (r) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSegmentedControl::touchUp (const AWPoint & inPoint) {
  if (mIsEnabled && (mHilitedTabIndex >= 0)) {
    const AWInt hilitedTabIndex = mHilitedTabIndex ;
    mHilitedTabIndex = -1 ;
    mHilitedTabIndexOnTouchDown = -1 ;
    const AWRect hilitedTabRect = tabTitleRectForIndex (hilitedTabIndex) ;
    setNeedsDisplayInRect (hilitedTabRect) ;
    const bool within = hilitedTabRect.containsPoint (inPoint) ;
    if (within) {
      if (mSegmentedControlAction == NULL) {
        selectTabAtIndex (hilitedTabIndex) ;
      }else{
        mSegmentedControlAction (this, hilitedTabIndex) ;
      }
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   ADD TAB
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSegmentedControl::addTab (const String & inTitle) {
  mTabTitles.append (inTitle) ;
  if (mTabTitles.count () == 1) {
    selectTabAtIndex (0) ;
  }else{
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   ADD TAB
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWSegmentedControl::setEnabled (const bool inEnabled) {
  if (mIsEnabled != inEnabled) {
    mIsEnabled = inEnabled ;
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   UTILITIES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWSegmentedControl::xTitleOriginForIndex (const AWInt inIndex) const {
  AWRect r = absoluteFrame () ;
  r.inset (1, 1) ;
  AWInt result = r.origin.x ;
  const int nt = (int) mTabTitles.count () ;
  if (nt > 0) {
    result += (r.size.width + 1) * inIndex / nt ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWSegmentedControl::tabTitleRectForIndex (const AWInt inIndex) const {
  AWRect result ;
  const int nt = (int) mTabTitles.count () ;
  if ((inIndex >= 0) && (inIndex < nt)) {
    result = absoluteFrame () ;
    result.inset (1, 1) ;
    result.origin.x = xTitleOriginForIndex (inIndex) ;
    result.size.width = xTitleOriginForIndex (inIndex + 1) - result.origin.x - 1 ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
