/*
 *  WidgetViewLayout.h
 *  Basic Liquid layout
 *
 *  Created by Andreas Borg on 12/26/15
 *  Copyright 2015 Elevated Digital LLC. All rights reserved.
 *
 */

#ifndef _WidgetViewLayout
#define _WidgetViewLayout

#include "ofMain.h"
#include "ofxInterface.h"
#include "Widget.h"
#include "WidgetView.h"
namespace ofxInterface
{

class WidgetViewLayout: public Widget {
	
  public:
	
	WidgetViewLayout();
    ~WidgetViewLayout();
	
	void setup();
	void update();
	void draw();
    
    WidgetView* getViewByName(string str);
    void removeViewByName(string str);
    void removeView(WidgetView* w);
    void moveView(WidgetView*w, int toRow, int toCol);
    void resizeView(WidgetView*w, float relWidth,float relHeight);
    
    void addViewToRow(WidgetView* w,int row = 0);
    
    map<int, vector<WidgetView*> > views;
    map<int, vector<ofVec2f> > sizes;
	
    void updateLayout();
    
    void onTouchDown(TouchEvent& event);
    void onTouchMove(TouchEvent& event);
    void onTouchUp(TouchEvent& event);
    ofVec2f touchAnchor;
};

};
#endif
