#include "ofMain.h"
#include "supermary.hpp"
#include "car.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
    
        vector<Supermary> supermarys;
        vector <car> cars;
        int start;
        int amount;

		
};
