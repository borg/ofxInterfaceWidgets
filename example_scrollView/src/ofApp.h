#pragma once

#include "ofMain.h"
#include "ofxInterface.h"
#include "ofxInterfaceWidgets.h"
#include "ofxInterfaceKeyboard.h"
#include "ButtonExample.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    void nodeDown(TouchEvent& event);
    void nodeUp(TouchEvent& event);
    
    void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    ofxInterface::Node* scene;

    ScrollView * scrollView_canvas;
    vector<Button*> buttons;

    bool bDebug = true;
    
};
