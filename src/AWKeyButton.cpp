//
//  AWKeyButton.cpp
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 15/08/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#include "AWKeyButton.h"
#include "AWKeyboardSettings.h"
#include "AWContext.h"
#include "AW-settings.h"

bool gShiftedKeyboard = false ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWKeyButton::AWKeyButton(const AWRect & inFrame, const AWColor & inBackColor) :
AWView(inFrame, inBackColor),
mHiliteState (false)
{
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWKeyButton::setShifted (const bool inShifted,
                              const AWView * const inSender)
{
  // does nothing by default
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWKeyButton::drawFrameAndBackgroundInRegion (const AWRegion & inDrawRegion) const {
  const AWRect af = absoluteFrame () ;
  //--- Fill corners
  AWContext::setColor (awkKeyboardBackColor) ;
  AWRect cornerRect ;
  cornerRect.origin = af.origin ;
  cornerRect.size.width = cornerRect.size.height = awkPushButtonRoundRadius ;
  cornerRect.fillRectInRegion (inDrawRegion) ;
  cornerRect.origin.x += af.size.width - awkPushButtonRoundRadius ;
  cornerRect.fillRectInRegion (inDrawRegion) ;
  cornerRect.origin.y += af.size.height - awkPushButtonRoundRadius ;
  cornerRect.fillRectInRegion (inDrawRegion) ;
  cornerRect.origin.x -= af.size.width - awkPushButtonRoundRadius ;
  cornerRect.fillRectInRegion (inDrawRegion) ;
  //--- Fill button
  AWContext::setColor (isHilited() ? awkHiliteBackColor : backColor()) ;
  af.fillRoundRectInRegion (awkPushButtonRoundRadius, inDrawRegion) ;
  //--- Frame button
  AWContext::setColor (awkKeyboardKeyTextColor) ;
  af.frameRoundRectInRegion (awkPushButtonRoundRadius, inDrawRegion) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWKeyButton::isOpaque (void) const {
  return true ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWKeyButton::touchDown (const AWPoint & inPoint) {
  mHiliteState = true ;
  setNeedsDisplay () ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWKeyButton::touchMove (const AWPoint & inPoint) {
  const bool within = absoluteFrame ().containsPoint (inPoint) ;
  if (within != mHiliteState) {
    mHiliteState = within ;
    setNeedsDisplay () ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWKeyButton::touchUp (const AWPoint & inPoint) {
  if (mHiliteState) {
    mHiliteState = false ;
    setNeedsDisplay () ;
  }
  const bool within = absoluteFrame ().containsPoint (inPoint) ;
  if (within) {
    sendAction () ;
  }
}

//======================================================================================================================

AWNormalKeyButton::AWNormalKeyButton (const AWRect & inFrame,
                                      const char inText,
                                      const char inShiftText) :
AWKeyButton (inFrame, awkKeyboardNormalKeyBackColor),
mNormalKey (inText),
mShiftKey (inShiftText),
mCurrentKey (inText),
mCurrentDisplayLength(awkKeyboardFont.stringLength (inText))
{
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWNormalKeyButton::setShifted (const bool inShifted, const AWView * const inSender)
{
  if (inShifted) {
    mCurrentKey = mShiftKey ;
  }
  else {
    mCurrentKey = mNormalKey ;
  }
  mCurrentDisplayLength = awkKeyboardFont.stringLength (mCurrentKey) ;
  AWRect af = absoluteFrame () ;
  af.inset (1, awkPushButtonRoundRadius) ;
  setNeedsDisplayInRect (af) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWNormalKeyButton::drawInRegion (const AWRegion &inDrawRegion) const
{
  //--- Fill corners
  drawFrameAndBackgroundInRegion (inDrawRegion) ;

  //--- Draw key text
  const AWRect af = absoluteFrame () ;
  const AWInt x = af.origin.x + (af.size.width - mCurrentDisplayLength) / 2 ;
  const AWInt y = af.origin.y - awkKeyboardFont.descent () + (af.size.height - awkKeyboardFont.lineHeight ()) / 2 ;
  AWContext::setColor (isHilited() ? awkHiliteTextColor : awkKeyboardKeyTextColor) ;
  awkKeyboardFont.drawStringInRegion (x, y, String (mCurrentKey), inDrawRegion) ;
}

//======================================================================================================================

AWReturnKeyButton::AWReturnKeyButton (const AWRect & inFrame) :
AWKeyButton(inFrame, awkKeyboardSpecialKeysBackColor)
{
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWReturnKeyButton::drawInRegion (const AWRegion &inDrawRegion) const
{
  //--- Fill corners
  drawFrameAndBackgroundInRegion (inDrawRegion) ;
  //--- Draw the return symbol
  AWContext::setColor (awkKeyboardKeyTextColor) ;
  AWRect drawingRect = absoluteFrame () ;
  const AWInt margin = (drawingRect.size.height - awkKeyboardFont.lineHeight ()) / 2 ;
  const AWPoint offset (2 * (drawingRect.size.width - 2 * margin) / 3 + margin, margin) ;
  drawingRect.origin.x += offset.x ;
  drawingRect.origin.y += offset.y ;
  drawingRect.size.width = (absoluteFrame ().size.width - 2 * margin) / 3 ;
  drawingRect.size.height = 2 ;
  drawingRect.fillRectInRegion (inDrawRegion) ;
  drawingRect.origin.x += drawingRect.size.width ;
  drawingRect.size.width = 2 ;
  drawingRect.size.height = awkKeyboardFont.lineHeight () / 2 ;
  drawingRect.fillRectInRegion (inDrawRegion) ;
  drawingRect.origin.y += drawingRect.size.height ;
  drawingRect.size.width = (absoluteFrame ().size.width - 2 * margin) / 8 ;
  drawingRect.origin.x -= drawingRect.size.width - 2 ;
  drawingRect.size.height = 2 ;
  drawingRect.fillRectInRegion (inDrawRegion) ;
  AWInt x = absoluteFrame ().origin.x + offset.x ;
  AWInt y = absoluteFrame ().origin.y + offset.y ;
  AWPoint::strokeLineInRegion (x, y + 1, x + 2 * margin / 3, y + margin / 3 + 1, inDrawRegion) ;
  AWPoint::strokeLineInRegion (x, y, x + 2 * margin / 3, y - margin / 3, inDrawRegion) ;
  AWPoint::strokeLineInRegion (x + 1, y + 1, x + 2 * margin / 3 + 1, y + margin / 3 + 1, inDrawRegion) ;
  AWPoint::strokeLineInRegion (x + 1, y, x + 2 * margin / 3 + 1, y - margin / 3, inDrawRegion) ;
}

//======================================================================================================================

AWBackspaceKeyButton::AWBackspaceKeyButton (const AWRect & inFrame) :
AWKeyButton(inFrame, awkKeyboardSpecialKeysBackColor)
{
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWBackspaceKeyButton::drawInRegion (const AWRegion &inDrawRegion) const
{
  //--- Fill corners
  drawFrameAndBackgroundInRegion (inDrawRegion) ;
  //--- Draw the backspace symbol
  AWContext::setColor (awkKeyboardKeyTextColor) ;
  AWRect drawingRect = absoluteFrame () ;
  const AWInt margin = (drawingRect.size.height - awkKeyboardFont.lineHeight ()) / 2 ;
  const AWPoint offset (2 * (drawingRect.size.width - 2 * margin) / 3 + margin, margin) ;
  const AWInt halfLineHeight = awkKeyboardFont.lineHeight () / 2 ;
  drawingRect.origin.x += offset.x ;
  drawingRect.origin.y += offset.y ;
  drawingRect.size.width = (absoluteFrame ().size.width - 2 * margin) / 3 ;
  drawingRect.size.height = 2 ;
  drawingRect.fillRectInRegion (inDrawRegion) ;
  drawingRect.origin.x += drawingRect.size.width ;
  drawingRect.size.width = 2 ;
  drawingRect.size.height = halfLineHeight ;
  drawingRect.fillRectInRegion (inDrawRegion) ;
  drawingRect.origin.y += drawingRect.size.height ;
  drawingRect.size.width = (absoluteFrame ().size.width - 2 * margin) / 3 + 2;
  drawingRect.origin.x -= drawingRect.size.width - 2;
  drawingRect.size.height = 2 ;
  drawingRect.fillRectInRegion (inDrawRegion) ;
  AWInt x = absoluteFrame ().origin.x + offset.x ;
  AWInt y = absoluteFrame ().origin.y + offset.y ;
  AWPoint::strokeLineInRegion (x - 1, y, x - halfLineHeight / 2 - 1, y + halfLineHeight / 2, inDrawRegion) ;
  AWPoint::strokeLineInRegion (x , y, x - halfLineHeight / 2, y + halfLineHeight / 2, inDrawRegion) ;
  AWPoint::strokeLineInRegion (x - 1, y + halfLineHeight + 1, x - halfLineHeight / 2 - 1, y + halfLineHeight / 2 + 1, inDrawRegion) ;
  AWPoint::strokeLineInRegion (x , y + halfLineHeight + 1, x - halfLineHeight / 2, y + halfLineHeight / 2 + 1, inDrawRegion) ;
  x += (absoluteFrame ().size.width - 2 * margin) / 8 ;
  y += halfLineHeight / 4 + 1 ;
  AWPoint::strokeLineInRegion (x, y, x + halfLineHeight / 2, y + halfLineHeight / 2, inDrawRegion) ;
  AWPoint::strokeLineInRegion (x, y + halfLineHeight / 2, x + halfLineHeight / 2, y, inDrawRegion) ;
  AWPoint::strokeLineInRegion (x + 1, y, x + 1 + halfLineHeight / 2, y + halfLineHeight / 2, inDrawRegion) ;
  AWPoint::strokeLineInRegion (x + 1, y + halfLineHeight / 2, x + 1 + halfLineHeight / 2, y, inDrawRegion) ;
}

//======================================================================================================================

AWUniqueArray<AWShiftKeyButton *> AWShiftKeyButton::mShiftKeys ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWShiftKeyButton::AWShiftKeyButton (const AWRect & inFrame,
                                    const bool inRightAlign) :
AWKeyButton (inFrame, awkKeyboardSpecialKeysBackColor),
mRightAlign (inRightAlign)
{
  mShiftKeys.append (this) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWShiftKeyButton::setShifted (const bool inShifted,
                                   const AWView * const inSender)
{
  for (AWInt i = 0 ; i < mShiftKeys.count() ; i++) {
    if (this != inSender) {
      AWRect frame = absoluteFrame () ;
      frame.inset(1, awkPushButtonRoundRadius) ;
      setNeedsDisplayInRect (frame) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWShiftKeyButton::drawInRegion (const AWRegion &inDrawRegion) const
{
  //--- Fill corners
  drawFrameAndBackgroundInRegion (inDrawRegion) ;
  //--- Draw the shift symbol (up arrow)
  AWContext::setColor (gShiftedKeyboard ? awkKeyboardKeyShiftedArrowColor : awkKeyboardKeyTextColor) ;
  AWRect drawingRect = absoluteFrame () ;
  const AWInt margin = (drawingRect.size.height - awkKeyboardFont.lineHeight ()) / 2 ;
  const AWInt halfLineHeight = awkKeyboardFont.lineHeight () / 2 ;
  const AWPoint offset (mRightAlign ? drawingRect.size.width - 2 * margin + halfLineHeight / 2 : margin + halfLineHeight / 2, margin) ;
  drawingRect.origin.x += offset.x ;
  drawingRect.origin.y += offset.y ;
  drawingRect.size.width = 2;
  drawingRect.size.height = halfLineHeight ;
  drawingRect.fillRectInRegion (inDrawRegion) ;
  const AWInt x = drawingRect.origin.x ;
  const AWInt y = drawingRect.origin.y + drawingRect.size.height ;
  AWPoint::strokeLineInRegion(x, y, x - halfLineHeight / 2, y - halfLineHeight / 2, inDrawRegion) ;
  AWPoint::strokeLineInRegion(x, y - 1, x - halfLineHeight / 2, y - 1 - halfLineHeight / 2, inDrawRegion) ;
  AWPoint::strokeLineInRegion(x + 1, y, x + 1 + halfLineHeight / 2, y - halfLineHeight / 2, inDrawRegion) ;
  AWPoint::strokeLineInRegion(x + 1, y - 1, x + 1 + halfLineHeight / 2, y - 1 - halfLineHeight / 2, inDrawRegion) ;
}

//======================================================================================================================

AWLeftArrowKeyButton::AWLeftArrowKeyButton (const AWRect & inFrame) :
AWKeyButton(inFrame, awkKeyboardSpecialKeysBackColor)
{
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWLeftArrowKeyButton::drawInRegion (const AWRegion &inDrawRegion) const
{
  //--- Fill corners
  drawFrameAndBackgroundInRegion (inDrawRegion) ;
  //--- Draw the left arrow symbol
  AWContext::setColor (awkKeyboardKeyTextColor) ;
  AWRect drawingRect = absoluteFrame () ;
  const AWInt margin = (drawingRect.size.height - awkKeyboardFont.lineHeight ()) / 2 ;
  const AWInt halfLineHeight = awkKeyboardFont.lineHeight () / 2 ;
  const AWPoint offset (margin, margin + halfLineHeight / 2) ;
  drawingRect.origin.x += offset.x ;
  drawingRect.origin.y += offset.y ;
  drawingRect.size.height = 2;
  drawingRect.size.width = halfLineHeight ;
  drawingRect.fillRectInRegion (inDrawRegion) ;
  const AWInt x = drawingRect.origin.x ;
  const AWInt y = drawingRect.origin.y ;
  AWPoint::strokeLineInRegion(x, y + 1, x + halfLineHeight / 2, y + 1 + halfLineHeight / 2, inDrawRegion) ;
  AWPoint::strokeLineInRegion(x + 1, y + 1, x + 1 + halfLineHeight / 2, y + 1 + halfLineHeight / 2, inDrawRegion) ;
  AWPoint::strokeLineInRegion(x, y, x + halfLineHeight / 2, y - halfLineHeight / 2, inDrawRegion) ;
  AWPoint::strokeLineInRegion(x + 1, y, x + 1 + halfLineHeight / 2, y - halfLineHeight / 2, inDrawRegion) ;
}

//======================================================================================================================

AWRightArrowKeyButton::AWRightArrowKeyButton (const AWRect & inFrame) :
AWKeyButton(inFrame, awkKeyboardSpecialKeysBackColor)
{
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRightArrowKeyButton::drawInRegion (const AWRegion &inDrawRegion) const
{
  //--- Fill corners
  drawFrameAndBackgroundInRegion (inDrawRegion) ;
  //--- Draw the left arrow symbol
  AWContext::setColor (awkKeyboardKeyTextColor) ;
  AWRect drawingRect = absoluteFrame () ;
  const AWInt margin = (drawingRect.size.height - awkKeyboardFont.lineHeight ()) / 2 ;
  const AWInt halfLineHeight = awkKeyboardFont.lineHeight () / 2 ;
  const AWPoint offset (drawingRect.size.width - margin - halfLineHeight, margin + halfLineHeight / 2) ;
  drawingRect.origin.x += offset.x ;
  drawingRect.origin.y += offset.y ;
  drawingRect.size.height = 2;
  drawingRect.size.width = halfLineHeight ;
  drawingRect.fillRectInRegion (inDrawRegion) ;
  const AWInt x = drawingRect.origin.x + drawingRect.size.width ;
  const AWInt y = drawingRect.origin.y ;
  AWPoint::strokeLineInRegion(x, y + 1, x - halfLineHeight / 2, y + 1 + halfLineHeight / 2, inDrawRegion) ;
  AWPoint::strokeLineInRegion(x + 1, y + 1, x + 1 - halfLineHeight / 2, y + 1 + halfLineHeight / 2, inDrawRegion) ;
  AWPoint::strokeLineInRegion(x, y, x - halfLineHeight / 2, y - halfLineHeight / 2, inDrawRegion) ;
  AWPoint::strokeLineInRegion(x + 1, y, x + 1 - halfLineHeight / 2, y - halfLineHeight / 2, inDrawRegion) ;
}
