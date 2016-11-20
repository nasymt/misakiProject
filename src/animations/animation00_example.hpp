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

class Animation00_example {
   public:
    void setup() { circleSize = 0; };

    void update() { circleSize = abs(sin(ofGetElapsedTimef()*2) * 100); };

    void draw() {
        ofSetColor(255);
        ofSetLineWidth(2);
        ofSetCircleResolution(64);
        ofNoFill();
        ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, circleSize);
        ofFill();
    };

   private:
    int circleSize;
};

#endif /* animation00_example_hpp */
