#pragma once

#include <classes\Forces.h>
#include <glm\ext.hpp>



Force::Force(ParticleSystem* p) {
	 particle_system = p;
	 gravity = { 0.0, -1.0, 0.0 };
}

void Force::applyForce() {
	vector<Particle*> p = particle_system->getParticles();
	int i = 0;
	while (i < particle_system->getCount()) {
		p[i]->force += gravity;
		i++;
	}
}

std::string Force::printForce() {
	return glm::to_string(gravity);
}

ParticleSystem* Force::getParticleSystem() {
	return particle_system;
}