#pragma once

class Asteroid
{
public:
	Asteroid(int x, int y, int speed, int health);

	void move();
	void updateHealth(int dHealth);
	int getHealth() const;
	int getPositionX() const;
	int getPositionY() const;

private:
	int positionX;
	int positionY;
	int speedY;
	int health;
};
