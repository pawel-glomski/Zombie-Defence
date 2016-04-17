#pragma once
#include "Animation.h"
#include <iostream>
#include <math.h>

#define WALKING_SMOOTHNESS 10.0	// NA ILE CZESCI ZOSTAJE PODZIELONY 1 BLOK PRZY CHODZENIU

class Movment
{
protected:
	Clock clock;

	Animation animations;
public:

	void setSpritePosition(Vector2f position);
	void setWalkingTexture(Texture & texture, float blockSize);
	Sprite & getWalkingSprite();

	Movment();
	~Movment();
};

