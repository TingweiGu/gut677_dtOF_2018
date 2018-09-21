#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(100);
    
    pos.y = 255;
    vel.y = 0.5;
}

//--------------------------------------------------------------
void ofApp::update(){
    pos += vel;
    
    if(pos.y>300){
        pos.y = 255;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    float a = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 255);
    
    ofSetColor(102,68,0);
    ofDrawCircle(195,235,25);
    ofDrawCircle(305,235,25);
    ofDrawCircle(200,270,30);
    ofDrawCircle(300,270,30);
    ofDrawCircle(225,295,25);
    ofDrawCircle(275,295,25);
    
    ofSetColor(255,230,204);
    ofDrawRectRounded(200, 195, 100, 100, 40);
    ofSetColor(0,204,204);
    ofDrawRectRounded(225, 300, 50, 70, 20);
    ofSetColor(255,230,204);
    ofDrawRectRounded(242, 287, 15, 20, 7);
    ofSetColor(255);
    ofDrawRectangle(225, 330, 70, 70);

    ofSetColor(102,68,0);

    ofDrawCircle(210,205,25);
    ofDrawCircle(248,195,30);
    ofDrawCircle(286,205,25);
    
    ofSetColor(255,230,204);
    ofDrawCircle(200,255,10);
    ofDrawCircle(300,255,10);
    
    ofSetColor(0);
    ofDrawCircle(233,250,3);
    ofDrawCircle(268,250,3);
    ofSetColor(255);
    ofDrawCircle(234,250,1.5);
    ofDrawCircle(269,250,1.5);
    
    ofSetColor(77,51,0);
    ofDrawCircle(225,pos.y,25);
    ofDrawCircle(274,pos.y,25);
    
    ofSetColor(255,195,a);
    ofDrawCircle(225,pos.y,21);
    ofDrawCircle(274,pos.y,21);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
