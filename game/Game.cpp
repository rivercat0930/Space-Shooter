#include "Game.h"

Game::Game() {
}

Game::~Game() {}

char Game::keyInput() {
	if (GetAsyncKeyState(W) & 0x01 || GetAsyncKeyState(VK_UP) & 0x01)
		return 'w';

	if (GetAsyncKeyState(A) & 0x01 || GetAsyncKeyState(VK_LEFT) & 0x01)
		return 'a';

	if (GetAsyncKeyState(S) & 0x01 || GetAsyncKeyState(VK_DOWN) & 0x01)
		return 's';

	if (GetAsyncKeyState(D) & 0x01 || GetAsyncKeyState(VK_RIGHT) & 0x01)
		return 'd';

	if (GetAsyncKeyState(J) & 0x01)
		return 'j';

	if (GetAsyncKeyState(K) & 0x01)
		return 'k';

	if (GetAsyncKeyState(L) & 0x01)
		return 'l';

	if (GetAsyncKeyState(VK_SPACE) & 0x01)
		return ' ';

	return 0;
}

void Game::startGame() {
	// init game data
	this->gameStatus = 1;
	this->score = 0;

	// spawn player ship
	this->playerShip = PlayerShip();

	// spwan space ship
	this->spaceShip = SpaceShip();
}

void Game::updateGame() {
	char playerNextStep = 0;
	bool isAttack = false;

	// get key input and decide next step
	switch (this->keyInput()) {
	case 'w':
		playerNextStep = -1;
		break;

	case 'a':
		playerNextStep = -11;

	case 's':
		playerNextStep = 1;
		break;

	case 'd':
		playerNextStep = 11;
		break;

		// NOT DONE YET NOT DONE YET NOT DONE YET NOT DONE YET NOT DONE YET NOT DONE YET
	case 'j':
	case 'k':
	case 'l':
		break;

		// NOT DONE YET NOT DONE YET NOT DONE YET NOT DONE YET NOT DONE YET NOT DONE YET
	case ' ':
		isAttack = true;
		break;
	}


	// is collision player ship

	// is collision space ship (miss some store and it is big or medium)

	// update player position

	// change asteroid position
}

void Game::endGame() {

}
