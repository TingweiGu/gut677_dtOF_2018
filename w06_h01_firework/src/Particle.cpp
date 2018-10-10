#include "Particle.hpp"
// default constructor
// Particle particle = Particle()
Particle::Particle()
{
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    lifespan = 255;
}

// "overload" constructor, alternative:
// Particle particle = Particle(pos,vel,acc);
Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass)
{
    pos = _pos;
    vel = _vel;
    mass = _mass;
}

void Particle::applyForce(glm::vec2 force)
{
    acc += force / mass;
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
    lifespan -= 15;
}

void Particle::draw()
{
    ofPushStyle();
    ofSetColor(255,0,255,lifespan);
    ofDrawCircle(pos, mass * 2.0);
    ofPopStyle();
}

