#include "supermary.hpp"

void Supermary::setup(){
    
    Pos1.set(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
    pos = Pos1;
    
    p1.set(ofRandom(-10,20), ofRandom(-31,0));
    p2.set(ofRandom(-10,20), ofRandom(31,0));
    p3.set(ofRandom(10,31), ofRandom(-10,20));
    
    c.r = ofRandom(20,255);
    c.g = ofRandom(20,255);
    c.b = ofRandom(20,255);
    
    newC = c;
}

void Supermary::update(float _mX, float _mY){
    
    ofVec2f mousePos;
    mousePos.set(_mX, _mY);
    
    ofVec2f diff;
    diff = mousePos - pos;
    
    //Rotate
    rot = atan2(diff.y,diff.x);
    rot = ofRadToDeg(rot);
    
    
    //Move
    float dist = sqrt(diff.x * diff.x + diff.y * diff.y);
    
    //move away
    if(dist <=100){
        
        ofVec2f newPos;
        newPos.set(pos.x+diff.x,pos.y+diff.y);
        
        pos = 0.95*pos + 0.05*newPos;
    }
    
    //move back
    else if(dist > 100){
        pos = 0.95*pos + 0.05*Pos1;
    }
    
    
}

void Supermary::draw(){
    
    float x1 = 0;
    float y1 = -10;
    
    float x2 = 0;
    float y2 = 20;
    
    float x3 = 31;
    float y3 = 0;
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(pos);
    ofRotate(rot);
    ofSetColor(newC);
    ofDrawTriangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    ofPopMatrix();
    ofPopStyle();
    
}
