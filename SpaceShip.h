#pragma once

class SpaceShip
{
public:
	SpaceShip();

	int getHealth() const;
	void setHealth(int dHealth);

private:
	int health;
};
