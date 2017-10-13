/*
 *  Button.cpp
 *  touchTable
 *
 *  Created by Andreas Borg on 01/04/2012
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

//ofInsidePoly(float x, float y, const vector<ofPoint> & poly);

#include "Button.h"
namespace ofxInterface {

Button::Button(){
    
    setup();
    
    /*****
     * register for touch events
     *
     * TouchManager will notify these automatically
     */
    ofAddListener(eventTouchDown, this, &Button::onTouchDown);
    ofAddListener(eventTouchUp, this, &Button::onTouchUp);
    ofAddListener(eventTouchMove, this, &Button::onTouchMove);

}
Button::~Button(){
    /*****
     * register for touch events
     *
     * TouchManager will notify these automatically
     */
    ofRemoveListener(eventTouchDown, this, &Button::onTouchDown);
    ofRemoveListener(eventTouchUp, this, &Button::onTouchUp);
    ofRemoveListener(eventTouchMove, this, &Button::onTouchMove);

}
//------------------------------------------------------------------
void Button::setup() {
    
    _images = 0;
    _isOn = false;
    _isOver = false;
    _isEnabled = true;
    setPosition(0, 0);
    setSize(100,100);
    _isToggable = false;
    setTint(ofColor(255));
    
    
}

void Button::setState(bool b){
    _isOn = b;
};

bool Button::isOn(){
    return _isOn;
};

bool Button::isOver(){
    return _isOver;
};

void Button::setEnabled(bool b){
    _isEnabled = b;
};

bool Button::isEnabled(){
    return _isEnabled;
};

void Button::setToggable(bool b){
    _isToggable = b;
};

bool Button::isToggable(){
    return _isToggable;
};

    

void Button::setImages(ButtonImages *_imgs){
    _images = _imgs;

};
ButtonImages* Button::getImages(){
    return _images;
};


//------------------------------------------------------------------
void Button::update() {

    

}

//------------------------------------------------------------------
void Button::draw() {

    
    if(isOver()){
        ofTranslate(2,2);
    }
    _beginDraw();
    
    if(isOver()){
        ofTranslate(-2,-2);
    }
    
    ofFill();
    
    bool onImgOK = 0;
    bool offImgOK = 0;
    bool overImgOK = 0;

    
    if(_images){
        if(_images->onImg.isAllocated()){
            onImgOK = 1;
        }
        if(_images->overImg.isAllocated()){
            overImgOK = 1;
        }
        if(_images->offImg.isAllocated()){
            offImgOK = 1;
        }
    }

    if(isOver()){
        
        if(isOn()){
            if(onImgOK){
                _images->onImg.draw(2,2,getWidth()-2,getHeight()-2);
            }else{
                
                if(_rectRadius > 0){
                    ofDrawRectRounded(2,2,getWidth()-2,getHeight()-2,_rectRadius);
                }else{
                    ofDrawRectangle(2,2,getWidth()-2,getHeight()-2);
                }
                
                //ofLog()<<"Button missing img: "<<_images->onImgStr<<endl;
            }
        }else{
            if(overImgOK){
                _images->overImg.draw(2,2,getWidth()-2,getHeight()-2);
            }else{
                
                
                if(_rectRadius > 0){
                    ofDrawRectRounded(2,2,getWidth()-2,getHeight()-2,_rectRadius);
                }else{
                    ofDrawRectangle(2,2,getWidth()-2,getHeight()-2);
                }
                //ofLog()<<"Button missing img: "<<_images->overImgStr<<endl;
            }
        }
    }else if(isOn()){
        if(onImgOK){
            _images->onImg.draw(0,0,getWidth(), getHeight());
        }else{
           
            
            
            if(_rectRadius > 0){
                ofDrawRectRounded(0,0,getWidth(),getHeight(),_rectRadius);
            }else{
                ofDrawRectangle(0,0,getWidth(),getHeight());
            }
            //ofLog()<<"Button missing img: "<<_images->onImgStr<<endl;
        }
        
    }else{
        if(offImgOK){
         _images->offImg.draw(0,0,getWidth(), getHeight());
        }else{
            
            
            if(_rectRadius > 0){
                ofDrawRectRounded(0,0,getWidth(),getHeight(),_rectRadius);
            }else{
                ofDrawRectangle(0,0,getWidth(),getHeight());
            }
            //ofLog()<<"Button missing img: "<<_images->offImgStr<<endl;
        }
    }
    
    
    
    _endDraw();
}



void Button::onTouchDown(ofxInterface::TouchEvent &event)
{
        /*****
     * event.position is always in global space, use toLocal
     */
    ofVec2f local = toLocal(event.position);
    //color = ofColor(255);
    _isOver = true;
    touchAnchor = local;
}
void Button::onTouchUp(ofxInterface::TouchEvent &event)
{
    //ofVec2f local = toLocal(event.position);
    //color = ofColor(100);
    _isOver = false;
}
void Button::onTouchMove(ofxInterface::TouchEvent &event)
{
    //creates drag
    //ofVec2f parentPos = ((Node*)parent)->toLocal(event.position);
    //setPosition(parentPos - touchAnchor);
}
    
}
