#include "Enemy.h"

int Enemy::getDamage()
{
	if (dealingDmgClock.getElapsedTime() >= seconds(0.75))
	{
		dealingDmgClock.restart();
		return dmg;		
	}
	else return 0;
}

void Enemy::takeDamage(int weaponDmg)
{
	hp -= weaponDmg;
}

int Enemy::getHp()
{
	return hp;
}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}
