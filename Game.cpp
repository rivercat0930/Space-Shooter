#include "Game.h"

Game::Game()
{
	this->score = 0;
}

int Game::getScore() const
{
	return this->score;
}

void Game::update()
{

}

bool Game::check(Player player, SpaceShip spaceShip)
{
	return player.getHealth() > 0 && spaceShip.getHealth() > 0;
}
