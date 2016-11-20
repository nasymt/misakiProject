#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    
    config = new DataReaderConfig();
    config->loadXml("xml/config.xml");
    sceneDuration = config->sceneDuration;
    int photoDuration = config->photoDuration;
    delete config;
    
    int bufferSize = 512;
    ofSoundStreamSetup(0, 1, this, 44100, bufferSize, 4);
    audio.setup();

    ofBackground(50);
    fbo.allocate(1280, 720);
    myGlitch.setup(&fbo);

//    photoScene.setup();
    displayCaption = false;
}


//--------------------------------------------------------------
void ofApp::update() {
    nowTime = ofGetElapsedTimeMillis();
    currentSceneTime = nowTime - startTime;
    scenes.update();
    
    fbo.begin();
    ofClear(0, 0, 0, 255);
    ofSetColor(255);
    scenes.draw();
    fbo.end();

}

//--------------------------------------------------------------
void ofApp::draw() {
    
    myGlitch.generateFx();
    ofSetColor(255);
    fbo.draw(0, 0);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == '1') {
        scenes.setMode(1);
        startTime = nowTime;
    } else if (key == '2') {
        startTime = nowTime;
        scenes.setMode(2);
    } else if (key == '3') {
        startTime = nowTime;
        audio.setup();
    }else if(key == 'd'){
        if(scenes.drawCaption){
            scenes.drawCaption = false;
        }else {
            scenes.drawCaption = true;
        }
    }
    
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
    //if (key == 'd') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE, true);
    if (key == 'f') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE, true);
    if (key == 'g') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, true);
    if (key == 'h') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT, true);
    if (key == 'j') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT, true);
    
    photoScene.keyEvent(key,true);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    photoScene.keyEvent(key,false);
    
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
    //if (key == 'd') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE, false);
    if (key == 'f') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE, false);
    if (key == 'g') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, false);
    if (key == 'h') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT, false);
    if (key == 'j') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT, false);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}
