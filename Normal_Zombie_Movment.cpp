#include "Normal_Zombie_Movment.h"

void Normal_Zombie_Movment::move(float blockSize, float & enemySpeed, Vector2f targetPosition)
{
	// obliczanie odpowiednych X i Y przemieszczenia... 
	float xLength = abs(animations.getSprite().getPosition().x - targetPosition.x);
	float yLength = abs(animations.getSprite().getPosition().y - targetPosition.y);
	float ratio = 0;
	float vectorYlen = 0;
	float vectorXlen = 0;
	if (yLength != 0)
	{
		ratio = xLength / yLength;
		vectorYlen = sqrt(pow(WALKING_SMOOTHNESS / 5 * (blockSize/20.0), 2) / (1 + pow(ratio, 2)));
		vectorXlen = vectorYlen*ratio;
	}
	else if (yLength == 0) vectorXlen = WALKING_SMOOTHNESS / 5;
	// ustalanie znakow
	if (animations.getSprite().getPosition().x > targetPosition.x)
		vectorXlen *= -1;
	if (animations.getSprite().getPosition().y > targetPosition.y)
		vectorYlen *= -1;

	movmentTimer += clock.getElapsedTime();
	clock.restart();
	if (movmentTimer >= milliseconds(1000.0 / (enemySpeed*enemySpeed)))
	{
		
		movmentTimer = seconds(0);
		{
			animations.walking();
			animations.setSpritePosition(Vector2f(animations.getSprite().getPosition().x + vectorXlen, animations.getSprite().getPosition().y + vectorYlen));
		}
	}

}

void Normal_Zombie_Movment::turnToTarget(float blockSize, Vector2f targetPosition)
{
		float angle;
		if (targetPosition.x > animations.getSprite().getPosition().x && targetPosition.y > animations.getSprite().getPosition().y)	// prawa dolna æwiartka
		{
			angle = atan(abs((float)animations.getSprite().getPosition().y - targetPosition.y) / abs((float)animations.getSprite().getPosition().x - targetPosition.x)) * 180 / 3.14159265358979323846;
			animations.setSpriteRotation(angle);
		}
		else if (targetPosition.x < animations.getSprite().getPosition().x && targetPosition.y > animations.getSprite().getPosition().y)	// lewa dolna æwiartka
		{
			angle = atan(abs((float)animations.getSprite().getPosition().x - targetPosition.x) / abs((float)animations.getSprite().getPosition().y - targetPosition.y)) * 180 / 3.14159265358979323846;
			animations.setSpriteRotation(90 + angle);
		}
		else if (targetPosition.x > animations.getSprite().getPosition().x && targetPosition.y < animations.getSprite().getPosition().y)	// prawa gorna æwiartka
		{
			angle = atan(abs((float)animations.getSprite().getPosition().y - targetPosition.y) / abs((float)animations.getSprite().getPosition().x - targetPosition.x)) * 180 / 3.14159265358979323846;
			animations.setSpriteRotation(-angle);
		}
		else if (targetPosition.x < animations.getSprite().getPosition().x && targetPosition.y < animations.getSprite().getPosition().y)	// lewa gorna æwiartka
		{
			angle = atan(abs((float)animations.getSprite().getPosition().x - targetPosition.x) / abs((float)animations.getSprite().getPosition().y - targetPosition.y)) * 180 / 3.14159265358979323846;
			animations.setSpriteRotation(-90 - angle);
		}
		else if (targetPosition.y - animations.getSprite().getPosition().y == 0)
		{
			if (targetPosition.x > animations.getSprite().getPosition().x)
				animations.setSpriteRotation(0);
			else
				animations.setSpriteRotation(180);
		}
		else if (targetPosition.x - animations.getSprite().getPosition().x == 0)
		{
			if (targetPosition.y > animations.getSprite().getPosition().y)
				animations.setSpriteRotation(90);
			else
				animations.setSpriteRotation(-90);
		}
}

Normal_Zombie_Movment::Normal_Zombie_Movment()
{
	movmentTimer = seconds(0);
}


Normal_Zombie_Movment::~Normal_Zombie_Movment()
{
}
