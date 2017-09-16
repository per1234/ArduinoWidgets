//
//  AWPoint.h
//  graphic
//
//  Created by Pierre Molinaro on 06/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWPoint_DEFINED
#define AWPoint_DEFINED

#include "AWInt.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWRegion ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWPoint {
//--- Default constructor (point outside screen)
  public : inline AWPoint (void) : x ((AWInt)-1), y ((AWInt)-1) {}

//--- Constructor
  public : inline AWPoint (const AWInt inX, const AWInt inY) : x (inX), y (inY) {}

//--- Equatable
  public : inline bool operator == (const AWPoint & inP) const { return (x == inP.x) && (y == inP.y) ; }
  public : inline bool operator != (const AWPoint & inP) const { return !(*this == inP) ; }

//--- Translation
  public : void translateBy (const AWInt inDx, const AWInt inDy) { x += inDx ; y += inDy ; }
  public : void translateBy (AWPoint & inTranslation) { x += inTranslation.x ; y += inTranslation.y ; }

//--- Stroke line
  public : void strokeLineInRegion (const AWPoint & inPoint, const AWRegion & inDrawRegion) const ;

  public : static void strokeLineInRegion (const AWInt inP1X,
                                           const AWInt inP1Y,
                                           const AWInt inP2X,
                                           const AWInt inP2Y,
                                           const AWRegion & inDrawRegion) ;

//--- Draw Point
  public : void drawInRegion (const AWRegion & inDrawRegion) const ;
  public : static void drawPointInRegion (const AWInt inX, const AWInt inY, const AWRegion & inDrawRegion) ;

//--- Frame circle
  public : void frameCircleInRegion (const AWInt inRadius,
                                     const AWRegion & inDrawRegion) const ;

  public : static void frameCircleInRegion (const AWInt inCenterX,
                                            const AWInt inCenterY,
                                            const AWInt inRadius,
                                            const AWRegion & inDrawRegion) ;

//--- Fill circle
  public : void fillCircleInRegion (const AWInt inRadius,
                                    const AWRegion & inDrawRegion) const ;

  public : static void fillCircleInRegion (const AWInt inCenterX,
                                           const AWInt inCenterY,
                                           const AWInt inRadius,
                                           const AWRegion & inDrawRegion) ;

//--- Properties
  public : AWInt x ;
  public : AWInt y ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
