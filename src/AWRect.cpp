//
//  AWRect.cpp
//  graphic
//
//  Created by Pierre Molinaro on 06/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWRect.h"
#include "AW-min-max.h"
#include "AWContext.h"
#include "AWColor.h"
#include "AWRegion.h"
#include "Arduino.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

template AWInt awMin<AWInt> (const AWInt inA, const AWInt inB) ;
template AWInt awMax<AWInt> (const AWInt inA, const AWInt inB) ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect::AWRect (const AWPoint & inP1, const AWPoint & inP2) :
origin (awMin (inP1.x, inP2.x), awMin (inP1.y, inP2.y)),
size (awMax (inP1.x, inP2.x), awMax (inP1.y, inP2.y)) {
  size.width -= origin.x ;
  size.width += 1 ;
  size.height -= origin.y ;
  size.height += 1 ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWRect::horizontalLine (const AWInt inX, const AWInt inY, const AWInt inWidth) {
  return AWRect (AWPoint (inX, inY), AWSize (inWidth, 1)) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWRect::verticalLine (const AWInt inX, const AWInt inY, const AWInt inHeight) {
  return AWRect (AWPoint (inX, inY), AWSize (1, inHeight)) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWPoint AWRect::topRight (void) const {
  return AWPoint (origin.x + size.width - 1, origin.y + size.height - 1) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWPoint AWRect::bottomRight (void) const {
  return AWPoint (origin.x + size.width - 1, origin.y) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWPoint AWRect::topLeft (void) const {
  return AWPoint (origin.x , origin.y + size.height - 1) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWRect::containsPoint (const AWPoint & inPoint) const {
  bool contains = (inPoint.x >= origin.x) && (inPoint.y >= origin.y) ;
  if (contains) {
    const AWPoint tr = topRight () ;
    contains = (inPoint.x <= tr.x) && (inPoint.y <= tr.y) ;
  }
  return contains ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWRect::operator & (const AWRect & inOtherRect) const {
  AWRect result ; // Empty rect
  if (!isEmpty() && !inOtherRect.isEmpty ()) {
    const AWPoint newOrigin (awMax (origin.x, inOtherRect.origin.x), awMax (origin.y, inOtherRect.origin.y)) ;
    const AWPoint myTopRight = topRight () ;
    const AWPoint otherTopRight = inOtherRect.topRight () ;
    const AWPoint newTopRight (awMin (myTopRight.x, otherTopRight.x), awMin (myTopRight.y, otherTopRight.y)) ;
    const AWSize newSize (newTopRight.x - newOrigin.x + 1, newTopRight.y - newOrigin.y + 1) ;
    result = AWRect (newOrigin, newSize) ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWRect::intersects (const AWRect & inOtherRect) const {
  bool result = false ;
  if (!isEmpty() && !inOtherRect.isEmpty ()) {
    const AWPoint newOrigin (awMax (origin.x, inOtherRect.origin.x), awMax (origin.y, inOtherRect.origin.y)) ;
    const AWPoint myTopRight = topRight () ;
    const AWPoint otherTopRight = inOtherRect.topRight () ;
    const AWPoint newTopRight (awMin (myTopRight.x, otherTopRight.x), awMin (myTopRight.y, otherTopRight.y)) ;
    const int intersectionWidth = newTopRight.x - newOrigin.x + 1 ;
    const int intersectionHeight = newTopRight.y - newOrigin.y + 1 ;
    result = (intersectionWidth > 0) && (intersectionHeight > 0) ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// Returns the smallest rectangle that completely encloses both receiver rect and inOtherRect

AWRect AWRect::operator + (const AWRect & inOtherRect) const {
  AWRect r ;
  if (isEmpty ()) {
    r = inOtherRect ;
  } else if (inOtherRect.isEmpty ()) {
    r = *this ;
  } else { // Both rectangles are non empty
    const AWInt left = awMin (origin.x, inOtherRect.origin.x) ;
    const AWInt bottom = awMin (origin.y, inOtherRect.origin.y) ;
    const AWInt rightPlusOne = awMax ((AWInt) (origin.x + size.width), (AWInt) (inOtherRect.origin.x + inOtherRect.size.width)) ;
    const AWInt topPlusOne = (AWInt) awMax (origin.y + size.height, inOtherRect.origin.y + inOtherRect.size.height) ;
    const AWInt newWidth = rightPlusOne - left ;
    const AWInt newHeight = topPlusOne - bottom ;
    r = AWRect (left, bottom, newWidth, newHeight) ;
  }
  return r ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRect::operator += (const AWRect inOtherRect) {
  *this = *this + inOtherRect ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRect::inset (const AWInt inDx, const AWInt inDy) {
  origin.x += inDx ;
  origin.y += inDy ;
  size.width  -= inDx + inDx ;
  size.height -= inDy + inDy ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRect::translateBy (const AWInt inDx, const AWInt inDy) {
  origin.x += inDx ;
  origin.y += inDy ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWRect::includesRect (const AWRect & inOtherRect) const {
  bool result = inOtherRect.isEmpty () ;
  if (!result) {
    result = (origin.x <= inOtherRect.origin.x)
      && (origin.y <= inOtherRect.origin.y)
      && ((origin.x + size.width) >= (inOtherRect.origin.x + inOtherRect.size.width))
      && ((origin.y + size.height) >= (inOtherRect.origin.y + inOtherRect.size.height))
    ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRect::differenceFrom (const AWRect & inRect,
                             AWRect & outR1,
                             AWRect & outR2,
                             AWRect & outR3,
                             AWRect & outR4) const {
//--- Compute R1
  outR1.origin = origin ;
  outR1.size.width = awMin (size.width, (AWInt) (inRect.origin.x - origin.x)) ;
  outR1.size.height = awMin (size.height, (AWInt) (inRect.origin.y + inRect.size.height - origin.y)) ;
//--- Compute R2
  outR2.origin.x = awMax (origin.x, inRect.origin.x) ;
  outR2.origin.y = origin.y ;
  outR2.size.width = origin.x + size.width - outR2.origin.x ;
  outR2.size.height = awMin (size.height, (AWInt) (inRect.origin.y - origin.y)) ;
//--- Compute R3
  outR3.origin.x = awMax (origin.x, (AWInt) (inRect.origin.x + inRect.size.width)) ;
  outR3.origin.y = awMax (inRect.origin.y, origin.y) ;
  outR3.size.width = origin.x + size.width - outR3.origin.x ;
  outR3.size.height = origin.y + size.height - outR3.origin.y ;
//--- Compute R4
  outR4.origin.x = origin.x ; // max (origin.x, inRect.origin.x) ;
  outR4.origin.y = awMax (origin.y, (AWInt) (inRect.origin.y + inRect.size.height)) ;
  outR4.size.width = awMin ((AWInt) (origin.x + size.width), (AWInt) (inRect.origin.x + inRect.size.width)) - outR4.origin.x ;
  outR4.size.height = origin.y + size.height - outR4.origin.y ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   DRAWING
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRect::fillRectInRegion (const AWRegion & inDrawRegion) const {
  if (AWContext::colorIsOpaque ()) {
    const AWRegion drawRegion = inDrawRegion & *this ;
    for (AWInt i=0 ; i<drawRegion.rectCount() ; i++) {
      const AWRect r = drawRegion.rectAtIndex (i) ;
      for (AWInt y = r.origin.y ; y < (r.origin.y + r.size.height) ; y++) {
        AWContext::drawHLine (r.origin.x, y, r.size.width) ;
      }
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRect::frameRectInRegion (const AWRegion & inDrawRegion) const {
  if (AWContext::colorIsOpaque ()) {
    const AWRegion drawRegion = inDrawRegion & *this ;
    if (!drawRegion.isEmpty ()) {
      AWRect::horizontalLine (origin.x, origin.y, size.width).fillRectInRegion (drawRegion) ;
      if (size.height > 1) {
        AWRect::horizontalLine (origin.x, origin.y + size.height - 1, size.width).fillRectInRegion (drawRegion) ;
      }
      if (size.height > 2) {
        AWRect::verticalLine (origin.x, origin.y + 1, size.height - 2).fillRectInRegion (drawRegion) ;
        if (size.height > 1) {
          AWRect::verticalLine (origin.x + size.width - 1, origin.y + 1, size.height - 2).fillRectInRegion (drawRegion) ;
        }
      }
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRect::fillRoundRectInRegion (const AWInt inRadius, const AWRegion & inDrawRegion) const {
  if (AWContext::colorIsOpaque ()) {
    const AWRegion drawRegion = inDrawRegion & *this ;
    if (!drawRegion.isEmpty ()) {
     const AWInt radius = awMin (inRadius, (AWInt) (awMin (size.width, size.height) / 2)) ;
     if (radius <= 1) {
        frameRectInRegion (drawRegion) ;
      }else{
        const AWInt centerXLeft   = origin.x + radius ;
        const AWInt centerYTop    = origin.y + size.height - 1 - radius ;
        const AWInt centerYBottom = origin.y + radius ;
        const AWRect r (origin.x, centerYBottom, size.width, centerYTop - centerYBottom + 1) ;
        r.fillRectInRegion (inDrawRegion) ;
        const AWInt centralWidth = size.width - 2 * radius ;
        AWInt x = 0 ;
        AWInt y = radius ;
        AWInt m = 5 - 4 * radius ;
        while (x <= y) {
          AWRect::horizontalLine (centerXLeft - y, centerYTop + x, 2 * y + centralWidth).fillRectInRegion (inDrawRegion) ;
          AWRect::horizontalLine (centerXLeft - y, centerYBottom - x, 2 * y + centralWidth).fillRectInRegion (inDrawRegion) ;
          if (m > 0) {
            AWRect::horizontalLine (centerXLeft - x, centerYTop + y, 2 * x + centralWidth).fillRectInRegion (inDrawRegion) ;
            AWRect::horizontalLine (centerXLeft - x, centerYBottom - y, 2 * x + centralWidth).fillRectInRegion (inDrawRegion) ;
            y -= 1 ;
            m -= 8 * y ;
          }
          x += 1 ;
          m += 8 * x + 4 ;
        }
      }
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRect::frameRoundRectInRegion (const AWInt inRadius, const AWRegion & inDrawRegion) const {
  if (AWContext::colorIsOpaque ()) {
    const AWRegion drawRegion = inDrawRegion & *this ;
    if (!drawRegion.isEmpty ()) {
     const AWInt radius = awMin (inRadius, (AWInt) (awMin (size.width, size.height) / 2)) ;
     if (radius <= 1) {
        frameRectInRegion (drawRegion) ;
      }else{
        const AWInt centerXRight  = origin.x + size.width - 1 - radius ;
        const AWInt centerXLeft   = origin.x + radius ;
        const AWInt centerYTop    = origin.y + size.height - 1 - radius ;
        const AWInt centerYBottom = origin.y + radius ;
        AWPoint::strokeLineInRegion (centerXLeft, centerYTop + radius, centerXRight, centerYTop + radius, inDrawRegion) ;
        AWPoint::strokeLineInRegion (centerXLeft, centerYBottom - radius, centerXRight, centerYBottom - radius, inDrawRegion) ;
        AWPoint::strokeLineInRegion (centerXLeft - radius, centerYTop, centerXLeft - radius, centerYBottom, inDrawRegion) ;
        AWPoint::strokeLineInRegion (centerXRight + radius, centerYTop, centerXRight + radius, centerYBottom, inDrawRegion) ;

        AWInt x = 0 ;
        AWInt y = radius ;
        AWInt m = 5 - 4 * radius ;
        while (x <= y) {
          AWPoint::drawPointInRegion (centerXRight + x, centerYTop    + y, inDrawRegion) ;
          AWPoint::drawPointInRegion (centerXRight + x, centerYBottom - y, inDrawRegion) ;
          AWPoint::drawPointInRegion (centerXLeft  - x, centerYBottom - y, inDrawRegion) ;
          AWPoint::drawPointInRegion (centerXLeft  - x, centerYTop    + y, inDrawRegion) ;
          AWPoint::drawPointInRegion (centerXRight + y, centerYTop    + x, inDrawRegion) ;
          AWPoint::drawPointInRegion (centerXRight + y, centerYBottom - x, inDrawRegion) ;
          AWPoint::drawPointInRegion (centerXLeft  - y, centerYBottom - x, inDrawRegion) ;
          AWPoint::drawPointInRegion (centerXLeft  - y, centerYTop    + x, inDrawRegion) ;
          if (m > 0) {
            y -= 1 ;
            m -= 8 * y ;
          }
          x += 1 ;
          m += 8 * x + 4 ;
        }
      }
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// https://sites.google.com/site/ruslancray/lab/projects/bresenhamscircleellipsedrawingalgorithm/bresenham-s-circle-ellipse-drawing-algorithm

// #define CHECK_FILL_OVAL

#ifdef CHECK_FILL_OVAL
  #include <math.h>
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRect::fillOvalInRegion (const AWRegion & inDrawRegion) const {
  if (AWContext::colorIsOpaque ()) {
    const AWRegion drawRegion = inDrawRegion & *this ;
    if (!drawRegion.isEmpty ()) {
      const AWInt width = (size.width - 1) / 2 ;
      const AWInt height = (size.height - 1) / 2 ;
      const AWInt centerXRight  = origin.x + size.width / 2 ;
      const AWInt centerXLeft   = origin.x + (size.width - 1) / 2 ;
      const AWInt centerYTop    = origin.y + size.height / 2 ;
      const AWInt centerYBottom = origin.y + (size.height - 1) / 2 ;
      #ifdef CHECK_FILL_OVAL
        { const AWColor savedColor = AWContext::color () ;
          AWContext::setColor (AWColor::white ()) ;
          const float af = (float) width ;
          const float bf = (float) height ;
          for (int xx=0 ; xx<width ; xx++) {
            const float x_div_a = ((float) xx) / af ;
            const float fy = bf * sqrtf (1.0F - x_div_a * x_div_a) ;
            const int yy = (int) lrint (fy) ;
            AWPoint::strokeLineInRegion (centerXLeft - xx, centerYTop + yy, centerXLeft, centerYTop + yy, inDrawRegion) ;
          }
          for (int yy=0 ; yy<=height ; yy++) {
            const float y_div_b = ((float) yy) / bf ;
            const int xx = (int) lrint (af * sqrtf (1.0F - y_div_b * y_div_b)) ;
            AWPoint::strokeLineInRegion (centerXLeft - xx, centerYTop + yy, centerXLeft, centerYTop + yy, inDrawRegion) ;
          }
          AWContext::setColor (savedColor) ;
        }
      #endif

      const int a2 = width * width ; // Use int! Overflow occurs with short
      const int b2 = height * height ; // Use int! Overflow occurs with short
      const int fa2 = 4 * a2 ;
      const int fb2 = 4 * b2 ;
      AWInt x, y ;
      int sigma ;
    //--- First half
      for (x = 0, y = height, sigma = 2*b2+a2*(1-2*height) ; b2*x <= a2*y; x++) {
        AWPoint::strokeLineInRegion (centerXLeft  - x, centerYTop    + y, centerXRight + x, centerYTop    + y, inDrawRegion) ;
        AWPoint::strokeLineInRegion (centerXLeft  - x, centerYBottom - y, centerXRight + x, centerYBottom - y, inDrawRegion) ;
        if (sigma >= 0) {
          sigma += fa2 * (1 - y);
          y -= 1;
        }
        sigma += b2 * (4 * x + 6);
      }
    //--- Second half
      for (x = width, y = 0, sigma = 2*a2+b2*(1-2*width); a2*y <= b2*x; y++) {
        AWPoint::strokeLineInRegion (centerXLeft  - x, centerYTop    + y, centerXRight + x, centerYTop    + y, inDrawRegion) ;
        AWPoint::strokeLineInRegion (centerXLeft  - x, centerYBottom - y, centerXRight + x, centerYBottom - y, inDrawRegion) ;
        if (sigma >= 0) {
          sigma += fb2 * (1 - x) ;
          x--;
        }
        sigma += a2 * (4 * y + 6);
      }
      #ifdef CHECK_FILL_OVAL
        { const AWColor savedColor = AWContext::color () ;
          AWContext::setColor (AWColor::white ()) ;
          const float af = (float) width ;
          const float bf = (float) height ;
          for (int xx=0 ; xx<width ; xx++) {
            const float x_div_a = ((float) xx) / af ;
            const float fy = bf * sqrtf (1.0F - x_div_a * x_div_a) ;
            const int yy = (int) lrint (fy) ;
            AWPoint::drawPointInRegion (centerXRight + xx, centerYTop + yy, inDrawRegion) ;
          }
          for (int yy=0 ; yy<=height ; yy++) {
            const float y_div_b = ((float) yy) / bf ;
            const int xx = (int) lrint (af * sqrtf (1.0F - y_div_b * y_div_b)) ;
            AWPoint::drawPointInRegion (centerXRight + xx, centerYTop + yy, inDrawRegion) ;
          }
          AWContext::setColor (savedColor) ;
        }
      #endif
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// #define CHECK_FRAME_OVAL

#ifdef CHECK_FRAME_OVAL
  #include <math.h>
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWRect::frameOvalInRegion (const AWRegion & inDrawRegion) const {
  if (AWContext::colorIsOpaque ()) {
    const AWRegion drawRegion = inDrawRegion & *this ;
    if (!drawRegion.isEmpty ()) {
      const AWInt width = (size.width - 1) / 2 ;
      const AWInt height = (size.height - 1) / 2 ;
      const AWInt centerXRight  = origin.x + size.width / 2 ;
      const AWInt centerXLeft   = origin.x + (size.width - 1) / 2 ;
      const AWInt centerYTop    = origin.y + size.height / 2 ;
      const AWInt centerYBottom = origin.y + (size.height - 1) / 2 ;

      const AWInt a2 = width * width ;
      const AWInt b2 = height * height ;
      const AWInt fa2 = 4 * a2 ;
      const AWInt fb2 = 4 * b2 ;
      AWInt x, y, sigma;
    //--- First half
      for (x = 0, y = height, sigma = 2*b2+a2*(1-2*height); b2*x <= a2*y; x++) {
        AWPoint::drawPointInRegion (centerXRight + x, centerYTop    + y, inDrawRegion) ;
        AWPoint::drawPointInRegion (centerXLeft  - x, centerYTop    + y, inDrawRegion) ;
        AWPoint::drawPointInRegion (centerXRight + x, centerYBottom - y, inDrawRegion) ;
        AWPoint::drawPointInRegion (centerXLeft  - x, centerYBottom - y, inDrawRegion) ;
        if (sigma >= 0) {
          sigma += fa2 * (1 - y);
          y -= 1;
        }
        sigma += b2 * (4 * x + 6);
      }
    //--- Second half
      for (x = width, y = 0, sigma = 2*a2+b2*(1-2*width); a2*y <= b2*x; y++) {
        AWPoint::drawPointInRegion (centerXRight + x,   centerYTop + y, inDrawRegion) ;
        AWPoint::drawPointInRegion (centerXLeft  - x,   centerYTop + y, inDrawRegion) ;
        AWPoint::drawPointInRegion (centerXRight + x, centerYBottom - y, inDrawRegion) ;
        AWPoint::drawPointInRegion (centerXLeft  - x, centerYBottom - y, inDrawRegion) ;
        if (sigma >= 0) {
          sigma += fb2 * (1 - x) ;
          x--;
        }
        sigma += a2 * (4 * y + 6);
      }
      #ifdef CHECK_FRAME_OVAL
        const AWColor savedColor = AWContext::color () ;
        AWContext::setColor (AWColor::white ()) ;
        const float af = (float) width ;
        const float bf = (float) height ;
        for (int xx=0 ; xx<width ; xx++) {
          const float x_div_a = ((float) xx) / af ;
          const float fy = bf * sqrtf (1.0F - x_div_a * x_div_a) ;
          const int yy = (int) lrint (fy) ;
          AWPoint::drawPointInRegion (centerXRight + xx, centerYTop + yy, inDrawRegion) ;
        }
        for (int yy=0 ; yy<=height ; yy++) {
          const float y_div_b = ((float) yy) / bf ;
          const int xx = (int) lrint (af * sqrtf (1.0F - y_div_b * y_div_b)) ;
          AWPoint::drawPointInRegion (centerXRight + xx, centerYTop + yy, inDrawRegion) ;
        }
      AWContext::setColor (savedColor) ;
      #endif
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

