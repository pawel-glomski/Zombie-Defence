#include "Movment.h"

void Movment::setSpritePosition(Vector2f position)
{
	animations.setSpritePosition(position);
}

void Movment::setWalkingTexture(Texture & texture, float blockSize)
{
	animations.setWalkingTexture(texture, blockSize);
}

Sprite & Movment::getWalkingSprite()
{
	return animations.getSprite();
}


Movment::Movment()
{
}


Movment::~Movment()
{
}
