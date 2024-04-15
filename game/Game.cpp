#include "Game.h"

Game::Game() {
	this->gameStatus = 0;
	this->score = 0;
}

Game::~Game() {
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
		playerNextStep = 1;
		break;

	case 'a':
		playerNextStep = 3;
		break;

	case 's':
		playerNextStep = 2;
		break;

	case 'd':
		playerNextStep = 4;
		break;

		// NOT DONE YET NOT DONE YET NOT DONE YET NOT DONE YET NOT DONE YET NOT DONE YET
	case 'j':
	case 'k':
	case 'l':
		break;

	case ' ':
		isAttack = true;
		break;
	}

	// is collision player ship

	// is collision space ship (miss some store and it is big or medium)

	// update player position
	this->playerShip.updatePosition(playerNextStep);

	// change asteroid position
	// for.......

	// DEBUG USE
	system("cls");
	std::cout << "X: " << this->playerShip.getPositionX() << "\n";
	std::cout << "Y: " << this->playerShip.getPositionY() << "\n";
	std::cout << "HP: " << this->playerShip.getHealth() << "\n";
}

void Game::endGame() {
	this->gameStatus = 2;
}

int Game::getGameStatus() const {
	return this->gameStatus;
}

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
