//
//  audioAnalyze.hpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/15.
//
//

#ifndef audioAnalyze_hpp
#define audioAnalyze_hpp

#include "ofMain.h"
#include "ofxFft.h"

enum {SINE, MIC, NOISE};

class AudioAnalyze {
   public:
    void setup();
    void draw();
    void plot(vector<float>& buffer, float scale, float offset);
    void audioReceived(float* input, int bufferSize, int nChannels);
    void keyEvent(int key);

    
   private:
    ofxFft *fft;
    
    int spectrogramOffset;
    ofImage spectrogram;
    int mode;
    int plotHeight,bufferSize;
    
    int appWidth, appHeight;
    
    ofMutex soundMutex;
    vector<float> drawBins, middleBins, audioBins;
    vector<float> drawBuffer, middleBuffer, audioBuffer;
    
};

#endif /* audioAnalyze_hpp */
