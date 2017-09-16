//
//  AWSegmentedControl.hpp
//  graphic
//
//  Created by Pierre Molinaro on 24/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWSegmentedControl_DEFINED
#define AWSegmentedControl_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWView.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWSegmentedControl ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

typedef void (* AWSegmentedControlAction) (AWSegmentedControl * inSender, const AWInt inHilitedTabIndex) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWSegmentedControl : public AWView {
//--- Constructor
  public : AWSegmentedControl (const AWPoint & inRelativeBaselineOrigin,
                               const AWInt inWidth,
                               const AWFont & inFont = awkDefaultFont) ;

//--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;

//--- Adding a Tab
  public : void addTab (const String & inTitle) ;

//--- Utilities
  private : AWInt xTitleOriginForIndex (const AWInt inIndex) const ;
  public : AWRect tabTitleRectForIndex (const AWInt inIndex) const ;

//---------------- Font
  private : AWFont mFont ;
  public : inline AWFont font (void) const { return mFont ; }

//--- Properties
  private : AWUniqueArray <String> mTabTitles ;
  private : AWInt mHilitedTabIndexOnTouchDown ;
  private : AWInt mHilitedTabIndex ;
  private : AWInt mSelectedTabIndex ;
  public : inline AWInt selectedTabIndex (void) const { return mSelectedTabIndex ; }
  public : void selectTabAtIndex (const AWInt inIndex) ;

//---------------- Segmented control action
// If segmented control action is NULL (by default), touch up changes selection and send action (defined in AWView)
// If not NULL, touch up does not change selection, and sends segmented control action
  private : AWSegmentedControlAction mSegmentedControlAction ; // NULL by default
  public : inline AWSegmentedControlAction segmentedControlAction (void) const { return mSegmentedControlAction ; }
  public : inline void setSegmentedControlAction (const AWSegmentedControlAction inAction) {
    mSegmentedControlAction = inAction ;
  }

//---------------- Touch
  public : virtual void touchDown (const AWPoint & inPoint) ;
  public : virtual void touchMove (const AWPoint & inPoint) ;
  public : virtual void touchUp (const AWPoint & inPoint) ;

//---------------- Enabled state
  private : bool mIsEnabled ;
  public : inline bool isEnabled (void) const { return mIsEnabled ; }
  public : void setEnabled (const bool inState) ;

//--- No copy
  private : AWSegmentedControl (const AWSegmentedControl &) ;
  private : AWSegmentedControl & operator = (const AWSegmentedControl &) ;

//--- For calling super class instance methods
   private : typedef AWView super ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
