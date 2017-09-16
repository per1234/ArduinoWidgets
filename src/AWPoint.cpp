//
//  AWPoint.cpp
//  graphic
//
//  Created by Pierre Molinaro on 06/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWPoint.h"
#include "AWRegion.h"
#include "AWContext.h"
#include "AWColor.h"
#include "AW-min-max.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWPoint::strokeLineInRegion (const AWPoint & inPoint, const AWRegion & inDrawRegion) const {
  strokeLineInRegion (x, y, inPoint.x, inPoint.y, inDrawRegion) ;
}


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWPoint::strokeLineInRegion (const AWInt inP1X,
                                  const AWInt inP1Y,
                                  const AWInt inP2X,
                                  const AWInt inP2Y,
                                  const AWRegion & inDrawRegion) {
  if (inP1X == inP2X) { // Vertical line
    const AWInt y = awMin (inP1Y, inP2Y) ;
    const AWInt height = awMax (inP1Y, inP2Y) - y + 1 ;
    AWRect::verticalLine (inP1X, y, height).fillRectInRegion (inDrawRegion) ;
  }else if (inP1Y == inP2Y) { // Horizontal line
    const AWInt x = awMin (inP1X, inP2X) ;
    const AWInt width = awMax (inP1X, inP2X) - x + 1 ;
    AWRect::horizontalLine (x, inP1Y, width).fillRectInRegion (inDrawRegion) ;
  }else{
  //--- Order points so that p1.x < p2.x
    const bool order = inP1X < inP2X ;
    AWInt p1x = order ? inP1X : inP2X ;
    AWInt p1y = order ? inP1Y : inP2Y ;
    const AWInt p2x = order ? inP2X : inP1X ;
    const AWInt p2y = order ? inP2Y : inP1Y ;
    const AWInt dx = 2 * (p2x - p1x) ;
    const AWInt dy = 2 * (p2y - p1y) ;
    if (p1y < p2y) { // Ascending line
      if (dx >= dy) { // 0° < Slope <= 45°
        AWInt e = p2x - p1x ;
        while (p1x <= p2x) {
          AWRect::horizontalLine (p1x, p1y, 1).fillRectInRegion (inDrawRegion) ;
          p1x += 1 ;
          e -= dy ;
          if (e <= 0) {
            p1y += 1 ;
            e += dx ;
          }
        }
      } else {  // 45° < Slope < 90°
        AWInt e = p2y - p1y ;
        while (p1y <= p2y) {
          AWRect::horizontalLine (p1x, p1y, 1).fillRectInRegion (inDrawRegion) ;
          p1y += 1 ;
          e -= dx ;
          if (e <= 0) {
            p1x += 1 ;
            e += dy ;
          }
        }
      }
    } else { // Descending line (dx > 0, dy < 0)
      if (dx >= -dy) { // 0° > Slope >= - 45°
        AWInt e = p2x - p1x ;
        while (p1x <= p2x) {
          AWRect::horizontalLine (p1x, p1y, 1).fillRectInRegion (inDrawRegion) ;
          p1x += 1 ;
          e += dy ;
          if (e <= 0) {
            p1y -= 1 ;
            e += dx ;
          }
        }
      } else {  // -45° > Slope > - 90°
        AWInt e = p2y - p1y ;
        while (p1y >= p2y) {
          AWRect::horizontalLine (p1x, p1y, 1).fillRectInRegion (inDrawRegion) ;
          p1y -= 1 ;
          e -= dx ;
          if (e <= 0) {
            p1x += 1 ;
            e -= dy ;
          }
        }
      }
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWPoint::drawInRegion (const AWRegion & inDrawRegion) const {
  if (inDrawRegion.containsPoint (*this)) {
    AWContext::drawHLine (x, y, 1) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWPoint::drawPointInRegion (const AWInt inX, const AWInt inY, const AWRegion & inDrawRegion) {
  if (inDrawRegion.containsPoint (inX, inY)) {
    AWContext::drawHLine (inX, inY, 1) ;
  }

}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWPoint::frameCircleInRegion (const AWInt inRadius,
                                   const AWRegion & inDrawRegion) const {
  frameCircleInRegion (x, y, inRadius, inDrawRegion) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// https://fr.wikipedia.org/wiki/Algorithme_de_tracé_d%27arc_de_cercle_de_Bresenham

void AWPoint::frameCircleInRegion (const AWInt inCenterX,
                                   const AWInt inCenterY,
                                   const AWInt inRadius,
                                   const AWRegion & inDrawRegion) {
  if (inRadius > 0) {
    AWInt x = 0 ;
    AWInt y = inRadius ;
    AWInt m = 5 - 4 * inRadius ;
    while (x <= y) {
      AWPoint::drawPointInRegion (inCenterX + x, inCenterY + y, inDrawRegion) ;
      AWPoint::drawPointInRegion (inCenterX + x, inCenterY - y, inDrawRegion) ;
      AWPoint::drawPointInRegion (inCenterX - x, inCenterY - y, inDrawRegion) ;
      AWPoint::drawPointInRegion (inCenterX - x, inCenterY + y, inDrawRegion) ;
      AWPoint::drawPointInRegion (inCenterX + y, inCenterY + x, inDrawRegion) ;
      AWPoint::drawPointInRegion (inCenterX + y, inCenterY - x, inDrawRegion) ;
      AWPoint::drawPointInRegion (inCenterX - y, inCenterY - x, inDrawRegion) ;
      AWPoint::drawPointInRegion (inCenterX - y, inCenterY + x, inDrawRegion) ;
      if (m > 0) {
        y -= 1 ;
        m -= 8 * y ;
      }
      x += 1 ;
      m += 8 * x + 4 ;
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWPoint::fillCircleInRegion (const AWInt inRadius,
                                  const AWRegion & inDrawRegion) const {
  fillCircleInRegion (x, y, inRadius, inDrawRegion) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//#define CHECK_FILL_CIRCLE

#ifdef CHECK_FILL_CIRCLE
  #include <math.h>
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// https://fr.wikipedia.org/wiki/Algorithme_de_tracé_d%27arc_de_cercle_de_Bresenham

void AWPoint::fillCircleInRegion (const AWInt inCenterX,
                                  const AWInt inCenterY,
                                  const AWInt inRadius,
                                  const AWRegion & inDrawRegion) {
  if (inRadius > 0) {
    AWInt x = 0 ;
    AWInt y = inRadius ;
    AWInt m = 5 - 4 * inRadius ;
    while (x <= y) {
      AWRect::horizontalLine (inCenterX - y, inCenterY + x, 2 * y + 1).fillRectInRegion (inDrawRegion) ;
      AWRect::horizontalLine (inCenterX - y, inCenterY - x, 2 * y + 1).fillRectInRegion (inDrawRegion) ;
      if (m > 0) {
        AWRect::horizontalLine (inCenterX - x, inCenterY + y, 2 * x + 1).fillRectInRegion (inDrawRegion) ;
        AWRect::horizontalLine (inCenterX - x, inCenterY - y, 2 * x + 1).fillRectInRegion (inDrawRegion) ;
        y -= 1 ;
        m -= 8 * y ;
      }
      x += 1 ;
      m += 8 * x + 4 ;
    }
    #ifdef CHECK_FILL_CIRCLE
      const AWColor savedColor = AWContext::color () ;
      AWContext::setColor (AWColor::green ()) ;
      const float r = (float) inRadius ;
      for (int xx=0 ; xx<inRadius ; xx++) {
        const float x_div_r = ((float) xx) / r ;
        const float fy = r * sqrtf (1.0F - x_div_r * x_div_r) ;
        const int yy = (int) lrint (fy) ;
        AWPoint::drawPointInRegion (inCenterX + xx, inCenterY + yy, inDrawRegion) ;
      }
      for (int yy=0 ; yy<inRadius ; yy++) {
        const float y_div_r = ((float) yy) / r ;
        const int xx = (int) lrint (r * sqrtf (1.0F - y_div_r * y_div_r)) ;
        AWPoint::drawPointInRegion (inCenterX + xx, inCenterY + yy, inDrawRegion) ;
      }
      AWContext::setColor (savedColor) ;
    #endif
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
