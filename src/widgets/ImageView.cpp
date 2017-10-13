/*
 *  ImageView.cpp
 *  iPadJam2
 *
 *  Created by Andreas Borg on 14/04/2015
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 */

#include "ImageView.h"

namespace ofxInterface
{

ImageView::ImageView(){
    setup();
}
    
ImageView::~ImageView(){
}
    
    
    
void ImageView::setup(){
    setName("ImageView");
    setSize(100,100);
};
    
void ImageView::draw() {
    _beginDraw();
    
    
    if(isAllocated()){
        ofImage::draw(0,0,Node::getWidth(),Node::getHeight());
    }
    
    _endDraw();
}

    
void ImageView::loadImage(string str){
    setName(str);
    ofImage::load(str);
    setSize(ofImage::getWidth(), ofImage::getHeight());
};
    
ofVec2f ImageView::getSize() {
    return Node::getSize();
}
void ImageView::setSize(float w, float h) {
   Node::setSize(w, h);
}
void ImageView::setSize(const ofVec2f& s) {
    Node::setSize(s);
}
float ImageView::getWidth() {
    return Node::getWidth();
}
void ImageView::setWidth(float w) {
    Node::setWidth(w);
}
float ImageView::getHeight() {
    return Node::getHeight();
}
void ImageView::setHeight(float h) {
    Node::setHeight(h);
}
    
    
}
