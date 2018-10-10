//
//  earth.hpp
//  wk06_h02_Interstellar
//
//  Created by Tingwei Gu on 10/9/18.
//

#pragma once
#ifndef earth_hpp
#define earth_hpp

#include <stdio.h>
#endif /* earth_hpp */

#include "ofMain.h"

class Earth{
public:
    Earth();
    Earth(float mass, ofVec2f pos);
    Earth(float mass, ofVec2f pos, ofVec2f vel, ofColor color);
    ofVec2f pos;

    ofColor color = ofColor(0,0,255);
    
    ofVec2f vel = ofVec2f(2,1);
    ofVec2f acc = ofVec2f::zero();
    float mass = 2;
    
    void update();
    void draw();
    void applyForce(ofVec2f force);
    
};

