/*
 *  TextureView.h
 *  
 *
 *  Created by Andreas Borg on 14/04/2015
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _TextureView
#define _TextureView

#include "ofMain.h"
#include "ofxInterface.h"
#include "Widget.h"

namespace ofxInterface
{

class TextureView : public Widget{
	
  public:
	
    TextureView();
    TextureView(ofTexture * t);
    ~TextureView();
    void setup();
	void draw();
    void setTexture(ofTexture * t);
    ofTexture * getTexture();
    
    virtual ofVec2f getSize();
    virtual void setSize(float w, float h);
    virtual void setSize(const ofVec2f& s);
    virtual float getWidth();
    virtual void setWidth(float w);
    virtual float getHeight();
    virtual void setHeight(float h);
    
protected:
    ofTexture * _tex;
};

};
#endif
