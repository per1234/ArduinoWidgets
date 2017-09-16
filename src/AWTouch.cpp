//
//  AW-settings.cpp
//  graphic
//
//  Created by Pierre Molinaro on 21/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWTouch.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AWTouch::AWTouch (const byte inCLK,
                  const byte inCS,
                  const byte inDIN,
                  const byte inDOUT,
                  const byte inIRQ) :
mCLK (inCLK),
mCS (inCS),
mDIN (inDIN),
mDOUT (inDOUT),
mIRQ (inIRQ) {
  pinMode (mCLK, OUTPUT) ;
  pinMode (mCS,  OUTPUT) ;
  pinMode (mDIN, OUTPUT) ;
  pinMode (mDOUT, INPUT_PULLUP) ;
  pinMode (mIRQ, INPUT_PULLUP) ;
  digitalWrite (mCLK, LOW) ;
  digitalWrite (mCS,  HIGH) ;
  digitalWrite (mDIN, LOW) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

uint16_t AWTouch::readRegister (const byte inRegister) const {
//--- Write register
	byte data = inRegister ;
	for (unsigned n=0; n<8; n++) {
    delayMicroseconds (1) ;
    digitalWrite (mDIN, (data & 0x80) != 0) ;
		data <<= 1 ;
    delayMicroseconds (1) ;
		digitalWrite (mCLK, HIGH) ;
    delayMicroseconds (1) ;
    digitalWrite (mCLK, LOW) ;
	}
 //--- Din SHOULD be low during reading
  delayMicroseconds (1) ;
  digitalWrite (mDIN, LOW) ;
//--- Read register value
	uint16_t result = 0 ;
	for (unsigned n=0 ; n<12 ; n++) {
		result <<= 1 ;
    delayMicroseconds (1) ;
		digitalWrite (mCLK, HIGH);
    delayMicroseconds (1) ;
		digitalWrite (mCLK, LOW);
    delayMicroseconds (1) ;
		if (digitalRead (mDOUT)) {
			result += 1 ;
    }
	}
 //---
	return result ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool AWTouch::dataAvailable (void) const {
	return !digitalRead (mIRQ) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void AWTouch::read (uint16_t & outX, uint16_t & outY) const {
//--- Select chip
  digitalWrite (mCS, LOW) ; // CLOCK is low
//--- Read registers
  outX = readRegister (0x90) ;
  outY = readRegister (0xD0) ;
//--- Unselect chip
	digitalWrite (mCS, HIGH) ; // CLOCK is low
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
