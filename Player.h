#pragma once

#include <iostream>
#include <vector>
#include "GameConfig.h"
#include "Projectile.h"

class Player
{
public:
	Player(int x, int y);

	void move(int dx, int dy);
	void attack();
	void updateProjectiles();
	void useSkill(int val);
	int getHealth() const;
	int getPositionX() const;
	int getPositionY() const;
	void setHealth(int dHealth);
	std::vector<Projectile>& getProjectiles();
	int getWidth() const;
	int getHeight() const;

private:
	int health;

	const int width = 30;
	const int height = 15;

	int positionX;
	int positionY;

	std::vector<Projectile> projectiles;
};
