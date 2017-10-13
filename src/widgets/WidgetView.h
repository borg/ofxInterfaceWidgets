/*
 *  WidgetView.h
 *  AbletonLive
 *
 *  Created by Andreas Borg on 12/26/15
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _WidgetView
#define _WidgetView
#include "ofMain.h"
#include "ofxInterface.h"
#include "Widget.h"
#include "TextureView.h"


namespace ofxInterface
{

class WidgetView : public Widget{
	
  public:
	
	WidgetView();
	~WidgetView();
	virtual void setup();
	virtual void update();
	virtual void draw();
    void beginDraw();
    void endDraw();
    void onTouchDown(TouchEvent& event);
    void onTouchMove(TouchEvent& event);
    void onTouchUp(TouchEvent& event);
    ofVec2f touchAnchor;
    

    
    
    virtual void resize(float w, float h){};//override in components
    
    
    //kinda private
    void setSize(float w, float h);
    void setSize(const ofVec2f& s);
    
    
    private:
    TextureView * tex;
    ofFbo fboView;

};

};
#endif
