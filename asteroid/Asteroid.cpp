#include "Asteroid.h"
#include "../game/GameScope.h"

Asteroid::Asteroid() {
	this->health = int(std::rand() % 3) + 1;
	this->positionX = int(std::rand() % 200);
	this->positionY = int(std::rand() % Y_AXIS_MAX) + Y_AXIS_MIN;
}

Asteroid::~Asteroid() {
}

int Asteroid::getHealth() {
	return this->health;
}

void Asteroid::setHealth(int val) {
	this->health = this->health + val;
}

int Asteroid::getPositionX() {
	return this->positionX;
}

int Asteroid::getPositionY() {
	return this->positionY;
}

void Asteroid::setPositionX(int x) {
	this->positionX = x;
}
