//
//  sun.cpp
//  wk06_h02_Interstellar
//
//  Created by Tingwei Gu on 10/9/18.
//

#include "sun.hpp"
void Sun::update(){
    
}

void Sun::draw(){
    ofPushStyle();
    ofSetCircleResolution(50);
    ofSetColor(ofColor(255,255,0));
    ofDrawCircle(pos.x, pos.y, 45);
    ofPopStyle();
}

ofVec2f Sun::calculateAttraction(Earth earth){
    ofVec2f force = pos - earth.pos;
    float distance = force.length();
    distance = ofClamp(distance, 0, 20);
    force.normalize();
    force *= (mass * earth.mass / (distance * distance));
    return force;
}
