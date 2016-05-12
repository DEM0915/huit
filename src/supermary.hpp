#include "ofMain.h"

class Supermary {
public:
    
    void setup();
    void update(float _mX, float _mY);
    void draw();
    
    ofVec2f Pos1, pos, p1, p2, p3;
    float rot;
    ofColor c, newC;
};

