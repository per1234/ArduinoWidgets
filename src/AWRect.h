//
//  AWRect.hpp
//  graphic
//
//  Created by Pierre Molinaro on 06/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWRect_DEFINED
#define AWRect_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWPoint.h"
#include "AWSize.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWContext ;
class AWRegion ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWRect {
//--- Default constructor (invisible rectangle)
  public : inline AWRect (void) : origin (), size () {}

//--- Constructors
  public : inline AWRect (const AWPoint inOrigin, const AWSize inSize) : origin (inOrigin), size (inSize) {}
  public : inline AWRect (const AWPoint inOrigin) : origin (inOrigin), size (AWSize (1, 1)) {}
  public : inline AWRect (const AWInt inX, const AWInt inY, const AWInt inWidth, const AWInt inHeight) :
  origin (AWPoint (inX, inY)),
  size (AWSize (inWidth, inHeight)) {
  }
  public : AWRect (const AWPoint & inP1, const AWPoint & inP2) ;
  public : static AWRect horizontalLine (const AWInt inX, const AWInt inY, const AWInt inWidth) ;
  public : static AWRect verticalLine (const AWInt inX, const AWInt inY, const AWInt inHeight) ;

//--- Accessors
  public : inline bool isEmpty (void) const { return (size.width <= 0) || (size.height <= 0) ; }
  public : bool containsPoint (const AWPoint & inPoint) const ;
  public : AWPoint topRight (void) const ;
  public : AWPoint bottomRight (void) const ;
  public : AWPoint topLeft (void) const ;
  public : inline AWPoint bottomLeft (void) const { return origin ; }
  public : inline AWInt minX (void) const { return origin.x ; }
  public : inline AWInt maxX (void) const { return origin.x + size.width - 1 ; }
  public : inline AWInt minY (void) const { return origin.y ; }
  public : inline AWInt maxY (void) const { return origin.y + size.height - 1 ; }

//--- Intersection
  public : AWRect operator & (const AWRect & inOtherRect) const ;
  public : bool intersects (const AWRect & inOtherRect) const ;

//--- Inclusion
  public : bool includesRect (const AWRect & inOtherRect) const ;

//--- Union (Returns the smallest rectangle that completely encloses both receiver rect and inOtherRect)
  public : AWRect operator + (const AWRect & inOtherRect) const ;
  public : void operator += (const AWRect inOtherRect) ;

//--- Difference (Returns 4 rects, possibly empty)
  public : void differenceFrom (const AWRect & inRect,
                                AWRect & outR1,
                                AWRect & outR2,
                                AWRect & outR3,
                                AWRect & outR4) const ;

//--- Transforming rectangle
  public : void inset (const AWInt inDx, const AWInt inDy) ;
  public : void translateBy (const AWInt inDx, const AWInt inDy) ;

//--- Equatable
  public : bool operator == (const AWRect & inRect) const { return (origin == inRect.origin) && (size == inRect.size) ; }
  public : inline bool operator != (const AWRect & inRect) const { return ! (*this == inRect) ; }

//--- Drawing
  public : void fillRectInRegion (const AWRegion & inDrawRegion) const ;
  public : void frameRectInRegion (const AWRegion & inDrawRegion) const ;
  public : void fillRoundRectInRegion (const AWInt inRadius, const AWRegion & inDrawRegion) const ;
  public : void frameRoundRectInRegion (const AWInt inRadius, const AWRegion & inDrawRegion) const ;
  public : void fillOvalInRegion (const AWRegion & inDrawRegion) const ;
  public : void frameOvalInRegion (const AWRegion & inDrawRegion) const ;

//--- Properties
  public : AWPoint origin ;
  public : AWSize size ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
