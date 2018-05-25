#include <classes\particleSystem.h>
#include <classes\Forces.h>
#include <iostream>

using namespace std;

int test()
{
	cout << "So far so good" << endl;

	float delta = 0.1;

	ParticleSystem p;
	p.addParticle(4, 1, 1);
	p.addParticle(0.5, 0.5, 0.5);
	p.printParticles();

	p.addGravity();
	int dims = p.particleDims();
	
	cout << p.force_count << endl;

	float* dst = p.temp1;

	p.eulerStep(delta);
	p.printParticles();

	p.eulerStep(delta);
	p.printParticles();

	p.eulerStep(delta);
	p.printParticles();

	p.eulerStep(delta);
	p.printParticles();

	p.eulerStep(delta);
	p.printParticles();

	cout << "Forces: " << p.forces[0]->printForce() << endl;
	cout << "Forces Particle System: " << p.forces[0]->getParticleSystem() << endl;
	cout << &p << endl;

	return 0;
}