
#include "ofMain.h" //have a reference to the openFrameworks framework

class Ball{
    public: //place public functions or variables declarations here
    
    void setup(float _x, float _y, float _dim); //set up initial state
    void update(); //refresh objects properties
    void draw(); //where you will do the object's drawing
    
    //variables
    float x, y; //position
    float speedX, speedY; //speed and direction
    float dim; //size
    ofColor color;
    
    Ball(); //constructor: initialize an object
}; // do not forget the semicolon!!!
