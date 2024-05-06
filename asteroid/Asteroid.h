#pragma once

#include <cstdlib>
#include <ctime>

class Asteroid {
public:
	Asteroid();
	~Asteroid();

	int getHealth();
	/*
	* set health need an argument
	* this argument will be modify value
	* if you want to change from 3 to 2
	* them pass value as -1
	*/
	void setHealth(int val);

	int getPositionX();
	int getPositionY();

	void setPositionX(int x);

private:
	int health;
	int positionX;
	int positionY;

};
