#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"
#include "dataReaderConfig.hpp"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
    
    DataReaderConfig *config;
    config = new DataReaderConfig();
    config->loadXml("xml/config.xml");
    
    int windowSize_x = config->windowSize_x;
    int windowSize_y = config->windowSize_y;
    int windowPos_x = config->windowPos_x;
    int windowPos_y = config->windowPos_y;
    int subWindowSize_x = config->subWindowSize_x;
    int subWindowSize_y = config->subWindowSize_y;
    int subWindowPos_x = config->subWindowPos_x;
    int subWindowPos_y = config->subWindowPos_y;
    
    delete config;
        
/*    ofGLFWWindowSettings settings;
    settings.width = windowSize_x;
    settings.height = windowSize_y;
    settings.setPosition(ofVec2f(windowPos_x,windowPos_y));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    settings.width = subWindowSize_x;
    settings.height = subWindowSize_y;
    settings.setPosition(ofVec2f(subWindowSize_x,subWindowSize_y));
    settings.resizable = false;
    // uncomment next line to share main's OpenGL resources with gui
    //settings.shareContextWith = mainWindow;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    guiWindow->setVerticalSync(false);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp->setupMonitor();
    ofAddListener(guiWindow->events().draw,mainApp.get(),&ofApp::drawMonitor);
    
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();*/

}
