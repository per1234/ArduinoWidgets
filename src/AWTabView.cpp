//
//  AWTabView.cpp
//  graphic
//
//  Created by Pierre Molinaro on 24/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWTabView.h"
#include "AWContext.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWTabView::AWTabView (const AWRect & inRelativeFrame,
                      const AWFont & inFont) :
AWView (inRelativeFrame, awkBackColor),
mFont (inFont),
mTabTitles (),
mTabViews (),
mContentView (NULL),
mHilitedTabIndexOnTouchDown (-1),
mHilitedTabIndex (-1),
mSelectedTabIndex (-1),
mBadges () {
  AWRect r (0, 0, inRelativeFrame.size.width, inRelativeFrame.size.height) ;
  mContentView = new AWView (contentRectFromFrame (r), awkBackColor) ;
  addSubView (mContentView) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWTabView::~ AWTabView (void) {
  delete mContentView ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWTabView::drawInRegion (const AWRegion & inDrawRegion) const {
//--- Draw separator line
  AWContext::setColor (awkTextColor) ;
  horizontalSeparator ().fillRectInRegion (inDrawRegion) ;
//--- Draw titles
  const int nt = (int) mTabTitles.count () ;
  if (nt == 0) { // Empty tab
    titleRect ().fillRectInRegion (inDrawRegion) ;
  }else{
  //--- Draw separators
    if (nt > 1) {
      const AWInt y = absoluteFrame().origin.y ;
      const AWInt height = titleHeight () ;
      AWContext::setColor (awkTextColor) ;
      for (AWInt i=1 ; i<nt ; i++) {
        const AWRect r (xTitleOriginForIndex (i) - 1, y, 1, height) ;
        r.fillRectInRegion (inDrawRegion) ;
      }
    }
  //--- Draw titles
    const AWInt y = absoluteFrame().origin.y - font ().descent () + awkButtonVerticalMargin ;
    for (AWInt i=0 ; i<nt ; i++) {
      AWColor backgroundColor = awkResponderBackColor ;
      AWColor textColor = awkTextColor ;
      if (mHilitedTabIndex == (int) i) {
        backgroundColor = awkHiliteBackColor ;
        textColor = awkHiliteTextColor ;
      }else if (mSelectedTabIndex == (int) i) {
        backgroundColor = awkSelectedBackColor ;
        textColor = awkSelectedTextColor ;
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
      if (mBadges (i COMMA_HERE)) {
        AWContext::setColor (awkBadgeColor) ;
        badgeRect (i).fillOvalInRegion (inDrawRegion) ;
      }
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   Touch
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWTabView::selectTabAtIndex (const AWInt inIndex) {
  if ((mSelectedTabIndex != inIndex) && (inIndex >= -1) && (inIndex <= (int) mTabTitles.count ())) {
  //--- Unselect previous tab
    if (mSelectedTabIndex >= 0) {
      const AWRect r = tabTitleRectForIndex (mSelectedTabIndex) ;
      setNeedsDisplayInRect (r) ;
      AWView * view = mTabViews (mSelectedTabIndex COMMA_HERE) ;
      view->removeFromSuperView () ;
    }
  //--- Select new tab
    mSelectedTabIndex = inIndex ;
  //--- Attach content view
    if (mSelectedTabIndex >= 0) {
      const AWRect r = tabTitleRectForIndex (mSelectedTabIndex) ;
      setNeedsDisplayInRect (r) ;
      AWView * view = mTabViews (mSelectedTabIndex COMMA_HERE) ;
      mContentView->addSubView (view) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   Touch
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWTabView::touchDown (const AWPoint & inPoint) {
//--- Find tab under touch
  bool found = false ;
  for (AWInt i=0 ; (i< (AWInt) mTabTitles.count ()) && !found ; i++) {
    const AWRect r = tabTitleRectForIndex (i) ;
    found = r.containsPoint (inPoint) ;
    if (found) {
      mHilitedTabIndex = i ;
      mHilitedTabIndexOnTouchDown = i ;
      setNeedsDisplayInRect (r) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWTabView::touchMove (const AWPoint & inPoint) {
  if (mHilitedTabIndexOnTouchDown >= 0) {
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

void AWTabView::touchUp (const AWPoint & inPoint) {
  if (mHilitedTabIndex >= 0) {
    AWInt newSelectedTabIndex = mSelectedTabIndex ;
    const AWRect hilitedTabRect = tabTitleRectForIndex (mHilitedTabIndex) ;
    setNeedsDisplayInRect (hilitedTabRect) ;
    const bool within = hilitedTabRect.containsPoint (inPoint) ;
    if (within) {
      newSelectedTabIndex = mHilitedTabIndex ;
    }
    mHilitedTabIndex = -1 ;
    mHilitedTabIndexOnTouchDown = -1 ;
    selectTabAtIndex (newSelectedTabIndex) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   ADD TAB
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWTabView::addTab (const String & inTitle, AWView * inView) {
  if (NULL != inView) {
    mTabTitles.append (inTitle) ;
    mTabViews.append (inView) ;
    mBadges.append (false) ;
    if (mTabTitles.count () == 1) {
      selectTabAtIndex (0) ;
    }else{
      setNeedsDisplayInRect (titleRect ()) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    BADGE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWTabView::setBadgeAtIndex (const AWInt inIndex, const bool inDisplayBadge) { // Does nothing if index if out of mList bounds
  if ((inIndex >= 0) && (inIndex < (int) mTabTitles.count ())) {
    if (mBadges (inIndex COMMA_HERE) != inDisplayBadge) {
      mBadges.setAtIndex (inDisplayBadge, inIndex COMMA_HERE) ;
      setNeedsDisplayInRect (badgeRect (inIndex)) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWTabView::hasBadgeAtIndex (const AWInt inIndex) const { // return false if index if out of mList bounds
  bool result = false ;
  if ((inIndex >= 0) && (inIndex < (int) mTabTitles.count ())) {
    result = mBadges (inIndex COMMA_HERE) ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   UTILITIES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWTabView::horizontalSeparator (void) const {
  AWRect r = absoluteFrame () ;
  r.origin.y += titleHeight () ;
  r.size.height = 1 ;
  return r ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWTabView::titleHeight (void) const {
  return font ().lineHeight () + 2 * awkButtonVerticalMargin ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWTabView::xTitleOriginForIndex (const AWInt inIndex) const {
  const AWRect r = absoluteFrame () ;
  AWInt result = r.origin.x ;
  const AWInt nt = (AWInt) mTabTitles.count () ;
  if (nt > 0) {
    result += (r.size.width + 1) * inIndex / nt ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWTabView::contentRectFromFrame (const AWRect & inFrame) const {
  const int titlePlusSeparatorHeight = titleHeight () + 1 ;
  AWRect r = inFrame ;
  r.origin.y += titlePlusSeparatorHeight ;
  r.size.height -= titlePlusSeparatorHeight ;
  return r ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWTabView::titleRect (void) const {
  AWRect r = absoluteFrame () ;
  r.size.height = titleHeight () ;
  return r ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWTabView::tabTitleRectForIndex (const AWInt inIndex) const {
  AWRect result ;
  const AWInt nt = (AWInt) mTabTitles.count () ;
  if ((inIndex >= 0) && (inIndex < nt)) {
    result = absoluteFrame () ;
    result.size.height = titleHeight () ;
    result.origin.x = xTitleOriginForIndex (inIndex) ;
    result.size.width = xTitleOriginForIndex (inIndex + 1) - result.origin.x - 1 ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWTabView::badgeRect (const AWInt inItemIndex) const {
  AWRect result ;
  if ((inItemIndex >= 0) && (inItemIndex < (int) mTabTitles.count ())) {
    result = tabTitleRectForIndex (inItemIndex) ;
    result.origin.x += result.size.width - awkBadgeSize - 1 ;
    result.origin.y += result.size.height - awkBadgeSize - 1 ;
    result.size.width = awkBadgeSize ;
    result.size.height = awkBadgeSize ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
