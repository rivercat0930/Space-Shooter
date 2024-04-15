#include "PlayerShip.h"

PlayerShip::PlayerShip() {
	this->positionX = 0;
	this->positionY = 0;
	this->health = 3;
}

PlayerShip::~PlayerShip() {
}

int PlayerShip::getPositionX() {
	return this->positionX;
}

int PlayerShip::getPositionY() {
	return this->positionY;
}

void PlayerShip::updatePosition(int val) {
	int tempX = this->positionX;
	int tempY = this->positionY;

	if (val == 1)
		tempX = tempX - 1;

	if (val == 2)
		tempX = tempX + 1;

	if (val == 3)
		tempY = tempY - 1;

	if (val == 4)
		tempY = tempY + 1;

	if (this->boundsCheck(tempX, tempY)) {
		tempX = this->positionX;
		tempY = this->positionY;
	}

	// update
	this->positionX = tempX;
	this->positionY = tempY;
}

int PlayerShip::getHealth() {
	return this->health;
}

void PlayerShip::setHealth(int val) {
	this->health = this->health + val;
}

bool PlayerShip::boundsCheck(int x, int y) {
	return x > X_AXIS_MAX || x < X_AXIS_MIN || y > Y_AXIS_MAX || y < Y_AXIS_MIN;
}
