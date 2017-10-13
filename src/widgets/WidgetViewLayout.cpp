/*
 *  WidgetViewLayout.cpp
 *  AbletonLive
 *
 *  Created by Andreas Borg on 12/26/15
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 */

#include "WidgetViewLayout.h"
namespace ofxInterface {

WidgetViewLayout::WidgetViewLayout(){
  //setup();
    
    /*****
     * register for touch events
     *
     * TouchManager will notify these automatically
     */
    ofAddListener(eventTouchDown, this, &WidgetViewLayout::onTouchDown);
    ofAddListener(eventTouchUp, this, &WidgetViewLayout::onTouchUp);
    ofAddListener(eventTouchMove, this, &WidgetViewLayout::onTouchMove);


};
WidgetViewLayout::~WidgetViewLayout(){
    ofRemoveListener(eventTouchDown, this, &WidgetViewLayout::onTouchDown);
    ofRemoveListener(eventTouchUp, this, &WidgetViewLayout::onTouchUp);
    ofRemoveListener(eventTouchMove, this, &WidgetViewLayout::onTouchMove);

};

//------------------------------------------------------------------
void WidgetViewLayout::setup() {
	
	
}


//------------------------------------------------------------------
void WidgetViewLayout::update() {
	
	
}


//------------------------------------------------------------------
void WidgetViewLayout::draw() {
	
	
}


WidgetView* WidgetViewLayout::getViewByName(string str){

};
void WidgetViewLayout::removeViewByName(string str){

};
void WidgetViewLayout::removeView(WidgetView* w){

};
void WidgetViewLayout::moveView(WidgetView*w, int toRow, int toCol){

};
void WidgetViewLayout::resizeView(WidgetView*w, float relWidth,float relHeight){

};

void WidgetViewLayout::addViewToRow(WidgetView* w,int row){
    addChild(w);
    
    views[row].push_back(w);
    float relW = 1/(float)views[row].size();
    float relH = 1/(float)views.size();
    
    ofVec2f relSize(ofVec2f(relW,relH));
    sizes[row].push_back(relSize);
    
    
    for(int i=0;i< sizes[row].size();i++){
        sizes[row][i] = relSize;
    }
    updateLayout();
};


void WidgetViewLayout::updateLayout(){
    float currX = 0,currY = 0;
    for(int r=0;r< views.size();r++){
        currX = 0;
        for(int c=0;c< views[r].size();c++){
            if(views[r][c] && sizes[r][c].x>0){
               views[r][c]->setSize(getWidth()*sizes[r][c].x, getHeight()*sizes[r][c].y);
               
               views[r][c]->setPosition(currX, currY);
               currX+=getWidth()*sizes[r][c].x;
            }
        }
        currY+=getHeight()*sizes[r][0].y;
        
    }

};




void WidgetViewLayout::onTouchDown(ofxInterface::TouchEvent &event)
{
        /*****
     * event.position is always in global space, use toLocal
     */
    ofVec2f local = toLocal(event.position);
    //color = ofColor(255);
    //_isOver = true;
    touchAnchor = local;
}
void WidgetViewLayout::onTouchUp(ofxInterface::TouchEvent &event)
{
    //ofVec2f local = toLocal(event.position);
    //color = ofColor(100);
    //_isOver = false;
}
void WidgetViewLayout::onTouchMove(ofxInterface::TouchEvent &event)
{
    //creates drag
    //ofVec2f parentPos = ((Node*)parent)->toLocal(event.position);
    //setPosition(parentPos - touchAnchor);
}
};
