//
//  AWListView.cpp
//  graphic
//
//  Created by Pierre Molinaro on 21/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWListView.h"
#include "AWContext.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWListView::AWListView (const AWRect & inRelativeFrame,
                        const String & inTitle,
                        const AWFont & inFont) :
AWView (inRelativeFrame, awkResponderBackColor),
mTitle (inTitle),
mTitleDisplayLength (inFont.stringLength (inTitle)),
mFont (inFont),
mList (),
mHilitedItemIndex (-1),
mSelectedItemIndex (-1),
mTouchPointY (0),
mVerticalScroll (0),
mScrolling (false) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const AWInt LEFT_MARGIN = 2 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWListView::drawInRegion (const AWRegion & inDrawRegion) const {
//--- Draw list title
  const AWRect rTitle = titleRect () ;
  const AWRegion titleDrawRegion = inDrawRegion & rTitle ;
  if (!titleDrawRegion.isEmpty ()) {
    AWContext::setColor (awkBackColor) ;
    rTitle.fillRectInRegion (inDrawRegion) ;
    AWPoint p = rTitle.origin ;
    p.x += (rTitle.size.width - mTitleDisplayLength) / 2 ;
    p.y += - font ().descent () ;
    AWContext::setColor (awkTextColor) ;
    font ().drawStringInRegion (p.x, p.y, mTitle, inDrawRegion) ;
  }
//--- Draw item list
  const AWRect r = listRect () ;
  const AWRegion listDrawRegion = inDrawRegion & r ;
  if (!listDrawRegion.isEmpty ()) {
    const AWInt  ascent = font ().ascent () ;
    const AWInt descent = font ().descent () ; // ⚠︎ Negative value
    AWContext::setColor (awkTextColor) ;
    const AWInt x = r.origin.x + LEFT_MARGIN ;
    AWInt y = r.origin.y + r.size.height + mVerticalScroll ;
    AWRect itemRect (r.origin.x, y, r.size.width, ascent - descent + 2 * awkButtonVerticalMargin) ;
    for (AWInt i=0 ; (i<mList.count ()) && (y > r.origin.y) ; i++) {
      AWColor backgroundColor = backColor () ;
      AWColor textColor = awkTextColor ;
      if (mHilitedItemIndex == (int) i) {
        backgroundColor = awkHiliteBackColor ;
        textColor = awkHiliteTextColor ;
      }else if (mSelectedItemIndex == (int) i) {
        backgroundColor = awkSelectedBackColor ;
        textColor = awkSelectedTextColor ;
      }
      AWContext::setColor (backgroundColor) ;
      itemRect.origin.y -= ascent - descent + 2 * awkButtonVerticalMargin ;
      itemRect.fillRectInRegion (listDrawRegion) ;
      itemRect.origin.y -= 1 ;
      AWContext::setColor (textColor) ;
      y -= ascent + awkButtonVerticalMargin + 1 ;
      const String s = mList (i COMMA_HERE).mName ;
      font ().drawStringInRegion (x, y, s, listDrawRegion) ;
      y += descent - awkButtonVerticalMargin ;
      AWContext::setColor (awkTextColor) ;
      AWRect::horizontalLine (r.origin.x, y, r.size.width).fillRectInRegion (listDrawRegion) ;
      if (mList (i COMMA_HERE).mHasBadge) {
        AWContext::setColor (awkBadgeColor) ;
        badgeRect (i).fillOvalInRegion (inDrawRegion) ;
      }
    }
    if (y > r.origin.y) {
      AWContext::setColor (backColor ()) ;
      itemRect.origin.y = r.origin.y ;
      itemRect.size.height = y - r.origin.y ;
      itemRect.fillRectInRegion (listDrawRegion) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWListView::append (const String & inName, const int inTag) {
  mList.append (cListViewElement (inName, inTag)) ;
  setNeedsDisplay () ;
  if (mList.count () == 1) {
    selectItemAtIndex (0) ;
    mSelectedItemIndex = 0 ;
    sendAction () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWListView::selectItemAtIndex (const AWInt inIndex) { // Does nothing if index if out of mList bounds
  if ((inIndex >= 0) && (inIndex < mList.count ()) && (mSelectedItemIndex != inIndex)) {
    setNeedsDisplayInRect (itemRect (mSelectedItemIndex)) ;
    mSelectedItemIndex = inIndex ;
    setNeedsDisplayInRect (itemRect (mSelectedItemIndex)) ;
    sendAction () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWListView::selectItemForTag (const int inTag) { // Does nothing if tag does not fit any item
  bool found = false ;
  for (AWInt i=0 ; (i<mList.count ()) && !found ; i++) {
    found = mList (i COMMA_HERE).mTag == inTag ;
    if (found) {
      selectItemAtIndex (i) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWListView::removeItemAtIndex (const AWInt inIndex) { // Does not if index if out of mList bounds
  if ((inIndex >= 0) && (inIndex < mList.count ())) {
    mList.removeAtIndex (inIndex COMMA_HERE) ;
  //--- Adjust scrolling
    const AWInt ms = maxScroll () ;
    if (mVerticalScroll > ms) {
      mVerticalScroll = ms ;
    }
  //--- If removed item was hilited, hilite none
    if (mHilitedItemIndex == inIndex) {
      mHilitedItemIndex = -1 ;
    }
  //--- Selected item
    if (mSelectedItemIndex == inIndex) { // Selected item is the removed one
    //--- Do not change selected item index: it means that the next item becomes selected
    //    But if the selected item was the las one, we select the previous one
      if (mSelectedItemIndex >= mList.count ()) {
        mSelectedItemIndex = mList.count () - 1 ; // No selection if mList is empty
      }
    //--- Tell the selection did change
      sendAction () ;
    }else if (mSelectedItemIndex > inIndex) { // Selected item is after the removed item
      mSelectedItemIndex -= 1 ;
    }
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWListView::insertItemAtIndex (const AWInt inIndex, const String & inItemName, const int inItemTag) { // Does not if index if out of mList bounds
  if ((inIndex >= 0) && (inIndex <= mList.count ())) {
    mList.insertAtIndex (cListViewElement (inItemName, inItemTag), inIndex COMMA_HERE) ;
    if (mHilitedItemIndex >= inIndex) {
      mHilitedItemIndex += 1 ;
    }
    if (mSelectedItemIndex >= inIndex) {
      mSelectedItemIndex += 1 ;
    }
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWListView::setNameAtIndex (const AWInt inIndex, const String & inItemName) { // Does not if index if out of mList bounds
  if ((inIndex >= 0) && (inIndex < mList.count ())) {
    mList (inIndex COMMA_HERE).mName = inItemName ;
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

String AWListView::itemAtIndex (const AWInt inIndex COMMA_LOCATION_ARGS) const {
  return mList (inIndex COMMA_THERE).mName ;
}
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWListView::removeAllItems (void) {
  if (mList.count () > 0) {
    mList.free () ;
    mHilitedItemIndex = -1 ;
    if (mSelectedItemIndex >= 0) {
      mSelectedItemIndex = -1 ;
      sendAction () ;
    }
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    BADGE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWListView::setBadgeAtIndex (const AWInt inIndex, const bool inDisplayBadge) { // Does nothing if index if out of mList bounds
  if ((inIndex >= 0) && (inIndex < mList.count ())) {
    if (mList (inIndex COMMA_HERE).mHasBadge != inDisplayBadge) {
      mList (inIndex COMMA_HERE).mHasBadge = inDisplayBadge ;
      setNeedsDisplayInRect (badgeRect (inIndex)) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWListView::hasBadgeAtIndex (const AWInt inIndex) const { // return false if index if out of mList bounds
  bool result = false ;
  if ((inIndex >= 0) && (inIndex < mList.count ())) {
    result = mList (inIndex COMMA_HERE).mHasBadge ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    BADGE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWListView::setTagAtIndex (const AWInt inIndex, const int inTag) { // Does nothing if index if out of mList bounds
  if ((inIndex >= 0) && (inIndex < mList.count ())) {
    mList (inIndex COMMA_HERE).mTag = inTag ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

int AWListView::tagAtIndex (const AWInt inIndex) const { // return -1 if index if out of mList bounds
  int result = -1 ;
  if ((inIndex >= 0) && (inIndex < mList.count ())) {
    result = mList (inIndex COMMA_HERE).mTag ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

int AWListView::selectedTag (void) const { // return -1 if index if out of mList bounds
  int result = -1 ;
  if (mSelectedItemIndex >= 0) {
    result = mList (mSelectedItemIndex COMMA_HERE).mTag ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWListView::itemIndexForTag (const int inTag) const { // return -1 if no item has the tag
  AWInt result = -1 ;
  bool found = false ;
  for (AWInt i=0 ; (i<mList.count ()) && !found ; i++) {
    found = mList (i COMMA_HERE).mTag == inTag ;
    if (found) {
      result = i ;
    }
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    TOUCH
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWListView::touchDown (const AWPoint & inPoint) {
  mTouchPointY = inPoint.y ;
  const AWInt hilitedItemIndex = itemAtPoint (inPoint) ;
  if (hilitedItemIndex >= 0) { // Ignore if touch down occurs outside an item
    if (mHilitedItemIndex != hilitedItemIndex) {
      if (mHilitedItemIndex >= 0) {
        setNeedsDisplayInRect (itemRect (mHilitedItemIndex)) ;
      }
      mHilitedItemIndex = hilitedItemIndex ;
      if (mHilitedItemIndex >= 0) {
        setNeedsDisplayInRect (itemRect (mHilitedItemIndex)) ;
      }
      if (mSelectedItemIndex >= 0) {
        setNeedsDisplayInRect (itemRect (mSelectedItemIndex)) ;
      }
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWListView::touchMove (const AWPoint & inPoint) {
  const AWInt dy = inPoint.y - mTouchPointY ;
  if (abs (dy) > 10) {
    AWInt newScroll = mVerticalScroll + dy ;
    if (newScroll < 0) {
      newScroll = 0 ;
    }else if (newScroll > 0) {
      const AWInt m = maxScroll () ;
      if (newScroll > m) {
        newScroll = m ;
      }
    }
    if (mVerticalScroll != newScroll) {
      mScrolling = true ;
      mTouchPointY += newScroll - mVerticalScroll ;
      mVerticalScroll = newScroll ;
      setNeedsDisplay () ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWListView::touchUp (const AWPoint & inPoint) {
  bool selectionDidChange = false ;
  if (mScrolling) {
    mScrolling = false ;
    if (mSelectedItemIndex >= 0) {
      setNeedsDisplayInRect (itemRect (mSelectedItemIndex)) ;
    }
  }else{
    const AWInt newSelectedItemIndex = itemAtPoint (inPoint) ;
    if (newSelectedItemIndex >= 0) { // Ignore if touch up occurs outside an item
      if (mSelectedItemIndex != newSelectedItemIndex) {
        selectionDidChange = true ;
        if (mSelectedItemIndex >= 0) {
          setNeedsDisplayInRect (itemRect (mSelectedItemIndex)) ;
        }
        mSelectedItemIndex = newSelectedItemIndex ;
        setNeedsDisplayInRect (itemRect (mSelectedItemIndex)) ;
      }
    }
  }
  if (mHilitedItemIndex >= 0) {
    setNeedsDisplayInRect (itemRect (mHilitedItemIndex)) ;
    mHilitedItemIndex = -1 ;
  }
  if (selectionDidChange) {
    sendAction () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//    UTILITIES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWListView::itemAtPoint (const AWPoint & inPoint) const {
  AWInt result = -1 ; // Not found
  const AWRect r = listRect () ;
  if (r.containsPoint (inPoint)) {
    AWInt y = r.origin.y + r.size.height + mVerticalScroll ;
    const AWInt  ascent = font ().ascent () ;
    const AWInt descent = font ().descent () ; // Negative value
    for (AWInt i=0 ; (i<mList.count ()) && (result < 0) ; i++) {
      const AWInt bottom = y - ascent + descent - 2 * awkButtonVerticalMargin ;
      if ((inPoint.y <= y) && (inPoint.y >= bottom)) {
        result = i ;
      }
      y = bottom - 1 ;
    }
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWListView::itemRect (const AWInt inItemIndex) const {
  AWRect result ; // Empty rect
  if ((inItemIndex >= 0) && (inItemIndex < (int) mList.count ())) {
    result = listRect () ;
    result.origin.y += result.size.height + 1 ;
    result.origin.y += mVerticalScroll ;
    result.size.height = font ().ascent () - font ().descent () + 2 * awkButtonVerticalMargin ;
    result.origin.y -= (result.size.height + 1) * (inItemIndex + 1) ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWListView::badgeRect (const AWInt inItemIndex) const {
  AWRect result ; // Empty rect
  if ((inItemIndex >= 0) && (inItemIndex < mList.count ())) {
    result = listRect () ;
    const AWInt itemHeight = font ().lineHeight () + 2 * awkButtonVerticalMargin ;
    result.origin.y += result.size.height - 1 ;
    result.origin.y += mVerticalScroll ;
    result.origin.y -= itemHeight * inItemIndex ;
    result.origin.y -= awkBadgeSize ;
    result.size.height = awkBadgeSize ;
    result.origin.x += result.size.width - awkBadgeSize - 1 ;
    result.size.width =  awkBadgeSize ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWListView::hasBadge (void) const { // return true if one or more items have a badge
  bool result = false ;
  for (AWInt i=0 ; i< mList.count () && !result ; i++) {
    result = mList (i COMMA_HERE).mHasBadge ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWListView::maxScroll (void) const {
  const AWInt itemSize = font ().lineHeight () + 2 * awkButtonVerticalMargin ;
  const AWInt totalSize = itemSize * mList.count () - 2 ;
  AWInt result = totalSize - listRect ().size.height ;
  if (result < 0) {
    result = 0 ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWListView::titleRect (void) const {
  AWRect r = absoluteFrame () ;
  const AWInt height = font ().lineHeight () ;
  r.origin.y += r.size.height ;
  r.origin.y -= height ;
  r.size.height = height ;
  return r ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWListView::listRect (void) const {
  AWRect r = absoluteFrame () ;
  const AWInt height = font ().lineHeight () ;
  r.size.height -= height ;
  return r ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
