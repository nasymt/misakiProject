//
//  scene_webCam.hpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/17.
//
//

#ifndef scene_webCam_hpp

//#ifndef INCLUDE_GUARD_HOGE_HPP
//#define INCLUDE_GUARD_HOGE_HPP
#include "ofxOpenCv.h"
#include "ofMain.h"
#include "ofxPostGlitch.h"

#define _USE_LIVE_VIDEO

class Scene_webCam {
   public:
    void setup();
    void update();
    void draw();
    void keyEvent(int key,bool keyPressed);
    
//    #ifdef _USE_LIVE_VIDEO
    
    ofVideoGrabber vidGrabber;
//    #else
//    #elseif
    
    ofPixels videoInverted;
    ofTexture videoTexture;
    
    int camWidth;
    int camHeight;
    bool show;
    
    
};

#endif /* scene_webCam_hpp */
