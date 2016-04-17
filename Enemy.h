#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;

enum KillReward
{
	NormalZombieCash = 50
};

class Enemy
{
protected:
	Clock dealingDmgClock;
	
	int hp;
	float speed;
	int dmg;
	float blocksize;

public:
	void takeDamage(int weaponDmg);
	int getDamage();
	int getHp();
	Enemy();
	~Enemy();
};

