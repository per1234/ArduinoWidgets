//
//  AWKeyboardInputField.cpp
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 16/08/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#include "AWKeyboardInputField.h"
#include "AWKeyboardSettings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWKeyboardInputField::AWKeyboardInputField (const AWRect & inRelativeFrame,
                                            const AWInt inMargin,
                                            const String inInitialText) :
AWRectView (inRelativeFrame, awkKeyboardInputColor, awkKeyboardFrameColor),
mInputLabel (AWPoint (inMargin, inMargin / 2),
             absoluteFrame().size.width - 2 * inMargin,
             kAWAlignmentLeft,
             String("")),
mCursorView(NULL),
mText(inInitialText),
mLength(0)
{
  mInputLabel.setTitle(mText) ;
  mCursorView = new AWKeyboardCursorView (&mInputLabel) ;
  mInputLabel.addSubView (mCursorView) ;
  addSubView (&mInputLabel) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWKeyboardInputField::setLength (const AWInt inLength)
{
  mLength = inLength ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

String &AWKeyboardInputField::getText ()
{
  return mText;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWKeyboardInputField::addChar ( char inChar )
{
  if (mText.length () < (size_t) mLength) {
    uint32_t cursorPosition = mCursorView->cursorPosition () ;
    if (cursorPosition < mText.length ()) {
      mText = mText.substring (0, cursorPosition) + inChar + mText.substring (cursorPosition) ;
    }
    else {
      mText.append(inChar);
    }
    mInputLabel.setTitle (mText);
    cursorForward () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWKeyboardInputField::delChar ( )
{
  if (mText.length() > 0) {
    uint32_t cursorPosition = mCursorView->cursorPosition () ;
    if (cursorPosition > 0) {
      mText.remove (cursorPosition - 1, 1) ;
      mInputLabel.setTitle (mText) ;
      cursorBackward () ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWKeyboardInputField::setText (const String &inText)
{
  mText = inText ;
  mInputLabel.setTitle (inText);
  cursorAtEnd () ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWKeyboardInputField::cursorForward (void)
{
  mCursorView->cursorForward () ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWKeyboardInputField::cursorBackward (void)
{
  mCursorView->cursorBackward () ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWKeyboardInputField::cursorAtEnd (void)
{
  mCursorView->cursorAtEnd () ;
}
