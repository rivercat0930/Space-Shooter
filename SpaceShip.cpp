#include "SpaceShip.h"

SpaceShip::SpaceShip()
{
	this->health = 10;
}

int SpaceShip::getHealth() const
{
	return this->health;
}

void SpaceShip::setHealth(int dHealth)
{
	this->health = this->health + dHealth;
}
