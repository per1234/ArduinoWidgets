//
//  AWKeyboardInputField.h
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 16/08/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#ifndef AWKeyboardInputField_h
#define AWKeyboardInputField_h

#include "AWRectView.h"
#include "AWLabel.h"
#include "AWKeyboardCursorView.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWKeyboardInputField : public AWRectView
{
  public : AWKeyboardInputField (const AWRect & inRelativeFrame,
                                 const AWInt inMargin,
                                 const String inInitialText) ;

  private : AWLabel mInputLabel ;
  private : AWKeyboardCursorView *mCursorView ;
  private : String mText ;
  private : AWInt mLength ;

  public : void setLength (const AWInt inLength) ;
  public : String &getText () ;
  public : void setText (const String &inText) ;
  public : void addChar (char inChar) ;
  public : void delChar () ;
  public : void cursorForward (void) ;
  public : void cursorBackward (void) ;
  public : void cursorAtEnd (void) ;
};

#endif /* AWKeyboardInputField_h */
