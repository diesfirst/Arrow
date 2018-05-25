#pragma once

#include <classes/particleSystem.h>
#include <classes/Particle.h>
#include <glm/glm.hpp>
#include <string>

class Force
{
private:
	glm::vec3 gravity;

protected:
	ParticleSystem* particle_system;

public:

	Force(ParticleSystem* p);

	std::string printForce();

	ParticleSystem* getParticleSystem();

	void applyForce();
};