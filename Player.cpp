#include "Player.h"

Player::Player(int x, int y)
{
	this->health = 3;

	this->positionX = x;
	this->positionY = y;
}

void Player::move(int dx, int dy)
{
	this->positionX = std::max(0, std::min(this->positionX + dx, GAME_WIDTH - width));
	this->positionY = std::max(0, std::min(this->positionY + dy, GAME_HEIGHT - height));
}

// NOT DONE YET
void Player::attack()
{ }

void Player::updateProjectiles()
{ }

// NOT DONE YET
void Player::useSkill(int val)
{ }

int Player::getHealth() const
{
	return this->health;
}

int Player::getPositionX() const
{
	return this->positionX;
}

int Player::getPositionY() const
{
	return this->positionY;
}

void Player::setHealth(int dHealth)
{
	this->health = this->health + dHealth;
}

std::vector<Projectile>& Player::getProjectiles()
{
	return this->projectiles;
}

int Player::getWidth() const
{
	return this->width;
}

int Player::getHeight() const
{
	return this->height;
}
