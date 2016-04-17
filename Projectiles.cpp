#include "Projectiles.h"



void Projectiles::fly()
{
	if (clock.getElapsedTime() >= milliseconds(1000 / (PROJECTILE_SPEED * PROJECTILE_SPEED * 1000)))
	{
		clock.restart();
		position.x += a_b.x;
		position.y += a_b.y;
	}
}

Vector2f Projectiles::getProjectilePosition()
{
	return position;
}

Projectiles::Projectiles(Vector2f charPosition, RenderWindow & window)
{
	position = charPosition;
	destPosition = Mouse::getPosition(window);

	float xLength = abs((float)window.getSize().x/2 - destPosition.x);
	float yLength = abs((float)window.getSize().y / 2 - destPosition.y);
	float ratio = 0;
	float vectorYlen = 0;
	float vectorXlen = 0;
	if (yLength != 0)
	{
		ratio = xLength / yLength;
		vectorYlen = sqrt(pow(PROJECTILE_VECTOR * (window.getSize().x / 800.0), 2) / (1 + pow(xLength / yLength, 2)));	// PROJECTILE_VECTOR - przeciwprostokatna trojkata * skala
		vectorXlen = vectorYlen*ratio;
	}
	else
	{
		vectorXlen = PROJECTILE_VECTOR * (window.getSize().x / 800.0);
		vectorYlen = 0;
	}

	if ((float)window.getSize().x / 2 > destPosition.x)
		vectorXlen *= -1;
	if ((float)window.getSize().y / 2 > destPosition.y)
		vectorYlen *= -1;

	a_b.x = vectorXlen;
	a_b.y = vectorYlen;
}


Projectiles::~Projectiles()
{
}
