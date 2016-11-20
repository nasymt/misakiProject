//
//  scene_webCam.cpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/17.
//
//

#include "scene_webCam.hpp"

void Scene_webCam::setup() {
    camWidth = ofGetWidth();  // try to grab at this size.
    camHeight = ofGetHeight();

    // we can now get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();

    for (int i = 0; i < devices.size(); i++) {
        if (devices[i].bAvailable) {
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        } else {
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }

    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.setup(camWidth, camHeight);

    videoInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
    videoTexture.allocate(videoInverted);
}

void Scene_webCam::update() {
    ofBackground(100, 100, 100);
    vidGrabber.update();
}

void Scene_webCam::draw() {
    ofSetColor(255);
    for (int i = 0; i < 4; i++) {
        vidGrabber.draw(ofGetWidth() / 4 * i, 0, ofGetWidth() / 4, ofGetHeight());
    }
}