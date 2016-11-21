//
//  oscSenderReceiver.hpp
//  misakiProject
//
//  Created by 松岡正 on 2016/11/21.
//
//

#ifndef oscSenderReceiver_hpp
#define oscSenderReceiver_hpp

#include "ofMain.h"
#include "ofxOsc.h"
#include "dataReaderConfig.hpp"

class OscSenderReceiver {
   public:
    void setup() {
        config = new DataReaderConfig();
        config->loadXml("xml/config.xml");
        receiver_port = config->osc_receiver_port;
        sender_port = config->osc_sender_port;
        send_address = config->osc_send_address;
        delete config;

        receiver.setup(receiver_port);
        sender.setup(send_address, sender_port);
    }

    void update() {}

    void receiveOscMessage() {}

    void sendOscMessage(string setAddress , int iArg, float fArg) {
        if(setAddress == "fps"){
            ofxOscMessage m;
            m.setAddress("/misaki/fps");
            m.addFloatArg(fArg);
            sender.sendMessage(m,false);
        }
    }

   private:
    int receiver_port;
    int sender_port;
    string send_address;
    ofxOscReceiver receiver;
    ofxOscSender sender;
    DataReaderConfig *config;
};

#endif /* oscSenderReceiver_hpp */
