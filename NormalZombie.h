#pragma once
#include "Enemy.h"
#include "Normal_Zombie_Movment.h"

class NormalZombie :
	public Enemy
{
	Normal_Zombie_Movment normalZombieMovment;
	Time knockbackTime;
	Clock knockbackClock;
	bool isKnockbacked;
public:
	void setEnemy(int x, int y, float blockSize, Texture & texture);
	void move(Vector2f targetPosition);
	void turnToTarget(Vector2f targetPosition);
	Sprite getWalkingSprite();
	void knockBackOnHit(Vector2f charPosition);
	NormalZombie();
	~NormalZombie();
};

