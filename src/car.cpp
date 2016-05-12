#include "car.hpp"

void car::setup(float Location_x,float Location_y, int radius_){
    
    Location.set(Location_x,Location_y);
    radius = radius_;
    Velocity.set(0,0);
    Accelaration.set(0.001,0);
    
    topspeed = 4;
}

void car::OUTscreen(){
    
    if(Location.x < 0 + radius){
        
        Location.y += 150;
        Location.x = ofGetWidth()/2;
    }
    else if(Location.x > ofGetWidth() - radius){
        
        Location.y -= 100;
        Location.x = ofGetWidth()/2;
    }
    else if(Location.y < 0 +radius){
        
        Location.y = ofGetHeight()-radius;
    }
    else if(Location.y > ofGetHeight()-radius){
        
        Location.y = 0+radius;
    }
}

void car::move(int key_){
    
    //left
    if(key_ == 'c'){
        
        Velocity -= Accelaration;
    }
    //right
    else if(key_ == 'm'){
        Velocity += Accelaration;
    }
    
    Velocity.limit(topspeed);
    Location += Velocity;
    
}

void car::display(){
    
    float graden = ofRadToDeg(atan2(-Velocity.y,-Velocity.x));
    
    ofPushMatrix();
    ofTranslate(Location.x,Location.y);
    
    ofRotateZ(graden);
    ofRotateX(graden);
    
    
    ofSetColor(207,175,48);
    ofDrawRectangle(0,0,radius,radius-20);
    ofDrawRectangle(15,-15,radius-15,radius-15);
    
    ofSetColor(210,36,109);
    ofDrawRectangle(18,-13,radius-20,radius-20);
    
    ofSetColor(188,237,195);
    ofDrawEllipse(38,20,radius-30,radius-30);
    ofDrawEllipse(3,20,radius-30,radius-30);
    
    ofSetColor(87,229,235);
    ofDrawEllipse(6,7,radius-30,radius-30);
    
    ofPopMatrix();
}
