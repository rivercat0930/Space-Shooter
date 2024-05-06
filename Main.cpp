#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <cstdlib>
#include "./game/Game.h"

int main() {

	// initiallize game windows, graphics, input system
	
	// game main loop
	std::srand(std::time(nullptr));
	Game game;
	game.startGame();
	while (true) {
		game.updateGame();

		if (game.getGameStatus() == 2)
			break;

		Sleep(20);
	}

	// release resources
}
