//
//  WidgetBase.h
//  iPadJam3
//
//  Created by Andreas Borg on 20/04/2015.
//
//

#ifndef __ofxInterface___Widget
#define __ofxInterface___Widget

#include "ofMain.h"
#include "ofxInterface.h"


namespace ofxInterface
{

class Widget : public Node{
        
    public:
        
    Widget(){
        _bgColor = ofColor(255,255,255,0);
        _strokeColor = ofColor(255);
        _tintColour = ofColor(255);
        _drawStroke = false;
        _drawBg = false;
        _strokeWidth = 1;
        _rectRadius = 0;
        
        setPosition(0, 0);
        setSize(100,100);
        
        _hitAreaMask = 0;
        
    };
    
    
    ~Widget(){};
        
    void setBackgroundColor(ofColor c){
        _bgColor = c;
    };
    
    ofColor getBackgroundColor(){
        return _bgColor;
    };
    
    void setDrawBackground(bool b){
        _drawBg = b;
    };
    
    bool getDrawBackground(){
        return _drawBg;
    }
    
    
    void setDrawStroke(bool b){
        _drawStroke = b;
    };
    
    bool getDrawStroke(){
        return _drawStroke;
    }
    
    void setStrokeColor(ofColor c){
        _strokeColor = c;
    };
    
    ofColor getStrokeColor(){
        return _strokeColor;
    };

    
    void setStrokeWidth(float f){
        _strokeWidth = f;
    }
    
    
    float getStrokeWidth(){
        return _strokeWidth;
    }
    

    void setTint(ofColor c){
        _tintColour = c;
    };
    
    ofColor getTint(){
        return _tintColour;
    };

    
    void setCornerRadius(float r){
        _rectRadius = r;
    
    };
    float getCornerRadius(){
        return _rectRadius;
    };
    
    virtual void draw(){
        _beginDraw();
        
        _endDraw();
    }
    
    
    void setHitArea(ofPolyline _p){
        _hitArea = _p;
        
    };
    
    ofPolyline getHitArea(){
        return _hitArea;
    };
    
    bool contains(const ofVec2f &globalPoint){
        
        if(_hitAreaMask){
            if(!_hitAreaMask->contains(globalPoint)){
                return false;
            };
        }
        
        ofVec2f local = toLocal(globalPoint);
        
        if(_hitArea.getVertices().size()>0){
            return ofInsidePoly( local.x , local.y, _hitArea.getVertices());
        }else if (local.x < 0 ||
                  local.y < 0 ||
                  local.x > size.x ||
                  local.y > size.y) {
            return false;
        }
        
        return true;
        
    }

    
    
    //primarily to prevent hits outside scroll area...but other masks may be added
    void setHitAreaMask(Widget *w){
        _hitAreaMask = w;
    }
    
    Widget * getHitAreaMask(){
        return _hitAreaMask;
    }
    
    
protected:
    
    void _beginDraw(){
        
        ofPushStyle();
        if(_drawBg){
            ofFill();
            ofSetColor(_bgColor);
            if(_rectRadius >0){
                ofDrawRectRounded(0,0,getWidth(),getHeight(),_rectRadius);
            }else{
                ofDrawRectangle(0,0,Node::getWidth(),Node::getHeight());
            }
            
        }
        
        if(_drawStroke){
            ofNoFill();
            ofSetLineWidth(_strokeWidth);
            ofSetColor(_strokeColor);
            if(_rectRadius >0){
                ofDrawRectRounded(0,0,getWidth(),getHeight(),_rectRadius);
            }else{
                ofDrawRectangle(0,0,Node::getWidth(),Node::getHeight());
            }
            
        }
        
        
        ofPopStyle();
        
        ofSetColor(_tintColour);
        
    }
    
    void _endDraw(){
    
    
    }
    
    float _rectRadius;
    ofColor _bgColor;
    ofColor _strokeColor;
    ofColor _tintColour;
    bool _drawBg;
    bool _drawStroke;
    
    float _strokeWidth;
    ofPolyline _hitArea;
    
    
    

    
    Widget * _hitAreaMask;//for widgets inside another view, ignore hits outside the _hitAreaMask
};
    
};
#endif
