#pragma once

#define X_AXIS_MAX 900
#define X_AXIS_MIN 0
#define Y_AXIS_MAX 400
#define Y_AXIS_MIN 0

class PlayerShip {
public:
	PlayerShip();
	~PlayerShip();

	int getPositionX();
	int getPositionY();
	void updatePosition(int val);

	int getHealth();
	/*
	* Set health method need an argument
	* val is update value
	* if you want to let health from 3 to 2
	* then please enter -1
	*/
	void setHealth(int val);

private:
	int positionX;
	int positionY;
	int health;

	/*
	* boundsCheck is check play will go outside or not
	*
	* return false => change is accept
	* return true => change is violate
	*/
	bool boundsCheck(int x, int y);
};
