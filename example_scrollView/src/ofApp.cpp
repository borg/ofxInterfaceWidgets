#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(30);
    ofBackground(64);

    scene = new Node();
    scene->setSize(ofGetWidth(), ofGetHeight());
    scene->setName("Scene");

    TouchManager::one().setup(scene);

    //---

    // 1. IMAGE BUTTON:

    float iconDim = 30;
    float sceneWidth = 600;
    float sceneHeight = 10;
    
    Button * startBtn = new ofxInterface::Button();
    startBtn->setImages(new ButtonImages("images.jpg"));
    startBtn->setSize(iconDim,iconDim);
    startBtn->setName("startBtn");
    startBtn->setPosition(sceneWidth/2-iconDim/2,sceneHeight-iconDim-80,0);
    startBtn->setPlane(3);
    scene->addChild(startBtn);

    ofAddListener(startBtn->eventTouchDown, this, &ofApp::nodeDown);
    ofAddListener(startBtn->eventTouchUp, this, & ofApp::nodeUp);

    //---------------

    // 2. SCROLL VIEW:

    // create view canvas

//    ScrollView * scrollView_canvas = new ofxInterface::ScrollView();
    scrollView_canvas = new ofxInterface::ScrollView();
    scrollView_canvas->setSize(200, 500);
    scrollView_canvas->setName("scrollView_canvas");
    scrollView_canvas->setPosition(0, 0, 0);
    scrollView_canvas->setPlane(3);
//    scrollView_canvas->fitContentToWindow(OF_ASPECT_RATIO_IGNORE);
//    scrollView_canvas->setContentRect(ofRectangle(0, 0, 200, 500));
//    scrollView_canvas->setScale(0.5);
//    scrollView_canvas->setZoom(0.5);

    // add childrens
    for (int i=0; i<50; i++)
    {
        Button * startBtn = new ofxInterface::Button();
        startBtn->setImages(new ButtonImages("images.jpg"));
        startBtn->setSize(40,40);
        startBtn->setName("buttons"+ofToString(i));
        startBtn->setPosition(0, i * 42, 0);
        startBtn->setPlane(0);
        buttons.push_back(startBtn);
        scrollView_canvas->addChild(startBtn);
    }
    scene->addChild(scrollView_canvas);

    //------------
}

//--------------------------------------------------------------
void ofApp::nodeDown(TouchEvent& event){
    cout<<"ofApp::nodeDown "<< event.receiver->getName()<<endl;
}

//--------------------------------------------------------------
void ofApp::nodeUp(TouchEvent& event){
    cout<<"ofApp::nodeUp "<< event.receiver->getName()<<endl;
}

//--------------------------------------------------------------
void ofApp::update(){

    TouchManager::one().update();

    for (int i = 0; i < buttons.size(); i++)
    {
        buttons[i]->update();
    }

    float dt = 1. / 30.;
    scrollView_canvas->update(dt);

//    std::string n = ("scrollView_canvas");
//    auto a = scene->getChildWithName(n, scene->getNumChildren());
//    a->update(dt);

}

//--------------------------------------------------------------
void ofApp::draw(){

    scene->render();

//    std::string n = ("scrollView_canvas");
//    auto a = scene->getChildWithName(n, scene->getNumChildren());
//    a->draw();

    /******
     * if you want debug rendering
     */
    if (bDebug) {
        scene->renderDebug();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

if(key == 'd')
    bDebug = !bDebug;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    TouchManager::one().touchMove(button, ofVec2f(x, y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    TouchManager::one().touchDown(button, ofVec2f(x, y));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    TouchManager::one().touchUp(button, ofVec2f(x, y));
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
