#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include "./game/Game.h"

int main() {
	// initiallize game windows, graphics, input system
	
	// game main loop
	Game game;
	game.startGame();
	while (true) {
		game.updateGame();

		Sleep(20);
	}

	// release resources
}
