//
//  animation07.hpp
//  misakiProject
//
//  Created by 棚原 みずき on 2016/11/23.
//
//

#ifndef animation07_hpp
#define animation07_hpp

#include "ofMain.h"
#include "ofxEasyFft.h"
#include "ofxGui.h"
#include "Particle.h"


class Animation07 {
public:
//--------------------------------------------------------------
void setup(){
    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(63);
    ofSetCircleResolution(4);
    
    //画面の更新をOFFに
    ofSetBackgroundAuto(true);
    ofBackground(0, 0, 0); //背景色を黒に設定
    
    // メッシュを点で描画
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
   // ofColor initColor = ofColor(0,127,255,255);
   // ofColor minColor = ofColor(0,0,0,0);
   // ofColor maxColor = ofColor(255,255,255,255);
  //  gui.add(color.setup("color", initColor, minColor, maxColor));
    
    
};

//--------------------------------------------------------------
void update(){
    //fft.update();
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].update();
    }
};

//--------------------------------------------------------------
void draw(){
    
    mesh.clear();
    for (int i = 0; i < particles.size(); i++) {
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y, 0));
    }
    mesh.draw();
    
  //  vector<float> buffer;
  //  buffer = fft->getBins();
  //  ofDrawBitmapString("fps = " + ofToString(ofGetFrameRate()), 10, 20);
  //  ofDrawBitmapString("Particle num = " + ofToString(particles.size()), 10, 40);
    
    //  ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    //for (int i = 0; i < buffer.size(); i++) {
    // float hue = ofMap(i, 0, buffer.size(), 0, 160);
    //float br = ofMap(buffer[i]*2, 0, 1, 0, 255);
    // float radius = ofMap(buffer[i], 0, 1, 0, radiusMax);
    
    ofSetColor(color);
    
    //     ofSetColor(255);
    
    int x = ofRandom(ofGetWidth());
    int y = ofRandom(ofGetHeight());
    for (int i = 0; i < 400; i++) {
        Particle p;
        // 摩擦係数を設定
        p.friction = 0.001;
        // 初期速度を設定
        ofVec2f velocity;
        float length = ofRandom(1);
        float angle = ofRandom(PI * 2);
        velocity.x = cos(angle) * length;
        velocity.y = sin(angle) * length;
        // パーティクル初期設定
      //  p.setup(ofVec2f(x, y), velocity);
        // Vectorに追加
        particles.push_back(p);
    }
    
    
    gui.draw();
    // }
    
};
    /*
    void keyPressed(int key){
        if (key == 'f') {
            ofToggleFullscreen();
        }
        if (key == 'c') {
            particles.clear();
        }
     */

//--------------------------------------------------------------


private:

vector<Particle> particles;
ofxEasyFft *fft;
ofxPanel gui;
ofxFloatSlider alpha;
ofxFloatSlider saturation;
ofxColorSlider color;
ofVboMesh mesh;
//ofxFloatSlider radiusMax;
    
};




#endif /* animation07_hpp */
