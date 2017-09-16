//
//  AWDynamicSlider.hpp
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 19/07/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#ifndef AWDynamicSlider_h
#define AWDynamicSlider_h

#include "AWSlider.h"

class AWDynamicSlider : public AWSlider
{
  public : AWDynamicSlider ( const AWPoint & inOrigin,
                             const AWInt inSize,
                             const bool inOrientation,
                             const bool inHasRuler = true ) ;
  
  //--- No copy
  private : AWDynamicSlider (const AWDynamicSlider &) ;
  private : AWDynamicSlider & operator = (const AWDynamicSlider &) ;
  
  //--- Draw
  public : virtual void drawInRegion ( const AWRegion & inDrawRegion ) const ;
  
  //--- Position
  private : AWInt mDynKnobPosition ;
  public : inline AWInt dynamicKnobPosition (void) const { return mDynKnobPosition ; }
  public : void setDynamicKnobPosition ( AWInt inKnobPosition ) ;
  private : AWRect dynamicKnobRect() const ;
  
};

#endif /* AWDynamicSlider_h */
