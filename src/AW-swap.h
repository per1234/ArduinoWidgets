//
//  AW-slkwap.h
//  test-regions
//
//  Created by Pierre Molinaro on 15/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef SWAP_TEMPLATE_FUNCTION_DEFINED
#define SWAP_TEMPLATE_FUNCTION_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//
//   Generic awSwap function
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

template <typename TYPE> void awSwap (TYPE & ioOperand1, TYPE & ioOperand2) {
  const TYPE temp = ioOperand1 ;
  ioOperand1 = ioOperand2 ;
  ioOperand2 = temp ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
