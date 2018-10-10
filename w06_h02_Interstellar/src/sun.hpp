//
//  sun.hpp
//  wk06_h02_Interstellar
//
//  Created by Tingwei Gu on 10/9/18.
//

#ifndef sun_hpp
#define sun_hpp

#include <stdio.h>
#include "ofMain.h"
#include "earth.hpp"

#endif /* sun_hpp */

class Sun{
public:
    ofVec2f pos = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    float mass = 200;
    void update();
    void draw();
    ofVec2f calculateAttraction(Earth earth);
};

