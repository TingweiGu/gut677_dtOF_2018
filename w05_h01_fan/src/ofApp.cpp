#include "ofApp.h"
float a = 0.25;
float b = 500;
float n = 300;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
//    cat.load("cat.png");
    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){
//        pos.x = ofMap(sin(ofGetElapsedTimef())*0.05, -1, 1, 0, ofGetWidth());
//        pos.y = ofMap(cos(ofGetElapsedTimef())*0.05, -1, 1, 0, ofGetWidth());;
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofPushStyle();
//    ofSetColor(255);
//    cat.draw(290,200,110,200);
//    ofTranslate(100,100);
//    ofSetColor(0);
//    ofDrawRectRounded(pos,13,180,10);
//    ofPopStyle();
    
    ofFill();
    ofSetColor(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(300,300);
    ofRotateZ(ofGetElapsedTimef()*n);
    ofDrawEllipse(0,0,220,50);
    ofDrawEllipse(0,0,50,220);
    ofPopMatrix();
    
    ofDrawLine(390, 390, 210, 210);
    ofDrawLine(210, 390, 390, 210);
    ofDrawLine(300, 430, 300, 170);
    ofDrawLine(170, 300, 430, 300);
    
    ofSetColor(255);
    ofDrawCircle(300,300,25);
    
    ofNoFill();
    ofSetColor(0);
    ofDrawCircle(300,300,130);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_UP){
        n += 50;
    }
    else if (key == OF_KEY_DOWN){
        n -= 50;
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
