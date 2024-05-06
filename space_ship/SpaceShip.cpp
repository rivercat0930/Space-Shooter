#include "SpaceShip.h"

SpaceShip::SpaceShip() {
	this->health = 5;
}

SpaceShip::~SpaceShip() {
}

int SpaceShip::getHealth() const {
	return this->health;
}

void SpaceShip::setHealth(int val) {
	this->health = this->health + val;
}
