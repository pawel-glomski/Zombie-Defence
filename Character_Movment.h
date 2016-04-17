#pragma once
#include "Movment.h"


using namespace std;
class Character_Movment : public Movment
{
	Time xTime;
	Time yTime;
	Time moveSoundTimer;
	bool whichSound;

	float xFrameMoved;
	float yFrameMoved;

	SoundBuffer stepSoundBuffer1;
	SoundBuffer stepSoundBuffer2;
	Sound stepSound1;
	Sound stepSound2;

	Vector2i mapSize;

public:
	void setMovmentMapSize(Vector2i mapSize);
	void move(View & view, int blockSize, int & charX, int & charY, float & charSpeed);
	void lookAround(RenderWindow & window);

	Character_Movment();
	~Character_Movment();
};
