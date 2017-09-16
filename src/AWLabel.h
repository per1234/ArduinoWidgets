//
//  AWLabel.hpp
//  graphic
//
//  Created by Pierre Molinaro on 09/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWLabel_DEFINED
#define AWLabel_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "WString.h"
#include "AWView.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

typedef enum {
  kAWAlignmentLeft,
  kAWAlignmentCenter,
  kAWAlignmentRight
} AWAlignment ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWLabel : public AWView {
//--- Constructor
  public : AWLabel (const AWPoint & inRelativeOrigin,
                    const AWInt inWidth,
                    const AWAlignment inAlignment,
                    const String & inTitle,
                    const AWFont & inFont = awkDefaultFont) ;

//--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;

//------------ Title
  private : String mTitle ;
  public : void setTitle (const String & inTitle) ;
  public : String title (void) const { return mTitle; }

//------------ Text color
  private : AWColor mTextColor ;
  public : void setTextColor (const AWColor & inColor) ;

//---------------- Font
  private : AWFont mFont ;
  public : inline AWFont font (void) const { return mFont ; }

//--- Properties
  private : AWInt mStringDisplayLength ;

//------------ Alignment
  private : AWAlignment mAlignment ;
  public : inline AWAlignment alignment (void) const { return mAlignment ; }
  public : void setAlignment (const AWAlignment inAlignment) ;

//--- No copy
  private : AWLabel (const AWLabel &) ;
  private : AWLabel & operator = (const AWLabel &) ;

//--- For calling super class instance methods
   private : typedef AWView super ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
