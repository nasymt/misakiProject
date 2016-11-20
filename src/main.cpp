#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"
#include "dataReaderConfig.hpp"

//========================================================================
int main( ){
    DataReaderConfig *config;
    config = new DataReaderConfig();
    config->loadXml("xml/config.xml");
    
    int windowSize_x = config->windowSize_x;
    int windowSize_y = config->windowSize_y;
    delete config;

    
	ofSetupOpenGL(windowSize_x,windowSize_y,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
