//
//  AWInvisiblePushButton.hpp
//  graphic
//
//  Created by Pierre Molinaro on 08/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWInvisiblePushButton_DEFINED
#define AWInvisiblePushButton_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWView.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWInvisiblePushButton : public AWView {
  public : AWInvisiblePushButton (const AWRect & inRelativeFrame) ;

//--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;

//--- No copy
  private : AWInvisiblePushButton (const AWInvisiblePushButton &) ;
  private : AWInvisiblePushButton & operator = (const AWInvisiblePushButton &) ;

//--- Touch
  public : virtual void touchUp (const AWPoint & inPoint) ;

//--- For calling super class instance methods
   private : typedef AWView super ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
