#pragma once

#include <classes/Particle.h>
#include <vector>

using namespace glm;
using std::vector;

class Force; //forward declaring 

class ParticleSystem 
{

private:

	vector<Particle*> particles; //array of particles

public:
	
	unsigned int count; //particle count
	float time; //simulation time
	float* temp1; //note currently only allows for 100 particles
	float* temp2;
	unsigned int force_count;
	vector<Force*> forces;

	ParticleSystem();

	// length of state derivatives, and force vectors
	int particleDims();

	// gather state from the particles into dst
	void getState(float *dst);

	// scatter state from src into the particles
	void setState(float* src);

	// calculate derivative, place into dst
	void derivative(float* dst);

	void clear_forces();

	void compute_forces();

	void addGravity();

	void scaleVector(float scale, float* vector);

	void addVectors(float* vector1, float* vector2, float* sumVector);

	void eulerStep(float delta_t);

	void addParticle(float x, float y, float z);

	void printParticles();

	vector<Particle*> getParticles();

	int getCount();

};