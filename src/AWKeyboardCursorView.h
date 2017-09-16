//
//  AWKeyboardCursorView.h
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 17/08/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#ifndef AWKeyboardCursorView_h
#define AWKeyboardCursorView_h

#include "AWView.h"
#include "AWLabel.h"

class AWKeyboardCursorView : public AWView
{
  public : AWKeyboardCursorView (const AWLabel * const inSuperView) ;
  
  //--- Draw
  public : virtual void drawInRegion (const AWRegion & inDrawRegion) const ;
  
  //--- Cursor position
  private : uint32_t mCursorPosition ;
  public : uint32_t cursorPosition (void) const { return mCursorPosition ; }
  
  public : void cursorForward (void) ;
  public : void cursorBackward (void) ;
  public : void cursorAtEnd (void) ;
  
  //--- Managed label
  private : const AWLabel * const mManagedLabel ;
  
  //--- Opacity
  public : virtual bool isOpaque (void) const ;
};

#endif /* AWKeyboardCursorView_h */
