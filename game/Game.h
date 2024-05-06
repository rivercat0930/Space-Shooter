#pragma once

#include <Windows.h>
#include <WinUser.h>
#include <iostream>
#include "../player_ship/PlayerShip.h"
#include "../space_ship/SpaceShip.h"
#include "../asteroid/Asteroid.h"
#include "./GameScope.h"

// key input
#define W 0x57
#define A 0x41
#define S 0x53
#define D 0x44
#define J 0x4A
#define K 0x4B
#define L 0x4C

class Game {
public:
	Game();
	~Game();

	PlayerShip playerShip;
	SpaceShip spaceShip;
	Asteroid asteroid[30];

	void startGame();
	void updateGame();
	void endGame();
	int getGameStatus() const;

private:
	/* 
	* The gameStatus is check the game current status for game loop to decide next step.
	*
	* status code:
	* 0 -> game done initialize and not start yet.
	* 1 -> game is running.
	* 2 -> game over.
	*/
	int gameStatus;

	/*
	* Record the player's score.
	* If player attack a asteroid, then it will get the same score on asteroid.
	* Bigger and more scores
	*/
	int score;

	char keyInput();
};
