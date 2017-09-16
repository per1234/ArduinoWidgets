//
//  AWSwitch.hpp
//  graphic
//
//  Created by Pierre Molinaro on 20/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWSwitch_DEFINED
#define AWSwitch_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "WString.h"
#include "AWView.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWSwitch : public AWView {
//--- Constructor
  public : AWSwitch (const AWPoint & inBaseLineRelativeOrigin,
                     const String & inTitle,
                     const AWFont & inFont = awkDefaultFont) ;

//--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;

//---
  public : void setTitle (const String & inTitle) ;

  public : AWRect boxRect (void) const ;

//--- Properties
  private : String mTitle ;
  private : AWColor mTextColor ;

//---------------- Font
  private : AWFont mFont ;
  public : inline AWFont font (void) const { return mFont ; }

//------------- State
  private : bool mChecked ; // true ⇔ ▣,  false ⇔ ▢
  public : inline bool checked (void) const { return mChecked ; }
  public : void setChecked (const bool inChecked) ;

//---------------- Hilite state
  protected : bool mHiliteState ; // false (by default): not hilited

//--- Enabled state
  private : bool mIsEnabled ;
  public : inline bool isEnabled (void) const { return mIsEnabled ; }
  public : void setEnabled (const bool inState) ;

//---------------- Touch
  public : virtual void touchDown (const AWPoint & inPoint) ;
  public : virtual void touchMove (const AWPoint & inPoint) ;
  public : virtual void touchUp (const AWPoint & inPoint) ;

//--- No copy
  private : AWSwitch (const AWSwitch &) ;
  private : AWSwitch & operator = (const AWSwitch &) ;

//--- For calling super class instance methods
   private : typedef AWView super ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
