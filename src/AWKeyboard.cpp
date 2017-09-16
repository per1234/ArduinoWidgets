//
//  AWKeyboard.cpp
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 09/08/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#include "AWKeyboard.h"
#include "AWKeyboardSettings.h"
#include "AWKeyboardBackView.h"
#include "AWContext.h"
#include "AWInvisiblePushButton.h"
#include "AWKeyButton.h"
#include "AWKeyboardInputField.h"

#include <stdio.h>

static AWView *gKeyboardView = NULL ;
static AWKeyboardInputField *gInputField = NULL ;
static AWKeyboardCallback gKeyboardCallback = NULL ;
static int gTag ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Actions

static void dismissKeyboard (AWView *inSender)
{
  if (gKeyboardView != NULL) {
    gKeyboardView->setVisibility (false) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void validateEntry (AWView * inSender)
{
  if (gKeyboardView != NULL &&
      gInputField != NULL)
  {
    gKeyboardView->setVisibility (false) ;
    if (gKeyboardCallback != NULL) {
      gKeyboardCallback (gInputField->getText(), gTag);
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void shiftAction (AWView *inSender)
{
  gShiftedKeyboard = !gShiftedKeyboard ;

  AWKeyboardBackView *super = (AWKeyboardBackView *)inSender->superView() ;
  super->setShifted (gShiftedKeyboard, inSender) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void keyAction (AWView *inSender)
{
  gInputField->addChar (((AWNormalKeyButton *)inSender)->keyChar ()) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void backKeyAction (AWView *inSender)
{
  gInputField->delChar () ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void leftArrowKeyAction (AWView *inSender)
{
  gInputField->cursorBackward () ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void rightArrowKeyAction (AWView *inSender)
{
  gInputField->cursorForward () ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void launchKeyboard (const String &inText,
                     const AWInt inMaxLength,
                     AWKeyboardCallback inCallback,
                     const int inTag)
{
  gTag = inTag ;
  if (gKeyboardView == NULL) {
    AWRect screenRect = AWContext::screenRect () ;
    gKeyboardView = new AWInvisiblePushButton (screenRect) ;
    gKeyboardView->setAction(dismissKeyboard) ;

    // Compute the size of the keys :
    // AZERTYUIOP keys + return (1.5 key width) = 10 + 1.5 = 11.5 +
    // interval = .2 * 10 = 2 = 14
    AWInt normalKeySize = screenRect.size.width / 14 ;
    AWInt returnKeySize = normalKeySize + normalKeySize / 2 ;
    AWInt keyInternalMargin = normalKeySize / 10 ;
    AWInt keyExternalMargin = (screenRect.size.width - 11 * normalKeySize - returnKeySize - 11 * keyInternalMargin ) / 2;
    AWInt keyboardBackgroundHeight = 4 * normalKeySize + 3 * keyInternalMargin + 2 * keyExternalMargin ;
    AWKeyboardBackView * keyboardBackgroundView = new AWKeyboardBackView( AWRect(0, 0, screenRect.size.width, keyboardBackgroundHeight ) ) ;

    String numberLine = "1234567890-";
    String numberLineShift = "@#&+'()=!:_";

    String firstLine = "azertyuiop";
    String firstLineShift = "AZERTYUIOP";

    String secondLine = "qsdfghjklm";
    String secondLineShift = "QSDFGHJKLM";

    String thirdLine = "<wxcvbn";
    String thirdLineShift = ">WXCVBN";

    gInputField = new AWKeyboardInputField (
      AWRect (0,
              keyboardBackgroundHeight,
              keyboardBackgroundView->absoluteFrame().size.width,
              30),
      keyExternalMargin,
      inText
    );
    gKeyboardView->addSubView (gInputField) ;

    AWInt keyXOffset = keyExternalMargin ;

    for (uint32_t i = 0 ; i < numberLine.length() ; i++) {
      AWNormalKeyButton *key = new AWNormalKeyButton(
        AWRect (keyXOffset,
                keyExternalMargin + 3 * (normalKeySize + keyInternalMargin),
                normalKeySize,
                normalKeySize
        ),
        numberLine.charAt (i),
        numberLineShift.charAt (i)
      ) ;
      key->setAction (keyAction);
      keyboardBackgroundView->addSubView (key);
      keyXOffset += keyInternalMargin + normalKeySize ;
    }

    AWBackspaceKeyButton *backKey = new AWBackspaceKeyButton (
      AWRect (keyXOffset,
              keyExternalMargin + 3 * ( normalKeySize + keyInternalMargin ),
              keyboardBackgroundView->absoluteFrame().size.width - 11 * ( normalKeySize + keyInternalMargin ) - 2 * keyExternalMargin,
              normalKeySize
      )
    ) ;
    backKey->setAction(backKeyAction);
    keyboardBackgroundView->addSubView( backKey );

    keyXOffset = keyExternalMargin + keyInternalMargin + normalKeySize / 2 ;

    for (uint32_t i = 0 ; i < firstLine.length() ; i++) {
      AWNormalKeyButton *key = new AWNormalKeyButton(
        AWRect ( keyXOffset,
                 keyExternalMargin + 2 * ( normalKeySize + keyInternalMargin ),
                 normalKeySize,
                 normalKeySize
        ),
        firstLine.charAt (i),
        firstLineShift.charAt (i)
      ) ;
      key->setAction(keyAction);
      keyboardBackgroundView->addSubView( key );
      keyXOffset += keyInternalMargin + normalKeySize ;
    }

    AWReturnKeyButton *returnkey = new AWReturnKeyButton (
      AWRect (keyXOffset,
              keyExternalMargin + 2 * ( normalKeySize + keyInternalMargin ),
              keyboardBackgroundView->absoluteFrame().size.width - keyXOffset - keyExternalMargin,
              normalKeySize
      )
    ) ;
    returnkey->setAction (validateEntry) ;
    keyboardBackgroundView->addSubView (returnkey);


    keyXOffset = keyExternalMargin + normalKeySize + 2 * keyInternalMargin;

    for (uint32_t i = 0 ; i < secondLine.length() ; i++) {
      AWNormalKeyButton *key = new AWNormalKeyButton (
        AWRect (keyXOffset,
                keyExternalMargin + 1 * ( normalKeySize + keyInternalMargin ),
                normalKeySize,
                normalKeySize
        ),
        secondLine.charAt (i),
        secondLineShift.charAt (i)
      ) ;
      key->setAction(keyAction);
      keyboardBackgroundView->addSubView( key );
      keyXOffset += keyInternalMargin + normalKeySize ;
    }

    AWShiftKeyButton *shiftKey = new AWShiftKeyButton(
      AWRect ( keyXOffset,
               keyExternalMargin + 1 * ( normalKeySize + keyInternalMargin ),
               keyboardBackgroundView->absoluteFrame().size.width - keyXOffset - keyExternalMargin,
               normalKeySize
      ),
      true
    ) ;
    shiftKey->setAction(shiftAction) ;
    keyboardBackgroundView->addSubView( shiftKey );

    shiftKey = new AWShiftKeyButton(
      AWRect ( keyExternalMargin,
               keyExternalMargin + 1 * ( normalKeySize + keyInternalMargin ),
               normalKeySize + keyInternalMargin,
               normalKeySize
      ),
      false
    ) ;
    shiftKey->setAction(shiftAction) ;
    keyboardBackgroundView->addSubView( shiftKey );

    keyXOffset = keyExternalMargin + 4 * keyInternalMargin ;

    for (uint32_t i = 0 ; i < thirdLine.length() ; i++) {
      AWNormalKeyButton *key = new AWNormalKeyButton (
        AWRect (keyXOffset,
                keyExternalMargin,
                normalKeySize,
                normalKeySize
        ),
        thirdLine.charAt (i),
        thirdLineShift.charAt (i)
      ) ;
      key->setAction(keyAction);
      keyboardBackgroundView->addSubView( key );
      keyXOffset += keyInternalMargin + normalKeySize ;
    }

    AWInt spaceBarKeyWidth = keyboardBackgroundView->absoluteFrame().size.width - keyXOffset - 2 * normalKeySize - 2 * keyInternalMargin - keyExternalMargin ;
    AWNormalKeyButton *spaceBarKey = new AWNormalKeyButton (
      AWRect (keyXOffset,
              keyExternalMargin,
              spaceBarKeyWidth,
              normalKeySize
      ),
      ' ',
      ' '
    ) ;
    spaceBarKey->setAction (keyAction) ;
    keyboardBackgroundView->addSubView( spaceBarKey );
    keyXOffset += spaceBarKeyWidth + keyInternalMargin ;

    AWLeftArrowKeyButton *leftArrowKey = new AWLeftArrowKeyButton(
      AWRect (keyXOffset,
              keyExternalMargin,
              normalKeySize,
              normalKeySize
      )
    ) ;
    leftArrowKey->setAction (leftArrowKeyAction) ;
    keyboardBackgroundView->addSubView( leftArrowKey );
    
    keyXOffset += keyInternalMargin + normalKeySize ;
    AWRightArrowKeyButton *rightArrowKey = new AWRightArrowKeyButton(
      AWRect (keyXOffset,
              keyExternalMargin,
              normalKeySize,
              normalKeySize
      )
    ) ;
    rightArrowKey->setAction (rightArrowKeyAction) ;
    keyboardBackgroundView->addSubView( rightArrowKey );

    gKeyboardView->addSubView( keyboardBackgroundView );
    addView( gKeyboardView ) ;
  }
  gKeyboardView->setVisibility( true ) ;
  gKeyboardCallback = inCallback ;
  gInputField->setLength (inMaxLength);
  gInputField->setText (inText) ;
}
