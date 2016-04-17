#pragma once
#include <vector>
#include "NormalZombie.h"


#define SPAWN_TIME 3.0	// W SEKUNDACH

struct Enemies
{
	vector<NormalZombie> normalZombies;
};


class Ai_Manager
{
	struct EnemiesSpawnPoints
	{
		Vector2i spawnPoint[4];
	};

	Texture normalZombieTexture;	// jedna zmienna na wszystkie obiekty klasy normalZombie
	Texture deadNormalZombieTexture;
	vector<Sprite> deadEnemiesSprites;

	int mapSizeX, mapSizeY, blockSize;
	Clock zombieSpawnerClock;
	Time zombieSpawnTime;
	Time stageTime;
	Enemies enemies;

	SoundBuffer normalZombieDyingSoundBuffer;
	Sound normalZombieDyingSound;

	EnemiesSpawnPoints spawnPoints;

	int enemiesSpawned;

	void zombies_Attack_Movment(Vector2f targetPosition);
	void spawnZombies(int stage);
public:
	void setManager(int mapSizeX, int mapSizeY, int blockSize);
	void manage(int stage, Vector2f targetPosition, int & cash, int & killedEnemiesNumber);
	void drawZombies(RenderWindow & window);
	Enemies & getEnemies();
	void nextStage();
	void drawDeadZombies(RenderWindow & window);

	Ai_Manager();
	~Ai_Manager();
};

