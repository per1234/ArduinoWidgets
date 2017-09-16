//
//  AWListView.hpp
//  graphic
//
//  Created by Pierre Molinaro on 21/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWListView_DEFINED
#define AWListView_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "WString.h"
#include "AWView.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWListView : public AWView {
//--- Constructor
  public : AWListView (const AWRect & inRelativeFrame,
                       const String & inTitle,
                       const AWFont & inFont = awkDefaultFont) ;

//--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;

//---------------- Properties
//--- List View Title
  private : String mTitle ;
  private : AWInt mTitleDisplayLength ;

//---------------- Font
  private : AWFont mFont ;
  public : inline AWFont font (void) const { return mFont ; }

//---------------- Private internal class
  private : class cListViewElement {
  //--- Default constructor
    public : cListViewElement (void) : mName (), mTag (-1), mHasBadge (false) {}

  //--- Constructor
    public : cListViewElement (const String & inName, const int inTag) : mName (inName), mTag (inTag), mHasBadge (false) {}

  //--- Properties
    public : String mName ;
    public : int mTag ;
    public : bool mHasBadge ;
  } ;

//---------------- List
  private : AWUniqueArray <cListViewElement> mList ;
  private : AWInt mHilitedItemIndex ; // -1 <-> none
  private : AWInt mSelectedItemIndex ; // -1 <-> none

  public : inline AWInt count (void) const { return mList.count () ; }
  public : void append (const String & inName, const int inTag = -1) ;
  public : void removeItemAtIndex (const AWInt inIndex) ; // Does nothing if index if out of mList bounds
  public : void insertItemAtIndex (const AWInt inIndex, const String & inItemName, const int inItemTag = -1) ; // Does nothing if index if out of mList bounds
  public : void removeAllItems (void) ;

//---------------- Item name
  public : void setNameAtIndex (const AWInt inIndex, const String & inItemName) ; // Does nothing if index if out of mList bounds
  public : String itemAtIndex (const AWInt inIndex COMMA_LOCATION_ARGS) const ; // Does not if index if out of mList bounds

//---------------- Utilities
  public : AWInt itemAtPoint (const AWPoint & inPoint) const ; // -1 if not found
  public : AWRect itemRect (const AWInt inItemIndex) const ;
  public : AWRect titleRect (void) const ;
  public : AWRect listRect (void) const ;

//---------------- Get selected item index
  public : inline AWInt selectedItemIndex (void) const { return mSelectedItemIndex ; }

//---------------- Set selected item (send action if selection did change)
  public : void selectItemAtIndex (const AWInt inIndex) ; // Does nothing if index if out of mList bounds
  public : void selectItemForTag (const int inTag) ; // Does nothing if tag does not fit any item

//---------------- Badge
  public : void setBadgeAtIndex (const AWInt inIndex, const bool inDisplayBadge) ; // Does nothing if index if out of mList bounds
  public : bool hasBadgeAtIndex (const AWInt inIndex) const ; // return false if index if out of mList bounds
  public : bool hasBadge (void) const ; // return true if one or more items have a badge
  public : AWRect badgeRect (const AWInt inItemIndex) const ;

//---------------- Tag
  public : void setTagAtIndex (const AWInt inIndex, const int inTag) ; // Does nothing if index if out of mList bounds
  public : int tagAtIndex (const AWInt inIndex) const ; // return -1 if index if out of mList bounds
  public : int selectedTag (void) const ; // return -1 if index if out of mList bounds
  public : AWInt itemIndexForTag (const int inTag) const ; // return -1 if no item has the tag

//---------------- Touch
  public : virtual void touchDown (const AWPoint & inPoint) ;
  public : virtual void touchMove (const AWPoint & inPoint) ;
  public : virtual void touchUp (const AWPoint & inPoint) ;

//--- Scroll
  private : AWInt mTouchPointY ;
  private : AWInt mVerticalScroll ; // 0 <= mVerticalScroll <= maxScroll
  private : bool mScrolling ; // true during scrolling
  public : AWInt maxScroll (void) const ;

//--- No copy
  private : AWListView (const AWListView &) ;
  private : AWListView & operator = (const AWListView &) ;

//--- For calling super class instance methods
   private : typedef AWView super ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
