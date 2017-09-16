//
//  AWLine.h
//  graphic
//
//  Created by Pierre Molinaro on 23/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWLine_h
#define AWLine_h

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWView.h"
#include "AWPoint.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWLine : public AWView {
//--- Constructor
  public : AWLine (const AWPoint & inRelativePoint1,
                   const AWPoint & inRelativePoint2) ;

//--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;

//--- Tell the view is opaque
  public : virtual bool isOpaque (void) const { return false ; }

//--- Private properties
  private : AWPoint mRelativePoint1 ;
  private : AWPoint mRelativePoint2 ;
  private : AWPoint mAbsolutePoint1 ;
  private : AWPoint mAbsolutePoint2 ;

  protected : virtual void setAbsoluteFrameFromOrigin (const AWInt inX, const AWInt inY) ;

//--- For calling super class instance methods
   private : typedef AWView super ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
