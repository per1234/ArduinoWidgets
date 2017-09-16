//
//  AWArrowPushButton.hpp
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 04/08/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#ifndef AWArrowPushButton_h
#define AWArrowPushButton_h

#include "AWView.h"

enum { kUpArrow, kDownArrow, kRightArrow, kLeftArrow } ;

class AWArrowPushButton : public AWView
{
  public: AWArrowPushButton(const AWRect & inRelativeFrame,
                            const uint32_t inArrowDirection,
                            const AWColor & inArrowColor) ;

  //--- Arrow color
  private: uint32_t mArrowDirection ;
  //--- Arrow color
  private: AWColor mArrowColor ;
  public: AWColor arrowColor() const { return mArrowColor; } ;
  public: void setArrowColor(AWColor & inArrowColor) { mArrowColor = inArrowColor; } ;

  //--- Enabled state
  private : bool mIsEnabled ;
  public : inline bool isEnabled (void) const { return mIsEnabled ; }
  public : void setEnabled (const bool inState) ;

  //--- On Off state management
  private : bool mIsOn ;
  public : inline bool isOn() const { return mIsOn ; }
  public : inline void setIsOn (const bool inIsOn) { mIsOn = inIsOn ; }

  private : bool mOnOffState ;
  public : inline bool onOffState() const { return mOnOffState ; }
  public : inline void setOnOffState(const bool inOnOffState) { mOnOffState  = inOnOffState ; }

  //---------------- Hilite state
  private : bool mHiliteState ; // false (by default): not hilited

  //--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;

  //--- Tell the view is opaque or not
  public : virtual bool isOpaque (void) const ;

  //--- Touch
  public : virtual void touchDown (const AWPoint & inPoint) ;
  public : virtual void touchMove (const AWPoint & inPoint) ;
  public : virtual void touchUp (const AWPoint & inPoint) ;

  //--- For calling super class instance methods
  private : typedef AWView super ;
};

#endif /* AWArrowPushButton_h */
