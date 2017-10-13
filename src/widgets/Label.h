/*
 *  Label.h
 *  BeSpoke
 *
 *  Created by Andreas Borg on 8/11/15
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _Label
#define _Label

#include "ofMain.h"
#include "ofxInterface.h"
#include "Widget.h"
#include "ofxFontStash.h"

namespace ofxInterface
{

class Label: public Widget {
	
  public:
	
	Label();
	~Label();
	void setup();
	void update();
	void draw();
    
    void setText(string t);
    string getText();
    
    void setInset(float x, float y);
    float _x = 1;
    float _y = 1;
    void setFontSize(float s);
    float fontSize = 10;
    
    ofRectangle getTextBox();
    
    bool loadFont(string file);
    
    //TODO: Add pointer support to save font loads
    ofxFontStash font;
    
    private:
    
    string _text = "";
    
	
};
};
#endif
