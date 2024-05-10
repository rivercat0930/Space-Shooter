#pragma once

#include <vector>
#include "Asteroid.h"

class Game
{
public:
	Game();

	int getScore();
	void update();

private:
	int score;
	std::vector<Asteroid> asteroids;

	void collisionCheck();
};
