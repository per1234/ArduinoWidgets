//
//  AWAutoLabel.hpp
//  graphic
//
//  Created by Pierre Molinaro on 24/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWAutoLabel_hpp
#define AWAutoLabel_hpp

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "WString.h"
#include "AWView.h"
#include "AW-settings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWAutoLabel : public AWView {
//--- Constructor
  public : AWAutoLabel (const AWPoint & inRelativeOrigin,
                        const String & inTitle,
                        const AWFont & inFont = awkDefaultFont) ;

//--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;

//------------ Title
  private : String mTitle ;
  public : void setTitle (const String & inTitle) ;

//------------ Text color
  private : AWColor mTextColor ;
  public : void setTextColor (const AWColor & inColor) ;

//---------------- Font
  private : AWFont mTextFont ;
  public : inline AWFont font (void) const { return mTextFont ; }

//--- No copy
  private : AWAutoLabel (const AWAutoLabel &) ;
  private : AWAutoLabel & operator = (const AWAutoLabel &) ;

//--- For calling super class instance methods
   private : typedef AWView super ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
