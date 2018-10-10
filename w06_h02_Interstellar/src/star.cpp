//
//  star.cpp
//  wk06_h02_Interstellar
//
//  Created by Tingwei Gu on 10/9/18.
//

#include "star.hpp"

Star::Star(Earth& _mother):mother(_mother){
}

void Star::update(){
    applyForce(calculateLocalAttraction());
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Star::draw(){
    ofPushMatrix();
    ofTranslate(mother.pos.x, mother.pos.y);
    ofSetColor(color);
    ofDrawCircle(pos.x, pos.y, 20);
    ofPopMatrix();
}

ofVec2f Star::calculateLocalAttraction(){
    
    ofVec2f force = -pos;
    float distance = force.length();
    distance = ofClamp(distance, 0, 10);
    force.normalize();
    force*= (3 * mass * mother.mass / (distance * distance));
    return force;
    
}

void Star::applyForce(ofVec2f force){
    acc += force/mass;
}
