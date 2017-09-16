//
//  AWSlider.cpp
//  graphic
//
//  Created by Jean-Luc Béchennec on 17/07/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//

#include "AWSlider.h"
#include "AWContext.h"
#include "AW-settings.h"

static const AWColor kKnobColor = AWColor::white() ;
static const AWColor kKnobColorTouched = AWColor::darkGray() ;

//—————————————————————————————————————————————————————————————————————————————
static AWRect computeSliderRelativeRect (const AWPoint & inOrigin,
                                         const AWInt inSize,
                                         const bool inOrientation)
{
  AWRect r (inOrigin, AWSize ()) ;
  if (inOrientation == kHorizontal) {
    r.size.width = inSize ;
    r.size.height = 30 ;
  }
  else {
    r.size.width = 30 ;
    r.size.height = inSize ;
  }
  return r;
}

//—————————————————————————————————————————————————————————————————————————————
AWSlider::AWSlider ( const AWPoint & inOrigin,
                     const AWInt inSize,
                     const bool inOrientation,
                     const bool inHasRuler ) :
  AWView ( computeSliderRelativeRect (inOrigin, inSize, inOrientation),
           awkResponderBackColor ),
  mOrientation( inOrientation ),
  mKnobColor( kKnobColor ),
  mHasRuler( inHasRuler ),
  mHowManyScales( 10 ),
  mKnobPosition( 50 ),
  mMaxKnobPosition( 100 ),
  mIsEnabled( true ) {
}

