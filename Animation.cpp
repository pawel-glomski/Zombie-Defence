#include "Animation.h"



Sprite & Animation::getSprite()
{
	return sprite;
}

void Animation::setSpritePosition(Vector2f position)
{
	sprite.setPosition(position);
}

void Animation::setSpriteRotation(float angle)
{
	sprite.setRotation(angle);
}

void Animation::setWalkingTexture(Texture & tex, float blockSize)
{
	texture = &tex;
	sprite.setTexture(*texture);
	sprite.setTextureRect(IntRect(0, 0, texture->getSize().x / walkFramesNumber, texture->getSize().y));
	sprite.setScale(blockSize / ((float)texture->getSize().x / walkFramesNumber), blockSize / (float)texture->getSize().y);
	sprite.setOrigin(texture->getSize().x / (float)walkFramesNumber / 2.0,texture->getSize().y/2.0);
}

bool Animation::walking()
{
	time += clock.getElapsedTime();
	if (time >= milliseconds(1000 / 2.0 / walkFramesNumber))
	{
		time = microseconds(0);
		whichFrame++;
		if (whichFrame == 4) whichFrame = 0;
		sprite.setTextureRect(IntRect(texture->getSize().x / walkFramesNumber * whichFrame, 0, texture->getSize().x / walkFramesNumber, texture->getSize().y));
		clock.restart();

		return 1;
	}

	clock.restart();
	return 0;
}

void Animation::standing()
{
	sprite.setTextureRect(IntRect(texture->getSize().x / walkFramesNumber, 0, texture->getSize().x / walkFramesNumber, texture->getSize().y));
}

Animation::Animation()
{
	whichFrame = 0;
	time = milliseconds(0);

}


Animation::~Animation()
{
}
