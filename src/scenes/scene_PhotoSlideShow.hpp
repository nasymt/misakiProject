//
//  scene_PhotoSlideShow.hpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/16.
//
//

#ifndef scene_PhotoSlideShow_hpp
#define scene_PhotoSlideShow_hpp

#include "ofMain.h"
#include "dataReaderConfig.hpp"
#include "ofxPostGlitch.h"

class Scene_PhotoSlideShow {
   public:
    void setup();
    void update();
    void draw();
    
    void keyEvent(int key,bool keyPressed);

    string photoPath;
    int photoTotal;
    int photoDuration;
    int photoIndex;
    int photoTotalAmount;
    int nextTime;
    int initTime;
    int sceneTime;
    int photoWidth,photoHeight;

    
   private:
    DataReaderConfig *config;
    

    ofImage img;
    ofFbo fbo;
    ofxPostGlitch myGlitch;
    ofTexture texture;
    
    
};

#endif /* scene_PhotoSlideShow_hpp */
