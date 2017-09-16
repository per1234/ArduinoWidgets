//
//  AWView.h
//  graphic
//
//  Created by Pierre Molinaro on 08/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWView_DEFINED
#define AWView_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWFont.h"
#include "AWRect.h"
#include "AWRegion.h"
#include "AWColor.h"
#include "AWUniqueArray.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWView ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

typedef void (* AWAction) (AWView * inSender) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWView {

//--- Constructor
  public : AWView (const AWRect & inRelativeFrame,
                   const AWColor & inBackColor) ;

//--- Destructor
  public : virtual ~ AWView (void) ;

//---------------- Frame
  private : AWRect mRelativeFrame ;
  private : AWRect mAbsoluteFrame ;
  public : inline AWRect absoluteFrame (void) const { return mAbsoluteFrame ; }

//---------------- Frame change
  public : void translateBy (const AWInt inDx, const AWInt inDy) ;
  protected : virtual void setAbsoluteFrameFromOrigin (const AWInt inX, const AWInt inY) ;
  public : void setSize (const AWSize & inNewSize) ;

//---------------- Background color
  private : AWColor mBackColor ;
  public : inline AWColor backColor (void) const { return mBackColor ; }
  public : void setBackColor (const AWColor & inBackColor) ;

//---------------- Managing view hierarchy
  public : void addSubView (AWView * inView) ;         // if inView is non NULL, view is added in front of other subviews
  public : void addCenteredSubView (AWView * inView) ; // if inView is non NULL, view is added in front of other subviews
  public : void removeFromSuperView (void) ; // Does nothing if has no super view
  public : inline AWView * superView (void) { return mSuperView ; } // Returns NULL if has no super view
//--- Properties
  private : AWView * mSuperView ;
  protected : AWUniqueArray <AWView *> mSubviews ; // At 0 : back view, at mSubviews.count () - 1 : front view

//---------------- Tag
  private : int mTag ; // Default value: -1
  public : inline void setTag (const int inTag) { mTag = inTag ; }
  public : inline int tag (void) const { return mTag ; }

//---------------- Action
  private : AWAction mAction ;
  public : void sendAction (void) ;
  public : inline AWAction action (void) const { return mAction ; }
  public : inline void setAction (AWAction inAction) { mAction = inAction ; }

//---------------- Touch
  public : virtual void touchDown (const AWPoint & inPoint) ;
  public : virtual void touchMove (const AWPoint & inPoint) ;
  public : virtual void touchUp (const AWPoint & inPoint) ;
//--- Internal method, do not call directly
  public : AWView * viewAtPoint (const AWPoint & inPoint) ;

//---------------- Display view
  public : void setNeedsDisplay (void) ;
  public : void setNeedsDisplayInRect (const AWRect & inRect) ;
  private : static bool viewsNeedDisplay (void) ;

//--- Draw method (to be overridden)
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;

//--- Tell the view is opaque
  public : virtual bool isOpaque (void) const ;

//--- Internal methods, do not call directly
  private : void drawAllViews (const bool inFlashing) const ;
  private : void drawViews (const AWRegion & inDrawRegion, const bool inFlashUpdate) const ;
  public : void removeOpaqueRegion (AWRegion & ioRegion) const ;
//  private : static void releaseInvalidRegion (void) ;

//---------------- Visibility
  private : bool mIsVisible ;
  public : inline bool isVisible (void) const { return mIsVisible ; }
  public : void setVisibility (const bool inIsVisible) ;

//---------------- Handle "on screen" state
  private : void setOnScreen (const bool inOnScreen) ;
  public : inline bool isOnScreen (void) const { return mIsOnScreen ; }
  private : bool mIsOnScreen ; // false (by default: not in screen)

//--- No copy
  private : AWView (const AWView &) ;
  private : AWView & operator = (const AWView &) ;

//--- Fiend class
  friend class AWContext ;
  friend void simulatorUpdateDisplay (void) ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
