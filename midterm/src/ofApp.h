#pragma once

#include "ofMain.h"
#include "Particle.hpp"

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
    ofRectangle rectCollider, rectCollider2, rectCollider3, rectCollider4, rectCollider5, rectCollider6, rectCollider7, rectCollider8, rectCollider9, rectCollider10, rectCollider11, rectCollider12, rectCollider13, rectCollider14, rectCollider15, rectCollider16, rectCollider17, rectCollider18, rectCollider19, rectCollider20, rectCollider21, rectCollider22, rectCollider23, rectCollider24, rectCollider25, rectCollider26, rectCollider27;
		
};
