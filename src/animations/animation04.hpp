//
//  animation01.hpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/21.
//
//

#ifndef animation04_hpp
#define animation04_hpp

#include "ofMain.h"
#include "Particle.h"
#include "ofxEasyFft.h"

class Animation04 {
    
public:
    void setup(){
        ofSetFrameRate(60);
        ofBackground(63);
        ofSetCircleResolution(4);
        ofSetBackgroundAuto(true); //フレーム更新時に塗り潰しを無効化
        
    };
    
    void update(){
        for (int i = 0; i < particles.size(); i++){
            particles[i].update();
        }
    };
    
    void resetForce(){
        
    }
    
    void draw(){
        ofSetColor(255);
        
        // 塗りつぶしなし
        ofNoFill();
        
        // パーティクルを曲線で結ぶ
        ofBeginShape();
        for (int i = 0; i < particles.size(); i++) {
            ofCurveVertex(particles[i].position.x, particles[i].position.y);
        }
        ofEndShape();
        
        if ( particles.size() > 200 ) {
            //  ofSetColor(0, 0, 0, 30); //半透明の黒（背景色）
            
        }
        
        // ログを表示
        ofDrawBitmapString("Particle num = " + ofToString(particles.size()), 10, 20);

        int x = ofRandom(ofGetWidth());
        int y = ofRandom(ofGetHeight());
        
        
        Particle p;
        // 摩擦係数を設定
        p.friction = 0.01;
        // 重力を設定
        p.gravity.set(0, 0);
        // 初期位置を設定
        p.setInit(ofVec2f(x, y));
        // 初期速度を設定
        float length = ofRandom(3);
        float angle = ofRandom(PI * 2);
        p.velocity.x = cos(angle) * length;
        p.velocity.y = sin(angle) * length;
        // Vectorに追加
        particles.push_back(p);
    };
    
    
   // void mousePressed(){
   //     particles.clear();
   // };
    



private:
    ofxEasyFft *fft;
  //  ofxPanel gui;
  //  ofxFloatSlider alpha;
  //  ofxFloatSlider saturation;
  //  ofxFloatSlider radiusMax;
    
    vector<Particle> particles;
    
};

#endif /* animation04_hpp */
