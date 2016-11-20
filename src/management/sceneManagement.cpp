//
//  sceneManagement.cpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/17.
//
//

#include "sceneManagement.hpp"

void SceneManagement::setup() {}

void SceneManagement::update() {
    nowTime = ofGetElapsedTimeMillis();
    currentSceneTime = nowTime - startTime;

    if (mode == PHOTO) {
        photo.update();
    } else if (mode == WEBCAM) {
        webCam.update();
    }
}

void SceneManagement::draw() {
    if (mode == PHOTO) {
        photo.draw();
    }else if(mode == WEBCAM){
        webCam.draw();
    }

    if (drawCaption) {
        caption();
    }
}

void SceneManagement::setMode(int index) {
    if (index == 1) {
        mode = PHOTO;
        photo.setup();
    } else if (index == 2) {
        mode = WEBCAM;
        webCam.setup();
    }
}

int SceneManagement::getMode() {
    int index;
    if (mode == PHOTO) {
        index = 1;
    } else if (mode == WEBCAM) {
        index = 2;
    }

    return index;
}

void SceneManagement::caption() {
    ofPushMatrix();
    ofTranslate(50, 50);
    ofSetColor(0, 0, 0);
    ofDrawRectangle(0, 0, 220, 120);
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("mode : " + ofToString(mode), 10, 20);
    ofDrawBitmapString("fps : " + ofToString(ofGetFrameRate()), 10, 100);
    ofDrawBitmapString("scenetime : " + ofToString(currentSceneTime) + " / " + ofToString(sceneDuration), 10, 40);
    ofDrawBitmapString("photoTime : " + ofToString(photo.sceneTime) + " / " + ofToString(photo.photoDuration), 10, 60);
    ofDrawBitmapString("photo : " + photo.photoPath, 10, 80);
    ofPopMatrix();
}