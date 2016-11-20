//
//  animationManagement.hpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/21.
//
//

#ifndef animationManagement_hpp
#define animationManagement_hpp

#include "animationManagement.hpp"
#include "animation01.hpp"

class AnimationManagement {
   public:
    void setup(int index) {
        switch (index) {
            case 1:
                anime01.setup();
                break;
            case 2:
                break;
        }
    };
    
    void update(int index){
        switch(index){
            case 1:
                anime01.update();
                break;
        }
    }
    
    void draw(int index){
        switch(index){
            case 1:
                anime01.draw();
                break;
        }
    }

   private:
    Animation01 anime01;
};

#endif /* animationManagement_hpp */
