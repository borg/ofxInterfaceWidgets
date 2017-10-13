//
//  Slider.cpp
//  BeSpoke
//
//  Created by Andreas Borg on 7/27/15.
//
//

#include "Slider.h"
namespace ofxInterface {

Slider::Slider(){

    int iconDim = 10;
    //imgs = new ButtonImages("icons/endSelection");
    dragBtn = new ofxInterface::Button();
    //dragBtn->setImages(imgs);
    dragBtn->setSize(iconDim,iconDim);
    dragBtn->setName("startSelectBtn");
    dragBtn->setPosition(0,0,0);
    dragBtn->setPlane(1);
    ofAddListener(dragBtn->eventTouchDown, this, &Slider::onTouchDown);
    ofAddListener(dragBtn->eventTouchUp, this, &Slider::onTouchUp);
    ofAddListener(dragBtn->eventTouchMove, this, &Slider::onTouchMove);
    this->addChild(dragBtn);



    setup();
    
    

}

Slider::~Slider(){
    ofRemoveListener(dragBtn->eventTouchDown, this, &Slider::onTouchDown);
    ofRemoveListener(dragBtn->eventTouchUp, this, &Slider::onTouchUp);
    ofRemoveListener(dragBtn->eventTouchMove, this, &Slider::onTouchMove);

};

void Slider::setup(){
    _isVertical = true;
    _isDragging = false;
    _value = 0;
};


void Slider::setSize(float w, float h){
    Widget::setSize(w,h);
    
    _isVertical = (h>w);
    
    if(_isVertical){
        dragBtn->setSize(w,10);
    }else{
        dragBtn->setSize(10,h);
    }
    
    setValue(_value);
};



void Slider::draw(){

    ofSetColor(255,255,255,50);
    ofFill();
    ofRect(0,0,getWidth(),getHeight());

}


void Slider::onTouchDown(ofxInterface::TouchEvent &event)
{
        /*****
     * event.position is always in global space, use toLocal
     */
    ofVec2f parentPos = ((Node*)parent)->toLocal(event.position);
    orgPos = dragBtn->getPosition();
    
    
    _isDragging = true;
    touchAnchor = parentPos;
}

void Slider::onTouchUp(ofxInterface::TouchEvent &event)
{
    _isDragging = false;
}


void Slider::onTouchMove(ofxInterface::TouchEvent &event)
{

    if(_isDragging){
        //creates drag
        ofVec2f currPos = ((Node*)parent)->toLocal(event.position);
        
        if(_isVertical){
            float diffY = currPos.y - touchAnchor.y;
            float finY = MAX(orgPos.y+diffY,0);
            finY = MIN(finY,getHeight()-dragBtn->getHeight());
            dragBtn->setPosition(orgPos.x,finY);
            
            _value = finY/(float)(getHeight()-dragBtn->getHeight());
        }else{
            float diffX = currPos.x - touchAnchor.x;
            float finX = MAX(orgPos.x+diffX,0);
            finX = MIN(finX,getWidth()-dragBtn->getWidth());
            dragBtn->setPosition(finX,orgPos.y);
            _value = finX/(float)(getWidth()-dragBtn->getWidth());
        }
        
        
        ofEventArgs e;
        ofNotifyEvent(eventOnChange,e);
    }
  
}
void Slider::setValue(float v){
    _value = v;
    if(_isVertical){
        float finY = _value * (getHeight()-dragBtn->getHeight());
        dragBtn->setPosition(dragBtn->getX(),finY);
    }else{
        float finX = _value * (getWidth()-dragBtn->getWidth());
        dragBtn->setPosition(finX,dragBtn->getY());
    }
    
    
};

float Slider::getValue(){
    return _value;

};

};