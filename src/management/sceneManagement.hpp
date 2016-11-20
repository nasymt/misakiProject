//
//  sceneManagement.hpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/17.
//
//

#ifndef sceneManagement_hpp
#define sceneManagement_hpp

#include "sceneManagement.hpp"
#include "scene_PhotoSlideShow.hpp"
#include "scene_webCam.hpp"

enum E_MODE {PHOTO, WEBCAM};

class SceneManagement {
   public:
    void setup();
    void update();
    void draw();
    void caption();
    
    void setMode(int index);
    void sceneChange();
    void keyEvent(int key);
    int getMode();

    int sceneDuration;
    int currentSceneTime,nowTime,startTime;
    bool drawCaption;


    
   private:
    Scene_PhotoSlideShow photo;
    Scene_webCam webCam;
    E_MODE mode;

};

#endif /* sceneManagement_hpp */
