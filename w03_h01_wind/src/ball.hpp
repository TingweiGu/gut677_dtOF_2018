
#include "ofMain.h" //have a reference to the openFrameworks framework

class Ball{
public: //place public functions or variables declarations here
    
    void setup(float posX, float posY, float _dim);
    void update();
    void draw();
    
    float dim;
    ofColor color;
    
    glm::vec2 pos;
    glm::vec2 vel;
    glm::vec2 acc;
    glm::vec2 wind;
   
};

