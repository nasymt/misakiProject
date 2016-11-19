#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    
    config = new DataReaderConfig();
    config->loadXml("xml/config.xml");
    sceneDuration = config->sceneDuration;
    int photoDuration = config->photoDuration;
    delete config;
    mode = WEBCAM;
    
    int bufferSize = 512;
    ofSoundStreamSetup(0, 1, this, 44100, bufferSize, 4);
    audio.setup();

    ofBackground(50);

    photoScene.setup();
    displayCaption = false;
}

//--------------------------------------------------------------
void ofApp::setupMonitor() { ofBackground(50); }

//--------------------------------------------------------------
void ofApp::update() {
    nowTime = ofGetElapsedTimeMillis();
    currentSceneTime = nowTime - startTime;
    
    
    if (mode == PHOTO) {
        currentSceneTime = nowTime - startTime;
        photoScene.update();
    }else if(mode == WEBCAM){
    }else if(mode == ANIMATION){
//        audio.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (mode == PHOTO) {
        ofDrawBitmapString("1", 50, 50);
        photoScene.draw();
    } else if (mode == WEBCAM) {
        ofDrawBitmapString("2", 50, 50);
    } else if (mode == ANIMATION) {
        ofDrawBitmapString("3", 50, 50);
        audio.draw();
    }
    if(displayCaption){
        caption();
    }
}


void ofApp::caption(){
    ofPushMatrix();
    ofTranslate(50,50);
    ofSetColor(0,0,0);
    ofDrawRectangle(0,0,220,120);
    ofSetColor(255,255,255);
    ofDrawBitmapString("mode : " + ofToString(mode),10,20);
    ofDrawBitmapString("fps : "+ofToString(ofGetFrameRate()),10,100);
    ofDrawBitmapString("scenetime : " + ofToString(currentSceneTime) + " / " + ofToString(sceneDuration), 10, 40);
    int tmp =ofGetElapsedTimeMillis()-photoScene.nextTime - photoScene.photoDuration;
    ofDrawBitmapString("photoTime : " + ofToString(photoScene.sceneTime)+" / " + ofToString(photoScene.photoDuration),10,60);
    ofDrawBitmapString("photo : " + photoScene.photoPath,10,80);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::drawMonitor(ofEventArgs &args) {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == '1') {
        mode = PHOTO;
        startTime = nowTime;
    } else if (key == '2') {
        startTime = nowTime;
        mode = WEBCAM;
    } else if (key == '3') {
        mode = ANIMATION;
        startTime = nowTime;
        audio.setup();
    }else if(key == 'd'){
        if(displayCaption){
            displayCaption = false;
        }else {
            displayCaption = true;
        }
    }
    photoScene.keyEvent(key,true);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    photoScene.keyEvent(key,false);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}
