#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofVec2f pos;
        float mass = 200;
        int lerpAmount = 1;
        int lerpStep = 1;
        int radius;
    
        string name[27] = {"door", "door2", "shelf", "shelf2", "set", "set2", "tv", "tv2", "shoe", "shoe2", "sofa", "sofa2", "kitchen", "kitchen2", "chair", "chair2", "desk", "desk2", "table", "table2", "coffee", "coffee2", "game", "game2", "ball", "cart", "cart2"};
    
        int posX[27] = {1320, 610, 730, 10, 830, 110, 980, 260, 1287, 570, 960, 240, 1150, 430, 1125, 405, 730, 10, 730, 10, 728, 8, 790, 100, 1000, 20, 740};
        int posY[27] = {29, 29, 12, 12, 40, 40, 31, 31, 110, 110, 200, 200, 550, 550, 400, 400, 130, 130, 588, 588, 170, 170, 350, 350, 450, 480, 480};
    
        ofImage image[27];
        int heights[27];
        int widths[27];
        ofRectangle rects[27];
};
