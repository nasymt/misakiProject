#pragma once

#include "ofMain.h"
#include "audioAnalyze.hpp"
#include "scene_PhotoSlideShow.hpp"
#include "dataReaderConfig.hpp"


enum E_MODE { PHOTO, WEBCAM, ANIMATION };

class ofApp : public ofBaseApp {
   public:
    void setup();
    void setupMonitor();
    void update();
    void draw();
    void drawMonitor(ofEventArgs& args);
    void caption();

    //    void plot(vector<float>& buffer, float scale, float offset);
    //    void audioReceived(float* input, int bufferSize, int nChannels);

    void keyPressed(int key);
    void keyReleased(int key);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

    int sceneDuration;
    int currentSceneTime,nowTime,startTime;

    AudioAnalyze audio;
    E_MODE mode;
    DataReaderConfig *config;
    
    Scene_PhotoSlideShow photoScene;
    
    bool displayCaption;
    

    

};
