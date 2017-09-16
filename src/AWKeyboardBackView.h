//
//  AWKeyboardBackView.hpp
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 15/08/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#ifndef AWKeyboardBackView_h
#define AWKeyboardBackView_h

#include "AWRectView.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWKeyboardBackView : public AWRectView
{
  public : AWKeyboardBackView (const AWRect & inRelativeFrame);
  
  public : void setShifted (const bool inIsShifted,
                            const AWView * const inSender) ;
};

#endif /* AWKeyboardBackView_h */
