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
    delete config;

    photoIndex = 1;
    photoPath = ofToString(photoIndex) + ".jpg";
    img.load("photo/" + photoPath);

    //    fbo.allocate(1280, 720);
    //    myGlitch.setup(&fbo);

    nextTime = photoDuration + ofGetElapsedTimeMillis();
    initTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void Scene_PhotoSlideShow::update() {
    int now = ofGetElapsedTimeMillis();
    sceneTime = now - initTime;

    //    fbo.begin();
    //    ofClear(0, 0, 0, 255);
    //    ofSetColor(255);
    //    img.draw(0, 0,1280,720);
    //    fbo.end();

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
    img.draw(0, 0, 1280, 720);
    //    myGlitch.generateFx();
    //    ofSetColor(255);
    //    fbo.draw(0, 0);
}

//--------------------------------------------------------------
void Scene_PhotoSlideShow::keyEvent(int key, bool keyPressed) {
}