//—————————————————————————————————————————————————————————————————————————————
void AWSlider::drawRulerInRegion ( const AWRegion & inDrawRegion ) const
{
  AWRect af = absoluteFrame();
  if (mOrientation == kHorizontal) {
    AWInt y = af.maxY() - 5 ;
    AWInt sizeX = af.size.width - 20 ;
    for ( AWInt scale = 0; scale <= mHowManyScales; scale++ ) {
      const AWInt x =  (af.origin.x + 10) + sizeX * scale / mHowManyScales ;
      AWPoint::strokeLineInRegion( x, y, x, y + 5, inDrawRegion ) ;
    }
  }
  else {
    AWInt x = af.minX();
    AWInt sizeY = af.size.height - 20 ;
    for ( AWInt scale = 0 ; scale <= mHowManyScales ; scale++ ) {
      const AWInt y =  (af.origin.y + 10) + sizeY * scale / mHowManyScales ;
      AWPoint::strokeLineInRegion( x, y, x + 5, y, inDrawRegion ) ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————
void AWSlider::setHowManyScales ( const AWInt inHowManyScales )
{
  if (inHowManyScales < 1) {
    mHasRuler = false ;
  }
  else {
    mHasRuler = true ;
    mHowManyScales = inHowManyScales ;
  }
  setNeedsDisplay() ;
}

//—————————————————————————————————————————————————————————————————————————————
AWInt AWSlider::pointToKnob ( const AWPoint & inPoint )
{
  const AWRect af = absoluteFrame() ;
  if ( mOrientation == kHorizontal ) {
    if ( inPoint.x - af.origin.x < 10 ) {
      return 0 ;
    }
    else if ( inPoint.x > ( af.origin.x + af.size.width ) ) {
      return mMaxKnobPosition ;
    }
    else {
      return ( inPoint.x - af.origin.x - 10 ) * mMaxKnobPosition / ( af.size.width - 20 ) ;
    }
  }
  else {
    if ( inPoint.y - af.origin.y < 10 ) {
      return 0 ;
    }
    else if ( inPoint.y > ( af.origin.y + af.size.height ) ) {
      return mMaxKnobPosition ;
    }
    else {
      return ( inPoint.y - af.origin.y - 10 ) * mMaxKnobPosition / ( af.size.height - 20 );
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————
void AWSlider::setKnobPosition( AWInt inKnobPosition, const bool inRefresh )
{
  if ( inKnobPosition < 0 ) {
    inKnobPosition = 0 ;
  }
  else if ( inKnobPosition > mMaxKnobPosition ) {
    inKnobPosition = mMaxKnobPosition ;
  }
  if ( inKnobPosition != mKnobPosition || inRefresh ) {
    AWRect invalidRect = knobRect() ;
    mKnobPosition = inKnobPosition ;
    invalidRect += knobRect() ;
    sendAction();
    setNeedsDisplayInRect(invalidRect) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————
void AWSlider::setMaxKnobPosition(const AWInt inMaxKnobPosition )
{
  if ( inMaxKnobPosition > 0 && inMaxKnobPosition != mMaxKnobPosition ) {
    mMaxKnobPosition = inMaxKnobPosition ;
    if ( mKnobPosition > mMaxKnobPosition ) {
      mKnobPosition = mMaxKnobPosition ;
    }
    setNeedsDisplay();
  }
}

//—————————————————————————————————————————————————————————————————————————————
bool AWSlider::isOpaque (void) const
{
  return false ;
}

//—————————————————————————————————————————————————————————————————————————————
AWRect AWSlider::knobRect() const
{
  AWRect r = absoluteFrame () ;
  if ( orientation() == kHorizontal ) {
    const int knobPos = mKnobPosition * (r.size.width - 20) / maxKnobPosition() ;
    r.origin.x += knobPos ;
    r.size.width = 20 ;
  }
  else {
    const int knobPos = mKnobPosition * (r.size.height - 20) / maxKnobPosition() ;
    r.origin.y += knobPos ;
    r.size.height = 20 ;
  }
  r.inset(2, 2);
  return r ;
}

//—————————————————————————————————————————————————————————————————————————————
void AWSlider::drawInRegion (const AWRegion & inDrawRegion) const
{
  AWContext::setColor( AWColor::black() ) ;
  AWRect af = absoluteFrame () ;
  AWRect knob = knobRect() ;
  if ( mOrientation == kHorizontal ) {
    af.size.height = 4 ;
    af.origin.y += 13 ;
    af.inset(10, 0) ;
  }
  else {
    af.size.width = 4 ;
    af.origin.x += 13 ;
    af.inset(0, 10) ;
  }
  af.fillRectInRegion( inDrawRegion ) ;
  if ( mHasRuler ) drawRulerInRegion( inDrawRegion ) ;
  AWContext::setColor( mKnobColor ) ;
  knob.fillOvalInRegion( inDrawRegion ) ;
  AWContext::setColor( AWColor::black() ) ;
  knob.frameOvalInRegion( inDrawRegion ) ;
}

//—————————————————————————————————————————————————————————————————————————————
void AWSlider::touchDown (const AWPoint & inPoint)
{
  mCurrentTouchPoint = inPoint ;
  AWRect af = absoluteFrame() ;
  if (mOrientation == kHorizontal) {
    /* Check the point is within the knob */
    int knobCoord = mKnobPosition * (af.size.width - 20) / mMaxKnobPosition + af.origin.x + 10 ;
    /* Compute the offset of the knob position */
    mTouchOffset = abs(knobCoord - inPoint.x) < 10 ? mKnobPosition - pointToKnob(inPoint) : 0 ;
  }
  else {
    /* Check the point is within the knob */
    int knobCoord = mKnobPosition * (af.size.height - 20) / mMaxKnobPosition + af.origin.y + 10 ;
    /* Compute the offset of the knob position */
    mTouchOffset = abs(knobCoord - inPoint.y) < 10 ? mKnobPosition - pointToKnob(inPoint) : 0 ;
  }
  mKnobColor = kKnobColorTouched ;
  setKnobPosition( mTouchOffset + pointToKnob( inPoint ), true ) ;
}

//—————————————————————————————————————————————————————————————————————————————
void AWSlider::touchMove (const AWPoint & inPoint)
{
  const int delta = (mOrientation == kHorizontal)
    ? (mCurrentTouchPoint.x - inPoint.x)
    : (mCurrentTouchPoint.y - inPoint.y)
  ;
  if (abs (delta) > 10) {
    mCurrentTouchPoint = inPoint ;
    setKnobPosition( mTouchOffset + pointToKnob( inPoint ), true) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————
void AWSlider::touchUp (const AWPoint & inPoint)
{
  mKnobColor = kKnobColor ;
  setKnobPosition( mTouchOffset + pointToKnob( inPoint ), true ) ;
}

