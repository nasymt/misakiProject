//
//  dataReaderConfig.hpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/14.
//
//

#ifndef dataReaderConfig_hpp
#define dataReaderConfig_hpp

#include "ofMain.h"
#include "ofxXmlSettings.h"

class DataReaderConfig {
   public:
    void loadXml(string path) {
        xml = new ofxXmlSettings();
        xml->load(path);

        xml->pushTag("config");
        osc_receive_enabled = xml->getValue("osc_receive_enabled",0);
        osc_send_enabled = xml->getValue("osc_send_enabled",0);
        osc_receiver_port = xml->getValue("osc_receiver_port",0);
        osc_sender_port = xml->getValue("osc_sender_port",0);
        osc_send_address = xml->getValue("osc_send_address","");
        
        sceneDuration = xml->getValue("sceneDuration", 0);
        windowSize_x = xml->getValue("mainWindowSettings:windowSize_x", 0);
        windowSize_y = xml->getValue("mainWindowSettings:windowSize_y", 0);
        windowPos_x = xml->getValue("mainWindowSettings:position_x", 0);
        windowPos_y = xml->getValue("mainWindowSettings:position_y", 0);

        subWindowSize_x = xml->getValue("subWindowSettings:windowSize_x", 0);
        subWindowSize_y = xml->getValue("subWindowSettings:windowSize_y", 0);
        subWindowPos_x = xml->getValue("subWindowSettings:position_x", 0);
        subWindowPos_y = xml->getValue("subWindowSettings:position_y", 0);

        photoTotalAmount = xml->getValue("photoTotalAmount", 0);
        photoDuration = xml->getValue("photoDuration",0);
        photoWidth = xml->getValue("photoWidth",0);
        photoHeight = xml->getValue("photoHeight", 0);

        xml->popTag();

        delete xml;
    };

    int osc_receiver_port,osc_sender_port;
    string osc_send_address;
    
    
    bool osc_receive_enabled,osc_send_enabled;
    
    int sceneDuration;
    int windowSize_x, windowSize_y, windowPos_x, windowPos_y;
    int subWindowSize_x, subWindowSize_y, subWindowPos_x, subWindowPos_y;
    int photoTotalAmount;
    int photoDuration;
    int photoWidth,photoHeight;

   private:
    ofxXmlSettings *xml;
};

#endif /* dataReaderConfig_hpp */
