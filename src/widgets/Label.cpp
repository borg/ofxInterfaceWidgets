/*
 *  Label.cpp
 *  BeSpoke
 *
 *  Created by Andreas Borg on 8/11/15
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 */

#include "Label.h"
namespace ofxInterface {


Label::Label(){
    _text = "";
};
Label::~Label(){};


void Label::setText(string t){
    _text = t;
    setHeight(10);//hack to prevent mouse block on overlap over other components
};
string Label::getText(){
    return _text;
};

void Label::setInset(float x, float y){
    _x = x;
    _y = y;
};

void Label::setFontSize(float s){
    fontSize = s;
    font.setSize(fontSize);
};
    
bool Label::loadFont(string file){
    bool s = font.setup(file, 1.0, 1024, false, 8, 1.5);
    font.setCharacterSpacing(0);
    return s;
};

//------------------------------------------------------------------
void Label::setup() {
	
	
}


//------------------------------------------------------------------
void Label::update() {
	
	
}




//------------------------------------------------------------------
void Label::draw() {
	ofPushStyle();
    ofSetColor(_tintColour);
    if(font.isLoaded()){
        font.draw(_text,fontSize,_x,_y);
    }else{
       ofDrawBitmapString(_text,0,0);
    }
    ofPopStyle();
	
}



ofRectangle Label::getTextBox(){
    if(font.isLoaded()){
        font.setSize(fontSize);
        return font.getStringBoundingBox(_text, _x,_y);
    }else{
        return ofRectangle(0,0,0,0);//dunno
    }
}



}
