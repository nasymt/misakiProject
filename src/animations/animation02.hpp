//
//  animation01.hpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/21.
//
//

#ifndef animation02_hpp
#define animation02_hpp

#include "ofMain.h"
#include "ofxEasyFft.h"
#include "ofxGui.h"

class Animation02 {
public:
    void setup(){
        fft = new ofxEasyFft();
        fft->setup(pow(2.0, 10.0));
        gui.setup();
        gui.add(saturation.setup("Saturation", 127, 0, 255));
        gui.add(alpha.setup("Alpha", 127, 0, 255));
        gui.add(radiusMax.setup("Radius Max", 50, 0, 500));
    };
    
    void update(){
        fft->update();
    };
    
    void draw(){
        vector<float> buffer;
        buffer = fft->getBins();
       
      //  ofTranslate(ofGetWidth()/2, 0);

        
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        ofSetCircleResolution(64);
        
        for (int i = 0; i < buffer.size(); i++) {
            float hue = ofMap(i, 0, buffer.size(), 0, 160);
            float br = ofMap(buffer[i]*2, 0, 1, 0, 255);
           // float radius = ofMap(buffer[i], 0, 1, 0, radiusMax);
            ofColor col;
            col.setHsb(hue, saturation, br, 30);
            ofSetColor(col);
            
            //float rx = ofMap(i, 0, buffer.size()/5, 0, ofGetWidth() / 2.0);
            //float lx = ofMap(i, 0, buffer.size()/5, 0, -ofGetWidth() / 2.0);
          ofRectangle(0,0, ofGetWidth(), ofGetHeight());
          
        }
        
        gui.draw();
    };
    
private:
    ofxEasyFft *fft;
    ofxPanel gui;
    ofxFloatSlider alpha;
    ofxFloatSlider saturation;
    ofxFloatSlider radiusMax;
    
};

#endif /* animation02_hpp */
