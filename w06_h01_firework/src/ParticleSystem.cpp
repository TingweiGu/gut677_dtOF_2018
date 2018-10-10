#include "ParticleSystem.hpp"

// default value
ParticleSystem::ParticleSystem()
{
    pos = glm::vec2(0,0);
}

// assigned value
ParticleSystem::ParticleSystem(glm::vec2 _pos)
{
    pos = _pos;
}

// add the force to all particles
void ParticleSystem::applyForce(glm::vec2 force)
{
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].applyForce(force);
    }
}

//create new particles
void ParticleSystem::update(int numNewParticles, int maxParticles)
{
    for (int i=0; i<numNewParticles; i++)
    {
        glm::vec2 vel = glm::vec2(ofRandom(-3,3), ofRandom(-3,1));   // move up
        float mass = ofRandom(1, 2);
        Particle particle = Particle(pos,vel,mass);     // start at system's position
        particles.push_back(particle);
    }
    
    // update particles:
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].update();
    }

}


void ParticleSystem::draw()
{
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].draw();
    }
}

