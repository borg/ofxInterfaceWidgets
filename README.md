
**ofxInterfaceWidgets**  
Addon to the [ofxInterface](https://github.com/galsasson/ofxInterface) family.

[Core](https://github.com/galsasson/ofxInterface)  
[Keyboard](https://github.com/armadillu/ofxInterfaceKeyboard)

**Usage example**

```

void ofApp::setup(){
    Button * startBtn = new ofxInterface::Button();
    startBtn->setImages(new ButtonImages("assets/btn_begin.png"));
    startBtn->setSize(iconDim,iconDim);
    startBtn->setName("startBtn");
    startBtn->setPosition(sceneWidth/2-iconDim/2,sceneHeight-iconDim-80,0);
    startBtn->setPlane(3);
    ofAddListener(startBtn->eventTouchDown, this, &ofApp::nodeDown);
    ofAddListener(startBtn->eventTouchUp, this, & ofApp::nodeUp);
}    
  
    
    void ofApp::nodeDown(TouchEvent& event){
    	cout<<"ofApp::nodeDown "<< event.receiver->getName()<<endl;
   }
```

Created by Andreas Borg, 2017  
[crea.tion.to](http://crea.tion.to)
