#pragma once

#include <classes\particleSystem.h>
#include <iostream>
#include <classes\Forces.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/ext.hpp>

using namespace glm;
using std::vector;

ParticleSystem::ParticleSystem()
	{
		count = 0;
		time = 0.0;
		force_count = 0;
		temp1 = new float[12];
		temp2 = new float[12];
	}

int ParticleSystem::particleDims() {
		return (6 * count);
	}

	// gather state from the particles into dst
void ParticleSystem::getState(float *dst) {
		int i;
		for (i = 0; i < count; i++) {
			*(dst++) = particles[i]->pos[0];
			*(dst++) = particles[i]->pos[1];
			*(dst++) = particles[i]->pos[2];
			*(dst++) = particles[i]->vel[0];
			*(dst++) = particles[i]->vel[1];
			*(dst++) = particles[i]->vel[2];
		}
	}

	// scatter state from src into the particles
void ParticleSystem::setState(float* src) {
		int i;
		for (i = 0; i < count; i++) {
			particles[i]->pos[0] = *(src++);
			particles[i]->pos[1] = *(src++);
			particles[i]->pos[2] = *(src++);
			particles[i]->vel[0] = *(src++);
			particles[i]->vel[1] = *(src++);
			particles[i]->vel[2] = *(src++);
		}
	}

	// calculate derivative, place into dst
void ParticleSystem::derivative(float* dst) {
		int i;
		clear_forces();
		compute_forces();
		for (i = 0; i < count; i++) {
			Particle* p = particles[i];
			*(dst++) = p->vel[0];
			*(dst++) = p->vel[1];
			*(dst++) = p->vel[2];
			*(dst++) = p->force[0];
			*(dst++) = p->force[1];
			*(dst++) = p->force[2];
		}
	}

void ParticleSystem::clear_forces() {
		int i;
		for (i = 0; i < count; i++) {
			particles[i]->force = { 0.0, 0.0, 0.0 };
		}
	}

void ParticleSystem::compute_forces() {
		int i;
		for (i = 0; i < force_count; i++) {
			forces[i]->applyForce();
		}
	}

void ParticleSystem::addGravity() {
		Force* gravity = new Force(this);
		forces.push_back(gravity);
		force_count++;
	}

void ParticleSystem::scaleVector(float scale, float* vector) {
		int i = 0;
		while (i < particleDims()) {
			vector[i] = vector[i] * scale;
			i++;
		}
	}

void ParticleSystem::addVectors(float* vector1, float* vector2, float* sumVector) {
		int i = 0;
		while (i < particleDims()) {
			sumVector[i] = vector2[i] + vector1[i];
			i++;
		}
	}

void ParticleSystem::eulerStep(float delta_t) {
		derivative(temp1);
		scaleVector(delta_t, temp1);
		getState(temp2);
		addVectors(temp1, temp2, temp2);
		setState(temp2);
		time += delta_t;
		//delete[] temp1;
		//delete[] temp2;
	}

void ParticleSystem::addParticle(float x, float y, float z){
		Particle* p = new Particle;
		p->mass = 1.0;
		p->pos = { x, y, z };
		p->vel = { 1.0, 0.0, 0.0 };
		p->force = { 0.0, 0.0, 0.0 };
		particles.push_back(p);
		count++;
	}

void ParticleSystem::printParticles() {
		std::cout << "----Particle List Start-----" << std::endl;
		for (int i = 0; i < count; i++) {
			std::cout << "Particle " << i << ": Position: " << to_string(particles[i]->pos) << std::endl;
		}
		std::cout << "----Particle List End-------" << std::endl;
	}

vector<Particle*> ParticleSystem::getParticles() {
		return particles;
	}

int ParticleSystem::getCount() {
		return count;
	}