#include "ball.hpp"

void Ball::setup(float posX, float posY, float _dim){
    
    pos = glm::vec2(posX, posY);
    dim = _dim;
}

void Ball::update(){
    vel += acc;
    pos += vel;
    
    if(pos.x>ofGetWidth()){
        pos.x = 0;
    }
    else if(pos.x < 0){
        pos.x = ofGetWidth();
    }
    
    if(pos.y>ofGetHeight()){
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
    else if(pos.y < 0){
        pos.y = 0;
        vel.y *= -1;
    }
}

void Ball::draw(){
    ofSetColor(color);
    ofDrawCircle(pos.x,pos.y,dim);
}
