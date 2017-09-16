//
//  AWRegion.cpp
//
//  Created by Pierre Molinaro on 09/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWRegion.h"
#include "AWRect.h"
#include "AW-min-max.h"
#include "AW-swap.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <limits.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   cSharedRegion
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class cSharedRegion {
//--- Default constructor
  public : cSharedRegion (void) ;

//--- No copy
  private : cSharedRegion (const cSharedRegion &) ;
  private : cSharedRegion & operator = (const cSharedRegion &) ;

//--- Properties
  public : size_t mReferenceCount ;
  public : AWUniqueArray <AWRect> mElements ;
  public : AWRect mEnclosingRect ;
  public : bool mEnclosingRectComputed ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

cSharedRegion::cSharedRegion (void) :
mReferenceCount (1),
mElements (),
mEnclosingRect (),
mEnclosingRectComputed (false) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   AWRegion
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRegion::AWRegion (void) :
mPtr (NULL) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRegion::AWRegion (const AWRect & inRect) :
mPtr (NULL) {
  if (!inRect.isEmpty()) {
    mPtr = new cSharedRegion ;
    mPtr->mElements.append (inRect) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRegion::AWRegion (const AWRegion & inRegion) :
mPtr (inRegion.mPtr)  {
  if (NULL != mPtr) {
    mPtr->mReferenceCount += 1 ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRegion & AWRegion::operator = (const AWRegion & inRegion) {
  if (mPtr != inRegion.mPtr) {
    release () ;
    mPtr = inRegion.mPtr ;
    if (NULL != mPtr) {
      mPtr->mReferenceCount += 1 ;
    }
  }
  return *this ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRegion::~ AWRegion (void) {
  release () ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRegion::release (void) {
  if (NULL != mPtr) {
    mPtr->mReferenceCount -= 1 ;
    if (0 == mPtr->mReferenceCount) {
      delete mPtr ;
    }
    mPtr = NULL ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRegion::insulate (AWUniqueArray <AWRect> & ioElements) {
  if (ioElements.count() == 0) {
    release () ;
  }else if (NULL == mPtr) {
    mPtr = new cSharedRegion ;
    mPtr->mEnclosingRectComputed = false ;
    awSwap (mPtr->mElements, ioElements) ;
  }else if (1 == mPtr->mReferenceCount) {
    awSwap (mPtr->mElements, ioElements) ;
    mPtr->mEnclosingRectComputed = false ;
  }else{
    cSharedRegion * p = new cSharedRegion ;
    awSwap (p->mElements, ioElements) ;
    mPtr->mReferenceCount -= 1 ;
    mPtr = p ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   DIFFERENCE FROM A RECTANGLE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRegion::operator -= (const AWRect & inRect) {
  if (!isEmpty () && !inRect.isEmpty ()) {
    AWUniqueArray <AWRect> resultArray ;
    AWRect r1 ;
    AWRect r2 ;
    AWRect r3 ;
    AWRect r4 ;
    for (AWInt i=0 ; i < mPtr->mElements.count () ; i++) {
      const AWRect r = mPtr->mElements (i COMMA_HERE) ;
      r.differenceFrom (inRect, r1, r2, r3, r4) ;
      if (!r1.isEmpty ()) {
        resultArray.append (r1) ;
      }
      if (!r2.isEmpty ()) {
        resultArray.append (r2) ;
      }
      if (!r3.isEmpty ()) {
        resultArray.append (r3) ;
      }
      if (!r4.isEmpty ()) {
        resultArray.append (r4) ;
      }
    }
    insulate (resultArray) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   INTERSECTION WITH A RECTANGLE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRegion AWRegion::operator & (const AWRect & inRect) const {
  AWRegion result ; // Empty region
  if (!isEmpty () && !inRect.isEmpty ()) {
    AWUniqueArray <AWRect> resultArray ;
    for (AWInt i=0 ; i < mPtr->mElements.count () ; i++) {
      const AWRect r = mPtr->mElements (i COMMA_HERE) ;
      const AWRect resultRect = r & inRect ;
      if (!resultRect.isEmpty()) {
        resultArray.append (resultRect) ;
      }
    }
    result.insulate (resultArray) ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWRegion::intersects (const AWRect & inRect) const {
  bool result = false ; // Empty region
  if (!isEmpty () && !inRect.isEmpty ()) {
    for (AWInt i=0 ; (i < mPtr->mElements.count ()) && !result ; i++) {
      const AWRect r = mPtr->mElements (i COMMA_HERE) ;
      result = r.intersects (inRect) ;
    }
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   INTERSECTION WITH A REGION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRegion AWRegion::operator & (const AWRegion & inRegion) const {
  AWRegion result ; // Empty region
  if (!isEmpty () && !inRegion.isEmpty ()) {
    AWUniqueArray <AWRect> resultArray ;
    for (AWInt i=0 ; i < mPtr->mElements.count () ; i++) {
      const AWRect ri = mPtr->mElements (i COMMA_HERE) ;
      for (AWInt j=0 ; j < inRegion.mPtr->mElements.count () ; j++) {
        const AWRect rj = inRegion.mPtr->mElements (j COMMA_HERE) ;
        const AWRect r = ri & rj ;
        if (!r.isEmpty ()) {
          resultArray.append (r) ;
        }
      }
    }
    result.insulate (resultArray) ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   ADDING A RECTANGLE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static void internalAddRectangle (const AWUniqueArray <AWRect> & inSourceArray,
                                  const AWInt inIndex,
                                  const AWRect & inRect,
                                  AWUniqueArray <AWRect> & outResultArray) {
  if (inIndex == inSourceArray.count ()) {
    outResultArray.append (inRect) ;
  }else{
    AWRect r1 ;
    AWRect r2 ;
    AWRect r3 ;
    AWRect r4 ;
    const AWRect r = inSourceArray (inIndex COMMA_HERE) ;
    inRect.differenceFrom (r, r1, r2, r3, r4) ;
    if (!r1.isEmpty ()) {
      internalAddRectangle (inSourceArray, inIndex + 1, r1, outResultArray) ;
    }
    if (!r2.isEmpty ()) {
      internalAddRectangle (inSourceArray, inIndex + 1, r2, outResultArray) ;
    }
    if (!r3.isEmpty ()) {
      internalAddRectangle (inSourceArray, inIndex + 1, r3, outResultArray) ;
    }
    if (!r4.isEmpty ()) {
      internalAddRectangle (inSourceArray, inIndex + 1, r4, outResultArray) ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRegion::operator += (const AWRect & inRect) {
  if (!inRect.isEmpty ()) {
    AWUniqueArray <AWRect> resultArray ;
    if (isEmpty ()) {
      resultArray.append (inRect) ;
    }else{
      for (AWInt i=0 ; i < mPtr->mElements.count () ; i++) {
        resultArray.append (mPtr->mElements (i COMMA_HERE)) ;
      }
      internalAddRectangle (mPtr->mElements, 0, inRect, resultArray) ;
    }
    insulate (resultArray) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   ENCLOSING RECTANGLE
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWRegion::enclosingRect (void) const {
  AWRect result ; // Empty rect
  if (!isEmpty ()) {
    if (mPtr->mEnclosingRectComputed) {
      result = mPtr->mEnclosingRect ;
    }else{
      for (AWInt i=0 ; (i < mPtr->mElements.count ()) ; i++) {
        const AWRect r = mPtr->mElements (i COMMA_HERE) ;
        result = result + r ;
      }
      mPtr->mEnclosingRect = result ;
      mPtr->mEnclosingRectComputed = true ;
    }
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   TESTING A POINT
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWRegion::containsPoint (const AWPoint & inPoint) const {
  bool result = false ;
  if (!isEmpty ()) {
    for (AWInt i=0 ; (i < mPtr->mElements.count ()) && !result ; i++) {
      result = mPtr->mElements (i COMMA_HERE).containsPoint (inPoint) ;
    }
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWRegion::containsPoint (const AWInt inX, const AWInt inY) const {
  return containsPoint (AWPoint (inX, inY)) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   ACCESSING RECTANGLES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWRegion::rectCount (void) const {
  AWInt result = 0 ;
  if (NULL != mPtr) {
    result = mPtr->mElements.count () ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWRegion::rectAtIndex (const AWInt inIndex) const {
  AWRect result ; // Empty rect
  if ((NULL != mPtr) && (inIndex < mPtr->mElements.count ())) {
    result = mPtr->mElements (inIndex COMMA_HERE) ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

