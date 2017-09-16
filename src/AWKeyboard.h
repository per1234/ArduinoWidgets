//
//  AWKeyboard.h
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 09/08/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#ifndef AWKeyboard_h
#define AWKeyboard_h

#include "WString.h"
#include "AWInt.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

typedef void (*AWKeyboardCallback)(const String &inText, const int inTag);

void launchKeyboard (const String &inText,
                     const AWInt inMaxLength,
                     AWKeyboardCallback inCallback,
                     const int inTag = -1) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif /* AWKeyboard_h */
