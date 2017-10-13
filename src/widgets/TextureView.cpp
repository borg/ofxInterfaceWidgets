/*
 *  TextureView.cpp
 *  iPadJam2
 *
 *  Created by Andreas Borg on 14/04/2015
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 */

#include "TextureView.h"

namespace ofxInterface
{

TextureView::TextureView(){
    _tex = 0;
    setup();
}
TextureView::TextureView(ofTexture *t){
    _tex = t;
    setup();
    setSize(_tex->getWidth(),_tex->getHeight());
};
    
TextureView::~TextureView(){
}
    
    
    
void TextureView::setup(){
    setName("TextureView");
    setSize(100,100);
};
    
void TextureView::draw() {
    _beginDraw();
    
    
    if(_tex){
        _tex->draw(0,0,getWidth(),getHeight());
    }
    
    
    _endDraw();
}


void TextureView::setTexture(ofTexture * t){
    _tex = t;
    setSize(_tex->getWidth(),_tex->getHeight());
};
ofTexture * TextureView::getTexture(){
    return _tex;
};
    
ofVec2f TextureView::getSize() {
    return Node::getSize();
}
void TextureView::setSize(float w, float h) {
   Node::setSize(w, h);
}
void TextureView::setSize(const ofVec2f& s) {
    Node::setSize(s);
}
float TextureView::getWidth() {
    return Node::getWidth();
}
void TextureView::setWidth(float w) {
    Node::setWidth(w);
}
float TextureView::getHeight() {
    return Node::getHeight();
}
void TextureView::setHeight(float h) {
    Node::setHeight(h);
}
    
    
}
