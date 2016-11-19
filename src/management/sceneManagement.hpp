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

class SceneManagement {
public:
    void setup();
    void update();
    void draw();
    
    void sceneChange();
    
    
   private:
    Scene_PhotoSlideShow photo;
    
    
};

#endif /* sceneManagement_hpp */
