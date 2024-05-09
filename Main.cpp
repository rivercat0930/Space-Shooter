#include <iostream>
#include <Windows.h>
#include "./Player.h"

// Debug switch
#define DEBUG true

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
	Player player(100, 100);

	std::cout << "Game initialized!\n";

	// ====================

	bool isGameRunning = true;
	while (isGameRunning)
	{
		// Process input
		int action = userInput();

		// Update game status
		player.move(1, 0);

		// Render Output

		// Force exit game (press esc)

	}

	std::cout << "Game Over!\n";
}
