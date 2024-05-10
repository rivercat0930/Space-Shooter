#include "Game.h"

Game::Game()
{
	std::srand((unsigned)time(NULL));
	this->score = 0;
	this->maxAsteroids = 30;
	this->start = std::chrono::high_resolution_clock::now();
	this->end = std::chrono::high_resolution_clock::now();
}

int Game::getScore() const
{
	return this->score;
}

void Game::update(Player player, SpaceShip spaceShip)
{
	// ===== Spawn new asteroid =====
	this->end = std::chrono::high_resolution_clock::now();
	bool isPastSeconds =
		std::chrono::duration_cast<std::chrono::seconds>(this->end - this->start).count() > this->spawnInterval;
	if (asteroids.size() < maxAsteroids && isPastSeconds)
	{
		//spawnAsteroid
		asteroids.push_back(Asteroid(
			int(rand() % GAME_WIDTH),
			-10,
			int(1 + rand() % 10),
			int(1 + rand() % 3)
		));

		//resetSpawnTime
		this->start = this->end;
	}

	// ===== Asteroid aollision check =====
	for (auto asteroid = asteroids.begin(); asteroid != asteroids.end();)
	{
		bool destroy = false;
		asteroid->move();

		// out of screen
		if (asteroid->getPositionY() > GAME_HEIGHT)
		{
			destroy = true;
			spaceShip.setHealth(-asteroid->getHealth());
		}

		// player
		bool isCollisionWithPlayer = 
			asteroid->getPositionX() < player.getPositionX() + player.getWidth() &&
			asteroid->getPositionX() + 20 > player.getPositionX() &&
			asteroid->getPositionY() < player.getPositionY() + player.getHeight() &&
			asteroid->getPositionY() + 20 > player.getPositionY();

		if (isCollisionWithPlayer)
		{
			destroy = true;
			player.setHealth(-asteroid->getHealth());
		}

		// projectile
		auto& projectiles = player.getProjectiles();
		for (auto projectile = projectiles.begin(); projectile != projectiles.end();)
		{
			bool isCollision =
				projectile->getPositionX() < asteroid->getPositionX() + 20 &&
				projectile->getPositionX() + 5 > asteroid->getPositionX() &&
				projectile->getPositionY() < asteroid->getPositionY() + 20 &&
				projectile->getPositionY() + 5 > asteroid->getPositionY();

			if (isCollision)
			{
				destroy = true;
				asteroid->updateHealth(-1);
				projectile = projectiles.erase(projectile);
				if (asteroid->getHealth() <= 0) break;
			}
			else
			{
				++projectile;
			}
		}

		// should delete this asteroid or not
		if (destroy || asteroid->getHealth() <= 0)
			asteroids.erase(asteroid);
		else
			asteroid++;
	}
}

bool Game::check(Player player, SpaceShip spaceShip)
{
	return player.getHealth() > 0 && spaceShip.getHealth() > 0;
}
