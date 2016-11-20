//
//  scene_webCam.cpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/17.
//
//

#include "scene_webCam.hpp"

void scene_webCam::setup(){
    camWidth = ofGetWidth();  // try to grab at this size.
    camHeight = ofGetHeight();
    
    //we can now get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(int i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.setup(camWidth, camHeight);
    
    videoInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
    videoTexture.allocate(videoInverted);
    ofSetVerticalSync(true);
    
    fbo.allocate(1280, 720);
    myGlitch.setup(&fbo);
    
    show = true;
    myGlitch.setup(&fbo);
}

void scene_webCam::update(){
    ofBackground(100, 100, 100);
    
    vidGrabber.update();
    fbo.begin();
    ofClear(0, 0, 0, 255);
    ofSetColor(255);
    vidGrabber.draw(0, 0);
    fbo.end();
}


void scene_webCam::draw(){
    if( show ) vidGrabber.draw(0, 0);
    myGlitch.generateFx();
    ofSetHexColor(255);
    fbo.draw(0, 0);
}




void scene_webCam::keyEvent(int key, bool keyPressed) {
    if (keyPressed) {
        
        if (key == 'q') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE, true);
        if (key == 'w') myGlitch.setFx(OFXPOSTGLITCH_GLOW, true);
        if (key == 'e') myGlitch.setFx(OFXPOSTGLITCH_SHAKER, true);
        if (key == 'r') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER, true);
        if (key == 't') myGlitch.setFx(OFXPOSTGLITCH_TWIST, true);
        if (key == 'y') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE, true);
        if (key == 'u') myGlitch.setFx(OFXPOSTGLITCH_NOISE, true);
        if (key == 'i') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN, true);
        if (key == 'o') myGlitch.setFx(OFXPOSTGLITCH_SWELL, true);
        if (key == 'p') myGlitch.setFx(OFXPOSTGLITCH_INVERT, true);
        
        if (key == 'a') myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
        if (key == 's') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE, true);
        if (key == 'd') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE, true);
        if (key == 'f') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE, true);
        if (key == 'g') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, true);
        if (key == 'h') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT, true);
        if (key == 'j') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT, true);
        
    } else {
        if (key == 'q') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE, false);
        if (key == 'w') myGlitch.setFx(OFXPOSTGLITCH_GLOW, false);
        if (key == 'e') myGlitch.setFx(OFXPOSTGLITCH_SHAKER, false);
        if (key == 'r') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER, false);
        if (key == 't') myGlitch.setFx(OFXPOSTGLITCH_TWIST, false);
        if (key == 'y') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE, false);
        if (key == 'u') myGlitch.setFx(OFXPOSTGLITCH_NOISE, false);
        if (key == 'i') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN, false);
        if (key == 'o') myGlitch.setFx(OFXPOSTGLITCH_SWELL, false);
        if (key == 'p') myGlitch.setFx(OFXPOSTGLITCH_INVERT, false);
        
        if (key == 'a') myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
        if (key == 's') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE, false);
        if (key == 'd') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE, false);
        if (key == 'f') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE, false);
        if (key == 'g') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, false);
        if (key == 'h') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT, false);
        if (key == 'j') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT, false);
    }
}
