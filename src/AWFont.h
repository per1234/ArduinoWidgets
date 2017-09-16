#ifndef FONT_CLASS_DEFINED
#define FONT_CLASS_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <stddef.h>
#include <stdint.h>
#include "WString.h"
#include "AWInt.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWContext ;
class AWRect ;
class AWRegion ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//                 FONT INTERNAL DESCRIPTION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWFontInternalDefinition {
  public : const AWInt mPointSize ;
  public : const AWInt mAscent ;
  public : const AWInt mDescent ;
  public : const AWInt mRangeCount ;
  public : const AWInt mMaximumAdvancement ;
  public : const AWInt mEmptyLeftColumnCount ;
  public : const AWInt mColumnCount ;
  public : const uint32_t * mRangeArray ;
  public : const uint8_t * mAdvancementArray ;
  public : const uint8_t * mHorizontalSegmentArray ;
  public : const uint8_t * mBitMapEntryArray8 ;
  public : const uint16_t * mBitMapEntryArray16 ;
  public : const char * mFontName ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//                 FONT CLASS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWFont {
//--- Default constructor: empty font
  public : AWFont (void) : mFont () {}

//--- Constructor from a font description
  public : AWFont (const AWFontInternalDefinition & definition) ;

  public : void drawStringInRegion (const AWInt inX,
                                    const AWInt inY,
                                    const char * inCString,
                                    const AWRegion & inDrawRegion) const ;

  public : void drawStringInRegion (const AWInt inX,
                                    const AWInt inY,
                                    const String & inString,
                                    const AWRegion & inDrawRegion) const ;

  public : AWInt ascent (void) const ;
  public : AWInt descent (void) const ;
  public : AWInt lineHeight (void) const ;

  public : AWInt advancement (const uint32_t inCodePoint) const ;

  public : AWRect stringRect (const AWInt inX,
                              const AWInt inY,
                              const char * inCString) const ;

  public : AWInt stringLength (const char * inCString) const ;
  public : AWInt stringLength (const String & inString) const ;


//--- Equatable
  public : inline bool operator == (const AWFont & inFont) const { return mFont == inFont.mFont ; }
  public : inline bool operator != (const AWFont & inFont) const { return !(*this == inFont) ; }

  protected : AWInt descriptorIndexForCodePoint (const uint32_t inCodePoint) const ;

//--- Property
  protected : const AWFontInternalDefinition * mFont ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
