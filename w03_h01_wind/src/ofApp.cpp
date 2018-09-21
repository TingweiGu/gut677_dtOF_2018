#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    for (int i=0; i<10; i++){
        float w = ofRandom(10,30);
        
        float x = ofRandom(0, 200);
        float y = ofRandom(0, 100);
        
        balls[i].setup(x,y,w);
    
        balls[i].vel.x = 0;
        balls[i].vel.y = ofRandom(0.2,0.5);

        balls[i].acc.x = 0;
        balls[i].acc.y = ofRandom(0.3,0.8);

        balls[i].wind.x = 0.3;
        balls[i].wind.y = 0;
        
        balls[i].color = ofColor(ofRandom(255),ofRandom(255),ofRandom(255),70);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<10; i++){
        balls[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<10; i++){
        balls[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for (int i=0; i<10; i++){
        if (key == OF_KEY_RIGHT){
            balls[i].vel += balls[i].wind;
        }
        else if (key == OF_KEY_LEFT){
            balls[i].vel -= balls[i].wind;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

