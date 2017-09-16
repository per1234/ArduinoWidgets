//
//  AW-min-max
//  graphic
//
//  Created by Pierre Molinaro on 06/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef MIN_MAX_TEMPLATE_FUNCTIONS_DEFINED
#define MIN_MAX_TEMPLATE_FUNCTIONS_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

template <typename T> T awMin (const T inA, const T inB) { return (inA < inB) ? inA : inB ; }

template <typename T> T awMax (const T inA, const T inB) { return (inA > inB) ? inA : inB ; }

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
