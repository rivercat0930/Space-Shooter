#include "Asteroid.h"

Asteroid::Asteroid(int x, int y, int speed, int health)
{
	this->positionX = x;
	this->positionY = y;
	this->speedY = speed;
	this->health = health;
}

void Asteroid::move()
{
	this->positionY = this->positionY + speedY;
}

void Asteroid::updateHealth(int dHealth)
{
	this->health = this->health + dHealth;
}

int Asteroid::getHealth() const
{
	return this->health;
}

int Asteroid::getPositionX() const
{
	return this->positionX;
}

int Asteroid::getPositionY() const
{
	return this->positionY;
}
