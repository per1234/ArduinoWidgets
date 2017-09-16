//
//  AWRegion.hpp
//  graphic
//
//  Created by Pierre Molinaro on 09/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWRegion_DEFINED
#define AWRegion_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWUniqueArray.h"
#include "AWPoint.h"
#include "AWSize.h"
#include "AWRect.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   AWRegion
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWRegion {
//--- Default constructor (build an empty region)
  public : AWRegion (void) ;

//--- Region from a rectangle (empty if rectangle is empty)
  public : AWRegion (const AWRect & inRect) ;

//--- Destructor
  public : ~ AWRegion (void) ;

//--- release region, becomes empty
  public : void release (void) ;

//--- Accessors
  public : inline bool isEmpty (void) const { return NULL == mPtr ; }
  public : AWInt rectCount (void) const ;
  public : AWRect rectAtIndex (const AWInt inIndex) const ;

//--- Difference from a rectangle
  public : void operator -= (const AWRect & inRect) ;

//--- Adding a rectangle
  public : void operator += (const AWRect & inRect) ;

//--- Intersection with a rectangle
  public : AWRegion operator & (const AWRect & inRect) const ;
  public : bool intersects (const AWRect & inOtherRect) const ;

//--- Intersection of regions
  public : AWRegion operator & (const AWRegion & inRect) const ;

//--- Enclosing rectangle
  public : AWRect enclosingRect (void) const ;

//--- Testing a point
  public : bool containsPoint (const AWPoint & inPoint) const ;
  public : bool containsPoint (const AWInt inX, const AWInt inY) const ;

//--- Handle copy
  public : AWRegion (const AWRegion & inRegion) ;
  public : AWRegion & operator = (const AWRegion & inRegion) ;

//--- Private methods
  private : void insulate (AWUniqueArray <class AWRect> & ioElements) ;

//--- Properties
  private : class cSharedRegion * mPtr ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
