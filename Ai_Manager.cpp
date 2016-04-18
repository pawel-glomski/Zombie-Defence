#include "Ai_Manager.h"



void Ai_Manager::zombies_Attack_Movment(Vector2f targetPosition)
{
	for (size_t i = 0; i < enemies.normalZombies.size(); i++)
	{
		enemies.normalZombies[i].move(targetPosition);
		enemies.normalZombies[i].turnToTarget(targetPosition);

		for (size_t j = 0; j < enemies.normalZombies.size(); j++)
		{
			if (enemies.normalZombies[i].getWalkingSprite().getGlobalBounds().intersects(enemies.normalZombies[j].getWalkingSprite().getGlobalBounds()) && j != i)
			{
				enemies.normalZombies[i].moveWalkingSprite
				(Vector2f((enemies.normalZombies[i].getWalkingSprite().getPosition().x - enemies.normalZombies[j].getWalkingSprite().getPosition().x) / 100.0,
				(enemies.normalZombies[i].getWalkingSprite().getPosition().y - enemies.normalZombies[j].getWalkingSprite().getPosition().y) / 100.0 ));	// 100 - jakas du¿a liczba, by wektor przemieszczenia by³ ma³y
				break;
			}
		}
	}
}

void Ai_Manager::spawnZombies(int stage)
{
	zombieSpawnTime += zombieSpawnerClock.getElapsedTime();
	stageTime += zombieSpawnerClock.getElapsedTime();
	zombieSpawnerClock.restart();
	if (zombieSpawnTime >= seconds(1.0/stage * SPAWN_TIME) && enemiesSpawned < stage * 10)
	{
		enemiesSpawned++;
		int random = rand() % 4;
		zombieSpawnTime = seconds(0);

		NormalZombie newNormalZombie;

		enemies.normalZombies.push_back(newNormalZombie);
		enemies.normalZombies[enemies.normalZombies.size() - 1].setEnemy(spawnPoints.spawnPoint[random].x, spawnPoints.spawnPoint[random].y, blockSize, normalZombieTexture);
	}
}

void Ai_Manager::setManager(int mapSizeX, int mapSizeY, int blockSize)
{
	this->mapSizeX = mapSizeX;
	this->mapSizeY = mapSizeY;
	this->blockSize = blockSize;
	zombieSpawnerClock.restart();

	spawnPoints.spawnPoint[0] = Vector2i(1, 1);
	spawnPoints.spawnPoint[1] = Vector2i(1, mapSizeY - 2);
	spawnPoints.spawnPoint[2] = Vector2i(mapSizeX-2, 1);
	spawnPoints.spawnPoint[3] = Vector2i(mapSizeX-2, mapSizeY-2);
}

void Ai_Manager::manage(int stage, Vector2f targetPosition, int & cash, int & killedEnemiesNumber)
{
	spawnZombies(stage);
	zombies_Attack_Movment(targetPosition);
	for (size_t i = 0; i < enemies.normalZombies.size(); i++)
	{
		if (enemies.normalZombies[i].getHp() <= 0)
		{
			Sprite newDeadNormalZombie;
			newDeadNormalZombie.setTexture(deadNormalZombieTexture);
			newDeadNormalZombie.setTextureRect(IntRect(0, 0, deadNormalZombieTexture.getSize().x, deadNormalZombieTexture.getSize().y));
			newDeadNormalZombie.setScale(enemies.normalZombies[i].getWalkingSprite().getScale());
			newDeadNormalZombie.setPosition(enemies.normalZombies[i].getWalkingSprite().getPosition());
			newDeadNormalZombie.setOrigin(enemies.normalZombies[i].getWalkingSprite().getOrigin());
			newDeadNormalZombie.setRotation(enemies.normalZombies[i].getWalkingSprite().getRotation());

			deadEnemiesSprites.push_back(newDeadNormalZombie);

			enemies.normalZombies.erase(enemies.normalZombies.begin() + i);
			normalZombieDyingSound.play();
			cash += NormalZombieCash;
			killedEnemiesNumber++;
		}
	}

}
void Ai_Manager::drawZombies(RenderWindow & window)
{
	for (size_t i = 0; i < enemies.normalZombies.size(); i++)
	{
		window.draw(enemies.normalZombies[i].getWalkingSprite());
	}
}

Enemies & Ai_Manager::getEnemies()
{
	return enemies;
}

void Ai_Manager::nextStage()
{
	enemiesSpawned = 0;
}

void Ai_Manager::drawDeadZombies(RenderWindow & window)
{
	if (deadEnemiesSprites.size() != 0)
	{
		for (size_t i = 0; i < deadEnemiesSprites.size(); i++)
		{
			
			window.draw(deadEnemiesSprites[i]);
		}
	}
}

Ai_Manager::Ai_Manager()
{
	enemiesSpawned = 0;
	stageTime = seconds(0);
	zombieSpawnTime = seconds(0);
	normalZombieTexture.loadFromFile("files/normalZombieWalkingAnimation.png");
	deadNormalZombieTexture.loadFromFile("files/DEADnormalZombie.png");
	normalZombieDyingSoundBuffer.loadFromFile("files/NormalZombieDyingSound.wav");
	normalZombieDyingSound.setBuffer(normalZombieDyingSoundBuffer);
	srand(time(NULL));

}


Ai_Manager::~Ai_Manager()
{
}
