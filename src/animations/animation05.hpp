//
//  animation05.hpp
//  misakiProject
//
//  Created by 棚原 みずき on 2016/11/23.
//
//

#ifndef animation05_hpp
#define animation05_hpp

#include "ofMain.h"

class Animation05 {
public:
    void setup(){
        
        camWidth = 480;  // try to grab at this size.
        camHeight = 720;
        
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
        
        vidGrabber.initGrabber(camWidth, camHeight);
        
        videoInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
        videoTexture.allocate(videoInverted);
        ofSetVerticalSync(true);
        ofFbo fbo;
        ofTranslate(ofGetWidth()/2, ofGetHeight());
        vidGrabber.initGrabber(640, 480);
        fbo.allocate(320, 240, GL_RGB);
    };
    
    void update(){
        ofBackground(100, 100, 100);
        vidGrabber.update();
        
        if(vidGrabber.isFrameNew()){
            ofPixels & pixels = vidGrabber.getPixels();
            for(int i = 0; i < pixels.size(); i++){
                videoInverted[i] = 255 - pixels[i];
            }
            videoTexture.loadData(videoInverted);
        }
    };
    
    void draw(){
        ofSetHexColor(0xffffff);
        vidGrabber.setDesiredFrameRate(60);
        vidGrabber.draw(272, 0, 480, 360);
        //videoTexture.draw(480, 1020, 120, 300);
        vidGrabber.setDesiredFrameRate(60);
        vidGrabber.draw(272, 360, 480, 360);
        
        // videoTexture.draw(480, 1020, 0, 0);
        
        
        ofSetColor( 255, 255, 255 );
        vidGrabber.bind();
        //  vidGrabber.draw(ofRandom(ofGetWidth()/2), ofRandom(ofGetHeight()/2));
 };
    
private:
    
    ofVideoGrabber vidGrabber;
    ofPixels videoInverted;
    ofTexture videoTexture;
    int camWidth;
    int camHeight;

 
};




#endif /* animation05_hpp */
