//
//  AWPushButton.hpp
//  graphic
//
//  Created by Pierre Molinaro on 08/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWPushButton_DEFINED
#define AWPushButton_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWView.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWPushButton : public AWView {
  public : AWPushButton (const AWPoint & inRelativeBaselineOrigin,
                         const AWInt inWidth,
                         const String & inTitle,
                         const AWFont & inFont = awkDefaultFont) ;
  
  public : AWPushButton (const AWRect & inFrame,
                         const String & inTitle,
                         const AWFont & inFont = awkDefaultFont) ;
  
//------------ Title
  protected : String mTitle ;
  public : void setTitle (const String & inTitle) ;

//---------------- Font
  private : AWFont mFont ;
  public : inline AWFont font (void) const { return mFont ; }

//--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;

//--- No copy
  private : AWPushButton (const AWPushButton &) ;
  private : AWPushButton & operator = (const AWPushButton &) ;

//--- Properties
  private : AWColor mTextColor ;
  public : inline AWColor textColor (void) const { return mTextColor ; }
  public : void setTextColor (const AWColor inTextColor) { mTextColor = inTextColor ; }
  
  protected : AWInt mStringDisplayLength ;
  
  private : AWInt mVerticalMargin ;
  public : inline AWInt verticalMargin (void) const { return mVerticalMargin ; }

//--- Enabled state
  private : bool mIsEnabled ;
  public : inline bool isEnabled (void) const { return mIsEnabled ; }
  public : void setEnabled (const bool inState) ;

//---------------- Hilite state
  private : bool mHiliteState ; // false (by default): not hilited
  public : inline bool isHilited (void) const { return mHiliteState ; }

//--- Tell the view is opaque or not
  public : virtual bool isOpaque (void) const ;

//--- Touch
  public : virtual void touchDown (const AWPoint & inPoint) ;
  public : virtual void touchMove (const AWPoint & inPoint) ;
  public : virtual void touchUp (const AWPoint & inPoint) ;

//--- For calling super class instance methods
   private : typedef AWView super ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
