//
//  AWColor.hpp
//  graphic
//
//  Created by Pierre Molinaro on 07/04/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifndef AWColor_DEFINED
#define AWColor_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <stdint.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class AWColor {
//--- Default constructor (clear color)
  public : inline AWColor (void) : mRed (0), mGreen (0), mBlue (0), mIsOpaque (false) {}

//--- Constructor (custom color)
  public : inline AWColor (const uint8_t inRed,
                           const uint8_t inGreen,
                           const uint8_t inBlue) :
  mRed (inRed),
  mGreen (inGreen),
  mBlue (inBlue),
  mIsOpaque (true) {
  }

//--- Colors
  public : inline static AWColor black (void) {
    return AWColor (0, 0, 0) ;
  }

  public : inline static AWColor gray (void) {
    return AWColor (128, 128, 128) ;
  }

  public : inline static AWColor darkGray (void) {
    return AWColor (64, 64, 64) ;
  }

  public : inline static AWColor lightGray (void) {
    return AWColor (192, 192, 192) ;
  }
  
  public : inline static AWColor veryLightGray (void) {
    return AWColor (224, 224, 224) ;
  }
  
  public : inline static AWColor red (void) {
    return AWColor (255, 0, 0) ;
  }

  public : inline static AWColor green (void) {
    return AWColor (0, 255, 0) ;
  }

  public : inline static AWColor blue (void) {
    return AWColor (0, 0, 255) ;
  }

  public : inline static AWColor white (void) {
    return AWColor (255, 255, 255) ;
  }

  public : inline static AWColor yellow (void) {
    return AWColor (255, 255, 0) ;
  }

  public : inline static AWColor orange (void) {
    return AWColor (255, 127, 0) ;
  }

  public : inline static AWColor brown (void) {
    return AWColor (153, 102, 51) ;
  }

  public : inline static AWColor cyan (void) {
    return AWColor (0, 255, 255) ;
  }

  public : inline static AWColor magenta (void) {
    return AWColor (255, 0, 255) ;
  }

  public : inline static AWColor purple (void) {
    return AWColor (127, 0, 127) ;
  }

  public : inline static AWColor deepSkyBlue (void) {
    return AWColor (0, 0xBF, 255) ;
  }

  public : inline static AWColor lightSkyBlue (void) {
    return AWColor (0x87, 0xCE, 0xFA) ;
  }

//--- Equatable
  public : bool operator == (const AWColor & inOtherColor) const ;
  public : inline bool operator != (const AWColor & inOtherColor) const {
    return !(*this == inOtherColor) ;
  }

//--- Accessors
  public : inline uint8_t redComponent (void) const { return mRed ; }
  public : inline uint8_t greenComponent (void) const { return mGreen ; }
  public : inline uint8_t blueComponent (void) const { return mBlue ; }
  public : inline bool isOpaque (void) const { return mIsOpaque ; }

//--- Properties
  private : uint8_t mRed ;
  private : uint8_t mGreen ;
  private : uint8_t mBlue ;
  private : bool mIsOpaque ;
} ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
