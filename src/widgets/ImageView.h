/*
 *  ImageView.h
 *  iPadJam2
 *
 *  Created by Andreas Borg on 14/04/2015
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __ofxInterface___ImageView
#define __ofxInterface___ImageView

#include "ofMain.h"
#include "ofxInterface.h"
#include "Widget.h"

namespace ofxInterface
{

class ImageView : public Widget, public ofImage{
	
  public:
	
    ImageView();
    ~ImageView();
    void setup();
	void draw();
    void loadImage(string str);
    
    
    virtual ofVec2f getSize();
    virtual void setSize(float w, float h);
    virtual void setSize(const ofVec2f& s);
    virtual float getWidth();
    virtual void setWidth(float w);
    virtual float getHeight() ;
    virtual void setHeight(float h);
};

};
#endif
