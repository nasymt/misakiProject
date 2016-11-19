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

    fbo.allocate(1280, 720);
    myGlitch.setup(&fbo);

    nextTime = photoDuration + ofGetElapsedTimeMillis();
    initTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void Scene_PhotoSlideShow::update() {
    
    int now = ofGetElapsedTimeMillis();
    sceneTime = now - initTime;

    fbo.begin();
    ofClear(0, 0, 0, 255);
    ofSetColor(255);
    img.draw(0, 0,1280,720);
    fbo.end();

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
    myGlitch.generateFx();
    ofSetColor(255);
    fbo.draw(0, 0);
}

//--------------------------------------------------------------
void Scene_PhotoSlideShow::keyEvent(int key, bool keyPressed) {
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