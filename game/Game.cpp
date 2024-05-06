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

	// update player position
	this->playerShip.updatePosition(playerNextStep);

#ifdef DEBUG
	std::cout << "Asteroids position and health:\n";
#endif // DEBUG


	// change asteroid position and trying to spawn it
	for (int i = 0; i < 30; i++) {
		bool isCollision = this->asteroid[i].getPositionX() == this->playerShip.getPositionX() && this->asteroid[i].getPositionY() == this->playerShip.getPositionY();
		bool isOut = this->asteroid[i].getPositionX() > X_AXIS_MAX;
		bool needDestroy = false;

		/* 
		* check is collision or not
		* if collision then take away health from playerShip
		* and destroy this asteroid
		* 
		* else if 
		* 
		* else change this asteroid position
		*/
		if (isCollision) {
			int damage = this->asteroid[i].getHealth();
			this->playerShip.setHealth(-damage);

			// destroy asteroid
			needDestroy = true;
		}
		else if (isOut) {
			int damage = this->asteroid[i].getHealth();
			this->spaceShip.setHealth(-damage);

			// destroy asteroid
			needDestroy = true;
		}
		else
			this->asteroid[i].setPositionX(this->asteroid[i].getPositionX() + 1);

		if (needDestroy) {
			this->asteroid[i] = Asteroid();
		}

#ifdef DEBUG
		std::cout << this->asteroid[i].getPositionX() << " " << this->asteroid[i].getPositionY() << " " << this->asteroid[i].getHealth() << "\n";
#endif // DEBUG
	}

	// end game
	if (this->spaceShip.getHealth() <= 0 || this->playerShip.getHealth() <= 0)
		this->endGame();


#ifdef DEBUG
	std::cout << "Player Info:\n";
	std::cout << "X: " << this->playerShip.getPositionX() << "\n";
	std::cout << "Y: " << this->playerShip.getPositionY() << "\n";
	std::cout << "HP: " << this->playerShip.getHealth() << "\n";
	std::cout << "====\n";
	std::cout << "HP_SpaceShip: " << this->spaceShip.getHealth() << "\n";
#endif
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
