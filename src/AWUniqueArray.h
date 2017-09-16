//---------------------------------------------------------------------------------------------------------------------*
//
//            Declaration and implementation of the template class 'AWUniqueArray'
//
//  COPY OF ITS INSTANCES IS FORBIDDEN BY REDEFINITION OF COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR.
//
//  This file is part of libpm library
//
//  Copyright (C) 1997, ..., 2016 Pierre Molinaro.
//
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr
//
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//---------------------------------------------------------------------------------------------------------------------*

#ifndef UNIQUE_GENERIC_ARRAY_IS_DEFINED
#define UNIQUE_GENERIC_ARRAY_IS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "AW-assertion.h"
#include "AWInt.h"

//---------------------------------------------------------------------------------------------------------------------*
//
//   Template class predeclaration
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> class AWUniqueArray ;

//---------------------------------------------------------------------------------------------------------------------*
//
//   awSwap function for AWUniqueArray <TYPE> classes
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void awSwap (AWUniqueArray <TYPE> & ioOperand1, AWUniqueArray <TYPE> & ioOperand2) ;

//---------------------------------------------------------------------------------------------------------------------*
//
//   Template class declaration
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> class AWUniqueArray {
//--- Default Constructor
  public : AWUniqueArray (void) ;

//--- Allocation Constructor (empty array)
  public : AWUniqueArray (const AWInt inCapacity
                          COMMA_LOCATION_ARGS) ;

//--- Virtual Destructor
  public : ~AWUniqueArray (void) ;

//--- No copy
  private : AWUniqueArray (const AWUniqueArray <TYPE> &) ;
  private : AWUniqueArray <TYPE> & operator = (const AWUniqueArray <TYPE> &) ;

//--- Get Count
  public : inline AWInt count (void) const { return (AWInt) mCount ; }

//--- Set Count to zero
  public : void setCountToZero (void) ;

//--- Get allocated capacity
  public : inline AWInt capacity (void) const { return mCapacity ; }

//--- Methods for setting capacity
  public : void setCapacity (const AWInt inNewCapacity) ;
  public : void setCapacityUsingSwap (const AWInt inNewCapacity) ;

//--- Get buffer pointer
  public : const TYPE * unsecureBufferPointer (void) const { return mArray ; }

//--- Remove all objects and deallocate
  public : void free (void) ;

//--- Append objects at the end of the array
  public : void append (const TYPE & inValue) ; // inValue is copied

  public : void appendObjectUsingSwap (TYPE & ioValue) ;

//--- Remove an object
  public : void remove (const TYPE & inObject) ;
  public : void removeAtIndex (const AWInt inIndex COMMA_LOCATION_ARGS) ;

//--- Insert objects at index (0 <= index <= count)
  public : void insertAtIndex (const TYPE & inValue,
                               const AWInt inIndex
                               COMMA_LOCATION_ARGS) ; // inValue is copied

  public : void insertObjectUsingSwap (TYPE & ioValue,
                                       const AWInt inIndex
                                       COMMA_LOCATION_ARGS) ;

//--- Element access (with index checking)
  public : const TYPE lastObject (LOCATION_ARGS) const ;
  public : TYPE & lastObject (LOCATION_ARGS) ;

  public : void setAtIndex (const TYPE & inObject,
                            const AWInt inIndex
                            COMMA_LOCATION_ARGS) ;

  public : TYPE & operator () (const AWInt inIndex COMMA_LOCATION_ARGS) ;

  public : const TYPE & operator () (const AWInt inIndex COMMA_LOCATION_ARGS) const ;

//--- Protected attributes
  protected : TYPE * mArray ;
  protected : AWInt mCount ;
  protected : AWInt mCapacity ;

//--- Array Pointer
  public : const TYPE * unsafeArrayPointer (void) const ;

//--- awSwap
  friend void awSwap <TYPE> (AWUniqueArray <TYPE> & ioOperand1,
                             AWUniqueArray <TYPE> & ioOperand2) ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//
//   Default Constructor
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> AWUniqueArray <TYPE>::AWUniqueArray (void) :
mArray (NULL),
mCount (0),
mCapacity (0) {
}

//---------------------------------------------------------------------------------------------------------------------*
//
//   Allocation Constructor
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> AWUniqueArray <TYPE>::AWUniqueArray (const AWInt inCapacity COMMA_LOCATION_ARGS) :
mArray (NULL),
mCount (0),
mCapacity (0) {
  if (inCapacity > 0) {
    mArray = new TYPE [inCapacity] ;
    mCapacity = inCapacity ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//
//   Destructor
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> AWUniqueArray <TYPE>::~AWUniqueArray (void) {
  delete [] mArray ;
}

//---------------------------------------------------------------------------------------------------------------------*
//
//   Destructor
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void AWUniqueArray <TYPE>::setCountToZero (void) {
  mCount = 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//
//   Method for making room using copy
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void AWUniqueArray <TYPE>::setCapacity (const AWInt inNewCapacity) {
  if (mCapacity < inNewCapacity) {
    AWInt newCapacity = (mCapacity > 32) ? mCapacity : 32 ;
    while (newCapacity < inNewCapacity) {
      newCapacity <<= 1 ;
    }
    TYPE * newArray = new TYPE [newCapacity] ;
    for (size_t i=0 ; i < (size_t) mCount ; i++) {
      newArray [i] = mArray [i] ;
    }
    delete [] mArray ; mArray = newArray ;
    mCapacity = newCapacity ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//
//   Method for setting capacity using awSwap function
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void AWUniqueArray <TYPE>::setCapacityUsingSwap (const AWInt inNewCapacity) {
  if (mCapacity < inNewCapacity) {
    AWInt newCapacity = (mCapacity > 32) ? mCapacity : 32 ;
    while (newCapacity < inNewCapacity) {
      newCapacity <<= 1 ;
    }
    TYPE * newArray = new TYPE [newCapacity] ;
    for (size_t i=0 ; i< (size_t) mCount ; i++) {
      awSwap (newArray [i], mArray [i]) ;
    }
    delete [] mArray ; mArray = newArray ;
    mCapacity = newCapacity ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//
//   Remove all objects and deallocate
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void AWUniqueArray <TYPE>::free (void) {
  mCount = 0 ;
  delete [] mArray ; mArray = NULL ;
  mCapacity = 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//
//   Add object at the end of the array
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void AWUniqueArray <TYPE>::append (const TYPE & inValue) {
  if (mCount >= mCapacity) {
    setCapacity (mCount + 1 + mCount / 2) ;
  }
  mArray [mCount] = inValue ;
  mCount ++ ;
}

//---------------------------------------------------------------------------------------------------------------------*
//
//   Add object at the end of the array
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void AWUniqueArray <TYPE>::appendObjectUsingSwap (TYPE & ioValue) {
  setCapacityUsingSwap (mCount + 1) ;
  awSwap (mArray [mCount], ioValue) ;
  mCount ++ ;
}

//---------------------------------------------------------------------------------------------------------------------*
//
//   Remove object
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void AWUniqueArray <TYPE>::remove (const TYPE & inObject) {
  AWInt index = -1 ; // Means not found
  for (AWInt i=0 ; (i<mCount) && (index < 0) ; i++) {
    if (mArray [i] == inObject) {
      index = i ;
    }
  }
  if (index >= 0) {
    for (AWInt i=index+1 ; i<mCount ; i++) {
      mArray [i-1] = mArray [i] ;
    }
    mCount -- ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//
//   removeAtIndex
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void AWUniqueArray <TYPE>::removeAtIndex (const AWInt inIndex COMMA_LOCATION_ARGS) {
  macroAssertThere ((inIndex >= 0) && (inIndex <= mCount), "invalid remove index") ;
  for (AWInt i=inIndex+1 ; i<mCount ; i++) {
    mArray [i-1] = mArray [i] ;
  }
  mCount -= 1 ;
}


//---------------------------------------------------------------------------------------------------------------------*
//
//   Insert object at index
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void AWUniqueArray <TYPE>::
insertAtIndex (const TYPE & inValue, const AWInt inIndex COMMA_LOCATION_ARGS) { // inValue is copied
  macroAssertThere ((inIndex >= 0) && (inIndex <= mCount), "invalid insert index") ;
  setCapacity (mCount + 1) ;
  for (AWInt i=mCount ; i>inIndex ; i--) {
    mArray [i] = mArray [i-1] ;
  }
  mArray [inIndex] = inValue ;
  mCount ++ ;
}

//---------------------------------------------------------------------------------------------------------------------*
//
//   Insert objects at index using awSwap
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void AWUniqueArray <TYPE>::
insertObjectUsingSwap (TYPE & ioValue, const AWInt inIndex COMMA_LOCATION_ARGS) { // inValue is copied
  macroAssertThere ((inIndex >= 0) && (inIndex <= mCount), "invalid insert index") ;
  setCapacity (mCount + 1) ;
  for (AWInt i=mCount ; i>inIndex ; i--) {
    awSwap (mArray [i], mArray [i-1]) ;
  }
  awSwap (mArray [inIndex], ioValue) ;
  mCount ++ ;
}

//---------------------------------------------------------------------------------------------------------------------*
//
//   Array Access
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void AWUniqueArray <TYPE>::setAtIndex (const TYPE & inObject,
                                                                const AWInt inIndex
                                                                COMMA_LOCATION_ARGS) {
  macroAssertThere ((inIndex >= 0) && (inIndex < mCount), "invalid index") ;
  if (NULL != mArray) {
    mArray [inIndex] = inObject ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> TYPE & AWUniqueArray <TYPE>::operator () (const AWInt inIndex COMMA_LOCATION_ARGS) {
  macroAssertThere ((inIndex >= 0) && (inIndex < mCount), "invalid index") ;
  return mArray [inIndex] ;
}

//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> const TYPE & AWUniqueArray <TYPE>::operator () (const AWInt inIndex COMMA_LOCATION_ARGS) const {
  macroAssertThere ((inIndex >= 0) && (inIndex < mCount), "invalid index") ;
  return mArray [inIndex] ;
}

//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> const TYPE AWUniqueArray <TYPE>::lastObject (LOCATION_ARGS) const {
  macroAssertThere (mCount > 0, "empty array") ;
  return mArray [mCount-1] ;
}

//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> TYPE & AWUniqueArray <TYPE>::lastObject (LOCATION_ARGS) {
  macroAssertThere (mCount > 0, "empty array") ;
  return mArray [mCount-1] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//
//   Unsafe array pointer
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> const TYPE * AWUniqueArray <TYPE>::unsafeArrayPointer (void) const {
  return mArray ;
}

//---------------------------------------------------------------------------------------------------------------------*
//
//   awSwap function for AWUniqueArray <TYPE> classes
//
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void awSwap (AWUniqueArray <TYPE> & ioOperand1,
                                      AWUniqueArray <TYPE> & ioOperand2) {
  const AWInt nc = ioOperand1.mCount ;
  ioOperand1.mCount = ioOperand2.mCount ;
  ioOperand2.mCount = nc ;
  const AWInt cy = ioOperand1.mCapacity ;
  ioOperand1.mCapacity = ioOperand2.mCapacity ;
  ioOperand2.mCapacity = cy ;
  TYPE * array = ioOperand1.mArray ;
  ioOperand1.mArray = ioOperand2.mArray ;
  ioOperand2.mArray = array ;
}

//---------------------------------------------------------------------------------------------------------------------*

#endif
