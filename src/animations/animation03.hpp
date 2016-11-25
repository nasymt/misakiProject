//
//  animation01.hpp
//  misakiProject
//
//  Created by ÊùæÂ≤°Ê≠£ on 2016/11/21.
//
//

#ifndef animation03_hpp
#define animation03_hpp

#include "ofMain.h"
#include "ofxPDF.h"

class Animation03 {
public:
    
    ofxPDF mPDF;
    vector<ofPolyline> polys;
    ofPath mPath;
    
    void setup(){
        mPDF.load("logo.pdf");
        
        
        mPath.setFilled(false);
        mPath.setStrokeWidth(2);
        mPath.setStrokeHexColor(5);
        for (int i = 0; i < mPDF.getNumPath(); i++){
            ofPath& path = mPDF.getPathAt(i);
            mPath.append(path);
        }
        mPath.close();
        
        
        for (int i = 0; i < mPDF.getNumPath(); i++){
            ofPath& path = mPDF.getPathAt(i);
            const vector<ofPolyline > &tmpPoly = path.getOutline();
            for (int k = 0; k < tmpPoly.size(); k++){
                polys.push_back(tmpPoly[k]);
            }
        }
        

    };
    
    void begin(){
        
    }
    
    void update(){
            }
    
    void draw(){
        
        ofSetColor(255, 255, 255);
        mPath.draw();
        drawAnimation();
    
    
    };
    
    void drawAnimation(){
        
        ofPolyline tmpPoly;
              //  ofSetColor(255, 255, 255);
       ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
        float animation_time = fmodf(ofGetElapsedTimef(), 0.45)*1 ;
        for (int k = 0; k < polys.size(); k++){
            tmpPoly = polys.at(k).getResampledByCount(100);
            int target_size = polys.size() * animation_time;
            tmpPoly.resize(target_size);
            tmpPoly.draw();
            
        }

        
    };
    
    
private:
 
    
};

#endif /* animation01_hpp */
