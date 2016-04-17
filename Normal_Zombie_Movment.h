#pragma once
#include "Movment.h"

class Normal_Zombie_Movment :
	public Movment
{
	Time movmentTimer;
public:
	void move(float blockSize, float & enemySpeed, Vector2f targetPosition);
	void turnToTarget(float blockSize, Vector2f targetPosition);
	Normal_Zombie_Movment();
	~Normal_Zombie_Movment();
};

