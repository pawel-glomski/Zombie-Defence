#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

#define PROJECTILE_SPEED 40.0
#define PROJECTILE_VECTOR 3.0

class Projectiles
{
	Clock clock;
	Vector2f position;
	Vector2i destPosition;
	Vector2f a_b;	// sk³adowe wektora przemieszczenia

public:

	void fly();
	Vector2f getProjectilePosition();

	Projectiles(Vector2f charPosition, RenderWindow & window);
	~Projectiles();
};

