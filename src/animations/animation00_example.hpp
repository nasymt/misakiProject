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
        

        for (int i = 0; i <NUM; i++) {
            loc_x[i] = ofRandom(0, ofGetWidth());
            loc_y[i] = ofRandom(0, ofGetHeight());
            speed_x[i] = ofRandom(-10, 10);
            speed_y[i] = ofRandom(-10, 10);
          }
        
    };
    
    void update() {
        circleSize = abs(sin(ofGetElapsedTimef()*2) * 100);
    
        
        for(int i = 0; i < NUM; i++){
            loc_x[i] = loc_x[i] + speed_x[i];
            loc_y[i] = loc_y[i] + speed_y[i];
            
           if(loc_x[i] < 0 ){
               speed_x[i] = speed_x[i] * -1;
            }
              if(loc_x[i] > ofGetWidth()) {
                  speed_x[i] = speed_x[i] * -1;
              }
              
              if(loc_y[i] < 0) {
                  speed_y[i] = speed_y[i] * -1;
              }
              if(loc_y[i] > ofGetHeight()) {
                  speed_y[i] = speed_y[i] * -1;
              }
                  
              }
              };
        
    
    
    void draw() {
        for(int i = 0; i < NUM; i++) {
        ofCircle(loc_x[i], loc_y[i], radius[i]);
        }
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
        
        
        ofRotateZ(angle);
        ofDrawCircle(ofGetWidth()/2 , ofGetHeight()/2, 20);
        
        
        
    };
    
private:
    ofxPanel gui;
    ofxFloatSlider radius;
    int circleSize;
    ofxColorSlider color;
    float angle;
    float loc_x;
    float loc_y;
    float speed_x;
    float speed_y;
    
    static const int NUM = 20;
    
    float loc_x1[NUM];
    float loc_y1[NUM];
    float speed_x1[NUM];
    float speed_y1[NUM];
    float radius[NUM];
    

    
    
};

#endif /* animation00_example_hpp */
