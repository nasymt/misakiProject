//
//  animation00_example.hpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/21.
//
//

#ifndef animation00_example_hpp
#define animation00_example_hpp

#include "ofMain.h"
#include "ofxGui.h"



class Animation00_example {
public:
    
    void setup() {
        
        
        ofColor initColor = ofColor(0, 127, 255, 255);
        ofColor minColor = ofColor(0,0,0,0);
        ofColor maxColor = ofColor(255,255,255,255);
        
        
        ofSetFrameRate(60);
        gui.setup();
        gui.add(radius.setup("radius", 0, 10, 300));
        gui.add(color.setup("color", initColor, minColor, maxColor));

        
        
    };
    
    void update() {
        circleSize = abs(sin(ofGetElapsedTimef()*2) * 100);
    
        
       
              };
        
    
    
    void draw() {

        ofSetColor(color);
        ofSetLineWidth(2);
        ofSetCircleResolution(64);
        
        ofNoFill();
        ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, circleSize);
        ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, circleSize*2);
        ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, circleSize*3);
        //  ofFill();
        gui.draw();
        // for (int i=0; i <10; i++) {
        // ofDrawCircle(ofGetWidth()/2+i*40, 50+i*40, circleSize);
        // }
        //ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        
        for (int i = 0; i <5; i++) {
            ofColor(i*20, i*30, i*10);
            ofDrawRectangle(ofGetWidth()/2-240+i*30, 40*i, radius, radius);
            ofDrawRectangle(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), radius, radius);
            
        }
        
        
      //  ofRotateZ(angle);
        ofDrawCircle(ofGetWidth()/2 , ofGetHeight()/2, 20);
        
        
        
    };
    
private:
    ofxPanel gui;
    ofxFloatSlider radius;
    int circleSize;
    ofxColorSlider color;
    float angle;


    
    
};

#endif /* animation00_example_hpp */
