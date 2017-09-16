//
//  AWSlider.h
//  graphic
//
//  Created by Jean-Luc Béchennec on 17/07/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#ifndef AWSlider_h
#define AWSlider_h

#include "AWView.h"

const bool kHorizontal = false;
const bool kVertical = true;

class AWSlider : public AWView {
  public : AWSlider (const AWPoint & inOrigin,
                     const AWInt inSize,
                     const bool inOrientation,
                     const bool inHasRuler = true) ;

  //--- Draw
  public : virtual void drawInRegion ( const AWRegion & inDrawRegion ) const ;
  
  //--- No copy
  private : AWSlider (const AWSlider &) ;
  private : AWSlider & operator = (const AWSlider &) ;
  
  //--- Orientation
  private : bool mOrientation ;
  public : bool orientation() const { return mOrientation ; }
  
  //--- Knob color
  protected : AWColor mKnobColor ;
  
  //--- Ruler display
  private : bool mHasRuler ;
  private : AWInt mHowManyScales ;
  protected : void drawRulerInRegion ( const AWRegion & inDrawRegion ) const ;
  public : bool hasRuler() const { return mHasRuler ; }
  //--- Set the number of scales on the slider. Any value < 1 sets mHasRuler
  //--- to false sothat no ruler is displayed
  public : void setHowManyScales ( const AWInt inHowManyScales ) ;
  
  //--- Position
  private : AWInt mKnobPosition ;
  private : AWInt mMaxKnobPosition ;
  private : AWInt mTouchOffset ;
  private : AWInt pointToKnob ( const AWPoint & inPoint ) ;
  public : inline AWInt knobPosition (void) const { return mKnobPosition ; }
  public : void setKnobPosition ( AWInt inKnobPosition, const bool inRefresh = false ) ;
  public : inline AWInt maxKnobPosition (void) const { return mMaxKnobPosition ; }
  public : void setMaxKnobPosition ( AWInt inMaxKnobPosition ) ;
  protected : AWRect knobRect() const ;
  
  //--- Enabled state
  private : bool mIsEnabled ;
  public : inline bool isEnabled (void) const { return mIsEnabled ; }
//  public : void setEnabled (const bool inState) ;
  
  //--- Tell the view is opaque or not
  public : virtual bool isOpaque (void) const ;
  
  //--- Touch
  private : AWPoint mCurrentTouchPoint ;
  public : virtual void touchDown (const AWPoint & inPoint) ;
  public : virtual void touchMove (const AWPoint & inPoint) ;
  public : virtual void touchUp (const AWPoint & inPoint) ;
  
  //--- For calling super class instance methods
  private : typedef AWView super ;
} ;

//—————————————————————————————————————————————————————————————————————————————

#endif /* AWSlider_h */
