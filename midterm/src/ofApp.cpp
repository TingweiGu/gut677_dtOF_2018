#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(100);
    
    //load image, set rectangle
    for (int i = 0; i < 27; i++){
        image[i].load(name[i] + ".png");
        
        heights[i] =  image[i].getHeight();
        widths[i] = image[i].getWidth();
        rects[i].set(posX[i], posY[i], widths[i], heights[i]);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    glm::vec2 destination;
    destination.x   = ofGetMouseX();
    destination.y   = ofGetMouseY();
    
    float percent   = .05;
    glm::vec2 diff = destination - pos;
    pos += percent * diff;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofDrawLine(720, 0, 720, 800);
    
    for (int i = 0; i < 27; i++){

        glm::vec2 nearestPoint; // clamp circle to rect bounds
        nearestPoint.x = ofClamp(pos.x, rects[i].getLeft(), rects[i].getRight());
        nearestPoint.y = ofClamp(pos.y, rects[i].getTop(), rects[i].getBottom());
        
        glm::vec2 diff;
        diff.x = nearestPoint.x - (pos.x);
        diff.y = nearestPoint.y - (pos.y);
        bool rectCollided = glm::length(diff) <= 100;
        
        if (rectCollided) {
            ofSetColor(255,255,255,255-(abs(int(diff.x))+abs(int(diff.y)))*2);
            image[i].draw(posX[i], posY[i]);
        }
    }
    
    //glow
    ofColor glowColor = ofColor::fromHex(0x3E544C);
    const ofColor targetColor = ofColor::fromHex(0xB5B585);
    
    glowColor = glowColor.lerp(targetColor, lerpAmount/100.0);
    
    if(lerpAmount>100 || lerpAmount<1)
        lerpStep *= -1;
    lerpAmount += lerpStep;
    
    int glowResolution = 20;
    glowColor.a = 255.0/glowResolution;
    ofSetColor(glowColor);
    
    for(int i = glowResolution; i>0; i--){
        ofDrawCircle(pos, i*2);
    }
    
    //light
    ofSetCircleResolution(30);
    ofSetColor(ofColor(255,255,0));
    ofDrawCircle(pos,2);
    ofPopStyle();

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
