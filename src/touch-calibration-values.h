#ifndef CONVERT_TOUCH_POINT_TO_SCREEN_POINT_FUNCTION_DEFINED
#define CONVERT_TOUCH_POINT_TO_SCREEN_POINT_FUNCTION_DEFINED

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//   THIS FILE SHOULD NOT BE USED FOR MAC OS SIMULATOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#ifdef __APPLE__
  error "This file should not be used with the Cocoa Simulator"
#endif

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern const float xA ;
extern const float yA ;

extern const float xB ;
extern const float yB ;

extern const float xC ;
extern const float yC ;

extern const float xD ;
extern const float yD ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#endif
