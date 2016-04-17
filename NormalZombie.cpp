#include "NormalZombie.h"

void NormalZombie::setEnemy(int x, int y, float blockSize, Texture & texture)
{
	this->blocksize = blockSize;
	normalZombieMovment.setSpritePosition(Vector2f(x*blockSize, y*blockSize));
	normalZombieMovment.setWalkingTexture(texture, blockSize);
}

void NormalZombie::move(Vector2f targetPosition)
{
	if (!isKnockbacked)
	{
		normalZombieMovment.move(blocksize, speed, targetPosition);
	}
	else
	{
		if (knockbackClock.getElapsedTime() >= knockbackTime)
			isKnockbacked = false;
	}
	
}

void NormalZombie::turnToTarget(Vector2f targetPosition)
{
	normalZombieMovment.turnToTarget(blocksize, targetPosition);
}

Sprite NormalZombie::getWalkingSprite()
{
	return normalZombieMovment.getWalkingSprite();
}

void NormalZombie::knockBackOnHit(Vector2f charPosition)
{
	float xLength = abs(charPosition.x - normalZombieMovment.getWalkingSprite().getPosition().x);
	float yLength = abs(charPosition.y - normalZombieMovment.getWalkingSprite().getPosition().y);
	float ratio = 0;
	float vectorYlen = 0;
	float vectorXlen = 0;
	if (yLength != 0 && xLength != 0)
	{
		ratio = xLength / yLength;
		vectorYlen = sqrt(pow(blocksize/2, 2) / (1 + pow(xLength / yLength, 2)));
		vectorXlen = vectorYlen*ratio;
	}
	else if (yLength == 0) vectorXlen = blocksize / 2;

	if (charPosition.x > normalZombieMovment.getWalkingSprite().getPosition().x)
		vectorXlen *= -1;
	if (charPosition.y > normalZombieMovment.getWalkingSprite().getPosition().y)
		vectorYlen *= -1;

	normalZombieMovment.setSpritePosition(Vector2f(normalZombieMovment.getWalkingSprite().getPosition().x + vectorXlen, normalZombieMovment.getWalkingSprite().getPosition().y + vectorYlen));

	isKnockbacked = true;
	knockbackClock.restart();
}


NormalZombie::NormalZombie()
{
	hp = 100;
	speed = 7;
	dmg = 1;
	knockbackTime = seconds(0.2);
	isKnockbacked = false;
}



NormalZombie::~NormalZombie()
{
}
