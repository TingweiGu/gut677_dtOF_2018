//
//  star.hpp
//  wk06_h02_Interstellar
//
//  Created by Tingwei Gu on 10/9/18.
//

#ifndef star_hpp
#define star_hpp
#include <stdio.h>
#endif /* star_hpp */
#include "ofMain.h"
#include "earth.hpp"

class Star{
public:
    Star(Earth& _mother);
    ofVec2f pos = ofVec2f(10,10);
    ofVec2f acc = ofVec2f::zero();;
    ofVec2f vel = ofVec2f(3,1);
    ofColor color = ofColor(255,0,255);
    
    Earth& mother;
    float mass = 1;
    void update();
    void draw();
    ofVec2f calculateLocalAttraction();
    void applyForce(ofVec2f force);
        
};
