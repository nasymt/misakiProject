//
//  scene_PhotoSlideShow.cpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/16.
//
//

#include "scene_PhotoSlideShow.hpp"

void Scene_PhotoSlideShow::setup() {
    config = new DataReaderConfig();
    config->loadXml("xml/config.xml");
    photoDuration = config->photoDuration;
    photoTotalAmount = config->photoTotalAmount;
    photoWidth = config->photoWidth;
    photoHeight = config->photoHeight;
    delete config;

    photoIndex = 1;
    photoPath = ofToString(photoIndex) + ".jpg";
    img.load("photo/" + photoPath);

    nextTime = photoDuration + ofGetElapsedTimeMillis();
    initTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void Scene_PhotoSlideShow::update() {
    int now = ofGetElapsedTimeMillis();
    sceneTime = now - initTime;

    if (sceneTime > photoDuration) {
        if (photoIndex < photoTotalAmount) {
            photoIndex++;
        } else {
            photoIndex = 1;
        }
        photoPath = ofToString(photoIndex) + ".jpg";
        img.load("photo/" + photoPath);
        initTime = now;
    }
}

//--------------------------------------------------------------
void Scene_PhotoSlideShow::draw() {
    img.draw(ofGetWidth() / 2 - photoWidth / 2, ofGetHeight() / 2 - photoHeight / 2, photoWidth, photoHeight);
}

//--------------------------------------------------------------
void Scene_PhotoSlideShow::keyEvent(int key, bool keyPressed) {}