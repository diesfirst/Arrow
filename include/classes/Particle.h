#pragma once

#include <glm/glm.hpp>

using namespace glm;

struct Particle
{

	float mass; //mass
	vec3 pos; //position
	vec3 vel; //velocity
	vec3 force; //force accumulator

};