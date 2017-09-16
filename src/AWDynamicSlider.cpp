//
//  AWDynamicSlider.cpp
//  CocoaSimulator
//
//  Created by Jean-Luc Béchennec on 19/07/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#include "AWDynamicSlider.h"
#include "AWContext.h"

//—————————————————————————————————————————————————————————————————————————————
AWDynamicSlider::AWDynamicSlider ( const AWPoint & inOrigin,
                                   const AWInt inSize,
                                   const bool inOrientation,
                                   const bool inHasRuler ) :
  AWSlider ( inOrigin, inSize, inOrientation, inHasRuler ),
  mDynKnobPosition( 50 )
{
}


//—————————————————————————————————————————————————————————————————————————————
void AWDynamicSlider::setDynamicKnobPosition( AWInt inKnobPosition )
{
  if (inKnobPosition < 0) {
    inKnobPosition = 0 ;
  }
  else if (inKnobPosition > maxKnobPosition()) {
    inKnobPosition = maxKnobPosition() ;
  }
  if (inKnobPosition != mDynKnobPosition) {
    AWRect invalidRect = dynamicKnobRect() ;
    mDynKnobPosition = inKnobPosition ;
    invalidRect += dynamicKnobRect() ;
    setNeedsDisplayInRect(invalidRect) ;
    sendAction() ;
  }
}

//—————————————————————————————————————————————————————————————————————————————
AWRect AWDynamicSlider::dynamicKnobRect() const
{
  AWRect r = absoluteFrame () ;
  if ( orientation() == kHorizontal ) {
    const int dynKnobPos = mDynKnobPosition * (r.size.width - 20) / maxKnobPosition() ;
    r.origin.x += dynKnobPos ;
    r.size.width = 20 ;
    r.inset(2, 7) ;
  }
  else {
    const int dynKnobPos = mDynKnobPosition * (r.size.height - 20) / maxKnobPosition() ;
    r.origin.y += dynKnobPos ;
    r.size.height = 20 ;
    r.inset(7, 2) ;
  }
  return r ;
}

//—————————————————————————————————————————————————————————————————————————————
void AWDynamicSlider::drawInRegion (const AWRegion & inDrawRegion) const
{
  AWContext::setColor( AWColor::black() );
  AWRect inner = absoluteFrame () ;
  AWRect knob = knobRect() ;
  AWRect dynamicKnob = dynamicKnobRect() ;
  AWRect outerLeftBottom;
  AWRect outerRightTop;
  if ( orientation() == kHorizontal ) {
    inner.size.height = 4 ;
    inner.origin.y += 13 ;
    inner.inset(10, 0) ;
    outerLeftBottom = inner ;
    outerRightTop = inner ;
    AWRect lowerKnob, higherKnob ;
    if (knob.origin.x < dynamicKnob.origin.x) {
      lowerKnob = knob ;
      higherKnob = dynamicKnob ;
    }
    else {
      lowerKnob = dynamicKnob ;
      higherKnob = knob ;
    }
    outerLeftBottom.size.width = lowerKnob.origin.x - outerLeftBottom.origin.x ;
    outerRightTop.size.width -= higherKnob.origin.x + higherKnob.size.width - outerRightTop.origin.x ;
    outerRightTop.origin.x = higherKnob.origin.x + higherKnob.size.width ;
    inner.size.width = higherKnob.origin.x - ( lowerKnob.origin.x + lowerKnob.size.width ) ;
    inner.origin.x = lowerKnob.origin.x + lowerKnob.size.width ;
  }
  else {
    inner.size.width = 4 ;
    inner.origin.x += 13 ;
    inner.inset(0, 10) ;
    outerLeftBottom = inner ;
    outerRightTop = inner ;
    AWRect lowerKnob, higherKnob ;
    if (knob.origin.y < dynamicKnob.origin.y) {
      lowerKnob = knob ;
      higherKnob = dynamicKnob ;
    }
    else {
      lowerKnob = dynamicKnob ;
      higherKnob = knob ;
    }
    outerLeftBottom.size.height = lowerKnob.origin.y - outerLeftBottom.origin.y ;
    outerRightTop.size.height -= higherKnob.origin.y + higherKnob.size.height - outerRightTop.origin.y ;
    outerRightTop.origin.y = higherKnob.origin.y + higherKnob.size.height ;
    inner.size.height = higherKnob.origin.y - ( lowerKnob.origin.y + lowerKnob.size.height ) ;
    inner.origin.y = lowerKnob.origin.y + lowerKnob.size.height ;
  }
  outerLeftBottom.fillRectInRegion( inDrawRegion ) ;
  inner.fillRectInRegion( inDrawRegion ) ;
  outerRightTop.fillRectInRegion( inDrawRegion ) ;
  if ( hasRuler() ) drawRulerInRegion( inDrawRegion ) ;
  AWContext::setColor( AWColor::veryLightGray() ) ;
  dynamicKnob.fillOvalInRegion( inDrawRegion );
  AWContext::setColor( AWColor::black() ) ;
  dynamicKnob.frameOvalInRegion( inDrawRegion ) ;
  AWContext::setColor( mKnobColor ) ;
  knob.fillOvalInRegion( inDrawRegion ) ;
  AWContext::setColor( AWColor::black() ) ;
  knob.frameOvalInRegion( inDrawRegion ) ;
}

