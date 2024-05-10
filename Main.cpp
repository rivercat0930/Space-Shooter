#include <iostream>
#include <Windows.h>
#include "Game.h"
#include "GameConfig.h"
#include "Player.h"

/*
* Receive player input and return specific codes to indicate the current state:
* -1 => End game
* 
* 11 => Player moves up
* 12 => Player moves right
* 13 => Player moves down
* 14 => Player moves left
*
* 2 => Player issues an attack command
*
* 31 => Player presses the 'j' skill
* 32 => Player presses the 'k' skill
* 33 => Player presses the 'l' skill
* 
* 0 => No input or invaild input
*/
int userInput()
{
	/*
	* More detail about GetAsyncKeyState please go to MSDN,
	* it also have some example.
	* 
	* https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getasynckeystate
	*/

	// ESC
	if (GetAsyncKeyState(VK_ESCAPE) & 0x01)
		return -1;

	// Up
	if ((GetAsyncKeyState(VK_UP) & 0x01) || (GetAsyncKeyState(0x57) & 0x01))
		return 11;
	// Right
	if ((GetAsyncKeyState(VK_RIGHT) & 0x01) || (GetAsyncKeyState(0x44) & 0x01))
		return 12;
	// Down
	if ((GetAsyncKeyState(VK_DOWN) & 0x01) || (GetAsyncKeyState(0x53) & 0x01))
		return 13;
	// Left
	if ((GetAsyncKeyState(VK_LEFT) & 0x01) || (GetAsyncKeyState(0x41) & 0x01))
		return 14;

	// Attack
	if (GetAsyncKeyState(VK_SPACE) & 0x01)
		return 2;

	// J
	if (GetAsyncKeyState(0x4A) & 0x01)
		return 31;
	// K
	if (GetAsyncKeyState(0x4B) & 0x01)
		return 32;
	// L
	if (GetAsyncKeyState(0x4C) & 0x01)
		return 33;

	return 0;
}

int main()
{
	Game game;
	Player player(385, 575);

	std::cout << "Game initialized!\n";

	bool isGameRunning = true;
	while (isGameRunning)
	{
		// ===== Debug information =====
#ifdef DEBUG

#endif

		// ===== Process input =====
		// Receive user input and determine the next step
		int action = userInput();

		// ===== Update game status =====
		// player move
		if (action == 11)
			player.move(0, 10);
		if (action == 12)
			player.move(10, 0);
		if (action == 13)
			player.move(0, -10);
		if (action == 14)
			player.move(-10, 0);

		// player attack
		if (action == 2)
			player.attack();

		// player using skill
		if (action == 31)
			player.useSkill(0);
		if (action == 32)
			player.useSkill(1);
		if (action == 33)
			player.useSkill(2);

		// update projectiles
		player.updateProjectiles();
		game.update();

		// ===== Render Output =====

		// ===== Check game status =====
		isGameRunning = game.check();

		// ===== Force exit game (press esc) =====
		if (action == -1)
			isGameRunning = false;

		// ===== Delay =====
		Sleep(200);
	}

	std::cout << "Game Over!\n";
}
