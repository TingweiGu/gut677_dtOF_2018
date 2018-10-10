#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    // setup general gravity force
    gravity = glm::vec2(0, 0.1);//just change y value

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].applyForce(gravity);
        particleSystems[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    // create a new particle system at mouse position on click
    particleSystems.push_back( ParticleSystem(glm::vec2(x,y)));

}
