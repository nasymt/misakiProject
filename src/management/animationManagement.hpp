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
#include "animation00_example.hpp"

class AnimationManagement {
   public:
    void setup(int index) {
        switch (index) {
            case 1:
                anime01.setup();
                break;
            case 2:
                break;
            case 0:
                anime00.setup();
                
        }
    };
    
    void begin(int index){
        
    }
    
    
    void update(int index){
        switch(index){
            case 1:
                anime01.update();
                break;
            case 0:
                anime00.update();
        }
    }
    
    void draw(int index){
        switch(index){
            case 1:
                anime01.draw();
                break;
            case 0:
                anime00.draw();
        }
    }

   private:
    Animation01 anime01;
    Animation00_example anime00;
};

#endif /* animationManagement_hpp */
