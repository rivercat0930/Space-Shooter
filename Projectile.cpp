#include "Projectile.h"

Projectile::Projectile(int x, int y)
{
	this->positionX = x;
	this->positionY = y;
	this->speedY = 5;
}

void Projectile::update()
{
	this->positionY = this->positionY + speedY;
}

int Projectile::getPositionX() const
{
	return this->positionX;
}

int Projectile::getPositionY() const
{
	return this->positionY;
}
