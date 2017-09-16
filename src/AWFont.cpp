//
//  AWFont.cpp
//  graphic
//
//  Created by Pierre Molinaro on 06/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWFont.h"
#include "AWContext.h"
#include "AW-min-max.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <stdio.h>
#include <string.h>

///——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWFont::AWFont (const AWFontInternalDefinition & definition) :
mFont (& definition) {
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//--- UTF8 encoding
// 0000 0000  0000 0000  0xxx xxxx -> 0xxx xxxx
// 0000 0000  0000 0yyy  xxxx xxxx -> 110y yyxx  10xx xxxx
// 0000 0000  zzzz yyyy  xxxx xxxx -> 1110 zzzz  10yy yyxx  10xx xxxx
// 000u uuuu  zzzz yyyy  xxxx xxxx -> 1111 0uuu  10uu zzzz  10yy yyxx  10xx xxxx

static uint32_t getCodePoint (const char * inCString, AWInt & ioIndex, const AWInt inLength) {
  uint32_t result = 0 ;
  uint32_t c = (uint32_t) inCString [ioIndex] ;
  ioIndex ++ ;
  bool ok = true ;
  if ((c & 0x80) == 0) {
    result = c ;
  }else if ((c & 0xE0) == 0xC0) {
    result = c & 0x1F ;
    result <<= 6 ;
    c = (uint32_t) inCString [ioIndex] ;
    ok = ((c & 0xC0) == 0x80) && (ioIndex < inLength) ;
    if (ok) {
      ioIndex ++ ;
      result |= c & 0x3F ;
    }
  }else if ((c & 0xF0) == 0xE0) {
    result = c & 0x0F ;
    result <<= 12 ;
    c = (uint32_t) inCString [ioIndex] ;
    ok = ((c & 0xC0) == 0x80) && (ioIndex < inLength) ;
    if (ok) {
      ioIndex ++ ;
      result |= (c & 0x3F) << 6 ;
      c = (uint32_t)  inCString [ioIndex] ;
      if (ok) {
        ok &= ((c & 0xC0) == 0x80) && (ioIndex < inLength) ;
        ioIndex ++ ;
        result |= c & 0x3F ;
      }
    }
  }else if ((c & 0xF8) == 0xF0) {
    result = (c & 0x07) << 18 ;
    c = (uint32_t)  inCString [ioIndex] ;
    ok = ((c & 0xC0) == 0x80) && (ioIndex < inLength) ;
    if (ok) {
      ioIndex ++ ;
      result |= (c & 0x3F) << 12 ;
      c = (uint32_t) inCString [ioIndex] ;
      ok = ((c & 0xC0) == 0x80) && (ioIndex < inLength) ;
      if (ok) {
        ioIndex ++ ;
        result |= (c & 0x3F) << 6 ;
        c = (uint32_t) inCString [ioIndex] ;
        ok = ((c & 0xC0) == 0x80) && (ioIndex < inLength) ;
        if (ok) {
          ioIndex ++ ;
          result |= c & 0x3F ;
        }
      }
    }
  }else{
    ok = false ;
  }
  return ok ? result : 0 ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWFont::drawStringInRegion (const AWInt inX,
                                 const AWInt inY,
                                 const String & inString,
                                 const AWRegion & inDrawRegion) const {
  if (inString.length() > 0) {
    drawStringInRegion (inX, inY, inString.c_str (), inDrawRegion) ;
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWFont::drawStringInRegion (const AWInt inX,
                                 const AWInt inY,
                                 const char * inString,
                                 const AWRegion & inDrawRegion) const {
  if ((NULL != inString) && (NULL != mFont)) {
    const AWInt n = (AWInt) strlen (inString) ;
    AWInt ligne = inY + mFont->mAscent + 1 ;
    for (AWInt ligneAbs = 0 ; ligneAbs <= (mFont->mAscent - mFont->mDescent) ; ligneAbs++) {
      ligne -- ;
      AWInt x = inX ;
      AWInt stringIndex = 0 ;
      while (stringIndex <n) {
        const uint32_t code = getCodePoint (inString, stringIndex, n) ;
        const AWInt entry = descriptorIndexForCodePoint (code) ;
        if (entry >= 0) {
          const int advancement = (NULL == mFont->mAdvancementArray) ? mFont->mMaximumAdvancement : mFont->mAdvancementArray [entry] ;
          const int entreeBitMap = entry * (mFont->mAscent - mFont->mDescent + 1) + ligneAbs ;
          int adresseBitMap = (NULL == mFont->mBitMapEntryArray8)
            ? mFont->mBitMapEntryArray16 [entreeBitMap]
            : mFont->mBitMapEntryArray8 [entreeBitMap]
          ;
          AWInt colonneAbs = x + mFont->mEmptyLeftColumnCount ;
          bool loop = true ;
          while (loop) {
            const uint8_t v = mFont->mHorizontalSegmentArray [adresseBitMap] ;
            adresseBitMap ++ ;
            loop = (v & 1) != 0 ;
            const uint8_t blanckCount = v >> 4 ;
            colonneAbs += blanckCount ;
            const uint8_t pixelCount = (v >> 1) & 0x07 ;
            if (pixelCount > 0) {
              const AWRect r =  AWRect::horizontalLine (colonneAbs, ligne, pixelCount) ;
              r.fillRectInRegion (inDrawRegion) ;
              colonneAbs += pixelCount ;
            }
          }
          x += advancement ;
        }
      }
    }
  }
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWRect AWFont::stringRect (const AWInt inX,
                           const AWInt inY,
                           const char * inCString) const {
  AWInt width = 0 ;
  const AWInt n = (AWInt) strlen (inCString) ;
  AWInt stringIndex = 0 ;
  while (stringIndex <n) {
    const uint32_t code = getCodePoint (inCString, stringIndex, n) ;
    width += advancement (code) ;
  }
  return AWRect (
    AWPoint (inX, inY + descent ()),
    AWSize (width, lineHeight ())
  ) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWFont::descriptorIndexForCodePoint (const uint32_t inCodePoint) const {
  AWInt result = 0 ;
  bool found = false ;
  if (NULL != mFont) {
    for (int idx=0 ; (idx < mFont->mRangeCount) && !found ; idx++) {
      if ((mFont->mRangeArray [2*idx] <= inCodePoint) && (inCodePoint <= mFont->mRangeArray [2*idx+1])) {
        found = true ;
        result += inCodePoint - mFont->mRangeArray [2*idx] ;
      }else{
        result += mFont->mRangeArray [2*idx+1] - mFont->mRangeArray [2*idx] + 1 ;
      }
    }
  }
  return found ? result : -1 ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWFont::ascent (void) const {
  return (NULL == mFont) ? 0 : mFont->mAscent ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWFont::descent (void) const {
  return (NULL == mFont) ? 0 : mFont->mDescent ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWFont::lineHeight (void) const {
  return ascent () - descent () + 1 ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWFont::advancement (const uint32_t inCodePoint) const {
  const int entry = descriptorIndexForCodePoint (inCodePoint) ;
  AWInt result = 0 ;
  if (entry >= 0) {
    result = (NULL == mFont->mAdvancementArray) ? mFont->mMaximumAdvancement : mFont->mAdvancementArray [entry] ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWFont::stringLength (const String & inString) const {
  AWInt result = 0 ;
  if (inString.length() > 0) {
    result = stringLength (inString.c_str ()) ;
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWInt AWFont::stringLength (const char * inCString) const {
  AWInt result = 0 ;
  if (NULL != inCString) {
    const AWInt n = (AWInt) strlen (inCString) ;
    AWInt stringIndex = 0 ;
    while (stringIndex < n) {
      const uint32_t code = getCodePoint (inCString, stringIndex, n) ;
      result += advancement (code) ;
    }
  }
  return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
