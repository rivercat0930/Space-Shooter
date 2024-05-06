#include "Asteroid.h"

Asteroid::Asteroid() {
	this->health = int(std::rand() % 3) + 1;
}

Asteroid::~Asteroid() {
}

int Asteroid::getHealth() {
	return this->health;
}
