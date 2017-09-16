//
//  AWKeyButton.hpp
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 15/08/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#ifndef AWKeyButton_h
#define AWKeyButton_h

#include "AWView.h"

extern bool gShiftedKeyboard ;

class AWKeyButton : public AWView
{
  public : AWKeyButton (const AWRect & inFrame,
                        const AWColor & inBackColor) ;
  
  public : virtual void setShifted (const bool inShifted,
                                    const AWView * const inSender) ;

  //---------------- Hilite state
  private : bool mHiliteState ; // false (by default): not hilited
  public : inline bool isHilited (void) const { return mHiliteState ; }
  
  //---------------- Drawing
  protected : void drawFrameAndBackgroundInRegion (const AWRegion & inDrawRegion) const ;
  public : virtual bool isOpaque (void) const ;

  //--- Touch
  public : virtual void touchDown (const AWPoint & inPoint) ;
  public : virtual void touchMove (const AWPoint & inPoint) ;
  public : virtual void touchUp (const AWPoint & inPoint) ;
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWNormalKeyButton : public AWKeyButton
{
  public : AWNormalKeyButton (const AWRect & inFrame,
                              const char inText,
                              const char inShiftText) ;
  
  //--- Attributes
  private : char mNormalKey ;
  private : char mShiftKey ;
  private : char mCurrentKey ;
  private : AWInt mCurrentDisplayLength ;
  
  public : virtual void setShifted (const bool inShifted,
                                    const AWView * const inSender) ;
  
  public : char keyChar () const { return mCurrentKey ; }
  
  //--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWReturnKeyButton : public AWKeyButton
{
  public : AWReturnKeyButton (const AWRect & inFrame) ;
  
  //--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWBackspaceKeyButton : public AWKeyButton
{
  public : AWBackspaceKeyButton (const AWRect & inFrame) ;
  
  //--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWShiftKeyButton : public AWKeyButton
{
  public : AWShiftKeyButton (const AWRect & inFrame, const bool inRightAlign) ;
  
  //---- Multi shift key management
  private : static AWUniqueArray<AWShiftKeyButton *> mShiftKeys ;
  
  //---- Alignment of the arrow in the key
  private : bool mRightAlign ;

  public : virtual void setShifted (const bool inShifted,
                                    const AWView * const inSender) ;
  
  //--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWLeftArrowKeyButton : public AWKeyButton
{
  public : AWLeftArrowKeyButton (const AWRect & inFrame) ;
  
  //--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWRightArrowKeyButton : public AWKeyButton
{
  public : AWRightArrowKeyButton (const AWRect & inFrame) ;
  
  //--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;
};


#endif /* AWKeyButton_hpp */
