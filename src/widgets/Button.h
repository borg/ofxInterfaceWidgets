/*
 *  Button.h
 *  touchTable
 *
 *  Created by Andreas Borg on 01/04/2012
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __ofxInterface___Button
#define __ofxInterface___Button

#include "ofMain.h"
#include "ofxInterface.h"
#include "Widget.h"

namespace ofxInterface
{


class ButtonImages{
    public :
    ButtonImages(string file){
        
        
    
        offImgStr = file+"_.png";
        overImgStr = file+"_over.png";
        onImgStr = file+"_on.png";
        
        if(!ofFile::doesFileExist(offImgStr) && ofFile::doesFileExist(file)){
            offImgStr = file;
            overImgStr = file;
            onImgStr =file;
        }
        
        offImg.load(offImgStr);
        overImg.load(overImgStr);
        //downImg.loadImage(file+"down");
        onImg.load(onImgStr);
    }
    ofImage offImg;
    ofImage overImg;
    //ofImage downImg;
    ofImage onImg;
    
    string offImgStr;
    string overImgStr;
    string onImgStr;
    
    
    void setImages(string off,string over="", string on=""){
        
        
        offImgStr = off;
        
        if(over ==""){
            overImgStr = off;
        }else{
            overImgStr = over;
        }
        
        if(on ==""){
            onImgStr = off;
        }else{
            onImgStr = on;
        }

        offImg.load(offImgStr);
        overImg.load(overImgStr);
        //downImg.loadImage(file+"down");
        onImg.load(onImgStr);
    }
    
};

class Button : public Widget{

  public:

	Button();
    ~Button();

	void setup();
	void update();
	void draw();


    
    //bool isActive;

    
    void setImages(ButtonImages *_imgs);
    ButtonImages * getImages();
    
    
    //on or off
    void setState(bool b);
    bool isOn();
    bool isOver();
    void setEnabled(bool b);
    bool isEnabled();
    
    void setToggable(bool b);
    bool isToggable();
    


    
    ofImage shadow;

    string action;
    
    
    void onTouchDown(TouchEvent& event);
    void onTouchMove(TouchEvent& event);
    void onTouchUp(TouchEvent& event);
    
    ofVec2f touchAnchor;


    
protected:
    bool _isOver;
    bool _isOn;
    bool _isEnabled;
    bool _isToggable;
    
   
    ButtonImages *_images;
   
};
};
#endif
