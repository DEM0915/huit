#include "ofApp.h"

void ofApp::setup(){
    
    ofBackground(0);
    ofHideCursor();
    
    for(int i=0; i<200; i++){
        
        Supermary _mary;
        _mary.setup();
        supermarys.push_back(_mary);
    }
    
    amount = 1;
    
    for(int y = 0; y < amount; y++){
        
        car newcar;
        newcar.setup(ofRandom(300,600),
                     ofRandom(ofGetHeight()-100,
                              ofGetHeight()-300),40);
        
        cars.push_back(newcar);
    }

}

void ofApp::update(){
    
    for(int i=0; i<supermarys.size(); i++){
        
        supermarys[i].update(ofGetMouseX(),ofGetMouseY());
    }
    
    
    for(int h = 0; h < cars.size(); h++){
        
        cars[h].OUTscreen();
        cars[h].move(start);
    }

}


void ofApp::draw(){
    
    
    for(int i=0; i<supermarys.size(); i++){
        
        supermarys[i].draw();
    }
    
    for(int h = 0; h < cars.size(); h++){
        cars[h].display();
    }

}


void ofApp::keyPressed(int key){
    
    start = key;
}

void ofApp::keyReleased(int key){
    
    start = 0;
}
