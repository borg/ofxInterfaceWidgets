//
//  Slider.h
//  BeSpoke
//
//  Created by Andreas Borg on 7/27/15.
//
//

#ifndef __BeSpoke__Slider__
#define __BeSpoke__Slider__

#include "ofMain.h"
#include "ofxInterface.h"
#include "Widget.h"
#include "Button.h"
namespace ofxInterface
{


class Slider : public Widget{
    
  public:
  
  Slider();
  ~Slider();
  
    ofxInterface::Button* dragBtn;
    void setup();
    void draw();
    void setSize(float w, float h);
    bool _isVertical;
    bool _isDragging;
    
    void setValue(float v);
    float getValue();
    
    float _value;
    
    ofVec2f touchAnchor;
    ofVec2f orgPos;
    void onTouchDown(TouchEvent& event);
    void onTouchMove(TouchEvent& event);
    void onTouchUp(TouchEvent& event);
    
    ofEvent<ofEventArgs> eventOnChange;
};

}
#endif /* defined(__BeSpoke__Slider__) */
