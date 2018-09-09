#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i=0; i < groupOfBalls.size(); i++){
        float randomX = ofRandom(0, ofGetWidth());
        float randomY = ofRandom(0, ofGetHeight());
        float size = ofRandom(0,40);
        groupOfBalls[i].setup(randomX, randomY, size);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i < groupOfBalls.size(); i++){
        groupOfBalls[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i < groupOfBalls.size(); i++){
        groupOfBalls[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    groupOfBalls.clear();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    Ball tempBall;
    tempBall.setup(x,y,ofRandom(0,40));
    groupOfBalls.push_back(tempBall);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    for(int i = 0; i < groupOfBalls.size(); i++) {
        float distance = ofDist(x, y, groupOfBalls[i].x, groupOfBalls[i].y);
        if(distance < groupOfBalls[i].dim) {
            groupOfBalls.erase(groupOfBalls.begin()+i);
        }
    }
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
