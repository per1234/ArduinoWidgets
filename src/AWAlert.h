//
//  AWAlert.hpp
//  CocoaSimulator
//
//  Created by Pierre Molinaro on 28/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWAlert_DEFINED
#define AWAlert_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWView.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void presentAlert (const String & inTitle,
                   AWAction inCancelAction,
                   AWAction inOkAction,
                   const int inOkActionTag) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
