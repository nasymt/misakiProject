//
//  sceneManagement.cpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/17.
//
//

#include "sceneManagement.hpp"

void SceneManagement::setup() {
    config = new DataReaderConfig();
    config->loadXml("xml/config.xml");
    sceneDuration = config->sceneDuration;
    delete config;
    animationIndex = -1;
    anime.setup(0);
    anime.setup(1);
}

void SceneManagement::update() {
    nowTime = ofGetElapsedTimeMillis();
    currentSceneTime = nowTime - startTime;
    
    if(currentSceneTime > sceneDuration){
        startTime = nowTime;
        if(mode == PHOTO){
            mode = WEBCAM;
        }else if(mode == WEBCAM){
            mode = PHOTO;
        }
    }
    
    if (mode == PHOTO) {
        photo.update();
    } else if (mode == WEBCAM) {
        webCam.update();
    }
    
    if(animationIndex >= 0){
        anime.update(animationIndex);
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
    
    if(animationIndex >= 0){
        anime.draw(animationIndex);
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

void SceneManagement::setAnimationIndex(int index){
    anime.begin(index);
    animationIndex = index;
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
    ofDrawRectangle(0, 0, 220, 140);
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("mode : " + ofToString(mode), 10, 20);
    ofDrawBitmapString("scenetime : " + ofToString(currentSceneTime) + " / " + ofToString(sceneDuration), 10, 40);
    ofDrawBitmapString("photoTime : " + ofToString(photo.sceneTime) + " / " + ofToString(photo.photoDuration), 10, 60);
    ofDrawBitmapString("photo : " + photo.photoPath, 10, 80);
    ofDrawBitmapString("animation index : " + ofToString(animationIndex) , 10 , 100);
    ofDrawBitmapString("fps : " + ofToString(ofGetFrameRate()), 10, 120);
    ofPopMatrix();
}

