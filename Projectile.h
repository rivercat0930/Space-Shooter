#pragma once

class Projectile
{
public:
	Projectile(int x, int y);

	void update();
	int getPositionX() const;
	int getPositionY() const;

private:
	int positionX;
	int positionY;
	int speedY;
};
