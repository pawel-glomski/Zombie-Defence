#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;


class Animation
{
	int whichFrame;
	Clock clock;
	Time time;
	Sprite sprite;
	Texture * texture;

public:
	int walkFramesNumber = 4;

	Sprite & getSprite();
	void setSpritePosition(Vector2f position);
	void setSpriteRotation(float angle);
	void setWalkingTexture(Texture & texture, float blockSize);
	bool walking();
	void standing();

	Animation();
	~Animation();
};

