//
//  earth.cpp
//  wk06_h02_Interstellar
//
//  Created by Tingwei Gu on 10/9/18.
//

#include "earth.hpp"
#include "ofMain.h"

Earth::Earth(){
}

Earth::Earth(float _mass, ofVec2f _pos){
    mass = _mass;
    pos = _pos;
}

Earth::Earth(float _mass, ofVec2f _pos, ofVec2f _vel, ofColor _color){
    mass = _mass;
    pos = _pos;
    vel = _vel;
    color = _color;
}

void Earth::update(){
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Earth::draw(){
    ofSetColor(color);
    ofDrawCircle(pos.x, pos.y, mass * 5);
}

void Earth::applyForce(ofVec2f force){
    acc += force/mass;
}
