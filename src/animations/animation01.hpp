//
//  animation01.hpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/21.
//
//

#ifndef animation01_hpp
#define animation01_hpp

#include "ofMain.h"
#include "fft.hpp"
#include "ofxGui.h"

class Animation01 {
   public:
    void setup(){
        fft = new Fft();
        fft->setup();
        gui.setup();
        gui.add(saturation.setup("Saturation", 127, 0, 255));
        gui.add(alpha.setup("Alpha", 127, 0, 255));
        gui.add(radiusMax.setup("Radius Max", 50, 0, 500));
    };
    
    void begin(){
        
    }
    
    void update(){
        fft->update();
    };
    
    void draw(){
        vector<float> buffer;
        buffer = fft->getBuffer();
        
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, 0);
        ofSetLineWidth(ofGetWidth() / float(buffer.size()) / 2.0);
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        ofSetCircleResolution(64);
        
        for (int i = 0; i < buffer.size(); i++) {
            float hue = ofMap(i, 0, buffer.size(), 0, 160);
            float br = ofMap(buffer[i]*2, 0, 1, 0, 255);
            float radius = ofMap(buffer[i], 0, 1, 0, radiusMax);
            ofColor col;
            col.setHsb(hue, saturation, br, alpha);
            ofSetColor(col);
            
            float rx = ofMap(i, 0, buffer.size()/5, 0, ofGetWidth() / 2.0);
            float lx = ofMap(i, 0, buffer.size()/5, 0, -ofGetWidth() / 2.0);
            
            for (int z = 0; z <50; z++) {
                ofDrawCircle(rx, z*200, radius);
                ofDrawCircle(lx, z*200, radius);
            }
        }
        ofPopMatrix();
        gui.draw();
    };

private:
    Fft *fft;
    ofxPanel gui;
    ofxFloatSlider alpha;
    ofxFloatSlider saturation;
    ofxFloatSlider radiusMax;

};

#endif /* animation01_hpp */
