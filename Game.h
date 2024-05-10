#pragma once

#include <vector>
#include "Asteroid.h"
#include "Player.h"
#include "SpaceShip.h"

class Game
{
public:
	Game();

	int getScore() const;
	void update();
	/*
	* Check Player or SpaceShip still alive or not
	* if alive then game continue, return true
	* else return false
	*/
	bool check(Player player, SpaceShip spaceShip);

private:
	int score;
	std::vector<Asteroid> asteroids;

	void collisionCheck();
};
