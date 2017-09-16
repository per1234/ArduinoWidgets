//
//  AWKeyboardBackView.cpp
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 15/08/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#include "AWKeyboardBackView.h"
#include "AWColor.h"
#include "AWKeyButton.h"
#include "AWKeyboardSettings.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWKeyboardBackView::AWKeyboardBackView (const AWRect & inRelativeFrame) :
AWRectView (inRelativeFrame, awkKeyboardBackColor, awkKeyboardFrameColor)
{
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWKeyboardBackView::setShifted (const bool inIsShifted,
                                     const AWView * const inSender)
{
  for (AWInt i = 0 ; i < mSubviews.count() ; i++) {
    AWKeyButton *key = (AWKeyButton*)mSubviews(i COMMA_HERE) ;
    key->setShifted(inIsShifted, inSender) ;
  }
}
