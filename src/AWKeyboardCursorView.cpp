//
//  AWKeyboardCursorView.cpp
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 17/08/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#include "AWKeyboardCursorView.h"
#include "AWKeyboardSettings.h"
#include "AWContext.h"

static AWRect computeKeyboardCursorViewFrame (const AWLabel * const inSuperView)
{
  AWRect frame = inSuperView->absoluteFrame () ;
  frame.origin.x = frame.origin.y = 0 ;
  return frame ;
}

AWKeyboardCursorView::AWKeyboardCursorView (const AWLabel * const inSuperView) :
AWView(computeKeyboardCursorViewFrame(inSuperView), AWColor ()),
mCursorPosition(0),
mManagedLabel(inSuperView)
{
}

void AWKeyboardCursorView::cursorForward (void)
{
  if (mCursorPosition < mManagedLabel->title ().length()) {
    mCursorPosition++ ;
    setNeedsDisplay () ;
  }
}

void AWKeyboardCursorView::cursorBackward (void)
{
  if (mCursorPosition > 0) {
    mCursorPosition-- ;
    setNeedsDisplay () ;
  }
}

void AWKeyboardCursorView::cursorAtEnd (void)
{
  mCursorPosition = mManagedLabel->title().length() ;
}

//--- Draw
void AWKeyboardCursorView::drawInRegion (const AWRegion & inDrawRegion) const
{
  AWRect cursor = absoluteFrame() ;
  cursor.size.width = 1 ;
  if (mManagedLabel->title ().length() > 0) {
    String stringUntilCursor = mManagedLabel->title ().substring (0, mCursorPosition) ;
    cursor.origin.x += mManagedLabel->font ().stringLength (stringUntilCursor) ;
  }
  AWContext::setColor (awkKeyboardCursorColor) ;
  cursor.fillRectInRegion (inDrawRegion) ;
}

//--- Opacity
bool AWKeyboardCursorView::isOpaque (void) const
{
  return false ;
}
