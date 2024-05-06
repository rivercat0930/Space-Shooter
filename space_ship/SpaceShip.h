#pragma once

class SpaceShip {
public:
	SpaceShip();
	~SpaceShip();

	int getHealth() const;
	/*
	* set health need an argument
	* this argument will be modify value
	* if you want to change from 5 to 4
	* them pass value as -1
	*/
	void setHealth(int val);

private:
	int health;
};
