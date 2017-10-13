/*
 *  ScrollView.h
 *  InterfaceComponents
 *
 *  Created by Andreas Borg on 15/04/2015
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _ScrollView
#define _ScrollView

#include "ofMain.h"
#include "ofxInterface.h"
#include "Widget.h"

namespace ofxInterface
{
    

class ScrollViewTouchPoint {
public:
    ScrollViewTouchPoint() {
        touchID = 0;
        touchDownTimeInSec = 0;
    }
    int touchID;
    ofVec2f touchPos;
    float touchDownTimeInSec;
};


    
    
    
class ScrollView : public Widget{
	
  public:
	
	ScrollView();
	~ScrollView();

    
    void setUserInteraction(bool bEnable);
    void setPinchZoom(bool bEnable);
    void setScrollEasing(float value);
    void setBounceBack(float value);
    void setDragVelocityDecay(float value);
    void setDoubleTapZoom(bool bEnable);
    void setDoubleTapZoomRangeMin(float value);
    void setDoubleTapZoomRangeMax(float value);
    void setDoubleTapZoomIncrement(float value);
    void setDoubleTapZoomIncrementTimeInSec(float value);
    void setDoubleTapRegistrationTimeInSec(float value);
    void setDoubleTapRegistrationDistanceInPixels(float value);
    
    virtual void setup();
    virtual void reset();
    
    //void setWindowRect(const ofRectangle & rect);//replaced by setSize
    void setContentRect(const ofRectangle & rect);
    
    void fitContentToWindow(ofAspectRatioMode aspectRatioMode);
    
    
    
    void setScale(float value);
    void setScaleMin(float value);
    void setScaleMax(float value);
    
    float getScale();
    float getScaleMin();
    float getScaleMax();
    
    void setZoom(float value);
    float getZoom();
    bool isZoomed();
    bool isZoomedInMax();
    bool isZoomedOutMax();
    
    float zoomToScale(float value);
    float scaleToZoom(float value);
    
    void zoomToMin(const ofVec2f & screenPoint, float timeSec=0.0);
    void zoomToMax(const ofVec2f & screenPoint, float timeSec=0.0);
    void zoomTo(const ofVec2f & screenPoint, float zoom, float timeSec=0.0);
    void zoomToContentPointAndPositionAtScreenPoint(const ofVec2f & contentPoint,
                                                    const ofVec2f & screenPoint,
                                                    float zoom,
                                                    float timeSec=0.0);
    void moveContentPointToScreenPoint(const ofVec2f & contentPoint,
                                       const ofVec2f & screenPoint,
                                       float timeSec=0.0);
    bool animStart(float animTimeInSec);
    
    void setScrollPositionX(float x, bool bEase=true);
    void setScrollPositionY(float y, bool bEase=true);
    void setScrollPosition(float x, float y, bool bEase=true);
    
    ofVec2f getScrollPosition();
    ofVec2f getScrollPositionNorm();
    
    const ofRectangle & getWindowRect();
    const ofRectangle & getContentRect();
    const ofRectangle & getScrollRect();
    const ofMatrix4x4 & getMatrix();
    
    virtual void update(float dt=1/60.0f);
    
    //-------------------------------------------------------------- the brains!
    ofRectangle getRectContainedInWindowRect(const ofRectangle & rect,
                                             float easing=1.0);
    
    ofRectangle getRectZoomedAtScreenPoint(const ofRectangle & rect,
                                           const ofVec2f & screenPoint,
                                           float zoom=0.0);
    
    ofRectangle getRectWithContentPointAtScreenPoint(const ofRectangle & rect,
                                                     const ofVec2f & contentPoint,
                                                     const ofVec2f & screenPoint);
    
    ofRectangle getRectLerp(const ofRectangle & rectFrom,
                            const ofRectangle & rectTo,
                            float progress);
    
    ofMatrix4x4 getMatrixForRect(const ofRectangle & rect);
    
    ofVec2f getContentPointAtScreenPoint(const ofRectangle & rect,
                                         const ofVec2f & screenPoint);
    
    ofVec2f getScreenPointAtContentPoint(const ofRectangle & rect,
                                         const ofVec2f & contentPoint);
    
    //--------------------------------------------------------------
    virtual void begin();
    virtual void end();
    virtual void draw();
    
    virtual void exit();
    
    virtual void dragDown(const ofVec2f & point);
    virtual void dragMoved(const ofVec2f & point);
    virtual void dragUp(const ofVec2f & point);
    virtual void dragCancel();
    
    virtual void zoomDown(const ofVec2f & point, float pointDist);
    virtual void zoomMoved(const ofVec2f & point, float pointDist);
    virtual void zoomUp(const ofVec2f & point, float pointDist);
    virtual void zoomCancel();
    
    ofRectangle windowRect;
    ofRectangle contentRect;
    
    bool bUserInteractionEnabled;
    bool bPinchZoomEnabled;
    bool bPinchZoomSupported;
    
    ofRectangle scrollRect;
    ofRectangle scrollRectEased;
    ofRectangle scrollRectAnim0;
    ofRectangle scrollRectAnim1;
    float scrollEasing;
    float bounceBack;
    
    ofVec2f dragDownPos;
    ofVec2f dragMovePos;
    ofVec2f dragMovePosPrev;
    ofVec2f dragVel;
    float dragVelDecay;
    bool bDragging;
    
    ofVec2f zoomDownPos;
    ofVec2f zoomMovePos;
    ofVec2f zoomMovePosPrev;
    float zoomDownDist;
    float zoomMoveDist;
    bool bZooming;
    
    float animTimeStart;
    float animTimeTotal;
    bool bAnimating;
    
    bool bDoubleTapZoomEnabled;
    float doubleTapZoomRangeMin;
    float doubleTapZoomRangeMax;
    float doubleTapZoomIncrement;
    float doubleTapZoomIncrementTimeInSec;
    float doubleTapRegistrationTimeInSec;
    float doubleTapRegistrationDistanceInPixels;
    
    float scale;
    float scaleDown;
    float scaleMin;
    float scaleMax;
    ofMatrix4x4 mat;
    
    

    
    
    
    vector<ScrollViewTouchPoint> touchPoints;
    ScrollViewTouchPoint touchDownPointLast;
    
    //----------------------------------------------------------
    virtual void mouseMoved(ofMouseEventArgs & mouse){
        mouseMoved(mouse.x,mouse.y);
    }
    virtual void mouseDragged(ofMouseEventArgs & mouse){
        mouseDragged(mouse.x,mouse.y,mouse.button);
    }
    virtual void mousePressed(ofMouseEventArgs & mouse){
        mousePressed(mouse.x,mouse.y,mouse.button);
    }
    virtual void mouseReleased(ofMouseEventArgs & mouse){
        mouseReleased(mouse.x,mouse.y,mouse.button);
    }
    
    virtual void mouseMoved(int x, int y);
    virtual void mouseDragged(int x, int y, int button);
    virtual void mousePressed(int x, int y, int button);
    virtual void mouseReleased(int x, int y, int button);
    
    //----------------------------------------------------------
    virtual void touchDown(ofTouchEventArgs &touch) {
        touchDown(touch.x, touch.y, touch.id);
    }
    virtual void touchMoved(ofTouchEventArgs &touch) {
        touchMoved(touch.x, touch.y, touch.id);
    }
    virtual void touchUp(ofTouchEventArgs &touch) {
        touchUp(touch.x, touch.y, touch.id);
    }
    virtual void touchDoubleTap(ofTouchEventArgs &touch) {
        touchDoubleTap(touch.x, touch.y, touch.id);
    }
    virtual void touchCancelled(ofTouchEventArgs &touch) {
        touchCancelled(touch.x, touch.y, touch.id);
    }
    
    virtual void touchDown(int x, int y, int id);
    virtual void touchMoved(int x, int y, int id);
    virtual void touchUp(int x, int y, int id);
    virtual void touchDoubleTap(int x, int y, int id);
    virtual void touchCancelled(int x, int y, int id);
    
    
    
    
    
    
    //borg extensions

    bool _horisontalScrollEnabled;
    void setHorisontalScrollEnabled(bool b){
        _horisontalScrollEnabled = b;
    }
    bool getHorisontalScrollEnabled(){
        return _horisontalScrollEnabled;
    }
    
    
    bool _verticalScrollEnabled;
    void setVerticalScrollEnabled(bool b){
        _verticalScrollEnabled = b;
    }
    bool getVerticalScrollEnabled(){
        return _verticalScrollEnabled;
    }
   
    virtual void setSize(float w, float h);
    virtual void setSize(const ofVec2f& s);
    
    virtual void setWidth(float w);
    virtual void setHeight(float h);
    
    virtual void setContentSize(float w, float h);
    virtual void setContentSize(const ofVec2f& s);
    
    virtual float getContentWidth();
    virtual float getContentHeight();
     /*
    virtual void setPosition(float x=0, float y=0, float z=0);
    virtual void setPosition(const ofVec3f& p);
    */
    void onTouchDown(TouchEvent& event);
    void onTouchMove(TouchEvent& event);
    void onTouchUp(TouchEvent& event);
    
    /*
     For nesting, nest inside the node itself
     autoResize will take the size of the node itself,
     however a container node doesn't currently adapt to child sizes
     */
    void setContent(Node* node, bool autoResize = true);
    
    Node* getContent(){
        return _contentChildNode;
    }
    
    
protected:
    Node* _contentNode;
    Node* _contentChildNode;
    ofFbo _canvas;
    
    ofAspectRatioMode _aspectRatioMode;
	
};
};
#endif
