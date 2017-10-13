/*
 *  WidgetView.cpp
 *  AbletonLive
 *
 *  Created by Andreas Borg on 12/26/15
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 */

#include "WidgetView.h"
namespace ofxInterface {

WidgetView::WidgetView(){
  //setup();
    
    /*****
     * register for touch events
     *
     * TouchManager will notify these automatically
     */
    ofAddListener(eventTouchDown, this, &WidgetView::onTouchDown);
    ofAddListener(eventTouchUp, this, &WidgetView::onTouchUp);
    ofAddListener(eventTouchMove, this, &WidgetView::onTouchMove);
    
    tex = new TextureView();
    addChild(tex);

};
WidgetView::~WidgetView(){
    ofRemoveListener(eventTouchDown, this, &WidgetView::onTouchDown);
    ofRemoveListener(eventTouchUp, this, &WidgetView::onTouchUp);
    ofRemoveListener(eventTouchMove, this, &WidgetView::onTouchMove);

};


//------------------------------------------------------------------
void WidgetView::setup() {
	

}

void WidgetView::setSize(float w, float h) {
   Node::setSize(w, h);
   
   //cout<<"WidgetView::setSize "<<w<<endl;
   fboView.allocate(w,h);
   tex->setSize(w,h);
   resize(w,h);
}
void WidgetView::setSize(const ofVec2f& s) {
    Node::setSize(s);
    fboView.allocate(s.x,s.y);
    tex->setSize(s.x,s.y);
    
    resize(s.x,s.y);
}

//------------------------------------------------------------------
void WidgetView::update() {
	
	
}


//------------------------------------------------------------------
void WidgetView::draw() {
	
	
}

void WidgetView::beginDraw(){
    ofPushStyle();
    
    fboView.begin();
    ofClear(255,0);
    
   // ofFill();
	//ofSetColor(getBackgroundColor());
	//ofDrawRectangle(0,0, getWidth(),getHeight());
};

void WidgetView::endDraw(){
    
   
    fboView.end();
    
    tex->setTexture(&fboView.getTexture());
//    ofSetColor(255);
  //  fboView.draw(0,0,getWidth(),getHeight());
    
    ofPopStyle();
};


void WidgetView::onTouchDown(ofxInterface::TouchEvent &event)
{
        /*****
     * event.position is always in global space, use toLocal
     */
    ofVec2f local = toLocal(event.position);
    //color = ofColor(255);
    //_isOver = true;
    touchAnchor = local;
}
void WidgetView::onTouchUp(ofxInterface::TouchEvent &event)
{
    //ofVec2f local = toLocal(event.position);
    //color = ofColor(100);
    //_isOver = false;
}
void WidgetView::onTouchMove(ofxInterface::TouchEvent &event)
{
    //creates drag
    //ofVec2f parentPos = ((Node*)parent)->toLocal(event.position);
    //setPosition(parentPos - touchAnchor);
}
};