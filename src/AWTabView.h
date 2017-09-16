//
//  AWTabView.hpp
//  graphic
//
//  Created by Pierre Molinaro on 24/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWTabView_DEFINED
#define AWTabView_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWView.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWTabView : public AWView {
//--- Constructor
  public : AWTabView (const AWRect & inRelativeFrame,
                      const AWFont & inFont = awkDefaultFont) ;

//--- Destructor
  public : virtual ~ AWTabView (void) ;

//--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;

//--- Adding a Tab
  public : void addTab (const String & inTitle, AWView * inView) ;

//---------------- Font
  private : AWFont mFont ;
  public : inline AWFont font (void) const { return mFont ; }

//--- Utilities
  public : AWInt titleHeight (void) const ;
  private : AWInt xTitleOriginForIndex (const AWInt inIndex) const ;
  public : AWRect horizontalSeparator (void) const ;
  public : AWRect contentRectFromFrame (const AWRect & inFrame) const ;
  public : AWRect titleRect (void) const ;
  public : AWRect tabTitleRectForIndex (const AWInt inIndex) const ;

//--- Properties
  private : AWUniqueArray <String> mTabTitles ;
  private : AWUniqueArray <AWView *> mTabViews ;
  private : AWView * mContentView ;
  private : AWInt mHilitedTabIndexOnTouchDown ;
  private : AWInt mHilitedTabIndex ;
  private : AWInt mSelectedTabIndex ;
  public : inline AWInt selectedTabIndex (void) const { return mSelectedTabIndex ; }
  public : void selectTabAtIndex (const AWInt inIndex) ;

//---------------- Badge
  private : AWUniqueArray <bool> mBadges ;
  public : void setBadgeAtIndex (const AWInt inIndex, const bool inDisplayBadge) ; // Does nothing if index if out of mList bounds
  public : bool hasBadgeAtIndex (const AWInt inIndex) const ; // return false if index if out of mList bounds
  public : AWRect badgeRect (const AWInt inItemIndex) const ;

//---------------- Touch
  public : virtual void touchDown (const AWPoint & inPoint) ;
  public : virtual void touchMove (const AWPoint & inPoint) ;
  public : virtual void touchUp (const AWPoint & inPoint) ;

//--- No copy
  private : AWTabView (const AWTabView &) ;
  private : AWTabView & operator = (const AWTabView &) ;

//--- For calling super class instance methods
   private : typedef AWView super ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
