//
//  AWRectView.h
//  graphic
//
//  Created by Pierre Molinaro on 22/07/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWRectView_CLASS_DEFINED
#define AWRectView_CLASS_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWView.h"
#include "AWRect.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWRectView : public AWView {
//--- Constructor
  public : AWRectView (const AWRect & inRelativeRect,
                       const AWColor & inBackColor,
                       const AWColor & inFrameColor,
                       const AWInt inMargin = 0,
                       const AWInt inFrameThickness = 0) ;

//--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;

//--- Tell the view is opaque
  public : virtual bool isOpaque (void) const { return true ; }

//--- Frame color
  private : AWColor mFrameColor ;
  public : inline AWColor frameColor (void) const { return mFrameColor ; }
  public : void setFrameColor (const AWColor & inFrameColor) ;

//--- Margin attribute and frame thickness attribute
  private : AWInt mMargin ;
  private : AWInt mFrameThickness ;

//--- For calling super class instance methods
   private : typedef AWView super ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
