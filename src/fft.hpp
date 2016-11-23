//
//  fft.hpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/22.
//
//

#ifndef fft_hpp
#define fft_hpp

#include "ofMain.h"
#include "ofxEasyFft.h"

class Fft {
   public:
    void setup() {
        easyFft = new ofxEasyFft();
        easyFft->setup(pow(2.0, 4.0));
    };

    void update() {
        easyFft->update();

        buffer = easyFft->getBins();
    };

    vector<float> getBuffer() { return buffer; };

   private:
    ofxEasyFft *easyFft;
    vector<float> buffer;
};

#endif /* fft_hpp */
