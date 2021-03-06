#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    
    config = new DataReaderConfig();
    config->loadXml("xml/config.xml");
    sceneDuration = config->sceneDuration;
    int photoDuration = config->photoDuration;
    osc_send_enabled = config->osc_send_enabled;
    delete config;
    
//    int bufferSize = 512;
//    ofSoundStreamSetup(0, 1, this, 44100, bufferSize, 4);
//    audio.setup();

    ofBackground(50);
    fbo.allocate(1280, 720);
    myGlitch.setup(&fbo);

    displayCaption = false;
    scenes.setup();
    audio.setup();
    osc.setup();
    
    
    mainOutputSyphonServer.setName("Screen Output");
    
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
    
    vector<float> tmp_drawBuffer = audio.getDrawBuffer();
    vector<float> tmp_middle = audio.getMiddleBuffer();
    //cout << tmp_drawBuffer[0] << " : " << tmp_middle[0] << " : " << tmp_drawBuffer.size()<< endl;
    
    for(int i=0;i<tmp_drawBuffer.size();i++){
        ofSetColor(255);
//        ofDrawBitmapString(ofToString(tmp_drawBuffer[i]) + " : " + ofToString(tmp_middle[i]), 10, i * 10);
    }
    
    if(osc_send_enabled){
        osc.sendOscMessage("fps",0,ofGetFrameRate());
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    
    myGlitch.generateFx();
    ofSetColor(255);
    fbo.draw(0, 0);
    
    mainOutputSyphonServer.publishScreen();

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == 'z') {
        scenes.setMode(1);
        startTime = nowTime;
    } else if (key == 'x') {
        startTime = nowTime;
        scenes.setMode(2);
    } else if (key == 'c') {
        audio.setup();
    }else if(key == 'd'){
        if(scenes.drawCaption){
            scenes.drawCaption = false;
        }else {
            scenes.drawCaption = true;
        }
    }
    
    if(key == '1'){
        scenes.setAnimationIndex(1);
    }else if(key == '2'){
        scenes.setAnimationIndex(2);
    }else if(key == '3'){
        scenes.setAnimationIndex(3);
    }else if(key == '4'){
        scenes.setAnimationIndex(4);
    }else if(key == '0'){
        scenes.setAnimationIndex(0);
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
