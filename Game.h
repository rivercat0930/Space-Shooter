#pragma once

#include <chrono>
#include <cstdlib>
#include <vector>
#include "Asteroid.h"
#include "GameConfig.h"
#include "Player.h"
#include "Projectile.h"
#include "SpaceShip.h"

class Game
{
public:
	Game();

	int getScore() const;
	void update(Player& player, SpaceShip& spaceShip);
	/*
	* Check Player or SpaceShip still alive or not
	* if alive then game continue, return true
	* else return false
	*/
	bool check(Player player, SpaceShip spaceShip);
#ifdef DEBUG
	std::vector<Asteroid> getAsteroids();
#endif


private:
	int score;
	std::vector<Asteroid> asteroids;
	int maxAsteroids;
	// if number is 1 then will have interval for 1 seconds
	int spawnInterval;
	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point end;
};
